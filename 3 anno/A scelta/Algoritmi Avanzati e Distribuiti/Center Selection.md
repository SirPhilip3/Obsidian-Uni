# The Problem

>[!info] Input
>Given : 
>+ A set of *sites* $s_1,\dots,s_n$
>+ An integer $k> 0$

>[!success] Optimization Version
>Select $k$ centers $C$ so that the *maximum* distance between a *site* and the *nearest* center is *minimized*
>>[!note] 
>>Practically find the smallest radius of the circle starting from one of the $k$ *centers* that applied to all other centers contains all the *sites*

>[!example] 
>#todo

Some **Notation** : 
+ $dist(x,y)$ : distance between $x$ and $y$
+ $dist(s_i,C) = \min_{c \in C}dist(s_i, c)$ : distance from $s_i$ ( a *site* ) to it's closest center
+ $r(C)= \max_idist(s_i,C)$ : smallest covering radius ( the maximum distance between a *site* and it's closest *center* )

**Propieties** of $dist$ : 
+ $dist(x,x)=0$
+ $dist(x,y)=dist(y,x)$
+ $dist(x,y)\leq dist(x,z)+dist(z,y)$ ( *triangula inequality* )

>[!important] Goal
>Our goal is to minimize the function $r(C)$ , considering that $|C| = k$

# Approximation Algorithm

## Greedy Algorithm 

Put the first center at the best possible location for a single center ( $k=1$ ) , than add centers to reduce the covering radius as much as possible 

```pseudo
	\begin{algorithm}
	\caption{Greedy-Center-Selection}
	\begin{algorithmic}
	\Comment{$s$ ( $S$ , set of sites ) are the sites}
	\Input $k, n, s_1,s_2,\dots,s_n$
	\Comment{Otherwise the perfect solution would be $C=S$}
	\State Assume $k\leq |S|$
	\State Select any site $s$ and let $C=\{s\}$
	\State Remove $s$ from $S$
	\For{$k-1$ times}
		\State Select a site $s_i$ with $\max dist(s_i, C)$
		\Comment{Selects the furthest site from any center}
		\State Add $s_i$ to $C$
    \EndFor
    \Return $C$
	\end{algorithmic}
	\end{algorithm}
```
>[!note] 
>At the end of the algorithm all centers in $C$ are, between each other , at least $r(C) = \max_i dist(s_i, C)$ apart , by contruction of the algorithm

>[!example]
>#todo
>

### Analysis

>[!important] Theorem
>Let $C^*$ be an optimal set of *centers*. Then $r(C)\leq 2r(C^*)$
#### $\rho=2$ proof ( by contradiction )

Let's assume that $r(C^*) < \frac{1}{2}r(C)$

+ Consider for each *site* $c_i$ in $C$ a circle of radius $\frac{1}{2}r(C)$ around it 