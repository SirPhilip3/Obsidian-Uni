# Vertex Cover Pracing Method

## The Problem

>[!important] Weighted Vertex Cover
>
>Given a graph $G$ with some *weights* on the *verteces* find a [[Vertex Cover]] of *minimum* weight

>[!example] 
>#todo

## Pricing Method

Each *edge* must be covered by some *vertex* , each *edge* $e=(i,j)$ pays some price $p_e\geq 0$  to use *verteces* $i$ and $j$ 

>[!important] Fairness
>*Edges* incident to *vertex* $i$ should pay $\leq w_i$ in total , so for each *vertex* $i$ : $$\sum_{e=(i,j)}p_e \leq w_i$$ 
>
>>[!note] 
>>In proctice the sum of all the weight on the *edges* incident to a *vertex* $i$ sould be less or equal to the weight on $i$

>[!important] Lemma
>For any [[Vertex Cover]] $S$ and any fair prices $p_e : \sum_e p_e \leq w(S)$ 
>>[!note] Proof
>>$\sum_{e\in E} p_e\leq \sum_{i \in S}\sum_{e=(i,j)}p_e \leq \sum_{i\in S} w_i = w(S)$
>>+ By definition of [[Vertex Cover]] we have that each edge $e$ is covered by at least one node in $S$ ( $\sum_{e\in E} p_e\leq \sum_{i \in S}\sum_{e=(i,j)}p_e$ ) 
>>+ From the *Fairness* we know that $\sum_{e=(i,j)}p_e \leq w_i$ and so : $\sum_{i \in S}\sum_{e=(i,j)}p_e \leq \sum_{i\in S} w_i$ 

>[!note] Tightness 
>A *vertex* $i$ is **tight** if $\sum_{e = (i,j)} p_e = w_i$

### Algorithm

>[!important] Weighted Vertex Cover
>Given a graph $G$ with $w$ *vertex weight* , find a [[Vertex Cover]] of *minimum* weight

```pseudo
	\begin{algorithm}
	\caption{Weightes-Vertex-Cover-Approx}
	\begin{algorithmic}
	\Input G, w
	\ForAll{e in E}
		\State $p_e=0$ 
		\Comment{Initilly set all the edges weight to 0}
    \EndFor
    \While{$\exists$ edge $i-j$ such that neither $i$ nor $j$ are tight}
	    \State Select this edge $e$
	    \State increase $p_e$ as much as possible until $i$ or $j$ are tight
    \EndWhile
    \State $S \leftarrow$ set of all tight vertex
    \Return $S$
	\end{algorithmic}
	\end{algorithm}
```
### $\rho = 2$ proof

#### Termination

The algotithm terminates because at least one new node become *tight* after each iteration of the while loop , and since the number of *edges* are finite at some point the algorithm will terminate
#### Correctness

Let $S$ be the set of all *tight* nodes when the algorithm *terminates* than :
+ $S$ is a [[Vertex Cover]] 

If some *edge* $i-j$ is uncovered than neither $i$ nor $j$ will be *tight* , but if this is the case than the `while` will not terminate since there are still some *verteces* that are not *tight*
#### Approximation

>[!important] Hypotesis
Let $S^*$ be the optimal [[Vertex Cover]] than $w(S) \leq 2 w(S^*)$

$$w(S) = \sum_{i \in S} w_i = \sum_{i \in S}\sum_{e=(i,j)} p_e$$
This is possible becouse all the nodes in $S$ are *thigh* by definition of the algorithm 
$$\sum_{i \in S}\sum_{e=(i,j)} p_e \leq \sum_{i \in V}\sum_{e=(i,j)} p_e$$
Since $S \subseteq V$ and $prices \geq 0$ ( $V$ is the set of all vertices in the graph $G$ ) 
>[!note] 
>This is the worst case possible , where we select each *edge* twice since we will count the incident *edges* for each *node* 

$$\sum_{i \in V}\sum_{e=(i,j)} p_e = 2 \times \sum_{e \in E}p_e \leq 2 \times w(S^*)$$
This for the *fairness* lemma ( $\sum_{e} p_e \leq w(S)$ )

