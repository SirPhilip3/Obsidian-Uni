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
>
>
>

