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
>[Spamho]()

### RFC Compliance

### Sender Policy Framework