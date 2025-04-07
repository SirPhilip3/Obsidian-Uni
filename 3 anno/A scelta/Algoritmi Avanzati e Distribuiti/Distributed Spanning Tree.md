---
publish: true
---
>[!important] Spanning Tree Definition
>A *spanning tree* $T$ of a *graph* $G=(V,E)$ is an *acyclic* subgraph $T=(V,E')$ of $G$ where $E' \subset E$

# SHOUT Protocol

>[!important] Assumptions
>+ Singe *initiator* 
>+ Bidirectional link
>+ Total reliability
>+ Connected graph ( otherwise we can't find a *tree* )

1. *Initially* nobody will know what are the edges making up the *spanning tree* 
2. At the *end* of the algorithm every node $x$ will know what links ( of the ones that terminates on himself ) belong to the spanning tree

>[!info] Idea
>1. The *initiator* sends to his neighbours a *question* ( `Do you want to be my neighbour in the spanning tree?` )
>2. An *entity* that recieves a *question* will reply with a `Yes` only if it's the *first time* that they recieve the question , and they will also forward the question to all of it's neighbours , *otherwise* the it will reply `No` and will not forward the question
>3. An *entity* *terminates* when it has recieved a reply from all *neighbours* to which it asked the question

*States* $S=\{INITATOR,IDLE,ACTIVE,DONE\}$
*Sinit* = $\{INITIATOR,IDLE\}$
*Sterm* = $\{DONE\}$

```pseudo
\begin{algorithm}
\caption{SHOUT}
\begin{algorithmic}
\State INITIATOR
	\State $\quad$ Spontaneusly
		\State $\qquad$ root:= true
		\State $\qquad$ Tree-neighbours := \{\}
		\State $\qquad$ send(Q) to N(x)
		\State $\qquad$ counter := 0
		\State $\qquad$ become ACTIVE
\State IDLE
	\State $\quad$ receiving(Q)
		\State $\qquad$ root:= false
		\State $\qquad$ parent := sender
		\State $\qquad$ Tree-neighbours := \{sender\}
		\State $\qquad$ send(yes) to sender
		\State $\qquad$ counter:=1
		\If{counter= $|N(x)|$}
		\State become DONE
        \EndIf
\State ACTIVE 
\end{algorithmic}
\end{algorithm}
```
