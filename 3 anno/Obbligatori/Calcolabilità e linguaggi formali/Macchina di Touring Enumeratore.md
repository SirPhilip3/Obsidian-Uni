---
creation: 2024-11-06T11:55:00
---
Un **Enumeratore** ( generatore ) è una **MdT** a cui attachiamo una *stampante*

Un **Enumeratore** : 
+ Non ha nessun input ma accumula caratteri nel buffer della *stampante*
+ Il suo linguaggio è rappresentato dall'insieme delle stringhe che stampa 

![[Enumerator.excalidraw]]

>[!important] Teorema
>
>Un linguaggio è **Touring riconoscibile** se e solo se esiste un **Enumeratore** che lo genera 
>

>[!important] Dimostrazione
>
>$\implies$ : Se $A$ linguaggio **Touring riconoscibile** dimostriamo che esiste un **Enumeratore** $E$ tale che $L(E)=A$ 
>
>Visto che $A$ è **Touring riconoscibile** esiste una **MtR** $M$ tale che $L(M)=A$ , costruiamo un **Enumeratore** $E$ tale che $L(E)=A$ 
>
>$E =$ per tutti gli indici $i = 1,2,3,\dots$ 
>1. Genera prime $i$ stringhe dell'ordine
>2. Prova $M$ su $i$ stringhe per $i$ passi di computazione
>3. Se troviamo una stringa accettata questa verrà stampata
>
>>[!note] 
>> $s_i$ saranno stringhe di lunghezza $i$
>> In pratica ad ogni passo generiamo stringhe più lunghe e le proviamo su sempre più passi di computazione ( andando più in profondità nell'albero delle computazioni ) , questo evita che se una stringa porta ad un loop manderebbe in loop anche $M$ non controllando più nessuna stringa
>
>
>$\Leftarrow$ : Se esiste un **Enumeratore** $E$ tale che $L(E)=A$ allora $A$ è **Touring riconoscibile**
>
>Costruisco una **MdT** $M$ per il linguaggio $A$
>$M =$ apetta un input $w$ : 
>1. Simula l'enumeratore $E$
>2. Ogni volta che $E$ stampa una stringa $v$ verifico se $v=w$ 
>3. Se $v==w$ allora *accetto* altrimenti torno allo step 1



