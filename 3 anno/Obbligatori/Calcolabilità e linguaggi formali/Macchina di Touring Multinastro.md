---
creation: 2024-11-06T10:07:00
---
Una **MdT** *multinastro* avrà $k>1$ nastri : 
+ Riceve l'input sul *primo* nastro
+ quando *computa* : 
	+ legge da $k$ nastri
	+ modifica $k$ nastri
	+ sposta $k$ testine arbitrariamente 

La *funzione di transizione* diventerà quindi : 
$$\delta : Q \times \Gamma^k \to Q \times \Gamma^k \times \{L,R,S\}^k$$
Dove : 
+ $Q \times \Gamma^k$ : dallo stato $Q$ legge $k$ simboli da $k$ nastri
+ $Q \times \Gamma^k \times \{L,R,S\}^k$ : passa ad uno stato $Q$ modificando $k$ simboli e fa $k$ passi indipendenti gli uni dagli altri

>[!example] 
>![[MdTMulti.excalidraw]]

>[!important] Teorema
>Ogni **MdT** *multinastro* può essere convertito in un **MdT** a singolo nastro ad esso equivalente 
>>[!important] Dimostrazione
>>
>>>[!info] Idea
>>>
>>>Salviamo i $k$ nastri in iniziali in un singolo nastro limitando i nastri con un *marker* $\#$ , inoltre per indicare la posizione delle testine nei nastri mettiamo un $\cdot$ sopra al simbolo dove si trova 
>>>![[MdTmultuTo1.excalidraw]]
>>
>>$S$ = Su input $w=w_1\dots w_n$ : 
>>1. Impostiamo il nastro singolo con all'inizio l'input e sucessivamente formattiamo il nastro per contenere i $k$ nastri di $M$
>>   $$\#\dot{w_1}w_2 \dots w_n\#\dot{\sqcup}\#\dot{\sqcup}\#\dots\#$$
>>2. $S$ scansiona il suo nastro leggendo tutti i simboli con il $\cdot$ e li salva nel suo stato 
>>   Scorri nuovamente il nastro per aggiornare i simboli con $\cdot$ e per spostare i pallini secondo la $\delta$ della **Mdt** *multinastro*
>>3. Se in un qualche momento spostiamo un pallino sopra ad un $\#$ facciamo uno shift a destra di una posizione in modo da simulare un nastro infinito 

