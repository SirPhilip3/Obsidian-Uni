---
publish: true
---
>[!important] Spanning Tree Definition
>A *spanning tree* $T$ of a *graph* $G=(V,E)$ is an *acyclic* subgraph $T=(V,E')$ of $G$ where $E' \subset E$

# SHOUT Protocol

>[!important] Assumptions
>+ *Singe* *initiator* 
>+ Bidirectional link
>+ Total reliability
>+ Connected graph ( otherwise we can't find a *tree* )

1. *Initially* nobody will know what are the edges making up the *spanning tree* 
2. At the *end* of the algorithm every node $x$ will know what links ( of the ones that terminates on himself ) belong to the spanning tree

>[!info] Idea
>1. The *initiator* sends to his neighbours a *question* ( `Do you want to be my neighbour in the spanning tree?` )
>2. An *entity* that recieves a *question* will reply with a `Yes` only if it's the *first time* that they recieve the question , and they will also forward the question to all of it's neighbours , *otherwise* the it will reply `No` and will not forward the question
>3. An *entity* *terminates* when it has recieved a reply from all *neighbours* to which it asked the question

*States* $S=\{INITATOR,IDLE,ACTIVE,DONE\}$
*Sinit* = $\{INITIATOR,IDLE\}$
*Sterm* = $\{DONE\}$

```pseudo
\begin{algorithm}
\caption{SHOUT}
\begin{algorithmic}
\State INITIATOR
	\State $\quad$ Spontaneusly
		\State $\qquad$ root := true
		\State $\qquad$ Tree-neighbours := \{\}
		\State $\qquad$ send(Q) to N(x)
		\State $\qquad$ counter := 0
		\State $\qquad$ become ACTIVE
\State IDLE
	\State $\quad$ receiving(Q)
		\State $\qquad$ root := false
		\State $\qquad$ parent := sender
		\State $\qquad$ Tree-neighbours := \{sender\}
		\State $\qquad$ send(yes) to sender
		\State $\qquad$ counter := 1
		\If{counter = $|N(x)|$} 
		\Comment{In this case we only have 1 neighbour , we are a leaf}
		\State become DONE
        \Else 
        \State send(Q) to N(x)-\{sender\}
        \State become ACTIVE
        \EndIf
\State ACTIVE 
	\State $\quad$ receiving(Q)
	\State $\qquad$ send(no) to sender
	\State $\quad$ receiving(yes)
	\State $\qquad$ Tree-neighbours := Tree-neighbours $\cup$ sender
	\State $\qquad$ counter := counter + 1
	\If{counter = $|N(x)|$}
	\State become DONE
    \EndIf
	\State $\quad$ receiving(no)
	\State $\qquad$ counter := counter + 1
	\If{counter = $|N(x)|$}
	\State become DONE
    \EndIf
\end{algorithmic}
\end{algorithm}
```
## Message Complexity

We can easily model the **SHOUT** algorithm as **FLOOD + REPLY** ( passing the question to all our neighbour and replying to the entities from where i have recived the question )

We can encounter $3$ possible messages combiantion on each *edge* : 
+ A question and a yes response
	+ These needs to be $(n-1)$ since the spanning tree is made up of $n-1$ edges we need $n-1$ yes respones nad $n-1$ questions so : $2(n-1)$
+ A question and another question
	+ On all the other links : $2(m-(n-1))$
+ A no and a no response 
	+ Since this is a consequence of the previous question and question exchange this will happend the same amount of times : $2(m-(n-1))$

In total we will have : 
$$2(n-1) + 2(m-(n-1)) + 2(m-(n-1)) = 4m -2n +2$$

>[!note] 
>Note that this i $2 \times FLOOD = 2 \cdot (2m -n +1) = 4m-2n+2$ 

# SHOUT+

We can simplify **SHOUT** by removing the $no$ responses

```pseudo
\begin{algorithm}
\caption{SHOUT+}
\begin{algorithmic}
\State INITIATOR
	\State $\quad$ Spontaneusly
		\State $\qquad$ root := true
		\State $\qquad$ Tree-neighbours := \{\}
		\State $\qquad$ send(Q) to N(x)
		\State $\qquad$ counter := 0
		\State $\qquad$ become ACTIVE
\State IDLE
	\State $\quad$ receiving(Q)
		\State $\qquad$ root := false
		\State $\qquad$ parent := sender
		\State $\qquad$ Tree-neighbours := \{sender\}
		\State $\qquad$ send(yes) to sender
		\State $\qquad$ counter := 1
		\If{counter = $|N(x)|$} 
		\Comment{In this case we only have 1 neighbour , we are a leaf}
		\State become DONE
        \Else 
        \State send(Q) to N(x)-\{sender\}
        \State become ACTIVE
        \EndIf
\State ACTIVE 
	\State $\quad$ receiving(Q)
		\State $\qquad$ counter := counter + 1
		\If{counter = $|N(x)|$}
		\State become DONE
	    \EndIf
	\State $\quad$ receiving(yes)
		\State $\qquad$ Tree-neighbours := Tree-neighbours $\cup$ sender
		\State $\qquad$ counter := counter + 1
		\If{counter = $|N(x)|$}
		\State become DONE
	    \EndIf
\end{algorithmic}
\end{algorithm}
```

>[!note] 
>In this case recieving a $Q$ in the $ACTIVE$ state is interpreted as recieveing a $no$ , since it is inevitable that we will send a $no$ after because we have already send a $yes$ to someone

## Message Complexity

Now we can only have two possibilities : 
+ We have two question messages on an edge
	+ $2(m-(n-1))$
+ We have a question and a yes response
	+ $2(n-1)$

So in total we will have : 
$$2(m-(n-1))+2(n-1) = 2m$$

>[!warning] 
>**SHOUT** in general doesn't work when we have multiple *initiator*
>>[!example] 
>>#todo



