# The problem

>[!info] Input
>Given :
>+ $m$ identical *machines* 
>+ $n$ *jobs* with each job $j$ having processing time $t_j$ 

>[!important] Definitions
> 
>+ **Load** of a machine $i$ as :
>	$L_i = \sum_{j \in J(i)}t_j$     where $J(i)$ is the subset of jobs assigned to machine $i$ 
>+ **Makespan** is the *maximum load* on any machine $L=\max_i L_i$ 

And knowing that :
+ A job $j$ must run *contiguosly* ( until termination ) on one single machine 
+ A *machine* can process at most **one** job at a time

>[!success] Optimization Version
>Assign each *job* to a *machine* in order to **minimize** the *makespan* 

>[!note] 
>It can be proven that this problem is **NP-Hard**

# Approximation Algorithms

![[List Scheduling]]