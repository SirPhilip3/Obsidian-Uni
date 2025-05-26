---
publish: true
---
# Definitions

## Message Passing Model

The *message passing model* rapresents a collection of entities that comunicate by *exchanging messages* 

We can rapresent this with a [[Graphs|graph]] where *nodes* are *entities* and *edges* are communication links 
### Entity

An *entity* is the *computational unit* of a distributed computing environment ( this could be a processor , switch , agent depending on the system modeled )

Each *entity* has some local memory where it stores : 
+ It's **State**
+ Varius *values* used in the computations

Each *entity* also mantains a *clock* 

Each *entity* can perform varius actions :
+ Do some calculations
+ *Setting* or *Resetting* the *clock*
+ Changing the values of the registers 
+ Transmitting some messages 

Each *entity* has : 
+ An input ( might be empty )
+ The *same* code
+ The *same* output

>[!important] 
>Each entity $x$ can be in one of a finite set of possible states  
### Events

The behaviour of an entity is *reactive* ( Triggered by **events** )

Some possible **events** are : 
+ *clock* tick
+ receiving a message
+ a spontaneous impulse ( the event that starts the computation )

>[!important] 
>Given a *State* and an *Event* it will always result in the same *Action*
### Action

An **Action** can be a sequence of activities ( computing , sending a message , changing state etcc ) 

>[!important] Atomicity
>An *action* is **Atomic** ( the sequence of activities can't be interrupted )

>[!important] Termination
>An *action* is always terminating ( the actions must terminate in a finite time )

>[!note] 
>An action can also be *nil* ( *null action* )
### Entity Behaviour

The **Behaviour** $B(x)$ is the set of rules of an entity $x$ for all the possible events and all the possible states 

>[!important] Deterministic Behaviour
>Given a couple composed of a *state* and an *event* this will produce only one action

>[!important] Complete Behaviour
>For all the possible couples of state and event there will always be an action : $\forall(state,event) \exists \text{ an action}$

>[!note] 
>This will be the algorithm of the *entity* 

### System Behaviour 

A system is **Symmetric** if all the entities have the same behaviour :
$$B(x)=B(y), \forall x,y \in E$$
Where $E$ are the *entities* in the system

>[!important] 
>Every system can be made symmetric
### Roles

Various *entities* can have different *roles* , we can create `if` in the *behavioural description* of our *entities* so that *entities* with different *roles* will act in different ways 

>[!note] 
>All *entities* still retain the same *behavioural description*
### Communication

Each message is a *finite sequence of bits*

The communication is *directional* :
+ $N_o(x)$ : *out-neighbors* of entity $x$
	+ An *entity* $x$ can send messages only to its *out-neighbors* 
+ $N_i(x)$ : in-neighbors of entity $x$
	+ An *entity* $x$ can recieve messages only from its *in-neighbors* 
+ $N(x) = N_o(x)\cup N_i(x)$ : neighborhood of $x$

We can create a graph describing the *communication topology* : $G(V,A)$ 
+ $V$ are *entities*
+ $A$ arcs defined by $N$ 

>[!example] 
>#todo

>[!important] Finite Transmission Delays 
>
>In abscence of *faults* a message from $x$ to one of it's *out-neighbor* $y$ reaches $y$ in a *finite time* 

>[!important] Local Orientation
>Each entity can distingush among its neighbors ( both *in-neighbor* and *out-neighbor* )  ( it will assign labels to each out going connection , like port numbers )
>
>These lables are rapresented formally as : $\lambda_x(x,y)$ ( for the outgoing label on $x$ ) , $\lambda_y(x,y)$ ( for the incoming label on $y$ )
>>[!example] 
>>![[ConnectionDist.excalidraw]]

>[!important] Message Ordering
>
>In abscence of failures , messages transmitted along the same link will follow **FIFO** ( *first in first out* ) ordering

#### Bidirectional Links

Where we have that : 
+ $\forall x, N_i(x) = N_o(x)=N(x)$ and
+ $\forall y\in N(x): \lambda_x(x,y) = \lambda_y(x,y)$

### Model Restrictions
#### Reliability Restrictions

>[!important] **Garanteed delivery**
>Any message that is sent will be recieved uncorrupted

>[!important] **Partial Reliability**
>There will be no failures 

>[!important] **Total Reliability**
>
>No failures have occurred nor will occur ( from the start of the system to it's end )

#### Topological Restictions

>[!important] Connection
>The graph $G$ must be strongly *connected*

>[!important] Topology
>+ The graph must be of a maximum *diameter* ( longhest minimum walk between two nodes )
>+ We can limit its number of *nodes* or *vertices*

#### Time Restriction

>[!important] Bounded Communication Delay
>
>There is a constant $\Delta$ that , in abscence of any failures , rapresents the maximum communication delay of any message on any link

>[!important] Syncronized clocks 
>All *clocks* are incremented by one unit simultaneously 

>[!warning] 
>This is impossible in practice , we will than consider *asyncronous systems*

### Complexity Measures

In the complexity mesure we consider the *communication cost* as the most important factor ( *computational cost* will be included in the *communication cost* )

We will use two types of measures : 
+ The *amount of communication activities*
+ The *time required* for the execution of the computation
#### Amount of Communication Activities

We use the amount of messages send ( *message cost* ) and the size of the messages ( *bit complexity* ) sent as complexity measures

#### Time

Depending if the *clock* is *sincked* or not we can have two types of complexity : 
+ *Ideal execution delay* : where the *clocks* are syncked and the cost of the transmission is unitary
+ *Casual time complexity* : is the lenght of the longhest chain of casually related message transmission 