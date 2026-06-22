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
>Kendall's $\tau$ is not sensitive to the position in the ranking , swapping two position at the top has the same weight as swapping at the bottom 

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
\mathcal{L}(f) = \frac{1}{N} \sum_{(q,d,y) \in \Psi} \sum_{i,j \text{ s.t. } y_{i} > y_{j}} \log (1+e^{-(f_{i} -f_{j})}) 
$$
Where $f_{i} = f(d_{i})$ 

The *loss decreases* as $f_{i}$ gets larger than $f_{j}$ when the best document gets a *larger score* 

>[!note] 
>This is *differentiable* and can be optimized with [[Gradient Descent]]

>[!warning] 
>*RankNet* is **not** nicely correlated with *NDCG*

## Decision Trees 

A *regression tree* is a piecewise linear function. 

The features of an instance are evaluated one by one at every node of the *tree* , depending on the outcoome of the test we proceed to a lower node 

*Leaves* contain the final prediction of the model

Decision trees have *high* *accuracy* and are train-efficient

### Gradient Boosted Decision Trees (GBDTs)

Each $f_{i}$ is regarded as a step in the *best optimization direction* 

$$
f_{i}(d) = -g_{i}(d)
$$
With 
$$
g_{i}(d) = \bigg[  \frac{\partial l(f(d),y)}{\partial f(d)} \bigg]_{f=\sum_{j<i}f_{i}}
$$
Let the loss function be $\frac{1}{2} \times \text{Sum of Squared Error}$ :
$$
-g_{i}(d) = - \frac{\partial \frac{1}{2} SSE(f(d),y)}{\partial f(d)} = -\frac{\partial \frac{1}{2} \sum(f(d)-y)^2 }{\partial f(d)} = y-f(d)
$$
>[!note] 
>Gradient $g_{i}$ is approximated by a *Regression Tree* $t_{i}$ 
>

![[Pasted image 20260619134758.png|169]]

Algorithm : 
```pseudo
	\begin{algorithm}
	\caption{Gradient Boosting}
	\begin{algorithmic}
	\State $F \leftarrow 0$
	\For{$m = 1 \to M$}
		\State $r_i \leftarrow$ current (pseudo) residual for $i \in [N]$
		\State $\mathcal{R} \leftarrow \{(x_i,r_i)\}^N_1$
		\State $T_m \leftarrow$ a regression model trained on $\mathcal{R}$
		\State $F \leftarrow F+ vT_m$ 
    \EndFor
	\end{algorithmic}
	\end{algorithm}
```

This works great for *regression* but ranking : 

### GBDTs for ranking: The LambdaMart algorithm 

The *LambdaMart* pushes the Metric into the *RankNet Cost* gradient. Let the gradient of the RankNet Cost for a pair of documents $(i,j)$ be :
$$
\frac{\partial \log\big(1+ e^{-(f_{i}-f_{j})}\big)}{\partial f} = \dots = -\frac{1}{1+e^{-(f_{i}-f_{j})}}
$$
Let $\lambda_{ij}$ be the Lambda gradient for a pair of documents $(i,j)$ : 
$$
\lambda_{ij} = -\frac{1}{1+e^{-(f_{i}-f_{j})}} |\Delta NDCG| 
$$
Where $\Delta NDCG$ is the *metric* change when swapping documents $i$ and $j$ in the ranked list

Then for a single document we sum up pairs contributions to estimate the documents gradient :
$$
g_{i} = \lambda_{i} = \sum_{y_{i} > y_{j}} \lambda_{ij} - \sum_{y_{i} < y_{j}} \lambda_{ij}
$$
>[!note] 
>This is used for training a *Tree* in **GBDT** for ranking.

>[!important] 
>We defined the *gradient* without defining the loss
>+ The metric is not differentiable but
>+ The gradient is in **agreement** with *NDCG*

We are ptimizing an approximation of the ranking metric 
### Efficient Scoring Functions 

*Scroring* documents with decision trees can be *expensive* because of poor memory layout 

Instead of *Decision Trees* we use **Decision Tables** 

**Decision Tables** : 
+ Have *level-wise decision* predicates , in each level we evaluate one single decision
>[!warning] 
>Potentially *less expressive* but *less prone* to *overfitting*

+ Built *level-wise* 
>[!note] 
>With a single dataset scan we add one level to the tree

+ More *compact* 
	+ Stores only $n$ predicates instead of $2^n$ nodes

+ More efficient at *scoring time* 
	+ Performs the same tests for every instance
	+ The true / false outcome result can be mapped in a $0/ 1$ string indicating as the location of the final prediction 
#### BackFitting

*Revise greedy* choices 

+ **Cyclic** backfitting
	+ Go back to the first cut and re-optimize all cuts in sequential *cyclic* order
+ **Random** backfitting
	+ Randomly select a cut to backfit
+ **Greedy** backfitting
	+ Test all possible cuts and then select the cut that gives the largest reduction of error

```pseudo
	\begin{algorithm}
	\caption{BackFitting Algorithm}
	\begin{algorithmic}
	\For{$pass= 1 \to n$}
		\For{$t = 0 \to d-1$}
			\State $k \leftarrow$ next() 
			\Comment{Pick the $k$-th cut to optimize}
			\State remove the $k$-th cut from 'dt'
			\State $(x_j,c) \leftarrow \arg \max_{x_j,c} Gain(x_j,c)$ 
			\State dt.features[k] $\leftarrow j$
			\State dt.cuts[k] $\leftarrow c$
        \EndFor
        \State Update dt.predictions
    \EndFor
	\end{algorithmic}
	\end{algorithm}
```
