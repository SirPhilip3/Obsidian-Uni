---
publish: true
---
# Randomization

It's often easier to design algorithms under the *assumption* that $x_1, \dots, x_m$ are *random*

>[!example]- 
>[Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort) allows us to perform *sorting* on $x_1,\dots,x_m$ distributed uniformly in *expected* $O(m)$ time

However generally $x_1,\dots,x_m$ are **not** *random* , we use *hashing* to randomize this input
# Hashing

Let our data $x_1,\dots,x_m$ consist of elements from the universe $x_i \in U$ ( strings , integers ecc. )

>[!important] Definition
>A *hash function* is a function $h: U \to [0,M)$ chosen *uniformly at random* from a finite family ( set ) $\mathcal{H}$ of functions

>[!note] 
>The random choice is done just *once* at the *beginning* of the algorithm, then the same $h$ is used during the whole execution

## Randomization via Hashing

Typical randomized algorithm : 
1. Input $x_1,\dots,x_m$ 
2. Draw $h$ uniformly from $\mathcal{H}$ 
3. Perform the computation on $h(x_1),\dots,h(x_m)$
4. Return result of computation

>[!example] 
>Given *family* $\mathcal{H}=\{ax^2+bx+c \mod{M} : a,b,c \in [0,M)\}$ 
>Input : $13,39,2,87,50$
>
>1. We uniformly choose $4x^2 +5x +1 \mod 7$ as hash function
>2. Applying it to the input : $h(13) = 0, h(39)=1, h(2)=6, h(87)=3, h(50)=3$
>3. Run the algorithm on them
## Properties

*Desired properties* for the family $\mathcal{H}$ :
1. $h(x_1), \dots, h(x_m)$ should be *as random as possible* , beahving like $m$ independent uniform numbers from $[0,M)$
2. $h(x)$ should be *fast to compute* , ideally 
	1. $O(1)$ if $x$ is an *integer*
	2. $O(|x|)$ if $x$ is a *string, set etcc*
3. The infromation needed to compute $h(x)$ should occupy as *small space* as possible
### Space

Choosing from the *family* of $\mathcal{H}=\{ax^2+bx+c \mod{M} : a,b,c \in [0,M)\}$ is equivalent in choosing *uniformly* from three coefficents $a,b,c \in [0,M)$

For a *general* $\mathcal{H}$ in the **worst** case the space needed is the [[Worst-case Entropy]] or $\log_2 |\mathcal{H}|$

>[!example] 
>For $\mathcal{H}=\{ax^2+bx+c \mod{M} : a,b,c \in [0,M)\}$  we need to store all the possible combinations of $a,b,c$ so : $M^3$
>
>The final bit space will be : 
>$$
>\log_2|\mathcal{H}| = \log_2 M^3 = 3 \log_2 M
>$$ 
>*bits*

### Randomness 

There is a **tradeoff** between *space* efficency and *randomness* , in fact the smaller $\mathcal{H}$ is the less space it take but also the less random it will be  

>[!example] 
>If $|\mathcal{H}|=1$ than $h(x)$ will always be the same , giving no randomness

>[!example] 
>Given instead $\mathcal{H}=[0,M)^U$ , the set of *all* functions $h : U \to [0,M)$
>
>$h(x)$ behaves like a *uniform number* in $[0,M)$
>In general over distinct $x_1,\dots,x_k \in U$ we will have that $(h(x_1),\dots,h(x_k))$ is a *unifrom element* from $[0,M)^k$ , achieving *maximum randomness*

### Uniform Hash Family

#todo 

