---
creation: 2024-10-02T09:38:00
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
>Quando il *sender* riceve gli [[Acknowledgment]] dei numeri più bassi della seqeunza muove la finestra a destra in modo da inviare nuovi [[Frame]]
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