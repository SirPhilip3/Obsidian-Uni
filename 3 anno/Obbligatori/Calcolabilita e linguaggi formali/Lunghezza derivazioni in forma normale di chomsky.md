---
creation: 2024-11-18T08:57:00
publish: true
---
Se $H$ è una [[Context-Free Grammar|CFG]] in [[Forma normale di Chomsky]] e $w$ è una stringa di lunghezza $n$ allora se $w \in L(H)$ è possibile trovare una [[Derivazione]] di $w$ che ha $2n-1$ passi , se $n=0$ la derivazione ha un solo passo

>[!important] Dimostrazione
>
>Le condizioni di *Chomsky* sono le seguenti : 
>1. $A \to BC$ dove $B,C\neq S$
>2. $A\to a$
>3. $S\to \epsilon$ 
>
>**Caso Base** : se $w$ ha $l=0$ allora l'unica produzione che genererà $w$ sarà $S \to \epsilon$ 
>
>Se $l > 0$ abbiamo due possibilità : 
>1. $A \to BC$ : un [[Simboli Non Terminali|Non Terminale]] genera due [[Simboli Non Terminali|Non Terminale]] , ossia aggiungiamo un terminale
>2. $A \to a$ : un [[Simboli Non Terminali|Non Terminale]] diventa un [[Simboli Terminali|Terminale]] 
>
>>[!example] 
>>Con *Chomsky* costruiamo una stringa di [[Simboli Non Terminali|Non Terminali]] per poi traformarla in una di [[Simboli Terminali]] che rappresenti $w$
>>
>>$w = aaab$
>>
>>$$S \implies AB \implies AAB \implies AAAB \implies aAAB \implies aaAB \implies aaaB \implies aaab $$
>>
>
>Notiamo che per la creazione della stinga di [[Simboli Non Terminali|Non Terminali]] necessitiamo di $n-1$ passi poichè nel primo passo aggiungiamo due [[Simboli Non Terminali|Non Terminali]] e sucessivamente solo $1$ , convertiamo poi i [[Simboli Non Terminali|Non Terminali]] in [[Simboli Terminali]] in $n$ passi poichè ogni [[Simboli Non Terminali|Non Terminale]] corrisponde ad un solo [[Simboli Terminali|Terminale]] , la lunghezza finale della derivazione sarà $2n-1$


