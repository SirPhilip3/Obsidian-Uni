---
publish: true
creation: 2024-12-16T11:54:00
---
>[!important] Teorema
>
>$ALL_{CFG} = \{ <G> | \text{G è una CFG e } L(G) = \Gamma^* \}$ è [[Indecidibile]]

**Dimostrazione** : 

Assumiamo per **assurdo** che $ALL_{CFG}$ sia [[Decidibile]] e costruiamo un [[Decisore]] per $A_{TM}$

$S$ = Su input $<M,w>$ :
1. Costruire una [[Context-Free Grammar|CFG]] $G$ con le seguenti propietà : 
$$L(G) = \begin{cases}
A \neq \Sigma^* & \text{Se M accetta $w$} \\
\Sigma^* & \text{Altrimenti} 
\end{cases}$$
2. Esegui il [[Decisore]] per $ALL_{CFG}$ su $<G>$
3. Ritorna il suo output invertito 

Costruiamo ora $G$ in modo che $L(G)$ contenga le stringhe che non sono **storie di computazione accettanti** per $M$ e $w$
+ Se $L(G)=\Sigma^*$ *nessuna* stringa è una [[Riducibilità Basata su Storie di Computazione#^bd6bb6|Storia di computazione accettante]] per $M$ e $w$ ( $M$ non accetta $w$ )
+ Se $L(G) \neq \Sigma^*$ *qualche* stringa è una [[Riducibilità Basata su Storie di Computazione#^bd6bb6|Storia di computazione accettante]] ( $M$ accetta $w$ )

>[!note] 
>
>Visto che la definizione di una [[Context-Free Grammar|CFG]] per $G$ sarebbe complesso 