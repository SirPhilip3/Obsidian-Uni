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

Since we need to have only one process access the resource at a certain time $t$ than we need to be sure that none of the remaining processes are requesting access to the resource : 
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
We **claim** that the probability that a process $i$ *fails* to access the shared resource in: 
+ $e \cdot n$ *round* is at most $1/e$  
+ $e\cdot n \cdot (c \ln n)$ *rounds* is at most $n^{-c}$ 


>[!note] 
>$c$ is a constant 

## Proof

Let's indicate with $F(i,t)$ the process $i$ that *fails* to access the shared resource in rounds $1$ through $t$ 

Since we know that the upper bound for the probability of *succeding* to access the resource is $\frac{1}{e \cdot n}$ ( from the previous proof ) , so the probability of *failing* will be $1-\frac{1}{e \cdot n}$ so the probabilty of doing it $t$ times in a row will be :
$$\bigg(1-\frac{1}{e\cdot n}\bigg)^{t}$$
Chosing : 
+ $e\cdot n$  we will have : $$\Pr[F(i,t)]\leq \bigg(1-\frac{1}{e\cdot n}\bigg)^{e \cdot n} \leq  \frac{1}{e}$$
+ $e\cdot n \cdot c \ln n$ we will have : $$\Pr[F(i,t)] \leq \bigg(\frac{1}{e}\bigg)^{c\ln n} = n^{-c}$$
---
We **claim** that the probability that *all* processes succeed within $2e\cdot n \cdot \ln n$ *rounds* is at least $1-\frac{1}{n}$

## Proof

Let $F(t)$ be the event that *at least one* of the $n$ processes *fails* to access the shared resource in any of the $t$ *rounds* :
$$\Pr[F(t)]=\Pr\bigg[\bigcup_{i=1}^n F(i,t)\bigg]\leq \sum_{i=1}^n \Pr[F(i,t)] \leq n\bigg(1-\frac{1}{en}\bigg)^t$$Chosing $t=2e\cdot n \cdot \ln n$ will give us :
$$\Pr[F(t)]\leq n \cdot n^{-2} = 1/n$$
Thus the probability that *all* processes will succeed within $2 e \cdot n \ln(n)$ is at least : $$1-1/n$$
