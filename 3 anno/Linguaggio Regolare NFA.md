---
creation: 2024-09-27T12:27:00
tags:
  - Corollario
  - Dimostrazione
---
>[!important] 
>Un [[Linguaggio Formale]] $A$ è **regolare** se e solo se esiste un [[NFA]] che lo riconosce

**Dimostrazione** 

Essendo un $\iff$ dobbiamo dimostrare i due versi del *corollario* : 
1. $\implies$ Sia $A$ *regolare* per definizione $\exists$ un [[DFA]] $D$ tale che $L(D) = A$ lo converto quindi in un [[NFA]] equivalente 
2. $\Longleftarrow$ Assumiamo che esiste un [[NFA]] $N$ tale che $L(N) = A$ converto quindi $N$ in un [[DFA]] equivalente e dimostro la regolarità ( [[Linguaggio Regolare DFA]] )