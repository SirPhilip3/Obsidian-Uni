---
creation: 2024-09-20T11:42:00
tags:
  - Definizione
---
Nella *[[Modulazione]] di frequenza* abbiamo :
+ Il segnale *portante* $p(t) = A \cos(2\pi\cdot f_p\cdot t)$ 
+ Il segnale *modulante* digitale $m(t)$

Avendo questi due segnali li moduleremo aumentando la *frequenza* del segnale *portante* di un certo $\Delta$ in modo da comunicare un segnale binario usando due *frequenze* del segnale *portante*
$$\begin{cases}
f'_p = f_p & \text{if} \ \ m(t) = 0\\
f'_p = f_p(1+\Delta) & \text{if} \ \ m(t) = 1
\end{cases}$$
>[!example] 
>![[Pasted image 20240920114912.png]]

Il *portante* può essere generato tramite :
+ Generatore di corrente alternata ( per le reti cablate )
+ Un'onda elettromagnetica ( per le reti wireless )

