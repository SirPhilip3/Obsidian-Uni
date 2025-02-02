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
>Se il *path* non è specificato il server ritornerà un documento di default `404.html`
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

Aggiungendo del codice *server-side* che cambia la pagina a seconda di una query o di azione che l'utente fa , ciò significa che l'`URL` non punta ad un file **HTML** ma ad un file con del codice che viene eseguito server-side e che ritorna una pagina **HTML**

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
	Permette di ricevere le linee *header* di un dato `URI` senza dover ricavare l'intero documento , può essere usato da un client per verificare l'esistenza di un dato documento 
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

La linea che indica lo stato della risposta include la versione di **HTTP** seguita da un codice di tre cifre e ulteriori informazioni 
+ `2XX` : Risposta valida 
+ `3XX` : Il documento richiesto non è disponibile sul server
+ `4XX` : Il server ha rilevato un errore nella richiesta **HTTP** fatta dal client
	+ `400 Bad Request` : Errore di sintassi nella richiesta **HTTP**
	+ `404 Not Found` : Indica la il documento richiesto non esiste  
+ `5XX` : Errore da parte del server 

>[!example]
>Request 
>```bash
>GET / HTTP/1.0
>User−Agent : curl/7.19.4 ( universal-apple-darwin10.0 ) libcurl/7.19.4 OpenSSL/0.9.8l zlib/1.2.3
>Host : www.ietf.org
>```
>Response
>```bash
>HTTP/1.1 200 OK
>Date : Mon, 15 Mar 2010 13:40:38 GMT
>Server : Apache/2.2.4 ( Linux/SUSE ) mod\_ssl/2.2.4 OpenSSL/0.9.8e ( truncated )
>Last-Modified : Tue, 09 Mar 2010 21:26:53 GMT
>Content−Length : 17019
>Content−Type : text/html
><!DOCTYPE HTML PUBLIC . . . /HTML>
>```
## Persistent Connection

Inizialmente una connessione `TCP` era disponibile per una sola richiesta `HTTP` , ora una pagina `HTTP` è formati da centinaia di parti e ognuna richiederebbe una connessione **TCP** 

E' stato aggiunto l'header `Connection: Keep Alive` per fare in modo che si possano fare più richieste per la stessa connesione , quando il *client* invia questo header il *server* risponde con lo stesso *header* specificando il numero di richieste che vuole fare

>[!example] 
>
>Request
>
>```bash
>GET / HTTP/1.1
>Host: www.kame.net
>User−Agent : Mozilla/5.0 ( Macintosh; U; Intel Mac OS X; en-us )
>Connection: Keep-Alive
>```
>
>Response
>```bash
>HTTP/1.1 200 OK
>Date : Fri , 19 Mar 2010 09:23:37 GMT
>Server : Apache/2.0.63 ( FreeBSD ) PHP/5.2.12 with Suhosin−Patch
>Keep−Alive : timeout=15, max=100
>Connection : Keep−Alive
>Content−Length : 3462
Content−Type : text/html
>\<html> . . .
>\</html>
>```
## Stateless Operation

>[!note] 
Ogni richiesta `HTTP` è scorrelata da quelle che ne venivano prima 

Il protocollo `HTTP` non mantiene uno stato 

>[!warning] 
>Questo non significa che il *backend* non mantega uno stato 
## HTTP Cookies

Un *cookie* è un'informazione generata dal *server* ed inviata al *client* , il *client* ritornerà il *cookie* ad ogni richiesta in modo da far vedere che è lo stesso che lo ha ricevuto inizialmente 

`HTTP` fornisce due *header* `Set-Cookie` e `Cookie` per spostare i *cookies* dal *client* al *server* 

I *cookie* possono essere distinti per il modo in cui vengono usati :
+ *Session Managment* : Usato per il log-in degli utenti
+ *Personalization* : Per settare la lingua , la locazione geografica etcc...
+ *Tracking* : Per profilare l'attività di un utente

>[!warning] Attacchi
>
>Se un attaccante ha accesso al *cookie* di sessione questo può essere usato per impersonare la vittima 
## Performance

Visto che le richieste sono iterative il caricamento di una pagina , a seconda del **Round-Trip-Time** della connessione , potrebbe richiedere diversi secondi 

Inoltre visto che le pagine sono dinamiche , il tempo di elaborazione per la creazione del file *html* introduce un'altro delay , questo problema viene risolto con l'utilizzo di server **proxy** 
### Proxy

Un server *proxy* è una cache che salva pagine per un certo periodo di tempo , generalmente queste risiedono all'interno del network dell'utente

Il broswer non si connetterà direttamente al server `HTTP` di destinazione ma passa prima per la *proxy* che poi si connetterà al server `HTTP` originale e salverà la pagina 

La prossima volta che il *client* visita quel deteminato sito la *proxy* semplicemente ritornerà il sito cachato 

>[!example] 
>![[Pasted image 20241220095737.png]]

>[!warning] 
>Una *proxy* è vulnerabile ad attacchi *MiMT* 

Per sapere se la *proxy* necessita di richiedere la pagina dal server originale `HTTP` fornisce degli *header* che vengono usati per capire se la pagina è cambiata : 
+ `Cache-Control` : 
	Usato dal server per notificare se la pagina :
	+ `no-store` : non può essere mantenuta in cache
	+ `max-age=10` : può essere mantenuta in cache per un numero massimo di secondi 
	+ `no-cache` : può essere cachata ma le richieste sucessive devono chiedere al server se la pagina è cambiata
+ `If-Modified-Since` :
	Se il *client* richiede la pagina con questo *header* , viene ritornata solo se la pagina è stata modificata da un certo tempo , altrimenti non viene ritornato nulla dal *server* e viene utilizzata la cache

#### Reverse Proxies

Una *reverse proxy* è una *proxy* che al posto di essere nella stessa rete del *client* è nella stessa rete del *server* 

Questa nasconde il server reale , il *client* manderà le richieste alla *proxy* come se fosse il server reale , la *proxy* inoltrerà poi le richieste ai server , questo è utilizzato per fare load balancing nei server che *hostano* la pagina

### HTTP 2.0

`HTTP 2.0` è stato creato per velocizzare `HTTP` 

Questo non è più un protocollo di testo , le richieste vengono codificate in formato binario 

Il contenuto di una pagina è diviso in *frame* , questi possono essere inviati in parallelo al *client* , in questo modo il *server* può inviare prima oggetti di piccole dimensioni e sucessivamente quelli più grandi , questo fa si che il caricamento delle pagine diventi più veloce

`HTTP 2.0` inoltre può *pushare* contenuti al *client* anche se non sono richiesti , questo fa risparmiare tempo quando il *server* sà di che risorsa il *client* ha bisogno prima che il *client* la richieda 
#### HoL Blocking

*Head-of-line* blocking è un termine generico utilizzato per indicare quando un grande *job* rallenta i *job* più piccoli 

Nel caso di *HTTP* , il broswer renderizza la pagina in ordine degli elementi che vengono scaricati , quindi se il primo contenuto richiesto è una grande immagine questa blocca il caricamento di altri elementi che potrebbero caricarsi prima 

In `HTTP 2.0` è il *server* a dare una priorità agli elementi che il *client* richiede ( normalmente viene data una priorità alta a elementi testuali piccoli )

