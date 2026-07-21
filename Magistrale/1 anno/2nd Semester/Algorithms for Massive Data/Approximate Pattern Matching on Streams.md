---
publish: true
---
We will use [[Porat&Porat Algorithm|Porat&Porat]] as a *blackbox* to solve *approximate pattern matching* on streams under the **Hamming** and **Edit** distances.
# Hamming distance (HD)

>[!important] Definition
>
>Given two strings $A$ and $B$ of the *same lenght* $n$ their *Hamming Distance* is:
>
>$$
>HD(A,B) = \sum_{i=1}^n (A[i]\neq B[i])
>$$
>

We want to compute $HD(A,B)$ *exactly with high probability* , provided that $HD(A,B) \le k$ 

The working *space* and *delay* will be $poly(k \log n)$
## Sketch for Hamming Distance

Given $k$ ( max distance ) reduce the computation of $HD(A,B)$ to *exact pattern matching*
+ Partition $A$ and $B$ into $t \ge k$ *subsequences* $A_{1},\dots,A_{t}$ and $B_{1},\dots,B_{t}$ 
+ We want that *each pair* $(A_{i},B_{i})$ contains *at most* **one** *mismatch* $A[j]\neq B[j]$ 

Hence the number of *mismatching subsequences* will equates to the **Hamming distance**

Starting from $k=1$ ( maximum $1$ mismatch ) we distinguish three cases : 
+ $HD(A,B)=0$ , or $A=B$
+ $HD(A,B)=1$ 
+ $HD(A,B)>1$ 

---

Let $A=ab\textcolor{red}{r}acadabra$ , $B=ab\textcolor{red}{b}acadabra$ with one mismatch in red

>[!important] Definition
>$A_{i,d}$ is the subsequence of $A$ defined as :
>$$
>A[i] \cdot A[i+d] \cdot A[i+2d] \dots
>$$

For example with $d=2$ we get :
+ $A_{1,2}=a\textcolor{red}{r}cdba$
+ $B_{1,2}=a\textcolor{red}{b}cdba$
+ $A_{2,2}=baaar$
+ $B_{2,2}=baaar$

The *mismatch* will be sent to just **one** of the two $i$ parts ( in this case $i=1$ )
$$
A_{1,2} \neq B_{1,2} \quad \text{and} \quad A_{2,2}=B_{2,2}
$$
>[!note] 
>The checks can be done by *hashing*

>[!warning] 
>It's *not* always true that the number of mismatching pairs is $=HD(A,B)$ 
>
>>[!example] 
>>Let $A=ab\textcolor{red}{r}aca\textcolor{red}{d}abra$  and $B=ab\textcolor{red}{b}aca\textcolor{red}{a}abra$
>>
>>In this case we will have :
>>+ $A_{1,2}=a\textcolor{red}{r}c\textcolor{red}{d}ba$
>>+ $B_{1,2}=a\textcolor{red}{b}c\textcolor{red}{a}ba$
>>+ $A_{2,2}=baaar$
>>+ $B_{2,2}=baaar$
>>
>>We still have that $A_{1,2} \neq B_{1,2}$ and $A_{2,2}=B_{2,2}$ so $1$ would be the number of mismatching pairs but the actual number is $2$
>>
>>This happends because $d=2$ divides the mismatches by distances so all mismatches that are pair will go in the same partition

#todo 
