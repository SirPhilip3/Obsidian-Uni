---
publish: true
---
*Formal models* of computer security can be used to prove that : 
+ *design* satisfies a set of security requirements
+ *implementation* conforms to the design

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
#todo 