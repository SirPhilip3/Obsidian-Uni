---
publish: true
---
# The Problem 

Given a graph $G$ with the following *topology* :
+ The number of entitites must be the same as the number of links , $n=m$
+ Each *entity* has two neighbours 
+ Each *entity* has a sense of direction ( it can distinguish between the *left* and the *right* neighbours )

>[!note] 
>In generale *left* and *right* may not coincide between neighbouring *entities*

>[!important] 
>Each *entity* must have a different label ( otherwise we can't break the simmetry )

In the end one entity must know that it is the **LEADER** and all the other are **FOLLOWERS**

# Algorithms

## All the Way

Each node will send a message containing it's *value* ( since we assume that everyone has different *ids* we can't have 2 identical messages ) to one of it's neighbours 

When someone recieves a message it will forward it to it's opposite neighbour , keeping track if the value in the message is lower than it's internal value ( in this case he know that it will be a **FOLLOWER** ) 
If he doesn't see a lower value than he will be a **LEADER** 

The algorithm terminates when every node that has sent out it's message recieves it back 

>[!warning] 
>+ This assumes that the links are **FIFO** , otherwise messages can pass others , this means that i may have not seen all the other messages when receiving back mine
>
>+ Or we need to have knowledge of $n$ , trivially when we have seen $n$ values passing we know that i have seen all the *values*

In order to implement the second solution we will need to add a :
+ counter inside each node ( this rapresents the messages seen so far by the node ) 
+ counter inside each message ( this rapresents the node passed so far , when it will come back to the sender it will contain the size of the ring )

When these two counter are equal than we can decide if we are a *LEADER* or a *FOLLOWER*

States $S=\{ASLEEP,AWAKE,FOLLOWER,LEADER\}$
$S_{INIT} = \{ASLEEP\}$
$S_{TERM} = \{FOLLOWER,LEADER\}$

![[Pasted image 20250418145644.png]]
![[Pasted image 20250418145656.png]]

>[!note] 
>This algorithm works also for *bidirectional* links and when the *sense of direction* is *different* between entities
### Message Complexity

Since each *message* needs to go back to the sender it will be passe trough $n$ links , this multiplied for the numbers of *entities* ( $n$ ) will give us : 
$$O(n^2)$$
### Time Complexity

The time compexity in the worst case will be $2n-1$ 

## As Far

It's not necessary to forward messages with a larger *id* than the ones that we have already seen 
