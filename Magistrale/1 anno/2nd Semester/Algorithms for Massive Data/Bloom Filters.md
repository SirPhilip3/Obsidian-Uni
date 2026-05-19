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

Than the *bloom filter* is a **