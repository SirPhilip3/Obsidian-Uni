---
publish: true
creation: 2024-12-16T09:01:00
---
$$E_{TM} = \{ <M> | \text{ M è MdT e } L(M) = \emptyset \}$$
>[!important] Teorema
>$E_{TM}$ è [[Indecidibile]]

**Dimostrazione** : 

Dimostriamo che $A_{TM} \leq E_{TM}$ ossia dimostriamo cche se avessi un [[Decisore]] $H$ per $E_{TM}$ allora potremmo costruire un [[Decisore]] per $A_{TM}$ ( Impossibile per [[Indecidibilità di A(TM)]] ) 

>[!error] Soluzione errata 
>
>Costruiamo il seguente [[Decisore]] per $A_{TM}$ :
>$S$ = Su input $<M,w>$ : 
>1. Esegue il [[Decisore]] per $E_{TM}$ su input $<M>$
>2. Se esso *accetta* ( il linguaggio di $M$ è vuoto ) ritorna `REJECT` 
>3. Se esso *rifiuta* ( il linguaggio di $M$ non è vuoto ) simulo $M$ su $w$ e ritorno il suo *output*
>>[!warning] 
>>$M$ potrebbe andare in loop , non è quindi garantito il [[Decisore]]

>[!success] Soluzione Corretta 
>
>$S$ = Su input $<M,w>$ 
>1. Costruiamo una nuova [[08 Macchine di Touring|MdT]] $N$ avente la seguente propietà :
>   $$L(N) = \begin{cases}\text{Non vuoto} & \text{Se $M$ accetta $w$} \\ \text{Vuoto} & \text{Altrimenti} \end{cases}$$
>2. Eseguiamo $E_{TM}$ su input $<N>$ 



