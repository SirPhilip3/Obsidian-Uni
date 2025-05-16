---
publish: true
---
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
	    \Comment{Assign job $j$ to machine $i$}
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
>![[output.gif.mp4]]

>[!note] 
>If we have at most $m$ *jobs* than *list scheduling* becomes an optimal algorithm

# Approximation discussion

>[!important] Theorem
>**List scheduling** is a $2$-approximation algorithm 
## $\rho$ proof

>[!note] Lemma 1
>The *optimal* **makespan** $L^*$ will always be $\geq \max_j t_j$ 
>
>>[!note] Proof
>>Some machine will have have to process the most time-consuming job 


>[!note] Lemma 2
>The *optimal* **makespan** $L^*$ will always be $\geq \frac{1}{m} \sum_j t_j$
>
>>[!note] Proof
>>One of $m$ machines must do at least $1/m$ of the total work 

Let's consider a *job* $j$ that has it's finish time as the finish time of the algorithm ( $L_i$ ) , now suppose it was assigned to machine $i$ , than before it was assigned this machine needed to have *load* : $L_i -t_j$ 

Than we will have that : $L_i - t_j \leq L_k$ for all $1\leq k \leq m$ this because we know that $L_i$ is the finishing time and that we assigned only 1 *job* to the machine , this implies that when it was the machine had the lowest *load* ( as per the algorithm ) 

Now the sum of the *load* ( $L_k$ ) of all the machines will need to be greater or equal to the previous *load* of the machine that rapresent the *makespan* of the system multiplied by $m$ ( number of machine ) , this is *true* because $L_i - t_j$ will be the lowest *load* before assigning the last job 
$$\sum_k L_k \ge m\cdot (L_i - t_j)$$
This can be rewritten as : $$L_i - t_j \le \frac{1}{m}\sum_k L_k$$
>[!note] 
>The $\sum_k L_k$ ( *total load* ) is the *total time* $\sum_k t_k$ 

$$L_i - t_j \le \frac{1}{m}\sum_k t_k$$
By **Lemma 2** we can write : 
$$L_i - t_j \le L^*$$
The *makespan* will be :
$$L_i = (L_i - t_j) + t_j \le L^* + L^* \le 2 \cdot L^*$$
>[!note] 
>For **Lemma 1** $t_j \leq L^*$ 

