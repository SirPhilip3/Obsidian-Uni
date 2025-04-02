# The Problem

One *entity* wants to send some information to all the other entities of the network 
# Algo

>[!note] 
>We need to define the actions that every entity takes indipendently from which entity starts
## Assumpion / Restrictions

+ We need to have a **Unique Initiatior** ( this is by definition of the problem )
+ The *graph* needs to be **Connected** ( otherwise the problem will be unsolvable )

*Simplifying assumptions :*
+ Total reliability
+ Bidirectional links

>[!info] Idea
>If an *entity* has some data it sends it to it's neighbours
## Algorithm

We will have 3 *states* : $S=\{initiator,sleeping,done\}$ 

```pseudo
	\begin{algorithm}
	\caption{FLOOD}
	\begin{algorithmic}
	\If{INITIATOR}
		\State spontaneous impulse event
		\State $\quad$ Send(I) to N(x)
		\State $\quad$ become(DONE)
		\State receving(I)
		\State $\quad$ do-nothing
    \EndIf
    \If{SLEEPING}
	    \State receiving(I)
	    \State $\quad$ Send(I) to N(x) - \{sender\}
	    \State $\quad$ become(DONE)
		\State spontaneous impulse event
		\State $\quad$ do-nothing
    \EndIf
    \If{DONE}
		\State receiving(I)
	    \State $\quad$ do-nothing
		\State spontaneous impulse event
		\State $\quad$ do-nothing
    \EndIf
	\end{algorithmic}
	\end{algorithm}
```

