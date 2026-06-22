---
publish: true
---
A raccomender system should recommend not only *popular* stuff but also niches connected to the user

**Quality measures** : 
1. Efficency in *building* the *model*
	+ How expensive is to process the data and build the recommender system
2. Efficency in *generating* *suggestions*
	+ How expensive is to produce reccomendations at run-time 
3. **Serendipity** of recommendations
	+ If recommendation novel and intresting 
4. **Cold-start** problem
	+ When we know a little about the user how do we recommend ? 
## Content Based Recommender system

>[!note] 
>Song recommender system 

Recommend the songs most similar to the user profile ( *similarity based* )

A user is the set of songs listened 
### Definitions

We need to define : 
+ The *song* ( $I$ ) *rapresentation*
>[!note] 
>This can be the lyrics

>[!warning] 
>This causes problems if there are synonyms etcc

+  The *user* ( $U$ ) *profile* 
>[!note] 
>Aggregate descriptions of listened songs ( sum \ avg )

Each **song** is modeled by theyr lyrics modeling it using the *vector-space model*

+ Each *item* $x \in I$ is a vector of size $N$
	+ $N$ is the number of words in the *lexicon*
	+ [[Document Ingestion#Stemming|Stemming]] , [[Document Ingestion#Lemmatization|Lemming]] and *stop-word* removal can be done here
+ $x[t]=tf(t,x) \cdot idf(t)$ ( [[Tf-Idf]] ) 
	+ $tf(t,x)$ : is the frequency of term $t$ in item $x$ 
	+ $idf(t)$ : is the inverse document frequency across all the *corpus* 

The **user** $u \in U$ is rapresented as the averge of it's *items* $I_{u}$ : 
$$
u = \frac{1}{|I_{u}|} \sum_{x \in I_{u}} x
$$
### Similarity Measure

Given a *user* $u$ and an *item* $x$ , theyr similarity is the **cosine** of the two vectors : 
$$
\cos(u,x) = \frac{u \cdot x}{||u||\cdot||x||} = \frac{\sum_{t} u[t] \cdot x[t]}{\sqrt{ \sum_{t} u[t]^2 } \cdot \sqrt{ \sum_{t} x[t]^2 }}
$$
>[!warning] 
>We don't use *euclidian* similarity since it considers also the *lenght* of the texts

### Efficency considerations

1. *Building the model*

Easy processing for the corpus
Cheap model for the user since it's rapresentation vector is *cheap* to keep and use for reccomendation

2. *Generating suggestion*

Nearest Neighbor search is not cheap among all the collection of documents 

3. *Serendipity*

Small , tied to text similarity 

4. *Cold-start problem*

>[!warning] 
>This approach will not work if the user has never listened to any song 

## User Based Collaborative Filtering 

An additional information is the *Rating* provided by the user 

>[!note] 
>The *rating* can be not only *explicit* but also *implicit* ( time listened etcc )

We can add a **rating matrix** $|U| \times |I|$ where each entry $R[u,i]$ stores the user feedback

Also instead of finding similar *items* , find **similar users** 

```pseudo
	\begin{algorithm}
	\caption{Algorithm sketch}
	\begin{algorithmic}
	\State Find a set of neighbors $N(u)$ of users similar to $u$
	\State Exploit the rating of users $N(u)$ to build recommendations for $u$
	\end{algorithmic}
	\end{algorithm}
```

**User** $u$ : is a vector of size $|I|$ where : 
+ $u[i]=r$ if the user $u$ gave a rating $r$ to the item $i$
+ $u$ is the row $R[u, :]$ of the *rating matrix*
### Similarity Measure 

We use **Pearson Correlation** , this is : 
+ *large* if both $u$ and $v$ increase / decrease similarly above / below their *mean* $\bar{u}$ and $\bar{v}$

$$
\rho(u,v) = \frac{cov(u,v)}{\sigma_{u} \sigma_{v}} = \frac{\sum_{i}(u[i]-\bar{u})(v[i]-\bar{v})}{\sqrt{\sum_{i}(u[i]-\bar{u})^2}\sqrt{\sum_{i}(v[i]-\bar{v})^2}}
$$
>[!example] 
[![](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d4/Correlation_examples2.svg/500px-Correlation_examples2.svg.png)](https://en.wikipedia.org/wiki/File:Correlation_examples2.svg)

>[!warning] 
>We can't use *cosine similarity* since it doesnt account for scale changes 
>
>So users that have different songs rating but with similar deltas they would result simililar when doing *cosine*  
>
>>[!example] 
>>![[SIM.excalidraw.png]]
>>%%[[SIM.excalidraw.md|🖋 Edit in Excalidraw]]%%
>>
>>+ $\cos(P,Q) =0.92$ : high similarity but it's not correct
>>+ $\rho(P,Q)=0.0$ : correct result

### Raccomendation System

In order to recommend an *item* to $u$ we want to **predict** what would it's *ranking* score $s_{u,i}$ be :

1. For each *item* $i \in I$ :
	1. Consider the *ratings* of users in $N(u)$
	2. **Weight** the *ratings* by the users similarity with $u$ :

$$
s_{u,i} = \frac{\sum_{v \in N(u)}(v[i]-\bar{v}) \cdot \rho(u,v)}{\sum_{v \in N(u)}| \rho (u,v)|} 
$$

Where : 
+ $v[i]$ is the *actual rating* neighbor $v$ has given to *item* $i$
+ $\bar{v}$ is the *average rating* $v$ gives to all items that they have rated

We divide by the sum of all the weights ( $\rho(u,v)$ ) to normilize the sum on the nominator 

2. Use $s_{u,i}$ to rank every item in $I$ and select the top-$k$ 

To predict the rating that could be given by the user $u$ we can use the following formula 
$$
r_{u,i} = \bar{u}+ s_{u,i}
$$
>[!note] 
>$\bar{u}$ is summed in order to consider the average user rating since $s_{u,i}$ rapresents the deviation in respect to theyr own *average*
### Efficency considerations

1. *Building the model*

User similarity is expensive : $O(|U|^2)$
Very expensive even if done off-line

>[!important] 
>For every new rating by a user *similarities* should be recomputed 

2. *Generating Suggestions*

Nearest neighbor search is not needed if pre-computed off-line

3. *Serendipity*

Great

4. *Cold-start problem*

>[!warning] 
>We need a sufficently large set of ratings for a new *user* / *item*

## Item Based Collaborative Filtering

This can be viewed as the *symmetric* approact to [[Recommender Systems#User Based Collaborative Filtering|User Based Collaborative Filtering]] 

+ An *item* is represented by a vector of size $|U|$ 
+ $i[u]=r$ if the *user* $u$ gave a *rating* of $r$ to the item $i$ 

**Algorithm** : 
1. Find a set $N(i)$ of other *items* **rated** by $u$ and *similar* to $i$
2. Exploit them to compute a *score* for $i$
### Similarity Measure 

>[!note] 
>In this case we don't us *Pearson Correlation* since it's more important capturing how the user behaves across items than they'r universal popularity in order to increase personalization

**Adjusted Cosine Similarity** :
$$
a\_\cos(i,j) = \frac{\sum_{u}(i[u]-\bar{u})(j[u]-\bar{u})}{\sqrt{\sum_{u}(i[u]-\bar{u})^2} \cdot \sqrt{\sum_{u}(j[u]-\bar{u})^2}}
$$
**Rating $r_{u,i}$ computation** : 
$$
r_{u,i} = \frac{\sum_{j \in N(i)} R[u,j] \cdot a\_\cos(i,j) }{\sum_{j \in N(i)} |a\_\cos(i,j)| }
$$

>[!note] 
>$R[u,j]$ is the rating given by $u$ to the neighboring *item* $j$

### Efficency consideration

1. *Building the model*

Since in general $|I|$ is smaller than $|U|$ the computation is **cheaper** than *user-based* and **offline**

2. *Generating suggestion*

We dont need *Nearest neighbor search* if we pre-compute off-line

3. *Serendipity*

Less than *user-based* since the final ranking depends on *rating* only by the **current user**

4. *Cold-Start*

>[!warning] 
>We need a sufficently large set of ratings for a new *user* / *item*

## Cold Start in Item-Based Collaborative Filtering

Ask users to rate a small number of *items*

Note that this set of *items* are equal for every user , therefore some user may not be able to provide a rating for *items* that he never encountered 

Some *techniques* to select that small number of *items* to present to the user are : 
+ **Popularity** : Propose the *most* rated items ( we have more probability that a user has seen those movies and so can give a rating )
+ **Contention** : Proposes items that are *polarizing* , so rating that are split between lowest and highest, this gives much more information regarding the user preferences
+ **Coverage** :  Proposes items that have a high numbers of *co-ratings* ( same use has rate two similar items similar ratings )
+ **GreedyExtend** : Proposes items that giving them a rating would maximaze the performance on the training set 

