---
publish: true
---
>[!important] Definition 
>
>**Information Retrieval** ( *IR* ) is about finding material ( documents ) of an *unstructured* nature that satisfies an information need, from a large digital collection

Examples are : *web search* , *email search* , *disk search*
# Web Search Engines ( WSE )

A *WSE* is a software system designed to search for information on the World Wide Web , the users enters a *query* and the *WSE* returns a *ranked list* of relevant websites 

A *WSE* mainly consist of : 
+ **Crawler** : collects web pages
+ **Indexing System** : organizes, stores and indexes pages for fast retrieval 
+ **Query processor** : Determines the relevance of pages to a given query and ranks them

![[WebIR_sys.excalidraw.png]]
%%[[WebIR_sys.excalidraw.md|🖋 Edit in Excalidraw]]%%

# Information Retrieval Definitions

>[!important] Collection
>A *set* of documents ( this can be static or dynamic )

The *goal* is to retrieve documents that are *relevant* to the user *information need*

To determine the goodness of the retrieved we have the following measures : 
+ *Precision* : is the number of relevant documents in the pool of retrieved documents 
$$
Precision = \frac{|Relevant \cap Retrieved|}{|Retrieved|}
$$
+ *Recall* : is the number of relevant documents in relation to all the relavant document in the index 
$$
Recall = \frac{|Relevant \cap Retrieved|}{|\text{All Relevant in Collection}|}
$$

