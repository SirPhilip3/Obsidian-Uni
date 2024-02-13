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
+ **Dipendenze Funzionali** :
	Stabiliscono le dipendenze tra gli attributi della relazione 
	Esempio : l'attributo *Titolo* dipende da *CodiceLibro* , ossia ogni volta che *CodiceLibro* è uguale lo è anche *Titolo* ( ogni volta che troviamo un *CodiceLibro* necessariamente dobbiamo avere quel *Titolo* )
+ **Assiomi di Armstrong** :
	Regole per derivare altre dipendenze funzionali
+ **Implicazione** :
	Per verificare se una certa dipendenza funzionale può essere derivata in una relazione
+ **Chiusura** : 
	Rappresenta l'insieme di tutti gli attributi derivsbile da un insieme di uno o più attributi ( come le chiavi ) secondo le regole di derivazione

>[!todo]
>#todo
### Dipendenze Funzionali

>[!note] Definizione
>Sia $R(T)$ uno schema di relazione e siano $X$ e $Y$ due insiemi di attributi non vuoti tali che $X\cup Y \subseteq T$ una *dipendenza funzionale* è un qualsiasi vincolo della forma $X\rightarrow Y$  ( $X$ determina $Y$ )

>[!note] Soddisfazione
>Un'istanza $r$ di $R(T)$ soddisfa la *dipendenza funzionale* $X\rightarrow Y$ se e solo se ogni coppia di ennuple in $r$ che coincide su $X$ ( ha gli stessi valori su $X$ ) coincide anche su $Y$
>$$\forall t_1, t_2 \in r : t_1[X]=t_2[X]\implies t_1[Y]=t_2[Y]$$

Indichiamo con $R(T,F)$ uno schema relazionale $R(T)$ con le dipendenze funzionali $F$ che tutte le sue istanze ( dello schema relazionale ) valide devono soddisfare 
( In pratica $R(T,F)$ indica uno schema relazionale $R(T)$ all'interno del quale sono definite delle dipendenze funzionali $F$ che devono essere soddisfatte per tutte le istanze ( schemi relazionali completi di dati ) dello schema relazionale )

**Esempio** :
>[!todo]
#### Dipendenze Derivate

>[!note] Definizione ( *Implicazione Logica* )
>Sia $R(T,F)$  uno schema relazionale . Diciamo che $F$ *implica logicamente* la dipendenza funzionale $X\rightarrow Y$ , $F \models X\rightarrow Y$ se e solo se **ogni** istanza valida di $R(T,F)$ soddisfa anche $X\rightarrow Y$ 

>[!example]
>Sia $F=\{ CodiceLibro \rightarrow Titolo , CodiceLibro \rightarrow NomeUtente \}$ avremo che :
>+ $F \models CodiceLibro \rightarrow Titolo,NomeUtente$
>+ $F \models CodiceLibro \rightarrow CodiceLibro$ 

Sia $RI$ un insieme di regole di *inferenza* ( regole di deduzione ) per $F$ , indichiamo con $F\vdash X \rightarrow Y$ il fatto che $X \rightarrow Y$ *sia derivabile da* $F$ utilizzando $RI$  ( in pratica è come se dicessimo $X \rightarrow Y \ \text{è derivabile da}\ F$ )

>[!todo]
>clarify

L'insieme di regole $RI$ possono essere *corrette* ( $F\vdash X \rightarrow Y\implies F\models X \rightarrow Y$ ) o *complete* ( $F\models X \rightarrow Y\implies F\vdash X \rightarrow Y$ )
### Assiomi di Armstrong

Gli *assiomi di Armstrong* sono un insieme di regole di inferenza della forma $F\vdash X \rightarrow Y$

+ **Riflessività** ( *REFL* ) :
	Se $Y\subseteq X$ allora $X \rightarrow Y$
+ **Arricchimento** ( *AUGM* ) :
	Se $X \rightarrow Y$ e $W \subseteq T$ allora $XW \rightarrow YW$ 
+ **Transitività** ( *TRANS* ) :
	Se $X \rightarrow Y$ e $Y \rightarrow Z$ allora $X \rightarrow Z$

Gli *assiomi di Armstrong* sono dimostrati essere *corretti* e *completi* ( $\vdash$ vale $\models$ ossia la deduzione logica implica la validità logica )
#### Derivazioni

>[!note] Definizione di $F\vdash X \rightarrow Y$
>Una derivazione di $X \rightarrow Y$ da $F$ una sequenza finita di *dipendenze funzionali* ( $f_1,\dots,f_n$ ) tale per cui l'ultima ( $f_n$ ) risulti essere $X \rightarrow Y$ , ogni passo è un elemento di $F$
>Oppure può essere ottenuta da $f_1,\dots,f_{i-1}$ usando una regola di inferenza

>[!warning]
>Risulta utile rappresentare una *derivazione* come albero rovesciato la cui radice è $X \rightarrow Y$ e ogni nodo è giustificato dall'insieme di dipendenze funzionali $F$  o da una regola di inferenza

##### Regole Derivative

###### Unione

Se $X \rightarrow Y$ e $X \rightarrow Z$ allora $X \rightarrow YZ$ 

**Dimostrazione** :



###### Decomposizione

Se $X \rightarrow YZ$ allora $X \rightarrow Y$ e $X \rightarrow Z$

###### Indebolimento

### Implicazione
### Chiusura