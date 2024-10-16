---
creation: 2024-10-16T11:26:00
---
I [[Context-Free Grammar|CFG]] in *forma normale di chomsky* sono una sottoclasse dei [[Context-Free Grammar|CFG]]

>[!note] Definizione
>Una [[Context-Free Grammar|CFG]] è una *forma normale di chomsky* se e solo se ognuna delle sue [[Produzioni]] è in uno di questi formati : 
>1. $A \to BC$ , dove $B$ e $C$ *non* sono lo [[Start Symbol]] 
>2. $A \to a$ , dove $a$ è un [[Simboli Terminali]]
>3. $S \to \epsilon$ , dove $S$ è lo [[Start Symbol]] 

>[!example] 
>```pseudo
>\begin{algorithm}
>\begin{algorithmic}
>\State $S \to AB|\epsilon$ 
>\State $A \to 0$
>\State $B \to CD$
>\State $C \to 1$
>\State $D \to 1$
>\end{algorithmic}
>\end{algorithm}
>```
>
>Questa [[Context-Free Grammar|CFG]] è in *forma normale di chomsky* 