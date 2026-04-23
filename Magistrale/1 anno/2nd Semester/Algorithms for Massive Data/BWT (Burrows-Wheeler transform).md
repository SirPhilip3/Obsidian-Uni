---
publish: true
---
The **BWT** is a string *permutation* that :
+ Given *RSA* ( *rank*, *select* and *access* ) queries on the **BWT** will enable **count** queries on the original string
+ **BWT** is *easier* to *compress* than the original string 
# Construction

1. Compute all *string rotations* 

|     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- |
| b   | a   | n   | a   | n   | a   | $   |
| a   | n   | a   | n   | a   | $   | b   |
| n   | a   | n   | a   | $   | b   | a   |
| a   | n   | a   | $   | b   | a   | n   |
| n   | a   | $   | b   | a   | n   | a   |
| a   | $   | b   | a   | n   | a   | n   |
| $   | b   | a   | n   | a   | n   | a   |


2. **Sort** them lexicographically 

|     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- |
| $   | b   | a   | n   | a   | n   | a   |
| a   | $   | b   | a   | n   | a   | n   |
| a   | n   | a   | $   | b   | a   | n   |
| a   | n   | a   | n   | a   | $   | b   |
| b   | a   | n   | a   | n   | a   | $   |
| n   | a   | $   | b   | a   | n   | a   |
| n   | a   | n   | a   | $   | b   | a   |


3. The **BWT** is the last column of the matrix 

|     |     |     |     |     |     | **BWT** |
| --- | --- | --- | --- | --- | --- | ------- |
| $   | b   | a   | n   | a   | n   | *a*     |
| a   | $   | b   | a   | n   | a   | *n*     |
| a   | n   | a   | $   | b   | a   | *n*     |
| a   | n   | a   | n   | a   | $   | *b*     |
| b   | a   | n   | a   | n   | a   | *$*     |
| n   | a   | $   | b   | a   | n   | *a*     |
| n   | a   | n   | a   | $   | b   | *a*     |
## BWT and [[Suffix trie-tree-array#Suffix Array|SA]]

The text position of the $i$-th matrix row is $SA[i]$

$S=banana\$$

| **SA** |     |     |     |     |     |     |     |
| ------ | --- | --- | --- | --- | --- | --- | --- |
| *7*      | $   | b   | a   | n   | a   | n   | a   |
| *6*      | a   | $   | b   | a   | n   | a   | n   |
| *4*      | a   | n   | a   | $   | b   | a   | n   |
| *2*      | a   | n   | a   | n   | a   | $   | b   |
| *1*      | b   | a   | n   | a   | n   | a   | $   |
| *5*      | n   | a   | $   | b   | a   | n   | a   |
| *3*      | n   | a   | n   | a   | $   | b   | a   |

>[!note] 
>If we consider the string $S$ as being circular ( $S[0] = S[n]$ ), then :
>$$
>BWT[i] = S[SA[i]-1]
>$$
>
>>[!important] 
>>**BWT** can be computed via [[Suffix trie-tree-array#Suffix Array|SA]] and can be viewed as a *compressed* [[Suffix trie-tree-array#Suffix Array|SA]]

## LF property

We don't want to store the whole matrix in memory, the *first* ( **F** ) and the *last* ( **L** or **BWT** ), in fact the *first* is simply the *last* but ordered lexicographically 

| **F** |     |     |     |     |     | **L** |
| ----- | --- | --- | --- | --- | --- | ----- |
| *$*     | b   | a   | n   | a   | n   | *a*   |
| *a*     | $   | b   | a   | n   | a   | *n*   |
| *a*     | n   | a   | $   | b   | a   | *n*   |
| *a*     | n   | a   | n   | a   | $   | *b*   |
| *b*     | a   | n   | a   | n   | a   | *$*   |
| *n*     | a   | $   | b   | a   | n   | *a*   |
| *n*     | a   | n   | a   | $   | b   | *a*   |
>[!note] 
>We can actually recover *F* from *L* using the **LF** *property*

>[!important] LF property
>
>The $i$-th occurrence of $c \in \Sigma$ in **L** is the same *text position* as the $i$-th occurrence of $c \in \Sigma$ in **F**

>[!note] 
>This works because the occurences of a character in both **L** and **F** are sorted according to the *suffix* that follows them

#todo add animation 

![[missi_test.excalidraw.png]]
%%[[missi_test.excalidraw.md|🖋 Edit in Excalidraw]]%%

We can see that **LF** moves us *backwards* in the original text , if we want to go *forward* we can just use $FL=LF^{-1}$ 
## BWT Compression Boosting property

Let $S \in \Sigma^n$ , Recall that [[Wavelet Trees (WT)]] uses $nH_0 + o(n \log \sigma)$ *bits* ( [[Empirical Entropy ( Zero-order )]] )

>[!important] Claim
>$WT(BWT(S))$ uses $nH_k+o(n \log \sigma)$ *bits* for a small ( logarithmic in $n$ ) context lenght $k$ 
>
>We can achieve [[High-Order empirical entropy]] 

**Proof**

