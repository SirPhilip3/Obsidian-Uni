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
+ scarsa affidabilità
+ chi gestiva la macchina era anche colui che la programmava
+ complessità d'uso
+ lentezza

#### 2° generazione ( 1955 - 1965 ) 

Caratteristiche principali : 
+ **Monoprogrammazione** : esecuzione di un job ( unità di esecuzione, programma o insieme di programmi ) alla volta

#### 3° generazione ( 1965 - 1980 )

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

