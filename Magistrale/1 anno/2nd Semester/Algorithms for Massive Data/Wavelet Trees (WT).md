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
n \log \sigma + O(\sigma \log n ) + O(\sigma \log n)
$$
# Queries 

## Access

## Rank

# Final Result