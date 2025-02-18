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
>Si può d