---
creation: 2024-09-25T09:00:00
tags:
  - Definizione
---
Iniziamo portando un esempio di [[02 Automi a stati finiti non-deterministici ( NFA )|NFA]] 

>[!example]
>![[NFA_1.excalidraw]]
>Notiamo 3 differenze rispetto ad un *DFA* :
>1. Lo stato $q_1$ ha 2 *archi* con la stessa etichetta ( più rami d'esecuzione )
>2. Uno stato può non avere tutti gli *output* ( $q_2$ non ha un arco con 1 )
>3. Esistono le **$\epsilon$-Transizioni** ( azioni spontanee che vengono svolte senza consumare un *input* )

Un [[02 Automi a stati finiti non-deterministici ( NFA )|NFA]] **accetta** una stringa quando esiste *almeno un* cammino d'esecuzione che la accetta 

>[!note] 
>In pratica un [[02 Automi a stati finiti non-deterministici ( NFA )|NFA]] simula l'esecuzione di più path concorrenti è come se venissero spawnati dei nuovi thread per ogni scelta che l'[[02 Automi a stati finiti non-deterministici ( NFA )|NFA]] deve fare

Facciamo un esempio di esecuzione :
>[!example] 
>*Input* : 0101
>
>L'esecuzione si presenta come un *albero di decisione* :
>![[NFA_decision.excalidraw]]
>
>Visto che abbiamo almeno un cammino *accettante* allora la stringa 0101 viene *accettata*

>[!note] 
>Ogni [[02 Automi a stati finiti non-deterministici ( NFA )|NFA]] può essere trasformato in un [[DFA]] equivalente

>[!example] 
>Scrivere un [[02 Automi a stati finiti non-deterministici ( NFA )|NFA]] per il linguaggio delle stringhe binarie contenenti un 1 nella terza posizione *dalla fine* ( 0100110 viene accettata ) 
>
>Possiamo dividere l'esecuzione in due parti quando troviamo un 1 :
>1. Quell'1 è inutile ( non è il terz-ultimo )
>2. Quell'1 è il terz-ultimo
>
![[NFA_third_last.excalidraw]]
>
>Nel caso della stringa 0100110 quando troviamo il primo 1 abbiamo due possibilità : 
>1. Passiamo a $q_2$ ma questo porterà ad arrivare in $q_4$ con ancora elementi nell'input e quindi quel path muore
>2. Rimaniamo in $q_1$ , questo porterà al secondo 1 dove la prima opzione porterà all'*accettazione* della stringa

>[!example] 
>Proviamo a tradurre il precedente [[02 Automi a stati finiti non-deterministici ( NFA )|NFA]] in un [[DFA]] :
>
>Necessitiamo di memorizzare gli ultimi 3 bit letti ( mi serviranno $2^3 = 8$ *stati* per coprire tutte le possibilità ) , quando avrò 100 , 110 , 101 , 111 decideremo se accettare o meno a seconda se troviamo altri caratteri dopo 
![[NFAtoDFA.excalidraw]]
>

>[!example] 
>Costruiamo un [[02 Automi a stati finiti non-deterministici ( NFA )|NFA]] che rappresenti strighe di soli 0 ( o $\emptyset$ ) di lunghezza pari o multiplo di 3
![[NFA_0.excalidraw]]

![[NFA]]

![[Linguaggio NFA]]

>[!example] 
>Scriviamo quindi la definizione del primo [[NFA]]
>
>![[NFA_1.excalidraw]]
>
>+ $Q = \{ q_1,q_2,q_3,q_4 \}$
>+ $\Sigma = \{0,1\}$ ( $\epsilon$ non fa parte del linguaggio )
>+ $q_0 = q_1$
>+ $F = \{q_4\}$ 
>+ $\delta$ :
>  
>  |   -   |        0        |        1        | $\epsilon$      |
| :---: | :-------------: | :-------------: | --------------- |
| $q_1$ |    $\{q_1\}$    |  $\{q_1,q_2\}$  | $\{\emptyset\}$ |
| $q_2$ |    $\{q_3\}$    | $\{\emptyset\}$ | $\{q_3\}$       |
| $q_3$ | $\{\emptyset\}$ |    $\{q_4\}$    | $\{\emptyset\}$ |
| $q_4$ |    $\{q_4\}$    |    $\{q_4\}$    | $\{\emptyset\}$ |

![[NFA to DFA]]

![[DFA to NFA]]

![[Linguaggio Regolare NFA]]

