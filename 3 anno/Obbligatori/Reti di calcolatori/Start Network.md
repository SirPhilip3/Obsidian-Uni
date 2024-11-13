---
creation: 2024-10-14T13:04:00
publish: true
---
>[!example] 
>![[Pasted image 20241014130519.png]]

**Pros** :
+ Migliore performance e costo rispetto al [[Ring Network]] visto che abbiamo un *link* dedicato ad ogni *link* ( tra server e host ) ( dobbiamo avere solo $n-1$ *link* fisici )
+ Resistenti a *failure* , se si rompe un link semplicemente si sconnette un *host* 

**Cons** : 
+ Se fallisce il centro tutto il network muore

>[!important]
>Usato per piccole LAN
>

>[!note] 
>In questo network non ci sono *collisioni* poichè i cavi usuano due circuiti separati per trasmissione e ricezione 