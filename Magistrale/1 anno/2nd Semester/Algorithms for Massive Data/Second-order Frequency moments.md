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

#todo 