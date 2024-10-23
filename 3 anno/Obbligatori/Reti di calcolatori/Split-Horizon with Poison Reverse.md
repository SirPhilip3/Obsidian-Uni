---
creation: 2024-10-22T17:03:00
---
Lo *Split-Horizon with Poison Reverse* è una variante del [[DV Routing]] 

Per generare i *DV* usiamo il seguente codice : 

```c
Every N seconds:
	for ifc in interfces:
		// creiamo un vettore per ogni intefaccia del router
		v = Vector()
		for d in R[]
			if (R[d].link != ifc):
				v.add(Pair(d, R[d].cost))
			else: 
				v.add(Pair(d, infinity))
		send(v, ifc)
```

**Split Horizon** : dice al *router* che il suo *orizzonte* non è tutto lo stesso , bensì è diviso tra i *router* che usa come *next-hop* e tutti gli altri ( in pratica ai miei vicini mando solo cammini che stanno nel loro *orizzonte* , ossia quelli che non ha appreso tremite quel vicino a cui sta mandando le rotte )

**Poison Reverse** : dice al *router* a cui sta mandando il *DV* che non ha un rotta a qualche destinazione $d$ se questa passa attraverso il vicino stesso ( in pratica setta a $\infty$ il costo per le rotte che prima avevo escluso )

>[!example] 
>**A** invia il *DV* usando **Poison Reverse**
>
>![[Pasted image 20241023085119.png]]
>
>Il *router* **D** non aggiornerà la sua [[Routing Table]] visto che **A** gli ha inviato rotte con costo $\infty$ per le destinazione che ha imparato attraverso **D** , a questo punto **A** ha ancora una [[Routing Table]] che ha delle rotte per **B** , **C** ed **E** , questo è risolto la prossima volta che **D** invia il suo *DV* visto che non aggiornerà le sue rotte poichè il link tra **D** ed **E** è rotto

>[!warning] 
>Il **Count-to-infinity** avviene ancora
>
>>[!example] 
>>Alla rottura del *link* tra **A** e **B** , **B** invia i *DV* con **Poison Reverse** a **E** e **C** ma *router* **C** non riceve il [[packet]]  
>>
>>![[Pasted image 20241023090119.png]]
>>
>>**C** ora invia il suo *DV* con **Poison Reverse** a **B** e **E** , questo non crea un *loop* tra **B** e **C** per via del **Poison Reverse** , **E** riceve però un *DV* che contiene ancora dei cammini per arrivare ad **A** , questo crea un [[Black Holes]] in **B** in quanto i [[packet]] che da **C** vogliono arrivare in **A** ora passeranno per **E** e andaranno in **B** dove veranno persi 
>>
>>Ora **E** manda il suo *DV*
>>
>>![[Pasted image 20241023091011.png]]
>>
>>A questo punto **B** aggiornerà il costo di **A** poichè ha ricevuto un valore minore da **E** 
>>Ora quando **B** manderà il suo *DV* **C** aggiornerà i suoi costi , li manderà ad **E** e così via 
>>
>>Si è creato un nuovo *loop* tra **B-C-E** , questo porterà ad un nuovo **Count-to-infinity**

Un metodo per prevenire questo è vietare l'aggiornamento delle rotte per un certo periodo di tempo dopo che il costo di un cammino viene settato a $\infty$ 

Questo fa in modo che ci sia abbastanza tempo per fare in modo che l'informazione si propaghi tra i vicini evitando che un singolo *packet loss* porti a **Count-to-infinity** 

>[!note] 
>In ``