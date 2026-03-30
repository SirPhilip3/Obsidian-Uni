---
publish: true
---
For each term *t* we store the list of all the documents ( *docID* ) that contain term *t* 

>[!note] 
>Sorted by *docID*, *postings* are the *docID* associated with one word 

All the term toghether form the *dictionary*

![[inverted_index.excalidraw.png]]
%%[[inverted_index.excalidraw.md|🖋 Edit in Excalidraw]]%%
## Storage 

On *disk* : we just store a continuos data structure of *postings* adding indexes for the start of each list 

On *memory* we can use *linked lists* or *variable-lenght* array 
## Construction

The process of building an *inverted index* follows the following path : 
1. Collect the document to be indexed
2. *Tokenize* them via a *tokenizer*
3. Modify the *tokens* with some *linguistic models* 
4. Build the *index*
### Tokenizer

A simple tokenizer will split each document into *word tokens* , so we identify some splitting character that let's us differentiate them ( for example the space )
### Linguistic models

Some linguistic models can contain :
+ *Normalization*
	We map the input text and the query text to the same "form" ( for example we want U.S.A. and USA to match )
	Transform all the words to lowercase 
+ *Stemming*
	We may normalize some words to common *prefixes* , for example authorize and autorization reduced to the common prefix authoriz
+ *Stop Words*
	We may omit common words ( the, a, to, of )

### Building the index

After the *normalization* step , we associate each term to it's corresponding *docID* forming a sequence of pairs : $(Term, DocID)$ 

>[!example] 
>
>| Term    | docID   |
>| ------- | ------- |
>| I       | 1       |
>| did     | 1       |
>| enact   | 1       |
>| julius  | 1       |
>| so      | 2       |
>| let     | 2       |
>| it      | 2       |
>| $\dots$ | $\dots$ |

Now we sort them by *terms* and than by *docID* if the sorting algorithm is not stable

>[!example] 
>
>| Term      | docID   |
| --------- | ------- |
| ambitious | 2       |
| be        | 2       |
| brutus    | 1       |
| brutus    | 2       |
| caesar    | 1       |
| caesar    | 2       |
| caesar    | 2       |
| $\dots$   | $\dots$ |

Now we can just compress it in the *postings lists* ( also adding the document frequency for each term )

>[!example] 
>![[inverted_inde.excalidraw.png]]
>%%[[inverted_inde.excalidraw.md|🖋 Edit in Excalidraw]]%%

## Processing Queries

### AND

If we need to process the following query : `X AND Y` we do the following : 
1. Locate `X` and `Y` in the *dictionary* and its corresponding *posting list* 
2. **Merge** the two postings by intersecting the two sets

The merge can be done by *walking* through the two postings simultaneously 

```pseudo
	\begin{algorithm}
	\caption{Intersect($p_1,p_2$)}
	\begin{algorithmic}
	\State $answer \leftarrow \langle \rangle$
	\While{$p_1 \neq NIL$ and $p_2 \neq NIL$}
		\If{$docID(p_1) = docID(p_2)$}
			\State ADD(answer,docID($p_1$))
			\State $p_1 \leftarrow next(p_1)$
			\State $p_2 \leftarrow next(p_2)$
        \Elif{$docID(p_1) < docID(p_2)$}
	        \State $p_1 \leftarrow next(p_1)$
        \Else 
	        \State $p_2 \leftarrow next(p_2)$
        \EndIf
    \EndWhile
    \Return $answer$
	\end{algorithmic}
	\end{algorithm}
```

>[!note] 
>The time complexity, in the worst case, is $O(x + y)$ with $x$ and $y$ the lenght of the two *posting list*

The output size of the intersection in the *worst case* is $\min(x,y)$ 
### AND with `nextGEQ`

`nextGEQ(p1,p2[j])` returns the pointer to the *first docID* in the list `p1` which is ***G**reater than or **EQ**ual* to `p2[j]`

This can be realized using **Binary Search** but in practice we use *skip pointers*

```pseudo
	\begin{algorithm}
	\caption{Intersect($p_1,p_2$)}
	\begin{algorithmic}
	\State $answer \leftarrow \langle \rangle$
	\While{$p_1 \neq NIL$ and $p_2 \neq NIL$}
		\If{$docID(p_1) = docID(p_2)$}
			\State ADD(answer,docID($p_1$))
			\State $p_1 \leftarrow next(p_1)$
			\State $p_2 \leftarrow next(p_2)$
        \Elif{$docID(p_1) < docID(p_2)$}
	        \State $p_1 \leftarrow \textcolor{orange}{nextGEQ}(p_1,p_2)$
        \Else 
	        \State $p_2 \leftarrow \textcolor{orange}{nextGEQ}(p_2,p_1)$
        \EndIf
    \EndWhile
    \Return $answer$
	\end{algorithmic}
	\end{algorithm}
```

>[!example] 
>![[nextGEQ.excalidraw.png]]
%%[[nextGEQ.excalidraw.md|🖋 Edit in Excalidraw]]%%

#### Postings with Skip pointers

We can add some pointers, at indexing time, in the *postings* in order to be able to skip blocks of *postings* that will surely noy contain the search result for an *AND* query 

>[!example] 
>![[skip_list.excalidraw.png]]
%%[[skip_list.excalidraw.md|🖋 Edit in Excalidraw]]%%
>
>Suppose that we have processed the two list until $8$, now advancing we have $41$ and $11$ and since $11$ is the smallest we advance the *second pointer* 
>
>But since the *skip pointer* on the second list is still lower than $41$ ( $31$ ) we can directly skip to $31$ skipping the block $\{17,21,31\}$

#todo pseudocode
##### Where to place the Skips

In general we have the following *tradeoffs* : 
+ *More* skips means that if we take one we will skip *shorter spans* but we are also *more likely* to skip
+ *Fewer* skips means that we skip *longher spans* if we take it but also *less successfull* skips

**Heuristic** : for *postings* of lenght $L$ we use $\sqrt{L}$ evenly spaced skip pointers 

>[!note] 
>+ This method ignores the distribution of the query terms
>+ Easy for *static* indexes
>

### OR

The result of *OR* is simply given by performing the set union of two postings lists

```pseudo
	\begin{algorithm}
	\caption{Union($p_1,p_2$)}
	\begin{algorithmic}
	\State $answer \leftarrow \langle \rangle$
	\While{$p_1 \neq NIL$ and $p_2 \neq NIL$}
		\If{$docID(p_1) = docID(p_2)$}
			\State ADD(answer,docID($p_1$))
			\State $p_1 \leftarrow next(p_1)$
			\State $p_2 \leftarrow next(p_2)$
        \Elif{$docID(p_1) < docID(p_2)$}
	        \State ADD(answer,docID($p_1$))
	        \State $p_1 \leftarrow next(p_1)$
        \Else 
	        \State ADD(answer,docID($p_2$))
	        \State $p_2 \leftarrow next(p_2)$
        \EndIf
    \EndWhile
    \If{$p_1 = NIL \land p_2 \neq NIL$}
	    \State EXTEND(answer,$p_2$)
    \EndIf
    \If{$p_2 = NIL \land p_1 \neq NIL$}
	    \State EXTEND(answer,$p_1$)
    \EndIf
    \Return $answer$
	\end{algorithmic}
	\end{algorithm}
```

>[!note] Space and Time complexity
>Since we need to scan the two lists completely we will have a *time* complexity of $O(x+y)$
>
>The *space* complexity instead , in the worst case is $x+y$ (the two sets are fully disjointed)
>

>[!important] 
>We can't use [[Inverted Index#AND with `nextGEQ`|nextGEQ]] or [[Inverted Index#Postings with Skip pointers|skip pointers]] in the *OR* operation

## Query Optimization

We can optimize queries like : 
+ `X AND (NOT Y)`
+ `X OR (NOT Y)`
### X AND (NOT Y)

```pseudo
	\begin{algorithm}
	\caption{$Intersect_not_second(p_1, p_2)$}
	\begin{algorithmic}
	\State $answer \leftarrow \langle \rangle$
	\While{$p_1 \neq NIL$ and $p_2 \neq NIL$}
		\If{$docID(p_1) = docID(p_2)$}
			\Comment{$p_1$ is also included in $p_2$, skip}
			\State $p_1 \leftarrow next(p_1)$
			\State $p_2 \leftarrow next(p_2)$
        \Elif{$docID(p_1) < docID(p_2)$} 
	        \Comment{$p_1$ is surely not in $p_2$, so we can append $p_1$}
	        \State ADD(answer,docID($p_1$))
	        \State $p_1 \leftarrow next(p_1)$
        \Elif{$docID(p_2) < docID(p_1)$}
	        \Comment{we need to advance $p_2$ to know if $p_1$ can be appended}
	        \State $p_2 \leftarrow next(p_2)$
        \EndIf
    \EndWhile
    \If{$p_1 \neq NIL$}
	    \Comment{since $p_2$ is empty the rest of $p_1$ can be appended}
	    \State EXTEND(answer,$p_1$)
    \EndIf
    \Return $answer$
	\end{algorithmic}
	\end{algorithm}
```

We add to the return list those that occur in the *first* ( `X` ) and not in the *second* ( `Y` ) , this will keep the time at $O(x+y)$
### Multiple Binary operators

>[!question] 
>What is the best order to follow in doing query processing ? 

#### AND

With multiple *AND* process in order of **increasing** frequency, we start from the *smallest set* 

>[!example] 
>
>Given the following query : `Calpurnia AND Brutus AND Caesar` 
>
>Where : 
>+ `Calpurnia` contains $2$ *postings* 
>+ `Brutus` contains $8$ *postings*
>+ `Caesar` contains $7$ *postings*
>
>Since the output size of the query is given by the $\min(X,Y)$ we will first execute the query `Calpurina AND Brutus` since it will give us a lower output size
>

#### OR

For *OR* queries we treat them as being always in the worst case scenario, so when `X` and `Y` are *disjointed* , giving us the size of an *OR* query as $x+y$ 

So we estimate the lenght of each resulting query from the *document frequencies* and start from the **smallest** result