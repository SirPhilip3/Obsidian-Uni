---
creation: 2024-11-06T11:02:00
publish: true
---
Una **MdT** *non deterministica* ha come funzione di transizione : 
$$\delta : Q \times \Gamma \to \mathcal{P}(Q \times \Gamma \times \{L,R\})$$
Ossia per ogni simbolo che legge la **MdT** può fare un insieme di mosse non solo una unica mossa 

>[!important] Teorema
>Ogni **MdT** *non deterministica* si può convertire in una **MdT** equivalente
>

>[!important] Dimostrazione
>>[!info] Idea
>>Rappresentiamo una computazione non deterministica come se fosse un albero di possibili computazioni
>>
>>![[MdTnonDetCompTree.excalidraw]]
>>
>>Descriviamo ogni possibile cammino con un *indirizzo* :  
>>$$11,12,21,31$$
>>Eseguiamo una computazione detereministica per ogni cammino , se ne troviamo uno che accetta entriamo nello stato accettante 
>>
>>>[!warning] 
>>>Se un cammino va in *loop* anche la computazione deterministica va in loop , la **MdT** non proverà nessun altro cammino
>>
>>Per risolvere questo problema facciamo una visita **BFS** dell'albero , esploreremo quindi i seguenti cammini : 
>>$$1,2,3,11,12,13,21,22,\dots$$ 
>
>Simuliamo una **MdT** *non deterministica* con una **MdT** *deterministica* avente 3 nastri : 
>1. Il *primo* nastro sarà *read-only* che contiene l'input iniziale
>2. Il *secondo* nastro sarà di *lavoro* ossia dove eseguo la computazione deterministica di ogni cammino sull'input del primo nastro
>3. Il *terzo* nastro contiene gli indirizzi , ossia tiene traccia di dove si trova l'**MdT** *deterministico* all'interno dell'albero delle computazioni
>
>L'**MdT** *deteministico* computerà nel seguente modo :
>1. Inizializza il primo nastro con l'input $w$ , il secondo e il terzo è vuoto
>2. Copiamo il primo nastro sul secondo
>3. Simuliamo una computazione *deterministica* sul secondo nastro risolvendo il *non determinismo* tramite l'indirizzo sul terzo nastro , se questa accetta entriamo in uno stato di *accept*
>4. Aggiorniamo il terzo nastro con il prossimo indirizzo secondo l'ordine menzionato ( lunghezza crescente ) e torniamo allo step 2 
>
>>[!note]
>>Se trovo un indirizzo che non corrisponde ad alcun cammino nell'albero diamo *reject*
