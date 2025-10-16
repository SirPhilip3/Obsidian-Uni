---
publish: true
---
The **Hill Cipher** is a *polyalphabetic* cipher that generalizes the idea of the [[Vigenere Cipher]] by introducing *linear transformations* of blocks of plaintext

Where :
+ $P = C = Z_{m}^{26}$ 
+ $K = \{K | K\text{is an invertible mod 26 matrix of size m x m}\}$ 

$E_k(x_1, \dots, x_m) = (x_1,\dots, x_m)\cdot K \mod 26$
$D_k(y_1,\dots,y_m) = (y_1,\dots,y_m) \cdot K^{-1} \mod{26}$

>[!example] 

