---
creation: 2024-10-15T09:11:00
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
>

