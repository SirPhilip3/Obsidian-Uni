---
publish: true
creation: 2024-12-16T08:39:00
---
$$HALT_{TM} = \{ <M,w> | \text{ $M$ MdT che termina su input $w$}\}$$

>[!important] Teorema
>
>$HALT_{TM}$ è [[Indecidibilità di A(TM)]]

**Dimostrazione** : 

>[!note] 
>Usiamo la tecnice della [[Riducibilità]] 

La *dimostrazione* avviene per **Assurdo** 

Assumiamo che $HALT_{TM}$ è [[Decidibile]] e lo utilizziamo per dimostrare che $A_{TM}$ è [[Decidibile]] ( questo contraddice [[Indecidibilità di A(TM)|Indecidibilità di A(TM)]] ) 

Assumiamo quindi di avere $N$ [[Decisore]] per $HALT_{TM}$ , costruiamo il seguente [[Decisore]] per $A_{TM}$ : 

$S$ = Su input $<M,w>$ :
1. Esegui $N$ su input $<M,w>$ 
2. Se $N$ *rifiuta* ritorna `REJECT` 
3. Se $N$ *accetta* simula $M$ su $w$ e ritorna il suo output

>[!important] 
>Notiamo quindi che se $N$ è [[Decisore]] per $HALT_{TM}$ potremmo costruire un [[Decisore]] per $A_{TM}$ ma visto che abbiamo dimostrato essere [[Indecidibilità di A(TM)]] allora anche $HALT_{TM}$ deve essere **Indecidibile** 