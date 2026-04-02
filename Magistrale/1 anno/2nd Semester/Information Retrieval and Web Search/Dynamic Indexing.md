---
publish: true
---
In general 
+ *documents* come in over time and need to be *inserted* into the *index*
+ *documents* can be *deleted* or *modified*

>[!info] Naive Idea
>Periodically reconstruct the *index* from scratch 
>
>*Not efficent* for big collections and frequently changing ones 

>[!info] 2nd Idea
>
>Maintain a *big* main index
>
>New documents go into a *smaller* auxiliary index
>
>>[!warning] 
>>At processing time we need to search both indexes and than merge the results 
>
>For **deletion** we use and *invalidation bitvector* that get's filtered out when we query documents
>
>Also we periodically *re-index* into the *main* index when the *auxiliary* index become too big  
>
>>[!warning] Issues
>>
>>Merging the *auxiliary* index and the *main* index is **efficent** if we keep separate files for each postings list , since merging them is a simple append as in [[Index Construction#SPIMI Single-pass in-memory indexing|SPIMI]] 
>>This is inefficient for the *OS*
>>
>>The final main index will be a *big single file*
>>

# Sharding 

*Sharding* distributes and partition data across multiple physical nodes 

**Advantages** : 

| Scalability                                                                                                     | Performance                                                                    | Fault Tolerance                                                       |
| --------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------ | --------------------------------------------------------------------- |
| As documents grows, sharding distributes the data allowing the system to scale horizontally by adding more node | By distributing data across multiple nodes we reduce load on any single server | *Replicating shards* if a node fails we have replicas still available |
>[!note] 
>A *query* is evaluated by processing it in the *partial indexes* and than merging the results

How the index is partitioned has implication on performance in the query system : 
+ **document based**
+ **term based**
## Document based partitioning

All the information relative to a *single document* stay on a *single* *node*

To perform a term **query** we need to query all the nodes and than merge the results  
## Term based partitioning

1. Build a **global** *index* on the entire *document collection* 
2. Assign to each *node* a *subset* of *terms* and it's corresponding [[Inverted Index]] 

To perform a term **query** we need only *few nodes* , those storing the relevant postings list

>[!warning] 
>Since some terms are more frequently searched than other there will be some *load imbalance* for the nodes

