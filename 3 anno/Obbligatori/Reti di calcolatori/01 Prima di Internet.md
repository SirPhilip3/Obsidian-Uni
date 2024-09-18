---
creation: 2024-09-18T08:48:00
---
Inizialmente i network di comunicazione ( telefoni , telegrafi etcc ) erano![[Multiplexing| circuit-switched]] 
>[!danger] 
>Se necessitassimo di un circuito diretto tra ogni utente del network questo sarebbe estremamente complesso e costoso
>Se avessimo $n$ clienti avremmo bisogno di $n\cdot (n-1)/2$ cavi ( qursto tipo di network viene detto **Full mesh** )

Si inventò quindi lo ![[switching]]  

Gli switch possono essere composti per creare un ![[nework gerarchico]]

Visti i problemi del [[nework gerarchico]] si iniziò a realizzare un nuovo tipo di network basato sul ![[packet switching]]

>[!example] 
>Facciamo un esempio di [[packet switching]] per una chiamata :
>1. La voce viene tradotta da un segnale analogico ad un segnale digitale 
>2. I bit del segnale digitale sono raggruppati dal sistema operativo
>3. Ogni [[packet|pacchetto]] viene inviato al router di A
>4. Il router decide il primo *hop* che deve fare quel pacchetto 
>5. Il [[packet|pacchetto]] viene instradato in internet , non sapendo che strada verrà percorsa poichè le dicisioni vengono prese *hop per hop*
>6. I [[packet|pacchetti]] venongo decodificati e riprodotti dall'autoparlante di B
>   
>![[Pasted image 20240918103009.png]]

**Vantaggi** : 
+ Ogni *hop* potrebbe usare una differente tecnologia per trasportare i [[packet|pacchetti]] 
+ Qunado i dati sono resi digitali potrebbero portare qualsiasi tipo di informazione 
+ Il *routing* è **dinamico** ossia se c'è un fallimento in una parte della rete è possibile sciegliere un'altra strada ( se ce n'è una )
