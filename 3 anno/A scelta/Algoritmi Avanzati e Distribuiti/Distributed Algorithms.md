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

