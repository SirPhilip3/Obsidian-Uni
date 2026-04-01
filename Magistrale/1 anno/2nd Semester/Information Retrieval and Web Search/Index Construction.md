---
publish: true
---
In general we would like to store the *index* in **DRAM** 

Also the *indes* should be *block efficent* since both the **cache** and *disk* work in blocks

>[!note] 
>Testing collection : `RCV1` ( Reuters news wire )
>
>| stas                                   | val    |
>| -------------------------------------- | ------ |
>| documents                              | 800000 |
>| avg tokens per doc                     | 200    |
>| vocabulary                             | 400000 |
>| avg bytes per token ( with spaces )    | 6      |
>| avg bytes per token ( without spaces ) | 4.5    |
>

Steps in index constuction : 
1. Documents are *parsed* extracting *terms* and *docID*
2. The *inverted file* is **sorted** by *terms*

>[!warning] 
>
>The *sorting* is very expensive 

We can build the *index* in $3$ ways : 
1. `<term, docID>` :

Highly *inefficient* for storage and sorting 

2. `<termID, docID>` + *lexicon*

While building the *index* , the parser replaces the *terms* with it's corresponding `termID` present in the *lexicon* ( also build simultaneously )

This improves *compression* and *sorting* ( sorting *integers* is faster than symbols )

3. `<termID, docID, docFreq>` + *lexicon*

Aggregates the *terms* for each *documents* maintaining the *occurence count*  

This still uses $12$ bytes ( $3$ integers of $4$ bytes each )

Given the $T=100,000,000$ *non positional postings* for `RCV1` we have : 
$$
100M \times 12Bytes = 1.2 GB
$$
>[!warning] 
>This while probably fitting in *RAM* , sorting in *RAM* is not efficent due to the fact that the array would need to be loaded into the *cache* causeing *Page Faults*
# BSBI : Blocked Sort-Based Indexing

For efficent *sorting* we need to devide the data into *blocks* that can be sorted independently 

>[!note] Idea
>1. *Accumulate* postings until *block capacity* is reached
>2. **Sort** *in memory* the block
>3. Write on the disk the intermediate result
>4. Merge the *blocks* into a single sorted *index*

## Blocks Merging

### Binary Merge

Using **binary merges** ( always merges two block togheter at the same level )

>[!note] 
>Merging two sorted *blocks* can be done in *linear* **time** and *linear* or *constant* **space**

>[!example] 
>![[bin_merge.excalidraw.png]]
%%[[bin_merge.excalidraw.md|🖋 Edit in Excalidraw]]%%

>[!warning] 
>Each time we merge two blocks the size dubles, this becomes very **expensive**

#todo algorithm

### Multi-way merge

We keep in memory only small *chunks* ( [[Strutture Dati#min_heap|min heap]] ) that recieve as input data from the bigger in-memory chucks of the actual *index blocks*

They than produce as ouput to an *output chuck* they'r minimum, this will than be flushed when full to the disk

( see [multi-way merge](https://satyadeepmaheshwari.medium.com/sorting-large-datasets-with-limited-memory-the-chunked-merge-sort-approach-318275275c81) ) 

# SPIMI : Single-pass in-memory indexing

>[!warning] 
>In all the previous solution we *assume* that the *dictionary* can be kept in memory 

**Ideas** : 
1. We can generate *separate dictionaries* for each *block*
2. Accumulate postings in *postings list* as they occur

Still using *blocks* we subdivide the documents into them and build *partial indexes* , these can be merged by simply appending each *postings list* in the blocks order

#todo algorithm

