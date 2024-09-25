---
creation: 2024-09-25T10:22:00
tags:
  - Definizione
---
Un *NFA* è una quintupla $(Q\, \sum,\ \delta,\ q_0,\ F)$ dove : 
+ $Q$ è un insieme finito di *stati*
+ $\sum$ è un *alfabeto* finito
+ $q_0$ è lo stato *iniziale* $\in Q$
+ $F \subseteq Q$ stati *accettanti* 
+ $\delta = Q \times(\sum\ \cup\ \{\epsilon\})\rightarrow P(Q)$ questo è un ![[powerset]]
	In pratica da uno stato di *partenza* e un elemento dell'alfabeto , incluso l'$\epsilon$ , possiamo avere un insieme di scelte che possiamo prendere come *stato* di arrivo
