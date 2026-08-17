---
publish: true
---
A *cipher* is defined through two functions :
+ **Encryption** : given a *plaintext* and *key* $K_{1}$ returns a *ciphertext* :
$$
E_{K_{1}}(X) = Y
$$
+ **Decryption** : given a *ciphertext* and a *key* $K_{2}$ returns a *plaintext* :
$$
D_{K_{2}}(Y) = X
$$
Keys $K_{1}$ and $K_{2}$ are *related* :
$$
D_{K_{2}}(E_{K_{1}}(X))=X
$$
>[!note] 
>+ When $K_{1}=K_{2}$ we have a *symmetric* key cipher like [[AES]]
>+ When $K_{1}\neq K_{2}$ we have an *asymmetric* key cipher like [[Magistrale/1 anno/1st Semester/Cryptography/RSA|RSA]] 

>[!important] 
>It should be *infeasible* to compute $X$ or $K_{2}$ from $Y$ even knowing other pairs $(X_{1},Y_{1}), \dots,(X_{n}, Y_{n})$

## Collision Resistant hash functions

>[!note] Hash Function definition
>
>A hash function $h$ computes efficiently a *fixed lenght* value $h(x)=z$ called **digest** from an $x$ of *arbitrary size*
>
>>[!important] 
>>Collision are possible where $h(x_{1})=h(x_{2})$

>[!important] Collision Resistant hash function
>A hash function $h$ is *collision resistant* if it is infeasible to compute different $x_{1}$ , $x_{2}$ such that $h(x_{1})=h(x_{2})$

## One-way hash function

>[!important] One-way hash function
>A hash function $h$ is *one-way* if given a digest $z$ it is infeasible to compute a *pre-image* $x'$ such that $h(x')=z$

![[Pasted image 20260817154808.png]]

# Cryptographic vulnerabilities

+ **Vulnerabilities in applications** : this can reveal *keys* or *downgrade* to less secure mechanisms

>[!example] 
>Heartbleed is a vulnerability in *OpenSSL* , an *over-read* allows for accessing process memory where the *server keys* were stored and is then possible to perform a *MITM attack*

+ **Insecurity of mechanism** : Crypto mechanisms are *not equally* *secure*
## AES-ECB attacks

If we use [[AES]] with *ECB* mode to split a long message there is a weekness where since :
1. each block is *encrypted* in the same way breaks *confidentiality*
>[!example] 
>![[Pasted image 20260817161226.png]]
>
>Simply substituting some blocks we can get the following 
>![[Pasted image 20260817161257.png]]

1. swapping encrypted blocks also swaps plaintext blocks breaks *integrity*
>[!example] 
>
>We can switch some blocks around so that we forge new messages
>
>

### Chosen plaintext attack in ECB

If an attacker can *prepend* arbitrary *prefix* to the plaintext then we can bruteforce blocks byte after byte

We prepend $15$ *known* bytes and then bruteforce the last byte until we find it matching with the first *ciphertext* 

---

+ **Configuration and managment** : The *configuration* and *managment* of cryptographic systems is complex and error prone 

In [[Block cipher modes#Counter mode (CTR)|CTR]] mode for block ciphers we need an initial *random* **nonce** , if we use a *fixed* **nonce** for more than one plaintext we can leak the *plaintext* from two *ciphertext* :

>[!note] 
>Same *nounce* means same key $K$

$P_{1}\oplus K = C_{1}$ and $P_{2}$

+ **Cryptanalysis** : Improvements in technology and cryptanalysis require better crypto

