---
publish: true
---
>[!info] Idea
>Divide the *indexing* job to a set of *parallel* tasks , a *master machine* will assign each *task* to an idle machine from a determined pool

>[!warning] 
>*Master machine* is a single point of failure

We will use two sets of *parallel tasks* : 
+ **Parsers**
+ **Inverters**
# Parsers

The *master* will *split* the documents and assign each one to an *indle* **parser**

The *parser* reads the document and emits the `<term, docID>` pairs 
Separates them into they'r corresponding $j$-th *partition* on the basis of a *key* 

In our case we can divide them based on the *first letter* of the `term` 

>[!example] 
>$j=3$
>
>We will have partitions : `a-f, g-p, q-z`

Each of the generated *partition* will be assigned to an **inverter** by the *master*
# Inverters

They perform a *reduction* from the `<key,value>` pairs that they recieve :

From many *values* ( `docID` in our case ) with the same *key* ( `term` ) it outputs an *aggregate* ( a sorted list )

So it *sorts* over `docID` and writes to a *postings list*


