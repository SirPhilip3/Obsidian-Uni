---
publish: true
creation: 2024-12-16T10:45:00
---
>[!important] Teorema
>
>$A_{LBA} = \{ <M,w> | \text{M è una MdT e } w\in L(N) \}$ è [[Decidibile]]

**Dimostrazione** : 

Per svolgere la dimostrazione utilizziamo un lemma ausiliario : 
![[Stati di un LBA]]

Costruiamo quindi il seguente [[Decisore]] per $A_{LBA}$ :
$S$ = Su input $<M,w>$ 
1. Simula $M$ su $w$ per $q\cdot n  \cdot g^n$ passi di computazione , oppure fino a terminazione
2. Se $M$ ha terminato ritorna il suo output
3. Se $M$ non ha terminato `REJECT` ( $M$ attraversa tutte le possibili $q\cdot n\cdot g^n$ *configurazioni* ) 

>[!note] 
>Visto che abbiamo un numero limitato di *configurazioni* possiamo accorgerci di un loop se osserviamo due triple uguali 