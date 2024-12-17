---
publish: true
creation: 2024-12-17T11:28:00
---
>[!important] Teorema
>$EQ_{TM}$ non è [[Touring Riconoscibili]]

**Dimostrazione** : 

Dimostriamo che $\bar{A}_{TM} \leq_M EQ_{TM}$ , ossia che $A_{TM} \leq_M \bar{EQ}_{TM}$

Costruiamo $f$ [[Funzione Calcolabile]] tale che $<M,w> \in A_{TM} \iff f(<M,w>) \in \bar{EQ}_{TM}$ 

$f$ è implementata dalla seguente [[08 Macchine di Touring|MdT]] $F$ : 
$F$ = Su input $<M,w>$ 
1. Costruiamo una [[08 Macchine di Touring|MdT]] $N_1$ :
	1. Su input $x$ `REJECT` ( $L(N_1) = \emptyset$ )
2. Costruiamo una [[08 Macchine di Touring|MdT]] $N_2$ :
	1. Su input $x$ :
		1. Simula $M$ su $w$ e ritorna il suo output
3. Ritorna $<N_1,N_2>$

**Correttezza** : 

1. $<M,w> \in A_{TM} \implies M \text{ accetta } w \implies L(N_2) = \Sigma^*$ ( questo perchè per qualsiasi input $x$ su $N_2$ questo accetterà se $M \text{ accetta } w$ ) , $\implies L(N_1) \neq L(N_2) \implies <N_1 , N_2> \in \bar{EQ}_{TM}$ 
2. $<M,w> \notin A_{TM} \implies M \text{ rifiuta } w \implies L(N_2) = \emptyset \implies L(N_1) = L(N_2) \implies <N_1 , N_2> \notin \bar{EQ}_{TM}$ 
