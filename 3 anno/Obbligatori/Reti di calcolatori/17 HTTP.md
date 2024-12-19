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

1. Aggiungendo del codice *server-side* che cambia la pagina a seconda di una query o di azione che l'utente fa , ciò significa che l'`URL` non pnuta ad un file **HTML** ma ad un file con del codice che viene eseuito server-side e che ritorna una pagina **HTML** , Questo pattern è detto **Common Gateway Interface** ( **CGI** )

>[!example] 
>```php
>\<html>
>\<body>
>	\<h1>Example PHP page\</h1>
>	<? php echo " This is the output of PHP code " ; ?>
>\</body>
>\</html>
>```

