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

+ The **computatioinal cost** of a sub-encoder is $O(KD/M)$
+ To encode all the $M$ sub-vectors it takes $O(DK)$

The *space cost* depends on the nunmber of *sub-vectors* $M$ and the number of *sub-codewords* $K$ :
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
1. For each *sub-vector* $y^m$ compute the distance between $y$ and all the $K$ *centriods* in all the $M$ sub-codebooks , resulting in a matrix $A \in \mathbb{R}^{M \times K}$ where $A(m,k) = ||y^m -c^m_{k}||_{2}^2$ 
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


## Inverted File Index

## Hierarchical K-Means

## Hierarchical Naviavle Small World