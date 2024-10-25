---
creation: 2024-10-23T11:04:00
---
>[!important] Teorema
>Un linguaggio $A$ è [[05 Linguaggi Context-Free|Context Free]] se e solo se esiste un [[06 Automi a Pila|PDA]] $P$ tale che $L(P)=A$ 
>>[!abstract] Dimostrazione
>>>[!note] Idea 
>>>Dato che **A** è un linguaggio [[05 Linguaggi Context-Free|Context Free]] allora esiste una [[Context-Free Grammar|CFG]] **G** tale che $L(G)=A$ ci basterà quindi convertire **G** in un [[06 Automi a Pila|PDA]] equivalente
>>
>>>[!example] 
>>>```pseudo
>>>	\begin{algorithm}
>>>	\begin{algorithmic}
>>>	\State $S \to AB | C$
>>>	\State $A \to a$
>>>	\State $B \to b | bB$
>>>	\State $C \to c$
>>>	\end{algorithmic}
>>>	\end{algorithm}
>>>```
>>>
>>>Consideriamo $w=abb$ , possiamo trovare una [[Derivazione]] per questa stringa : 
>>>$$S \implies AB \implies aB \implies abB \implies abb$$
>>>Ora ci basterà simulare questa [[Derivazione]] tramite un [[06 Automi a Pila|PDA]] per dimostrare il *teorema* 
>>>
>>>Rappresentiamo solo lo **stack** :
>>>
|  1  |                2                |          3           |                                  4                                   |                5                 |         6         |          7           |                                       8                                        |
| :-: | :-----------------------------: | :------------------: | :------------------------------------------------------------------: | :------------------------------: | :---------------: | :------------------: | :----------------------------------------------------------------------------: |
|     |                A                |          a           |                                                                      |                b                 |                   |                      |                                                                                |
|  S  |                B                |          B           |                                  B                                   |                B                 |         B         |          b           |                                                                                |
|  $  |                $                |          $           |                                  $                                   |                $                 |         $         |          $           |                                       $                                        |
|     | `pop(S)` e `push(A)`, `push(B)` | `pop(A)` , `push(a)` | $a, a \to \epsilon$ tolgo $a$ solo se matcha con la stringa in input | `pop(B)` , `push(B)` , `push(b)` | $b,b\to \epsilon$ | `pop(B)` , `push(b)` | $b,b\to \epsilon$ Abbiamo finito la stringa in input matchandola completamente |
>>
>> Sia $A$

Da questo possiamo derivare il seguente *corollario* : 
>[!important] Corollario
>Qualsiasi **Linguaggio Regolare** è anche [[05 Linguaggi Context-Free|Context Free]] 
>>[!summary] Dimostrazione
>>Sia **A** un linguaggio regolare , allora esiste un [[NFA]] **N** tale che $L(N)=A$ 
>>Un [[NFA]] è un [[06 Automi a Pila|PDA]] che non tocca lo *stack* quindi **N** è un [[06 Automi a Pila|PDA]] , per il **teorema** principale possiamo quindi dire che **A** è un linguaggio [[05 Linguaggi Context-Free|Context Free]] 

