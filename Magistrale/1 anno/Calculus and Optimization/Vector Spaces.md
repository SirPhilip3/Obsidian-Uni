---
publish: true
---
>[!important] Definition
>Let : 
>+ $V$ be a set of objects ( *vectors* )
>+ $K$ be a *numerical set* ( *Field* )
>
>Than we call $V(K)$ a **Vector Space** over the *field* $K$ if some propieties hold 
>

We define the following operations : 
+ $+$ : *cross* between two $V(K)$
+ $\bullet$  : *bullet* between the elements of $K$ and the vectors of $V$ 
+ $\oplus$ : *crossed circle* between two $K$
+ $\cdot$   : *dot* between two $K$

**Propieties** of a *Vector Space* : 
0. 
$$
\colorbox{green}{$x+y\in V(K)$} \forall x, y \in V(K)
$$
( **Closure propiety** )
	Given $x,y$ being part of $V(K)$ than the result of the operation of *cross* $+$ must be part of $V(K)$
1. 
$$\colorbox{green}{(x + y) + z = x + (y + z)} , \forall x,y,z \in V(K)
$$
( **Associative propiety** )
2. 
$$
\colorbox{green}{$\exists w \in V(K) : x + w = x$} , \forall x \in V(K)
$$
( **Neutral / Null vector** )
	$w$ is the *null vector* ( for integers this will be $0$ )
3. 
$$
\colorbox{green}{$\exists \bar x  \in V(K) : x + \bar x = w$}, \forall x \in V(K)
$$
	It exists $\bar x$ such that *summed* to the original $x$ it will produce the *null vector* ( for integers this will be $-1\cdot x$ ) , $\bar x$ is called **Inverse / Opposite vector**
4. 
$$
\colorbox{green}{x+y = y +x}, \forall x,y \in V(K)
$$
( **Commutative propiety** )

>[!note] 
>An *Abelian group* is a *Vector space* such that only the first $5$ rules are satisfied ( it uses only one operand $+$ ) 

5. 
$$
\forall \alpha , \beta \in K , \forall x \in V(K) \implies \colorbox{green}{$\alpha \bullet x \in V(K) \implies \alpha \bullet (\beta \bullet x ) = (\alpha \cdot \beta)\bullet x$}
$$
7. 
$$
\colorbox{green}{$\exists \sigma \in K : \sigma \bullet x = x$} , \forall x \in V(K)
$$
	$\sigma$ is a *unit* in the numerical set $K$ ( $1$ for $\mathbb{R}$ ) 
8. 
$$
\forall \alpha \in K : \colorbox{green}{$\alpha \bullet (x +y) = \alpha \bullet x + \alpha \bullet y$} ,\forall x, y \in V(K)
$$
( **Distributed propiety** 1 )
9. 
$$
\forall x \in V(K), \forall \alpha, \beta \in K : \colorbox{green}{$ (\alpha \oplus \beta) \bullet x = \alpha \bullet x + \beta \bullet x$}
$$
( **Distributed propiety** 2 )

>[!example] Some examples of **Vector Spaces**

+ $\mathbb{R}(\mathbb{R}) \approx \mathbb{R}$ 
	This rapresents the *real* numbers with the standard operations amongst *real* numbers
	
	*Null vector* : $0$
	*Opposite vector* : $x \cdot -1$ 
	*Unit* $\sigma$ : $1$

>[!example] 
>Why does the multiplication of two negative numbers produce a positive number
>
>#todo

+ $\mathbb{R}^n(\mathbb{R}) \approx \mathbb{R}^n$ : set of *n-tuplas* 

$$
\alpha x = \alpha \begin{pmatrix}
x_1  \\
\vdots \\
x_n 
\end{pmatrix} = \begin{pmatrix}
\alpha x_1  \\
\vdots \\
\alpha x_n 
\end{pmatrix}
$$
$$
x + y = \begin{pmatrix}
x_1  \\
\vdots \\
x_n 
\end{pmatrix}  + \begin{pmatrix}
y_1  \\
\vdots \\
y_n 
\end{pmatrix} = \begin{pmatrix}
x_1 + y_1  \\
\vdots \\
x_n + y_n
\end{pmatrix}
$$
$$
w = \begin{pmatrix}
0  \\
\vdots \\
0 
\end{pmatrix}
$$
+ $M_{m,n}(\mathbb{R})$ : where $M_{m,n}$ is a matrix of $m$ *rows* and $n$ *colums*

+ $P_n(x) , x \in \mathbb{R}$ is the *set* of all the possible *polynomials* of *degree* **at most** $n$ where $x$ is the only unknown variable in the *polynomial* 

>[!example] 
>$p(x) = p_0 + p_1 x + p_2 x^2+ \dots + p_n x^n$

Given $p_1(x) = x^3-x^2+2x -2 \in P_4(x)$ and $p_2(x) = 2x^2 + 1 \in P_4(x)$ 

$p_1(x) + p_2(x) = x^3 + x^2+2x +0 \in P_4(x)$

$\alpha p(x) = (\alpha p_0) + (\alpha p_1) x + \dots + (\alpha p_n) x^n$ 

The *null vector* is a *polynomial* with all coefficients that are at $0$ 

*Opposite* will be a *polynomial* with all reversed signs 

$\sigma  = 1$ 

>[!warning] 
>The set of polynomials that are the exact degree $n$ is **not** a *vector space* 
>
>The *closure* propiety does not hold : 
>given $p(x) = x^4$ and $q(x) = -x^4$ than $p(x)+q(x) = 0$ , but $0$ is not in the *vector space* since we define the degree of a polynomial as the *largest* non null degree , so in this case the degree qould would be $0$

## Dimensions of a Vector Space 

The dimension of a vector space is given by the number of : 
>[!important] **Linearly Indipendent Vectors** 
>A set of vectors that rapresents the whole vector space 
>
>These are those *vectors* that satisfy the following criteria : 
>given $v_1, \dots , v_n \in V(K)$ and $\alpha_1, \dots, \alpha_n \in K$ than the *vectors* $\{v_1, \dots , v_n\}$ are *linearly indipendent* if : 
>$$
>\alpha_1 v_i + \dots + \alpha_n v_n = w \iff \alpha_1= \dots = \alpha_m = 0
>$$
>

>[!example] 
>$$
>\alpha_1 \begin{pmatrix} 5 \\ 5 \end{pmatrix} + \alpha_2 \begin{pmatrix} 2 \\ 2 \end{pmatrix} + \alpha_3 \begin{pmatrix} 1 \\ 1 \end{pmatrix} = \begin{pmatrix} 0 \\ 0 \end{pmatrix}
>$$
>
>Since in order to get $w$ as a result we could have values of $\alpha$ that are not $0$ ( $\alpha_1 = 1/5, \alpha_2 = 0, \alpha_3 = -1$ ) these are not *lineraly independent*
## Vector Space Combinations

### Affine Combiantion

>[!important] Definition
>Given the *set* of *vectors* : $v_1,\dots,v_n \in \mathbb{R}^n$
>
>We say that the *vector* $s \in \mathbb{R}^n$ is an **affine combination** of *vectors* $\{v_i,\dots,v_m\}$ on $\mathbb{R}$ if :
>$$
>s = \alpha_1v_1 + \dots + \alpha_m v_m\qquad \text{with} \quad \sum_{i=1}^{m} \alpha_i = 1, \alpha_i \in \mathbb{R}
>$$

We can give a *geometric rapresentation* considering a set of vectors of size $2$ ( so that the rapresentation is two dimensional ) :  

$s$ are all the *vectors* whos second extreme is on the *line* *between* the two extremes of $v_1$ and $v_2$

>[!example] 
>
>![[Tute1_ManimCE_v0.19.0.png]]
### Cone Combination

>[!important] Definition
>Given the *set* of *vectors* : $v_1,\dots,v_m \in \mathbb{R}^n$
>
>We say that the *vector* $z \in \mathbb{R}^n$ is a **cone combination** of *vectors* $\{v_i,\dots,v_m\}$ on $\mathbb{R}$ if :
>$$
>z = \alpha_1v_1 + \dots + \alpha_m v_m\qquad \text{with} \quad \alpha_i \ge 0, i = 1, \dots, m
>$$

This the following *geometric* two dimensional interpretation of the **cone combination** 

$z$ are all the vectors that stay in the *area* between $v_1$ and $v_2$  

>[!example] 
>![[ConeCombiantion_ManimCE_v0.19.0.png]]
### Convex Combination

>[!important] Definition
>Given the *set* of *vectors* : $v_1,\dots,v_n \in \mathbb{R}^n$
>
>We say that the *vector* $y \in \mathbb{R}^n$ is a **convex combination** of *vectors* $\{v_i,\dots,v_m\}$ on $\mathbb{R}$ if :
>$$
>s = \alpha_1v_1 + \dots + \alpha_m v_m\qquad \text{with} \quad \sum_{i=1}^{m} \alpha_i = 1,\alpha_i \ge 0,\quad \alpha_i \in \mathbb{R} ,i = 1, \dots, m
>$$

So $y$ is a *convex cobination* if it's both an *affine combination* and a *cone combination*

So geometrically we can rapresent it as the *vector* passing through the two extremes of $v_1$ and $v_2$

>[!example] 
>![[ConvexCombination_ManimCE_v0.19.0.png]]

## Inner Product ( Scalar )


>[!important] Definition
>The **inner product** '$<\bullet, \bullet>$' is defined as a *function* :
>$$
>f : V^n(\mathbb{R}) \times V^n(\mathbb{R}) \rightarrow \mathbb{R}
>$$

With the following *properties* : 

1. $<x,x>\ge 0$ with $<x,x> = 0 \iff x = 0$ , $\quad \forall x \in V^n(\mathbb{R})$ 
2. $<x , y +z > = <x,y> + <x,z> \quad \forall x,y,z \in V^n(\mathbb{R})$
3. $<x,y> = <y,x> \quad \forall x, y \in V^n(\mathbb{R})$

>[!important] **Standard** *inner product*
>
>Given *vectors* $x,y \in \mathbb{R}^n$ than by definition :
>$$
><x,y> = x^Ty
>$$

>[!example] 
>With
>$$
>x = \begin{pmatrix}
>x_1 \\ \vdots \\ x_n
>\end{pmatrix} \quad y = \begin{pmatrix}
>y_1 \\ \vdots \\ y_n
>\end{pmatrix}
>$$
>Than
>$$
><x,y> = x^Ty = \begin{pmatrix}
>x_1, \dots,x_n
>\end{pmatrix}\times \begin{pmatrix}
>y_1 \\ \vdots \\ y_n
>\end{pmatrix} = \sum_{i=1}^n x_i y_i
>$$
## Vector Norms

>[!important] 
>The **norm** of a *vector* $x \in V^n(\mathbb{R})$ is the *function* from $V^n(\mathbb{R})\rightarrow\mathbb{R}^+ \cup \{0\}$  , indicated with $||\bullet||$ 

With the following *proprieties* :
1. $||x|| \ge 0$ with $||x||=0 \iff x = 0, \quad \forall x \in V^n(\mathbb{R})$ 
2. $||\alpha x|| = |\alpha|\ ||x||, \quad \forall x \in V^n(\mathbb{R}), \forall \alpha \in \mathbb{R}$
3. $||x+y|| \le ||x|| + ||y||, \quad \forall x,y \in V^n(\mathbb{R})$

*Standard* norms : 

+ $||x||_1 = |x_1|+\dots+ |x_n|$
+ $||x||_2 = (x^T x)^{1/2} = [x_1^2 +\dots + x_n^2]^{1/2}$ ( *euclidean norm* )
+ $||x||_\infty = \max_{1\le i \le n}|x_i|$ 

Geometrically we can rapresent them in the following way ( with only two *unknowns* ) : 

![[NormsScene_ManimCE_v0.19.0 1.png]]

The *euclidean norm* can be written as the [[Vector Spaces#Inner Product ( Scalar )|Inner Product]] between vectors $x,y \in \mathbb{R}^n$ in the following way : 
$$
<x,y> = x^T y = \sum_{i=1}^n x_i y_i = ||x||_2\cdot ||y||_2 \cdot \cos(\widehat{xy})
$$
Where $\widehat{xy}$ is the *smallest angle* between vectors $x$ and $y$ of $\mathbb{R}^n$
## Linear Functions

>[!important] Definition
>
>Given the function $f : \mathbb{R}^n \to \mathbb{R}^m$ we say that $f(x)$ is *linear* in $\mathbb{R}^n$ if it satisfies the following *relations* : 
>1. $f(x+y) = f(x)+f(y), \quad \forall x,y \in \mathbb{R}^n$
>2. $f(\alpha x) = \alpha f(x), \quad \forall x \in \mathbb{R}^n, \forall \alpha \in \mathbb{R}$

>[!example] 
>$f(x,y) = 3xy$

>[!note] 
>*Linear functions* **must** pass through the origin

## Affined Functions

>[!important] Definition
>Given the function $g(x)$ , with $g: \mathbb{R}^n \to \mathbb{R}^m$ we say that $g(x)$ is an *affine function* in $\mathbb{R}^n$ if there exists a function $f(x)$ , *linear* in $\mathbb{R}$ , and the vector $\bar{c} \in \mathbb{R}^m$ , such that 
>$$
>g(x) = f(x)+ \bar{c}
>$$ 

>[!example] 
>$g(x,y) = 3xy + 5$

## Continuos Differentiability in $\mathbb{R}^n$ 

>[!important] Definition
>Given the function $f : \mathbb{R}^n \rightarrow \mathbb{R}$ than we say that $f(x)$ is $p$ **times continuosly differentiable** on the 'closed set' $\mathcal{A}$, if in the 'open set' $\mathcal{B}$ , with $\mathcal{A} \subset \mathcal{B}$  there exists both the *partial* and *mixed* derivatives of $f(x)$ up to order $p$ and they are continuos in $\mathcal{B}$

>[!note] 
>When $f: \mathbb{R} \to \mathbb{R}$ than : 
>$$
>\frac{\partial f(x)}{\partial x} \equiv \frac{df(x)}{dx}
>$$ 

For $p=1$ we use *Gradient* : $\nabla f(x)$ , we can so say that $f \in C^1(\mathbb{R}^n)$ 

Where : 
$$
\nabla f(x) = \begin{pmatrix}
\frac{\partial f(x)}{\partial x_1} \\ \vdots \\ \frac{\partial f(x)}{\partial x_n}
\end{pmatrix}
$$

For $p=2$ we use *Hessian* : $\nabla^2 f(x)$ , we can so say that $f \in C^2(\mathbb{R}^n)$ 

Where : 
$$
\nabla^2 f(x) = \begin{pmatrix}
\frac{\partial^2 f(x)}{\partial x_1 \partial x_1}  & \dots & \frac{\partial^2 f(x)}{\partial x_1 \partial x_n} \\ \vdots & \ddots & \vdots \\ \frac{\partial^2 f(x)}{\partial x_n \partial x_1} & \dots & \frac{\partial^2 f(x)}{\partial x_n \partial x_n}
\end{pmatrix}
$$

>[!important] Definition
>Given the function $f : \mathbb{R}^n \to \mathbb{R}$ with domain $\mathcal{A} \subseteq \mathbb{R}^n$ we say that the point $\bar{x} \in \mathcal{A}$ is of **regularity** for $f(\bar{x})$ if $\nabla f(x)$ is *defined*
>>[!note] 
>>The previous definition simply states that the point $\bar x$ is a *regular* point if $\nabla f(\bar x)$ exists or more simply if $f(\bar x)$ is *differentiable*

## Taylor Expansion

>[!important] Definition
>
>Given the function $f(x)$ , let $f : \mathbb{R}^n \to \mathbb{R}$ be $f \in C^m(\mathbb{R^n})$ ( *continuosly differentiable* at least $m$ times ) in the **neighborhood** $I(x, \delta) = \{x \in \mathbb{R}^n : ||x-\bar{x}|| \leq \delta , \delta > 0\}$ of the point $\bar{x}$. Than we have :
>$$
>f(x) = \sum^{m}_{h=0} \frac{D^h f(\bar{x})}{h!}(x-\bar{x})^h + R_{m+1}(\bar x) , \quad \lim_{x\to \bar x} \frac{R_{m+1}(\bar x)}{||x - \bar x||^m} = 0
>$$ 

Where $h$ indicates the *order* of the *partial derivative* and $D^h f(\bar{x})$ indicates the *partial derivative* of order $h$ computed at point $\bar{x}$ 

The *taylor series* allows us to approximate a function $f(x)$ on a point $\bar{x}$ because by $x$ approaching $\bar{x}$ we have that :
$$
\lim_{x\to \bar x} \frac{R_{m+1}(\bar x)}{||x - \bar x||^m} = 0
$$
### $m=0$

When $m=0$ the *taylor expansion* becomes the following expression :
$$
\frac{D^0 f(\bar{x})}{0!}(x-\bar{x})^0 + R_{0+1}(\bar x)
$$
Simplified it becomes : 
$$
f(\bar{x}) + R_1(\bar{x})
$$
With $(x-\bar{x})^0 \equiv 1$

### $m=1$ 

$$
\dots + \frac{D^1 f(\bar{x})}{1!}(x-\bar{x})^1 + R_{2}(\bar x)
$$
$$
\dots + \nabla f(\bar{x})^T(x - \bar{x}) +R_2(\bar{x})
$$
### $m=2$

$$
\dots + \frac{D^2 f(\bar{x})}{2!}(x-\bar{x})^2 + R_{3}(\bar x)
$$
$$
\dots + \frac{1}{2}(x-\bar{x})^T\nabla^2 f(\bar{x})(x-\bar{x})+ R_3(\bar{x})
$$
## Directional Derivatives

>[!important] Definition
>Let $f(x) : \mathbb{R}^n \to \mathbb{R}$ be $f\in C^1(\mathbb{R}^n)$ ( *continuosly differentiable* in $\mathbb{R}$ only **once** )
>
>We say that the function $f(x)$ in the point $x \in \mathbb{R}^n$  admits **directional derivative** $D(f,d)$ along the *direction* $d \in \mathbb{R}^n - \{0\}$ if there exists the limit : 
>
>$$
>D(f,d) = \lim_{\alpha \to 0^+} \frac{f(x+\alpha d) - f(x)}{\alpha}
>$$
>

>[!note] 
>$$
>D(f,d) = \nabla f(x)^Td
>$$

>[!example] 
>Given $f(x_1,x_2,x_3) = x_1 + x_2^2x_3^2$ let's compute the *directional derivative* along the direction $d = \begin{pmatrix}1\\2\\3\end{pmatrix}$ at the point $\bar{x} = \begin{pmatrix}0\\1\\0\end{pmatrix}$
>
>$$
>\begin{align}
>D(f,d) & = \nabla f(\bar{x})^Td \\ & = \begin{bmatrix}1 \\ 2 x_2 x_3^2 \\ 2x_2^2x_3\end{bmatrix} \cdot \begin{bmatrix} 1\\2\\3\end{bmatrix} \\ & = \begin{bmatrix}1 \\ 0 \\ 0\end{bmatrix} \cdot \begin{bmatrix} 1\\2\\3\end{bmatrix} \\ & = 1
>\end{align} 
>$$
>
>Given that $1 > 0$ than we know that $f(x_1,x_2,x_3)$ in $\bar{x}$ is *increasing*
>

## Mean Values Theorem

### First order MVT

>[!important] Definition
>Given the function $f : \mathbb{R}^n \to \mathbb{R}$ be $f\in C^1(\mathbb{R}^n)$ on the open neighborhood $I(x,\rho) = \{y \in \mathbb{R}^n : ||y -x||< \rho\} \subseteq \mathbb{R}^n$ , with $x \in \mathbb{R}^n$ and $\rho > 0$
>
>Ther *exists* a value $\theta \in [0,1]$ such that *for any* $y\in I(x,\rho)$ : 
>1. $f(y) = f(x) + \nabla f[x+\theta(y-x)]^T(y-x)$
>2. $f(y) = f(x)+\nabla f(x)^T(y-x) + o(||y-x||)$
>
>Where by definition :
>$$
>\lim_{y \to x} \frac{o(||y-x||)}{||y-x||} = 0
>$$
>

Geometrical rapresentation for $n=1$ : 

![[FirstOrderExpansion_ManimCE_v0.19.0.png]]

>[!example] 
>Given $f(x_1,x_2) = 3x_1^2 + x_1 \ln(3-x_2)$
>
>This function is *continuosly differentiable* on the set $S = \{(x_1,x_2)\in \mathbb{R}^2 : x_2 < 3\}$ 
>
>Find the value of $\theta$ for $\bar{x} = \begin{pmatrix}2\\2\end{pmatrix}$ and $\bar{y}= \begin{pmatrix}2 \\ 5/2\end{pmatrix}$
>
>$f(\bar{x}) = 12 + 2 \cdot \ln(1) = 12$
>$f(\bar{y}) = 12 + 2 \cdot \ln(1/2)$
>
>$\nabla f(x_1,x_2) = \begin{bmatrix}6 x_1 + \ln(3 -x_2) \\ -\frac{x_1}{3-x_2}\end{bmatrix}$
>
>$\bar{x} + \theta(\bar{y}-\bar{x}) = \begin{pmatrix}2 \\ 2\end{pmatrix} + \theta \begin{pmatrix}0 \\ 1/2\end{pmatrix} = \begin{pmatrix}2 \\ 2 +\frac{\theta}{2}\end{pmatrix}$
>
>Finally :
>$$
>12 + \ln(\frac{1}{2}) = 12 + \begin{bmatrix} 12 + \ln (1- \frac{\theta}{2}) \\ - \frac{2}{1-\frac{\theta}{2}}\end{bmatrix} \cdot \begin{bmatrix}0 \\ \frac{1}{2}\end{bmatrix}
>$$
>
>$\theta \sim 0.557$

### Second order MVT

>[!important] Definition
>Give the function $f : \mathbb{R}^n \to \mathbb{R}$ be $f\in C^2(\mathbb{R}^n)$  on the open neighborhood $I(x,\rho) = \{y \in \mathbb{R}^n : ||y -x||< \rho\} \subseteq \mathbb{R}^n$ , with $x \in \mathbb{R}^n$ and $\rho > 0$
>
>There *exists* a value $\theta \in [0,1]$ such that *for any* $y\in I(x,\rho)$ : 
>1. $f(y) = f(x) + \nabla f(x)^T(y-x) + \frac{1}{2}(y-x)^T \nabla^2 f[x+\theta (y-x)](y-x)$
>2. $f(y) = f(x) + \nabla f(x)^T(y-x) + \frac{1}{2}(y-x)^T \nabla^2 f(x)(y-x) + o(||y-x||^2)$
>
>Where by definition : 
>$$
>\lim_{y \to  x} \frac{o(||y-x||^2)}{||y-x||^2} = 0
>$$

## Local \ Global Maximum \ Minimum

### Local Minimum

>[!important] Definition
>
>Let be $\mathcal{A} \subseteq \mathbb{R}^n$ and the function $f: \mathcal{A} \to \mathbb{R}$ , the point $x^* \in \mathcal{A}$ is a **local minimum** of $f(x)$ , if there exists an *open neighborhood* $I(x^*, \rho) = \{x \in \mathbb{R}^n : ||x - x^*|| < \rho \}$ with *center* $x^*$ and *radius* $\rho > 0$ such that  : 
>
>$$
>f(x^*) \leq f(x), \quad \forall x \in I(x^*, \rho) \cap \mathcal{A}
>$$
>

>[!note] 
>Or all the points present in the *neighborhood* of $x^*$ and in the *domain* $\mathcal{A}$ must be higher than $x^*$ 

>[!note] *Strict local minimum*
>If we impose that $x \neq x^*$ and $f(x^*) < f(x)$ to the definition than $x^*$ becomes a point of *strict local minimum* 

In order to be a *local minimum* the following condition must be satisfied :
$$
f'(x) = 0
$$
### Global Minimum

>[!important] Definition
>
>Let be $\mathcal{A} \subseteq \mathbb{R}^n$ and the function $f: \mathcal{A} \to \mathbb{R}$ , the point $x^* \in \mathcal{A}$ is a **global minimum** of $f(x)$  if : 
>
>$$
>f(x^*) \leq f(x), \quad \forall x \in \mathcal{A}
>$$

>[!note]
>Or all the point present in the *domain* $\mathcal{A}$ of the function must be higher than $x^*$ 
>

>[!note] *Unique global minimum* 
>
>If we impose that $x \neq x^*$ and $f(x^*) < f(x)$ to the definition than we call $x^*$ a point of *unique global minimum*
>
### Local Maximum

>[!important] Definition
>
>Let be $\mathcal{A} \subseteq \mathbb{R}^n$ and the function $f: \mathcal{A} \to \mathbb{R}$ , the point $x^* \in \mathcal{A}$ is a **local maximum** of $f(x)$ , if there exists an *open neighborhood* $I(x^*, \rho) = \{x \in \mathbb{R}^n : ||x - x^*|| < \rho \}$ with *center* $x^*$ and *radius* $\rho > 0$ such that  : 
>
>$$
>f(x^*) \geq f(x), \quad \forall x \in I(x^*, \rho) \cap \mathcal{A}
>$$
>

>[!note] 
>Or all the points present in the *neighborhood* of $x^*$ and in the *domain* $\mathcal{A}$ must be lower than $x^*$ 

>[!note] *Strict local maximum*
>If we impose that $x \neq x^*$ and $f(x^*) > f(x)$ to the definition than $x^*$ becomes a point of *strict local maximum* 

In order to be a *local maximum* the following condition must be satisfied :
$$
f'(x) = 0
$$
### Global Maximum

>[!important] Definition
>
>Let be $\mathcal{A} \subseteq \mathbb{R}^n$ and the function $f: \mathcal{A} \to \mathbb{R}$ , the point $x^* \in \mathcal{A}$ is a **global maximum** of $f(x)$  if : 
>
>$$
>f(x^*) \geq f(x), \quad \forall x \in \mathcal{A}
>$$

>[!note]
>Or all the point present in the *domain* $\mathcal{A}$ of the function must be lower than $x^*$ 

>[!note] *Unique global maximum* 
>
>If we impose that $x \neq x^*$ and $f(x^*) > f(x)$ to the definition than we call $x^*$ a point of *unique global maximum*
## Convexity 

### Convexity for Sets

>[!important] Definition
>Give the *nonempty* set $C \subseteq \mathbb{R}^n$ we say that $C$ is a **convex set** if : 
>$$
>\lambda x + (1-\lambda)y \in C, \quad \forall x,y \in C ,  \forall \lambda \in [0,1] 
>$$

>[!note] 
>The point $\lambda x + (1-\lambda)y$ , when $\lambda \in [0,1]$ , is any point in the closed segment joining $x$ and $y$
>

>[!example] 
>
>![[convexSet.excalidraw.png]]
>%%[[convexSet.excalidraw.md|🖋 Edit in Excalidraw]]%%

Some *convex* sets are : 
+ $\mathbb{R}^n$
+ $\mathbb{R}$
+ *Singleton* ( set composed of only 1 element )
+ $\emptyset$
>[!note] Empty set ( $\emptyset$ )
>
>We denote the *empty set* as a *convex set* for *convention* ( in fact we could not apply the definition of convex set since there are no point $x$ or $y$ )
+ Any *polyhedron*
#### Intersection between Sets

>[!important] Definition
>We say that given the *convex sets* $C_1,\dots,C_m$ with $m\geq 1$ than the *intersection* $C = C_1 \cap \dots \cap C_m$ is a *convex set*

**Proof** :

If $C$ is *empty* or contains only one point ( *singleton* ) than the proof is self evident

Instead where $C$ is composed of $2$ or more points than we can give the following proof : 

Given than $x, y\in C$ we can say that , by definition of intersection , also $x,y \in C_i, i = 1, \dots,m$ 
Than we can also say that $\lambda x+ (1-\lambda) y \in C_i, \forall \lambda \in [0,1]$ , since this belongs to all $C_i$ it must also belong to $C$ by definition of *intersection*

>[!example] 
>
>![[Inersection.excalidraw.png]]
>%%[[Inersection.excalidraw.md|🖋 Edit in Excalidraw]]%%

>[!example] 
>Given a set of contraints on a problem we can rapresent them as theyr intersection and retain theyr convexity

### Convexity for Functions

Given the function $f : \mathbb{R}^n \to \mathbb{R}$ than it has the following *property* :
$$
f[\lambda x + (1-\lambda)y] \leq \lambda f(x) + (1-\lambda)f(y) , \quad \forall x,y \in C, \forall \lambda \in [0,1] 
$$
Where $C$ must be a *convex set* 

>[!example] 
>![[Pasted image 20251022165435.png]]

$f$ can also be said **strictly convex** if the following *property* holds : 
$$
f[\lambda x + (1-\lambda)y] < \lambda f(x) + (1-\lambda)f(y) , \quad \forall x,y \in C, \forall \lambda \in ]0,1[ 
$$
### Concave Functions

Give the function $f: \mathbb{R}^n \to \mathbb{R}$ and $f \in C^0(\mathbb{R}^n)$ than it has the following *property* : 
$$
f[\lambda x + (1-\lambda)y]\ge \lambda f(x) + (1-\lambda)f(x) \quad \forall x,y \in C, \forall\lambda \in [0,1]
$$
Where $C$ must be a *convex set*

>[!example] 
>![[Pasted image 20251027112448.png]]

$f$ can also be said **strictly concave** if the following *property* holds : 
$$
f[\lambda x + (1-\lambda)y] > \lambda f(x) + (1-\lambda)f(y) , \quad \forall x,y \in C, \forall \lambda \in ]0,1[ 
$$

>[!caution] Linear and Affine functions
>
>*Linear* and *Affine* functions are by *definition* both **Convex** and **Concave** 

## Min / Max equality

Some solvers are able to solve only *maximality* problems but we can simply see that : 
$$
\min f(x) \equiv \max -f(x) ,\quad \forall x \in C
$$
>[!example] 
>So if $x^*$ is a global *mininum* for $f(x)$ than $x^*$ is a global *maximum* for $-f(x)$ 
>
>![[MinMaxEquivalence_ManimCE_v0.19.0.png]]

## Penalty Methods

Given the following *minimization problem* : 
$$
\min f(x)
$$
Where $f(x)$ is subject to the following **contraints** : 
$$
\mathcal{X} = \begin{cases}
g_1(x) \le 0 \approx A_1 \\
g_2(x) \le 0 \approx A_2 \\
\dots \\
g_n(x) \le 0 \approx A_n 
\end{cases}
$$
Where $A_1, \dots, A_n$ are *subset* of the *vector space* identified by each contraint 
Since we need to fullfill all the contraints at the same time : $$\mathcal{X} = A_1 \cap A_2 \cap \dots \cap A_n$$  
>[!note] 
>For the [[Vector Spaces#Intersection between Sets|Intersection Between Convex Set]] we can say that $\mathcal{X}$ will be *convex*

We can rewrite the problem in the following *unconstrained* form : 
$$\min = f(x) + \sum^{n}_{i=1} \rho_i \max\{0,g_i(x)\}, \quad \rho_i \ge 0$$
#todo clarification on formula

We can derive two *lemmas* from the previous formula : 

Given that $g_1(x),\dots,g_n(x), \quad g_i : \mathbb{R}^n \to \mathbb{R}, i = 1, \dots , n$ are [[Vector Spaces#Convexity for Functions|Convex Functions]] on $\mathbb{R}^n$ and $\rho_i \ge 0, i=1,\dots,n$ 

>[!important] Lemma 1
>$$
>\sum^{n}_{i=1} \rho_i g_i(x)
>$$
>
>Is **convex** on $\mathbb{R}^n$ 
>>[!note] 
>>This equates to the [[Vector Spaces#Cone Combination|Cone Combiantion]]
>
>

>[!important] Lemma 2
>$$
>\sum^{n}_{i=1} \max[0,g_i(x)]
>$$
>Is **convex** on $\mathbb{R}^n$

We can derive the following *theorems*

>[!important] Theorem 1
>
>Suppose we want $\min f(x)$ ( $\mathcal{P}$ )
>$f : \mathbb{R}^n \to \mathbb{R}, C \subseteq \mathbb{R}^n$ is a [[Vector Spaces#Convexity for Sets|Convex Set]]  
>
>$f$ **convex** on $C$ 
>
>If $x^* \in C$ is a [[Vector Spaces#Local Minimum|Local Minimum]] of $f(x) \Rightarrow x^*$ is a [[Vector Spaces#Global Minimum|Global Minimum]] 

>[!important] Theorem 2
>$f : \mathbb{R}^n \to \mathbb{R}, C \subseteq \mathbb{R}^n$ is a [[Vector Spaces#Convexity for Sets|Convex Set]]  
>
>$f$ **convex** on $C$ 
>
>Then the set of solutions of $\mathcal{P}$ is **Convex**
## Level Set

Given the function $f(x)$ with $f : \mathbb{R}^n \to \mathbb{R}$ , let $f(x)$ be **convex** on $\mathbb{R}^n$

Then the **level set** ( possibly empty ) $\mathcal{L}_\gamma$ is *defined* as :
$$
\mathcal{L}_\gamma = \{x \in \mathbb{R}^n : f(x) \leq \gamma\}
$$
is **convex** $\forall \gamma \in \mathbb{R}$ 

Or all the possible real points $x$ that fullfillis $f(x) \leq \gamma$  ( where $\gamma$ is set at our will )

>[!example]
>
>![[levelsetex.excalidraw.png]]
>%%[[levelsetex.excalidraw.md|🖋 Edit in Excalidraw]]%%

