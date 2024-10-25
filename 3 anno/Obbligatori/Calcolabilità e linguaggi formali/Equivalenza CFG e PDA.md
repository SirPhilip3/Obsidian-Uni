---
creation: 2024-10-23T11:04:00
---
>[!important] Teorema
>Un linguaggio $A$ è [[05 Linguaggi Context-Free|Context Free]] se e solo se esiste un [[06 Automi a Pila|PDA]] $P$ tale che $L(P)=A$ 

>[!abstract] Primo verso della dimostrazione
>
>Sia **A** un [[05 Linguaggi Context-Free|Linguaggio Context-Free]] allora esiste un [[Context-Free Grammar|CFG]] **G** tale che $L(G)=A$
>
>>[!note] Idea 
>>Dato che **A** è un linguaggio [[05 Linguaggi Context-Free|Context Free]] allora esiste una [[Context-Free Grammar|CFG]] **G** tale che $L(G)=A$ ci basterà quindi convertire **G** in un [[06 Automi a Pila|PDA]] equivalente
>
>>[!example] 
>>```pseudo
>>	\begin{algorithm}
>>	\begin{algorithmic}
>>	\State $S \to AB | C$
>>	\State $A \to a$
>>	\State $B \to b | bB$
>>	\State $C \to c$
>>	\end{algorithmic}
>>	\end{algorithm}
>>```
>>
>>Consideriamo $w=abb$ , possiamo trovare una [[Derivazione]] per questa stringa : 
>>$$S \implies AB \implies aB \implies abB \implies abb$$
>>Ora ci basterà simulare questa [[Derivazione]] tramite un [[06 Automi a Pila|PDA]] per dimostrare il *teorema* 
>>
>>Rappresentiamo solo lo **stack** :
>>
|  1  |                2                |          3           |                                  4                                   |                5                 |         6         |          7           |                                       8                                        |
| :-: | :-----------------------------: | :------------------: | :------------------------------------------------------------------: | :------------------------------: | :---------------: | :------------------: | :----------------------------------------------------------------------------: |
|     |                A                |          a           |                                                                      |                b                 |                   |                      |                                                                                |
|  S  |                B                |          B           |                                  B                                   |                B                 |         B         |          b           |                                                                                |
|  $  |                $                |          $           |                                  $                                   |                $                 |         $         |          $           |                                       $                                        |
|     | `pop(S)` e `push(A)`, `push(B)` | `pop(A)` , `push(a)` | $a, a \to \epsilon$ tolgo $a$ solo se matcha con la stringa in input | `pop(B)` , `push(B)` , `push(b)` | $b,b\to \epsilon$ | `pop(B)` , `push(b)` | $b,b\to \epsilon$ Abbiamo finito la stringa in input matchandola completamente |
>
>
> Costruiamo il seguente [[06 Automi a Pila|PDA]] a partire da **G** : 
> 1. Mettiamo nello **stack** **$** e sucessivamente lo [[Start Symbol]] **S** 
> 2. Ripeti i seguenti passi fino a terminazione :
> 	1. Se sulla cima dello **stack** c'è un [[Simboli Non Terminali|Non Terminale]] **A** , sciegli non deterministicamente una [[Produzioni|Produzione]] $A \to u_1\dots u_k$ e fai `push` di $u_k\dots u_1$ dopo aver fatto `pop(A)` 
> 	2. Se sulla cima dello **stack** c'è un [[Simboli Terminali|Terminale]] confrontalo con il prossimo carattere in *input* , se sono uguali fai `pop` altrimenti rifiuta l'*input*
> 	3. Se sulla cima dello **stack** c'è **$** passiamo allo stato di *accettazione*
> 
>>[!example] 
>>![[CFGtoPDA.excalidraw]]

>[!example] Esempio di Conversione
>
>```pseudo
>	\begin{algorithm}
>	\begin{algorithmic}
>	\State $S \to aTb | \epsilon$
>	\State $T \to Ta|\epsilon$
>	\end{algorithmic}
>	\end{algorithm}
>```
>
>
![[ExCFGtoPDA.excalidraw]]

>[!abstract] Secondo verso della dimostrazione 
>
>Sia **A** un linguaggio tale che esiste un [[06 Automi a Pila|PDA]] **P** per cui $L(P)=A$ allora **A** è [[05 Linguaggi Context-Free|Context-Free]] 
>
>>[!note] Idea
>> Convertiamo il **P** in una [[Context-Free Grammar|CFG]] **G** tale che $L(P)=L(G)$
>>1. Rendiamo **P** più "disciplinato" senza cambiare il suo linguaggio , **P** deve avere 3 requisiti : 
>>	1. **P** ha un solo stato accettante $q_{accept}$ ( semplicemente utilizzeremo $\epsilon$ transizioni per passare dai vecchi stati accettanti a questo )
>>	2. **P** accetta *solo* con **stack** *vuoto* 
>>	3. Ogni mossa di **P** è o una `push` o una `pop` 
>>2. Definiamo una nuova [[Context-Free Grammar|CFG]] che contiene un [[Simboli Non Terminali|Non Terminale]] $A_{pq}$ per ogni coppia di stati $p$ e $q$ del [[06 Automi a Pila|PDA]] , questa genera tutte le stringhe che portano il [[06 Automi a Pila|PDA]] originale dallo stato $p$ con **stack** *vuoto* a $q$ con **stack** *vuoto*
>>3. Definiamo come $S$ del [[Context-Free Grammar|CFG]] il [[Simboli Non Terminali|Non Terminale]] $A_{q_0 q_{accept}}$ dove $q_0$ è lo stato iniziale del [[06 Automi a Pila|PDA]] e $q_{accept}$ quello finale  
>
>Definiamo meglio il passo 2 
>
>Le produzioni possono avere 3 formati :
>+ $A_{pp} \to \epsilon$ per ogni $p$ stato del [[06 Automi a Pila|PDA]]
>+ $A_{pq} \to A_{pr}A_{rq}$ per ogni tripla di stati $p,q,r$ del [[06 Automi a Pila|PDA]]
>+ Se $(r,u) \in \delta(p,a,\epsilon)$ e $(q,\epsilon) \in \delta(s,b,u)$ allora $A_{pq} \to aA_{rs}b$ fa parte della [[Context-Free Grammar|CFG]] 
>
>Ossia se sono nel primo stato $p$, leggo il primo char $a$ e nello **stack** ho $\epsilon$ passo allo stato $r$ e metto nello **stack** $u$ ; se sono nello stato $s$ , leggo l'ultimo char $b$ e ho nello **stack** il primo simbolo inserito $u$ allora passo nello **stato** $q$ e `pop` di $u$ dallo **stack** 
>Ossia leggendo $a$ e arriviamo a $b$ passando per $rs$  

>[!todo] Correttezza
>
>Possiamo dimostrare che $A_{pq} \implies^* x$ se e solo se da $p$ con **stack** *vuoto* arriviamo a $q$ con **stack** *vuoto* leggendo la stringa $x$
>
>+ $\implies$ 
>
>
>

Da questo possiamo derivare il seguente *corollario* : 
>[!important] Corollario
>Qualsiasi **Linguaggio Regolare** è anche [[05 Linguaggi Context-Free|Context Free]] 
>>[!summary] Dimostrazione
>>Sia **A** un linguaggio regolare , allora esiste un [[NFA]] **N** tale che $L(N)=A$ 
>>Un [[NFA]] è un [[06 Automi a Pila|PDA]] che non tocca lo *stack* quindi **N** è un [[06 Automi a Pila|PDA]] , per il **teorema** principale possiamo quindi dire che **A** è un linguaggio [[05 Linguaggi Context-Free|Context Free]] 

