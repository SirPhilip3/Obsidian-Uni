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
## Caesar Cipher

**Encryption** : All the letters of the message are *substituted* by the one $3$ positions ahead in the alphabeth 

>[!example] 
>![[Pasted image 20251003124509.png]]

In this case the *key* is $3$

**Decription** : This will be the opposite of *encryption* so each letter will go back $3$ positions

>[!warning] 
>Given the [[Kerckhoffs principle]] this algorithm is **insecure** since once we know that we are using a *Ceasar Cipher* we already know the key

## Shift Cipher

The *shift cipher* generalizes the *ceasar cipher* by providing as $k$ a random number $\in Z_{26}$ ( an integer in the range $0-25$ )

$E_k(x) = (x + k)\mod{26}$
$D_k(y) = (y -k)\mod{26}$

>[!note] 
>The propiety $D_k(E_k(x)) = x$ holds
>>[!important] Proof
>> $$D_k(E_k(x)) = D_k((x + k) \mod{26}) = ((x + k) \mod{26} - k) \mod{26} = x \mod{26} = x$$
>>
>

### Attacks

Testing the [[Kerckhoffs principle]] suppose that we know that we are using a *sobstitution cipher* than a simple attack would be **brute force** since the number of *key* to test is low ( $26$ )

>[!note] 
>The [[Kerckhoffs principle]] does not hold

## Substitution Cipher

We can overcome the limitations of the *shift cipher* by just using a *generic permutation* of the alphabet used to *encode* the message

>[!example] 
>
>```
>ABCDEFGHIJKLMNOPQRSTUVWXYZ
>SWNAMLXCVJBUYKPDOQERIFHGZT
>```

>[!note] 
>For the *decription* we simply invert the substitution

$K = \{p | p\text{ is a permutaion of }0,\dots,25\}$

>[!note] 
>We use $0,\dots,25$ just because they rapresent the indices of the letter of the alphabeth

$E_k(x) = p(x)$
$D_k(y) = p^{-1}(y)$ 

Let's verify the propieties :
1. 
$$D_p(y) = D_p(E_p(x)) = D_p(p(x)) = p^{-1}(p(x)) = x$$
2. Since we have a permutation of the alphabet as the *key* we will than have a space of the keys equal to : $26!$ 
>[!note] 
>It's now *infeasable* to use **brute force** 

### Attacks


## Polyalphabetic ciphers