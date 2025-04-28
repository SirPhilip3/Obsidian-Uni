---
publish: true
---
# The Problem 

Given a graph $G$ with the following *topology* :
+ The number of entitites must be the same as the number of links , $n=m$
+ Each *entity* has two neighbours 
+ Each *entity* has a sense of direction ( it can distinguish between the *left* and the *right* neighbours )

>[!note] 
>In general *left* and *right* may not coincide between neighbouring *entities*

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

When one entity wakes up alone , each node wakes up 1 unit of time after the previous one , the last that will stop will be $n-1$ 

So : 
$$n + n-1 = 2n -1$$
## As Far

It's not necessary to forward messages with a larger *id* than the ones that we have already seen 

In this way a message from an *entity* will travel as far as it can until it reaches an *entity* that has seen a lower value , if it returns back to the sender this means that the sender is the **LEADER** and all the other *entity* are **FOLLOWER** ( we will need a *notification* message to let the other entities know otherwise they can't know that a message has returned back to it's sender )

![[Pasted image 20250418151547.png]]

### Message Complexity

#### Worst Case

The **worst case** is when all the messages needs to reach the **LEADER** to be terminates , so when all the *entities* have an higher value than the previous one , or when each message encounters always an higher value *entity* until the last one

>[!example] 
![[WorstCaseRingRanking.excalidraw.png]]
%%[[WorstCaseRingRanking.excalidraw.md|🖋 Edit in Excalidraw]]%%

In this case $1$ will need to transverse $n$ links ( until he comes back ) , $2$ will need to transverse $n-1$ links etcc 
$$n +(n-1)+(n-2)+\dots+1 = \frac{n(n+1)}{2}$$
We also need a notification message : 
$$\frac{n(n+1)}{2}+n = O(n^2)$$

#### Best Case 

In the *best case* instead all the messages stop at the next *entity* ( they find a lower value )
So only $1$ message will do the full circle , passing all the $n$ *entities* 
$$n+(n-1)$$
We also need the final notification message
$$n+(n-1)+n = O(n)$$
#### Average Case Complexity

If *entities* are ordered in an equiprobable manner than the $J$-th smallest *id* crosses $\frac{n}{J}$ links 

Than the number of messages sent will be : $$\sum_{J=1}^n (\frac{n}{J}) = n\cdot Hn$$
Where $H$ is the *harmonic series* $\approx 0.69 \log n$ 
Than adding the *notification* message we will have : 
$$n\cdot Hn +n = 0.69 \cdot n \log n + O(n)=O(n \log n)$$

>[!note] 
>In the *bidirectional* case there are $0.49 n \log n$ messages sent on *average*

### Time complexity

#todo 


Assuming the ring is syncronous 
In the worst case it will be $2n-1+n$ 

the smallest entity should be woken up at last :
+ $n-1$ to be woken up
+ $n$ to send it's value and come back
+ $n$ for the notification ( not really needed since when you see back yourself than you are a leader and everyone has already seen you )

