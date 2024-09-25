---
creation: 2024-09-22T21:21:00
tags:
  - Definizione
---
Siano $A$ e $B$ due [[Linguaggio|Linguaggi]] *qualsiasi* definiamo le seguenti [[Operazioni Regolari]] :
1. **Unione** : $A \cup B = \{ w\ |\ w \in A \lor w \in B \}$
2. **Concatenazione** : $A\ o\ B = \{ w_1w_2 \ | \ w_1 \in A \land w_2 \in B\}$ ^4445db
3. **STAR** : $A^* = \{ w_1w_2 \dots w_k | \ \forall i \in [1,k] :w_i \in A \land k \geq 0 \}$

>[!example] 
>Abbiamo $A = \{a,b\}$ e $B=\{a,cc\}$ : 
>1. $A \cup B = \{a,b,cc\}$
>2. $A\ o\ B = \{aa,acc,ba,bcc\}$
>3. $B^* = \{\epsilon , a , cc, aa, acc , cca , cccc , \dots\}$

