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

## DBMS

In generale : una qualsiasi raccolta di dati permanenti gestiti tramite un elaboratore elettronico

_Definizione_ : Una **Base di Dati** è una raccolta di *dati* permanenti , gestiti da un elaboratore elettronico , suddivisi in 2 tipologie :
+ **Metadati** : Definiscono lo schema della **B.D.** ( schema è creato prima dell'inserimento dei dati ) e descrivono :
	+ Struttura dei dati
	+ Operazioni eseguibili sui dati
	+ Restrizioni sui valori ammissibili ( **Vincoli di Integrità** )
	+ Autorizzazioni per utenti 
	I *Metadati* / lo schema dei dati è indipendente dalle applicazioni che usano la base di dati
+ **Dati** : rappresentazioni di certi fatti conformi alle definizioni dello schema ,  



raccolta di dati permanenti : 
+ metadati ( struttura dati + operations + vincoli di integrità ( valori accetabili ) ) 
	+ autorizzazioni per utenti ( sola lettura etcc )
	+ schema creato prima dell'inserimento dati , indipendenti dalle app
+ Dati : fatti conformi ai metadati :::
	+ Insiemi omogenei
	+ definite relazioni tra insiemi ( relazioni descritte nello schema )
	+ modello di dati : meccanismi di astrazione che definiscono struttura dei dati, vincoli
		+ modello ad oggeti
		+ modello relazionale
			+ modello caratteristiche / proprietà:
				+ espressività ( rapressentazione ( modellazione ) naturale e diretto dei dati )
				+ facilità d'uso 
				+ realizzabilità : implementazione semplice ed efficente
	+ dati sono molti e permanenti : gestione in memoria secondaria , non legati a applicazioni 
	+ possono essere utilizzati contempporanemente : accessi concorrenti non devono creare malfunzionamenti
	+ protezione dei dati : malfunzionamenti etcc
	+ accedibili tramite transazioni ( o tutte a buon fine altrimenti rollback ) 

DBMS : è un sistema centralizzato o distribuito che offre opportuni linguaggi/strumenti per : 
+ definire lo schema della BD (va definito prima di creare dati) -
	+ definito usando il modello dei dati adottato dal DBMS - 
	+ interrogabile con le stesse modalità previste per i dati;
+ scegliere le strutture dati per la memorizzazione dei dati ( cartelle , file hash, utilizzo di struuture che favoriscono la riceraca )
+ memorizzare i dati rispettando i vincoli definiti nello schema; 
+ recuperare e modificare i dati interattivamente (linguaggio di interrogazione o query language) o da programmi

Utenti e programmi accedono ai dati solo tramite il DBMS 

DBMS modello realzionale ( tabella ) più diffuso
tabella : insieme di record con tipi elementari

![[Pasted image 20230922090622.png]]

Matricola : definito un vincolo : vincolo di *chiave primaria* :
	non possono esistere 2 elementi che hanno lo stesso valore nel campo matricola , matricola individua in modo univoco uno studente

CREATE DATABASE database vuoto

Definizione schema

NOT NULL vincolo di integrità

![[Pasted image 20230922090934.png]]

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