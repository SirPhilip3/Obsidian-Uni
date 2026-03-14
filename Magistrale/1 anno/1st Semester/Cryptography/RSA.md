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


