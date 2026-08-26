---
publish: true
---
The pre-shared key $k$ system between two hosts doesn't scale if we have lot's of user
# Trusted intermediary

Determining a shared key for *symmetric key cryptography* and securely obtaining the public key for *public key cryptography* can be solved using a *trusted intemediary* 

For *symmetric* key cryptography the trusted intermediary is called a **Key Distribution Center** ( *KDC* )

For public key cryptography the trusted intermediary is called a **Certification Authority** ( *CA* )

## Key Distribution Center ( KDC )

A centralized *trusted server* that behaves as *Key Distribution Center* is a server for distributing new session keys to any pair of users asking for them 

The *KDC* shares one key with each user $U$ ( $K_{U}$ ) and users *do not* *directly share* keys among them 

When a new user *Alice* is added she just register to the *KDC* and gets her key $K_{A}$ 

### Communication between A and B

*A* and *B* only know their individual key $K_{A-KDC}$ and $K_{B-KDC}$ respectively for communicating securely with the *KDC*

1. *Alice* wants to comunicate with *Bob* sends the following to the *KDC* : $K_{A-KDC}(A,B)$
2. *Alice* recieves $K_{A-KDC}(R1, K_{B-KDC}(A,R1))$ , now *Alice* knows $R1$ 
3. *Alice* send the following to *Bob* : $K_{B-KDC}(A,R1)$ 
4. Now *Bob* knows $R1$ and *Alice* and *Bob* communicate using the shared session key $R1$ 

Having a centralized *KDC* does not scale to a wide area network like the *Internet*

## Asymmetric key authentication

Asymmetic-key protocols are better suited for the *Internet* 

>[!warning] 
>Asymmetric-key encryption never proves the knowledge of a secret as it only requires the knowledge of $PK_{B}$ which is public

*Decryption* instead can be done *only* when the *private key* is *known*, a **correct** unilateral authentication protocol can be obtained by *challenging* *Alice* to **decrypt** something

A way to achieve this is to adopt a *Nonce*-based authentication scheme : 
$$
\begin{align}
B \to A &: E_{PKA}(N_{B},B) \\
A \to B &: N_{B}
\end{align}
$$
Where *Bob* sends a *nonce* $N_{B}$ encrypted together with his identifier under the public key of *Alice* , only knowing *Alice* private key it's possible to *decrypt* the *nonce* and send back it's value in the clear

>[!note] 
>The presence of the *time-variant* nonce prevents possible *replays*
>
>We specify the identifier in the first message to prevent *man-in-the-middle* attacks

This protocol can be extended using the *Needham-Schroeder public-key protocol* to provide mutual authentication

# Signature-based authentication

*Encryption* is to protect key *confidentiality* while *signature* gives *authentication*

Starting from the *flawed* unilateral protocol :
$$
A \to B : E_{PKB}(A,t_{A},k_{S})
$$
We add a *signature* from *Alice* to prove her identity , this replaces *Alice* identifier
>[!note] 
>The *timestamp* can be sent in the clear

We also add *Bob* identifier to the signature to specify the intendended reciever
$$
A \to B: t_{A}, E_{PKB}(k_{S}, sign_{A}(B,t_{A},k_{S}))
$$
>[!warning] 
>The message to encrypt will be typically bigger than the size of one block ( since the signature is already the size of the modulus itself )

We would need some block encryption mode with strong integrity guarantees

A solution would be to *separate* the encryption and signature :
$$
A \to B: t_{A}, E_{PKB}(k_{S}),sign_{A}(B,t_{A},k_{S})
$$
A *symmetric key* $k_{S}$ is typically much smaller than one encryption block 

>[!example] 
>We might have $1024$ bits [[Magistrale/1 anno/1st Semester/Cryptography/RSA|RSA]] modulus and a $128$ or $256$ bits [[AES]] *symmetic key*

>[!warning] 
>This protocol can be adopted only *when* the *signature* scheme *prevents* the *computation* of the signed *message* 

A general solution is thus to first *encrypt* and then *sign*
$$
A \to B: t_{A},E_{PKB}(k_{S},A),sign_{A}(B,t_{A},E_{PKB}(k_{S},A))
$$
>[!note] 
>Since signatures can be implemented with *hashes* we do not have lenght issues with this protocol

Having *A* in the encrypted message prevents the attacker to intercept the message sign the key himself

The reciever will verify that the identifier in the signature os the same as the one in the encrypted message

## X.509 strong authentication protocols

$$
\begin{align}
A \to B&: t_{A},E_{PKB}(k_{S}^A,A),sign_{A}(B,t_{A},E_{PKB}(k_{S},A)) \\
B \to A&: t_{B},E_{PKA}(k_{S}^B,B),sign_{B}(A,t_{B},E_{PKA}(k_{S}^B,B))
\end{align}
$$
*Alice* and *Bob* compute a session key as $k_{S}=f(k^A_{S},k^B_{S})$

>[!note] 
>This can be achieved based on *nonces* as follows
>$$
>\begin{align} 
>B \to A &: N_{B} \\
>A \to B&: N_{A},E_{PKB}(k_{S}^A,A),sign_{A}(B,N_{A},N_{B},E_{PKB}(k_{S},A)) \\
>B \to A&: E_{PKA}(k_{S}^B,B),sign_{B}(A,N_{A},N_{B},E_{PKA}(k_{S}^B,B))
>\end{align}
>$$

# Symmetric Key managment

In practice authentication protocols based on symmetic keys requier the presence of a centralized trusted party that sahres one long-term key with each possible user 

The *trusted party* possesses a master key $k_{M}$ that it only knows

When a new user $U$ is register the respective long-term key $k_{U}$ is *generated* and is *encrypted* *under* the *master* key together with the identifier and additional information such as the key lifetime
$$
SCert_{U} = E_{kM}(U,k_{U},L)
$$
These **certificates** can be distributed to users together with their keys 

The *trusted party* can *forget* about the *keys* and *ask* for *certificates* instead

# Asymmetric Key certificates

If *Alice* and *Bob* want to comunicate they need a way to check that the public key is the one truly associated with the opposite party 

>[!warning] 
>It's insecure for *Bob* to send his *public key* to *Alice* since the attacker can replace $PK_{B}$ with it's own key

We introduce **Public Key certificates** , they contain the same infromation as the symmetric key certificates

They, instead of being encryped under a *symmetric master key* they are ***signed*** by a **Certification Authority (CA)** , a trusted entity that certifies the authentifity of a user public key
$$
Cert_{B} = B, PK_{B},L, sign_{CA}(B,PK_{B},L)
$$
If *Alice* knows the *public key* of the **CA** and *Bob* sends this certificate then *Alice* can check the validity of the key that is associated with *Bob*
$$
\begin{align}
B \to A &: Cert_{B}  \\
A \to B &: E_{PKB}(M)
\end{align}
$$
The attacker can't change the *public key* as he is not able to forge a signature from the **CA**

`openSSL` is an implementation of all this

>[!note] 
>The *CSR* ( *Certificate Signing Request* ) is what we send to the *CA* to be signed it contains the *public key* but not the private key

#todo openSSL code ? 37 L23

# Transport Layer Security protocol ( SSL/TLS )

When a user connects to a website using `https` , the *SSL/TLS* protocol establishes a secure , encrypted session

The association of the identity and the public key of the *Web Server* is checked using *certificates* 

The *asymmetric key* of the Web server is used to establish a new session key 

>[!warning] 
>Websites can still generate their own certificates , in this case *man-in-the-middle* attacks are possible where a fake site uses a self signed certificate and can subsequently intecept / modifying all the messages

**CA**s are distributed in hierarchical level

The *root* **CA** cerifies the next *CA* in the hierarchy and so on all the way to the end user 

>[!example] 
>![[CAchain.excalidraw.png]]
>%%[[CAchain.excalidraw.md|🖋 Edit in Excalidraw]]%%
>
>If *Carol* wants to communicate with *Dave* she needs to send *Dave* the **certificate chain** from the root *CA* to *herself* :
>+ $CA_{1}$ certificate signed by $CA_{root}$
>+ $CA_{3}$ certificate signed by $CA_{1}$
>+ *Carol* certificate signed by $CA_{3}$

# Pretty Good Privacy ( PGP )

*PGP* does not require a centralized authority

It's a web of trust : any user can trust other users 

If *Alice* trusts *Bob* any other user that is cerified by *Bob* is trusted by *Alice*

If we trust the starting user then we can successfully verify the identity and public key of the final user in the path