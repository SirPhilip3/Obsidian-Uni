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
>
>Let's assume that the *cipher* is perfect than $p_P(x|y) =p_P(x)$ , that implies $p_C(y|x) = p_C(y)$ ( from the [[Legge di Bayes|Bayers Theroem]] ) 
>
>Assuming that $p_C(y) > 0$ than if we fix $x$ we obtain that for each $y$  $p_c(y|x) = p_c(y) >0$ meaning that there exists *at least one key* $k$ such that $E_k(x)=y$
>
>All of this keys are different since $E_k$ is a function and given a unique $x$ this can't be mappet to two different *chipertexts* by the same key
>
>Thus : $|K| \geq |C|$
>
>Since any cipher injects the set of *plaintexts* into the set of *ciphertext* we also have $|C| \geq |P| \implies |K| \geq |C| \geq |P| \implies |K| \geq |P|$ 


>[!important] Theorem 2
>Let $|P| = |C| = |K|$. A *cipher* is perfect $\iff$ : 
>1. $P_K(k) = 1/|K|,  \quad \forall k \in K$
>2. For each $x \in P$ and $y \in C$, there exists exactly one key $k$ such that $E_K(x) = y$  
>>[!note] 
>>Or for a *cipher* to be *perfect* ( given that the size of $P,K,C$ is the same ) keys should be picked at random for any *encryption* and each *plaintext* is mapped into each *ciphertext* throgh a unique key   

>[!check] Proof
>#todo

## One Time Pad 

The *one time pad* is a *pefect cipher* , its a *binary* variant of the [[Vigenere Cipher]] 

Where we have that : 
+ $P = C = K = \mathbb{Z}_{2^d}$
+ $P_K(k) = 1/|K| = 1/ 2^d \quad \forall k \in K$

$E_{k1, \dots,k_d}(x_1,\dots x_d) =  (x_1 \text{ xor } k_1, \dots, x_d \text{ xor } k_d)$

>[!check] Proof
>Using *Theorem 2* we see that the *hypotesis* of $|P| = |C| = |K|$ holds since $|K| = d, |P| = d, |C| = d$ 
>Condition $1$ also hods by definition of the *one time pad*
>
>Condition $2$ : given $x \in P$ and $y \in C$ we than have that the *unique* key giving $y$ from $x$ can be computed as : $x \text{ xor } y$ 
>
>We can than conculated that the *cipher* is *perfect*

>[!note] 
>In general *perfect ciphers* require as many keys as the possible *plaintext* and *keys* must be picked at random for each *encryption*
# Modern Ciphers

## Cipher Composition

>[!note] 
>*Combining* simple *ciphers* does not always improve security

>[!example] 
>Consider the combination of $2$ *shift* chipers :
>
>$$
>\begin{matrix} X & \rightarrow & \fbox{Shift} & \rightarrow & \fbox{Shift} & \rightarrow & Y\\ & & \uparrow & & \uparrow \\ & & k1 & & k2 \end{matrix}
>$$
>
>This equates to :
>$$
>\begin{matrix} X & \rightarrow &\fbox{Shift}& \rightarrow & Y\\ & & \uparrow \\ & & \begin{matrix}{k1+k2}\\{\mod 26}\end{matrix} \end{matrix}
>$$

>[!important] Definition
>Consider two *ciphers* : $S^1 = (P^1,C^1,K_1,E^1,D^1)$ and $S^2 = (P^2,C^2,K_2,E^2,D^2)$ 
>
>We can say , whithout lusing generalization that $P^1 = C^1 = P^2 = C^2$
>
>We can now than define the composition as : 
>$S^1 \times S^2 = (P,C,K_1 \times K_2, E,D)$
>
>Where :
>+ $E_{k_1, k_2}(x) = E^2_{k_2}(E^1_{k_1}(x))$
>+ $D_{k_1, k_2}(y) = D^1_{k_1}(E^2_{k_2}(y))$

## Idempotent ciphers

>[!important] Definition
>A *cipher* is said to be *idempotent* when $S \times S = S$ 

In *modern ciphers* at least one operation must be **non** idempotent 

>[!important] Definition
>
>If we have two *idempotent* ciphers that **commute** ( $S^1 \times S^2 = S^2 \times S^1$ ) than their *composition* is also idempotent
>
>>[!check] Proof
>>
>>$$
>>\begin{array}{ll}(S^1 \times S^2) \times (S^1 \times S^2)\\ = S^1 \times (S^2 \times S^1) \times S^2 &\mbox{ associative property}\\ = S^1 \times (S^1 \times S^2) \times S^2 &\mbox{ commutative property}\\= (S^1 \times S^1) \times (S^2 \times S^2) &\mbox{ associative property}\\ = S^1 \times S^2 &\mbox{ idempotence of the initial ciphers} \end{array}
>>$$

## AES 

*Advanced Encryption Standard* is a *symmetric* cipher that is composed of simple , linear , operation and one *non-linear component* in order to avoid known-plaintexts attacks

The composed operations give a *non-idempotent cipher* that is iterated for a fized number of *rounds*

**AES** works on *Galois Field* with $2^8$ elements ( $GF(2^8)$ ) 

It's the set of all $8$-bit digits with *sum* and *multiplication* performed the bits as binary coefficents of polynomials 

>[!example] 
>`11010011` can be seen as : $x^7+x^6+x^4 + x +1$ 
>`00111010` can be seen as : $x^5+x^4+x^3+x$ 
### Sum

It behaves like binary *xor*

>[!example] 
>$(x^7+x^6+x^4+x+1) + (x^5+x^4+x^3+x) =x^7 +x^6 +x^5+x^3+1$
>
>Rapresenting it as bits : 
>$$\begin{align}& 11010011 & \oplus \\ & 00111010 & \\ = & 11101001 & \end{align}$$
### Multiplication

The multiplication is done normally summing each exponent modulus the *irriducible* polynomial ( it can't be written as the *product* of two other polynomials ) : $x^8+x^4+x^3+x+1$ 

>[!example] 
>$$\begin{aligned}
(x^7+x^6+x^4+x+1)(x^5+x^4+x^3+x) 
&= x^{12}+x^{11}+x^{10}+x^8+x^{11}+x^{10}+x^9+x^7 \\
&\quad +x^9+x^8+x^7+x^5+x^6+x^5+x^4+x^2+x^5+x^4+x^3+x \\
&= x^{12}+x^6+x^5+x^3+x^2+x
\end{aligned}$$
>>[!note] 
>>The sum is done as before
>
>Now we need to *devide* by the *irreducible* polynomial and return the *remainder*
#### Division

The division is performed on the basis of the *xor* operation with the *irreducible* polynomial where the *remainder* will be the result

Shift the *irreducible* polynomial to the left in order to align it with the original oplynomial than execute the *xor* operation , repeat until the resulting polynomial has maximum exponent $\le 8$

$$
\begin{array}{ccccccccccccc}1&0&0&0&0&0&1&1&0&1&1&1&0 \\ 1&0&0&0&1&1&0&1&1 \\\hline & & & &1&1&1&0&1&1&1&1&0\\ & & & &1&0&0&0&1&1&0&1&1 \\\hline & & & & &1&1&0&0&0&1&0&1 \end{array}
$$
#### Multiplication optimization

The following algorithm is an optimization for the *multiplication* operation in $GF(8)$ : 

1. Given the two polynomials to multiply $a$ and $b$ ( written in binary form )
2. Set $p$ to $0$
3. Check the least significant bit of $b$ 
4. If it's a $1$ 
	1. Change $p$ to the result of $p \oplus a$ 
	2. Append a $0$ to $a$ in it's least significant position
	3. Remove the $1$ from $b$
5. If it's a $0$ 
	1. Append a $0$ to $a$ in it's least significant position
	2. Remove the $1$ from $b$
	3. Don't change $p$ 
6. Repeat until $b$ is empty and *return* $p$

>[!example] 
>#todo

### AES Schema

**AES** operates on $4\times 4$ matrix of bytes and given the plaintext subdivided into *bytes* these get's distribuite in the following way : 
$$
\begin{bmatrix}b_1 & b_5 & b_9 & b_{13} \\ b2 & b_6 & b_{10} & b_{14} \\ b_3 & b_7 & b_{11} & b_{15}\\ b_4 & b_8 & b_{12} & b_{16}\end{bmatrix}
$$

*AES* can work with the following *key* and *round* lenght : 

| Key lenght | Rounds |
| ---------- | ------ |
| 128 bit    | 10     |
| 192 bit    | 12     |
| 256 bit    | 14     |

Each *round* is composed of the following operations : 
+ bitwise *xor*
+ fixed *non-linear* substitution
+ *shifting* of matrix rows
+ matrix column multiplications

#### AddRoundKey

This operations is simply a *bitwise* *xor* with the *key*

>[!example] 
>
>![[AES-AddRoundKey.svg]]
#### SubBytes

It's a fixed *non-linear* **substitution** called *S-box* this get's applied to *each byte* of the block 

Given the byte in exadecimal notation than the *first digit* is used to select the *row* and the *second* to select the *column* in the **fixed** reference matrix

>[!example] 
>`0x25` would be the third row and the sixth column giving `0x3f`

![[AES-SubBytes.svg]]

This is the *S-box* :

![[512253718012_gf3.jpg]]

#### ShiftRows

The *rows* are shifted to the *left* by : $0,1,2,3$ respectively

![[AES-ShiftRows.svg]]

#### MixColumns

Each *column* gets *xored* with the **fixed** matrix $c(x)$

![[AES-MixColumns.svg]]

Where $c(x)$ is the following *matrix* : 
$$
\begin{bmatrix}2&3&1&1\\1&2&3&1\\1&1&2&3\\3&1&1&2\end{bmatrix}
$$
