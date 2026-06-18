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

## WAND Scroing

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

At 