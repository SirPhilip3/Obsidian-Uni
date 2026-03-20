>[!important] Theorem 
>Any $S \subseteq \{0,\dots, n-1\}$ of cardinality $m=|S| \leq n$  can be compressed in : 
>$$
>\log \binom{n}{m} + O(m) \equiv m \log(n/m) +O(m)
>$$
>*bits*

**Queries** : 
+ *access* ( retrieving the $i$-th smallest integer from $S$ ) costs $O(1)$ *time*
+ *membership* , *predecessor* and *successor* cost $O(\log m)$ *time*

This can *equivalently* be seen in terms of *bitvectors* : 
>[!important] Theorem
>Any [[Bitvectors]] $B \in \mathscr{B}_{n,m}$ can be compressed in : 
>$$
>\log \binom{n}{m} + O(m) \leq n H_0 +O(m)
>$$
>*bits*

**Queries** : 
+ $select_1$ can be solved in $O(1)$ time  
+ *rank*, *access* and $select_0$ can be solved in $O(\log m)$ time 

# Assumptions

+ The smallest integer is $0$
+ $n$ is a *power* of $2$ , since we will encode integers in binary using $k$ *bits* where $n=2^k$
+ $m$ is a *power* of $2$

>[!note] 
>$$
>\log \binom{n}{m} + O(m)
>$$
>
>bits are ok both on sparse and dense sets but with slower queries

# Elias-Fano

Given $S=\{0,5,8,12,14,17,20,31\} \subseteq \{0,\dots, 31\}$ , $m=8, n=32$

1. Order the number in incresing order
2. Write each number using $\log n$ *bits*
>[!example] 
>
>| $x\in S$ | $(x)_2$ |
>| :------: | :-----: |
>|    0     |  00000  |
>|    5     |  00101  |
>|    8     |  01000  |
>|    12    |  01100  |
>|    14    |  01110  |
>|    17    |  10001  |
>|    20    |  10100  |
>|    31    |  11111  |
>
3. Break every integer in a : 
	1. *prefix* of lenght $\log m$ 
	2. *suffix* of lenght $\log n - \log m = \log(n/m)$ *bits*
>[!example] 
>
>| $x\in S$ | $\text{prefix of }(x)_2$ | $EF_1 = \text{ suffix of } (x)_2$ |
>| :------: | :----------------------: | :-------------------------------: |
>|    0     |           000            |                00                 |
>|    5     |           001            |                01                 |
>|    8     |           010            |                00                 |
>|    12    |           011            |                00                 |
>|    14    |           011            |                10                 |
>|    17    |           100            |                01                 |
>|    20    |           101            |                00                 |
>|    31    |           111            |                11                 |
>
4. Store the *suffixes* ( in a [[Bitvectors#Bit-packing|Bit-packed]] array ) in $m\log (n/m)$ *bits* of space
>[!note] 
>The *prefixes* are *nondecreasing* numbers in the range $[0,m)$ 

$$
EF_1 = 00\ 01\ 00\ 00\ 10\ 01\ 00\ 11
$$
5. Keep the *first* number
6. Keep the *differences* between consecutive numbers
>[!example] 
>| $x\in S$ | $\text{prefix } \to \text{diffrences}$ | $EF_1 = \text{ suffix of } (x)_2$ |
>| :------: | :------------------------------------: | :-------------------------------: |
>|    0     |               $0 \to 0$                |                00                 |
>|    5     |               $1 \to 1$                |                01                 |
>|    8     |               $2 \to 1$                |                00                 |
>|    12    |               $3 \to 1$                |                00                 |
>|    14    |               $3 \to 0$                |                10                 |
>|    17    |               $4 \to 1$                |                01                 |
>|    20    |               $5 \to 1$                |                00                 |
>|    31    |               $7 \to 2$                |                11                 |


7. Write them in **unary** : $y \to 0^y 1$
>[!example] 
>
>| $x\in S$ | $EF_2$ ( *unary* ) | $EF_1 = \text{ suffix of } (x)_2$ |
>| :------: | :----------------: | :-------------------------------: |
>|    0     |        $1$         |                00                 |
>|    5     |        $01$        |                01                 |
>|    8     |        $01$        |                00                 |
>|    12    |        $01$        |                00                 |
>|    14    |        $1$         |                10                 |
>|    17    |        $01$        |                01                 |
>|    20    |        $01$        |                00                 |
>|    31    |       $001$        |                11                 |

$$
EF_2 = 1\ 01\ 01\ 01\ 1\ 01\ 01\ 001
$$
$EF_2$ uses :
+ $m$ *bits* for the number of $1$'s
+ The number of $0$'s is equal to the sum of *differences* between adjacent *prefixes* , equal to the largest *prefix* $\leq m -1$
So in total $RRR(EF_2) \leq 2m +o(m)$

**Elias-Fano** is the pair $(EF_1,EF_2)$ , in total than , *at most* :
$$
m \log (n/m) + 2m +o(m)
$$
## Queries

>[!note] 
>Retrieving the $i$-th *integer* from $EF_1$ is *easy* since we use a *fixed-lenght* encoding , $O(1)$ time

Getting the *prefix* is done in the following way : 
$$
EF_2.rank_0(EF_2.select_1(i))
$$
>[!note] 
>These operation are in $O(1)$ time since $EF_2$ uses $RRR$ ( [[Bitvectors#Compressing the bitvector to $nH_0+o(n)$ bits|RRR]] )

>[!example] 
>Given $EF_1 = 00\ 01\ 00\ 00\ 10\ 01\ 00\ 11$ and $EF_2 = 1\ 01\ 01\ 01\ 1\ 01\ 01\ 001$
>
>Get $i=5$ , the *prefix* is $EF_2.rank_0(EF_2.select_1(5)) = 3 = 011$  and the *suffix* is $10$ 
>
>The result is $011\ 10 = (14)_2$


