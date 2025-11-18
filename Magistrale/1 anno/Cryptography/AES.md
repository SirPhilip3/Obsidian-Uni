---
publish: true
---
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
(x^7+x^6+x^4+x+1)\cdot(x^5+x^4+x^3+x) 
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

### AES Encryption Schema

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

The overall *schema* is the following with a $128$-bit key :

![AES Encryption](https://binaryterms.com/wp-content/uploads/2020/05/AES-Encryption.jpg)
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

>[!note] 
>This *S-box* has been obtained by taking for each *byte* its *multiplicative inverse* in the finite field 
>

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

#### Key Expansion

In [[AES#AddRoundKey|AddRoundKey]] the *key* used needs to be a different one for each *round* of the algorithm 

We than need to expand the original *key* of $16$ bytes ($128$ bits) to a bigger array of size $4 \cdot (Nr + 1)$ where :
+ $Nr$ is the number of *rounds* 

### AES Decryption Schema

The *decryption* is performed by applying the inverse operations :
+ **AddRoundKey** : is unchanged since *xor* is the inverse of itself
+ **InvShiftRows** : shift to the *right* instead than to the left 
+ **InvSubBytes** : uses the following *S-box* 
![[Pasted image 20251101171744.png]]
+ **InvMixColumns** : uses a different matrix to which multiply each *column* 
$$
\begin{bmatrix}0e&0b&0d&09\\09&0e&0b&0d\\0d&09&0e&0b\\0b&0d&09&0e\end{bmatrix}
$$

>[!example] 
>
>![AES Decryption Algorithms](https://xilinx.github.io/Vitis_Libraries/security/2019.2/_images/original_decryption_flow.png)

>[!note] 
>The result does not change if we first apply the *byte-wise sobstitution* or we first *shift* the rows 
>
### Attacks 

The best known attacks were found for *rounds* lower than $10$ 