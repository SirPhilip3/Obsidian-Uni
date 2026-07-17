---
publish: true
---
With *locality-sensitive hashing* we want that if $x$ and $y$ are *similar* under some metric than we want that $h(x)=h(y)$ with *large probability*

>[!example] Example application
>
>Suppose we want to find *similar pairs* of elements ( they have *small* $d(x,y)$ for some metric $d$ ) 
>
>A distance-preserving sketch speeds up the computation of $d(x,y)$ but we still need to compute $O(|A|^2)$ distances
>
>To solve this issue we could use an *hash function* $h$ suche that $\mathbb{P}(h(x)=h(y))$ *increases* as $d(x,y)$ *decreses*
>
>We then put in the same *bucket* all objects with the same hash and check $d(x,y)$ only inside buckets

We start by fixing a distance threshold $t$, such that $h(x)=h(y)$ if and only if $d(x,y)\le t$

>[!note] 
>The *collision probability* would be the following graph : 
>![[Pasted image 20260716180323.png]]
>
>We *won't be able to achieve this*
>
>But we can get close to a perfect function , but the *closer* we want to get *to a perfect step function* the *more hash function* we need to use ( using more space and time )
>
>![[Pasted image 20260716180659.png]]
>
>


The *most* *informative* description of an *LSH* is the *plot* of collision probability vs distance, however we want a more **compact** description :

We just store what happends in *two points* on the curve close to the step 

>[!important] Definition
>A $(d_{1},d_{2},p_{1},p_{2})$-sensitive family of hash functions $\mathscr{H}$ is such that, for a uniformly-chosen $g \in \mathscr{H}$ we have :
>+ If $d(x,y) \le d_{1}$, then $\mathbb{P}(g(x)=g(y)) \ge p_{1}$
>+ If $d(x,y) \ge d_{2}$, then $\mathbb{P}(g(x)=g(y)) \le p_{2}$
>
>![[Pasted image 20260716182405.png]]
>
>The function in the plot is $(0.48,0.6,0.75,0.12)$-sensitive
>
>>[!note] 
>>Generally we are free to choose the two points, ideally :
>>+ $d_{1} \approx d_{2}$
>>+ $p_{1} \approx 1$
>>+ $p_{2} \approx 0$
>>
>>Or as close as possible to the perfect step function

## Bulding the LSH function

1. Start from a *simple function* ( straight line )
2. Apply *two transformations* to the function, making it resemble a step function
	1. Achieved by *combining* several *distance-sensitive hash* functions

One is the [[Introduction to sketching#Jaccard Similarity and MinHash|Jaccard distance]] between sets ( $MinHash(\hat{h})$ is the hash function with *collision probability* related to the *Jaccard distance* )  

![[Pasted image 20260717145924.png]]

This is a **bad** *approximation* of a step function 

To compose *hash* functions we need to define the **AND** and **OR** operation between them
### AND construction

>[!important] Definition
Let $\mathscr{H}$ be a $(d_{1},d_{2},p_{1},p_{2})$-sensitive family.
>
>Choose uniformly $r$ independent hash functions $h_{1},\dots,h_{r} \in \mathscr{H}$ and define :
>$$
>h^{AND}(x) = (h_{1}(x),\dots,h_{r}(x))
>$$

If $\mathbb{P}(h(x)=h(y)) = p$ for a uniform $h \in \mathscr{H}$, then :
$$
\mathbb{P}(h^{AND}(x)=h^{AND}(y)) = p^r
$$
Hence $h^{AND}$ is a $(d_{1},d_{2},p_{1}^r,p_{2}^r)$-sensitive hash function

In case of **Jaccard distance** we have :
$$
\mathbb{P}(\hat{h}(A)=\hat{h}(B)) = 1-d_{J}(A,B)
$$
$$
\mathbb{P}(\hat{h}^{AND}(A)=\hat{h}^{AND}(B)) = \Big(1-d_{J}(A,B)\Big)^r
$$
The associated *plot* is the following :

```functionplot
---
title: Collision Probability vs Distance
xLabel: distance
yLabel: collision probability
bounds: [-0.05,1,-0.05,1]
disableZoom: true
grid: true
---
f(y)=(1-x)^1
g(y)=(1-x)^2
z(y)=(1-x)^4
h(y)=(1-x)^8
```
>[!warning] 
>This is not a *step function* yet

### OR construction

>[!important] OR definition
>Let $\mathscr{H}$ be a $(d_{1},d_{2},p_{1},p_{2})$-sensitive family.
>
>Choose uniformly $b$ independent hash functions $h_{1},\dots,h_{r} \in \mathscr{H}$ 
>
>We say that $x$ and $y$ collide, denoted with $h^{OR}(x) \equiv h^{OR}(y)$, if and only if $h_{i}(x)=h_{i}(y)$ for *at least one* $i \in [b]$

>[!example] 
>
>Suppose we have $m$ data points $x_{1},\dots, x_{m}$ , we want to quickly find all the $x_{i}$ such that $h^{OR}(x_{i})\equiv h^{OR}(y)$ , for a new incoming point $y$
>
>We build $b$ *hash tables* $H_{1},\dots,H_{b}$ and insert $x$ in bucket $H_{i}[h_{i}(x)]$ for each $i \in [b]$.
>
>Two elements *collide* if and only if they and up in the *same bucket* in *at least one hash table* 

If $\mathbb{P}(h(x)=h(y)) = p$ for a uniform $h \in \mathscr{H}$, then :
$$
\mathbb{P}(h^{OR}(x)=h^{OR}(y)) = 1-(1-p)^b
$$

Hence $h^{OR}$ is a $(d_{1},d_{2},1-(1-p_{1})^b,1-(1-p_{2})^b)$-sensitive hash function
#### Proof

For a fixed $i$ we have that $\mathbb{P}(h_{i}(x)\neq h_{i}(y)) = 1 -p$ , subsequently the probability that *all hashes* **do not collide** is :
$$
\mathbb{P}(\land_{i=1}^b h_{i}(x)\neq h_{i}(y)) = (1-p)^b
$$
The probability that *at least* **one hash collides** is :
$$
\begin{align}
\mathbb{P}(\lor_{i=1}^b h_{i}(x)=h_{i}(y)) & = \\
& = 1- \mathbb{P}(\land_{i=1}^b h_{i}(x) \neq h_{i}(y)) \\
& = 1 - (1-p)^b
\end{align}
$$
### AND+OR construction

