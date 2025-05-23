---
creation: 2024-09-20T23:30:00
tags:
  - Definizione
  - Teorema
publish: true
---
Il teorema di *Shannon* introduce un limite alla capacità in $bit/s$ tenendo conto del [[Noise]] 

La capacità di un canale con [[Bandwidth]] $B$ che è affetto da [gaussian white nose](https://en.wikipedia.org/wiki/White_noise) è data da :
$$C_S = B \log_2\bigg(1+\frac{S}{N}\bigg)$$
Dove $S/N$ è l'[[SNR]] 

>[!note] 
>Possiamo comunicare anche se $S<N$ 

>[!note] 
>La capacità cresce lentamente a causa della funzione $\log_2$ che cresce molto più lentamente rispetto alla lineare

>[!note] 
>Questo limita la capacità di ricezione del **ricevutore** con un certo [[SNR]] , non limita la quantità di dati che il trasmettitore può inviare

