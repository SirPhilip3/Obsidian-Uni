---
publish: true
---
We can use **context**

>[!example] 
>If we see the word "ompile" than almost cerainly the previous letter is "c" , we can than use few bits for "c" and more bits for other letters

**Definitions** : 

Let $S\in \Sigma^n$ , *choose* an integer $k$ such thata $k \leq n$ , let than $w \in \Sigma^k$ 

$S_w$ is the concatenation of all the characters that are preceding the occurances of $w$ in $S$ , starting from the *left* up to it's *rightmost* occurence

>[!example] 
>$S=aababbabab$ and $k=2$ , than we have : 
>+ $S_{ab} = abbb$ ( *a*a*b*ab*b*a*b*ab )
>+ $S_{bb} = a$
>+ $S_{aa} = b$
>+ $S_{ba} = abaa$

>[!info] Idea
>Put in the same *bucket* ( $S_w$ ) all characters followed by the same context $w$ and apply $H_0$ inside each bucket  

>[!important] Definition **k-th order empirical entropy**
>
>Let $S \in \Sigma^n$ and choose $k \leq n$. The *k-th order empirical entropy* of $S$ is :
>$$
>H_k(S) = \sum_{w \in \Sigma^k} \frac{|S_w|}{n} H_0(S_w)
>$$ 

**Property** : 
$$
\log_2 \sigma \geq H_0 \geq H_1 \geq H_2 \geq \dots
$$
>[!danger] 
>We can't choose $k=n$ since any *entropy compressor* must pay an additonal term $\sigma^k$ , hence , to be viable $k < \log_{\sigma} n$ 
