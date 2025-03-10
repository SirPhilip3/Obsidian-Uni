# The Problem

Given an *undirected* graph $G=(V,E)$ with *weights* on the edges that are *positive* *integers* , find a partition $(A,B)$ of nodes such that the total weight of edges crossing the cut ( edges that connects two nodes of different partitions ) is *miximized*

# Single-flip Neighborhood

Given a partition $(A,B)$ move one node from $A$ to $B$ or from $B$ to $A$ if it improves the solution ( higher weight ) 

```pseudo
	\begin{algorithm}
	\caption{Max-Cut-Local}
	\begin{algorithmic}
	\State Pick a random node partition $(A,B)$
	\While{$\exists$ an improving node $v$}
		\If{$v$ is in $A$}
			\State move $v$ to $B$        
		\Else
	        \State move $v$ to $A$
		\EndIf
    \EndWhile
    \Return $(A,B)$
	\end{algorithmic}
	\end{algorithm}
```

>[!warning] 
>This is not a poly time algorithm since the number of iteration are not bound by 