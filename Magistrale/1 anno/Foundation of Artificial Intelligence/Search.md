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

Search is implemented like a *FIFO* ( First In First Out ) list

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

The number of *nodes* to examine to *reach* depth $d$ is : 
$$1+b+b^2+\dots + b^{d-1} = \frac{b^d -1}{b-1}$$
>[!note]
>This is a [Geometric Series](https://mathworld.wolfram.com/GeometricSeries.html)

The average number of nodes explored at depth $d$ is : 
$$\frac{1+b^d}{2}$$
The total time complexity is : 
$$\frac{b^d-1}{b-1} + \frac{1+b^d}{2} = \frac{b^{d+1} + b^d + b -3}{2(b-1)} = O(b^d)$$
>[!note] 
>The final time complexity is *dominated* by the last *level*

##### Spatial Complexity

Since for each *level* we need to memorize all the next neighbours , the maximum *spatial complexity*  will be achieved at the last *level* of
the search : $O(b^d)$
### Depth-First Search

The *search* is implemented in a *LIFO* ( Last In First Out ) way , this result in the search exploring fully one route of the *tree* at a time

>[!example] 
>![](https://static-assets.codecademy.com/Courses/CS102-Data-Structures-And-Algorithms/Breadth-First-Search-And-Depth-First-Search/Depth-First-Tree-Traversal.gif)

#### Evaluation

This algorithm is **not** *complete* : if there is a path that has infinite depth towards the side from where the algorithm starts than it will never explore the other branches where a solution may exist

>[!example] 
>![](https://www.baeldung.com/wp-content/uploads/sites/4/2021/09/dfs-2-1024x570.jpg)


This algorithm is **not** *optimal* : if the problem has more than one solution it may not find the one at minimum depth

>[!example] 
>![](https://www.baeldung.com/wp-content/uploads/sites/4/2021/09/dfs-1-1024x507.jpg)

##### Temporal Complexity

>[!important] Assumptions
>+ Constant branching factor $b$
>+ Depth $d$
>+ There is *one* goal and it is at depth $d$

>[!warning] 
>These conditions are really restrictive and arbitrary for example in reality we don't know if there is only *one* goal and at what *depth* it is

**Best** case : 
	The *goal* is positioned in the far *left* of the tree , than we will need to explore only $d+1$ nodes

**Worst** case : 
	The *goal* is at the far *right* of the tree , this impliest that the whole tree needs to be explored :
$$1 + \dots + b^d = \frac{b^{d+1}-1}{b -1}$$
**Average** case : 
$$\frac{\frac{b^{d-1}-1}{b-1} + (d+1)}{2} = \frac{b^{d+1}+bd+b-d-2}{2(b-1)}$$

##### Spacial Complexity

The maximum memory required is : 
$$d(b-1)+1 = O(db)$$
This is because the length of the longest path is $d$ ( the level at which the goal resides ) , for each node we need to store it's siblings ( except the one counted in the length of the path ).

### Iterative deepening

Perfoms *Depth-First search* up to depth $C$ , if the *goal* is not found at level $C$ increase it until the *goal* is found

```python
iterative_deepening(G , source , is_goal) :
	C=0
	while C<max_depth :
		L=[source] # reinitialize list and
		# restart with new C
		while L : 
			n = L.pop() # extract from the top
			if is_goal(n) :
				return path ( source , n )
			# visit adjacent nodes if depth < C
			if depth(n)<C :
				children = G.adjacent(n)
				L.append(children)
		C+=1 # inrease C and restart
	return FAIL 
```

>[!example] 
>![](https://www.baeldung.com/wp-content/uploads/sites/4/2021/09/id-768x665.jpg)

>[!note] 
>For each iteration of $C$ the algorithm re-explores the whole tree even if the previous iteration would have already explored upper nodes 
>
>This is not an issue since the last layer will always rapresent the "biggest effort" performed by the algorithm
>

#### Evaluation

+ **Complete** 
>[!warning] 
>Only if no node has an infinite number of childrens
+ **Optimal** 

##### Temporal Complexity

>[!warning] 
>This is the time complexity give in [baeldung](https://www.baeldung.com/cs/iterative-deepening-vs-depth-first-search) , different from the slides

The algorithm explores the start node $d+1$ times , it's children $d$ times and so on
It explores the nodes at depth $d$ only one time since the *goal* is at depth $d$ 

The number of children for each node will be the following : 
+ No more than $b$ children at the start node
+ No more than $b^2$ children for the nodes at depth $2$ etcc

The total number of explored nodes will be :
$$(d+1) + db + (d-1)b^2 + \dots + b^d = O(b^d)$$
##### Spacial Complexity

Since at each iteration the algorithm performs *Depth-First search* teh memory required equals that of *DFS* with an added constant for $C$ :
$$d(b-1) + 2 = O(db)$$
