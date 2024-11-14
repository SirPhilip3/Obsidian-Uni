---
creation: 2024-11-14T09:30:00
---
Determinare se un [[DFA]] $D$ accetta una stringa $w$ ( in forma contratta : $A_{DFA}$ ( problema dell'*acceptance* del [[DFA]] ) )

$$
A_{DFA} = \{<M,w> | M \text{ e' un } DFA \land w\in L(M)\}
$$
>[!important] Teorema
>$A_{DFA}$ è [[Decidibile]]

>[!important] Dimostrazione
>Costruisco un [[Decisore]] $N$ tale che $L(N)=A_{DFA}$ 
>
>$N$ : aspetta in input $<M,w>$
>1. Simuliamo il [[DFA]] $M$ su $w$ 
>2. Se $M$ termina in stato di accettazione *ACCEPT*
>   Se $M$ termina in stato non accettante *REJECT*
>
>>[!note] 
>>
>>Questo è sicuramente un decisore perchè sicuramente $M$ termina , essendo $DFA$ una macchina a stati finiti 
>>
>
>