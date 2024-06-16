# Sistema Informativo

Sistema per la : 
+ Acquisizione
+ Archiviazione 
+ Elaborazione
+ Distribuzione 
delle informazioni necessarie alle attività dell'azienda

![[Immagine 2023-09-19 130447.png]]
# Sistema Informatico

+ Sistema informatico : insieme delle tecnologie infromatiche a supporto delle attività di un organizzazione
+ Sistema informativo automatizzato : parte del sistema informatico che raccoglie, elabora , archivia e scambia le informazioni usando un sistema informatico

# Informazioni 

Nei sistemi informatici le **informazioni** vengono rappresentate in modo essenziale attraverso i **dati**
+ **Informazioni** : elemento che consente di a vere conoscenza più o meno esatta di situazioni
+ **Dato** : ciò che è immediatamente presente alla conoscenza , priva di ogni elaborazione

# Storia 

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

# Sistemi informatici operativi

Attività strutturate e ripetitive ( calcolo paghe, emissione fatture , magazzino )

Elaborazioni su DB : **OLTP** ( **On-Line Transaction Processing** ) 
Operazioni svolte da processi operativi : 
+ Predefinite , semplici
+ Coinvolge pochi dati
+ Dati in dettaglio , aggiornati

# Sistemi informatici direzionali

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
# Base di Dati

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

*Matricola* è la **primary key** ( vincolo di *chiave primaria* ) della tabella ( dovrebbe essere sottolineata )
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
WHERE  Materia = 'BD' AND Voto = 30;

/* response : tutte le matricole con voto 30 in BD */

Matricola : 71523
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

La tabella *InfCorsi* (conta quanti studenti hanno svolto un esame) è una tabella *virtuale* : 
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
		+ [k-anonimity](https://it.wikipedia.org/wiki/K-anonimato) per proteggere i dati riservati :
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

### Aspetto ontologico

Ciò che vogliamo rappresentare sono : 
+ **Conoscenza concreta** :
	I fatti
+ **Conoscenza astratta** :
	Struttura e vincoli sulla conoscenza concreta
+ **Conoscenza procedurale** : 
	Le operazioni di base e degli utenti
+ **Comunicazioni** :
	Come si comunicherà con il sistema informatico

#### Conoscenza Concreta

Per modellare la *conoscenza concreta* dobbiamo modellare 3 tipologie di fatti :
+ **Entità** : es studente , libro , prova d'esame
+ **Collezioni** : es insieme degli studenti , insieme dei libri
+ **Associazioni** : es un esame è associato ad uno studente

##### Entità 

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

##### Collezione

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
##### Associazioni

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

#### Conoscenza Astratta

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
Le associazioni tra più *classi* vengono rappresentate inserendo una classe intermedia al posto di una *associazione* 

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
>#todo

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

La *foreing key* va messa dalla parte della molteplicità N che punta alla molteplicità 1
Inoltre se sono presenti degli attributi sulla relazione questi devono essere inseriti all'interno della *tabella* che contiene la *foreing key*
##### Univoche e parziali

![[Pasted image 20231023130147.png]]

Se le associazioni sono parziali dalla parte univoca abbiamo 2 scielte su come tradurlo nello schema relazionale :
+ Mantenere la traduzione delle *univoche e totali* permettendo però alla chiave esterna di essere *NULL*
+ Creando una nuova classe che colleghi le 2 classi attraverso 2 *key* , una *private key* che identifica l'oggetto questa sarà anche *foreing key* per il verso che non ha la parzialità , per il verso che ha la *parzialità* avremo una foreing key
	Così facendo essendo che la *primary key* non può mai essere *NULL* se non esiste una relazione nel verso parziale allora semplicemente non essiterà la tabella di connesione

La seconda opzione è preferibile se vi sono molti *NULL* 

Come prima se vi sono attributi nella relazione si aggiungono dove vi sono le *forening key*
##### Ricorsive

![[Pasted image 20231023132301.png]]

Le associazioni ricorsive parziali si risolvono come nelle univoche e parziali , abbiamo quindi 2 scelte riguardanti la traduzione come nelle univoche e parziali
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
##### Ricorsione

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
>#todo
## Algebra Relazionale

L'*algebra relaziomale* sono un insieme di operatori che danno come risultato relazioni , possiamo avere :
+ *Operatori primitivi* ( ridenominazione, proiezione, unione e differenza, restrizione, prodotto )
+ *Operatori derivati* ( giunzione, divisione, ... )
+ *Altri operatori* ( raggruppamento, order by, min, max )

*Calcolo relazionale* : linguaggio dichiarativo ( espressioni ) di tipo logico da cui è derivato l'SQL
### Operatori primitivi
#### Notazione

Data una relazione $R\space( A_1 : T_1 , \dots , A_n : T_n )$ avremo :
+ *tipo* : insieme dei tipi $\{( A_1 : T_1 , \dots , A_n : T_n )\}$
+ *grado* : $n$
+ *valore* : data una ennupla $t$ avremo che :
	$t.A_i$ risulterà essere il *valore* dell'attributo $A_i$

Nel modello di base non viene utilizzato il *NULL*
#### Ridenominazione

Indicata con $\rho$
Data una *relazione* $R(X)$ con $X$ insieme di attributi abbiamo che $A \in X$ e $B \notin X$ 
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
#### Unione e Differenza

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
	+ $|R\cup S|\le n+m$ ( l'unione risulta nella eliminazione dei duplicati per questo $\le$ )
	+ $max\{0 , n-m\}\le|R-S|\le n$   ( poichè tolgo tutto o non tolgo nulla )
#### Proiezione

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

In questo caso abbiamo che i duplicati di `VE` risultano essere stati eliminati per questo la *cardinalità* è 2
#### Restrizione

Indicata con $\sigma$

$$\sigma_{\phi}(R)=\{t|t\in R\land \phi(t)\}$$
Utilizzata per creare una relazione le cui ennuple sono le ennuple di R che soddifano la condizione $\phi$

La condizione $\phi$ è una composizione di uguaglianze , disuguaglianze e disequazioni tra attributi ( o tra attributi e costanti )
$$\phi = A_i\space op\space A_j\space|\space A_i\space op\space c\space|\space\neg \phi\space|\space\phi\land\phi\space|\space\phi\lor\phi $$
dove $op$ è un'operazione di confronto

La nuova relaziona avrà :
+ *tipo* : stesso tipo di R
+ *cardinalità* : 
	Sapendo che $|R|=n$
	Avremo che :
	$|\sigma_{\phi}|\le n$

>[!tip]
> Se una restrizione è molto selettiva meglio svolgerla prima di una meno selettiva
> La restrizione gode infatti della proprietà *commutativa*

**Esempio** :

Trovare i dati degli `Studenti` della `Provincia` di Venezia `VE`

$$\sigma_{\text{Provincia = 'VE'}}(Studenti)$$
La relazione risultante sarà :

|Nome|Cognome|*Matricola* `<PK>`|Anno|Provincia|
|---|---|---|---|---|
|Paolo|Verdi|71523|2005|VE|
|Giorgio|Zeri|71347|2005|VE|
|Chiara|Scuri|71346|2006|VE|

Trovare il `Nome` , la `Matricola` e l'`Anno` di iscrizione degli `Studenti` di `Venezia`

$$\pi_{\text{Nome,Matricola,Provincia}}(\sigma_{\text{Provincia = 'VE'}}(Studenti))$$
La relazione risultante sarà :

|Nome|*Matricola* `<PK>`|Anno|
|---|---|---|
|Paolo|71523|2005|
|Giorgio|71347|2005|
|Chiara|71346|2006|

#### Prodotto

$R \times S$

Deve soddisfare una condizione iniziale ossia che R e S devono avere attributi distinti tra di loro ( se abbiamo attributi uguali per mantenere questa condizione basta fare una *ridenominazione* prima del prodotto )

Le ennuple risultanti vengono ottenute tramite la concatenazione tra le ennuple di R e di S

Avremo quindi :
$$R\times S=\{<t\cdot A_1,\dots,t\cdot A_n,u\cdot B_1,\dots,u\cdot B_n>| t\in R \land u \in S\}$$
La nuova realzione avrà :
+ *tipo* : la concatenzione dei tipi di R e S $\{(t\cdot A_1,\dots,t\cdot A_n,u\cdot B_1,\dots,u\cdot B_n>)\}$
+ *cardinalità* : 
	Sapendo che : $|R|=n$ e $|S|=m$
	Avremo che :
	$|R\times S| = n\times m$

Non ci possono essere duplicati nella relazione risultante poichè epr ipotesi iniziale abbimo che tutti gli attribuit devoni essere distinti tra loro

**Esempio** :

`Studenti x Esami`

Con `Studenti` :

|Nome|Cognome|*Matricola* `<PK>`|Anno|Provincia|
|---|---|---|---|---|
|Paolo|Verdi|71523|2005|VE|
|Anna|Rossi|76523|2006|PD|
|Giorgio|Zeri|71347|2005|VE|
|Chiara|Scuri|71346|2006|VE|

Con `Esami` :

|*Codice* `<PK>`|Materia|Candidato `<FK>`|Data|Voto|Lode|
|---|---|---|---|---|---|
|B112|BD|71523|08.07.06|27|N|
|F31|FIS|76366|08.07.06|26|N|
|B247|BD|76366|28.12.06|28|S|

Il prodotto associa ad ogni ennupla di `Studenti` tutte le ennuple di `Esami` , questo però a livello logico non è corretto poichè ad uno stidente viene assegnato un esame di un'altro studente ( non viene rispettato il vincolo di *foreing key* ) 

Per farlo rispettare necessitiamo di fare delle altre operazioni

Innazitutto dobbiamo fare una *restrizione* sul prodotto facendo in modo che abbiamo solo le ennuple tale che la `Matricola` sia uguale al `Candidato`

$$\sigma_{\text{Matricola=Candidato}}(Studenti\times Esami)$$
### Operatori derivati
#### Giunzione

Indicata con $\bowtie$

Utile se vogliamo combinare relazioni correlate tra loro come la precedente 
$$R\underset{A_i=B_j}{\bowtie}S$$
Avendo R e S con attributi distinti 
Possiamo espandere la *giunzione* in :
$$R\underset{A_i=B_j}{\bowtie}S=\sigma_{A_i=B_j}(R\times S)$$

La *giunzione* viene anche chiamata *equijoin* 

**Esempio** :
Nel caso di prima la formula finale può essere scritta come :
$$Studenti\underset{Matricola=Candidato}{\bowtie}Esami$$
##### Giunzione naturale 
$R\bowtie S$
Con $R(X,Y)$ e $S(Z,X)$

Avremo quindi che R ed S hanno un attributo in comune : X

Definizione formale :
$$t\in R \bowtie S\quad \text{sse}\quad t[X\space Y] \in R\ \land\ t[Z\ X]\in S$$
Ossia l'ennupla $t$ esiste in $R\bowtie S$ se e solo se l'ennupla $t$ con attributi $X$ e $Y$ appartiene alla relazione $R$ e se l'ennupla $t$ con attributi $Z$ e $X$ appartiene alla relazione $S$

In sostanza $R\bowtie S$ restituisce una relazione che ha come attributi $X$ $Y$ $Z$ , in cui l'attributo comune $X$ è presente una sola volta

Fa la giunzione di 2 relazioni basandosi su 2 attributi con lo stesso nome

La *giunzione naturale* può essere rappressentata anche attraverso *operazioni primitive* :

Siano $X = \{A_1, \dots , A_n\}$ gli attributi comuni di R e S

1. Come prima cosa dobbiamo *ridenominare* gli attributi comuni :
$$R'=\rho_{A_k\leftarrow RA_k}(R)$$
	Con $k=1,\dots,n$
	Dove $\{RA_1,\dots , RA_n\}$ devono essere attributi nuovi
2. Prodotto 
$$T=R'\times S$$
3. Vogliamo ora svolgere un *equijoin* su $A_k$ e $RA_k$
	$$N = \sigma_{A_k=RA_k}(T)$$
	con $k=1,\dots,n$
	I precedenti 2 passi possono essere riscritti nel seguente modo :
	$$R'\underset{A_k=RA_k}{\bowtie}S$$
4. Ora mi basterà selezionare ( fare la *proiezione* ) di uno degli attributo $A$ o $RA$
	$$\pi_{XYZ}(N)$$
	Dove $X=\{A_1, \dots , A_n\}$ 

**Esempio** :

Abbaimo :
`Studenti(Nome, Matricola <PK>, Cognome)`
`Esami(Codice <PK>, Matricola <FK>(Studenti), Voto, Materia)`

Se facciamo la *giunzione naturale* abbiamo :
$$Studenti\bowtie Esami$$
Avremo come risultato l'*equijoin* :
$$Studenti\underset{Stud.Matricola=Exa.Matricola}{\bowtie}Esami$$
>[!warning]
> Se vi sono più attributi con lo stesso nome dobbiamo capire se volgiamo il comportamento della *giunzione naturale* poichè es :
>`Studenti.Nome != Esami.Nome`
>Ma se facciamo la *giunzione naturale* verrebbero incorporate anche se hanno significato differente in contesti differenti , in questo caso usare una *ridenominazione*

##### Giunzione Esterna

La *giunzione esterna* include nel risultato finale anche le ennuple che non partecipano alla *giunzione* 

*Esempio* :

Se uno studente non ha fatto alcun esame ( ossia non è presente nella tabella `Esami` ) con una *giunzione* verrebbe escluso dalla tabella risultante mentre con una *giunzione esterna* questo viene incluso ma con gli attributi della tabella dove non è presente settati a *NULL*

Vi sono 3 tipi di *giunzione esterne* :
+ *Giunzione esterna completa*
+ *Giunzione esterna destra*
+ *Giunzione esterna sinistra*

###### Completa

Si rappresenta con 
$$R\overleftrightarrow{\bowtie}S$$

E restituisce la *giunzione naturale* di $R$ e $S$ estesa con le ennuple di $R$ ed $S$ che non appartengono alla *giunzione naturale* ( queste vengono completate con *NULL* per gli attributi mancanti )

Formalmente avremo :

Avendo $R(X)$ e $S(Y)$
Dove :
$A_1,\dots,A_n$ sono attributi di R e non di S
$B_1,\dots,B_n$ sono attributi di S e non di R

Avremo quindi : 
$$R\overleftrightarrow{\bowtie}S=R\bowtie S \cup \Big[(R-\pi_X(R\bowtie S))\times\{(B_1=NULL,\dots,B_n=NULL)\}\Big]\cup$$
$$\cup\Big[\{(A_1=NULL,\dots,A_n=NULL)\}\times (S-\pi_Y(R\bowtie S)) \Big]$$
Spiegando :
+ $R\bowtie S$ : *giunzione naturale* iniziale
+ $\cup$ : unisco alla *giunzione naturale* le ennuple non presenti 
+ $\Big[(R-\pi_X(R\bowtie S))\times\{(B_1=NULL,\dots,B_n=NULL)\}\Big]$ : rappresenta le ennuple in R non presente nella *giunzione naturale*
	+ $(R-\pi_X(R\bowtie S))$ : Abbiamo $R$ a cui togliamo gli elmenti nella *giunzione naturale* ( proiezione su $X$ poichè $R\bowtie S$ ha il tipo come l'unione dei tipi di $R$ e $S$ )
	+ $\times$ : dobbiamo completare la tabella con i valori *NULL* degli attributi che non sono presenti 
+ $\Big[\{(A_1=NULL,\dots,A_n=NULL)\}\times (S-\pi_Y(R\bowtie S)) \Big]$ : è la stessa cosa del precedente ma rispetto ad $S$

**Esempio** :

Se la `Matricola` 125443 non ha fatto alcun `Esame` questa verrà inculsa alla *giunzione naturale* nel seguente modo 

|Nome|Cognome|Matricola|Codice|Voto|Materia|
|---|---|---|---|---|---|
|Anna|Rossi|125443|NULL|NULL|NULL|

###### Destra

Si rappresenta con 
$R\overrightarrow{\bowtie}S$

E' un parziale della *giunzione esterna completa*

Ossia :
$$R\overrightarrow{\bowtie}S=R\bowtie S \cup \Big[(R-\pi_X(R\bowtie S))\times\{(B_1=NULL,\dots,B_n=NULL)\}\Big]$$
###### Sinistra

Si rappresenta con 
$R\overleftarrow{\bowtie}S$

E' un parziale della *giunzione esterna completa*

Ossia :
$$R\overleftarrow{\bowtie}S=R\bowtie S \cup\Big[\{(A_1=NULL,\dots,A_n=NULL)\}\times (S-\pi_Y(R\bowtie S)) \Big]$$
#### Intersezione 

Formalmente :
$$R\cap S=\{t|t\in R \land t \in S\}$$
Può essere vista come :
$$R-(R-S)$$
+ $R-S$ : indica le ennuple che stanno in $R$ ma non in $S$
Se poi sottraiamo a queste $R$ allora avremo l'*intersezione* tra $R$ ed $S$

Ora dimostriamo la precedente formula :

partiamo quindi da :
$$t\in R -(R-S)\quad \text{sse}\quad t\in R \land t\notin(R-S)$$
$$t\in R \land\lnot\Big[ t \in (R-S) \Big]$$
$$t\in R \land \lnot\Big[t\in R \land t\notin S\Big]$$
$$t\in R\land \Big[t\notin R \lor t \in S\Big] \quad \text{per deMorgan}$$
$$t\in R\land t\in S\quad \text{Poichè essendo che $t\in R$ non può essere $t\notin R$}$$
Essendo arrivati alla definizione iniziale abbiamo concluso la dimostrazione
#### Divisione

Si indica con $\div$

Abbiamo :
$R(XY)$
$S(Y)$

Vogliamo produrre una relazione $T(X)$ tale che una ennupla $t$ è di $T$ se e solo se per ogni $s$ di $S$ l'ennupla $<t, s>$ appare in $R$
$$R\div S$$
**Esempio** 

Abbiamo $R$ :

|$X$|$Y$|
|---|---|
|t1|s1|
|t1|s2|
|t2|s2|
|t1|s3|
|t3|s1|
|t3|s2|
|t3|s3|

Abbiamo $S$ :

|$Y$|
|---|
|s1|
|s2|

$R\div S =$

|X|
|---|
|t1|
|t3|

Questo perchè decidiamo di inserire in $R \div S$ un $t$ se e solo se in $R$ è concatenato da ogni ennupla di $S$

Quindi per $t1$ visto che è accopiato sia da $s1$ che da $s2$ in $S$ allora $t1$ può essere inserto in $R \div S$
Stessa cosa per $t3$ 
$t2$ invece non è concatenato ad $s2$ quindi non possiamo inserirlo nella tabbella $R \div S$

Formalmente quindi avremo che :
$$R \div S=\{t|t \in \pi_X(R)\land \forall s \in S \quad <t,s>\in R\}$$

**Dimostrazione**

Se compariamo la divisione sulle relazioni e sui numeri

Nei *numeri* abbiamo :
$$r\div s = max\{t |t\cdot s \le r\}\quad \text{con $s\neq 0$}$$
Nelle *relazioni* abbiamo :
$$R\div S=max\{T|T\times S\subseteq R\}\quad \text{con $S\neq 0$}$$

>[!todo]
>completa dimostrazione
>#todo

**Esempio** :

Vogliamo ricavare la `Matricola` degli studenti che hanno fatto tutti gli esami che ha fatto anche Anna Rossi ( `Matricola = 76366` )

Abbiamo 2 tabelle ricavate così :
+ $ES\_AR=\pi_{Materia}(\sigma_{Candidato='76366'}(Esami))$
	Questa rappresenta tutte le materie di cui ha svolto un esame Anna Rossi
+ $ES=\pi_{Candidato,Materia}(Esami)$ 
	Questa rappresenta la tabella con le matricole e gli esami svolti da tutti gli studenti

La tabella che quindi volgiamo sarà data dalla seguente operazione
$$ES\div ES\_AR$$

>[!todo]
>tabella di spiegazione
>#todo

L'operazione di $\div$ può essere scritta in termini di *operatori primitivi* nel seguente modo :
$$R\div S=\pi_{X}(R)-\pi_{X}\big((\pi_X(R)\times S)-R\big)$$
Spiegazione :

>[!todo]
>completa spiegazione
>#todo


**Dimostrazione** :
>[!todo]
>completa dimostrazione
>#todo

#### Proiezione generalizzata

$$\pi_{Exp_1\ \textbf{AS}\ A_1\ ,\ Exp_2\ \textbf{AS}\ A_2 \ ,\ \dots \ , Exp_n\ \textbf{AS}\ A_n } ( R )$$

In questo caso le espressioni $Exp_n$ possono contenere attributi , costanti e operazioni su di essi 

**Esempio** :

Data un relazione : `Utente(Codice, SalarioLordo, Trattenute, ...)`

$$\pi_{\text{Codice, SalarioLordo - Trattenute AS Stipendio }} ( Utente )$$
Questo creerà la seguente tabelle :

|Codice|Stipendio|
|---|---|
|--|--|

Dove `Stipendio` sarà il calcolo effettuato da : `SalarioLorodo - Trattenute`

#### Aggregazione

Le *funzioni di aggregazione* hanno come argomenti *multinsiemi* e ritornano come risultato un valore

+ **sum(...)** : ritorna la somma degli elementi del multinsieme
+ **avg(...)** : ritorna la media degli elementi del multinsieme
+ **count(...)** : ritorna il numero degli elementi del multinsieme
+ **min(...)** e **max(...)** : ritorna il minimo e il massimo valore degli elementi del multinsieme

Se vogliamo ignorare eventi duplicati ( 23 , 30 , 30 -> il secondo 30 viene ignorato ) si estende il nome della funzione con la stringa *-distinct*  

#### Raggruppamento

$$A_1,A_2,\dots,A_n\ \gamma \ f_1,f_2,\dots,f_n (R)$$

Dove $f_n$ sono *funzioni di aggregazione* e $A_n$ sono attributi di $R$

L'operatore $\gamma$ restituisce una realzione con tipo :
$$\{(A_1:T_1,\dots,A_n:T_n\ , f_1:T_{f_1}\ , \dots , f_k : T_{f_k} )\}$$
Il cui *grado* è : $n+k$

**Funzionamento** :

1. Si divide la relazione $R$ rispetto agli attributi  $A_1,\dots , A_n$ 
	Si vanno quindi a creare un insieme di gruppi che hanno all'interno ennuple i cui attributi  $A_1,\dots , A_n$  coincidono
	Se $A_1,\dots , A_n=\emptyset$  si crea un unico gruppo contente tutte le ennuple di $R$
2. Si calcolano le *funzioni di aggregazione* per ogni gruppo 
3. Ogni gruppo restituirà una sola ennupla contente :
	+ I valori degli attributi $A_1,\dots , A_n$ 
	+ i risultati delle funzioni $f_1,\dots , f_k$ 

![[Pasted image 20231109094326.png]]

**Esempio**

Vogliamo restituire per ogni `Candidato` il : n° di esami svolti , il voto minimo , il voto massimo e la media dei suoi voti

Abbiamo :

`Esami( Materia , Candidato , Data , Voto , Lode )`

|Materia|Candidato|Data|Voto|Lode|
|---|---|---|---|---|
|BD|71523|08.07.06|20|N
|FIS|76366|08.07.07|26|N
|ASD|71523|28.12.06|30|S
|BD|76366|28.12.06|28|N

$$\text{Candidato}\ \gamma \ \text{count(*), min(Voto), max(Voto), avg(Voto)}\Big(Esami\Big)$$
1. Raggruppamento rispetto a `Candidato`

|Materia|Candidato|Data|Voto|Lode|
|---|---|---|---|---|
|BD|71523|08.07.06|20|N
|ASD|71523|28.12.06|30|S

|Materia|Candidato|Data|Voto|Lode|
|---|---|---|---|---|
|FIS|76366|08.07.07|26|N
|BD|76366|28.12.06|28|N

2. Calcolo delle *funzioni* e merge 

|Candidato|Count(\*)|min(Voto)|max(Voto)|avg(Voto)|
|---|---|---|---|---|
|71523|2|20|30|25
|76366|2|26|28|27

>[!info]
>`{SQL}count(*)`
>significa che conta tutte le ennuple presenti nel gruppo

#### Multinsiemi

##### Proiezione senza l'eliminazione dei duplicati

$$\pi^b_{A_1,\dots,A_n}(O)$$
L'apice $b$ ( bag ) indica che si decono mantenere i duplicati sulla *proiezione*
##### Eliminazione dei duplicati

Per elimirare tutti i duplicati da una relazione O :
$$\delta(O)$$
##### Ordinamento

Ordinamento lessicografico degli attributi specificati all'interno della relazione O 

$$\daleth_{A_1,\dots,A_n}(O)$$
##### Unione , Intersezione , Differenza con bag ( b )

Unione , Intersezione , Differenza con bag ( b ) significa svolgere le operazioni insiemisitiche *mantenedo* i duplicati

+ *Unione* : 
	$O_1\ \cup^b \ O_2$

	**Esempio** :
	$O_1=\{1,1,1,2,2,3\}$
	$O_2=\{2,2,2,3,3,4\}$
	$O_1\ \cup^b \ O_2 = \{1,1,1,2,2,2,2,2,3,3,3,4\}$
+ *Intersezione*
	$O_1\ \cap^b \ O_2$
	Contiene solo le ennuple che compaiono meno volte 
	**Esempio** :
	$O_1\ \cap^b \ O_2 = \{2,2,3\}$
+ *Differenza*
	$O_1\ -^b \ O_2$
	Un elemento compare nella differenza tante volte quanto appare in $O_1$ meno il numero di volte che compare in $O_2$

	**Esempio** :
	$O_1\ -^b \ O_2 = \{1,1,1\}$
	$O_1\ -^b \ O_2=\{2,3,4\}$ 

### Trasformazioni Algebriche

Utilizzate per anticipare *anticipazioni* , *proiezioni* e *restrizioni* in modo da avere meno ennuple quando dobbiamo svolgere una *moltiplicazione*

**Esempio** :

Prendiamo la relazione `R(A, B, C, D)`

+ $\pi_A(\pi_{A,B}(R))\equiv \pi_A(R)$
+ $\sigma_{C_1}(\sigma_{C_2}(R))\equiv \sigma_{C_1\land C_2}(S)$
+ $\sigma_{C_1\land C_2}(S\times R)\equiv \sigma_{C_1}(R)\times \sigma_{C_2}(S)$
+ $R\times(S\times T) \equiv (R\times S)\times T$
+ $\sigma_C(X\gamma F(R))\equiv X\gamma F(\sigma_C(R))$

**Esempio di Ottimizzazione**

Consideriamo le relazioni `R(A, B, C, D)` e `S(E, F, G)` e la seguente espressione da ottimizzare :
$$\pi_{A,F}(\sigma_{A=100\land F\gt5 \land A=E}(R\times S))$$

Le espressioni possono essere rappresentate attravero degli *alberi*

![[Pasted image 20231109105407.png]]

Ora utilizziamo  $\sigma_{C_1\land C_2}(S\times R)\equiv \sigma_{C_1}(R)\times \sigma_{C_2}(S)$ per semplificare  $\sigma_{A=100\land F\gt5 \land A=E}(R\times S)$
Ovviamente in questo caso abbiamo che possiamo anticipare $A=100$ e $F\gt 5$ ma non $A=E$ poichè $A$ ed $E$ si trovano assieme solo sulla tabella ottenuta dopo $\times$

![[Screenshot 2023-11-09 105740.png]]

Ora visto che necessitiamo solo di $A$ , $E$ , $F$ per formare la tabella finale possiamo anticipare la *proiezione* di questi attributi prima di $\times$ 

![[Pasted image 20231109110220.png]]

### Calcolo Relazionale 

Esistono 2 varianti del *calcolo relazionale* :
+ *calcolo relazionale di ennuple* ( *CRE* )
+ *calcolo relazionale su domini* ( *CRD* )

Tutti questi linguaggi sono espressivamente *equivalenti* ( ossia posso ricavare lo stesso risultato con 3 formule differenti ) 

Linguaggi  espressivamente *equivalenti* ai sopra citati viene detto *relazionalemente completo* 

 + *calcolo relazionale*  
	+ Un'interrogazione del DB è un'espressione che specifica cosa va recuperato ma non come venga recuperato ( operazioni decise dal DBMS ) ( *dichiarativo* )
+ *algebra relazionale*
	+ Un'interrogazione del DB è un'espressione che specifica oltre a cosa va recuperato anche le operazioni necessarie al loro recupero ( *procedurale* )

>[!todo] 
>completa algebra relazionale
>#todo

## SQL

Chiamato **Strucutred English QUEry Language** o **SEQUEL** o **SQL**

Si utilizza lo standard SQL:2006
I sistemi industriali utilizzano uno standard differente includendo funzionalità non previste , non includendone alcune o implementandole in modo differente

### Caratteristiche

SQL è un linguaggio *dichiarativo* basato sul *calcolo relazionale su ennuple* e *algebra relazionale*
Le relazioni diventano *tabelle* 
Le ennuple diventano *record* o *righe*
Gli attributi diventano *campi* o *colonne*

Le tabelle possono avere righe duplicate per :
+ *efficenza* : eliminare i duplicati costa ( $n\cdot\log n$ )
+ *flessibilità* : può essere utile vedere i duplicati per svolgere correttamente le funzioni di aggregazione ed altro

SQL comprende :
+ *DML* ( *Data Manipulation Language* ) $\rightarrow$ per svolgere query
+ *DDL* ( *Data Definition Language* ) $\rightarrow$ per definire una base di dati

### DML

Il construtto base dell'*SQL* è il seguente 
```SQL
SELECT [DISTINCT] Attributi
FROM Tabelle
[WHERE Condizione]
```
#### SELECT

La `{SQL}SELECT` ci permette di selezionare come sarà fatto la tabella risultante ( la *target list* in algebra relazionale ) 

`{sql}SELECT *` significa selezionare per la tabella finale tutti gli attributi dati dalla `{sql}FROM` e `{sql}WHERE` 

**Esempi** :

```SQL
SELECT *
FROM Studenti;
```
Creo una tabella contenete tutti gli `Studenti`

```SQL
SELECT *
FROM Esami
WHERE Voto > 26;
```
Creo una tabella contente tutti gli esami che abbiano come `Voto > 26`

```SQL
SELECT DISTINCT Provincia
FROM Studenti;
```
Creo una tabella nella quale ci sono le `Provincie` da dove provengono gli studenti 
`{sql}DISTINCT` Rimuove i duplicati 

```SQL
SELECT *
FROM Studenti JOIN Esami ON Matricola = Candidato;
```
Creo una tabella che è l'*equi-join* tra `Studenti` ed `Esami` ( l'attributo sul quale facciamo il *join* è `Candidato` e `Matricola` , equivale a fare $Studenti\underset{Matricola=Candidato}{\bowtie}Esami$ )
#### FROM

La `{SQL}FROM` ci permette di dire che tabelle e quale loro combinazione useremo per ottenere la tabella risultante

#### WHERE

La `{SQL}WHERE` ci permette di imporre delle condizioni sugli attributi che andremo a selezionare per costruire la tabella risultante   

#### Disambiguazione

Se ho tabelle che presentano gli stessi attributi devo specificare da che tabella provengono ( *Disanbiguazione* ) : `Esami.CodDoc` e `Docenti.CodDoc` 

#### Alias

Si associa un identificatore alle relazioni , essenziale se si opera su più copie della stessa relazione 

**Esempio** :

Generare una tabella che contenga cognomi e matricole degli studenti e dei tutor
```sql
SELECT s.Cognome, s.Matricola, t.Cognome, t.Matricola
FROM Studenti s JOIN Studenti t ON s.Tutor = t.Matricola
```

Gli *Alias* permettono la ricorsività su un numero arbitrario di elementi 

**Esempio** : 

Cognome e Nome delle persone ( e dei Nonni ) che fanno lo stesso lavoro dei Nonni 

Dove avremo la seguente tabella :
`{sql}Persone(Id, Nome, Cognome, IdPadre, Lavoro)`
`PK(Id) , IdPadre FK(Persone)`
Avremo quindi che ci sarà una ricorsità su `Persone` che indica il Padre di ogni persona legando l'`Id` e il `IdPadre`
Ad una Persona corrisponde un nonno se abbiamo una prima relazione con suo padre e una seconda relazione tra suo padre e il padre di suo padre ( il nonno ) 

```sql
SELECT n.Nome , n.Cognome , f.Nome , f.Cognome
FROM Persone n , Persone p , Persone f
WHERE f.IdPadre = p.Id AND p.IdPadre = n.Id AND n.Lavoro = p.Lavoro
```
#### AS

```sql
Expr AS Nome
```

Diamo il nome `Nome` alla colonna ottenuta come risultato dell'espressione `Expr`

Usato per dare un nome ad un attributo calcolato :
```sql
SELECT Nome, Cognome, date_part('year', current_date)-Nascita AS Età
FROM Studenti
WHERE Provincia='VE'
```
#### Espressioni

Le *espressioni* possono includere operatori aritmetici ( o altri operatori e funzioni sui tipi degli attributi ) o funzioni di *aggregazione* 

>[!warning]
>Le funzioni di *aggregazione* **NON** possono essere usate nella clausola `{sql}WHERE`  

Le funzioni di *aggregazione* sono :
```sql
SUM , COUNT , AVG , MAX , MIN
```

##### Esempi

Numero di elementi della relazione Studenti
```sql
SELECT COUNT(*)
FROM Studenti
```

Anno di nascita minimo , massimo e medio degli studenti 
```sql
SELECT MIN(Nascita) , MAX(Nascita), AVG(Nascita)
FROM Studenti
```

è diverso da , questa quey infatti nel calcolo della media non considera i duplicati ( `{sql}DISTINCT` )
```sql
SELECT MIN(Nascita) , MAX(Nascita) , AVG( DISTINCT Nascita )
FROM Studenti
```

>[!warning]
Questa query non ha senso
```sql
SELECT Candidato, AVG(Voto)
FROM Esami
```

Numero di Studenti che hanno un Tutor 
```sql
SELECT COUNT(Tutor)
FROM Studenti
```

Numero di Studenti che fanno i Tutor
```sql
SELECT COUNT(DISTINCT Tutor)
FROM Studenti
```
#### Giunzioni

Nel `{sql}FROM` si possono combinare le tabelle attraverso le *giunzioni* oppure facendo il prodotto attraverso la virgola : `{sql}FROM T1 , T2`

Quindi il `{sql}FROM` può essere formato nel seguente modo :

```sql
Tabella  [Identificativo(Ide)] {, Tabella [Ide]}  |

Tabella Giunzione Tabella [USING (Attributi) | ON Condizione]
```

Le *giunzioni* possono essere :

```sql
[CROSS|NATURAL] [LEFT|RIGTH|FULL] JOIN
```

##### CROSS JOIN

Il `{sql}CROSS JOIN` realizza il prodotto tra 2 tabelle 

**Esempio**

```sql
SELECT *
FROM Esami CROSS JOIN Docenti
```

##### NATURAL JOIN

Rappresenta la *giunzione naturale* ( se vi sono 2 attributi con lo stesso nome )

**Esempio**

```sql
SELECT *
FROM Esami NATURAL JOIN Docenti
```

##### JOIN ... ON Condizione

Effettua il `{sql}JOIN` su una condizone ( esempio quali valori devono essere uguali ma si possono anche utilizzare : `{sql}=, <> ( diverso ), >, <, >= , <= , AND , OR` ) 

**Esempio** :

```sql
SELECT *
FROM Studenti s JOIN Studenti t ON s.Tutor = t.Matricola
```
Seleziono tutti i Tutor
##### JOIN ... USING Attributi comuni

Effettua il `{sql}NATURAL JOIN` ma solo sugli attributi comuni elencati

**Esempio** :

```sql
SELECT s.Cognome AS CognomeStud, e.Materia, d.Cognome AS CognomeDoc
FROM Studenti s JOIN Esami e ON s.Matricola = e.Candidato 
	 JOIN Docenti d USING (CodDoc);
```

##### LEFT, RIGHT, FULL

Se precede `{sql}JOIN` svolge la corrispondente *giunzione esterna* 

**Esempio** : 

Esami di tutti gli studenti , con cognome e nome relativo elencando anche gli studenti che non hanno fatto esami 

```sql
SELECT Nome, Cognome, Matricola, Data, Materia 
FROM Studenti s LEFT JOIN Esami e ON s.Matricola=e.Candidato;
```

Risultato :

|Nome|Cognome|Matricola|Data|Materia|
|--|--|--|--|--|
|Chiara|Scuri|71346|NULL|NULL
|Giorgio|Zeri|71347|NULL|NULL
|Paolo|Verdi|71523|2006-07-08|BD
|Paolo|Verdi|71523|2006-12-28|ALG
|Paolo|Poli|71576|2007-07-19|ALG
|Paolo|Poli|71576|2007-07-29|FIS
|Anna|Rossi|76366|2007-07-18|BD
|Anna|Rossi|76366|2007-07-08|FIS

#### ORDER BY

Utilizzato per ordinare la tabella secondo gli attributi indicati ( in ordine lessicografico ) in modo crescente ( `{sql}ASC` , ordinamento di default )  o decrescente ( `{sql}DESC` )

**Esempio** :

```sql
SELECT Nome,Cognome 
FROM Studenti 
WHERE Provincia=’VE’ 
ORDER BY Cognome DESC, Nome DESC
```

Quando inseriamo 2 ordinamenti su attributi differenti questi vengono utilizzati in caso di ambiguità nel primo ordinamento 

>[!todo]
>riscrivi meglio
>#todo
#### Operatori Insiemistici

Operatori che possono essere applicate per combinare tabelle con colonne di ugual nome ( se le tabelle hanno attributi con lo stesso tipo ma nome differenti possiamo rinominarle con `{sql}AS` ) e tipo 

Le operazioni insiemistiche rimuovono i duplicati a meno che non specificato con `{sql}ALL` 

Gli operatori sono : `{sql}UNION` `{sql}INTERSECT` `{sql}EXCEPT` 

>[!note]
> Gli operatori insiemistici vengono sempre applicati su 2 tabelle

**Esempi** :
##### 1 

Nome, cognome e matricola degli studenti di Venezia e di quelli che hanno preso più di 28 in *qualche* esame

```sql
SELECT Nome, Cognome, Matricola 
FROM Studenti 
WHERE Provincia='VE' 
UNION 
SELECT Nome, Cognome, Matricola 
FROM Studenti JOIN Esami ON Matricola = Candidato 
WHERE Voto>28
```

Può essere scritta senza gli operatori insiemistici :

```sql
-- necessario il distinct poichè gli operatori insiemistici tolgono i duplicati inplicitamente
SELECT DISTINCT s.Nome , s.Cognome , s.Matricola
-- left join poichè ci possono essere studenti che non hanno fatto esami di venezia , se non ci fosse il left non verrebbero inclusi nel risultato finale
FROM Studenti s LEFT JOIN Esami e ON s.Matricola = e.Candidato 
WHERE e.Voto > 28 OR s.Provincia = 'VE'
```

##### 2

Matricole degli studenti che non sono tutor

```sql
SELECT Matricola
FROM Student
-- tutti gli studenti tranne i tutor
EXCEPT
-- tutor è lo stesso tipo di matricola ma diverso nome
SELECT Tutor AS Matricola
FROM Studenti
```

Equivalentemente 

```sql
SELECT s.Matricola
-- Left join poichè devo matenere gli studenti che non sono tutor
FROM Studenti s LEFT JOIN Studenti t ON s.Matricola = t.Tutor
WHERE t.tutor IS NULL
```

##### 3

Nome e cognome degli studenti che hanno preso in un esame 18 e in un altro esame 30

```sql
SELECT Nome, Cognome, Matricola 
FROM Studenti JOIN Esami ON Matricola=Candidato
WHERE Voto = 18
-- ALL mantiene i duplicati minori tra i 2 insiemi , es 3 volte 18 e 4 volte 30 -> nella tabella finale 3 volte lo studente
	INTERSECT ALL
SELECT Nome, Cognome, Matricola
FROM Studenti JOIN Esami ON Matricola=Candidato
WHERE Voto = 30
```

Equivalentemente 

```sql
-- se non mi interessano i duplicati utilizzo il DISTINCT nella SELECT , altrimenti in questo caso avremmo avuto n*m linee dello stesso studente ( n=e.voto=18 , m = e.voto=30 )
SELECT DISTINCT s.Nome , s.Cognome , s.Matricola
FROM Studenti s JOIN Esami e ON s.Matricola = e.Candidato
				JOIN Esami e2 ON s.Matricola = e2.Candidato
WHERE e.Voto = 18 AND e2.Voto = 30
```

>[!todo]
>spiegazione
>#todo
#### NULL

`{sql}NULL` è un valore speciale : `unknown = U` -> nè false nè true 
Questo cambia i risultati delle espressioni , necessitiamo l'implementazione di una logica a 3 valori :

| $p$ | $\lnot p$ |
| --- | --------- |
| U   | U         |

| $p$ | $q$ | $p\land q$ | $p\lor q$ |     |
| --- | --- | ---------- | --------- | --- |
| T   | U   | U          | T         |     |
| F   | U   | F          | U         |     |
| U   | T   | U          | T         |     |
| U   | F   | F          | U         |     |
| U   | U   | U          | U         |     |

`{sql}NULL = 0` non è nè vero nè falso ma *unknown*
`{sql}NULL = NULL` è *unknown*

Per questo necessitiamo di un predicato specifico che svolga il *test di nullità* : `{sql}Expr IS [NOT] NULL` risulta vera se `{sql}Expr` è `{sql}NULL` o non è `{sql}NULL`

**Esempi** :

Gli Studenti che non hanno tutor

```sql
SELECT *
FROM Studenti
WHERE Tutor IS NULL
```

```sql
SELECT *
FROM Studenti 
WHERE Tutor = NULL
```
Questa query non ritorna alcuna ennupla poichè `{sql}Tutor = NULL` risulta essere sempre falsa

##### Altri operatori per NULL

+ `{sql}Expr1 IS [NOT] DISTINCT FROM Expr2`
	Risulta *vero* se i due valori sono diversi o uno solo dei due è `NULL`
	Se entrambi i valori sono uguali o entrambi `NULL` l'espressione risulta *falsa*
	L'inverso con il `{sql}NOT`
+ `{sql}COALESCE(Expr1,...,Exprn)`
	Viene utilizzato per traformare un valore `NULL` in un valore non nullo
	Valuta le espressioni in sequenza da sinistra verso destra , restituisce il primo valore trovato differente da `NULL` , ritorna `NULL` se tutte le espressioni hanno valore `NULL`
#### BETWEEN

`{sql} WHERE Expr BETWEEN Expr AND Expr`

Restituisce i valori compresi tra 2 espressioni

**Esempio** :

Restituire gli studenti con matrocola compresa tra 71000 e 72000 
```sql
SELECT *
FROM Studenti
WHERE Matricola BETWEEN 71000 AND 72000
```
#### Pattern Matching

Utilizzato principalmente sulle stringhe 

`{sql}WHERE Expr LIKE Pattern`

Il `Pattern` può contenere dei caratteri speciali :
+ `%` : indica una sequenza di 0 o più caratteri
+ `_` : indica un carattere qualsiasi

**Esempio** : 

Tutti gli studenti con il nome di almento 2 caratteri che inizia per A
```sql
SELECT *
FROM Studenti
WHERE Nome LIKE 'A_%'
```

Tutti gli studenti con il nome che inizia per A e termina per a o per i
```sql
SELECT *
FROM Studenti 
WHERE Nome LIKE 'A%a' OR Nome LIKE 'A%i'
```

#### WHERE

Può essere :
+ `{sql}Expr Comp Expr`
+ `{sql}Expr Comp (Sottoselect che ritorna esattamente un valore)`
+ `{sql}Expr [NOT] IN (Sottoselect)` oppure `{sql}IN (v1,...,vn)`
+ `{sql} [NOT] EXISTS (Sottoselect)`
+ `{sql}Expr Comp (ANY | ALL) (Sottoselect)`

Dove `Comp` : $\lt,=,\gt,<> (\text{not}),\le,\ge$

##### SELECT annidate

Utili per estrarre dati dalla base di dati per fare dei confronti 

Possiamo eseguire confronti con l'insieme di valori ritornati dalla sottoselect ( sia quando questo è un singoletto sia quando contiene più elementi )
+ Se restituisce un solo valore posso semplicemente svolgere un'operazione di confronto
	**Esempio** :
	
	Studenti che vivono nella stessa provincia di `{sql}'71346'` escluso lo studente stesso
```sql
SELECT *
FROM Studenti
WHERE (Matricola<> '71346') AND
		Provincia = (SELECT Provincia
					 FROM Studenti
					 WHERE Matricola = '71346')
 ```

La sottoselect non è necessaria infatti si può tradurre nel seguente modo :
```sql
SELECT altri.*
FROM Studenti altri, Studenti s
WHERE altri.Matricola<>'71346' AND
	  s.Matricola = '71346' AND altri.Provincia = s.Provincia
```

Oppure :
```sql
SELECT altri.* 
-- utilizzo USING visto che hanno gli stessi attributi
FROM Studenti altri JOIN Studenti s USING (Provincia)
WHERE altri.Matricola <> '71346' AND s.Matricola = '71346’
```

+ Se restituisce più di un valore ho 2 possibilità : 
	+ `{sql}ANY` : utilizzato per confrontare solo alcuni elementi della relazione
		Restituisce *true* se *qualsiasi* confronto con gli elementi della sottoselect restituiscono *true*
	+ `{sql}ALL` : utilizzato per mettere in relazione tutti gli elementi della sottoselect
		Restituisce *true* solo se *tutti* i confronti con gli elementi della sottoselect restituiscono *true*

##### Quantificazione

**Esempio** :

Gli studenti che hanno preso 30 -> risulta essere ambiguo

Possiamo invece detereminare la quantificazione delle seguenti query : 
+ Gli studenti che hanno preso sempre (solo, tutti) 30 : *universale*
+ Gli studenti che hanno preso qualche (almeno un) 30 : *esistenziale* 
+ Gli studenti che non hanno preso mai 30 (senza alcun 30) : *universale*
+ Gli studenti che non hanno preso sempre 30 : *esistenziale*

Una query *universale* se viene negata diventa una *esistenziale* , il contrario per l'*esistenziale* :
+ $\lnot \forall x.P(x)== \exists x .\lnot P(x)$
+ $\lnot \exists x.\lnot P(x)== \forall x.P(x)$

Visto che in sql non esiste un costrutto che ci permetta di fare il $\forall$ utilizziamo l'`{sql}EXISTS` 

##### Quantificazione esistenziale EXISTS

Può essere usata nel `{sql}WHERE` :
`{sql}WHERE [NOT] EXISTS (Sottoselect)`

Per ogni tupla o combinazione di tuple $t$ della select esterna : 
+ calcola la sottoselect
+ verifica se ritorna una tabella \[non] vuota e in quel caso seleziona $t$

**Esempio** 

Studenti con *almeno* un voto > 27

```sql
SELECT *
FROM Studenti s
WHERE EXISTS (SELECT * -- non mi interessa la tabella risultante ma solo se restituisce o no una tabella
			  FROM Esami e
			  WHERE e.Candidato = s.Matricola AND e.Voto > 27)
			  -- con la EXISTS devo collegare la select superiore con la sottoselect
```

La stessa query può essere svolta con una giunzione :

```sql
SELECT DISTINCT s.* -- necessario il DISTINCT altrimenti se uno studente ha più esami con voto>27 ritorno più ennuple
FROM Studenti s JOIN Esami e ON e.Candidato = s.Matricola
WHERE e.Voto > 27
```

##### Quantificazione esistenziale ANY

Il costrutto `{sql}ANY` permette la quantificazione universale :
`{sql}Expr Comp ANY (Sottoselect)`

Per ogni tupla o combinazione di tuple $t$ della select esterna :
+ calcola la sottoselect
+ verifica se `Expr` è in relazione con `Comp` con *almeno* uno degli elementi ritornati dalla select 

**Esempio** :

Studenti con *almeno* un voto > 27

```sql
SELECT *
FROM Studenti s
WHERE s.Matricola =ANY (SELECT e.Candidato
						FROM Esami e
						WHERE e.Voto > 27)
```

oppure :

```sql
SELECT *
FROM Studenti s
WHERE 27 <ANY (SELECT e.Voto
			   FROM Esami e
			   WHERE e.Candidato = e.Matricola)
```

La `{sql}ANY` è equivalente alla `{sql}EXISTS` nel seguente modo :

```sql
SELECT * 
FROM Tab1 
WHERE attr1 op ANY (SELECT attr2 
					FROM Tab2 
					WHERE C)
```
Si traduce in :
```sql
SELECT * 
FROM Tab1 
WHERE EXISTS (SELECT * 
			  FROM Tab2 
		      WHERE C AND attr1 op attr2)
```

##### Quantificazione esistenziale IN

`{sql}IN` è uno zucchero sintattico per `{sql}=ANY` , la sua implementazione è quindi equivalente all'`{sql}=ANY` :

```sql
SELECT *
FROM Studenti s
WHERE s.Matricola IN (SELECT e.Candidato
					  FROM Esami e
					  WHERE e.Voto > 27)
```

`{sql}IN` può essere utilizzato anche elencando dei valori :

```sql
SELECT *
FROM Studenti
WHERE Provincia IN ('PD','VE','BL')
```
Ritornerà gli studenti di Padova , Venezia , Belluno
##### Quantificazione universale NOT EXISTS

**Esempio** :

Gli studenti che hanno preso solo 30
```sql
SELECT * 
FROM Studenti s
WHERE NOT EXISTS (SELECT * 
				  FROM Esami e 
				  WHERE e.Candidato = s.Matricola AND e.Voto <> 30)
```

Se abbiamo degli studenti che non hanno fatto alcun esame questi vengono compresi nella vista finale per evitare questo dobbiamo considerare solo gli studenti che hanno superato qualche esame , avremo quindi :
```sql
SELECT * 
FROM Studenti s
WHERE NOT EXISTS (SELECT * 
				  FROM Esami e 
				  WHERE e.Candidato = s.Matricola AND e.Voto <> 30)
	  AND EXISTS (SELECT * -- solo gli studenti con almeno un esame svolto 
				  FROM Esami e 
				  WHERE e.Candidato = s.Matricola)
```

La query precente può essere scritta senza una sottoselect :
```sql
SELECT s.Matricola, s.Cognome
FROM Studenti s JOIN Esami e ON s.Matricola = e.Candidato 
GROUP BY s.Matricola, s.Cognome 
HAVING MIN(e.Voto) = 30
```

>[!todo]
>appunti
>#todo 
##### Quantificazione universale ALL

La precedente può essere scritta con l'`{sql}ALL` che è il parallelo dell'`{sql}ANY` per la quantificazione esistenziale 

```sql
SELECT * 
FROM Studenti s 
WHERE NOT(s.Matricola =ANY (SELECT e.Candidato 
							FROM Esami e 
							WHERE e.Voto <> 30))
```
Si trasforma in 
```sql
SELECT * 
FROM Studenti s 
WHERE s.Matricola <>ALL (SELECT e.Candidato 
						 FROM Esami e 
						 WHERE e.Voto <> 30)
```

##### Raggruppamento

Costrutto : 
```sql
SELECT ... FROM ... WHERE ...
GROUP BY A1 ... An
[HAVING condizione]
```

Semantica :

+ Esegue le clausole `{sql}FROM ... WHERE ...`
+ Partiziona la tabella risultante rispetto all'uguaglianza su tutti i campi `{sql}A1, ... ,An` 
+ Elimina i gruppi che non rispettano la clausola `{sql}HAVING` 
+ Da ogni gruppo estrae una riga usando la clausola `{sql}SELECT`

**Esempio** :

Per ogni materia trovare il nome della materia e voto medio degli esami in quella materia ( solo materie per le quali sono stati sostenuti più di 3 esami )

```sql
SELECT e.Materia, AVG(e.Voto)
FROM Esami e
GROUP BY e.Materia
HAVING COUNT(*)>3 -- Seleziono solo i gruppi che hanno più di 3 righe (ossia che la materia abbia più di 3 esami svolti)
```

| Codice | Materia | Candidato | Data | Voto | Lode | CodDoc |
| ------ | ------- | --------- | ---- | ---- | ---- | ------ |
| B112 | BD | 71523 | 2006-07-08 | 27 | N | AM1 | 
| A143 | ALG | 71523 | 2006-12-28 | 25 | N | NG2 | 
| B247 | BD | 76366 | 2007-07-18 | 30 | L | AM1 | 
| A213 | ALG | 71576 | 2007-07-19 | 21 | N | NG2 | 
| F31 | FIS | 76366 | 2007-07-08 | 30 | N | GL1 | 
| F45 | FIS | 71576 | 2007-07-29 | 22 | N | GL1 |
|F56|FIS|73442|2007-07-23|25|N|GL1|

Svolgimento del `{sql}GROUP BY` 

| Codice | Materia | Candidato | Data | Voto | Lode | CodDoc |
| ------ | ------- | --------- | ---- | ---- | ---- | ------ |
| B112 | BD | 71523 | 2006-07-08 | 27 | N | AM1 | 
| B247 | BD | 76366 | 2007-07-18 | 30 | L | AM1 | 

| Codice | Materia | Candidato | Data | Voto | Lode | CodDoc |
| ------ | ------- | --------- | ---- | ---- | ---- | ------ |
| A143 | ALG | 71523 | 2006-12-28 | 25 | N | NG2 | 
| A213 | ALG | 71576 | 2007-07-19 | 21 | N | NG2 | 

| Codice | Materia | Candidato | Data | Voto | Lode | CodDoc |
| ------ | ------- | --------- | ---- | ---- | ---- | ------ |
| F31 | FIS | 76366 | 2007-07-08 | 30 | N | GL1 | 
| F45 | FIS | 71576 | 2007-07-29 | 22 | N | GL1 |
|F56|FIS|73442|2007-07-23|25|N|GL1|

L'`{sql}HAVING` selezionerà solo il gruppo di fisica visto che è l'unico avente almeno 3 esami

Calcoliamo quindi le condizinoni sul `{sql}SELECT`

|Materia|AVG(Voto)|
|--|--|
|FIS|25.600|


>[!note]
>Gli attributi espressi non aggregati nella `{sql}SELECT` e in `{sql}HAVING` se presenti devono essere inclusi tra quelli citati nella `{sql}GROUP BY` 
>Gli attributi aggregati (`{sql}AVG(e.Voto)`) vanno scelti tra quelli non raggruppati

**Esempio** : 

Per ogni studente restituire il suo Cognome e Voto medio : 

```sql
SELECT s.Cognome, AVG(e.Voto)
FROM Studenti s, Esami e 
WHERE s.Matricola = e.Candidato
GROUP BY s.Matricola ,-- s.Cognome --devo aggiungere s.Cognome anche se non mi servirebbe nella GROUP BY ma mi serve nella SELECT
```

>[!note]
>Nella clausola `{sql}HAVING` possiamo citare solo : 
>- espressioni su attributi di raggruppamento 
>- funzioni di aggregazione applicate ad attributi non di raggruppamento

**Esempio** :

Ritornare il Cognome e il Voto medio degli studenti che hanno svolto gli degli esami dopo il 2006

```sql
SELECT s.Cognome, AVG(e.Voto)
FROM Studenti s JOIN Esami e ON s.Matricola = e.Candidato
GROUP BY s.Matricola, s.Cognome , -- e.Data 
HAVING YEAR(Data) > 2006; -- Data deve essere incluso nel GROUP BY
```


 Nel *raggruppamento* si assume che  `{sql}NULL=NULL`

**Esempio** :

Ritorna il numero di studenti assegnati ad ogni Tutor

```sql
SELECT Tutor, COUNT(*) AS NStud
FROM Studenti
GROUP BY Tutor
```

Il risultato è :

|Tutor|NStud|
|--|--|
|NULL|2|
|71347|2
|71523|1

In questo caso `{sql}NULL` indica che 2 studenti non hanno un Tutor assegnato

Potrei far 'sparire' il `{sql}NULL` utilizzando un `{sql}COALESCE(Tutor, "Non ha tutor")`

##### CASE

```sql
CASE input_expression 
	WHEN when_expression THEN result_expression 
	...
	[ ELSE Default ]
```

>[!todo]
>incomplete
>#todo

##### Modifica dei Dati

###### INSERT

Sintassi :
```sql
INSERT INTO Tabella [(A1,...,An)]
VALUES (V1,...,Vn) | AS Select
```

Vi sono vari modi di inserire dati in una tabella :

```sql
INSERT INTO Tabella 
	VALUES (V1,...,Vn)
```
In questo caso tutti i valori che inserico in `{sql}VALUES` devono essere posti nel medesimo modo della tabella selezionata ( altrimenti si creano delle inconsistenze )

```sql
INSERT INTO Tabella [(A1,...,An)]
```
Specifico quali e che attributi inserico all'interno della Tabella , nel caso un attributo è un `{sql}NOT NULL` e non vi sono valori di *Default* allora sono costretto ad inserire un valore

```sql
INSERT INTO Tabella AS 
	SELECT ...
```
Inserisco nella tabella i valori che vengono selezionati dalla `{sql}SELECT

###### UPDATE

Sintassi :

```sql
UPDATE Tabella
SET attr1 = expr1 , ... , attrn = exprn;
WHERE Condizione
```

**Esempio** :

Aggiorna il tutor degli studenti 76366 e 76367 a 71523

```sql
UPDATE Studenti
SET Tutor = '71523'
WHERE Matricola = '76366' OR Matricola = '76367'
```

###### DELETE

Sintassi

```sql
DELETE FROM Tabella
WHERE Condizione
```

La *Delete* può far riferimento al massimo ad una tabella 

Cancella quelle righe che soddisfano la *Condizione* , se non specifichiamo un `{sql}WHERE` la `{sql}DELETE` eliminerà tutte le righe della Tabella senza cancellare la Tabella stessa 

**Esempio** :

Elimina tutti gli Studenti che non hanno svolto alcun esame 

```sql
DELETE FROM Studenti
WHERE Matricola NOT IN (SELECT Candidato 
						FROM Esami)
```

Oppure :

```sql
DELETE FROM Studenti
WHERE NOT EXISTS (SELECT * 
				  FROM Esami
				  WHERE s.Matricola = e.Candidato)
```

### DDL

L'SQL è anche un linguaggio per la *definizione* di basi di dati ( *Data Definition Language* , DDL ) 

#### Creazione di uno schema

Uno schema di dati può viene creato da :

```sql
CREATE SCHEMA Nome AUTHORIZATION Utente
```

Questo crea un database con Nome ed asseggna come possesore della base di dati l'utente indicato , se non specifichiamo `{sql}AUTHORIZATION` l'utente che sta eseguendo l'operazione viene scielto come possessore

Uno schema può essere eleminato attraverso il comando : 
`{sql} DROP SCHEMA Nome [CASCADE | RESTRICT]`

Dove :
+ `{sql}CASCADE` indica che verranno rimossi tutti i contenuti dello schema
+ `{sql}RESTRICT` indica che se lo schema contiene delle tabelle l'operazione di eliminazione non viene eseguita 

Nel caso in cui non si specifica una di queste politiche di eliminazione viene scielta la più restrittiva ( `{sql}RESTRICT` )

>[!warning]
>Ad ogni `{sql}CREATE` deve corrispondere un `{sql}DROP`

#### Tabelle

Uno schema può contenere 2 tipi di tabelle : 
+ *tabelle base* ( *base tables* )
	- I metadati appartengono allo schema 
	- I dati *sono* fisicamente memorizzati 
+ *viste*
	- I metadati appartengono allo schema 
	- I dati *non sono* fisicamente memorizzati ( prodotti dalla valutazione di un'espressione ( query ) )
		- Alle viste posso dare un nome e quindi referenziarle 

##### Creazione Tabella

Una tabella viene creata con il comando : 
```sql
CREATE TABLE Nome (
	NomeAttr1 TipoAttr1
	...
	NomeAttrn TipoAttrn
) 
```

Specificando per ogni colonna il 
+ *nome*
+ *tipo di dato* può essere :
	+ *predefinito* 
	+ *definito dall'utente* ( *dominio* )

###### Domini

Un *dominio* può essere creato con il comando :
```sql
CREATE DOMAIN NomeDominio AS TipoDiDato
	[ValoreDiDefault]
	[Vincolo]
```

**Esempio** :

```sql
CREATE DOMAIN Voto AS SMALLINT
	CHECK ( VALUE <= 30 AND VALUE >= 18 )
```
Dominio *Voto* che ha tipo `{sql}SMALLINT` e che può avere valore compreso tra 18 e 30

###### Tipi Predefiniti

+ **Interi** : `{sql} INTEGER , SMALLINT , ...`
+ **Decimali** : 
	+ *fissi* : `{sql}NUMERIC(p,s)` , `p` e `s` indicano il numero massimo di numeri prima e dopo la virgola rispettivamente
	+ *virgola mobile* : `{sql}REAL , FLOAT(p)`
+ **Bit** : 
	+ `{sql}BIT(x)` , stringa di bit di lunghezza fissa `x` 
	+ `{sql} BIT VARYING(x)` , la lunghezza massima della stringa di bit è `x` ma può anche essere di lunghezza minore
+ **Booleani** : `{sql}BOOLEAN`
+ **Stringhe** : 
	+ `{sql}CHAR(x) ( o CHARACTER(x) )` , stringa di caratteri di lunghezza `x`
	+ `{sql}VARCHAR(x) ( o CHAR VARYING(x) o CHARACTER VARYING(x) )`, la lunghezza massima della stringa di char è `x` ma può anche essere di lunghezza minore
+ **Date** : 
	+ `{sql} DATE` : con attributi : `{sql} year , month , day`
	+ `{sql}TIME` : con attributi : `{sql} hour , minute , second `
	+ `{sql}TIMESTAMP` : contiene  gli attributi sia di `{sql}DATE` che di `{sql}TIME`
+ **Intervalli** : `{sql}INTERVAL {YEAR, MONTH, DAY, HOUR, MINUTE, SECOND}`
+ **Testo o oggetti binari** :
	+ `{sql}BLOB` Binary Large Object
	+ `{sql}CLOB` Character Large Object
	In questi tipi di dati non posso performare operazioni di uguaglianza o confronto
+ *Identificatore* :
	`{sql}SERIAL` serve per creare una colonna che costituisca un identificare unico 
	**Esempio** :
```sql
CREATE TABLE tablename ( 
	colname SERIAL,
	name VARCHAR(10) )
```
Per inserire righe all'interno di questa tabella posso :
+ Assegnare come valore a questa righa quando faccio un `{sql}INSERT`  il valore `{sql}DEFAULT` , in questo modo il `{sql}SERIAL` creerà un identificatore unico per quella righa
*Esempio*
```sql
INSERT INTO tablename
VALUES (DEFAULT, ...) 
```

+ Non seleziono la colonna contente `{sql}SERIAL` quando faccio `{sql}INSERT`
*Esempio*
```sql
INSERT INTO tablename(...) -- non inserico la colonna con SERIAL
VALUES (...)
```

###### Vincoli di ennupla

Per ogni colonna posso specificare : 
+ Un valore di *default* :
	+ Questo può essere un valore costante o `{sql}NULL` 
	+ oppure il risultato di una chiamata a funzione che non richiede elementi come input ( *0-aria* ) es : `{sql}CURRENT_DATE`
```sql
CREATE TABLE Province (
	Provincia CHAR(2) DEFAULT 'VE'
)
```
+ Un eventuale *vincolo* es : `{sql}NOT NULL , CHECK (<CONDIZIONE>)`
```sql
CREATE TABLE Studenti ( 
	...
	Cognome VARCHAR(10) NOT NULL,
	Sesso CHAR(1) CHECK(Sesso IN (‘M’, ‘F’))
	...
	)
```

###### Vincoli intra- e inter-relazionali

+ *intrarelazionali* :
	+ `{sql}PRIMARY KEY` : Degnia un insieme di attributi come *chiave primaria*
	+ `{sql}UNIQUE` : designa un insieme di attributi come chiave ( non primaria ) ( a differenza della *primary key* queste possono assumere valori `{sql}NULL` )
	+ `{sql}CHECK` : specifica un'espressione che produce un valore booleano
+ *interrelazionali* :
	+ `{sql}FOREING KEY` : 
		+ rappresenta un insieme di attributi come *chiave esterna*
		+ designa un eventuale azione ( `{sql}NO ACTION , SET NULL , SET DEFAULT , CASCADE` ) da intraprendere se il voncolo di chiave esterna viene violato a causa di *cancellazione* ( `{sql}ON DELETE` ) o *modifica* ( `{sql}ON UPDATE` ) della riga riferita

>[!note]
>Ai vincoli di tabella può essere dato un nome ( per poterli eliminare )

**ON DELETE** : 
+ `{sql}CASCADE` : tutte le righe della tabella interna corrispondenti alla righa cancellata vengono cancellate
+ `{sql}SET NULL` : all'attributo referente viene assegnato il valore `{sql}NULL` al posto del valore cancellato nella tabella esterna
+ `{sql}SET DEFAULT` : all'attributo referente viene assegnato il valore di `{sql}DEFAULT` al posto del valore cancellato nella tabella esterna ( se non esiste il `{sql}DEFAULT` assegniamo il valore di `{sql}DEFAULT` del tipo della colonna )
+ `{sql}NO ACTION` : la cancellazione *non* viene consentita

**ON UPDATE** : 
+ `{sql}CASCADE` : Il nuovo valore dell'attributo della tabella esterna viene riportato su tutte le corrispondenti righe della tabella interna
+ `{sql}SET NULL` : all'attributo referente viene assegnato il valore `{sql}NULL` al posto del valore modificato nella tabella esterna
+ `{sql}SET DEFAULT` : all'attributo referente viene assegnato il valore di `{sql}DEFAULT` al posto del valore modificato nella tabella esterna ( se non esiste il `{sql}DEFAULT` assegniamo il valore di `{sql}DEFAULT` del tipo della colonna )
+ `{sql}NO ACTION` : la modifica *non* viene consentita

##### Modifica Tabelle

Ciò che viene creato con una `{sql}CREATE` può essere *modificato* con il comando `{sql}ALTER` e *eliminato* con il comando `{sql}DROP` 

###### Aggiungere nuovi attributi
```sql
ALTER TABLE Studenti
	ADD COLUMN Nazionalità VARCHAR(10) DEFAULT 'Italiana'
```

###### Eliminare attributi
```sql
ALTER TABLE Studenti
	DROP COLUMN Provincia
```

###### Modificare il tipo di una colonna 
```sql
ALTER TABLE Studenti
	ALTER COLUMN Nazionalità TYPE VARCHAR(15) 
```

###### Aggiungere ed eliminare voncoli
```sql
ALTER TABLE Docenti
	ADD UNIQUE(RecapitoTel) -- ora RecapitoTel è UNIQUE
```

```sql
ALTER TABLE Studenti
	ADD CONSTRAINT nome_vincolo [vincolo]
```

##### Eliminare tabelle

Le tabelle possono essere distrutte utilizzando il comando `{sql}DROP TABLE` , con il quale si rimuovono dallo schema la definizione della tabella e i dati al suo interno ( le righe )

Vi sono 2  politiche per fale la `{sql}DROP TABLE` :
+ `{sql}CASCADE` : provoca la rimozione automatica di tutte le righe e di tutte le viste che utilizzano la tabella ( o la vista ) cancellata
+ `{sql}RESTRICT` : non viene rimossa se la tabella possiede delle righe o se è utilizzata in altre viste 

##### Tabelle Inizializzate

Per create tabelle aventi come contenuti elementi di altre viste o tabelle 

```sql
CREATE TABLE Nome [AS] EspressioneSELECT 
```

**Esempio** :

```sql
CREATE TABLE EsamiFino2006 AS (
	SELECT *
	FROM Esami e
	WHERE e.Dara <= '31/12/2006')
```
Crea una tabella `{sql}EsamiFino2006` contente tutte le ennuple di `{sql}Esami` con data minore o uguale `{sql}'31/12/2006'`

##### Viste

Le *viste* vengono create dal seguente comando
```sql
CREATE VIEW Nome [(Attributi)]
		AS EspressioneSELECT
```

I dati delle *viste* non vengono memorizzati fisicamente ( se non in cache per velociazzare l'esecuzione delle query ) ma vengono ricalcolati ad ogni query ( se presente in cache query ricalcolata solo se i dati in input cambiano )

Per ottimizzare il *DBMS* potrebbe decidere di sostiutire una vista all'interno di una query con la query direttamente dalle tabelle

**Utilità** :
+ Per nascondere certe modifiche dell'organizzazione logica dei dati ( *indipendenza logica* )
	Es voglio mantenere `Studenti` sapendo che li abbiamo divisi in `Matricole` e `NonMatricole`
+ Per *proteggere i dati* 
	In modo da dare ad un utente accesso solo ad una determinata vista ( parte limitata dei dati )
+ Per offrire visioni diverse degli stessi dati senza ricorrere a duplicazioni ( es vista con i voti medi senza avere una tabella con i voti medi visto che sono calcolabili )
+ Per rendere più *semplici* o *possibili* certe interrogazioni

**Esempio** :

Interrogazioni impossibili senza viste : 

1. Trovare la media dei voti massimi ottenuti nelle varie province 

>[!danger]
>Non si può fare :
```sql
SELECT AVG(MAX(e.Voto)) -- non si può fare 
FROM Studenti s JOIN Esami e ON s.Matricola = e.Candidato 
GROUP BY s.Provincia
```

Invece possiamo fare :

```sql
CREATE VIEW ProvMax(Provincia, Max) AS 
	SELECT s.Provincia, MAX(e.Voto)
	FROM Studenti s JOIN Esami e ON s.Matricola = e.Candidato 
	GROUP BY s.Provincia;
	
SELECT AVG(Max) FROM ProvMax
```

2. Le provincie dove la media dei voti degli studenti è massima , restituire tali province e la media

```sql
CREATE VIEW ProvMedia (Provincia, Media) 
AS SELECT s.Provincia, AVG(e.Voto) 
   FROM Studenti s JOIN Esami e ON s.Matricola=e.Candidato 
   GROUP BY s.Provincia; 
   
SELECT Provincia, Media 
FROM ProvMedia 
WHERE Media = ( SELECT MAX(Media) 
			   FROM ProvMedia)
```

Equivale a : 

```sql
SELECT s.Provincia, AVG(e.Voto) 
FROM Studenti s JOIN Esami e ON s.Matricola=e.Candidato 
GROUP BY s.Provincia 
HAVING AVG(e.voto) >=ALL (SELECT AVG(e.Voto) 
						  FROM Studenti s JOIN Esami e 
										  ON s.Matricola = e.Candidato 
						  GROUP BY s.Provincia)
```

3. Ritornare il nome di ogni cane che ha entrambi i genitori e i loro genitori della sua stessa razza

Consideriamo avere una tabella costruita nel seguente modo :
`Cani(_Cod_, Nome , Razza* , Padre* , Madre* , AnnoNasc , AnnoMorte , Istruttore* )`

Dove `Cod PK` , `Madre FK(Cani)` , `Padre FK(Cani)` , `Razza FK(Razze)` , `Istruttore FK(Istruttori)`

Visto che dobbiamo legare un cane con i suoi genitori creiamo una vista per rappresentare ciò , inoltre visto che ci interessa solo i cani che hanno i geniroi con la stessa sua razza modelliamo questo nella clausola `{sql}WHERE` della vista :

```sql
CREATE VIEW GenStessaRazza(Figlio, Padre, Madre, Razza) 
AS SELECT c.Cod, p.Cod, m.Cod, c.Razza 
   FROM Cani c JOIN Cani p ON c.Padre = p.Cod -- lega al padre
			   JOIN Cani m ON c.Madre = m.Cod -- lega alla madre
   WHERE m.Razza = p.Razza AND m.Razza = c.Razza; -- solo se sono della stessa razza

SELECT c.Nome 
FROM GenStessaRazza f JOIN GenStessaRazza m ON f.Madre = m.Figlio -- link padre e madre di 1 cane con i loro genitori che anchessi hanno le caratterisitche di stessa razza 
					  JOIN GenStessaRazza p ON f.Padre = p.Figlio 
					  JOIN Cani c ON c.Cod = f.Figlio -- per aver il nome
```

###### Viste Modificabili

Le *viste* si interrogano come le tabelle ma in generale non si possono modificare,

Perchè si possano modificare le *viste* devono valere le seguenti proprietà : 
+ `{sql}SELECT` senza `{sql}DISTINCT` e solo di attributi ( non calcolati nè funzioni di aggregazione )
+ `{sql}FROM` con una sola tabella modificabile
+ `{sql}GROUP BY` e `{sql}HAVING` non devono essere presenti nella definizione
+ Non deve contenere operatori insiemistici

##### WITH

Il construtto `{sql}WITH` fornisce un modo alternativo per specificare sottoquery di query più complesse , questa a differenza di una *vista* è temporanea per quella query sucessiva

**Esempio** :

Le provincie dove la media dei voti degli studenti è massima , restituire tali province e la media

```sql
WITH ProvinceMedia AS ( 
	SELECT s.Provincia, AVG(e.Voto) AS Media 
	FROM Studenti s JOIN Esami e ON s.Matricola=e.Candidato 
	GROUP BY s.Provincia 
	) 
SELECT Provincia, Media 
FROM ProvinceMedia 
WHERE Media = (SELECT MAX(Media) FROM ProvinceMedia)
```

##### Associazioni Simmetriche 

Abbiamo una associazione simmetrica su `Persone` che indica i `Fratelli` :

![[Pasted image 20231212150911.png]]

Questa viene tradotta in schema realzionale nel seguente modo : 

![[Pasted image 20231212150938.png]]

Ci sono 2 moetodi per riempire la tabella `Fratelli` :
1. Inserire anche i duplicati nella tabella 
	**Esempio** :

|id1|id2|
|--|--|
|13|21|
|21|13|

2. Inserise solo una ennupla per ciascuna coppia di fratelli :
	**Esempio** :

|id1|id2|
|--|--|
|13|21|

Entrambe le soluzioni hanno problematiche :

1. Nel caso dell prima soluzione vi è ridodanza all'interno dei dati , per ottenere una tabella senza ripetizioni dobbiamo escludere una delle due coppie 

**Esempio** :
```sql
SELECT p1.* , p2.*
FROM Persone p1 JOIN Fratelli f ON pi.Id = f.Id1
				JOIN Persone p2 ON p2.Id = f.Id2
WHERE f.Id1 < f.Id2 -- necessario per restituire solo una copia dei fratelli 
```

2. Nel secondo caso le query diventano più complicate

**Esempio** : 
```sql
SELECT p.*
FROM Persone p, Fratelli f
WHERE (f.Id1 = 21 AND p.Id = f.Id2) OR
	  (f.Id2 = 21 AND p.Id = f.Id2) -- per rappresentare la possibilità che l'indice si trovi in Id1 e Id2
```

Generalmente si preferisce la seconda versione in quanto non si introducono duplicazioni all'interno dei dati
##### For all senza For all

Modi per scrivere la `{sql}NOT IN` senza la sottoselect

**Esempio** :

Gli studenti che hanno preso solo 30

```sql
SELECT s.* 
FROM Studenti s 
WHERE s.Matricola NOT IN (SELECT e.Candidato 
						  FROM Esami e 
						  WHERE e.Voto <> 30)
```

###### Complemento

Si può scrivere con l'operatore insiemistico `{sql}EXCEPT`

```sql
SELECT s.* 
FROM Studenti s 
	EXCEPT 
SELECT s.* 
FROM Studenti s JOIN Esami e ON s.Matricola=e.Candidato 
WHERE e.Voto <> 30;
```

###### Giunzione Esterna

Si può scrivere attraverso una `{sql}LEFT JOIN` , prendiamo con il `{sql}LEFT` tutti gli studenti che non hanno preso 30 , in questo modo le colonne in cui il voto degli esami è `{sql}NULL` saranno gli studenti che non hanno mai preso un voto differente da 30

```sql
SELECT s.* 
FROM Studenti s LEFT JOIN Esami e 
	ON s.Matricola = e.Candidato AND e.Voto <> 30 
WHERE e.Voto IS NULL;
```