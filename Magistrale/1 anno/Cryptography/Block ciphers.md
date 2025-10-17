*Block ciphers* are cryptosystems that "reuse" the same key to encrypt letters or blocks of the *plaintext*

$$
\begin{matrix} x_1 & x_2& \ldots ~~~~~~& x_n\\\downarrow& \downarrow&&\downarrow\\k\rightarrow\fbox{E}~~~~~~&k\rightarrow\fbox{E}~~~~~~~~&\ldots~~~~~~&k\rightarrow\fbox{E}~~~~~~~~\\\downarrow&\downarrow& &\downarrow\\y_1 & y_2 & \ldots ~~~~~~& y_n\end{matrix}
$$

## Stream ciphers

A more advanced form of *block ciphers* are *stream ciphers* where instead of using a single key $k$ we will use a precomputed stream of keys $z_1,z_2, \dots, z_n$

$$
\begin{matrix} x_1 & x_2& \ldots ~~~~~~& x_n\\\downarrow& \downarrow&&\downarrow\\z_1\rightarrow\fbox{E}~~~~~~~~&z_2\rightarrow\fbox{E}~~~~~~~~~~&\ldots~~~~~~&z_n\rightarrow\fbox{E}~~~~~~~~~~\\\downarrow&\downarrow& &\downarrow\\y_1 & y_2 & \ldots ~~~~~~& y_n\end{matrix}
$$

>[!warning] 
>Having a different *key* for each of the *blocks* in the *plaintext* is not *pratical*

So in general instead of a stream of *keys* we will derive it from a given intial $k$ based on the previous parts of the *plaintext* : 
$$
z_i = f_i(k, x_1, \dots , x_{i-1})
$$
### Periodic stream ciphers
A *stream cipher* id *periodic* if it's key stream has the following form : 
$$
z_1,z_2,\dots, z_d, z_1,z_2,\dots,z_d,z_1,\dots
$$

The [[Vigenere Cipher]] is an example of *periodic ciphers* where the blocks are single letters : $z_i = k_{i \mod{m}}$

### Synchronous stream cipher

A stream cipher is *synchronous* if it's key stream does not depend on the plaintexts : $z_i = f_i(k) , \forall i$

An example can be the [[Vigenere Cipher]]

### Asynchronous stream cipher

We are in the general case where $z_i = f_i(k,x_1,\dots,x_{i-1})$ and we need to decrypt and compute the *keys stream* at the same time since a key depends on the previous *plaintexts*

An example is the **Autokey cipher** :

$P=C=K=Z_{26}$
$E_{z_i}(x_i) = (x_i + z_i)\mod{26}$
$D_{z_i}(y_i) = (y_i -z_i)\mod{26}$ 

>[!note] 
>The *encryption* and *decryption* are exactly like the [[Shift Cipher]]

>[!important] 
>The *key stream* is defined as $z_1 = k$ and $z_i = x_{i-1}$ for $i\ge 2$
>
>The first key in the stream is the initial key $k$ while the next keys are the previous *plaintext*

>[!example] 
>$P =$ `networksecurity`
>$K = 5$  
>
>The corresponding numbers are : 
>`13 4 19 22 14 17 10 18 4 2 20 17 8 19 24`
>
>*Encryption* : 
>$z_1 = 5$ , $z_2 = x_1 = 13$ , $z_3 = x_2 = 4$ , $\dots$ 
>
>$C =$ `18 17 23 15 10 5 1 2 22 6 22 11 25 1 17`
>
>*Decryption* : 
>
>$x_1= (18 - 5)\mod{26} = 13$
>$x_2 = (17 -13)\mod{26} = 4$
>$\dots$
>

#### Attacks

Since the whole *decryption* depends only on the first letter it is sufficient to bruteforce the first letter to break the cipher