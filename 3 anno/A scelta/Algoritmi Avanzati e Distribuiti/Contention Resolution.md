# The Problem

Given $n$ processes $P_1,\dots,P_n$ each one of them compete to access a shared resource ( could be a database or a CPU ) 

>[!warning] 
The shared resource can only support one access per round , if two or more processes access the resource simultaneously all processes will be locked out 

# Randomized Algorithm

Each process will request access to the resource at time $t$ with probability $p = 1/n$ 

>[!note] 
>$n$ are the number of processes

We **claim** that the probability of success of a process $i$ to access the resource at time $t$ ( $S(i,t)$ ) is :
$$\frac{1}{e \cdot n} \leq \Pr[S(i,t)] \leq \frac{1}{2n}$$
## Proof

Since we need to have only one process access the resource at a certain time $t$ than we need to be sure that none of the reamaining processes are requesting access to the resource : 
$$\Pr[S(i,t)] = p \cdot (1-p)^{n-1}$$
By sobstitution we have : 
$$\Pr[S(i,t)]=1/n \cdot (1-1/n)^{n-1}$$
>[!note] 
>It can be demonstrated that $(1-1/n)^{n-1}$ converges monotonically from $1/2$ down to $1/e$ 

We can write 
$$\frac1e\leq \bigg(1-\frac1n\bigg)^{n-1}\leq\frac 12$$
$$\frac1n\cdot \frac1e\leq\frac1n\cdot\bigg(1-\frac1n\bigg)^{n-1}\leq \frac1n \cdot \frac12$$
$$\frac{1}{n\cdot e} \leq \Pr[S(i,t)]\leq \frac{1}{2n}$$
---
We **claim** that the probability that a process $i$ fails to access the shared resource in: 
+ $e \cdot n$ *round* is at most $1/e$  
+ $e\cdot n \cdot (c \ln n)$ *rounds* is at most $n^{-c}$ 


>[!note] 
>$c$ is a constant 

## Proof

