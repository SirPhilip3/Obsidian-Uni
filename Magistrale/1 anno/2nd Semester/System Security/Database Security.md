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
>2. The web application server executes the query that contains that malicious input
>3. The result of the query is included in a dynamic web page
>4. Attacker extract sensitive data directly from the web page

>[!example] 
>We have the following query : 
>```SQL
>SELECT * FROM Users WHERE Name = '" + Username + "'"
>```
>
>Where `Username` is the untrusted input , if an attacker inserts the following `Username = "'; DROP TABLE Users --"` the whole User table will be destroyed
>
>This works because we closed the `Username` input with `'` giving a null username and then entering another SQL command and then adding `--` to comment out the rest of the query

There can be various *origins* for an *injection* : 
+ **User input** 
	+ Inputs from *forms* to compose *SQL* queries
+ **Server variables**
	+ Headers logged used for usages statistics
+ **Second-order injections**
	+ The attacker injects data in the database that is used to compose another query
+ **Cookies**
	+ If the cookie value is used to compose queries
+ **Physical user input**
	+ Bracodes, RFID tags, scanned documents etcc

## SQLi Attack Types

### Inband

When the application uses the same communication channel for *SQLi* and *retrieving results*

+ **Tautology**
Injects code in conditional statements so that they *always* evaluate to *true*

>[!example] 
>Authentication check
>```SQL
>SELECT * FROM Users WHERE
>Name = '"+ Username +"' AND
>Pwd = '"+ Password +"'
>```
>
>Authentication fails if the query returns an empty result
>
>The attacker can inject `Username = "admin"` and `Password = "'OR 1=1 --"`
>
>This makes the `WHERE` condition *always true*
>

+ **End-of-line comment** 
The part after the comment is nullified through the usage of end of line comments

>[!example] 
>The attacker injects in the previous query : `Username = "admin' -- "` and `Password = ""` 
>
>This *nullifies* the **AND** condition , not checking the password

+ **Piggybacked queries** 
The attacker adds additional queries beyond the intended query 

>[!note] 
>This attack requires that the server configuration allows for different query within a single string of code
>
>The attacker injects `Username = "'; DROP TABLE Users -- "` and `Password = ""`
>
>This terminates the query at the username check and piggibacks the query that drops the user table
### Inferential

There is no direct leakage of infromation , the attacker reconstructs the information by observing the resulting behaviour

+ **Incorrect queries** 
The default error page is often overly descriptive it can be revealing : 
+ The *query* or a significant part of the query
+ *Name* of tables and columns
+ Input *filtering*

This is typically the first step of attacks to get information about the *DBMS*

+ **Blind SQL injections**
The attacker infers data from the database even qhen the application does not display errors or data

The attacker "asks" true/false questions and observes the behavious 

## SQLi Countermeasures

We need to apply *Defensive coding* techniques like : 
+ *Whitelisting inputs*  
	+ Check that input belongs to a whitelist of trusted values
+ *Strict typing* 
	+ Check input type
+ *Prepared statements*
	+ The query get's parametrized and pre-parsed so that the prameters never get's interpreted as code
+ *Typed API's*
	+ generic API's for the DBMS access with typed parametrized queries
+ *Trusted input*
	+ Ensure input authenticity ( *HMAC* )
+ *Sanitization*
	+ Use standard functions to sanitize the input
## Database Access Control

Control access to specific portions of the database using [[Magistrale/1 anno/2nd Semester/System Security/Access Control#Discretionary Access Control (DAC)|DAC]] and [[Magistrale/1 anno/2nd Semester/System Security/Access Control#Role-Based Access Control (RBAC)|RBAC]] 

To manage the priviledges *SQL* has two operations :
+ **Grant** : to grant access on specific tables to users / roles
>[!example] 
>`GRANT SELECT ON * TO alice`
>
>Grants `SELECT` ( *read* ) access on the whole database to use `alice`
+ **Revoke** : used to revoke access rights previously granted
>[!example] 
>`REVOKE SELECT ON * FROM alice`
>
>Revoke the previously granted premission

>[!note] 
>Privileges granted with `GRANT` can be granted to more users
>>[!example] 
>>```SQL
>>GRANT SELECT ON * TO alice 
>>WITH GRANT OPTION
>>```
>>Delegates `alice` to grant the same permission to other users

The revoking can be on `CASCADE`

>[!example] 
>``` SQL
>REVOKE SELECT ON * FROM alice
>CASCADE
>```
>
>This revokes all permissions from `alice` and from all the users that got the permission through `alice`

We can also create *Roles* that gather specific permission in a single space so that we can assign them to various users 

