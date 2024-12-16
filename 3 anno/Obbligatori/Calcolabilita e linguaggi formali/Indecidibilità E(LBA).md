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
+ Se $L(N) = \emptyset$ allora non ci sono storie di computazione accettanti di $M$ e $w$ , quindi $M$ non accetta $w$
+ Se $L(N) \neq \emptyset$ allora iv è una storia di computazione accettante di $M$ e $w$ , quindi $M$ accetta $w$

>[!note] Assunzione
>
>Assumiamo di rappresentare le storie di computazioni accettante nel seguente formato : 
>$$\# C_1 \# C_2 \# \dots \# C_k \#$$ dove $C_i$ sono configurazioni

$N$ : Su input $\# C_1 \# C_2 \# \dots \# C_k \#$ :
1. Verifica che $C_1$ sia una configurazione *iniziale* di $M$ su $w$ ( ci basta farne una scansione e verificare che sia nella forma $q_0 w$)
2. Verifica che $C_k$ sia una configurazione *finale* di $M$ su $w$ ( ci basta farne una scansione e verificare che è nella forma $\mu q_{accept} v$ , per qulche $\mu , v$ )
3. Verifica che $\forall i\ C_{i+1}$ discende da $C_i$ secondo la funzione di transizione di $M$

>[!note] 
>
>L'ultimo passo è possibile poichè tra le due configurazioni cambiano solo le posizioni direttamente adiacenti alla testina 

