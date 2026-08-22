---
publish: true
---
*Formal models* of computer security can be used to prove that : 
+ *design* satisfies a set of security requirements
+ *implementation* conforms to the design

## BLP formal model

[[Magistrale/1 anno/2nd Semester/System Security/Access Control#Bell - La Padula ( BLP )|BLP]] can be stated *formally* 

**Assume** : 
+ $S_{1},\dots,S_{m}$ subjects
+ $O_{1},\dots,O_{n}$ objects
+ $A_{1},\dots,A_{w}$ access modes ( read, write, append )

It has a *state* , a $3-$tuple $(b,M,f)$ defined as :
+ $b$ : *current access set* of triples, where $(S_{i},O_{j},A_{x})$ rapresent subject $S_{i}$ accessing object $O_{j}$ in mode $A_{x}$
+ $M$ : *access matrix* of permitted access modes where $M_{ij}$ contains modes for subject $S_{i}$ accessing object $O_{j}$
+ $f$ : *level function* assigning a security level to subjects and objects
	+ $f(O_{j})$ is the security level of object $O_{j}$
	+ $f(S_{i})$ is the security level of subject $S_{i}$

### BLP secure state

The **Simple security** property can be written as : 
	Every triple of the form $(S_{i},O_{j},read)$ in the current access set $b$ has the *property* :
$$
f(S_{i})\geq f(O_{j})
$$
The **\*-property** can be written as :
	Every triple of the form $(S_{i},O_{j},write)$ in the current access set $b$ has the *property* :
$$
f(S_{i}) \leq f(O_{j})
$$

In addition to *MAC* , *BLP* also forces [[Magistrale/1 anno/2nd Semester/System Security/Access Control#Discretionary Access Control (DAC)|DAC]] in terms of the access control matrix $M$ , it can be formalized as follows :
The **ds-property** :
	If $(S_{i},O_{j},A_{x})$ is a current access in $b$ , then access mode $A_{x}$ is present in $M_{ij}$. That is :
$$
A_{x} \in M_{ij}
$$
### BLP abstract operations

**Get access** : initiate access to an object by adding $(S_{i},O_{j},A_{x})$ to $b$ 

If $A_{x}$ is $read$ then to maintain the *BLP* properties we need to check that $f(S_{i})\geq f(O_{j})$ and $read \in M_{ij}$ 
Also if $A_{x}$ is $write$ instead we need to check that $f(S_{i})\leq f(O_{j})$ and $write \in M_{ij}$

**Release access** : release access to an object by removing $(S_{i},O_{j},A_{x})$ from $b$

**Change object level** : change the value of $f(O_{j})$ for some object $O_{j}$

We need to check that for the new value of $f(O_{j})$ we have that : 
$\forall i \ (S_{i},O_{j}, read) \in b \implies f(S_{i}) \ge f(O_{j})$
$\forall i \ (S_{i},O_{j}, write) \in b \implies f(S_{i}) \le f(O_{j})$

**Change subject level** : change the value of $f(S_{i})$ for some object $S_{i}$

**Give access permission** : grant an access mode , add $A_{x}$ to $M_{ij}$

**Revoke access permission** : delete an access mode , remove $A_{x}$ from $M_{ij}$ 

Check that $(S_{i},O_{j},A_{x})\notin b$

**Create an object** : add a new object $O_{j}$ with security level $f(O_{j})$

**Delete an object** : remove object $O_{j}$

>[!note] 
>When an action violates a *condition* :
>+ the action is *forbidden* or
>+ the state should be updated by releasing accesses that violate the new permission or level

### BLP security proof

A *state* ( $(b,M,f)$ ) is *secure* if and only if every element of $b$ satisfies the *three* properties

>[!important] 
>A system starting from a *secure state* remains *secure* if and only if any *operation* *preserves* the three properties

>[!note] 
>It's theoretically possible to prove that an actual implementation is *secure*, but for complex system this proofs simplify too much 

## Implementing BLP in [[Magistrale/1 anno/2nd Semester/System Security/Access Control#Role-Based Access Control (RBAC)|RBAC]] 

+ *Constraint on Users* :
	For each subject $s$ a security *clearance* $L(s)$ is assigned

+ *Permission* :
	For each role $r$ and object $o$ assign $read/write$ permissions ( *access matrix* )

+ *Constrain on Objects* :
	For each object $o$ a security *classification* $L(o)$ is assigned

+ *Read-level* :
	The read-level of a role $r$ ( *r-level(r)* ) is the *least upper bound* of the security levels of the objects for which *read* is in the permissions of $r$

+ *Write-level* :
	The write-level of a role $r$ ( *w-level(r)* ) is the *greatest lower bound* of the security levels of the objects for which *write* is in the permissions of $r$

+ *Constraint on role assignment* :
	The *clearance* of the subject must *dominate* the *r-level* of the role and *be dominated* by the *w-level* of the role
$$
\begin{align}
L(S) \ge r-level(r) \\
L(S) \le w-level(r) 
\end{align}
$$
>[!note] 
>The *r-level* of the *role* indicate the least security classification that dominates the level of objects readable from the role

**Simple security** property demands that a *subject* is assigned *to* a *role* only if the subject's clearance is *at least as high* as the r-level of the role

>[!note] 
>Same but with *write* access in the **\*-property**
# Trusted systems

>[!important] Trusted computing base ( TCB )
>part of the system *enforcing* a particular policy , small enough to be analyzed

## Trusted Platfrom Module (TPM)

**TPM** is a hardware module integrated in the CPU, motherboard or smartcards that is at the heart of a hardware / software approach to trusted computing

It's an hardware, *tamper resistant* **Trusted Computing Base** ( **TCB** ) 

*TPM* works with *TC*-enabled software including the OS and applications

The software can be assured that the data it recieves are *trustworthy* and the system can be assured that the software itself is trustworthy

*TPM*s offer three services :
### Authenticated boot service 

It's responsible for booting the entire OS , assuring that it's an approved version for use

Boot happens in *stages* :
+ *Boot ROM* is loaded
+ *Boot Block* on storage is loaded
+ *Larger blocks* are loaded until the fill OS is loaded

At each stage the *TPM* checks that valid software has been loaded by verifying a digital signature

Also *TPM* keeps a *tamper-evident log* of the loading process
>[!note] 
>A cryptographic hash function is used to detect any tampering with the log

*TPM* can expand it's *Trust boundary* to include additional hardware and application 

The *TC*-enabeled system checks whether any new component : 
+ is on the *approved list*
+ is *digitally signed*
+ has a serial number *not revoked*
### Certification Service

*TPM* has a mechanism to certify the trusted configuration to other parties 

This produces a *digital certificate* by **signing** a description of the configuration using the *TPM*'s private key

>[!note] 
>Only the *TPM* has his particular private key, it's public ket can be used to verify the signature

>[!warning] 
>A simple *replay* attack might work in the following way : 
>+ *intercept* TPM certification
>+ *compromise* the system
>+ *replay* the certification when needed to prove trustworthiness of the attacked system
>
>***Solution*** : TPM includes a random chellenge $R$ from the requester in the signature to prevent replays
>![[Pasted image 20260822113201.png]]
### Encryption

It allows for encryption relative to a certain machine so that it can only *decrypted* if that machine is in a certain *trusted configuration*

It has a master key that is used to derive many encryption *keys* *one* *for* each trusted *configuration* 

It allows for **hierarchical trust** where *TMP* provides an ecnryption key to a certified application so that it can encrypt it's data , decryption can only be done by : 
+ the *desired* *version* of the *desired application* running on the *desired version* of the *desired OS*  

