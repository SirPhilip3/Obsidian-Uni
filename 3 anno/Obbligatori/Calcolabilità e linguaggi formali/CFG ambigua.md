---
creation: 2024-10-11T12:11:00
---
Una [[Context-Free Grammar|CFG]] $G$ si dice *ambigua* se e solo se esiste $w\in L(G)$ tale che $w$ ha almeno due [[Albero di Parsing]] differenti

>[!example] 
>```pseudo
>\begin{algorithm}
>\begin{algorithmic}
>\State $E \to E + E | E \times E|a$
>\end{algorithmic}
>\end{algorithm}
>```
>Se abbiamo la seguente stringa : $a+a\times a \in L(G)$ questa può formare due [[Albero di Parsing]] differenti : 
![[ParseTree_ambiguity.excalidraw]]

>[!failure] 
>Una definizione **sbagliata** di *ambiguità* è la seguente : 
>Una [[Context-Free Grammar|CFG]] $G$ si dice *ambigua* se e solo se esiste $w\in L(G)$ tale che $w$ ha almeno due [[Derivazione|Derivazioni]] differenti
>
>Possiamo trovare il seguente *controesempio* : 
>```pseudo
>\begin{algorithm}
>\begin{algorithmic}
>\State $S \to AB$
>\State $A \to a$
>\State $B \to b$
>\end{algorithmic}
>\end{algorithm}
>```
>
>Per questa [[Context-Free Grammar|CFG]] avremo il seguente [[Albero di Parsing]] :
![[CFG_notAmb.excalidraw]]
>
>Avremo quindi che non è *ambigua* ma allo stesso tempo avremo due [[Derivazione|Derivazioni]] differenti : 
>+ $S \to AB \to aB \to ab$
>+ $S \to AB \to Ab \to ab$
>

Una definizione equivalente sarebbe : 
>[!check] 
>Una [[Context-Free Grammar|CFG]] $G$ si dice *ambigua* se e solo se esiste $w\in L(G)$ tale che $w$ ha almeno due [[Derivazione|Derivazioni]] *"a sinistra"* / *"a destra"* ( ossia che riscrive sempre i [[Simboli Non Terminali]] più a *sinistra* o *destra* ) differenti

