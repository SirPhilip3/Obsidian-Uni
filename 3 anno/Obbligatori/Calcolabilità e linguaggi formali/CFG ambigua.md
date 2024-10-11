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




