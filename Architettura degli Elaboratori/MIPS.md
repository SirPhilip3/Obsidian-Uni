Datapath a singolo ciclo MIPS: 

![[nM8IuyM.png]]

Istruzioni implementate:
+ **[lw](lw.md)** 
+ **[sw](sw.md)**
+ **[add](add.md)**
+ **[or](or.md)**
+ **[slt](slt.md)**
+ **[beq](beq.md)**

**Clock**: rising edge-triggered
I valori vengono scritti negli elementi sequenziali al passaggio da un livello basso ad uno alto, ciò ci permette di scrivere e leggere contemporaneamente da uno stesso elemento nello stesso ciclo di clock ( Datapath ottimizzato )

![[3-s2.0-B9780128124772000216-gr009.jpg]]

**Prestazioni** : Le prestazioni della CPU (MIPS) a singolo ciclo sono sono molto basse infatti , per mantenere l'integrità delle informazioni il ciclo di clock deve per forza essere lunga come la più lunga istruzione che il Datapath può eseguire; in questo caso la **lw** ( all'incirca 1000ps ); questo porta ad istruzioni più comuni che potrebbero essere svolte più velocemente a dover "rallentare"

## Pipeline

Divisione MIPS in Unità funzionali:

### IF ( Istruction Fetch )

+ Lettura dell'istruzione dall'indirizzo presente nel registro PC
+ Il PC viene incrementato

![[Immagine 2023-03-08 174223.png]]

Texe = 200 ps

### ID ( Instruction Decode & register file read )

+ L'istruzione viene scomposta nelle varie parti e decodificata
+ Lettura dei registri coinvolti nell'istruzione 

![[Immagine 2023-03-08 174730.png]]

Texe = 100 ps

### EX ( Execute )

3 Possibilità:
+ Calcolo operazione aritmetica ( add/or )
+ Calcolo indirizzi di memoria ( lw/sw )
+ Calcolo indirizzi branch ( beq )

![[Immagine 2023-03-08 175130.png]]

Texe = 200 ps

### MEM ( Memory Access )

+ Accesso alla memoria dati per leggere e scrivere un valore ( lw/sw )

![[Immagine 2023-03-08 175321.png]]

Texe = 200 ps 

### WB ( Write Back )

+ Scrittura nei registri ( lw )

![[Immagine 2023-03-08 175458.png]]

Texe = 100 ps

Per aumentare le prestazioni bisogna fare in modo che le **Unità Funzionali** vengano svolte tutte contemporaneamete ma su istruzioni sucessive ( **Instruction Level Parallelism** ) in questo modo ogni singol istruzione viene svolta nello stesso periodo di tempo rispetto alla CPU a singolo ciclo ma viene aumetato il **throughput**

![[Immagine 2023-03-08 184159.png]]

Per fare ciò basta inmpostare il clock a seconda dello stadio più lento ossia: 200 ps, mente nella CPU a singolo ciclo 1 operazione veniva svolta interamente in 1 ciclo di clock, che deve essere impostato secondo l'istruzione più lunga ossia una lw o 800 ps anche se altre istruzioni impiegano meno tempo come la Branch ( 500 ps ). 
Perciò nella CPU a singolo ciclo di fatto completiamo una istruzione ogni 800 ps mentre nella CPU con pipeline un'istruzione viene completata ogni 200 ps

Esempio:

Singolo ciclo: 2400 ps

![[Immagine 2023-03-08 192wee2e.png]] 

Pipeline: 1400 ps

![[Immagine 2023-03-08 200131.png]]

Speedup: $2400/1400=1.7$

La prima **lw** è più lenta rispetto a quella effettuata dalla CPU a singlo ciclo ( 1000 ps vs 800 ps) sucessivamente però con il riempimento della pipeline il risultato delle **lw** verrà salvato nei registri ogni 200 ps. Calcolando lo speedup ideale 
$$\lim_{x\to\infty} \frac{800n}{1000+200n} = 4 $$
Dove n sono il numero di **lw** , 800n poichè la cpu a singolo ciclo impiega 800 ps per ogni istruzione, 1000 + 200n poichè nella pipeline vi è un overhead (costo) iniziale , infatti perchè la pipeline sia efficente si deve avere un numero di istruzioni maggiori rispetto agli stadi della pipeline, in questo caso 1000 ps corrispondono alla prima operaziona che se presa singolarmente è più lenta rispetto alla cpu a singolo ciclo , sucessivamente però, per ogni ciclo di clock 200 ps viene fatta uscire dalla pipeline un'istruzione: aumento del **troughput**

Lo speedup è quindi , teoricamente , equivalente al numero di stadi di una pipeline.

---
## Prestazioni

$T_{seq}$ : Tempo di esecuzione di un'istruzione nella CPU a singolo ciclo
$T_s$ : Tempo di esecuzione di uno stadio nella pipeline
$n$ : numero di stadi della pipeline 
$$T_s=\frac{T_{seq}}{n}$$
$IC$ : Instruction Count, numero di istruzioni di un determianto programma
$T$ : periodo di clock del processore a singolo ciclo
$T'=\frac{T}{n}$ : Periodo di clock della CPU a pipeline

Tempo totale della CPU a singolo ciclo $IC*T$ 

Tempo di esecuzione CPU pipeline:

Overhead iniziale:

|1|2|3|4|5|
|---|---|---|---|---|
|istr1|---|---|---|---|
|istr2|istr1|---|---|---|
|istr3|istr2|istr1|---|---|---|
|istr4|istr3|istr2|istr1|---|---| 

A questo punto al pipeline è piena, al prossimo ciclo di clock inizierà di essere completata un'istruzione, l'overhead time è terminato ( 800 ps )

|1|2|3|4|5|
|---|---|---|---|---|
|istr5|istr4|istr3|istr2|istr1|
|istr6|istr5|istr4|istr3|istr2|

A questo punto esce dalla pipeline 1 istruzione ogni ciclo di clock ( 200 ps )

Tempo per riempire la pipeline : $(n-1)T'$
Tempo per esegiuire le istruzioni : $IC\cdot~T'$

Tempo totale  $$(n-1)\cdot~T'+IC\cdot~T'=(n-1)\frac{T}{n}+IC\cdot~\frac{T}{n}$$
Speedup: $$\frac{IC\cdot~T}{(n-1)\frac{T}{n}+IC\frac{T}{n}}=\frac{IC}{(n-1)\frac{1}{n}+IC\frac{1}{n}}=\frac{n\cdot~IC}{(n-1)+IC}$$
Con $IC$ molto grande
$$\lim_{IC\to\infty} \frac{n\cdot~IC}{(n-1)+IC}=n$$
Lo speedup risulta idelamente il numero degli stadi della pipeline, in realtà lo speedup effettivo è molto minore poichè bisogna considerare:
+ L'overhead ( IC non infinito)
+ Gli stadi non sono bilanciati $T_s>\frac{T_{seq}}{n}$
+ Vi sono le dipendenze tra istruzioni che provocano stalli nella CPU

Speedup con $T_s>\frac{T_{seq}}{n}$ 
$$\lim_{IC\to\infty}\frac{IC\cdot~T_{seq}}{(n-1)\cdot~T_s+IC\cdot~T_{s}}=\frac{T_{seq}}{T_{s}}$$
Infatti se $T_s=\frac{T_{seq}}{n}$ lo speedup risulta pari a $n$

---
## Implementazione

Ogni stage necessita dei valori calcolati dallo stage precedente, nel precedente ciclo di clock; ci basterà aggiungere dei registri intermedi tra gli stadi 

![[Immagine 2023-03-10 181756.png]]

Dobbiamo anche mantenere il PC nei registri intermedi 
Nella lw necessitiamo di mantenere nei registri anche l'indirizzo Write Register 

![[Immagine 2023-03-10 184615.png]]

## Controllo

![[Immagine 2023-03-10 185321.png]]

Nello stadio ID vengono calcolati i segnali di controllo per le istruzioni  sucessive, per questo devono essere propagati attraverso il datapath.

---
## Hazard

L’esecuzione dell’istruzione corrente dipende dai risultati dell’istruzione precedente, questo crea una criticità o **Hazard**

Effetto sulla pipeline:
+ Lo stadio della pipeline che ha scoperto l'**Hazard** , assieme agli stadi precedenti rimangono in **Stallo**, ossia rieseguono la stessa istruzione
+ Introduzione di **Nop** negli stadi seguenti della **pipeline**

Ciò crea uno spreco di cicli di clock

### Sructural Hazards

Un **Hazard struttutrale** si verifica quando un'istruzione ha bisogno di una risorsa che è già occupata da un'istruzione precedente.
Nel caso del MIPS ciò non può avvenire poichè l'**ISA** è stato progettato appositamente per il suo utilizzo in **pipeline**.
Un esempio di **Strucural Hazard** nel caso del MIPS sarebbe stato l'utilizzo di un'unica memoria per le istruzioni e i dati, infatti in questo caso sarebbe potuto accadere che un'istruzione avrebbe dovuto accedere in memoria e allo stesso tempo un'altra istruzione avrebbe dovuto svolgere lo stadio della **wb** creando un conflitto per l'accesso in memoria

### Data Hazards

Nascono quando un'istruzione dipende dal risultato di un'istruzione precedenteche si trova ancora all'interno della pipeline

Esempio
```armasm
add $s1, $t0, $t1
sub $s2, $s1, $s3
```

**sub** deve entrare in stallo finchè l'istruzione precedente non ha completato la scrittura di **$s1** nel register file.
Questo implica inoltre che 2 coppie di istruzioni con **Data Hazards** sono in **ordine di esecuzione relativo non modificabile** ( non è possibile modificare l'ordine delle istruzioni mantenendo inalterato il risultato finale )

3 tipi di **Data Hazard**

#### RAW ( Read after Write )

Quando un'istruzione legge un registro scritto da una istruzione precedente
```armasm
add $s0, $t0, $t1 //write $s0
sub $t2, $s0, $t3 //read $s0
```

Scrittura di un registro avviene allo stage 5 ( **WB** ) mentre la lettura avviene allo stage 3 ( **ID** )

Esempio: ( con register file non ottimizato )

![[Immagine 2023-03-13 082341.png]]

Lo stadio **ID** propaga 3 nop all'intero della pipeline, il controllo delle dipendenze tra registri avviene attraverso l'**Hazard detection unit** che propaga i segnali di controllo per codificare una nop e il **PC** non viene aggiornato in modo tale da ri-eseguire le stesse istruzioni nei cicli sucessivi.

Questo controllo può essere svolto anche dal compilatore aggiungendo delle istruzioni nop o istruzioni che non comportino dipendenze tra 2 istruzioni che provocano **RAW** 

##### Forwarding

Il nuovo valore è già disponibile allo stadio **EXE** ( subito dopo essere stato calcolato nel registro intermedio **EX/MEM** )

![[Immagine 2023-03-13 123631.png]]

Lo stadio **EXE** della sub preleva il valore salvato nel registro intermedio **EXE/MEM** invece di quello decodificato nello stadio **ID**

Posso anche prendere il valore dallo stadio intermedio **MEM/WB** allo stadio **EXE**

Implementazione:

![[Immagine 2023-03-13 124348.png]]

Nel caso della **lw** lo stallo è inevitabile poichè producono il valore da memorizzare nel registro target durante lo stadio **MEM** ( necessita almeno una nop )

#### WAW ( Write after Write )

Quando un'istruzione scrive un registro scritto da una istruzione precedente
```armasm
add $s1, $t0, $t1 //write $s1
sub $s1, $s2, $t3 //write $s1
```

Importante solo se la CPU è out-of-order ( può eseguire istruzioni in ordine diverso dall'originale )
In una CPU in-order l'unica cosa che può accadere è la sovrascrittura del registro, mentre nelle out-of-order il risultato finale può cambiare se invertiamo l'ordine delle istruzioni e ciò crea **Hazard**

#### WAR ( Write after Read )

Quando un'istruzione scrive un registro letto da una istruzione precedente
```armasm
add $t0, $s1, $t1 //read $s1
sub $s1, $s2, $t3 //write $s1
```

Importante solo se la CPU è out-of-order
In una CPU in-order l'unica cosa che può accadere è la sovrascrittura del registro, mentre nelle out-of-order il risultato finale può cambiare se invertiamo l'ordine delle istruzioni e ciò crea **Hazard**

#### RAR ( Read after Read ) 

Quando un'istruzione legge un registro letto da una precedente istruzione
```armasm
add $t0, $s1, $t1 //read $s1
sub $t4, $s1, $t3 //read $s1
```

Poichè leggere i registri non causa il cambiamento di una varaibile ciò non crea **Hazard**

### Control Hazards 

Avvengono quando una istruzione di salto ( **beq**/**bne**/**slt** ), infatti bisogna attendere che le istruzioni di branch abbiano calcolato l'indirizzo di salto e aggiornato il **PC** , pre fare il fetch dell'istruzione corretta 

Soluzioni:

#### Naive
 Inserire 3 nop nella pipeline dopo ogni istruzione branch
 
#### Speculativa
+ assumiamo che il branch è sempre not taken
	+ se il branch è not taken abbiamo già le sucessive 3 istruzioni nella pipeline 
	+ se il branch e taken le 3 istruzioni entrate nella pipeline non hanno ancora modificato i registri, basta quindi annullare il loro effetto modificando i segnali di controllo con delle nop

#### Delayed branch
anticipiamo il calcolo del **PC** e il confronto dei registri della **beq** 
Invece di usare l'**ALU** usiamo un circuito specializzato:
![[Immagine 2023-03-13 130814.png]]
In questo caso il controllo per la branch avviene nello stadio **ID** ciò comporta che solo  l'istruzione sucessiva è entrata nella pipeline, in **MIPS** questa istruzione viene sempre eseguita
Le istruzioni che vengono sempre eseguite dopo una branch viene chaimato **delay slot**, questo aumenta all'aumentare delle dimensioni della pipeline, e può essere riempito con una nop o con delle altre istruzioni  

Questo crea problemi con il **forwarding** in quanto necessito dei valori corretti dei registri da confrontare già nel 2 stadio ( **ID** ), il **forwarding** può solo copiare valori verso **EXE** non **ID** per questo necessitiamo di inserire delle nop 

![[Immagine 2023-03-13 133057 1.png]]
Il registro $4 sarà disponibile solo al termine di **EXE**, non può essere usato subito dopo nello stadio **ID** della **beq**, per questo dobbiamo inserire una nop
![[Immagine 2023-03-13 133207.png]]

Nel caso della **lw** necessitiamo di 2 nop

#### Branch Prediction

Lo stage **IF** procede con il fetch del ramo più probabile.

##### Naive

Prediciamo che la branch sia sempre not-taken, ossia prediciamo la prossima istruzione da eseguire come PC+4, se la branch è taken è necessario annullare le istruzioni che sono state svolte nel frattempo ( **branch penalty** ), molto svantaggioso per pipeline profonde

##### Dynamic Prediction

Viene utilizzata una **history table** , indicizzata tramite indirizzi delle istruzioni **beq** contiene l'indirizzo all'istruzione sucessiva al salto in caso di branch taken ( calcolato durante la prima esecuzione ), uno o più bit di stato per memorizzare il risultato dell'esecuzione di ciascun salto 

###### Predittore con stato a 1-bit

Se l'indirizzo dell'istruzione è presente nella **history table** allora considero il bit di stato, se taken allora **PC** = indirizzo di branch presente sulla **history table** altrimenti PC=PC+4

![[Immagine 2023-03-14 171004.png]]

Caso dei loop innestati
```
Outer:{
	Inner{
	
	beq , , Inner
	}
beq , , Outer
}
```

Inner Loop

taken = 1, not-taken = 0
Pattern:      111110111110111110....
Prediction: 1111110111110111110....

Doppio errore nella predizione ( sarebbe più probabile che la beq interna sia sempre taken )

###### Predittore con stato a 2-bit

![[Immagine 2023-03-14 171622.png]]

Necessita di 2 predizione sbagliate per cambiare stato in not-taken

Pattern:      111110111110111110....
Prediction: 111111111111111111....

É comunque necessario la presenza di un'**Hazard detection unit** nello stadio **ID** , per individuare eventuali errori che possono essere commenssi dal **Branch predictor**

### Eccezioni e Interruzioni ( Interrupts )

#### **Eccezioni** 

Cambiamento del flusso delle istruzioni a causa della CPU
+ Problemi nell'esecuzione di un istruzione all'interno di un programma:
	+ Overflow
	+ Istruzione non valida
	+ Page fault
	+ TLB miss


#### **Interruzioni**

Cambiamento del flusso delle istruzioni per causa esterna ( **IO** )
Provocato da periferiche per comunicare alla CPU il verificarsi di un evento

#### Gestione delle eccezioni/interruzioni

+ **Interrompere** l'esecuzione del programma corrente
+ **Salvare** lo stato di esecuzione del programma corrente, nelle eccezioni il **PC** viene salvato in un registro speciale **Exeption Program Counter** ( **EPC** ) 
+ **Trasferire** il controllo al sistema operativo impostando il **PC** ad un indirizzo specifico , una volta gestito l'eccezione l'esecuzione può riprendere

Per capire che eccezione si è verificata:
+ **CAUSE register** registro che contiene un codice numerico che identifica l'eccezione ( MIPS )
+ **Vectorized interrupts** il registro a cui si salta dopo un'eccezione dipende dall'eccezione stessa

MIPS salva solo il **PC** è compito del Sistema Operativo salvare altre parti dello stato corrente del programma

#### Eccezioni in pipeline

Altra forma di **Control Hazard** 
Bisogna:
+ Annullare le istruzioni che sono entrate nella pipeline subito prima che l'**eccezione** si verificasse inserendo delle **nop** 
+ Eccezioni Aritmetiche rilevate nello stadio **EXE**, quindi anche lo stadio **EXE** deve poter mettere in stallo la CPU

Problems:
+ Esssendo che nella pipeline vengono svolte più istruzioni contemporanemente potrebbero verificarsi più **eccezioni contemporaneamente** ( nello stesso ciclo di clock ), è necessario quindi implementare un sistema di **gestione delle priorità delle eccezioni**
+ **Interrupt** non sono dovute a istruzioni specifiche ma dall'**IO**
+ Eccezioni posso verificarsi nell'**handler delle eccezioni**
---
## Processori superscalari

Per aumentare ulteriormente il parallelismo è possibile replicare componenti della **pipeline** in modo tale da poter immettere più istruzioni alla volta nella pipeline ( **Multiple issue** )

Esempio:
Con un **multiple issue** a 4 vie ( 4 istruzioni contemporaneamente ) CPI teroico: 0,25

2 tipi di **multiple issue**

### Static Multiple issue

Sfrutta il compilatore per raggruppare le istruzioni ( **issue packet** o **Very Long Instruction Word (VLIM)** ), compilatore risolve eventuali **hazard** presenti nell'**issue packet** 

Vantaggi:
+ compilatore può effettuare ottimizzazioni più complesse
+ **Branch prediction** non più implementato nella CPU ( risparmio di transistor )
+ ottimizzazione ha costo una tantum ( alla compilazione del programma )

Svantaggi:
+ non tutti gli stalli sono predicibili a compile time
+ **Dynamic branch prediction** non disponibile
+ codice prodotto dipende dalla specifica CPU, se lo si vuole portare in un'altra CPU, con lo stesso ISA è necessario un recompile

### Dynamic Multiple issue

CPU decide quante e quali istruzioni immettere nella pipeline ad ogni ciclo di clock

2 versioni:
+ **in-order**: la CPU decide solo quante istruzioni indipendenti vengono lette dal flusso sequenziale ogni ciclo di clock
+ **out-of-order**: la CPU può decidere l'ordine delle istruzioni per massimizare il parallelismo

Pipeline divisa in 4 macro unità:

1. Fetch and decode unit
	  Carica le istruzioni **in-order**, le decodifica, le invia alle reservetion stations a seconda dell'operazione da effettuare
2. Reservation stations
	  Controllano la presenza di tutti gli operandi in lettura dell'istruzione e la inviano per l'esecuzione ( **out-of-order** ) alle functional units salvando il risultato su un registro temporaneo
4. Functional units
         Svolge le istruzioni presenti nelle reservation stations
6. Commit unit
	  Scrive i valori calcolati dalle varie operazioni rispettando l'ordine delle dipendenze

![[Immagine 2023-03-14 183639.png]]

### Dipendenze e scheduling dinamico

Le uniche dipendenze che provocano stalli sono le **RAW**

**WAW** e **WAR** risolte eseguendo le operazioni in parallelo e scrivendo i risultati in ordine (**in-order comit**)

Esempi

#### WAW

```armasm
add $s1, $t0, $t1
sub $s1, $s2, $s3
```

$s1 scritto sia da add che da sub

Non è possibile cambiare l'ordine delle operazioni ma è sufficiente solgere la add e sub contemporaneamete e svolgere la stadio **WB** in-order

#### WAR

```armasm
add $t0, $s1, $t1
sub $s1, $s2, $s1
```

$s1 scritto dalla sub dopo essere stato letto dalla add

Non è possibile cambiare l'ordine delle operazioni ma è sufficiente solgere la add e sub contemporaneamete e svolgere la stadio **WB** in-order