---
publish: true
creation: 2024-12-17T13:21:00
---
>[!info] Enunciato Informale 
>
>Qualsiasi propietà non banale ( che non è o sempre vera o sempre falsa ) del linguaggio di una [[08 Macchine di Touring|MdT]] è [[Indecidibile]] 

>[!example] 
>
>$E_{TM} = \{ <M> | M \text{ MdT e } L(M) = \emptyset \}$
>$A_{TM} = \{<M,v> | M \text{ MdT e } w \in L(M)\}$
>$REG_{TM} = \{ <M> | M \text{ MdT e } L(M) \text{ è Regolare}\}$
>
>Sono in automatico [[Indecidibile]] per *RICE*

---

>[!important] Enunciato Formale

**Definizioni** ausiliarie : 

+ ![[Propietà]]
+ ![[Propietà Non Banale]]
+ ![[Propietà del Linguaggio]]
**Dimostrazione RICE** : 

Sia $P$ una [[Propietà Non Banale]] [[Propietà del Linguaggio|Del Linguaggio]] di una [[08 Macchine di Touring|MdT]] 

Assumiamo che $P$ sia [[Decidibile]] e sia $H$ il suo [[Decisore]] , in tal caso riusciremo a costruire un [[Decisore]] per $A_{TM}$ , questo è **Assurdo** poichè abbiamo dimostrato l'[[Indecidibilità di A(TM)]] 

Il [[Decisore]] per $A_{TM}$ sarebbe il seguente : 
$S$ = Su input $<M,w>$
1. Costruisci una nuova [[08 Macchine di Touring|MdT]] $N$ tale che $N$ ha la [[Propietà]] $P$ se $M$ *accetta* $w$ e non ha la [[Propietà]] $P$ altrimenti 
2. Eseguo $H$ su $<N>$
3. Ritorna il suo output

>[!note] 
>Visto che $P$ è [[Propietà Non Banale]] devono esistere almeno due [[08 Macchine di Touring|MdT]] , uno che soddisfa $P$ e uno che non la soddisfa 

Assumiamo , senza perdita di generalità ( non restringe la correttezza della dimostrazione ) , che la macchina $V_{\emptyset}$ ( $L(V_{\emptyset}) = \emptyset$ ) non soddisfa $P$ , ossia $<V_{\emptyset}> \notin P$ 

Sia invece $T$ una [[08 Macchine di Touring|MdT]] che soddisfa $P$ ossia $<T>\in P$ 

Costruiamo la macchina $N$ :
$N$ = Su input $x$ : 
1. Esegue $M$ su $w$ 
2. Se $M$ ha rifiutato `REJECT`
3. Se $M$ ha accettato 
	1. Simula $T$ su $x$ e ritorna il suo output

Quindi il [[Linguaggio]] di $N$ sarà : 
$$L(N) = \begin{cases}
L(T) & M \text{ accetta } w\ ( L(N) = L(T) ) \\
\emptyset & \text{Altrimenti } ( L(N) = \emptyset = L(V_{\emptyset}) ) 
\end{cases}$$

