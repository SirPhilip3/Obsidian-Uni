---
creation: 2024-11-19T11:06:00
publish: true
---
In [[RSA]] le chiavi *pubbliche* e *private* possono essere invertite , ossia : 
+ Ciò che cifriamo con una chiave *privata* possiamo decrifrare con una chiave *pubblica* e viceversa

Quindi se **Alice** cifra un messaggio $M$ con la sua *private key* , tutti coloro che hanno la sua *public key* posso decifrarlo , in questo modo visto che solo **Alice** possiede la *public key* chiunque decifri il messaggio è sicuro che arrivi da **Alice**

Questo viene detta **Digital Signature**

Quando qualcosa è firmato con una **Digital Signature** è [[Non repudiation]] 
	Visto che il messaggio che ha ricevuto **Bob** poteva essere generato solo da **Alice** questa non può *negare* di esserne il mittente

>[!note] 
>
>**Digital signatures** hanno valore legale

>[!warning]
>
>L'attacco *MiTM* è ancora possibile , basta che **Eve** sostituisca la *public key* di **Bob** con la sua

