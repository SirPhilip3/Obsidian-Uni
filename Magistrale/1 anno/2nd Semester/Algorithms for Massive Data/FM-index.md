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

Memorize a separate $C$ array containing the *positions* of the first occurrence of every $c\in \Sigma$ 
 