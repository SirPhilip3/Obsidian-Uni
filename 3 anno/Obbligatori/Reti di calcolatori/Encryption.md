---
creation: 2024-11-11T09:16:00
---
# Foundations 

**Cryptography** garantisce i seguenti servizi : 
+ [[Data integrity]] ( tramite *funzioni hash* )
+ [[Secrecy]] ( tramite *endcryption* )
+ [[Non repudiation]] ( tramite *firme digitali* )
+ Tramite la composizione di diverse funzioni criptografiche possiamo anche ottenere : 
	+ Autenticazione del peer e dell'origine
	+ Controllo degli accessi
	+ Anonimato

![[Cryptographic Algorithm]]

![[Cryptographic function]]

>[!important] Golden Rules
>
>+ Non usare mai [[Cryptographic Algorithm]] non conosciuti
>+ Non usare [[Cryptographic Algorithm]] closed source
>+ Utilizza le funzioni più popolari e mantenute 
>+ Utilizza protocolli standard 
>+ Consenti di utilizzare il servizio solo se supportano l'ultima versione del protocollo

# Hash Functions

![[Hash Functions]]

## HMAC

>[!danger] Limitazioni
>
>![[Pasted image 20241111124718.png]]
>
>In questo caso **Eve** può intercettare il messaggio con `plaintext|digest` , creare un nuovo messaggio $M'$ , coputarne l'hash $D'$ ed inviare quel messaggio a **Bob** che , visto che $H(M') = D'$ accetterà il messaggio
>
>**Eve** ha rotto [[Data integrity]]

![[HMAC]]

## CRAM-MD5

![[CRAM-MD5]]

# Encryption in Transit

![[Pasted image 20241111091838.png]]

In questo caso il messaggio viene *decriptato* quando raggiunge i server di colui che fornisce il servizio , lo salva e sucessivamente lo encripta di nuove e lo mada a *Bob*

In questo caso **Alice** , che può leggere i canali di comunicazione tra gli utenti e il server , non può fare nulla con il messaggio 

Un threat actor che controlla però i server ( che può essere il service provider stesso ) ha il completo accesso ai dati non criptati 
# E2E Encryption

![[Pasted image 20241111092500.png]]

Solo **Alice** e **Bob** conoscono la chiave di cifratura del messaggio , quindi anche il service provider stesso non ha accesso ai messaggi in chiaro 

>[!note] 
>
>**E2E** ha dei tradeoff : 
>+ Puoi utilizzare solo un dispositivo alla volta ( questo perchè la key è mantenuta nel device ) 
>+ Visto che il server non mantiene i messaggi in chiaro non può fornire servizi ai vari client , tutto deve essere fatto on device
