# Definitions

>[!important] Path
>A *path* from a node $x$ to a node $y$ of a graph is a sequence of adjacent nodes that connect node $x$ to node $y$
>![[Path.excalidraw]]

>[!important] Closed Path
>A *closed path* is a path that starts from a node and goes back to the same node
>![[ClosedPath.excalidraw]]

>[!important] Simple Path
>A *simple path* is a path without repeated nodes 

>[!important] Circuit
>A *circuit* is a simple closed path

>[!important] Tree
>A *Tree* is an undirected simple graph $G$ that satisfies any of the following conditions : 
>+ *Acyclicl* graph with $|E|=|V|-1$
>+ *Connected* and acyclic
>+ *Acyclic, connected* and by adding an edge it becomes *cyclic*
>![[Tree.excalidraw]]

>[!important] Rooted Tree
>A *rooted tree* is a tree with a node called *root* 
>![[RootedTree.excalidraw]]
> 
>+ *Internal nodes* : Nodes with a *degree* $\ge 2$
>+ *Leaves* : Nodes with *degree* $1$

>[!important] Degree
>A *degree* of a vertex of an undirected graph is the number of *indegree* ( edges that are coming into the vertex ) and *outdegree* ( edges that are going away from the vertex ) edges 

>[!important] Eulerian circuit
>
>A closed path that *visits* *each* *edge* of the graph exactly *once* ( or each *node* at *least* once )
>>[!note] 
>>It needs to start and finish at the same vertex for the definition of *circuit*

>[!important] Hamiltonian circuit
>A closed path that visits all *verteces* exactly once


