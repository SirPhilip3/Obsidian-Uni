---
creation: 2024-09-20T23:17:00
tags:
  - Definizione
  - Teorema
publish: true
---
Avendo : 
+ $B$ : la [[Bandwidth]] che usiamo
+ $M$ : il numero di livelli che codifichiamo 

Allora il [[Bit-rate]] *massimo teoretico* sarà dato da : 
$$C = 2B\log_2(M)$$
>[!example] Example 1
>Usiamo un link con frequenze :
>+ minima : $2401 MHz$
>+ minima : $2441 MHz$
>
>$\implies B = 2.441.000.000 − 2.401.000.000 = 40.000.000$
>Usando un $M = 4$ avremo che il massimo [[Bit-rate]] sarà :
>
>$$C = 2B\log_2(4) = 4\cdot 40.000.000 \cdot 2 = 160 Mb/s$$

>[!example] Example 2
>
>Avendo lo stesso $B$ di prima e sapendo che il link deve supportare $300 Mb/s$ 
>Qual'è il numero minimo di livelli $M$ richiesti ?
>
>$$C = 2 \cdot 40.000.000 \log_2(M) > 300.000.000$$
>$$M > 2^{\frac{300}{80}}> 13.45$$
>
>Ma visto che $M$ deve essere la potenza di $2$ allora $M = 16$ 
>Quindi per avere $300Mb/s$ potremmo avere $320 Mb/s$ 
