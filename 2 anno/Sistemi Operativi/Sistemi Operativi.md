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

### Storia dei Sistemi Operativi

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
+ **CPU** scheduling
+ **SPOOL** ( *Simultaneous Pheripherials Operation On-Line* ) 
	+ utilizzato per
#### 4° generazione ( 1980 - present )

#### 5° generazione ( 1990 - present )




cpu state:
user - supervisor

scheduling

----
OS : 
verso l'alto
- macchina astratta
	- user UI
	- programmi da eseguire
verso il basso
- gestore di risorse
	- gestione HW
	- gestione os, mem virtuale

interfaccia tra utente e macchina fisica ( HW , os ) , illusione di macchia "ideale"

gestione delle risorse : performance

--- 
Definizione

SF che controlla l'HW
gestisce e controlla l'esecuzione di un insieme di applicazioni, interfaccia tra app e hw, gestione risorse hw

process possono essere : 
+ user ( app )
+ kernel ( OS )

Macchina estesa : nasconde dettagli e operazioni che devono essere eseguite
 - se avvengono dei malfunzionamenti l'utente non può svolgere nessuna diagnostica
 - in generale vantaggio perchè l'utente non necessita di sapere , rende indipendente le applicazioni dai dettagli 

Gestore di risorse rispetto a spazio e tempo ( dipende dal processo )

multiprogrammazione : gestione dei job a differenza di utilizzo hw ( cpu , memoria , perifercihe )

