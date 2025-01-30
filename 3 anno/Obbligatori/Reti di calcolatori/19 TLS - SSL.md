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

A seconda del layer dello stack [[TCP IP]] in cui vogliamo inserire la sicurezza abbiamo dei *pro* e dei *contro* : 
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
>La maggior parte dei protocolli originali non erano sicuri , adesso esistono versioni sicure per ognuno di essi : 
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

![[Pasted image 20241227171800.png]]


1. I primi tre messaggi sono la [[18 TCP - UDP#Transmission Control Protocol (TCP)#Connection Setup|3-way handshake TCP]] 
2. Il clienti invia un `ClientHello` 
>[!note] 
>Questo contine l'[[Acknowledgment|ack]] per la [[18 TCP - UDP#Transmission Control Protocol (TCP)#Connection Setup|3-way handshake TCP]] , inoltre segnale all'host che supporta **TLS**
3. Il server invia : 
	1. un `ServerHello` 
	2. un `Certificate` ( e la catena di [[Certificate]] dalla rotto [[Certification Authority|CA]] al [[Certificate]] del *server* ) del *server*
	3. un messaggio di `ServerHelloDone` indicato che ha finito il suo `Hello`
4. Il *client* invia :
	1. un `ClientKeyExchange` , in cui il client scambia la chiave con il *server* ( il client ha già una connessione privata con il server ) 
	2. un `ChangeCipherSpec` : indica che il prossimo messaggio che verrà scambiato sarà cifrato
	3. Come ultimo messaggio il *client* invia `Finished` , questo sarà il primo messaggio cifrato , questo contiene una *hash* di tutti i precedenti messaggi , questo serve per verificare che i messaggi precedenti non siano stati modificati da attacchi **MiTM**

>[!note] 
>Per 3 **RTT** non riceviamo byte usabili dall'applicazione 

>[!note] One way Authentication 
>Solo il *server* deve autenticarsi con l'utente , l'utente non ha bisogno di un valido certificato 
#### TLS Record Protocol

Lo stream di dati deve essere diviso per farmo stare in un **MTU** 

![[Pasted image 20241227222649.png]]

Fornisce due propietà : 
+ *La connessione è privata* : I dati vengono cifrati con **Symmetric Encryption** ( **AES** ) , queste sono generate dal [[19 TLS - SSL#TLS Handshake Protocol|TLS Handshake Protocol]] 
+ *La connessione è reliable* : La reliability viene data dal **MAC** aggiunto ( **SHA-256** )
#### mTLS ( mutual Authentication )

Ci fidiamo di un servizio solo se *entrabi* hanno un [[Certificate]] valido 
### TLS 1.3

**TLS 1.2** aveva una superfice di attacco troppo estesa , per questo è stato riscritto completamente eliminando molta superfice di attacco 

+ Supporta solo $5$ algoritmi di cifratura e autenticazione con un solo schema di blocco ( **AEAD** )
+ L'*handshake* iniziale può essere lunga un **RTT** 
+ La sessione può essere ripresa con $0$ **RTT**
+ Implementa **Forward Secrecy**
#### Forward Secrecy 

Fa in modo che le *chiavi di sessione* non vengano compromesse anche se le *chiavi private* del server sono compromesse 

>[!example] 
>*Eve* intercetta una comunicazione **TLS** tra *Alice e Bob* e salva il suo contenuto anche se non può ancora decifrarlo 
>*Eve* riesce a rubare la chiave privata di *Bob*
>
>Ora anche se *Eve* è in possesso della chiave privata la **Forward Secrecy** ci garantisce che non possa decifrarne il contenuto 

Questo viene implementato usando [[Public Key]] *effimere* , ossia che vengono generate durante l'*handshake* e eliminate subito dopo essere usate 
##### Example Protocol
1. Il *server* invia il suo [[Certificate]] 
2. Il *client* lo verfica
3. Il *client* inizia una sessione [[Diffie-Hellman Protocol]] con una chiave *effimera* randomica
4. Il *server* completa la sessione [[Diffie-Hellman Protocol|Diffie-Hellman]] con qualche altra chiave *effimera* randomica
5. Sia il *client* che il *server* hanno ora una chiave $K$ 
6. Da ora in poi il *client* e *server* usano **AES** e [[HMAC]] con chiave $K$ 
7. Sia il *server* che il *client* eliminano le chiavi effimere
8. Ora il *client* usa una passaword per autenticarsi 
