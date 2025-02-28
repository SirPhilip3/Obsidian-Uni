---
creation: 2024-11-11T09:16:00
publish: true
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

# Base Encryption Operations

**Encryption** si basa su due principali operazioni : 
+ ![[Sostituzione]]
+ ![[Trasposizione]] 
>[!important] 
>
>Un *cifraio* funziona solo se non c'è nessuna correlazione statistica tra $C$ e $M$ 
>
>La [[Trasposizione]] e [[Sostituzione]] hanno abbastanza correlazione per poter rompere il *cifraio* 
# Perfect Cipher

![[One-Time-Pad]]

# Modern Algorithms

Algoritmi moderni cercano di mixare le due funzioni primitive di [[Trasposizione]] e [[Sostituzione]] in modo da arrivare ad un algoritmo con le seguenti propietà : 
+ La lunghezza delle chiave è fissa e non deve essere lunga come il `plaintext`
+ La correlazione tra $M$ e $C$ è così poca che è [[Computationally Impossible]] recuperare $M$ da $C$ 

Algoritmi moderni applicano multiple iterazione di [[Trasposizione]] e [[Sostituzione]] in modo che , ad ogni iterazione venga tolta in pò di correlazione 

![[Feistel Scheme]]
# Symmetric Key Encryption

Un esempio di funzione di *encryption* che funziona a chiave simmetrica è **AES**

Quando **Alice** vuole mandare un messaggio a **Bob** usa **AES** per cifrare un messaggio $M$ , il messaggio diventerà quindi : $C=AES(K,M)$  , quando **Bob** riceve il messaggio esso , avendo la chiave $K$ , può ritornare al messaggio originale nel seguente modo : $M=AES(K,C)$  

## [[Data integrity|Integrity]] , [[Secrecy]] and [[Data authentication|Authentication]]

Una volta che **Alice** e **Bob** si sono messi daccordo su una *chiave* condivisa $K$ possono usare la stessa $K$ sia per [[HMAC]] che per [[11 Encryption]]  

![[Pasted image 20241112105215.png]]

**Step-by-step** : 
**Alice**
1. **Alice** usa una schema a *chiave simmetrica* ( **AES** in questo caso ) per trasformare un `plaintext` in `ciphertext` , la chiave deve essere condivisa anche con **Bob**
2. Il `ciphertext` viene passato attraverso una [[HMAC]] che usa la *chiave condivisa* , il risultato è il `digest` del `ciphertext`
3. `digest` e `ciphertext` vengono inviate a **Bob**

**Bob**
4. **Bob** usa il `ciphertext` , assieme alla *chiave condivisa* per produrre attraverso [[HMAC]] un candidato `digest` 
5. Se il candidato `digest` corrisponde con il `digest` arrivato assieme al `ciphertext` allora significa che il `plaintext` non è stato manipulato in transito
6. **Bob** utilizza **AES** per ritornare al `plaintext` grazie alla *chiave condivisa* 

>[!note] 
>Visto che nessuno tranne **Bob** e **Alice** conosce la *chiave condivisa* siamo sicuri che la connessione è *segreta*

### Limitations

Assumiamo che [[HMAC]] e [[11 Encryption]] siano robuste
Assumiamo inoltre che **Alice** e **Bob** possano condividere la *chiave condivisa* tra di loro

>[!note] 
>Realmente vengono utilizzate due chiavi differenti , una per [[11 Encryption]] e una per [[HMAC]] 

>[!warning] 
>E' possibile fare ancora *Off-line brute force* 
# Encryption in Transit

![[Pasted image 20241111091838.png]]

In questo caso il messaggio viene *decriptato* quando raggiunge i server di colui che fornisce il servizio , lo salva e sucessivamente lo cifra di nuovo e lo mada a *Bob*

In questo caso **Eve** , che può leggere i canali di comunicazione tra gli utenti e il server , non può fare nulla con il messaggio 

Un threat actor che controlla però i server ( che può essere il service provider stesso ) ha il completo accesso ai dati non criptati 
# E2E Encryption

![[Pasted image 20241111092500.png]]

Solo **Alice** e **Bob** conoscono la chiave di cifratura del messaggio , quindi anche il service provider stesso non ha accesso ai messaggi in chiaro 

>[!note] 
>
>**E2E** ha dei tradeoff : 
>+ Puoi utilizzare solo un dispositivo alla volta ( questo perchè la key è mantenuta nel device ) 
>+ Visto che il server non mantiene i messaggi in chiaro non può fornire servizi ai vari client , tutto deve essere fatto on device
