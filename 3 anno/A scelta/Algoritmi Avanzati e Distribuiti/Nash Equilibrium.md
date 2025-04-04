---
publish: true
---
# Multicast Routing 

## The Problem

Given a directed graph $G=(V,E)$ with : 
+ Cost for each node $c_e \geq 0$ 
+ Source node $s$ 
+ $k$ *agents* ( robots ) initially located at $s$ and at the end located at terminal node $t_i,\dots, t_k$ 

Each agent $j$ must construct a path $P_j$ from node $s$ to it's corresponding terminal node $t_j$ 

>[!important] 
>If $x$ agents use edge $e$ than each will pay $c_e/x$

## Best response dynamics

>[!important] 
>Each *agent* is continually prepared to improve its solution in response to changes made by other agents  

>[!important] Nash equilibrium
>It's a solution where no agent has an incentive to switch ( this will be a *stable* solution )

>[!example] 
>#todo

```pseudo
	\begin{algorithm}
	\caption{Best-Response-Dynamics}
	\begin{algorithmic}
	\Input G, c
	\State Pick a random path for each agent
	\While{not a Nash equilibrium}
		\State Pick an agent $i$ who can inprove by switching paths
		\State Switch path of agent $i$
    \EndWhile
	\end{algorithmic}
	\end{algorithm}
```

>[!important] Social Optimum
>The *social optimum* is the *minimum* total cost of all the *agents* ( the sum of all the path tha agents take )
>>[!note] 
>>In general there can be many **Nash equilibra** and they don't necessary equal to the *social optimum*

>[!example] 
>#todo

>[!important] Theorem
>There is a *Nash Equilibrium* for which the total cost to all *agents* **exceeds** that of the *social optimum* by at most a factor of $H(k)$ where $H(k)$ is the harmonic number $1+\frac{1}{2}+\frac{1}{3}+\dots+\frac{1}k$ 
>
>So the *best* Nash Equilibrium is never more than a factor of $H(k)$ *worse* than the *social optimum*

>[!note] 
>Finding any *Nash equilibrium* is an $NP-Hard$ problem

