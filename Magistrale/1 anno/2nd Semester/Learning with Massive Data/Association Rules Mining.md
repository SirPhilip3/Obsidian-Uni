---
publish: true
---
In the typical scenario of *marked-basket analysis* our *goal* is to :
+ Identify items that are bought together by sufficiently many customers

>[!example] 
>
>| TID | Items                     |
>| --- | ------------------------- |
>| 1   | Bread, Milk               |
>| 2   | Bread, Diaper, Beer, Eggs |
>| 3   | Milk, Diaper, Beer, Coke  |
>| 4   | Bread, Milk, Diaper, Beer |
>| 5   | Bread, Milk, Diaper, Coke |
>

**Definitions** :

+ *Itemset* :
	A collection of one or more items :  
	$\{Milk, Bread,Diaper\}$
+ *k-Itemset* :
	An *itemset* that contains $k$ items
+ *Support count* $\sigma$ : 
	Number of occurences of an itemset
	$\sigma(\{Milk, Bread,Diaper\})=2$
+ *Support* $supp$ :
	Fraction of transaction that contain an *itemset*
	$supp(\{Milk,Bread,Diaper\}) = \frac{2}{5}$
+ *Frequent Itemset* :
	An itemset whose *support* is *greater* than or equal to a given threshold $s$ 

+ **Association Rule** : 
	Is an implication expression in the form $X \to Y$ where $X$ and $Y$ are *itemsets*
	$\{Milk,Diaper\} \to \{Beer\}$

## Rule Evaluation Metrics

**Support** $supp$ :
	Fraction of transactions that contain both $X$ and $Y$

**Confidence** $conf$ :
	Measures how often items in $Y$ appear in transactions that contain $X$ 

**Interest** $int$ :
	Difference between the *confidence* of the rule and the *support* $\sigma(Y)$

>[!example] 
>$r: \{Milk,Diaper\} \to \{Beer\}$
>
>+ $supp(r)=\frac{\sigma(\{Milk,Diaper,Beer\})}{|D|} = \frac{2}{5}$
>+ $conf(r) = \frac{\sigma(\{Milk,Diaper,Beer\})}{\sigma(\{Milk,Diaper\}) }= \frac{2}{3}$ 
>+ $int(r)= conf(r) - \sigma(\{Beer\}) = \frac{2}{3}-\frac{3}{5}=+7\%$ 

# Finding Association Rules

>[!important] Problem Statement
>Find all association rules with *support* $\ge s$ and *confidence* $\ge c$ 

>[!error] Brute Force approach
>
>1. List all possible association rules
>2. Compute the *support* and *conficence* for each rule
>3. Prune rules that fail the *thresholds*
>
>**Computationally prohibitive**

---

Example *generated* rules : 
+ $\{Milk,Diaper\} \to \{Beer\}$ (supp=0.4, conf=0.67)
+ $\{ Milk,Beer\} \to \{Diaper\}$ (supp=0.4, conf=1.0)
+ $\{Diaper,Beer\} \to \{Milk\}$ (supp=0.4, conf=0.67)
+ $\{Beer\} \to \{Milk,Diaper\}$ (supp=0.4, conf=0.67)
+ $\{Diaper\} \to \{Milk,Beer\}$ (supp=0.4, conf=0.5)
+ $\{Milk\} \to \{Diaper,Beer\}$ (supp=0.4, conf=0.5)


We notice that all the generated rules are *binary partitions* of the same *itemset* 

Rules originating from the same *itemset* have identical *support* but can have different *confidence*

**Two-step approach** :

1. Frequent Itemset Generation
	1. Generate all *itemset* whose support $\ge s$
2. Rule Generation
	1. Given a frequent itemset $I$ 
	2. For every $A \subset I$ generate rule $r : A \to I \backslash A$
	3. Since $supp(I) \ge s$ then $supp(r) \ge s$
	4. Scan the dataset to compute the conficence $conf(r)$ 
		1. Since $A$ and $I$ are frequent we have both *supports* already
	5. Output *confident* rules

## Frequent Itemset Generation

### Apriori Algorithm

>[!important] Apriori Principle
>If an itemset is frequent then *all* of its *subsets* are *frequent*

>[!important] Anti-monotonicity
>If we increase the itemset lenght its support cannot increase

With this principle we can say that when we find an *in-frequent* itemset all of it's superset will also be *in-frequent* and so can be pruned

Let :
+ $C_{k}$ be a set of $k$-itemset that *might* be *frequent*
+ $L_{k}$ be a set of $k$-itemset that *are* *frequent*

```pseudo
	\begin{algorithm}
	\caption{Apriori Algorithm}
	\begin{algorithmic}
	\State $k=1$
	\State Scan the dataset to compute $L_1$
	\While{$L_k \neq \emptyset$}
		\State Generate $C_{k+1}$ from $L_k$
		\State Scan the dataset to compute the support of each itemset in $C_{k+1}$
		\State Remove infrequent itemsets from $C_{k+1}$ to get $L_{k+1}$
		\State $k=k+1$
    \EndWhile
	\end{algorithmic}
	\end{algorithm}
```
#### Candidate Generation

+ **Brute Force** : 
	Given the single items compute all possible combinations of lenght $k$

+ **Merge** $L_{k-1}$ *and* $L_{1}$ :
	Append one item from the frequent singletons

+ **Merge** $L_{k-1}$ *and* $L_{k-1}$ :
	Merge any two frequent itemsets with equal $k-2$ *prefix*

>[!example] 
>Let $L_{3} = \{ ABC,ABD, ABE, ACD,BCD,BDE, CDE\}$
>
>We obtain $C_{4}$ by doing :
>+ $Merge(ABC,ABD) = ABCD$
>+ $Merge(ABC,ABE) = ABCE$
>+ $Merge(ABD,ABE) = ABDE$

Also after generating $C_{k}$ we can do *candidate pruning* checking if **all** its subsets of lenght $k-1$ are in $L_{k-1}$ , if not *discard it* 

#### Spark Implementation 

1. Compute $L_{1}$ :

```python
transactions   = sc.textFile("database") 
items          = transactions.flatMap(lambda line: get_list_of_ints(line))
itemPairs      = items.map(lambda item: (item, 1))
itemCounts     = itemPairs.reduceByKey(sum)
freqItemCounts = itemCounts.filter(lambda ic: ic[1] >= min_supp)

L1 = freqItemCounts.keys().collect()
```

2. Compute $L_{k}$ :

```python
while( len(L_{k-1}) > 0 ):
	C_k = Generate( L_{k-1} )
	C_k = sc.broadcast( C_k )
	
	transactions  = transactions.map(lambda line: get_set_of_ints(line))
	itemsets      = transactions.flatMap(lambda tr: get_candidates_in_tr(tr, C_k))
	itemsetPairs  = itemsets.map(lambda itemset: (itemset, 1))
	itemsetCounts = itemsetPairs.reduceByKey(sum)
	freqsCounts   = itemsetCounts.filter(lambda ic: ic[1] >= min_supp)
	
	L_k = freqsCounts.keys().collect()
```

3. Parallelize candidate generation

```python
L_{k-1} = sc.parallelize( L_{k-1} )
prefix_last = L_{k-1}.map( lambda itemset: (itemset[:-1], itemset[-1]))
prefix_extensions = prefix_last.reduceByKey(concat)
C_k = prefix_extensions.flatMap( append_extension_pairs() )
C_K = sc.broadcast(C_k.collect())
```

>[!note] 
>+ Re-oder items by descending counts helping reducing the number of candidates
>+ Remove from the dataset items not in $L_{1}$ and remap item *ids* from $0$ to $|L_{1}|-1$
>+ Itemset of lenght $k=2$ significantly impact performance
#### Counting Pairs 

Counting pairs with less memory : 
+ **Matrix Approach** : keep counts in a *triangular* matrix 
	+ for each transaction and for each pair in the transaction incremente the matrix entry by $1$ 
	+ Memory demanding 
+ **Triples Approach** : keep $[i,j,c]$ where $\{i,j\}$ is a candidate pair and $c$ is its count :
	+ Does not store pairs with $0$ count
	+ Use *hash* table where $\{i,j\}$ is the key and $c$ is the value
	+ Migh require more memory than matrix 

### PCY ( Park-Chen-Yu ) Algorithm

>[!note] 
>In pass $1$ of [[#Apriori Algorithm]] most of the memory is idle

**1st Pass**

In addition to item counts maintain an *hash table* with as many buckets at they fit in memory

Keep a count for each bucket into which pairs of items are hashed 

For each bucket just keep the count not the actual pairs 

**2nd Pass**

We use the output of the first pass as a filter

1. Replace the buckets with a *bit-vector*
	+ $1$ = frequent , $0$ = infrequent buckets 

2. Count support of pair $\{i,j\}$ if and only if :
	+ $i$ and $j$ are both *frequent*
	+ $\{i,j\}$ hashes to a frequent bucket

#todo 
### SON  ( Savasere, Omiecinski and Navathe ) Algorithm

### Toivonen Algorithm 

