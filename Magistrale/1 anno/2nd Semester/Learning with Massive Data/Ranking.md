---
publish: true
---
Given a query $q \in Q$  and a *dynamic* collection of documents $\mathcal{D}$ find an ordered $k$-subset that *maximizes* a utility function $u: \mathcal{Q} \times \mathcal{D}^k \to \mathbb{R}$ , where $u$ is the *user-percieved* quality of the result set  

We have : 
+ a dataset of **labeled** examples $\Psi$ 
+ a *Rapresentation function* $\phi(\cdot)$
+ an *Hypothesis class* of ranking functions $f(\cdot, \Theta)$
+ a *Training loss function* $l(\cdot,\cdot)$
+ an *Evaluation metric* $\mathcal{U}(\cdot,\cdot)$

>[!note] Labels
>
>Labels have two origins : 
>+ **Explicit feedback** 
>	+ A human is presented with a query and a ranked list and is asked to grade each document with respect to the query
>>[!warning] 
>>It's *costly* , queries and documents may be private (emails)
>+ **Implicit feedback**
>	+ Signals collected when a user interacts with a ranking systems
>
>>[!warning] 
>>Has *biases* like position and trust bias , also the signals maybe noisy or unavailable on unobserved documents 
## Document Reprentation

Describe a document *mathematically* asuuming that there exists a *function* $\phi$ that : 
1. Takes an *object* 
2. Returns a *vector* in $\mathbb{R}^n$ as its representation

[[Tf-Idf]] is an example of this *function* for text , we also may include other signals like [[PageRank]] , number of clicks , time spent on page etcc 

## Ranking with Linear Regression

We can predict the **relevance label** $y \in \mathcal{Y}$ of a document $x \in \mathbb{R}^n$ using a linear function : 
$$
f(x)=w^T x + b
$$
We learn the parameters of the function $f$ by minimizing the *empirical error* on a set of $m$ training examples :
$$
w* , b* = \arg \min_{w,b} \frac{1}{m} \sum_{i=1}^m l(f(x_{i}),y_{i})
$$
>[!note] 
>This is just a *binary* classification : 
>$$
>l(f,y) = \begin{cases} 0 & \text{d is ranked correctly} \\ 1 & otherwise\end{cases}
>$$

The *regression loss* is the following : 
$$
l(f,y)= ||f(q,d)-y||_{2}^2
$$

>[!warning] 
>Since we only have binary ranking the positioning of the documents in the final ranking does not matter
>
>*Regression loss* is not sensitive to the order of the documents 
>

---

Considering also the position of the ranked results we could use [[Evaluation#Kendall's Tau $ tau$|Kendall tau]] :
$$
\tau = \frac{2}{n(n-1)} \sum_{i<j} sign(y_{i}-y_{j})\cdot sign(f_{i}-f_{j})
$$
>[!warning] 
>Kendall's $\tau$ is not sensitive to the position in the ranking , swapping two position at the tpo has the same weight as swapping at the bottom 

---

Another measure is the **Discounted Comulative Gain at Rank@k** ( [[Evaluation#Discounted Comulative Gain|DCG]] )

It rapresents the behaviour of a user : 
$$
DCG@k = \sum_{r \le k} Gain(y_{\pi_{r}}) \times Discount(r)
$$
Where : 
+ $\pi_{r}$ maps from rank $r$ to the corresponding document id $i$ 
$$
Gain(y) = 2^y-1
$$
$$
Discount(r) = \frac{1}{\log_{2}(r+1)}
$$
Normalizing by the *ideal* *DCG* gives us [[Evaluation#Normalized Discounted Comulative Gain (NDCG)|NDCG@k]]

Since *NDCG*, *Kendall's* $\tau$ are *step* functions the **gradient** is either $0$ or undefined and so we can't apply directly [[Gradient Descent]] 

We use a *proxy loss* function that is differentiable and has similar behaviour to the original cost function 

---
**RankNet Loss** is a proxy loss 

Given a set of ranking examples $\Psi = \{ (q_{j},d_{j},Y_{j}) \}^N_{j=1}$ , the *RankNet Loss* is :
$$
\mathcal{L}(f) = \frac{1}{N} \sum_{(q,d,y) \in \Psi} \sum_{i,j \text{ s.t. } y_{i} > y_{j}} \log  
$$