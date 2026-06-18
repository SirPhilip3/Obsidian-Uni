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

#todo 

