---
publish: true
---
Spell correction is used on both end of an *IR* system : 
+ Correcting *documents* being indexed
+ Correcting *user queries* to retrieve more relevant documents

Spell correction can have two modes : 
+ *Word sensitive* 
	+ Checks the spelling of each word regardless of the *context*
+ *Context sensitive*
	+ Checks for context ( can correct "I flew *form* Heathrow to Narita" )

# Document Correction

Useful for correcting *OCR* ( *Optical Character Recognition* ) scanned documents and web pages

>[!note] Domain-specific mistakes 
>In *OCR* some mistakes are more common : `rn -> m` or `o -> d`
>
>
# Query mis-spellings 

We have two possibilities : 
1. Retrieve document with the most likely correct spelling ( corrects the query )
2. Return suggested queries based on the most likely spelling

# Word Sensitive correction

>[!note] 
>A *correct lexicon* needs to exists

The *correct lexicon* can be the English Dictionary or an industry specific one 

In general we want , given a *lexicon* and a *query* `Q` return the words **closest** to `Q` from the *lexicon*

>[!note] 
>If two correct spellings have equal distance use the most common 
## Distance Meatrics

### Edit Distance

>[!important] Definition
>
>Given two strings $S_1$ and $S_2$ the *edit distance* is the *minimum number of* **operations** to convert one to the other 

**Operations** are ( character level ) : 
+ Insert
+ Delete
+ Replace
+ *Transposition* ( can be viewed as two *replace* , `ca->ac` )

The solution is found by [[Strutture Dati#Programmazione Dinamica|Dynamic Programming]] in $O(|S_1| \times |S_2|)$ 

#### Algorithm

Given $X$ and $Y$ strings of lenght respectively $n$ and $m$ 

Define $D[i,j]$ as : 
+ The *edit distance* between prefixes : $X[1..i]$ and $Y[1..j]$
+ The *edit distance* between the full $X$ and $Y$ is than $D[n,m]$ 

```pseudo
	\begin{algorithm}
	\caption{$Edit\_Distance(X,Y)$}
	\begin{algorithmic}
	\ForAll{$i$ from $0$ to $|X|$}
		\State $D(i,0) = i$ 
    \EndFor
    \ForAll{$j$ from $0$ to $|Y|$}
		\State $D(0,j) = j$ 
    \EndFor
    \ForAll{$i$ from $1$ to $|X|$}
		\ForAll{$i$ from $1$ to $|Y|$}
	        \State $D(i,j) = \min \begin{cases} D(i-1,j) +1 \\ D(i,j-1) +1 \\ D(i-1,j-1) + & \begin{cases} 2 & \text{if } X(i) \neq Y(j) \\ 0 & \text{if } X(i) = Y(j) \end{cases} \end{cases}$
        \EndFor 
    \EndFor
    \Return D(|X|,|Y|)
	\end{algorithmic}
	\end{algorithm}
```
### Weighted Edit Distance

Since some errors are more *probable* than other ( letter closer togheter in a keybpard ) we can add a *weight matrix* 
### $n$-gram overlap

#todo 

