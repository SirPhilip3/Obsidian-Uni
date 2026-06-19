---
publish: true
---
# TAAD ( Term-At-A-Time )

The documents scores are computed one *query term* at a time by accumulating the *per-term* $tf-idf$ weights in *per-doc* accumulators

```pseudo
	\begin{algorithm}
	\caption{CosineScore_TAAT}
	\begin{algorithmic}
	\Input query $q$
	\State float Scores[N] = 0
	\State int Lenght[N]
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

It requires more *space* since it needs to keep in memory all the intermediate scores for all the documents until the end of the algorithm 
## Efficent TAAD

We can remove the *weighting* on the query terms by doing the following **assumption** : 
+ each query term occurs only once ( $tf_{t,q}=1$ ) , with this we can see that the [[Tf-Idf#Log-frequency weighting|Log-frequency weighting]] goes to $1= 1 + \log_{10}tf_{t,q}=1+0$ 
+ $idf$ is only used for computing $wf_{t,d}$ and not $wf_{t,q}$ 

This allows us to perform only *addittive contribution* to the final score 

```pseudo
\begin{algorithm}
\caption{\textsc{FastCosineScore}(q)}
\begin{algorithmic}
\State float $Scores[N] = 0$
\ForAll{$d$}
    \State Initialize $Length[d]$ to the length of doc $d$
\EndFor
\ForAll{query terms $t$}
    \State Calculate $w_{t,q}$
    \State Fetch postings list for $t$
    \ForAll{$pair(d, tf_{t,d})$ in postings list}
        \State add $w_{t,d}$ to $Scores[d]$
    \EndFor
\EndFor
\State Read the array $Length[d]$
\For{each $d$}
    \State Divide $Scores[d]$ by $Length[d]$
\EndFor
\Return Top $K$ components of $Scores[]$
\end{algorithmic}
\end{algorithm}
```

To return the top $K$ scores we need to *reorder* the final $Scores$ array  
## TAAD Cons

1. Lots of *cache misses* due to the jumps in memory to access the accumulators
2. The *sorting* is on a huge number of accumulators ( all the docs )

>[!note] 
>We can sort less number if we consider only the *docs* with *nonzero cosines* , this will be much less than $N$ if query terms do not include stop-words 
### MaxHeap to select top $K$

Construct a *MaxHeap* for the accumulators ( takes $2J$ comparisons to build this tree )

Than to get the top $K$ scores, each score will take $\log J$

Total operations $2J + K \log J$

# DAAT ( Document-At-A-Time )

Compute the total score for a single document before proceeding the next documents

```pseudo
	\begin{algorithm}
	\caption{Document-At-A-Time Query Processing}
	\begin{algorithmic}
	\Input Query terms $Q = [t_1, t_2, \dots, t_n]$, Cutoff $k$, Sorted posting lists $PL_1, \dots, PL_n$
	\Ensure A min-heap $H$ of size $k$ containing the top-$k$ scored docIDs
	\For{$i \gets 1$ \textbf{to} $n$}
	    \State $p_i \gets 0$ \Comment{Initialize pointers for each posting list}
	\EndFor
	\State $H \gets \text{InitializeMinHeap}(k)$
	\State $\textit{threshold} \gets 0.0$
	\While{$\exists i \in [1, n]$ \textbf{such that} $p_i < \text{len}(PL_i)$}
	    \State $\textit{current\_docIDs} \gets [PL_i[p_i].\text{docID} \textbf{ for } i \in [1, n] \textbf{ if } p_i < \text{len}(PL_i)]$
	    \State $\textit{min\_docID} \gets \min(\textit{current\_docIDs})$
	    \State $\textit{score\_accumulator} \gets 0.0$
	    \For{$i \gets 1$ \textbf{to} $n$}
	        \If{$p_i < \text{len}(PL_i)$ \textbf{and} $PL_i[p_i].\text{docID} == \textit{min\_docID}$}
	            \State $\textit{score\_accumulator} \gets \textit{score\_accumulator} + PL_i[p_i].\text{weight}$
	            \State $p_i \gets p_i + 1$ \Comment{Advance the posting list pointer}
	        \EndIf
	    \EndFor
	    \If{$\text{len}(H) < k$ \textbf{or} $\textit{score\_accumulator} > \textit{threshold}$}
	        \State $\textit{threshold} \gets H.\text{add}(\textit{min\_docID}, \textit{score\_accumulator})$ \Comment{Updates heap and threshold}
	    \EndIf
	\EndWhile
	\State \Return $H$
	\end{algorithmic}
	\end{algorithm}
```

In **DAAT** we use a *MIN-heap* of $k$ elements : 

1. Processing a new documents $d'$ with score $s'$ :
	1. Get the current minimum of the heap $h_{m}$ ( $O(1)$ )
	2. If $s'\leq h_{m}$ skip to the next document 
	3. If $s' > h_{m}$ delete the root of the min-heap ( $O(\log k)$ )
	4. Heap-add $s':d'$ ( $O(\log k)$ )

>[!example] 
>#todo

## WAND Scoring

1. We maintain a running *threshold* score :
	The $K^{th}$ highest score computed so far ( them minimum score in the min-heap )

2. We *prune* away all docs whose cosine scores are *guaranteed* to be *below* the current *threshold*

3. Compute the exact cosine scores only for the un-pruned docs

>[!warning] 
>In the first pruning we can't remove false negatives 

### Implementation

The *postings* must be ordered by docID

We have pointers at some docID in the posting lists of each query term 

>[!note] 
>Each pointer move only to larger docIDs

**Invariant** :
+ All docIDs lower than any finger have already been processed ( pruned or computed the similarities )

Each *posting list* for term $t$ we maintain an **upper bound** $UB_{t}$ on the score contribution of any documents in the list 

Where $UB_{t} = idf_{t} \cdot M$ , with $M = \max w_{t,d}$ for all $d$ in the posting list of $t$

>[!note] 
>$UB$ rapresents the maximum score that a term can reach 

The **threshold** $\tau$ is set to the *minimum score* of the heap , when a document enters the *min-heap* the **threshold** grows

#### Pivoting

The **pivot** is the the *minimum cursor* ( practically the minimum docID ) for which the comulative sum of the **Upper Bounds** of the lower docIDs is lower than the current *threshold*  

>[!note] 
>The docIDs must be ordered 

>[!example] 
>![[Pivoting.excalidraw.png]]
>%%[[Pivoting.excalidraw.md|🖋 Edit in Excalidraw]]%%
>
>We than move the pointer to the first docID that is *Greather Than Equal* to $589$ ( *nextGEQ* implemented as in [[Inverted Index#AND with `nextGEQ`|Boolean Retrieval Model]]
>
>**If** $589$ is present in all the three postings :
>+ Compute its actual cosine score ( it may be a *false positive* )

>[!note] 
>*WAND* is a *safe ranking* since it keeps also false positives

## Block-Max

In *WAND* we use the maximum *impact score* to filter the posting lists leading to lots of *false positive* 
For *Block-Max* we use an augmented *inverted index* ( *block-max index* ) , this stores the *maximum* "*impact score*" for each **block** of a compressed inverted list in uncompressed form 

1. Split the inverted lists into blocks of $64,128$ docID's
2. Store for each compressed block :
	1. The *maximum* and *minimum* docID
	2. *Maximum impact value* for each **block** 
	3. The *block size*

>[!note] 
>*nextGEQ* needs to be implemented to avoid decompressing blocks 

# Unsafe Ranking

The result *approximates* the true top-$K$ , possibbly containig *false positieves*

>[!note] 
>Acceptable since the ranking functions are already proxies for user happiness

## Unsafe DAAT

Uses a more *aggressive* *pruning*, uses threshold $\tau' = F \cdot \tau$ where $F \ge 1$ is a *tunable parameter*

Only consider :
+ docs containinig *at least one query term* 
+ **high-idf** query terms ( remove semi-stopwords )
	+ removing *low-idf* terms have long postings list meaning that removing it will decrease the overall complexity of the algorithm
+ docs containing **many** query terms 

## Champion Lists

*Precompute* for each dictionary term $t$ the $r$ *docs* of *highest weight* in $t$'s postings ( *champion list* )

At query time only compute scores for docs that are in the *champions list* of some query term and pick the top-$K$ document scores from these

>[!note] 
>$r$ must be chosen at *index building time* , also this can be different for various terms , for *rare* terms $r$ cuold include most of its posting list

# Static quality scores

We want top-ranking documents to be both *relevant* and **authoritative** 

*Authority* is a *query-independent* property of a document 

>[!example] Example of Authority signals 
>1. Wikipedia
>2. Newspapers
>3. A scientific paper with many citations
>4. [[PageRank]]

Assigned as $g(d)$ $[0,1]$ to each document $d$ 

## Net Score

We combine *cosine relevance* and *authority* in :
$$
\text{net-score}(q,d) = g(d)+cosine(q,d)
$$
>[!note] 
>We can use some other linear combination

We now use this *net-score* to filter the top-$K$ documents

### Top-$K$ by net-score

#todo 

1. Order all postings by $g(d)$ 

