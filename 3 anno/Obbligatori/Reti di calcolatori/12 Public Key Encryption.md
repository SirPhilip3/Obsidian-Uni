---
creation: 2024-11-12T11:20:00
---
 Con *public key cryptography* **Alice** e **Bob** possono comunicare in sicurezza senza scambiarsi nessuna informazione segreta 

Questa si basa sull'*intrattabilità* di certi problemi : 
+ ![[Integer Factorization Problem]]
+ ![[Discerte Logarithm Problem]]

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
+ $f$ è semplice da computare nella direzione $D \to R$
+ $f$ è semplice da computare nella direzione $R \to D$ solo se conosci $t$ 
+ Risulta essere teoricamente *inpossibile* computare $f$ in direzione $R \to D$ se non conosci $t$ 

>[!danger] 
>
>Non esistono funzioni matematiche che sono invertibili solo se conosciamo un certo parametro $t$ , dobbiamo fare affidamento sul fatto che possiamo approssimare questo tipo di funzioni in modo che sia [[Computationally Impossible]]

Gli algoritmi che la implementano sono : 
+ ![[Diffie-Hellman Protocol]]
+ ![[RSA]]
+ Elliptic curve encryption 

