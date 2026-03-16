>[!question] 
>What is the information-theoretic lower bound for encoding strings over $\{a,b,c,d\}^n$

Since each position has $4$ choices we have $4^n$ strings , than the **IT** is $$\lceil \log_2 4^n \rceil = n \log_2 4 = 2n = O(n)$$
So we need $2n$ *bits* to econde it

>[!question] 
>What is the information-theoretic lower bound for encoding strings over $\{a,b,c,d\}^n$ and such that the string contains only $2$ occurrences of letter $a$ ?

Since we know that we need to put we remain with $3$ possibilities ( $\{b,c,d\}$ )  for the remaining $n-2$ position so $3^{n-2}$ possible strings , than we need to choose the postion of the two a's : $\binom{n}{2}$ , so the total possibilities are : 
$$
\binom{n}{2} \cdot 3^{n-2}
$$
The **IT** is : 
$$
\log_2 \binom{n}{2} \cdot 3^{n-2} = \log_2 \binom{n}{2} + (n-2)\log_2 3
$$
>[!note] 
>$$
>\frac{n!}{2! \cdot (n-2)!} = \frac{n(n-1)(n-2)!}{2 \cdot (n-2)!} = \frac{n\cdot(n-1)}{2} \approx n^2
>$$

simplifyng with the [[Notazione O grande|Big O Notation]] we have : 
$$
2 \cdot \log_2 n + n \log_2 3 \approx O(\log_2 n) +n \log_2 3
$$

>[!question] 
> Can you encode (lossless) in $m$ bits a set containing $m$ integers from $[n]$? And in $n$ bits?

In $m$ bits *NO* we can't since we will run into collisions

In $n$ bits we just use the a *presence vector* , for example to store the set $\{2,5,7\}$ with $n=8$ we encode the following *bitvector* : $01001010$


>[!question] 
>Is it true that $10^{999}n \in O(n^2)$ ?

Yes , *big O* ignores multiplication therms

>[!question] 
>Is it true that $n(\log \log n)^2/\log n \in o(n)$ ?

We use the definition of [[Notazione O grande#$o Big(g(n) Big)$|o(n)]] : 
$$
\lim_{\infty} \frac{n(\log \log n)^2}{\log n} \cdot \frac{1}{n} = \lim_{\infty} \frac{(\log \log n)^2}{\log n}
$$

Since $\log n$ grows *faster* than $\log \log n$ than the limit approaches $0$ and therefore by definition $n(\log \log n)^2 / \log n \in o(n)$


