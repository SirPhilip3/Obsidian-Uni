---
publish: true
---
**P2P** networks can be seen as an organization principle where the partecipating entities are all equal ( everyone acts as a *client* and *server* at the same time )

We can have 2 types of *Peer-to-Peer* network :
+ Hybrid 
+ Pure 
	+ Unstructured
	+ Structured

# Hybrid

An instance of **hybrid** *P2P* is *Napster* 

Each user machine stores a subset of the total file hosted on *Napster* 
It used a *Centralized Napster Index* that stores the index that maps files to machines ( this is in fact a *server* )
## Search in Napster

To find a file in *Napster* the *peer* sends a request to the *Centralized Index* , it returns a list of machines that host that particular resource 

The file sharing is next done *directly* between *peers*  

![[Napster.excalidraw.png]]
%%[[Napster.excalidraw.md|🖋 Edit in Excalidraw]]%%

>[!check] Advantages
>+ Easy to implement sophisticated seach techniques
>+ User load is limited  
>+ Central server has a complete overview of the system
>+ Always correct answer

>[!error] Disadvantages
>+ Scalability : the centralized index has to handle all the requests 
>+ Robustness : The *index* is a Central point of failure 
>

## KaZaA

In *KaZaA* there are **Super Peers** that supervise subnetworks , these *Super Peers* executes the queries for the leaves ( normal *peers* ) that they supervise 

*Super Peers* act like a Napster centralized *index* for it's leaves 

Each **Super Peers** will comunicate among themselves and do not have information regarding *peers* supervised by other *Super Peers* 

>[!info] **Joining** the network
>
>A *peer* sends a request to one *Super Peer* containing the list of files that he can share 

### Seach in KaZaA

To find a *resource* a *peer* will send a request to it's relative *Super Peer* : 
+ If the resource is found in it's *index* it will return the address of the *peer* and they exchange information directly ( like in *Napster* )
+ Otherwise the *Super Peer* will forward the request to it's neighbouring *Super Peers* until the resource it's found 
	+ When a resource is found the *Super Peer* will respond with the address of the resource 
	+ The two *peers* will than exchange the resource

>[!example] 
![[c5s16ucx.png]]

>[!check] Advantages
>+ Efficent search with *Flooding* resticted only to *Super Peers*
>

>[!error] Disadvantages
>+ The resource could not be found if it surpasses the *TTL* limit
>+ *Super Peers* are single point of failure for it's supervised *peers*

# Unstructured Pure
## Gnutella 

*Peers* have an initial set of addresses to witch they connect 
*Peers* are equally treated , each one provides both the files and sends / replies to *routing requests* 

Each *peer* knows a subset of the neighbouring *peers* 

>[!note] 
>There are some *cache* servers that maintains as many peers addresses as possible , when a *peer* start it will contact the cache server that will :
>+ add the new *peer* to it's cached addresses
>+ send back an initial list of *peers*

### Search in Gnutella

 A *peer* that wants a resource from another *peer* will send the request from *neighbour* to *neighbour* ( *ping* ) until :
 + The resource is found
 + The message has reached the *TTL* ( *Time to Leave* ) ( generally a predifined number of steps )

When the resource has been found the *peer* that hosts that resource will simply connect to the intial *peer* ( it's address will be maintained in the *ping* message ) and download the resource 

>[!example] 
![[Gnutella.excalidraw.png]]
%%[[Gnutella.excalidraw.md|🖋 Edit in Excalidraw]]%%

>[!check] Advantages 
>
>+ Completely distributed ( decentralized )
>+ *Robust* to random node failures 

>[!error] Disadvantages
>+ We could recieve *redundant* *results* if the resource is in many *peers*
>+ We could not recieve a result if the resource is stored in a peer that is further than the *TTL*
>+ One peer could recieve multiple request messages 
>+ Vulnerable to *Denial of service attacks* ( continuos flooding of the network with fake requests ) 

#### Iterative Deepening

If a resource is not found within the limited *TTL* we increase the *TTL* until :
+ We found the resource
+ We found a *boundary* *TTL* 
# Structured Pure

## BitTorrent

Files are divided into different parts and spread between *peers* 

Each *peer* that makes a request for a certain file will also host part of it for the other peer to download 

>[!note] 
>Initially there will be only one *peer* that will host the file but as more *peers* will request it more *peer* will also host part of it to download

>[!example] 
[![](https://upload.wikimedia.org/wikipedia/commons/3/3d/Torrentcomp_small.gif)](https://it.wikipedia.org/wiki/File:Torrentcomp_small.gif)
## Chord

>[!note] 
>Uses *Distributed Hash Tables*

+ Each *peer* get's an *ID* ( *SHA-1* of the *IP* ) 
+ Each *resource* get's a *key* ( *SHA-1* of the title etcc ) , to avoid possible collision we use long keys ( `160bit+` ) ( $m$ is the number of bits in the *hash key* )

>[!warning] 
>
>*SHA-1* is deprecated 

The hasing should be done so that each *peer* will recieves the same number of resources / keys to store 

In order to keep this *load balancing* each time that a new *peer* joins / parts the network , we regenerate the keys  

### Protocol

Each *peer* and *key* are are arranged in a circle with at most $2^m$ nodes 

>[!note] 
>$m$ should be chosen large enough to avoid collision

Some *node* will map to *peer* others will be empty 

Each *node* has a $successor(k)$ and a $predecessor(k)$ 

Each *node* will maintain a **finger table** , this will contain $m$ entries where the $i$-th entry of node $n$ will contain $succesor((n+2^{i-1})\mod{2^m})$ 
This way the first entry will always be it's immediate $successor$ 

Every time we want to look for a *key* $k$ we will pass the *query* to the closest $successor$ of $k$ present in the *finger table* ( the largest one whose *ID* is smaller than $k$ ) until a node finds out that the *key* is stored in its immediate successor 

The number of nodes that must be contacted to find a succesor in a $N$-node network is $O(\log N)$

>[!important] 
>The insertion or removal of a node will generate $O(\log^2 N)$ messages , this because we will need to move the resources and modify the *finger tables* of its $predecessors$ and $successors$ 

>[!example]-
>Let's assume that $m=3$  than $2^m = 8$ 
>
>$1$ joins the network , since no other node is in the network it's successors will be itself
![[Chord1.excalidraw.png]]
%%[[Chord1.excalidraw.md|🖋 Edit in Excalidraw]]%%
>
>$2$ join the network
![[Chord2.excalidraw.png]]
%%[[Chord2.excalidraw.md|🖋 Edit in Excalidraw]]%%
>>[!note] 
>> Now the closest successor for $1$ is $2$
>
>$6$ and $0$ join the network 
>
![[Chord3.excalidraw.png]]
%%[[Chord3.excalidraw.md|🖋 Edit in Excalidraw]]%%
>
>Now let's assign the resources $7$ and $1$ ( assign to the closest successor to it's index ) 
>
>![[Chord4.excalidraw.png]]
%%[[Chord4.excalidraw.md|🖋 Edit in Excalidraw]]%%
>

>[!example]- 
>Let's now do the query for item with *id*=$7$ from node $1$ 
>
![[Chord5.excalidraw.png]]
%%[[Chord5.excalidraw.md|🖋 Edit in Excalidraw]]%%

### Complexity

#todo 

