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
>
>Vediamo perchè con un esempio
>>[!example] 
>>
>>+ $t_0$ il *client* apre una connessione con $ISN=X$
>>+ $t_1$ la connessione termina
>>+ $t_2$ Il *client* apre una nuova connessione con $ISN=X+\Delta$ verso lo stesso *server* ,  svolgiamo $n$ operazioni che fanno wrappare l'**ISN** : $(X +\Delta)\%n = X$
>>+ $t_4$ il *client* riceve quindi un **CA** *acknoledging* $X$ , questo però è ugale alla prima connessione , si riferisce a questa o alla vecchia ? 
>>
>

Possiamo quindi avere due casi :
+ Assumiamo che il tempo di *wrap* dell'**ISN** sia molto grande rispetto all'**MSL** allora non è possibile che il **CA** wrappato si riferisca alla vecchia connessione
>[!fail] 
>+ Il tempo di *wrapping* è comparabile con **MSL** e quindi potrebbe essere che il **CA** sia una copia della prima connessione

### Two-way communication

Generalmente vogliamo una comunicazione bidiriezionale tra i due *host*

Abbiamo bisogno quindi di due *numeri di sequenza* , uno per ogni direzione della connessione 
>[!note] 
>Anche il *server* dovrà generare un **ISN** ed inviarlo al *client*
#### Three Way Handshake

![[Pasted image 20241029130213.png]]

1. **A** manda una **CR** a **B** con un *port number* e un *sequence number* $x$
2. **B** processa la richiesta e crea uno stato per la connessione ( aspetta per il **CA** da parte di **A** ) , ritorna un **CA** contente il suo *sqeuence number* e un [[Acknowledgment]] per il *sequence number* $x$ inviato prima da **A**
>[!note] 
>La connessione non è ancora stata stabilita
1. **A** riceve il **CA** e conferma l'[[Acknowledgment]] mandato da **B** , ora per **A** è stata stabilita la connessione , prima di mandare dati deve però fare l'[[Acknowledgment]] del **CA** contenente *sequence number* $y$ mandato da **B** , invia quindi un **CA** con come *numero di sequenza* iniziale $x$   
2. **B** riceve il **CA** e considera anchesso la connessione come stabilita ( adesso è sicuro che la **CR** iniziale non era duplicata ) , ora le sue comunicazioni inizieranno con numero di sequenza $y$
## Reliable Data Transfer

Visto che abbiamo i *sequence number* possiamo utilizzare i metodi visti in precedenza per garantire integrità dei dati : **Checksum** , **go-back-n** , **selective repeat**

Ci sono però delle differenze : 