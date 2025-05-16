---
publish: true
---
# The Model

+ **Autonomous** : there is no central control
+ **Homogeneous** : they run the same software
+ **Identical** 
+ No communication capabilities 

What is the minimum level of capabilities that a robot must possess to *Collectively* solve a task in a deterministic way :

Each robot has : 
+ limited storage and processing power 
+ some sensors to determine his position in a *local* coordinate system
+ some sensors to "*see*" other robots 
+ motors to move towards a destination
## Life Cycle

Each robot :
1. Uses its sensors to observe the world ( *LOOK* )
2. Based on the information gathered in the previous fase calculate a destination point ( *COMPUTE* )
3. Move to the computed destination ( *MOVE* ) 
>[!warning] 
>It might not reach the destination 
4. *SLEEP* ( to recharge batteries etcc ) 
5. Return to step $1$

## Limitations

### Visibility

The **Visibility** of a robot may be limited to a determined *radius*
### Coordinate System

The robots can have different agreement on the *coordinate system* : 
+ Total Agreement 
+ Agreement on axes and one orientation
+ Agreement on axes
+ No agreement 
### Time Synchronization

+ Fully Synchronous ( *FSYNC* )
	+ There is a **Global clock tick** reaching all robots simultaneously
	+ At each *tick* every *robot* will become *ACTIVE* and perform it's cycle
	
+ Semi Synchronous ( *SSYNC* )
	+ There is a **Global clock tick** reaching all robots simultaneously
	+ At each *tick* every *robot* is either *ACTIVE* or *INACTIVE* , only *ACTIVE* perform they'r cycle automatically
	
+ Asynchronous ( *ASYNC* )
	+ There is **no** global clock and robots do not have a common notion of time
	+ Each *robot* becomes *ACTIVE* at *unpredictable* times
	+ Each *Computation* will take a **FINITE** but *unpredictable* amount of time 

>[!example] 
>![[Illustration-of-activity-intervals-in-the-FSync-SSync-and-Async-scheduling-models.png]]
### Multiplicity Detection

+ **Weak** multiplicity detection :
	A *robot* can only distinguish if there is more than one robot together

+ **Strong** multiplicity detection :
	A *robot* can distinguish the number of robots together

### Oblivious

Each time a *robot* starts again it's cycle it will not have any memory of the past 

This is helpfull since *robots* can :
+ *crash*
+ join the network at any time and in any state 
+ can sustain *errors*

#todo add examples

