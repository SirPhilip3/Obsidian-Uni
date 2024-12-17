---
publish: true
creation: 2024-12-17T10:12:00
---
>[!important] 
>
>$E_{TM} \leq_M EQ_{TM}$

**Dimostrazione** : 
$$E_{TM} = \{ <M>| M \in MdT \land L(M) = \emptyset \}$$
$$EQ_{TM} = \{ <M_1 , M_2> | M_1 \in MdT , M_2 \in MdT \land L(M_1) = L(M_2)\}$$

Costruiamo $f$ [[Funzione Calcolabile]] tale che $<M> \in E_{TM}\iff f(<M>) \in EQ_{TM}$ , implementiamo $f$ nel seguente [[08 Macchine di Touring|MdT]] $F$ 
$F$ = Su input $<M>$ : 
1. Costruisci una nuova [[08 Macchine di Touring|MdT]] $N$ che risconosca il $L(N)=\emptyset$
2. Ritorna in output $<M,N>$ 

**Correttezza** : 
1. Se $<M> \in E_{TM} \implies L(M)=\emptyset \implies <M,N> \in EQ_{TM}$ poichè entrambi vuoti
2. Se $<M> \notin E_{TM} \implies L(M)\neq\emptyset \implies <M,N> \notin EQ_{TM}$ 




