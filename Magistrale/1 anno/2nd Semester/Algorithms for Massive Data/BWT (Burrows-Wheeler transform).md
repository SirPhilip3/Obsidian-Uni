---
publish: true
---
The **BWT** is a string *permutation* that :
+ Given *RSA* ( *rank*, *select* and *access* ) queries on the **BWT** will enable **count** queries on the original string
+ **BWT** is *easier* to *compress* than the original string 
# Construction

1. Compute all *string rotations* 

|     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- |
| b   | a   | n   | a   | n   | a   | $   |
| a   | n   | a   | n   | a   | $   | b   |
| n   | a   | n   | a   | $   | b   | a   |
| a   | n   | a   | $   | b   | a   | n   |
| n   | a   | $   | b   | a   | n   | a   |
| a   | $   | b   | a   | n   | a   | n   |
| $   | b   | a   | n   | a   | n   | a   |


2. **Sort** them lexicographically 

|     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- |
| $   | b   | a   | n   | a   | n   | a   |
| a   | $   | b   | a   | n   | a   | n   |
| a   | n   | a   | $   | b   | a   | n   |
| a   | n   | a   | n   | a   | $   | b   |
| b   | a   | n   | a   | n   | a   | $   |
| n   | a   | $   | b   | a   | n   | a   |
| n   | a   | n   | a   | $   | b   | a   |


3. The **BWT** is the last column of the matrix 

|     |     |     |     |     |     | **BWT** |
| --- | --- | --- | --- | --- | --- | ------- |
| $   | b   | a   | n   | a   | n   | *a*       |
| a   | $   | b   | a   | n   | a   | *n*       |
| a   | n   | a   | $   | b   | a   | *n*       |
| a   | n   | a   | n   | a   | $   | *b*       |
| b   | a   | n   | a   | n   | a   | *$*       |
| n   | a   | $   | b   | a   | n   | *a*       |
| n   | a   | n   | a   | $   | b   | *a*       |
## BWT and [[Suffix trie-tree-array#Suffix Array|SA]]

The text position of the $i$-th matrix row is $SA[i]$

$S=banana\$$

| **SA** |     |     |     |     |     |     |     |
| ------ | --- | --- | --- | --- | --- | --- | --- |
| *7*      | $   | b   | a   | n   | a   | n   | a   |
| *6*      | a   | $   | b   | a   | n   | a   | n   |
| *4*      | a   | n   | a   | $   | b   | a   | n   |
| *2*      | a   | n   | a   | n   | a   | $   | b   |
| *1*      | b   | a   | n   | a   | n   | a   | $   |
| *5*      | n   | a   | $   | b   | a   | n   | a   |
| *3*      | n   | a   | n   | a   | $   | b   | a   |

#todo

