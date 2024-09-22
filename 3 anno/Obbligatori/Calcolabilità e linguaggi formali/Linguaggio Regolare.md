---
creation: 2024-09-22T18:53:00
tags:
  - Definizione
---
Un [[Linguaggio]] $A$ si dice **Regolare** se e solo se esiste un [[DFA]] $M$ tale che il [[Linguaggio]] di $M$ è *uguale* ad $A$ 

>[!note] 
>In pratica per dimostrare che un [[Linguaggio]] sia *regolare* dobbiamo costruire un [[DFA]] che lo rappresenti

>[!example] Example 1
>Dimostrare che l'insieme delle stringhe binarie che contengono un numero dispari di $1$ è *regolare*
>
>Poichè non mi interessa il numero di volte che incontro $1$ ( mi servirebbe un numero di stati infinito ) mi bastano *due* stati che codifichino parità e disparità
>
>L'alfabeto sarà binario : $0,1$
>$q_0$ sarà $q_{pari}$ poichè una stringa senza $1$ ha un numero pari di $1$ ( $0$ )
>Se da $q_{pari}$ trovo un $1$ lungo la sequenza allora andiamo allo stato $q_{dispari}$ , se ne troviamo un'altro ritorniamo allo stato $q_{pari}$ e così via 
>
>![[DFA_reg1.excalidraw]]

>[!example] Example 2
>
>Dimostrare che che l'insieme delle stringhe binarie che contengono la sottostringa $001$ è *regolare*
>
>Possiamo costruire un [[DFA]] con 3 stati ognuno dei quali memorizza se è stata trovata una parte della sottostringa :
>
>![[DFA_reg2.excalidraw]]
>
>>[!example] 
>>Proviamo ad eseguire l'automa 
>>
>>| I     | 0     | 0     | 0     | 1     | 0     |
| ----- | ----- | ----- | ----- | ----- | ----- |
| $q_0$ | $q_1$ | $q_2$ | $q_2$ | $q_3$ | $q_3$ |
>> Come abbiamo visto arriviamo allo stato *accettante*

