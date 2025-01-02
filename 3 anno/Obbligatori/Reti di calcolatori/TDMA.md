---
creation: 2024-10-15T09:11:00
publish: true
---
**TDMA** ( *Time-Division Multiple Access* ) 

Se un network ha $m$ terminali , il tempo viene diviso in $m$ *slot* di dimensione prefissata , con ogni *slot* assegnato ad *un* terminale 

Gli *slot* vengono ripetuti ciclicamente e quindi un terminale $i$ può trasmettere solo durante il [[Frame]] $i$

![[Pasted image 20241015091453.png]]

## Efficenza

Il **TDMA** è efficente a *saturazione* ( quando tutte le stazioni hanno qualcosa da trasmettere ) , ogni *slot* è occupato e non ci sono collisioni

>[!warning] 
>Generalmente quando siamo a *saturazione* della rete significa che c'è più traffico che vogliamo inviare rispetto alla quantità massima di traffico che possiamo inviare
>
>Ciò significa che generalmente vogliamo avere un network che raramente è congestionato , questo però ci fa perdere efficenza 

## Limitazioni

Ogni *terminale* avrà l'opportunità di trasmettere ogni $\frac{1}{m}$ *slot* 

>[!note] 
>Se un terminale $i$ ha un [[Frame]] da trasmettere a tempo $i+1$ dovrà aspettare tutto il ciclo prima di poter trasmettere anche se tutti gli altri terminali non hanno qualcosa da trasmettere   

## Use cases

Il *TDMA* essendo semplice da implementare e deterministico ( siamo sicuri che tutti gli host possono trasmettere qualcosa ad ogni ciclo )

Viene utilizzato in sistemi in cui si paga per il servizio e uno scheduling prefissato garantisce un servizio minimo a tutti gli utenti

>[!example] Esercizio
>
>Consideriamo un **TDMA** in cui :
>+ $b=100Mb/s$ [[Bit-rate]] 
>+ $n=5$ terminali 
>+ $s=1ms$ lunghezza di un singolo slot
>
>1. Massima quantità di dati che un *terminale* può inviare in uno *slot* ? 
>
>$$s \times b = 10^{-3} s \times 10^8 b/s = 100 kb$$
>
>2. Massima quantità di dati che un *terminale* può inviare in $1$ secondo ?
>
>Essendoci $5$ *terminali* ognuno avrà : $1000/5 = 200$ *slot* per secondo avremo quindi :
>$$10^5 \times 200 = 20.000.000 = 20 Mb/s$$
>
>3. Assumi che il *terminale* $1$ deve inviare $250kb$ quanto tempo $t$ ci mette per inviare il *frame* ( 3 risultati : *best* , *average* , *worst* )
>
>Se il *terminale* riceve il dato *prima* che il suo *slot* inizi :
>+ *best case* : $t = 10.5 ms$ ( il *frame* arriva poco prima che lo *slot* inizi )
>+ *worst case* : $t= 10.5 + 5 ms = 15.5 ms$ ( il *frame* arriva esatta dopo che lo *slot* inizia )
>+ *average case* : $t=10.5 + (5+0)/2 = 13 ms$
>

>[!note] 
>Il **TDMA** non arriverà *mai* alla [[Congestion Collapse]] anche se il network è *sovraccarico* 
>Questo perchè in qualsiasi caso garantiamo uno *slot* in cui trasmettere 
>
>La rete sarà quindi a *full efficency* ( anche se droppiamo dei [[Frame]] ) 

