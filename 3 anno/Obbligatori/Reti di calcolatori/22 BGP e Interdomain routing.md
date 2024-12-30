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