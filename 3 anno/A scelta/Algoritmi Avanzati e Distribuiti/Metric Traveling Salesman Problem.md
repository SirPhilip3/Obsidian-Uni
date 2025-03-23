# Inapproximability of Traveling Salesman Problem

>[!important] Traveling Salesman Problem ( TSP )
>Given a **complete** graph with a non-negative edge cost find a minimum cost circuit that visits each *vertex* exactly once
>

>[!important] Eulerian Path Problem
>Given an *undirected* graph find a walk visiting every edge exactly once

It can be proven that there is no constant $\rho$ factor approximation algorithm for **TSP** ( unless $P=NP$ )

# The Problem 

Given a *complete* graph with edge costs satisfying *triangular inequalities* , find a minimum cost cycle visiting every *vertex* exactly once

>[!important] Metric graph
>
>A graph is called *metric* if :
>+ For any two *vertices* $u,v$ in the graph than $w(u,v)=w(v,u)$ 
>+ The *Triangle Inequlity* holds if for any three vertices $u,v,x$ in the graph $w(u,v) \leq w(u,x)+w(x,v)$

# $2$-approximation Algorithm

1. Find the [[Strutture Dati#Alberi di copertura minimi|minimum spanning tree]] $MST(G)$ ( using [[Strutture Dati#Algoritmo di Prim|Prim]] this step has complexity $O(m \log n)$ or $O(m + n \log n)$ depending on the data structure used )
2. Double all of it's edges : $T=2\times MST(G)$
3. Since we have doubled each edge than the graph $T$ is *Eulerian* ( all verteces have an even degree and it's connected ) , we can trasverse it visiting each edge exactly once 
4. Create shortcuts in the *Eulerian* tour in order to create a *tour* 

## Shortcuts

Since we don't want to visit each *vertices* more than once , if we encounter a *vertex* already visited than we skip directly over to the next vertex in the tour 

>[!note] 
>Since the graph is complete we know that the shortcut will always exist 
>
>Since we also know that the graph satisfies the *triangular inequality* than that shortcut can't be longer than going to a vertex that we already visited

## $\rho = 2$ proof 

>[!summary] Definitions
>$OPT$ : optimal solution for **Metric-TSP** ( as a set of edges )
>$A$ : edges chosen by the algorithm
>$EC$ : edges in the *Euler* cycle

1. $cost(T)\leq cost(OPT)$ : this is true since *OPT* is a cycle so removing any edge implies building a [[Strutture Dati#Alberi di copertura|spanning tree]] and removing an edge means lowering the cost 

>[!note] 
>**MST** is a lower bound of **TSP**

2. $cost(EC)=2\cdot cost(T)$ : by construction of *EC* ( doubling each edge ) 

This implies that : $cost(EC)= 2 \cdot cost(T) \leq 2 \cdot cost(OPT)$

3. $cost(A) \leq cost(EC)$ : this is true because of *triangular inequalities* , the shortcut will always have a lower cost since we pass trough less *edges*

So in the end we can conclude that : 
$$cost(A) \leq 2 \cdot cost(OPT)$$
# $1.5$-approximation Algorithm

We can get a better approximation if we use **Graph matching** :

>[!important] Graph Matching
>A *matching* $M$ in a graph $G(V,E)$  is a *subset* of *edges* of $G$ so that no *edges* in $M$ are *incident* to a common *vertex* 

>[!example] 
![[matchingGraph.excalidraw]]

>[!important] Perfect Matching
>A perfect matching is a *matching* in whitch every *vertex* si marched ( covered ) 
>>[!note] 
>>In weighted graphs this can have a weight , in the previous example the weight is $16$

>[!note] 
>The matching problem can be solved in *poly time*

## Algorithm

1. Find an [[Strutture Dati#Alberi di copertura minimi|MST]] 
2. Find a $M$ = *Minimum weight Perfect Matching* for the verteces that have an odd degree
3. Add the new nodes to the **MST** : $E = MST + M$  
4. Find an *Euler* walk of $E$ 
5. Bypass repeted nodes on the *Euler* walk with *shortcuts* to get a **TSP** *tour* ( $A$ )

>[!example] 
>#todo
## $\rho = 1.5$ proof

1. $cost(T)\leq cost(OPT)$ : this is true since *OPT* is a cycle so removing any edge implies building a [[Strutture Dati#Alberi di copertura|spanning tree]] and removing an edge means lowering the cost 
2. $cost(M) \leq 0.5 \times cost(OPT)$ : a *tour* always contains $2$ matching this implies that the cost of the *minimum weight perfect matching* is *at most* $0.5 \times cost(OPT)$
3. By combining the cost of the [[Strutture Dati#Alberi di copertura|spanning tree]] ( $T$ ) and the cost of the *matching* ( $E$ ) we will have that : $cost(EC) = cost(T)+cost(M) \leq 1.5\times cost(OPT)$
4. With the *shortcut* we know that $cost(A)\leq cost(EC)\leq 1.5 \times cost(OPT)$

In the end we will have that : 
$$cost(A)\leq 1.5 \times cost(OPT)$$
