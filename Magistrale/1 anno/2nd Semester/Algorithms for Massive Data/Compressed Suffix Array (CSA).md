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
 
 