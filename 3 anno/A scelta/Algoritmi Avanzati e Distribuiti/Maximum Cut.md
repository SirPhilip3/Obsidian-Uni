# The Problem

Given an *undirected* graph $G=(V,E)$ with *weights* on the edges that are *positive* *integers* , find a partition $(A,B)$ of nodes such that the total weight of edges crossing the cut ( edges that connects two nodes of different partitions ) is *maximized*

# Single-flip Neighborhood

Given a partition $(A,B)$ move one node from $A$ to $B$ or from $B$ to $A$ if it improves the solution ( higher weight ) 

```pseudo
	\begin{algorithm}
	\caption{Max-Cut-Local}
	\begin{algorithmic}
	\State Pick a random node partition $(A,B)$
	\While{$\exists$ an improving node $v$}
		\If{$v$ is in $A$}
			\State move $v$ to $B$        
		\Else
	        \State move $v$ to $A$
		\EndIf
    \EndWhile
    \Return $(A,B)$
	\end{algorithmic}
	\end{algorithm}
```

>[!warning] 
>This is not a poly time algorithm since the number of iteration are not bound by anything 

We can add a stopping criterion : 
+ When the sum of the weight in each partitions is lower than the weight of the *cut* we can stop the algorithm

## $\rho = 1/2$ proof

>[!important] Theorem
>Let $(A,B)$ be a *local optimal* partition and let $(A^*,B^*)$ be the *optimal* partition
>
>Than $w(A,B) \ge \frac{1}{2}\sum_e w_e \ge \frac{1}{2}w(A^*,B^*)$

Since $(A,B)$ is a *local optimal* partition for any $u\in A$ than :
$$\sum_{v \in A} w_{uv} \leq \sum_{v\in B}w_{uv}$$ Let's sum up for all $u \in A$ :
$$\sum_{u\in A}\sum_{v \in A} w_{uv} \leq \sum_{u\in A}\sum_{v\in B}w_{uv}$$
Now :
+ $\sum_{u\in A}\sum_{v \in A} w_{uv} = 2\sum_{\{u,v\}\subseteq A}w_{uv}$ this because in the first case we will sum twice each edge in $A$ ( $a,b$ and $b,a$ ) and so it's equal to $2\times$ the weight of the single edges
+ $\sum_{u\in A}\sum_{v\in B}w_{uv} = w(A,B)$ since one vertex will be in $A$ and one in $B$ ( this is the definition of *cut* ) 
$$2\sum_{\{u,v\}\subseteq A}w_{uv}\leq w(A,B)$$
$$\sum_{\{u,v\}\subseteq A}w_{uv}\leq \frac{1}{2}w(A,B)$$
The same can be done summing all $u\in B$ : 
$$2\sum_{\{u,v\}\subseteq B}w_{uv}\leq w(A,B)$$
$$\sum_{\{u,v\}\subseteq B}w_{uv}\leq \frac{1}{2}w(A,B)$$
Than when can write that : 
$$\sum_{\{u,v\}\subseteq A}w_{uv} + \sum_{\{u,v\}\subseteq B}w_{uv} + w(A,B)\leq 2w(A,B)$$
So the sum of all the edges in $A$ , in $B$ and in the *cut* is $\leq 2w(A,B)$ , than the total weight of the *global optimum* will certanly be $\leq$ in respect to this so :
$$w(A^*,B^*) \leq 2 w(A,B)\implies w(A,B) \geq \frac{1}2 w(A^*,B^*)$$
## Improvments

The algorithm can be improved reaching a maximum aproximation of $\frac{16}{17}$
