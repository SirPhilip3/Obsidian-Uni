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

## Algorithm

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

### Breadth-First Search

Search is implemented like a *FIFO* list

>[!example] 
>![](https://v.redd.it/hzx5bc9y7o241/DASH_1080)
>

For each *level* of the *tree* we will espand each *node* and put on the list $L$ all the *neighbours* at that level before moving on with the next *level*

>[!note] Assumptions
>+ The search tree has a constant branching factor $b$ 
>+ The first *goal* at at depth $d$

#### Evaluation

+ *BFS* is **complete** since we will search all the possible *nodes* 
+ It's **optimal** since we will find the solution at the smallest depth $d$ 

##### Temporal Complexity

>[!note] 
>At level $d$ the number of *nodes* are $b^d$ 

The number of *nodes* to examine to reach depth $d$ is : 
$$1+b+b^2+\dots + b^{d-1} = \frac{b^d -1}{b-1}$$
>[!note]
>This is a [Geometric Series](https://mathworld.wolfram.com/GeometricSeries.html)



### Depth-First Search

### Iterative deepening

