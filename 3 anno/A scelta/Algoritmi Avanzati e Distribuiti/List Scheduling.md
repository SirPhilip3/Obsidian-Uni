This is a [[Strutture Dati#Algoritmi Greedy|greedy]] algorithm that considers the jobs to schedule in a fixed order ( a list ) and assigns *job* $j$ to the *machine* that has the lowest **Load** so far 

```pseudo
	\begin{algorithm}
	\caption{List Scheduling}
	\begin{algorithmic}
	\Input $m, n , t_1, t_2, \dots , t_n$
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
 
Where : 
+ $m$ : number of *machines*
+ $n$ : number of *jobs* 

>[!note] 
>If we utilize a [[Strutture Dati#Code di Priorità|priority queue]] to rapresent the *Loads* of each machine the complexity becomes $O(n \log m)$ instead of $O(n \cdot m)$ ( since we would have had to explore the entire list to find the minimum load )

>[!example] 
>#todo

# Approximation discussion

>[!important] Theorem
**List scheduling** is a $2$-approximation algorithm 
## $\rho$ proof

>[!note] Lemma 1
>The *optimal* **makespan** $L^*$ will always be $\geq \max_j t_j$ 
>
>>[!note] Proof
>>


>[!note] Lemma 2
>The *optimal* **makespan** $L^*$ will always be $\geq \frac{1}{m} \sum_j t_j$
>