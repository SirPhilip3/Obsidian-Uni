# Concetti di Base

## Terminologia

+ **Popolazione** :
	Tutte le unità statistiche di interesse ( es : persone ... )
+ **Parametro** :
	Una caratteristica numerica della popolazione di interesse : $\theta$
+ **Censimento** :
	Osservazione di *tutte* le unità della popolazione per valutare $\theta$
+ **Campione** :
	Sottoinsieme della popolazione utilizzato per stimare $\theta$ quando il censimento non è opportuno ( troppo costoso etcc )
+ **Statistica** : 
	Una qualsiasi funzione dei dati cesuari o campionari
+ **Stimatore** :
	Una particolare funzione statistica $\hat\theta$ ( theta cappello ) utilizzata per ricostruire $\theta$ ( si inferisce dal particolare al generale )
+ **Stima** :
	Valore dello *stimatore* corrispondente al particolare campione osservato

Il *campione* ha di per s'è un *errore* rispetto al *parametro* 
### Errori

Vi sono due diverse tipologie di errore :
+ **Errori campionari** : sono inevitabili
+ **Errori non campionari** : sono evitabili
#### Errori campionari

Sono dovuti al fatto che osserviamo solo un campione dei dati
Questi diminuiscono al crescere della dimensione campionaria se lo *stimatore* $\hat\theta$ è ragionevole ( se stima correttamente il parametro )

>[!example]
#### Errori non campionari

Dovuti ad una scorretta costruzione del campione o all'utilizzo di uno stimatore non approriato
Possono non diminuire al crescere della dimensione campionaria

>[!example]

### Campionamento Casuale

Per evitare gli errori non campionari il metodo più efficace è estrarre le unità del campione *casualmente* dalla popolazione

Questo ci permette di evitare l'introduzione di *distorsioni* dovute ad aspetti della popolazione che non conosciamo ( il nostro obbiettivo è evitare di avere un campione rappresentativo solo di un sottoinsieme della popolazione )

Esistono diversi *disegni di campionamento* ( schemi ) per estrarre casualmente le unità del campione 

#### Campionamento causale semplice

Le unità sono estratte dalla popolazione con la seguenti caratteristiche : 
+ Le unità sono indipendenti l'una dall'altra
+ Le unità hanno tutte la stessa probabilità di essere selezionate :
	Avendo $N$ unità ognuna di queste ha probabilità di essere selezionata : $\frac 1 n$ *indipendentemente* dalle altre 

>[!note]
>Le osservazioni ottenute con il campionamento casuale semplice sono variabili casuali *indipendenti e identicamente distribuite* o *i.i.d.*

>[!note]
>Esistono altre forme di campionamenti più complessi , si dicono *stratificati*
>Utilizzato dove il richio di un campione squilibrato darebbe risultati più difficilmente interpretabili

### Statistiche campionarie

Consideriamo un campione casuale di dimensione $n$ : $(X_1,\dots,X_n)$ i valori assunti dalle variabili sono indicati con $(x_1,\dots,x_n)$  

>[!example]
>campione casuale dei tempi di elaborazione ( CPU ) di 30 processi ( jobs ) in secondi :
>![[Pasted image 20240217155129.png]]

L'obbiettivo è utilizzare i dati campionari per ricostruire alcuni parametri della popolazione

Statistiche che misurano la posizione : 
+ *media* campionaria
+ *mediana* campionaria
+ *quantili* , *percentili* , *quartili*
Statistiche che misurano la variabilità : 
+ *varianza* campionaria e *deviazione standard*
+ *scarto interquartile*

Le statisiche sono *variabili casuale* quando calcolate su un campione *casuale* di dati 

Quando applico una statistica ad una variabile casuale sarà essa stessa una variabile casuale ( rappresenta la strategia che utiliziamo prima di guardare i dati ) , se la applico sui dati avremo di ritorno un valore 
#### Media campionaria

Supponiamo che le osservazioni $X_i$ siano variabili *i.i.d.* con valore atteso $E[X]=\mu$ e varianza $Var[X]=\sigma^2$ 

La media campionaria sarà allora : 
$$\hat X=\frac 1 n \sum_{i=1}^n X_i$$
$\hat X$ è uno stimatore della media di popolazione $\mu=E[X]$

Per l'esempio precedente la media campionatoria sarà : $\hat x=48.23$ 

La notazione che useremo sarà : 
+ $\hat X$ è la variabile casuale media campionaria ( è uno *stimatore* di $\mu$ )
+ $\hat x$ è il particolare valore osservato della media campionaria nel campione ( è una *stima* di $\mu$ ) 

Sia la stima che lo stimatore è rappresentato dal simbolo $\hat\theta$ , siccome $\hat\theta$ ( stima ) è calcolata su un campione della popolazione difficilmente sarà uguale al valore di popolazione $\theta$ 

Se il campione è ben costruito allora al crescere di $n$ lo stimatore $\hat\theta$ convergerà a $\theta$ 
##### Distorsione



##### Consistenza




>[!todo]
>fino a slide 25