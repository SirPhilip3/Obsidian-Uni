---
publish: true
---
Asymmetric key cryptography is also employed to develop *digital signature schemes* 

>[!important] 
>We should avoid that a signature can be cut-and-pasted to a different document
>
>*Two* different *documents* *signed* by the same entity will have *different* *signatures*

>[!important] 
>We need a mechanism to verify a singed document with respect to an entity ( the signer )

>[!warning] 
>Differently from real word in the digital word we can replicate the same document many times, in some cases we need to integrate mechanism that *avoid* *uncontrolled* replicas

A digital signature consists of two functions :
1. $Sig_{SK}(x)$ generates the signature of $x$ using a *private key* $SK$
2. $Ver_{PK}(x,y)$ checks the validity of signature $y$ on message $x$ using the *public key* $PK$ , returns :
	1. *true* if the signature is valid
	2. *false* otherwise

These functions are *easy* to *compute* knowing the *keys* 

Without knowing the *private key* it is computationally infeasible to find a message $x$ and a signature $y$ such that $Ver_{PK}(x,y)$ holds

# Digital signature with RSA

The [[Magistrale/1 anno/1st Semester/Cryptography/RSA|RSA]] can be used to implement a digital signature scheme. We let :
$$
Sig_{SK}(x)=D_{SK}(x)
$$
$$
Ver_{PK}(x,y)= \begin{cases}
true & \text{if } E_{PK}(y)=x \\
false & otherwise
\end{cases}
$$
>[!note] 
>It's *impossible* to sign without knowing $SK$, possible to check the signature knowing $PK$

>[!example] 
>$p=7$ , $q=13$, Public key $(5,91)$ , Private key $(29,91)$ , $x=2$
>
>+ $Sig_{SK}(2)=D_{SK}(2)=2^{29} \mod{91} = 32$
>+ $Ver_{PK}(2,32) =$ true if $E_{PK}(32)=32^5 \mod{91}=2$

>[!warning] 
>This doesn't satisfy the fact htat without knowing the *private key* it is computationally infeasable to find a message $x$ and a signature $y$ such that $Ver_{PK}(x,y)$ hods

## Attacks

### Forgin a random signature

We pick an arbitrary signature $y$ and we compute the corresponding *signed message* as $E_{PK}(y)$ this will give use true at the *verify* function by definition 

This is still a valid forged signature with a meaningless message 

### Multiplying signed messages

If we have two *signed messages* $x_{1},x_{2}$ with signatures $y_{1}$ and $y_{2}$ then $y_{1} \cdot y_{2} \mod{n}$ is the signature of the message  $x_{1} \cdot x_{2} \mod{n}$

If the expected message is just a number with no particular format or padding this attack might be effective

## Problems

Another problem is that the size of the signature is at least the same as the size of the message meaning that to sign a message we send double the data

# Properties for a Digital Signature

+ *Authenticity*
	+ The origin of the message is correctly identified
+ *Non-Repudiation* 
	+ The sender cannot deny the transmission of a message
+ *Integrity*
	+ The information can be modified only by authorized entities

If we use *RSA* if the message is bigger than the *modulus* it should be split into blocks , this can violate *authenticity* 

## Cryptographic hash functions

We use **cryptographic hash functions** 

>[!note] 
>An *hash function* $h: X \to Z$ is a function taking an arbitrarily long message $x$ and returning a *digest* $z$ of fixed lenght

We can modify the functions in the following way :
$$
Sig_{SK}^h(x)=D_{SK}(x)
$$
To sign $x$ we *decrypt* it's *hash* under the *private key*
$$
Ver_{PK}^h(x,y)= \begin{cases}
true & \text{if } E_{PK}(y)=x \\
false & otherwise
\end{cases}
$$
To check the signature we *encrypt* the signature under the *public key* we recompute the *hash* on $x$ and we cmopare the two results

>[!note] 
>The fact that the *hash* is of fixed lenght removes the problem of the need of  encryption modes and also the size problem

>[!warning] 
>In the first attack [[#Forgin a random signature]] then if we are able to find $x$ such that $h(x)=E_{PK}(y)$ we will have that $Ver^h_{PK}(x,y)=true$ 

These functions to be *cryptographic* needs to have some special **properties** :
### Preimage resistance

>[!important] Definition
>A hash function $h$ is *preimage resistant* ( or *one-way* ) if given $z$ it is infeasible to compute $x$ such that $h(x)=z$

Also prevents forging based on *RSA* *multiplicative property*

If we have two signed messages $x_{1},x_{2}$ with signatures $y_{1}$ and $y_{2}$ , then $y_{1} \cdot y_{2} \mod{n}$ is the signature $y$ of a message $x$ whose hash is the same as $z=h(x_{1})\cdot h(x_{2}) \mod{n}$ ( or $h(x)=z$ )

Finding such a message $x$ means that we can compute a preimage $x$ of $h$ such that $h(x)=z$ but this is *ruled* out by preimage resistance
### Second-Preimage resistance

>[!important] Definition
>A hash function is *second-preimage resistant* if *given* $x_{1}$ it is *infeasible* to *compute* $x_{2}$ such that $h(x_{1})=h(x_{2})$

This is necessary because if we can calculate another $x_{2}$ from $x_{1}$ that has $h(x_{1})=h(x_{2})$ then the signature $y_{1}$ is valid for both $x_{1}$and $x_{2}$ 

### Collision resistance

>[!important] Definition
>
>A hash function is collision resistant if it is infeasible to compute different $x_{1}$ and $x_{2}$ such that $h(x_{1})=h(x_{2})$

>[!note] 
>If a hash is collision resistant it is also second-preimage resistant and preimage resistant

This *holds* under the *assumption* that the number of *messages* we can hash is at least twice the number of digest 

>[!important] Theorem 1
>
>Let $h: X \to Z$ be a collision resistant hash function such that $|X|\ge 2 |Z|$. Then $h$ is also *preimage resistant*

To *prove* this theorem we can prove the following equivalent fact :
+ If $h$ is *not preimage resistant* then $h$ is *not collision resistant* 

We can sse that given an algorithm $Invert(z)$ for inverting $h$ ( this breaks *preimage resistance* ) we can write a *Las Vegas* probabilistic algorithm that finds a collision

The algorithm is the following : 
1. We pick a random message
2. compute it's hash
3. invert it using $Invert(z)$
4. If we find a different message we are done otherwise we *FAIL* 

We now show that failure happens with probability at most $1/2$ 

Since we have $|Z|$ possible *digest* we have that $Invert(z)$ returns exactly $|Z|$ preimages , these are the cases where messages remap to themselves

The good cases are $|X|-|Z|$ and the probability of success is :
$$
\frac{|X|-|Z|}{|X|} \ge \frac{|X|-\frac{1}{2}|X|}{|X|} =\frac{\frac{1}{2}|X|}{|X|} = \frac{1}{2} 
$$
Given that $|X| \ge 2 |Z|$ or $|Z|\le |X|/2$. As a consequence we fail with probability $\leq \frac{1}{2}$

This algorithm can be iterated as needed giving us the prob of failure of $\le \frac{1}{2}^r$

### Common Hash Functions

#### MD5

*MD5* is a $128$-bit hash function 

>[!warning] 
>It has been shown to be **not** *collision resistant* and vulnerable to *Birthday attacks*

#### SHA ( Secure Hash Algorithm )

This is also been shown to be *non-collision resistant* vulnerable to *Birthday attacks* 

*SHA-2* has a variable digest size from $224$ to $512$ bits 

*SHA-3* is it's successor
### Birthday Attack

Brute forcing a *crypto* hash function is made easier by the *Birthday attack*

>[!example] 
>Within a group of $41$ people the probability to have at least two with the same birthday is $90\%$

Birthday can be seen as a *hash function* from any person to a fixed size set of $365$ days of the year

Two people with the same birthday represent a collision on the hash function 

We assume people are being mapped to birthdays in a *uniform way* 

We can than compute the *probability* that in a group of $k$ people none share the birthday
$$
\prod_{i=0}^{k-1} \frac{365-i}{365}
$$
Then the probability of collision is :
$$
1-\prod_{i=0}^{k-1} \frac{365-i}{365}
$$
Relating to *hash functions* the probability that we do NOT find a collision is :
$$
\prod_{i=0}^{k-1} \frac{n-i}{n} = \prod_{i=0}^{k-1}\left( 1- \frac{i}{n} \right)
$$
Knowing that for small $x$ , then $1+x \approx e^x$ 

Then $1-\frac{1}{n} = e^{-1/n}$ 

Thus the probability of finding a collison is :
$$
e \approx 1- \prod_{i=0}^{k-1} e^{-i/n} = 1 -e^{-\frac{(k-1)k}{2 \cdot n}}
$$
$$
1- e \approx -e^{-\frac{(k-1)k}{2 \cdot n}}
$$
$$
\ln(1-e) \approx -\frac{(k-1)k}{2 \cdot n}
$$
By further approx we get :
$$
k \approx \sqrt{ 2n \cdot \ln(1/(1-e)) }
$$
For $e=\frac{1}{2}$ will give us $k \approx 1.17\sqrt{ n }$ 

A *brute-force* attack on a hash function with $n$ digests finds a collision with probability $\frac{1}{2}$ after  about $\sqrt{ n }$ attempts
## Message Authentication codes

*Message Authentication Codes* ( *MAC*s ) are hash functions with a *simmetric key* 

They produce a *fixed-size* digest of a message whose value depends on the given key

**Properties** :
+ Without knowing the key $k$ it should be computationally *infeasible* to find a message $x$ and a *MAC* $y$ such that $MAC_{k}(x)=y$ ( such that $y$ is the *MAC* for $x$ under key $y$ )

The *MAC* is checked by recomputing it and comparing with the received one
### CBC-based MAC

### Hash-based MAC