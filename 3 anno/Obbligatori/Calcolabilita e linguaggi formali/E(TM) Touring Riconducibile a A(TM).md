---
publish: true
creation: 2024-12-17T12:31:00
---
>[!important] Teorema
>
>$E_{TM} \leq_T A_{TM}$

**Dimostrazione** : 

Dimostriamo che esiste una [[Macchina di Touring con Oracolo|MdT con Oracolo]] per $A_{TM}$ che decide $E_{TM}$ :
$S$ = Su input $<M>$ : 
1. Costruiamo una nuova [[08 Macchine di Touring|MdT]] $N$ con la seguente propietà : 
	$$L(N) = \begin{cases} \Sigma^* & \text{se } L(M) \neq \emptyset \\ \emptyset & \text{se } L(M) = \emptyset \end{cases}$$
2. Chiamiamo l'[[Oracolo]] per $A_{TM}$ su $<N,w>$ dove $w$ è qualsiasi stringa 
3. Inverti l'output

Scriviamo ora la [[08 Macchine di Touring|MdT]] $N$ : 
$N$ = Su input $x$ : 
1. Per $i=0,1,2,3,\dots$
	1. Esegui $M$ su $s_1,s_2,\dots,s_n$ per $i$ passi di computazione
	2. Se una di tali stringhe *accetta* ritorna `ACCEPT`

>[!note] 
>Se $M$ *non accetta* alcuna stringa $N$ va in loop per tutti i suoi input 
>Se $M$ *accetta* almeno una stringa prima o poi finirà con `ACCEPT`