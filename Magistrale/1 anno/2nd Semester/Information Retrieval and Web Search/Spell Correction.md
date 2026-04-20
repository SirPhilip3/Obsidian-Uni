---
publish: true
---
Spell correction is used on both end of an *IR* system : 
+ Correcting *documents* being indexed
+ Correcting *user queries* to retrieve more relevant documents

Spell correction can have two modes : 
+ *Word sensitive* 
	+ Checks the spelling of each word regardless of the *context*
+ *Context sensitive*
	+ Checks for context ( can correct "I flew *form* Heathrow to Narita" )

# Document Correction

Useful for correcting *OCR* ( *Optical Character Recognition* ) scanned documents and web pages

>[!note] Domain-specific mistakes 
>In *OCR* some mistakes are more common : `rn -> m` or `o -> d`
>
>
# Query mis-spellings 

We have two possibilities : 
1. Retrieve document with the most likely correct spelling ( corrects the query )
2. Return suggested queries based on the most likely spelling

# Word Sensitive spell correction

>[!note] 
>A *correct lexicon* needs to exists

The *correct lexicon* can be the English Dictionary or an industry specific one 

In general we want , given a *lexicon* and a *query* `Q` return the words **closest** to `Q` from the *lexicon*

>[!note] 
>If two correct spellings have equal distance use the most common 
## Distance Meatrics

### Edit Distance

>[!important] Definition
>
>Given two strings $S_1$ and $S_2$ the *edit distance* is the *minimum number of* **operations** to convert one to the other 

**Operations** are ( character level ) : 
+ Insert
+ Delete
+ Replace
+ *Transposition* ( can be viewed as two *replace* , `ca->ac` )

The solution is found by [[Strutture Dati#Programmazione Dinamica|Dynamic Programming]] in $O(|S_1| \times |S_2|)$ 
#### Algorithm

Given $X$ and $Y$ strings of lenght respectively $n$ and $m$ 

Define $D[i,j]$ as : 
+ The *edit distance* between prefixes : $X[1..i]$ and $Y[1..j]$
+ The *edit distance* between the full $X$ and $Y$ is than $D[n,m]$ 

```pseudo
	\begin{algorithm}
	\caption{$Edit\_Distance(X,Y)$}
	\begin{algorithmic}
	\ForAll{$i$ from $0$ to $|X|$}
		\State $D(i,0) = i$ 
    \EndFor
    \ForAll{$j$ from $0$ to $|Y|$}
		\State $D(0,j) = j$ 
    \EndFor
    \ForAll{$i$ from $1$ to $|X|$}
		\ForAll{$i$ from $1$ to $|Y|$}
	        \State $D(i,j) = \min \begin{cases} D(i-1,j) +1 \\ D(i,j-1) +1 \\ D(i-1,j-1) + & \begin{cases} 2 & \text{if } X(i) \neq Y(j) \\ 0 & \text{if } X(i) = Y(j) \end{cases} \end{cases}$
        \EndFor 
    \EndFor
    \Return D(|X|,|Y|)
	\end{algorithmic}
	\end{algorithm}
```
#### Weighted Edit Distance

Since some errors are more *probable* than other ( letter closer togheter in a keybpard ) we can add a *weight matrix* 
#### Spell Checking 

Given a *misspelled word*, enumerate all the *correct* words up to a preset distance 

>[!example] 
>Enumerate all the words at distance $1,\dots$ from the *misspelled* one

We can then : 
+ Present alternatives to the user
+ Directly substitute with the most likely correction

>[!warning] 
>This means computing the distances from all the terms in the dictionary , very **expensive** 

**Optimization** : 
+ Generate everything up to a small edit distance ( $k=1,2$ ) than *intersect* these with *terms* in the *index* lexicon 
### $n$-gram overlap

1. Enumerate all the $n$-grams in the misspelled query 
2. Use the [[Tolerant Retrieval#K-Gram Index|n-gram index]] to retrieve the *lexicon* terms matching *any* of the query $n$-grams
3. Filter out terms with number of marching $n$-grams smaller than a certain *threshold*

>[!note] 
>As per [[Spell Correction#Weighted Edit Distance|Weighted Edit Distance]] we could introduce weight based no the keyboard layout etcc , to prioritize some $n$-grams in respect to others

>[!example] Trigrams Example 
>
>Query text : `december` -> `dec`, `ece`, `cem`, `emb`, `mbe`, `ber`
>Actual text : `november` -> `nov`, `ove`, `vem`, `emb`, `mbe`, `ber`
>
>The *overlapping* trigrams are $3$ , while the union of the trigrams are $9$

If the *overlap* is high enugh we than may have a misspelling 
#### Jaccard Coefficent

The *Jaccard Coefficent* allows us to measure the set overlap : 
$$
J(X,Y) = \frac{|X \cap Y|}{|X \cup Y|}
$$
This will equal to :
+ $1$ : when $X$ and $Y$ have the *same* elements
+ $0$ : when they are fully *disjointed*

We can then define a *jaccard* threshod where we declare a match ( $J \geq 0.8$ ) 

>[!note] 
>$$
>|X \cup Y| = |X| + |Y| - |X \cap Y|
>$$
# Context-sensitive spell correction 

*Initial* solution : 

1. Retrieve the top $N$ closest terms ( considering the [[Spell Correction#Edit Distance|Edit Distance]] ) to each query term 
2. Try all the possible resulting query, build from keeping one word from the original query fixed ( since we don't know the one that is actually misspelled ) and change the other with the $N$ closest terms
3. Suggest the phrase that has the most *hits* ( how many times they appear ) in the documents

---

*Another* solution : 

1. As we expand the alternative from *flew* and *form* retain only the most frequent combinations in the *query logs* ( previous query by the users )
2. Break the phrase query into conjunction of *biwords*
3. Look for *biwords* that need only **one term corrected** 
	1. keep the one *biword* with one term changed that appears more frequently in the *query logs*

## LLM based Approach

*LLM* produces the following ouput given a text : 
$$
P(\text{next\_word}, \text{previous\_language\_pattern})
$$
And so in our example we will have that :
$$
P(from |\text{I flew}) \gg P(form|\text{I flew})
$$
Since in the training texts "I flew from Heathrow" will be extreamly more *common* than "I flew form Heathrow" 

### BERT ( Bidirectional Encoder Rapresentation for Transformer )

Some *LLM* used are **BERT** that uses a technique called **Masked Language Modeling** ( *MLM* ).
In the training the model was given millions of sentences with a random word *blanked* out and forced *BERT* to guess it 

To use *BERT* as a contextual spellchecker we give it the *sentence* with hidden the *suspicious* word and let *BERT* predict it.

