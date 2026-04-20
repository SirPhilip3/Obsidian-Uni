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
+ $df_t$ : *document frequency*, the total number of documents that contain $t$ in the *corpus*
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
#### $idf$ weight

>[!important] 
>**Rare terms** carry *more information* than frequent terms , in fact a document containing a rare term present in the query is very likely to be relevant to that query 

To capture this we use $df_t$ :
+ globally *rare* terms will have *small* $df_t$
+ globally *frequent* terms will have *high* $df_t$ 

This an the *inverse* measure of the *informativeness* of a term $t$ 

Define $idf$ ( *Inverse Document Frequency* ) of $t$ as :
$$
idf_t = \log_{10} (N/df_t)
$$
Where $N$ is the number of documents in the collection 

>[!note] 
>The $idf$ value does not change for different documents since it depends only on the occurrences of term $t$ in the corpus  

>[!example] 
>
>| term      | $df_t$  | $idf_t$ |
>| --------- | ------- | ------- |
>| calpurnia | 1       | 6       |
>| animal    | 100     | 4       |
>| under     | 100000  | 1       |
>| the       | 1000000 | 0       |

>[!warning] 
>$idf$ *can't rank* *one-term queries* since all the documents retrieved will have the same score since it depends only on the occurences of that term in the corpus and not on the documents 
>

$idf$ can rank query with *at least two terms* only if some docs to be ranked do not contain all query terms , in this case the occurrences of rare terms contribute more to the final rankings in respecto to more common words

#### $tf\textendash idf$ weighting

+ Terms that appear *often* in a document ( $tf$ ) should get *high weights* 
+ Terms that appear in *many* documents ( $df$ ) should get *low weights*

The $tf\textendash idf$ ( or $wf\textendash idf$ ) *weight* is the product of its $tf$ weight ( normalized $wf$ ) and its $idf$ weight :
$$
wf\textendash idf_{t,d} = wf_{t,d} \times idf_t
$$
The *score* for a *document-query* pair will be :
$$
Score(q,d) = \sum_{t\in q\cap d} wf\text{-}idf_{t,d}
$$
>[!note] 
>There are variants based on the usage of *logarithmic* normalization , discretization etcc 
>

>[!example] 
>#todo

# Vector Retrieval Systems 

Each document is now rapresented by a real-valued vector of $tf\text{-}idf$ *weights* $\in \mathbb{R}^{|V|}$ 

>[!note] 
>$V$ is the *vocabulary* of the collection 

These *vectros* are **very sparse** and very **high dimesional** 
## Queries

1. Transform the *queries* in vectors
2. Rank the documents according to their proximity to the query 
### Proximity 

#### Euclidian Distance 
$$
d(p,q) = \sqrt{\sum^{n}_{i=1} (q_i - p_i)^2}
$$
>[!error] 
>*Euclidian distance* is bad 
>>[!example] 
>>
>>Take document $d$ , append it to himself , creating $d'$ 
>>This than have the same semantic content but their *euclidian distance* becomes large even though the overlap each other
>>
>>
#### Angle

Instead of using *distance* we use the *angle* between the query and document to determine their similarities 

In fact in the previous example the *angle* remains the same 

We can use equivalently also the **cosine** of the angle as an index of similarity 

+ Rank documents in **decreasing** order of the *angle* betwen the query and document
+ Rank documents in **increasing** order of *cosine* of the angle

The *cosine* of the angle can be calculated easily in the following way : 
$$
\cos(\theta) = \frac{A \cdot B}{||A|| \times ||B||}
$$
>[!note]- Info
>
>This comes from the *geometric definition* of **dot product**
>$$
>A \cdot B = ||A||\times ||B|| \times \cos(\theta)
>$$
>

This can also be seen as : 
$$
\cos(\theta) = \frac{A}{||A||} \cdot \frac{B}{||B||}
$$
Or the *dot product* of the two *length-normalized* vectors becoming unit vectors

We can decline this to our $tf\text{-}idf$ *weight* vectors : 
$$
\cos(\vec{q},\vec{d}) = \frac{\vec{q}\cdot \vec{d}}{|\vec{q}||\vec{d}|} = \frac{\vec{q}}{|\vec{q}|} \cdot \frac{\vec{d}}{|\vec{d}|} = \frac{\sum^{|V|}_{i=1} q_i d_i}{\sqrt{\sum^{|V|}_{i=1} q_i^2} \sqrt{\sum^{|V|}_{i=1} d_i^2}}
$$
Where $q_i$ and $d_i$ are the $tf\text{-}idf$ *weight* of the term $i$ in the *query* and *documents*
##### Term-at-a-time ( TAAT )

Computing the *cosine scores* :

```pseudo
	\begin{algorithm}
	\caption{CosineScore(q)}
	\begin{algorithmic}
	\State float Scores[N] = 0
	\State float Lenght[N]
	\ForAll{query term $t$}
		\State Calculate $w_{t,q}$
		\State Fetch postings list for $t$
		\ForAll{$pair(d,tf_{t,d})$ in postings list}
			\State Scores[d] += $w_{t,d}\times w_{t,q}$
        \EndFor
        \State Read the array Length
    \EndFor
    \ForAll{d}
	    \State Scores[d] = Scores[d] / Length[d]
    \EndFor
    \Return Top K components of Scores[]
	\end{algorithmic}
	\end{algorithm}
```

## Weighting notation

Since we have various form of *weighting* in the formulation of the *rank* we use **SMART** notation to rapresent what types of *formula* we use :
$$
ddd.qqq
$$
Where each of them declares a mode to use for each different measure ( $d$ for documents and $q$ for query ) :
+ The first character for *term frequency*
+ The second character for *document frequency*
+ The third character for *normalization*

>[!example] 
>$lnc.ltc$
>
>*Document* : 
>+ logarithmic $tf$
>+ no $idf$
>+ cosine normalization
>
>*Query* : 
>+ logarithmic $tf$
>+ $idf$
>+ cosine normalization
>
# BM25 (Best Match 25)

**BM25** is a *probabilistic* ranking function better than *cosine*

It uses the **term independence** assumption : 
	Every word in a document is idipendent from one another
To approximate the document probability of being relevant 

$$
BM25(d,q) = \sum_{t \in q \cap d} IDF_t\ \tau(F_t)
$$
Where : 
$$
F_t = \frac{tf_{t,d}}{1-b+b \cdot l_d /L}
$$
+ $tf_{t,d}$ : is the *term frequency*
+ $l_d$ : *length* of *document* $d$ ( longher documents are less important )
+ $L$ : *average* document *lenght* in the collection
+ $b$ : determines the importance of $l_d$

$b > 0$ : means that we penalize long documents because they have a better probaboloty to match query terms  

$$
\tau (F_t) = \frac{F_t}{k +F_t}
$$
$\tau$ is a *saturation function* modeling **non-linearity** of the *term frequency* distribution :
+ For high values of $F_t$ increments in *term frequency* don't contribute significantly to the final score

>[!important] 
>$b$ and $k$ are **hyper parameter** and should be tuned depending on the collection , tipically $b=0.75$ and $k\in[1.2,2.0]$

