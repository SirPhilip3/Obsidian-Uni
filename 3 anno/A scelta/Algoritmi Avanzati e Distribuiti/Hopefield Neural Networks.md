>[!note] Hopefield Network Problem
>Simple model of an associative memory in which a large collection of units are connected by an underlying network and neighboring units try to correlate their states 

**Input** : Graph $G=(V,E)$ with weights ( as integers ) on the edges

**Configuration** : Assigning to a node $s_u$ a value of $\pm 1$

**Intuition** : 
+ If $w_{uv}<0$ than $u$ and $v$ need to have the *same* state 
+ If $w_{uv} > 0$ than $u$ and $v$ need to have *different* state

>[!important] 
>In generale no configuration respects all constraints

>[!note] *Good* edge
>Considering a configuration $S$ , *edge* $e=(u,v)$ is *good* if $w_e s_u s_v < 0$ ( so if $w_e <0$ than $s_u = s_v$ and if $w_e >0$ $s_u \neq s_v$ )

>[!note] *Satisfied* node
>Considering a configuration $S$ a node $u$ is *satisfied* if the total absolute weight of all *good* edges incident to $u$ is at least as large as the total absolute weight of all *bad* edges incident to $u$

>[!note] *Stable* configuration
>A configuration is *stable* if all nodes are *satisfied* 

>[!important] 
>The ultimate goal is to find a *stable* configuration if it exists

