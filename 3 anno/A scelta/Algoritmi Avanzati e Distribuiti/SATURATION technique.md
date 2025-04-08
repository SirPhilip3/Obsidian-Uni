---
publish: true
---
*Saturation* is a technique used to *elect* a *leader* ( or an edge leader ) in a **Tree** 

>[!example] 
>#todo

>[!note] 
>This tecnique is used to solve also other problems

>[!important] Assumpions
>+ Bidirectional links
>+ *FIFO* messages
>+ Total Reliability
>+ *Topology knowledge* ( each entity knows whether it is a *leaf* or an internal *node* ) , the *topology* needs to be a **Tree**

## Algo

States : $S = \{available,awake,processing,saturated\}$

>[!note] 
>At the beginning all the entities are $available$

We can divide the *algorithm* in $3$ phases :
### Activation Phase

This is just a *wake-up* phase where : 
+ each *initiator* sends a *wake-up* message to all of its neighbours and passes to the $active$ state
+ each *non initiator* that recieves a *wake-up* message ( or *activation* message ) from a neighbour will forward it to all of it's other neighbours passing to the $active$ state

>[!note] 
>$active$ nodes ignore all *wake-up* messages 

Within a finite amount of time ( *total relaibility* enables this ) every node will be in an $active$ state

![[ActivationPhase.excalidraw.png]]
%% [[ActivationPhase.excalidraw]] %%
### Saturation Phase

Each $active$ *leaf* ( each node knows if he is a *leaf* ) sends a *saturation* message to it's parent and passes to the $processing$ state

An *internal* node waits until it has recieved a *saturation* message from all of its *neighbours* except $1$ and sends a *saturation* message to that neighbour and passes to the $processing$ state

This will be considered as his *parent* 

If a $processing$ node recieves a message from it's *parent* it becomes $saturated$

![[SatuarionPhase.excalidraw.png]]
%%[[SatuarionPhase.excalidraw.md|🖋 Edit in Excalidraw]]%%
### Resolution Phase

This *phase* depends on the application that we want to implement and is started by the $saturated$ nodes 

This generally is a *notification* phase where the saturated nodes do flooding on theyr *non saturated* links sending a *notification* message to theyr children in order to achieve *local termination* 

![[ResolutionPhase.excalidraw.png]]
%%[[ResolutionPhase.excalidraw.md|🖋 Edit in Excalidraw]]%%

>[!warning] 
>These phases can happend in parallel

>[!warning] 
>Depending on the timing of the message we can have different solutions

>[!important] 
>Exactly *two* $processing$ nodes will become $saturated$ and they will be neighbours

## Message Complexity

**Worst case** : we have $n$ initiators

+ **Activation phase** : Since everyone will be an *initiator* everyone will send a message to it's neighbours , so there will be two messages passing per *edge* $$2(n-1)$$
+ **Saturation phase** : Since everyone will send only one message per edge ( except for the *saturated* edge where there will be two messages ) we will have : $$(n-2) +2 = n$$
+ **Notification phase** : Since only the *saturated* nodes will send messages on they's non saturated links each edge will have $1$ passing message except the saturated node : $$n-2$$
In total : $$2(n-1)+n+(n-2)=4n -4$$
## Leader Selection

In our case the $saturated$ nodes idenitifies a *saturated* arch 

In an *asyncronous* system one will recieve the *saturation* message first , we can select this as the *leader*

