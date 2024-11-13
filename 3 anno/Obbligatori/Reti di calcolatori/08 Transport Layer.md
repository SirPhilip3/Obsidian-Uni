---
creation: 2024-10-24T09:51:00
publish: true
---
Il [[Transport Layer]] deve fare delle assunzioni sul [[07 Network Layer|Network Layer]] ( quello che usiamo su internet è *connectionless* ( non viene formata una connessione formale tra due host ) e *unreliable* )  

Il [[07 Network Layer|Network Layer]] quindi : 
+ Può solo trasferire [[SDU]] di una dimensione limitata
+ Potrebbe *scartare* degli [[SDU]]
+ Potrebbe *corrompere* degli [[SDU]]
+ Potrebbe introdurre del *delay* , *riordinare* o *duplicare* [[SDU]]

L'[[Application Layer]] richiede che : 
+ **Rendere la consegna dei dati affidabile** ossia : 
	+ Assicurare che i dati arrivino corretti 
	+ Assicurare che il *ricevitore* possa riordinarle
	+ Assicurare che i *duplicati* vengano riconoscuti
+ Supporti il **Multiplexing** ossia : Il [[Transport Layer]] deve fare in modo che si possa distinguere flussi di dati provenienti da due diverse coppie *client-server* 

![[Client-Server Model]]

>[!note] 
>Le applicazioni non hanno nessuna conoscenza di [[packet]] , condividono semplicemente un **buffer** con il [[Transport Layer]] da dove prelevano e inseriscono dati , il [[Transport Layer]] semplicemente **Segmenta** i dati in arrivo dall'applicazione e li manda al [[07 Network Layer|Network Layer]] che li impacchetterà correttamente

Il [[Transport Layer]] offre due tipi di servizi : 
+ ![[Connectionless Service]]
+ ![[Connection-oriented Service]] 