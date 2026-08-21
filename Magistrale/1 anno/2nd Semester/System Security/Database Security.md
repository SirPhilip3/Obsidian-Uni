---
publish: true
---
Database are important to protect since they tend to contain *sensitive information*

Database need *dedicated access control* systems and security mechanisms

## SQLi

>[!important] Definition
>*Injection attack* is when the attacker triggers unexpected behaviour by supplying untrusted , malicious input to an application

Web applications have *dynamic content* that depends on data stored in databases , when queries depend on *untrusted user input* an attacker might inject malicious SQL code that will be sent to the datanabe

>[!example] 
>Typical attack : 
>1. Attacker sends *malicious input*