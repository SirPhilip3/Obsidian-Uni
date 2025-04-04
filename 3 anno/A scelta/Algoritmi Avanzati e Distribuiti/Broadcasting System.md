---
publish: true
---
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

>[!note] 
>In an *asyncronous* system there are diffrerent executions that can depend on the speed of the messages

# Proofs

## Termination

>[!note] Local Termination
>The *entities* terminate the computation ad different instants of time ( when they enter the *done* state ) , this means that there is no *global termination* , only *local termination*

>[!note] Termination Detection Problem
>No *entity* knows when the entire process terminates ( *termination detection problem* )

Eventually every *entity* that recieve the message ( this will happend because of the *correctness proof* ) will move to the state *done* and will therefore *terminate*
## Correctness

If $G$ is *connected* and there is *total reliability* than every *entity* will eventually receive the information
## Complexity

In this case we mesure the **message complexity**  
### Worst Case

In the worst case we will have that $\leq 2$ messagges will be passing on each edge 
Since there are $m$ *edges* in the graph we will have that the maximum number of messages send will be : 
$$\leq 2 m \quad O(m)$$

### Lower Bound