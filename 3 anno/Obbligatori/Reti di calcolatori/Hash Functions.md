---
creation: 2024-11-11T10:13:00
aliases:
  - Funzione di Hashing
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
>4. Dato $D$ , trovare $X$ in modo che $H(X)=D$ deve essere [[Computationally Impossible]] ( questo viene garantito by design visto che la funzione può accettare qualsiasi input nella traduzione si perderanno molte informazioni rigurado il messaggio originale )
>>[!warning] 
>>
>>Un attacco bruteforce può essere *computazionalmente fattibile* se possiamo raffinare il *digest* , ossia se data una funzione $d(D,D')$ che calcola la distanza tra due stringhe binarie è vero che $d(D,D'') < d(D,D')$ allora $d(M,M'') < d(M,M')$ , questo non deve essere possibile 
>>
>5. Dato $X$ , trovare $Y$ in modo che $H(X)=H(Y)$ deve essere [[Computationally Impossible]] ( **Weak Collision resistance** )
>>[!important] 
>>Il **digest** non deve rivelare nessuna infomazione riguradante il messaggio iniziale , ossia se troviamo un documento $M'$ con hash $D$ simile non significa che sia simile a $M$ 
>1. Trovare due $X$ e $Y$ per cui $H(X)=H(Y)$ deve essere [[Computationally Impossible]] ( **Strong Collision resistance** )