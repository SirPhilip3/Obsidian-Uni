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
**Recall** : fraction of relevant docs that are retrieved ( $\mathbb{P}(\text{relevant retrieved}|\text{relevant})$ )
$$
R = \frac{\text{retrieved and relevant docs}}{(\text{retrieved and relevant docs} + \text{relevant but not retrieved docs})}
$$
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

