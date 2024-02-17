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
+ Le unità hanno tutte la stessa probabilità di essere selezionate

>[!todo]
>fino a slide 25