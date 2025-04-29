---
creation: 2024-10-02T09:44:00
publish: true
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
>La *regexp* è valida solo se le due parti della concatenazione sono delle *regexp* valide (regola 5): 
>1. $0 \cup 1$ : risulta essere valida se $0$ e $1$ sono delle *regexp* , lo sono visto che siamo nel caso base ( regola 1 )
>2. $0^*$ : è una *regexp* se $0$ è una *regexp* , lo è per la regola 1
>
>Possiamo concludere quindi che $(0 \cup 1)\ o\ 0^*$ è una *regexp* valida per la definizione

>[!important] Convenzioni
>
>+ L'operatore $o$ viene di solito omesso
>+ L'ordine delle operazioni è il seguente : 
>	1. $^*$
>	2. $o$
>	3. $\cup$

![[Linguaggio di una Regexp]]