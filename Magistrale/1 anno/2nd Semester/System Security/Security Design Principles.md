---
publish: true
---
1. In general the design of security measures embodied in both hardware and software should be as **simple** and **small** as possible

>[!note] 
>*Complex* mechanism are more *vulnerable* and hard to maintain and configure

2. *Fail-safe default* : Access decisions should be based on **permission** rather than exclusion 

>[!note] 
>A mistake will tend to refuse permission ( *safe* and easy to detect )
>

>[!warning] 
>*access* based on *exclusion* might permit unauthorized access that would be hard to notice

3. *Complete mediation* : every access must be checked against the access control mechanism

>[!note] 
>This means that we can't use *caching* for access decisions since they would ignore changes in the access policy

4. *Open design* : the design of a security mechanism should be open rather than secret

>[!note] 
>Open design allows for expert reviews

5. *Separation of privilege* : **multiple privilege** attributes are required to achieve a sensitive task 

>[!example] 
>multi-factor user authentication requires the use of multiple techniques

6. *Least privilege* : every process and user of a system should operate at the **least set of privileges** necessary to perform the task

7. *Layering* : use of **multiple**, **overlapping** **protection** approaches so that failure of one protection system will not leave the system unprotected

8. *Psychological acceptability* : the security mechanism should not interfere with the work of users 

>[!note] 
>Low usability might lead to users turning off those mechanism or making mistakes

9. *Isolation* : physical or logical isolation of critical information / resources 

>[!example] 
>Files and processes of users shoud be isolated from one another

10. *Modularity* : use a mosular architecture for mechanism design and implementation

>[!note] 
>These are common security modules shared by various applications that can be easily maintained 

# Computer Security Strategy

A security policy has always some tradeoffs : 
+ *Ease of use versus security* : more security involves penalties in usability
+ *Cost of security versus cost of failure and recovery* : 
	  When designing a security system the cost of failure and recovery should be considered , this depends on the asset *value* and on the *risk* and *cost* of attacks
## Attack trees

Attack trees allow us to methodically describe the security of a system 

Each *node* can be *OR* ( is possible if one child is possible ) or *AND* ( is possible if all children are possible )

>[!example] 
>![[Pasted image 20260817114004.png]]
>
>The dotted lines rapresent possible attaks , not that this can change depending on other requirements , for example that the cost of the attack must be less than some value
>
>![[Pasted image 20260817114331.png]]

>[!note] 
>Values can be associated to each *node* 
>>[!example] 
>>We can attach the cost of that attack or the need of special equipment to perform that attack

## Security implementation

1. *Prevention* :
	+ The ideal security scheme should be where no attack is successful but this is not always *practical*
2. *Detection* :
	+ When absolute protection is not feasable we should be able to detect security attacks using an *Intrusion Detection System* ( *IDS* )
3. *Response* :
	+ The system responds in such a way to halt the attack and prevent further damage , for example by blacklisting malicious IP's
4. *Recovery* :
	+ The system should be able to recover the state prior to the attack using backups

## Correctness 

**Assurance** : confidence that the system operates such that the system's security policy is enforced 

>[!note] 
>Formal analysis will help in determinig if the security system and its implementation meet the specification and requirements

**Evaluation** : process of examining a computer product or system with respect to certain criteria