---
publish: true
---
*DoS* is a popular attack aimed to compromising the *availability* of a service 

>[!note] 
>*DoS* is particularly effective when launched from many devices ( *DDoS* ) now also *IoT* devices like webcams etcc

>[!important] Definition
>**DoS** is an attack that prevents or imparis the authorized use of networks, systems or applications by *exhausting resources*

This can be targeting $3$ different types of *resources* : 
+ **Network bandwidth**
+ **System resources**
+ **Application resources**
## Network Bandwidth

>[!important] Definition
>*Network bandwidth* is the capacity of links connecting a server to the internet

Usually this is the *link* to the *ISP* ( *Internet Service Provider* )

This is done because if incoming traffic exceed the bandwidth packets will be *discarded* , so that if *malicious* one exceeds the network capability legitimate one will be blocked 

![[Pasted image 20260820155850.png]]

### Attacks

The attack vector is the *Flooding Attack* aimed to overwhelm network capacity, this can be done as : 
+ **ICMP Flooding**
	+ *Internet Control Message Protocol* is generally used to send error message and operational information , `ping -f` can *flood the server* 
	+ If the target server *responds* to this messages it increases the *load* on the server
+ **UDP Flooding**
	+ Attacker targets a *UDP service* ( ex diagnostic echo )
+ **TCP Flooding**
	+ Attacker targets *TCP services*

A simple flooding attack is done from a *single host* , this makes it *easy* to **identify** 

An attacker can do *Source Address Spoofing* using raw socket interface to change the source address of each packet 

The attacker will *randomly select* source addressed making it difficult to identify 

>[!note] 
>This is possible because *TCP/IP* doesn't ensure that source address corresponds to the originating host 

To identify the *attacker* we should query the logs of traversed routers manually

Also [[Malware#Theft of Service ( BotNets )|BotNets]] can be hired to perform *DDoS*
## System Resources

>[!important] Definition
>*Network handling resources* are the resource required to implement network protocols ( buffers etc.. )

When the limit is reached new network connections are *refused* , this was done by forging *poison packets* that trigger *bugs* that breaks network services 

>[!example] 
>ping of death, teardrop

![[Pasted image 20260820160323.png]]

### Attacks

*SYN spoofing* : this attack overflows the tables used to manage *TCP* connections

>[!note] 
>*TCP* uses a three-way handshake to establish a connection so that *lost IP packets* gets transparently *resent*

**Attack scheme**

1. Attacker sends *SYN* packets with a *spoofed source* addresses
2. For each spoofed source $S$
	1. Server sends *SYN-ACK* to $S$
	2. If Server timeouts and $N_{s}<MAX$ do $N_{S}=N_{S}+1$ and go to 1.1
	3. Delete connection with $S$

>[!note] 
>Since *TCP* needs to keep some memory for connection half opened to wait for the *ACK* message if the attacker forges enough fake addressed $S$ the *memory* will be *full* at some point 

>[!warning] 
>This works because most of the generated addresses will never respond to a *SYN-ACK* message
>

## Application Resources

>[!important] Definition
>*Application Resources* are the ones required to accomplish a task

When the limit is reached the application becomes *unresponsive* 

This is done by exploiting bugs that *crash* the application 

>[!example] 
>Excessively complex queries to a database

![[Pasted image 20260820161119.png]]
### Attacks

The attacker *floods an application protocol* 

>[!example] 
>These protocols can be :
>+ *Session Initiaton Protocol* ( *SIP* ) since invite requests go through proxies and consume resources 
>+ *HTTP* requests can be heavy

**Slowloris** is a particular *DoS* attack that leverages server multi-threading

This creates many *HTTP* requests without completing them and keeping them alive by sending useless data periodically , by creating lot's of requests *all* the *available* web server *connections* will be *consumed* 

To *mitigate* this attack we can check for **human interaction** ( eg use captchas )
# DoS techniques

## Reflection attack

The attacker sends packet to an *intermediary* with a *spoofed source* address of the **target** 

The *intermediary* responds to the actual **target** 

>[!note] 
>If the response is *larger* than request the attack will also be amplified 

>[!example] 
>*DNS* , *SNMP* and *ISAKMP* has been exploited with reflection since they can generate large responses

When *echo* service on port $7$ is enabeled than **refelection loops** are possible 

>[!example] 
>The attacker sends a packet `1.2.3.4` port $7$ with spoofed source address `5.6.7.8` port $7$
>
>![[Pasted image 20260820174051.png]]
>
>Blocking or limiting combinations of ports can *mitigate* this attack
## Amplification attack

An amplification attack is aimed at *generating multiple response* packets with a single request

>[!example] 
>Send a packet to the *broadcast* address of a network with spoofed address , then *all hosts* with broadcast enabeled will *respond* to the target
>
>![[Pasted image 20260820174255.png]]
>
>A *defense* in this case is to simply block *broadcast*
# Defenses

>[!important] 
>*DoS* **cannot** be fully **prevented** because legitimate incidental traffic can also cause the same behaviour 

## Preventing spoofed source addresses

+ **Filtering** spoofed source address as close as possible to the originating host
>[!example] 
>Where the organization connects to the internet

+ Ensure that the **path back** to the claimed source address is the one used by the current packet 
>[!note] 
>This solution is *too strict* when the two path A->B and B->A *differ*

## Preventing SYN spoofing

The solution is to make the protocol *stateless* by encoding the state information directly into the *SYN-ACK* message by adding the sequence number $y$ , this does not need a *TCP table* on the server

## Mitigations 

*ICMP* and *UDP* flooding to diagnostic services ( ping ) can be mitigate by imposing *limits* on packet rates 

*SYN spoofing* can also be mitigated by *limiting* the connection rate to a certaine service 

Also *table overflow* in *TCP* can be mitigated by *dropping* random connections
>[!warning] 
>This can drop legitimate connections also

# Detenction

To *detect* this types of attack we need to capture and analyze packet flow , after this we can activate proper *filters* , solve *bugs* , create *backups* etcc 