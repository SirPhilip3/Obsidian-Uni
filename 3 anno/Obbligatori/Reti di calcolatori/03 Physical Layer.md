---
creation: 2024-09-19T08:22:00
---
Innanzittutto diamo delle definizioni che ci permetteranno di comprendere meglio la gestione del segnale al livello fisico : 
+ ![[Bit-rate]]
+ ![[Attenuation]]
+ ![[Delay]]
>[!note] 
>Il [[Delay]] non influenza direttamente la velocità di trasmissione
+ ![[Noise]]
+ ![[SNR]]
+ ![[Sensitivity]]
+ ![[Syncronization]]
### Sending Signals

Per mandare segnali usiamo la ![[Modulazione]]
Nel nostro caso utilizzeremo ![[Frequency Modulation]]
>[!example] 
>Quale sarà il [[Bit-rate]] di una comunicazione ?
>+ Assumiamo che $f_p = 4$ ( ossia l'onda *portante* fa 4 oscillaizoni al secondo )
>+ La lunghezza di un *bit* è determinato da 4 oscillazioni ( questo è chiamato **simbolo** )
>+ Mandiamo un *simbolo* al secondo ( [[Baud rate]] )
>+ Essendo che ogni *simbolo* rappresenta un bit avremo che il [[Bit-rate]] sarà $1 \ b/s$ 

>[!important] 
>Il [[Bit-rate]] è dato dal [[Baud rate]] moltiplicato per il numero di bit per *simbolo*

Per aumentare il [[Bit-rate]] possiamo fare due cose : 
1. Ridurre la lunghezza di un *simbolo* ( aumentiamo il [[Baud rate]] )
2. Codificare più bit all'interno di ogni *simbolo*

#### 1. Ridurre la durata di un simbolo

#### 2. Codificare più di un bit per simbolo
