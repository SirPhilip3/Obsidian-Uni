---
creation: 2024-10-22T10:43:00
tags:
  - Algoritmo
---
In *Distance Vector routing* assumiamo che ogni *link* abbia un costo ( questo può essere il delay , l'inverso della capacità etcc , il costo più semplice è *unitario* per ogni link ) , questo rappresenta la **penalità** che il [[packet]] subisce per passare da quel *link* 

>[!note] 
>Ogni **DV router** inizializza la [[Routing Table]] $R$ con una entry per il suo stesso indirizzo con distanza settata a $0$

>[!info] Initial State
>![[Pasted image 20241022105039.png]]

Periodicamente un *router* invia la sua [[Routing Table]] ( il *distance vector* ) a tutti i suoi vicini 

>[!note] 
>L'ordine di ricezione dei *distance vector* non è definito , può essere un ordine qualsiasi

>[!info] Sending DV
>```c
>Every N seconds:
>	v = Vector()
>	for d in R[] // R rappresenta tutte le destinazioni conosciute dal nodo
>		// aggiunge la destinazione d al vettore
>		v.add(Pair(d, R[d].cost)) 
>	for i in interface
>		// invia il vettore v sull'interfaccia i
>		send(v, i)
>```
>

>[!info] Recieving DV
>```c
>// V : received Vector
>// l : link over which vector is received
>def received (V , l ) :
>	// received vector from link l
>	for d in V[]
>		if not (d in R[]):
>			// new route
>			R[d].link = l
>			R[d].cost = V[d].cost + l.cost
>			R[d].time = now()
>		else :
>		// existing route , should I update ?
>			if ((V[d].cost + l.cost) < R[d].cost) or (R[d].link == l):
>				R[d].link = l
>				R[d].cost = V[d].cost + l.cost
>				R[d].time = now()
>```


Alla *ricezione* di un *DV* ricevo un certo *Vettore* `V` ad un certo *link* `l` 
Per tutte le destinazioni `d` presenti nel vettore `V` 
+ Se `d` non è all'interno della [[Routing Table]] allora la aggiungerà alla sua [[Routing Table]] , mettendo come costo la somma del costo indicato nel *DV* e il costo del *link* `l` 
+ Se `d` è già presente allora solamente se :
	Il costo indicato nel *DV* sommato al costo del *link* `l` è minore del costo già persente nella [[Routing Table]] 
		**oppure**
	se lo ricevo dal *next-hop* per quella destinazione ( ciò significa che qualcosa è cambiato nel *percorso* per la destinazione )

>[!example] 


>[!note] 
>+ I [[Control Plane Packets]] non sono mai intradati oltre il primo *hop*  
>+ Ad un certo punto le [[Routing Table]] possono non essere ottimali ( *fasi transitorie* ) ma la convergenza ad uno stato ottimale è garantita in un network statico
>+ Possiamo avere più configurazioni se abbiamo più *percorsi minimi* , la scelta dipende solo dall'ordine con cui vengono generati i *DV*
>+ La durata delle *fasi transitorie* dipende dalla sequenza di eventi che avvengono

## Failure Recovery

