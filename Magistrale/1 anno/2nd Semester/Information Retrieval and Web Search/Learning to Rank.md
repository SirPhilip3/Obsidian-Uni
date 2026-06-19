---
publish: true
---
# Bag Of Words (BOW) ranking

*Query* and *Documents* are represented as sparse *BOW* vectors

We ditch the *query-document* features 

## Pipeline

![[Learning _to_rank_pipe.excalidraw.png]]
%%[[Learning _to_rank_pipe.excalidraw.md|🖋 Edit in Excalidraw]]%%

*Learning to Rank* ( *LtR* ) is applied only to the second stage 

## Features

The feature to be used during training of the *Learning To Rank* algorithm can be : 

+ Log frequency of query word in anchor text
+ Query word in color on page
+ \# of images on page
+ \# of (out) links on page
+ PageRank of page
+ .....

>[!example] 
>We can train a *linear classifier* to predict the *relevance* of a document given a query-document pair with *feature vector* : 
>+ cosine similarity : $\alpha$
>+ min query window shortest text span that contains all query words regardless of the order : $\omega$ 
>
>The linear score function is then :
>$$
>Score(d,q) = Score(<\alpha, \omega>) = a \alpha + b \omega
>$$
>
>The linear classifier will learn $a$, $b$ and $\Omega$ ( the intercept ) than we can decide if : 
>+ a document is *relevant* if $Score(d,q)> \Theta$ 
>+ is *irrelevant* if $Score(d,q) \leq \Theta$
>
>![[Linear_class_LtR.excalidraw.png]]
>%%[[Linear_class_LtR.excalidraw.md|🖋 Edit in Excalidraw]]%%

## Learning to Rank approaches

### Pointwise

+ Each *query-document* pair is associated with a score
+ The objective is to predict this *score*
+ Does not consider the position of the document into the result list

### Pairwise *RankNet*

+ Based on *pairwise preferences* : $d_{1}$ is better than $d_{2}$ for query $q$ 
+ The objective is to predict a score that preserves such preferences
	+ Like a binary classification problem ( is $d_{1}$ better than $d_{2}$ )

>[!note] 
>It doesn't consider *graded relevance*
### Listwise 

We are given the ideal ranking for each query 
**Objective** is to maximize the quality of the resulting ranked list 
## BM25F

**BM25F** is an extension of [[Tf-Idf#BM25 (Best Match 25)|BM25]] to handle structured ( *multi-field* ) documents
>[!note] 
>A *field* is a part of a document ( eg header , body etcc )

$$
BM25F(d,q) = \sum_{t} IDF_t\ \tau(F_t)
$$
$$
F_{t} = \sum_{s} \frac{w_{s} \cdot f_{t,s}}{1-b_{s}+b_{s} \cdot l_{s} / L_{s}}
$$
Where : 
+ $w_{s}$ is a weight of the field $s$
+ $f_{t,s}$ is the frequency of the term $t$ in field $s$
+ $l_{s}$ is the lenght of field $s$
+ $b_{s}$ determines the importance of $l_{s}$
+ $L_{s}$ is the average lenght of field $s$ in the whole collection

It has $2S+1$ *free parameters* to tune ( $S$ is the number of fields )

## LtR applied to BM25F

**Data** :
Training instances are *query/set of results*
+ Every query has a set of candidate results
+ Each result is manually annotated with a relevance judgment

**Evaluation** :
+ [[Evaluation#Normalized Discounted Comulative Gain (NDCG)|Normalized Discounted Comulative Gain NDCG@10]] 

**Algorithm** : 
+ Hypotesis space : all possible *BM25F funtions*
+ Optimization strategy : *gradient descent* over *NDCG@K* 

Learn a model $h$ that assigns scores to documents in $D$ according to their relevance : 
+ *Results* : $sort\{h(d_{1}),h(d_{2}),\dots\}$ 

>[!note] 
>Where $h$ is *BM25F*  with a proper parameter set $\theta$

>[!warning] 
>We can't directly apply *gradient descent* since **sort** is not a continuos and derivable function

>[!error] 
>*NDCG@K* cannot be optimized directly 
>
>We need to optimize a *pairwise proxy measure* ( called **RankNet** ) the *pairwise cross-entropy loss*

>[!note] Approximating the NDCG@K Gradient 
>*Lambda-MART* uses a loss for which it's possible to approximate a *NDCG* gradients
>
>Where *MART* is a *Gradient Boosted Regression Tree* 

With the *pairwise* approach we *minimize* the *number* of incorrectly classified pairs but we want to give *more importance* to missclassifing *top result* pairs

# From BOW to NIR rankings 

**BOW** ( *Bag of Words* ) infers the relevance of a document to a query exploting partially hand-crafted  functions like [[Tf-Idf#BM25 (Best Match 25)|BM25]] using *term frequency* ( *TF* ) of a query term in each document and the term popularity in the whole collection with *inverse document frequency* ( *IDF* )

**Learning To Rank** instead uses relevant signals about a query term gathered from the usage and structure of the web , this are used by *Machine Learning* methods like *linear regressors* , *boosted trees ensambles* etcc 
## Neural Information Retrieval 

Aims at learning *rich abstract rapresentations* of documents and queries leaving behind the pure presence / absence or frequency of a given term in documents 
### Language Models

A *language model* is a *machine learning* model that predicts upcoming words by giving a probability distribution over possible next words 
$$
\mathbb{P}(w_{1:n}) = \mathbb{P}(w_{1})\mathbb{P}(w_{2}|w_{1})\mathbb{P}(w_{3}|w_{1:2})\dots\mathbb{P}(w_{n}|w_{1:n-1}) \approx \prod_{k=1}^n \mathbb{P}(w_{k}|w_{1:k-1})
$$
#### N-gram Language Models

In general we cant compute the probability of a word given its entire history but we approximate it with just the last few words 

In the *bigram* model we approximate it with the preceding word ( this can be generalized for *N-grams* ) 

In order to move away from strict presence / absence rapresentation of words we can use [[Relevance Feedback and Query Expansion#Distributional semantics|Distributional Semantics]] 

We create *low dimensional word embedding* to rapresent words , this embeddings are learned by the *Neural Networks* 

>[!note] 
>Similar word embedding ( measured with dot product ) must also rapresent similar words 

#### Skip-Gram Model ( Word2vec )

*Word2vec* is a framework to learn word embeddings 

Go through each position $t$ in the text which has : 
+ a *center word* $c=w_{t}$ 
+ various *context words* $o$ 

Use the similarity of the word vectors for $c$ and $o$ to calculate the *probability* of $o$ given $c$ : $\mathbb{P}(o|c)$ 

>[!note] 
>The *Continuos Bag of Words Model* does the opposite $\mathbb{P}(c|o)$

>[!example] 
>![[Pasted image 20260618101430.png]]

**Word2vec** trains a neural network to predict context terms given the center word, it returns the *probability* for every word in our vocabulary of being a *nearby word*  

>[!note] 
>**Word2vec** is not used for inference but to learn the *word vectors* ( *embeddings* )

The goal is to *maximize* for all possible $T$ windows of size $m$ in the training set :
$$
\arg \max_{\theta} \prod_{t=1}^T \prod_{-m\le j\le m} \mathbb{P}(w_{t+j}|w_{t}; \theta)
$$
The *objective function* will be :
$$
J(\theta) = -\frac{1}{T} \sum_{t=1}^T \sum_{-m\le j \le m} \log (\mathbb{P}(w_{t+j}|w_{t}; \theta))
$$
With $j\neq 0$ since a context window of $0$ does not exist

In this case we can use [[Gradient Descent#Stocastinc Gradient Descent|Stocastic Gradient Descent]] to adjust the parameters $\theta$ to *minimize* $J$
##### Calculating $\mathbb{P}(w_{t+j}|w_{t}; \theta)$ 

We use the following *softmax* function : 
$$
P(o|c) = \frac{\exp(u_{o}^T v_{c})}{\sum_{w \in V}\exp(u_{w}^T v_{c})}
$$
Where : 
+ $v_{c}$ : the vector for the central word
+ $u_{w}$ : the vector of a context word
+ $V$ : the total vocabulary size 

##### Neural network structure

We give in 
+ **input** a *one-hot encoded* vector of lenght $|L|$ where $L$ is the is the whole vocabulary rapresenting the *center* word in input 
+ **output** a *one-hot encoded* vector of lenght $|L|$ rapresenting the probability for every word in the vocabulary to be a *nearby* word 

>[!example] 
>![[LtRword2vect.excalidraw.png]]
>%%[[LtRword2vect.excalidraw.md|🖋 Edit in Excalidraw]]%%

#todo 