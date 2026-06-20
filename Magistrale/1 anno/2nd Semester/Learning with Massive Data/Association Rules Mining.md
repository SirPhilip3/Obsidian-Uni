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

