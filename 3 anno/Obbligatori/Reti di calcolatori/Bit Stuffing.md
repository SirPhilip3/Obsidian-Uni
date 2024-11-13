---
creation: 2024-09-30T12:49:00
publish: true
---
Inseriremo un bit addizionale ogni volta che troviamo una sequenza simile al *frame* 

>[!example]
>*Encoding* 
>Avendo un *marker* di 01111110 inseriremo uno 0 addizionale all'interno della parte contenente i dati dopo ogni sequenza di 11111 ( 5 uni )  
>
>*Decoding*
>Il ricevitore se incontra uno 0 dopo 5 uni , all'interno del *data frame* , questo 0 verrà eleminato
>>[!important] 
>>Lo 0 **deve** essere stato inserito dal mittente altrimenti si corrompe il *frame*
>
>| Original frame            | Trasmitted frame                                       |
| ------------------------- | ------------------------------------------------------ |
| 0001001001001001001000011 | *01111110*0001001001001001001000011*01111110*          |
| 0110111111111111111110010 | *01111110*011011111*0*11111*0*11111*0*110010*01111110* |
| 0111110                   | *01111110*011111*0*0*01111110*                         |
| 01111110                  | *01111110*011111*0*10*01111110*                        |

Questo aumenta il ![[Protocol Overhead]] 
In ogni caso avremo un *overhead* costante di 2 byte per i *marker*

Il numero di bit che aggiungeremo dipenderà se parliamo di : 
+ **Worst Case** :
	Abbiamo che i dati saranno tutti 1 , ciò significa che ogni 5 bit dovremmo inserire uno 0 aggiuntivo che non porta informazione e verrà eliminato dal ricevitore 
	In questo caso perderemo $1/6$ del [[Bit-rate]] originale
+ **Average Case** :
	Assumiamo che la probabilità di avere un 0 o 1 sia una variabile di [[Bernulli]] con $p=0.5$ 
	La probabilità quindi di avere 5 uni consecutivi sarà : $\frac{1}{2^5} = \frac{1}{32}$ quindi in media avremo che circa il $3\%$ della capacità viene persa 

>[!example] 
>Calcoliamo l'overhead medio per un *frame* :
>+ Tramettiamo sempre frame di 64 bit
>+ Assumiamo che il *marker* è : 011110
>
>Ogni 64 bit dovremmo aggiungere $6 \cdot 2 = 12$ bit per i *maker*
>Ogni 3 bit dovremo avere aggiungere uno zero , questo avviene con una probabilità di $1/8$
>All'interno di una stringa di 64 bit avremo 62 sottostringe possibili di 3 bit quindi alla fine avremo una media di $\frac{62}{8} \sim 8$ bit di overhead 
>Sommati ai 12 bit del *marker* avremo 20 bit di overhead : $20/64 \sim 23\%$ della capacità viene persa
>

>[!note] 
>Più grandi sono i *marker* più l'overhead fisso aumenta , ma più lo rimpicciolisco più sarà la probabilità di dover usare bit di *stuffing* 
>
>Quindi generalmente è meglio avere grandi *marker* e avere grandi frame in modo da compensare l'overhead fisso dei *marker* 

>[!example] 
>Abbiamo un *link* con i seguenti parametri : 
>+ *marker* di lunghezza 6
>+ $B = 20MHz$
>+ $M = 16$
>+ $S/N = 222$ [[SNR]] 
>  
>Qual'è la probabilità che l'intero frame venga perso ?
>
>Perchè ciò avvenga il *reciever* non deve riuscire a trovare l'inizio o la fine del frame 
>
>+ La legge di [[Shannon Theorem|Shannon]] ci dice che $C_S = B \log_2(1+222) \simeq 156 Mb/s$
>+ [[Nyquist Theorem|Nyquist]] ci dice che stiamo trasmettendo $C_N = 2 \times 20 \log_2(16) = 160 Mb/s > C_S$
>+ Ciò significa che in media avremo $4 Mb/s$ di dati contengono errori : $BER = \frac{4}{160} = 0.025$ 
>+ La probabilità di ricevere 12 bit ( i due *marker* ) in modo corretto è : $p = (1-0.025)^12 \simeq 0.74$ 
>>[!warning] 
>>Ciò significa che con un [[BER]] di solo 2.5% il 26% dei *frame* verrà perso 

>[!note] 
>Lo *stuffing* può essere fatto anche per altre dimensioni di dati : byte , caratteri etcc