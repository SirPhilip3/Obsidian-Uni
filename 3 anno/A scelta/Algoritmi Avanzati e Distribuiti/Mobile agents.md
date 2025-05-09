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

##### Cautious Walk in a Circle

In this case we can solve the *black hole* problem with $2$ *agents* 

>[!important] Supposition
>We suppose that each node has directionality ( each node has a port marked as left and one as right )

Two agents starting from the same *homebase* will explore using *cautious walk* one port each 

#todo 

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
### Decontamination Problem 

Initially all the agents are in an *homebase* and form a team and the whole network is **Contaminated** except the *homebase* 

An agent cleans a *node* when it enters it 

>[!important] Goal
>At the end the agents must *clean* the whole network

>[!warning] 
>A node becomes *contaminated* if it is not protected by an agent and at least one of it's neighbour is contaminated 

#### Decontamination Process

