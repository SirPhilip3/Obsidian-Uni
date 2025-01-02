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
>4. 
>

