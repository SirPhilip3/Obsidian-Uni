---
creation: 2024-09-22T18:32:00
tags:
  - Definizione
---
Sia $M = (Q\ , \sum \ , \delta \ , q_0\ , F\ )$ e $w = w_1 , w_2,\dots ,w_n$ la stringa tale che per ogni $\forall i \in [1,n] \ w_i \in \sum$ 
Diciamo che $M$ **accetta** $w$ se e solo se $\exists \ r_0 , r_1, \dots , r_n \in Q$ stati tali che :
1. $r_0 = q_0$
2. $r_n \in F$
3. $\forall i \in [0, n-1] : \delta(r_i , w_{i+1}) = r_{i+1}$

>[!example] 
>![[DFA_2.excalidraw]]
>
>Dimostriamo che *accetta* la seguente stringa : 101
>Visto che l'automa deve accettare la stringa dovremmo finire in uno stato *accettante* ( $q_1$ in questo caso )
>Eseguendo quindi l'automa avremo : 
>$$q_0 \rightarrow q_1 \rightarrow q_0 \rightarrow q_1$$
>>[!note] 
>>Notiamo che la sequenza degli stati è sempre più lunga di 1 rispetto all'input
>
>Che dimostra che l'automa accetta la stringa 101

