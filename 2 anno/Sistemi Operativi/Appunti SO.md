# Appunti 

## 14/11/2023

minor nujmero di page fault = seleziono pagina a cui verra fatto riferimento in futuro

+ Rand ( scielgo pagina random )
+ FIFO
+ LRU ( least recently used ) suppongo che la pagina a cui ho fatto riferimento più tardi non verrà riferita in futuro
+ LFU ( least frequently )
+ NFU ( not frequently )
+ Second-chance
	+ FIFO , guarda bit di riferimento della pagina più vecchia , se è stata modificata allo viene tolta altrimenti viene considerata come appena arrivata , la mantengo
	+ le pagine più riferite tendono a non essere mai sostituite
+ clock
	+ come seconda chance ma utilizzo al posto della fifo una lista circolare
	+ quando abbiamo la 
+ far
	+ riferimenti tra le pagine rappresentati in un grafo ,
	+ scieglie per sostituzione la pagina più lontana da qualsiasi pagina che sia stata referenziata 

Working set 

Un programma non usa sempre tutte le pagine , i riferimenti alla memoria sono concetrati in un insieme , se mantengo in memoria il working set avrò il minimo numero di page fault  

qual'è il numero minimo di pagine del working set per avere la massima efficenza ( minor numero di page fault ) oltre quello il numero id page fault si stabilizza

la percentuale di page fault dimnuisce in modo es mi basterà avere un % di apgine in memoria relativamente basse per avere un page fault rate accettabile 

la finestra di pagine che possono essitere nel working set varia nel tempo ( insieme di pagine riferite precedentemente ad un tempo t )

grandezza ws dipende da :
+ grandezza finestra 
+ grandezza del processo

la dimensione della finestra può essere al massimo la dimensione intera del programma

obbiettivo finale : evitare scelte sbagliate 

nella pratica approssimazioni : 
+ working set pagine refernziate negli ultimi n secondi

Working set e clock
+ utilizzo di clock per la sostituzione delle pagine

Page fault Frequency ( PFF )
+ Si regolano le pagine presenti in memoria  solo dopo che accade un page fault e a seconda della frequenza con cuoi il processo fa page fault

Si potrebbero rilasciare pagine dalla memoria preventivamente quando si rileva che non verrano più utilizzate

### Dimensione page

+ pagine più *piccole*
	+ più pagine per processo
	+ minor frammentazione interna
	+ può ridurre la memoria necessaria per il ws, c'è meno spreco di memria in quanto con pagine grandi una pagina potrebbe non essere utilizzazata completametne
	+ minor preco di memoria
+ pagine più *grande*
	+ riduce numero di operazioni di IO
+ pagine di diverse dimensioni
	+ possibile frammentazione esterna ( come con partizioni variabili ) 

comportamento processo 
	in poco tempo si fa riferimento a molte pagine 

Strategia globale ( riferimento a tutti i processi ) vs Locale ( all'interno del processo )

se un processo ha bisogno di una pagina potrebbe andare a togliere una pagina da un altro processo 

Linux 

Utilizza LRU con 2 liste : 
+ pagine attive 
+ pagine inattive -> state usate ma ora non vengono referenziate 

per sostituire una pagina scelgo dalle pagine inattive

*segmentazione* : blocchi di dimensione differente , hanno un significato logico ( un programma etcc ) 
un processo può non a vere tutti i segmenti in memoria , se mi serve qualcosa deve essere caricato in memoria principale

ho bisogno di un mapping dei segmenti con address 

address virtuale = s (segmento)+ d (displacement)

traduzione : n° segmento matchato nella mappa dei segmenti ritorna l'address reale 

anche qui abbiamo il bit di residenza 
ci sarà anche la lunghezza del segmento poichè ognuno è diverso fra loro , controllo di overflow ossia che il displacement non mi porti fuori dal segmento 

bit di protezione -> lettura scrittura other

chiave di protezione -> se la chiave per il processore e il blocco richiesto sono gli stessi allora il processo può accedere alla memoria







## 28/11/2023

blocco indice contengono un elenco di puntatori che indicano i blocchi di dati possiamo avere vari livelli di blocchi indice 

blocchi indice vicini ai blocchi dati in modo da accedere velocemente tra i blocchi indice e  i blocchi dati

in UNIX blocchi indice detti i-node hanno varie informazioni : 
+ Proprietario
+ dimensione
+ data creazione
+ data modifica
+ indirizzi blocchi dati
+ indirizzi blocchi indice

-> NTFS

gli attributi legati ai file sono contenuri direttamente nella riga delle directory (NTFS) o negli i-node in UNIX

nomi dei file 
+ limite massimo ( perdita memoria se non lungo max )
+ lunghezza varaibile (carattere speciale indica la fine)
+ utilizzo dell' heap per memorizzare i nomi -> puntatori per nomi

condivisione files 

attraverso link ma necessito di un caounter per determinare il numero di utilizzatori , per evitare incoerenza se condividiamo il file questo non viene 'eliminato' alla sua cancellazione

Gestione spazio libero

collegati come per un file FIFO queue
oppure utilizzo mappa di bit ogni bit corrisponde ad un blocco di memoria

per diversi utenti  utilizzo di un record di quota per ogni utente 

backup e recovery 

backup -> copie ridondanti delle informazioni 
recovery -> recupero delle informaizoni di sistema dopo un errore di sistema

backup -> fisico copia bit a bit
			-> logico memorizzare solo ciò che ha senso ( backup incrementali memorizzano solo i dati che sono cambiati )

backup copresso 
