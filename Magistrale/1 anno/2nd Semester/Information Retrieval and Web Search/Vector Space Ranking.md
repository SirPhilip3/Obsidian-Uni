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

It requires more *space* since it needs to keep in memory all the intermediate scores for all the documents until the end of the algorithm 

## Efficent TAAD

We can remove the *weighting* on the query terms by doing the following **assumption** : 
+ each query term occurs only once ( $tf_{t,q}=1$ ) , with this we can see that the [[Tf-Idf#Log-frequency weighting|Log-frequency weighting]] goes to $1= 1 + \log_{10}tf_{t,q}=1+0$ 
+ $idf$ is only used for computing $wf_{t,d}$ and not $wf_{t,q}$ 

This allows us to perform only *addittive contribution* to the final score 
# DAAT ( Document-At-A-Time )

Compute the total score for a single document before proceeding the next documents

```pseudo
	\begin{algorithm}
	\caption{Term-At-A-Time Query Processing}
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