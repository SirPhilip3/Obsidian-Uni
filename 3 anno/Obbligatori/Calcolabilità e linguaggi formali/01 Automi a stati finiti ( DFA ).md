---
creation: 2024-09-21T21:04:00
---
Un **DFA** ( *Deterministic Finite state Automa* ) è un ![[Modello computazionale]]
 Un *DFA* ha un una quantità finita di memoria , limitata dal numero di stati dell'automa

>[!example] 
>Comportametno di una porta automatica :
>+ Due stati : Chiuso ed Aperto 
>+ Input : Abbiamo 4 possibili imput che indicano la presenza di persone in parti del sistema : 
>	+ Fronte
>	+ Retro
>	+ Entrambi
>	+ Nessuno
>
>![[DFA_porta.excalidraw]]
>
>Dove le transizioni tra i vari stati sono rappresentate dalle frecce con lo stato del sensore relativo perchè avvenga la transizione

>[!warning] 
>Questo non è un *DFA* vero e proprio

Un esempio reale di *DFA* è il seguente : 

>[!example] 
![[First_DFA.excalidraw]]

Se alla fine della stringa di *input* sono in uno stato finale si dice che la stringa viene *accettata* altrimenti viene *rifiutata* 

>[!important] 
>L'insieme delle stringhe che vengono accettate si dicono il *linguaggio* del *DFA*

>[!example] 
>Per l'esempio precedente avremo :
>
|  I  |   -   |   0   |   1   |   1   |
| :-: | :---: | :---: | :---: | :---: |
|  q  | $q_1$ | $q_1$ | $q_2$ | $q_2$ |
>
>Visto che questa stringa finisce in $q_2$ allora verrà *accettata*
>
>
|  I  |   -   |   0   |   1   |   0   |
| :-: | :---: | :---: | :---: | :---: |
|  q  | $q_1$ | $q_1$ | $q_2$ | $q_3$ |
>
>Questa invece non finendo in $q_2$ ma in $q_3$ verrà *rifiutata*

![[DFA]]

>[!note] 
>Accettiamo le stringhe vuote $\iff$ $F = q_0$

>[!example] 
>Caratteriziamo formalmente il *DFA* precedente :
![[First_DFA.excalidraw]]
>
>$M_1 = (Q,\sum, \delta,q_0,F)$
>1. $Q = \{ q_1,q_2,q_3 \}$
>2. $\sum = \{0,1\}$
>3. $q_0 = q_1$
>4. $F = \{ q_2 \}$
>5. $\delta$ :
>
>|       |   0   |   1   |
| :---: | :---: | :---: |
| $q_1$ | $q_1$ | $q_2$ |
| $q_2$ | $q_3$ | $q_2$ |
| $q_3$ | $q_2$ | $q_2$ |

Avremo che $|Q| = n$ e $|\sum| = m$ e quindi abbiamo che $\delta$ dovrà essere $n\times m$ 

>[!example] 
>Proviamo a trovare il suo *linguaggio* 
>
>
| Stringhe accettate | Stringhe rifiutate |
| ------------------ | ------------------ |
| 1                  | 0                  |
| 11                 | 00                 |
| 1101               | 110                |
| 011                | $\emptyset$        |
| 01011              |                    |
>
>Possiamo quindi descrivere il linguaggio basandoci sugli esempi fatti precedentemente nel seguente modo ( in linguaggio naturale ) : 
>$L(D)$ : l'insieme delle stringhe con almeno un $1$ e dopo l'ultimo $1$ ha un numero pari di $0$

#todo Dimostrazione di correttezza

Ulteriori esempi di *DFA* e dei loro *linguaggi* :

>[!example] Example 1
>
>![[DFA_2.excalidraw]]
>
>
| Accettate | Rifiutate |
| --------- | --------- |
| 1         | 0         |
| 11        | 010       |
| 101       | 000       |
>
>In questo caso vengono utilizzati gli stati per memmorizzare l'ultimo bit letto dall'*input* , avremo allora che il linguaggio del [[DFA]] sarà 