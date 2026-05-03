---
publish: true
---
# Introduction 

+ Designing *randomized algorihtms* to **estimate** statistics on data stream 
+ The output $X$ of a *randomized algorithm* is a **Random Variable** ( $RV$ )
+ Usually $E[X]$ is equal to the *value* we want to *estimate*

>[!example] 
>
>Estimate the *frequency* $f_x$ of $x$ in a stream $x_1,\dots,x_m$
>
>**Algorithm** : 
>+ For every $x_i$ append $x_i$ to a list $S$ with probability $1/1000$
>
>**Ouput** :
>+ $\tilde{f}_x = 1000 \cdot$ number of occurrences of $x$ in $S$. ( $E[\tilde{f}_x] = f_x$ ) 
>
>**Space** : 
>+ Uses $m/1000$ words on expectation space 
>
>
# Concentration Bounds

>[!note] 
>In general if we run a randomized algorithm only *once* than it's output $X \neq E[X]$

The *goal* of concentration bounds is to *bound* the probability that $|X -E[X]|$ exceeds some desired threshold 

This allows us to prove the following

>[!important] 
>For any $\delta>0$ and $\epsilon>0$ of you choice, the algorithm uses space increasing in $\epsilon^{-1}$ and $\delta^{-1}$ and outputs a value $X$ that is a $\epsilon-$approximation of $E[X]$ with probability at least $1-\delta$

Where : 
+ $\delta$ is the *failure probability*
+ $\epsilon$ is the *error rate*
+ $\epsilon$-approximation if $|X-E[X]|\leq \epsilon \cdot E[X]$
## Markov ( linear )

>[!important] Assumption
>$X\geq 0$
>
>works only on non-negative *random variables*

Let $X\geq 0$ be a non-negative *RV*. For any $a\geq 0$ it holds that : 
$$
\mathbb{P}(X \geq a) \leq E[X]/a
$$
Or *equivalently* :
$$
\mathbb{P}(X \geq a \cdot E[x]) \leq 1/a
$$

**Proof** :
$$
\begin{align}
E[X] & = \sum_{x \geq 0} x \cdot \mathbb{P}(X=x) \\
& \geq  \sum_{x \geq a} a \cdot \mathbb{P}(X=x) \\
& = a \cdot \sum_{x \geq a} \mathbb{P}(X=x) \\
& = a \cdot \mathbb{P}(X \geq a)
\end{align}
$$
>[!example] 
>The *probability* that $X$ is *twice* its expected value is at most $1/2$

### Example 1

Throw a $6$ faces *dice*. Let $X=$ number on the face $\geq 0$

The *expected* value is : $E[X]=\sum^{6}_{i=1} \frac{1}{6}i = 21/6 = 3.5$

Applying **Markov** we obtain that :
$$
\mathbb{P}(X \geq 6) \leq E[X]/6 \approx 0.583
$$
But this can be easily computed as $1/6\approx 0.1667$

### Example 2 

Flip $100$ *coins*. 
+ Let $X_i=0$ if $i$-th coin is *tail* 
+ $X_i=1$ if *head*

Let $X=\sum_{i=1}^{100} X_i$ be the number of *heads*

Then $E[X]=\sum^{100}_{i=1}E[X_i] =\sum^{100}_{i=1}0.5 = 50$

Applying **Markov** we get :
$$
\mathbb{P}(X \geq 80) \leq E[X]/80 = 50/80 = 0.625
$$

## Chebyshev ( quadratic )

>[!important] Assumption 
>We know $Var[X]$

For any $k\geq 0$ it holds :
$$
\mathbb{P}(|X -E[X]|\geq k) \leq Var[X] / k^2
$$
**Proof** :
$$
\begin{align}
&\ \mathbb{P}(|X -E[X]| \geq k) \\
= &\ \mathbb{P}((X -E[X])^2 \geq k^2) 
\end{align}
$$
By than applying [[Concentration Bounds#Markov ( linear )|Markov]] on the non-negative *random variable* $(X-E[x])^2$ :
$$
\begin{align}
\leq & \ \mathbb{E}[(X - E[x])^2]/k^2 \\
= & \ Var[X]/k^2
\end{align}
$$
### Example


### Boosted Chebyshev

## Chernoff-Hoeffding ( exponential )

## Mean+Median trick