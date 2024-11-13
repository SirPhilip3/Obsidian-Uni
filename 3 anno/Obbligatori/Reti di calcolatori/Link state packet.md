---
creation: 2024-10-23T10:08:00
aliases:
  - LSP
publish: true
---
Un *link-state packet* contiene le seguenti informazioni : 
+ `LSP.Router` : l'indirizzo di chi invia l'*LSP*
+ `LSP.age` : età o tempo rimanente dell'*LSP*
+ `LSP.seq` : numero di sequenza dell'*LSP* ( viene incrementato per ogni *LSP* inviato )
+ `LSP.Links[]` : lista di *link* presenti nell'*LSP*
	+ `LSP.Links[i].id` : indirizzo del vicino
	+ `LSP.Links[i].cost` : costo del *link*
