---
publish: true
creation: 2024-11-18T10:00:00
---
>[!important] Teorema
>
>Ogni [[05 Linguaggi Context-Free|Linguaggio Context Free]] è [[Decidibile]] 

>[!important] Dimostrazione
>
>Sia $A$ un [[05 Linguaggi Context-Free|Linguaggio Context Free]] allora esiste una [[Context-Free Grammar|CFG]] $G$ tale che $L(G)=A$ 
>
>Dimostriamo che esiste un [[Decisore]] $M$ tale che $L(M)=A$ 
>
>$M$ aspetta in input $w$ : 
>1. Esegui il [[Decisore]] per il problema [[A(CFG)]] su input $<G,w>$ 
>2. Ritorna il suo output