---
publish: true
---
The **Vertex Centric Paradigm** allows us to better model the spark algorithms for graphs:
+ Each node knows about its neighbors and exchanges data with them
>[!warning] 
>Graph structure can change from iteration to iteration

+ Each node can hold additional information
+ The *same* computational *kernel* is executed *for* each *node*
+ Repeat until convergence
## Compute Connected Components

### Label Propagation

*Hypotesis* : 
+ Each node $X$ knows its neighbours $N(X)$ with $X \in N(X)$
+ Each node and connected component is *identified* via a numerical id
+ Initially node $X$ is assigned to connected component with id $X_{min} = X$ 

```pseudo
	\begin{algorithm}
	\caption{Label Propagation}
	\begin{algorithmic}
	\State Each node $X$ sends its own component id $X_{min}$ to all its neighbours $N(X)$
	\State Each node $X$ receives a list of component ids and computes the minimum among them , this is the new $X_{min}$
	\State Repeat until convergence 
	\end{algorithmic}
	\end{algorithm}
```

>[!note] 
>$O(d)$ complexity where $d$ is the *diameter* of the graph

#### MapReduce Implementation

```python
def map(key: X, value: [X_min, N(X)]):
	for Z in N(X):
		emit(Z, X_min) # (recipient, message)
	emit(X, N(X))      # preserve graph information

def reduce(key: X, values:[N(X), X_min, Z_min, Y_min, ...]):
	X_min = min([X_min, Z_min, Y_min, ...])
	emit(X, [X_min, N(X)])
```

Repeat until converence 

>[!note] 
>The output of the *reduce* is the input of the *map*

### Hash-To-Min

Each node $X$ has a new $C(X)$ 

>[!note] 
>Initially $C(X)=X \cup N(X)$

Eventually :
$C(X)$ *equals* to the *node* with *minimum id* in the same connected component of $X$ **or** $C(X)$ includes all the nodes of a connected component

```pseudo
	\begin{algorithm}
	\caption{Hash-To-Min}
	\begin{algorithmic}
	\State Each node $X$ computes $C_{min}$ being the smallest node in $C(X)$ 
	\State Each node $X$ sends $C(X)$ to node $C_{min}$ and $C_{min}$ to every node in $C(X)$
	\State Each node $X$ merges together all the node sets recieved, this is the new $C(X)$
	\State Repeat until convergence
	\end{algorithmic}
	\end{algorithm}
```

>[!note] 
>Complexity is $O(\log(d))$ where $d$ is the diameter of the graph

#### MapReduce Implementation

```python
def map(key: X, value:C(X)):
	C_min = min(C(X))
	emit( C_min, C(X) ) # send C(x) to C_min
	for Z in C(X):
		emit(Z, C_min)  # send C_min to every node in C(X)
		
def reduce(key: X, value:[C(Z), C(Y), ...]):
	C(X) = C(Z) + C(Y) + ... # union
	emit(X, C(X))  # new X(X) for next iteration
```

The output of the *reduce* is the input of the *map* for the next iteration , repeat until convergence
## Counting Triangles

*Assumptions* : 
+ Consider only *undirected graphs* 
+ Every node has an associated integer id 
+ An edge $(A,B)$ implies $A < B$
+ $N(X)$ stores the neighbors of $X$ with larger id 

Consider each triange as a triplet $(X,Y,Z)$

We know that partitioning to the *reducers* is based on the *keys* produced by the mappers 

>[!error] 
>We cant have the key as the triplet $(X,Y,Z)$ since if we have $N$ nodes we could have $N^3$ and have one triangle per reduce , inefficent

We want to ship multiple triangles to one reducer 

**Hash** the nodes into $B$ buckets :
+ given an hash function $h$ that maps a node into $[0,B-1]$ 
+ $(X,Y,Z)$ becomes $(h(X),h(Y),h(Z))$

This creastes $B^3$ different triplets and so $B^3$ *reducers*

```python
def map(key: X, value: Y): # edge (X,Y)
	for b in 0...B-1:
		emit(<h(X),h(Y),b>, [X,Y])
		emit(<h(X),b,h(Y)>, [X,Y])
		emit(<b,h(X),h(Y)>, [X,Y])

def reduce(key:<b1,b2,b3>, values: [[X,Y], [U,V], ...]):
	traingles = count_triangles([[X,Y], [U,V], ...])
	emit(<b1,b2,b3>, triangles)

def count_triangles(graph G):
	triangles = 0
	for edge E=(U,V) in the graph G:
		triangels += len(set_intersect(N(U),N(V)))
	return triangles
```

