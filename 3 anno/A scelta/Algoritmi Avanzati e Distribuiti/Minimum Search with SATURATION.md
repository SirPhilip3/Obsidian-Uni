We can use the [[SATURATION technique]] to solve problems , in this case finding the minimum in a distributed system with *tree topology* 

At the end of the algorithm each *entity* should know whether it is the minimum or not 
# Algo 

The algorithm is very similar to the [[SATURATION technique]] the only difference is that with the saturation message we will also send the minimum value seen until now

>[!note] 
>Values are not necessary distinct , so if there are multiple minimum values all of them must become *minimum*

We will have 5 states $S=\{AVAILABLE,ACTIVE,PROCESSING,MINIMUM,LARGE\}$
$Sinit = AVAILABLE$

```pseudo
	\begin{algorithm}
	\caption{FindMin}
	\begin{algorithmic}
	\State AVAILABLE
		\State $\quad$ Spontaneusly
		\State 
	\end{algorithmic}
	\end{algorithm}
```
