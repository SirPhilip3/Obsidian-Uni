---
creation: 2024-10-30T09:47:00
publish: true
---
>[!note] 
>Le applicazioni essendo tutte diverse le une dalle altre sono difficili da standardizzare 

Generalmente le applicazioni vogliono scambiarsi due tipi di dati : 
## Exchanging Text

In genere il testo utilizza due tipi di *encoding* : 
+ **ASCII**
+ **UTF-8**

>[!note] 
I protocolli a livello di applicazione devono definire in che standard vengono mandati i dati 
## Exchanging Raw Data

I dati possono avere due formati a seconda dall'architettura della CPU : 
+ *big-endian* : I byte più significativi precedono i byte meno significativi
+ *little-endian* : I byte meno significativi precedono i byte più significativi

>[!note] 
>Su Internet si scambiano dati in formato *big-endian*

>[!note]
>Usiamo `htonl()` in c per convertire dati dal formato dell'*host* a quello del *network* , `ntohl()` per fare il contrario 
# Naming System

Utilizziamo *nomi di dominio* per indicare un indirizzo di un *host* al livello di applicazione 

Per effettuare il mapping tra *address* e [[Domain Name]] si utilizza il **Domain Name System** ( **DNS** ) 

Per ricavare l'indirizzo dell'*host* vengono utilizzati i ![[Name Servers]]