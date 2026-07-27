---
publish: true
---
# Count Sketch

>[!note] Objective 
>Estimate individual frequencies

Let $h:[n]\to \{-1,+1\}$ be a [[Hashing#k-wise independent Hasing|pairwise independent hash]] 

Then : 
$$
E[h(x)] = (1/2) \cdot (1) + (1/2) \cdot (-1)=0
$$
Also :
$$
E[h(x)\cdot h(y)] = \cases{E[h(x)^2] = E[1]=1 & \text{if $x=y$} \\ E[h(x)] \cdot E[h(y)]= 0 & \text{if $x \neq y$}} 
$$
>[!note] 
>The second result is derived from the fact that $h(x)$ and $h(y)$ are *independent* when $x \neq y$ 

```pseudo
	\begin{algorithm}
	\caption{initialization()}
	\begin{algorithmic}
	\State $h \leftarrow$ four-wise independent function from $[n]$ to $\{-1,+1\}$
	\State $z \leftarrow 0$
	\end{algorithmic}
	\end{algorithm}
	
	\begin{algorithm}
	\caption{new_stream_element(x)}
	\begin{algorithmic}
	\State $z \leftarrow z + h(x)$
    \end{algorithmic}
    \end{algorithm}
    
    \begin{algorithm}
    \caption{estimate_frequency(y)}
    \begin{algorithmic}
    \Return $z \cdot h(y)$
    \end{algorithmic}
    \end{algorithm}
```
### Proving that $z \cdot h(y)$ is unbiased for $f_{y}$

$$
\begin{align}
E[z \cdot h(y)] & = E\left[ \left( \sum_{i=1}^m h(x_{i}) \right) \cdot h(y) \right] \\
& = E\left[\left( \sum_{x_{i}=y} h(x_{i})\cdot h(y) \right) + \left( \sum_{x_{i}\neq y} h(x_{i}) \cdot h(y) \right)   \right] \\
& =\sum_{x_{i} = y} E[h(x_{i}) \cdot h(y)] + \sum_{x_{i}\neq y} E[h(x_{i}) \cdot h(y)]
\end{align}
$$
Knowing that when $x\neq y$ we have that $E[h(x)\cdot h(y)]=0$ we get :
$$
= \sum_{x_{i} = y} E[h(x_{i}) \cdot h(y)] + 0 = \sum_{x_{i} = y} 1 = f_{y}
$$
### Analysis

By *repetition* we get :

>[!important] Theorem
>Let $f$ be the *frequency vector* of our stream. Fix $\epsilon$ and $\delta$. *Count Sketch* uses $O(\epsilon^{-2}\log(1/\delta))$ *words* and *returns* $f_{y} \pm \epsilon ||f||_{2}$ with *probability* $1-\delta$

>[!note] 
>[[Frequency Estimation on Streams#Count-Min sketch|Count-Min sketch]] is *smaller* then *Count Sketch* by a factor $\epsilon^{-1}$ but returns $f_{y} \pm \epsilon \cdot m$ , this is worse that *Count Sketch* because $||f||_{1} = m \ge ||f||_{2} = \sqrt{\sum_{x} f_{x}^2}$

# Tug-of-war sketch (ToW)

We can use the idea of *Count Sketch* to estimate $F_{2}=\sum_{x}f_{x}^2$ 

>[!note] 
>$F_{2}$ reflects how much frequencies are *unbalanced*

```pseudo
	\begin{algorithm}
	\caption{initialization()}
	\begin{algorithmic}
	\State $h \leftarrow$ four-wise independent function from $[n]$ tp \{-1,+1\}
	\State $z \leftarrow 0$
	\end{algorithmic}
	\end{algorithm}
	
	\begin{algorithm}
	\caption{new_stream_element(x)}
	\begin{algorithmic}
	\State $z \leftarrow z + h(x)$
    \end{algorithmic}
    \end{algorithm}
    
    \begin{algorithm}
    \caption{estimate_second_order_moment()}
    \begin{algorithmic}
    \Return $z^2$
    \end{algorithmic}
    \end{algorithm}
```
### Analysis

>[!important] Theorem
>*ToW* is **unbiased** : $E[z^2]=F_{2}$

**Proof** :

$$
\begin{align}
E[z^2] & = E\left[ \left( \sum_{i=1}^m h(x_{i}) \right)^2 \right] \\
& = E\left[ \left( \sum_{x\in [n]} f_{x}\cdot h(x) \right)^2 \right]
\end{align}
$$
>[!note]- 
>This is just a reformulation where instead of summing for each element in the stream it's hash value we get the unique elements and sum the multiplication of it's frequency by its hash value

$$
= E \left[ \sum_{x \in [n]}(f_{x}^2 \cdot h(x)^2) + \sum_{x \neq y}(2 f_{x} f_{y} \cdot h(x) \cdot h(y)) \right]
$$
>[!note]-
>Just expanding the square

$$
=\sum_{x\in[n]} f_{x}^2 \cdot E[h(x)^2] + \sum_{x\neq y} 2 f_{x} f_{y} \cdot E[h(x)\cdot h(y)]
$$
Now as before we have that $E[h(x) \cdot h(y)] = 0$ and $E[h(x)^2]=1$ the result will be the following :
$$
= \sum_{x \in [n]} f_{x} \cdot 1 + \sum_{x\neq y} 2 f_{x} f_{y} \cdot 0 = F_{2}
$$
---
>[!important] Theorem 
>$$
>Var[z^2] \le 3 F_{2}^2 = 3 E[z^2]^2
>$$

**Proof**

$$
\begin{align}
Var[z^2] = E[(z^2)^2] - E[z^2]^2 & \le E[z^4] \\
& = E\left[ \left( \sum_{y=1}^n f_{y} \cdot h(y) \right)^4 \right] \\
& = \sum_{a,b,c,d\in [n]} f_{a}f_{b}f_{c}f_{d} E[h(a)h(b)h(c)h(d)]
\end{align}
$$
>[!note] 
>For *four-wise* independence if an integer in $a,b,c,d$ appear an *odd* number of *times* than that expectation goes to $0$
>>[!example] 
>>$E[h(3)h(5)h(3)h(7)] = E[h(3)^2]\cdot E[h(5)]\cdot E[h(7)] = 1 \cdot 0 \cdot 0 = 0$
>
>On the other hand if all integers in $a,b,c,d$ appear an *even* number of *times* this expectation is $1$
>>[!example] 
>>$E[h(3)h(5)h(3)h(5)] = E[h(3)^2 \cdot h(5)^2] = 1$

Hence only **squares** and $4$**-th powers** of frequencies survive

$$
\begin{align}
Var[z^2] = E[(z^2)^2] - E[z^2]^2 & \le E[z^4] \\ \\
& \leq F_{4} + 6 \sum_{a<b \in [1,n]} f_{a}^2f_{b}^2 \\
& \leq 3 F_{2}^2 - 2 F_{4} \\
& \leq 3 F_{2}^2 = O(E[z^2]^2)
\end{align}
$$
### Final result

Now that we know that :
+ $z^2$ is unbiased for $F_{2}$ 
+ $Var[z^2]=O(E[z^2]^2)$

We can use the [[Concentration Bounds#Mean+Median trick|Mean+Median trick]] this gives us :

>[!important] Theorem
>For any chosen $\epsilon$, $\delta > 0$ the *tug-of-war* algorithm uses $O(\epsilon^{-2}\log(1/\delta))$ words of *space* and returns an estimator $z^2$ such that :
>$$
>\mathbb{P}(|z^2-F_{2}|>\epsilon \cdot F_{2}) < \delta
>$$

## Dimensionality Reduction

With $F_{2}$ we can create a *linear operator* $M$ ( a matrix ) such that, with probability $2/3$ $M$ *preserves* the **Euclidean** *distance* ( $l_{2}$ norm ) with distortion factor $\epsilon$ but reducing the *dimensions* from $\mathbb{R}^n$ to $\mathbb{R}^{O(\epsilon^{-2})}$ 

![[dim_red.excalidraw.png]]
%%[[dim_red.excalidraw.md|🖋 Edit in Excalidraw]]%%

>[!note]
>$$
>l_{2} = ||x-y||_{2}=\sqrt{ \sum_{i=1}^n (x_{i}-y_{i})^2}
>$$ 

This is useful because with $\mathbb{R}^n$ the time that we need to compute each distance is $O(n)$ , while with *dimensionality reduction* we get *time* : $O(\epsilon^{-2})$ 

Also the set gets compressed to just $O(\epsilon^{-2})$ *words* per vector

### $\mathbb{R}^n$ to $\mathbb{R}^1$ 