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
## Message Complexity

In this case we mesure the **message complexity**  
### Worst Case

In the worst case we will have that $\leq 2$ messagges will be passing on each edge 
Since there are $m$ *edges* in the graph we will have that the maximum number of messages send will be : 
$$\leq 2 m \quad O(m)$$
>[!note] More Precisely
>
>Let $s$ be the *initiator* than the total number of messages sent will be : 
>$$|N(s)| + \sum_{x\neq s}(|N(x)-1|)$$
>Than we can write that 
>$$\sum_x |N(X)| - \sum_{x \neq s} 1$$
>$$2m - (n-1)$$
>
### Lower Bound

Since every *entity* must know the information than at least one message must be recieved by each one of the $n-1$ *entities* that initially don't have the information

A better lower bound would be $m$ , this is true since if we don't transmit at least one message per link we could be missing some *entities*

>[!note] 
Since the *worst case* complexity is , in order of magnitude , $O(m)$ we can say that **FLOOD** is a *message-optimal* solution

## Time Complexity

>[!note] Ideal Time
>
>In one unit of time ( this includes all the operations done by an *entity* and the time that takes to send the message ) all the neighbours of an *entity* $x$ will recieve a message 

### Worst Case

Since the first message is sent by the initiator and has to reach all the *entities* we will have that the *worst case* complexity will be the longhest distance between the initiator and any other *entity* ( the so called *radius* of $G$ )

>[!info] Distance
>Let's define the *distance* $d(a,b)$ as the *minimal* number of edges between $a$ and $b$ 

Given that any node can be the initiator we will have that : 
$$D(G) = Max_{x,y}\{ d(x,y)\}$$
In the worst case ( where the graph is a line ) we will have that the maximum distance will be the number of *entities* $-1$ ( this because the initiator already has the data )
$$Time \leq D(G) \leq n -1 = O(n)$$
### Lower Bound

Since every *entity* needs to recieve the information independently from the distance to the initiator than , since the *diameter* of a graph is the maximum minimum distance between two *entities* , the time complexity can't be less :
$$T(Broadcast) \geq Max_{x,y}\{d(x,y)\} = D(G)$$

We can than say that the **FLOOD** solution has *optimal time complexity*

>[!note] 
>As before we can improve the bound until $\Omega(m)$ 
# On Known Topologies

