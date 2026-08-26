---
publish: true
---
Passwords and PINs suffer from *interception* and *replay attacks* 

This can be improved using *OTP*s 

>[!warning] 
>All of this techniques allow for user to prove the knowledge of a password by exibiting the secret value

*Strong authentication* techniques instead allow for proving the knowledge of a secret qithour showing it 

The secret shared between the *claimant* and the *verifier* is a symmetric cryptographic key

In order to prove the knowledge of the key $K$ the *claimant* sends to the verifier a message *encrypted under* $K$

Since generating an encrypted messsage without knowing the key is assumed to be infeasible this proves its knowledge

## Protocols

In generale we have a :
+ **Challenge** :
	+ The verifier challenges the claimant to send a particular message encrypted under $K$
+ **Response** :
	+ The claimant sends the requires message 

>[!example] 
>A challenge might be "send me your name encrypted under $K$". The response from Alice would then be $E_{k}(A)$
>The verifier decrypts the message and cehcks if it maches the name of $A$

>[!warning] 
>If the challenge is always the same an attacker can perform a *replay* attack

The challenge can be made always different by adding a *time-variant* parameter

### Sequence Numbers

A *time-variant* parameter is a **Sequence number** : the response can be $E_{k}(A,seq_{A})$

The sequence number is increased by $1$ after sending so that it never repeats

The *verifier* must store the last sequence number from *Alice* 

>[!warning] 
>Sequence numbers require the verifier to store the last sequence number of each claimant
>
>Also it they become out of sync it's unclear what to do since restarting from $0$ would make it possible to reuse authentications

### Timestamps

The challenge is now : "send me your name and a *recent* timestamp encrypted under $K$" or :
$$
A \to B : E_{k}(A,t_{A})
$$
$t_{A}$ is the time at the local clock of *Alice* when sending the message 

The *verifier* decrypts the message and verifies Alice name, then he extracts a local timestamp $t_{B}$ and verifies that $t_{B}-t_{A}< W$ where $W$ is the *acceptance window* 

>[!warning] 
>$W$ must be big enough to accept honest messages but small enough so that no *replay* will ever be accepted

This is very hard to do so instead the reciever *buffers* the recieved timestamps so that the arrival timestamp is checked against the *buffer* . This are periodically *deleted*

Timestamps do not require to store any per-user information

In case *synchronization* is lost it is enough to synchronize the local clocks

>[!warning] 
>The synchronization should be authenticated since malicious clock chenages might allow the attacker to make old timestamps valid or prevent any honest message to be accepted 

The authenticated synchronization cannot be implemented using timestamps

### Nonces

We need at least one time variant parameter that *does not* *assume* any form of *synchronization* to implement the authenticated synchronization for timestamps and sequence numbers 

*Nonce* are *Numbers used only once* 

The *challenge* implies an *additional message* from the verifier to the claimant containing the *nonce* 

Challenge : "send me your name and nonce ecnrypted under key $K$" :
$$
B \to A : N_{B}
$$
$$
A \to B : E_{K}(A,N_{B})
$$
*Bob* generated a random *nonce* and sends it to *Alice*. He then decrypts the recieved message and checks if it matches

The *nonce* is ***discarded*** 

If *nonce* are big enough picking them at random implies that the probability of reusing the same *nonce* is negligible 

## Attacks

In challenge-response algorithm is important to avoid scenarios that facilitate cryptanalysis

>[!example] 
>$A \to B : E_{k}(A,t_{A})$ it's not too hard to estimate the *time-stamp* value provinding a *known-plaintext* scenario

The protocol
$$
B \to A : N_{B}
$$
$$
A \to B : E_{K}(A,N_{B})
$$
provides a *partial* *chosen-plaintext* scenario where the attacker can ask for encryption of any plaintext $A,z$ with arbitrary $z$ 

It's enough for the attacker to *impersonate* **Bob** and send as *nonce* :
$$
E(B) \to A : z
$$
$$
A \to E(B) : E_{K}(A,z)
$$
### Redundancy

Consider the following protocol based on *sequence numbers* :
$$
A \to B : A, E_{k}(seq_{A})
$$
The identifier $A$ is sent in the clear while the sequence number is *encrypted*

Suppose that $B$ only checks for *monotonicity* 

The attacker sends an arbitrary message :
$$
A \to B : A, z
$$
The probability that the decryption of $z$ is a valid number bigger than the stored one is high ( especially if we started from small sequence numbers )

>[!warning] 
>Encrypting arbitrary numbers with no format or message redundancy makes it impossible to check the integrity of the decryption , a random $z$ can always be decrypted in a meaningful arbitrary number

The presence of the identifier mitigates this problem since $z$ once decrypted should at least match $A$

If $A$ is $n$ bits long the probability that this happens is $\frac{1}{2^n}$

*Adding redundancy* :
+ Enclose a *one-way hash* of the encrypted message called *witness* as in $h(seq_{A}), E_{k}(seq_{A})$

The *hash* is a proof that the sender knows the content of the message

When *Bob* decrypts he cheks if the hash of the decrypted message matches the received one

The attacker coould send arbitrary $w,z$ but with a hash of $128$ bits the probability of passing the test would be $1/2^{128}$

>[!note] 
>Since the hash is one way this makes the technique applicable when it's important to *preserve* the *secrecy* of the sent message ( $seq_{a}$ replaced by $x$ )
### Reflection

Consider the following protocol based on *timestamp* :
$$
A \to B : A, E_{k}(t_{A})
$$
Suppose *Bob* is allowed to run the same protocol to authenticate with *Alice* using the same shared key $K$ :
$$
B \to A: B, E_{k}(t_{B})
$$
The attacker can *pretend* to be Bob ( $E(B)$ ) as follows :
$$
\begin{align}
A \to E(B) : A, E_{k}(t_{A}) \\
E(B) \to A : B, E_{k}(t_{A})
\end{align}
$$
The message from *Alice* trying to authenticate with *Bob* is sent back to *Alice* in a second session where the attacker pretends to be *Bob*

If this is fast enough to be in $W$ , *Alice* accepts the identity of *Bob* who is the attacker

>[!note] 
>Alice has never received this timestamp before she generated it

The symmetry of the key is dangerous if there is no information in the ciphertext about who are the intended sender and reciever

It's enough to specify $A$ or $B$ as long as *Alice* and *Bob* agree on what they expect to see in the message ( protocol agreement )
## Countermeasure

To avoid this we need to *randomize cryptography* 

This can be done for example by adding a *random padding* to the plaintext

The protocols becomes :
$$
A \to B: E_{k}(A,t_{A},R_{A})
$$
and
$$
B \to A: N_{B}
$$
$$
A \to B : E_{k}(A,N_{B},R_{A})
$$
>[!note] 
>We will assume that this form of *randomization* is at the cryptographic level. When decrypting the random *cofaunder* will be ignored by $Bob$

## ISO/IEC 9798-2 protocols

+ **One-pass unilateral authentication**
$$
A \to B : E_{k}(ts_{A},B)
$$
Where $ts_{A}$ is a *timestamp* or a *sequence* number

+ **Two-pass unilateral authentication**
$$
\begin{align}
B \to A : N_{B} \\
A \to B : E_{k}(N_{B},B)
\end{align}
$$
+ **Two-pass mutual authentication**
*Alice* and *Bob* authenticate each other
$$ 
\begin{align}
A \to B : E_{k}(ts_{A},B) \\
B \to A : E_{k}(ts_{B},A)
\end{align}
$$
Where $ts_{A}$ and $ts_{B}$ are either *timestamp* or a *sequence* number

+ **Three-pass mutual authentication**
$$
\begin{align}
B \to A &: N_{B} \\
A \to B &: E_{k}(N_{A},N_{B},B) \\
B \to A &: E_{k}(N_{B},N_{A})
\end{align}
$$
>[!note] 
>This is the composition of two two-pass unilateral authentications

Including the *nonce* $N_{A}$ in the encryption of the second message makes the two unilateral autentication tied in a unique mutual authentication session

Same holds for adding $N_{B}$ in the third message

Also the fact that the *intended reciever* is specified in the second message togheter with challenge $N_{A}$ makes it possible to remove $A$ from the last message as it is enogh to prevent reflections 

## Key exchange

*Strong-authentication* becomes useless if we then send messages in the clear , since an attacker can simply be in the middle and change messages 

This is solved by *exchanging* a new *session key* *while identifiying* , one technique is to *enclose* the new *key* inside the *ciphertext*

### ISO/IEC 11770-2 protocols

+ **One-pass unilateral key-establishment**
$$
A \to B : E_{k}(ts_{A},B,k_{s})
$$
Where $ts_{A}$ is a *timestamp* or a *sequence* number

+ **Two-pass unilateral key-establishment**
$$
\begin{align}
B \to A &: N_{B} \\
A \to B &: E_{K}(N_{B},B,k_{s})
\end{align}
$$
+ **Two-pass mutual key-establishment**
$$
\begin{align}
A \to B &: E_{K}(ts_{A},B,k_{s}^A) \\
B \to A &: E_{K}(ts_{B},A,k_{s}^B)
\end{align}
$$
Where $ts_{A}$ and $ts_{B}$ are either *timestamp* or a *sequence* number

The session key is then computed as a *function* of the two subkeys $k_{s}=f(k_{s}^A,k_{s}^B)$

+ **Three-pass mutual key-establishment**
$$
\begin{align}
B \to A&: N_{B} \\
A \to B&: E_{K}(N_{A},N_{B},B,k_{s}^A) \\
B \to A&: E_{K}(N_{B},N_{A},k_{s}^B)
\end{align}
$$
The session key is computed a before

### [[Diffie-Hellman Protocol|Diffie-Hellman]] key agreement

*Diffie-Hellman* allows for establishing a fresh secret between *Alice* and *Bob* without the need of pre-shared keys or secrets

The scheme is based on the [[Discrete Logarithm Problem]] 

We choose a *prime* number $p$ and a *generator* $a$ of $\{1,\dots,p-1\}$

>[!note] 
>A generator $a$ is a number such that :
>$$
>\{a^1 \mod{p}, \dots, a^{p-1} \mod{p}\} = {1,\dots,p-1}
>$$
>
>If we rise $a$ to all the powers $1,\dots,p-1$ modulo $n$ we obtain all such numbers
>
>>[!example] 
>>$a = 5$ and $p=23$
>>1. $5^1 \mod{23} = 5$
>>2. $5^2 \mod{23} = 2$
>>3. $5^3 \mod{23} = 10$
>>4. $\dots$
>>5. $5^{20} \mod{23} = 12$
>>6. $5^{21} \mod{23} = 14$
>>7. $5^{22} \mod{23}=1$

It can be proven that for *any prime* $p$ there *always exists* at *least* *one* generator $a$ 

We can define the *discrete logarithm modulo* $p$ of any number $1 \le b \le p-1$ as follows : 
$$\log_{a}^b$$ is the power $i$ such that :
$$
a^i \mod{p} = b
$$
>[!example] 
>$b=2$ , $5^2 \mod{23}=2$

Computing the *discrete logarithm modulo* $p$ is **infeasible** for a *big prime* $p$ such that $p-1$ has at least a big prime factor

*Diffie-Hellman* protocol picks one of such big primes $p$ and a generator $a$ of $\{1,\dots,p-1\}$ 

>[!note] 
>prime $p$ and the generator $a$ are public

*Alice* and *Bob* generate two secrets $SA$ and $SB$ and run the following protocol :
$$
\begin{align}
A \to B &: a^{SA} \mod{p} \\
B \to A &: a^{SB} \mod{p}
\end{align}
$$
*Alice* and *Bob* compute the new key respectively as :
1. $(a^{SB})^{SA} \mod{p}$
2. $(a^{SA})^{SB} \mod{p}$

Computing the secrets from the exchanged messages amounts to computing the *discrete logarithm* that is assumed to be **infeasible**

>[!example] 
>Given $p=23$ and $a=5$ are public. Alice chooses $SA=6$, Bob chooses $SB=15$ :
>+ $A \to B : a^{SA} \mod{p}=5^6 \mod{23} = 8$
>+ $B \to A : a^{SB} \mod{p} = 5^{15} \mod{23}=19$
>  
>The new computed key is : 
>+ $(a^{SB})^{SA} \mod{p}= 19^{6} \mod{23} = 2$
>+ $(a^{SA})^{SB} \mod{p}= 8^{15} \mod{23} = 2$

>[!warning] 
>An *active attacker* can still do a *man-in-the-middle* attack where he is able to impersonate *Alice* with *Bob* and *Bob* with *Alice*
>
>He will negotiate a key with both of them so that he can be in the middle on the next sessions

