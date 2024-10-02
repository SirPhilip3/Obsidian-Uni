---
creation: 2024-10-02T09:44:00
---
Le *espressioni regolari* ( *regexp* ) sono un formalismo per descrivere i [[Linguaggio Regolare NFA|Linguaggi Regolari]] 

>[!example] 
>$(0 \cup 1)\ o\ 0^*$ è una *espressione regolare* e si spiega nel seguente modo : 
>+ $0 \cup 1$ : scielta di un simbolo tra 0 e 1
>+ $o$ : concatena
>+ $0^*$ : quanti 0 vuoli ( anche nessuno )
>
>| ✓   | ✗   |
| --- | --- |
| 0   | 01  |
| 1   | 11  |
| 00  | 101 |
| 100 |     |

>[!example] 
>
>$(0 \cup 1)^*$ : rappresenta qualsiasi stringa binaria 

>[!important] Definizione Formale
>
>Sia $\Sigma$ un *alfabeto* , l'insieme delle *regexp* definite da $\Sigma$ è definito come segue : 
>1. Se $a \in \Sigma$  allora $a$ è una *regexp*
>2. $\epsilon$ ( stringa vuota ) è sempre una *regexp*
>3. $\emptyset$ è una *regexp*
>4. Se $R_1$ e $R_2$ sono *regexp* allora $R_1 \cup R_2$ è una *regexp*
>5. Se $R_1$ e $R_2$ sono *regexp* allora $R_1\ o\ R_2$ è una *regexp*
>6. Se $R$ è una *regexp* allora $R^*$ è una *regexp*
>   
>>[!note] 
>>Definizione per induzione dove 1,2,3 sono i casi base e 4,5,6 sono i casi induttivi

>[!example] 
>
>Dimostriamo formalmente che $(0 \cup 1)\ o\ 0^*$ è una *regexp*
>
>La *regexp* è valida solo se le due parti della 
