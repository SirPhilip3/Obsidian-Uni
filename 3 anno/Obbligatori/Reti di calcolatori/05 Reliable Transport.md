---
creation: 2024-10-02T09:38:00
publish: true
---
![[Ridondanza Tripla]]

>[!important] 
>Generalmente si assume che la rete funziona ragionevolmente bene , non è quindi convenienente sprecare troppe risorse per correggere o prevenire errori

## Errori nei data frame

Visto che sappiamo come trovare degli errori nei [[Frame]] da parte del *ricevitore* ( attraverso le [[Internet Checksum]] ) colui che manda il [[Frame]] basta che segua il seguente schema per evitare che non arrivino i [[Frame]] corretti : 
1. Invia il **Frame** 
2. Inizia un *timer* 
3. Se l'[[Acknowledgment]] non arriva entro il timer ri-inizia dal passo 1 

>[!warning] 
>Se però vi sono degli errori durante il trasporto dell'[[Acknowledgment]] e questo non viene recepito dal *sender* originale questo invierà di nuovo il [[Frame]] precedente anche se questo sarà una copia del precedente per il ricevitore

## Numeri di Sequenza

Viene aggiunto all'*header* del [[Frame]] un'ulteriore informazione : il **numero di sequenza** 

Questo ci permette di distinguere i [[Frame]] tra di loro 

Il metodo più semplice per implementarlo è l'utilizzo di un *singolo* bit che viene *invertito* ogni volta ( **Alternating Bit Protocol** , **ABP** )
>[!note] 
>Il [[Frame]] di [[Acknowledgment]] deve riportare a che numero di frequenza sta facendo riferimento

### Macchina a stati del mittente

![[Pasted image 20240925122810.png]]

1. Siamo nello stato iniziale in cui aspettiamo dei dati da inviare ( `Wait for D(0,..)` )
2. Alla presenza di dati `Data.req(SDU)` : 
	1. Manda i dati assieme al primo bit di sequenza `0` ( `send(D(0,SDU,CRC))` )
	2. Inizia un *timer* `start_timer()`
	3. Passa allo stato sucessivo
3. Siamo nello stato in cui aspettiamo un [[Acknowledgment]] che abbia come *bit* di sequenza `0` , abbiamo due possibilità :
	1. Se riceviamo un [[Acknowledgment]] con il bit di sequenza a  `1` ( `recvd(C(0K1))` ) o il *timer* finisce :
		1. Rimandiamo il [[Frame]] precedente `send(D(0,SDU,CRC))`
		2. Ri-iniziamo il *timer* `restart_timer()`
	2. Se riceviamo un [[Acknowledgment]] con bit di sequenza a `0` ( `recvd(C(OK0))` ):
		1. Cancelliamo il *timer* `cancel_timer()`
		2. Passiamo allo stato sucessivo
4. Aspettiamo che ci siano dei dati con [[Acknowledgment]] a `1` da inviare 
>[!note] Dopo questo il ciclo continua
### Macchina a stati del ricevitore

![[Pasted image 20241006172807.png]]

1. Il *ricevitore* inizia dallo stato in cui aspettiamo che arrivi un dato che abbia come numero di sequenza `0` 
	1. Se ricevo un [[Frame]] con numero di sequenza `1` e il [[Frame]] ha una [[Internet Checksum]] *corretta* rimango nello stesso stato
	2. Se ricevo un [[Frame]] con un numero di sequenza `0` e ha una [[Internet Checksum]] *corretta* passiamo al prossimo stato
2. Nello stato sucessivo processeremo i dati
3. Una volta processato il [[Frame]] mandiamo un [[Acknowledgment]] con numero di sequenza `0` 
4. Nello stato sucessivo aspetteremo un [[Frame]] con numero di sequenza `1` 
>[!note] Dopo questo il ciclo continua

>[!warning] 
>Se il *sender* e *reciever* non sono sincronizzati le due macchine vanno in loop e non c'è modo per re-sincronizzarle se non riavviando entrambe le macchine
## Performance

>[!example] 
>Assumiamo che abbiamo 20ms di *RTT* ( *round trip time* ) 
>Assumiamo che il [[Frame]] sia $1500B = 1500 \cdot 8 \text{bit}$ (grandezza standard di un [[packet]])
>Assumiamo che il link sia un gigabit : $10^9$ b/s
>Ci vorrà $\frac{1500 \cdot 8}{10^9} = 0.012 ms$ per inviare un [[Frame]]
>Un [[Frame]] di [[Acknowledgment]] è fatto di due bit ( uno per l'header e uno per il numero di sequenza ) , ci metteremo quindi $\frac{2}{10^9}ms$ , questo tempo è abbastanza basso per essere ignorato
>
>Il *TTL* sarà quindi : $20.024$ , il [[Bit-rate]] sarà quindi : $\frac{1500 \cdot 8}{0.020024} \simeq 0.6 Mb/s$

Questo è dato dal fatto che dobbiamo aspettare l'[[Acknowledgment]] per ogni singolo [[Frame]] , questo è una forma di [[Protocol Overhead]] introdotto per rendere la trasmissione affidabile 

>[!note] 
>L'*RTT* è limitato dalla velocità del mezzo che trasporta l'informazione

### Pipelining

Al posto di mandare un [[Frame]] alla volta mandiamo un insieme di [[packet]] senza aspettare un [[Acknowledgment]] per ogni pacchetto 

![[Pasted image 20241006215314.png]]

#### Sliding Window

I numeri di sequenza ora sono interi , i due devono mettersi daccordo sulla dimensione della finestra 

>[!example] 
>Abbiamo una finestra di grandezza 5 , ciò significa che il *sender* manderà 5 [[Frame]] e poi si fermerà 
>All'arrivo dei [[Frame]] il *reciever* invierà i relativi [[Acknowledgment]] , specifici per il numero di sequenza relativi 
>Quando il *sender* riceve gli [[Acknowledgment]] dei numeri più bassi della sequenza muove la finestra a destra in modo da inviare nuovi [[Frame]]
>
>![[Pasted image 20241006215947.png]]
>
>![[Pasted image 20241006220419.png]]
>

Per fare in modo che la finestra abbia numero finito di *numeri di sequenza* ci basterà definire i bit che vogliamo assegnagli $n$ allora il numero massimo di sequenza sarà : $2^n -1$ , quando arriviamo al numero massimo ci basterà ritornare all'inizio
#### Frame Loss

Come gestiamo la perdita di qualche [[Frame]] ?

>[!note] 
>Una politica che gestisce la perdita di [[Frame]] deve essere *veloce* , non importa se non è perfetta , questo perchè un server potrebbe dover gestire centinaia di migliaia di connessioni allo stesso tempo 

##### Go-back-n

###### Il Ricevitore

Accetta solo [[Frame]] che arrivano in sequenza , quelli *out-of-sequence* vengono scartati.

Il *ricevitore* ritorna sempre un [[Acknowledgment]] contenente il *numero di sequenza* dell'ultimo [[Frame]] *in sequenza* che ha ricevuto 

>[!note] 
>Gli [[Acknowledgment]] sono *comulativi* ossia questo indica che l'ultimo [[Frame]] e tutti i precedenti sono arrivati correttamente

Il *ricevitore* non ha buffer , conterrà solo due variabili : 
+ `lastack` : l'ultimo *numero di sequenza* che è stato [[Acknowledgment|Acknowledged]]
+ `next` : il prossimo numero di sequenza che si aspetta di ricevere

![[Pasted image 20241011145836.png]]
###### Il Mittente

Mantiene un *buffer* che può mantenere l'intera *finestra* 
1. I [[Frame]] vengono inviati con numeri di sequenza crescenti finchè il *buffer* non si riempie ( al primo [[Frame]] inviato si inizia un timer ) 
2. Il *mittente* aspetta quindi per un [[Acknowledgment]] prima di inviare altri [[Frame]]  
3. Quando il *mittente* riceve un [[Acknowledgment]] 
	1. Rimuove dal *buffer* tutti i [[Frame]] [[Acknowledgment|Acknowledged]] , visto che è comulativo
	2. Fa ripartire il timer solo se ci sono ancora [[Frame]] non [[Acknowledgment|Acknowledged]] nel suo *buffer*
4. Se il *timer* scade , il *mittente* assume che tutti i frame non [[Acknowledgment|Acknowledged]] sono persi e ritrasmette tutti i [[Frame]] nel *buffer* 

Avremo quindi le seguenti variabili :
+ `size(buffer)` : numero di [[Frame]] nel *buffer*
+ `seq` : l'ultimo numero di sequenza che è stato inviato
+ `unack` : il numero di sequenza dell'ultimo frame non ancora [[Acknowledgment|Acknowledged]] 
+ un *timer*

![[Pasted image 20241012114712.png]]

Facciamo un **esempio** : 
>[!example] 
>![[Pasted image 20241012115000.png]]
>
>**B** rifiuta tutti i [[Frame]] che hanno numero di sequenza sucessivo a 1 
>Dopo aver ricevuto $0$ come [[Acknowledgment]] **A** sposta la *finestra* oltre $0$ , quando il timer termina ( iniziato da $2$ ) **A** reinvia i dati dopo *a* 
>Ora visto che abbiamo uno spazio libero nella finestra mandiamo *d* 
>Quando arriva *e* per essere inviato la *finestra* è piena e quindi aspettiamo che si liberi e reinviamo

###### Dimensione massima della finestra

Abbiamo $n$ *bit* nell'header per il numero di sequenza , avremo quindi $2^n$ numeri possibili ma non possiamo utilizzarli tutti poichè :
+ A manda esattamente $2^n$ [[Frame]]
+ B li riceve , manda gli [[Acknowledgment|Ack]] e setta `next` a $0$
+ Tutti gli [[Acknowledgment|Ack]] vengono persi , A finisce il *timer* e rimanda tutti i [[Frame]] 
+ B li riceve tutti ma visto che `next` è settato a $0$ verrano accettati di nuovo e duplicati

Per risolvere il problema settiamo la grandezza massima della *finestra* a $2^n-1$

##### Limiti del Go-back-n

Quando ci sono troppi [[Frame]] *persi* : 
+ Il *ricevitore* non accetta [[Frame]] fuori sequenza anche se corretti  
+ Il *mittente* ritrasmette tutti i [[Frame]] prima dell'ultimo [[Acknowledgment]] anche se non necessario
#### Selective Repeat

Aggiungiamo un *buffer* anche per il *ricevitore* , questo accetta tutti i [[Frame]] finchè sono all'interno della *finestra* di invio 
In ogni [[Acknowledgment]] il *ricevitore* riporta :
+ L'ultimo numero di sequenza prima dell'inizio della *finestra*
+ Una lista di [[Frame]] inviati correttamente

![[Pasted image 20241014121549.png]]

Ogni volta che viene *inviato* un [[Frame]] si inizia un timer ( un timer per [[Frame]] ) 
Quando il *mittente* riceve un [[Acknowledgment]] rimuove tutti i timer dei precedenti [[Frame]] [[Acknowledgment|ACKed]] ,se possibile shifta la *finestra* a destra 

Quando un timer scade solo il [[Frame]] corrispondente viene reinviato

![[Pasted image 20241014121939.png]]

#### Real Protocols

Nel mondo real i dati non seguno mai una direzione singola , L'[[Acknowledgment|Ack]] non viene quindi inviato separatamente ma viene aggiunto nell'*header* del prossimo [[Frame]] ( **Piggybacking** )

Inoltre visto che facciamo *piggybacking* non mandiamo l'[[Acknowledgment|Ack]] subito immediatamente ma solo dopo che siano arrivati dei dati da mandare al *mittente* 

>[!note] 
>La dimensione della finestra dovrebbe essere negoziabile con tra i due in modo che cambi a seconda delle condizioni della rete

