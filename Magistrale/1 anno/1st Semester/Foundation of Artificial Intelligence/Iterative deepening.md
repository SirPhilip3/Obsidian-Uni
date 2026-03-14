---
publish: true
---
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
>This is the time complexity give in the book ( Artificial Intelligence, A Modern Approach ) , different from the slides

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
