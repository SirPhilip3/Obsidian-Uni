---
publish: true
---
# Relevance

Relevance should be measured against the actual user *information need* not the queries to judge user happiness

>[!note] 
>Information need is the information that the user is looking for 

*Vocabulary mismatch problem* : if we search for exact words we may miss text that contain synonims

## Interactive Relevance Feedback 

Improve the initial retrieved result by telling the *IR* system which docs are **relevant** / **nonrelevant** 

1. User submit a query
2. *SE* returns some documents
3. User marks some docs as *relevant* other as *nonrelevant*
4. *SE* creates a new query whith this information
### Rocchio Algorithm

*Rocchio* aims to choose an artificial query maximizing :
$$
\vec{q}_{opt} = \arg \max_{\vec{q}} [ sim(\vec{q}, \mu(D_{r})) - sim(\vec{q}, \mu(D_{nr})) ]
$$
+ $D_{r}$ is the set of known *relevant* docs
+ $D_{nr}$ is the set of known *nonrelevant* docs

>[!note] Goal
>**Maximize** *similarity* with *relevant* documents while **minimizing** *similarity* with *nonrelevant* ones

$\mu$ is the centroid of a set of documents : 
$$
\vec{\mu}(D) = \frac{1}{|D|} \sum_{d \in D} \vec{v}(d)
$$
>[!note] 
>$\vec{v}(d) = \vec{d}$ is the *normalized vector* used to rapresent each document in $D$

Under *cosine similarity* if we know $D_{r}$ and $D_{nr}$ , $\vec{q}$ can be rapresented as vector difference between two centroids : 
$$
\vec{q}_{opt} = \frac{1}{|D_{r}|} \sum_{\vec{d}_{j} \in D_{r}} \vec{d_{j}} - \frac{1}{|D_{nr}|} \sum_{\vec{d}_{j} \in D_{nr}} \vec{d_{j}} 
$$
>[!warning] 
>$D_{r}$ is **unknown**

### Rocchio SMART

$$
\vec{q}_{m} = \alpha\vec{q}_{0} + \beta \mu(C_{r}) - \gamma \mu(C_{nr}) = \alpha\vec{q}_{0}+ \beta\frac{1}{|C_{r}|} \sum_{\vec{d}_{j} \in C_{r}} \vec{d_{j}} - \gamma\frac{1}{|C_{nr}|} \sum_{\vec{d}_{j} \in C_{nr}} \vec{d_{j}} 
$$
Where : 
+ $C_{r}$ : is the set of **known** *relevant* document vectors
+ $C_{nr}$ : is the set of **known** *nonrelevant* document vectors
+ $q_{m}$ : is the *modified* **query** vector
+ $q_{0}$ : is the *original* **query** vector
+ $\alpha, \beta,\gamma$ are hand chosen *weight*

>[!note] 
>Since *positive feedback* is more valuable than negatie feedback we can set $\beta = 0.75$ and $\gamma = 0.25$ to weight more positive feedback


>[!warning] 
>+ It's *expensive* since it creates *long* modified queries, more expensive to process
>+ Users are *reluctant* to provide explicit feedback

### Psuedo-relevance feedback

1. Retrieve a ranked list of hits from a user query
2. Assume that the top-$k$ documents are *relevant* 
3. Apply relevance feedback to this

>[!warning] 
>It can cause *query drift* if we perform several iteration of pseudo-relevance feedback
# Query espansion

Improve the retrieved result by adding synonyms and related terms to the query 

The main source of query expansion are the *query logs* :

>[!example] 
>1. After issuiing the query *herbs* users frequently search *herbal remedies* meaning that this may be a potential expantion for *herbs* ( **user session analysis** )
>2. User searching for *flower pix* clicked URL1 and also user searching *flower clipart* click on the same URL meaning that *flower clipart* and *flower pix* may be potential expansions ( **co-clicks** )

## Global Query expansion

The *query* is *expanded* based on some resource that is *not query-dependent*  

We use (*near*-)*synonyms* , a database that collects those is called a **thesaurus**
+ Manual thesaurus 
+ Automatically driven thesaurus ( based on co-occurence statistics etcc ) *WorldNet* 
### Thesaurus-based query expansion

For each *term* $t$ in the query, expand the query with words that the thesaurus lists as semantically related

It generally *increases* [[Evaluation#Precision and Recall|Recall]] but can *decrease* **Precision** with ambiguous terms
#### Automatic thesaurus generation 

We use *similarity* between words , this can have various definitions : 
1. Two words are similar if they *co-occur* *with* *similar words* 

>[!example]
>Car is similar to motorcycle since htey both occur near the words : road, gas, license

2. Two words are similar if the occur in a given *grammatical relation* with the same words 

>[!example] 
>We can "harvest", "peel", "eat" *apples* and *pears*, *apples* and *pears* must be similar
>

##### Co-occurrence Thesaurus

A thesaurus based on *term-term* similairities can be computed starting from the *term-doc* incidence matrix $A$ by doing the *dot-product* with it's transposed : $A A^T$  

##### Distributional semantics

Keep the *context* of a given word $w$ ( the words thata appear nearby within a fixed-size window )

For each word $w$ we can than create a vector based on the *context* of that word $w$ ( **emebeddings** ) , we can compute similarity as the *dot product* between words

### Word2Vec for Query Expansion

Related terms to a query are obtained by the *K-nearest-neighbour* with respect to the *term-vector similarity* 

>[!example] 
>+ *Query* : $q=\{t_{1},\dots,t_{m}\}$ 
>+ Candidate terms : $C=\cup_{t\in q} kNN(t)$
>+ Calculate similarities with respect to the query : $AvgSim(t,q)= \frac{1}{|q|}\sum_{t_{i}\in q} \cos ine(t,t_{i})$
>+ We select the top $K$ candidate terms as expansion terms

