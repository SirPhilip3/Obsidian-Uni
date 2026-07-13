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
>![[CBF_del.excalidraw.png]]
%%[[CBF_del.excalidraw.md|🖋 Edit in Excalidraw]]%%

>[!warning] 
>Now asking for `Membership(5)` we get that not all $k$ integers are $>0$ ( $CBF[5]=0$ ) so *False* but $5$ is still in $S$ so we introduced a **False Negative**
>
>This happend because during the *insertion* we had an **overflow** at $5$ 

## Computing $\mathbb{P}(FP)$

>[!note] 
>With the way we handle *underflows* and *overflows* , **insert** and **membership** behave exactly like [[Bloom Filters]]

Looking at *insert* and *memebership* the behavious of $CBF[i]$ is the same as applying [[Bloom Filters]]  

So looking the probability is the one already calculated in [[Bloom Filters#$ mathbb{P}$ of False Positives|Bloom Filters]] , choosing $\delta > 0$ then we have : 
$$
\mathbb{P}(FP) = \left( \frac{1}{2} \right)^{(M/m) \ln 2} = \delta
$$
So : 
+ $k = \log_{2}\left( \frac{1}{\delta} \right)$
+ $M = mk \log_{2} e = O\left( m \log\left( \frac{1}{\delta} \right) \right)$

>[!note]-
>$M$ is the size of the *bloom filter* and $k$ is the maximum integer that can be stored 
>

## Computing $\mathbb{P}(FN)$

Let $x \in S$ , what is the probability that $x$ is a *False Negative* ( an element is present in the $CBF$ but the `Membership` query says the is *not present* )

>[!important] 
>If **no overflow** happens on any $CBF[h_{j}(x)]$ then $x$ **can not be a False Negative** 

Therefore the probability can be bound in the following way : 
$$
\mathbb{P}(x \in FN) \le \mathbb{P}(\exists j : CBF[h_{j}(x)] \text{ overflows} )
$$
Now we calculate the following: 
	Fix any $i$, what is $\mathbb{P}(CBF[i] \text{ overflows})$ ?

This means that while inserting some numbers in the filter $CBF[i]$ gets incremented at least $2^t$ times

Since $i$ is *fixed* then only *one hash* function has *effect* on $CBF[i]$ :
$$
h_{j} = h_{\lfloor i/k \rfloor +1}
$$
Now for each of the positions touched by $h_{j}$ while inserting $x_{1},\dots,x_{m}$ we have :
$$
i_{1}=h_{j}(x_{1}),\ i_{2} = h_{j}(x_{2}), \dots,\ i_{m}=h_{j}(x_{m})
$$

>[!important] 
>All the *random variables* $i_{1},\dots,i_{m}$ are **iid** *uniform values* in the slot of size $M/k$ containing position $i$

Noticing also that for any $p \in [m]$ we have that $\mathbb{P}(i_{p}=i) = k/M$

This means that we can write :
$$
\mathbb{P}(CBF[i]\text{\ overflows}) \leq \mathbb{P}(\exists\ j_{1}<\dots < j_{T} : i_{j_{1}}=\dots = i_{j_{T}}=i )
$$
>[!note]-
>This means that the probability that $CBF[i]$ overflows is given by the probability that for $T$ execution of $h_{j}$ ( $i_{j_{1}}$ ) the resulting hash value is $i$

The $\mathbb{P}(i_{j_{1}}= \dots = i_{j_{T}}=i)$ can be rewritten as :
$$
\prod_{p=1}^T \mathbb{P}(i_{j_{P}}=i) = \left( \frac{k}{M} \right)^T
$$
Now we need the probability that we find a group of $T$ executions of $j$ that causes an *overflow* 

One specific cobination is :
$$ 
\binom{m}{T}
$$
>[!note]-
>Where $m$ is the size of the elements that can be put in the *Counting Bloom Filter*

By **union** we find :
$$
\mathbb{P}(\exists\ j_{1}<\dots < j_{T}: i_{j_{1}} = \dots = i_{j_{T}}=i) \leq \binom{m}{T} \cdot \left( \frac{k}{M} \right)^T
$$
Or :
$$
\mathbb{P}(CBF[i]\ \text{overflows}) \le  \binom{m}{T} \cdot \left( \frac{k}{M} \right)^T
$$
Now bounding the *binomial coefficent* as :
$$
\binom{m}{T} \leq \left( \frac{em}{T} \right)^T
$$
So :
$$
\mathbb{P}(CBF[i]\ \text{overflows}) \le \left( \frac{emk}{TM} \right)^T
$$
Now remembering that $M=mk \log_{2} e$ we have :
$$
\left( \frac{e \ln 2}{T} \right)^T
$$
Assuming that $2^t =T \ge 4$ since surely $t\ge 2$ ( since otherwise we would have a simple [[Bloom Filters]] )

But then we can say the following :
$$
\left( \frac{e \ln 2}{T} \right)^T \le \left( \frac{1}{2} \right)^T
$$

The **result** that we got is that a particular $CBF[i]$ *overflows* is :
$$
\left( \frac{1}{2} \right)^{2^t}
$$
Now the probability that $x$ is a **False Negative** is :
$$
\mathbb{P}(x \text{ is FN}) \le \mathbb{P}(\exists j : CBF[h_{j}(x)]\text{ overflows}) \le k \cdot \left( \frac{1}{2} \right)^{2^t}
$$
Since $j \in [k]$

>[!example] 
>#todo

## Space as a function of $\mathbb{P}(FP)$ and $\mathbb{P}(FN)$

#todo 