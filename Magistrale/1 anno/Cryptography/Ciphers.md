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

## Some modern ciphers

+ [[AES]]
+ [[DES]]

# Public Key Cryptography 

The main problem of [[Ciphers#Symmetric Ciphers|Symmetric Ciphers]] is the need to have a different *shared key* between two users , this becomes impractical if we are in a connected network like the internet where having $n$ users we would need to exchange $n(n-1)/2$ or $O(n^2)$ keys

>[!info] Idea
>
>Each user has one *encrypting* key and one *decrypting* key . They need to be different but related in such a way that knowledge of the *public* key does not give any information abount the *private* key
>
>The *encryption* key is made public but the *decrypting* key remains a secret

Let :
+ $PK_A$ be the *public key* of A 
+ $SK_A$ be the *secret key* of A 

B sends an *encrypted* message $E_{PK_A}(M)$ to A 
A recieves it and *decrypts* it as $D_{SK_A}(E_{PK_A}(M))=M$

>[!note] 
>As before we need that *encryption* and *decryption* are such that $D_{SK_A}(E_{PK_A}(M))=M$  holds

>[!important] Asymmetric-key cipher definition
>An *Asymmetric-key cipher* is a quintuple $(P,C,K_S \times K_P, E,D)$ with :
>+ $E : K_P \times P \to C$
>+ $D : K_A \times C \to P$
>  
> Such that : 
>+ It's computationally *easy* to generate a key-pair $(SK,PK) \in K_S \times K_P$
>+ It's computationally *easy* to compute $y=E_{PK}(x)$
>+ It's computationally *easy* to compute $x=D_{SK}(y)$
>+ $D_{SK}(E_{PK}(x))=x$ needs to hold
>+ It's [[Computationally Impossible|Computationally Infeasable]] to compute $SK$ from $PK$ and $y$
>+ It's [[Computationally Impossible|Computationally Infeasable]] to compute $D_{SK}(y)$ knowing $PK$ and $y$ but *without* knowing $SK$ 

>[!warning] 
>Everybody could send a message to A saying the origin was B , *asymmetric-key ciphers* do not provide **Authentication** ( this was provided in *symmetric-key ciphers* since the two users needed to have the same *key* to communicate )

## One-way trap-door functions

>[!important] Definition
>An *injective* , *invertible* family of functions $f_k$ is *one-way trap-door* , $\iff$ **given** $k$ : 
>+ $y = f_k(x)$ is *easy* to compute 
>+ $x = f_k^{-1}(y)$ is [[Computationally Impossible|Computationally Infeasable]] without knowing the *secret* **trap-door** $S(k)$ relative to $k$

>[!note] 
>Or we can compute it's *inverse* only if we know a certain information $k$

## Merkle-Hellman knapsack system

This is an example of *asymmetric-key* cipher

>[!warning] 
>This cipher has been *broken*

### Subset-sum

It's based on the **subset-sum** [[Strutture Dati#Classe $NP-completi$ ( o NPC )|NP-Complete]] problem : 

>[!important] Subset-sum
>Let $s_1,\dots,s_n$ be *sizes* ( positive integers ) and $T$ be the *target* integer.
>
>A solution to the *subset-sum* problem is a subset of $s_1,\dots,s_n$ whose *sum* is exactly the *target* $T$
>
>Formally the solution will be a *binary* tuple $x_1,\dots,x_n$ such that $\sum_{i=1}^n x_i s_i = T$

>[!example] 
>If we have as *sizes* $(4,6,3,8,1)$ and $T=11$ than we have two solutions :
>+ $(0,0,1,1,0)$ , $3 +8 = 11$ 
>+ $(1,1,0,0,1)$ , $4+6+1 = 11$

>[!note] 
>We can see that we can define a function that computes the *target* from a given binary sequence quite easily : $f(x_1,\dots,x_n) = \sum_{i=1}^n x_i s_i$ 
>
>But the *inverse* ( starting from the *target* derive the binary sequence such that $\sum_{i=1}^n x_i s_i = T$ ) is instead **infeasable** for a big enough $n$ 

#### Easy instance

We can consider a special instance of the problem : 
Let $S$ be a *super-increasing* sequence such that : 
$$
s_i > \sum_{j=1}^{i-1} s_j, \quad\forall i > 1
$$
>[!note] 
>Or any $s_i$ must be bigger than the sum of all the previous $s_j$

>[!example] 
>$(1,3,5,10)$ is a *super-increasing* sequence

Than we can device an algorithm that solves this instance of the problem 

Start from the biggest element in the *sequence* , if $s_i$ fits into $T$ than we set $x_i=1$ and we reduce $T=T-s_i$ 

A solution is found when $T=0$

>[!note] 
>It's important to start from the *biggest* element since by definition of *super-increasing* sequence if we don't take it all the other 