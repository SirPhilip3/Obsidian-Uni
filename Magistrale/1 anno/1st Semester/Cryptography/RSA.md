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

#todo 