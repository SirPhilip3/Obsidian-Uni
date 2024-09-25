---
creation: 2024-09-25T09:00:00
tags:
  - Definizione
aliases:
  - NFA
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




