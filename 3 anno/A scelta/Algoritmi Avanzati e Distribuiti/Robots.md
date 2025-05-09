# The Model

+ **Autonomous** : there is no central control
+ **Homogeneous** : they run the same software
+ **Identical** 
+ No communication capabilities 

What is the minimum level of capabilities that a robot must possess to *Collectively* solve a task in a deterministic way 

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
>It might not reach it 
4. *SLEEP* ( to recharge batteries etcc ) 
5. Return to step $1$

## Limitations

The **Visibility** of a robot may be limited to a determined *radius*

The robots can have different agreement on the *coordinate system* : 
+ Total Agreement 
+ Agreement on axes and one orientation
+ Agreement on axes
+ No agreement 

**Synchronization** :
+ Fully Synchronous ( *FSYNC* )
+ Semi Synchronous ( *SSYNC* )
+ Asynchronous ( *ASYNC* )

#todo 
# The Gathering Problem

