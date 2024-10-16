---
creation: 2024-09-25T07:36:00
---
![[Time-sequence diagram ( TSD )]]

![[Framing]]

![[SDU]]

**Limitazioni**

>[!example] 
>Facciamo come esempio una video call , il *mittente* userà `DATA.req(SDU)` per inviare un chunk di video al layer inferiore per essere inviato
>
>Il *ricevitore* controllerà ( con un *busy loop* ) se vi sono dati da ricevere , chiamerà quindi `DATA.ind(SDU)` per inviare il chunk al layer superiore per essere decodificato e riprodotto 
>
>>[!warning] 
>>Se il *ricevitore* è lento a leggere i dati questo dovrà utilizzare un buffer per mantenere i chunk in memoria visto che al livello superiore non possono acettare altri chunk in quel momento 
>>
>>Questo buffer però potrebbe riempirsi e il *ricevitore* dovrà per forza ignorare alcuni chunk
>>
>>La soluzione sarebbe mandare un segnale al *sender* in modo che invii dati più lentamente

![[Acknowledgment]]

Possiamo definire un [[DFA]] che rappresenti il flusso di informazioni 

**Mittente** 

![[Pasted image 20241001102125.png]]

>[!note] Spiegazione
>+ All'inizio ( `start` ) la macchina aspetta che vi sia un [[SDU]] da inviare
>+ Una volta ricevuti i dati da inviare fa una `Data.req(SDU)` al livello inferiore , questo farà [[Bit Stuffing]] se necessario
>+ Una volta inviati i dati la macchina aspetta la ricezione di un [[Acknowledgment]]
>+ Una volta ricevuto l'[[Acknowledgment]] la macchina ritorna allo stato iniziale 

**Ricevitore**

![[Pasted image 20241001103347.png]]

>[!note] Spiegazione
>+ All'inizio ( `start` ) la macchina aspetta che vi sia un [[Frame]] di dati che può ricevere
>+ Il frame ricevuto da `recvd(D(SDU))` viene inviato ai livelli superiori da `Data.ind(SDU)`  
>+ I dati vengono processati dai livelli superiori ( siamo passati nel secondo stato )
>+ Una volta processati i dati viene inviato un [[Acknowledgment]] al *mittente*

## Gestione degli errori

### Error Detection 

Il modo più semplice per identificare gli *errori* sono i ![[Parity Bit]] 
Per controllare la *parità* al *ricevitore* assumendo che *odd parity* venga usata ci basterà controllare che il [[Frame]] ricevuto contenga un numero dispari di `1`

>[!example] 
>+ `111011011` viene ricevuto : *ok*
>+ `001100110` : *not ok*

Se *non* ci sono *errori* il *ricevitore* semplicemente rimuove il bit in più e invia il [[Frame]] agli strati superiori

Se invece c'è un errore il *ricevitore* potrebbe :
+ Mandare un segnale al *mittente* chiedendo di rimandare il [[Frame]]
+ Ignorare completamente il [[Frame]]

>[!note] 
>Il comportamento dipende dal design del [[DataLink Layer]]

![[CRC]]

![[Internet Checksum]]

