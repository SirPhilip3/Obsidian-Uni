---
publish: true
creation: 2024-12-17T09:39:00
---
>[!important] Teorema
>
>$A_{TM} \leq_M HALT_{TM}$

**Dimostrazione** : 

**Hp** : 
$$A_{TM} = \{ <M,w> | M \in MdT \land w \in L(M)\}$$
$$HALT_{TM} = \{ <M,w> | M \in MdT \text{ che termina su $w$} \}$$
Dobbiamo trovare una $f$ [[Funzione Calcolabile]] tale che :
$$<M,w> \in A_{TM} \iff f(<M,w>) \in HALT_{TM}$$
Diamo una [[08 Macchine di Touring|MdT]] $F$ che implementi la funzione $f$ : 
$F$ = Su input $<M,w>$ 
1. Costruisci una nuova [[08 Macchine di Touring|MdT]] $N$ definita come segue : 
	$N$ = Su input $x$ :
	1. Simula $M$ su $x$
	2. Se $M$ *accetta* ritorna `ACCEPT`
	3. Se $M$ *rifiuta* vai in *loop* 
2. Ritorna $<N,w>$ 

**Correttezza** : 
1. $M$ *accetta* $w$ $\implies$ $<M,w> \in A_{TM}$ per definizione 
	$N$ *accetta* $w$ quindi $<N,w> \in HALT_{TM}$ perchè ha terminato
2. $M$ *rifiuta* $w$ $\implies$ $<M,w> \notin A_{TM}$
	$N$ va in *loop* quindi $<N,w> \notin HALT_{TM}$ poichè non termina mai 
3. $M$ va in loop su $w$ $\implies$ $<M,w> \notin A_{TM}$ 
	In questo caso $N$ va in *loop* su $w$ quindi $<N,w>\notin HALT_{TM}$ 

>[!note] 
>Ricordiamo che visto che abbiamo dimostrato che [[HALT Problem]] è [[Indecidibile]] allora anche $A_{TM}$ è [[Indecidibile]]