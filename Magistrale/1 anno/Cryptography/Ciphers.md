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
