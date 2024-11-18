---
creation: 2024-11-14T14:38:00
publish: true
---
Determinare se un [[Context-Free Grammar|CFG]] $G$ genera una certa stringa $w$ 
$$
A_{CFG} = \{ <G,w> | G \text{ e' un } CFG \land w \in L(G)\}
$$
>[!important] Teorema
>
>$A_{CFG}$ è [[Decidibile]]

>[!note] 
>
>In generale una derivazione può crescere in modo infinito , se però la [[Context-Free Grammar|CFG]] è in [[Forma normale di Chomsky]] possiamo trovare un upperbound al numero di derivazioni in base alla lunghezza $n$ della stringa

![[Lunghezza derivazioni in forma normale di chomsky]]

>[!important] Dimostrazione
>
>Costruiamo un [[Decisore]] $M$ per $A_{CFG}$ 
>
>$M$ aspetta un input $<G,w>$ : 
>1. Converte $G$ in una [[Forma normale di Chomsky]] 
>2. Provo tutte le possibili derivazioni di lunghezza $2n-1$ passi dove $n$ è la lunghezza di $w$ , se $n=0$ proviamo le [[Derivazione]] di lunghezza $1$
>3. Se una di esse genera $w$ *ACCEPT* altrimenti *REJECT* 

