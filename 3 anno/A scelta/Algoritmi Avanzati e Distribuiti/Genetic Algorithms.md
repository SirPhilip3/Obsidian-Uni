>[!info] Idea
>A genetic algorithm maintains a population of candidate solutions for the problem and makes it evolve by iteratively applying a set of **stochastic** *operators*

Basic Structure : 
1. Randomly generate an initial population 
2. Evaluate the *fitness* of the population
3. Select parents and *reproduce* the next generation
4. Replace the old generation with the new one if it improves in the *fitness* function
5. Repeat from step $2$ for $n$ iterations

>[!important] 
>The *fitness function* is the only link between a classical *genetic algorithm* and the problem it's solving

# Definitions

## Stochastic operators

+ **Selection**

The *selection operator* tries to replicate a successfull solution at a rate proportional to their relative quality ( using the *fitness function* )

>[!note] 
>Generally the *fitness function* has higher value for instances that are closer to a good solution , this value is used to calculate the probabilty with which a pair of solution is selected for *recombination*

+ **Recombination ( cross-over )**

Decomposes two solutions and randomly recompose them in order to form a new solution

+ **Mutation**

Random perturbation of the candidate solution
## Deletion

+ **Generational**
	The entire population is replaced in each iteration of the algorithm 
+ **Steady-State**
	A few members of the original population get replaced in each generation 

# Example Algorithm

![[MAXONE problem]]

![[Random Traveling Salesman Problem]]