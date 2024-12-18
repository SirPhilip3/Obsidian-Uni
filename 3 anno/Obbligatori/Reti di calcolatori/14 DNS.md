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
>


