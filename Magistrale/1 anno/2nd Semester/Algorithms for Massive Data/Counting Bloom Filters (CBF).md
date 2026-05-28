---
publish: true
---
The [[Bloom Filters]] do not support **delete** because for any *bit* $B[i]$ we don't know how may elements $x \in S$ effected that bit

>[!important] 
>Instead of *bits* we store *integer* **Counters**

They in fact work as [[Bloom Filters]] but instead of doing $BF[h_{j}(x)] \leftarrow 1$ we will do : 
$$
CBF[h_{j}(x)] \leftarrow CBF[h_{j}(x)] + 1
$$
>[!warning] 
>We need to manage *undeflows* and *overflows*

**Cost** : 
+ Larger *space*
+ $\mathbb{P}(FN)>0$

## Building CBF

We want to represent sets $S \subseteq [n]$ of cardinality at most $m$