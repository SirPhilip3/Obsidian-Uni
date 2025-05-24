---
publish: true
---
# The Problem

Lot's of distributed algorithms ( like [[Distributed Spanning Tree]] ) do not work when we have multiple *initiators*

**Leader Election** algorithms move the system from an initial state where all *entities* are in the *same state* ( generically called *AVAILABLE* ) to a final configuration where all *entities* are in the same state ( *followers* ) except one ( **Leader** )

>[!note] 
>There is no restriction on how many entities *start* the computation nor on who becomes *leader*

>[!important] Theorem
>The *leader election* problem is *unsolvable* unless the *entities* have diffent *id* assigned
>
>>[!important] Assumptions
>>+ Bidirectional links
>>+ Connected graph
>>+ Total Reliability
>
>>[!question] Proof
>>Let's consider a system composed of two *identical* *entities* ( same id ) $x$ and $y$  , let's assume that they will start protocol $P$ at the same time , given that they are identical they will execute the same actions and will always remain in the *same* *state*
>>
>>This implies that if one becomes a *leader* also the other one will be one violating the *leader* definition 

![[SATURATION technique]]