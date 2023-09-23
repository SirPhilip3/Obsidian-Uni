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

GIS : 
- dati vettoriali
- rasterized

Sistemi di supporto alle decisioni

Dato vs Informazione
+ dato mancanza di elaborazione

interpretoando dati ottengo informazioni

DBMS
+ canale sicuro per accedere alle basi di dati

OLTP
+ sequenza di operazioni elementari i cui effetti devono essere rimossi se una transizione è erronea, come se transizione non eseguita
+ stato consistente = base di dati con dati corretti

basi di dati operazionali solo db recenti 

usare contineuamente le basi di dati operzioali studio di dati storici

data wearhouse contiene dati storici

misura ciò voglio rappresentare 

aggregazione di dati a seconda del dettaglio che voglio raggiungere , 
data warehouse alimentato da basi di dati operazionali e basi di dati esterni -> aggergazione dei dati in DB operazionali (EstrazioneTLoading)

gerarchie relazionali

DW astrazione di DB operazionali (dati aggregati)

DW con operazioni OLAP 

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

La **primary key** può essere costituita da più attributi ( comunque deve essere un insieme *minimale* di attributi che indentificano univocamente una riga del  )

Primary key può essere costituita da più attributi ( insieme minimale )
solo materia ci sono più studenti che fanno lo stesso esame , singolarmente non sono chiavi

Superkey : insieme di attribuit che individuano un elemento in modo univoco ma non in modo minimale

Aspetto estensionale : valori della tabella

Posso mettere in proveesami solo valori che esistono in studenti, non ho modo di collegare uno studente 

Vincolo di foreing key : controllo se chiave presente in tabella studenti

Query : 

![[Pasted image 20230922092004.png]]

tutti gli studenti con voto 30 in basi di dati

Funizioni : 
+ DDL ( data definition language )
+ DML ( linguaggio per uso dei dati )
+ controllo dei dati
+ admin panel
+ strumenti per lo sviluppo di applicazioni

DDL

DB deve essere indipendente da app

livelli di astrazione : 
+ livello fisico : come i dati sono immagazzinati in memoria secondaria
+ livello logico : descrizione schema base de dati
+ livello di vista logica : come vengono visti da diversi utenti ( moltepli e differenti )

livello logico : solo struttura non come vengono memorizzati ( fisicamente )

```sql

CREATE TABLE Studenti(Matricola int, Nome char(20), Login char(8), AnnoNascita int, Reddito real)

CREATE TABLE Corsi(IdeC char(8), Titoli char(20), Credito int)

CREATE TABLE Esami(Mtricola int, IdeC char(8), Voto int)

```

livello fisico : 

come vanno realizzati in memoria

organizzazione seriale : nessun ordinamento
organizzazione sequenziale con index 

```sql
CREATE INDEX Indice ON Studenti(Matricola); 
```

accedo temite index per indirizzare la ricerca

vista logica

es fornire solo il numero di studenti che sostengono un esame non chi lo ha svolto

tabella virtuale : ogni volta ricalcolata con query , infCorsi non immagazzinata in memoria
conta quanti studenti hanno svolto un esame

Indipendenza fisica : app indipendente dall'organizzazione fisica dei dati
indipendenza logica : app indipendente dallo schema logica della base di dati
	Bisogna creare una nuova vista in modo che ci sia la stessa visione precedente, tabella virtuale

Linguaggi per uso dei dati 
a.c.
tipi di utenti : 
+ utenti delle applicazioni only gui
+ utenti non programmatori
	+ accedere ai dati 
	+ linguaggi di interrogazione
+ programmatori 
	+ SQL embedded , all'interno di linguaggi convenzinali con sql ( execsql )
	+ linguaggio convenzionale + librerie
	+ Linguaggi integrati

Data security

+ Integrità
	+ mantenimento vincoli di integrità
+ Sicurezza
	+ protezione da usi non autorizzati
	+ limitazione delle operazioni esaguibili
	+ protezione delle privacy : k-anonimity posso svelare un dato solo se esistono k-1 di questi dati, se k troppo piccolo rischio di deanonimmizzazione
+ Protezione : 
	+ interferenza da accesso concorrente
		+ soluzione attraverso la *transazione* proprietà A.C.I.D.
			+ Atomicità
			+ consistenza 
			+ durability ( persistenza )
			+ isolation : anche se le transazioni vengono esuite contemporaneamente effetto complessivo come se fosse un esecuzione seriale
	+ malfunzionamentni hw e sw
		+ fallimento transazione 
		+ fallimento di sistema
		+ disastri
	 ripristino copia di sicurezza e journal : riesecuzione di transazioni che sono avvenute dopo copia di sicurezza tramite journal  