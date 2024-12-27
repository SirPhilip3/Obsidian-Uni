---
publish: true
creation: 2024-12-27T16:01:00
---
# Introduction

Per raggiungere una comunicazione bi-direzionale sicura possiamo usare : 
+ [[Hash Functions]] per garantire integrità dei dati
+ **Symmetric Key Encryption** per garantire la velocità nella cifratura e decifratura dei dati
+ [[Public Key]] *Encryption* per garantire [[Data authentication]] e [[Non repudiation]]
+ [[Certificate]] per avere una **Web of Trust**

A second del layer dello stack [[TCP IP]] in cui vogliamo inserire la sicurezza abbiamo dei *pro* e dei *contro* : 
+ Più in basso lo mettiamo più informazioni possiamo cifrare , ma alcune cose potrebbero non funzionare 
+ Più in alto meno supporto dobbiamo avere dal sistema operativo , ma meno infomazioni possiamo cifrare 
## IP Encryption

Non possiamo cifrare l'header **IP** poichè è necessario per fare routing ai router intemedi , dovremmo avere una *security association* con ogni router 

>[!warning] 
>Questo renderebbe inutile cifrare i dati perchè tutti potrebbero decifrarli 

Un possibile metodo sarebbe usare una **VPN** ( **Virtual Private Network** ) , questo incapsula il pacchetto **IP** criptato in un'altro non criptato con cui viene fatto il routing

>[!note] 
>Questo necessita del setup nelle reti si di *Alice* che *Bob*

## TCP Encryption

Essendo [[18 TCP - UDP#Transmission Control Protocol (TCP)|TCP]] un protocollo *end-to-end* tecnicamente sarebbe possibile tuttavia su internet esistono le *middleboxes* , questi sono host che necessitano di vedere l'header **TCP**

Inoltre se **TCP** fosse cifrato una **NAT** non funzionerebbe più ( nemmeno firewall o fare *traffic shaping* ) 

>[!note] 
>Come prima la **VPN** risolve questo problema ma non è largamente utilizzata

>[!note] 
>Se non cifriamo **TCP** un attaccante può sapere la porta di destinazione del protocollo , questo permette all'attacante di fare profiling ( essendo che le porte per vari servizi sono conosciute l'attacante saprà cosa sta facendo la vittima )

## TLS ( Transport Layer Security ) / SSL ( Secure Socket Layer )

Questo viene aggiunto al di sopra di [[18 TCP - UDP#Transmission Control Protocol (TCP)|TCP]] 

>[!note] 
>Ci sono soluzioni per la sicurezza per ogni layer
>![[Pasted image 20241227163425.png]]

>[!note] 
>La maggior parte dei protocolli origniali non erano sicuri , adesso esistono versioni sicure per ognuno di essi : 
>+ `HTTP` diventa `HTTPS` ( da porta $80$ a $443$ )
>+ `POP3` diventa `POP3S` ( da porta $110$ a $995$ )
>+ `IMAP` diventa `IMAPS` ( da porta $143$ a $993$ )
>+ `UDP` diventa `DTLS` ma non è molto utilizzato

**TLS** fornisce i seguenti servizi ai layer superiori : 
+ *Origin authentication* : Il *server* e *client* possono identificarsi tra loro usando [[X.509]] 
+ *Segretezza* : Dopo l'autenticazione vengono scambiate delle chiavi che verrano usate per cifrare il traffico usando **Symmetric Key Encryption**
+ *Integrità* : Genera una chiave utilizzata per garantire *integrità* usando [[HMAC]] 
### TLS 1.2

![[Pasted image 20241227164538.png]]
#### TLS Handshake Protocol

Questo protocollo è utilizzato per negoziare *chiavi* e parametri di sicurezza 

Quello che vogliamo negoziare : 
+ Che funzioni cryptografiche usare ( [[RSA]] , **Curve Ellittiche** )
+ Che [[Hash Functions]] usare ( **SHA-256** , **SHA-384** )
+ Come negoziare la chiave simmetrica ( [[RSA]] , [[Diffie-Hellman Protocol]] )

>[!important] 
>Questa negoziazione delle chiavi è critica poichè avviene prima di qualsiasi cifratura , è soggetta quindi ad attacchi **MiTM** 

L'*Handshake Protocol* garantisce le seguenti propietà : 
+ L'identità del *peer* può essere verificata utilizzando **Asymmetric** cryptography o [[12 Public Key Encryption]] ( [[RSA]] , **DSA** ) 
>[!important] 
>Questa autenticazione può essere resa opzionale , ma generalmente richiesta per almeno uno dei *peer*
+ La negoziazione di un segreto condiviso tra i due *peer* è sicura ( non può avvenire un attacco **MiTM** )
+ La negoziazione è *reliable* : nessun attacante può modificare la negoziazione senza essere rilevato
---

1. I primi tre messaggi sono la [[18 TCP - UDP#Transmission Control Protocol (TCP)#Connection Setup|3-way handshake TCP]] 
2. 

#### TLS Record Protocol

