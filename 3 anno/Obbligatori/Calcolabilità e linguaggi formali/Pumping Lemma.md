---
creation: 2024-10-08T10:11:00
tags:
  - Lemma
publish: true
---
>[!summary] Enunciato
>
>Sia $A$ un [[Linguaggio Regolare NFA|Linguaggio Regolare]] allora esiste un intero $p \ge 1$  ( *lunghezza di pumping* ) tale che per ogni stringa $s\in A$ tale che $|s|\ge p$ si hanno le seguenti condizioni :
>$s$ può essere divisa in tre parti $x,y,z$ soddisfacendo le seguenti condizioni : 
>1.  $\forall i \ge 0 \quad x,y^i,z \in A$ : ossia la stringa con la parte centrale $y$ ripetuta $i$ volte esisterà anchessa nel *linguaggio* $A$ 
>2. $|y|>0$
>3. $|xy| \le p$
>

>[!important] Dimostrazione
>
>**Idea** : Siccome per *ipotesi* abbiamo che $A$ è un [[Linguaggio Regolare NFA|Linguaggio Regolare]] allora esiste un [[DFA]] $D$ tale per cui $L(D)=A$ , per cui $p$ sarà il numero di stati del [[DFA]] $D$ 
>
>Se $s$ in $A$ allora questa dovrà essere almeno lunga $p$
>
>Supponiamo che una stringa $s$ sia lunga $n$ allora la sequenza di stati che la descrive all'interno del [[DFA]] sarà lungha $n+1$ , poichè $n$ deve essere almeno $p$ avremo che la sequenza di stati sarà di lunghezza $\ge p +1$ , ciò significa che dobbiamo avere che almeno uno stato sella sequenza di stati che la descrive dovrà essere *ripetuto*
>
>Il [[DFA]] che rappresenta $s=xy^iz$ sarà : 
>![[xyiz.excalidraw]]
>
>Verifchiamo che le tre condizioni imposte prima siano corrette : 
>1. Possiamo accettare $xy^iz$ ( possiamo accettare anche con $i=0$ )
>2. La $y$ è non vuota poichè se lo fosse non avrei almeno un arco e quindi lo stato non si ripeterebbe 
>3. $|xy|$ limitata da $p$ 