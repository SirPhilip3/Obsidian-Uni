# 20/09/2023

## Cos'è un S.O.

Il **Sistema Operativo** è il software che controlla l'hardware 

Un **Sistema Operativo** è un programma che *gestisce e controlla l'esecuzione* di un insieme di applicazioni, agisce come *interfaccia* tra le applicazioni e l'hardware del calcolatore e *gestice le risorse* hardware

Un **Sistema Operativo** è quindi un :
+ **Macchina Astratta** :
	Nasconde i dettagli e le operazioni complesse ( *mascheramento* ) e presenta all'utente una macchina virtuale facile da usare ( *trasparenza* )
+ **Gestore di Risorse** :
	Deve gestire le risorse **HW** in modo da fornire le migliori prestazioni possibili 
### Modalità

+ **Utente** : Le applicazioni sono in maggior parte runnate in modalità *utente* 
+ **Kernel** : Il S.O. è per la maggior parte runnato in modalità *kernel*

## Storia dei Sistemi Operativi

#### 1° generazione ( 1945 - 1955 )

Caratteristiche principali :
+ Assenza **S.O.**
+ Programmazione in linguaggio macchina ( attraverso schede perforate ) o cablando i circuiti
+ Memorie estremamente limitate ( decine di numeri )

Limiti : 
+ Scarsa affidabilità
+ Chi gestiva la macchina era anche colui che la programmava
+ Complessità d'uso
+ Lentezza

#### 2° generazione ( 1955 - 1965 ) 

Caratteristiche principali : 
+ **Monoprogrammazione** : esecuzione di un *job* ( unità di esecuzione, programma o insieme di programmi ) alla volta
+ Uso di linguaggi ad alto livello : Fortran, Assembly
+ Programmazione attraverso schede perforate
+ Separazione tra programmatore e operatori
+ Semplici **S.O.** 
	+ *Single-stream batch-processing* o *Sistemi operativi batch*
		+ I programmi e i dati venivano caricati in sequenza su un nastro
		+ Spostati sul computer e eseguiti a lotti ( *Batch* )
		+ Ouput stampato su nastro 
		
![[Immagine 2023-09-20 173300.png]]

+ Utilizzo del **JCL** ( *Job Control Language* ) per lanciare batch o sottoprocessi example :

![[Pasted image 20230920175249.png]]

+ Esempio di utilizzo della memoria per un sistema batch

![[Pasted image 20230920175351.png]]
#### 3° generazione ( 1965 - 1980 )

Caratteristiche principali :
+ **Sistemi operativi batch**
+ **Multiprogrammazione** : 
	+ Più job in esecuzione *contemporanea*, 1 solo job può essere svolto per unità di tempo dalla CPU, quando un job richiede l'utilizzo dell' I/O, delle memorie o viene stoppato alla CPU viene assegnato un ulteriore job
+ Utilizzo di *circuiti integrati*
+ Utilizzo di linguaggi ad alto livello ( C )
+ Editor testuali e grafici
+ **CPU** scheduling ( scheduling dei processi per ottimizzarne il tempo di esecuzione )
+ **SPOOL** ( *Simultaneous Pheripherials Operation On-Line* ) 
	+ Esecuzione di job parallela ad operazioni di I/O
+ Memory partitions ( dovuta alla *multiprogrammazione* )

![[Pasted image 20230921130856.png]]

+ Sistemi **Timesharing**
	+ Variante della *multiprogrammazione* per supportare utenti multiplici
	+ Il tempo di *CPU* è diviso in *quanti di tempo*
		+ Alla fine di ogni *quanto* il job viene interroto e il prossimo *quanto* viene assegnato al prossimo job ( con più utenti diminuisce il tempo di risposta poichè ogni utente deve aspettare meno per l'esecuzione di un job )
		+ Frequenti *cambi di contesto* : richiedono tempo 
		+ Introduzione della **Memoria virtuale** per gestire in sicurezza i vari job ( nessun job dovrebbe accedere alla memoria di un altro job )
+ Sistemi **real-time** 
	+ Hanno una deadline entro la quale un processo deve essere terminato ( differenti algoritmi di *scheduling* )
	+ 2 tipologie di sistemi *real-time*
		+ **Hard real time** : la deadline è fissa , senza alcun margine 
		+ **Soft real time** : la deadline ha un delta dinamico entro il quale può essere termianto il job

Un sistema *timesharing* può anche essere *multiprogrammato*

Sviluppo dei protocolli **TCP/IP** ( *Transmission Control Protocol/Internet Protocol* )

#### 4° generazione ( 1980 - present )

Sviluppo del modello di elaborazione *Cliente/Servente* ( *Client/Server* ) 

Sviluppo del **Multithreading** : esecuzione di più istruzioni contemporaneamente ed in modo indipendente

Sviluppo di sistemi *Distribuiti* : Vari computer collegati ad una rete che cooperano per un obbiettivo comune 

Sviluppo di sistemi *Paralleli* : sistema costituito da un insieme di unità di elaborazione , condivione di risiorse tra di loro  

Utilizzo della teconologia a **oggetti** per sviluppare i sistemi operativi ( *Sistemi operativi orientati agli oggetti* , **OOOS** ) , consente modularità facilmente mantenibili e estensibili

Creazione del progetto **GNU** e **OSI** ( *Open Source Initiative* ) : 
+ Open source operating systems : *Linux* , *Apache Web server*
+ Migliora il debugging , testing e advancement del software ( visto che tutti possono lavorarci ) 
+ Adattabilità a vari ambienti di utilizzo

Creazione di **GUI** per migliorare l'esperienza utente 
Introduzione della tecnologia *plug-and-play*

#### 5° generazione ( 1990 - present )

Sviluppo della tecnologia per sistemi *mobili* ( Android , iOS ) 
	Considerando le limitazioni di questi :
	Risparmio energetico mantenendo prestazioni decenti

Sviluppo dell'**IoT**

## Componenti OS

Deve gestire componenti *hardware* e *software* : 
+ processori
+ memoria
+ memoria secondaria
+ I/O
+ processi
+ thread
+ file
+ database

### Processori

esegue codice in linguaggio macchina

presenza di *coprocessori* per compiti specifici ( es audio / video )

contengono *registri* ( memorie ad alta velocità vicine al processore , amntengono i dati immediatamenti necessari all'avanzamento di un processo ) 
	ci sono dei registri speciali : ( **PC** ( Program Counter ) , **SP** ( Stack Pointer ) , **PSW** ( [Program Status Word](https://en.wikipedia.org/wiki/Program_status_word) ) che contiene *flags* , bit di confronto quando si usano istruzioni di confronto o flags per **interrupt** di sistema ossia cambiamenti di contesto / errori / modalità del kernel )

lunghezza della *parola* -> lunghezza delle istruzioni ( supporate diverse lunghezze a seconda della macchina )

tempo di esecuzione misurazione in cicli ossia un'oscillazione completa di un segnale elettrico la cui lunghezza è fornita dal *clock* di sistema ( misurata in Hz )

La **CPU** ha 2 modalità di funzionamento :
+ *kernel* ( riservata per funzioni del sistema operativo come managing memoria etcc )
+ *utente* 
Per cambiare tra queste 2 modalità un'applicazione in modalità *utente* può usare l'istruzione **TRAP** per cambiare modalità in *kernel*

#### Miglioramento prestazioni

Le prestazioni di una **CPU** si possono calcolare attraverso la seguente fromula :
$$T = N_i/IPS$$
dove $IPS$ è :
$$IPS=F\times IPC=F/CPI$$
Dove :
+ T : è il tempo di esecuzione
+ $N_i$ : è il numero di istruzioni di un programma
+ IPS : è il numero di istruzioni svolte al secondo
+ F : è la frequanza di clock del processore
+ IPC : sono il numero di istruzioni per ciclo di clock
+ CPI : sono i cicli di clock per istruzioni

Il *T*empo di esecuzione può essere migliorato :
	- Aumentando F
	- Riducendo $N_i$ ( svolto realizzando diverse architetture es : CISC / RISC )
	- Aumentando gli IPC o diminuendo il CPI ( costruendo una *pipeline* o creando una *CPU superscalare* )

![[Pasted image 20231004220324.png]]

Per il miglioramento delle prestazioni possono essere implementati :
+ *Multithreading* ( hyperthreading )
	*una* CPU può mantenere lo stato di due *thread* ( più piccola parte eseguibile di un programma ) se il loro scambio avviene entro 1 nanosec ( in modo che sembrino concorrenti )
+ *Multi core CPU* 
	più processori completi ( *core* ) su un singolo chip 
	questi hanno la memoria L1 non condivisa e possono o no avere anche la memoria L2 condivisa

> [!warning] 
>  Se la memoria è condivisa bisogna fare attenzione che i *thread* non modifichino o accedino a memoria in conflitto 

#### Scheda madre

Scheda che contiene tutti i circuiti elettrici stampati per il collegamento dei vari componenti di un calcolatore inoltre contiene il :
+ **BIOS** ( *Basic Input Output System* ) Software I/O di basso livello per il boot del sistema e gestione delle risorse ( mantenuto in un chip a parte )
+ **Memorie**

### Memoria 

Vi sono vari livelli di memoria che permettono all'utente finale di avere l'impressione di possedere una macchina con molta memoria e veloce 

![[Pasted image 20231004222902.png]]

#### Registri

Sono interni alla CPU , molto veloci 

Capacità :
+ 32x32 bit per CPU a 32 bit
+ 64x64 bit per CPU a 64 bit

Alcuni registri importanti ( oltre a PC , SP , PSW ) :

+ *Base register* 
+ *Limit register*

Limitano inferiormente ( start , *base register* ) e superiormente ( fine , *limit register* ) un processo , limtando così gli indirizzi che può accedere e modificare 
Possono essere utilizzati a coppie per condiviere vari dati con vari programmi per cui :
+ la prima coppia di *base* e *register* (1) sono associati al limite del codice del programma
+ la seconda coppia (2) limita invece i *dati* su cu un programma può operare

![[Screenshot 2023-10-04 230745.png]]
#### Cache

Diversi livelli dal livello più basso , *L1* , interno alla CPU molto veloce ma molto piccolo ; a livelli più alti con sempre più memoria , più distanti dalla CPU e più lenti

La cache è fondamentale per l'aumento delle prestazioni del calcolatore , essa riduce infatti i tempi di accesso alla memoria memorizzando blocchi di dati vicini tra loro che hanno più probabilità di essere acceduti il più vicino possibile alla CPU

Risulta quindi fondamentale trovare le adatte :
+ *dimensioni*
+ *politiche* di inserimento e rimozione

Quando un dato è presente in cache si dice *cache hit*

Inoltre la cache è considerata *valida* quando rappresenta correttamente lo stato dei dati nella memoria principale

#### RAM

**RAM** ( *Random Access Memory* )

è una memoria *volatile* e ad acesso diretto

vari tipi di *RAM* : 
+ **DRAM** : ( dynamic ) richiede aggiornamenti continui del circuito per non perdere i dati
+ **SRAM** : ( static ) non richiede aggiornamenti ma è più lenta

La *RAM* è caratterizzata da una *banda* ossia quanti dati possono essere trasferiti per unità di tempo
#### ROM

*Read Only Memory* : 
	non volatile , veloce , economica , programmata dal produttore
#### EEPROM

Memoria *Flash* , *Electronically Erasable* :
	non volatile , riscrivibile , molto più lenta della *RAM*
#### CMOS

memoria volatile che principalmente mantiene dati come la data e l'ora

#### Dischi

