---
publish: true
---
# Streaming Algorithm 

>[!important] Streaming Model of Computation
>
>We have as input a *stream* $x_{1},\dots,x_{m}$ of $m$ *integers* , receiving them one by one 
>
>Once received $x_{i}$  we use it to *update* some *data sketch* and then *discard* $x_{i}$
>
>After seeing any stream *prefix* $x_{1},\dots,x_{i}$ we *must* be able to return the *answer* to the particular *statistic* that we are computing on the stream 

Streaming algorithms have the following features :
+ Maximum *working **space***
+ ***Delay*** per element :
	How much time the algorithm spends when receiving a new stream element $x_{i}$
+ ***Probability*** of obtaining a *correct* solution 
+ **Approximation ration** if the solution is approximated

# Pattern matching on streams

>[!important] Problem statement
>We recieve a stream containing $n+m$ characters ( $n \le m$ ) :
>$$
>y_{1},\dots,y_{n} , x_{1},\dots , x_{m}
>$$
>
>Where :
>+ $y=y_{1},\dots,y_{n}$ is a **pattern** of lenght $n$
>+ $x=x_{1},\dots,x_{m}$ is the **text** of length $m \ge n$
>
>After processing $y$, every time we receive a new text character $x_{i}$ we must be able to determine if $y=x_{i-n+1},\dots,x_{i}$ ( for $i \ge n$ )
>
>Or if the *pattern* $y$ is a *suffix* of the current text *prefix* $x_{1},\dots,x_{i}$

This problem is *easy* to solve the problem in $O(n)$ words of space by maintaining a *window* of the last $n$ text characters 
## $O(n)$ working space

Using [[Hashing#Polynomial Hashing ( Rabin hashing )|Polynomial Hashing ( Rabin hashing )]] we can squeeze the *pattern* into $1$ memory word

But this can't be used to solve the problem in $O(1)$ space for the following problem :

>[!example] 
>Suppose we have the hashes of the *pattern* $y$ and the last $n$ text characters 
>
>$$
>\begin{align}
>\text{text prefix } x_{1},\dots,x_{i} = & \text{ abbaabba}\textcolor{red}{bbab} & \kappa_{q,z}(x_{i-n+1},\dots,x_{i}) \\
>\text{pattern } y = &\ \textcolor{blue}{baba} & \kappa_{q,z}(y)
>\end{align}
>$$
>
>Keeping these two hashes takes $O(1)$ *space* , also checking if the pattern is a *suffix* of the current text prefix takes $O(1)$ *time*
>
>>[!warning] 
>>The problem is **updating** the text *prefix* *hash* when a new character arrives 
>>
>>The new *hash* is :
>>$$
>>\kappa_{q,z}(x_{i-n+2},\dots,x_{i+1}) = \kappa_{q,z}(x_{i-n+1},\dots,x_{i}) \cdot z - b \cdot z^n + a \mod{q}
>>$$
>>
>>Where $a$ is the new arriving character and $b$ the character exiting the window
>>
>>Since we need to access the $n$-th last stream character we need to *explicitly* *store* the last $n$ characters , so we are still in $O(n)$ *space*
>>

# Porat & Porat's algorithm 

*Instead* of storing the last $n$ characters of the stream, we can keep a *combination* of $O(\log n)$ *hashes* in order to retrieve tha last $n$ characters when needed

This will give us :
+ $O(\log n)$ *space*
+ $O(\log n)$ *update* time
+ *Correctness* with *high* *probability*

---

## Data Structures

Consider the following pattern of lenght $n=16$ 

We compute the *hashes* of its $\log n +1$ *prefixes* of length $2^j$

![[P&P_init.excalidraw.png]]
%%[[P&P_init.excalidraw.md|🖋 Edit in Excalidraw]]%%

Then the *text* arrives 

We also keep $\log n$ *sets* : $W_{0}, \dots , W_{\log n -1}$

Each set $W_{i}$ stores the occurences of the *pattern* *prefix* *of lenght* $2^i$ in the last $2^{i+1}$ text's characters 

![[P&P_state.excalidraw.png]]
%%[[P&P_state.excalidraw.md|🖋 Edit in Excalidraw]]%%

>[!note] 
>$W_{0}$ has the starting postions for the pattern identifying $b$, $W_{1}$ has the starting postions for the pattern identifying $ba$ and so on

>[!warning] 
>Each $W_{i}$ could contain up to $2^i+1$ *integers* , this can be shown to be stored in $O(1)$ space since they are periodic 

Also the set $W_{\log n} = W_{4}$ will tell us if the *full pattern* occurs as a *suffix*

## Updates

