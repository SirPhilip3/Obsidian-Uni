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
0. $$\fcolorbox{green}{}{$x+y\in V(K)$} \forall x, y \in V(K)$$  ( **Closure propiety** )
	Given $x,y$ being part of $V(K)$ than the result of the operation of *cross* $+$ must be part of $V(K)$

1. $$\fcolorbox{green}{}{(x + y) + z = x + (y + z)} , \forall x,y,z \in V(K)$$ ( **Associative propiety** )

2. $$\fcolorbox{green}{}{$\exists w \in V(K) : x + w = x$} , \forall x \in V(K)$$ ( **Neutral / Null vector** )
	$w$ is the *null vector* ( for integers this will be $0$ )

3. $$\fcolorbox{green}{}{$\exists \bar x  \in V(K) : x + \bar x = w$}, \forall x \in V(K)$$
	It exists $\bar x$ such that *summed* to the original $x$ it will produce the *null vector* ( for integers this will be $-1(x)$ ) , $\bar x$ is called **Inverse / Opposite vector**

4. $$\fcolorbox{green}{}{x+y = y +x}, \forall x,y \in V(K)$$( **Commutative propiety** )

>[!note] 
>An *Abelian group* is a *Vector space* such that only the first $5$ rules are satisfied ( it uses only one operand $+$ ) 

5. $$\forall \alpha , \beta \in K , \forall x \in V(K) \implies \fcolorbox{green}{}{$\alpha \bullet x \in V(K) \implies \alpha \bullet (\beta \bullet x ) = (\alpha \cdot \beta)\bullet x$}$$
6. $$\fcolorbox{green}{}{$\exists \sigma \in K : \sigma \bullet x = x$} , \forall x \in V(K)$$
	$\sigma$ is a *unit* in the numerical set ( $1$ ) 
7. $$ \forall \alpha \in K : \fcolorbox{green}{}{$\alpha \bullet (x +y) = \alpha \bullet x + \alpha \bullet y$} ,\forall x, y \in V(K)$$ ( **Distributed propiety** 1 )

8. $$\forall x \in V(K), \forall \alpha, \beta \in K : \fcolorbox{green}{}{$ (\alpha \oplus \beta) \bullet x = \alpha \bullet x + \beta \bullet x$}$$
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

$$\alpha x = \alpha \begin{pmatrix}
x_1  \\
\vdots \\
x_n 
\end{pmatrix} = \begin{pmatrix}
\alpha x_1  \\
\vdots \\
\alpha x_n 
\end{pmatrix}$$
$$x + y = \begin{pmatrix}
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
\end{pmatrix}$$
$$w = \begin{pmatrix}
0  \\
\vdots \\
0 
\end{pmatrix} $$
+ $M_{m,n}(\mathbb{R})$ : where $M_{m,n}$ is a matrix of $m$ *rows* and $n$ *colums*

+ $P_n(x) , x \in \mathbb{R}$ is teh *set* of all the possible *polynomials* of *degree* **at most** $n$ where $x$ is the only unknown variable in the *polynomial* 

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
>These are those *vectros* that satisfy the following criteria : 
>given $v_1, \dots , v_n \in V(K)$ and $\alpha_1, \dots, \alpha_n \in K$ than the *vectors* $\{v_1, \dots , v_n\}$ are *linearly indipendent* if : 
>$$\alpha_1 v_i + \dots + \alpha_n v_n = w \iff \alpha_1= \dots = \alpha_m = 0$$
>

>[!example] 
>$$\alpha_1 \begin{pmatrix} 5 \\ 5 \end{pmatrix} + \alpha_2 \begin{pmatrix} 2 \\ 2 \end{pmatrix} + \alpha_3 \begin{pmatrix} 1 \\ 1 \end{pmatrix} = \begin{pmatrix} 0 \\ 0 \end{pmatrix}$$
>
>Since in order to get $w$ as a result we would need values of $\alpha$ that are not $0$ these are not *lineraly independent*

## Vector Space Combinations

### Affine Combiantion

>[!important] Definition
>Given the *set* of *vectors* : $v_1,\dots,v_n \in \mathbb{R}^n$
>
>We say that the *vector* $s \in \mathbb{R}^n$ is an **affine combination** of *vectors* $\{v_i,\dots,v_m\}$ on $\mathbb{R}$ if :
>$$s = \alpha_1v_1 + \dots + \alpha_m v_m\qquad \text{with} \quad \sum_{i=1}^{m} \alpha_i = 1, \alpha_i \in \mathbb{R}$$

We can give a *geometric rapresentation* considering a set of vectors of size $2$ ( so that the rapresentation is two dimensional ) :  

$s$ are all the *vectors* whos second extreme is on the *line* *between* the two extremes of $v_1$ and $v_2$

>[!example] 
>
>![[Tute1_ManimCE_v0.19.0.png]]

### Cone Combination

>[!important] Definition
>Given the *set* of *vectors* : $v_1,\dots,v_n \in \mathbb{R}^n$
>
>We say that the *vector* $z \in \mathbb{R}^n$ is a **cone combination** of *vectors* $\{v_i,\dots,v_m\}$ on $\mathbb{R}$ if :
>$$s = \alpha_1v_1 + \dots + \alpha_m v_m\qquad \text{with} \quad \alpha_i \ge 0, i = 1, \dots, m$$

This the following *geometric* two dimensional interpretation of the **cone combination** 

$z$ are all the vectors that stay in the *area* between $v_1$ and $v_2$  

>[!example] 
>![[ConeCombiantion_ManimCE_v0.19.0.png]]

### Convex Combination

>[!important] Definition
>Given the *set* of *vectors* : $v_1,\dots,v_n \in \mathbb{R}^n$
>
>We say that the *vector* $y \in \mathbb{R}^n$ is a **convex combination** of *vectors* $\{v_i,\dots,v_m\}$ on $\mathbb{R}$ if :
>$$s = \alpha_1v_1 + \dots + \alpha_m v_m\qquad \text{with} \quad \sum_{i=1}^{m} \alpha_i = 1,\alpha_i \ge 0,\quad \alpha_i \in \mathbb{R} ,i = 1, \dots, m$$

So $y$ is a *convex cobination* if it's both an *affine combination* and a *cone combination*

So geometrically we can rapresent it as the *vector* passing through the two extremes of $v_1$ and $v_2$

>[!example] 
>![[ConvexCombination_ManimCE_v0.19.0.png]]

## Inner Product ( Scalar )


>[!important] Definition
>The **inner product** '$<\bullet, \bullet>$' is defined as a *function* :
>$$f : V^n(\mathbb{R}) \times V^n(\mathbb{R}) \rightarrow \mathbb{R}$$

With the following *properties* : 

1. $<x,x>\ge 0$ with $<x,x> = 0 \iff x = 0$ , $\quad \forall x \in V^n(\mathbb{R})$ 
2. $<x , y +z > = <x,y> + <x,z> \quad \forall x,y,z \in V^n(\mathbb{R})$
3. $<x,y> = <y,x> \quad \forall x, y \in V^n(\mathbb{R})$

>[!important] **Standard** *inner product*
>
>Given *vectors* $x,y \in \mathbb{R}^n$ than by definition :
>$$<x,y> = x^Ty$$

>[!example] 
>With
>$$x = \begin{pmatrix}
>x_1 \\ \vdots \\ x_n
>\end{pmatrix} \quad y = \begin{pmatrix}
>y_1 \\ \vdots \\ y_n
>\end{pmatrix}$$
>Than
>$$<x,y> = x^Ty = \begin{pmatrix}
>x_1, \dots,x_n
>\end{pmatrix}\times \begin{pmatrix}
>y_1 \\ \vdots \\ y_n
>\end{pmatrix} = \sum_{i=1}^n x_i y_i$$
## Vector Norms

>[!important] 
>The **norm** of a *vector* $x \in V^n(\mathbb{R})$ is the *function* from $V^n(\mathbb{R})\rightarrow\mathbb{R}^+ \cup \{0\}$  , indicated with $||\bullet||$ 

With the following *proprieties* :
1. $||x|| \ge 0$ with $||x||=0 \iff x = 0, \quad \forall x \in V^n(\mathbb{R})$ 
2. $||\alpha x|| = |\alpha|\ ||x||, \quad \forall x \in V^n(\mathbb{R}), \forall \alpha \in \mathbb{R}$
3. $||x+y|| \le ||x|| + ||y||, \quad \forall x,y \in V^n(\mathbb{R})$

*Standard* norms : 

+ $||x||_1 = |x_1|+\dots+ |x_n|$
+ $||x||_2 = (x^T x)^{1/2} = [x_1^2 +\dots + x_n^2]^{1/2}$
+ $||x||_\infty = \max_{1\le i \le n}|x_i|$ 

#todo example

## Linear Functions

>[!important] Definition
>
>Given the function $f : \mathbb{R}^n \to \mathbb{R}^m$ we say that $f(x)$ is *linear* in $\mathbb{R}^n$ if it satisfies the following *relations* : 
>1. $f(x+y) = f(x)+f(y), \quad \forall x,y \in \mathbb{R}^n$
>2. $f(\alpha x) = \alpha f(x), \quad \forall x \in \mathbb{R}^n, \forall \alpha \in \mathbb{R}$

>[!example] 
>$f(x,y) = 3xy$
## Affined Functions

>[!important] Definition
>Given the function $g(x)$ , with $g: \mathbb{R}^n \to \mathbb{R}^m$ we say that $g(x)$ is an *affine function* in $\mathbb{R}^n$ if there exists a function $f(x)$ , *linear* in $\mathbb{R}$ , and the vector $\bar{c} \in \mathbb{R}^m$ , such that 
>$$g(x) = f(x)+ \bar{c}$$ 

>[!example] 
>$g(x,y) = 3xy + 5$
