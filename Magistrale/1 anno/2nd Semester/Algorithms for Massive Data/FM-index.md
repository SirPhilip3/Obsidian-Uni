---
publish: true
---
# Backward Search 

## Idea

Consider the following [[BWT (Burrows-Wheeler transform)|BWT]] matrix:
![[Pasted image 20260430135852.png|405]]

Assume that we have the range $[5,9]$ of the string *ab* and we want to find the range of the string **a***ab*

![[Pasted image 20260430140759.png]]

Since the **BWT** stores the next character in the string if we want to find the range for **a***ab* we simply apply [[BWT (Burrows-Wheeler transform)#LF property|LF mapping]] to the *a*'s present inside the same range in the *BWT*

![[Pasted image 20260430141413.png]]


>[!note]
>To identify the range we simply need to perform $\psi$ only on the *first* and *last* ( from top to bottom )
## Algorithm

1. Start from the range of the empty string 
2. Search the character of out pattern P from *right* to *left*
3. At the end we will have the range $[l,r]$ of the full pattern 
4. *count(P)* will simply be $r-l+1$
5. *locate(P)* = $SA[l, \dots, r]$

>[!example] 
>#todo

### Time Complexity

We can show that this take in total $O(m \log \sigma)$ *time* 

>[!note]-
>$m$ is the size of the *pattern* $P$

We need to solve $2$ problems in $O(\log \sigma)$ *time*
1. Find the **rank** of the *first* and *last* letter in an arbitrary **BWT** range
2. Compute the **LF** function
#### 1)

Given a range $[i,j]$, the **ranks** of the *first* and *last* letter will be : 
+ $f=BWT.rank_L(i-1)+1$
+ $l = BWT.rank_L(j)$

Since we are simply doing operations on [[Bitvectors (RRR)]] this will take $O(\log \sigma)$ *time*
#### 2)

Memorize a separate $C$ array containing the *positions* of the first occurrence of every $c\in \Sigma$ minus $1$ ( since we need to also keep \$ in memory that has position $0$ )

>[!example] 
>The the 2-nd $a$ in the *BWT* will be in position $F[C[a]+2] = 3$
>![[Pasted image 20260502171417.png]]

This takes : 
+ $O(1)$ *time*
+ $\Theta(\sigma \log n)$ *bits* of space for $C$

#### Count algorithm

```pseudo
	\begin{algorithm}
	\caption{Count(P)}
	\begin{algorithmic}
	\State $m \to |P|$
	\State $l \to 1$
	\State $r \to |S|$
	\For{$i = m$ down to $1$}
		\State $c \to P[i]$
		\State $l \to C[c] + BWT.rank_c(l-1)+1$
		\State $r \to C[c] + BWT.rank_c(r)$
    \EndFor
    \Return r - l + 1 
	\end{algorithmic}
	\end{algorithm}
```
This takes $O(m \log \sigma)$ *time*

# FM-Index

We have shown that computing $\psi[i]$ ( which in our case is the *locate* function, finding the rank in the *BWT* ) takes $O(\log \sigma)$ *time* ( [[FM-index#1)|Time complexity]] ) 

>[!note] 
>The $\psi$ function for the [[Compressed Suffix Array (CSA)]] is faster ( $O(1)$ )

Being able to compute $\psi$ let's us build a [[Compressed Suffix Array (CSA)#Sampled Suffix Array (SSA)|Sampled Suffix Array]] by doing *sampling* 
>[!warning] 
>In this case we need to sample more values since the $\psi$ function takes more time and so we can't afford to skip more values

**Sampling** : 
$$
T = \frac{(\log n)^{1 +\epsilon}}{\log \sigma}
$$
values of the [[Suffix trie-tree-array#Suffix Array|Suffix Array]]

We obtain that : 
+ *sampling* takes $o(n \log \sigma)$ *bits* of **space**
+ $T$ application of $\psi$ take $O((\log n)^{1 +\epsilon})$ *time*

>[!important] Theorem
>Choosen any constants $\epsilon > 0$ ( *as small as possible* ) and $\alpha < 1$ ( *as large as possible* ) 
>
>Let $k = \lfloor \max\{0, \alpha \log_{\sigma} n - 1 \} \rfloor$
>
>Than the **FM-index** uses 
>$$
>nH_k + o(n \log \sigma) +\Theta(\sigma \log n)
>$$ 
>*bits* of space and supports 
>
>+ *count(P)* queries in time $O(m \log \sigma)$
>+ *locate(P)* queries in time $O(m \log \sigma + occ \cdot (\log n)^{1+\epsilon})$
>+ *extract(i,l)* queries in time $O((\log n)^{1+\epsilon}+ l \log \sigma)$

>[!note] *Constant* sized *alphabets*  
>
>The *FM-index* uses 
>$$
>n H_k +o(n)
>$$ 
>*bits* of space and supports
>+ *count(P)* queries in time $O(m)$
>+ *locate(P)* queries in time $O(m + occ \cdot (\log n)^{1+\epsilon})$
>+ *extract(i,l)* queries in time $O((\log n)^{1+\epsilon}+ l)$

