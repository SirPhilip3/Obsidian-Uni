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

## Inverted File Index

## Hierarchical K-Means

## Hierarchical Naviavle Small World