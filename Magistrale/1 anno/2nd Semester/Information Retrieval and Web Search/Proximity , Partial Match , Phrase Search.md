>[!example] WestLaw system
>
>Has the following operators :
>+ `/p` : matches in the same *parargaph*  
>+ `/s` : matches in the same *sentence*
>+ `/k` : matches within $k$ words
>+ `!` : trailing waildcard ( ex `disabl!` matches `disability` or `disable` ecc  )
>+ *spaces* are interpreted as `OR`

>[!warning] Problem
>
>We want to be able to search for a complete phrase ( ex `standford univerity` ) , this can be seen as an *AND* with a specific **order** in the terms 
>
>For this we we need to store more than `<term : docs>`
# Biword indexes

Uses the following *tokenizer* : 
+ Index every *consecutive pair of terms* in the text as a phrase

>[!example] 
>For the text `Friends, Romans, Countrymen` we produce the following *biwords* :
>+ `friends romans`
>+ `romans countrymen`

Each *biword* becomes a **dictionary term**

>[!note] 
>This only allows for *two word* phrase query processing

We still can encounter *false positive* for long phrases 

>[!example] 
>
>Searching `standford university palo alto` , this will be broken down in : 
>`"stanford university" AND "univesity palo" AND "palo alto" `
>
>Can produce phrases like this : 
>+ *Stanford University* is in *Palo Alto*. This is not the only *university. Palo* Alto also hosts Palo Alto University

Another problem is the *index blowup* due to the bigger dictionary , it doesnt scale for larger *k-words* indexes
# Positional Indexes

In the *postings*, store for each *term* the *document postions* in which the token appears :

```
<term, n (frequency of the term);
	docID1: position1, position2, ...;
	...
	docIDn: position1, position2, ...;>
```

>[!example] 
>
>```
><be, 9934;
>	1: 7, 18, 33,72, 231;
>	2: 3, 149;
>	4: 17, 191, 291, 430, 434;
>	5: 363, 367, ...>
>```
>
>The documents that *may* contain the "to be or not to be" , considering "be" the documents that have them at the right *distance* are $4,5$
>

We can compute *phrase* queries by merging recursively at the document level

>[!example] 
>Extracting "to be or not to be", we first extract each distinct term from the *inverted* index 
>
>We *merge* their `doc:position` lists ( *AND* ) and than check for adjacent positional indexes 
>
>
>```
>to:
>	4: 8,16,190,429,433 
>be
>	4: 17,191,291,430,434
>```
>
>We can see groups of indexes grouped togheter : 
>+ `16`, `17`
>+ `190`, `191`
>+ `429`, `430`
>+ `433`, `434`

## Proximity queries 

We can use *positional indexes* also for proximity queries by adapting the *merge* ( *AND* ) operation  

```pseudo
	\begin{algorithm}
	\caption{$PositionalIntersect(p_1, p_2, k)$}
	\begin{algorithmic}
	\State $answer \gets \langle \rangle$
	\While{$p_1 \neq \emptyset$ \textbf{and} $p_2 \neq \emptyset$}
		\If{$docID(p_1[0]) = docID(p_2[0])$}
			\State $l_1 \gets positions(p_1[0])$
			\State $l_2 \gets positions(p_2[0])$
			\For{\textbf{each} $el_1 \in l_1$}
				\For{\textbf{each} $el_2 \in l_2$}
					\If{$|el_1 - el_2| \leq k$}
						\State \Call{Append}{$answer, (docID(p_1[0]), (el_1, el_2))$}
					\Elif{$el_2 > el_1$}
						\State \textbf{break}
					\EndIf
				\EndFor
			\EndFor
			\State $p_1 \gets \text{rest}(p_1)$
			\State $p_2 \gets \text{rest}(p_2)$
		\ElIf{$docID(p_1[0]) < docID(p_2[0])$}
			\State $p_1 \gets \text{rest}(p_1)$
		\Else
			\State $p_2 \gets \text{rest}(p_2)$
		\EndIf
	\EndWhile
	\State \Return $answer$
	\end{algorithmic}
	\end{algorithm}
```

Considering the *size* of the index this expands substantially $2-4$ time larger than the correponding non positional *index*
# Combination

For particularly common *pharses* we can keep a [[Proximity , Partial Match , Phrase Search#Biword indexes|biword index]] to avoid doing the *merge* operation for large positing lists