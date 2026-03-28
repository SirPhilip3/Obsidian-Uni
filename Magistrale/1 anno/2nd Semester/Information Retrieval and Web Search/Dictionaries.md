# Dictionary

>[!question] 
>What data structure do we use to store the *dictionary* ? 
## Naive solution

Use array of *structs* containing a *term* field ( `char[20]` ) , a *document frequency* field ( `int` ) and a *pointer* to the *postings list* 

>[!example] 
>
>| term   | document frequency | pointers to postings list |
>| ------ | ------------------ | ------------------------- |
>| a      | 656265             | ->                        |
>| aachem | 65                 | ->                        |
>| ...    | ...                | ...                       |
>
## HashTables

Each vocabulary *term* is hashed to an integer 

**Pros** :
+ Looking up is faster than for a tree : $O(1)$

**Cons** : 
+ No easy way to find minor variants
+ No prefix search with wildcard
+ If the vocabulary keeps growing we need to occasionaly *rehash* the whole table 
## Trees

Trees require the *terms* to be ordered in *lexicographic order* 

Also with *trees* we can get a range of terms allowing us to search for close terms ( because they are ordered *lexicographically* )
### Binary tree

>[!example]
>
>![[BinTrees_IR.excalidraw.png]]
>%%[[BinTrees_IR.excalidraw.md|🖋 Edit in Excalidraw]]%% 
>

>[!warning] 
>Binary trees are *not* good for **spacial locality** 

The cost of access is still slower than *hashtables* : $O(\log M)$ ( $M$ is the number of nodes stored in the trees ) 
### B-tree

>[!example] 
>
>![[B-tree_IR.excalidraw.png]]
>%%[[B-tree_IR.excalidraw.md|🖋 Edit in Excalidraw]]%%
>

*B-trees* are generalization of *binary trees* allowing more that one children per node

A *B-tree* of *order* $m$ means that each *nonleaf node* has up to $m$ children , if a node has $n \leq m$ children it contains $n-1$ keys

They have better **spacial locality** since each node has multiple elements

>[!important] 
>An important optimization for *B-trees* is making shore that $m$ can fill out a *cache* line so we can access directly from *cache*

