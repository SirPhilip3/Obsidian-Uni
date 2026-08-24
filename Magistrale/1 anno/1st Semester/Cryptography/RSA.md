---
publish: true
---
## Euler Function

The **RSA** cipher is based on the **Euler function** $\phi(n)$ : given a number $n$ it returns the *number* of *numbers* than are $\leq n$ and are *coprime* ( $\gcd(i,n) = 1$ ) to $n$ 

>[!example]
>$\phi(3) = 2$ since both $1$ and $2$ are *coprime* with $3$
>
>$\phi(4) = 2$ since only $1$ and $3$ are *coprime* with $4$
>

>[!note]
>If $n$ is *prime* than $\phi(n)=n-1$ 

>[!important] 
>If $n=p_1 \cdot \ldots \cdot p_k$ where $p_1 \neq p_2 \neq \dots \neq p_k$ and $p_i$ are *prime* than we have that : 
>$$
>\phi(n) = \phi(p_1)\cdot \ldots \cdot \phi(p_k) = (p_1 -1) \cdot \ldots \cdot (p_k-1)
>$$
>
>>[!example] 
>>$n=3 \cdot 5=15$ than $\phi(15) = 2\cdot 4 = 8$

**Proof**

Let's consider $n=pq$ with $p\neq q$ *primes* , than the number $<n$ that are not *coprime* with $n$ must be *mutiples* of $p$ and $q$ so :
+ For $p$ : $p,2p,\dots,(q-1)p$
+ For $q$ : $q,2q,\dots,(p-1)q$ 

That are $q-1$ for $p$ and $p-1$ for $q$ so in total $(q-1)+(p-1)$

Than we will have that : 
$$
\phi(n)=pq-1-(q-1)-(p-1) = pq-q-p+1 = (p-1)(q-1)
$$
## Cipher

**Key generation** : 
+ Compute two distinct *big* *prime* numbers $p$ and $q$
+ Compute $n=pq$ and $\phi(n)=(p-1)(q-1)$
+ *Choose* a small number $a$ , *prime* with $\phi(n)$ and smaller than $\phi(n)$
+ Compute the *unique* $b$ such that $a \cdot b \mod{\phi(n)} = 1$ 

Now we define :
+ $PK = (b,n)$
+ $SK = (a,n)$

>[!note] 
>Assuming that $C=P=Z_n$ 

Now we define : 
+ **Encryption** of $x$ : $E_{PK}(x) = x^b \mod{n}$
+ **Decryption** of $y$ : $D_{SK}(y) = y^a \mod{n}$

>[!example] 
>We select $p=5$ and $q = 11$ than $n=55$ and $\phi(55) = (5-1) \cdot (11-1) = 40$
>
>Let's *choose* $a$ prime and less than $40$ , $a=23$
>
>$b$ can be computed using the [[Inverse of an Integer#Extended Euclidian Algorithm|Extended Euclidian Algorithm]] , this will give us $b=7$
>
>Now we have $PK = (7,55)$ and $SK=(23,55)$
> 
>Now we can perform *encryption* : $E_{PK}(2) = 2^7 \mod{55} = 18$
>
>While *decryption* will be $D_{SK}(y)=18^{23} \mod{55} = 2$ 

### Correctness

We need to show that *decrypting* under the private key a plaintext $x$ encrypted under the public key gives $x$

Or check :
$$
D_{SK}(E_{PK}(x))=x
$$
First we need to *prove* the **Euler Theorem** :

#### Euler Theorem Proof

Let $a$ and $n$ be *coprime* ( $gcd(a,n)=1$ ) then $a^{\phi(n)} \mod{n}=1$

*Proof* :
	Let $S=(s_{1},\dots,s_{\phi(n)})$ be the $\phi(n)$ *numbers* less than $n$ and coprime with $n$

We consider $R=(a\cdot s_{1} \mod{n}, \dots, a \cdot s_{\phi(n)}\mod{n})$ and we *show* that $S=R$ 

>[!important] Lemma 1
>Let $x,y$ be *coprime* to $n$. Then $x \cdot y$ is coprime to $n$
>
>*Proof* :
>	All the divisors of $x\cdot y$ are products of the divisors of $x$ and / or $y$ thus a common divisor of $x\cdot y$ and $n$ must also divide $x$ and / or $y$. Thus $\gcd(x\cdot y,n)>1$ would imply that the $\gcd(x,n)>1$ and / or $\gcd(y,n)$ giving a *contradiction*

>[!important] Lemma 2
>Let $x$ be coprime to $n$. Then $x \mod{n}$ is coprime to $n$
>
>*Proof* :
>	Since $x \mod{n} = x - k \cdot n$ we have that any common divisor $d$ of $x \mod{n}$ and $n$ must divide $x$

>[!important] Lemma 3
>Let $a\cdot x \mod{n} = a \cdot y \mod{n}$ with $\gcd(a,n)=1$ . Then $x \mod{n}=y \mod{n}$ 
>
>*Proof* :
>	We have that $a\cdot x - k \cdot n = a \cdot x \mod{n} = a \cdot y \mod{n} = a \cdot y - j \cdot n$ . Thus we will have that $a \cdot x - a \cdot y =k \cdot n - j \cdot n$ , we can also write $w=k-j$ 
>	We then imply $x-y = w \cdot n/a$ 
>	Since $\gcd(a,n)=1$ we have that $a$ must divide $w$ and so $x-y =t \cdot n$ 
>>[!note] 
>>$w=t \cdot a$ , substituting $t = \frac{w}{a}$ 
>
>Then applying the $\mod{n}$ we get : $(x-y)\mod{n} = t \cdot n \mod n$ ,
>$$
>\begin{align}
>(x-y) \mod{n}& = 0  \\
>x \mod{n}& = y \mod{n}
>\end{align}
>$$

Now using the *previous lemmas* :
By *lemma 1* and *2* we have that all numbers in set $R=(a \cdot s_{1} \mod{n}, \dots, a \cdot s_{\phi(n)}\mod{n})$ are *coprime* to $n$ and smaller than $n$

Since $S$ is the set of all numbers coprime to $n$ and smaller than $n$ we obtain $R \subseteq S$ 

Now considering $a \cdot s_{i}\mod{n}$ and $a\cdot s_{j}\mod n$ in $R$.

Since $a$ is *coprime* to $n$ by *lemma 3* we can say that $a \cdot s_{i}\mod{n} = a \cdot s_{j}\mod{n}$ this implies $s_{i} \mod{n} = s_{j} \mod{n}$ which gives a *contradiction* since in $s_{i}$ would be equal to $s_{j}$ which are two different number taken from $R$

We have that then $a \cdot s_{i} \mod{n} \neq a \cdot s_{j} \mod{n}$ proving that $R=S$ 

>[!note] 
>This is because we have proven that $\forall i,j$ we have that $a \cdot s_{i} \mod{n} \neq a \cdot s_{j} \mod{n}$ meaning that no element can be a duplicate and since $R$ is a subset of $S$ then $R$ and $S$ must contain the same elements 

Now since $S=R$ we have :
$$
\prod_{i=1}^{\phi(n)} s_{i} = \prod_{i=1}^{\phi(n)} a s_{i} \mod{n} = a^{\phi(n)} \prod_{i=1}^{\phi(n)} s_{i} \mod n 
$$
Now using $P=\prod_{i=1}^{\phi(n)} s_{i}$ we get :
$$
\begin{align}
P & = a^{\phi(n)} P \mod n \\
\frac{P}{P} & = a^{\phi(n)} \frac{P}{P} \mod{n} \\
1 &= a^{\phi(n)} \mod{n}
\end{align} 
$$

#### RSA Correctness

>[!note] 
>$a\cdot b \mod{\phi(n)}=1$ implies $a \cdot b = k \cdot \phi(n)+1$ for some $k$

We have that :
$$
\begin{align}
D_{SK}(E_{PK}(x))& = (x^b \mod{n})^a \mod n \\
&= (x^b)^a \mod n = x^{a\cdot b} \mod{n}
\end{align}
$$
We need to prove that $x^{a\cdot b} \mod{n} = x$

We notice now that : 
$$
\begin{align}
x^{a\cdot b} \mod{n} & = x^{k \cdot \phi(n)+1} \mod{n} \\
& = (x^{\phi(n)})^k \cdot x \mod{n}
\end{align}
$$
Thus to finish the proof it's enough to show that :
$$
(x^{\phi(n)})^k \cdot x \mod{n} = x
$$
The proof is split into *two cases* :
1. $\gcd(x,n)=1$

In this case we know that the *Euler theorem* holds and directly have that : $x^{\phi(n)} \mod{n} = 1$ which implies $(x^{\phi(n)})^k \mod{n} = 1$

2. $\gcd(x,n)>1$

In this case since $x<n$ we have that either :
+ $\gcd(x,n)=p$
+ $\gcd(x,n)=q$

The two proofs are identical 

We now have $x=j \cdot p$ for some $j$ and $\gcd(x,q)=1$ ( as $x<n$ ) which for *Euler theorem* gives $x^{\phi(q)} \mod{q}=1$ 

This implies that $x^{\phi(q) \phi(p)} \mod{q}=x^{\phi(n)} \mod{q}=1$ 

This implies that $(x^{\phi(n)})^k \mod{q}=1$

We also have 
$$
(x^{\phi(n)})^k = w \cdot q +1
$$
For some $w$ by definition of modulus

Then we have the following :
$$
\begin{align}
(x^{\phi(n)})^k \cdot x \mod{n} & =  \\
(w \cdot q + 1) \cdot x \mod{n} & =  \\
(w \cdot q + 1) \cdot (j \cdot p) \mod{n} &=  \\
(w\cdot q \cdot j \cdot p + j \cdot p) \mod{n} &=  \\
(w\cdot j \cdot n + x) \mod n & = \\
\end{align}
$$
Since $b \cdot x \mod x = 0$ we have
$$
(0+x) \mod{n} =x
$$

### Implementation

*RSA* requires a big modulus $n$ of at least $1024$ bits making the cipher secure

>[!warning] 
>With this size implementation becomes an issue , in fact *linear complexity* $O(n)$ is prohibitive as it could require $2^{1024}$ steps

+ **Sum** can be performed in $O(k)$ 
+ **Multiplication** can be performed in $O(k^2)$
+ **Division** can be performed in $O(k^2)$ 

>[!warning] 
>A important problem is the **Exponentiation** , we cannot implement exponentiation to the power of $b$ as $b$ multiplications since it would require $k^{2} \cdot 2^k$ or $O(2^k)$
>
>Which is like *brute-forcing* the secret trapdoor and infeasable for $k\geq 1024$

#### Square-and-Multiply algorithm

>[!note] Idea
>When we rise a number $x$ to a power of $2$ ( like $8$ ) we can compute $((x^2)^2)^2$ instead of doing $7$ mutliplication we do only $3$

If the exponent is not a power of $2$ we can just perform some additional multiplication :
+ If the exponent is *even* we divide by $2$ and we *square*
+ If the esponent is *odd* we get one out and then divide the rest by $2$ and *square* 

In *binary* operations we get

Starting from the most significant bit. At each step we *square* and only when we have a $1$ we *multiply* by $x$

>[!example] 
>Compute $2^{10}$ , where $10=1010$ and $x=2$
>
>1. $r=1$ , $r=1\cdot 1$ + since the bit is $1$ we do $r = r\cdot x = 1 \cdot 2 =2$ 
>2. $r=2 \cdot 2 = 4$ , the remaining most significant bit is $0$ so no multiplication
>3. $r = 4 \cdot 4=16$ , $r=r \cdot x = 16 \cdot 2 = 32$
>4. $r=32 \cdot 32 = 1024$

The number of steps in the *worst case* is $O(k^2)$ for the two multiplications , iterated $k$ times we get $O(k^3)$ 

>[!note] 
>Where $k$ is the number of bits of the exponent

For $1024$ bits we expect $1b$ steps which is still somewhat *efficent* in modern machines
#### Inverse modulo

To compute the private exponent from the public one we require that :
$$
a \cdot b \mod{\phi(n)} = 1
$$
To find $a$ and $b$ :
1. choose $b$ 
2. compute it's ***multiplicative*** ***inverse** modulo* $\phi(n)$ 

>[!note] 
>This is guaranteed to exist by the *Euler theorem* when $\gcd(b, \phi(n))=1$
>

The algorithm to compute it is based on [[Inverse of an Integer#Euclidian Algorithm|Euclidian Algorithm]] for computing $\gcd$
#### Generating RSA exponents

The above algorithm works if $b$ and $\phi(n)$ are *coprime* , this happends with probability $\approx 0.6$ , iterating this $2-3$ times should give suitable pairs of public and private exponents

In *practice* $b$ is a fixed *constant* typically the prime number $2^{16}+1=65537$

>[!note] 
>Using a low exponent improves the performance of encryption , this is because each $1$ in the exponent requires an extra multiplication

*RSA security* is based on the infeasability of factoring the modulu $n$ ( $3072$ bits )

Knowing $\phi(n)$ makes it very simple to compute the private exponent $a$ 

If we compute $\phi(n)$ we can easily factor $n$ since we have the following system of equations :
$$
\begin{cases}
n = pq \\
\phi(n) = (p-1)(q-1)
\end{cases}
$$
By solving it we can find $p$ and $q$ , we thus have that finding $\phi(n)$ is *at least* *as difficult as factoring* 

#### Primality test

To *generate* *two* *big prime* numbers the oldest algorithm is *Eratosthenes* :
1. Pick all number from $2$ to $N$
2. Start from the *smallest prime* (2, initially) call it $p$ and update the list by removing all the multiples of $p$ 
3. Iterate until we finish all the prime numbers on the list, primes are the $p$'s picked

>[!example] 
>$N=10$
>Numbers from $2$ to $N$ : $\{2,3,4,5,6,7,8,9,10\}$
>
>1. Start from $2$, remove $2,4,6,8,10$ , we get $\{3,5,7,9\}$
>2. Take $3$ and remove $3,9$ , we get $\{5,7\}$
>3. Take $5$ and remove $5$
>4. Take $7$ and remove $7$
>
>Primes are $2,3,5,7$

The algorithm can be optimized by removing multiples starting from $p^2$ 

In fact any smaller $x \cdot p$ with $x<p$ would have been removed at a prevoious step

We can also stop when $p$ is the *square root* of $N$

>[!warning] 
>This algorithm takes at least $N$ steps meaning that it takes too much 

Instead of generating all the primes we *pick* them at *random* and *test* their *primality*

There are many *efficent* *probabilistic* algorithm that do *primality test* , deterministic algorithms are much slower $O(k^6)$ 
##### Miller-Rabin test

This is a *NO-biased Montecarlo* , this means it is *always correct* for the *NO* answer 

>[!note] 
>The probability of being wrong is $\le \epsilon = \frac{1}{4}$

With this we can iterate the test until the error is small enough

By running it $r$ times the probability that it says *Yes* and that the number is not prime is less than $\epsilon^r = \frac{1}{4}^r$

The complexity is $O(\log^3 n)$ *steps* ( $O(\log n)$ multiplication each multiplication costs $O(\log^2n)$ steps )

```pseudo
	\begin{algorithm}
	\caption{Prime(n)}
	\begin{algorithmic}
	\State write $n-1 = 2^k \cdot m$
	\State pick a random $a$ such that $1<a<n$
	\State
	\end{algorithmic}
	\end{algorithm}
```