---
creation: 2024-11-19T08:37:00
publish: true
---
>[!important] Teorema
>
>Esistono dei linguaggi che *non* sono [[Touring Riconoscibili]] 

>[!important] Dimostrazione
>
>Sfruttiamo l'osservazione sulla [[Cardinalità]] , ossia dimostriamo che vi sono più linguaggi che [[08 Macchine di Touring|Macchine di Touring]] 
>
>1. *Dimostriamo* che l'insieme delle **MdT** è [[Insieme Numerabile|Numerabile]] 
>
>Osserviamo che l'insieme delle stringhe costruite su un qualsiasi alfabeto $\Sigma$ finito è un [[Insieme Numerabile]] 
>
>>[!example] 
>>
>>Per $\Sigma = \{0,1\}$ avremo : 
>>
>>| 1          | 2   | 3   | 4   | 5   | 6   | 7   | 8   | $\dots$ |
>>| ---------- | --- | --- | --- | --- | --- | --- | --- | ------- |
>>| $\epsilon$ | 0   | 1   | 00  | 01  | 10  | 11  | 000 | $\dots$ |
>>
>>Possiamo infatti notare che la funzione di traduzione ( enumerazione per lunghezza della stringa ) è [[Iniettività|Iniettiva]] e [[Suriettività|Suriettiva]]
>
>Qualiasi [[08 Macchine di Touring|MdT]] $(Q , \Sigma , \Gamma, \delta , q_0 , q_{accept} , q_{q_reject})$ è rappresentabile come una stringa , visto che le stringhe sono numerabili anche le [[08 Macchine di Touring|MdT]] sono numerabili 
>
>2. *Dimostriamo* che l'insieme dei linguaggi non è [[Insieme Numerabile|Numerabile]]
>
>Osserviamo che qualsiasi linguaggio si può rappresentare come una stirnga bianaria infinita 
>>[!example] 
>>Dato il seguente linguaggio : 
>>$L = \{0,00,01\}$
>>
>>Possiamo creare tutte le stringhe creabili con l'alfabeto di $L$ , ossia $\{0,1\}$ e assegnare $0$ se esiste nel linguaggio $L$ $1$ altrimenti 
>>
>>
>>| $\epsilon$ | 0   | 1   | 00  | 01  | 10  | 11  | $\dots$ |
>>| ---------- | --- | --- | --- | --- | --- | --- | ------- |
>>| 0          | 1   | 0   | 1   | 1   | 0   | 0   | $\dots$ |
>>
>
>Osserviamo che l'insieme delle stinghe binarie non è [[Insieme Numerabile|Numerabile]] ( per *diagonalizzazione* )
>
>>[!important] Dimostrazione 
>>
>>Assumiamo *per assurdo* che l'insieme delle stringhe binarie sia [[Insieme Numerabile|Numerabile]] 
>>
>>| 1     | $00100\dots$ |
>>| ----- | ------------ |
>>| **2** | $01100\dots$ |
>>| **3** | $10001\dots$ |
>>| **4** | $01101\dots$ |
>>| **5** | $11111\dots$ |
>>
>>Possiamo costruire una stringa binaria infinita diversa da tutte semplicemente invertendo l'$i$-esimo bit : $10110\dots$  







