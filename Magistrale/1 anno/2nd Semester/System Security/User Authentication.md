---
publish: true
---
# Introduction

*Identification* is the task of correctly identifying a user or entry, this is a *requirement* for enforcing other security properties 

Any time the access to a resource needs to be regulated some form of identification is necessary 

>[!example] 
>Users identify to the *SIM* card using a *PIN*

*Identification* can also be seen as *authenticating* a user or an *entity* 

An *identification* scheme should always prevent :
+ **Impersonation** even by observing previous identifications
+ **Uncontrolled transferability** :
	The verifier should not *reuse* a previous identification to impersonate the claimant with a different verifer, unless *authorized*

>[!example] 
>Reuse same password for different web sites

## Classes of identification schemes

+ **Something known** : Check the *knowledge* of a secret 
>[!example] 
>*passwords*, Personal Identification Numbers ( *PIN* )

+ **Something possessed** : Check the *possession* of a device
>[!example] 
>ATM cards, One Time Password ( *OTP* ) generators

+ **Something inherent** : Check *biometric* features of users
>[!example] 
>Fingerprints, voice and face recognition

### Password-based authentication

We need to use passwords over *encrypted* channels ( `https` ) to avoid sniffing 

To avoid bruteforce attacks we disable the service after some `MAX` attempts, also to make it more difficult in case of *offline* *attacks* ( if the service can't be disabled ) the password must be strong 

Also we should store a [[Introduction to Cryptography#One-way hash function|One-way hash function]] of the passwords in the server , in this way if an attaker has access to the database it will not find the password in clear text

>[!warning] 
>Even if we use a *one-way hash* hackers can precompute hashes of *easy passwords* and see if the hashes match

**Precomputation** can be prevented by adding a random *salt* to the password so that we store also the *salt* in the database and we simply need to check the following : 
$$
h(pwd,salt) =? \text{ pwd hash}
$$

To *slow down brute force* instead of using a single hash hashes are usually **iterated** 

### Token-based authentication

*Token-based authentication* checks the posession of a phisical device : 
#### Memory cards

Memory cards are *Passive* cards that have a memory , and have paired a pin to decypher it's content 

>[!warning] 
>They are easy to clone 

#### Smart cards

Smart cards have an embedded chip that provide some information

The can have two types of interfaces : 
+ *Contact* : a conductive contact plate on the surface of the card is used to transmit commands , data and card status
+ *Contactless* : both the reader and the card have an antenna and communicate using radio frequencies

They can provide the following *protocols* :
+ **Static** : the card provides a fixed secret ( like a passive memory card )
+ **One Time Password** : the card generates a fresh *OTP* that is used for authentication
+ **Challenge-response** : a challenge is processed by the card that produces a response ( digital signature )

#### One Time Passwords

To avoid the problem of *sniffing* a secret and reusing it we use *One Time Passwords* that are **never reused** 

>[!important] 
>The tocken and computer system must be kept *synchronized* so that the computer knows the *OTP* that is usable in this instant
##### Implementation


##### Case Studies


#### Biometrics