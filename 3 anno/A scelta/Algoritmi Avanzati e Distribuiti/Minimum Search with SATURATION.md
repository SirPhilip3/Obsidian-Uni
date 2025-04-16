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
		\State $\qquad$ send(Activate) to N(x);
		\State $\qquad$ min:=v(x) 
		\Comment{min will be the value of the node itself}
		\State $\qquad$ Neighbours:=N(x)
		\If{|Neighbours|=1}
			\State $\qquad$ M:=("Saturation", min)
			\Comment{if I am a leaf the minimum is my value}
			\State $\qquad$ parent <= Neighbours
			\State $\qquad$ send(M) to parent
			\State $\qquad$ \textbf{become} PROCESSING
			\Else 
			\State $\qquad$ \textbf{become} ACTIVE
        \EndIf
		\State $\quad$ Receving(M)
		\State $\quad$ send(Activate) to N(x);
		\State $\quad$ min:=v(x) 
		\Comment{min will be the value of the node itself}
		\State $\quad$ Neighbours:=N(x)
		\If{|Neighbours|=1}
			\State $\qquad$ M:=("Saturation", min)
			\State parent <= Neighbours
			\State send(M) to parent
			\State \textbf{become} PROCESSING
			\Else 
			\State \textbf{become} ACTIVE
        \EndIf
    \State ACTIVE
	    \State $\quad$ min := MIN\{min ,M\}
	    \State $\quad$ Neighbours := Neighbours - \{sender\} 
	    \If{|Neighbours|=1}
			\State $\qquad$ M:=("Saturation", min)
			\State $\qquad$ parent <= Neighbours
			\State $\qquad$ send(M) to parent
			\State \textbf{become} PROCESSING
        \EndIf
    \State PROCESSING
    
	\end{algorithmic}
	\end{algorithm}
```

