---
publish: true
---
In *massive data* we can't store the data on the disk and than build a data structure on it 

**Massive Data Paradigm** : 

Data arrives as a stream ( we will not store it ) , we then can use two solutions to build data structures on it : 
+ build on the fly a **lossless** *compressed* data structure
+ build on the fly a **lossy** *sketch* of the data 

>[!note] 
>**lossy** *sketch* can have *exponential compression* but will return *approximate answers* ( wrong with *small* probability )

# Notation

Set of integers $S = \{ 3,5,6,7 \}$ 
	$m=4$  ( number of inegers in the set $S$ ) 
	$n=8$   ( $[8] = \{1,2,\dots,8\}$ from the *universe* of the numbers from $1$ to $n$ )

We denote $\{a,b,c,d\}^n$ , where $\{...\}$ is the universe and $n$ is lenght of the sets
 
>[!important] 
>Number of subsets of cardinality $m$ ( lenght ) from the universe $[n]$ : 
>$$
>\binom{n}{m} = \frac{n!}{m!(n-m)!}
>$$
>
>[[Combinazioni]]

>[!important] 
>The longest *injective ([[Iniettività]]) binary encoding* of a *set* $S$ must be of at least : 
>$$
>\log_2\binom{n}{m}
>$$
>
>**bits**
>
>>[!example] 
>>Otherwise we will have **collisions** : 
>>
>>Use $2$ bits to encode *sets* with $m=2$ and $n=4$
>>
>>```
>>{1,2} -> 00
>>{1,3} -> 01
>>{1,4} -> 10
>>{2,3} -> 11
>>{2,4} -> 00
>>{3,4} -> 01
>>```
>
>If we calulate $\log_2 \binom{4}{2} = \log_2 6 = 2.58 = 3$ bits necessary 

>[!important] **Information-Theoretic lower bound**
>
>If i want to encode objects from a universe $U$, i cannot use less than $\log_2(|U|)$ *bits* from each of those objects

For sets of integers: 
$$
\log_2 \binom{n}{m} = m \log(n/m) + O(m)
$$
*bits*

We use [[Notazione O grande|Big O Notation]] 

[[Lec 1 exercise]]
