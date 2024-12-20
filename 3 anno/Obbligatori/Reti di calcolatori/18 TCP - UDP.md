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

# TCP

## Performance