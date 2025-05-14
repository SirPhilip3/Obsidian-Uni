---
publish: true
---
# Model

## Graph

Given a graph $G=(V,E)$ where 
+ An *edge* rapresents a communication link , each *edge* has a *distinct label* ( port numbers )
+ Each *node* ( *host* ) has a **whiteboard** that can be accessed by the robots
## Mobile agents

A *mobile agent* :
+ has *Computing* capabilities
+ has Local storage
+ Can *move* from one node to a neighbouring one
+ have the *same behaviour*

Generally they start from a *node* called **Homebase**

Mobile agents **Syncronization** : 
+ *asyncronous* : actions take a finite but unpredictable amount of time
+ *syncronous* : actions each take $1$ unit of time
## Communication

The *mobile agents* can communicate ( with *mutual exclusion* ) through the **whiteboards** stored in the nodes 
# Security

There can be : 
+ **Harmful Host** : harmful stationary process ( *black holes* ) 
+ **Harmful Agent** : malicious mobile agents 
## Harmful Host

An *Harmful Host* can be considered a *black hole* where : 
+ It will destroy any agent arriving at that node
+ Does not leave any trace of destruction 
+ It's location is unknown to the agents
### Report it's Location

>[!important] Goal
At least one agent must survive and know the location of the *black hole*
#### Cautious Walk

For each *port* we assign 3 possible values : 
+ Unexplored : the port could be **dangerous**
	+ We send $1$ agent to explore it : go to the first node and come back 
+ Active : some *agent* is exploring it
	+ No other agent can go in that port
+ Explored : that port is *safe*
	+ Once the *agent* is returned the port is marked as safe and can be crossed by other agents

>[!important] Supposition
>We suppose that our system is *Asyncronous* , this mean that we can't distinguish between a slow *agent* and one that has disappeared in the *black hole* 
>
>We suppose that there is only one *black hole*

>[!note] 
>Even if the system is *asyncronous* we know that sooner or later if the port is safe the agent will come back and mark the port as *explored*

>[!fail] 
>The problem is impossible if : 
>+ The size of the graph is unknown
>+ The graph is not *byconnected* ( there must be at least 2 different paths to reach a node )

##### Black Hole with cautious walk

In this case we can solve the *black hole* problem with $2$ *agents* 

>[!important] Supposition
>We suppose that each node has directionality ( each node has a port marked as left and one as right )

Two agents starting from the same *homebase* will explore using *cautious walk* one port each 

Each time they explore a new node they will come back to the *homebase* and add a message to the *whiteboard* saying that the $i^{th}$ node is safe 

When one *agent* will encounter the *black hole* , the other one will continue until the number of **unexplored** *nodes* is $1$ 

>[!important] 
>We assume that we know the size of the *ring*

At this point we know exactly where the *black hole* is 

#todo insert animation
## Harmful Agent

An *Harmful agent* is an agent that can move from a node to a neighbouring one arbitrarily fast

>[!important] 
>+ It **can't** cross a node guarded by an *agent* 
>+ It is *invisible* to the agents 
>+ Can permanently see the position of the other agents

### Capturing the Intruder 

Initially all the agents are in an *homebase* and form a team 

>[!important] Goal
>At the end the agents must '*capture*' the intruder ( surrounding him )
>

This problem is equivalent to the **Decontamination** problem 
#### Decontamination Problem 

Initially all the agents are in an *homebase* and form a team and the whole network is **Contaminated** except the *homebase* 

>[!note] 
>There can be only the nodes or also the edges that are contaiminated

An agent cleans a *node* when it enters it 

>[!important] Goal
>At the end the agents must *clean* the whole network

>[!warning] 
>A node becomes *contaminated* if it is not protected by an agent and at least one of it's neighbour is contaminated 
##### Decontaminating a [[Model Topologies#2-dimensional mesh|Mesh]]

>[!important] 
>A node should not be recontaminated

The *agents* need to form a line to block the possibilities of recontamination 

>[!important] Assumption
>+ *Agents* can only move to one of it's neighbour
>+ The system is *asyncronous*

We can adopt 2 strategies : 
+ Using a **Syncronizer**
+ *Agents* have **Visibility**
###### Syncronizer

The *agents* that are searching can not see their neighbouring nodes 

There is a special *agent* , the **Sycnronizer** , that coordinates the moves of each agent 

>[!info] Idea
>Start from the *homebase* and contiguosly clean the *contaminated* network by maintaining a vertical barrier of *agents* ( in order to avoid recontamination ) 
>

>[!important] Assumption
>
>Every *agent* ( also the *syncronizer* ) will start on an angle of the mesh
>

We have 2 phases : 
1. *Initialization*

The *Syncronizer* will push the *agents* down until the first column is fully sanitized

In a *mesh* that is $m\times n$ this will take :
+ $m-1$ *time*
+ $m\cdot(m-1)/2$ *moves* 

>[!note] 
>$m$ is the number of *rows*

>[!example] 
![[DecontaminationInit.mp4]]

2. *Clean Up*

In the *cleaning* phase the *syncronizer* will push each *agent* forward by one node until the mesh is finished 

*Moves* :
1. The *synchronizer* moves *SOUTH* and forces the encountered *agent* to execute one move *EAST*. 
2. The *synchronizer* executes one move *EAST*.
3. The *synchronizer* moves *NORTH* and forces the encountered *agent* to execute one move *EAST*. 
4. The *synchronizer* executes one move *EAST*
>[!note] 
>Since the *syncronizer* can't see if the mesh has ended it will need to make a last move to the *east* in order to verify that the *agent* can't be pushed more

>[!example] 
>![[DecontaminationCleanup.mp4]]

**Time Complexity** :  

The *syncronizer* moves : 
+ $m-1$ time units *North* and *South* ( going up and down the columns ) for $n-1$ columns : $(m-1)(n-1)$
+ $n-2$ time units *East* to move between colums  

In total we spend : 
$$(m-1) + (m-1)(n-1) + (n-2) + 1 = mn - 1$$

**Move Complexity** :

+ $m$ *agents* do $n-1$ moves *EAST* , $m(n-1)$
+ the *syncronizer* will do : 
	+ $n-2$ moves *EAST* 
	+ $m-1$ moves for each column except the last one 

In total : 
$$\frac{m(m-1)}2 + m(n-1) + n-2 + (m-1)(n-1) = \frac{m^2 +4mn -5m -2}{2}$$
>[!note] Edge Decontamination
>We can simply solve also the problem of *edge decontamination* simply adding one last stage at the cleaning process where the *sincronizer* will go *NORTH* ( or *SOUTH* depending on the mesh ) on the last column 
>
>This will result in the following complexities :
>+ *Time complexity* : $mn + m -2$
>+ *Move coplexity* : $\frac{m^2 +4mn -3m -2}{2}$

###### With Visibility

*Agents* can see their neighbouring nodes and so they can move independently 

For each *agent* $s$ : 
+ `if` the *Whiteboard* is *empty* 
	+ $s$ writes `CLEAN` 
	+ *guards* the node 
	+ moves *EAST* if all the $N(s)$ , except the one *EAST* are `CLEAN` or `GUARDED`
+ `if` the *Whiteboard* is `CLEAN` 
	+ move *SOUTH* 

>[!example]
>#todo animation

