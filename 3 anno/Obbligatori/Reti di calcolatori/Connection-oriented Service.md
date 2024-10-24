---
creation: 2024-09-26T14:33:00
---
Il *Connection-oriented Service* crea una connessione tra un *client* e un *server* , questa connessione ha uno **stato** ( qualche variabile interna che vengono usate per tracciare l'evoluzione della connessione ) 

Prima di inviare dei dati necessitiamo quindi di *stabile* la connessione e quando abbiamo terminato di inviare dati dobbiamo *distruggere* la connessione

>[!note] 
>Il **Multiplexing** è implementato con le [[Porte]] come per il [[Connectionless Service]] 
## Establishing a Connection

Per stabilire la connessione ci basta uno scambio di [[packet]] tra i due *endpoint* 

>[!example] 
![[Pasted image 20241024151433.png]]

>[!warning] 
>I pacchetti potrebbero **Duplicarsi**

