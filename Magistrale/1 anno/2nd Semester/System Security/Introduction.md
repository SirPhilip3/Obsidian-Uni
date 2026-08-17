---
publish: true
---
# Definitions

>[!important] Confidentiality
>
>**Data confidentiality** : 
>	Confidential information is not disclosed to unauthorized individuals ( sensitive data in a database )
>
>**Privacy** : 
>	Individuals control what information related to them may be *collected* and *stored*, and by/to whom that information may be discosed ( Personal privacy while browsing the Web )

>[!important] Integrity
>**Data integrity** : 
>	Information and programs are *changed* only in a specifed and *authorized* *manner* ( bank account )
>
>**System integrity** : 
>	A system performs its *intended function* free from unauthorized manipulation ( IoT firmware should not be altered )

>[!important] Availability
>
>Systems work promptly and services are *not denied* to authorized users ( E-voting )
>

>[!important] Authenticity
>**Identification** : 
>	The possibility of correctly identifying an entry ( User login )
>
>**Message Authentication** :
>	Confidence in the validity of a transmission, a message, or message originator ( verified email messages )

>[!important] Accountability
>The possibility of *tracing* an event to a unique entry ( digital signature ) or allows us to trace a security breach to a responsible party ( logs )

# Impact of an attack ( FIPS 199 )

Three *levels*

Low :
1. effectiveness of primary functions is *noticeably* reduced
2. *minor* damage to organization assets
3. *minor* financial loss
4. *minor* harm to individuals

*Medium* :
1. effectiveness of primary functions is *significantly* reduced
2. *significant* damage to organization assets
3. *significant* financial loss
4. *significant* harm to individuals

**High** :
1. **unable** to perform one or more primary functions
2. **major** damage to organizational assets
3. **major** financial loss
4. **severe** or **catastrophic** harm to individuals

>[!example] 
>If a patient allergy information system fails / is hacked it may cause *severe harm* or *death* to patients this gives us a **high** requirement for *integrity*
>
>If a university website goes down may cause truble to students and professors but not catastrophic, we will need **medium** requirement for *availability*

# Terminology

**System Resource** ( *Asset* ) :
	A major application, general support system, high impact program, physical plant, mission critical system

**Threat** :
	Any circumstance or event with the potential to *adversely impact* organizational operations, assets, individuals or organization

**Adversary** :
	Who conducts harmful activities

**Vulnerability** : 
	Weakness in an information system that could be *exploited* or *triggered* by a threat source

**Attack** :
	Malicious activity that attempts to collect, disrupt, deny, degrade or destroy *information* and/or system *resources*
	An *attack* is a *threat* that is carried out typically through a *vulnerability* 

**Countermeasure** :
	A device or technique that reduces the effectiveness of an *attack*

**Risk** :
	A measure of the extent to which an entity is threatened based on *impact* and *likelihood*

**Security Policy** :
	A set of criteria for the provision of security services : it *defines* and *containts the activities* of a data processing facility in order to maintain a condition of security for systems and data

# Classes of attacks

1. **Active attack** : An attempt to *alter* system resources or affect their operation
2. **Passive attack** : An attempt to *learn* information from the system without affecting system resources

3. **Inside attack** : Initiated by an entry inside the security perimeter
4. **Outside attack** : Initiated from ouside the perimeter by an unauthorized or illegitimate user of the system

## Attack examples

### Interception

+ An attacker gets *unauthorized access* to information
+ Breaks *data confidentiality*
+ *Passive attack*

Threat *consequence* is ***Unauthorized disclosure***

![[Pasted image 20260816183831.png]]

>[!example] 
>$S$ sends the credit card information in the *clear* to $D$ ( without encryption ) and $S$ intercepts it
### Modification

+ An attacker *maliciously modifies* information
+ Breaks *Integrity* and possibly *authenticity* and *accountability*
+ **Active attack**

![[Pasted image 20260816184309.png]]

>[!example] 
>$A$ redirects $S$ bank transfer to himself ( Man-in-the-middle )
### Falsification

+ An attacker forges *new information*
+ Breaks *authenticity* , *accountability* and *integrity*
+ **Active attack**

![[Pasted image 20260816185732.png]]

>[!example] 
>Forging a signature through a crypto vulnerability , credential theft
### Interruption

+ Attacker *interrupts* a service
+ Breaks *availability*
+ **Active attack**

![[Pasted image 20260816185855.png]]

>[!example] 
>DoS attack

>[!example] Other Examples
>**Incapacitation** : physical *destruction* or *damage* to a system possibly due to malware
>
>**Corruption** : *modification* of a system functions ( placing a backdoor in order to provide subseqeunt access )
>
>**Misappropiation** : malicious software makes *unauthorized use* of processor and operating system resources

