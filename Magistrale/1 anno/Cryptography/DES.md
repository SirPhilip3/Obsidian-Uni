---
publish: true
---
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

>[!note] 
>*DES* has a block size of $64$ bits 

If we list all the $2^{64}$ possible blocks and we pick one *DES* key $k$ than the cipher will map each of these blocks into a different block 

Since the *encryption* must be invertible than the mapping must be **injective** 
Thus a key corresponds to a *permutation* of all the possible *plaintext* blocks ( $2^{64}!$ ) 

We can than say that the *key* $k$ is selecting a random subset of $2^{56}$ permutations from the $2^{64}!$ possible ones 

>[!note] 
>We suppose that the way these permutation are selected is *complex* enugh , otherwise *DES* would be a *weak cipher* 

The probability of getting of the composition of two permutation being still in the same subset of keys is :
$$
\frac{2^{56}}{2^{64}!}
$$
Which is *negligible*

#### Meet-in-the-middle Attack

Let's now consider *DoubleDES* , we than have a key of $112$ bits 

Let's put ourself in the [[Types of Attaks#Known-plaintext attack|Known-plaintext attack]] scenario

The attacker will select a *pair* $(X,Y)$ and will try to decrypt $Y$ with all the possible *second keys* $k2$ , we will than obtain a list of **possible** decryption values $Z$

Now we try to encrypt under all the possible *first keys* $k1$ the plaintext $X$ 

If we find a *match* , test the resulting key *pair* with all the other examples if a majority of test succeed than the two *keys* are a reasonably probable solution 

>[!note] Complexity
>The resulting complexity is $2^{56}+2^{56} = 2^{57}$ which is a lot lower than the brute force attack $2^{112}$

>[!warning] 
>We could find a pair of *false* keys that are correct for the pair $(X,Y)$ but not for the others
>
>In fact we can estimate the number of *false keys* as $\frac{|K|}{|C|}$ which in our case is $\frac{2^{112}}{2^{64}} = 2^{48}$ which is still a huge number but tasting with other pairs reduce this probability significantly
>
>The probability that a *false key* is also valid for $(X',Y')$ is $1$ over all the possible *ciphertexts* giving $\frac{1}{2^{64}}$ 
>
>Thus the number of *false keys* is reduced to $\frac{2^{48}}{2^{64}} = \frac{1}{2^{16}}$ , trying even more key pairs we will have $\frac{1}{2^{80}}$ which is negligiable
## 3DES

Iterates *DES* for $3$ times giving us robstness against the *meet-in-the-middle* attack