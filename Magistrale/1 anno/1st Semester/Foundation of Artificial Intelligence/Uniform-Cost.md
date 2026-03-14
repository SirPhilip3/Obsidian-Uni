---
publish: true
---
Also called *Dijkstra* algorithm it is guided by the minimum cost of a path 

We assume that each path has a different cost and that there is a *minimum* cost $\epsilon$ 

This algorithm behaves like [[Best First Search]] where the *evaluation* function is the cost of the path from the root to the current node 

>[!note] Implementation
>This can be implemented using an *heap*

## Complexity

Let : 
+ $C^*$ be the *path lenght* of the *optimal solution*
+ $\epsilon$ be the minimum cost of any *action* 

**Worst case** *time* and *space* complexity :
$$O(b^{1+\lfloor C^* / \epsilon \rfloor})$$
>[!warning] 
>This can be much *greater* than $b^d$ 

>[!note] 
>If all *action* costs are equal than the complexity becomes : $b^{d+1}$ , similar to [[Breadth-First Search]]

It's **complete** and **cost-optimal**
