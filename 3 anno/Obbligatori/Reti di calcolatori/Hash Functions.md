---
creation: 2024-11-11T10:13:00
---
>[!important] Definizione
>
>Una funzione **hash** è una funzione unidirezionale $H()$ che una volta applicata ai dati questa genera un **digest** , una stringa di lunghezza fissa ( generalmente un multiplo di $2$ , eg $128$ , $256$ ) 

Attraverso le funzioni di **Hashing** possiamo ottenere [[Data integrity]] :
+ *Alice* manda a *Bob* un messaggio $M$ , inoltre calcola $H(M)=D$ e invia anche $D$
+ *Bob* riceve $M$ e $D$ , ricalcola $H(M)=D'$ 
+ Se $D=D'$ allora il messagio non è stato modificato in transito 

![[Pasted image 20241111124718.png]]

>[!important] Proprietà
>1. L'*input* $M$ può essere di dimensione qualsiasi
>2. L'*output* deve essere di dimensione fissata
>3. Dato $M$ , calcolare $H(M)$ deve essere *computazionalmente* molto *efficente* 
>>[!warning] 
>>
>>Per definizione differenti input mapperanno negli stessi output ( visto che l'input ha dimensione arbitraria ) , quando per due messaggi differenti $M$ e $M'$ abbiamo che $H(M)=H(M')=D$  si dice che la funzione hash ammette delle **collisioni**
>
>4. Dato $D$ , trovare $X$ in modo che $H(X)=D$ deve essere [[Computationally Impossible]]
>5. Dato $X$ , trovare $Y$