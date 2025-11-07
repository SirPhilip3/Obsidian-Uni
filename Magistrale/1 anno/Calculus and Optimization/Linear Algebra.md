---
publish: true
---
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

## Linear Functions notation 

>[!important] Definition
>Given the linear function $f : \mathbb{R}^n \to \mathbb{R}^m$ and the matrix $A$ associated with $f(x)$ we say :
>+ $f(x)$ is **injective** if $rk(A)=n$ 
>	$N[A] = \{0\}$ and given a value $\gamma$ there exists *only* *one* vector $\bar x$ such that $f(\bar x) = \gamma$ 
>+ $f(x)$ is **onto** if $rk(A) = m$


>[!important] Homomorphism
>$f : \mathbb{R}^n \to \mathbb{R}^m$  if $n \neq m$ than we call $f$ an **homomorphism**

>[!important] Endomorphism
>$f : \mathbb{R}^n \to \mathbb{R}^m$ if $m=n$ than $f(x)$ is an *endomorphism* between [[Vector Spaces|Vector space]] $V^n(K)$ and $W^n(K)$


>[!important] Automorphism
>$f : \mathbb{R}^n \to \mathbb{R}^m$ if $m=n$ and $f(x)$ is both **injective** and **onto** than $f(x)$ is an *automorphism* between [[Vector Spaces|Vector space]] $V^n(K)$ and itself
# Change of Basis in $\mathbb{R}^n$

Let's consider the following vector : 
$$
x = x_1e_1+ \dots + x_n e_n = \bar{x}_1 u_1 + \dots + \bar{x}_n u_n
$$
In order to change *basis* from $e_i$ to $u_i$ we need to find a *matrix* $C$ that lets us pass from $X$ to $\bar X$ 

Since $u_i$ can be expressed as a *linear combination* of the vectors $\{e_i\}$ we can write : 
$$
u_i = c_{1i}e_1 + \dots+ x_{ni}e_n, \quad i=1,\dots,n
$$
We than can substitute this in definition of $x$ with *base* $u$ : 
$$
\begin{align}
x & = \bar{x}_1 u_1 + \dots + \bar{x}_n u_n\\
& = \bar{x}_1(c_{11}e_1 + \dots+ x_{n1}e_n) + \dots + \bar{x}_n(c_{1n}e_1 + \dots+ x_{nn}e_n) \\
& = (e_1\ \vdots\ \dots\ \vdots\ e_n) \begin{bmatrix}
c_{11} & \dots & c_{1n} \\
\vdots & \ddots & \vdots \\
c_{n1} & \dots & c_{nn}
\end{bmatrix}
\begin{pmatrix}
\bar{x}_1 \\ \vdots \\ \bar{x_n}
\end{pmatrix} \\
& = (e_1\ \vdots\ \dots\ \vdots\ e_n) C\bar{X}
\end{align}  
$$

>[!important] 
>Than we can **change basis** in the following way : 
>$$
>\bar{X} = C^{-1}X
>$$

>[!note] 
>The matrix $C$ must be *nonsingular* ( invertible )

>[!note] 
>The *change of basis matrix* is build by writing for each column the coordinates of the new *basis vector* expressed in the old *basis* 

>[!note] 
>If $u\equiv e$ than $C$ is the *identity matrix*  

# Change of basis in $\mathbb{R}^n$ and $\mathbb{R}^m$

Now having a function $f : \mathbb{R}^n \to \mathbb{R}^m$ , let's consider the change of basis for both $y$ ( $\mathbb{R}^m$ ) and $x$ ( $\mathbb{R}^n$ ) than we can write : 
$$
X = C \bar{X}, \quad C \in \mathbb{R}^{n\times n} \text{ nonsingular}
$$
and 
$$
Y = D \bar{Y} , \quad D \in \mathbb{R}^{m\times m} \text{ nonsingular} 
$$
>[!note] 
>If $m \equiv n$ than $D \equiv C$ 

Remebering that $Y = AX$ we can rewrite it changin bases in the following way : 
$$
\begin{align}
D \bar{Y} & = A C \bar{X} \\
\bar{Y} & = D^{-1} A C \bar{X} 
\end{align}
$$
>[!important] 
>For *eigenparis* we aim at selecting $D$ and $C$ such that we can simplify $A$

# Eigenpairs

Let the *linear* function $f : V^n(K) \to V^n(K)$ be an **endomorphism** then if : 
$$
f(v) = \lambda v, \quad \lambda\in K, v \neq 0_V
$$
>[!note] For $\mathbb{R}^n$
>$\lambda \in \mathbb{R}$ and $v \in \mathbb{R}^n - \{\emptyset\}$ 

Than we call $(\lambda, v)$ an **eignepair** , where $\lambda$ is an *eigenvalue* and $v$ is an *eigenvector*

Let's now consider the *matrix* $A$ associated with the function $f(x)$ than we can write : 
$$
Av = \lambda v
$$
>[!example] 
>#todo

## Secular (Characteristic) Equation 

$$
\det(A) = 0
$$
## Special Cases

For *diagonal* , *upper* and *lower* triangular matrices the **eigenvalues** are the values present in the *diagonal* 

## Matrix Rapresentation through Eigenpairs

We know that $Av = \lambda v$ where $(\lambda,v)$ *eigenpairs* 

Than we can write the following : 
$$
A\cdot(v_1\ \vdots\ \dots\ \vdots \ v_n) =(v_1\ \vdots\ \dots\ \vdots \ v_n) \begin{pmatrix} \lambda_1 & & \\ &  \ddots & \\ & &  \lambda_n \end{pmatrix}
$$
Than the matrix $A$ can be described in the following way 

$$
A = (v_1\ \vdots\ \dots\ \vdots \ v_n)\begin{pmatrix} \lambda_1 & & \\ &  \ddots & \\ & &  \lambda_n \end{pmatrix} (v_1\ \vdots\ \dots\ \vdots \ v_n)^{-1}
$$

>[!note] Lemma
>We can easly see that $A^n$ can be written in the following way :
>$$
>\begin{align}
>A^2 = A \cdot A & = \Bigg[V \begin{pmatrix} \lambda_1 & & \\ &  \ddots & \\ & &  \lambda_n \end{pmatrix} \cancel{V^{-1}}\Bigg] \cdot \Bigg[\cancel{V} \begin{pmatrix} \lambda_1 & & \\ &  \ddots & \\ & &  \lambda_n \end{pmatrix} V^{-1}\Bigg] \\ & = \Bigg[V \begin{pmatrix} \lambda_1^2 & & \\ &  \ddots & \\ & &  \lambda_n^2 \end{pmatrix} V^{-1}\Bigg]
>\end{align}
>$$

