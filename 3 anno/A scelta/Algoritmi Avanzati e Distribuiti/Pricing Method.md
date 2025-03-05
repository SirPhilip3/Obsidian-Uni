# Vertex Cover Pracing Method

## The Problem

>[!important] Weighted Vertex Cover
>
>Given a graph $G$ with some *weights* on the *verteces* find a [[Vertex Cover]] of *minimum* weight

>[!example] 
>#todo

## Pricing Method

Each *edge* must be covered by some *vertex* , each *edge* $e=(i,j)$ pays some price $p_e\geq 0$  to use *verteces* $i$ and $j$ 

>[!important] Fairness
>*Edges* incident to *vertex* $i$ should pay $\leq w_i$ in total , so for each *vertex* $i$ : $$\sum_{e=(i,j)}p_e \leq w_i$$ 
>
>>[!note] 
>>In proctice the sum of all the weight on the *edges* incident to a *vertex* $i$ sould be less or equal to the weight on $i$

>[!important] Lemma
>For any [[Vertex Cover]] $S$ and any fair prices $p_e : \sum_e p_e \leq w(S)$ 
>>[!note] Proof
>>$\sum_{e\in E} p_e\leq \sum_{i \in S}\sum_{e=(i,j)}p_e \leq \sum_{i\in S} w_i = w(S)$

