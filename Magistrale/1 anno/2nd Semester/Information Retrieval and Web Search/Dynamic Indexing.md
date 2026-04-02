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
>>
>>

