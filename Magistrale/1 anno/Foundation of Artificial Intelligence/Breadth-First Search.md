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