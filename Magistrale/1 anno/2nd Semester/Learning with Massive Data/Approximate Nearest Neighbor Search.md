---
publish: true
---
# Nearest Neighbor Search

>[!important] Problem Statement
>Let $\mathcal{X}=\{ x_{n} \}^N_{n=1}$ be a set of $N$ $D$-dimensional vectors where each $x_{n} \in \mathbb{R}^D$ 
>
>Given a *query* $y \in \mathbb{R}^D$ , *find* the vector $x_{n*}\in \mathcal{X}$ that is closest to the query $y$ :
>$$
>n^* = \arg \min_{n \in \{1,\dots,N\}} ||y - x_{n}||^2_{2}
>$$
>Where $||\cdot||_{2}$ is the *squared Euclidean distance*

>[!note] 
>Any other distance can be used 

A *Naive Solution* is **Linear Scan** : 

Compute the distance between the query $y$ and all the data points in $\mathcal{X}$ and then return the one with the minimum distance 

+ *Time Complexity* : $O(DN)$
+ *Space Complexity* : $O(DN)$

Too **expensive** for large datasets

# Approximate Nearest Neighbor Search

>[!important] Problem Statement
>Let $\mathcal{X}=\{ x_{n} \}^N_{n=1}$ be a set of $N$ $D$-dimensional vectors where each $x_{n} \in \mathbb{R}^D$ 
>
>Given a *query* $y \in \mathbb{R}^D$ , *find* the vector $\hat{x} \in \mathcal{X}$ such that :
>$$
>||y - \hat{x}||^2_{2} \leq (1+\epsilon) \cdot ||y - x_{n^*}||^2_{2}
>$$
>With $\epsilon>0$ being a small constant

>[!note] 
>The formula means that algorithms needs to find an element $\hat{x}$ such that its distance from the actual closest point is within a small error margin

**Idea** : 
+ Use a compact but *approximate* representation of the data points 
## Product Quantization (PQ)

Compacting data points is achieved through *vector quantization*

Consider a vector $x\in \mathbb{R}^D$ as a concatenation of $M$ subvectors each of dimension $D/M$ :
$$
x=[x^1,x^2,\dots, x^M]
$$
Where each $m$-th subvector is $x^m \in \mathbb{R}^{D/M}$ 

>[!info] Idea
>Map each $x^m$ into a small *integer* field

### Encoding

Consider a *subvector* $x^1$ 

1. All the possible values of $x^1$ in the dataset are clustered into $K$ clusters using [[Clustering#K-Means|K-means]] 
2. The $k$-th *centroid* of a cluster is called **sub-codeword** $c_{k}^1$
3. All the $K$ **sub-codewords** create a **sub-codebook** $C^1 = \{c_{k}^1\}^K_{k=1}$

We define a **sub-encoder** $i^m$ takes the subvector $x^m$ and returns the identifier of the closest *centroid* or *sub-codeword*
$$
i^m(x^m) = \arg \min_{k \in \{i,\dots,K\}} ||x^m - c^m_{k}||_2^2
$$
Now the *encoding* of a data point $x$ ( **PQ code** ) is the tuple of sub-encoders output :
$$
i(x) = [i^1(x^1),i^2(x^2),\dots,i^M(x^M)]
$$
#### Cost

A *sub-encoder* is implemented as a *linear scan* across all the $K$ centroids

+ The **computational cost** of a sub-encoder is $O(KD/M)$
+ To encode all the $M$ sub-vectors it takes $O(DK)$

The *space cost* depends on the number of *sub-vectors* $M$ and the number of *sub-codewords* $K$ :
+ The *space cost* of the encoding is $M \log_{2}K$ bits

>[!note] 
>In general we use :
>+ $K=256$
>+ $M=8$ or $M=16$ leading to a final cost of $64$ bits or $128$ bit

### Encoding error

Denoting $i^{-1}$ as the *inverse of the encoder*

>[!note] 
>The decoder maps from **PQ code** ids to corresponding *centroids* in the *sub-codebooks*

We measure the *error* of the encoding with respect to the *codebooks* $C=\{C^m\}_{m=1}^M$ ( **quantization error** ) as : 
$$
e(c;C) = || x -i^{-1}(i(x)) ||_{2}^2 = \sum^{M}_{m=1} \min_{k \in\{1,\dots, K\}} ||x^m -c_{k}^m||_{2}^2
$$
### Distance Computation

Since we store the full dataset as a set of *PQ codes* we can approximate the *distance* between a query $y$ and a data point $x_{n} \in X$ as follows : 
+ Use $\tilde{x}_{n}= i^{-1}(i(x_{n}))$ to reconstruct an approximation of $x_{n}$
+ Compute the distance between $y$ and $\tilde{x}_{n}$

>[!warning] 
>The *time complexity* is still large $O(DN)$

We can compute the distance without materializing the reconstructed vectors $\tilde{x}_{n}$ 
### Asymmetric Distance Computation (ADC)

For a given query $y \in \mathbb{R}^D$ and the *PQ code* $i(x_{n})$ :
1. For each *sub-vector* $y^m$ compute the distance between $y$ and all the $K$ *centroids* in all the $M$ sub-codebooks , resulting in a matrix $A \in \mathbb{R}^{M \times K}$ where $A(m,k) = ||y^m -c^m_{k}||_{2}^2$ 
2. Given the *PQ code* $i(x_{n})=[i^1,i^2,\dots, i^M]$ the approximate distance between $y$ and $x_{n}$ is given by :
$$
||y-x_{n}||_{2}^2 \approx \sum_{m=1}^M || y^m-c^m_{i^m} ||_{2}^2 = \sum_{m=1}^M A(m,i^m)
$$
**Computational Cost** : 
+ Precomputing $A$ takes $O(M \cdot K \cdot D/M)=O(DK)$ *time*
+ Computing the distances takes $O(M)$ *lookups*
>[!warning] 
>Large for single query computation

Computing $N$ distances gives a total cost of :
$$
O(DK+NM)
$$
>[!note] 
>In general the time is dominated by $NM$ *lookups*

## Inverted File Index (IVFADC)

[[#Asymmetric Distance Computation (ADC)|ADC]] performs a *full scan* of the dataset which is too expensive for large datasets

**Inverted File Index** instead uses a **Divide and Conquer** approach : 
### Indexing

1. Partition the dataset into $J$ buckets and let $\mu_{j} \in \mathbb{R}^D$ be the *representative vector* of the $j$-th bucket
2. The *Inverted File* index has $J$ initially *empty* postings lists one per bucket
3. For each $x_{n} \in X$ :
	1. Find the *closest* *representative* vector $\mu_{j}$
	2. Store the [[#Product Quantization (PQ)|PQ]] of the residual $x_{n}-\mu_{j}$ in the postings list of the $j^{th}$ bucket

>[!note] 
>*Partitioning* is [[Clustering#K-Means|K-means]] , we chose residual since they provide more precision than the orginal vector
### Searching

Given a *query* $y\in \mathbb{R}^D$ :
1. *Coarse quantization* : find the closest representative vector $\mu_{j}$
2. *Distance estimation* : use [[#Asymmetric Distance Computation (ADC)|ADC]] between the residual $y-\mu_{j}$ and all the [[#Product Quantization (PQ)|PQ codes]] in the $j^{th}$ bucket

>[!note] 
>$J$ is typically $\sqrt{N}$
>Search considering returning more than one bucket to search in 
>

## Hierarchical K-Means (HKM)

### Indexing

Define the following hyperparameters : 
+ $k$ : branching factor
+ $L_{\max}$ : max depth of the tree
+ $N_{\min}$ : minimum number of points in a leaf 

The algorithm : 
1. If the dataset is $\le N_{\min}$ or we reached the $L_{\max}$ depth create a *Leaf* containing all the dataset remaining
2. Else run [[Clustering#K-Means|K-Means]] on the dataset creating $k$ clusters
3. Recursively run the algorithm on each of the created *clusters* 
4. Return a *Node* with the *centroid* and a pointer to the *Nodes* or *Leafs* created 

>[!example] 
>![[Pasted image 20260614215512.png]]

### Search

1. If we are in a *Leaf* 
	1. Return the $id$ of the closest datapoint : $id \leftarrow \arg \min_{j=1}^M ||q-x_{j}||^2_{2}$
2. Else 
	1. Find the *nearest* centroid : $id \leftarrow \arg \min_{i=1}^M ||q-c_{i}||^2_{2}$
	2. Move to the children of that centroid and recursively run tha algorithm 

>[!example] 
>![[Pasted image 20260614215537.png]]

## Hierarchical Navigale Small World (HNSW)

It's goal is to build a *multi-layer graph* where :
+ Every node is a data point
+ Edges *smartly* connect close data points 
+ The dataset is searched by traversing the graph
+ The *top layer* is the sparsest ( fewest edges )
+ The *bottom layer* constains all the data points

### Insertion

**Layer Assignment** : a new data point $q$ is randomly assigned a *maximum layer* $l$ : 
$$
l =  \bigg\lfloor \frac{-\ln(uniform(0,1))}{\ln M} \bigg\rfloor
$$
Where $M$ is the parameter that controls the number of *neighbours*

The expected number of layers is $O(\log_{M}N)$

**Greedy Traversal** : starting from an entry point at the highest level, search the one nearest neighbour up to layer $l+1$ 

At each layer : 
1. Greedy search the *one nearest neighbour* of $q$ in layer $l$ 
	1. evaluate the neighbours of the current node
	2. select the closest to $q$
	3. repeat until no more improvements
2. Use the cosest node found as entry point for layer $l-1$ 

**Insert into Layers** : insert $q$ in all layer from $l$ down to $0$ and set edges with other nodes in each layer 

At each layer down to $0$:
1. **Beam Search** : 
	1. Keep a queue $W$ of the *best nearest neighbours* found so far
	2. Evaluate neighbours of nodes in $W$ and add them to $W$ if they are closer to $q$ 
	3. Repeat until no more improvments
2. Add bi-directional edges between $q$ and the selected neighbours
3. If any of the selected neighbour has more then $M_{\max}$ edges remove the least useful ones
4. $W$ becomes the entry point for the next layer

>[!note] 
>If $q$ was inserted in a new higher layer it becomes the entry point of the *HNSW*

### Search

Given a query point $q$ run a *greedy search* from the entry point at top layer down to $0$ :

1. For each layer from $L$ down to $1$ :
	1. *Greedy Search* as in **Traversal**
	2. Use the closest node as entry point for layer $l-1$
2. At layer $0$ :
	1. **Beam search** as in **Insertion**
	2. Return the one or $k$ nearest neighbours

