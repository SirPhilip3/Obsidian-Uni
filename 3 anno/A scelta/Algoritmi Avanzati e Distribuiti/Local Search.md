We use this method if we can't find an *approximation* algorithm for the problem

>[!note] 
>They explore the space of the possible solutions in a sequential way , passing from the current solution to a *nearby* one

>[!note] 
>It's often difficult to prove something about the quality of the solution 

## Definitions

+ $C$ : is a *set* of *solutions* to a problem
+ $S$ : is a specific *solution*
+ $c(S)$ : given a *solution* $c$ gives a *cost* to that solution ( **Cost Function** )
+ $S \sim S'$ : $S'$ is a *neighboring* solution of $S$
+ $N(S)$ : is the *neighborhood* of $S$ , so the set of $[S':S \sim S']$

>[!important] Goal
>Find a solution $S^*$ that has $c(S^*)$ as small as possible ( or as big when maximizing )

## Local Search Algorithms

A *local search algorithm* has a solution $S$ , at a given step it chooses a neighbouring solution $S'$ of $S$ , declares it as the new current solution ( remembering the solution of *minimum* cost so far ) and continues to iterate 

>[!note] 
>The hard part of these algorithms is finding a good neighbour

>[!example] Gradient Descent
>#todo

### Gradient Descent for [[Vertex Cover]]

>[!important] Neighbor definition
>$S \sim S'$ if $S'$ can be obtained from $S$ by :
>+ Adding a *single* node currently *not in* the [[Vertex Cover]] 
>+ Deleting a *single* node in the [[Vertex Cover]]

>[!note] 
>Each [[Vertex Cover]] $S$ has at most $n$ neighbors

The local search algorithm will consist in searching all the neighbouring solutions and tring to find the smallest [[Vertex Cover]] 

>[!example] Possible algorithm
>
>Start with $S=V$, if there is a neighbor $S'$ that is a [[Vertex Cover]] and has lower cardinality , replace $S$ with $S'$ , otherwise terminate the algorithm

>[!note] Termination
>The algorithm terminate after at most $n$ steps , since each step we reduce the size of the [[Vertex Cover]] by one

>[!warning] 
>These types of algorithm could find a local minimum instead of a global minimum
## Metropolis Algorithm

The *metropolis algorithm* is an attempt to improve the case where the algorithms finds a local minimum by adding an element of randomness 

So the algorithm generally goes *downhill* but occasionally it can make an *uphill* step in order to try and get out fo the local minimum

>[!note] 
>A probability function used is the [Gibbs-Boltzmann function](https://en.wikipedia.org/wiki/Boltzmann_distribution) adapted in the following way : $e^{-(c(S')-c(S))/ kT}$ 
>Where $k$ is a constant

---

1. Given a *fixed* temperature $T$ , maintain the current state $S$ 
2. Randomly perturb the current state $S$ to a new state $S' \in N(S)$
3. *If* $c(S') \leq c(S)$ than update the current state to $S'$
	*Else* update the current state to $S'$ with *probability* : $e^{-(c(S')-c(S))/ kT}$ otherwise keave $S$ unchanged 
## Hopefield Neural Networks

>[!note] Hopefield Network
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

