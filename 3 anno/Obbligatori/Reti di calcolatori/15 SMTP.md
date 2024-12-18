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

Le *e-mail* sono messaggi testuali , inizialmente in ASCII , 
#### Headers

Le *e-mail* ha delle righe iniziali contenenti gli *headers* ( ex : `From, To, Date, CC, BCC, Subject` etcc )

>[!example] 
>```
>From:  Bob Smith <bob@machine.example>
>To : Alice Doe <alice@example.net>, Alice Smith <alice@machine.example>
>Subject : Hello
>Date : Mon , 8 Mar 2010 19:55:06 -0600
>his is the " Hello world " of email messages .
>This is the second line of the body
>```


Ulteriori *header* 
+ `Message-Id` : Un *ID* unico usato da altre email che referenziano questo messaggio
+ `In-reply-to` : Contiene il `Message-Id` del messaggio a cui sta rispondendo
+ `Received` : Ogni server che riceve il messaggio aggiunge una riga *recieved*
+ `X-` : Il client o server può aggiungere campi custom che iniziano con `X-`

>[!example] 
>![[Pasted image 20241218115634.png]]
#### Message Body

Il **message body** più semplice può essere del testo `ASCII` , ma può anche essere un qualsiasi file binario e allegati

Per questo viene usato il **Multiporpouse Internet Mail Extensions** ( **MIME** ) 

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
+ `Content-Transfer-Encoding` : la codifica dei dati ( ex ASCII , UTF-8, Base64 etcc )

>[!note] 
>`multipart` può avere una struttura ad albero 

>[!example] 
>![[Pasted image 20241218120528.png]]

>[!note] 
>
>Generalmente la *boundary* è un valore randomico

## Simple Mail Transfer Protocol
