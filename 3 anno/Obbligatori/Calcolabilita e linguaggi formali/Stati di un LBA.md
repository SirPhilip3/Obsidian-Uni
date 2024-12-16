---
publish: true
creation: 2024-12-16T10:49:00
---
>[!important] Lemma
>
>Sia $M$ un [[Automi Linearmente Limitati|LBA]] con $q$ *stati* e $g$ *simboli* possibili per il suo nastro. Se un nastro a lunghezza $n$ allora il numero di configurazioni possibili del corrispondente [[Automi Linearmente Limitati|LBA]] sarà : 
>$$q \cdot n \cdot g^n$$

**Dimostrazione** : 

Una *configurazione* è una tripla composta da : 
+ Stato dell'[[Automi Linearmente Limitati|LBA]]
+ Posizione della testina
+ Contenuto del nastro 

In totale un [[Automi Linearmente Limitati|LBA]] potrà quindi avere : 
+ $q$ stati
+ $n$ posizioni della testina
+ $g^n$ possibili contenuti del nastro 

Il numero totale delle possibili triple sarà quindi : $q\cdot n \cdot g^n$ 