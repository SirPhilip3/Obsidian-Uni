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

