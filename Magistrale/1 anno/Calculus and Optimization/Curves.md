---
publish: true
---
Let's consider the *functions* : 
$$
x_i(t) : \mathbb{R} \to \mathbb{R}, \quad i = 1, \dots,n
$$
for any $t \in [a,b] \subseteq \mathbb{R}$ ( $t$ is in an interval ) 

Then $x_i(t)$ is a *parametric* description of the point : 
$$
x(t) = \begin{pmatrix}
x_1(t) \\ \vdots \\ x_n(t)
\end{pmatrix} \in \mathbb{R}^n , \quad \forall t \in [a,b]
$$

This rapresents a **curve** in $\mathbb{R}^n$ 

>[!important] *Regular* Curve Definition
>
>Give the *curve* $x(t) \in \mathbb{R}^n$  , $\forall t \in [a,b] \subseteq \mathbb{R}$  we know that it's **regular** if : 
>1. $x_i(t) \in C^1([a,b])$ , for any $i = 1,\dots,n$ and for any $t\in [a,b]$ ( so it must be continuosly differentiable on the interval $[a,b]$ , included the extremes )
>2. $\sum_{i=1}^{n}[x_i'(t)]^2 \neq 0$ , for any $t \in [a,b]$ ( the *derivatives* of the functions $x_i(t),\dots,x_n(t)$ are not *simultaneously* $0$ )
>3. given the values $t_1,t_2 \in [a,b]$ if $t_1 \neq t_2$ we have $x(t_1) \neq x(t_2)$ ( for two distinct values of $t$ we can not obtain the same point in $\mathbb{R}^n$ )
# Tangent

Let's consider a *curve* $C$ , than we can consider the line by the two points $P$ and $Q$ such that : 
+ $P:x(t), t \in [a,b]$ 
+ $Q:x(t+\Delta t), t+\Delta t \in [a,b]$

Than the *secant* line between these points will be given by the following $n-1$ equations in $n$ unknowns
$$
l : \frac{x_1 -x_1(t)}{x_1(t+\Delta t)-x_1(t)} = \dots = \frac{x_n -x_n(t)}{x_n(t+\Delta t) -x_n(t)}
$$
In order to get the **tangent** line to $P$ we just need to move the point $Q$ to $P$ 

>[!note] 
>The *secant* will exists only if we assume that the curve is *regular* 

>[!example] 
>#todo why divide by delta t ?

We will just let $\Delta t \to 0^+$ which corresponds to : 
$$
l' : \lim_{\Delta t \to 0^+} \frac{x_1 -x_1(t)}{\frac{x_1(t+\Delta t)-x_1(t)}{\Delta t}} = \dots = \frac{x_n -x_n(t)}{\frac{x_n(t+\Delta t) -x_n(t)}{\Delta t}}
$$
By definition of *derivative* we can write the **tangent** as the following : 
$$
l' : \frac{x_1 -x_1(t)}{x_1(t)'} = \dots = \frac{x_n -x_n(t)}{x_n(t)'}
$$

>[!important] Orthogonal / Normal Hyperplane 
>
>We can define the *orthogonal hyperplane* to the curve $C$ at point $x(t)$ : 
>$$
>\pi_{x(t)} =\sum^{n}_{i=1} x'_i(t)[x_i-x_i(t)]
>$$

# Curvilinear Abscissa

The *curvilinear abscissa* on a curve rapresents the lenght of an arc on the curve between two points $P$ and $Q$ 

$$
s(t) = \pm \int^{t}_{t_0} \sqrt{[x_1'(\tau)]^2 + \dots + [x_n'(\tau)]^2} d \tau
$$
There is no determined *origin* so we can arbitrarily select $+$ ( $P \to Q$ ) or $-$ ( $Q \to  P$ ) 

>[!note] 
>$+$ if $t> t_0$ , $-$ otherwise

The *derivative* $s'(t)$ is : 
$$
s'(t)= \pm \sqrt{[x_1'(\tau)]^2 + \dots + [x_n'(\tau)]^2}
$$

