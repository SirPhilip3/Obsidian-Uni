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
|  |  |  |  |  |

>[!todo]
>#todo
>completa tabella

In questo caso i dati sono ridondati poichè *replichiamo* le informazioni degli utenti se questi hanno più prestiti attivi , inoltre possiamo inserire degli utenti nella base di dati solo se hanno preso in prestito almeno un libro ( *scarsa espressività* )

I problemi di *ridondanza dei dati* potrebbero comportare **Anomalie di Aggiornamento** :

>[!todo]
>#todo

I problemi di *scarsa espressività* potrebbero invece causare **Anomalie di Inserimento e Cancellazione**

>[!todo]
>#todo

## Teoria della Normalizzazione

### Dipendenze Funzionali

### Assiomi di Armstrong
### Implicazione
### Chiusura