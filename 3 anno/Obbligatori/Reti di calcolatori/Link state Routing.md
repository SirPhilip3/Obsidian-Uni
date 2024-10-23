---
creation: 2024-10-23T09:32:00
---
>[!info] Idea
>I *router* si scambiano messaggi in modo che ognuno sappia tutta la topografia della rete , in base alla topologia imparata ogni *router* deciderà indipendentemente il cammino minimo tramite un algoritmo di *shortes path* come *Dijkstra*

>[!note] 
>La rete è rappresentata attraverso un grafo direzionato con i *link* che possono avere diversi tipi di pesi : 
>+ Peso *unitario*
>+ Peso proporzionale al *delay* del link , il percorso più breve sarà quello con minore *delay* complessivo
>+ $\frac{C}{link\_capacity}$ dove $C$ è una *costante* , più grande sarà la capacità del *link* minore sarà il peso 

## LSP Messages

Ogni *router* ha un indirizzo unico 

Un *router* manda un messaggio di `HELLO` ogni $N$ secondi su tutte le sue interfacce , questo messaggio contiene l'indirizzo del *router* , visto che anche tutti i suoi vicini mandano messaggi di `HELLO` questo automaticamente scopre tutti i suoi vicini

>[!note] 
>Se un *link* fallisce questo non potrà più mandare messaggi di `HELLO` , un *link* viene considerato fallito se non abbiamo ricevuto un `HELLO` per almeno $k\times N$ secondi

![[Pasted image 20241023100049.png]]

![[Link state packet]]

## LSP Flooding

