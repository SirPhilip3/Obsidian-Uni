# 19/11/2023

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

