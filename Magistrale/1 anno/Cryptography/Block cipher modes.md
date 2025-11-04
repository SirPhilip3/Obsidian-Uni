---
publish: true
---
When using [[Block ciphers]] we may need to *encrypt* *plaintexts* that are **longer** than the block size 

There are various *mode of operation* that repeatedly applies the [[Block ciphers]] selected and allows for the *ecryption* of *plaintexts* of arbitrary size 

## Electronic CodeBook mode (ECB)

The *plaintext* is split into *blocks* whose size is exactly the same as the size of the *cipher block*

Each block is *encrypted* independently with the *fixed key* $k$

An example is the [[Substitution Cipher]]

| Pros                                                                                                         | Cons                                                                                                                    |
| ------------------------------------------------------------------------------------------------------------ | ----------------------------------------------------------------------------------------------------------------------- |
| Very *fast* ( the operation can be parallelized since each block is indepent from one another ) and *simple* | Each plaintext block is encrypted the same way                                                                          |
|                                                                                                              | It can be attacked by *code-book* mapping                                                                               |
|                                                                                                              | *Absence* of *integrity* , an attacker in the middle can modify , delete or swap blocks and the decryption works anyway |

>[!example] 
>
>This type of encryption retains pattern of the plaintext
>
>![ECB bitmap](https://citizenlab.ca/wp-content/uploads/2024/04/image6-combined.png)
## Cipher Block Chaining mode (CBC)

This mode *chains* the *encryption* by using the *previous* encrypted block 

The first block get's *encrypted* by firstly *xor*-ing the *plaintext* with an **Initialization Vector** ( $IV$ ) that *must* be *random*

Than the result of the *encryption* with the key $k$ get's used to *xor* the next block 

>[!example] 
>$$
>\begin{array}{r@{}c@{~~~~~~~}r@{}c@{~~~~~~~}c@{~~~~~}r@{}c}& x_1 && x_2& \ldots&& x_n\\&\downarrow&&\downarrow&&&\downarrow\\IV\rightarrow&\oplus& y_1\rightarrow&\oplus&&y_{n-1}\rightarrow&\oplus\\&\downarrow&& \downarrow&&&\downarrow\\k\rightarrow&\fbox{E}&k\rightarrow&\fbox{E}&\ldots&k\rightarrow&\fbox{E}\\&\downarrow&&\downarrow&&&\downarrow\\& y_1 && y_2 & \ldots&& y_n\end{array}
>$$

For the **decryption** simply *xor* the *decrypted* block with , initially the $IV$ and than with the *previous* block *cyphertext* input 

>[!example] 
>$$
>\begin{array}{r@{}c@{~~~~~~~}r@{}c@{~~~~~~~}c@{~~~~~}r@{}c}& y_1 && y_2& \ldots&& y_n\\&\downarrow&&\downarrow&&&\downarrow\\k\rightarrow&\fbox{D}&k\rightarrow&\fbox{D}&\ldots&k\rightarrow&\fbox{D}\\&\downarrow&&\downarrow&&&\downarrow\\IV\rightarrow&\oplus& y_1\rightarrow&\oplus&&y_{n-1}\rightarrow&\oplus\\&\downarrow&& \downarrow&&&\downarrow\\& x_1 && x_2 & \ldots&& x_n\end{array}
>$$

| Pros                                                                                                                    | Cons                                                                                                                                 |
| ----------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------ |
| Prevents the *code-book* attack since we never encrypt the same plaintext bock in the same way                          | The manipulation of one bit in an *encrypted* block $y_i$ obtains that also the same bit of the *plaintext* $x_{i+1}$ is manipulated |
| *Integrity* is improved since if the attacker does the *mimt* attack it will result in at least one corrupted plaintext |                                                                                                                                      |

## Output FeedBack mode (OFB)

Use the *block cipher* in order to generate a complex key stream 

The *encryption* is than simply performed by *xor*-ing the *plaintext blocks* with the generated keys

>[!note] 
>This aims at emulating the working of [[One-Time-Pad]] 

>[!example] Encryption Schema
>$$
>\begin{array}{r@{}c@{~~~~~~~}r@{}c@{~~~~~~~}c@{~~~~~}r@{}c}& IV && z_1& \ldots&& z_{n-1}\\&\downarrow&&\downarrow&&&\downarrow\\k\rightarrow&\fbox{E}&k\rightarrow&\fbox{E}&\ldots&k\rightarrow&\fbox{E}\\&\downarrow&&\downarrow&&&\downarrow\\&z_1&&z_2&&&z_n\\&\downarrow&&\downarrow&&&\downarrow\\x_1\rightarrow&\oplus& x_2\rightarrow&\oplus&&x_{n}\rightarrow&\oplus\\&\downarrow&& \downarrow&&&\downarrow\\& y_1 && y_2 & \ldots&& y_n\end{array}
>$$

>[!note] 
>In this case the *key* generation is compleatly indepent from the *encryption* we could than generate the stream of *keys* **offline** 

>[!example] *Decryption* Schema
>
>In order to *decrypt* a *cyphertext* we simply *xor* it with the generated keys since the *xor* is the inverse of itself 

| Pros                                                                                    | Cons                                                                                                                                                           |
| --------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| The *key* can be precomputed                                                            | This is a [[Block ciphers#Synchronous stream cipher\|Synchronous cipher]] , if we reuse the same *IV* with the same *key* than we obtain the same *key stream* |
| *key* stream is generated with a *block cipher* , this makes it very hard to predict it | *Lack of integrity* , if an attacker is in the middle he can change the plaintext stream and the *decrypted* blocks will not be corrupted                      |

### Key generation

The generation of the key stream is the [[Block cipher modes#Cipher Block Chaining mode (CBC)|CBC]] *encryption* of a *zero plaintext*

>[!note] 
>If there are *plaintext* blocks smaller than the size of the *block cipher* than we can use part of the key for the remaning part of the next block 

## Counter mode (CTR)

This is a variation of [[Block cipher modes#Output FeedBack mode (OFB)|OFB]] where the *IV* is a *random number* and a **counter** 

>[!note] 
>The *counter* increases it's value for each *block encryption*

![[CTR_encryption_2.jpg]]
## Cipher FeedBack mode (CFB)

This mode mitigates the problems introduced by [[Block cipher modes#Output FeedBack mode (OFB)|OFB]] by making the *key stream* dependent on the previos encrypted element  

It use a *shift register* than is shifted to the *left* by the number of bits of the *previous* *ciphertext* , this get's than copied into the rightmost bits of the register 

>[!example] Encryption
>![[Pasted image 20251103113703.png]]

The ***decryption*** simply works like for [[Block cipher modes#Output FeedBack mode (OFB)|OFB]] 


| Pros                                                                                                                                                                                                                                                                                                                  | Cons                                                                                    |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------- |
| We have *higher* *integrity* in respect to [[Block cipher modes#Output FeedBack mode (OFB)\|OFB]] , when one *bit* of the *ciphertex* is modified the next $BSize / CSize$ *plaintexts* are corrupted (this number is equal to the number of left *shifts* necessary for a *ciphertext* to exit the *shift register*) | We can't parallelize any operations during the *encryption*                             |
|                                                                                                                                                                                                                                                                                                                       | An error in the transmission of the data can be propagated to $BSize/CSize$ *plaintext* |



