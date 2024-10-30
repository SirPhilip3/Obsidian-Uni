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

>[!note] 
>I *numeri di sequenza* sono relativi ai **byte** non ai [[Frame]] 

Per questo il *reciever* deve mantenere un **buffer** visto che la quantità di dati che può ricevere non è conosciuta in precedenza ( non ho una [[Frame]] size )

Finchè il **buffer** ha spazio il *reciever* può mandare dati e via via che l'applicazione termina di processare i dati questi vengono rimossi dal **buffer** 

>[!important] 
>Gli [[Acknowledgment]] vengono mandati appena i dati vengono messi nel **buffer** non dopo che questi vengono processati

>[!warning] 
>In questo modo si perde la capacità di throttling , se l'applicazione è lenta a processare i dati il **buffer** potrebbe riempirsi e rifiutare nuovi dati
### Window Advertising

Il *reciever* aggiunge negli [[Acknowledgment]] anche la dimensione della sua *finestra di ricezione* 

Il *sender* manterrà due variabili : 
+ `swin` : la dimensione della sua *sending* window
+ `rwin` : la dimensione della *recieving* window ricevuta nell'[[Acknowledgment]] del *reciever*

In ogni momento il numero di segmenti **unacknowledged** non possono essere maggiori del `min(swin,rwin)`    

>[!example] 
>![[Pasted image 20241029161159.png]]

>[!note] 
>La dimensione della *window* può anche essere 0 , in questo caso il *receiver* è completamente sovraccarico , in questo caso il *sender* non invierà nulla finchè non riceverà un [[Acknowledgment]] con una dimensione *positiva* 
>>[!warning] 
>>Se viene perso questo [[Acknowledgment]] potremmo entrare in un deadlock
>
>Per questo il *sender* manda periodicamente dati vecchi in modo da forzare il *reciever* ad inviare degli [[Acknowledgment]] con la nuova *window size*
>

### Sequence Number Wrap

>[!error] 
>
>Consideriamo un *sequence number* di soli $2$ bit , questo wrapperà quando il counter arriva a $3$ 
>**B** sta usando *selective repeat* ( accetta dati out-of-order ma manda [[Acknowledgment]] comulativi )
>
>![[Pasted image 20241030090808.png]]
>
>**A** manda un [[packet]] con *numero di sequenza* $1$ , questo però ritarda ad arrivare a **B** 
>
>Nel frattempo riceve dati con *numero di sequenza* fino al $3$ , **B** però non avendo ricevuto ancora i dasti con numero di sequenza $1$ manda l'[[Acknowledgment]] `C(OK,0)` 
>
>**A** rimanda i dati con *numero di sequenza* = 1 , **B** muove quindi la finestra in avanti e manda un [[Acknowledgment]] per tutti i dati ricevuti con *numero di sequenza* fino al $3$
>
>Ora visto che il counter wrappa , **A** manda ulteriori dati con *numero di sequenza* = 0 , a questo punto vengono ricevuti i dati con [[Acknowledgment]] = 1 , questo verrrà accettato da **B** poichè correttamente si aspetta un *sequence number* = 1   
>>[!danger] 
>>Abbiamo accettato un [[packet]] duplicato , il data stream viene corrotto 

Dobbiamo quindi rifiutare tutti i pacchetti che arrivano oltre l'**MSL** , questo però diminuisce il **throughput** :

>[!warning] 
>Anche con *numeri di sequenza* molto grandi , se abbiamo un network molto veloce , questi vrapperano in un tempo molto minore dell'**MSL**

>[!example]
>Supponiamo di avere un network con velocità di $30Gb/s$  e i *sequence number* sono formati da $32$ bit , visto che ogni sequenza [[Acknowledgment|Ack's]] un byte allora il *sequence number* wrapperà ogni : 
>$$\frac{2^{32} \times 8}{30 \times 10^9} \simeq 1s$$
>Questo è molto minore dell'**MSL** 

Quando la capacità è molto alta i ritardi sono molto piccoli quindi l'**MSL** deve essere molto più basso ( nei protocolli moderni ogni [[Acknowledgment]] non indicizza un solo byte ma un multiplo di byte )

## Connection Release

Visto che i dati vengono trasmessi in entrambe le direzioni , entrambi gli *endpoint* devono essere al corrente che la connessione è stata terminata 
### Graceful Release

Entrambi gli *endpoint* mandano un [[packet]] di disconnessione , **DR** 

>[!note] 
In questo caso gli *endpoint* si assicurano di avere ricevuto tutti i dati correttamente prima di terminare la connessione 

![[Pasted image 20241030094345.png]]
### Abrupt Release

Avviene quando la chiusura della connessione è dettata da un evento esterno ( ex  shutdown dell'*endpoint* etcc ) , in questo i dati in transito al momento della disconnessione verranno persi 

![[Pasted image 20241030094702.png]]
