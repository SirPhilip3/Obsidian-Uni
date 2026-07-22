---
publish: true
---
>[!important] Problem Definition
>Given a stream :
>$$
>x_{1},\dots,x_{m}
>$$
>
>Where $x_{i} \in [n]$, build a *data sketch* that allows us to estimate for any $y \in [n]$ :
>$$
>f_{y} = |{i : x_{i} = y}|
>$$
>
>Or the **frequency** ( number of occurrences ) of $y$ in the stream 

## Sampling

We can *randomly sample* a subset of the stream and we return the frequency in the sample **scaled** opportunely

>[!note] 
>This works because the *expected* *frequency* in the sample is the same as in the original stream

**Algorithm** :
1. Sample uniformlyat random $q$ elements $x_{1}',\dots,x_{q}'$ from the stream

>[!note] 
>+ $q$ will be determined by the *error* and *sucess probability* that we want 
>+ The sample can be extracted *on-the-fly* from the stream ( resevoir sampling with replacement )

2. Return :
$$
\tilde{f}_{y}= \frac{m}{q} \cdot |\{i : x_{i}'=y\}|
$$
>[!example] 
>$$
>stream = 4,5,2,4,1,3,4,5,1,5,1,1,4,3
>$$
>
>Uniform sample of size $q=5 : \quad 2,4,1,1,3$
>
>$f_{4}=4$ 
>$\tilde{f}_{4}=\frac{14}{5}\cdot {1} = 2.8$

### Precision

We denote as $(x=y)$ the *binary indicator* taking value $1$ if and only if $x=y$ 

Tehn we have that :
$$
E[(x_{i}'=y)] = f_{y}/m
$$
Also we have that :
$$
E\Bigg[ \sum_{i=1}^q (x_{i}' = y) \Bigg] = (q/m) \cdot f_{y}
$$
Our estimator can be rewritten as :
$$
\tilde{f}_{y} = \frac{m}{q} \sum_{i=i}^q (x_{i}'=y)
$$
Than we get that :
$$
E[\tilde{f}_{y}] = \frac{m}{q} \cdot \frac{q}{m} f_{y} = f_{y}
$$
So the estimator is **unbiased**

---
Then we can write also the following :
$$
\mathbb{P}(|\tilde{f}_{y}-f_{y}| \ge \epsilon \cdot m)
$$
Now multiplying both sides by $\frac{q}{m}$ we get :
$$
\mathbb{P}\Bigg(\Bigg|\sum_{j=1}^q (x_{j}' = y) - E \Big[\sum_{j=1}^q (x_{j}'=y) \Big]  \Bigg| \ge \epsilon \cdot q \Bigg)
$$
>[!note] 
>The two summation since they are i.i.d. *Bernullian* random variables we can use [[Concentration Bounds#Chernoff-Hoeffding ( exponential )|Chernoff-Hoeffding]] 

$$
\mathbb{P}\Bigg(\Bigg|\sum_{j=1}^q (x_{j}' = y) - E \Big[\sum_{j=1}^q (x_{j}'=y) \Big]  \Bigg| \ge \epsilon \cdot q \Bigg) \leq 2\epsilon^{-(e\cdot q)^2/2q} = 2\epsilon^{-e^2\cdot q/2}
$$
Now setting :
$$
2e^{-e^2\cdot q/2} = \delta
$$
Solving for $q$ we get :
$$
q = \left\lceil  2\epsilon^{-2}\ln\left( \frac{2}{\delta} \right)  \right\rceil \in \Theta\left( \epsilon^{-2}\log\left( \frac{1}{\delta} \right) \right)
$$
>[!important] Theorem
>Choose $\epsilon>0$ *error* and $\delta >0$ *failure probability*
>
>By sampling $q= \lceil 2 \epsilon^{-2}\ln(2/\delta) \rceil \in \Theta(\epsilon^{-2}\log(1/\delta))$ stream elements *uniformly at random* we can approximate any *frequency* $f_{y}$ up to *addittive error* $\epsilon \cdot m$ and *failure probability* $\delta$

In other words for any $y \in [1,n]$ our estimator $\tilde{f}_{y}$ satisfies :
$$
\mathbb{P}(|\tilde{f}_{y}-f_{y}|\ge \epsilon \cdot m) \le \delta
$$
>[!important] 
>The error is *additive* $f_{y}\pm \epsilon \cdot m$ not multiplicative 

>[!warning] 
>The estimate will be *bad* if $f_{y}$ is very *small* compared to $m$

>[!example] 
>#todo

## Count-Min sketch