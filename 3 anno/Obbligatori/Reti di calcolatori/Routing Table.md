---
creation: 2024-10-21T12:56:00
---
Una *routing table* è una struttura dati che contiene per ogni *destination address* $d$ i seguenti attributi : 
+ `R[d].link` : Rappresenta l'*outgoing link* che viene utilizzato per instradare i [[packet]] vero la destinazione $d$
+ `R[d].cost` : Rappresenta il costo ( delay , inverso della capacità del link ) che ha il *link* ( somma dei costi se multi-hop ) per arrivare alla destinazione $d$
+ `R[d].time` : E' la *timestamp* dell'ultimo [[Control Plane Packets]] che ha portato informazioni riguardo a $d$ 

>[!note] 
>Ci possono essere più routing table nello stesso router 
>>[!example] 
>>Una potrebbe essere gestita dal [[Daemon]] del *router*
>>L'altra potrebbe essere gestita dall'amministratore

>[!info] 
>L'*obbiettivo* di un [[Routing Protocol]] è quello di riempire le *routing tabel* in tutti i *router* del network

>[!note] 
>Nel *router* tutte le *routing table* sono *unite* in un unica [[Forwarding Table]] su cui ci basiamo per prendere le decisioni di routing per ogni [[packet]]