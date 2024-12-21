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

## Performance