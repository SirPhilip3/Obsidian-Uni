---
publish: true
creation: 2025-02-18T13:06:00
---
Using approximation is useful in order to "solve" ( they will not find the optimal solution but at least we have poly-time solution ) hard problems ( [[Strutture Dati#Classe $NP-completi$ ( o NPC )|NP-Complete]] )

>[!important] $\rho$-approximation algorithm
>+ Garanteed to run in poly-time
>+ Garanteed to solve arbitrary istances of the problem 
>+ Garanteed to find a solution within $\rho$ ration of the *true* optimum

>[!note] 
>The difficult part is proving that a solution value is close to the *optimum* without knowing it 

Assume that we are searching for the *minimum* or *maximum* of a determined *cost* function

Let's say that $C^*$ is the *cost* of the **Optimal** solution and $C$ is the cost of the *Approximation Algorithm* 

Than we have a $\rho$ *Approximated Algorithm* if and only if $max(\frac{C}{C^*}, \frac{C^*}{C}) \leq \rho$ 

>[!note] 
>$\rho$ rappresents the worst possible cost *ratio* that the approximation algorithm can achieve ( in [[Vertex Cover]] an approximation algorithm with $\rho=2$ means that in the worst case it produces a solution that is double as inefficent as the *optimum* ( needs double the vertices to produce a [[Vertex Cover]] ) )

