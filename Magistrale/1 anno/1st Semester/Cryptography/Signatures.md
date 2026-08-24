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

We use **cryptographic hash functions** 

#todo 