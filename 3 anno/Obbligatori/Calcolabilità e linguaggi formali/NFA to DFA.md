---
creation: 2024-09-27T10:52:00
tags:
  - Teorema
  - Dimostrazione
---
Per ogni [[NFA]] $N$ esiste un [[DFA]] $D$ tale che il linguaggio $L(D) = L(N)$

**Dimostrazione**

>[!note] Idea
>Visto che per ogni [[NFA]] abbiamo un albero di computazione 
>Non so a priori quale sarà il percorso corretto per riconoscere la stringa $w$ , mi salvo quindi negli stati del [[DFA]] *tutte* le possibilità

Sia $N=(Q\ ,\Sigma\ ,\delta\ ,q_0\ ,F\ )$ un [[NFA]] e costruiamo un [[DFA]] $D=(Q'\ ,\Sigma\ ,\delta'\ ,q_0'\ ,F'\ )$

>[!note]
>I $\Sigma$ devono essere uguali per riconoscere lo stesso [[Linguaggio Regolare]]
>

*Ipotesi* : 
	Assumiamo per ora che $N$ *non* contenga $\epsilon$-transizioni 

+ $Q' = P(Q)$ ( [[powerset]] )
+ $q_0' =\{ q_0 \}$ ( deve essere un *insieme* poichè deve $\in Q'$ che è un [[powerset]] )
+ $F' = \{R \in Q' |\ \exists r \in R : r \in F \}$ ( esiste un elemento del mio stato ( insieme di stati presi dal [[powerset]] ) tale che sia accettante per l'automa di partenza $N$ )
+ $\delta' (R,a) = \bigcup_{r\in R} \delta(R,a)$ ( unione di tutte le possibilità )

Con $\epsilon$-tansizioni  

Costruiamo una funzione che preso in imput un insieme di $Q'$ ritorna gli *stati* espandi aggiungendo quelli raggiungibili dalle $\epsilon$-transizioni
$$E(R) = \{ q\ |\ q \text{ può essere raggiunto da qualche $r\in R$ con 0 o più $\epsilon$-transizioni }\}$$
Avremo quindi che : 
+ $q_0' = E(\{q_0\})$
+ $\delta'(R,a)= \bigcup_{r\in R} E(\delta(R,a))$

>[!example] 
>Proviamo a costruire il corrispondente [[DFA]] :
![[Starting_NFA.excalidraw]]
>
>Innanzitutto dobbiamo trovare $q_0' = E(\{1\}) = \{1,3\}$ ( poichè attraverso una $\epsilon$-transizione possiamo raggiungere $3$ ) 
>
>Abbiamo che $Q'=\{\emptyset,\{1\},\{2\},\{3\},\{1,2\},\{1,3\},\{2,3\},\{1,2,3\}\}$
>
>Gli stati accettanti saranno quindi quegli stati che contengono o $\{1\}$ o $\{3\}$ o entrambi
>$$F' = \{ \{1\},\{1,2\},\{1,3\},\{1,2,3\} \}$$
>
>Determiniamo quindi la funzione di transizione :
>+ Lo stato $\{2\}$ va in $\{2,3\}$  con *input* $a$ poichè in $N$ lo stato $2$ va sia in $2$ che in $3$ con l'*input* $a$ e non possiamo procedere attraverso nessuna $\epsilon$-transizione 
>+ Lo stato $\{3\}$ va in $\{1,3\}$ con *input* $a$ poichè in $N$ lo stato $3$ va in $1$ con $a$ e attraverso una $\epsilon$-transizione $1$ va in $3$
![[DFAfromDFA.excalidraw]]
>
>Notiamo che vi sono due *stati* che non sono raggiungibili ( hanno solo archi uscenti ) , possiamo toglierli dal [[DFA]]
>
![[CorrectedDFA.excalidraw]]
