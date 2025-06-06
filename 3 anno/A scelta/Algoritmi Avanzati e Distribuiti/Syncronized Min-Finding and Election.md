---
publish: true
---
We can speed up the [[Ring Ranking#As Far|As Far]] algorithm by differentiating the speed of the messages

We modify the speed ( by waiting ) so that it will be proportional to the value of the *entity* ( where larger value will wait for larger amount of time ) so that the message with a lower id will travel faster and catch up with the larger id messages in order to delete them faster 

1. When an entity $x$ recieves a message with a value $i$ smaller than any seen so far by $x$ $x$ will hold the message for an amount of time $f(i)$ proportional to the value $i$ 
2. If a message with a smaller value arrives at $x$ during this time $x$ will remove $i$ and process the new value 
3. Otherwise after holding $i$ for $f(i)$ it will forward it along the ring 

>[!important] Assumpion
>All the entities start at the same time

>[!note] 
>We generally choose $f(i)=2^i$ 
>
>This is very useful since by the time that the smallest value has travelled along all the ring the second one will have at most traveled only half way trough the ring 
>
>In general the $j$th smallest value will have travelled at most $\frac{n}{2^{j-1}}$ along the ring 
>
>So the *total* number of transmissions until the *entity* with the smallest value completes the ring will be : 
>$$\sum_{j=1}^{n}\frac{n}{2^{j-1}}<2n$$
>
>This implies that the **Message Complexity** is : $O(n)$

>[!note] 
>We always need a final notification for the other *entities* to know the **LEADER**

>[!important] 
>Removing the assumpion of syncronized start changes only the fact that the *election* messages will also act as *wake-up* messages for the *entities* thar are not *spontaneous initiators*

The **Time Complexity** will instead be : $O(2^i n)$ 

>[!abstract] Proof
>Since the *leader* will travel along the ring with a speed of $2^{i_x}$ ( where $i_x$ is the value of $x$ ) and since it will be delayed by each *entity* it's total delay will be : $(n-1)(2^{i_x}+1)$ or $O(2^in)$

>[!example] 
>#todo

