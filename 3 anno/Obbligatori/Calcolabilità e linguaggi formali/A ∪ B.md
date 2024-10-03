---
creation: 2024-09-25T08:54:00
tags:
  - Dimostrazione
---
>[!important] Dimostrazione
>
>Dimostriamo che se $A$ e $B$ sono regolari allora $A \cup B$ è *regolare*
>
>Essendo $A$ e $B$ regolari allora esisteranno :
>+ $M_1 = (Q_1,\sum_1,\delta_1,q_1,F_1)$ con $L(M_1) = A$
>+ $M_2 = (Q_2, \sum_2, \delta_2,q_2,F_2)$ con $L(M_2) = B$ 
>  
>Per dimostrare la proprietà dovremo quindi creare un nuovo [[DFA]] $M$ tale che $L(M) = A \cup B$
>
>Costruiamo $M$ in modo che simuli $M_1$ e $M_2$ in "parallelo"
>
>Sia $M=(Q,\sum,\delta,q_0,F)$ il [[DFA]] definito come segue :
>1. Assumiamo che $\sum_1 = \sum_2 = \sum$
>2. $Q = Q_1 \times Q_2 = \{ q_1q_2 | q_1 \in Q_1 \land q_2 \in Q_2 \}$
>3. $q_0 = (q_1,q_2)$
>4. $F = \{ (r_1,r_2) \in Q | r_1 \in F_1 \lor r_2 \in F_2 \}$
>5. $\delta = ((r_1,r_2),a) = (\delta_1(r_1,a),\delta(r_2,a))$
>
>Visto che $\delta_1(r_1,a) \in Q_1$ e $\delta_2(r_2,a) \in Q_2$ avremo che $(\in Q_1, \in Q_2) \in Q$ 
>
>In pratica se uno dei due $M_1$ e $M_2$ accetta , accetterà anche $M$ ( li simulo simultaneamente ) 

>[!question] Perchè l'assunzione di $\sum_1 = \sum_2 = \sum$ non è limitante?
>
>Questa infatti è detta **assunzione senza perdita di generalità** , questo perchè possiamo ricondurci ad un altro *alfabeto* modificando il [[DFA]] :
>>[!example] 
>>![[DFA+pozzo.excalidraw]]
>>
>>Possiamo sempre aggiungere un nuovo nodo *pozzo* dove se trovo il nuovo carattere dell'alfabeto rifiuto sempre la stringa , in questo modo il [[Linguaggio DFA]] non cambia anche se abbiamo aggiunto un elemento a $\sum$

