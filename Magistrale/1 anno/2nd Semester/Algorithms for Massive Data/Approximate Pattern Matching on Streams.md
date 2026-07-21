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

+ If $HD(A,B)=0$ then for every $i \in [d]$ : $\kappa(A_{i,d})=\kappa(B_{i,d})$ 
+ If $HD(A,B)=1$ then there exists *only one* $i \in [d]$ such that $\kappa(A_{i,d}) \neq \kappa(B_{i,d})$ 
+ If $HD(A,B)>1$ and $d$ does *not divide* the *distance* $|j-i|$ between at least two mismatches $i,j$ then there *exist* *at* *least* *two* $i \in [d]$ such that $\kappa(A_{i,d})\neq \kappa(B_{i,d})$ 

>[!error] 
>We can't know the distances between mismatches since $A$ and $B$ must be built *independently*

We know that the distance $|j-i|$ between two mismatches is a number in $[n]$ ( size of the two patterns )

We also know that the number of *distinct **prime** divisors* that $|j-i|$ can have are no more than $\log_{2} n$ 

We then *try* all $d \in P = \{2,3,5,7,11,\dots,(\log_{2} n)-\text{th prime number}\}$ 

Then for sure *for every pair* $(i,j)$ of mismatches *at least one* $d \in P$ will *not divide* $|j-i|$ 

```pseudo
	\begin{algorithm}
	\caption{}
	\begin{algorithmic}
	\Input The sketches of $A$ and $B$
	\Output $HD(A,B)$ if $HD(A,B) \leq 1$, otherwise return "$HD(A,B)>1$"
	\ForAll{$d \in P$}
		\State compute number $c_d$ of integers $i \in [d]$ such that $\kappa(A_{i,d}) \neq \kappa(B_{i,d})$
    \EndFor
    \State $c \leftarrow \max\{c_d : d \in P \}$
    \If{$c \leq 1$}
	    \Return $c$
    \Else
	    \Return "$HD(A,B)>1$"
    \EndIf
	\end{algorithmic}
	\end{algorithm}
```

The sketch will be : 
$$
sketch(A)=\big( \kappa(A_{1,d}),\dots,\kappa(A_{d,d}) \big)_{d \in P}
$$
The size of the sketch is :
$$
O((\log n)^2\log \log n) \text{ words}
$$
>[!note]-
>$$
>\text{Total Size} = \underbrace{O(\log n)}_{\text{Levels } d \in P} \times \underbrace{O(\log n)}_{\text{Components per level}} \times \underbrace{O(\log \log n)}_{\text{Words per sketch } \kappa} = \mathbf{O((\log n)^2 \log \log n) \text{ words}}
>$$

The with $k=1$ we have :
+ If $HD(A,B)=0$ then for *every* $d \in P$ and *every* $i \in [d]$ : $\kappa(A_{i,d})=\kappa(B_{i,d})$ 
+ If $HD(A,B)=1$ then for *every* $d \in P$ there exists *only one* $i \in [d]$ such that $\kappa(A_{i,d}) \neq \kappa(B_{i,d})$ 
+ If $HD(A,B)>1$ then there *exists* $d\in P$ and $i \neq j \in [d]$ such that $\kappa(A_{i,d})\neq \kappa(B_{i,d})$ and $\kappa(A_{j,d}) \neq \kappa(B_{j,d})$ 

All of the above cases can be *distinguished with high probability* using our sketch

## Streaming Algorithm

While the streamed text $x$ arrives :
+ *Copy* every stream character $|P|= \log n$ *times* , creating $\log n$ parallel streams of $x^1,\dots,x^{|P|}$
+ Stream $x^d$ is *divided* into $d$ sub-streams : $x_{i,d}^d$ for each $i \in [d]$
+ Run [[Porat&Porat Algorithm|Porat&Porat]] on each sub-stream and each $y_{i,d}$

>[!example] 
>+ $x=abracadabra$
>+ $y=abba$
>+ $n=4$
>+ $P=\{2,3\}$
>
>![[Screenshot 2026-07-21 162000.png]]
>
>In this case even if we have $13$ parallel instances of [[Porat&Porat Algorithm|P&P]] we check the results of only $5$ instances , the ones corresponding to the relative partition that we want to check
>
>When a new character arrives the patitioning remains the same, every block is switched to the next "index" ( the next coloring )
>
>![[Screenshot 2026-07-21 163607.png]]

>[!note] 
>Only $\log n$ really change so we need to recheck their hashes

Since [[Porat&Porat Algorithm|Porat&Porat]] has $O(\log n)$ *delay* here we will have $O((\log n)^2)$ 

In terms of *space* we have :
+ $O(\log n)$ stream copies 
+ $O(\log n \log \log n)$ *sub-stream* , since we have to store each prime number partition
+ For each sub-stream: at most $O(\log n \log \log n)$ [[Porat&Porat Algorithm|P&P]] instances , each of those takes $O(\log n)$ *space*

So in *total* :
$$
O((\log n)^4(\log \log n)^2)
$$
---
>[!important] Theorem
>Given a stream :
>$$
>y_{1},\dots,y_{n}\ , \ x_{1},\dots,x_{m}
>$$
>
>after receiving every $x_{j}$ ( $j \geq n$ ) we can report which of the following occurs :
>+ $HD(y_{1},\dots,y_{n},x_{j-n+1},\dots,x_{j})=0$
>+ $HD(y_{1},\dots,y_{n},x_{j-n+1},\dots,x_{j})=1$
>+ $HD(y_{1},\dots,y_{n},x_{j-n+1},\dots,x_{j})>1$
>
>With a streaming algorithm running in $O((\log n)^4(\log \log n)^2)$ words of *space* and $O((\log n)^2)$ *delay* 
>
>The algorithm returns the correct answer *with high probability*

## Generalization to $k \ge 1$

