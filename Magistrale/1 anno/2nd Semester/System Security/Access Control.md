---
publish: true
---
>[!important] Definition
>*Access Control* is the protection of system resources against unauthorized access

The access to *system resources* is regulated according to a *security policy* where access is permitted only by authorized entities

# Definitions

**Authotization** : The granting of a right or permission to a system entity to access a system resource. This determines who is trusted for a given purpose

**Audit** : an independent review and examination of system records and activities in order to : 
+ *test* for *adequacy* of controls
+ *ensure compliance* with established policy and operational procedures
+ *detect breaches* in security and recommend changes in control, policy and procedures

**Subject** : is an entity capable of accessing resources ( *objects* )

**Object** : is a resource to which access is controlled. An *object* is an entity used to contain and/or receive information

>[!example] 
>pages , files , directories , I/O devices etcc

Any user or application *gains access* to an object by means of a *process* which inherits the attributes of the user such as the access rights  

## Access rights

+ **Read** :
	+ *Subject* may *view* information in an object, read access includes the ability to *copy* or *print*
+ **Write** :
	+ *Subject* may *add* , *modify* or *delete* data in an object
+ **Execute**
	+ *Subject* may *execute* a program
+ **Delete** :
	+ *Subject* may *delete* an object
+ **Create** :
	+ *Subject* may *create* an object
+ **Search**
	+ *Subject* may *search* into an object

>[!note] 
>One access right might imply another one , for example read implies also search

# Access Control Policies

## Discretionary Access Control (DAC)

It can be implemented with a :
1. ***Access matrix*** : we define access right for each *subject* ( rows ) and *object* ( column )

>[!example] 
>
>|           | README.txt    | /etc/shadow   | Carol.pdf     | /bin/bash                |
| --------- | ------------- | ------------- | ------------- | ------------------------ |
| **Alice** | Read<br>Write | Read<br>Write |               | Read<br>Write<br>Execute |
| **Bob**   | Read          |               |               | Read<br>Execute          |
| **Carol** | Read          |               | Read<br>Write | Read<br>Execute          |

2. ***Access Control List*** ( *ACL* ) : for each *object* lists *subjects* and their permission rights 

>[!note] 
>*Easy* to find which subjects have access to a certain *object*

>[!warning] 
>*Hard* to find all the access rights for a certain subject

>[!example] 
>```
>README.txt
>	Alice: Read, Write;
>	Bob: Read;
>	Carol: Read;
>/etc/shadow
>	Alice: Read, Write;
>```

3. ***Capabilities*** : for each *subject* list *objects* and access rights to them

>[!note] 
>*Easy* to find all the access rights for a certain subject

>[!warning] 
>*Hard* to find which *subjects* have access to a certain *object*

>[!example] 
>
>```
>Alice:
>	README.txt: Read,Write;
>	/etc/shadow: Read,Write;
>	/bin/bash: Read,Write,Execute.
>Bob:
>	README.txt: Read;
>	/bin/bash: Read,Execute.
>```

#todo 
## Mandatory Access Control (MAC)

## Role-Based Access Control (RBAC)

## Attribute-Based Access Control (ABAC)