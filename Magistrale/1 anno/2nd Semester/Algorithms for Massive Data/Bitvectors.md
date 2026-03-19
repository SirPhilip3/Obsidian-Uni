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

Given $B=010\ 101\ 001\ 110\ 000\ 011\ 111$ so $n=21$ , $b = \lceil \frac{log_2 n}{2} \rceil = 3$  block size , $n/b = 7$ *blocks*

>[!important] Class of a block
>
>The number of $1$'s in the block

>[!example] 
>$$
>\begin{array}{lccccccc} B = & 010 & 101 & 001 & 110 & 000 & 011 & 111 \\ C = & 1 & 2 & 1 & 2 & 0 & 2 & 3 \end{array}
>$$

The array $C$ needs $\lceil \log_2(b+1) \rceil= \log_2( \frac{\log_2 n}{2} +1) = O(\log \log n)$ *bits* per integer , and in total in $C$ there are $n/b$ *bits* : 
$$
n/b \cdot \log(b+1) = n/\log n \cdot O(\log \log n) = n \frac{\log \log n}{\log n} = o(n)
$$
>[!note] 
>As seen in the [[Lec 1 exercise#^f4388e|Exercises]]

Now we build table $T$ , where the **classes** are on the row , each containing all the possible configuration of the *blocks* of that class, ordered from smallest to largest 

>[!example] 
>$$
>\begin{array}{r|c|c|c|c|}  & & 0 & 1 & 2 \\  \mathscr{B}_{3,0} \rightarrow & 0 & 000 & & \\ \mathscr{B}_{3,1} \rightarrow & 1 & 001 & 010 & 100 \\ \mathscr{B}_{3,2} \rightarrow & 2 & 011 & 101 & 110 \\
\mathscr{B}_{3,3} \rightarrow & 3 & 111 & & \\ \end{array}
>$$

We have $b+1$ *rows* , $\leq 2^b$ *columns* , each cell will take $b$ *bits* :
$$
O(b^2 \cdot 2^b) = O((\log n)^2 \cdot 2^{\log_2 n/2})= O((\log n)^2 \cdot \sqrt{2^{\log_2 n}}) = O((\log n)^2 \cdot \sqrt{n}) = o(n)
$$

>[!important] Offset of a block
>
>Is the *column* in $T$ where the *block* appears

>[!example] 
>$$
>\begin{array}{lccccccc} B = & 010 & 101 & 001 & 110 & 000 & 011 & 111 \\ C = & 1 & 2 & 1 & 2 & 0 & 2 & 3 \\ O = & 1 & 1 & 0 & 2 & 0 & 0 & 0 \end{array}
>$$

>[!note] 
>We can use a *variable encoding* to encode each *row* 

>[!example] 
>*Row* $1$ and $2$ in $T$ contains $3$ *nonempty columns* so we need enough *bits* to encode $3$ distinct values so we need $2$ bits to store them , while *row* $0$ and $3$ just needs to encode $1$ value so we need $0$ *bits* to store it

$$
\log |\mathscr{B}_{b,k}| = \log \binom{b}{k}
$$
Where $k$ is the *row number* ( or offset class )

In total we have : 
$$
\sum_{j=1}^{n/b} \log_2 \binom{b}{C[j]}
$$
Let's show that this is $\leq n H_0$
$$
\sum^{n/b}_{j=1} \log\binom{b}{C[j]} = \log \prod^{n/b}_{j=1} \binom{b}{C[j]}
$$
>[!note] 
>Knowing that 
>$$
>\binom{x}{y} \cdot \binom{z}{w} \leq \binom{x +z}{y+w}
>$$
>
>>[!example] 
>>![[binomsumlemult.excalidraw.png]]
>>%%[[binomsumlemult.excalidraw.md|🖋 Edit in Excalidraw]]%%

Summing $b$ for $n/b$ *blocks* than we have $\frac{n}{b} \cdot b = n$
Summing all $C[j]$ we get the total number of $1's$ in $B$ or $m$ 

We than get : 
$$
\log \prod^{n/b}_{j=1} \binom{b}{C[j]} \leq \log \binom{n}{m} 
$$
Using *Stirling* approximation ( [[Empirical Entropy ( Zero-order )#^328557|Stirling approximation]] ) we get : 
$$
\log \binom{n}{m} \leq nH_0
$$
>[!example] **Final encoding** ( using bit rapresentation )
>$$
>\begin{array}{lccccccc} B = & 010 & 101 & 001 & 110 & 000 & 011 & 111 \\ C = & 1 & 2 & 1 & 2 & 0 & 2 & 3 \\ encoded(C) = & 01 & 10 & 01 & 10 & 00 & 10 & 11 \\ O = & 1 & 1 & 0 & 2 & 0 & 0 & 0 \\ encoded(O) = & 01 & 01 & 00 & 10 &  & 00 &  \end{array}
>$$

>[!note] 
>We can reconstruct the lenghts of the codes in $O$ with the values in $C$

## Access 

Assuming that we can access any element of $C,O,T$ in *constant time*, than $B[i]$ can be also accessed in *constant time* :
1. Identifiy the block $t$ containing $B[i]$ : $t = \lfloor (i-1)/b \rfloor + 1$
>[!note] 
>The $+1$ it's only due to the indexing
>

>[!example] 
>Accessing $B[8]$ , $t = \lfloor (8-1)/3 \rfloor +1 =\lfloor 2.33 \rfloor +1 = 2+ 1 = 3$
>$$
>\begin{array}{lccccccc} B = & 010 & 101 & 0\textcolor{red}{0}1 & 110 & 000 & 011 & 111 \\ C = & 1 & 2 & \textcolor{red}{1} & 2 & 0 & 2 & 3 \\ O = & 1 & 1 & \textcolor{red}{0} & 2 & 0 & 0 & 0 \end{array}
>$$

2. Now access $B_t = T[C[t],O[t]] = T[1,0] = 001$
3. Extract $B[i]$ from $B_t$ , as seen in [[Bitvectors#Bit-packing|Bit-packing]]

>[!note] 
>Accessing $C$ and $T$ in $O(1)$ is *easy* , since they use *fixed-lenght encoding* we can just use [[Bitvectors#Bit-packing|Bit-packing]]  

### Accessing $O[i]$ in $O(1)$ time using just $o(n)$ extra bits

Divide $O$ in **macroblocks** , groups of $b$ blocks:
+ Store explicitly the starting position of every *macroblock* 
+ Store the starting position of every *offset* block, *relative to the beginning* of each *macroblock*

>[!example] 
>
>$$
>\begin{array}{rccc|ccc|c} & O_1 & O_2 & O_3 & O_4 & O_5 & O_6 & O_7 \\
>\text{encoded offsets} & 01 & 10 & 00 & 10 & & 00 & \\  \text{starting position of macroblock} & 1 & & & 7 & & & 11 \\  \text{relative starting position of offset inside macroblock} & 1 & 3 & 5 & 1 & 3 & 3 & 1 \end{array}
>$$

Now to extract a code we just need to sum up the *starting position* of that *macroblock* and it's *relative starting* position

>[!example] 
>To extract $O_6$ we sum up $7$ and $3$ , so $7+3-1=9$ , the $-1$ is just becouse we use $0$ indexing

#### Space analysis

Each encoded offset takes at most : 
$$
\log \binom{b}{k} \le \log 2^b = b
$$
>[!note] Proof
>#todo

Since ther are a maximum of $b$ 

## Rank

# Compressing Multiple bitvectors