---
publish: true
creation: 2025-02-18T13:09:00
---
# The Problem

The problem of the **Vertex Cover** ( **VC** ) says the following : 

>[!important] Definition
>Given a undirected graph $G=(V,E)$ ( where $V$ are *vertices* and $E$ are *edges* ) and an integer $k$  is there a subset of vertices $V'\subseteq V$ such that : 
>+ $|V'| \le k$
>+ For each of it's *edges* at least one of it's *endpoint* is in $V'$

>[!success] Optimization Version
>Gets in *input* a graph $G$ and returns the *Vertex Cover* $V'$ of **minimum** size

>[!question] Decision Version
>Gets in input a graph $G$ and an integer $k$ , returns `True` if $G$ has a *Vertex Cover* of size $\leq k$

>[!note] 
>It can be demonstrated that the **Decision Version** is [[Strutture Dati#Classe $NP-completi$ ( o NPC )|NP-Complete]] ( $3SAT \leq_p VC$ ) , so the **Optimization Version** is at least as hard

# Approximation Algorithm

The following is a $2$-approximation algorithm 

```pseudo
	\begin{algorithm}
	\caption{Approx-Vertex-Cover}
	\begin{algorithmic}
	\Input some graph $G=(V,E)$
	\State $V' \leftarrow \emptyset$
	\State $E' \leftarrow E$
	\While{$E' \neq \emptyset$}
		\State let $(u,v)$ be a $\boldsymbol{random}$ edge of $E'$
		\State $V' \leftarrow V' \cup \{u,v\}$
		\State remove from $E'$ all the edges incident on either $u$ or $v$
    \EndWhile
    \Return $V'$
	\end{algorithmic}
	\end{algorithm}
```

>[!example] 
![[VertexCover.excalidraw]]
## $\rho$ proof

**Hypotesis** : 
+ $A$ : the set of *edges* that are picked by the algorithm ( e.g. $\{(c,e),(d,g),(a,b)\}$ ) 

**Lemmas** : 
1. The algorithms givea a *vertex cover*
2. The *vertex cover* found has size $\leq2\times \text{optimal solution}$ 

**Demonstraions** :
 1. By construnction of the algorithm it gives a *vertex cover*
---
2. 

Suppose we have the *vertex cover* $|A|$ and an optimal solution $|VC^*|$ 
By construction we need to have at least one endpoint of each edges in $A$ in the ve

#todo 