# The Problem

>[!important] 
>We want to maximize the number of 1's in a string of $l$ binary bits

>[!example] 
>Suppose $l=10$ , an *individual* in or population will be encoded as a string of $l$ binary bits ( e.g. $0000000001$ )

# Algorithm

>[!important] 
>In this case the *fitness function* will be the number of $1$'s in the string , higher is better

## Initialization

We take $l=10$ and $n=6$ 

At the start we take $6$ string of length $10$ with a random number of $1$'s in them :
+ $s_1 = 1111010101\quad f(s_1) = 7$
+ $s_2 = 0111000101\quad f(s_2) = 5$
+ $s_3 = 1110110101\quad f(s_3) = 7$
+ $s_4 = 0100010011\quad f(s_4) = 4$
+ $s_5 = 1110111101\quad f(s_5) = 8$
+ $s_6 = 0100110000\quad f(s_6) = 3$

## Selection

In order to produce a probabilty of selection we use the [*Roulette Wheel Method*](https://en.wikipedia.org/wiki/Fitness_proportionate_selection) : 

The individual $i$ will have probability of being chosen equal to :
$$\frac{f(i)}{\sum_i f(i)}$$

The selection is repeated as many times as the number of *individuals* we need to have the same parent population ( *Generational genetic algorithm* ) size ( $6$ in this case )
## Recombination ( Cross-over ) 

For each couple selected in the *selection* phase we decide , according to a *cross-over* probability ( an arbitrary value ) if we perform the *cross-over* or not

Suppose we selected couples $(s_1, s_3)$ and $(s_4,s_5)$ 

For each couple we select randomly a *cross-over point* ( in our case $2$ for the first one and $5$ for the second one ) , every bit following the *cross-over point* will be *swapped* between the two 

>[!example] 
>$s_1 = 11\color{red}11010101$
>$s_3 = \textcolor{green}{11}10110101$
>
>Will become :
>
>$s_1 = 1110110101$
>$s_3 = \textcolor{green}{11}\color{red}11010101$
>
>---
>
>$s_4 = 01000\color{red}10011$
>$s_5 = \textcolor{green}{11101}11101$
>
>Will become :
>
>$s_4 = 0100011101$
>$s_5 = \textcolor{green}{11101}\color{red}10011$

## Mutation

For each bit we assign a low probability ( e.g. $0.1$ ) to flip bit 

>[!example] 
>In *red* are the bit selected for mutation : 
>+ $s_1 = 11101\textcolor{red}{1}0101$
>+ $s_2 = 0111000101$
>+ $s_3 = 1111\textcolor{red}{0}1010\color{red}1$
>+ $s_4 = 0100011101$
>+ $s_5 = 11101111\textcolor{red}{0}1$
>+ $s_6 = 11101100\textcolor{red}{1}1$
>
>After mutation :
>+ $s_1 = 11101\textcolor{green}{0}0101 \quad f(s_1) = 6$
>+ $s_2 = 0111000101 \quad f(s_2) = 5$
>+ $s_3 = 1111\textcolor{green}{1}1010\textcolor{green}{0} \quad f(s_3) = 7$
>+ $s_4 = 0100011101 \quad f(s_4) = 5$
>+ $s_5 = 11101111\textcolor{green}{1}1 \quad f(s_5) = 9$
>+ $s_6 = 11101100\textcolor{green}{0}1 \quad f(s_6) = 6$

Since the solution has now a total *fitness* of $38$ from the previous value of $34$ ( an improvment of $\sim 12\%$ ) we can sobstitute the old population with this one

We reapeat the process until a stopping criterion is met

