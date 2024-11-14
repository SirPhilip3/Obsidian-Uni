---
creation: 2024-11-14T14:11:00
publish: true
---
Dati due [[DFA]] $D_1$ e $D_2$ vogliamo determinare se riconoscono lo stesso linguaggi ( *equivalence* problem ) 
$$
EQ_{DFA} = \{ <D_1 , D_2> | D_1 \text{ e } D_2 \ \ DFA \land L(D_1) = L(D_2) \}
$$
>[!important] Teorema
>
>$EQ_{DFA}$ è [[Decidibile]] 

Osserviamo che $L(D_1) = L(D_2)$  se e solo se : 
+ Tutte le stringhe di $L(D_1)$ stanno anche in $L(D_2)$
+ Tutte le stringhe di $L(D_2)$ stanno anche in $L(D_1)$
Ossia : 
+ Non esiste alcuna stringa del $L(D_1)$ tale che essa non stia in $L(D_2)$
+ Non esiste alcuna stringa del $L(D_2)$ tale che essa non stia in $L(D_1)$

Ossia possiamo scrivere : 
$L(D_1)=L(D_2)$ se e solo se $(L(A) \cap \overline{L(B)}) \cup (\overline{L(A)} \cap L(B)) = \emptyset$

>[!important]  Dimostrazione
>
>Costruiamo un [[Decisore]] $D$ per $EQ_{DFA}$
>
>$M$ prende in input $<D_1,D_2>$ :
>1. Costruiamo un nuovo [[DFA]] $D$ tale che $L(D)=(L(A) \cap \overline{L(B)}) \cup (\overline{L(A)} \cap L(B))$ , ciò è possibile per la [[Chiusura linguaggi regolari]] 
>2. Eseguiamo il decisore per $E_{DFA}$ su input $<D>$
>3. Ritorno il suo output ( è corretto poichè $E_{DFA}$ accetta solo se il linguaggio è $\emptyset$ ) 



