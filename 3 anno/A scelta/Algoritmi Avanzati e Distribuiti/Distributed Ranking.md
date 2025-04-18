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

>[!example] 
>#todo
### Message Complexity

The *worst case message complexity* will be when the *ranking* message would need to go back to the *leader* passing each node of the tree , so the worst *topology* for this algorithm would be a *line* where the first node to rank is positioned opposite to the *leader* and the subsequent nodes to be ranked are in ascending order until the last one to be ranked would be the *leader*

>[!example] 
>![[RankingComplexity.excalidraw.png]]
>%%[[RankingComplexity.excalidraw.md|🖋 Edit in Excalidraw]]%%

The total messages send will be : 
$$2(n-1)+2(n-2)+\dots+2(1)=\frac{2(n-1)n}{2}=(n-1)n$$
So the complexity is $O(n^2)$
## Decentralized Ranking

In *decentralized ranking* the ranking message will contain 3 values $(first,second,rank)$
+ $first$ : is the smallest value
+ $second$ : second smallest value known so far 
+ $rank$ : the rank to assign 

>[!note] 
>The *second* value might be unknown , in this case the value $\infty$ is used , this can happend if we are in a leaf 

$second$ will be updated while the message is traveling to $first$ with a lower value if it is encountered on the links of tree

>[!example]
>#todo
>

### Message Complexity

The worst case complexity will be achieved when the message is forced to go back an forth between the two ends of a linear tree ( imagine that we remove the ranked node an recursively apply the alogrithm ) where the starting node is the second one to rank ( so that the message is forced to go to the other side to rank the first one )

>[!example] 
![[DecentralizedRanking.excalidraw.png]]
%%[[DecentralizedRanking.excalidraw.md|🖋 Edit in Excalidraw]]%%

In this case the complexity will be : 
$$2(n-1) + (n-2) + (n-3)+\dots+1 = \frac{(n-1)n}{2}+(n-1)=(n-1)(\frac{n}{2}+1)$$
>[!note] 
>The worst case complexity is always $O(n^2)$ but on average we will have less messages 

