---
publish: true
---
# Filters

A *filter* is a *randomized* data structure encoding a set of cardinality $m$ over universe of size $n$ 

**Features** :
+ Limited range of operations : 
	+ insert
	+ membership
	+ *sometimes* delete
+ Membership queries may *fail* with a **user-defined** probability $\delta$
+ Some filters guarantee *False Negative* probability of $0$
+ They break the information-theoretic lower bound: typically $O(m \log (1/\delta))$ *bits* of space
	+ $O(m)$ when $\delta$ is *constant* 
	+ *non constant* $\delta = n^{-\Theta(1)}$ will solve *membership* *with high probability* and uses $O(m \log n)$ *bits* of space

>[!example] Usage example 
>
>Bloom filters are generally used as an interface to a much slower and exact data structure , in fact since in bloom filters there are no *false negative* if it respond no to our query than we can exclude a lookup on the disk

# Bloom Filters

Operations : 
+ *Insert* : $S \leftarrow S \cup \{x\}$ 
+ *Membership* : does $x \in S$ ? :
	+ If $x \notin S$ with a *small probability* the bloom filter will say that $x \in S$ : **False Positive**
	+ If $x \in S$ there will be no **False Negative**

>[!warning] 
>It does not support *delete*

The filter must be initialized with a maximum capacity $m$ and a desired *False Positive* probability $\delta$ , in this case the $\mathbb{P}(FP)\leq \delta$ is *guaranteed* as long as we do not insert more than $m$ elements 

## Building Bloom Filter

We want to rapresent set $S \subseteq [n]$ of cardinality at most $m$ 

Given the paramaters $M=15$ and $k=3$ ( see [[]] for theyr derivation ) 

Than the *bloom filter* is a *bitvector* of lenght $M$ initialized to $0$ :
![[BloomFilter.excalidraw.png]]
%%[[BloomFilter.excalidraw.md|🖋 Edit in Excalidraw]]%%

The *bitvector* is partitioned in $k$ equal size disjoint parts so that each $i$-th part ( $i=1,\dots,k$ ) spans indices $[(i-1)\cdot M/k, i\cdot M/k)$ 

We than draw $k$ *independent* and *fully-uniform* hash function : 
$$
h_i : [n] \to \bigg[ (i-1)\frac{M}{k}, i \frac{M}{k} \bigg)
$$
In other words the $i$-th hash function outputs indices inside the $i$-th part of the *bitvector*

>[!note]- 
>$n$ is the *input domain* 

>[!example] 
>With $n=6$ we draw these *hash functions*
>
>|   *$x$*    |  1  |  2  |  3  |  4  |  5  |  6  |
>| :--------: | :-: | :-: | :-: | :-: | :-: | :-: |
>| *$h_1(x)$* |  3  |  0  |  1  |  0  |  4  |  2  |
>| *$h_2(x)$* |  7  |  5  |  5  |  5  |  5  |  6  |
>| *$h_3(x)$* | 12  | 13  | 10  | 11  | 11  | 10  |

^39c7e2

### Insert

```pseudo
	\begin{algorithm}
	\caption{Insert(x)}
	\begin{algorithmic}
	\For{$i=1,\dots,k$}
		\State $BF[h_i(x)] \leftarrow 1$
    \EndFor
	\end{algorithmic}
	\end{algorithm}
```

>[!example] 
>Taking into consideration the hash functions from this [[Bloom Filters#^39c7e2|table]] , $Insert(5)$ : $h_1(5) = 4$ , $h_2(5) = 5$ and $h_3(5)=11$
>
>So the *Bloom Filter* becomes the following ( also $Insert(2)$ ) : 
>
>
![[insBloom.excalidraw.png]]
%%[[insBloom.excalidraw.md|🖋 Edit in Excalidraw]]%%

^c09a42

>[!note] 
>Indexing in the *Bloom Filter* starts from $0$

### Membership

```pseudo
	\begin{algorithm}
	\caption{Membership(x)}
	\begin{algorithmic}
	\Return $\land_{i=1}^k BF[h_i(x)]$
	\end{algorithmic}
	\end{algorithm}
```

>[!example] 
>Considering the *Bloom Filter* after inserting $5$ and $2$ ( [[Bloom Filters#^c09a42| Resulting Bloom Filter]] ) we do the following $Membership$ queries : 
>
>$$
>\begin{align}
>Membership(2) & = BF[h_{1}(2)] \land BF[h_{2}(2)] \land BF[h_{3}(2)] \\
>& =  BF[0] \land BF[5] \land BF[13] \\
>& = 1 \land 1 \land 1 = 1 
>\end{align}
>$$
>The query returns $True$ and $2$ it was actually inserted ( *Correct* )
>
>$$
>\begin{align}
>Membership(3) & = BF[h_{1}(3)] \land BF[h_{2}(3)] \land BF[h_{3}(3)] \\
>& =  BF[1] \land BF[5] \land BF[10] \\
>& = 0 \land 1 \land 0 = 0 
>\end{align}
>$$
>The query returns $False$ and $3$ was not inserted ( *Correct* )
>
>$$
>\begin{align}
>Membership(4) & = BF[h_{1}(3)] \land BF[h_{2}(3)] \land BF[h_{3}(3)] \\
>& =  BF[0] \land BF[5] \land BF[11] \\
>& = 1 \land 1 \land 1 = 1 
>\end{align}
>$$
>The query returns $True$ and $4$ was not inserted ( *False Positive* )

## $\mathbb{P}$ of False Positives

We need to compute the following probability : $\mathbb{P}(FP)=\mathbb{P}(membership(x)=true|x \notin S)$

First we need to compute $\mathbb{P}(BF[i]=1)$ for any position $i$

What's $\mathbb{P}(BF[13]=1)$ ? 
$i=13$ falls into the third block so it's only effected by $h_{3}$  
Let's *notice* that $\mathbb{P}(BF[13]=1) = 1- \mathbb{P}(BF[13]=0)$

$BF[13]=0 \iff h_{3}(x_{j})\ne 13\ \forall\ j \in [m]$ 

The probability that $h_{3}(x_{j})\ne 13$ is : 
$$
1 -(\text{size of third part})^{-1} = 1 - \frac{k}{M}
$$
#todo https://en.wikipedia.org/wiki/Bloom_filter#Probability_of_false_positives

