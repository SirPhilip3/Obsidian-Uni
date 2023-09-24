# 18/09/2023

## Sistema Informativo

Sistema per la : 
+ Acquisizione
+ Archiviazione 
+ Elaborazione
+ Distribuzione 
delle informazioni necessarie alle attività dell'azienda

![[Immagine 2023-09-19 130447.png]]
## Sistema Informatico

+ Sistema informatico : insieme delle tecnologie infromatiche a supporto delle attività di un organizzazione
+ Sistema informativo automatizzato : parte del sistema informatico che raccoglie, elabora , archivia e scambia le informazioni usando un sistema informatico

## Infromazioni 

Nei sistemi informatici le **informazioni** vengono rappresentate in modo essenziale attraverso i **dati**
+ **Informazioni** : elemento che consente di a vere conoscenza più o meno esatta di situazioni
+ **Dato** : ciò che è immediatamente presente alla conoscenza , priva di ogni elaborazione

## Storia 

+ **'60** : Sistemi informatici settoriali 
	+ **Autorizzazione di operazioni ripetute** : Elaborazione sistematica e ripetuta di grandi quantità di dati  es : calcolo paghe, emeissione fatture
	+ **Supporto alle attività di gestione** 
	+ **Tecnologia dei sistemi di gestione di archivi** ( file processing systems - FPSs )

Difficoltà : 
+ nessuna integrazione dei stati
+ duplicazioni e incoerenze
+ difficoltà nel collegare dati settoriali

+ **'70** : Sitemi informatici per l'organizzazione
	+ **Sistemi di gestione di basi di dati** ( DBMSs ) 
	+ Caratteristiche : 
		+ **Integrazione dei dati** : unica raccolta di dati comuni 
			+ Disponibilià 
			+ Limitazione delle ridondanze 
			+ Efficienza
		+ **Flessibilità**  :
			+ **Database auto-descrittivi** : I programmi applicativi non sono tenuti a conoscere la struttura della base infromativa in quanto lo schema della struttura del **DB** è parte del **DB** stesso, e a questa struttura i programmi applicativi possono accedere

+ **'80** : Servizi infromati per la pianificazione strategica
	+ Supporto alla direzione
	+ Data Warehouse, Data Mining

## Sistemi informatici operativi

Attività strutturate e ripetitive ( calcolo paghe, emissione fatture , magazzino )

Elaborazioni su DB : **OLTP** ( **On-Line Transaction Processing** ) 
Operazioni svolte da processi operativi : 
+ Predefinite , semplici
+ Coinvolge pochi dati
+ Dati in dettaglio , aggiornati

## Sistemi informatici direzionali

Necessari per la direzione medio-alta dell'azienda
+ **analisi storiche**
+ **produzione di rapporti di sintesi** ( con differenti livelli di dettaglio )

DB operativi inadatti poichè :
+ lo svolgimento di operazioni complesse e su grandi quantità di dati rallenterebbero le funzioni operative

Per questo si utilizzano **Data Warehouse** che lavorano su : 
+ dati storici
+ dati di sintesi
+ dati aggregati

Supporto ai processi decisionali , di controllo sulle prestazioni aziendali

Elaborazioni su **DW** : **OLAP** ( **On-Line Analytical Processing** )
+ Operazioni complesse e casuali
+ Operazioni su grandi quantità di dati
+ Dati solo in lettura
+ Dati aggregati, storici, anche non attuali

![[Pasted image 20230920155522.png]]

---
# 22/09/2023

## Base di Dati

In generale : una qualsiasi raccolta di dati permanenti gestiti tramite un elaboratore elettronico

_Definizione_ : Una **Base di Dati** è una raccolta di *dati* permanenti , gestiti da un elaboratore elettronico , suddivisi in 2 tipologie :
+ **Metadati** : Definiscono lo schema della **B.D.** ( schema è creato prima dell'inserimento dei dati ) e descrivono :
	+ Struttura dei dati
	+ Operazioni eseguibili sui dati
	+ Restrizioni sui valori ammissibili ( **Vincoli di Integrità** )
	+ Autorizzazioni per utenti 
	I *Metadati* / lo schema dei dati è indipendente dalle applicazioni che usano la base di dati
+ **Dati** : rappresentazioni di certi fatti conformi alle definizioni dello schema ( *metadati* ) , caratteristiche :
	+ Organizzati in *insiemi omogenei*  
	+ Vi sono *relazioni* tra insiemi ( descritte nei *metadati* )
	+ Struttura dei dati : **modello dei dati** :
		+ ad **oggetti**
		+ **relazionale**
	+ Sono *permanenti* e *molti* ( non possono essere gestiti in memoria primaria )
	+ Possono essere utilizzati **contemporanemente** 
	+ Sono **protetti** da : 
		+ accessi non autorizzati 
		+ corruzioni dovuti a malfunzionamenti hardware e software
	+ Sono accedibili tramite **transazioni** : unità di lavoro atomiche che non possono avere effetti parziali ( rollback in caso di fail )

**Modello di dati relazionale** :
Meccanismi di astrazione per definire una base di dati , associando operatori e vincoli di integrità

Caratteristiche :
+ *espressività* : rappresentazione naturale e diretta di ciò che si sta modellando
+ *facilità d'uso* 
+ *realizzabilità* : i meccanismi del modello di astrazione e i relativi operatori per la manipolazione dei dati devono essere realizzabili in modo efficiente su di un elaboratore 
## DBMS ( Data Base Management System )

Un **DBMS** è un sistema centralizzato o distribuito che offre opportuni linguaggi / strumenti per :
+ **definire** lo *schema* della BD
	+ definizione tramite il *modello di dati* usato dal *DBMS*
+ sciegliere le *strutture dati* per memorizzare i dati ( cartelle , file hash , strutture che favoriscano la ricerca )
+ *memorizzare* i dati rispettando i vincoli definiti nello schema
+ recuperare e *modificare* i dati interattivamente ( tramite linguaggi di query ) o da programmi

![[Pasted image 20230923161257.png]]

Esempio di **DBMS Relazionale**

Meccanismo di astrazione fondamentale è la **relazione** ( **tabella** ) : insieme di record con campi di tipo elementare

|Nome|*Matricola*|Città|AnnoNascita|
|--|--|--|--|
|Verdi|71523|Padova|1987|
|Rossi|76366|Dolo|1988|
|Zeri|71347|Venezia|1988|
*Studenti*

*Matricola* è la **primary key** (vincolo di *chiave primaria* ) della tabella ( dovrebbe essere sottolineata )
	Non possono esistere 2 elementi che hanno la stesso valore nel campo *matricola* , questa individua in modo univoco uno studente

Creare un database vuoto :
```sql
CREATE DATABASE EsempioEsami
```

Definirne lo schema :
```sql
CREATE TABLE Studenti (
		Nome char(8),
		Matricola int NOT NULL, /* NOT NULL vincolo di integrità */
		Città char(10),
		AnnoNascita int,
		PRIMARY KEY (Matricola)  );

CREATE TABLE ProveEsami (
		Materia char(5),
		Matricola int,
		Data char(6),
		Voto int,
		Lode char(1),
		PRIMARY KEY (Materia,Matricola)  );
```

La **primary key** può essere costituita da più attributi ( comunque deve essere un insieme *minimale* di attributi che indentificano univocamente una riga della tabella , altrimenti viene detta *Super key* )
	
Esempio : 
Se la *primary key* fosse solo *Matricola* allora uno studente non potrebbe fare più di un esame , se fosse solo *Materia* solo uno studente potrebbe fare quell'esame

|*Materia*|*Matricola*|Data|Voto|Lode|
|--|--|--|--|--|
|CN|71523|08.07.06|27|N|
|FIS|76366|08.07.07|26|N|
|BD|71523|28.12.06|20|S|
*ProveEsami*

Vincolo di **Foreing key** ( *Matricola* è una *foreing key* poichè fa riferimento alla tabella *Studenti* ) : 
	se volessi inserire in *ProveEsami* una matricola non presente in studenti non posso poichè non ho modo di collegare a quella matricola uno studente dalla tabella *Studenti*

Inserimento dati :
```sql
INSERT INTO ProveEsami
VALUES ('BD', 71523 , '28.12.06' , 30 , 'S')
```

Query : 
```sql
SELECT Matricola
FROM   ProveEsami
WHERE Materia = 'BD' AND Voto = 30;

/* response : tutte le matricole con voto 30 in BD */

Matricola : 

71523
```

## Funzionalità dei DBMS

+ Linguaggio per la **definizione della base di dati** ( *DDL* )
+ Linguaggi per l'**uso deo dati** ( *DML* )
+ Meccanismi per il **controllo dei dati**
+ Strumenti per il **responsabile della base di dati**
+ Strumenti per lo **sviluppo delle applicazioni**

### DDL 

La definizione / descrizione del *DB* è indipendente dalle applicazioni che la usano

3 livelli di descrizione ( astrazione ) dei dati :
+ **livello di vista logica**
+ **livello logico**
+ **livello fisico**

#### Livello Logico

**Schema logico** : descrive la *struttura* degli insiemi di dati e delle *realzioni* tra questi secondo un certo *modello dei dati* ( non fa riferimento alla loro organizzazione fisica in memoria )

Esempio creazione delle tabelle :
```sql

CREATE TABLE Studenti(Matricola int, Nome char(20), Login char(8), AnnoNascita int, Reddito real)

CREATE TABLE Corsi(IdeC char(8), Titoli char(20), Credito int)

CREATE TABLE Esami(Mtricola int, IdeC char(8), Voto int)

```

#### Livello Fisico

Descrive lo *schema fisico* o *interno*
+ Come vanno organizzati fisicamente i dati nelle memorie permanenti
+ Definizione di strutture dati ausiliarie per l'utilizzo della *Base di Dati* ( es : indici per la ricerca )

Esempio : 
+ *Organizzazione seriale* : organizzazione senza alcun ordinamento
+ *Organizzazione sequenziale* :  organizzazione attraverso indici ( utile per la ricerca , accedo direttamente attraverso l'indice )
```sql
CREATE INDEX Indice ON Studenti(Matricola); 
```

#### Livello di Vista Logica

Descrive come deve *apparire* la struttura della base di dati ad una certa applicazione ( o utente , privacy oriented ) 

Esempio :
```sql
InfCorsi (IdeC char(8), Titolo char(20), NumEsami int)

CREATE VIEW InfCorsi (IdeC , Titolo , NumEsami) AS
			SELECT IdeC ,
				   Titolo ,
				   COUNT(*)
			FROM Corsi NATURAL JOIN Esami
			GROUP BY IdeC, Titolo
```

La tabella *InfCorsi* ( conta quanti studenti hanno svolto un esame ) è una tabella *virtuale* : 
	Non viene salvata in memoria ma viene ricalcolata ogni volta che la si richiede con una query

#### Data independence 

+ **Indipendenza fisica** : I programmi applicativi non devono essere modificati in seguito a modifiche dell'organizzazione fisica dei dati
+ **Indipendenza logica** : I programmi applicativi non devono essere modificati in seguito a modifiche dello schema logico :
	+ richiede la creazione di una nuova vista ( *tabella virtuale* ) in modo che ci sia la stessa visione precente da parte dell'applicazione
	
	Esempio : 
	```sql
	/* La tabella Studenti divisa in StudentiPartTime e StudentiFullTime */
	CREATE TABLE StudentiFullTime (...);
	CREATE TABLE StudentiPartTime (...);

	/* Tabella virtuale che ricrea la tabella Studenti */
	CREATE VIEW Studenti AS
		SELECT * FROM StudentiFullTime
		UNION
		SELECT * FROM StudentiPartTime
	```

### DML

*Linguaggi per l'uso dei dati*

Tipi di utenti : 
+ *Utenti delle applicazioni* : Only GUI
+ *Utenti non programmatori* : 
	+ interfaccia grafica per accedere ai dati
	+ lingaggio di interrogazione
+ *Programmatori delle applicazioni*
	+ **SQL embedded** : Linguaggio convenzionale esteso con un construtto per marcare i comandi *SQL* ( macro : risolte dal pre-compilatore con chiamate a funzioni di libreria che supporta *SQL* )
	+ **Linguaggio tradizionale + librerie** : Aggiunta di funzioni che hanno come input una stringa con comandi *SQL* 
	+ **Linguaggi integrati** : Linguaggi disegnati ad-hoc per usare *SQL* 

### Controllo dei dati

Caratteristiche che garantisce il **DBMS** : 
+ **Integrità**
	+ Mantenere i vincoli di integrità 
+ **Sicurezza**
	+ Protezione dei dati da usi non autorizzati :
		+ limitazione delle operazioni eseguibili ( alcuni utenti possono solo accedere altri possono solo vedere dati statistici etc.. )
		+ limitazione dell'accesso ai soli utenti autorizzati
		+ [k-anonimity](s://it.wikipedia.org/wiki/K-anonimato) per proteggere i dati riservati :
			Un dato di una persona può essere svelato se so i dati di qualcun'altro soprattuto se vi sono poche persone con questo dato ( esempio media ) per questo si può svelare un dato solo se esistono k-1 persone con questo dato 
+ **Affidabilità**
	Protezione dei dati da : 
	+ **interferenze** da *accesso concorrente* 
	+ **malfunzionamenti hardware o software**

#### Transazione

Una *Transazione* è una sequenza di azioni di lettura e scrittura in memoria permanente e di elaborazioni di dati in memoria temporanea con le seguenti caratteristiche ( *A.C.I.D.* ) :
+ **Atomicità** : Le transizioni che terminano prematuramente ( *Aborted Transactions* ) sono trattate dal sistema come se non fossero mai iniziate eliminando eventuali effetti sulla base di dati
+ **Consistenza** 
+ **Isolation** : Nel caso di esecuzioni concorrenti di più transazioni l'effetto complessivo è quello di una esecuzione seriale
+ **Durability** : Le modifiche sulla base di dati di una transazione terminata normalmente sono permanenti, non sono alterabili da eventuali malfunzionamenti 

Tipi di *malfunzionamenti* :
+ **Malfunzionamenti HW o SW**  : detemina interruzione di tutte le transazioni attive e la perdita dei contenuti della memoria temporanea
+ **Fallimento transazione** 
+ **Disastri**
Ripristino da *malfunzionamenti* tramite *jurnal* e copie di sicurezza ( *backup* ) : 
	*Riesecuzione* di tutte le operazioni avvenuto dopo l'ultimo *backup* tramite il *journal* in modo da far tornare la base di dati allo stato originale
