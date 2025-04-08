---
publish: true
---
# The Problem

Lot's of distributed algorithms ( like [[Distributed Spanning Tree]] ) do not work when we have multiple *initiators*

**Leader Election** algorithms move the system from an initial state where all *entities* are in the *same state* ( generically called *AVAILABLE* ) to a final congifuration where all *entities* are in the same state ( *followers* ) except one ( **Leader** )

>[!note] 
>There is no restriction on how many entities *start* the computation nor on who becomes *leader*

>[!important] Theorem
>The *leader election* problem is *unsolvable* unless the *entities* have diffent *id* assigned

>[!important] Assumptions
>+ Bidirectional
>+ Connected graph
>+ Total Reliability

