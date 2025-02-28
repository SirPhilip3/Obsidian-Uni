The *longest processing time* it's an improvment of the [[List Scheduling]] algorithm 

In the preprocessing step we simpliy reorder the list of  jobs in *decresing* order

```pseudo
	\begin{algorithm}
	\caption{List Scheduling}
	\begin{algorithmic}
	\Input $m, n , t_1, t_2, \dots , t_n$
	\State $\color{red}\text{Sort jobs so that } t_1\geq t_2\geq \dots \geq t_n$
	\For{i = 1 to m}
		\State $L_i \leftarrow 0$
		\Comment{Load on machine $i$, initially $0$}
		\State $J(i) \leftarrow \emptyset$
		\Comment{Jobs assigned to machine $i$ , initially $\emptyset$}
    \EndFor
    \For{j = 1 to n}
	    \State $i = \min_k L_k$
	    \Comment{Machine $i$ has the smallest load}
	    \State $J(i) \leftarrow J(i) \cup \{j\}$
	    \Comment{Assegna job $j$ to machine $i$}
	    \State $L_i \leftarrow L_i + t_j$
	    \Comment{Update the load of machine $i$}
    \EndFor
    \Return $J(1),\dots , J(m)$
	\end{algorithmic}
	\end{algorithm}
```

# Approximation discussion

>[!important] Theorem 
>**Longes Processing Time** is a $1.5$-approximation algorithm

## $\rho$ proof

>[!note] Lemma 3 
>If there are more than $m$ *jobs* than $L^* \geq 2 \cdot t_{m+1}$ 
>>[!note] Proof
>>Since the $t_i$ are in descending order by construction , than each one of will take at least $t_{m+1}$ time ( the lowest time )
>>Since there are $m$ *machines* and $m+1$ *jobs* than at least one machine get's two jobs 

Returning to the basic [[List Scheduling]] approach we will have that : 
$$L_i = (L_i - t_j) + t_j$$
We know that :
+ $L_i - t_j \leq L^*$ : trivially because we don't include the last *job*
+ $t_j \leq \frac{1}{2}L^*$ : we can assume that the number of *jobs* are $>m$ and the last scheduled *job* $t_j\leq  t_{m+1}\leq L^*/2$ ( because of *Lemma 3* )

Applying the sobstitution we will have that : 
$$L_i \leq L^* + L^*/2 \leq 1.5\cdot L^*$$

>[!note] 
>it can be demonstrated that the real $\rho$ value is $4/3$

