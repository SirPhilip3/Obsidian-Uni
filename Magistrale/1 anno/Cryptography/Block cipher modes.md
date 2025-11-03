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

#todo 

## Counter mode (CTR)

## Cipher FeedBack mode (CFB)