---
creation: 2024-11-18T09:38:00
publish: true
---
Determinare se un [[Context-Free Grammar|CFG]] $G$ ha come $L(G)=\emptyset$
$$
E_{CFG} = \{ <G> | G \text{ e' } CFG \land L(G)=\emptyset\}
$$ 
>[!important] Teorema
>
>$E_{CFG}$ è [[Decidibile]]

>[!important] Dimostrazione
>
>>[!info] Idea
>>
>>Evidenziamo tutti i simboli che hanno a destra una stringa completamente sottolineata , ossia fatta di soli terminali 
>
>Costruiamo un [[Decisore]] per $E_{CFG}$ 
>
>$M$ aspetta in input $<G>$ : 
>1. Sottolinea tutti i [[Simboli Terminali|Terminali]] di $G$ 
>2. Finchè è possibile sottolineare [[Simboli Non Terminali|Non Terminali]] lo facciamo
>	1. Sottolinea i [[Simboli Non Terminali|Non Terminali]] $A$ tale che ha una [[Produzioni|Produzione]] $A \to w_1 \dots w_n$ dove tutti i $w_i$ sono sottolineati 
>3. Se ho sottolineato lo [[Start Symbol]] $S$ *REJECT* altrimenti *ACCEPT*