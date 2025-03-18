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

# Example