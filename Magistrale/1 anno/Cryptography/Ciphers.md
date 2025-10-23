---
publish: true
---
# Symmetric Ciphers

Mathematical model to describe a **Symmetric Encryption System** $(P,C,K,E,D)$ where : 
+ $P$ : the *set* of *plaintexts*
+ $C$ : the *set* of *ciphertexts*
+ $K$ : the *set* of *keys* 
+ $E: k \times P \rightarrow C$  is the *encryption* function 
+ $D: k \times C \rightarrow P$ is the *decryption* function

>[!note] Notation
>+ $E_k(x)$ where $x \in P$ and $k \in K$ rapresents the *encrytion* of the *plaintext* $x$ with *key* $k$
>+ $D_k(y)$ where $y \in C$ and $k \in K$ rapresents the *decryption* of the *ciphertext* $y$ with *key* $k$

>[!important] Propieties
>+ $D_k(E_k(x))=x$ : decrypting an encrypted text with the same *key* $k$ gives the original *plaintext*
>+ Computing $k$ or $x$ given a *ciphertext* $y$ needs to be *infeasible*

>[!note] 
>There should be a **secure channel** where we transmit the agreed *key*

We have two types of ciphers : 
+ **Monoalphabetic**
	+ The letters of the *plaintext* are mapped to *ciphertext* based on a single alphabetic key 
	+ Some are : [[Caesar Cipher]] , [[Shift Cipher]] , [[Substitution Cipher]]
+ **Polyalphabetic** 
	+ The same letters of the *plaintext* are not always mapped to the same *ciphertext* 
	+ Some are : [[Vigenere Cipher]] , [[Hill Cipher]]

Other types of *ciphers* are the [[Block ciphers]]
# Perfect Cipher

>[!important] Definition 1
>A *perfect cipher* is a cipher that can never be broken , even after an unlimited time 

>[!important] Definition 2
>A cipher system is said to offer *perfect secrecy* if on seeing the *ciphertext* the attacker gets **no extra information** about the *plaintext* 

>[!note] 
>This condition needs to hold in the [[Types of Attaks#Ciphertext-only attack|Ciphertext-only]] attack scenario
 
These type of ciphers are *unpractical* but they exists , they are made in a way here the *attacker* is forced to **guess** the *plaintext* 

## Probability distribution on the ciphertexts

+ $P_P(x)$ : the probability of a *plaintext* $x$ occurring
+ $P_K(k)$ : the probability of a certain *key* $k$ to be used as *encryption* key

>[!note] 
>Given a *plaintext* and a *key* there exists a unique corresponding *ciphertext* 

With this probabilities defined we can introduce the probability of the *ciphertexts* :
$$
P_C(y) = \sum_{k\in K , \exists x : E_k(x) = y} P_K(k) P_{p}(D_k(y))
$$
Or given a *ciphertext* $y$ we look for all the *keys* that can give $y$ from some *plaintext* $x$ , we than sum all the *probabity* of all of these keys times the probability of the corresponding *plaintext* to get the final probability of *ciphertext* $y$

>[!example] 
>

**Conditional Probability** :
	The *conditional probability* of *ciphertext* $y$ given *plaintext* $x$ computes how likely is that we observe a certain *ciphertext* given an input *plaintext*
$$
P_{C}(y|x) = \sum_{k \in K , E_k(x)=y} P_K(k)
$$
Or simply the sum of the *probability* of all keys giving $y$ from $x$

Knowing the [[Legge di Bayes|Bayers Theroem]] we can rewrite the *conditional probability* of a *plaintext* $x$ with respect to a *chipertext* $y$ as : 
$$
P_p(x|y) = \frac{P_p(x)P_C(y|x)}{P_C(y)}
$$

>[!important] Perfect Cipher Definition
>A *cipher* is **perfect** $\iff P_p(x|y) = P_p(x), \quad \forall x \in P \land \forall y \in C$  
>
>>[!note] 
>>Or if observing a *chipertext* $y$ gives no information about the possible *plaintexts* $x$

So a *perfect cipher* is one where there is some key that maps any message to any chipertext with equal probability

>[!important] Theorem 1
>Let $P_C(y) >0 \forall y$. A *cipher* is perfect only if $|k| \geq |P|$
>>[!note] 
>>Or a necessary condition for a perfect cipher is that the number of *keys* is at least the same as the number of *plaintexts*

>[!check] Proof
>#todo

>[!important] Theorem 2
>Let $|P| = |C| = |K|$. A *cipher* is perfect $\iff$ : 
>1. $P_K(k) = 1/|K|,  \quad \forall k \in K$
>2. For each $x \in P$ and $y \in C$, there exists exactly one key $k$ such that $E_K(x) = y$  

# Modern Ciphers

## AES 

