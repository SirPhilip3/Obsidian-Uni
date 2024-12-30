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
+ Esporta l'intero *path* verso quell'*AS* , non solo la distanza dalla destinazione ( Per questo è detto *Path Vector* e non *Distance Vector* protocol )
+ Invia aggiornamenti solo quando qualcosa cambia o quando un vicino chiede per un aggiornamento 
+ I messaggi di `UPDATE` contengono informazioni solo riguardanti alcuni prefissi non tutta la routing table , solo se la rotta è *nuova* 