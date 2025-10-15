---
publish: true
---
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