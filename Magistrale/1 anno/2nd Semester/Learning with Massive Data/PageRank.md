---
publish: true
---
*PageRank* computes the relevance of a Web page based on the *link structure* 

>[!note] 
>*PageRank* is *independent* of the query

We can measure the **importance** of a node $i$ ( $\pi[i]$ ) in a graph $G$ as the *sum of the **importances** of its neighbours* :
$$
\pi[i] = \sum_{j \to i} \pi[j]
$$
>[!error] 
>This will **never** *converge* since each node *multiplies* the importance that it recieves 

$$
\pi[i] = \sum_{j\to i} \frac{\pi[j]}{o(j)}
$$
Where $o(j)$ is the *out-degree* of node $j$ 

>[!note] 
>Rewritten as *matrix-vector* multiplication : 
>

$$
\pi^{t+1} = M \pi^t \quad \text{with} \quad M[i,j] = \begin{cases}
\frac{1}{o(j)} & \text{if } j \to i \\
0 & \text{otherwise}
\end{cases}
$$
This defines an *iterative process* ( random surfer model ) where we start from a *random vector* $\pi^0$ 

>[!note] 
>$\pi^0$ must sum up to $1$ since it's a *probability distribution*

>[!error] 
>This formulation *converges* only if the original graph $G$ is :
>+ **irreducible** : any state is reachable by any other state 
>+ **aperiodic** : no *cycles* of fixed lenght
>
>>[!warning] 
>>The *Web Graph* does not satisfy this criteria since it presends *dead ends* and *cycles*

## Google Matrix

$$
\pi^{t+1} = \beta M \pi^t +(1-\beta)\cdot 1/n \quad \text{with}\quad M[i,j]=\begin{cases}
\frac{1}{o(j)} & \text{if}\ j \to i  \\
\frac{1}{n} & \text{if}\ o(j) = 0  \\
0 & \text{otherwise}
\end{cases}
$$
In this case we follow : 
+ $M$ with probability $\beta$
+ jump to a random node ( *teleportation* ) with probability $1-\beta$

Also we *remove* dead ends by linking them to every other nodes 
>[!note] 
>This is done by setting $M[i,j]$ to $\frac{1}{n}$ when the *out-degree* ( $o(j)$ ) is $0$ 

>[!note] 
>This reaches stability ( $\pi^{t+1} = \pi^t$ ) in around $50$ *iterations*

### Cost 

Each iteration takes $N^2$ *multiplications* and $N^2$ *addition* so $O(N^2)$

>[!note] 
>$N$ is the number of pages in the graph

The *memory* consumption also strictly linked to the *matrix* 

