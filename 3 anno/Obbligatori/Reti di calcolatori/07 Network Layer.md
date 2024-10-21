---
creation: 2024-10-15T10:48:00
---
Il *network layer* permette la trasmissione delle informazioni tra *host* che non sono parte della stessa rete fisica attraverso *router* ( questi hanno più di una *network interface card* ( *NIC* ) doranno quindi prendere una decisione sul *forwarding* ) intermedi

Il **Network Layer** assume che : 
+ Il [[DataLink Layer]] sia *almost reliable* ( può avvenire *packet loss* ma è poco frequente )
+ Un [[packet]] contiene i *dati* e un *header* , questi verranno incapuslati in un [[Frame]] del [[DataLink Layer]]

Possiamo avere due tipi di **Network Layer** : 
+ ![[Datagram-Oriented]]
+ **Circuit-Oriented**

Il *router* è diviso in due funzioni : 
+ ![[Data Plane]]
+ ![[Control Plane]]
Se avessimo un approccio *centralizzato* potemmo utilizzare i ![[Virtual Circuits]]

![[Addressing]]

![[Fragmentation]]

## Routing Algorithm

![[Hot Potato Routing]]



[[DV Routing]]

[[Count to Infinity]]

[[Link state Routing]]