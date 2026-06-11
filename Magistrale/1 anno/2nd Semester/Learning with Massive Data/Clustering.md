---
publish: true
---
>[!important] Definition
>The goal of *clustering* is to group the data of a given dataset into *clusters*
>
>A *Cluster* is a collection of data objects that are : 
>+ **Similar** to other objects within the same cluster
>+ **Dissimilar** to other objects in other clusters 

>[!note] 
>*Clustering* is **unsupervised learning**


The quality of a clustering algorithm depends on : 
+ ability to handle clusters of *arbitrary shapes, sizes* and *densities*
+ ability to handlw *noise* and *outliers*
+ *computational complexity*
+ *scalability* to large dataset

## Cluster Quality

**High quality clusters** have : 
+ *high intra-class similarity* : cohesion within clusters
+ *low inter-class similarity* : distinctive between clusters

>[!important] Definition
>Let the **Centroid**  of a *cluster* be the **mean** of the data points in the cluster

The quality measure for clusters is **Sum of Squared Distances** ( **SSD** ) or *inertia* of the data points to the center of their cluster

Given a dataset $D$, with $n=|D|$ data points 

+ Let $C_{1}, C_{2},\dots,C_{k}$ be a clustering of $D$ and let $c_{i}$ be the *centroid* of cluster $C_{i}$ 
+ Let $d(x,y)$ be the distance between data points $x$ and $y$ 

>[!example] 
>The *distance* is the *Euclidian distance* $d(x,y) = \sqrt{ \sum_{j}(x_{j}-y_{j})^2 }$

Then the quality of the *clustering* is given by : 
$$
SSD=\sum^{k}_{i=1}\sum_{x\in C_{i}} d(x,c_{i})^2
$$
To have *good clustering* this quantity should be **Minimized**
# K-Means

Approach : 
1. Start with *random* *centroids* $c_{1},c_{2},\dots, c_{k}$
2. Improve them iteratively by minimizing **SSD**

```pseudo
	\begin{algorithm}
	\caption{K-Means Algorithm}
	\begin{algorithmic}
	\Input Dataset $D$, number of clusters $k$
	\State $c_1,\dots,c_k \leftarrow$ random data points from $D$
	\While{clusters keep changing or $\Delta SSD > \epsilon$}
		\State $C_i = \{ x \in D | d(x,c_i) \leq d(x,c_j)\ \forall\ j \neq i \}$
		\State $c_i \leftarrow \frac{1}{|C_i|}\sum_{x \in C_i} x$
    \EndWhile
	\end{algorithmic}
	\end{algorithm}
```

>[!note] 
>The *assigning* of the clusters and the *update* of the centroid minimize the *Sum of Squared Distances*

## Properties

+ Initializing the centroid at random has **problems** 
	+ It can handle only *spherical clusters* of *similar size* and *density*
+ The algoritm converges to a *local optimum*, in fact it can be demostrated that *minimizing* $SSD$ is **NP-hard** for a general number of clusters $k$ even for a 2-D euclidian space

The number of **clusters** $k$ can be determined by varying $k$ and choose a value of $k$ corresponding to the **elbow** of the error curve ( **Elbow Method** )

The *elbow* can be defined as the point where increasing $k$ does not reduce the error significantly

>[!example] 
>![Elbow Method for optimal value of k in KMeans - GeeksforGeeks](https://media.geeksforgeeks.org/wp-content/uploads/20241028173908396970/Elbow-Method.png)

# K-Means++

*K-Means++* replaces the random initialization with a **smart** *centroid selection*

**Centroid initialization** :

```pseudo
	\begin{algorithm}
	\caption{K-Means++ Initialization}
	\begin{algorithmic}
	\Input Dataset $\mathcal{D}$, number of centroids $k$
	\State $c_1 \leftarrow$ single random data point from $\mathcal{D}$ 
	\For{$i=2$ to $k$}
		\ForAll{$x \in \mathcal{D}$}
			\State $D(x)^2 = \min_{j<i} d(x,c_j)^2$
	    \EndFor
	    \State $c_i \leftarrow$ sample data point $x \in \mathcal{D}$ with probability $P(x) = \frac{D(x)^2}{\sum_{x' \in \mathcal{D}}D(x')^2}$
    \EndFor
	\end{algorithmic}
	\end{algorithm}
```

>[!note] 
>```pseudo
>	\begin{algorithm}
>	\caption{}
>	\begin{algorithmic}
>	\ForAll{$x \in \mathcal{D}$}
>		\State $D(x)^2 = \min_{j<i} d(x,c_j)^2$
>	\EndFor
>	\end{algorithmic}
>	\end{algorithm}
>```
>
>For every single data point $x$ calculate the distance to it's *nearest centroid* 
>
>```pseudo
>	\begin{algorithm}
>	\caption{}
>	\begin{algorithmic}
>	\State $c_i \leftarrow$ sample data point $x \in \mathcal{D}$ with probability $P(x) = \frac{D(x)^2}{\sum_{x' \in \mathcal{D}}D(x')^2}$
>    \end{algorithmic}
>	\end{algorithm}
>```
>
>The next centroid will be selected with *probability* that prioritizes *distant* points
>
>>[!note] 
>>The fraction is just to *normalize* the distances

With this *initialization* we can say that 

>[!important] K-means++ is *Error bound*
>
>For any dataset $\mathcal{D}$, K-means++ *guarantees* that the expected $SSD$ is at most $8(\ln k +2)$ **times** the *optimal* $SSD$ 

>[!warning] 
>This algorithm is very *inefficent*. The complexity is $O(|\mathcal{D}|\cdot k \cdot i)$ where $i$ is the number of *iterations*

# Mini-Batch K-Means

To improve efficency *Mini-Batch K-Means* uses only a small sample at each iteration 

```pseudo
	\begin{algorithm}
	\caption{Mini-Batch K-Means}
	\begin{algorithmic}
	\Input Dataset $\mathcal{D}$, number of clusters $k$, mini-batch size $b$
	\State $v_i \leftarrow 0$ for every cluster centroid $c_i$
	\While{centroids keep changing or for max $t$ iterations}
		\State $M \leftarrow$ sample of $b$ objects from $\mathcal{D}$
		\For{}
		
        \EndFor
        \For{}
        
        \EndFor
    \EndWhile
	\end{algorithmic}
	\end{algorithm}
```

# CURE
