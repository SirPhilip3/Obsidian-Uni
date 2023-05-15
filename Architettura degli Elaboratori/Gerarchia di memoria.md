## Tipologie di memoria

### SRAM ( Static Random Access Memory )

6 transistors per ogni bit da memorizzare ( 4 per memorizzare il dato 2 per accedere )

Caratteristiche 
+ Veloci
+ Area occupata per bit alta
+ Energy inefficient
+ Non richiedono refresh

### DRAM ( Dynamic Random Access Memory )

1 transistor e 1 condensatore per bit

Caratteristiche
+ più lente delle **SRAM**
+ Area occupata minore rispetto alle **SRAM**
+ Energy efficient
+ Necessitano di refresh ( Dynamic )

Intervallo per il refersh ( lettura e riscrittura della memoria ): 64 ms
Refeshe effettuato su una riga alla volta; se venisse svolto cella per cella occuperebbe troppo tempo non permettendo altre operazioni

#### SDRAM ( Syncronized DRAM )

Clock sincronizzato con CPU per leggere e scrivere

#### DDR-SDRAM ( Double Data Rate SDRAM )

Possono trasferire sia su fronte di discesa che di salita del clock ( raddopiamento della banda ) 

### flash

Tipo particolare di Elettrically Erasable Programmable Read-only Memory ( EEPROM )

Usato negli **SSD** ( Solid State Drives ) con **flash NAND** ( floating gate transistors )

Non richiedono refresh e mantengono i dati anche senza alimentazione

### NAND

5 tipologie, si differenziano a seconda delle quantità di bit memorizzabili
+ **SLC**: le più costose e veloci
+ **MLC**
+ **TLC**
+ **QLC**
+ **PLC**
+ **3D NAND**: strati multipli di celle di memoria su pile verticali, maggiore capacità di memoria rispetto a dimensioni più compatte

**Usura**:

Si usurano nel tempo soprattuto a causa dei cicli di scrittura:
**Wear leveling**: controller dedicato che distribuisce le scritture in modo uniforme su tutta la memoria, introduzione di overhead che diminuisce leggermente le performance

### Hard Disk

Caratteristiche:
+ estremamente capienti 
+ molto economici
+ performance peggiori
---
## Gerarchie

Le memorie più veloci utilizzate vicino alla CPU, le memorie più lente ma più capienti utilizzate a cascata per memorizzare i dati che vengono utilizzati meno di frequente.
**Obiettivo**: velocità di accesso della memoria del livello più vicino alla CPU con la capienza di quella al livello più distante 

![[Immagine 2023-03-16 173316.png]]

### Principio di località

I programmi accedono ad una porzione di memoria piccola rispetto allo spazio di indirizzamento

Tipi di località:
+ **Località temporale**: Quando si fa riferimento ad un dato c'è la tendenza a far riferimento allo stesso dato dopo un breve periodo di tempo ( cicli )
+ **Località spaziale**: Quando si fa riferimento ad un certo dato c'è la tendenza a far riferimento ad altri dati che hanno un indirizzo vicino al corrente ( accesso agli elementi di un array

I dati sono sempre copiati tra 2 livelli adiacenti alla volta, i livelli sottostanti contengono sempre una copia dei dati dei livelli superiori

Unità di dati minima : Blocchi ( minimo 1 byte , 8 bit )

Definizioni:

**hit**: i dati sono presenti in un blocco immediatamente superiore; else **miss**

**hit rate**= $\frac{hit}{accessi}$
**miss rate**= $\frac{miss}{accessi}$ = 1-**hit rate**

**hit time**: tempo di accesso al livello superiore, comprende overhead per capire se il tentativo porterà a **hit**              o **miss**

**miss penalty**: tempo necessario a sostituire un blocco al livello superiore ( più vicino all CPU ) con uno al livello inferiore e a passare tali dati alla CPU

---
## Memoria Cache

Memoria tra CPU e RAM che sfrutta il principio di località degli accessi

I blocchi della cache sono normalmente un multiplo di 2

### Mapping

Problemi:

+ Determinare se un determianto blocco è presente in cache
+ come individuarlo
+ se un blocco non è presente in cache dove lo scrivo in cache dai livelli inferiori

Tipologie di **Mapping**

#### Direct-mapped cache

Funzione per determinare l'address della cache da address di memoria

< address >mod< # blocchi cache>
equivale a prendere i primi log$_{2}$<# blocchi cache> bit dall'indirizzo
equivale a fare lo shift verso sinistra di n bit

Esempio:

![[Immagine 2023-03-16 174119.png]]

cache da 8 blocchi (log$_2$ 8=3)
address: 00101
cache address: 00101%8 -> 101

Indirizzamento con più di 1B per blocco

![[Immagine 2023-03-16 174223.jpg]]

+ Calcolo block address = address / block size
+ Calcolo **block index** = block address % # **cache blocks**
+ **byte offset** = log$_2$ ( **block size** )

##### Tag

Più blocchi di memoria indirizzano ad uno stesso blocco nella cache, per distinguerli utilizziamo i bit più significativi ( **Tag** ) 

Tag = block address / # cache blocks

##### Valid bit

Utilizzato per identificare un blocco con informazioni valide (allo startup la cache è inizializzata a caso però ogni blocco è comunque decodificabile, solo quando inseriamo un valore in un blocco diventa  un'informazione valida)

##### Dimensione ottimale blocco

Aumento dimensioni blocco:
+ diminuzione **miss rate** ( utiliziamo maggiormente la località spaziale )
+ aumento del **miss penalty**
+ aumentando le dimensioni del blocco, esso non viene utilizzato completamente: spreco nell'utilizzo della cache, genera inoltre conflitti con altri blocchi utilizzati

![[Immagine 2023-03-16 181632.png]]

Il **block size** ideale risulta nel mezzo

##### Miss rate

Vi sono 2 tipi di cache:
+ Instruction cache
+ Data cache

Instruction cache contiene le istruzioni, queste essendo svolte sequenzialmente possono godere maggiormente della **località spaziale** mentre la data cache ne beneficia di meno in quanto i dati non sono scritti e letti in modo sequenziale ( si basa sull'indirizzo ), per questo l'**instruction miss rate** diminusce maggiormente con l'aumentare della **block size** rispetto al **data miss rate**

|Program|Block size|Instruction miss rate|Data miss rate|
|---|---|---|---|
|gcc|1|6.1%|2.1%|
||4|2.0%|1.7%|
|spice|1|1.2%|1.3%|
||4|0.3%|0.6%|

### Conflict Managment

Se il blocco da portare in cache deve essere sovrascritto su un altro blocco di dati già presente in cache cosa viene fatto al vecchio blocco? :

+ Vecchio blocco acceduto solo in lettura può essere rimpiazzato
+ Se è stato scritto, essendo una copia dei dati al livello inferiore, bisogna stabilire delle **politiche di coerenza tra livelli di memoria** ( bisogna che sia coerente anche nei livelli inferiori )

#### Politiche di coerenza

##### Write through

Ogni scrittura nella cache implica anche la scrittura dei livelli sottostanti

Vantaggi:
+ Il blocco in conflitto può essere rimpiazzato
Svantaggi:
+ Le scritture sono molto lente ( degradazione delle performance )

**Write through con write buffer**

Utilizzo di un **write buffer** come memoria veloce tra cache e memoria:
I blocchi sono scritti temporaneamente nel **write buffer** in attesa di essere scritti in memoria, il processore può intanto proseguire senza attendere la scrittura ( a meno che il buffer non si riempia )

Se la frequenza con cui la memoria può completare la write è minore della frequenza con cui la CPU genera write , il write buffer verrà riempito e a quel punto le write saranno lente quanto write senza buffer

##### Write back

Solo quando un blocco deve essere rimpiazzato questo viene scritto anche nei livelli sottostanti
Il blocco quando viene scritto viene segnato come **dirty**, assegnandoli un bit di stato

Vantaggi:
+ In assenza di conflitti non vi è overhead
Svantaggi:
+ La sostituzione di un blocco in conflitto è più lenta poichè richiede la scrittura del blocco al livello sottostante

### Hit/Miss

#### Read-hit

+ Come conseguenza di **lw** e **Instruction Fetch**
+ Nessun rallentamento in memoria

#### Read-miss

+ Stallo della CPU finchè la lettura del blocco non avviene
+ Con il dato in cache se:
	+ **Instruction cache miss**: ripeti fetch dell'istruzione
	+ **Data cache miss**: completa l'accesso al dato ( **lw** )

#### Write-hit

+ Come conseguenza di **sw**
+ 2 casi per le **politiche di accesso**:
	+ **Write through**: dati scritti in cache e memoria
	+ **Write back**: dati scritti solo in cache e assegnato lo stato **dirty**

#### Write-miss

2 casi per le **politiche di accesso**:
+ **Write back**: 
	+ Controllo mette in stallo la CPU
	+ Lettura del blocco dalla memoria in cache ( **write allocate** )
	+ Completamento dell'istruzione di **sw** in cache
+ **Write through**:
	+ Controllo mette in stallo la CPU
	+ Scrittura avviene direttamente in memoria

### Prestazioni

Calcolo delle prestazioni in presenza della cache 

CPU time = (execution cycles + stall cycles) * cycle time

stall cycles = IC * miss ratio * miss penalty( unico per scritture e letture, sarebbe differente, semplicità )

Miss ratio:
+ Instruction miss ratio
+ Data miss ratio:
	+ Write miss ratio (sw)
	+ Read miss ratio (lw)

IC * miss ratio = numero di istruzioni che provocano miss

CPI$_{reale}$ = CPI$_{ideale}$ + cicli di stallo medi per istruzione

Aumento delle prestazioni: 
+ Ridurre il miss ratio
+ Ridurre il miss penalty

Se lasciassi immutato il sottosistema memoria e velocizzassi la CPU:

+ Tempo assoluto di penalty _Invariato_
+ Miss ratio _Invariato_
+ Miss penalty -> **Dipende de come è stata velocizzata la CPU**
+ IC _Invariato_
+ CPI$_{ideale}$ -> **Dipende da come è stata velocizzata la CPU** 

Velocizzazione CPU:
+ Modifica organizzazione interna
	+ Diminuisco il CPI$_{ideale}$
	+ Miss penalty rimane invariato
+ Aumento frequenza di clock
	+ CPI$_{ideale}$ rimane invariato
	+ CPI$_{reale}$ aumenta poichè il miss penalty aumenta ( il tempo di accesso alla memoria è lo stesso ma visto che ogni ciclo di clock è più corto avremo bisogno di più cicli di clock per svolgere lo stesso lavoro )

Legge di Amdahl:

Exe time after improvment = Exe time effected by improvement / Amount of improvment + Exe time unaffected by improvment

--- 
### Cache associativa

**Completamente associativa** : ogni blocco di memoria puù essere associato con un blocco qualsiasi della cache, la ricerca nella cache non viene effettuata scorrendo tutti i possibili blocchi

Ciascun indirizzo di memoria viene mappato nel primo blocco libero senza una funzione di mapping

Per cercare il blocco richiesto occorre scorrere l'intera lista:   _Inefficente_ 

Soluzione:
**Associatività su insiemi**

#### 2-way set associative

![[Immagine 2023-03-21 190447.png]]

Cache organizzata in insiemi da 2 blocchi ( vie ) ciascuno:
+ La scelta dell'insieme avviene con una funzione di mapping
+ La scelta della via avviene come nella cache **completamente associativa**

La cache **fully associative** ha un numero di vie pari al numero di blocchi

#### Miss

Nella cache associativa 2 casi poichè non indentifichiamo in modo univoco un blocco attraverso una funzione ma solo un insieme:
+ Se nell'insieme è presente un blocco libero viene usato per risolvere il miss
+ Se tutti i blocchi sono occupati dobbiamo sciegliere il blocco da sostituire

**Politiche di rimpiazzamento dei blocchi**:
+ Causale
+ Least Recently Used ( **LRU** )
	+ Rimpiazzato il blocco che è stato usato meno di recente
	+ Utilizzo di ulteriori bit per memorizare quanto tempo un blocco non viene acceduto

Esempio: 
Block address = [0,8,0,6,8]

**Cache Diretta**

Cache address = [0%4=0; 8%4=0; 0%4=0; 6%4=2; 8%4=0]

![[Immagine 2023-03-22 083005.png|630]]

**Cache 2-way (LRU)**

Cache address = [0%2=0; 8%2=0; 0%2=0; 6%2=0; 8%2=0] (tutti in insime 0)

![[Immagine 2023-03-22 083506.png]]

**Fully associativie**

![[Immagine 2023-03-22 083626.png|630]]

Benefici maggiori per cache di piccole dimensioni poichè nel caso diretto avremo un miss rate molto alto

![[Immagine 2023-03-22 083848.png]] 




