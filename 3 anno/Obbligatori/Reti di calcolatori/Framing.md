---
creation: 2024-09-25T12:06:00
tags:
  - Definizione
---
Un *frame* è l'unità base di informazione scambiata tra due host connessi direttamente 

>[!important] Definizione
>Un *frame* è una sequenza di bit che ha una lunghezza massima e una particolare *sintassi* o *struttura*

>[!question] 
>Come fa il ricevitore a capire che siamo all'inizio di un *frame* ? 

Inseriamo un *marker* ( sequenza ben definita di bit ex : ‘01111110’ ) alla fine ed inizio del frame ( detto *frame boundary marker* )

>[!warning] 
>Potrebbe accadere che all'interno dei dati racciusi dal *marker* sia presente la stessa sequenza , questo verrebbe interpretato come segnale di fine da parte del *reciever*
>

Una soluzione è il ![[Bit Stuffing]]