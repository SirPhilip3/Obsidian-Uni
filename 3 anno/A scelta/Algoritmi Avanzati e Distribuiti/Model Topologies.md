---
publish: true
---
# 2-dimensional mesh

A *2D meshes* is a $X \times Y$ grid with each *node* having a distinct label $(x,y)$ ( where $0 \leq x \leq X-1$ and $0 \leq y \leq Y-1$ ) 

We have 3 types of nodes :
+ The ones on the 4 edges with $2$ connections each
+ The ones on the sides with $3$ connections each
+ All the other one with $4$ connections each

>[!note] 
>A switch that has label $(0\leq x < X-1, 0 \leq y < Y-1)$ will always be connected to swithces $(x,y+1), (x,y-1),(x+1,y),(x-1,y)$

>[!example] 
# 3-dimensional mesh

Same as per *2D meshes* but now each node has label $(x,y,z)$

>[!example] 

# Torus network

A *torus* is a *2D mesh* that has the connections between the border *nodes* completed with the opposite *node* 

>[!example]
>![Example of the grid graph (left) and torus graph (right), both with... |  Download Scientific Diagram](https://www.researchgate.net/publication/319662543/figure/fig4/AS:631635653455910@1527605083636/Example-of-the-grid-graph-left-and-torus-graph-right-both-with-dimensions-d-6-5.png) 
# Hypercubes

## 1 dimension (H1)

Every node has a label of $k$ bits ( $k$ is the dimension of the *hypercube* ) ,

Each *arc* label rapresent the position of the bit , starting from the right , where the node labels differ

>[!example] 
>![[1DHyperCube.excalidraw.png]]

## 2 dimension (H2)

In order to build a *2D HyperCube* we duplicate **H1** and we add $1$ bit to the nodes label , for the first **H1** we add a $0$ at the end and for the second one a $1$ at the end

>[!example] 
>![[2DHyperCube.excalidraw.png]]
## 3 dimension (H3)

>[!example] 
>![[3DHyperCube.excalidraw.png]]

An *HyperCube* $H_k$ with $k$ dimensions will have $2^k$ *nodes* , each node has $k$ *arcs* ( $m=n\cdot k /2$ ) 

And since $k = \log n$ we will have that $m = n \cdot \log n /2$ 
## 4 dimension (H4)

>[!example] 
>#todo

# Trees

