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

The **user** $u \in U$ is rapresented as the averge ot it's *items* $I_{u}$ : 
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
Cheap mode for the user #todo 

2. *Generating suggestion*

Nearest Neighbor seach is not cheap among all the collection of documents 

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
	\State Find a set of neighbors $N(u)$ of users simialr to $u$
	\State Exploit the rating of users $N(u)$ to build recommendations for $u$
	\end{algorithmic}
	\end{algorithm}
```

**User** $u$ : is a vector of size $|I|$ where : 
+ $u[i]=r$ if the user $u$ gave a rating $r$ to the item $i$
+ $u$ is the roe $R[u, :]$ of the *rating matrix*

### Similarity Measure 

We use **Pearson Correlation** , this is : 
+ *large* if both $u$ and $v$ increase / decrease similarly above / below their *mean* $\bar{u}$ and $\bar{v}$

$$
p(u,v) = \frac{cov(u,v)}{\sigma_{u} \sigma_{v}} = \frac{\sum_{i}(u[i]-\bar{u})(v[i]-\bar{v})}{\sqrt{\sum_{i}(u[i]-\bar{u})^2}\sqrt{\sum_{i}(v[i]-\bar{v})^2}}
$$
>[!example] 
[![](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d4/Correlation_examples2.svg/500px-Correlation_examples2.svg.png)](https://en.wikipedia.org/wiki/File:Correlation_examples2.svg)

## Item Based Collaborative Filtering
