# Normalizzazione

La teoria della *normalizzazione* ci permette di rispondere in modo rigoroso alle seguenti domande:
+ Quando una rappresentazione è di buona qualità ?
+ Quando due diverse rappresentazioni sono equivalenti ?
## Problemi di una Base di Dati

I principali problemi delle basi di dati sono i seguenti : 
+ *Ridondanza dei dati* 
+ *Scarsa espressività*

**Esempio** : 

| NomeUtente | Telefono | *CodiceLibro* | Titolo | Data |
| ---- | ---- | ---- | ---- | ---- |
| Rossi Carlo | 75444 | XY188A | Decameron | 07-07 |
| Pastine Maurizio | 66133 | XY090C | Canzoniere | 01-08 |
| Paolicchi Laura | 59729 | XY101A | Vita Nova | 05-08 |
| Paolicchi Luca | 59729 | XY701B | Adelchi | 14-01 |
| Paolicchi Luca | 59729 | XY008C | Amleto | 17-08 |

In questo caso i dati sono ridondati poichè *replichiamo* le informazioni degli utenti se questi hanno più prestiti attivi , inoltre possiamo inserire degli utenti nella base di dati solo se hanno preso in prestito almeno un libro ( *scarsa espressività* )

I problemi di *ridondanza dei dati* potrebbero comportare **Anomalie di Aggiornamento** :

Potremmo aggiornare in modo scorretto o parziale dei dati 
**Esempio** :

| NomeUtente | Telefono | *CodiceLibro* | Titolo | Data |
| ---- | ---- | ---- | ---- | ---- |
| Paolicchi Luca | 59729 | XY701B | Adelchi | 14-01 |
| Paolicchi Luca | *64135* | XY008C | Amleto | 17-08 |
I problemi di *scarsa espressività* potrebbero invece causare **Anomalie di Inserimento e Cancellazione** :

Se volessimo inserire un utente anche se non ha preso in prestito nessun libro ? con la rappresentazione corrente non è possibile poichè il *CodiceLibro* essendo *private key* non può essere null

| NomeUtente | Telefono | _CodiceLibro_ | Titolo | Data |
| ---- | ---- | ---- | ---- | ---- |
| Paolicchi Luca | 59729 | ??? | ??? | ??? |

Se volessimo cancellare una persona ma non il libro ? dovremmo inserire dei valori nulli ( non ideale )

| NomeUtente | Telefono | _CodiceLibro_ | Titolo | Data |
| ---- | ---- | ---- | ---- | ---- |
| null | null | XY701B | Adelchi | null |

Per risolvere le precedenti **Anomalie** dobbiamo sciegliere una modellazione alternativa : utilizziamo 2 tabelle , una contente gli utenti e una i libri con *foreing key* NomeUtente

| *NomeUtente* | Telefono |
| ---- | ---- |
| Rossi Carlo | 75444 |
| Pastine Maurizio | 66133 |
| Paolicchi Laura | 59729 |
| Paolicchi Luca | 59729 |

| *CodiceLibro* | Titolo | Data | NomeUtente (FK) |
| ---- | ---- | ---- | ---- |
| XY188A | Decameron | 07-07 | Rossi Carlo |
| XY090C | Canzoniere | 01-08 | Pastine Maurizio |
| XY101A | Vita Nova | 05-08 | Paolicchi Laura |
| XY701B | Adelchi | 14-01 | Paolicchi Luca |
| XY008C | Amleto | 17-08 | Paolicchi Luca |

Se invece utilizziamo come *foreing key* Telefono lo schema non sarebbe equivalente allo schema di partenza poichè più persone potrebbero avere lo stesso numero di telefono
## Teoria della Normalizzazione

La teoria della normalizzazione fornisce un insieme di strumenti e algoritmi per stabilire in modo rigoroso la bontà di uno schema relazionale e per migliorare ( normalizzare ) schemi relazionali esistenti 

*Intuizione* dei concetti : 
+ **Dipendenze Funzionali**
+ **Assiomi di Armstrong**
+ **Implicazione**
+ **Chiusura**

### Dipendenze Funzionali

### Assiomi di Armstrong
### Implicazione
### Chiusura