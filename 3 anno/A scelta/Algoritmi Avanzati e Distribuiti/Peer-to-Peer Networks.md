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

## Seach in KaZaA

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



# Structured Pure


## Chord

