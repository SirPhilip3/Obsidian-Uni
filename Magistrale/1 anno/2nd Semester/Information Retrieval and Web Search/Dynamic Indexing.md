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