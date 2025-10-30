# Change of Basis in $\mathbb{R}^n$ 

Lets consider $f: \mathbb{R}^n \to \mathbb{R}^m$ and suppose it's [[Vector Spaces#Linear Functions|Linear]]  ( $y = f(x)$ )

For any $x \in \mathbb{R}^n$ we can write $x = x_1 e_1 + \dots + x_n e_n$ , where $x_i \in \mathbb{R}$ for any $i = 1, \dots , n$ and $e_i$ is the $i-th$  unit vector :
$$
e_i = \begin{pmatrix}
0 \\ \vdots \\ 0 \\ 1 \\ 0 \\ \vdots \\ 0
\end{pmatrix}
$$
Where $1$ is the $i$-th element of the vector

Now we can rewrite $f(x)$ in the following way : 
$$
\begin{align}
f(x) & = f[x_1 e_1 + \dots + x_n e_n] \\
& = x_1f(e_1) + \dots + x_nf(e_n)
\end{align}
$$

We define a new matrix 