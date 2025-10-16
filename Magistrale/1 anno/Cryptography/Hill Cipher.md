---
publish: true
---
The **Hill Cipher** is a *polyalphabetic* cipher that generalizes the idea of the [[Vigenere Cipher]] by introducing *linear transformations* of blocks of plaintext

Where :
+ $P = C = Z_{m}^{26}$ 
+ $K = \{K | K\text{is an invertible mod 26 matrix of size m x m}\}$ 

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

### Known-plaintext attacks

