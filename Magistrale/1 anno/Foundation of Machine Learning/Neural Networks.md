---
publish: true
---
# McCulloch and Pitts (MP) Model

Each *McCulloch-Pitts (MP) Neuron* is modeled as a *binary* **threshold** unit 

![[Untitled(1).svg]]

The unit will produce as output $y=1$ if the *net input* reaches or exceed the unit *threshold* ( or *bias* ) $T$ otherwise it will produce $y=0$ : 
$$
y = g\bigg(\sum_j w_j x_j - T\bigg)
$$
Where 
+ $\sum_j w_j x_j$ is the *net input* 
+ $g(x) = \begin{cases} 0 & \text{if } x < 0 \\ 1 & \text{if } x \ge 0 \end{cases}$ 

>[!note] 
>Weights $w_{ij}$ rapresent the *strength* of the synapse between neuron $j$ and neuron $i$ 

## MP neurons can simulate any Boolean circuit

It can be proven that the combination of *MP* neurons can simulate the behavior of any *boolean* circuit

>[!example] 
>#todo

## Network Topologies and Architectures 

Some typical network topologies are : 
+ **Feedforward** 
	In this case the data moves only in one direction 
>[!example] 

>[!note] 
>There may be cases where the data skips some *layers* 

+ **Feedback**
	In this case the data can loop between various nodes
>[!example] 

## Problem Types

We can separate *inference* problems in two different types : 
+ **Classification**
+ **Regression**

#todo 
### Digit Recognition

### Face Detection 

## Features Types 