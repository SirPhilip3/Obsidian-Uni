---
publish: true
creation: 2024-12-16T11:08:00
---
>[!important] Definizione
>
>$E_{LBA}=\{<M>|\text{M è LBA e } L(M)=\emptyset \}$ è [[Indecidibile]]

**Dimostrazione** : 

Costruiamo una $A_{TM} \leq E_{LBA}$ sfruttando la [[Riducibilità Basata su Storie di Computazione]]

Assumiamo per **Assurdo** che $E_{LBA}$ sia [[Decidibile]] e costruiamo un [[Decisore]] per $A_{TM}$ :

$S$ = Su input $<M,w>$ :
1. Costruiamo un [[Automi Linearmente Limitati|LBA]] $N$ con la seguente caratteristica : 
$$L(N) = \begin{cases}
\text{Non Vuoto} & \text{Se $M$ accetta $w$} \\ \text{Vuoto} & \text{Altrimenti}
\end{cases}$$
2. Eseguo il [[Decisore]] per $E_{LBA}$ su $N$
3. Ritorno il suo output *invertito* ( poichè $E_{LBA}$ ritorna `ACCEPT` se $M$ non accetta $w$ )

Costruiamo l'[[Automi Linearmente Limitati|LBA]] $N$ in modo che $L(N)$ sia l'insieme delle **storie di computazione accettanti** di $M$ e $w$ : 
+ Se $L(N) = $