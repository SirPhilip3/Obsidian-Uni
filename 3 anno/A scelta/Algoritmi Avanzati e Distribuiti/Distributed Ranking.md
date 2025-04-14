---
publish: true
---
# The Problem

Given a graph $G$ , with entitiy $x$ having assigned a value $V(x)$ than we want to rank $x$ as $1+\text{\# of nodes with a lower value}$   

# Algo

1. Find a *spanning tree* ( with [[Distributed Spanning Tree#SHOUT Protocol|SHOUT]] or [[Distributed Spanning Tree#SHOUT+|SHOUT+]] ) 
2. Use [[Minimum Search with SATURATION]] to find a starting node
3. Do *Ranking* 

>[!note] 
>The **Ranking** can be done in 2 different ways : **Centralized** or **De-centralized** 

## Centralized Ranking

We elect a *leader* ( it will be one of the saturated nodes ) whitch will execute the computation for ranking the rest of the tree
### Message Complexity

## Decentralized Ranking

### Message Complexity

