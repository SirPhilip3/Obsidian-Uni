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

