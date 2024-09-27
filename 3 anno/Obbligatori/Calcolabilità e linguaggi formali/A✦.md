---
creation: 2024-09-27T13:31:00
tags:
  - Dimostrazione
---
*Dimostriamo* che se $A$ è **regolare** allora $A*$ è **regolare**

Sia $A$ **regolare** allora esiste un [[NFA]] tale che $L(N)=A$ ( [[Linguaggio Regolare NFA]] )

Anche in questo caso possiamo dimostrare la *regolarità* per *costruzione* :
Costruiamo un [[NFA]] $M$ tale che $L(M) = A*$ , come per [[A o B]] abbiamo che dovremmo controllare molti casi di divisione della stringa di *input* $w$

>[!note] Idea
![[A✦.excalidraw]]
>
>Ogni volta che troviamo una stringa in accettata da $A$ proviamo a matchare la rimanente parte della stringa
>Visto che la stringa vuota deve essere accettata dobbiamo aggiungere uno stato iniziale accettante 

