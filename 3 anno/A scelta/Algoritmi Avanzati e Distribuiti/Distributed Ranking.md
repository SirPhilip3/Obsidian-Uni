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

We elect a *leader* ( it will be one of the saturated nodes , normally the one that has the lower value ) which will execute the computation to rank the rest of the tree

This *leader* will know in what direction the *minimum* is ( he might not be the minimum ) , he will send a *ranking* message in that direction 

>[!note] 
>Since every node know the minimum of its subtrees everyone can always send the message in the right direction

>[!note] 
>In order to be able to send a message in the right direction we need to label the edges with the minimum of that subtree 

When the node to be ranked recieves the message it returns a $Notificatio\&Update$ message that will go back to the *leader*

>[!note] 
>If the node that it reached was a leaf it will assign $\infty$ to the label of the edge assigned by its parent
>

>[!important] 
>The *Update* will contain the *new-minimum* , initially assigned to $\infty$ if we were on a leaf or to the new *minimum* value between it's subtree otherwise 
>
>For each *node* it will check it ther's a lessere value in it's subtrees and update the value on the message 
>
>It will than update the label of the edge from which the message arrived 

### Message Complexity



## Decentralized Ranking

### Message Complexity

