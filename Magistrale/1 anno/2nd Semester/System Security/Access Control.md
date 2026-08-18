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

### Access matrix

we define access right for each *subject* ( rows ) and *object* ( column )

>[!example] 
>
>|           | README.txt    | /etc/shadow   | Carol.pdf     | /bin/bash                |
| --------- | ------------- | ------------- | ------------- | ------------------------ |
| **Alice** | Read<br>Write | Read<br>Write |               | Read<br>Write<br>Execute |
| **Bob**   | Read          |               |               | Read<br>Execute          |
| **Carol** | Read          |               | Read<br>Write | Read<br>Execute          |

### Access Control List ( ACL )

For each *object* lists *subjects* and their permission rights 

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

### Capabilities 

For each *subject* list *objects* and access rights to them

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

### Authorization Table

We store an entry in a database for each *subject* , *access right* and *object*

+ Querying by *subject* gives us [[Magistrale/1 anno/2nd Semester/System Security/Access Control#Capabilities|Capabilities]] 
+ Querying by *object* gives us [[Magistrale/1 anno/2nd Semester/System Security/Access Control#Access Control List ( ACL )|ACL]] 

>[!example] 
>
>| Subject | Access right | Object      |
| ------- | ------------ | ----------- |
| Alice   | Read         | README.txt  |
| Alice   | Write        | README.txt  |
| Alice   | Read         | /etc/shadow |
| Alice   | Write        | /etc/shadow |
| Alice   | Read         | /bin/bash   |
| Alice   | Write        | /bin/bash   |
| Alice   | Execute      | /bin/bash   |
| Bob     | Read         | README.txt  |
| Bob     | Read         | /bin/bash   |
| Bob     | Execute      | /bin/bash   |

>[!warning] 
>In *DAC* a *subject* can give access to the *object* it owns 
>
>We can have the following attack scenario : 
>1. A malware is executed by Alice , since it inherits her's access rights it can give access to other malicious *subjects*
>2. Alice might *erroneously* give read access to malicious users

## Mandatory Access Control (MAC)

*MAC* imposes rules that subjects *cannot change* 

>[!example] 
>
>Alice can access some files but will not be able to make those file accessible to others
>

This preventes the previous two problems of *DAC*
### Bell - La Padula ( BLP )

We define *security levels* 

*Subjects* and *objects* are assigned to security levels 

>[!note] 
>+ *Clearance* : the security level of subjects
>+ *Classification* : the security level of objects

Information should never flow from a level to lower ones :
+ **Simple security** : Subjects *cannot read* from objects at a *higher* level
+ **\*-property** Subjects *cannot write* into objects classified at a *lower* level

>[!note] 
>Also uses standard [[#Discretionary Access Control (DAC)|DAC]]

>[!warning] Covert channels
>
>Speed of a program that is shared between levels can encode information
>>[!example] 
>>Slow could encode a $0$ , Fast a $1$

### Chinese wall

The goal of this system is to prevent *conflict of interest* 

+ Objects belongs to *company datasets*
+ The company datasets belong to some *conflict of interest classes*

>[!note] Idea 
>Subjects cannot access objects from different companies that belong to the same *conflict of interest class*

>[!example] 
>We have $3$ objects : Bank A, Oil company B, Oil company C
>
>B and C *objects* are in conflict
>
>Subject $S$ access objects from $B$ cannot access $C$ objects and can access $A$'s objects
>

#### Simple security

**Read** access is granted if *object* :
+ is in the same *company dataset* as an already accesed object
+ belongs to an entirely *different conflict of interest* class

>[!warning] 
>Write access can create conflicts
>
>As before we have : Bank A, Oil company B, Oil company C 
>
>B and C *objects* are in conflict
>
>Now :
>1. Subject $S'$ reads from $C$
>2. Subject $S$ reads from $B$ and writes into $A$
>3. Subject $S'$ reads from $A$
>
>Now $S'$ has access to $B$ without ever violating the conflict thanks to $S$

#### \*-property

**Write** access is granted if :
+ access is permitted by the *simple security property* **AND** 
+ no object can be read which is in a *different company dataset* to the one for which write access is requested

>[!important] 
>This rule is very restricitive

## Role-Based Access Control (RBAC)

+ *Subjects* are assigned to **roles** 
+ **Roles** have the access rights to *objects*

>[!note] 
>*RBAC* can express [[#Discretionary Access Control (DAC)|DAC]] and [[#Mandatory Access Control (MAC)|MAC]] policies

Uses *Access matrix* : access rights for each **role** ( *row* ) and **object** ( *column* )

>[!example] 
>|                   | README.txt    | /etc/shadow   | Carol.pdf     | /bin/bash                |
| ----------------- | ------------- | ------------- | ------------- | ------------------------ |
| **Administrator** | Read<br>Write | Read<br>Write |               | Read<br>Write<br>Execute |
| **Student**       | Read          |               |               | Read<br>Execute          |
| **Professor**     | Read          |               | Read<br>Write | Read<br>Execute          |

For *role assignment* : for each *subject* ( row ) and *role* ( column ) we set a bit to assign the role

>[!example] 
>
>|           | Administrator | Student | Professor |
| --------- | :-----------: | :-----: | :-------: |
| **Alice** |       x       |         |     x     |
| **Bob**   |               |    x    |           |
| **Carlo** |               |         |     x     |

>[!note] 
>We can have *multiple roles* per user and *multiple users* per role

Users establish sessions with the *roles the need* to accomplish a task ( least privilege principle )

Roles can be organized as *hierarchy* 

Roles might be *mutually exclusive* to enforce *separation of duties*

>[!important] Definition
>**Separation of duties** : if one task requires two users to be performed
## Attribute-Based Access Control (ABAC)

Access regulated through attributes 

>[!example] 
>