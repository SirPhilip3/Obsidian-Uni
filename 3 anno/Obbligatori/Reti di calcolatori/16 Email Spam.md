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
### Sender Policy Framework ( SPF )

Alcune definizioni :
+ `HELO` : Identifica il [[Domain Name]] dell'**MTA** ( il server `SMTP` ) che rappresenta il *client*
+ `MAIL FROM` : 
>[!warning] 
>Questo non necessariamente rappresenta il *sender* dell'email , rappresenta invece l'indirizzo email a cui inviare gli *errori* , questo può essere diverso dal *sender* vero e proprio
+ `From` : Questo è quello che il *reciever* vede come il *sender* della mail , questo viene usato come *reciever* se usiamo `Reply-to`
#### Sender Spoofing

Visto che nella connessione il *client* può usare diversi *domini* per `HELO` , `MAIL FROM` e `From` 

Un *client* **SMTP** può quindi mandare e-mail usando `From` con domini differenti

>[!example] 
>Quando un dominio viene registrato il *Registrar* fornisce vari indirizzi email con cui mandare email , queste saranno inviate dall'**MTA** del provider con il nosto campo `From` che sarà diverso dal dominio dell'`HELO`

>[!important] 
Per questo un reciever **MTA** non può rifiutare email perchè il `From` non corrisponde con il dominio presente nell'`HELO`

>[!warning] 
>Questo viene usato da spammers per fingersi un dominio noto alla vittima , normalmente infatti il `Reply-to` non sarà vero l'indirizzo presente nel `From`

#### Protecting `HELO` and `MAIL FROM`

**SPF** fa in modo che uno spammer non possa usare `HELO` o `MAIL FROM` usando un dominio che non possiede 

Viene aggiunta una entry `SPF` nel record **DNS** di un'organizzazione che specifica gli indirizzi *IP* che possono inviare emails ( mantenuta dentro la `TXT` entry )

>[!example] 
>```bash
>unive.it. 86400 IN TXT “v=spf1 ip4:17.18.7.120 -all”
>```
>
>Questo significa : 
>+ `v=spf1` versione $1$ del protocollo `SPF`
>+ `17.18.7.120` può mandare email
>+ `-all` tutti gli altri non possono mandare email

Quando l'**MTA** del ricevente riceve una connessione dall'**MTA** del sender fa le seguenti cose : 
+ Fa un risoluzione **DNS** per i domini specificati in `HELO` e `MAIL FROM` 
+ Verifica che esiste il record `SPF` per entrambi 
+ Controlla che la connessione arriva da indirizzi *IP* consentiti nei record `SPF`
>[!note] 
>Pernderà poi una decisione che dipende dalla policy che ha settata

>[!warning] 
>`SPF` si basa sull'assunzione che un attaccante non può modificare il record **DNS**

##### Syntax

>[!example] 
>```bash
>$ dig ietf.org TXT
>;; ANSWER SECTION :
>ietf.org. 300 IN TXT 
>	"v=spf1 ip4:50.223.129.192/26 ip6:2001:559:c4c7::/48 
>	 a:ietf.org mx:mail.ietf.org ip4:192.95.54.32/27
>	   ip6:2607:5300:60:9ccf::/64 ip4:54.240.73.154/31
>	 include:_spf.google.com include:spf.hostedrt.com 
>	   include:amazonses.com ~all"
>```
>
>>[!note] 
>>`50.233.192.192/26` è permesso 

+ `ipv4/ipv6` : seguito dagli *IP* che possono inviare email ( ossia gli indirizzi che possono comportarsi come **MTA** usando `HELO` o `MAIL FROM` con il dominio `ietf.com` ) 
+ `a` :  stesso di `ipv4/ipv6` ma con un [[Domain Name]] , l'**MTA** risolverà il dominio e controllerà l'*IP*
+ `mx` : stesso ma con un record `MX` , l'**MTA** risolverà il dominio del record `MX` e controllerà l'*IP*
+ `include` : include il record `SPF` di qualche dominio specificato
+ `all` : indica tutto il resto , usato per dare un comportamento di default
+ Qualifiers :
	+ `+` : Pass ( se omettiamo il qualifier significa *pass* )
	+ `-` : Fail
	+ `∼` : Softfail
	+ `?` : Neutral

##### Decision Delegation

Se il server **MTA** trova una regola `SPF` che finisce con `-all` e il client **MTA** non matcha quella regola , allora il server dropperà la mail 

>[!note] 
>Così è il dominio del *sender* che decide non l'**MTA** 

Se la regola invece termina con `?all` vuol dire che il dominio del *sender* non da una regola precisa , l'**MTA** deciderà quindi cosa fare 
### DKIM 

Visto che tutti i campi di una email sono generati dall'**MUA** e vengono poi forwardati dall'**MTA** , l'unica entità che può verificare che quei campi siano corretti è l'**MSA**  

`DKIM` è un protocollo che permette di autenticare l'associaizone tra una e-mail e un **MTA** valido 

>[!note] 
>Questo funziona solamente se l'**MSA** possiede un paio di chiavi pubbliche / private che l'amministratore deve generare e configurare nell'**MSA** 

---

Quando un **MUA** contatta l'**MSA** questo si autentica 

>[!warning] 
>Quest è l'unico momento in cui una email può essere certificata in quanto il prossimo **MTA** non potrà più fare autenticazione

Quando usiamo `DKIM` l'**MSA** selezionerà dei campi della mail ( potenzialmente il `From` e il body ) e ne farà una [[Digital Signature]] usando la sua *private key* 

Un *digest* della [[Digital Signature]] viene generata e inclusa nell'*header* della mail 

Il prossimo **MTA** che riceverà la mail potrà verificare la [[Digital Signature]] con la [[Public Key]] dell'**MTA** firmataria

#### DKIM Field

>[!example] 
>```bash
>DKIM-Signature: v=1; a=rsa-sha256; c=relaxed/simple; d=ietf.org; s=ietf1; t=1730884895; bh=gKKOhIEVnQtATJMEQQoY5UYl3/bV+mlSqzFkKJnzquw=; h=Date:To:From:Subject:List-Id:List-Archive:List-Help:List-Owner:List-Post:List-Subscribe:List-Unsubscribe; b=ILdywWIjDUwI3JoXDLHPdhOBf02HPj9+
>WyjSYJlFL9S28eiCiR/ybDhCL1BAoYzYhMlLaDQUPo4jYp6FwU82cSjaj7/
>OIr6JcS0wVcCYLJQaLhRfRUkEA7i9xilpNuBEIyax9Ltt1YHZNvXuZ9m8Bfuapxs1UKL3tW0luG8MU6E=
>```
>

+ `v` : versione `DKIM` 
+ `a` : [[Hash Functions]] usata 
+ `h` : header firmati
+ `bh` : hash del body ( `sha256` in questo caso )
+ `h` :  [[Digital Signature]] ( firma `rsa` degli header e dell'hash del body )
+ `d,s` : domain e selector , usati per prendere la [[Public Key]]

#### Key Publication

L'amministratore del **MTA** firmatario deve pubblicare la [[Public Key]] tra le informazioni in record **DNS** ( in un campo `TXT` )

>[!important] 
>Il record **DNS** deve essere pubblicato sotto il dominio `selector._domainkey.domain` , dove `_domainkey` è una stringa fissata 
>>[!example] 
>>`ietf1._domainkey.ietf.org`

La chiave sarà recuperata tramite una query **DNS**

>[!example] 
>```bash
>dig ietf1.\_domainkey.ietf.org TXT
>
>;; ANSWER SECTION :
>ietf1.\_domainkey.ietf.org. 300 IN TXT ‘‘k = rsa ; p=
>MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDNzNnjKTd5cczd2CDzHflCZuv1tMWYwd7zE+deoJ6s/fXR7/n9ZIBnDS5egt7HAHjNjZrmjcoRlfSsNxRJvUQFyYvaU1BT1s8R+mkPgSOqZ4t9HqAVjiczn2B9+dbjdNN+S/zvSyMMuSCSJDKKAXhBpDeQTpeY7/UdP9s6ws0yjQIDAQAB’’
>```
#### FQDN + DKIM + SPF

Possiamo avere la seguente *chain* di requisiti :
$$\text{Valid IP/domain} \to \text{MTA allowed by SPF} \to \text{DKIM-valid From for a certain domain}$$

>[!warning] 
>Non abbiamo ancora un modo per linkare il *dominio* con il `From` e prendere una decisione
### DMARC

#### Alignment check

Gli *Alignment check* sono le decisioni che vengono prese a seconda di come sono settati i campi per `SPF` , `DKIM` , `From` etc..

>[!example] 
>Un *check* basilare è : 
>Il `From` deve matchare almeno uno di : 
>+ `d` nella `DKIM` [[Digital Signature]] 
>+ uno dei domini verificati da `SPF`

Cosa succede se un *Alignment check* fallisce ? ,

Qualsiasi sia la decisione questa deve essere consistente per ogni **MTA** , questo è deciso dal propietario del dominio 
#### DMARC

`DMARC` è un protocollo che permette al propietario del dominio di settare una policy di accettazione / rifiuto che tutte le **MTA** devono rispettare 

Viene usato un altro record `TXT` nel **DNS** , acessibile a `_dmarc.domain.com`
###### Syntax

Campi importanti : 
+ `p` ( policy ) : l'azione che l'**MTA** deve prendere se una *alignment check* fallisce 
	+ `none` : non fa nulla
	+ `quarantine` : flagga l'email come sospetta
	+ `reject` : rifiuta l'email
+ `rua` : l'email a cui vengono riportati fallimenti della policy 

>[!example] 
>```bash
>$ dig _dmarc.whitehouse.gov TXT
>;; ANSWER SECTION :
>_dmarc.whitehouse.gov. 2012 IN TXT "v=DMARC1 ; p=reject ; rua=mailto:b1fabe8b7f3f41a181ecd1253a794edf@dmarc-reports.cloudflare.net , mailto:reports@dmarc.cyber.dhs.gov"
>```
>
>In questo caso le email vengono rifiutate

# Summary

![[Pasted image 20241219124508.png]]

**Steps** : 

1. Alice usa `SMTP` con il suo **MSA** locale per dire che vuole inviare una mail da `alice@a.com` a `bob@b.com`
2. L'**MSA** autentica `Alice` con delle credenziali 
3. L'**MTA** in `a.com` usa `SMTP` per inviare una email usando gli appropiati `HELO`, `Mail From`, `From` e `DKIM-Signature` , l'*IP* sorgente è `1.2.3.4`
4. `1.2.3.4` viene testato contro *Spamhaus DNSBL* con query : `4.3.2.1.zen.spamhos.com`
5. Il server **MTA** in `b.com` fa una *reverse DNS query* per l'*IP* del **MTA** client
6. Questo risolve in `mail.a.com` e controlla che entrambe le risoluzioni matchano
7. Il server **MTA** fa una query `TXT` al server **DNS** di `a.com` e controlla che la policy `SPF` permette a `1.2.3.4` di inviare email per conto di `a.com`
8. Il server **MTA** fa una query per un sottodominio `_domainkey` al server **DNS** di `a.com` , riceve un key `DKIM` e controlla la firma della email
9. Il server **MTA** fa una query per un sottodominio `_dmarc` al server **DNS** di `a.com` , controlla che tutte le policy siano tutte rispettate 
10. Se tutte le policy sono rispettate la mail viene accetta




