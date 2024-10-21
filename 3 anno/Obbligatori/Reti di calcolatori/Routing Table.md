---
creation: 2024-10-21T12:56:00
---
Una *routing table* è una struttura dati che contiene per ogni *destination address* $d$ i seguenti attributi : 
+ `R[d].link` : Rappresenta l'*outgoing link* che viene utilizzato per instradare i [[packet]] vero la destinazione $d$
+ `R[d].cost` : Rappresenta il costo ( delay , inverso della capacità del link ) che ha il *link* ( somma dei costi se multi-hop ) per arrivare alla destinazione $d$
+ `R[d].time` : E' la *timestamp* dell'ultimo [[Control Plane Packets]] che ha portato informazioni riguardo a $d$ 