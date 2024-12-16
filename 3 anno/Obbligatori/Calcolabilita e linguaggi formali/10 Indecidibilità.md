---
publish: true
creation: 2024-11-18T10:05:00
---
![[Linguaggi non Touring Riconoscibili]]

![[Linguaggio Indecidibile]] 

![[notA(TM) non è TR]]

---

>[!important] Teorema 
$A$ è [[Decidibile]] se e solo se sia $A$ che $\bar{A}$ sono [[Touring Riconoscibili]]
>
>>[!note] Corollario
>>
>>Se $\bar{A}_{TM}$ fosse [[Touring Riconoscibili]] allora $A_{TM}$ sarebbe [[Decidibile]]
>>

**Dimostrazione** : 

>[!note] 
>Essendo un se e solo se abbiamo due direzioni da dimostrare 

$\implies$ 
Sia $A$ [[Decidibile]] dimostriamo che $A$ e $\bar{A}$ sono [[Touring Riconoscibili]] 
1. Notiamo che visto che $A$ è [[Decidibile]] esso è anche [[Touring Riconoscibili]] per definizione 
2. Visto che $A$ è [[Decidibile]] anche $\bar{A}$ è [[Decidibile]] e quindi [[Touring Riconoscibili]] ( questo perchè una [[08 Macchine di Touring|MdT]] è resistente rispetto al complemento )

$\impliedby$ 
Assumiamo che $A$ e $\bar{A}$ siano [[Touring Riconoscibili]] , definiamo $M$ ed $N$ due [[08 Macchine di Touring|MdT]] tali che $L(M)=A$ e $L(N)=\bar{A}$ , costruiamo il seguente [[Decisore]] ( [[Macchina di Touring Multinastro]] ) per $A$ :

$D$ = Su input $w$ :
1. Simula $M$ su $w$ per un passo di computazione sul primo nastro se $M$ accetta ritorna `ACCEPT` , $M$ rifiuta `REJECT`
2. Simula $N$ su $w$ per un passo di computazione sul primo nastro se $N$ accetta ritorna `REJECT` , $N$ rifiuta `ACCEPT`
3. Torna al passo $1$ 

>[!note] 
>Questa macchina *termina* se una delle due macchine termina ( questo avverrà sempre pocihè se $M$ *rifiuta* $N$ di conseguenza accetterà per le ipotesi iniziali )
>
>Questa è *corretta* poichè se $M$ sta in $A$ prima o poi verrà accettata anche se per $N$ ( che riconosce $\bar{A}$ ) va in loop 
>

![[Riducibilità]]