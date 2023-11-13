>[!todo]
>traduzione

# Definizioni 

## Tipo di dato

Un *tipo di dato* è un modello matematico che consiste in una collezione di valori sui quali sono ammesse certe operazioni 

Un *tipo di dato* specifica cosa un'operazione deve fare ma *non come* questa venga svolta 
Inoltre non specifica come i dati sono organizzati per rendere le operazioni efficenti o per fare in modo che si occupi minor spazio in memoria

**Esempio** :

Il tipo di dato *pila* ha come operazioni :
+ `top` : restituisce l'elemento in cima alla pila
+ `pop` : toglie il nodo in cima alla pila 
+ `push` : aggiunge un nodo in cima alla pila

## Struttura dati

La *struttura dati* è una particolare organizzazione delle informazioni che permetta di supportare in modo efficente le operazioni su di un *tipo di dato*

Una *struttura dati* specifica quindi *come* organizzare i dati e *come* realizzare le operazioni definite per un tipo di dato in modo che risultino efficenti 

**Esempio** :

Il tipo di dato *pila* viene implementato attraverso la struttura dati *array*

# Classificazione 

Si possono suddividere le *strutture dati* in diverse categoria a seconda dei seguenti criteri :
1. **Disposizione dei dati**
	+ *Lineare*
		I dati sono disposti in sequenze ( è possibile identificare un primo , secondo elemento )
		Es : array , liste , pile , code
	+ *Non Lineare*
		Non è individuata una seguenza nei dati 
		Es : alberi , grafi 
1. **Numero di elementi della struttura**
	+ *Statiche*
		Il numero di elementi della struttura dati è costante nel tempo 
		Es : array 
	+ *Dinamiche*
		Il numero di elementi nella struttura dati può cambiare nel tempo 
		Es : pile , liste , code , alberi
1. **Tipo**
	+ *Omogenee*
		I dati sono tutti dello stesso tipo
	+ *Non Omogenee*
		I dati non sono tutti dello stesso tipo 

# Dizionari

Un *Dizionario* rappresenta il concetto matematico di *relazione univoca* definita da un certo dominio $D$ as un certo codomino $C(R:D \rightarrow C)$ 
Gli elementi appartenenti al dominio prendono il nome di *chiavi* , quelli appartenenti al codominio prendono il nome di *valori*

Avremo quindi che il dizionario può essere espresso come un insieme di associazioni di tipo $(\text{CHIAVE} , \text{VALORE})$

Quindi potremo definire :

**Dati** : Un insieme $S$ di coppie $(\text{CHIAVE} , \text{VALORE})$ 

**Operazioni** : 
+ `{cpp} search(Dizionario S, Chiave k) -> Elem U {NIL}`
	- *Precondizione* : nessuna
	- *Post-condizione* : 


# Alberi 