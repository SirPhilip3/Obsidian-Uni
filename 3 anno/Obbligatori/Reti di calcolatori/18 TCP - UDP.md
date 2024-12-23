---
publish: true
creation: 2024-12-20T10:21:00
---
# Introduction

I protocolli di trasporto fanno affidamento sui servizi offerti dal [[07 Network Layer]] per funzionare , questo fornisce un servizio *connectionless* e permette ad un *host* di inviare pacchetti che contengano fino a `64Kb` di *payload* ad un qualsiasi altro *host* nella rete 

>[!note] 
>Il [[07 Network Layer]] non garantisce la consegna delle informazioni 
>Non può riconoscere errori di trasmissione e non preserva la sequenza dei pacchetti 

# User Datagram Protocol ( UDP )

**UDP** fornisce un servizio *unreliable* e *connectionless* al di sopra dei servizi di trasporto del [[07 Network Layer]] 

**Caratteristiche** : 
+ Massima dimensione per [[SDU]] : `65467` byte
+ Non garantisce la consegna degli [[SDU]]
+ Può fare *error detection* tramite *cecksum* 
>[!note] 
>Non può fare *error correction*

**UDP** permette di fare multiplexing ossia permette a varie applicazioni che runnano sulla macchina *host* di scambiarsi [[SDU]] con altre applicazioni in esecuzione su un *host* remoto

Per fare ciò ogni applicazione viene identificata da un numero di **porta**

>[!example] 
>![[Pasted image 20241220112050.png]]

### UDP Header

Un *header* **UDP** contiene 4 campi :
+ Una *porta* fonte di `16`bit
+ Una *porta* destinazione di `16`bit
+ Un campo lunghezza di `16`bit
+ Una [[CRC]] ( *checksum* ) di `16`bit

>[!note] 
>La *checksum* viene computata sugli *header* , un sottoinsieme dell'*header* di *IP* ( contenente anche gli indirizzi ) e il *payload*

### UDP Ports

Visto che il campo *porta* è grande `16`bit ci possono essere un massimo di `65535` differenti applicazioni in esecuzione contemporaneamente su un dato *server*

Generalmente questi indirizzi sono divisi in :
+ `1<port<1024` *porte* privilegiate , solo processi che hanno privilegi di amministratore possono usare queste porte
+ `1024<=port<49152` sono porte *registrate* , protocolli che usano queste *porte* dovrebbero chiedere alla *IETF* di assegnarli una determinata porta
+ Le restanti porte sono dette *effimere* , tutti possono usarle

### UDP Usage

**UDP** viene generalmente utilizzato per applicazioni che non necessitano di affidabilità e volgiono minimizzare la latenza

>[!example] 
>+ *VoIP* ( *Voice over IP* )
>+ *DNS*
>+ *QUIC* : un nuovo protocollo di trasporto incentrato su contenuti multimediali basato su *UDP*
# Transmission Control Protocol (TCP)

**TCP** fornisce un servizio di trasporto *affidabile* e *connection-oriented* 

>[!note] 
>In **TCP** ogni byte trasmesso corrisponde ad un **sequence number** 
>
>L'unità di dati in **TCP** è il *segmento*
## Segment Header

![[Pasted image 20241220115339.png]]

>[!note] 
>Visto che l'*header* ha parti fisse e parti opzionali non necessariamente avrà sempre la stessa dimensione

+ `16`bit di *Source* e *Destination port*
+ `32`bit per il numero di *sequenza* e *ack*
+ `4`bit per indicare la lunghezza dell'*header* ( **TCP** **Header Length** o *Data Offest* ) , questo indica la lunghezza dell'header in [[words]] di `32`bit ossia la lunghezza massima dell'*header* sarà `64`byte
+ `6`bit riservati -> usati per **ECN** ( **Explicit Congestion Notifications** )
+ **Flags** :
	+ `SYN` : Usato per iniziare una connessione
	+ `FIN` : Usato durante il rilascio di una connessione
	+ `RST` : Chiude la connessione in caso di problemi
	+ `ACK` : Indica che il campo *acknowledgment* è valido 
	+ `CWR` , `ECE` : usati per **ECN**
	+ `PSH` , `URG` : *Push* e *Urgent Pointer*
+ `window` : la dimensione della finestra di ricezione di colui che sta inviando il segmento ( `16`bit )
+ `checksum` : Checksum simile a quella usata in `IP` , che comprende tutto il segmento **TCP** e alcuni header **IP** ( tra cui l'indirizzo **IP** stesso ) ( `16`bit )

>[!note] 
>Dopo queste parti fisse ci possono essere delle estensioni 
#### PSH e Urgent Pointer

Colui che riceve i dati ha un buffer dove mantiene i dati ricevuti , notificherà l'applicazione di nuovi dati , questo però non è controllato da colui che li invia 

In certi casi vogliamo un comportamento controllato : 
+ `PSH` fa in modo che quando un *reciever* vede un segmento con `PSH` settato mandi tutto il contenuto del buffer all'applicazione
>[!note] 
>L'ordine di sequenza viene rispettato 

Se vogliamo invece che un pacchetto venga mandato immediatamente all'applicazione senza che venga messo in queue possiamo usare la flag `URG` e `Urgent Pointer` :
	Il reciever deve mandare i dati direttamente all'applicazione senza rispettare i *sequence numbers*

>[!note] 
>`URG` è deprecato e `PSH` non è quasi mai usato
## Connection Setup

![[Pasted image 20241221175020.png]]

>[!note] 
>La connessione deve essere iniziata in entrambi i versi 

>[!note] 
>L'*ack* che mandiamo dopo il pacchetto `SYN` è relativo al prossimo numero di sequenza poichè è quello che ci aspettiamo di ricevere la prossiama volta , ossia : ho ricevuto dati fino ad $x$ , ora mi aspetto $x+1$

## Connection Refusal

![[Pasted image 20241221175558.png]]

Il rifiuto della connessione può avvenire se per esempio non c'è un'applicazione in esecuzione a quella porta 

>[!note] 
>Per rifiutare la connessione mandiamo un pacchetto di `RST` 
>>[!important] 
>>Questo deve comunque rispettare i numeri di sequenza , altrimenti un attacante potrebbe mandare un pacchetto di `RST` che abbia un numero di sequenza all'interno della finestra anche se non valido
## TCP connection Macchina a Stati

![[Pasted image 20241221180456.png]]

>[!note] 
>+ "?" significa riceve
>+ "!" significa invia

>[!warning] 
>Se I due cercano di connettersi nello stesso istante alle *stesse porte* , ossia entrabi sono nello stato `SYN Sent` , se non ci fosse l'arco `?SYN / !SYN+ACK` questo rimarrebbe in *dealock* invece se riceviamo un `SYN` anche senza l'*ack* passiamo allo stato `SYN RCVD` da dove invieremo l'*ack* e la connessione diventerà *Established*

Per implementare una macchina a stati dobbiamo mantere uno stato all'interno dell'*host* , questo avviene attraverso il `TCB` ( `Transmission Control Block` ) , questo mantiene , per ogni connesione , delle informazioni usate per mantenere lo stato della connessione ( eg i *buffer di ricezione* e *invio* )
### SYN packet Options

`Maximum Segment Size (MSS)` , ogni *host* setta il suo valore alla lunghezza massima di segmento che può ricevere 

Normalmente questo è settato all'**MTU** della rete , il frame più grande supportato dal network del ricevente che non viene frammentato

>[!note] 
>La dimensione minima è `536`
>
>Il suo valore può essere diverso da rete a rete
## Connection Release

**TCP** supporta due tipologie di *connection release*
### Graceful Release

Una *Graceful Release* avviene quando ogni *host* può terminare la sua direzione di connessione dopo aver completato la trasmissione dei dati 

Questo avviene con un segmento `FIN` con numero di sequenza $x$ , ciò significa che ha finito di inviare tutti i dati , l'ultimo segmento valido è $x$ 

L'altro potrà comunque inviare i segmenti *persi* prima di $x$ , aspetterà quindi un `FIN` dall'altra parte

>[!note] 
>I segmenti `FIN` devono avere un *ack* 
### Abrupt Release

Una *Abrupt Release* avviene con un segmento con il flag `RST` settato , appena viene ricevuto o inviato il `TCB` viene eliminato

>[!note] 
>Per evitare `RST` ping-pong , un *host* **TCP** che riceve un segmento `RST` non può mai rispondervi con un'altro `RST`

### Connection Release Macchina a Stati

![[Pasted image 20241222174238.png]]

Lo stato *Time Wait* viene utilizzato per fare in modo di essere sicuri che ci sia arrivato l'*ack* per l'ultimo segmento `FIN` 

>[!note] 
>l'*RFC* dice che deve essere mantenuto per $2\times MSL$ ( 4 minuti ) , visto che questo potrebbe causare una grande occupazione di memoria questo generalmente viene ridotto a $60$ secondi
>>[!example] 
>> Se una connessione dura 1 minuto questa deve mantenere la `TCP` per altri 4 minuti , in questo modo $80\%$ del tempo di connessione sarebbe sprecato ad aspettare mantenendo occupata memoria che potrebbe essere allocata ad altre connessioni
## Reliable Transfer

Originariamente **TCP** utilizzava [[go-back-n]] con [[selective repeat]] usando solo *ack* comulativi 
### TCB ( Transfer Control Block )

Gli elementi mantenuti nel **TCB** che *non cambiano* mai sono :
+ L'*IP* locale , remoto e le relative porte 
+ *sending buffer* : un buffer che contiene tutti i dati che non hanno ricevuto un [[Acknowledgment|ack]] 
+ *receiving buffer* : un buffer che contiene tutti i dati ricevuti che non sono ancora stati inviati all'applicazione ( perchè o l'applicazione è troppo lenta a processarli o non sono stati ricevuti in sequenza ) 

Gli elementi che cambiano invece sono : 
+ Lo stato corrente della macchina a stati ( `SYN-Sent`,`SYN-Received`,`Established`) 
+ Il `maximum segment size` ( `MSS` )
+ `snd.nxt` : prossimo numero di sequenza in uscita
+ `snd.una` : ultimo numero di sequenza senza un [[Acknowledgment|ack]] presente nel *sending buffer*
+ `snd.wnd` : la dimensione ( in byte ) della *sending window* 
+ `rcv.nxt` : il numero di sequenza del prossimo byte che ci aspettiamo di ricevere 
+ `rcv.wnd` : la dimensione corrente della *recieve window* del destinatario
### Sending Data

Quando l'applicazione mette dei nuovi dati nel *sending buffer* il layer **TCP** : 
1. Controlla che il *sending buffer* non contenga più dati rispetto alla dimensione della *recieve window* dell'*host* remoto ( `rcv.wnd` )
2. Fino a *MSS* byte vengono messi nel payload di un segmento **TCP**
3. Il numero di sequenza del segmento è settato a `snd.nxt` e `snd.nxt` viene aumentato per la lunghezza del payload **TCP**
4. L'[[Acknowledgment|ack]] viene settato a `rcv.nxt` e il campo `window` del segmento **TCP** è computato in base allo spazio libero nel *receiving buffer* 

>[!note] 
>I dati vengono mantenuti temporaneamente nel *sending buffer* in caso questi debbano essere reinviati 
### Receiving Data

Quando un nuovo segmento arriva , questo può essere un [[Acknowledgment|ack]] :
+ imposta `rcv.wnd` al valore del campo `window` del segmento ricevuto 
+ compara l'[[Acknowledgment|ack]] con `snd.una`
+ I dati appena [[Acknowledgment|Acknowledged]] sono rimossi dal *sending buffer* e `snd.una` viene aggiornato 

Se invece è un pacchetto di dati :
+ Compara il numero di sequenza con `rcv.nxt`
+ Se sono gli stessi allora abbiamo ricevuto dei segmenti in sequenza , possiamo quindi inviarli all'applicazione e `rcv.nxt` viene aggiornato
+ Se il contenuto del *receiving buffer* contiene dati che possono essere inviati in sequenza all'applicazione allora `rcv.nxt` viene aggioranto di conseguenza
+ Il *payload* viene messo nel *receiving buffer*
+ Invia l'[[Acknowledgment|ack]] con la *window size* aggiornata

## TCP Implementation

### Sending Data 

#### Send ASAP

Idealmente appena il *sending buffer* non è vuoto possiamo mandare un segmento **TCP** 

Questo però spreca moltissimo spazio se consideriamo che la dimensione minima di un pacchetto è $40B$ ( $20IP + 20TCP$ ) , ciò significa che se mandiamo $1$ byte sprechiamo il $97\%$ dello spazio

>[!note] 
>Questo può essere desiderato nel caso di app real-time 
>>[!example] 
>>Remote shell
#### Wait until MSS to Send

In questo modo aspettiamo di riempire al massimo il *payload* per **TCP** prima di inviare dati , questo fa in modo che abbiamo massima efficenza 
 
Se l'applicazione produce dati ad un alto *throughput* questa è una buona decisione 

Se invece l'appllicazione ci mette molto tempo per riempire un buffer , i dati potrebbero aspettare molto tempo prima di essere inviati
#### Nagle Algorithm

L'*algoritmo di Nagle* è un *trade-off* tra le due precedenti techiche 

```pseudo
	\begin{algorithm}
	\caption{Nagle Algorithm}
	\begin{algorithmic}
	\If{ $len(data) >= MSS \land rcv.wnd >= MSS$}
		\State Invia un segmento di dimensione $MSS$
    \Else
	    \If{Ci sono dati un-acknowledged}
		    \State Metti i dati nel buffer finchè l'acknowledgment viene ricevuto
		\Else
			\State Manda un segmento $TCP$ contenente al massimo rcv.wnd dati
        \EndIf
    \EndIf
	\end{algorithmic}
	\end{algorithm}
```

`1-2` Controlla che la *reciever window* possa ricevere `MSS` dati , e che ne abbiamo abbastanza allora inviamo il segmento con `MSS` dati 

>[!note] 
>Se il *reciever* vuole rallentare l'invio di dati semplicemente diminuendo la dimensione della *window* in un pacchetto di [[Acknowledgment|ack]]
>

`3` Altrimenti i dati che ho da inviare o sono meno di `MSS` o la dimensione della *window* del reciever è piccola , a questo punto dobbiamo decidere se ha senso inviare quei dati 

`4-5` Se stiamo aspettando per [[Acknowledgment|ack]] di dati vecchi , aspetta per fare in modo che il buffer si riempia e quando l'[[Acknowledgment|ack]] viene ricevuto invia i dati 

`6-7` Altrimenti non ho inviato dati fin'ora , oppure sono stati tutti [[Acknowledgment|Acknowledged]] , allora posso mandare un piccolo segmento ma solo una volta per **RTT** ( **Round Trip Time** )   

>[!note] 
>Questo algoritmo fa in modo che sia più probabile che segementi più grandi vengano inviati 
>Questo però rendere **TCP** non adatto per *real-time traffic*
### Window Size

Essendo che il campo `window` è di `16`bit la dimensione massima della finestra sarà $2^{16}=65536B$ 

In pratica non possiamo mandare più di una finestra di dati per **RTT** , ciò significa che il *throughput* è limitato dall'**RTT**

|   RTT    | Maximum Throughput |
| :------: | :----------------: |
|  1 msec  |      524 Mbps      |
| 10 msec  |     52.4 Mbps      |
| 100 msec |     5.24 Mbps      |
| 500 msec |     1.05 Mbps      |
>[!note] 
>Questi numeri non soddisfano le velocità odierne

Per questo viene usata un'estensione di **TCP** , questa introduce un moltiplicatore per la dimensione della finestra 
>[!note] 
>La **TCP** *Window Scale Option* viene scambiata solo in pacchetti `SYN` e `SYN-ACK`
>

Questo è un numero compreso tra $0\le S \le 14$ , in questo modo la *receiving window* avrà dimensione `rcv.wnd`$\times 2^S$ , le velocità diventano quindi ( con $S=14$ )

|   RTT    | Maximum Throughput |
| :------: | :----------------: |
|  1 msec  |     8590 Gbps      |
| 10 msec  |      859 Gbps      |
| 100 msec |      86 Gbps       |
| 500 msec |      17 Gbps       |

### Retransmission Time Out ( RTO )

Idealmente l'**RTO** è leggermente più grande dell'**RTT** , se alla fine di un **RTT** l'[[Acknowledgment|ack]] non arriva allora dovremmo ritrasmettere i dati 

>[!note] 
>L'**RTT** dipende dal path che prende quel segmento , questo può variare molto 

>[!warning] 
>Misurare l'**RTT** è soggetto ad errori 
>>[!example] 
>>![[Pasted image 20241223170024.png]]
>>Se il timer scade e re-inviamo i dati ma poco dopo ci arriva l'[[Acknowledgment|ack]] per quei dati , quale **RTT** prendiamo in considerazione ? 

Una soluzione potrebbe essere quella di ignorare gli **RTT** relativi alla ritrasmissione 

>[!warning] 
>Non possiamo sapere a chi appartiene l'[[Acknowledgment|ack]] che ci arriva

#### TCP Timestamps

Questa è un'estensione di **TCP** , in ogni segmento **TCP** vengono aggiunte due *timestamp* :
+ *current*
+ L'ultima *timestamp* ricevuta dall'altro *host* 

Questo ci permette di identificare a che segmento appartiene un [[Acknowledgment|ack]] e calcolare l'**RTT** corretto

>[!example] 
>![[Pasted image 20241223171319.png]]

>[!note] 
>In reti molto veloci i numeri di sequenza potrebbero wrappare prima di **MSL** , se usiamo le *timestamp* l'ambiguità che si potrebbe creare viene subito risolta visto che anche se avremmo gli stessi numeri di sequenza la *timestamp* ci direbbe che il segmento è vecchio


#### RTT Smoothing

Visto che il valore dell'**RTT** varia molto vorremmo appiattirlo , per questo utilizziamo l'algoritmo di *Van Jacobson* 

Questo ha tre variabili : 
+ `rtt` : l'ultimo **RTT** misurato
+ `srtt` : il valore appiattito dell'**RTT** , inizialmente settato a `rtt`
+ `rttvar` : la deviazione stimata dal valore medio dell'**RTT** , inizializzato a `rtt/2`
+ `rto` : il retransmission timer



## Performance