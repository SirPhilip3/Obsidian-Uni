---
creation: 2024-10-17T14:13:00
tags:
  - Algoritmo
---
1. Generiamo un nuovo [[Start Symbol]] $S'$ e aggiungiamo la produzione $S' \to S$ 
>[!note] 
>Questo passaggio ci assicura che lo [[Start Symbol]] non occorra a destra di una [[Produzioni|Produzione]] 

2. Elimino le [[Produzioni]] nella forma $A \to \epsilon$ dove $A \neq$ [[Start Symbol]] 
	Per tutte le regole nella forma $R \to uAv$ introduco una nuova regola $R \to uv$ per tutte le occorrenze di $A$ 
>[!example] 
>Per $R \to uAvAw$ introduco 3 nuove regole che rappresentano tutte le possibilità di combinazione della stringa espansa da $S$ avendo rimosso $A\to \epsilon$  : 
>$R \to uvAw$
>$R \to uAvw$
>$R \to uvw$
>>[!note] 
>>Possiamo anche riscriverle in questo modo : $R \to uvAw | uAvw | uvm$

3. Elimino tutte le [[Produzioni]] 