---
creation: 2024-09-21T22:44:00
tags:
  - Definizione
---
La definizione formale di *DFA* è la seguente :

Il *DFA* è rappresentatno da una quintupla : 
$$DFA : (\ Q,\ \sum ,\ \delta ,\ q_0 ,\ F\ )$$
Dove : 
+ $Q$ : è un insieme finito di *stati*
+ $\sum$  : è un insieme finito di *input*
+ $\delta$  : è la funzione di transizione e $Q\times \epsilon \rightarrow Q$ ( l'*input* della funzione rappresenta lo *stato* + l'*alfabeto* , l'*output* è un nuovo stato $Q$ )
+ $q_0$ : è un elemento di $Q$ che rappresenti lo *stato finale*
+ $F$ : è un sottoinsieme $\subseteq$ di $Q$ che rappresenta gli *stati finali / accettanti* 
>[!note] 
>Se $F$ è $\emptyset$ l'automa rifiuta tutte le stringhe 

