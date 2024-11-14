---
creation: 2024-11-14T09:47:00
---
Determinare se un [[NFA]] $N$ accetta una stringa $w$ 
$$
A_{NFA} = \{  <N,w> | N \text{ e' un } NFA \land w\in L(N) \}
$$

>[!important] Teorema
>
>$A_{NFA}$ è [[Decidibile]] 

>[!important] Dimostrazione 1
>
>Costuiamo una [[Macchina di Touring non Deterministica|MdT Non Deterministica]] $M$ fatta come nel segue :
>
>$M$ : aspetta in input $<N,w>$ :
>1. Simula $N$ su $w$ in modo non deterministico
>2. Se $N$ accetta ritorna *ACCEPT*
>   altrimenti rifiuta in questo ramo della *MdT non deterministica* 

>[!important] Dimostrazione 2
>
>Costruiamo una **Macchina di Touring** deterministica $M$ : 
>
>$M$ aspetta in input $<N,w>$ :
>1. Converto $N$ in un [[DFA]] $D$ ad esso equivalente
>2. Esegui il decisore per [[A(DFA)]] su input $<D,w>$
>3. Ritorna il suo output