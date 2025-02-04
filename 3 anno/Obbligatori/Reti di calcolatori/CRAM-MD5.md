---
creation: 2024-11-11T14:47:00
publish: true
---
**CRAM-MD5** è un protocollo che consente [[Data authentication]] in base alla conoscenza di una *password* e alla conoscenza di un [[Hash Functions|Funzione di Hashing]] 

Assumiamo che **Alice** ( il *client* ) vuole autenticarsi a **Bob** ( il *server* ) , il suo username è "Alice" e possiede la *shared key* $K$ 

**Bob** compone una *challenge* $C$ formata nel seguente modo : `<timestamp@domain>` , per esempio : `C=<1896.697170952@postoffice.reston.mci.net>` 

**Alice** , essendo che conosce $K$ può computare $D=HMAC(C,K)$ e invia a **Bob** il messaggio : $(\text{"Alice"},D)$ 

**Bob** controlla la presenza di `Alice` nel database , prende $K$ e ricomputa $D' = HMAC(C,K)$ se $D' == D$ allora *OK* 

![[Pasted image 20241111151354.png]]

>[!warning] 
>
>E' importante che si utilizzi una *challenge* sempre differente in modo che **Eve** non possa riutilizzare $D$ intercettati precedentemente

>[!fail] 
>Questo protocollo è *deprecato* poichè : 
>1. Utilizza una [[Hash Functions|Funzione di Hashing]] debole ( **MD5** ) 
>	Visto che all'inizio il *client* e *server* devono accordarsi su che [[Hash Functions|Funzione di Hashing]] utilizare e la connessione non può essere sicura **Eve** potrebbe intercettare il messaggio e costringere **Alice** e **Bob** ad utilizzare una [[Hash Functions|Funzione di Hashing]] debole 
>2. L'autenticazione non è mutua
>	**Alice** non sa se il *server* con cui sta parlando è realmente **Bob** , per risolvere il problema potremmo ripetere il processo anche per il *server* , ma non è supportato da **CRAM-MD5**
>3. Può subire *brute force* off-line
>	Possiamo osservare lo scambio di infomazioni tra **Alice** e **Bob** e dato il *digest* possiamo provare tutte le password possibili off-line ( non dobbiamo mai interagire con il *server* )

