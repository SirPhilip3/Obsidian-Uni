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
#todo

# Classification

# Gradient Descent