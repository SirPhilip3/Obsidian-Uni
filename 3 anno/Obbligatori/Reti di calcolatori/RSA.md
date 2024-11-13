---
creation: 2024-11-13T09:05:00
---
I principi di **Public Key Encryption** sono : 
+ **Alice** e **Bob** hanno ognuno due *chiavi* 
+ **Alice** possiede una chiave *pubblica* `Pub_A` e una *privata* `Priv_A`
+ **Bob** possiede una chiave *pubblica* `Pub_B` e una *privata* `Priv_B`

>[!important] 
>Le chiavi private devono essere mantenute segrete 

Ciò che *cifriamo* con una chiave *pubblica* può essere *decifrato* **solo** con la corrispondente chiave *privata* 

![[Pasted image 20241113091658.png]]

**Vantaggi** :
+ Public key encryption fornisce [[Secrecy]] 
+ Non necessitiamo di un canale segreto per condividere le chiavi 

## Implementation

In pratica vogliamo una funzione $f: D \to R$ con un parametro aggiuntivo $t$ che ha tre *features* : 
+ 