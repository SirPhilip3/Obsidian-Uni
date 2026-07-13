>[!important] Goal
>In general the goal will be to read a stream of *integers* $x_{1}, \dots, x_{m} \in [n]$ and create *on-the-fly* ( *online* ) a **data sketch** of the stream

We will typically use space proportional to :
$$
polylog(n+m) = O((\log(n+m))^{O(1)})
$$
This will allows us to compute statistics on the stream 

## Definitions

A **data sketch** of some data $x$ is the output $f(x)$ of a function $f()$ with the following properties :

1. *Small size* : $bitsize(f(x)) \ll bitsize(x)$
2. $f(x)$ can be used to *estimate* some *properties* of $x$ , for example ( if $x$ is a stream ) :
	+ number of distinct elements in $x$
	+ frequency of any $y \in x$
	+ Some function of the frequencies of the elements in $x$

>[!note] 
>*Often* condition $1$ makes it impossible to compute $2$ exactly. 
>
>In those cases we will compute an $\epsilon$-*approximation* with *porbability* $\ge 1 - \delta$ 
>
>The space of the *sketch* will depend on $\epsilon$, $\delta$ and the size of $x$

3. 