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

*Encryption* is to protect key confidentiality while *signature* gives authentication

