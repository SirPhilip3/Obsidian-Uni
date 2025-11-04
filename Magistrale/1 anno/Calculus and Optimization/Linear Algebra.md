---
publish: true
---
# Change of Basis in $\mathbb{R}^n$ 

## Notation

Lets consider $f: \mathbb{R}^n \to \mathbb{R}^m$ and suppose it's [[Vector Spaces#Linear Functions|Linear]]  ( $y = f(x)$ )

For any $x \in \mathbb{R}^n$ we can write $x = x_1 e_1 + \dots + x_n e_n$ , where $x_i \in \mathbb{R}$ for any $i = 1, \dots , n$ and $e_i$ is the $i-th$  unit vector :
$$
e_i = \begin{pmatrix}
0 \\ \vdots \\ 0 \\ 1 \\ 0 \\ \vdots \\ 0
\end{pmatrix} \in \mathbb{R}^n
$$
Where $1$ is the $i$-th element of the vector

Now we can rewrite $f(x)$ in the following way : 
$$
\begin{align}
f(x) & = f[x_1 e_1 + \dots + x_n e_n] \\
& = x_1f(e_1) + \dots + x_nf(e_n)
\end{align}
$$

We define a new matrix containing the vectors $\{f(e_i)\}$ :
$$
A = \bigg [ f(e_1)\ \vdots\ \dots\ \vdots \ f(e_n)\bigg] \in \mathbb{R}^{n\times m}
$$
We can than also rewrite the *n-tuplas* of the points $x, y \in \mathbb{R}^n$ in the following form : 
$$
X = (x_1\ x_2 \dots \ x_n )^T \quad Y = (y_1\ y_2 \dots \ y_n )^T 
$$
Than : 
$$
y = f(x) \iff Y = AX
$$
## Basis

Vectors that rapresent the *unit* of the [[Vector Spaces]]
## Null Space 

The **null space** of a matrix $A$ can be defined as : 
$$
N[A]\triangleq \{ X \in \mathbb{R}^n | AX  = \emptyset\}
$$
Or the part of the domain that is mapped to the *null vector* ( $\emptyset$ )

>[!note] 
>The **null space** of a *non linear* function is *undefined*
## Range 

The **range** of a matrix $A$ can be defined as :
$$
R[A] \triangleq \{Y \in \mathbb{R}^m | \exists X \in \mathbb{R}^n \text{ st } Y = AX \}
$$
Or the subset of all the *vectors* in $\mathbb{R}^m$ such that they can be obtained with a linear combiantion from $\mathbb{R}^n$ 

>[!note] 
>Since both *null space* and *range* are [[Vector Spaces]] than they can't be $\emptyset$ ( they at least contain the *null vector* )

## Rank Nullity Theorem

Given a matrix $A \in \mathbb{R}^{m \times n}$ than we have that : 
$$
\dim\{R[A]\} + \dim\{N[A]\} = n
$$
>[!note] 
>The *null vector* always has $\dim = 0$  

## Change of Basis

Let's consider the following vector : 
$$
x = x_1e_1+ \dots + x_n e_n = \bar{x}_1 u_1 + \dots + \bar{x}_n u_n
$$
In order to change *basis* from $e_i$ to $u_i$ we need to find a *matrix* $C$ that lets us pass from $X$ to $\bar X$ 

Since $u_i$ can be expressed as a *linear combination* of the vectors $\{e_i\}$ we can write : 

#todo 