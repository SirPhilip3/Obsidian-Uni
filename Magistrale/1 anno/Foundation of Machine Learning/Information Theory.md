---
publish: true
---
Infromation theory was "invented" by Claude Shannon 

It's a *math theory* that models *communication problems* 
## Model

![[Pasted image 20251017155730.png]]

Where : 
+ **Source** : creator of information in a given alphabet
+ **Transmitter** ( *encoder* ) : translates the information produced by the *source* in an alphabet that the *channel* can understand
+ **Channel** : The mean with which the message is transported 
+ **Noise** : Some random perturbation that the channel is subject to
+ **Reciever** ( *encoder* ) : translates the information coming from the *channel* in an alphabet that the *destination* can understand
+ **Destination** : final destination of the message

>[!note] 
>The *source* and *destination* of the information can be the same ( like for storing things in memory ) or there could be multiple *destinations* ( in a dsitributed setting ) etcc 

>[!important] 
>The model only treats with the *symbolic* ( the way symbols combine ) level of "information"
>

### Measuring Information

>[!important] 
>Given an event $E$ , $I(E)$ rapresents the amount of information provided by $E$ when it actually occurs 

The foundamental fact of *information theory* is that $I(E)$ is a function of the probability of  $E$
$$
I(E) = f(P(E))
$$
Or the more uncertain an event is the more information it produces 

$I(E)$ has the following *properties* :
1. $I(E) \ge 0$ 
	With *equality* happening when $P(E) = 1$ ( when an even is certain this will cointain $0$ information because we already know that it will happend )
2. $\lim_{P(E) \to 0} I(E) = + \infty$
	An extreamly unlikely event will give a huge amount of information 
>[!note] 
>This needs to be a *limit* since calculating the information of an event that *never* happends doesn't make sense

3. $P(E_1)< P(E_2) \implies I(E_1) > I(E_2)$ 

Given these *properties* ( and a 4th not treated here ) the *only* remaining choice is the following function : 
$$
I(E) = \log \frac{1}{P(E)} = -\log P(E)
$$
### Entropy

**Entropy** measures the average amount of *information* produced by the source 

We can model the source as a *discrete random variable* $X$ with *probability distribution* $p(x)$ and *range* $\mathcal{X}$ , than the **entropy** is defined as :
$$
H(X) = -\sum_{x \in \mathcal{X}} p(x) \log p(x)
$$
>[!note] 
>We use the convention that $0\log 0 = 0$ 

>[!note] 
>Knowing that $I(E)=-log P(E)$ we can rewrite *entropy* in the following way :
>$$
>H(X) = \sum_{x \in \mathcal{X}} p(x) I(E)
>$$

>[!note] 
>The base of the *logarithm* amounts to the unit used to send information , for example if we send *bits* at a time it will be $2$

*Properties* : 
1. $H_b(X) = (\log_b a)H_a(X)$
2. $H(X) \ge 0$ 
	With equality $\iff X$  has a $0-1$ distribution ( all probabilies are $0$ except $1$ )
3. $H(X) \leq \log |\mathcal{X}|$
	With equality $\iff X$ has a *uniform distribution*

>[!example] 
>Let $X$ be the toss of an *unbiased* coin then : 
>$$
>H(X) = \frac{1}{2} \log_2 2 + \frac{1}{2} \log_2 2 = 1 
>$$ 
>
>So the average amount of information given by an event that has 2 *equally* likely outcomes is $1$ bit
>

Generalizing to a *biased* coin we have the following equation : 
$$
H(x) = -p\log p - (1-p)\log(1-p)
$$
>[!note] Graph
>![[Pasted image 20251020154409.png]]

#### Joint Entropy

>[!important] Definition
>Let $X$ and $Y$ be two *discrete* random variables , the *joint entropy* between them is defined as : 
>$$
>H(X,Y) = -\sum_x \sum_y p(x,y) \log p(x,y)
>$$ 
>
>Or more generally given $n$ random variables :
>
>$$
>H(X_1, \dots,X_n) = -\sum_{x_1} \dots \sum_{x_n} p(x_1,\dots,x_n) \log p(x_1,\dots,x_n)
>$$

#### Conditional Entropy

>[!important] Definition
>Let $X$ and $Y$ be two *discrete* random variables , the *conditional entropy* of $X$ give the event $Y = y$ is the *entropy* of the conditional distribution $p(x | Y =y)$ :
>$$
>H(X | Y = y) = -\sum_x p(x|y)\log p(x |y)
>$$

>[!info] 
>If we average the entropy for all possible $y$ than we obtain the *conditional entropy* of $X$ given $Y$ :
>$$
>H(X|Y) = -\sum_x \sum_y p(x|y)\log p(x|y)
>$$

>[!example] 
>Lets have $X$ with the following *range* : $\mathcal{X} = \{1,2,\dots,6\}$ and $Y$ with the following *range* : $\mathcal{Y} = \{even,odd\}$
>
>Now $H(X|Y) \le H(X)$ this is true since if we know that a number is *even* or *odd* ( $Y$ ) we can reduce the uncertanty of $X$ by $1/2$ 
>
>$H(Y|X) = 0$ since once we know the precise number i also know if it's *even* or *odd* 

##### The Chain Rule

Let $X$ and $Y$ be two *discrete* random variables , then : 
$$
\begin{align}
H(X,Y) & = H(X) +H(Y|X) \\
& = H(Y) + H(X|Y)
\end{align}
$$
More generally given $n$ random variables :
$$
H(X_1,\dots,X_n) = H(X_1) + H(X_2|X_1) + \dots + H(X_n|X_1,\dots,X_{n-1})
$$
### Kullback-Leibler Divergence

Given $\bar p = \begin{pmatrix} p_1 \\ \dots \\ p_n \end{pmatrix}$ a *probability vector* such that : 
1. $p_i \ge 0, \quad \forall i$
2. $\sum^{n}_{i=1} p_i =1$ 

Or $\bar p \in \mathbb{R}_{\{0,1\} }^n$ ( also known as *standard simplex* $\triangle = \bigg\{ x \in \mathbb{R}^n : \sum_{i=1}^n x_i = 1 , x_i > 0 \bigg\}$ )

Than *Kullback-Leibler (KL) divergence* between $\bar p$ and $\bar q$ $\in \triangle$ is defined as : 
$$
D(\bar p || \bar{q}) = \sum_{i=1}^n p_i \log \frac{p_i}{q_i}
$$

>[!note] 
>$D(p||q) \ge 0$ with equality $\iff p=q$ 
>
>Also the *triangular inequality* **does not hold**

>[!note] 
>This mesure of *distance* is different from the normal *euclideian distance* : 
>$$
>d(\bar{p}||\bar{q}) = ||\bar{p} - \bar{q}||
>$$

### Mutual Information

>[!summary] 
>It quantifies the *amount* of information obtained about one random variable by observing the other random variable

Let $X$ and $Y$ be two *discrete random variables* , the **mutual information** between $X$ and $Y$ is : 
$$
I(X;Y) = \sum_x \sum_y p(x,y) \log \frac{p(x,y)}{p(x)p(y)}
$$
Or reformulated using [Kullback-Leibler Divergence] :
$$
I(X;Y) = D\big(p(x,y) || p(x)p(y)\big)
$$

**Propieties** : 

1.  $\begin{align}I(X;Y) & = H(X) - H(X|Y) \\ & = H(Y) - H(Y | X)\end{align}$

Or in other words $I(X;Y)$ measures the *amount* of information that *travels* on a *channel*

2. $I(X;Y) = I(Y;X)$
3. $I(X;Y) \ge 0$ , with *equality* $\iff X$ and $Y$ are *independent*
4. $H(X|Y) \leq H(X)$ , with *equality* $\iff X$ and $Y$ are *independent*
5. $I(X;Y) = H(X) + H(Y) - H(X,Y)$
6. $I(X;X) = H(X)$

![[Entropy-mutual-information-relative-entropy-relation-diagram.svg]]
### Sorce Coding ( Data Compression )

A *code* $C$ for a random variable $X$ with range $\mathcal{X}$ and probability distribution $p(x)$ is a *mapping* : 
$$
C : \mathcal{X} \to \mathscr{D}^*
$$
Where $\mathscr{D}^*$ is the set of *strings* of symbols from a $D$-ary alphabet :
$$
\mathscr{D} = \{0,1,\dots,D-1\}
$$

$C(x)$ is the *codeword* associated to $x$ and $l(x)$ is it's *lenght*