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

## Metropolis Algorithm

## Hopefield Neural Networks