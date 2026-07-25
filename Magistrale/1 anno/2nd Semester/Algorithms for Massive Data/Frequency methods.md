---
publish: true
---
We want to estimate *aggregations of frequencies* 

>[!important] Definition
>Let $k\ge 0$ be an *integer*. Let $f_{x}$ be the number of occurrences of $x \in [n]$ on a stream ( multi-set ) of lenght $m$. The $k$-th **frequency moment** is defined as :
>$$
>F_{k}=\sum_{x \in [n]} f_{x}^k
>$$

$F_{1}$ is then the *length* $m$ of the stream 

>[!note] 
>$F_{1}$ admits the trivial sketch of $\log m$ *bits*, if we use the [[Frequency Estimation on Streams#Morris Algorithm|Morris Algorithm]] then we can use only $O(\log \log m)$ *bits*

$F_{0}$ is also the number of *distinct elements* in the steam ( letting $0^0=0$ )
## Counting distinct elements

Counting the ***exact*** *distinct elements* would mean storing the entire stream , in most application we dont care about the *exact* number just an approximation of it 

Let : 
+ $x_{1},\dots,x_{m}\in [n]^*$ be our *stream*
+ $d$ be the number of *distinct stream elements*

Some solution for computing $d$ are the following :
+ [[Bitvectors (RRR)]] , taking $n$ *bits* of *space*
+ *Hash table* , taking $O(d \log m)$ *bits* of *space* 
+ [[Introduction to sketching#Jaccard Similarity and MinHash|MinHash]] in $O(\epsilon^{-2}\log(1/\delta))$ words of *space*, returning $d \pm \epsilon \cdot n$ with *probability* $1-\delta$ 
>[!note] 
>For the [[Introduction to sketching#Jaccard Similarity and MinHash|MinHash]] implementation $d=J(stream,[n])\cdot n$

>[!warning] 
>*Uniform sampling* *doesn't work* to estimate distinct elements since the probability to sample an element is proportional to it's frequency , so  we are going to *miss rare elements*

## Flajolet-Martin (FM) algorithm

>[!info] Idea
>
>1. Draw $d$ distinct elements $x_{1}<x_{2}<\dots<x_{d}$ *uniformly at random* from $[n]$
>2. If we repeat this with a *larger* $d$, then the smallest element $x_{1}$ will become *smaller* ( on *expectation* ) 
>
>Then $d$ can be expressed as a function of $x_{1}$, the sketch is just $x_{1}$ 
>
>>[!warning] 
>>If the elements are *not uniform* in $[n]$ we just *randomize* them with *hashing* 
>
>>[!note] 
>>Also if the stream contains *repeated elements* the minimum $x_{1}$ is *not effected*

The following is the *idealized* algorithm

```pseudo
	\begin{algorithm}
	\caption{Initialization()}
	\begin{algorithmic}
	\State $h \leftarrow$ uniform function from $[n]$ to real numbers in $[0,1]$
	\State $y \leftarrow 1$ 
	\end{algorithmic}
	\end{algorithm}
	
	\begin{algorithm}
	\caption{new_stream_element(x)}
	\begin{algorithmic}
	\State $y \leftarrow \min{y,h(x)}$
	\end{algorithmic}
	\end{algorithm}
	
	\begin{algorithm}
	\caption{estimate_distinct()}
	\begin{algorithmic}
	\Return $\frac{1}{y}-1$
	\end{algorithmic}
	\end{algorithm}
```
### `estimate_distinct()` correctness

The $d$ distinct values $\{y_{1}<\dots < y_{d}\}=\{h(x_{1},\dots,h_{x_{m}})\}$ are *uniformly spread* in $[0,1]$ 

We can prove that *on expectation* they are *spread regularly* on the unit line

>[!example] 
>![[FM_div.excalidraw.png]]
%%[[FM_div.excalidraw.md|🖋 Edit in Excalidraw]]%%

So we get :
$$
\begin{align}
E[y_{1}] & = 1/(d+1) \\
d & = 1/E[y_{i}]-1
\end{align}
$$
The estimatore returns instead : $1/y_{1}-1$ and having that :
$$
E[1/y_{1}-1]\neq 1/E[y_{1}] -1
$$
We are dealing with a **biased estimator**
