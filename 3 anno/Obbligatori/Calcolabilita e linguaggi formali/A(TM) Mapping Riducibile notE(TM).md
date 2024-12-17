---
publish: true
creation: 2024-12-17T10:32:00
---
>[!important] 
>$A_{TM} \leq_M \bar{E}_{TM}$ 

**Dimostrazione** : 

Costruiamo una $f$ [[Funzione Calcolabile]] tale che $<M,w> \in A_{TM} \iff f(<M,w>) \in \bar{E}_{TM}$

Implementiamo $f$ tramite la seguente [[08 Macchine di Touring|MdT]] $F$ : 
$F$ = Su input $<M,w>$ 
1. Costruisci una nuova [[08 Macchine di Touring|MdT]] $N$ definita nel seguente modo : 
	$N$ = Su input $x$ :
	1. Se $x \neq w$ 	`REJECT`
	2. Altrimenti simula $M$ su $w$ e ritorna il suo output
2. Ritorna $<N>$ 

**Correttezza** : 
1. Se $<M,w>\in A_{TM}\implies M \text{ accetta } w \implies L(N) = \{w\} \implies L(N)\neq \emptyset\implies <N> \notin E_{TM} \implies <N> \in \bar{E}_{TM}$
2. Se $<M,w>\notin A_{TM} \implies M \text{ non accetta } w \implies L(N) = \emptyset\implies <N> \in E_{TM}\implies <N> \notin \bar{E}_{TM}$
