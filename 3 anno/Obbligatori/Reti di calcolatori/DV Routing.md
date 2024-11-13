---
creation: 2024-10-22T10:43:00
tags:
  - Algoritmo
publish: true
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

Visto che ogni $n$ secondi viene aggiorno `R[d].time` allora ogni rotta non può avere un `time` più vecchio di $n$ secondi 

Se una rotta è più vecchia di $3\times n$ secondi il suo costo viene settato a $\infty$

Dopo ulteriori $3 \times n$ secondi la rotta viene rimossa dalla [[Routing Table]]

>[!note] 
>Dovrebbe essere passato abbastanza tempo per fare in modo che : 
>+ Possa eventualmente ricevere un *DV* che abbia un costo minore di $\infty$
>+ I vicini abbiano abbastanza tempo per installare rotte migliori provenienti da qualche altro *router* 
>+ I *DV* non vengano persi per via di errori di trasmissione

>[!important] 
>3 viene usato in modo arbitrario

>[!example] 
>Il link tra **A** e **B** fallisce
>![[Pasted image 20241022160850.png]]
>
>**A** manda il suo *DV*
>![[Pasted image 20241022161032.png]]
>
>**D** manda il suo *DV*
>![[Pasted image 20241022161057.png]]
>
>>[!note] 
>>A questo punto viene creato un [[Black Holes]] dove tutto il traffico da **C** verso **A** viene perso in **B**
>
>**E** manda il suo *DV*
>
>![[Pasted image 20241022161243.png]]
>
>Adesso non c'è più il [[Black Holes]] su **B** ma non abbiamo ancora la *convergenza* nel network in quanto **C** usa una rotta con 4 *hop* ( `C-B-E-D-A` ) invece degli ottimali 3 ( `C-E-D-A` ) , dopo la convegenza avermo che il network sarà : 
>
>![[Pasted image 20241022161624.png]]

>[!warning] Count to Infinity
>Ipotiziamo ora che fallisca il nodo tra **D** ed **E** 
>
>Il nodo **D** è il primo a rilevare il guasto e setta il costo per **B** , **C** ed **E** a $\infty$ , però il nodo **A** genera il suo *DV* prima che **D** riesca a generare il suo *DV* , questo quindi avendo costi per **B** , **C** ed **E** minore di $\infty$ setterà i costi nella [[Forwarding Table]] di **D** a quelli di **A** sommandoci $1$ ( è come se ora per andare a **B** , **C** ed **E** possa passare per **A** )
>
>![[Pasted image 20241022163549.png]]
>
>>[!note] 
>>Il router **D** non può spere che le rotte nel *DV* di **A** passino per se stesso 
>
>Il router **D** manderà quindi il suo *DV* ad **A** che però ora non riflette la mancanza di un percorso per **B** , **C** ed **E** , **A** lo riceverà ed aumenterà i suoi costi di $1$ 
>
>![[Pasted image 20241022163927.png]]
>
>Alla fine i *router* **D** ed **A** arriveranno con i costi settati ad infinito  
>

Una possibile soluzione possono essere i **Triggered Updates** :
Ogni volta che un *link* fallisce viene *triggerata* la generazione di un *DV*

Questi non risolvono il problema infatti : 
+ Potrebbe sempre essere che **D** riceva un *DV* da **A** prima che riesca a generare il *DV*
+ Potremmo perdere il [[packet]] contenente il *DV* di **D**

>[!danger] 
>Il **Count-to-infinity** ( con **Triggered Updates** ) può avvenire se :
>+ C'è un loop ( un *link* full-duplex è già un loop )
>+ Ci deve essere un cambio nella topologia della rete
>+ Un [[packet]] viene perso
>
>>[!note] 
>>Non è importante di come si fatto il network dopo il *link* che fallisce

