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

#todo 
