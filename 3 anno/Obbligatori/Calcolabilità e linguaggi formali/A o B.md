---
creation: 2024-09-25T08:55:00
tags:
  - Definizione
---
Dimostriamo che se $A$ e $B$ sono **Regolari** allora $A\ o\ B$ è *regolare*  

Ricordiamo come funziona la ![[Operazioni Regolari#^4445db]] 
Avremo quindi che dovremmo dimostrare che all'interno di una stringa $w = abbab$ per ogni possibile suddivisione in due ogni prima sottostringa $\in A$ e ogni seconda sottostringa $\in B$ 

La costruzione di un [[DFA]] che rispetti queste caratteristiche è molto complessa , per questo non possiamo procedere per **costruzione** ( si utilizzano gli [[02 Automi a stati finiti non-deterministici ( NFA )|NFA]] )

Utilizziamo quindi un [[NFA]] per provare tutti i possibili tagli

**Dimostrazione** costruttiva

Assumiamo che $A$ e $B$ siano [[Linguaggio Regolare NFA]] $\implies$ che esistino degli [[NFA]] $N_1$ e $N_2$ tale che $L(N_1) = A$ e $L(N_2) = B$ costruiamo un nuovo [[NFA]] $N$ tale che $L(N) = A\ o\ B$ 

>[!note] Idea
![[AoB.excalidraw]]
>
>Concateno $N_1$ a $N_2$ in modo che quando ho riconoscituo una stringa di $N_1$ continuo e accetto solamente se riconosco anche una stringa di $N_2$ , mi basterà collegare gli stati *accettanti* ( rendendoli non accettanti ) di $N_1$ con lo stato iniziale di $N_2$ attraverso $\epsilon$-transizioni 

Avendo quindi : 
+ $N_1 = (\ Q_1,\ \Sigma ,\ \delta_1 ,\ q_1 ,\ F_1\ )$
+ $N_2 = (\ Q_2,\ \Sigma ,\ \delta_2 ,\ q_2 ,\ F_2\ )$

Dovremo costruire : 
$$N = (\ Q,\ \Sigma ,\ \delta ,\ q_0 ,\ F\ )$$
Dove : 
+ $Q = Q_1 \cup Q_2$
+ $q_0 = q_1$
+ $F = F_2$ 
+ $$\delta = \begin{cases} 
	\delta_1(q,a) & \text{se} \ q \in Q_1 \land q \notin F_1 \\ 
	\delta_2(q,a) & \text{se} \ q \in Q_2 \\ 
	\delta_1(q,a) & \text{se} \ q \in F_1 \land a \neq \epsilon \ \text{(le loro eventuali transizioni $\epsilon$ non voglio toccarle)} \\ 
	\{q_2\} \cup \delta_1(q,a) & \text{se} \ q \in F_1 \land a = \epsilon \end{cases}$$
