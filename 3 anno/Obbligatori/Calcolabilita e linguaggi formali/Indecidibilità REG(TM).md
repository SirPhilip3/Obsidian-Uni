---
publish: true
creation: 2024-12-16T09:44:00
---
>[!important] Teorema
>
>$REG_{TM} = \{ <M> | \text{M è MdT e L(N) è Regolare} \}$ è [[Indecidibile]]

**Dimostrazione** : 

Dimostriamo che $A_{TM} \leq REG_{TM}$ ( $A_{TM}$ [[Riducibilità|Riducibile]] a $REG_{TM}$ ) , ossia dimostriamo che se avessimo un [[Decisore]] $H$ per $REG_{TM}$ potremmp costuire un [[Decisore]] per $A_{TM}$ , questo è **Assurdo** per [[Indecidibilità di A(TM)]] 

Costruiamo quindi il decisore $S$ per $A_{TM}$ :

$S$ = Su input $<M,w>$ : 
1. Costruiamo una nuova [[08 Macchine di Touring|MdT]] $N$ tale che :$$L(N)= \begin{cases}
\text{Regolare} & \text{Se $M$ accetta $w$} \\ \text{Non Regolare} & \text{Altrimenti}
\end{cases}$$
2. Esegui il [[Decisore]] per $REG_{TM}$ su $N$
3. Ritorna il suo output

Costruiamo ora $N$ : 

$N$ = Su input $x$ :
1. Se $x$ ha la forma $0^n1^n$ , per qualche $n$, `ACCEPT` 
2. Altrimenti simula $M$ su $w$ e ritorna il suo *output*

>[!note] 
>**Correttezza** : 
>
|         $N$         | $x = 0^n1^n$ | $x\neq 0^n1^n$ | $L(N)$                                                                      |
| :-----------------: | ------------ | -------------- | --------------------------------------------------------------------------- |
|   $M$ accetta $w$   | `ACCEPT`     | `ACCEPT`       | $\Sigma^*$ , questo è [[Regolare]]                                          |
| $M$ non accetta $w$ | `ACCEPT`     | `REJECT`       | $\{0^n1^n\}$ , questo [[04 Linguaggi Non Regolari#^ddb1cb\|Non è Regolare]] |
