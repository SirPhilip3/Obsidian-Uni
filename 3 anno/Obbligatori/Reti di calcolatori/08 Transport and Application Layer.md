---
creation: 2024-10-24T09:51:00
---
Il [[Transport Layer]] deve fare delle assunzioni sul [[07 Network Layer|Network Layer]] ( quello che usiamo su internet è *connectionless* ( non viene formata una connessione formale tra due host ) e *unreliable* )  

Il [[07 Network Layer|Network Layer]] quindi : 
+ Può solo trasferire [[SDU]] di una dimensione limitata
+ Potrebbe *scartare* degli [[SDU]]
+ Potrebbe *corrompere* degli [[SDU]]
+ Potrebbe introdurre del *delay* , *riordinare* o *duplicare* [[SDU]]

L'[[Application Layer]] richiede che il [[07 Network Layer|Network Layer]] venga : 
+ **Reso affidabile** ossia : 
	+ Assicurare che i dati arrivino corretti 
	+ Assicurare che il *ricevitore* possa riordinarle
	+ Assicurare che i *duplicati* vengano riconoscuti