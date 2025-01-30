---
creation: 2024-10-16T10:18:00
publish: true
---
>[!example] 
>![[Pasted image 20241016101927.png]]
>
>Assumiamo che $A$ voglia mandare un [[packet]] a $B$ 
>
>1. $A$ manda il pacchetto alla sua unica interfaccia , l'header conterrà l'address della destinazione $B$  e l'address d'origine $A$ 
>2. Quando $R1$ riceve $A$ , $R1$ sa che può raggiungere $A$ attraverso la sua inerfaccia *West* , aggiorna di conseguenza la sua [[Forwarding Table]] ( $A \to West$ )
>3. Visto che $R1$ non ha una entry per $B$ manda il [[packet]] a tutte le sue interfacce ( tranne quella da cui ho ricevuto il *pacchetto* ) ( **Broadcast** )
>4. Quando $R2$ riceve un [[packet]] , aggiorna la sua [[Forwarding Table]] con una rotta $A \to West$ , e fa un **Broadcast**
>5. Il pacchetto arriva a $C$ ma non essendo la destinazione scarta il pacchetto . aggiornando la sua [[Forwarding Table]] con $A \to West$
>6. $R3$ riceve il pacchetto , aggiorna [[Forwarding Table]] con $A \to North-West$ e fa il **broadcast**
>7. $R4$ non fa nulla visto che il pacchetto di $A$ non ha come destinazione nessun address di $R4$ 
>8. $R5$ aggiorna la sua [[Forwarding Table]] e infine il pacchetto arriva a $B$

Alla fine di questo *broadcast* il [[packet]] è arrivato correttamente e tutti i *router* hanno una entry corretta per $A$

**Limiti** : 

Viene usato in piccoli network dove la rete è un *albero* altrimenti si creano dei **Loop** 

>[!warning] 
>![[Pasted image 20241016104939.png]]
> 
>$R1$ farà il *broadcast* a $R2$ e $R3$ 
>$R2$ *broadcast* a $R3$
>$R3$ *broadcast* a $B$ e $R1$ , $R1$ farà di nuovo il broadcast e il ciclo si riepterà , $B$ riceverà infinite copie del pacchetto originale

**Vantaggi** : 

Non utilizza nessun [[Control Plane Packets]] 