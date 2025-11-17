---
publish: true
---
The **Hill Cipher** is a *polyalphabetic* cipher that generalizes the idea of the [[Vigenere Cipher]] by introducing *linear transformations* of blocks of plaintext

Where :
+ $P = C = Z_{m}^{26}$ 
+ $K = \{K | K\text{ is an invertible mod 26 matrix of size m x m}\}$ 

$E_k(x_1, \dots, x_m) = (x_1,\dots, x_m)\cdot K \mod 26$
$D_k(y_1,\dots,y_m) = (y_1,\dots,y_m) \cdot K^{-1} \mod{26}$

>[!example] Encryption
>Let's assume that : 
>+ $M=(x_1,x_2) = (5,9)$
>+ $K=\begin{bmatrix}5 & 11\\ 8 &3 \end{bmatrix}$
>  
>Than :
>$$
>\begin{align*}E_k(5,9) & = (5,9) \times \begin{bmatrix}5 & 11\\ 8 &3 \end{bmatrix} \mod{26} \\ & = ( 5 \cdot 5 + 9 \cdot 8, 5 \cdot 11 + 9 \cdot 3 ) \mod{26}\\  & = (97,82) \mod{26} \\ & = (19,4) \end{align*}
>$$
>

>[!example] Decryption
>
>In order to *decript* a message we need to : 
>1. compute the inverse of $K = K^{-1}$
>2. compute $(y_1,\dots, y_m) K^{-1}\mod{26}$
>
>Let's compute the *inverse* : 
>$$
>K^{-1} = \det^{-1}(K) \text{adj}(K) \mod{26} 
>$$
>
>Where : 
>+ $\text{adj}(K) = \begin{bmatrix} d & -b \\ -c & a\end{bmatrix}$
>+ $\det^{-1}(K) =\Big( (a \cdot d - b \cdot c) \mod{26}\Big ) ^{-1}$
>
>In this case : 
>$\det(K) = (5 \cdot 3 - 11 \cdot 8) \mod{26} = -73 \mod{26} = 5$ 
>
>Now to find $\det(K)^{-1}$ we need to find a number in the interval $[0,25]$ such that multiplied by $\det(k) \mod{26}$ it gives $1$
> 
>In our case $5\times 21 \mod 26 = 105 \mod 26 = 1$ thus $\det(K)^{-1}=21$
>
>At the end wi will have that : 
>$$
>K^{-1} = 21 \times \begin{bmatrix}3 & -11 \\ -8 & 5 \end{bmatrix} \mod{26} = 21 \times \begin{bmatrix}3 & 15 \\ 18 & 5 \end{bmatrix} = \begin{bmatrix}63 & 315 \\ 378 & 105 \end{bmatrix}\mod{26} = \begin{bmatrix}11 & 3 \\ 14 & 1 \end{bmatrix} 
>$$
>
>$$
>D_k(19,4) = (19,4) \begin{bmatrix}11 & 3 \\ 14 & 1 \end{bmatrix}\mod{26} = (19 \cdot 11 + 4 \cdot 14 , 19 \cdot 3 + 4 \cdot 1 )\mod{26} =(5,9) 
>$$

## Attaks

The *Hill Cipher* is subscetible to attacks that are known as [[Types of Attaks#Known-plaintext attack|Known-plaintext attack]]

Assume than that we know $m$ *pairs* of *plaintexts* and *ciphertexts* 

>[!note] 
>$m$ is the *block* lenght

We than know that : 
$$
\begin{align}
(y_1^1, \dots, y_m^1) & = & (x_1^1, \dots,x_m^1) K \mod{26} \\
& \dots & \\
(y_1^m, \dots, y_m^m) & = & (x_1^m, \dots,x_m^m) K \mod{26}
\end{align}
$$
This ca be written in *matrix* form in the following way : 
$$
Y = XK\mod{26}
$$
We can than derive the $K$ in the following way : 
$$
K = X^{-1} Y \mod{26}
$$
>[!note] 
>Since the *Hill Cipher* is just a *linear tranformation* of a *plaintext* block into a *cipher* block 

>[!example] 
Given the following pairs : 
$(5,9) \to (19,4)$ and $(2,5)\to (24,11)$ and $m=2$
>$$
>\begin{bmatrix}
>19 & 4 \\ 24 & 11
>\end{bmatrix} = \begin{bmatrix}
>5 & 9 \\ 2 & 5
>\end{bmatrix} \cdot K \mod{26}
>$$
>We need to find $X^{-1}$
>
>1. $\det(X) = 5 \cdot 5 - 2 \cdot 9 = 7$
>2. $\det(X)^{-1} : 7 \times a = 1 \mod{26}$ , $a=15$
>3. 
>$$
>\begin{align}
>X^{-1} & = 15 \cdot \begin{bmatrix} 5 & -9 \\ -2 & 5 \end{bmatrix} \mod{26}\\ & = 15 \cdot \begin{bmatrix} 5 & 17 \\ 24 & 5 \end{bmatrix} \mod{26}\\ & = \begin{bmatrix} 23 & 21 \\ 22 & 23 \end{bmatrix}  
>\end{align}
>$$
>
>Than to get the key $K$ : 
>$$
>\begin{align}
>K & = \begin{bmatrix} 23 & 21 \\ 22 & 23 \end{bmatrix}  
> \cdot \begin{bmatrix} 19 & 4 \\ 24 & 11 \end{bmatrix} \mod{26}\\ & = \begin{bmatrix} 23\cdot 19 + 21\cdot24 & 23 \cdot 4 + 21 \cdot 11 \\ 22\cdot 19 + 23 \cdot 24 & 22\cdot 4 + 23 \cdot 11 \end{bmatrix} \mod{26}\\ & = \begin{bmatrix} 5 & 11 \\ 8 & 3 \end{bmatrix}  
>\end{align}
>$$

