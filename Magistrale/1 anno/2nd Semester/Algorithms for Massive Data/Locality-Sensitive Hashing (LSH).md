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
	1. Achieved by *combining* several *distance-sensitive hash* functions , one is the [[Introduction to sketching#Jaccard Similarity and MinHash|Jaccard distance]] between sets ( $MinHash(\hat{h})$ is the hash function with *collision probability* related to the *Jaccard distance* )  

