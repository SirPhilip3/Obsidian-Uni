---
publish: true
---
**Quality** of a search engine : 
+ What results get clicked a lot 
+ If the user buys a product after clicking
+ Repeated visitors / buyers
+ Dwell time ( how much time the user stayed on the page )

This is **difficult** to measure, we use *relevance* of search results

# Measuring relevance

We need $3$ elements :
+ A benchmark document collection
+ Some benchmark queries 
+ An assessment of *relevant* or *nonrelevant* for each query and document pair

The *relevance judgments* can be **crowd sourced** 

>[!warning] 
>The variance in the judgments can be very high depending on the biases

The **test queries** :
+ must be suitable to the available docs
+ mast represent actual user queries
+ can be a *sample of actual user queries* ( if available )

>[!note] 
>In non web system queries can be crafted manually 

>[!note]- TREC
>Conference on IR techonlogy large scale testing
>
>A user information needs is called a *topic*

## Evaluation Measures

### Unranked Measures 

	#### Precision and Recall 

**Precision** : fraction of retrieved docs that are relevant ( $\mathbb{P}(\text{relevant retrieved}|\text{retrieved})$ )
$$
P = \frac{\text{retrieved and relevant docs}}{(\text{retrieved and relevant docs} + \text{retrieved but not relevant docs})}
$$
>[!note] 
>$P@k$ is *precision* limited to the first $k$ documents retrieved

**Recall** : fraction of relevant docs that are retrieved ( $\mathbb{P}(\text{relevant retrieved}|\text{relevant})$ )
$$
R = \frac{\text{retrieved and relevant docs}}{(\text{retrieved and relevant docs} + \text{relevant but not retrieved docs})}
$$

>[!note] 
>$R@k$ is *recall* limited to the first $k$ documents retrieved

#### F-Measure or F-Score

The **F-Measure** is the *harmonic mean* of [[#Precision and Recall]] : 
$$
F = \frac{1}{0.5 \frac{1}{P} + 0.5 \frac{1}{R}} = 2\frac{PR}{P+R}
$$
>[!note] 
>The *harmonic mean* is always $\le$ to the *arithmetic* and *geometric mean*
>
>When the two values are very different the *harmonic mean* is closer to their *minimum* than the *arithmetic mean*

We can give **weights** $\alpha$ to $P$ and $(1-\alpha)$ to $R$ 

With $\alpha = \frac{1}{(1+\beta^2)}$ we have :
$$
F_{\beta} = \frac{1}{\alpha \frac{1}{P} + (1-\alpha)\frac{1}{R}} = (\beta^2 +1)\frac{PR}{\beta^2P +R}
$$

For values of $\beta$ :
+ $<1$ : Puts more weight on *Precision* 
	+ use this when false positives are highly costly
+ $=1$ : Gives equal importance to precision and recall
+ $>1$ : Puts more weight on *Recall*
	+ use this when false negative are dangerous

### Ranked Measures

#### Precision-recall curve

Calculate *Precision* and *Recall* while varying $k$ ( number of retrieved documents )

>[!example] 
>![[Precision-recall-plot.excalidraw.png]]
%%[[Precision-recall-plot.excalidraw.md|🖋 Edit in Excalidraw]]%%

>[!note] 
>In order to have a *Precision* value for each possible *Recall* value we need to build an **interpolated precision** function defined as the *highest precision* found for *any recall level* $r' \ge r$ :
>$$
>p_{interp}(r) = \max_{r' \ge r} p(r')
>$$ 

We can get the *averaged precision-recall curve* by averaging the *interpolated precision* across multiple queries 

#### Mean Average Precision (MAP)

*AP* ( *average precision* ) is : 
$$
\frac{1}{G} \sum_{k=1}^n P(k) \times rel(k)
$$
Where : 
+ $G$ : the total number of actual relevant documents
+ $n$ : total number of retrieved documenst
+ $P(k)$ : the *precision* *at rank* $k$ 
+ $rel(k)$ : is a binary indicator that is : 
	+ $1$ if the document at rank $k$ is *relevant*
	+ $0$ otherwise

>[!example] 
>Having the relevant documents as in the previous example we get *AP* : 
>
>$$
>\frac{1}{3}\left( \frac{1}{1} + \frac{2}{3} + \frac{3}{5} \right) \approx 0.76
>$$

**Mean Average Precision** is the *mean AP* across multiple queries

Let $R_{j} = \{d_{1}, \dots, d_{mj}\}$ be the set of *relevant* documents for a *query* $q_{j} \in Q$
Let $R_{jk}$ be the set of results from the top until document $d_{k}$ 

Then *MAP* over the query set $Q$ : 
$$
MAP(Q) = \frac{1}{|Q|} \sum_{j=1}^{|Q|} \frac{1}{m_{j}} \sum^{m_{j}}_{k=1} Precision(R_{jk}) = \frac{1}{|Q|} \sum_{j=1}^{|Q|} AP(q_{j})
$$
>[!note] 
>Each *query* counts equally 
>
>$MAP@k$ is *MAP* but evaluated until the *cut-off rank* $k$ arbitrarily chosen

#### Mean Reciprocal Rank (MRR)

Suppose that there is only one *Relevant Document* 

Search durantion for a user is linked to the rank of the correct answer :
+ The higher the rank the faster the search is 
+ The lower the rank the slower the search gets 

*MRR* measure the *user effort* to find a result

Consider rank position $rank_{i}$ of the first relevant foc return for query $q_{i} \in Q$ 

Than the *Reciprocal Rank* ( *RR* ) score is : 
$$\frac{1}{rank_{i}}$$
*Mean Reciprocal Ranks* is the *mean* of *RR* across multiple queries :
$$
MRR = \frac{1}{|Q|} \sum^{|Q|}_{i=1} \frac{1}{rank_{i}}
$$
### Beyond Binary Relevance

#### Discounted Comulative Gain

Relevance is no more binary but we can have *high* and *low* *relevance* documents

>[!note] 
>The lower the ranked position of a relevant document is the less useful it is to the user since it most likely will not be examined by the user

Uses *graded relevance* or **gain** as a measure of usefulness 

**Gain** is accumulated starting from the top of the ranking and may be reduced or *discounted* at *lower ranks* 

Typical discount is $\frac{1}{\log(rank)}$ 

>[!note] 
>We can use different bases for the *log*

The *Comulative Gain* ( *CG* ) at rank $n$ is :
$$
CG = r_{1} + r_{2} + \dots + r_{n}
$$
Where $r_{1}, r_{2},\dots,r_{n}$ are the *relevance* judgements of each document 

**Discounted Comulative Gain** ( *DCG* ) at rank $n$ :
$$
DCG_{p} = r_{1} +\frac{r_{2}}{\log_{2} 2}  +\frac{r_{3}}{\log_{2} 3} + \dots +\frac{r_{n}}{\log_{2} n} = rel_{1} + \sum_{i=2}^p \frac{rel_{i}}{\log_{2}i}
$$
>[!note] 
>The gain is discounted only for relevant documents at ranks $>1$

Alternative formulation where high relevance judgments become more important :
$$
DCG_{p} = \sum_{i=1}^p \frac{2^{rel_{i}} -1}{\log(1+i)}
$$
>[!note] 
>This work best with non binary relevance

>[!example] 
>#todo

#### Normalized Discounted Comulative Gain (NDCG)

*Normalize DCG* at rank $n$ by the *DCG* value at that rank of the *ideal ranking*

Where *ideal ranking* is the ranking that would return first documents with the highest relevance level going lower and lower

>[!note] 
>Normalizing is useful for contrasting queries with varying numbers of relevant results


>[!example] 
>*Perfect ranking* : $3,3,3,2,2,2,1,0,0,0$
>*ideal* DCG values : $3,6,7.89,8.89,9.75,10.52,10.88,10.88,10.88,10.88$ 
>
>*Actual ranks* : $3,2,3,0,0,1,2,2,3,0$
>*actual* DCG : $3,5,6.89,6.89,6.89,7.28,7.99,8.66,9.61,9.61$
>
>*NDCG* values ( divide *actual* DCG by the *ideal* DCG ) :
>$$
>1,0.83,0.87,0.76,0.71,0.69,0.73,0.8,0.88,0.88
>$$

>[!note] 
>*NDCG* $\le 1$ at any rank position

### User clicks

Human judgments are expensive and inconsistent ( also a lot may be bots )

Given a set of *pairwise refrences* $P$ ( ground truth , *baseline* ranking ) 

We want to confront two rankings $A$ and $B$ , we define a *proximity* measure betweem $A,B$ and $P$ , declaring the winner as the *ranking* with *better proximity* 
#### Kendall's Tau $\tau$

Let :
+ $X$ be the number of *agreements* between a ranking and $P$ 
+ $Y$ be the number of *disagreements* between a ranking and $P$

*Kendall tau* between $A$ and $P$ will be : 
$$
\tau = \frac{X-Y}{X+Y}
$$
$-1\le \tau \le 1$ : 
+ $1$ : is *perfect agreement*
+ $-1$ : is perfect *disagreement*
+ $0$ : $X$ and $Y$ are *independent*

>[!example] 
>#todo
#### A/B testing

Given two rankings $A$ and $B$ :
1. *interlieve* them ( the start ranking doesnt matter ) 
2. *remove duplicates* 
3. Count user clicks per rank by presenting interlieved *ranking* ( randomly start from $A$ and than $B$ )

The better ranking should get more average clicks

>[!example] 
>#todo
>

