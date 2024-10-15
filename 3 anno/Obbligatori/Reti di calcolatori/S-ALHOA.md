---
creation: 2024-10-15T09:38:00
---
*Slotted* **ALHOA** ( algoritmo *ALHOA* dove i terminali devono essere sincronizzati e il tempo viene diviso in *slot* )

Quando un *host* deve inviare un [[Frame]] aspetta l'inizio del prossimo *slot* e lo trasmette , questo permette una certa probabilità di *collisione* , se questa avviene la trasmissione fallisce 

## Assunzioni 

+ Ci sono $m$ terminal *sincronizzati* che trasmettono ad un singolo *ricevitore* 
+ I terminali sanno l'inizio di ogni slot
+ Le trasmissioni sono sempre più corte del tempo fornito dallo slot
+ Due trasmissioni contemporanee fanno fallire la trasmissione , assumiamo che i *terminali* sanno del fallimento istantaneamente
+ Nel mondo reale il *ricevitore* ha uno slot dedicato in cui nessuno può trasmettere in cui invia gli [[Acknowledgment]] 
+ Se una collisione avviene il *mittente* non riceverà un'[[Acknowledgment]] e rileverà l'erroe con un qualche delay 

## Details

Chiamiamo $q_a$ la probabilità che un *terminale* abbia qualcosa da trasmettere 
Se un altro *terminale* vuole trasmettere nello stesso [[Frame]] , entrambi entrano in uno stato **Backlogged** , ciò vuol dire che questi ritrasmetteranno lo stesso [[Frame]] nel prossimo *slot* con una probabilità $q_b > q_a$