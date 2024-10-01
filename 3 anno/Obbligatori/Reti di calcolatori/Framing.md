---
creation: 2024-09-25T12:06:00
tags:
  - Definizione
---
![[Frame]]
>[!question] 
>Come fa il ricevitore a capire che siamo all'inizio di un *frame* ? 

Inseriamo un *marker* ( sequenza ben definita di bit ex : ‘01111110’ ) alla fine ed inizio del frame ( detto *frame boundary marker* )

>[!warning] 
>Potrebbe accadere che all'interno dei dati racciusi dal *marker* sia presente la stessa sequenza , questo verrebbe interpretato come segnale di fine da parte del *reciever*
>

Una soluzione è il ![[Bit Stuffing]]
![[Frame Preamble]]

Per semplificare la programmazione ai layer superiori aggiungiamo un *layer* in cui abbiamo un primitiva che invia [[Frame]] , non bit , in questo modo il livello inferiore si occuperà del [[Bit Stuffing]] e dell'aggiunta dei *marker*
