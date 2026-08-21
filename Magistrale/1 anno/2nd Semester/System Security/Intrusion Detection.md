---
publish: true
---
>[!important] Definition
>
>**Intrusion** : unauthorized act of *bypassing* the security mechanisms of a system
# Classes of intruders

+ **Cybercriminals** : member of organized crime motivated by financial reward
+ **Hacktivists** : individual or groups motivated by social and political causes
+ **State-sponsored organizations** : hackers sponsored by governments to conduct espionage or abotage activites
+ **Other** : generally motivated by technical challenges and reputation

*Skills* :
+ **Apprentice** : aka script kiddies have minimal technical knowledge and reuse existing attack toolkits 
+ **Journeyman** : modifies and extends existing tools finding new variants of vulnerabilities
+ **Master** : high level technical skill able to find *0-days* vulnerabilities typically employed by state-level organizations

>[!example] Example intrusions
>+ Remote server compromise
>+ Web server *defacing* 
>+ Password cracking
# Behaviours

1. *Target acquisition and information gathering* 

The attacker identifies and characterizes the target system by :
+ *examinig* corporate website
+ use network exploration / scanning tools such as *DNS lookup* and *NMAP*
+ Identify potential *vulnerable* services
+ *Interact* by email

2. *Initial access* 

Is the initial access to the target system based on the previous phase by :
+ exploting a *vulnerability*
+ guess weak *credentials*
+ install *malware* by phishing

3. *Privilege escalation*

An attacker exploits a *local vulnerability* to increase privileges by :
+ *Search* for local vulnerabilites
+ Install *sniffers* to capture administrator passwords

4. *Information leakage and system exploit*

Leak sensitie data and use local data to access other systems by :
+ Scanning and examining files
+ Transfer sensitive data 
+ Use guessed or captured passwords to access other systems

5. *Maintaining access* 

Enable continued access to the systems by :
+ Installing remote administrator tools , [[Malware#Rootkit|Rootkits]] with *backdoors*
+ Use admin priviledges to modify or disable intrusion detection systems

6. *Covering tracks* by hiding installed or modified files with *Rootkits* and also removing *logs*

# Intrusion Detection System ( IDS )

***IDS*** is an hardware or software systems that analyzes information from a computer or network to *identify* possible intrusions

**Sensors** collect data that might contain evidence of intrusion
+ networks packets
+ logs
+ syscall traces

**Analyzers** receive input from sensors and *determine* if an intrusion occurred 

>[!note] 
>*IDS* can help us in order to quickly detect intrusions and prevent more damage to be done 
>
>Also an effective *IDS* acts as a *deterrent* reducing the attack attempts , also it allows to collect information about the methodologies used that will help our system to become *stronger*

## Analysis approaches

There are $2$ main detection methods :
1. **Anomaly detection** 

Involves the *collection* of *data* relating to the behaviour of legitimate users so to create a model of user behaviour , the systems analyzes the user behaviours and when it classifies it as an *intruder*  

2. **Signature or heuristic detection**

Uses :
+ A set of known malicious data patterns ( *signatures* )
+ attack rules ( *heuristics* )

>[!warning] 
>This approach only works for known attack vector not 0-days

### Anomaly-based detection

We have various mathods to build the *user* model :
+ **Statistical**
	+ Create a statistical profile of the *observed metrics* , this is very *simple* and *efficent* but not really flexible since it only considers those specific *metrics*
+ **Knowledge based**
	+ Uses rules to classify legitimate behaviour , this can be *robust* and *flexible* but requires *experts* and is difficult to develop
+ **Machine learning**
	+ Create a classification model , this is *flexible* and *automated* but the model can be attacked using *adversarial ML*

>[!warning] 
>Honest and malicious behaviours also **overlap** , it's important to not have *false negatives* ( intruders missclassified as honest users ) 

>[!warning] *False Positive paradox*
>
>The percentage of real detection is directly correlated to the *base rate* and the *false positive rate*
>>[!example] 
>>A breathalizer has $5\%$ *false positive rate* , assuming that $1/1000$ drivers tested are really drunk than we will have that :
>>
>>+ $1/1000$ gives *true positive*
>>+ $5\%$ of $999$ = $49.95$ gives *false positive*
>>
>>Thos gives a probability of detection of $1/(49.95+1) = 1.96\%$
>>
>
>

In our case systems with *few intrusions* present a big problem since with too many false positves the *IDS* becomes useless as the probability of getting a real detection lowers dramatically 

>[!note] 
>This is not trivial to solve since it would necessary to make detection extreamly tight introducing *false negatives*

This is good to detect :
+ [[Denial of Service]] attacks since they involve anomalous increase in packet traffic and connection attempts
+ *Scanning* attacks , it can be detected by *atypical* flow patterns
+ *Worms* since they show anomalous behaviour on the network since they cause to host to communicate and use ports that they normally dont use
### Signature and Heuristic detection

+ *Signature-based* match known malicious patterns 

>[!example] 
>These are common *anti-virus* programs

This approach is *fast* at detection but needs continuos updates to keep the malware signatures updated, also they are unable to detect 0-days

+ *Heuristic-based*

They use *rules* to identify intrusions and suspiciosu behaviours , these are created by analyzing exisiting attack tools

>[!warning] 
>The *rules* are specific to that machine and operating systems also if they are known attackers can circumvent them

These are good to detect :
+ *Application layer attacks* 
+ *Transport layer attacks* : unusual packet fragmentation 
+ *Network layer attaks* : spoofed IP addresses and illegal IP header  values
+ *Unexpected application services* detect if activity on a transport conncetion is consistent with the expected application protocol
+ *Policy violation* : use of inappropiate websites nad forbidden application protocols

## Host-based IDS ( HIDS )

An *HIDS* monitors the events occurring in a *single host* 

They can detect both *internal* and *external* intrusions

It can use the following *sensors* :
+ **System call traces** :
	+ Monitors the sequences of syscalls made by processes , we can than create *models* for *anomaly based* intrusion detection or *rules* for *Heuristic-based* detection
+ **Log files** :
	+ Uses the system logs as a *sensor*
>[!note] 
>They are easier to manipulate by the intruder but they have less *overhead* than the syscall traces but they also contain *less information*

+ **File checksums**
	+ Compares crypto checksum to known ones , they can detect *integrity* attacks easily but it has significat overhead to manage the checksums
+ **Registry access** 
	+ Monitors access to the registry ( Windows OS specific )
## Network-based IDS ( NIDS )

It monitors *network traffic* for a particular network 

It *inspects network packets* directed to the host 

This system can be deployed :
+ On the **External Perimeter**

This detects *external intrusions* , firewall *misconfiguration* and *outgoing* malicious traffic

>[!warning] 
>It does not detect internal attacks

>[!example] 
>![[Pasted image 20260821113519.png]]

+ Before the **LAN**'s

Detects both *internal* and *external intrusions* , firewall *misconfiguration* , outgoing malicious traffic
>[!example] 
>![[Pasted image 20260821113459.png]]


## Distributed IDS

*Combines* information from a number of sensor both on *host* and *network* based in a **central analyzer** that is able to better identify and respond to intrusion activity ( the best of both *HIDS* and *NIDS* )