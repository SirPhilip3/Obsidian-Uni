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