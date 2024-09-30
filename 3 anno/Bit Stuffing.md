---
creation: 2024-09-30T12:49:00
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


 