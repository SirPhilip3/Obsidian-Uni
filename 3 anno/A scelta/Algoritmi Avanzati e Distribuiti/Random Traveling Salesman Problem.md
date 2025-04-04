---
publish: true
---
# The Problem 

Find a tour of a given set of cities so that each city is visted only once and the total distance traveled ( the sum of the wrights on the edges ) is minimized

**Encoding** : 
+ Label the cities $1,2,\dots,n$
+ A tour is a permutation of these cities ( $n!$ permutation possibile , e.g. for $n=4$ we have $[1,2,3,4] ,\ [3,4,2,1], \dots$ )

# Algorithm

## Selection

The *fitness* $f(i)$ of a solution is the *inverse cost* of the corresponding tour , in this way higher cost tour will have less probability to be selected 

## Recombination ( Cross-over )

>[!warning] 
>Normal *cross-over* operation will often lead to inadmissible solutions
>>[!example] 
>>![[TSPinvalidCrossover.excalidraw]]

```pseudo
	\begin{algorithm}
	\caption{Cross-over}
	\begin{algorithmic}
	\State Choose an arbitrary part from the first parent
	\State Copy this part to the first child
	\State Copy the numbers that are not in the first part to the first child
		\State $\quad$ starting right from the cut point of the copied part 
		\State $\quad$ using the order of the second parent and wrapping around at the end
	\State Similarly for the second child with parent roles reversed
	\end{algorithmic}
	\end{algorithm}
```

>[!example] 
>![[TSPCrossover.excalidraw]]

## Mutation


There are various type of mutation that can be done :
+ **Insert** mutation

Pick two values at random and move the second value close the first one shifting the rest to the right 

>[!example] 
>![[Pasted image 20250314104027.png]]

>[!note] 
>This solution preserves most of the order and adjacency information

+ **Swap** mutation

Pick two values at random and *swap* their positions

>[!example] 
>![[Pasted image 20250314104110.png]]

+ **Inversion** mutation

Pick two values at random and than *invert* the *substring* between them

>[!example] 
>![[Pasted image 20250314104202.png]]

+ **Scramble** mutation

Pick a subset of values at random and rearrange them randomly 

>[!example] 
>![[Pasted image 20250314104238.png]]

