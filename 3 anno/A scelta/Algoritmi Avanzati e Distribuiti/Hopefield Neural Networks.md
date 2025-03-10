>[!note] Hopefield Network Problem
>Simple model of an associative memory in which a large collection of units are connected by an underlying network and neighboring units try to correlate their states 

**Input** : Graph $G=(V,E)$ with weights ( as integers ) on the edges

**Configuration** : Assigning to a node $s_u$ a value of $\pm 1$

**Intuition** : 
+ If $w_{uv}<0$ than $u$ and $v$ need to have the *same* state 
+ If $w_{uv} > 0$ than $u$ and $v$ need to have *different* state

>[!important] 
>In generale no configuration respects all constraints

>[!note] *Good* edge
>Considering a configuration $S$ , *edge* $e=(u,v)$ is *good* if $w_e s_u s_v < 0$ ( so if $w_e <0$ than $s_u = s_v$ and if $w_e >0$ $s_u \neq s_v$ )

>[!note] *Satisfied* node
>Considering a configuration $S$ a node $u$ is *satisfied* if the total absolute weight of all *good* edges incident to $u$ is at least as large as the total absolute weight of all *bad* edges incident to $u$

>[!note] *Stable* configuration
>A configuration is *stable* if all nodes are *satisfied* 

>[!important] 
>The ultimate goal is to find a *stable* configuration if it exists

# State-flipping algorithm

```pseudo
	\begin{algorithm}
	\caption{Hopefield-Flip}
	\begin{algorithmic}
	\Input G, w
	\State $S \leftarrow$ arbitrary start configuration
	\While{Current configuration is not stable}
		\State $u \leftarrow$ one unsatisfied node
		\State $s_u = -s_u$ 
		\Comment{Flip it's state}
    \EndWhile
    \Return $S$
	\end{algorithmic}
	\end{algorithm}
```
>[!example] 
>#todo

## Termination Proof

>[!important] Theorem
>The *algorithm* terminates with a *stable* configuration after at most $W = \sum_e |w_e|$ iterations 
### Proof 

Let's consider a measure of progress as $\Phi(S) =\sum_{e\ good}|w_e|$ ( the total absolute weight of all *good* edges in the network )

Let's confirm that this measure always increases : 

+ Since we always add positive integers clearly $\Phi(S) \ge 0$ 
+ Since at most all of the edges will be *good* we also have an upper bound : $\Phi(S)\leq W$ , where $W=\sum_e |w_e|$ 

Now suppose that we are in a *nonstable* configuration $S$ and we flip the *state* of a node $u$ resulting in a new configuration $S'$ 

>[!note] 
>When we flip the *state* of $u$ all the *edges* incident to $u$ :
>+ *bad* will become *good*
>+ *good* will become *bad*
>
>And the edges that wheren't incident will remain the same 
>

Let :
+ $g_u$ be the total absolute weight of the *good* edges *incident* to $u$
+ $b_u$ be the total absolute weight of the *bad* edges *incident* to $u$
>[!note] 
>$g_u$ and $b_u$ are the weights before the *flip*

Than we will have that :
$$\Phi(S') = \Phi(S) - g_u + b_u$$
This is true since the *good* $g_u$ will become *bad* and be subtracted from $S$ and the other way around for $b_u$ 

Since $u$ is *unsitisfied* we know that $b_u > g_u$ and since they are both integers we can write that $b_u \ge g_u +1$ , by substitution we will have : 
$$\Phi(S') \ge \Phi(S) +1 $$
This shows us that the value of $\Phi$ *increases* by at least $1$ with every flip until it reaches the maximum of $W$ when it will **Terminate** 

>[!warning] 
>The execution time could be big if the weights are big 

