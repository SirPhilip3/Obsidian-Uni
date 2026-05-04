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

Flip $100$ *coins*. 
+ Let $X_i=0$ if $i$-th coin is *tail* 
+ $X_i=1$ if *head*

Let $X=\sum_{i=1}^{100} X_i$ be the number of *heads*

Then $E[X]=50$

But we need to know the *variance* , and since each $X_i$ is *fully indipendent* from each other we will have : 
$$
Var[X]=\sum_{i=1}^{100} Var[X_i]
$$
And since every $X_i$ is a [[Statistica e Probabilità#Distribuzione di Bernuolli|Bernulli]] *distribution* that has $Var[X]=p(1-p)$ , where $p$ is the probability of success :
$$
=\sum_{i=1}^{100} Var[X_i] = \sum_{i=1}^{100} 0.5(1-0.5) = 25
$$

Than applying **Chebyshev** what is $\mathbb{P}(X \geq 80)$

Since *chebyshev* calculates the probability that a given random variable deviates from the the mean by at least $k$ we will have that :
$$
\mathbb{P}(|X - 50| \geq 30) = \mathbb{P}(X \ge 80) + \mathbb{P}(X \le 20)
$$
>[!note] 
>Since we are intrested only in the bound for $\mathbb{P}(X \ge 80)$ we must multiply $\mathbb{P}(|X - 50| \geq 30)$ by $0.5$ 

$$
\begin{align}
\frac{1}{2} \cdot \mathbb{P}(|X-50|\ge 30) & \le \frac{1}{2} \cdot \frac{Var[X]}{30^2} \\
& \le \frac{1}{2} \cdot \frac{25}{30^2} = 0.01389
\end{align}
$$
### Boosted Chebyshev

Instead of sampling $X$ only *1* time we sample *multiple times* and take the **average**

Fix $k > 0$ and an integer $s\ge 1$

Let $X_1,\dots,X_s$ *pairwise independent* random variables distributed as $X$ 

Let $\hat{X} = \frac{1}{s}\sum_{i=1}^s X_i$, then : 
$$
\mathbb{P}(|\hat{X}-E[X]|\ge k) \le \frac{Var[X]}{s \cdot k^2}
$$
#### Example

Flip $100$ coins for *10* times and take the **average** number of heads you see in the *10* rounds

The $\mathbb{P}(X \ge 80)$ will be $1/10$ the previous *Chebyshev* probability :
$$
\approx 0.01389 / 10 = 0.001389
$$
## Chernoff-Hoeffding ( exponential )

>[!important] Assumption
>My random variable $Y = \sum_{i=1}^n Y_i$ is the sum of $n$ *independent and identically distributed* [[Statistica e Probabilità#Distribuzione di Bernuolli|Bernullian]] random variables $Y_i$

Then for any $t \ge 0$ :
+ $\mathbb{P}(Y \ge E[Y] +t) \le e^{\frac{-t^2}{2n}}$ , right sided
+ $\mathbb{P}(Y \le E[Y]-t) \le e^{\frac{-t^2}{2n}}$ , left sided
+ $\mathbb{P}(|Y-E[Y]|\ge t) \le 2e^{\frac{-t^2}{2n}}$ , double sided

### Example

Flip $100$ *coins*. 
+ Let $X_i=0$ if $i$-th coin is *tail* 
+ $X_i=1$ if *head*

Let $X=\sum_{i=1}^{100} X_i$ be the number of *heads*

Then $E[X]=50$

Applying *Chernoff-Hoeffding* ( right side ) : 
$$
\mathbb{P}(X \ge 80) = \mathbb{P}(X \ge E[X] + 30) \le e^{\frac{-30^2}{2 \cdot 100}} \approx 0.0111
$$

## Mean+Median trick

Our goal is to estimate $E[X]$ 

>[!important] Assumption
>$$
>Var[X] = O(E[X]^2)
>$$
>
>Or the variance must not be too large

Choose prameters : 
+ $\epsilon > 0$ , *error rate*
+ $\delta > 0$ , *failure probability*

Let then : 
+ $t = \Theta(\log(1/\delta))$
+ $s = \Theta(\epsilon^{-2})$

Draw $st = \Theta(\epsilon^{-2} \log(1/\delta))$ *iid* realizations $X_{i,j}$ of $X$ , building the following *matrix* : 

$$
\begin{matrix}
X_{1,1} & X_{1,2} & \dots & X_{1,t} \\
X_{2,1} & \dots & \dots & \dots\\ 
\dots & \dots & \dots & \dots\\
X_{s,1} & \dots & \dots & X_{s,t}
\end{matrix}
$$

Let :
+ $\hat{X}_j = \frac{1}{s}\sum_{i,j}$ be the **mean** of the $j-$th column  
+ $Y = median(\hat{X}_1, \dots, \hat{X}_t)$ be the **median** of those means 

Then :
$$
\mathbb{P}(|Y-E[X]| \ge \epsilon \cdot E[X]) \le \delta
$$
>[!note] 
>We can have *arbitrary* **precision** $\epsilon$ and *failure* **probability** $\delta$ , the price to pay is to repeat $st$ *times* the randomized algorithm

### Mean trick

Let $c$ be the *smallest constant* such that $Var[X] \le c \cdot E[X]^2$ 

Begin by choosing enough rows such that the following holds :
$$
\mathbb{P}(|\hat{X}_j - E[X]| \ge \epsilon \cdot E[X]) \le 1/3
$$
The probability that the *mean* of any column **exceeds** *relative error* $\epsilon$ with constant probability $1/3$ 

We can use [[Concentration Bounds#Boosted Chebyshev|Chebyshev]] as *concentration bound* with $k = \epsilon \cdot E[X]$ :
$$
\mathbb{P}(|\hat{X}_j -E[X]| \ge k) \le \frac{Var[X]}{s \cdot k^2}
$$
$$
\le \frac{c \cdot E[X]^2}{s \cdot (\epsilon \cdot E[X])^2} = c s^{-1} \epsilon^{-2}
$$
Since we want to know how many *sampling* we need to do we solve for $s$

$$
\begin{align}
cs^{-1}\epsilon^{-2} & = 1/3 \\
3 \cdot cs^{-1}\epsilon^{-2}& = \frac{1}{\cancel{3}} \cdot \cancel{3} \\
\cancel{s} \cdot3 \cdot \frac{c}{\cancel{s} \cdot \epsilon^2} & = 1 \cdot s \\
s & = 3 c\epsilon^{-2} = \Theta(\epsilon^{-2})
\end{align}
$$
### Median trick

So if out matrix has $s = \Theta(\epsilon^{-2})$ *rows* we know that **mean** $\hat{X}_j$ of each column exceeds the *relative error* $\epsilon$ with *probability* $1/3$ 

Now we want to show that the **mendian** of the $\hat{X}_j$ exceeds *relative error* $\epsilon$ with probability at most $\delta$ if we have $t = \Theta(\log(1/\delta))$ *columns*

