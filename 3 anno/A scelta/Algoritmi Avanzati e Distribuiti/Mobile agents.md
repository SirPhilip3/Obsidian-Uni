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

An *Harmful Host* can be considered a *blo*