---
creation: 2024-11-14T10:07:00
publish: true
---
Dato un [[DFA]] determinare se esso non accetta nessuna stringa ( ***E**mptiness* problem )
$$
E_{DFA} =\{ <D> | D \text{ e' un } DFA \land L(D)=\emptyset\}
$$
>[!important] Teorema
>
>$E_{DFA}$ è [[Decidibile]] 

>[!important] Definizione
>
>Costruiamo un [[Decisore]] $M$ per $E_{DFA}$ 
>>[!example] 