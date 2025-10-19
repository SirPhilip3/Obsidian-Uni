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
