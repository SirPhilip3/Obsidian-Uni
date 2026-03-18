>[!important] Definition 
>A *bitvector* is an element of $\{0,1\}^n$ ( string of $n$ bits )

**Operations** let $B\in\{0,1\}^n$ : 
+ *access* : $B[i]$ access the $i$-th bit in $B$
+ *rank* : $B.rank_0(i)$ the number of $0$ in $B[1, \dots,i]$ ($rank_1$ for the $1$'s)
+ *select* : $B.select_0(i)$ the position in $B$ of the $i$-th $0$ ( $select_1$ for the $1$'s )

>[!example] 
>$B=0010100$
>+ $B[3] = 1$
>+ $B[6] = 0$
>+ $B.rank_0(5) = 3$
>+ $B.rank_1(5) = 2$
>+ $B.select_0(4) = 6$
>+ $B.select_1(2) = 5$

>[!note] 
>A *bitvector* $B$ can be seen as the set $S$ , by encoding it as *presence vector* , so $I \equiv B$ , where $I$ is a *integer set*

>[!note] 
>$\mathscr{B}_{n,m}$ is the *bitvector* over the set $S \subseteq [n]$ with $|S|=m$

We can solve *membership* , *predecessor* , *successor* on a **set** by reducing these operations to *access*, *rank*, *select* on it's characteristic **bitvector** :

+ *membership* of $x$ in $S$ check if $B[x] = 1$
+ *predecessor* ( $\max\{y \in S | y \leq x \}$ ) $B.select_1(B.rank_1(x))$ : rank will get the lenght of the $1$'s before $x$ , select will get the position of the last , this will be $y$
+ *successor* ( $\min\{y \in S | y \ge x \}$ ) we distinguish two cases : 
$$
succ(x) = \begin{cases}
x & \text{if } B[x]=1 \\
B.select_1(B.rank_1(x) +1) & \text{otherwise}
\end{cases}
$$
# Zero-order compressed Bitvectors

>[!important] Definition
>There exists a *data structure* over any **bitvector** $B \in \mathscr{B}_{n,m}$ using $\log \binom{n}{m} + o(n) \leq n H_0 + o(n)$ *bits* o space, and **supports** *constant-time* **access, rank , select** queries

This definition is equivalent also to the following one : 
>[!important] Definition
>There exists a *data structure* over any *subset of size* $m$ of $[n]$ using $1log \binom{n}{m} + o(n)$ bits of space and supporting *constant-time* **membership** , **predecessor** and **successor** queries
>
>>[!note] 
>>The $o(n)$ could be $\gg \log \binom{n}{m}$ so this is *bad* for *sparse/dense sets*

# Moder Model of Computation

We use the **word RAM** model:
+ Uses *words* of $w = \Theta(\log n)$ *bits* each, where $n$ is the *input size*
+ *contant-time* **bitwise operations** between words
	+ $X+Y$
	+ $X * Y$
	+ $X\ \&\ Y$ ( bitwise *and* )
	+ $X\ |\ Y$ ( bitwise *or* )
	+ $X >> k$ ( right shift )
# Bit-packing

Storing $B \in \{0,1\}^n$ using $n +\Theta(\log n)$ *bits* while supporting **access** in $O(1)$ time : 

Pack the $n$ bits in a vector $V$ containing $n/w$ integers of $w$ bits each ( $w$ is the word lenght )

>[!example] 
>Given $B= 10010110111100011000$ and $w=4$ , $n=20$, than the corresponding vector $V$ is $V=[9,6,15,1,8]$ , this has *space* : $n+\Theta(w) = n +\Theta(\log n)$

Now implementing **access** in $O(1)$ : 
1. We want to extract $B[i]$, than to find the index in $V$ : $\lfloor i/w \rfloor$  
2. To discover the position inside that *integer* we simply execute $i \mod{w}$ 
3. Extracting the *bit* : $(V[word] >> offset)\ \&\ 1$ , the $\&\ 1$ at the end keeps only the rightmost bit and discards the rest

>[!example] 
>$B[6] = 1$ : 
>$word = \lfloor  6/4 \rfloor = 1.5 = 1$
>$V[1] = 6 = 0110$ 
>$offset = 6 \mod{4} = 2$
>$0110 >> 2 = 0001 \& 0001 = 1$

>[!important] Theorem
>$B \in \{0,1\}^n$ can be stored in $n+ \Theta(\log n)$ *bits* so that any subsequence $B[i, \dots , i + l -1]$ of lenght $l \leq \log n$ , can be *extracted* and *packed* in one *word* in $O(1)$ time

# Compressing the bitvector to $nH_0+o(n)$ bits

1. Fix a **block size** $b = \lceil \frac{log_2 n}{2} \rceil$
2. Divide $B\in \{0,1\}^n$ into $n/b$ *blocks* of $b$ bits each
>[!note] 
>Assume that $b$ divides $n$
3. Store a table $T$ containing *all possible bitvectors* of lenght $b$, $T[k]=\mathscr{B}_{b,k}$ 
4. Encode each *block* of $B$ as a *variable-lenght* pointer inside $T$
>[!note] 
>We need to divide $b$ by $2$ or by a constant larger than $2$ because otherwise the table $T$ would become $O(n)$ 

## Building $T$

