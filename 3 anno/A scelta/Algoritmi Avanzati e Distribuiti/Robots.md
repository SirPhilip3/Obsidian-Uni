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

# The Gathering Problem 
## The Problem

Initially every robot is in arbitrary position , by the end they should *gather* in the same place 
## In FSYNC

The problem is *solvable* 

>[!check] 
>
>Go thowards the *Center-of-Gravity* ( *CoG* ) of the robot group
>
>To get the the vector towards which to move :
>$$\stackrel{\rightarrow}{c} = \frac{1}{N} \sum_{i=1}^{N} \stackrel{\rightarrow}{p_i}$$  

>[!warning] 
>The *CoG* can change over time since we can't be certain that the *agent* will reach it's destination 

## In SSYNC and ASYNC

A solution to the fact that the *Center of Gravity* can change over time could be using the :

>[!note] Weber Point
>
>Given $r_1,\dots , r_n$ the **Weber Point** is the point minimizing the sum of distances to it :
$$WB = \arg \min \sum_i dist(p,r_i)$$
>
>>[!important] 
>>The *Weber Point* is unique
>
>>[!important] 
>>The *Weber Point* will also be the *Weber Point* for all other point present on the line between $[r_i,WP]$ 
>
>This implies that the **Weber Point** will be *invariant* to robots movent towards it 

>[!error] 
>The **Weber Point** is not computable 

## Gathering for 2 Robots

### In FSYNC

Go to the *middle point* 
### In SSYNC

>[!error] 
>The problem it's *unsolvable*

>[!note] 
>The robot's in this theoretical model do not have any dimensionality ( they are like points in a plane )

One *robot* could wake up only each other round 
>[!warning] 
>This will achieve *convergence* but not gathering

In *general* we can apply $3$ rules to each robot : 
1. Go to the other robot place 
2. Stay in place 
3. Go to some other vacant point

>[!important] 
>In any case an adversarial actor can :
>1. If *both* follow rule $1$ , make them both awake
>2. Else *wake* one robot that does not apply rule $1$

#### With Randomization

We can solve the problem using *randomization* :
+ **Possible rules** :
	1. Go to the other robots place 
	2. Stay in place 
+ **Algorithm**
	1. Flip a coin
	2. Apply rule $1$ or $2$ according to that flip 

This way each robot will *gather* in each round with a probability of $\frac{1}{2}$ 

## Gathering for 3 and 4 robots

### In SSYNC

1. If the robots are in the *same line* just meet in the middle 
>[!example] 
>![[ThreePointsGather.mp4]]

2. Otherwise they must be in a *triangle shape*
	1. If the one angle is *greather* than $120\degree$ than that *robot* will remain still and the other two will reach it 
>[!example] 
>![[TriangleGatherPoints.mp4]]

Otherwise the *robots* will meet in the **Center of Equiangularity** ( where each internal angle is the same ( $120\degree$ ) ) ( or *first Fermat Point* )

>[!example] 
>![[FermatPointTriangle.mp4]]

## Gathering in SSYNC for $N\ge3$

>[!important] Moltiplicity point definition
>
>A point $p^*$ where there are two or more *robots* 
>

>[!important] Assumptions
>
>+ Initially there are no multiplicity point ( each *robot* will be in a different position )
>+ *Robots* can detect multiplicity 
>

**Strategy** : 
1. Create a ***single*** *multiplicity point* $p^*$ 
2. Move other *robots* to $p^*$ along "free corridors" ( a line where there are no other *robots* moving in )

>[!warning] 
>If two or more *multiplicity point* accour than the problem becomes **unsolvable** 
>
>New multiplicity point can be created if : 
>+ two path intersect
>+ two robots halt permanently after moving a distance 

### Stage 1

>[!important] Definition Smalles Enclosing Circle ( *SEC* )
>
>For a given point configuration the *SEC* is : 
>+ *Unique*
>+ Computable in polynomial time
>+ Is invariant while the *points on it* do not move

Creating the *multiplicity point* : 
1. If $N=3$ , invoke *3-gather*
2. If $N \ge 3$ calculate the *SEC* 
	1. $C_{int}$ will be the number of *robots* inside
	
+ If $|C_{int}| = 0$ go to the *center* of *SEC*
>[!example] 
+ If $|C_{int}| = 1$ go to the single *internal robot*
>[!example] 
+ If $|C_{int}| = 2$ : the two internal nodes will need to create one *multiplicity point*

1. Compute the *Voronoi* partition of the robots *on SEC*
	1. If the *internal robots* do *not share* a cell move to the center f