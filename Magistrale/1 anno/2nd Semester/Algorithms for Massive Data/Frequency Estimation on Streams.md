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

# Sampling

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

## Precision

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
>
>The sample size for a stream of lenght $m=10^{12}$ if we want $\epsilon = 0.01$ and $\delta = 0.0001$ is :
>$$
>q = \lceil 2 \cdot 0.01^{-2}\ln(2/0.0001) \rceil \approx 2 \cdot 10^5
>$$
>
>The addittive error is $\epsilon \cdot m = 10^{10}$ which is *huge*
>
>The sketch size is proportional to $\epsilon^{-2}$ so we must choose $\epsilon \ge 1/\sqrt{m}$ otherwise $\epsilon^{-2}>m$ and the sketch is as large as the stream
>
>This implies that the *addittive error* *cannot* be *smaller* than $\epsilon \cdot m \ge \sqrt{ m }$ 

# Count-Min sketch

**Count-Min** has the following characteristics :
+ $O(\epsilon^{-1} \log(1/\delta))$ *space*
+ *One-sided error* : always true that $\tilde{f}_{y} \ge f_{y}$

*Algorithm* :
+ Initialize a $t \times s$ matrix of integers *CM*
+ Each row is associated with a i.i.d. [[Hashing#Universal Hashing|Universal hash]] function
+ All entries are initialized to $0$

>[!example] 
>
>![[Init_countmin.excalidraw.png]]
>%%[[Init_countmin.excalidraw.md|🖋 Edit in Excalidraw]]%%

### Insert

```pseudo
	\begin{algorithm}
	\caption{Insert(x):}
	\begin{algorithmic}
	\ForAll{$i=1,\dots,t$}
		\State $CM[i,h_i(x)]\leftarrow CM[i,h_i(x)]+1$
    \EndFor
	\end{algorithmic}
	\end{algorithm}
```
>[!note] 
>This is a [[Counting Bloom Filters (CBF)|Counting Bloom Filter]] without the *overflow* check

>[!example] 
>Processing the stream : $1,3,4,3,3,1,5,1,5,8,8,8,1,2$ we get :
>
>![[Full_CM.excalidraw.png]]
%%[[Full_CM.excalidraw.md|🖋 Edit in Excalidraw]]%%

### Frequency estimation

```pseudo
	\begin{algorithm}
	\caption{estimate_frequency(x):}
	\begin{algorithmic}
	\Return $\min\{CM[i,h_i(x)]: i \in [t]\}$
	\end{algorithmic}
	\end{algorithm}
```
Returning the minimum is a good estimate since if :
+ no element $y \neq x$ is such that $h_{1}(y)=h_{1}(x)$ then $f_{x}=CM[h_{1}(x)]$ ( *no collisions* )
+ other elements *collide* with $x$ then $CM[h_{1}(x)] > f_{x}$ 

Then if we take the *minimum* between the hash function we take the fow with lowest collision and then closest estimate to $f_{x}$

>[!note] 
>This implies a *one-sided* error since the estimate can only be $\ge f_{x}$

---
Let's calculate $E[CM[i,h_{i}(x)]]$ 

>[!note] 
>Let $h_{i}(x)=h_{i}(y)$ be the *bernullial random variable* indicating whether the two hashes collide

Then :
$$
\begin{align}
E[CM[i,h_{i}(x)]] & = E\left[ f_{x}+ \sum_{y\neq x} f_{y} \cdot (h_{i}(x)=h_{i}(y)) \right]  \\
& = f_{x} + \sum_{y\neq x} f_{y} \cdot E[(h_{i}(x)=h_{i}(y))]
\end{align}
$$
Now remembering that $h$ *universal* 
$$
\begin{align}
& \le f_{x} + \sum_{y \neq x} f_{y} \cdot \frac{1}{s} \\
& \le f_{x} + \frac{1}{s} \sum_{y \neq x} f_{y}  \\
& \le f_{x} + \frac{m}{s}
\end{align}
$$
>[!note] 
>$s$ is the number of *columns* of $CM$ 
>$m$ is the size of the stream 

We than have that the *expected precision* is bounded in the following way :
$$
f_{x} \le E[CM[i,h_{i}(x)]] \le f_{x} + \frac{m}{s}
$$
How do we control $CM[i,h_{i}(x)]$ ? 

We can notice that $E[CM[i,h_{i}(x)]-f_{x}]\le m/s$ and by applying [[Concentration Bounds#Markov ( linear )|Markov]] we get :
$$
\mathbb{P}(CM[i,h_{i}(x)]-f_{x} \ge \textcolor{orange}{2}\cdot m/s \le 1/\textcolor{orange}{2})
$$
So with *probability* $\geq 1/2$ :
$$
CM[i,h_{i}(x)]\le f_{x} + 2m/s
$$
>[!note] 
>Thanks to [[Concentration Bounds#Markov ( linear )|Markov]] we turned a bound on the expectation to a bound on the random variable 

>[!important] 
>This happends *independently on each row* 
>
>In fact the probability that *all* $t$ *rows* exceed error $2 \cdot m/s$  is $\leq 2^{-t}$
>
>Then with probability $\geq 1-2^{-t}$ *at least one* row $i$ achieves $CM[i,h_{i}(x)]\le f_{x}+2m/s$

---
Finally since $\tilde{f}_{x} = \min\{CM[i,h_{i}(x)] : i \in [t]\}$ is the *row* with the *smallest error* , hence $\tilde{f}_{x}$ **exceeds error** $2 \cdot m/s$ with *probability* at most $2^{-t}$  

Setting :
+ $2\cdot m/s = \epsilon \cdot m$
+ $2^{-t} = \delta$ 

And solving for $s,t$ we get :
+ $s=2/\epsilon$
+ $t = \log(1/\delta)$

We obtain the final result :
>[!important] Theorem
>Choose any desired *error rate* $\epsilon > 0$ and *failure probability* $\delta >0$ 
>
>The *CM* sketch uses $2\epsilon^{-1} \log(1/\delta)$ *words of space* and, for any $x \in [n]$ returns an *estimate* $\tilde{f}_{x}$ such that :
>+ $\tilde{f}_{x} \ge f_{x}$
>+ $\mathbb{P}(\tilde{f}_{x}\leq f_{x} + \epsilon \cdot m) \ge 1-\delta$
>
>Frequency estimation *queries* are supported in $O(\log(1/\delta))$ *time*
>
>The $CM$ sketch can be updates in $O(\log(1/\delta))$ *time*

>[!important] 
>If we allow $CM$ to use $O(m/k)$ *space* then the error is $k$ , for any $k \ge 1$

## Count-Min sketch with conservative updates (CMS-CU)

This *optimization* improves the error rate

When inserting $x$, *increment* *only* the *smallest* *cell* $CM[i][h_{i}(x)]$ 

>[!warning] 
>This introduces dependencies between *rows* , making it hard to formalize

## Count-Min sketch for range queries 

#todo end of pdf exercise 2

# Misra-Gries sketch

We *dynamically* keep a **sample** ( *MG* ) of the stream's elements 

Where *MG* is a *hash table* associating an estimate $MG[x]=\tilde{f}_{x}$ to every $x \in MG$
**Invariant** : $|MG| < s$

>[!note] 
>Initially $MG$ will be empty, also if $x \not\in MG$ then we will consider $\tilde{f}_{x}=0$

### Insert

```pseudo
	\begin{algorithm}
	\caption{insert(x)}
	\begin{algorithmic}
	\If{$(x \in MS)$}
    \Comment{increment $\tilde{f}_x$ by $1$}
		\State $MS[x] \leftarrow MS[x] + 1$
    \Else
	    \State $MS \leftarrow MS \cup \{(x,1)\}$
    \EndIf
    \If{$|MS|=s$}
    \Comment{If the sample is too larger decrement all $\tilde{f}_y$ by $1$}
	    \ForAll{$y \in MS$}
		    \State $MS[y]\leftarrow MS[y]-1$
        \EndFor
    \EndIf
    \ForAll{$y \in MS$ such that $MS[y]=0$}
	    \State $MS \leftarrow MS \backslash \{(y,0)\} $
    \EndFor
	\end{algorithmic}
	\end{algorithm}
```

>[!example] 
>
>![[MG_example.excalidraw.png]]
>%%[[MG_example.excalidraw.md|🖋 Edit in Excalidraw]]%%
>
>estimate_frequency(17) = 2
>estimate_frequency(5) = 1
>estimate_frequency(81) = 0
>estimate_frequency(42) = 0

Since we *increment* $CM[x]$ only when we see an occurrence of $x$ then for sure :
$$
\tilde{f}_{y} \le f_{y}
$$
Also since we *decrement* $s$ values $\tilde{f}_{y}$ each time $|MS|=s$, also 
