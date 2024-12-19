---
publish: true
creation: 2024-12-19T08:21:00
---
# SPAM 

Generalmente uno spammer controlla un numero di computer zombie che si connettono ad un certo **SMTP** e provano a inviare email in massa 

>[!note] Hypotesis 1
>Se lo spammer è un **MUA** è facile da individuare dal suo stesso **MSA** visto che si autenticherà e comincerà a mandare email in massa

>[!note] Hypotesis 2 
>Se lo spammer invece finge di essere un **MTA** , per l'**MTA** che riceve le mail è più difficile distinguere tra traffico buono e traffico cattivo visto che un **MTA** generalmente ricevono migliaia di email da altri **MTA**

## Network Based solutions

### Closing Relays

Non permettere il **relaying** se un **MUA** non è autenticato , ossia viene fatta la distinzione tra **MTA** e **MSA** 

>[!warning] 
>Il campo `From` può essere *soofato* mettendoci un qualunque indirizzo sorgente se l'utente non è autenticato
### FQDN ( Fully Qualified Domain Name ) check

Si richiede che il comando `HELO`cosa ca porti con se anche un [[Domain Name]] se il *client* ne possiede uno ( è un **MTA** ) o un letterale di indirizzo altrimenti ( ex `123.255.37.2` ) ( è un **MUA** )

>[!note] 
>Se riceve un [[Domain Name]] lo risolve in un *IP* 

Gli **MTA** possono :
1. Controllare che il [[Domain Name]] usato nell'`HELO` risolva in un qualche indirizzo *IP* esistente
2. Controllare che l'*IP* corrisponda alla connessione con il server 
3. Faranno una *Reverse DNS* query per controllare che questo corrisponda al [[Domain Name]] dato 

Se una delle condizioni precedenti non viene soddisfatta l'**MTA** potrebbe rifiutare la connessione

>[!note] 
>Per operare un **MTA** necessitiamo un *IP* pubblico , un dominio e un record `PRT` 
>Inoltre dobbiamo rendere l'**MTA** identificabile in modo da controllarne la sua reputazione
>
>Tutto questo richiede allo *spammer* di almeno possedere un dominio
### IP balcklisting

Esistono varie organizzazioni che mantengono una lista di indirizzi *IP* che generano email spam , gli **MTA** controlleranno quindi che l'*IP* di provenienza della mail non sia dentro una di queste liste
#### DNSBL ( DNS Block List )

Prima di consentire l'invio di e-mail l'**MTA** farà una query al server **DNSBL** per testare se l'*IP* è presente nei loro database , se presente non consente l'invio di email 

>[!example] 
>[Spamhaus](https://www.spamhaus.org/)

>[!warning] 
>Il processo per entrare ed uscire da una *blocklist* non è trasparente , inoltre degli spammer possono affittare momentaneamente grandi range di *IP* per poi , quando sono entrati nella *blocklist* , cambiarli 

>[!example] 
>Se la query **DNS** non ritorna un valido record `A` allora l'*IP* non è all'interno della *blocklist*
>```bash
>$ dig 2.0.0.127.zen.spamhaus.org
>;; ANSWER SECTION :
>2.0.0.127. zen . spamhaus . org . 60 IN A 127.0.0.4
>2.0.0.127. zen . spamhaus . org . 60 IN A 127.0.0.2
>2.0.0.127. zen . spamhaus . org . 60 IN A 127.0.0.10
>```
>
>In questo caso `127.0.0.4` , `127.0.0.2` , `127.0.0.10` sono nella lista
>
>Se si vuole sapere il perchè bisogna fare una query `TXT`
>```bash
>dig 2.0.0.127.zen.spamhaus.org TXT
>;; ANSWER SECTION :
>2.0.0.127.zen.spamhaus.org. 60 IN TXT " Listed by XBL , see https://check.spamhaus.org/query/ip/127.0.0.2 "
>2.0.0.127.zen.spamhaus.org. 60 IN TXT " Listed by SBL , see https://check.spamhaus.org/sbl/query/SBL2 "
>2.0.0.127.zen.spamhaus.org. 60 IN TXT " Listed by PBL , see https://check.spamhaus.org/query/ip/127.0.0.2 "
>```
### RFC Compliance

Un server **SMTP** non spam aderisce completamente allo standard `SMTP` , invece uno controllato da uno spammer tende a non aderire alle parti che potrebbero rallentarlo

>[!example] 
>Se un **MTA** ricevente delle email può *ritardare* la risposta o ritornare un errore temporaneo , i server **SMTP** controllati dagli spammer non aspetteranno la risposta , dropperanno la connessione e andranno avanti con il prossimo server **SMTP** target
>
>>[!warning] 
>>Questo però rallenta anche il traffico legittimo

#### Graylisting

Possiamo sfruttare il fatto che un **MTA** controllato da uno spammer non riproverà se riceve un errore `4XX` 

Quindi un **MTA** che usa **graylisting** mantiene una lista di indirizzi *IP* conosciuti che possono mandare mail ( *whitelist* )

>[!example] 
>Quando una connessione è ricevuta da un *client* **MTA** che non è dentro la lista , il server **MTA** risponde con un errore `4XX` e aggiunge l'*IP* alla *whitelist*
>
>Un **MTA** non spammer riproverà dopo del tempo e essendo l'*IP* nella *whitelist* l'email verrà inviata ( il delay dipende da come è impostato il server **SMTP** )
>
>>[!note] 
>>Per *RFC* il server dovrà accettare la seconda connessione se arriva tra 1 minuto e 24 ore dopo , inoltre dopo un certo perio di inattività *IP* viene rimosso dalla *whitelist*
>
>Un **MTA** *spammer* invece non riproverà
>>[!warning] 
>>Anche in questo caso si introduce un delay nell'invio della email

>[!warning] 
>Questo è efficente per **MTA** molto utilizzati che quindi rimaranno sempre in whitelist ( ex google ) , mentre **MTA** poco utilizzati avranno molto facilmente la loro prima email ritaradata
### Sender Policy Framework

Alcune definizioni :
+ `HELO` : Identifica il [[Domain Name]] dell'**MTA** ( il server `SMTP` ) che rappresenta il *client*
+ `MAIL FROM` : 
>[!warning] 
>Questo non necessariamente rappresenta il *sender* dell'email , rappresenta invece l'indirizzo email a cui inviare gli *errori* , questo può essere diverso dal *sender* vero e proprio
+ `From` : Questo è quello che il *reciever* vede come il *sender* della mail , questo viene usato come *reciever* se usiamo `Reply-to`
#### Sender Spoofing

