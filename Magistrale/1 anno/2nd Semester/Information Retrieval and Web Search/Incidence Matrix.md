---
publish: true
---
In simple cases we can use **Term-document incidence matrix/tensor** where each document is divided using *word-based tokenization* and *ohe-hot encoding* for each word

This will give us a *matrix* where : 
+ *columns* are the **document vectors** for each document ( or a $0/1$ vector where $1$ indicate presence and $0$ not ) 
+ *rows* are the words in the *dictionary* of the *collection* of documents

>[!example]
>
>|           | Antony and Cleopatra | Julius Caesar | The Tempest | Hamlet | Othello | Macbeth |
>| :-------: | :------------------: | :-----------: | :---------: | :----: | :-----: | :-----: |
>|  Antony   |          1           |       1       |      0      |   0    |    0    |    1    |
>|  Brutus   |          1           |       1       |      0      |   1    |    0    |    0    |
>|  Caesar   |          1           |       1       |      0      |   1    |    1    |    1    |
>| Calpurnia |          0           |       1       |      0      |   0    |    0    |    0    |
>| Cleopatra |          1           |       0       |      0      |   0    |    0    |    0    |
>|   mercy   |          1           |       0       |      1      |   1    |    1    |    1    |
## Answering Queries

In order to answer any query relative to some *terms* we take the *rows* for each term and we apply the *binary* operators between them 

>[!note] 
>To perform a *NOT* we simply do the *AND* with the complement of that *vector*

>[!example] 
>*Query* : **Brutus** `AND` **Caesar** `BUT NOT` **Calpurnia** 
>becomes : **Brutus** `AND` **Caesar** `AND (NOT` **Calpurnia** `)`
>
>Now getting the *bitvector* for each query term ( the rows ) :
>+ *Brutus* : `110100`
>+ *Caesar* : `110111`
>+ `NOT` *Calpurnia* : `101111`
>
>We will have the following result : 
>```
>110100 AND
>110111 AND
>101111 =
>100100
>```
>
>Meaning that the results are *columns* $1$ and $4$ or *Antony and Cleopatra* and *Hamlet*
>
## Restrictions

For bigger collections the resulting *matrix* will be too big and sparse 

>[!note] 
>The sparse problem can be resolved by storing only the position of the $1$'s

