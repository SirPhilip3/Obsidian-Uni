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
	2. Inizia un 
### Macchina a stati del ricevitore