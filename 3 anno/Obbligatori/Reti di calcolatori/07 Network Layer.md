---
creation: 2024-10-15T10:48:00
---
Il *network layer* permette la trasmissione delle informazioni tra *host* che non sono parte della stessa rete fisica attraverso *router* ( questi hanno più di una *network interface card* ( *NIC* ) doranno quindi prendere una decisione sul *forwarding* ) intermedi

Il **Network Layer** assume che : 
+ Il [[Data Link Layer]] sia *almost reliable* ( può avvenire *packet loss* ma è poco frequente )
+ Un [[packet]] contiene i *dati* e un *header* , questi verranno incapuslati in un [[Frame]] del [[Data Link Layer]]

Possiamo avere due tipi di **Network Layer** : 
+ ![[Datagram-Oriented]]
+ **Circuit-Oriented**

[[Addressing]]

[[DV Routing]]

[[Count to Infinity]]

[[Link state Routing]]