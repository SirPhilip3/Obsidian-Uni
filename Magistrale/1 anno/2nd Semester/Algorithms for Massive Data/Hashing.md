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

>[!important] Definition
>
>Let $U=\{x_1,\dots,x_n\}$ be our universe ( $n=|U|$ ). We say that $\mathcal{H}$ is *uniform* if and only if, for any $y_1,\dots,y_n$ ( not necessarily distinct ) :
>$$
>\mathbb{P}\bigg( (h(x_1,\dots,h(x_n))=(y_1,\dots,y_n)) \bigg) = \frac{1}{M^n}
>$$ 

We can prove that $\mathcal{H}=[0,M)^U$ is the *only possible* *uniform family* of hash functions 

**Proof**

Let $\mathcal{H}' \neq \mathcal{H}$ then : 
+ $|\mathcal{H}'| < |\mathcal{H}|$ since $\mathcal{H}$ has all the possible function and so to be different $\mathcal{H}'$ needs to have at least one less function

Let $h$ be that function that's $\in \mathcal{H}$ but not $\mathcal{H}'$

Let $y_i = h(x_i)$ , $\forall x_i \in U$ , than it must be that for any $h' \in \mathcal{H}'$ we will have that :
$$
(h'(x_1),\dots,h'(x_n)) \neq (y_1,\dots,y_n)
$$
Hence :
$$
\mathbb{P}\bigg( (h'(x_1),\dots,h'(x_n)) = (y_1,\dots,y_n) \bigg) = 0 \neq \frac{1}{M^{|U|}}
$$
This implies that $\mathcal{H}'$ is **not** *uniform*

#### Space

To store a function $h$ from $\mathcal{H}$ we need :
$$
\log_2 |\mathcal{H}| = \log_2 M^{|U|} = |U|\log_2 M
$$
*bits*

>[!example] 
>Let the $U$ the space of IPv4 addresses $|U|=2^{32}$ 
>Let $M=2$ 
>
>So a function *unifromly-chosed* $h \in \mathcal{H}$ maps an IPv4 address $x$ to a uniform bit $h(x)$
>
>Storing $h$ requires $2^{32} = 512MiB$ of *space*

### k-wise independent Hasing

>[!info] Idea
>
>We dont care that *all* $h(x_1),\dots,h(x_n)$ are *iid uniform numbers* since our input will rarely be that large 

We fix a maximum $k$ for which $(h(x_1),\dots,h(x_k))$ is *uniform* in $[0,M)^k$

>[!important] Definition
>
>$\mathcal{H}$ is *k-wise independent* iff , for a uniform choice of $h \in \mathcal{H}$ : 
>+ for any distinct $x_1,\dots,x_k\in U$
>+ for any ( not necessary distinct ) $y_1,\dots,y_k\in [0,M)$ 
>  
>$$
>\mathbb{P}\big( (h(x_1),\dots,h(x_k)) \neq (y_1,\dots,y_k) \big) = \frac{1}{M^k}
>$$

For $k=2$ we call it *pairwise-independent hasing*

>[!example] 
>Let $U = [n]$ then:
>
>$\mathcal{H} = \{ax + b\mod{M} : a,b \in [0,M)\}$ is *pairwise-independent* if $M \ge n$ is the *power* of a *prime* number

#### Proof

Choose *uniformly* :
+ $h \in \mathcal{H}$ and 
+ $a,b \in [0,M)$

Choosing any *distinct* $x_1,x_2 \in [n]$ and any $y_1,y_2 \in [0,M)$ we need to *prove* that :
$$
\mathbb{P}\big( h(x_1) = y_1 \land h(x_2) = y_2 \big) = \frac{1}{M^2}
$$
Now by *definition* of $h$ we get : 
$$
\mathbb{P}(ax_1+b \equiv_M y_1 \land ax_2+b \equiv_M y_2)
$$
Solving for $a$ and $b$ we get : 
$$
\mathbb{P} \bigg( a \equiv_M \frac{y_2 - y_1}{x_2-x_1} \land b \equiv_M y_1 - x_1 \cdot \frac{y_2 - y_1}{x_2-x_1}\bigg )
$$
Since $a$ and $b$ are *independent* we get : 
$$
\mathbb{P}\bigg( a \equiv_M \frac{y_2 - y_1}{x_2-x_1} \bigg)\cdot \mathbb{P}\bigg( b \equiv_M y_1 - x_1 \cdot \frac{y_2 - y_1}{x_2-x_1} \bigg)
$$
 
Since we have chosen distinct $x_1,x_2 \in [n]$ then $x_1 \neq x_2$ 

Also since $M \ge n$ then $x_2-x_1 \not\equiv_M 0$

Now since $M$ is the power of a *prime number*, $(x_2-x_1)^{-1} \mod{M}$ *exists* since $\mathbb{Z}_M$ is a *field*

Sice everything is defined and $\mod{M}$ each of the right sides will be a number between $[0,M)$

Let's call them $z_1, z_2$ 
$$
\mathbb{P}\big( a \equiv_M z_1 \big)\cdot \mathbb{P}\big( b \equiv_M z_2 \big)
$$
Now the probability that $a$ or $b$ are a particular number from $[0,M)$ is $1/M$ , than we can write the following : 
$$
\mathbb{P}\big( a \equiv_M z_1 \big)\cdot \mathbb{P}\big( b \equiv_M z_2 \big) = 1/M \cdot 1/M = M^{-2}
$$
Now generalizing the proof to a general $k$ we get : 

>[!important] Theorem
>Let $U = [n]$ and $k \leq n$. Then : 
>$$
>\mathcal{H} = \Bigg\{ \sum_{i=0}^{k-1} a_i x^i \mod{M}\ :\ a_0, \dots, a_{k-1} \in [0,M) \Bigg\}
>$$
>Is *k-wise independent* if $M \ge n$ is the *power of a prime number*
>
>or : *random polynomials of degree $k-1$ over the field $\mathbb{Z}_M$* are *k-wise independent*

#### Example

$$h(x) = \sum_{i=0}^{k-1} a_ix^i \mod{M}$$
Is a *k-wise independent hash familty*

To encode a function $h$ of this family we will need $k\log M$ *bits* , where : 
+ $k$ is the total lenght of the *polynomial*
+ $\log M$ is the bit size necessary to encode each integer $a_i$ 

The time complexity to compute $h(x)$ is $O(k)$ ( using [Horner method](https://en.wikipedia.org/wiki/Horner%27s_method) )

This is small for $k$ small and since in most application $k \in O(1)$ its *good enough*

### Universal Hashing

*Universal Hashing* is a **weaker** version of $k$-wise independence 

>[!important] Defintion
>$\mathcal{H} \subseteq [0,M)^U$ is a *universal* hash family $\iff$  for a unifrom choice of $h \in \mathcal{H}$ and any two distinct $x_1,x_2 \in U$ :
>$$
>\mathbb{P}(h(x_1) = h(x_2)) \leq 1/M
>$$

Universal hasing *guarantees* that the *probability of collision* between two elements is at most $1/M$ , or the probability that we would obtain from a completely uniform hash function 

#### Proof 

>[!important] Theorem
>If $\mathcal{H}$ is *pairwise independent* then $\mathcal{H}$ is *universal*

$$
\mathbb{P}\big(h(x_1) = h(x_2)\big) =
$$
By [law of total probabibility](https://en.wikipedia.org/wiki/Law_of_total_probability) we get that : 
$$
\begin{align}
\sum_{y \in [0,M)}\mathbb{P}\big( h(x_1) = h(x_2) \land h(x_2) = y\big) & = \\
\sum_{y \in [0,M)} \mathbb{P} \big( h(x_1) = y \land h(x_2) = y \big) & = \\
\end{align}
$$
Now by *pairwise independence* we will have : 
$$
\sum_{y \in [0,M)} M^{-2} = 1/M
$$
