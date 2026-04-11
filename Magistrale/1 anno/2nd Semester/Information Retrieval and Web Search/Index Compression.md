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

>[!note] 
>For rare words we use more *bits* per gap since the *gaps* are *larger* , while for *common* words we use *less* *space* since they occur in most documents

In general we would like to reach the best possible number of bits per encoding : $\lfloor \log_2 G \rfloor$

## Variable lenght encoding

We can use *byte* aligned codes , it's lenght varies depending on the distance between *gaps*

Let's say that $G$ is the *gap* between two postings for a term

We use $7$ bytes from each *byte* block to encode the actual number and a starting *bit* to indicate if we need to continue reading the *bytes* for the same *gap* or we can muve to the next one 

The $c$ *bit* will be : 
+ $0$ : if we need to continue reading
+ $1$ : if we can start reading the next *gap* after reading the byte

So if :
+ $G\leq 127$ we *binary encode* the number and set $c=1$
+ $G>127$ we *binary encode* the number , divide it in chunks of $7$ bits and add $c=0$ at the end, except for the *lowest order* bits that will have $c=1$ 

>[!example]
>
>| docID's | 824                      | 829        | 215406                                 |
>| ------- | ------------------------ | ---------- | -------------------------------------- |
>| gaps    | -                        | 5          | 214577                                 |
>| VB code | *0*0000110<br>*1*0111000 | *1*0000101 | *0*0001101<br>*0*0001100<br>*1*0110001 |
 >

Than the full *postings list* will be stored as the *byte concatenation* of all the encoded gaps 

>[!example] 
>*0*0000110*1*0111000*1*0000101*0*0001101*0*0001100*1*0110001

>[!note] 
>Other than bytes we can use different *unit of alignment*

>[!warning] 
>**VB** encoding wastes space if we have lots of *small gaps* , in this cases a *smaller* unit of alignemt may be better

>[!note] 
>*VB codes* are *uniquely prefix-decodable* , we don't need to look ahead or before to decode a number

## Unary code

Instead of rapresenting the gaps in *binary* we can rapresent $G=n$ with $n$ $1$'s with a final $0$

>[!example] 
>$4 = 11110$ 
>$40 = 11111111111111111111111111111111111111110$

### (Elias) Gamma codes $\gamma$

Gamma codes are *bit-level* codes 

This rapresents $G$ as a pair *lengh* and *offset* where :
+ *Offset* is $G$ in *binary* with the *leading bit truncated* 
>[!example] 
>$13 \to 1101 \to 101$

+ *Lenght* is the number of bits used to rapresent a gap, rapresented in *unary* 
>[!example] 
>For $13$ , with *offset* $101$ we will have $3 \to 1110$

The *Gamma code* will be the *concatenation* of *lenght* and *offset* 

>[!example] 
>For $13 \to 1110+101 \to 1110101$ 

>[!note] 
>*Gamma codes* are *uniquely prefix-decodable* , we don't need to look ahead or before to decode a number

The *Gamma codes* uses : $2 \lfloor \log_2 G \rfloor +1$ :
+ *offset* is $\lfloor \log_2 G \rfloor$ *bits*
+ *lenght* is $\lfloor \log_2 G \rfloor +1$ *bits* ( including the ending $0$ )

>[!note] 
>All *gamma codes* have an *odd* number of *bits* 

>[!important] 
>*Gamma codes* are not *byte/word* aligned , meaning that in machine operations maybe slower
>
>*VB encoding* instead is a bit more efficent and simpler at a small space cost , also if gaps are larger *VB* is better than *Gamma*

### (Elias) Delta codes $\delta$

$\delta$-*codes* encode the *lenght* in $\gamma$-code instead of *unary* while the *offsets* are encoded in the same way as *gamma codes*

>[!example] 
>$\delta$-code for $7$ is :
>+ *offset* : $7 \to 111 \to 11$
>+ *lenght* : should be $2$ that in *gamma coding* is : 
>	+ *offset* : $2 \to 10 \to 0$
>	+ *lenght* : $1$ in *unary* $10$
>	+ *total* : $10 + 0 \to 100$
>+ *total* : $100 + 11 \to 10011$

In total we will need the following space : 
$$
2 \cdot \lfloor \log L \rfloor +1
$$
Where $L = \lfloor \log G \rfloor$

#### Elias Delta vs Elias Gamma



### Huffman encoding 

The [[Information Theory#Huffman Coding|Huffman encoding]] is *efficent* if the symbol aphabet is *small* otherwise we must keep a *massive mapping tree* in memory

It's **too expensive** for the *postings list* since the alphabet is every possible $d$-gap size
## Why not using $\lfloor \log_2 G \rfloor +1$ bits

This would be simply *binary encoding* each gap and than appending it, this would not be **prefix free** , and this would imply that there are *multiple interprestations* for the same *binary string* 