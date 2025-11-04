*Data Encryption Standard* ( *DES* ) is a [[Ciphers#Symmetric Ciphers|Symmetric]] key algorithm 

The *block size* is $64$ bits 
The *key* is of $64$ bits but $8$ are used for *error correction* ( so in reality the key is only of $56$ bits )
## Encryption

The *encryption scheme* is constituted of $16$ identical *rounds* of a **Feistel function** ( $F$ ) opened and closed by , respectively : 
+ **Initial Permutation** ( $IP$ )
+ **Final Permuation** ( $FP$ )
### Feistel scheme

Before the main rounds the block get's divided into two $32$-bit *halves* 

The first half get's *expanded* to $48$ bits in order to match the *subkey* extracted with permutation and *circular shifts* 

They get *xor*ed toghether to than be passed to $8$ singular *S-box*es taking in $6$ bit each and return $4$ bits 

The resulting $32$ bit will than be *permutated* and *xor*ed with the other *half* of the *plaintext* 

The two half will than be switched for the next rounds 

>[!example] 
>![[Data_Encription_Standard_Flow_Diagram.svg]]

>[!example] 
>![[DES-main-network.png]]

### Confusion and Diffusion

The previous process garantees the following two propieties : 
+ **Confusion** : 
	The data is drastically different from input to output
+ **Diffusion** :
	Changing a single character of the input will change the output

### Attacks

Normal *DES* and *2DES* are subject to *meet-in-the-middle* attack , in order to protect from that we *iterate* the *DES* cipher $3$ times 
#### DES is non-idempotent

In order to be able to iterate the *DES* the cipher needs to be *non-idempotent*   

#todo 

#### Meet-in-the-middle Attack



## 3DES

The main problem with **DES** is the reduced lenght of the key 