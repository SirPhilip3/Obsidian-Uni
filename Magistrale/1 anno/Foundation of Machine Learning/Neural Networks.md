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
>
>![[feedfwnn.excalidraw.png]]
>%%[[feedfwnn.excalidraw.md|🖋 Edit in Excalidraw]]%%

>[!note] 
>There may be cases where the data skips some *layers* 

+ **Feedback**
	In this case the data can loop between various nodes
>[!example] 
>![[connnn.excalidraw.png]]
>%%[[connnn.excalidraw.md|🖋 Edit in Excalidraw]]%%
## Problem Types

We can separate *inference* problems in two different types : 
+ **Classification**
	Returns a *class* ( eg apple, orange etcc )
+ **Regression**
	Returns a *continuos* value ( like temperature etcc )
### Digit Recognition

We get as *input* images $n \times n$ pixels and we need to classify them in $10$ classes , one for each digit

The number of *feature* will be than $1$ per pixel 
### Face Detection 

>[!note] 
>Face *detection* is different from face *recognition* , in the first case the objective is to find faces in an image in the second we need to assign an identity to the faces

We can see this problem as a sequence of *classification* problem where the system does not know the number of faces present in the picture 

A very simple implementation is where we create a *sliding window* of the image , for each position we run the *classifier* that tells us if there is a face or not

>[!warning] 
>The size of the *window* in this case is fixed but the faces can be of different dimension

>[!success] 
>A solution is that of repetedly run the algorithm on *down sampled* versions of the original image
## Features Types 

We can have two different types of *features* : 
+ *Numeric* :
	For example the weight of an apple
+ *Symbolic* : 
	For example the level of redness of an apple 

In order to rapresent an object in high dimensional space we need to l