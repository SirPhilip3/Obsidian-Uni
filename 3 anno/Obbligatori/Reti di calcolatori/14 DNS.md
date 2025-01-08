---
publish: true
creation: 2024-12-16T16:53:00
---
# Application Layer Protocol

Molte applicazioni possono runnare nello stesso momento all'interno di un *server* , queste sono identificate da una **porta** offerta dal [[Transport Layer]] e da un *indirizzo di rete* della macchina *host*

>[!example] 
>![[Pasted image 20241218084709.png]]

>[!note] 
>La stessa cosa avviene sia per [[TCP]] che per [[UDP]] ( anche se in [[UDP]] non viene usato il termine *connessione* )
## IP Addresses

Ogni **NIC** ( **Network Interface Card** ) che ha accesso a *Internet* ha bisogno di un [[07 Network Layer]] *address* , questo è l'indirizzo **IP** ( *Internet Protocol* ) , può essere : 
+ *IPv4*
+ *IPv6*
## DNS

Dobbiamo mappare un [[Domain Name]] ad un indirzzo **IP** 
### Registering a Name

>[!example] 
>
>Ipotizziamo che vogliamo una pagina web con il dominio `example.com` 
>
>Abbiamo bisogno di un server con un indirizzo *IP* pubblico , ex : `1.2.3.5` , setuppa un *web server* per servire la pagina quando viene richiesta 
>
>Compra il *dominio* da qualche *Registrar* , deve ora configurare un server [[DNS]] per rispondere alle *name queries* per il *dominio* in modo da matchare `1.2.3.5` a `example.com` 
>
>Generalmente il server [[DNS]] viene fornito dal *Registrar* , questo comunicherà al propietario del **TLD** per `.com` che esiste un nuovo sottodominio `example.com` , questo rende il server [[DNS]] **autoritativo** per quel dominio
### Accessing the Domain

Un *broswer* web che vuole accedere a `example.com` non sa chi è *autoritativo* per lui , il broswer conosce però 13 *root servers* , questi forniscono gli indirizzi dei server [[DNS]] che sono *autoritativi* per tutti i **TLD** 

>[!example] 
>
>Per accedere a `example.com` , il broswer conosce l'indirizzo *IP* del server [[DNS]] per `.com` , questo risponde che non sa l'*IP* di `example.com` ma sa che `1.2.3.4` è *autoritativo* per lui 
>
>Il broswer chiederà quindi a `1.2.3.4` che risponderà che `example.com` è a `1.2.3.5`

>[!note] 
>
>I server [[DNS]] sono strutturati ad albero , se uno non conosce l'*IP* ritornerà l'indirizzo di un altro server [[DNS]] 

>[!important] 
>
>Questo processo è molto **inefficente** , per questo si aggiungo all'*host* dei server [[DNS]] interni al suo *network* a cui facciamo la domanda iniziale che poi eventualmente viene instradata ad altri [[DNS]] se non sa la risposta
>
>>[!example] 
>>![[Pasted image 20241218094717.png]]

### Recursive , Iterative query

#### Recursive

Una query **ricorsiva** avviene quando l'host delega l'intera ricerca al server [[DNS]] locale , in questo caso il server non può ritornare una risultato parziale 

>[!note] 
>Ogni server **DNS** fa query *ricorsive* solo se ha ricevuto una query da qualchè *host* della rete locale 

#### Iterative

Una query **iterativa** può ritornare una risposta *parziale* 

>[!note] 
I server **root** e quelli *atoritativi* per `.com` non permettono query *ricorsive*

### DNS Caching

Se qualcuno all'interno della rete locale ha già visitato quel determinato dominio il server **DNS** locale manterrà l'*IP* risolto in modo che alla prossima richiesta non verrà fatta una richiesta **ricorsiva** ma una il server **DNS** locale risponderà direttamente

>[!example] 
>![[Pasted image 20241218100832.png]]
>
>In questo caso viene mantenuto il fatto che `1.2.3.4` è `AUTHORITATIVE` per tutti i sotto domini di `example.com`

## DNS Protocol

>[!warning] 
>
>**DNS** non è stato ideato con nessun servizio di sicurezza 
>
>Originalmente **DNS** utilizza [[UDP]] , versioni più recenti usano [[TCP]] 
### Message Format

![[Pasted image 20241218101828.png]]

Dove : 
+ `Header` : Spazio per gli *header*
+ `Question` : Contiene la domanda per il [[Name Servers]] 
+ `Answer` : Risposte alla question ( [[14 DNS#Resource Record|Resource Record]] )
+ `Authority` : Contiene il campo *authority* ( [[14 DNS#Resource Record|Resource Record]] )
+ `Additional` : Spazio per altre informazioni

#### Header

![[Pasted image 20241218102134.png]]

+ Transaction `ID` : è un numero unico che rappresenta la transazione , inviato dal *client* , questo verrà replicato nella *risposta* 
>[!warning] 
>Il suo valore deve essere random altrimenti si introducono problemi di sicurezza 
+ *Flags* : 
	+  `QR` : Query type 
		+ `0` per *richieste*
		+ `1` per *risposte*
	+ `AA` : Se la risposta è `Authoritative` ( `1` ) o meno ( `0` )
	+ `RD` : La richiesta è *ricorsiva* ( `1` )
	+ `RA` : Se il server supporta la ricorsione ( `1` )
	+ `Z` : Per usi futuri
	+ `RCODE` : Response code `0` OK , errori ( `1-5` )
+ I rimanenti campi rappresentano il numero di : *Questions* , *Answers* , *Authority* e *Additional* presenti nel resto del messaggio , ognuno di questi è un **Resource Record** 
#### Resource Record 

![[Pasted image 20241218103528.png]]

+ `NAME` : Il nome che era stato richiesto 
+ `TYPE` : 
	+ `A` : Indirizzo *IPv4* dell'*host*
	+ `AAAA` : Indirizzo *IPv6* dell'*host*
	+ `NS` : Authoritative Name Server
	+ `MX` : Mail Exchange
	+ `CNAME` : Alias per la stessa risorsa
	+ `SOA` : Dati riguardanti al propietario
	+ `TXT` : Qualsiasi altra cosa
+ `TTL` : Il tempo per cui questa informazione può essere mantenuta in *cache*
+ `RDLENGTH` : La lunghezza del campo `RDATA`
+ `RDATA` : L'informazione

>[!note] 
>
>La lunghezza degli *header* sono di lunghezza fissa , questo ci permette di renderne più facile il parsing in hardware ma limita la possibilità di estensione del protocollo , per questo vengono mantenuti dei bit riservati ad uso futuro
>>[!example] 
>>
>>Il campo `TXT` fa in modo che possiamo scriverci all'interno qualsiasi cosa , e quindi possiamo utilizzarlo per fare anche cose più complesse 
>>

>[!note] 
>Alcuni `TYPE` sono *non-terminali* ossia anche se abbiamo raggiunto un server *autoritativo* non risponde con un *IP* ma con un altri *dominio* , necessiteremo poi un'altra query per risolverlo
### Reverse DNS

Quando registriamo un dominio **possiamo** ( non è obbligatorio ) aggiungere un [[14 DNS#Resource Record|RR]] `PTR` dove specifichiamo un dominio nel seguente formato : `<reversed ip>.in-addr.arpa`

In cui il dominio `in-addr.arpa` è usato per fare **reverse lookups** , questo permette di , dato un indirizzo *IP* ritornare un *dominio* 

>[!example] 
>
>Se vogliamo sapere il dominio associato a `1.2.3.5` , facciamo una richesta *DNS* per `5.3.2.1.in-addr.arpa` , questo ci ritornerà una lista di *domini* associati ad esso 

>[!note] 
>L'indirizzo viene rovesciato poichè anche il *reverse DNS* è *gerarchico* , infatti :
>>[!example] 
>>1. Inizialmente chiediamo l'indirizzo dei server *DNS* di `in-addr.arpa` 
>>2. Ad uno di questi *DNS* chiediamo quindi di `5.3.2.1.in-addr.arpa` che risponderà con l'indirizzo per `1.in-addr.arpa` 
>>3. Chiediamo al *DNS autoritativo* per `1.in-addr.arpa` di risolvere `5.3.2.1.in-addr.arpa` questo ci risponderà con il *DNS autoritativo* per `2.1.in-addr.arpa`
>>4. Cos'ì via fino a ritrovare l'indirizzo completo `5.3.2.1.in-addr.arpa` 

### WHOIS Protocol

Il protocollo `WHOIS` ci permette di ricevere informazioni legate ad un certo dominio 

Una query `WHOIS` chiede al **Regional Register** ( **RIR** ) l'indirizzo del **Registrar** responsabile per il *dominio* , a cui verra chiesto di dare dei dati riguardanti quel dominio ( *Owner, email* etcc )

### DNS Operations

#### Server Redundancy

Generalmente abbiamo più server *DNS autoritativi* per lo stesso dominio , in modo che se uno non risponde la stessa query viene ripetuta in *round-robin* per gli altri 

>[!note] 
>Dobbiamo fare *round-robin* poichè la comunicazione è [[UDP]] e quindi non sappiamo distinguere se i pacchetti sono andati persi o il server è down 

>[!warning] 
>
>In alcuni casi il servizio viene replicato su diverse macchine , per questo potrebbe essere che per lo stesso dominio il *DNS* ritorni diversi *IP* anche prima che il `TTL` termini , l'*IP* ritornanto sarà scelto a *round-robin* tra quelli forniti dal *DNS*

#### TTL

Il `TTL` può essere : 
+ *grande* : il `DNS` riceve meno richieste
+ *piccolo* : ogni cambiamento viene propagato velocemente 
