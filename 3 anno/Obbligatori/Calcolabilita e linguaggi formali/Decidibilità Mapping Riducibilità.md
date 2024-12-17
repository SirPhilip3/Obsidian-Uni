---
publish: true
creation: 2024-12-17T09:22:00
---
>[!important] Teorema
>
>Se $A \leq_M B$ e $B$ [[Decidibile]] allora $A$ è anch'esso [[Decidibile]]
>

**Dimostrazione** : 

Dato che $A \leq_M B$ allora $\exists$ $f$ ( [[Funzione Calcolabile]] ) tale che $\forall w \in \Sigma^* \ w\in A \iff f(w) \in B$ , visto che $B$ è [[Decidibile]] per definizione allora esiste $M$ [[Decisore]] tale che $L(M)=B$ 

Costruiamo quindi un [[Decisore]] per $A$ : 
$S$ : Su input $w$ : 
1. Calcola $f(w)$
2. Esegui $M$ su input $f(w)$ 
3. Ritorna il suo output 

>[!example] 
>Se $w \in A \implies f(w)\in B$ il [[Decisore]] ritorna `ACCEPT`
>Se $w \notin A \implies f(w)\notin B$ il [[Decisore]] ritorna `REJECT` 

>[!important] Corollario
>Se $A \leq_M B$ e $A$ è [[Indecidibile]] allora $B$ è [[Indecidibile]] 

>[!example] 
![[A(TM) Mapping Riducibile a HALT(TM)]]
![[E(TM) Mapping Riducibile a EQ(TM)]]
![[A(TM) Mapping Riducibile notE(TM)]]

---

>[!important] Teorema
>
>Se $A \leq_M B$ e $B$ è [[Touring Riconoscibili]] allora $A$ è [[Touring Riconoscibili]] 

**Dimostrazione** : 

Dato che $A \leq_M B$ esiste una [[Funzione Calcolabile]] $f$ tale che per ogni stringa $w$ , $w \in A \iff f(w)\in B$ 

Dato che per ipotesi $B$ è [[Touring Riconoscibili]] esiste una [[08 Macchine di Touring|MdT]] $M$ tale che $L(M)=B$ 
Costruiamo quindi una [[08 Macchine di Touring|MdT]] $N$ tale che $L(N)=A$ : 
$S$ = Su input $w$ : 
1. Calcoliamo $f(w)$ 
2. Eseguiamo $M$ su $f(w)$ e ritorniamo il suo output 

>[!important] Corollario 
>
>Se $A \leq_M B$ e $A$ *non* è [[Touring Riconoscibili|TR]] allora $B$ *non* è [[Touring Riconoscibili|TR]] 
>
>Visto che abbiamo dimostrato che [[notA(TM) non è TR]] questo corollario ci permette di dimostrare che alcuni problemi non sono [[Touring Riconoscibili]]
>
>>[!example] 

![[EQ(TM) non è TR]]