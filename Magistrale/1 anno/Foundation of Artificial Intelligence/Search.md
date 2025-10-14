**Search** algorithms are the backbone of AI. They allow the systematic exploration of alternatives 

We can have : 
+ **Uninformed** ( *blind* ) search : 
	We only know the *current state* and states that are reachable through a single action ( the *neighbours* )
+ **Informed** ( *heuristic* ) search : 
	We have means to asses progress toward the *goal* state 

In general a problem in AI can be solved by *reducing* it to a problem that can be attributed to the *search* on a [[Graphs|graph]] 

In order to *reduce* a problem to a graph search :
+ *states* become all the relevant aspects of the problem
+ *actions* become what can be performed on the states
+ *goal test* the condition for success 

>[!example] Trip
>+ *states* : the cities ( ex Vicenza, Padova, Venezia etcc )
>+ *actions* : moving to a new city 
>+ *goal test* : reaching your destination
>``` dot
>graph G {
>    rankdir=LR;
>    Vicenza -- Padova ;
>    Padova -- Treviso ;
>    Treviso -- Venezia;
>    Venezia -- Padova;
>    Venezia [peripheries=2]
>}
>```

## Graph Search

Since we have efficent algorithm to perform the search on a *Tree* we will convert the *graph* in a *tree* in the following way : 

+ Replace undirected links by $2$ directed links ( back and forward )
+ Avoid loops

The resultin *tree* will have numerous duplicated nodes since there may be multiple paths to the same node in the *graph*

>[!example] 
>```dot
>digraph G {
>  compound=true; // permette agli archi di attraversare i cluster
>    subgraph cluster_0 {
>        style=filled;
>        color=lightgrey;
>        node [style=filled,color=white];
>        Sg -> Ag -> Dg -> Gg;
>        Sg -> Bg -> Dg;
>        Bg -> Gg;
>        Dg -> Cg;
>        Ag -> Cg;
>        Sg [label="S"];
>        Ag [label="A"];
>        Bg [label="B"];
>        Cg [label="C"];
>        Dg [label="D"];
>        Gg [label="G"];
>        label = "Graph";
>
>        // nodo fittizio per collegare il cluster
>        cl0 [label="", shape=point, style=invis];
>    }
>
>    subgraph cluster_1 {
>        node [style=filled];
>        S -> A -> D -> C;
>        D -> G;
>        S -> B;
>        A -> C1;
>        B -> D1;
>        B -> G1;
>        D1 -> C2;
>        D1 -> G2;
>        D1 [label="D"]
>        C2 [label="C"]
>        C1 [label="C"]
>        G1 [label="G"]
>        G2 [label="G"]
>        
>        label = "Tree";
>        color=blue;
>
>        // nodo fittizio per collegare il cluster
>        cl1 [label="", shape=point, style=invis];
>    }
>
>    // freccia tra cluster (in realtà tra i nodi fittizi)
>    cl0 -> cl1 [lhead=cluster_1, ltail=cluster_0];
>
>}
>```

## Evaluating

4 criteria to evaluate a *search algorithm* :
+ **Completeness** : will it find a solution if one exists
+ **Optimality** : will the algorithm find the *best* solution if one exists
+ **Temporal Complexity** : time to solution find a solution 
+ **Spatial Complexity** : memory required

## Stab Algorithm

We can build an initial schema to implement the *search procedure* : 
```python
search(G , source , is_goal):
	L=[source] # list of visited but
	# not expanded nodes
	while L:
		n = extract_from(L) # expand node n
		# the policy with which we get the node changes the algo
		if is_goal(n) : # goal node found
			return path(source , n)
		# goal not found , visit adjacent nodes
		children = G.adjacent(n)
		insert_into(L , children) # changes the algo
return FAIL # goal not present in G 
```

Where *nodes* can be in two states : 
+ *visited* : 
	when they are encountered and placed in the list $L$ 
+ *expanded* :
	when they are removed from $L$ (`extract_from`) and subjected to the *goal test* (`is_goal`) and its *neighbours* are inserted in $L$ (`insert_into`) ( they become *visited* )

>[!important] 
>The type of the algorithm used depends on the implementation of the `extract_from` and `insert_into` functions
>

## Implementations : 

+ [[Breadth-First Search]]
+ [[Depth-First Search]]
+ [[Iterative deepening]]
+ [[Uniform-Cost]] ( *Dijkstra* )

## Heuristic Search

In this case we can exploit a task-specific *measure of goodness* in order to "guide" the search

>[!important] Definition
>$h'(n)$ is an *heurisitc function* such that : 
>+ $h'(n)$ assigns to each *node* $n$ an *estimate* of the optimal path lenght from $n$ to the *goal* node
>+ $h'$ is *non-negative* 
>+ $h'(n)=0 \iff n$ is a *goal* node 

>[!example] Heuristics for the *sliding* [game of 8](https://en.wikipedia.org/wiki/15_puzzle)
>
>We define 2 heuristics : 
>+ $h'_1(n)$ : number of *missplaced* tiles
>+ $h'_2(n)$ : sum of the [[Manhattan distance]] of each tile to it's desination 
>>[!example] 
>>Let's consider the following position for the *game of 8* and compute the two *heuristics*
>>
>>![[game8init.excalidraw.png]]
>>%%[[game8init.excalidraw.md|🖋 Edit in Excalidraw]]%%
>>
>>$h'_1(n) = 7$ : only one tile is placed correctly ( $2$ )
>>$h'_2(n) = 4 + 0 +2 +3 +1+3+1+3 = 17$ : the distance between $1$ and it's goal position is $4$ tiles $+$ $2$ is in the correct position so the distance is $0$ and so on 
>>
>>

### Admissible Heuristic

An *admissible heuristic* is one that *never overestimates* the cost to reach a goal 

### Consistent Heuristic

A *heuristic* is **consistent** if from every node $n$ , every successor $n'$ of $n$ generated by any action $a$ with cost $c(n,a,n')$ will have that : 
$$h'(n) \le c(n,a,n') + h'(n')$$
![[Pasted image 20251013111937.png]]

>[!note] 
>This is a form of *triangualr inequality*

Given this result we can also determine that the *heuristic* must be *monotonic* 

Consider that : 
+ $g(n)$ is the path cost from the initial state to node $n$ 
+ $h'(n)$ is the *estimated* cost of the *shortest* path from $n$ to the goal state
$$\begin{align*}
f (n') &= g (n') + h'(n') \\
&= g (n) + c(n, a, n') + h'(n') \\
&\ge g (n) + h'(n) \\
&= f (n)
\end{align*}$$
$f(n)$ is than a *monotonically increasing* function since passing through $1$ more node will always be more expensive than the normal path 
#explain
### Algorithms

#### Best First Search ( Greedy )

**BFS** always explores the most promising path first  

The implementation cab be obtained by selecting from $L$ in the *stab algorithm* the node with the minimal value of the *expected distance* to the goal ( the value of the *heuristic function* $h'$ )

```python
search(G , source , heuristic , is_goal ) :
	L =[ source ] # list of visited but not expanded nodes
	while L :
		n = extract_min (L , heuristic )
		# expand node with minimum heuristic
		
		if is_goal ( n ) : # goal node found
			return path ( source , n )
		
		# goal not found , visit adjacent nodes
		children = G . adjacent ( n )
		insert_into (L , children ) # anywhere
	return FAIL # goal not present in G
```

>[!example] 
>
>![[Pasted image 20251013113350.png]]

##### Evaluation

+ It's *not complete* since it can get stuck in *loops*
+ It has $O(b^m)$ *time complexity* 
>[!note] 
>Good *heuristics* can improve performance by a lot
+ It has $O(b^m)$ *space complexity* since it keeps all the nodes in memory
+ It's *not optimal*

>[!example] Example of non optimality
>![[notoptgreedyex.excalidraw.png]]
>%%[[notoptgreedyex.excalidraw.md|🖋 Edit in Excalidraw]]%%
#### A*

It's a *variation* of [[Best First Search (Greedy)]] where the *evaluation* function is : 
$$f(n) = g(n)+ h'(n)$$
Where : 
+ $g(n)$ is the path cost from the initial state to node $n$ 

This adds a "penalty" for the *lenght* of the path to the *evaluation function*

>[!example] 
>![[AstarExploration.excalidraw.png]]
>%%[[AstarExploration.excalidraw.md|🖋 Edit in Excalidraw]]%%


>[!example] Shortest path search
> ![[Pasted image 20251013141018.png]]

##### Evaluation

**Optimality** : if $h'$ is a [[Consistent Herusitic]] than $A^*$ is *optimal* : 

>[!important] Proof
>
>Let : 
>+ $s$ be an *optimal* *goal* node 
>+ $x$ a *non-optimal* one
>+ $n_0,n_1,\dots, n_k = s$ be the path from the root to $s$ , for all $i=0,\dots,k$ we have that $f(n_i)< f(x)$ 
>

We can in fact say that 
$$f(n_i) = g(n_i) + h(n_i)$$
#### Iterative Deepening A*

