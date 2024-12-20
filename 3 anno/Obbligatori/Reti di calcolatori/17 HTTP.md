---
publish: true
creation: 2024-12-19T13:09:00
---
# Introduction

## URI

Un `URI` è una stringa di caratteri che identifica univocamente una risorsa su internet

Uno `URL` è un `URI` che fornisce una posizione da dove recuperare una risorsa 
Uno `URN` invece semplicemente identifica il *nome* della risorsa e non la sua posizione 

>[!example] 
>`URI = scheme ":" "//" authority path [ "?" query ] [ "#" fragment ]`
### Scheme

Lo schema ( `scheme` ) viene utilizzato per indicare il significato dei campi che lo seguono , *generalemente* identifica l'[[Application Layer]] *protocol* che deve essere usato dal *client* per recuperare un documento 

>[!example] 
>Alcuni schemi validi sono : 
>+ `http` / `https`
>+ `ftp`
>+ `mailto`
### Authority

Questo campo include il [[Domain Name]] o l'indirizzo *IP* del server dove è conservato il documento 

L'*authority* può essere preceduto da altre informazioni riguardanti l'utente ( username e password ) che sta richiedendo il documento , generalmente prima del carattere `@` 

Il [[Domain Name]] può essere seguito da un simbolo di `:` e un numero di porta 

>[!note] 
>Il numero della porta dovrebbe essere incluso solamente se lo schema non ne definisce una implicitamente 

### Path

L'ultima parte dell'`URI` contiene il *path* fino al documento , generalmente questo è strutturato come in *Unix*

>[!note] 
>Se il *path* non è specificato il server ritornarà un documento di default `404.html`
### Query and Fragment 

La parte di *query* è usata per dare un parametro al *server* ( usato per fare query etcc )

>[!example] 
`?parameter=value`

La parte di *fragment* viene usata per indicare una specifica parte del documento 

>[!example] 
`#SubsectionTitle`

## HTML ( HyperText Markup Language )

**HTML** è un linguaggio di *Markup* utilizzato per arrichire il testo con vari attirbuti , chiamati *tag* 

Un documento **HTML** è fatto di un *header* e un *body* inclusi nelle rispettive tag , possiamo formattare il documento tramite *tag* 

>[!example] 
>```html
>\<html>
>\<head>
>	....
>\</head>
>
>\<body>
>	....
>	\<img src="deam.jpg">
>	\<a href="www.alink.org">
>\</body>
>
>```

### Dynamic pages

Visto che **HTML** è semplicemente un file se vogliamo che la pagina carichi del contenuto dinamicamente abbiamo due metodi : 

#### Common Gateway Interface ( CGI )

Aggiungendo del codice *server-side* che cambia la pagina a seconda di una query o di azione che l'utente fa , ciò significa che l'`URL` non pnuta ad un file **HTML** ma ad un file con del codice che viene eseuito server-side e che ritorna una pagina **HTML**

Un linguaggio con cui possiamo fare questa cosa è **php**

>[!example] 
>```php
>\<html>
>\<body>
>	\<h1>Example PHP page\</h1>
>	<? php echo " This is the output of PHP code " ; ?>
>\</body>
>\</html>
>```
>
>Se l'utente naviga alla pagina `http://example.com/?name=Hannes`
>
>```php
>\<html>
>	\<body>
>	<? php
>	echo " Hello " . htmlspecialchars($_GET [ "name " ] ) . " ! " ;?> 
>	\</body>
>\</html>
>```
>
>Darà in output : *Hello Hannes*

Generalmente questo è usato quando dobbiamo per esempio fare la query di un database 

L'utente infatti non dovrebbe avere accesso al database in se , solo il server dovrebbe potervi accedere 
#### Client Side Code

Il codice viene *embeddato* all'interno della pagina , quando inviamo una pagina **HTML** con codice embeddato il broswer runna gli script e renderizza la pagina risultante 

Un linguaggio con cui possiamo fare questa cosa è **javascript**

>[!example] 
>```javascript
>\<html>
>	\<body>
>	\<p>Hello World !\</p>
>	\<script>
>		alert( " Hello , world! in JS" );
>	\</script>
>\</body>
>\</html>
>```

Generalmente questo è usato per azioni dinamiche , che potrebbero non richiedere l'utilizzo di una connessione ( ex riordinare una lista etcc )
## CSS ( Cascading Style Sheet )

**CSS** è un'altro standard che viene utilizzato per aggiustare a livello grafico la pagina 

Questo ci permette di rendere indipendenti i dati dallo stile

>[!example] 
>```css
>\<html>
>\<body>
>	\<h1>This is a title\</h1>
>	\<p style=" color:#00FF00 " ;>This is a simple paragraph\</p>
>\</body>
>\</html>
>```

Se volessimo modificare lo stile di tutti i paragrafi assieme sarebbe estremamente tedioso , per questo possiamo linkare un file `.css` dove possiamo fare riferimento ad un *tag* e dare lo stile desiderato per ogni istanza di quel *tag*

>[!example] 
>Pagina **HTML** :
>
>```html
>\<html>
>\<link href="style.css" rel="stylesheet" type="text/css">
>\<body>
>	\<h1>This is a title\</h1>
>	\<p>This is a paragraph\</p>
>\</body>
>\</html>
>```
>
>```css
>h1 {
>	color: black ;
>	font-size : 5em ;
>}
>p {
>	color: green ;
>}
>```

# HyperText Transfer Protocol ( HTTP )

**HTTP** è un protocollo basato sul testo come **SMTP**

Il *client* manda un richiesta e il server ritorna una risposta 

>[!note] 
>**HTTP** runna sopra il protocollo [[TCP]] e ascola sulla porta `80` di default
>

Ogni *richiesta* **HTTP** contiene tre parti :
+ Un *metodo* che indica il tipo della richiesta , un `URI` e la versione del protocollo usato dal *client*
+ Un *header* che è usato dal *client* per specificare parametri opzionali , una linea vuota indica la fine dell'*header*
+ Un documento *MIME* opzionale

Ogni *risposta* contiene tre parti : 
+ Una linea contenente lo stato della richiesta , se è andata a buon fine o no
+ Un *header* contente le informazioni riguardanti la risposta , la risposta finisce con un linea vuota 
+ Un documento *MIME*

## HTTP Methods

+ `GET` : 
	Usato per ricevere un documento dal server. 
	E' seguito dal path dell'`URI` del documento richiesto e la versione di **HTTP** usata
+ `HEAD` : 
	Permette di ricevere le linee *header* di un dato `URI`senza dover ricavare l'intero documento , può essere usato da un client per verificare l'esistenza di un dato documento 
+ `POST` :
	Usato da un *client* per inviare un documento ad un server , aggiunto alla richiesta **HTTP** come documento *MIME*

>[!example] 
>`GET` 
>
>Per ricevere il documento `http://www.w3.org/MarkUp/` , dobbiamo :
>1. Aprire una connessione `TCP` su porta `80` con l'host `www.w3.org`
>2. Invia una richiesta **HTTP** : `GET /MarkUp/ HTTP/1.0`

## HTTP headers

Gli *header* `MIME` sono parzialmente simili a `SMTP` , per esempio per esprimere l'encoding 

Altri *header* sono : 
+ `User-Agent` :
	Informazioni riguardanti software che runna sul *client* , usato per dare una versione differente per ogni device
+ `Referrer` : 
	Il precedente sito visitato dal broswer del client , in modo da capire da dove arriva il nostro traffico 
+ `Host` :
	Il dominio che l'host richiede , nel caso in cui sul server abbiamo più di un dominio con lo stesso server path
+ `Server` :
	Informazioni sul software che sta runnando sul server 

## HTTP Status Code

