---
creation: 2024-10-15T11:19:00
---
## Caratterstiche 

+ Ogni *host* è identificato da un *network layer address*
+ Il [[packet]] inviato sarà costituito da : 
	+ Il *network layer address* dell'*host* di destinazione
	+ Il suo *network layer address*
	+ I *dati* da inviare
+ *Routers* usano *hop-by-hop forwarding* : ossia ogni *router* che riceve il [[packet]] deve scieglere il prossimo *hop* indipendentemente dagli hop precedenti e futuri 

La decisione per ogni *hop* è basata sulla ![[Forwarding Table]] 
>[!warning] 
>Possiamo avere due tipologie di errori con questa architettura di routing : 
>+ ![[Black Holes]]
>+ ![[Routing Loops]]

