---
creation: 2024-10-10T09:42:00
aliases:
  - CFG
publish: true
---
Facciamo un sempio di *Context-Free Grammar* o **CFG**
>[!example] 
>```pseudo
>	\begin{algorithm}
>	\begin{algorithmic}
>	\State $A \to 0A1 | B$
>	\State $B \to \#$
>	\end{algorithmic}
>	\end{algorithm}
>```
>Questo significa : 
>+ $A$ possiamo riscriverlo come $0A1$ *oppure* $B$
>+ $B$ possiamo riscriverlo come $\#$
>
>Questo sono dette [[Produzioni]] o [[Produzioni|Regole]]
>

![[Start Symbol]]

I *simboli* possono essere divisi in due **classi**

![[Simboli Non Terminali]]
![[Simboli Terminali]]

![[Derivazione]]

Una [[Derivazione]] può anche essere rappresentata da un ![[Albero di Parsing]]

Possiamo notare che il [[Linguaggio Formale]] dell'esempio iniziale può essere scritto nel seguente modo : 
$$L(G)=\{ 0^n\#1^n\ | \ n\ge 0 \}$$
>[!note] 
>Questo *linguaggio* non è *regolare* , esso infatti è molto simile a $0^n1^n$ che non è regolare ( vedi [[04 Linguaggi Non Regolari#^ddb1cb|esempio]] )

>[!important] 
>Una [[Context-Free Grammar|CFG]] è più espressiva di [[DFA]] , [[NFA]] o [[Linguaggio di una Regexp|regexp]] 

>[!important] Definizione
>Un **CFG** è una *quadrupla* $(V,\Sigma,R,S)$ dove : 
>+ $V$ : è un insieme finito di [[Simboli Non Terminali]]
>+ $\Sigma$ : è un insieme finito di [[Simboli Terminali]] tale che $V \cap \Sigma = \emptyset$
>+ $R$ : è un insieme finito di [[Produzioni]] della forma : 
>	$A \to w$ dove $A\in V$ e $w \in (V \cup \Sigma)^*$ ( tutte le stringhe formate da $V$ e $\Sigma$ , compreso $\epsilon$ )
>+ $S \in V$ : è lo [[Start Symbol]] 

>[!example] 
>Riprendendo l'esempio iniziale possiamo scriverlo nel seguente modo : 
>+ $V = \{A,B\}$
>+ $\Sigma = \{0,1,\#\}$
>+ $R = \{A \to 0A1\ |\ B , B \to \#\}$
>+ $S=\{A\}$

