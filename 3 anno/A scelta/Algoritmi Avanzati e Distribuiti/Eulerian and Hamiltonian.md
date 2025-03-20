# Eulerian


>[!important] Eulerian circuit
>
>A closed path that *visits* *each* *edge* of the graph exactly *once* ( or each *node* at *least* once )
>>[!note] 
>>It needs to start and finish at the same vertex for the definition of *circuit*
>![[EulerianCircuit.excalidraw]]

>[!important] Eulerian graph
>A *graph* will be *Eulerian* if and only if :
>+ It is *connected*
>+ All nodes have an *even* *degree*

## Algorithm to find an Eulerian circuit

```pseudo
	\begin{algorithm}
	\caption{Eulero}
	\begin{algorithmic}
	\Input InitialVertex
	\If{InitialVertex does not have outgoing edges}
	\Return InitialVertex
    \Else
    \State Create a closed path $C=[InitialVertex,v_2,\dots,v_k,InitialVertex]$ visiting all edges only once 
    \State Remove all the edges of path $C$
    \Return (\Call{Eulero}{InitialVertex} , $\dots$ , \Call{Eulero}{$v_k$} , InitialVertex )
    \EndIf
	\end{algorithmic}
	\end{algorithm}
```

Complexity : $O(m)$ , where $m=|E|$ ( number of *edges* )

>[!example]
# Hamiltonian


>[!important] Hamiltonian circuit
>A closed path that visits all *verteces* exactly once
>![[HamiltonianCircuit.excalidraw]]

>[!important] Hamiltonian Graph
>A *graph* that contains at least one *hamiltonian circuit*

 This is an **hard** problem

>[!caution] 
>A *bipartite* graph with an *odd* number of *vertex* can't have an *hamiltonian circuit*