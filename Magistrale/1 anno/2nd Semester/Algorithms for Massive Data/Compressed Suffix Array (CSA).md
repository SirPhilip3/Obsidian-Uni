Using [[Suffix trie-tree-array#Suffix Array|SA]] , [[Bitvectors (RRR)|RRR]] and [[Elias-Fano]] we can obtain the following data structure : 

>[!important] Theorem
>
>The ***S**uffix **A**rray* + text can be compressed to $nH_0 +O(n)$ *bits* while retaining the following ability : 
>+ *Count* queries in $O(m \log n)$
>+ *Locate* queries in $O((m + occ) \cdot \log n)$
>+ *Extract* queries in $O(\log n + \textit{l})$

