>[!info] Idea
>A genetic algorithm maintains a population of candidate solutions for the problem and makes it evolve by iteratively applying a set of **stochastic** *operators*
 
 >[!note] Idea
 >Start with a population of *candidate solutions*
 >Evolve the solution by applying **stochastic** *operators*

# Definitions

## Stochastic operators

+ **Selection**

The *selection operator* tries to replicate a successfull solution at a rate proportional to their realtive quality ( using the *fitness function* )

+ **Recombination ( cross-over )**

Decomposes two solutions and rabìndomly recompose them in order to form a new solution

+ **Mutation**

Random perturbation of the candidate solution
## Deletion

+ **Generational**
	The entire population is replaced in each iteration of the algorithm 
+ **Steady-State**
	A few members of the original population get replaced in each generation 


