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

In order to rapresent an object in high dimensional space we need to be able to rapresent it as a *point* so we need to transform the *symbolic* variables into *numerical* ones

One way to do this is *one hot encoding* :
	Given a *feature* $f$ with $3$ *symbolic* possible values than we create $3$ columns than rapresent the presence of that *value* in the object at hand

>[!example] 

| Symbolic feature | ohe_1 | ohe_2 | ohe_3 |
| ---------------- | ----- | ----- | ----- |
| 1                | 1     | 0     | 0     |
| 2                | 0     | 1     | 0     |
| 3                | 0     | 0     | 1     |

## Smoothness Assumption

>[!important] 
>Two objects rapresented by $2$ points in the *hyperspace* can be considered to be in the same *class* if they are sufficently *close* to each other
# Neural Networks for Classification

## Thresholds

We can remove the *bias* ( or *threshold* ) as a parameter in the *activation function* by adding an additional input that is *permanently clamped* to $-1$ or $+1$ 

The *net input* becomes than :
$$
\begin{align}
& = \sum_{i=1}^n w_i x_i - T \\
& = \sum_{i=1}^n w_i x_i - w_0 \cdot (-1) \\
& = \sum_{i=1}^n w_i x_i + w_0 \cdot 1 \\
& = \sum^{n}_{i=0} w_i x_i, \quad \text{where } x_0 = -1
\end{align}
$$

>[!note] 
>If we expand the formula with $n=2$ we get : 
>$$
>w_1 x_1 + w_2 x_2 + w_0
>$$
>
>Where the *weights* create all the possible lineas separating 2 region of space $<0$ and $>0$  ( 2 *classes* )
## Perceptron

The *perceptron* is the simplest form of *neural network* consisting of *one* layer of *M&P* neurons connected in a *feedforward* way 
### Perceptron Learning Algorithm

Parameter and variables : 
+ $x(n)$ : the *inputs*
+ $w(n)$ : the *weights*
+ $b$ : the *bias*
+ $y(n)$ : **actual** response ( that given by the neural network )
+ $d(n)$ : **desired** response 
+ $\eta$ : the *learning rate* $>0, <1$

>[!important] Learning Algorithm

1. Initialization 
	Set $w(0) = 0$
2. Activation
	At time-step $n$ activate the *perceptron* by applying the continuos input vector $x(n)$ and get the *desired* response $d(n)$ 
3. Actual Response 
	Compute the *actual* response of the *perceptron* as : 
$$
y(n) = sgn[w^T(n)\cdot x(n)]
$$
4. Weight vector adaptation
	Update the *weight* vector of the *perceptron* in the following way :
$$
w(n+1) = w(n) + \eta [d(n)-y(n)]\cdot x(n)
$$
	Where 
$$
d(n) = \begin{cases}
+1 & \text{if } x(n) \text{ belongs to class } \mathscr{C}_1 \\
-1 & \text{if } x(n) \text{ belongs to class } \mathscr{C}_2 \\
\end{cases}
$$
5. Continuation
	Increment the time step $n$ and go back to step $2$

## Decision Regions

#todo 

### Linear Separability

### Limitation of Perceptron

## Perceptron Convergence Theorem

# Back-Propagation Learning Algorithm

