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

Let $M=15$ and $k=3$

The **CBF** is an *integer* vector of length $M$ ( total size $M\cdot t$ )

>[!note] 
>Every *integer* is formed by $t$ *bits* , and can hold values in $[0,2^t)$ 

>[!warning] 
>$M$, $k$ and $t$ depends on the $\mathbb{P}(FP)$ and $\mathbb{P}(FN)$ , see [[]] for theyr derivation

1. Split **CBF** in $k$ parts 
2. Draw $k$ *independent* and *fully-uniform* hash functions $h_{i}: [n] \to \left[ (i-1) \frac{M}{k}, i \frac{M}{K} \right)$

Let also $t=2$ then every $CBF[i]$ can hold numbers in $[0,2^2) = [0,4)$ 

>[!example] 
>With $n=6$ we draw these *hash functions*
>
>|   *$x$*    |  1  |  2  |  3  |  4  |  5  |  6  |
>| :--------: | :-: | :-: | :-: | :-: | :-: | :-: |
>| *$h_1(x)$* |  1  |  0  |  1  |  0  |  4  |  2  |
>| *$h_2(x)$* |  5  |  5  |  5  |  5  |  5  |  6  |
>| *$h_3(x)$* | 11  | 13  | 10  | 11  | 11  | 10  |

^6a4257
### Insert 

```pseudo
	\begin{algorithm}
	\caption{Insert(x)}
	\begin{algorithmic}
	\For{$i=1,\dots,k$}
		\State $BF[h_i(x)] \leftarrow \min(BF[h_i(x)]+1,2^t-1)$
    \EndFor
	\end{algorithmic}
	\end{algorithm}
```
>[!important] 
>The $\min$ handles the *overflows* by limiting the integer that can be inserted

>[!example] 
>Taking into consideration the hash functions from this [[Counting Bloom Filters (CBF)#^6a4257|table]] , $Insert(5)$ : $h_1(5) = 4$ , $h_2(5) = 5$ and $h_3(5)=11$
>
>So the *Counting Bloom Filter* becomes the following ( also $Insert(2),Insert(3),Insert(4)$ ) : 
>
>
>![[CountingBloomFilters.excalidraw.png]]
>%%[[CountingBloomFilters.excalidraw.md|🖋 Edit in Excalidraw]]%%

### Membership 

```pseudo
	\begin{algorithm}
	\caption{Membership(x)}
	\begin{algorithmic}
	\Return $\land_{i=1}^k (BF[h_i(x)]>0)$
	\end{algorithmic}
	\end{algorithm}
```
>[!example] 
>Now considering the previously constructed $CBF$ and the hash functions from [[Counting Bloom Filters (CBF)#^6a4257|table]]
>
>![[CBF_mem.excalidraw.png]]
%%[[CBF_mem.excalidraw.md|🖋 Edit in Excalidraw]]%%
>
>We can do the following membership queries :
>+ `Membership(2)` : All $k$  integers are $>0$ so *True*, this is also present in $S$ so the membership query is *correct*
>+ `Membership(6)` : Not all $k$ integers are $>0$ ( $CBF[2]=0$, $CBF[6]=0$ ) so *False*, since $6$ is not present in $S$ then the membership query is *correct*
>>[!warning] 
>>+ `Membership(1)` : All $k$ integers are $>0$ so *True*, but $1$ is not in $S$ so this is a **False Positive**
>>

### Delete

```pseudo
	\begin{algorithm}
	\caption{Delete(x)}
	\begin{algorithmic}
	\For{$i=1,\dots,k :$}
		\State $BF[h_i(x)]\leftarrow \max (BF[h_i(x)]-1,0)$
    \EndFor
	\end{algorithmic}
	\end{algorithm}
```

>[!note] 
>$\max$ is needed to handle *underflows* 

>[!example] 

