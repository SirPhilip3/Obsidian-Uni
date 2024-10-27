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

### Reliability

Non possiamo utilizzare un *id* da assegnare ad ogni *segment* poichè questo forza il *server* a manetere una coda di tutti gli *id ricevuti*

La *duplicazione* dei [[packet]] potrebbe dipendere da *loop* , visto che questi sono temporanei definimo la **Maximum Segment Life** ( **MSL** ) , questa indica il tempo massimo che un [[packet]] , ed eventualmente l'[[Acknowledgment]] relativo al [[packet]] , può persistere in una rete ( generalmente è 120s )

Ora quindi ci basta identificare un numero di sequenza *duplicato* all'interno dei 120 secondi 

Per generare gli *id* utilizziamo un **Transport Clock** : 
	Questo è un counter che viene gradulamente incrementato avanzando nel tempo 
>[!note] 
>Il *clock* non deve essere sincronizzato tra gli endpoint della connessione

Ogni *Connection Request* include un **Initial Sequence Number** ( **ISN** ) 

Questo è una funzione del *Transport Clock* , se aumenta il *timer* allora anche l'**ISN** aumenta 

Il *server* ritorna il *sequence number* all'interno del massaggio di **CA** ( **Connection Acknowledge** ) , quando il *client* lo riceve sa che è relativo alla connesione in corso basandosi sull'**ISN**

>[!important] 
>Visto che l'**ISN** deve essere incluso nell'*header* la sua dimensione deve essere limitata questo implica che con il tempo ritornerà a 0 

>[!warning] 
>E' importante quindi che il tempo necessario perchè l'**ISN** *wrappi* sia molto più grande dell'**MSL**


