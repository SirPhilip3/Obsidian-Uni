---
publish: true
---
>[!info] Minimization Problem
>Given an objective function $f: \mathbb{R}^D \to \mathbb{R}$ we want to find a vector $x^* \in \mathbb{R}^D$ that minmizes $f(x)$ : 
>$$
>x^* = \arg \min_{x \in \mathbb{R} f(x)}
>$$

In most learning tasks we want to minimize a **loss function** ( error of our predictions ) over multiple data points , the solution $x^*$ is the set of *parameters* that define the most accurate *machine learning model*
# Collaborative Filtering

>[!example] Loss function example

Given a *user* $u$ and an *item* $i$ we want to learn a *model* $g : U \times I \to \mathbb{R}$ that predicts the *rating* that the user $u$ would give to the item $i$ 

Let $R_{ui}$ be the *true rating* that the user $u$ gives to the item $i$ 

We can measure the errors of the model $g$ ( **loss** $L$ ) as the **Root Mean Squared Error** ( **RMSE** ) over a set of known ratings :
$$
L(g) = \sqrt{\frac{1}{|S|} \sum_{(u,i)\in S} (R_{ui}-g(u,i))^2 }
$$
Where $S=\{(u,i)\in U \times I | R_{ui} \text{ is known}\}$

>[!warning] 
>The prediction of a model depends on its *parameters* ( maximum number of nodes etcc )

We can rewrite the machine learning task as : 
$$
\theta^* = \arg \min_{\theta\in \Theta} L(g(\cdot; \theta)) = \arg \min_{\theta\in \Theta} \sqrt{\frac{1}{|S|} \sum_{(u,i)\in S} (R_{ui}-g(u,i;\theta))^2 }
$$
Where $\Theta$ is the set of *all possible parameters* of the model 
## UV-Decomposition

We assume that the *true rating* $R_{ui}$ can be approximated by the dot product of two vectors :
+ A *user vector* $u \in \mathbb{R}^k$
+ An *item vector* $v \in \mathbb{R}^k$

Where $k$ is the *latent dimesion* of the model 

*Users* and *items* can be described by the intensity of $k$ *topics* / *hidden factor* 

>[!example] 
>+ A *user* is intrested in a given genre, actor, director etcc 
>+ An *item* has a given genre, actor, director etcc

The *dot product* measures the **agreement** between the user intrest and the items characteristics

The **rating** matrix $R \in \mathbb{R}^{|U|\times |I|}$ is approximated by the product of two matrices : 
$$
R\approx UV
$$
Where $U \in \mathbb{R}^{|U| \times k}$ and $V \in \mathbb{R}^{k \times |I|}$ 

>[!example] 
>$$
>\begin{bmatrix}
>u_{11} & u_{12}  \\
>u_{21} & u_{22}  \\
>u_{31} & u_{32}
>\end{bmatrix} \cdot
>\begin{bmatrix}
>v_{11} & v_{12} & v_{13}  \\
>v_{21} & v_{22} & v_{23}
>\end{bmatrix}
>$$

**Goal** : Find $U$ and $V$ that minimize **RMSE** or **Sum of Squared Errors** ( *SSE* ) : 
$$
U,V = \arg \min_{U,V} \sqrt{\frac{1}{|S|} \sum_{(u,i)\in S}(R_{ui}-U_{u:} \cdot V_{:i})^2} = \arg \min_{U,V} \sum_{(u,i)\in S} (R_{ui} - U_{u:}\cdot V_{:i})^2
$$
>[!note] 
>$R_{ui}$ is the real *rating matrix* not approximated

## Minimum of the loss function

The minimum is where the *gradient* is $0$ :
$$
\partial L / \partial\theta = 0
$$
We search for the parameters $\theta ^ *$ where the gradient of $L$ is $0$ 

>[!example] 
>![[GradDesc.excalidraw.png]]
>%%[[GradDesc.excalidraw.md|🖋 Edit in Excalidraw]]%%

>[!warning] 
>This may be a *local minimum*

### UV-Decomposition Optimization

In [[Recommender Systems#User Based Collaborative Filtering|Collaborative Filtering]] we can start from a *random* $U,V$ and iteratively improve them.

Let's consider $U, V$ filled with $1$'s find the best value for $u_{11}$ :

$$
\begin{bmatrix}
u_{11} & 1 \\
1 & 1 \\
1 & 1
\end{bmatrix} \cdot
\begin{bmatrix}
1 & 1 & 1  \\
1 & 1 & 1
\end{bmatrix} = 
\begin{bmatrix}
u_{11} +1 & u_{11} +1 & u_{11}+1  \\
1 & 1 & 1  \\
1 & 1 & 1
\end{bmatrix} \approx 
\begin{bmatrix}
5 & 2 & 4  \\
3 & 1 & 2 \\
2 & & 3
\end{bmatrix}
$$

The *derivative* with respect to $u_{11}$ of $L$ ( considering the previous example rating matrix ) is : 
$$
\frac{\partial  L}{\partial u_{11}} = \frac{\partial \left( (5-(u_{11}+1))^2 + (2-(u_{11}+1))^2 + (4-(u_{11}+1))^2 \right)}{\partial u_{11}} = \frac{\partial(3 u_{11}^2 - 16 u_{11} + 26)}{\partial u_{11}} = 6u_{11} -16
$$
Valued to $0$ we have : 
$$
6u_{11}-16 = 0 \to u_{11} = \frac{6}{16} =0.375
$$

We can now update the matrix :
$$
\begin{bmatrix}
0.375 & 1 \\
1 & 1 \\
1 & 1
\end{bmatrix} \cdot
\begin{bmatrix}
1 & 1 & 1  \\
1 & 1 & 1
\end{bmatrix} = 
\begin{bmatrix}
1.375 & 1.375 & 1.375  \\
1 & 1 & 1  \\
1 & 1 & 1
\end{bmatrix} \approx 
\begin{bmatrix}
5 & 2 & 4  \\
3 & 1 & 2 \\
2 & & 3
\end{bmatrix}
$$

Now we can see that the dot product better "approximates" $R$ 

We can repeat the process for all entries of $U$ and $V$ 

For a generic $u_{rs}$ to be optimized we have :
$$
\begin{align}

\frac{\partial L}{\partial u_{rs}} &= \frac{\partial}{\partial u_{rs}} \sum_{j} (R_{rj} - U_{r:} \cdot V_{:j})^2 \\
&= \frac{\partial}{\partial u_{rs}} \sum_{j} (R_{rj} - \sum_{k} u_{rk} v_{kj})^2 \\ & = \frac{\partial}{\partial u_{rs}} \sum_{j} (R_{rj} - \sum_{k \neq s} u_{rk} v_{kj} - u_{rs} v_{sj})^2 \\
&= \sum_{j} 2(R_{rj} - \sum_{k \neq s} u_{rk} v_{kj} - u_{rs} v_{sj}) \cdot (-v_{sj}) \\ &= -2 \sum_{j} (R_{rj} - \sum_{k \neq s} u_{rk} v_{kj} - u_{rs} v_{sj}) v_{sj} \\
&= -2 \sum_{j} (R_{rj} - \sum_{k \neq s} u_{rk} v_{kj}) v_{sj} + 2u_{rs} \sum_{j} v_{sj}^2
\end{align}
$$
This is $0$ when : 
$$
u_{rs} = \frac{\sum_{j}\left( R_{rj}-\sum_{k\neq s} u_{rk}v_{kj} \right) v_{sj}}{\sum_{j}v^2_{sj}}
$$
For a generic $v_{rs}$ instead : 
$$
u_{rs} = \frac{\sum_{i}\left( R_{is}-\sum_{k\neq s} u_{ik}v_{ks} \right) v_{ir}}{\sum_{i}v^2_{ir}}
$$
### Algorithm

1. Initialize $U$ and $V$ with random values
2. Repeat until convergence:
	1. For each $u_{rs}$ :
		+ set $u_{rs}$ such that $\partial L / \partial u_{rs} = 0$ by using the previous rule
	2. For each $v_{rs}$ :
		+ set $v_{rs}$ such that $\partial L / \partial v_{rs} = 0$ by using the previous rule

>[!important] 
>+ we do *not consider unknown ratings* when computing gradients 
>+ the *update* of a rating is **not final**
>+ the procedure converges to a local minimum
>+ an exact algorithm exists but it requires $|U|\times |I|$ *space* and $O(|U|\times|I|\times k)$ *time* , unfeasable for massive datasets

>[!note] 
>$k$ is the number of *hidden features*

The larger the $k$ the smaller the error, since we will track all the possible intrest subject ( ??? ), but in contrast the error on unseen data increases causing *overfitting*

While smaller $k$ forces the model to compress information and capture patters
# Classification

>[!important] Binary Classification Problem
>Given a set of data points $S=\{(x_{i},y_{i})\}_{i=1}^n$ where $x_{i} \in \mathbb{R}^d$ and $y_{i} \in \{-1,1\}$ , we want to find a function $g: \mathbb{R}^d \to \{-1,1\}$ that minimizes the number of missclassifications

## Linear Classifier

A linear classifier is a function of the form : 
$$
g(x;w,b) = sign(w \cdot x+ b)
$$
Where $w \in \mathbb{R}^d$ and $b \in \mathbb{R}$

**Question** :
+ What is the best line $w \cdot x + b = 0$ that separates the data

## Support Vector Machine (SVM) 

An **SVM** is a linear classifier that maximizes the margin between the data points and the decision boundary

+ **margin** $\gamma$ the distance between the decision boundary and the *closest* data points
+ **support vectors** the data points at distance $\gamma$ from the decision boundary

>[!info] Idea
>The larger the margin the smaller the missclassification risck on unseen data

We want to solve the following optimization problem :
$$
\begin{align}
\max &\ \gamma \\
s.t. &\ y_{i}(w \cdot x_{i} + b) \ge \gamma
\end{align}
$$
>[!warning] 
>This is not well formulated since if $y_{i}(w\cdot x_{i}+b) \ge \gamma$ then $y_{i}(2w\cdot x_{i}+2b) = 2 y_{i}(w \cdot x_{i} +b)\ge 2 \gamma$ , so with $2w$ and $2b$ we found a solution with twice the marging so there is no unique solution  

>[!important] 
>Normalize $w$ and $b$ such that the margin is $1$ 

Given the two support vectors $x_{1}, x_{2}$ :
$$
\begin{align}
w \cdot x_{1}+ b &= 1 \\
w \cdot x_{2}+ b & = -1 
\end{align}
$$
By definition their distances from the decision boundary are :
$$
d_{1} = \frac{|w \cdot x_{1} + b|}{||w||_{2}}= \frac{1}{||w||_{2}}
$$
$$
d_{2} = \frac{|w \cdot x_{2} + b|}{||w||_{2}}= \frac{1}{||w||_{2}}
$$
We can change the optimization problem as : 
$$
\begin{align}
\max &\ \frac{1}{||w||_{2}} \\
s.t. &\ y_{i}(w \cdot x_{i} + b) \ge \gamma
\end{align}
$$

>[!info] 
>Maximizing the margin is equivalent to minimizing the norm of $w$ , or finding the *smallest* $w$ / *simplest* model $g$ 

### Approximate Separators

>[!important]
>It's not always possible to find a clean linear separator
>
>We intorduce a *penalty* depending on their distance from the margin:
>+ $0$ if $y_{i}(w \cdot x_{i} + b) \ge 1$
>+ $1-y_{i}(w \cdot x_{i} + b)$ otherwise

We aim at **minimizing** the *penalties* : 

$$
\min \frac{1}{2} ||w||_{2}^2 + C \sum_{i} \max(0,1-y_{i}(w \cdot x_{i} + b))
$$
>[!note] 
>+ $C$ is an hyperparmeter that controls the trade-off between *margin maximization* and *missclassification penalty* 

>[!warning] 
>An analytical solution exists but it cost $O(n^3)$
# Gradient Descent

**Idea** : 
+ Do *small steps* in the direction of the *negative* gradient
+ Repeat until convergence

**Algorithm** :
1. Start from a random parameter set $\Theta$
2. Repeat until convergence : 
	1. Compute the gradient $\Delta L(\Theta)$
	2. Update the parameters : $\Theta \leftarrow \Theta - \eta \Delta L(\Theta)$

>[!note] 
>$\eta$ is the *learning rate*

## Gradient Descent for SVM

The loss to be *minimized* is :
$$
\frac{1}{2} ||w||_{2}^2 + C \sum_{i} \max(0,1-y_{i}(w \cdot x_{i} + b))
$$
**First Term** :
$$
\frac{\partial}{\partial w_{j}} \frac{1}{2} ||w||_{2}^2 = \frac{1}{2} \frac{\partial}{\partial w_{j}} \sum_{k} w_{k}^2 = \frac{1}{2} 2 \cdot w_{j} = w_{j}
$$
**Second Term** : 
$$\frac{\partial}{\partial w}  C \sum_{i} \max\left( 0,1-y_{i}\left( \sum_{j} w_{j} \cdot x_{ij} + b \right) \right) = C \sum_{i} \begin{cases}
-y_{i} x_{ij} & if\ y_{i}(w \cdot x_{i} + b) < 1  \\
0 & \text{altrimenti} \end{cases}$$

>[!warning] 
>Updates are computed for all $w_{j}$ and $b$ and then applied at once 

## Batch Gradient Descent

The gradient is compute over the *whole dataset* and only after we updaate the parameter and repeat

>[!warning] 
>This is slow for large datasets
## Stocastinc Gradient Descent

The gradient is computed over a single data point chosen uniformly at random , after computing the gradient we update the parameters and repeat

>[!note] 
>Some instances may never be chosen

>[!warning] 
>This provides noisy convergence but it's fast for massive datasets
## Mini-batch Gradient Descent

Data is randomly partitioned in *mini-batches* of a limited size, the gradient is computed over that mini-batch, after this we update the paramers and repeat

>[!note] 
>Provide smooth and fast convergence

>[!example] 
>![[Pasted image 20260616135148.png]]

## Alternative to learning rate $\eta$

We can use :
+ *second derivaties* 
+ *momentum* 
+ *adaptive learning rate* 

In **Collaborative Filtering** we can :
+ use gradient descent
+ include regularization
+ add other terms to the loss function ( biases )