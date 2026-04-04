---
publish: true
---
Compressing : 
+ **Dictionary**
	+ Small enough to keep it in main memory all the time 
+ **Postings files**
	+ Reduce disk space
	+ Decrease time needed to read the postings lists from disk 
# Initial Sizes 

![[Pasted image 20260402150601.png]]
# Heap Law

Helps us determine the *vocabulary size* depending on the *collection size* :
$$
M = k T^b
$$
Where : 
+ $M$ : *vocabulary* size
+ $T$ : tokens in the *collection* 

$k$ and $b$ are *free parameter* determined empirically 

>[!note] 
>If we use *log-log* space , where $X= \log M$ and $Y = \log T$ we get :
>$$
>\log M = \log k T^b
>$$
>$$
>\log M = \log k + \log T^b
>$$
>$$
>\log M = \log k + b \log T
>$$
>$$
>Y = bX + \log k
>$$
>Than now $k$ is the *intercept* and $b$ the *slope*
>

#todo do graph

For each *document corpus* we can than train it like a linear classifier
# Zipf Law

*Zipf law* studies the relative frequencies of terms 

>[!note] 
>Assume that *terms* are *ranked* from most frequent to least 

>[!note] Notation
>+ $t_i$ : the *term* at rank $i$
>+ $cf_i$ : *collection frequency* or the number of *occurences* of the term $t_i$ in the collection
>$$
>cf_i = \sum_{d \in D} tf_{i,d}
>$$
>+ $df_i$ : *document frequency* : the *total* number of documents that contain the term $t_i$  
>$$
>\sum_{d\in D} f(tf_{i,d})
>$$
>Where $f$ is :
>$$
>f(tf_{i,d}) = \begin{cases}
>1 & \text{if } tf_{i,d} > 0 \\
>0 & \text{otherwise}
>\end{cases}
>$$
>+ $tf_{i,d}$ : *term frequency* : total numer of occurences of the term $t_i$ in the document $d$

>[!important] Definition
>The $i$-th *most frequent term* $t_i$ has a *collection frequency* $cf_i$ proportional to $\frac{1}{i}$

There can be a normalization factor $K$ , so it becomes $\frac{K}{i}$ , generally $K=cf_1$

>[!example] 
>The *1st* most frequent term occurs $cf_1$ times , the *2nd* insted occurs $cf_1/2$ times

We can than write the following formula : 
$$
cf_i = K/i = K \cdot i^{-1}
$$
>[!note] 
>On *log-log* space we can write ( with $X= \log i$ and $Y = \log cf_i$ )
>$$
>\log cf_i = \log k \cdot i^{-1}
>$$
>$$
>\log cf_i = \log k + \log i^{-1}
>$$
>$$
>\log cf_i = \log k - \log i
>$$
>$$
>Y = -X + \log k
>$$
>

#todo do graph

# Power Law

In general $80\%$ of the *effect* comes from $20\%$ of the *terms*
$$
p(i) \approx k \cdot i^{-\alpha}
$$
Where $\alpha$ is the *slope* of the probability distribution

#todo 
# Dictionary Compression

## Fixed Width array

Simply store each *dictionary* entry as the following struct : 
```c
struct Term{ 
	char[20] term;
	int frequency;
	int postings_pointer;
}
```

So in total each term will be : 
+ $20$ bytes for the *term* itself + 
+ $4$ bytes for the *frequency* of the term + 
+ $4$ bytes for the pointer to the *postings list*

This for $\sim 400000$ terms, we will have $400000 \times 28 = 11.2 MB$

>[!warning] 
>This method is wasteful since not all the *terms* need $20$ bytes to be stored , also we can't handle very large words 
## Dictionary as a String

Store the *dictionary* as a long string of characters , in the struct we save a pointer stating the starting postion of that term on the string ( the lenght of the term is the distance between the current pointer and the next one )

A string containing $400000$ *terms*, each of *average lenght* $8$ , will need $400000 \times 8B = 3.2MB$

And since we need to resolve $3.2M$ pointers positions we will need $\log_2 3.2M=22$bits to store the *pointers* ( $3$ *Bytes* )  

So in total we will have :
+ $4$ bytes per *term frequency*
+ $4$ bytes per *pointer* to postings
+ $3$ bytes per *term pointer*
+ An *average* of $8$ bytes per term in the *string*

$\sim 400000 \times 19$ Bytes = $7.6MB$

>[!example] 
>![[dict_string.excalidraw.png]]
%%[[dict_string.excalidraw.md|🖋 Edit in Excalidraw]]%%
### Blocking

Instead of storing pointer to all the words, store a *pointer* to the start of blocks of $k$ consecutive terms 

We need to store an extra *Byte* before each word to indicate the lenght of the 

>[!example] 
>![[dic_string_blocking.excalidraw.png]]
%%[[dic_string_blocking.excalidraw.md|🖋 Edit in Excalidraw]]%%

Like this we save $3$ *pointers* ( $9$ bytes ) but we add $4$ bytes for *block* for the lenght integer

We save $5$ *bytes* per block

With $k=4$ we save :
$$
5B \cdot \frac{400000}{4} = 0.5 MB
$$
The dictionary becomes : $7.1MB$
#### Perfomance

>[!warning]
>We save more with larger $k$ but at a *performance cost* in the **query**

In fact doing *dictionary search* **without** *blocking*, assuming each term is *equally likey* to show up in a query, will take an average of $\log_2 n$ comparisons, since we perform **binary search** on the pointers ( $n$ is the number of *terms* )

Instead in *dictionary search* **with** *blocking* we can only do **binary search** for $k$-term block and than we will need to do *linear search* for the rest
### Front coding

Since the *dictionary string* is **sorted** blocks will have *long* **common** *prefix* , for each block we will than store the difference between them 

>[!example] 
>![[front_coding.excalidraw.png]]
%%[[front_coding.excalidraw.md|🖋 Edit in Excalidraw]]%%

Another possible *front coding* is always looking at prefixes of the previous term 

| Input      | Common prefix | Compressed output |
| ---------- | ------------- | ----------------- |
| myxa       | ---           | `0 myxa`          |
| myxophyta  | `myx`         | `3 ophyta`        |
| myxopod    | `myxop`       | `5 od`            |
| nab        | ---           | `0 nab`           |
| nabbed     | `nab`         | `3 bed`           |
| nabbing    | `nabb`        | `4 ing`           |
| nabit      | `nab`         | `3 it`            |
|            |               |                   |
| *64 bytes* |               | *46 bytes*        |
>[!note] 
>In the *compressed output* we still need to store the lenght of the *suffixes*
# Postings Compression

In the *postings* we can just store the **gaps** between `docID`'s , since most of the gaps can be encoded with less than the bit necessary to store the whole `docID`

## Variable lenght encoding

#todo 