---
creation: 2024-10-14T12:36:00
publish: true
---
Possiamo avere diverse tipologie di *network* :
+ ![[Full Mesh Network]]
+ ![[Bus Network]]
+ ![[Ring Network]]
+ ![[Start Network]]
+ ![[Tree Network]]

![[Bottleneck]]

Per evitare le *collisioni* vi sono diversi metodi : 
+ ![[FDMA]]
+ ![[TDMA]]
+ **CDMA**

>[!note] 
>Questi metodi possono essere combinati tra loro

Un ulteriore metodo è quello del *Random Access* : 
+ Il *terminale* tenta di inviare dati sempre , se una collisione avviene questa viene rilevata e il [[Frame]] viene re-inviato

Uno dei primi schemi *Random Access* è **ALHOA**

![[S-ALHOA]]

>[!example]
>![[Pasted image 20250102154459.png]]
>
>>[!note] 
>>Link con lo stesso colore utilizzano lo stesso mezzo fisico :
>>+ *rosso* : $B=20MHz$ , $M=8$ , [[TDMA]] con $3$ slot
>>+ *blue* : [[S-ALHOA]] con $B=20MHz$ e $M=16$
>>+ *verdi* : [[S-ALHOA]] con $B=5MHz$ e $M=8$
>>+ *neri* : non sono mai un [[Bottleneck]] 
>>
>>Assumiamo che i link siano perfetti ( [[Nyquist Theorem]] )
>
>1. Assumiamo che **C1** sia l'unico client che genera traffico , questo genera un **Constant Bit-Rate** ( **CBR** ) di $40Mb/s$ verso *Internet* , riesce **C1** ad inviare *tutto* il suo traffico ?
>
>Il network *rosso* ha capacità : $C_r = 2 \times 20 \times \log_2(8) = 120 Mb/s$ , visto che si sono $3$ stazioni allora il [[TDMA]] fornirà $40Mb/s$ per ogni *terminale*
>
>Il network *blu* ha capacità : $C_b = 2 \times 20 \times \log_2(16) = 160 Mb/s$ , [[S-ALHOA]] ha efficenza $1/e$ quando molti terminali sono collegati , ma inizialmente è solo **C1** a trasmettere
>
>Essendo che entrambe le reti supportano almeno $40Mb/s$ per *link* allora **C1** può trasmettere senza problemi
>
>2. Oltre a **C1** inizieranno a trasmettere anche i terminali da **C2** a **C20** con un **CBR** verso **R2** di $1Mb/s$ , riescono tutti i client ad inviare il proprio traffico ?
>
>Il traffico da **C2** a **C20** rimane sempre nel network *blu* , l'*efficenza* massima di [[S-ALHOA]] è : $\frac{160}{e} \approxeq 59 Mb/s$ 
>
>Il traffico generato da tutto il *network* è : $40 + 19 = 59Mb/s$ , [[S-ALHOA]] può trasmettere tutti i *frame*
>
>3. Ora da **C2** a **C20** invia **CBR** ad *Internet* , riescono tutti i client ad inviare i propri *frame* ?
>
>Notiamo che il traffico aggregato da **R2** ad **R1** è $59Mb/s$ , questo è maggiore di $40Mb/s$ supportata dal link tra **R2** ed **R1** , **R2** sarà costretto a droppare $19Mb/s$ di traffico , si è creato un [[Bottleneck]]
>
>4. **C1** genera $40Mb/s$ **CBR** a **C'1** , tutti gli altri terminali non generano traffico 
>
>Il link tra **C1-R2** ha una capacità di $59Mb/s$ , **R1-R2** e **R2-R3** hanno una capacità di $40Mb/s$ , questi non causano problemi 
>
>Il network *verde* ha una capacità di : $C_g = 2 \times 5 \times \log_2(8)=30Mb/s$
>
>Visto che solo **R3** sta trasmettendo l'efficenza è $100\%$ , questo però crea un [[Bottleneck]] 
>
>5. **C1** genera $3Mb/s$ di traffico **CBR** verso **C'1** , inoltre da **C'2** a **C'20** generano $1.42 Mb/s$ verso *Internet*, qual'è la comunicazione massima da **C1** a **C'1**
>
>Il network *verde* permette $C_g = \frac{30}{e} \simeq 11Mb/s$ con più terminali che trasmettono 
>
>Il *load totale* è : $1.42 \times 19 + 3 = 30$ , però solo $11Mb/s$ vengono inviati , se assumiamo che sono divisi tra tutti i *terminali* allora **C'1** riceve solo $\frac{11}{20} = 0.55Mb/s$ , il network *verde* è il [[Bottleneck]]
>
>6. Come prima però anche **R4** genera $30Mb/s$ verso *Internet* , riesce **R4** ad inviare tutto il traffico 
>
>Nel *link* **R3-R1** ci sono $11+30 Mb/s$  ma la capacità è solo $40Mb/s$ , **R4** perderà quindi dei *frame* , il network *rosso* diventa un [[Bottleneck]] 
>
>7. Come *6* ma da **C'2** a **C'20** generano $3Mb/s$ invece di $1.42$ , riesce **R4** a gestire tutto il traffico
>
>Il *load* totale sarà : $3\times 19 +3 = 60$ quindi $G=2$ e l'efficenza diminuisce a $2e^-2$ , il traffico verso l'esterno del network *verde* è quindi $30 \times 0.27 = 8 Mb/s$ , quindi **R3-R1** sarà $38Mb/s$ e **R4** può quindi inviare il suo traffico  
>

