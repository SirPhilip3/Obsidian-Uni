---
publish: true
---
A document is a vector $d$ of $N$ elements :
+ $N$ is the number of distinct words in the corpus
+ documents have ids from $1$ to $N_{docs}$  
+ $d[i]$ can store :
	+ the *frequency* of *term* $i$ in document $d$ ( $tf(i)$ ) , *normalized* by it's $L_{2}$ norm
	+ The [[Tf-Idf]] ( $tf(i)\ln \left( \frac{N_{docs}}{df(i)} \right)$ )

The *similarity* between two documents is measured with **cosine** *similarity* :
$$
s(a,b) = \sum_{i=1}^N a[i] \cdot b[i]
$$
>[!important] Problem Statement
>
>Given a copus of documents find all pairs such that their similarity $s$ is at least $\tau$

## MapReduce Implementation 

>[!note] 
>Documents with similarity $s > 0$ *share* at least *one term* 

**Idea** :
+ Attach a key $t$ to a document $d$ , for each of it's terms 
+ If *two documents* have the *same key* $t$ then they have *at least* *one term in common*
+ If two documents *never share a key* $t$ than we can safely *avoid computing* it's similarity


```python
map(doc_id, document):
	for each term t in document:
		emit(t, [doc_id,document])

reduce(t, docs: list[[doc_id, document]]):
	for id1, d1 in docs:
		for id2, d2 in docs:
			if s(d1,d2) >= tau:
				emit([id1,id2], s(d1,d2))
```

>[!warning] 
>We duplicate the whole document for each term

### Prefix Filtering

*Sort* terms by **decreasing frequency** ( or score ) in the corpus

>[!example] 
>$d[0]$ correspond to the most frequent term in the corpus

Create the *maximum document* $d^*$ :
$$
d^*[i] = \max_{d} d[i] 
$$
This stores the maximum score of each terms in any document in the collection

>[!note] 
>If $s(d,d^*) \le \tau$ then $d$ has no similar documents in the corpus 

>[!note] 
>Let $b(d)$ be the largest term id such that :
>$$
>\sum_{0\le t \le b(d)} d[t] \cdot d^*[t] < \tau
>$$
>
>Then a document similar to $d$ must share with $d$ at least one term $t > b(d)$
>
>It is sufficient to check common terms beyond $b(d)$

```python
map(doc_id, document):
	for each term t in sorted(document):
		if t > b(document):
			emit(t, [doc_id,document])

reduce(t, docs: list[[doc_id, document]]):
	for id1, d1 in docs:
		for id2, d2 in docs:
			if s(d1,d2) >= tau:
				emit([id1,id2], s(d1,d2))
```

>[!warning] 
>We create as many *reducers* as the number of terms in common between two documents 

### Removing Reducers

Since each reducer recieves the two full documents it knows what are the terms in common 

We *compute* the actual similarity *only* if the reducer has the *key* *equal* to the *largest common term* 

```python
map(doc_id, document):
	for each term t in sorted(document):
		if t > b(document):
			emit(t, [doc_id,document])

reduce(t, docs: list[[doc_id, document]]):
	for id1, d1 in docs:
		for id2, d2 in docs:
			if t == max(intersect(d1,d2)) :
				if s(d1,d2) >= tau:
					emit([id1,id2], s(d1,d2))
```
