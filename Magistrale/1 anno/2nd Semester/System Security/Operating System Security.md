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

In linux the systems can be easily maintained up to date with tools like `apt`

The configuration of the system is in the `/etc` folder

*Permissions* use [[Magistrale/1 anno/2nd Semester/System Security/Access Control#Access Control List ( ACL )|ACL]]s 

Authentication is available through the *PAM* ( *pluggable authentication module* )

Linux offers *remote access* through a *tcp* wrapper that enforces hostname-based *access control* using `/etc/hosts.allow` and `/etc/hosts.deny` 

`netfilter` allows for host-based *firewalling*

*Logging* is provided through `syslogd` 

We can use `chroot` to set the root directory of a service so that the rest of the filesystem is not accessible

Uses [[Magistrale/1 anno/2nd Semester/System Security/Access Control#Mandatory Access Control (MAC)|MAC]] that allows for centralized policies that can't be changed by root

*SELinux* have implementation of **MAC** that have restrictions for crucial system processes and than uses standard [[Magistrale/1 anno/2nd Semester/System Security/Access Control#Discretionary Access Control (DAC)|DAC]] this is more *usable* 
## Windows

Application configuration are centralized in the *Registry* as a database of keys and values

**Permissions** : [[Magistrale/1 anno/2nd Semester/System Security/Access Control#Access Control List ( ACL )|ACL]]s grant access to *SID* ( *Security ID*'s ) that refers to a user or group

**User accounts** : *SAM* ( *Security Account Manager* ) manages the accounts centralized through *Active Directory* based on *LDAP* ( *Lightweight Directory Access Protocol* ) 

Windows can have *System wide privileges* in general used to perform backups and system configurations, they shuold be granted with care

The administrative rights are only used when required through *User Account Control*

*Low Privilege Service Accounts* are used for long-lived service processes

Windows has the possiblity to use *Encryption* on the *File System* ( *EFS* ) to protect against phisical access 
# Virtualization

>[!important] Definition
>**Hypervisor** is the software that stays between the hardware and the *Virtual Machines* and acts as a resource broker
>
>It provides *abstraction* of all physical resources and enables for multiple *VM* to be run on the same physical host

## Type 1 hypervisor

A *type 1 hypervisor* is loaded as a software layer directly onto a physical server

It's called **native virtualization** since the hypervisor can directly control the physical resources of the host

![[Pasted image 20260821213453.png]]

This *performs better* than type 2 hypervisors

>[!note] 
>This is generally more secure than a type 2 hypervisor , since it has fewer layers to protect 
## Type 2 hypervisor

A *type 2 hypervisor* is loaded as a software layer on a host *OS* installed on the physical server

This is called **hosted virtualization** where the *hypervisor* relies on the host *OS* to access physical resources

![[Pasted image 20260821213624.png]]

>[!note] 
>Host based virtualization does not require to dedicate the full machine to *VM*'s
## Containers

Virtualization containers provide an *isolated environment* for application that can *share* the same *OS kernel*

This is loaded as a software layer on a host OS

![[Pasted image 20260821214159.png]]
## Security

**VM escape** is a vulnerability in the *hypervisor* that might allow *VM*s and virtualized applications to *access* :
+ The hypervisor
+ other VMs
+ the host OS

Or in the contrary a *Host OS attack* is a vulnerability in the host OS that allows to access the guest OS images

>[!warning] 
>This kind of vulnerabilities might allow for taking full control over the physical server or the host OS

---
A *VM* is secured in a similar way to an *OS* 

Traffic from a *VM* should be ideally separated using *different* *physical interfaces* , *VLAN*'s or *Software Defined Networks* ( *SDN*s )

---
*VM*s can have *virtual firewall*

**VM Bastion Host** : it separates *VM* by running Bastion Host services ( *firewalls* , *IDS* etcc ) to monitor the virtual network interfaces used by *VM*s

**VM host-based firewall** : Guest OS can use *host-based protection* as if it were running on physical hardware 

**Hypervisor firewall** : a firewall supported directly inside the hypervisor , this is more efficent than *VM Bastion Host* since it doesn't compete for resources with other *VM*'s , this is more secure in principle since it's invisible by other *VM*'s but adds complexity to the hypervisor 

