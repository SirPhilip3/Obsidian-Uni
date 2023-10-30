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

## Informazioni 

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


### Strumenti per amministrazione

Strumenti per l'amministrazione della base di dati :
+ Strumenti per la messa a punto del sistema :
	dati per valutare le prestazioni del database con come obbiettivo il miglioramento delle performance
+ Strumenti per stabilire i diritti di accesso ai dati
+ Strumenti per ripristinare la base di dati in caso di malfunzionamenti del sistema o di disastri

# 25/09/2023
## DBMS Vantaggi / Svantaggi

**Vantaggi** : 
+ *Indipendenza fisica dei dati* da programmi : 
	 questa viene assicurata alla creazione dello schema logico in cui non si danno informazioni sulla loro organizzazione fisica
+ *Indipendenza logica* : 
	 assicurata mediante la creazione di viste per varie applicazioni o utenti 
+ Gestione efficiente dei dati :
	 attraverso strutture dati apposite per la ricerca ( hashes , index ... )
+ *Stato consistente* :
	 tutti vincoli di integrità vengono rispettati , il *DBMS* verifica la correttezza di questi vincoli e se è presente un vincolo non rispettato la transazione non ha successo
+ Protezione da accessi concorrenti grazie alle transazioni
+ Riduzione dei tempi di sviluppo delle applicazioni : 
	 non è necessario fare i controlli di integrità all'interno delle applicazioni

**Svantaggi** : 
+ costosi da mantenere in passato ( eliminato dalle soluzioni open source )

## Progettazione e Modellazione

Definizione della *struttura dati* della base di dati richiede di definire un **modello** della realtà di interesse il più possibile fedele  

**Definizione** : Un *modello astratto* è la rappresentazione formale di idee e conoscenze relative a un fenomeno.

Aspetti fondamentali di un modello : 
+ è la rappresentazione di certi fatti 
+ utilizzo di un linguaggio formale disanbiguo

Fasi di progettazione della Base di Dati
![[ProgettazioneDB.excalidraw]]

**Analisi dei requisiti** : 
	è la specifica che viene data in input da un commitente , deve essere trasformato in *schema concettuale* con un linguaggio ad alto livello ( modello ad oggetti ) 

**Progettazione logica** :
	Trasformazione dello *schema concettuale* in *schema logico* realizzato nel calcolatore utilizzando lo schema relazionale ( *modello relazionale* ) 

**Progettazione fisica** :
	è lo *schema logico* arrichito con informazioni di come sono immagazzinati i dati in memoria permanente ( utilizzo di strutture dati ( index , hashes ) che possono aiutare la ricerca dei dati )

## Modellazione concettuale 

Aspetti del problema :
+ **aspetto ontologico** :
	ciò che volgiamo rappresentare
+ **aspetto logico** :
	che meccanismi di astrazione si applicano
+ **aspetto linguistico** :
	con quale linguaggio fromale definiamo il modello
+ **aspetto pragmatico** :
	come si procede per lo sviluppo del modello

#### Aspetto ontologico

Ciò che vogliamo rappresentare sono : 
+ **Conoscenza concreta** :
	I fatti
+ **Conoscenza astratta** :
	Struttura e vincoli sulla conoscenza concreta
+ **Conoscenza procedurale** : 
	Le operazioni di base e degli utenti
+ **Comunicazioni** :
	Come si comunicherà con il sistema informatico

##### Conoscenza Concreta

Per modellare la *conoscenza concreta* dobbiamo modellare 3 tipologie di fatti :
+ **Entità** : es studente , libro , prova d'esame
+ **Collezioni** : es insieme degli studenti , insieme dei libri
+ **Associazioni** : es un esame è associato ad uno studente

###### Entità 

Le **entità** sono ciò di cui ci interessa rappresentare alcuni fatti ( o *proprietà* )
	Es : un libro , una descrizione bibliografica , un prestito
> [!caution] 
>  Una *entità* non coincide con i valori delle sue proprietà 
> 	 Es : 2 persone possono avere le stesse proprietà ma sono comunque entità distinte ( nel modello concettuale )  

Ogni *entità* ha un **tipo** che ne specifica la natura e identifica le *proprietà* e il *dominio relativo* :
	Es Antonio ha tipo *Persona* con proprietà :
		- Nome : `string`
		- Indirizzo : `string`


Le **proprietà** si distinguono dalle *entità* poichè sono fatti che sono interessanti poichè descrivono delle caratteristiche di determinante *entità*
	Es : indirizzo che è interessante solo poichè riferito ad un utente

Una *propietà* è una coppia < Attributo , Valore >
+ Tipologie di *proprietà* :
	+ **Atomica** : non è ulteriormente divisibile ( il nome )
	+ **Strutturara** : può essere divisibile in parti atomiche ( l'indirizzo è divisibile in : città , cap , via etcc )

	+ **Univoca** : quando quella proprietà assume un unico valore ( grado di parentela ) 
	+ **Multivalore** : quando quella proprietà può assumere più valori ( gli autori di un libro possono essere più di uno )

	+ **Totale** : quando quella proprietà deve assumere sempre almeno un valore ( il nome )
	+ **Parziale** : quando quella proprietà può non assumere un valore ( numero di telefono )


Esempi :

|Tipo Entità|Proprietà|
|---|---|
|Studente|Nome,AnnoNascita,Matricola,e-mail,...
|Esame|Materia,Candidato,Voto,Lode,...
|Auto|Modello,Colore,Cilindrata,Targa
|Decrizione bibliografica|Autori,Titolo,Editore,Anno,...

###### Collezione

Una **Collezione ( classe )** è un insieme variabile nel tempo di *entità* omogenee ( dello stesso *tipo* )
	Es : `Studenti` è un insieme di tutti gli *Studenti* 

Esempi :

![[CollectionEx.excalidraw]]

> [!caution] 
> Certi fatti possono essere interpretati come *proprietà* in certi constesti e come *entità* in altri  

Spesso le collezioni di *entità* sono organizzate in una gerarchia di **specializzazione/generalizzazione (sottoclassi/superclassi)** 
	Es : nella **B.D.** della biblioteca la collezione degli `Utenti` può essere considerata una *generalizzazione* di `Studenti`e `Docenti`

Due importanti caratteristiche delle gerarchie :
+ **Ereditarietà** : 
	Una *sottoclasse* eredita le proprietà della classe generale , possono essere aggiunte altre proprietà o ridefinire quelle presenti nella *superclasse*
+ **Inclusione** : 
	Una *sottoclasse* deve essere un sottoinsieme della sua *generalizzazione*

  Es : 
	La *classe* degli `Studenti` è una generalizzazione delle *classi* :
	+ **matricole** e **laureandi**
	+ **studenti in corso** e **studenti fuori corso**
	+ **sudenti locali** e **studenti fuori sede**
###### Associazioni

Una *Istanza di Associazione* è un fatto che correla due o più *entità* stabilendo un legame logico tra di loro 
	Es : l'utente `Tizio` *ha in prestito* una copia della `Divina Commedia`

Un’**associazione** $R(X, Y)$ fra due collezioni di entità $X$ ed $Y$ è un insieme di *istanze di associazione* tra elementi di $X$ e $Y$, che varia in generale nel tempo. 
Il prodotto cartesiano $(X \times Y)$ è detto *dominio* dell’associazione.

Esempio :
![[AssociationEx.excalidraw]]

HaScritto ( insieme di coppie ) è un sottoinsieme del prodotto tra autori e descrizioni bibliografiche

Un'*Associazione* è caratterizzata dalle seguenti proprietà strutturali :
- *molteplicità* o *cardinalità* : 
	- *univoca* : 
		per ogni elemento di X esiste un associazione con al più ( al massimo ) un elemento di Y
	- *multivalore* : 
		per ogni elemento di X esiste un associazione con più di un elemento di Y
	+ Combinazioni delle *molteplicità* : 
		+ `Frequenta(Studenti, Corsi)`
			ha molteplicità ( **N : M** ) ( *uno studente* frequenta *più corsi* , *un corso* è frequentato da *molti studenti* )
		+ `Insegna(Professori, Corsi)`
			ha moltelpicità ( **1 : N** ) ( *un corso* è insegnato da *un solo professore* , *un professore* insegna *più corsi* )
		+ `SuperatoDa(Esami, Studenti)`
			ha molteplicità ( **N : 1** ) ( *un esame* è superato da *uno studente* ( considerato come il foglio d'esame ) , *uno studente* può superare *più esami* )
		+ `Dirige(Professori, Dipartimenti)`
			ha molteplicità ( **1 : 1** ) ( *un professore* dirige *un diaprtimento* , *un dipartimento* è diretto da *un professore* )
- *totalità* :
	- *totale* : quando per ogni elemento di $X$ *esiste almeno* un elemento di $Y$ a cui è *associato* 
	- *parziale* : quando ogni elemento di $X$ può *non avere* alemo un elemento di $Y$ a cui è associato
	- Esempi :
		- `Insegna(Professori, Corsi)`
			è *totale* su `Corsi` in quanto non può esistere un corso del piano di studi senza il corrispondente docente che lo `Insegna`
			è *parziale* su `Professori` in quanto un professore potrebbe non insegnare corsi 

Esempi :
+ `NataA(Persone, Città)`
	ha *cardinalità* ( **N : 1** ) ( *una persona* è nata in un *unica città* , *in una città* sono nate *più persone* )
	è *totale* su `Persone` , *parziale* su `Città`
+ `HaVisitato(Persone, Città)`
	ha *cardinalità* ( **N : M** ) ( *più persone* hanno visitato *una città* , *più città* sono visitate da *una persona* )
	è *parziale* su `Persone` e `Città` ( una persona può non aver visitato nessuna città , una città può non essere mai visitata da nessuna persona )
+ `èSindacoDi(Persone, Città)`
	ha *cardinalità* ( **1 : 1** ) ( *una persona* è sindaco di una *sola città* , *una citta* può avere un *solo sindaco*)
	è *parziale* su `Persone` e `Città` ( una persona può non essere sindaco di nessuna città , una città può non avere nessun sindaco ( durante le elezioni ) )

##### Conoscenza Astratta

La *conoscenza astratta* sono i fatti generali che descrivono :
+ la struttura della *conoscenza concreta* : 
	- *collezioni* : nomi , tipo degli elementi 
	- *associazioni* : nomi , collezioni correlate ,prorpietà strutturali 
+ restrizioni sui valori possibli ( **vincoli di integrità** ) sulla *conoscenza concreta* e sui modi in cui essi possono evolvere nel tempo
+ regole per derivare nuovi fatti da altri noti ( **Fatti derivabili** )

- **Vincoli di Integrità** :
	+ **Vincoli di integrità statici** :
		Condizioni della *conoscenza concreta* che devono essere soddisfatte indipendentemente da come evolve l'universo del discorso 
		Es : `Stipendio` deve sempre essere positivo
	+ **Vincoli di integrità dinamici** : 
		Condizioni sul modo in cui la *conoscenza concreta* può evolvere nel tempo  
		Es : `DataNascita` non può cambaire nel tempo 


+ **Fatti derivabili** : 
	Es : media dei voti ( da tutti i voti ) , età di una persona ( dalla data di nascita )

# 29/09/2023

## Modello dei dati ad Oggetti

Un **Modello dei dati** è un insieme di meccanismi di astrazione per descrivere la struttura della conoscenza concreta ciò avviene attraverso *schemi* simili ai diagrammi ER ( entità-relazione )

Il *Modello ad oggetti* è caratterizzato dalle seguenti nozioni :
+ L'*oggetto*
+ Il *Tipo di Oggetto*
+ La *classe*
+ Le *Ereditarietà*
+ La *Gerarchia fra tipi*
+ La *Gerarchia fra classi*

### Oggetto

Un *Oggetto* è un'entità software con :
+ **Stato** : 
	Modellato da un insieme di *costanti* o *variabili* ( possono essere anche oggetti ma per noi ciò non sarà possibile )
+ **Comportamento** : Modellato da un insieme di metodi ( operazioni per *manipolare* oggetti ) 
+ **Identità** : 
	è associato ad un oggetto al momento della sua creazione e non può essere modificato ( come se fosse un index che *identifica univocamente* quell'oggetto )

Un *oggetto* può rispondere a richieste dette **messaggi** restituendo valori memorizzato nello stato o calcolati attraverso metodi

#### Tipo Oggetto

Primo passo nella costruzione di un modello consiste nel :
+ Identificare le *classi* ( o collezioni omogenee ) 
+ Definizione dei *tipi di oggetti* ( ossia lo *stato* e i *metodi*  ) che rappresentano le *classi*
	Es : `Persona`
	Definiamo lo *stato* : 
	`string` Nome
	`string` Cognome
	`int` DataNascita
	Definiami i *metodi* :
	`int GiveEtà()`

#### Classi

Una *classe* è un insieme di *oggetti* dello stesso tipo , modificabile con operatori per includere o estrarre elementi dall'insieme , associabile a *vincoli di integità*

Es : `Persone`

![[SrudentiExClass.excalidraw]]

##### Tipi degli attributi

+ **Primitivi** : ( `int, real, bool, date, string` )
+ **Non Primitivi** :
	+ **Record** : `[A1:T1;...;An:Tn]` , è un insieme di coppie `nome:tipo` 
		Es : `Indirizzo: [Via:string ; Città:string]`
	+ **Enumerazione** : `(Val1;...;Valn)` , può assumere un solo valore presente all'interno dell'enumerazione
		Es : `Sesso: M`  ( scielto tra `(M; F)` )
	+ **Sequenza** : `seq T` , lista di elementi
		Es : `LingueParlate: Italiano,Tedesco,Inglese`

##### Associazioni

Le *associazioni* si leggono e creano pensando o da sinistra verso destra o dall'alto al basso

![[rappAssociazioni.excalidraw]]

Esempio :
![[AssociazioniEx1.excalidraw]]

Le *associazioni* possono avere delle *proprietà*

![[AssociazioniEx2.excalidraw]]

Se vi sono più di 1 attributo in una *associazione* allora sarebbe meglio trasformarla in una *classe*

Es : 
	se vogliamo rendere la precedente associazione storica : 
![[AssociazioniEx2_1.excalidraw]]

In cui `Prestiti` ha come proprietà la data di inizio e fine del prestito

Le *associazioni* possono essere *ricorsive*

![[AssociazioniEx3.excalidraw]]

Posso renderla più generalistica :

![[AssociazioniEx3_1.excalidraw]]

*Associazioni* n-arie
Le associazioni tra più *classi* vengono rappresentate inserndo una classe intermedia al posto di una *associazione* 

Esempio : Si vuole rappresentare l’associazione tra Voli, Passeggeri e Posti. Per ogni volo, al momento dell’imbarco, viene assegnato un posto a ciascun passeggero

![[AssociazioniEx4.excalidraw]]

###### Esempio più complesso

Si vogliono modellare alcuni fatti riguardanti una biblioteca universitaria:
+ Le *descrizioni bibliografiche* dei libri a volume unico :
	- sia quelli già disponibili che quelli ordinati ma non ancora consegnati alla biblioteca
	caraterizzati da :
	+ codice ISBN che li identifica
	+ titolo del libro
	+ autori
	+ aditore
	+ anno di pubblicazione
	+ termi che lo descrivono
+ I termini del *thesaurus* (parole chiave) :
	Termini che descrivono il contenuto del libro
	Relazioni tra i termini del *thesaurus* :
	+ **Preferenza**
		Es : 
		+ Elaboratore , Calcolatrice : lo **Standard** è Calcolatore
		+ Calcolatore i **Sinonimi** sono : Elaboratore , Calcolatrice
	+ **Gerarchia** 
		Es :
		+ Felino **PiùSpecifico** è Gatto , Leone , Tigre
		+ Gatto **PiùGenerale** è Felino 
+ I *libri* :
	identificati da : 
	+ la loro *posizione* in biblioteca
+ Gli *autori* dei libri
	con le seguenti caratteristiche:
	+ codice fiscale
	+ nome 
	+ cognome
	+ nazionalità 
	+ data di nascita
+ Gli *utenti* della biblioteca
	Dati interessanti :
	+ nome
	+ cognome
	+ indirizzo
	+ recapiti telefonici
	I dati del prestito interessano fino alla restituzione , un utente può avere più libri in prestito
+ I *prestiti* in corso
	che hanno :
	+ data di inizio del prestito
	+ data di restituzione del prestito

Schema finale 
![[AssociazioniComplexExample.excalidraw]]
##### Gerarchie tra tipi di oggetto

Relazione di **sottotipo** ( $\leq$ ) o ( *ordine parziale* )

Proprietà :
+ **Riflessiva** : ogni oggetto è sempre $\leq$ a se stesso
+ **Antiriflessiva** :
	presi $t_1$ e $t_2$ se $t_1\leq t_2$ e $t_2\leq t_1$ allora $\implies$ $t_1==t_2$
+ **Transitiva** :
	presi $t_1 , t_2\space \text{e}\space t_3$ se $t_1\leq t_2$ e $t_2\leq t_3$ allora $\implies t_1\leq t_3$  

Esempio :

![[Point.excalidraw]]

![[ColoredPoint.excalidraw]]

`ColoredPoint` è un *sottoinsieme* di `Point` poichè gli attributi di `Point` sono tutti presenti in `ColoredPoint`

![[ColoredPointInt.excalidraw]]

Anche `ColoredPointint` è un *sottoinsieme* di `ColoredPoint` e quindi di `Point` poichè `x , y` essendo interi sono un *sottotipo* dei reali

##### Ereditarietà

L'*Ereditarietà* ci permette di definire un tipo oggetto a partire da un altro per differenza , infatti questo metodo ci permette di ereditare tutti gli attributi dell'oggetto "padre" e aggiungerene o ridefinire attributi per differenziare l'oggetto "figlio"

L'*ereditarietà* tra tipi si usa solo per definire sottotipi ( *ereditarietà stretta* ) , in questo caso :
+ gli attributi possono essere aggiunti 
+ gli attributi possono essere ridefiniti solo specilizzandone il tipo

Esempio :

![[fj.png]]

In questo caso `Student` eredita tutti gli attributi di `Person` e per specializzarsi abbiamo aggiunto gli attributi `Matricola` e `AnnoDiIscrizione`
##### Gerarchia tra Classi

Fra le *classi* può essere definita una relazione di *sottoclasse* ( o sottoinsieme ) con le seguenti proprietà :

+ *Vincolo estensionale* : 
	Se C è sottoclasse di C' allora le entità in C sono un sottoinsieme delle entità in C' 
+ *Vincolo intesionale* : 
	Se C è ssottoclasse di C' allora il tipo delle entità in C è sottotipo del tipo degli elementi di C'
+ *Vincolo di disgiunzione*
	Esempio :
	![[dis.png]]
	In questo caso l'intersezione tra le due sottoclassi deve essere nulla ( ossia le 2 sottoclassi sono *disgiunte* tra loro ) : $B\cap C =\emptyset$
+ *Vincolo di copertura* :
	Esempio :
	![[Pasted image 20231023110902.png]]
	In questo caso l'unione tra le due sottoclassi deve essere la classe "padre" ( superclasse ) :
	$B\cup C=A$

Ovviamente si possono fare varie combinazioni di questi vincoli :
+ *Sottoclassi scorrelate*
	![[Pasted image 20231023111818.png]]
+ *Sottoclassi disgiunte*
	![[Pasted image 20231023111836.png]]
+ *Sottoclassi copertura*
	![[Pasted image 20231023111856.png]]
+ *Sottoclassi partizione*
	![[Pasted image 20231023111926.png]]

Esempio di *Gerarchia Multipla* :
![[Pasted image 20231023112155.png]]

In questo caso se in `Giornalisti` ci fosse un attributo `LavoraPer : string` e in `Fotografi` ci fosse un attributo `LavoraPer : seq string` quando questo verrà ereditato da `Fotogioranlisti` gli attributi saranno incompatibili in quanto di tipo diverso per questo durante la creazione della base di dati si definirà un ordine secondo ilquale bisogna ereditare quell'attributo

#### Integrazione degli Schemi

Se abbiamo 2 schemi con caratteristiche simili possiamo combinarli per avere uno schema più generale

Esempio : 
Avendo i seguenti 2 schemi che descrivono i libri di una biblioteca :

![[Pasted image 20231023113557.png]]

Innanzitutto risolviamo i conflitti di nome , di tipo e di vincoli di integrità , nel secondo schema possiamo quindi modificare :
+ `Nome` diventa `Titolo`
+ `Editore` diventà l'entità `Editori` con come attributo `Nome` 
+ `Descrittori` diventa `Argomenti`

![[Pasted image 20231023114214.png]]

Fondendo quindi i due schemi ( unendo le classi comuni ) avremo :

![[Pasted image 20231023114238.png]]

Ed in quanto `Libri` è una specializzazione di `Documenti` avremo : 

![[Pasted image 20231023114325.png]]

>[!todo]
>svolgimento esercizi

## Modello Relazionale

Dobbiamo trasformare il modello *concettuale* ad oggetti al modello logico *relazionale*

Le *collezioni* diventano *realzioni* ( *tabelle* )
Le *associazioni* vengono rappresentate con *chiavi* ( *foreing* )

I meccanismi per definire una base di dati con il modello realzionale sono l'*ennupla* e la *relazione*

+ Tipo *ennupla* T : insieme finito di coppie ( Attributo : *Tipo primitivo* )
	Es : `( A1 : T1 , .... , An : Tn )`
+ *Tipo relazione* ( o tipo insieme di ennuple ) : 
	Se T è un tipo *ennupla* allora { T } è un tipo relazione 
	Esempio :
	`{ (Nome : string, Cognome : string, Matricola : int) }`
+ *Schema di relazione* : assegna ad una relazione un nome :
	Esempio :
	`Studenti : { (Nome : string, Cognome : string, Matricola : int) }`
+ *Istanza di uno schema* : insieme finito di ennuple di tipo T ( la usa *cardinalità* è il numero di ennuple )
+ *Schema ralezionale di un BD* : insieme di schemi di relazione e vincoli di integrità

#### Vincoli di integrità

I vincoli di integrità che considereremo sono :
+ *chiavi*
+ *chiavi esterne*
+ *valori non nulli*

Un'*istanza* di uno schema di relazione si dice *valida* se rispetta tutti i vincoli definiti su R

##### Chiavi

Si possono distiguere vari tipi di *chiavi* :
+ *Superchiave* : 
	un sottoinseme di attributi di uno schema relazionale tale che il valore di questi determini in modo univoco una ennupla
	Esempio : `(Matricola)` e `(Cognome,Matricola)` sono superchiavi in `Studenti(Nome,Cognome,Matricola,Anno)`
+ *Chiave* : 
	è una *superchiave* minimale ( minimo numero di attributi per identificare univocamente una ennupla ) 
	Esempio : `(Matricola)`
+ *Chiave Primaria* : una delle *chiavi* in genere di lunghezza minima

Altri tipi di chiave sono indicati con `<<UNIQUE>>` oppure `<<CK>>`

+ *Chiavi esterne* :
	Sono un insieme di attributi in una relazione R che riferisce la *chiave primaria* di un'altra realazione S 
	Le *relazioni* sono create con questo meccanismo
	La *chiave esterna* deve rispettare il vincolo di *integrità refrenziale* ossia essa non può assumere valori non presenti nella chiave a cui si riferisce

Esempio :

![[Pasted image 20231023124851.png]]

##### Valori non nulli

Un attributo può avere valore non specificato ( *proprietà praziali* ) per varie ragioni :
+ non applicabile 
+ sconoscituo al momento

Per indicare valori non specificati si usa *NULL* 

Negli schemi relazionali si può imporre il vincolo *NOT NULL* per un attributo ( questo non può avere come valore *NULL* , deve essere inserito , non può essere sconosciuto )

Gli attributi delle *chiave primaria* ( in generale delle *chiavi* ) devono assumere valore *NOT NULL*
Una *chiave esterna* può avere come valore *NULL* se essa rappresenta un associzione parziale

### Da Modello a Oggetti al Modello Relazionale

#### N : 1

##### Univoche e totali

![[Pasted image 20231023125801.png]]

La *foreing key* va messa dalla parte della moltelicità N che punta alla molteplicità 1
Inoltre se sono presenti degli attributi sulla relazione questi devono essere inseriti all'interno della *tabella* che contiene la *foreing key*
##### Univoche e parziali

![[Pasted image 20231023130147.png]]

Se le associazioni sono parziali dalla parte univoca abbiamo 2 scielte su come tradurlo nello schema relazionale :
+ Mantere la traduzione delle *univoche e totali* permettendo però alla chiave esterna di essere *NULL*
+ Creando una nuova classe che colleghi le 2 classi attraverso 2 *key* , una *private key* che identifica l'oggetto questa sarà anche *foreing key* per il verso che non ha la parzialità , per il verso che ha la *parzialità* avremo una foreing key
	Così facendo essendo che la *primary key* non può mai essere *NULL* se non esiste una relazione nel verso parziale allora semplicemente non essiterà la tabella di connesione

La seconda opzione è preferibile se vi sono molti *NULL* 

Come prima se vi sono attributi nella relazione si aggiungono dove vi sono le *forening key*
##### Ricorsive

![[Pasted image 20231023132301.png]]

Le associazioni ricorsive parziali si risolvono come nelle univoche e parziali , abbiamo quindi 2 scielte riguardanti la traduzione come nelle univoche e parziali
Seguono le stesse regole delle univoche e parziali
#### 1 : 1

![[Pasted image 20231024131626.png]]
>[!todo]
##### Parzialità

![[Pasted image 20231024131643.png]]
>[!todo]
#### N : M

![[Pasted image 20231024131718.png]]
>[!todo] 
##### ricorsione

![[Pasted image 20231024131731.png]]
>[!todo] 

#### Sottoclassi

Per tradurre le *sottoclassi* abbiamo a disposizione 3 possibili soluzioni

Esempio :

![[Pasted image 20231024132129.png]]

##### Relazione Unica

Nella *relazione unica* creo una *relazione* unica contente tutti gli attributi ( anche le chiavi ) ed in più un discriminante che mi permette di distinguere in che classe mi trovo

![[Pasted image 20231024132703.png]]
##### Partizionamento Verticale

Nel *partizionamento verticale* mantengo la divisione delle sottoclassi ed inserisco in ogni sotto-relazione la chiave della superclasse come *primary key* e come *foreing key* alla "superelazione" ( la superclasse originale )

![[Screenshot 2023-10-24 133034.png]]

##### Parizionamento Orizzontale

Nel *partizionamento orizzontale* creo 3 tabelle indipendenti , le tabelle relative alle sottoclassi dovranno contenere tutti i campi della sovraclasse ( ciò crea duplicazione di dati )
>[!warning]
>Se la superclasse ha delle *foreing key* entranti non si può utilizzare questo parizionamento poichè nel caso di sottoclassi partizione non si potrebbe fare il collegamento 
 
![[Pasted image 20231024133554.png]]

In questo caso la tabella della superclasse non è presente poichè le sue sottoclassi erano disgiunte e quindi l'unione delle stesse crea la superclasse per questo aver la tabella della superclasse creerebbe ridondanza nei dati
##### Cosa sciegliere ?

+ **Relazione Unica**
	Conveniente se le sottoclassi differiscono per pochi attributi
+ **Partizionamento orizzontale**
	- Complica la visita di tutti gli elementi della supercalsse ( devo visitare entrambe le sottoclassi )
	- Se vi è un'associzione entrante nella suoperclasse è sconsigliato 
	- Senza vincolo di disgiunzione è necessario creare 3 classi distinte
+ **Parizionamento verticale**
	+ Complica il recupero di tutte le informazioni relative ad un'entità ( sono distribuite in più classi )

##### Che chiave sciegliere ?

+ Per relazioni corrispondenti a *classi radice* ( senza superclasse ) :
	+ attributo univoco , totale , costante
	+ attributo artificiale ( *chiave sintetica* )
+ Relazioni che corrispondo a *sottoclassi* :
	+ chiave della corrispondente *superclasse*
+ Relazioni in associazioni *N : N* :
	+ *concatenazione* delle *chiavi esterne* delle 2 classi

#### Attributi multivalore

Come vengono tradotte le *sequenze* ?
Creo una nuova sottoclasse contente come *primary key* e *foreing key* la chiave della sua superclasse ( ossia dove c'è la sequenza ) 
Aggiungo un attributo che serà un singolo elemento della sequenza originale e la pongo come *primary key* ( viene così creata una associazione simil *N : M* )

Prima :
![[Pasted image 20231025101033.png]]

Dopo :
![[Pasted image 20231025101009.png]]
>[!todo]
>svolgimento esercizi


## Algebra Relazionale

L'*algebra relaziomale* sono un insieme di operatori che danno come risultato relazioni , possiamo avere :
+ *Operatori primitivi* ( ridenominazione, proiezione, unione e differenza, restrizione, prodotto )
+ *Operatori derivati* ( giunzione, divisione, ... )
+ *Altri operatori* ( raggruppamento, order by, min, max )

*Calcolo relazionale* : linguaggio dichiarativo ( espressioni ) di tipo logico da cui è derivato l'SQL
### Notazione

Data una relazione $R\space( A_1 : T_1 , \dots , A_n : T_n )$ avremo :
+ *tipo* : insieme dei tipi $\{( A_1 : T_1 , \dots , A_n : T_n )\}$
+ *grado* : $n$
+ *valore* : data una ennupla $t$ avremo che :
	$t.A_i$ risulterà essere il *valore* dell'attributo $A_i$

Nel modello di base non viene utilizzato il *NULL*
### Ridenominazione

Indicata con $\rho$
Data una *relazione* R(X) con X insieme di attributi abbiamo che $A \in X$ e $B \notin X$ 
Avremo che 
$$\rho_{A\leftarrow B}(R)$$
Sarà la relazione R dove A viene ridenominato con B

Formalizzazione :
$$\rho_{A\leftarrow B}(R)=\{t\space |\space \exists\space u \in R\quad t.B=u.A\space \land\space \forall C \in X-\{A\}\quad t.C=u.C \}$$
La nuova relazione avrà :
+ *grado* : stesso grado di R
+ *tipo* : stesso tipo di R ma con un attributo modificato $\rho_{A\leftarrow B}(R) : \{( A_1 : T_1 , \dots , B : T , \dots , A_n : T_n )\}$
+ *cardinalità* : uguale a quella di R

*Esempio*

La ridenominazione risulta essere utile quando vogliamo unire 2 tabelle ( relazioni ) ma queste hanno un attributo con il medesimo nome :

	Studenti( Nome , Cognome , Matricola )
	Esami( Nome , Candidato , Voto )

In questo caso il `Nome` dell'esame , se volessimo unire le 2 tabelle , andrebbe cambiato :
$$\rho_{Nome\leftarrow NomeEsame}(Esami)$$

### Unione e Differenza

Avendo due relazioni R ed S con lo *stesso tipo* 

*Unione* :
	$R\cup S=\{t|t\in R \lor t \in S\}$
*Differenza* :
	$R-S=\{t|t\in R \land t \notin S\}$

La nuova relazione avrà :
+ *tipo* : hanno entrambi lo stesso tipo delle relazioni originarie
+ *cardinalità* : 
	Sapendo che $|R|=n$ e $|S|=m$
	Avremo che :
	+ $|R\cup S|\le n+m$   ( l'unione risulta nella eliminazione dei duplicati per questo $\le$ )
	+ $max\{0 , n-m\}\le|R-S|\le n$   ( poichè tolgo tutto o non tolgo nulla )
### Proiezione

Indicata con $\pi$
Utilizzato per selezionare degli attributi specifici

Data la relazione $R(n)$ con $\{A_1, \dots , A_m\}\subseteq X$
L'operazione $$\pi_{A_1,\dots,A_m}(R)=\{<t.A_1,\dots,t.A_m>|t\in R\}$$
'Elimina' tutti gli attributi diversi da $A_1,\dots,A_m$

La nuova relazione avrà :
+ *tipo* : $\{(t.A_1,\dots,t.A_m)\}$  ossia il tipo degli attributi che abbiamo selezionato
+ *cardinalità* :
	Sapendo che $|R|=n$
	Avremo che :$$|\pi_{A_1,\dots,A_m}(R)|\le n$$
	Anche in questo caso se vi sono duplicati tra gli elementi che selezioniamo queste entry vengono eliminate

	Se gli attributi selezionati sono una *superchiave* ( contengono almeno una *key* ) il numero di ennuple saranno $n$

**Esempio** : 

Abbiamo la seguente relazione 
`Studenti( Nome , Cognome , Matricola <PK> , Anno , Provincia )`

|Nome|Cognome|*Matricola* `<PK>`|Anno|Provincia|
|---|---|---|---|---|
|Paolo|Verdi|71523|2005|VE|
|Anna|Rossi|76523|2006|PD|
|Giorgio|Zeri|71347|2005|VE|
|Chiara|Scuri|71346|2006|VE|

Possiamo selezionare `Nome, Matricola, Provincia`
$$\pi_{\text{Nome,Matricola,Provincia}}(Studenti)$$
La risultante relazione è :

|Nome|*Matricola* `<PK>`|Provincia|
|---|---|---|
|Paolo|71523|VE|
|Anna|76523|PD|
|Giorgio|71347|VE|
|Chiara|71346|VE|

In questo caso la *cardinalità* risulterà essere $n$ poichè la relazione risultante contiene la `<PK>`

Se però avessimo :
$$\pi_{\text{Provincia}}(Studenti)$$
La risultante relazione è :

|Provincia|
|---|
|VE|
|PD|

In questo caso abbiamo che i duplicat
### Restrizione

### Prodotto

### Giunzione
