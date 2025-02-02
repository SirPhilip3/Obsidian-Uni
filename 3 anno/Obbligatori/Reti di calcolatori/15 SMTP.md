---
publish: true
creation: 2024-12-18T11:13:00
---
# e-mail

## Architecture

>[!example] 
>
![[Pasted image 20241218112905.png]]
>
>1. L'e-mail *client* di *alice* formatta correttamente il messaggio
>2. L'e-mail *server* di *alice* a cui il client invia la mail 
>3. L'e-mail server di *bob* che riceve la mail dal server di *alice*
>4. Il client e-mail di *bob* che riceve la mail dal suo server

## e-mail protocols

### Internet Message Format

Le *e-mail* sono messaggi testuali , inizialmente in ASCII , in cui ogni riga termina con il carattere `CRLF`
#### Headers

Le *e-mail* hanno delle righe iniziali contenenti degli *headers* ( ex : `From, To, Date, CC, BCC, Subject` etc )

>[!example] 
>```
>From:  Bob Smith <bob@machine.example>
>To : Alice Doe <alice@example.net>, Alice Smith <alice@machine.example>
>Subject : Hello
>Date : Mon , 8 Mar 2010 19:55:06 -0600
>This is the " Hello world " of email messages .
>This is the second line of the body
>```


Ulteriori *header* 
+ `Message-Id` : Un *ID* unico usato da altre email che referenziano questo messaggio
+ `In-reply-to` : Contiene il `Message-Id` del messaggio a cui sta rispondendo
+ `Received` : Ogni server che riceve il messaggio aggiunge una riga *received*
+ `X-` : Il client o server può aggiungere campi custom che iniziano con `X-`

>[!example] 
>![[Pasted image 20241218115634.png]]
#### Message Body

Il **message body** più semplice può essere del testo `ASCII` , ma può anche essere un qualsiasi file binario e allegati

Per questo viene usato il **Multipurpose Internet Mail Extensions** ( **MIME** ) 
##### MIME

Campi `MIME` :
+ `MIME-Version` : la versione del protocollo 
+ `Content-Type` :
	+ `text/plain` : semplici messaggi di testo
	+ `multipart/mixed` : messaggi di testo più altri contenuti non testuali
	+ `multipart/alternative` : messaggi in testo e in qualche altro formato
	+ `image, audio, video, ...` : formati binari 
>[!note] 
>Per `multipart` si aggiunge anche un *header* per definire il confine tra le varie parti
+ `Content-Transfer-Encoding` : la codifica dei dati ( ex ASCII , UTF-8, Base64 etc )

>[!note] 
>`multipart` può avere una struttura ad albero 

>[!example] 
>![[Pasted image 20241218120528.png]]

>[!note] 
>
>Generalmente la *boundary* è un valore randomico

## Simple Mail Transfer Protocol ( SMTP )

>[!note] 
>Il *formato* dell'email è rilevante principalmente per gli end-point dell'email , detti *Mail User Agent* ( **MUA** )

Gli **MTA** ( *Mail Transfer Agent* ) invece sono i server che si prendono cura della consegna dell'email 

Per la comunicazione tra **MTA** e **MUA** si utilizzano due protocolli **SMTP** e **POP/IMAP**

>[!example] 
![[Pasted image 20241218122142.png]]

**SMTP** è un protocollo *text-based* , questo fa affidamento su un servizio *connection oriented* ( [[TCP]] ) , il *server* ascolta sulla porta `25` dove il client invia comandi testuali in ASCII terminati da `CRLF` , il *server* risponde con un numero di tre cifre che indica se è avvenuto un *errore* o l'operazione ha avuto *successo* ( in aggiunta vi possono essere dei commenti )
### Comandi

I comandi più usati sono : 
+ `EHLO` : Il *client* saluta il *server*
+ `MAIL FROM` : Il sender
+ `RCPT TO` : Il ricevitore
+ `DATA` : Inizio del messaggio 
+ `QUIT` : Terminazione del messaggio

### Reply Codes

+ `2XX` : esito *positivo* 
	+ `220` : Il servizio è pronto , usato quando la connessione viene aperta
	+ `250` : Requested mail action , completed
+ `3XX` : esito *positivo* ma necessita più input
+ `4XX` : esito *negativo* ma il problema è temporaneo , puoi riprovare con lo stesso comando più avanti
	+ `450` : Requested mail action not taken ( mailbox occupata o bloccata per qualche *policy* )
+ `5XX` : esito *negativo* , il problema è permanente , non riprovare
	+ `550` : Requested action not taken ( mailbox non trovata , non ha accesso o comando rifiutato per motivi di *policy* )

>[!example] 
>![[Pasted image 20241218124026.png]]

### SMTP Operations

>[!note] 
>Queste non sono regola ma configurazioni comunemente usate

Il **MUA** viene configurato con il nome di *dominio* di un *server* **SMTP** , si connetterà a questo e svolgerà una certa *autenticazione* con l'**SMTP**

>[!warning] 
>Inizialmente non c'era autenticazione per **SMTP** 

>[!note] 
>Se il *client* può mandare *email* a qualsiasi dominio allora diciamo che il server **SMTP** permette il **relaying** di *email* verso altri domini 

Una volta che il server **SMTP** riceve la mail dal **MUA** deve inviarla la server **SMTP** di destinazione 

>[!warning] 
>Inizialmente non conosce l'indirizzo *IP* del server **SMTP** che gestisce la posta per il *destinatario*

Fa quindi una richiesta al **DNS** usando come `TYPE` `MX` in modo da ricevere una risposta *non-terminale* con più di una opzione classificate secondo uno score ( lower = better , usato per fare *load balancing* ) 

Ciò che ritornerà sarà un nome di *dominio* per cui fare un altra query **DNS** per risolvere il suo indirizzo *IP*

Ottenuto l'*IP* l'**SMTP** si connette all'**SMTP** di destinazione , l'**MTA** però non fa autheticazione e quindi non permetterà **relaying** , solo *email* destinate allo stesso *dominio* saranno accettate
#### SMTP Authentication

Al primo `EHLO` da parte del *client* il *server* risponde con diversi `250-` con in aggiunta , come commento, i metodi di autenticazione che il server supporta :

>[!example] 
![[Pasted image 20241218130336.png]]

Il *client* sucessivamente ne sceglie una con cui autheticarsi

>[!note] 
>Quando ci connettiamo ad un **MTA** o **MUA** facciamo sempre la stessa azione , inviare una *mail* 
>
>Quando l'**MUA** si connette ad un **MTA** con cui condivide delle credenziali valide , l'**MUA** farà un'autenticazione e l'**MTA** gli permetterà di fare **relaying**
>>[!warning] 
>>Se non facciamo l'autenticazione l'**MTA** permetterà di inviare email solo all'interno del proprio dominio

Per rendere questo processo esplicito è stato aggiunto un ulteriore componente : **Mail Submission Agent** ( **MSA** ) ossia un **MTA** che svolge l'autenticazione

>[!example] 
>![[Pasted image 20241218133150.png]]

>[!note] 
>In `RFC 5068` viene specificato che l'**MSA** deve supportare la porta di `SUBMISSION` `587` 
>
>L'**MSA** deve fare *autenticazione* ( verificare i suoi permessi con l'opertore dell **MSA** ) anche per quelle comunicazioni tra indirizzi email che appartengono allo stesso *dominio*
>
>Per un periodo di tempo dopo l'invio della mail l'**MSA** deve essere in grado identificare l'utente autenticato che ha inviato la mail

## POP / IMAP

Quando la mail viene ricevuta dal server **SMTP** del destinatario viene salvata dentro una mailbox da dove può essere recuperata tramite un protocollo come **POP** o **IMAP** ( **Mail Delivery Agent** ( **MTA** ) )

### POP3

Quando una mail arriva all'ultimo **MTA** viene invata ad un **MDA** , questo la rende disponibile all'**MUA** del destinatario attraverso un protocollo come **POP3** ( Sostituito da **IMAP** )

Questo è un protocollo testuale con comandi come : 
+ `USER` : seguito dal nome utente
+ `PASS` : seguito dalla password
+ `STAT` : chiede lo stato della mailbox
+ `LIST` : dai una lista di nuovi messaggi 
+ `RETR` : seguito da un numero ritorna l'$n$-esimo messaggio

Le risposte possono essere `+OK` seguito dalla risposta o codici di errore simili a **SMTP**

>[!example] 
>![[Pasted image 20241218134320.png]]

>[!warning] 
>Originariamente **POP** consentiva di fare autenticazione senza encryption , per questo è stato esteso per supportare ex [[CRAM-MD5]] 

