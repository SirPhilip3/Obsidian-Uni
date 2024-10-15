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

>[!note] 
>$q_a$ dipende dal traffico mentre $q_b$ è un parametro del network

Un terminale nello stato **Backlogged** ritorna ad uno stato normale se riesce a ritrasmettere il [[Frame]] 

Se un *terminale* nello stato **Backogged** riceve degli altri dati da inviare li scarta

>[!example] 
>![[Pasted image 20241015102110.png]]
>
> 5/9 frame vengono trasmessi con successo

## Performance

Assumiamo che $G$ sia il carico del sistema ( il numero medio di [[Frame]] al secondo che vogliamo inviare in uno slot )
La probabilità di trasmettere correttamente un [[Frame]] sarà $P_s$ ( la probabilità di avere un solo [[Frame]] trasmettso in uno slot ) : $P_s=Ge^{-G}$ 

Quando $G=1$ il *network* è a saturazione , poichè non possiamo inviare più di un [[Frame]] per *slot* 

Ciò però significa che $P_s=1/e = 0.36$ ossia , in media , perdiamo il $64\%$ dei [[Frame]] 

Se aumentiamo il *carico* ( ossia aumento $G$ ) la probabilità di collisione aumenta e l'efficenza del link dimuisce fino as arrivare alla ![[Congestion Collapse]]