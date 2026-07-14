>[!important] Goal
>In general the goal will be to read a stream of *integers* $x_{1}, \dots, x_{m} \in [n]$ and create *on-the-fly* ( *online* ) a **data sketch** of the stream

We will typically use space proportional to :
$$
polylog(n+m) = O((\log(n+m))^{O(1)})
$$
This will allows us to compute statistics on the stream 

## Definitions

A **data sketch** of some data $x$ is the output $f(x)$ of a function $f()$ with the following properties :

1. *Small size* : $bitsize(f(x)) \ll bitsize(x)$
2. $f(x)$ can be used to *estimate* some *properties* of $x$ , for example ( if $x$ is a stream ) :
	+ number of distinct elements in $x$
	+ frequency of any $y \in x$
	+ Some function of the frequencies of the elements in $x$

>[!note] 
>*Often* condition $1$ makes it impossible to compute $2$ exactly. 
>
>In those cases we will compute an $\epsilon$-*approximation* with *porbability* $\ge 1 - \delta$ 
>
>The space of the *sketch* will depend on $\epsilon$, $\delta$ and the size of $x$

3. **Dynamic** : $f(x)$ can be *updated* efficently when $x$ changes 

>[!important] 
>This must not require the knowledge of $x$, but just of the *changes* made to $x$ 

>[!note] Non mandatory property
>4. **Similarity-preserving** : if $x_{1}$ and $x_{2}$ are *similar* according to some metric, then $f(x_{1})$ and $f(x_{2})$ are *also similar* according to the same metric 

Often $f(x)$ will be *randomized* , obtained by combining the results of a certain number of *hash functions* on $x$

>[!note] 
>[[Bloom Filters]] can be considered sketches since they satisfy properties $1-3$ , however typically we consider sketches if they use *sublinear* space 

# Simple Sketches 

## Average , Min / Max

Given the stream $x_{1},\dots,x_{m}\in [n]$ we can design a sketch that allows us to compute the *average* of the numbers by simply keeping the running *sum* of the numbers seen 

This has the following properties :
+ Uses $O(\log n)$ *bits*
+ It can be updated in $O(1)$ ( a simple sum ) when a new element arrives

To build a sketch to compute the *maximum* / *minimum* number in a stream we simply maintain the *maximum* / *minimum* number seen so far ( it has the same properties a before )

## Check if $S=\emptyset$ 

Consider a stream $x_{1},\dots,x_{m} \in [-n,n] \backslash \{0\}$ representing a sequence of **operations** on a *multiset* $S$

+ Seeing a *positive* number $x$ means that $x$ has to be *added* to $S$
+ Seeing a *negative* number $-x$ means that $x$ has to be *removed* to $S$

>[!note] Assumption
>Assume that when we are asked to remove $x$ from $S$, this element belongs to $S$

The designed *sketch* should : 
+ Use $O(\log n)$ bits
+ Allow us to check if $S=\emptyset$ with *high probability* of success
+ It can be updated in $O(1)$ when a new element arrives 

The sketch could be build using [[Hashing#Polynomial Hashing ( Rabin hashing )|Polynomial Hashing]] :
+ Inserting element $x$ : $\kappa(S) + 2^{x-1} \mod{q}$
+ Deleting element $x$ : $\kappa(S) - 2^{x-1} \mod{q}$

# Metrics

We will devise sketches that possess property $4$ ( *similarity preserving* ) under the following *metrics* :
+ *Jaccard* distance / similarity
+ Hamming distance
+ Euclidean distance ( $||\ ||_{2}$ norm )

>[!note]- 
>Sketches exists for most metrics 

>[!important] *Metric* Definition
>A **metric** is a *non-negative* binary function $d(x,y) \ge 0$ satisfying : 
>+ Identity : $d(x,x)=0$
>+ Symmetry : $d(x,y)=d(y,x)$
>+ Triangle inequality : $d(x,z) \le d(x,y) + d(y,z)$

## Jaccard Similarity and MinHash

**MinHash** is a sketching technique used to estimate the *Jaccard similarity* of sets.

>[!important] Jaccard *Similarity*
>
>$$
>J(A,B) = \frac{|A \cap B|}{|A \cap B|}
>$$
>
>+ $0 \le J(A,B) \le 1$
>+ $J(A,B)=0$ if and only if $A \cap B = \emptyset$ ( *minimized* )
>+ $J(A,B)=1$ if and only if $A = B$ ( *maximized* )

>[!important] Jaccard *Distance*
>
>$$
>d_{J}(A,B) = 1-J(A,B) = 1 -\frac{|A \cap B|}{|A \cap B|}
>$$
>
>It can be shown that $d_{J}(A,B)$ is a *metric*

Let $h: [n] \to [n]$ be a *uniform permutation* of $[n]$, and let $A \subseteq [n]$.

The **MinHash** *function* $\hat{h}(A)$ of $A$ defined as :
$$
\hat{h}(A) = \min h(A) = \min \{h(x) : x \in A\}
$$
In other words, $\hat{h}(A)$ is the *minimum hash value* of elements in $A$ 

>[!example] 
>Let $n=6$ and $h$ be the following permutation :
>
>|  $x$   |   1 |   2 |   3 |   4 |   5 |   6 |
>| :----: | --: | --: | --: | --: | --: | --: |
>| $h(x)$ |   5 |   3 |   1 |   2 |   4 |   6 |
>
>Set $A=\{4,2,6,1\}$
>
>Then $h(A) = \{h(4),h(2),h(6),h(1)\} = \{2,3,6,5\}$
>
>$\hat{h}(A) = \min h(A) = \min \{2,3,6,5\} = 2$
>>[!note] 
>>A set ($|A|\le n$) is squeezed into just one integer $\hat{h}(A)$ of $\log n$ bits ( *exponential compression* )

We can use $\hat{h}$ to *estimate* the *Jaccard* similarity of two sets $A$ and $B$ by remembering that $\hat{h}(A)$ is a *Random Variable* since $h$ is a *uniform permutation* 

It can be proven that $\hat{h}(A) = \hat{h}(B)$ with *probability* $J(A,B)$ , this will allow us to derive an *unbiased estimator* for $J(A,B)$ 

### Proof

Define the following *Bernoullian indicator* : 
$$
\hat{J}(A,B) = \begin{cases}
1 & \text{if } \hat{h}(A) = \hat{h}(B) \\
0 & \text{otherwise} 
\end{cases}
$$
