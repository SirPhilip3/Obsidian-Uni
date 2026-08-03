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
+ the *tree* is **balanced** with *height* equal to $O(\log \sigma)$
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

*Let* :
+ $S\in \Sigma$ be the *string*, of lenght $n$, represented in the *Wavelet Tree* above of *height* $h+1$ 
+ $\sigma = |\Sigma|$ 
+ $N_0$ , $N_1$ be the *number* of $0$ and $1$ in the *root* ( $n=N_0 + N_1$ )

>[!note] 
>$|S_0|=N_0$ and $|S_1|=N_1$

Let's partition the alphabet $\Sigma$ of $S$ as $\Sigma = \Sigma_{0}\cup \Sigma_{1}$ : 
+ Character in $\Sigma_{0}$ are the one that start with $0$ 
+ Character in $\Sigma_{1}$ are the one that start with $1$ 

>[!note] 
>+ The *subtrees* $S_{0}$ and $S_{1}$ are over the alphabets $\Sigma_{0}$ and $\Sigma_{1}$ respectively
>+ Both $S$ and $S_0$ have $n_c$ occurences of character $c$ ( same for $S_1$ )

Then $S_{0}$ is compressed in the following *space* :
$$
N_{0} \cdot \left( \sum_{c\in \Sigma_{0}} \frac{n_{c}}{N_{0}} \log \frac{N_{0}}{n_c} \right) + o(h \cdot N_{0})
$$

We can notice that 
$$
\sum_{c\in \Sigma_{0}} \frac{n_{c}}{N_{0}} \log \frac{N_{0}}{n_c}  = H_{0}(S_{0})
$$
The *root* instead takes the following *space* :
$$
n\cdot \left( \sum_{b\in \{0,1\}} \frac{N_{b}}{n} \log \frac{n}{N_{b}} \right) + o(n)
$$
In total we have :
$$
\begin{align}
S_{0}+S_{1}+Root = \\  \\
\cancel{N_{0}} \cdot \left( \sum_{c\in \Sigma_{0}} \frac{n_{c}}{\cancel{N_{0}}} \log \frac{N_{0}}{n_c} \right) + o(h \cdot N_{0})\ & +  \\
\cancel{N_{1}} \cdot \left( \sum_{c\in \Sigma_{1}} \frac{n_{c}}{\cancel{N_{1}}} \log \frac{N_{1}}{n_c} \right) + o(h \cdot N_{1})\ & + \\
\cancel{n}\cdot \left( \sum_{b\in \{0,1\}} \frac{N_{b}}{\cancel{n}} \log \frac{n}{N_{b}} \right) + o(n)
\end{align}
$$
The small o's becomes : $o(n \cdot (h+1))=o(n \log \sigma)$

So we have :
$$
\sum_{c \in \Sigma_{0}} n_{c} \log \frac{N_{0}}{n_{c}} + \sum_{c \in \Sigma_{1}} n_{c} \log \frac{N_{1}}{n_{c}} + N_{0} \log \frac{n}{N_{0}} + N_{1} \log \frac{n}{N_{1}}
$$
>[!note] 
>+ $N_0 = \sum_{c \in \Sigma_0} n_c$
>+ $N_1 = \sum_{c \in \Sigma_1} n_c$

Summing the *first* and *third* and the *second* and *fourth* we get :
$$
\begin{align}
\sum_{c \in \Sigma_{0}} n_{c}\log \left( \frac{N_{0}}{n_{c}} \cdot \frac{n}{N_{0}} \right) + \sum_{c \in \Sigma_{1}} n_{c}\log \left( \frac{N_{1}}{n_{c}} \cdot \frac{n}{N_{1}} \right)& =  \\
\sum_{c \in \Sigma_{0}} n_{c}\log \frac{n}{n_{c}} + \sum_{c \in \Sigma_{1}} n_{c}\log \frac{n}{n_{c}} & = \\
\sum_{c \in \Sigma} n_{c} \log \frac{n}{n_{c}}& = n H_{0}
\end{align}
$$
>[!important] Theorem
>The *Wavelet Tree* of string $S \in \Sigma^n$ stored using *RRR bitvectors* in the nodes uses :
>$$
>n H_{0}(S) + o(n \log \sigma)
>$$
>bits of space
>>[!note] 
>>Assuming $\sigma = |\Sigma|=o(n/\log n)$
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

We can prove that the **WT** of the concatenation of strings reaches the [[Empirical Entropy ( Zero-order )|Zero-order entropies]] of those strings  

>[!important] Theorem
>Let $WT\_size(S)$ be the bit-size of $WT(S)$ 
>
>Let $S_i \in \Sigma^{n_i}$ for $i=1,\dots,t$, be $t$ *strings* of total lenght $n = \sum_{i=1}^{t} n_i$. Then:
>
>$$
>WT\_size(S_1S_2\dots S_t) \leq \bigg (  \sum_{i=1}^{t} n_i H_0(S_i) \bigg) + o(n \log \sigma) + O(t \sigma \log n)
>$$

