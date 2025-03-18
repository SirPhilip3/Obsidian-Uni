# Idea

+ The same randomized algorithm may provide **different** solutions on the same input 
+ A randomized algorithm may provide a **wrong** result , but this should happend with a *small probability* for every instance of the problem
+ Running it *multiple times* will *increase* our *confidence* on the result 
+ Usually we have a *better average case complexity* compared to a deterministic algorithm 

# Types

## Numerical Algorithms

They provide an approximate result with a certain confidence. 

Each time we repeat the algorithm we increase the precision 

>[!example] 
>With probability $90\%$ the answer is $20 \pm 1$ 
## Monte Carlo Algorithms

They provide the *correct* answer with a very high probability. 

>[!warning] 
>In some cases the answer *can be wrong* 

By repeating the algorithm we increase the probability of getting a correct answer

>[!example] 
>With probability $99\%$ the answer is $20$ 
## Las Vegas Algorithms

It will always provide the correct answer or it doesn't return a result 

>[!example] 
>The answer is $20$

# Examples

Given the following problem : $1 +\frac{1}{2} + \frac{1}{2} = ?$ each type of algorithm will run it $4$ times : 
+ *Numerical algorithm* : $2\pm 0.5,\ 2.3 \pm 0.5,\ 2.1 \pm 0.5, \ 2.3 \pm 0.5$
+ *Monte Carlo algorithm* : $2,2.1,2,2$
+ *Las Vegas algorithm* : $2,\text{ no output},\ 2,2$
# Monte Carlo vs Las Vegas 

Let's introduce a dummy problem in order to show the differences between the *Monte Carlo* and the *Las Vegas* algorithms

**Input** : 
	Given an array of $n\geq 2$ elements in which half are `a` and half are `b` 
**Output** :
	Find an `a` in the array
## Monte Carlo version 

```pseudo
	\begin{algorithm}
	\caption{findingA\_MC}
	\begin{algorithmic}
	\Input array A, n, k
	\State $i=0$
	\Repeat
		\State Randomly select one element out of $n$ elements
		\State $i=i+1$
    \Until{$i=k$ or 'a' is found}
	\end{algorithmic}
	\end{algorithm}
```
>[!note] 
>$k$ is the stopping criterion for the algorithm 

We can compute that after $k$ iterations of the algorithm we can be relatively certain that we didn't find an `a` , this since the probabilit of *not finding an a* after $k$ iterations is : 
$$Pr[\text{not find a}] =(1/2)^k$$
And the *probability of finding an a* after $k$ iteration will be : 
$$Pr[\text{find a}]=1-(1/2)^k$$

>[!note] 
>The algorithm doesn't garantee success but the running time is bound by $k$ and if this is a constant than the complexity will be : $O(k)\sim O(1)$ 

## Las Vegas algorithm

```pseudo
	\begin{algorithm}
	\caption{findingA\_LV}
	\begin{algorithmic}
	\Input array A, n
	\Repeat
		\State Randomly select one element out of n elements
    \Until{'a' is found}
	\end{algorithmic}
	\end{algorithm}
```
>[!note] 
>This algorithm will only stop if it finds an $a$ , the expected running time over many calls is $O(1)$ but it could also go on loop never finding an `a`

>[!important] 
>We can always convert a *Las Vegas* algorithm into *Monte Carlo* ( simply add a stopping criterion ) but there is no known method to convert from *Monte Carlo* to *Las Vegas*

# PseudoRandom generators


