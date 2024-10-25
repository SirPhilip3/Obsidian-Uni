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
>>[!example] 
>>![[Pasted image 20241025085427.png]]
>>
>>In questo caso la **CR** ( *Connection Request* ) viene mandata due volte 
>
>Non possiamo utilizzare un *id* da assegnare ad ogni *segment* poichè questo forza il *server* a manetere una coda di tutti gli *id ricevuti*
>
>La *duplicazione* dei [[packet]] potrebbe dipendere da *loop* , visto che questi sono temporanei definimo la **Maximum Segment Life** ( **MSL** ) , questa indica il tempo massimo che un [[packet]] , ed eventualmente l'[[Acknowledgment]] relativo al [[packet]] , può persistere in una rete ( generalmente è 120s )
>
>Ora quindi ci basta identificare un numero di sequenza *duplicato* all'interno dei 120 secondi 