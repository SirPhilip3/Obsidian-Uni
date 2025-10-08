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
>	rankdir=LR;
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

>[!example] Heuristics for the [game of 8](https://en.wikipedia.org/wiki/15_puzzle)
>
>We define 2 heuristics : 
>+ $h'_1(n)$ : number of *missplaced* tiles
>+ $h'_2(n)$ : sum of the [[Manhattan distance]] of each tile to it's desination 

### Best First Search ( Greedy )

