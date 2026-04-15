---
publish: true
---
The [[Boolean Retrieval Model]]s returns a list of *matching* documents, this are not **ranked** in any way, making it difficult to search between those 

Also in general results are *too few* or *too many*
# Ranked Retrieval models 

The top results of a given query are **reordered** to reflect they'r relevance in respect to a given query 

Also the *queries* are **free text**, without operators and expressions

Since the results are ranked we dont have the problem of having *too few* or *too many* results since we just show the top $k$ results 
## Scoring

In order to retrieve a ranked order of the documents each of them must be assigned a **score** rapresent how much they *match* with a given *query*
### Jaccard Coefficent Scoring
$$J(Q,D)=\frac{|Q \cap D|}{|Q \cup D|}$$

The *jaccard* coefficent always returns a value between $1$ and $0$ , where $1$ means perfect match and $0$ otherwise 

>[!warning] 
>*Jaccard* doesn't consider the *term frequency* since text are rapresented as *sets* of words
>
>Ideally the *more frequent* a query term is in the document the *higher* the *score* should be 
### Bag of Words

In order to store the information needed to determine *term frequency* we modify the [[Incidence Matrix]] to store the number of *occurrences* of a term $t$ in a document $d$ ( $tf_{t,d}$ )

>[!example] 
>
>|           | Antony and Cleopatra | Julius Caesar | The Tempest | Hamlet | Othello | Macbeth |
>| :-------: | :------------------: | :-----------: | :---------: | :----: | :-----: | :-----: |
>|  Antony   |         157          |      73       |      0      |   0    |    0    |    1    |
>|  Brutus   |          4           |      157      |      0      |   1    |    0    |    0    |
>|  Caesar   |         232          |      227      |      0      |   2    |    1    |    1    |
>| Calpurnia |          0           |      10       |      0      |   0    |    0    |    0    |
>| Cleopatra |          57          |       0       |      0      |   0    |    0    |    0    |
>|   mercy   |          2           |       0       |      3      |   5    |    5    |    1    |

Each *column* ( eg. each *document* ) is a **count vector** ( *bag of words* )

>[!warning] 
>The *count vector* doesn't take into consideration the *ordering* of the words inside the document 

**Notation** : 
+ $t$ : generic *vocabulary term*
+ $cf_t$ : *collection frequency* , the number of occurrences of term $t$ in the *document collection*
+ $df_t$ : *document frequency*, the total number fo documents that contain $t$ in the *corpus*
+ $tf_{t,d}$ : *term frequency*, total number of occurrences of term $t$ in document $d$  

We can't use raw $tf_{t,d}$ to compute *match* **scores** since a document with $10$ occurrences of a term is *more* *relevant* than one with $1$ but **not** $10$ times more relevant
#### Log-frequency weighting 

$$
w_{t,d} = \begin{cases}
1 + \log_{10} tf_{t,d} & \text{ if } tf_{t,d} > 0 \\
0 & \text{ otherwise}
\end{cases}
$$
>[!note] 
>This smooths $tf_{t,d}$ effects 
>
>>[!example] 
>>$0 \to 0, 1 \to 1, 2 \to 1.3, 10 \to 2, 1000 \to 4$

The final **score** for a *document-query* pair will be : 
$$
Score_{qd} = \sum_{t \in q \cap d} (1 + \log tf_{t,d})
$$
