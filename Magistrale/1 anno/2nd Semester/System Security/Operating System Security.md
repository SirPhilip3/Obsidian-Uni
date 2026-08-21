---
publish: true
---
Programs may be *vulnerable* , The **Operating system** aims at providing *adequate security* guarantees even in presence of *weaknesses*

The *OS* can be hardened by :
+ **whitelisting** approved applications
+ **Patch** third-party applications
+ Allow only *latest version* of the OS
+ Restrict *administrative privileges*
## Security Layers

A system is built in $3$ main security layers : 
+ *Physical hardware*
+ *Operating system* : kernel code, API's, services interacting with physical hardware
+ *User application*
# OS security

## System security planning

The security level of the *OS* must be planned from the very beginning based on : 
+ *porpose* of the system, security requirement
+ categories of users
+ how users authenticate
+ what access to other hosts
+ who administer the system and how
+ what additional security is needed
## Installation

The *OS* should be ideally installed in an isolated environment with *outgoing connections* only towards the necessary sites

*Secure boot* should be enabled , preventing changes in the *BIOS* and limiting the boot media to the trusted ones

>[!note] 
>This prevents the loading of *malicious hypervisors* and the trivial bypass of access control by booting from an esternal drive to access the filesystem

>[!note] 
>Cryptographic file systems add another protection to the stored data by needing a key to decrypt the volume

## Trusted code and patching

*Device drivers* should be installed with care since they have *kernel level* privileges and might be used to install *malware*

System should be up to date with *security patches*
>[!warning] 
>Updates can introduce instability
## Unnecessary services

In general it's better to remove *unnecessary software* to reduce the risk of vulnerability

>[!note] 
>*Not installing* is better than removing or disabiling since it doesnt eliminate everything 

*Access control* is implemented in all modern systems with [[Magistrale/1 anno/2nd Semester/System Security/Access Control#Discretionary Access Control (DAC)|DAC]] , sometimes [[Magistrale/1 anno/2nd Semester/System Security/Access Control#Role-Based Access Control (RBAC)|RBAC]] or [[Magistrale/1 anno/2nd Semester/System Security/Access Control#Mandatory Access Control (MAC)|MAC]] 

Retricting as much as possible *administrative privileges* to only a few users and loggin any administrative actions
## Additional Security

*Anti-virus* can be installed ( traditionally on windows )

*Host-based firewalls* [[Intrusion Detection#Intrusion Detection System ( IDS )|IDS]] can improve security by *filtering* connections, *blocking* ports , monitoring traffic and file integrity 

*Whitelisting* applications to prevent execution of malware
## Application Security

*Default* data, scripts or user accounts should be reviewed and maintained only if *required* since the often include insecure settings 

We should apply *minimum privilege* to the *access rights*
## Logging

It's important to *Log* everything so that after bad things happend we can remediate correctly and *recover* from that

>[!note] 
>*What is logged* is part of the initial security planning phase and depends on :
>+ *security requirements*
>+ *information sensitivity*

>[!note] 
>Logs can become big so its necessary to compress, arcive or delete them

*Logs* should be built to allow for automated analysis perfromed by [[Intrusion Detection#Intrusion Detection System ( IDS )|IDS]]'s
## Backup

It's foundamental to make copies of the data at regular interval allowing for the recovery of lost or corrupted data

it's also a requirement to meet legal and operational requirements

*online* vs *offline* : online backup is easier and cheaper but in case of attack the backups may be destroied

*local* vs *remote* : in case of calamaty the *local* backups would be lost
# Case Studies

## Linux / Unix

## Windows

# Virtualization


