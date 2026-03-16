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

We can solve *membership* , *predecessor* , *successor* on a **set** by reducing these operations to *access*, *rank*, *select* on it's characteristic **bitvector** :

+ *membership* of $x$ in $S$ check if $B[x] = 1$
+ *predecessor* $B.select_1(B.rank_1(x))$ : rank will get the last  
+ *successor*
# Zero-order compressed Bitvectors

>[!important] Definition
>There exists a

# Moder Model of Computation

# Bit-packing