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
