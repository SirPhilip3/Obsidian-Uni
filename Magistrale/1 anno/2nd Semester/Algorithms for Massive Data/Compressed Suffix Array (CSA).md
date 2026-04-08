---
publish: true
---
Using [[Suffix trie-tree-array#Suffix Array|SA]] , [[Bitvectors (RRR)|RRR]] and [[Elias-Fano]] we can obtain the following data structure : 

>[!important] Theorem
>
>The * **S**uffix **A**rray * + text can be compressed to $nH_0 +O(n)$ *bits* while retaining the following ability : 
>+ *Count* queries in $O(m \log n)$
>+ *Locate* queries in $O((m + occ) \cdot \log n)$
>+ *Extract* queries in $O(\log n + \textit{l})$

>[!note]- Notation 
>$n$ is the *corpus size* ( text size ) ,
>$m$ is the *query* size ,
>$occ$ number of times that the query appears in the text
>$l$ number of output characters

>[!note] 
>We don't need the *original text* 

For simplicity we will use the *assumption* that : 
$$
\sigma \leq \frac{n}{\log n}
$$
>[!note]- Notation
>$\sigma$ is the *alphabet size* 

1. This *implies* : 
$$
\begin{align}
\log \sigma \leq & \ \log \bigg( \frac{n}{\log n} \bigg) \\
\log \sigma \leq & \ \log n - \log(\log n)
\end{align}
$$
Noting that $\log n$ is surely $\leq \log n - \log(\log n)$ we get : 
$$
\log \sigma \leq \log n
$$

2. Also : 
$$
\begin{align}
\sigma \log \sigma \leq &\ \sigma \log n \\
\sigma \log \sigma \leq &\ \frac{n}{\cancel{\log n}}\cdot  \cancel{\log n} \\
\sigma \log \sigma \leq &\ n
\end{align}
$$
 >[!important] 
 >The *assumption* is not true when the string is a permutation of $[n] \ (\sigma = n)$ , numbers from $1 \to n$
 
# Binary searching *without* [[Suffix trie-tree-array#Suffix Array|SA]] and text 

To do this we would need to build a *black-box* that allows us to extract the $i$-th suffix
## 1) string F

We need to store at least the *first character* of every *suffix* in sorted order  

>[!example] 
>
>| **i** | 1   | 2   | 3   | 4   | 5   | 6   | 7   |
>| ----- | --- | --- | --- | --- | --- | --- | --- |
>| **F** | *$*   | *A*   | *A*   | *A*   | *B*   | *N*   | *N*   |
>|       |     | $   | N   | N   | A   | A   | A   |
>|       |     |     | A   | A   | N   | $   | N   |
>|       |     |     | $   | N   | A   |     | A   |
>|       |     |     |     | A   | N   |     | $   |
>|       |     |     |     | $   | A   |     |     |
>|       |     |     |     |     | $   |     |     |

In order to store **F** we mark in a [[Bitvectors (RRR)]] **FO** the *first occurrence* of every character , and store just *one* occurrence of every chatacter in a vector $\Sigma$ of size $\sigma$ 

>[!example] 
>| i            | 1   | 2   | 3   | 4   | 5   | 6   | 7   |
>| ------------ | --- | --- | --- | --- | --- | --- | --- |
>| F            | $   | A   | A   | A   | B   | N   | N   |
>| **FO**       | *1* | *1* | *0* | *0* | *1* | *1* | *0* |
>| **$\Sigma$** | *$*   | *A*   | *B*   | *N*   |     |     |     |

This will have *Space* : 
$$
\leq n + o(n) + \sigma \log \sigma = O(n)
$$
*bits* 

>[!note] 
>Keeping in mind the *assumption* that $\sigma \leq \frac{n}{\log n}$
### Queries

With $F$ we can extract the *first character* of the $i$-th *suffix* by doing the following operation :
1. $FO.rank_1(i)$
2. Access the result in $\Sigma$

## 2) $\psi$ function

In order to extract the other *characters* of the $i$-th *suffix* we build the $\psi$ *mapping function*

$\psi$ is build by noting that the second character of a *suffix* is the starting character of the same *suffix* without the first character

>[!example] 
>The second character of `ANA$` is the first character of the *suffix* `NA$` 
>

So $\psi$ is build in the following way : 
+ For each $i$ write down the *index* of the remaining *suffix*, build by removing the first character of the current *suffix*, taken from the *sorted suffixes*

>[!example] 
>
>![[CSA_psi_build.mp4]]

Also formally we can say that : 
$$
\psi[i] = SA^{-1}[SA[i]+1]
$$
## Full query 

Now getting the full $i$-th *suffix* is simply a matter of applying $\psi$ *recursively*

>[!example] 
>Extracting the $3$-rd *suffix* : 
>1. $F[3] = A$
>2. $F[\psi[3]=6]=N$
>3. $F[\psi[6]=2]=A$
>4. $F[\psi[2]=1]=\$$
# Compressing $\psi$

We would like to *compress* $\psi$ to $nH_0$ *bits* while maintaning the ability to compute $\psi[i]$ in $O(1)$ *time* 

>[!note] Idea
>We can notice that the *sub-array* of $\psi$'s corresponding to a group of *identical character* in $F$ are **sorted in increasing order**
>
>This must be true since the *suffixes* are sorted *lexicographically*

A data structure that is efficent in storing *sorted list of integers* is [[Elias-Fano]] 

We build one [[Elias-Fano]] data structure per each block of $\psi$'s relating to a single *character* in $F$ 

>[!example] 
>