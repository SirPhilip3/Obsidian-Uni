---
creation: 2024-10-10T09:42:00
aliases:
  - CFG
---
Facciamo un sempio di *Context-Free Grammar* o **CFG**
>[!example] 
>```pseudo
>	\begin{algorithm}
>	\begin{algorithmic}
>	\State $A \to 0A1 | B$
>	\State $B \to \#$
>	\end{algorithmic}
>	\end{algorithm}
>```
>Questo significa : 
>+ $A$ possiamo riscriverlo come $0A1$ *oppure* $B$
>+ $B$ possiamo riscriverlo come $\#$
>
>Questo sono dette [[Produzioni]] o [[Produzioni|Regole]]
>

![[Start Symbol]]

I *simboli* possono essere divisi in due **classi**

![[Simboli Non Terminali]]
![[Simboli Terminali]]

![[Derivazione]]

Possiamo notare che il [[Linguaggio Formale]] dell'esempio iniziale può essere scritto nel seguente modo : 
$$L(G)=\{ 0^n\#1^n\ | \ n\ge 0 \}$$
>[!note] 
>Questo *linguaggio* non è *regolare*