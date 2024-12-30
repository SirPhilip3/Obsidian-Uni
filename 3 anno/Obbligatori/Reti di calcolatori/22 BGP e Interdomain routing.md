---
publish: true
creation: 2024-12-29T18:33:00
---
# Autonomous Systems ( AS )

Un *Autonomous System* è una collezione di **IP** connessi tra di loro controllati da uno o più *network operator* a nome di una singola entità o dominio

## Stub AS

Questi sono **AS** che non forniscono servizi di transito ma sono gli utenti finali delle informazioni 

Una **Stub AS** è collegata ad una ( *single-homed* ) o più ( *multi-home* ) **AS** upstream da cui prende i dati 

>[!note] 
>*Multi-homed* **stub AS** non permettono alle varie **AS** in entrata di indirizzare traffico attraverso di loro per collegarsi alle altre **AS** collegate
## Transit AS

Queste **AS** si connettono a più **AS** e offrono rotte tra un'**AS** ed un'altro , in pratica fornisce un servizio di transito dei dati
## In practice

Ogni **AS** è una collezione di *networks* che usano il propio protocollo di routing , ciò che le rende un **AS** è il fatto che siano possedute e controllate dalla stessa entità 

>[!note] 
>Ogni **AS** deve avere un numero identificativo fornito dalla **IANA**

Ogni **AS** ha un **Point of Presence** ( **POP** ) , ossia il posto fisico da dove sono accessibili
### Connecting AS

+ **Private Peering** :
	Questa è una connessione diretta tra due *router* di due **AS** , gli **AS** pagano per l'infrastruttura necessaria per connettersi , e generalmente lo scambio di dati tra i due è gratuito
+ **Internet Exchange Points ( IXP )** : 
	E' un datacenter condiviso dove i vari **AS** metteno i loro **POP** e si connettono tra di loro 

Per connettere due **AS** è necessario un **transit agreement** : un contratto tra due **AS** **A** e **B** dove **B** offre di connettere **A** ad internet , **B** funziona come un *gateway* per **A**

>[!note] 
>Un relazione di transito generalmente include delle tasse , **A** paga **B** in modo che **A** possa raggiungere internet 

# BGP

Il *routing* tra **ASes** deve usare il protocollo **BGP** ( **Border Gateway Protocol** )

Visto che in questo caso ci sono relazioni commerciali tra i vari **AS** i router non sempre annunciano tutti i loro *prefissi* agli altri , in generale
+ In una relazione da *customer* al *provider* , il *customer* annuncia tutti suoi prefissi e le rotte che ha imparata dai suoi clienti
+ In una relazione da *provider* al *customer* , il *provider* annuncia tutte le rotte che sa al suo *cliente*
+ In una connessione *shared-cost* una **AS** annuncia solo le sue rotte interne e le rotte che ha imparato dai suoi clienti 

>[!example] 
>![[Pasted image 20241230114610.png]]

## BGP routers

Ogni **AS** ha bisogno di almeno un *router* che supporta il protocollo **BGP** , questo annuncia i suoi prefissi ( ex : "il network con prefisso X è in questo **AS**" ) ma anche prefissi di altre **AS**

>[!note] 
>Per collegare le **AS** con il suo network interno il *border router* deve supportare sia **BGP** che il protoccollo di routing usato all'interno della rete 

### Example

![[Pasted image 20241230115726.png]]

**AS150** ha un il network `10.150.0.0/24` e ha il *router* di bordo **A** :
1. **A** annuncia `10.150.0.0/24` al router **D** in **AS11**
2. **A** annuncia `10.150.0.0/24` al router **B** in **AS151**
>[!note] 
>Gli annunci di **BGP** contengono il *prefisso* della rete e il *path* per raggiungere quel prefisso , all'inizio **AS150** si aggiunge a questo path

**AS151** e **AS11** forniscono entrambi il transito verso **AS150** , annunceranno quindi il prefisso per **AS150**
3. **B** annuncia `10.150.0.0/24` a **D** aggiungendo **151** nel *path*
4. **D** annuncia `10.150.0.0/24` a **B** aggiungendo **11** nel *path*
>[!note] 
>**B** e **D** non riannunciano `10.150.0.0/24` ad **A**

A questo punto sia **D** che **B** hanno due differenti rotte per raggiungere **A** :
+ Una diretta fatta di un solo *hop* 
+ Una indiretta fatta di due *hop*
Assumiamo che la scelta della rotta dipenda solo dalla lunghezza del *path* , in questo caso verrà quindi sempre scelta una rotta ad un *hop*

>[!note] 
>**BGP** implementa **Split Horizon** , infatti un **AS** non annuncia un prefisso al *router* da cui l'ha ricevuto , questo elimina i *single link loop*

>[!important] 
>Una cosa molto importante e che il prefisso viene sempre annunciato con il *path* completo per raggiungerlo , questo ci permette di evitare loop lunghi più di un singolo link

**BGP** può essere usato all'interno di una rete , in questo caso si chiama *Internal-BGP* ( *I-BGP* ) 

5. Quando usiamo *I-BGP* per router che sono all'interno dello stesso network non aggiungiamo nulla al *path* , semplicemente passiamo in avanti l'*annuncio* fatto agli altri *router* di bordo ( **F** e **E** )

>[!note] 
>**AS3** e **AS160** sono *single-homed stub AS*

6. **F** annuncia `10.150.0.0/24` a **G** aggiungendo al path **11**
7. **E** annuncia `10.150.0.0/24` a **C** aggiungendo al path **11**  

Ora **C** sa che per raggiungere `10.150.0.0/24` deve inviare traffico ad **E** , passare attraverso **AS11** per raggiungere **AS150** ( stessa cosa per **G** )

### BGP è un Path Vector Protocol 

**BGP** usa gli stessi principi di [[DV Routing]] con 3 differenze : 
1. Esporta l'intero *path* verso quell'*AS* , non solo la distanza dalla destinazione ( Per questo è detto *Path Vector* e non *Distance Vector* protocol )
2. Invia aggiornamenti solo quando qualcosa cambia o quando un vicino chiede per un aggiornamento 
3. I messaggi di `UPDATE` contengono informazioni solo riguardanti alcuni prefissi non tutta la routing table solo se :
	+ la rotta è *nuova*
	+ uno dei suoi attributi è cambiato ( tipo il *path* ) 
	+ la rotta è diventata *unreachable* e deve essere ritirata ( *withdrawn* )

#### Path Withdrawal

Se un **AS** smette di *hostare* un determinato prefisso invia un messaggio di *withdrawal* , i *router* che lo annunciavano invieranno a loro volta un messaggio di *withdrawal*

#### Link Failure

Se il link tra **A** e **D** si rompe , **D** manderà il messaggio di *withdrawal* ai router **B, E, F** 
Visto però che **D** ha un *path* alternativo per **A** passando attraverso **AS151** , **D** annuncerà il nuovo *path* agli altri 

## BGP Details

### BGP Connection

Quando due router **BGP** vogliono comunicare ognuno di loro accetta una connessione **TCP** alla porta `179`

**BGP** può mandare $5$ tipi di messaggi : 
+ `Open` : per iniziaire una connessione **BGP**
+ `Update` : per trasferire informazioni di routing tra router **BGP**
+ `Keepalive` : per controllare se un *peer* è ancora raggiungibile
+ `Notification` : per notificare **BGP** *peer* di errori
+ `Route-refresh` : per supportare capacità di *Route Refresh* 

Il messaggio di `Update` è fatto nel seguente modo : 
![[Pasted image 20241230164914.png]]

Questo ha due sezioni : 
+ *Routes* di cui un *router* vuole fare il *withdrawal*
+ *Routes* che un *router* vuole annunciare

>[!warning] 
>Non c'è criptografia o autenticazione in questi pacchetti
## BGP Path Prepending

>[!example] 
>![[Pasted image 20241230165335.png]]

Supponiamo che **1** sia un *multi-homed stub AS* che ha due connessioni :
+ una a $10Gb/s$ principale
+ una a $1Gb/s$ per backup 

L'**AS6** avrà una probabilità del $50\%$ di passare per **AS2** o per **AS3** , vogliamo che tutti utilizzino il path con maggiore capacità se è disponibile

**AS1** annuncia il prefisso `X.Y.Z.0/24` normalmente sul path con maggiore capacità , nel verso invece con minore capacità invece aggiungeremo al *path* **1** ripetuto $6$ volte : `X.Y.Z.0/24` con `path : 1,1,1,1,1,1` 

**AS6** in questo modo riceverà queste due route : 
+ `X.Y.Z.0/24 path : 5,3,1`
+ `X.Y.Z.0/24 path : 4,2,1,1,1,1,1,1`

In questo modo **AS6** utilizzerà sempre il *path* di minore lunghezza per arrivare a **AS1** 

>[!note] 
>Anche **AS2** e **AS4** passeranno attraverso **AS6** visto che comunque la lunghezza del *path* è minore

Se il link tra **AS3** e **AS5** si rompe verrà *withdrawal* la rotta che passa attraverso **AS3** e quindi l'unica rotta rimasta sarà attraverso la connessione di backup

>[!note] 
>**AS5** riceverà un aggiornamento con un *path* lungo $9$
>![[Pasted image 20241230170813.png]]
## BGP Anycast

>[!example] 
>![[Pasted image 20241230171510.png]]

In questo caso **AS1** e **AS6** annunciano lo stesso prefisso , gli *AS* connessi si divideranno in due : 
+ **AS2** e **AS3** si connetteranno ad **AS1**
+ **AS4** e **AS5** si connetteranno ad **AS6**
Per via della lunghezza del *path*

Questo permette alle grande aziende di instradare traffico ad un server rispetto ad un altro a seconda di dove si trova l'utente 

>[!note] 
>Questo significa che due *host* possono avere lo stesso indirizzo **IP**

>[!note] 
>Anche se un *link* fallisce essendo che tutti gli **AS** hanno sia il path verso **AS1** che verso **AS6** ci sarà sempre un backup

>[!warning] 
>E' possibile avere un **AS** che però ha la stessa lunghezza del *path* verso **AS6** e **AS1**
>![[Pasted image 20241230171956.png]]
>
>**AS7** cambierà destinazione dei pacchetti randomicamente , questo potrebbe causare problemi con servizi che hanno uno stato ( **TCP** ) 
>
>Per questo *Anycast* non viene usato con servizi che abbiano uno stato , solo con servizi che siano di tipo *richiesta-risposta* ( **DNS** )

### BGP Anycast for Root servers

Ci sono 13 root **DNS** server in tutto il mondo ma questi vengon annunciati da decine di **AS** differenti in tutto il mondo , questo fa in modo che la richiesta venga consegnata alla copia del server *root* più vicino

Questo funziona poichè ogni richiesta *DNS* è indipendente dalla precedente quindi anche se **BGP** cambia la decisione di routing non importa 

>[!note] 
>Per mantere in sync i server vengono aggiornati periodicamente 

