---
creation: 2024-10-16T09:28:00
---
Gli indirizzi vengono raggruppati in *blocchi* 

Ad ogni *router* gli viene assegnato uno specifico *blocco* di indirizzi , in questo modo la [[Forwarding Table]] deve contenere solo gli indirizzi del *blocco* ( migliaia / milioni di indirizzi ) 

**Pros** :
	Possiamo usare hardware meno costoso visto che necessiteremo meno memoria e potenza computazionale 
**Cons** : 
	Se un *host* cambia *network* cambierà anche il suo indirizzo , dovremo quindi avere: 
+ un metodo per ricevere un *indirizzo* quando entriamo un nuovo network
+ un metodo per mantenere tutte le comunicazioni attive quando entriamo in un nuovo network

