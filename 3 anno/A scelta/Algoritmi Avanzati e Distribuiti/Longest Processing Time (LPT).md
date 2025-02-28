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