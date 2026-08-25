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

*Adding redundancy* 

### Reflection

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

###