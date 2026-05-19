---
publish: true
---
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