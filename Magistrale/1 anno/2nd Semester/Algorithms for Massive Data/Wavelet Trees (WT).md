---
publish: true
---
**Wavelet Trees** are data structure that : 
+ Achieve *zero-order compressed space*
+ **rank**, **select**, **access** ( *RSA* ) queries are solved in $O(\log \sigma)$ time 

This for any *string*

>[!note]- 
>$\sigma$ is the alphabet

The tree is 
+ **binary** 
+ with $\sigma$ *leaves* , one for each distinct character 
+ the *tree* is **balances** , has $O(\log \sigma)$ as *height*
+ each *nodes* is a [[Bitvectors (RRR)]] 

The *RSA* queries are solved by navigating the *tree* from root to a leaf or the other way around 

During the navigation we run *RSA* queries on *each node*'s [[Bitvectors (RRR)]]

# Building the tree

>[!example] 
>$S=$`FACE BAKE CAFE`
>
>>[!note] 
>>space `' '` is a character 
>>
>
>$\sigma = 7$ , $n=14$
>
>1. Encode the alphabet using $\lceil \log \sigma \rceil = 3$ *bits* per charcter using the ASCII ordering of the characters 
>  
>| char  | bin   |
>| ----- | ----- |
>| `' '` | `000` |
>| `A`   | `001` |
>| `B`   | `010` |
>| `C`   | `011` |
>| `E`   | `100` |
>| `F`   | `101` |
>| `K`   | `110` | 
>
>2. Write the codes vertically forming $3$ *levels*
>
>![[WT_build1.excalidraw.png]]
>%%[[WT_build1.excalidraw.md|🖋 Edit in Excalidraw]]%%
>
>3. Build the tree level by level 
>
>![[wt_BUILD2.excalidraw.png]]
>%%[[wt_BUILD2.excalidraw.md|🖋 Edit in Excalidraw]]%%

# Complexity

**Space** for the *nodes* : 
	Each *level* will contain a total of $n$ *bits* , since there are $\log n$ *levels* we will have :
	$$
	n \log \sigma
	$$
**Space** for the *topology* of the tree : 
$$
O(\sigma \log n)
$$
**Space** for the *leaves* :
$$
\sigma \log \sigma \leq \sigma \log n
$$
So in total, using [[Bitvectors (RRR)]] : 
$$
n \log \sigma + O( n \log \sigma ) + O(\sigma \log n)
$$
*Assuming* that $\sigma = o(n/\log n)$ the *space* becomes : 
$$
n \log \sigma + o(n \log \sigma)
$$
## [[Empirical Entropy ( Zero-order )|Zero-order]] compression 

>[!note] Claim
>
>Using [[Bitvectors (RRR)]] the space is $nH_0(S) + o(n \log \sigma)$
>
>Or the compression of the [[Bitvectors (RRR)]] propagate to the whole *string*
>
### Proof

We can prove this by **induction** on the height $h$ of the **Tree** 

+ **Base case** : $h=1$

Since we have no leaf the *claim* is true since [[Bitvectors (RRR)]] achieves [[Empirical Entropy ( Zero-order )|Zero-order]] compression

+ **Inductive hypotesis** 

The *claim* is true for height $h \ge 1$ ( strings $S_0, S_1$ over alphabets of size $\sigma \leq 2^h$ ) 

+ **Inductive step** 

Prove the *claim* for height $h+1$

>[!note] 
>We are in this situation :
>![[WB_t_proof.excalidraw.png]]
>%%[[WB_t_proof.excalidraw.md|🖋 Edit in Excalidraw]]%%

#todo 
# Queries 

## Access

>[!example] 
>$access(6)$
>![[WB_t_access.excalidraw.png]]
>%%[[WB_t_access.excalidraw.md|🖋 Edit in Excalidraw]]%%

**Time** : $O(\log \sigma)$ 
## Rank

>[!example] 
>![[WB_t_rank.excalidraw.png]]
>%%[[WB_t_rank.excalidraw.md|🖋 Edit in Excalidraw]]%%

**Time** : $O(\log \sigma)$

## Select

To answer $select_C(i)$ start in the *leaf* relative to the character $C$ and navigate up to the root 

#todo 

# Final Result

Any string $S \in \Sigma^n$ can be stored in $nH_0 + o(n \log \sigma)+O(\sigma \log n)$ *bits* so that **access**, **rank** and **select** queries take $O(\log \sigma)$ *time* 

>[!note]- 
>$\sigma = |\Sigma|$
>
>If $\sigma = O(1)$ ( constant ) then the *space* simplifies to $nH_0 +o(n)$ and queries are solved in time $O(1)$

## Wavelet Trees of *concatenation* of string

#todo 

