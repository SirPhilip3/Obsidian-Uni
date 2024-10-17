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
>Questa [[Context-Free Grammar|CFG]] è in *forma normale di Chomsky* poichè :
>+ Lo [[Start Symbol]] si espande in un massimo di due [[Simboli Non Terminali]] oppure in un $\epsilon$ ( regole $3$ e $1$ )
>+ $A,C,D$ si espandono tutti in [[Simboli Terminali]] ( regola $2$ )
>+ $B$ si espande in due [[Simboli Non Terminali]] ( regola $1$ )

Definiamo inoltre il seguente **Teorema** : 
>[!important] Teorema
>Per ogni [[Context-Free Grammar|CFG]] $G$ esiste una [[Context-Free Grammar|CFG]] $H$ in *forma normale di Chomsky* tale che $L(H)=L(G)$ 

