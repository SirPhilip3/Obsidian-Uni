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
**Ricevitore**