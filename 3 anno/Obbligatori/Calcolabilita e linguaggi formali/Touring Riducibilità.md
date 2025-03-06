---
publish: true
creation: 2024-12-17T11:44:00
---
Prima di definire la **Touring Riducibilità** diamo la seguente definizione : 
![[Oracolo]]

![[Macchina di Touring con Oracolo]]

>[!important] Definizione
>
>Un [[Linguaggio]] $A$ si dice **Touring Riducibile** ad un [[Linguaggio]] $B$ $\iff$ esiste una [[Macchina di Touring con Oracolo]] per $B$ che è un [[Decisore]] per $A$

>[!example] 
>Dimostriamo che $\bar{A}_{TM} \leq_{T} A_{TM}$ 
>
>Costruiamo una [[Macchina di Touring con Oracolo|MdT con Oracolo]] per $A_{TM}$ che decidi $\bar{A}_{TM}$
>
>$S$ = Su input $x$ : 
>1. Invoca l'[[Oracolo]] per $A_{TM}$ su $x$ 
>2. Inverti il suo output
>---   
>
>![[E(TM) Touring Riconducibile a A(TM)]]

---
# Propietà 

>[!important] Teorema
>
>Se $A \leq_{T} B$ e $B$ [[Decidibile]] allora anche $A$ [[Decidibile]]

**Dimostrazione** : 

Sia $A \leq_{T} B$ allora esiste una [[Macchina di Touring con Oracolo|MdT con Oracolo]] per $B$ che è un [[Decisore]] per $A$

Posso costruire un [[Decisore]] per $A$ sostituiendo tutte le chiamate all'[[Oracolo]] per $B$ con chiamate al [[Decisore]] per $B$ ( questo è possibile poichè sappiamo per ipotesi che $B$ è un [[Decisore]] ) 

>[!important] Corollario
>
>Se $A\leq_T B$ e $A$ è [[Indecidibile]] allora $B$ è [[Indecidibile]] 
>

## Corrispondenza tra Mapping e Touring Riducibilità

>[!important] Teorema
>
>Se $A \leq_M B$ allora $A \leq_T B$ 

**Dimostrazione** : 

Dato che $A \leq_M B$ allora esiste una [[Funzione Calcolabile]] $f$ tale che $\forall w,w \in A \iff f(w)\in B$ 

Costruiamo una [[Macchina di Touring con Oracolo|MdT con Oracolo]] per $B$ che decide $A$ come segue : 
$S$ : Su input $x$ : 
1. Calcola $f(w)$
2. Esegui l'[[Oracolo]] per $B$ su $f(w)$
3. Ritorna il suo output

