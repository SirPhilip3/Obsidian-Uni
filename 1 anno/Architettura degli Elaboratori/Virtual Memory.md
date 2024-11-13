---
publish: true
---
**Memoria virtuale**: La memoria primaria **RAM** agisce come cache per la memoria secondaria **SSD, dischi** 

Perchè:
+ Meccanismo con il quale possiamo condividere memoria **RAM** tra più programmi in esecuzione in modo **sicuro** ( senza accedere ad aree di memoria di altri programmi )
+ Un programma può utilizzare più **RAM** di quella realmente disponibile

I programmi sono compilati ripetto ad uno spazio di indirizzamento virtuale,
il Sistema Operativo e la CPU effettuano la traduzione tra indirizzo virtuale e fisico

La CPU lavora su indirizzi virtuali mentre la memoria viene acceduta da indirizzi fisici

**Pagine** ( Blocchi di memoria ) sono mappati da indirizzi virtuali ad inidrizzi fisici, una **Pagina** può essere assente nella **RAM** e risiedere invece sul disco

La pagina fisica può essere condivisa tra più inidirizzi virtuali diversi, in questo modo diversi programmi possono condividere degli spazi di memoria

Vantaggi:
+ Illusione di possedere più memoria di quella presente nel sistema
+ Garanzia che gli spazi di indirizzamento virtuali di programmi diversi siano mappati su indirizzi fiisci differenti
+ Semplifica il caricamento in memoria dei programmi poichè possono essere caricati ovunque in memoria , anche in regioni **non contigue** senza ricompilazione

Indirizzi virtuali
2 parti:
+ **Virtual Page number**
+ **Page offset**

Indirizzi nella pagina fisica:
+ **phisical page number**
+ **page offset** ( uguale al page offset virtuale )

Traduzione: 

![[Immagine 2023-03-31 175130.png]]

Il numero di bit del **page offset** determina le dimensione della pagina Page offset = $log_{2}$ page size

La **Traduzione** avviene attraverso una **page table** 
+ Ciascun programma in esecuzione ha una **page table**
+ La **page table** risiede in memoria **RAM**
+ Il **page table register** contiene l'indirizzo della **page table**

Ad ogni pagina virtuale può corrispondere una qualsiasi pagina fisica: **completamente associativa**

Aggiunta di un bit di validità per determinare se la **page table** è in memoria

![[Immagine 2023-04-01 144834.png]]

Se una pagina non è presente in **RAM** ma solo sul disco si verifica **page fault**:
+ **Miss penalty enorme** : necessario ridurre il più possibile in numero di **page faults** 

Gestione **page faults**:
+ mapping tra pagine virtuali e fisiche **completamente associativo** 
+ Utilizzata politica di rimpiazzo **LRU**
+ page fault gestiti via software tramite **Sistema Operativo**
+ utilizzo politica di **Write-back** per diminuire gli accessi in memoria secondaria

## Memoria paginata

+ Al loading del processo creato sul disco l'immagine delle varie **pagine** del programma e dei dati
+ **pagine** portate in memoria fisica solo quando avvengono i **page faults**

## Bit di stato

+ **dirty** bit : indica se una pagina è stata modificata , e quindi ricopiata al livello inferiore di memoria se viene rimpiazzata
+ **reference** bit :  indica se in un certo lasso di tempo la pagina è stata riferita, periodicamente azzerato e  settato a 1 ogni volta che la pagina viene riferita ( implementazione politica **LRU** )

## Translation Lookaside Buffer

+ La **page table** può essere molto grande ( molti MB ) e risiedendo in **RAM** implica maggiori accessi in memoria:
	+ 1 accesso = traduzione indirizzo virtuale in indirizzo fisico
	+ 2 accesso = accedere ai dati veri e propria

Presenza località spaziale e temporale anche nell'accesso alla **page table**
+ Aggiunta di una **cache della page table** / **translation cache** / **TLB**
	+ Contiene una porzione di **page table**
	+ Implementazione in hardware overhead minimo in caso di hit
	+ prima volta che una pagina viene riferita ( **page fault** ) viene copiata anche nella **TLB** per velocizzare gli accessi sucessivi

Può avere vari livelli di associatività 

![[Immagine 2023-04-01 161414.png]]

**TLB** contiene solo entry che sono Valid nella **page table** , se una paina viene eliminata dalla memoria fisica anche la entry della **TLB** viene invalidata ( bit **valid** = 0 ) 

### TLB Miss
Nel caso si verifichi un **TLB miss** generata un'eccezione che :
+ Risolta se la pagina è presente nella **page table**
+ **page fault** se non è presente in **page table**

## Cache integration

3 tipologie : 
+ **Physically addressed cache** : La cache lavora dopo la **TLB** e page table, su indirizzi fisici
+ **Virtually addressed cache** : La cache lavora su indirizzi virtuali, prima della **TLB** e **page table**
+ **Virtually indexed but phisically tagged** : La cache usa il TAG fisico ( per evitare **aliasing** ) ma indice virtuale 

**aliasing** quando 2 indirizzi virtuali differenti puntano ad uno stesso indirizzo fisico

### Phisically addressed cache

+ Usa indirizzi fisici, ogni accesso alla cache deve prima passare per la **TLB** ( o **page tabel** in caso di **TLB miss** )
+ Non soggetta ad **aliasing** tra programmi diversi che usano gli stessi indirizzi virtuali in un dato istante

### Virtually addressed cache

+ Utilizza indirizzi virtuali, quindi ogni cache hit non richiede alcun accesso alla **TLB** ( non vengono provocati nè **TLB miss** nè **page fault** )
+ Soggetta ad **aliasing** se porgrammi diferenti usano gli stessi indirizzi virtuali ( due processi che usano lo stesso indirizzo virtuale sono indistinguibili dalla cache i dati possono essere letti/sovrascritti da entrambi i porcessi )

### Virtually indexed but physically tagged

+ **INDEX** calcolato dall'indirizzo virtuale
+ **TAG** calcolato dell'indirizzo fisico
+ **aliasing** non possibile
+ possono essere ventaggiose in termini di prestazioni

### Tipologia miss

+ **compulsory** : quando i blocchi vanno portati per la prima volta in cache poichè inizialmente vuota
+ **capacity** : la cache non è in grado di contenere tutti i blocchi necessari all'esecuzione del programma  ( es un blocco viene espulso e subito dopo richiamato )
+ **collision** : due blocchi sono in conflitto per una certa posizione 
	+ possono verificarsi anche se la cache non è piena
	+ avvengono solo se la cache non è completamente associativa, altrimenti viene usato il primo blocco libero

## SO e memoria virtuale

**SO** invocato per gestire 2 eccezioni:
+ **TLB miss**
+ **page fault**

Risposte:
+ **CPU** salta alla ruotine di gestione del **SO**
+ Cambio di modalità di esecuzione : **User mode** -> **supervisor ( kernel ) mode**

### CPU modes

In **User mode** un programma non può :
+ modificare la **page table**
+ modificare le entry della **TLB**
+ cambiare l'execution mode

Restrizioni non presenti in **supervisor mode**

Un programma in esecuzione in user mode può passare volontariamente ( in modo indiretto ) in **supervisor mode** solo invocando una **system call** ( in ARM SVC )
+ Trasferisce il controllo ad un indirizzo di memoria dedicato alla gestione dell'interruzione
+ Cambia execution mode in **supervisor**
+ Salva il **PC** in un registro chiamato **Exeption Link Register ( ELR )** 
+ **SVC** utilizza un parametro immediato per capire il tipo di Exeption

### Exeptions

#### Only TLB-miss

Pagina presente in memoria ma non nella **TLB**

Risolta tramite **page table** allocata in RAM

Penalty simile al cache miss ( RAM lookup )
L'istruzione che ha causato miss ( lw/sw ) deve essere rieseguita dopo essere stata caricata l'entry della **page table**

Gestione del **TLB miss** via hardware -> piccolo penalty

#### TLB-miss + page fault

La pagina non è presente in memoria: l'entry corrispondente della **page table** è invalid

La pagina deve essere portata in memoria RAM dalla memoria secondaria, causa un penalty enorme ( micro/millisecondi ) -> effettuato un **context switch** 

Quando il **page fault** è risolto si riprende l'esecuzione del programma che era stato bloccato

##### Context Switch

**SO** :
+ Salva lo stato del programma in esecuzione ( Registri generali, Registro che punta alla page table )
+ Carica stato di un altro processo pronto per essere eseguito
+ Riprende esecuzione del nuovo processo

#### page fault con rimpiazzamento di pagina

Se la memoria fisica ( RAM ) è piena bisogna risolvere il page fault rimpiazzando una pagina
+ La pagina da rimuovere deve essere scritta in memoria secondaria se il bit **dirty** è asserted
+ Modificando la **page table** occorre ripulire anche la **TLB** se l'entry corrispondente era presente

### Protezione spazio di memoria

**TLB** e **page table** non possono essere modificate da un processo in esecuzione in modalità utente
**SO** grantisce che ciascun processo abbia le proprie pagine fisiche private 

### Costo Context Switch

Il cambiamoento di processo implica il cambiamento del puntatore alla **page table** da utilizzare
Dovermo cancellare dalla **TLB** le entry del processo precedente per :
+ Garantire la protezione dei dati
+ Far spazio alle entry del nuovo processo

Operazione costosa

#### ASID

Alcune CPU l'indirizzo virtuale è esteso con l'ID del task ( **ASID** ) a cui appartiene quel blocco di memoria
**ASID ( Address Space ID )**  concatenato al **TAG** in modo che un hit avviene soltanto se si ha un match tra **page number** e process **ID** 

Quindi non devo liberare completamente la **TLB** in caso di **context switch** 

### Address Spaces

Diveris sapazi di indirizzamento e page table per gestire macchine virtuali

![[Immagine 2023-04-02 173012.png]]

### Page table multi livello

Solo una piccola parte dello spazio di indirizzamento è usata da ciascun programma, ARM utilizza un approccio gerarchico a 4 livelli per la **page table** ( Altrimenti per ARM con pagine a 12bit la **page table** risulterebbe contenere $2^{36}$ elementi da 28 bit -> 200GB di **page table** per ogni processo )

Ogni livello usa 9 bit per indirizzare al prossimo livello della tabella ( 9* 4=36 )

Ciascuna entry della page table composta da 8 bytes, ciascuna tabella è da $2^9$ = 512 elementi per un totale di 4Kb per tabella 

Così ciascuna delle 4 tabelle è contenuta in una pagina di memoria 

**TTRB** è il registro che punta ala tabella a livello 0

![[Immagine 2023-04-02 181410.png]]