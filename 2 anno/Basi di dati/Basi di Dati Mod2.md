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

1. $X \rightarrow Y$  per ipotesi
2. $X \rightarrow YX$  per arricchimento su 1 ( aggiungo $X$ ) ( $XX$ da $X$ , l'unione degli stessi insiemi da l'insieme stesso )  
3. $X \rightarrow Z$  per ipotesi
4. $XY \rightarrow YZ$  per arrichimento su 3 ( aggiungo $Y$ )
5. $X \rightarrow YZ$  per transitività da 2 a 4

Rappresentazione ad albero :

![[UnioneBD2.excalidraw]]
###### Decomposizione
Se $X \rightarrow YZ$ allora $X \rightarrow Y$ e $X \rightarrow Z$

**Dimostrazione** : 
>[!todo]
###### Indebolimento
Se $X \rightarrow Y$ allora $XZ \rightarrow Y$

**Dimostrazione** : 
>[!todo]
### Implicazione

#### Chiusura

>[!important] Definition
>Dato un insieme $F$ di dipendenze funzioneli la *chiusura* di $F$ ( $F^+$ ) è definita come l'insieme di tutte le dipendenze funzionali logicalmente implicate da $F$ attraverso gli assiomi di *Armstrong*  
$$F^+=\{ X \rightarrow Y | F\vdash X \rightarrow Y \}$$

In pratica : l'insieme di tutte le dipendenze funzionali derivabili da $F$ 

**Problema dell'implicazione** : 

Il problema dell'implicazione corrisponde a decidere , dati $F$ e $X \rightarrow Y$ se $X \rightarrow Y\in F^+$ ( ossia se una determinata dipendenza funzionale appartiene a $F^x$ ) oppure no  
Calcolare $F^+$ applicando gli *assiomi di Armstrong* risulta avere una complessità **esponenziale** ( questo poichè se abbiamo $a$ attributi allora avremo almeno $2^a-1$ possibili dipendenze funzionali ) rispetto al numero di attributi . Calcolare $F^+$ risulta quindi essere un modo algoritmicamente *inefficente* per risolvere il problema dell'implicazione 

Una soluzione per ridurre la complessità è controllare che $Y\subseteq X^+$ , per dimostrare la veridicità di questo algoritmo dobbiamo definire $X^+$

>[!important] Chiusura di X
> Sia $R(T, F)$ uno schema relazionale. Dato $X \subseteq T$ la *chiusura* di $X$ rispetto ad $F$ è definita come l'insieme $X_F^+ = \{ A\in T | F \vdash X \rightarrow A \}$ 

Ossia $X^+_F$ è l'insieme degli attributi di $X+F$ che sono dipendenti da $X$ applicando le dipendenze di $F$ 

Da questo possiamo ricavare il seguente teorema : 
>[!Important] Theorem
>$F\vdash X \rightarrow Y$ se e solo se $Y \subseteq X_F^+$ 

Pertanto per decidere se $X \rightarrow Y\in F^+$ si può controllare se $Y \subseteq X_F^+$ 
Che può essere svolto in tempo polinomiale 
#### Calcolo di $X_F^+$
```pseudo
	\begin{algorithm}
	\caption{Algo Caption}
	\begin{algorithmic}
	\Function{CLOSURE}{X,F}
	\State $X_{old}^+ \leftarrow 0$
	\State $X_{new}^+ \leftarrow X$
	\While{$X_{new}^+\neq X_{old}^+$}
		\State $X_{old}^+ \leftarrow X_{new}^+$
		\Forall{$Y \rightarrow Z \in F$}
			\If{$Y \subseteq X_{new}^+$}
				\State $X_{new}^+ \leftarrow X_{new}^+ \cup Z$
            \EndIf
		\EndFor
    \EndWhile
    \Return $X_{new}^+$
    \EndFunction
    \end{algorithmic}
	\end{algorithm}
```

**Esempio** :  
Abbiamo $X=AB$ e $F=\{ A \rightarrow C, AC \rightarrow D , E \rightarrow F \}$

1. $X_0^+=AB$
2. $X_1^+=AB \cup C = ABC$ ( poichè un sottoinseme di $AB$ ( $A$ ) è presente nella prima dipendenza , dobbiamo aggiungere a $X^+$ $C$  )
3. $X_2^+=ABC \cup A = ABCD$ ( poichè un sottoinseme di $ABC$ ( $AC$ ) è presente nella seconda dipendenza , dobbiamo aggiungere a $X^+$ $D$ )
4. Da qui in poi non è più possibile aggiungere altri attributo , l'algoritmo termina

**Complessità**

Siano $a$ il numero totale di attributi di $T$ e $d$ il numero di dipendenze funzionali $F$ allora : 
+ Il *while* esterno viene eseguito al più $a$ volte
+ Il *for* interno viene eseguito al più $d$ volte
+ Per verificare se $Y\subseteq X_{new}^+$ ha costo $O(a)$

Il costo totale dell'algoritmo sarà quindi : $O(a^2 d)$

### Chiavi e Attributi primi

>[!important] Definizione Superchiave
>Dato uno schema relazionale $R(T,F)$ , un insieme di attributi $X\subset T$ è una **superchiave** di $R$ se e solo se $X \rightarrow T \in F^+$

Ossia : $X$ ( un sottoinsieme degli attributi $T$ ) è una **superchiave** se da essi possiamo ricavare tutti i restanti attributi 

>[!important] Definizione Chiave
>Una *chiave* è un superchiave minimale ossia una superchiave tale per cui nessun suo sottoinsieme sia una superchiave 

>[!important] Definizione Attributi Primi
>Un attributo è *primo* se e solo se appartiene ad *almeno* una chiave

#### Verifica di Superchiave

Per determinare se un sottoinseme degli attributi di $R(T,F)$ è una *superchiave* possiamo utilizzare il seguente algoritmo ( dal costo polinomiale ) :
1. Calcolo la *chiusura* $X_F^+$
2. Verifico se $X_F^+=T$

>[!example]
>Consideriamo lo schema relazionale $R(T, G)$ con $T=ABCDEF$ e $G=\{ AB \rightarrow C , E \rightarrow A, A \rightarrow E, B \rightarrow F\}$
>Verifichiamo che $ABD$ è superchiave : 
>1. $ABD_0^+=ABD$ 
>2. $ABD_1^+=ABCD$ ( poichè $AB \rightarrow C$ )
>3. $ABD_2^+=ABCDE$ ( poichè $A \rightarrow E$ )
>4. $ABD_3^+=ABCDEF$ ( poichè $B \rightarrow F$ )

#### Verifica di Chiave

Per determinare se un sottoinsieme degli attributi di $R(T,F)$ è una *chiave* possiamo utilizzare il seguente algoritmo ( dal costo polinomiale )
1. Verifica se $X$ è una *superchiave* , se non lo è allora non è nemmeno una *chiave*
2. Verifica che per ogni $A\in X$ si abbia che la *copertura* di $X$ meno $A$ non sia $T$
>[!example]
>Consideriamo lo schema relazionale $R(T,F)$ con $T=ABCDEF$ e $G=\{ AB \rightarrow C , E \rightarrow A, A \rightarrow E, B \rightarrow F\}$ 
>Verifichiamo che $ABD$ sia una chiave tenendo presente che abbiamo dimostrato che è una *superchiave* :
>1. Proviamo a rimuovere $A$ : 
>	$BD_G^+ = BDF$ , non essendo $T$ non è un chiave
>2. Proviamo a rimuovere $B$ : 
>	$AD_G^+=ADE$ , non essendo $T$ non è un chiave
>3. Proviamo a rimuovere $D$ : 
>	$AB_G^+=ABCEF$ , non essendo $T$ non è un chiave
>Possiamo quindi concludere che $ABD$ è una *chiave*

#### Trovare una Chiave

Dato $R(T,F)$ è possibile trovare una sua chiave in tempo *polinomiale* , possiamo infatti partire da $T$ e togliere uno ad uno gli attributi finchè non troviamo gli attributi indispensabili per derivare $T$ ( quando la *copertura* è $T$ )

**Algoritmo** : 

```pseudo
	\begin{algorithm}
	\caption{FindKey}
	\begin{algorithmic}
	\Function{FindKey}{R(T,F)}
    \State $K \gets T$
	\ForAll{$A\in T$}
		\If{$(K-\{ A \})_F^+=T$}
			\State $K \gets K-\{ A \}$
        \EndIf
    \EndFor
    \Return $K$
    \EndFunction
	\end{algorithmic}
	\end{algorithm}
```

>[!example]
>Dato $G=\{ AB \rightarrow C , E \rightarrow A, A \rightarrow E, B \rightarrow F\}$ costruiamo una chiave 
>1. Partiamo da $K_0=ABCDEF$
>2. Rimouviamo $A$ da $K_0$ : $BCDEF_G^+=ABCDEF$ poichè siamo tornati a $T$ dobbiamo rimuovere $A$ , $K_1=BCDEF$ 
>3. Rimouviamo $B$ da $K_1$ : $CDEF_G^+=ACDEF$ dobbiamo quindi mantenere $B$
>4. Rimuoviamo $C$ da $K_1$ : $BDEF_G^+=ABCDEF$ quindi $C$ deve essere rimosso , aggiorniamo $K_2=BDEF$
>5. Rimuoviamo $D$ da $K_2$ : $BEF_G^+=ABCEF$ quindi dobbiamo mantenere $D$
>6. Rimuoviamo $E$ da $K_2$ : $BDF_G^+=BDF$ quindi dobbiamo mantenere $E$
>7. Rimuoviamo $F$ da $K_2$ : $BDE_G^+=ABCDEF$ quindi $F$ deve essere rimosso , aggiorniamo $K_3=BDE$
>La *chiave* è quindi $BDE$ , questa però non è l'unica chiave , infatti la *chiave* che troviamo dipende dall'ordine con il quale togliamo gli attributi

#### Trovare tutte le Chiavi 

Trovare tutte le *chiavi* ha complessità *esponenziale* poichè ogni sottoinsieme di $T$ è potenzialmente una chiave
Esiste un algoritmo ottimizzato per la ricerca di tutte le chiavi : 

>[!important] Intuizione
>+ Generiamo le possibili chiavi dalle più piccole alle più grandi
>+ Rappresentiamo i candidati da testare nella forma $X::(Y)$ dove $X$ è l'insieme degli attributi da testare come *chiave* e $Y$ l'insieme dei possibili attributi da aggiungere a $X$ qualora $X_F^+\neq T$
>+ Se $X_F^+ = T$ allora $X$ è una chiave e possiamo scartare $X::(Y)$
>+ Altrimenti calcoliamo $Y-X_F^+=\{ A_1,\dots, A_n \}$ e generiamo i nuovi candidati : $XA_1::(A_2,\dots,A_n), \quad XA_2::(A_3,\dots,A_n),\dots,XA_n::()$

>[!warning]
>Se un attributo non compare mai alla destra di una dipendenza funzionale allora esso deve fare parte di tutte le chiavi
>L'insieme di questi attributi saranno i primi testati

```pseudo
	\begin{algorithm}
	\caption{FindAllKeys}
	\begin{algorithmic}
	\Function{FindAllKeys}{R(T,F)}
	\State $Z=\{ B\in T | \forall X \rightarrow Y \in F : B \notin Y  \}$
	\State $Cand=[Z::(T-Z)]$
	\State $Keys=[]$
	\While{$Cand\neq []$}
		\State $X::(Y)=Head(Cand)$
		\State $Cand=Tail(Cand)$
		\If{$\nexists K \in Keys : K \subset X $}
			\If{$X_F^+=T$}
				\State $Keys=Keys+X$
			\Else
				\State $A_1,\dots,A_n=Y-X_F^+$
				\For{$i \in 1,\dots,n$}
					\State $Cand = Cand + XA_i::(A_{i+1},\dots,A_n)$
                \EndFor
			\EndIf
        \EndIf
    \EndWhile
    \EndFunction
	\end{algorithmic}
	\end{algorithm}
```

>[!example]
>Sia $G=\{ AB \rightarrow C , E \rightarrow A, A \rightarrow E, B \rightarrow F\}$ :
>1. 
>	+ $Cand=[BD::(ACEF)]$
>	+ $Keys=[]$
>	+ $X::(Y)=BD::(ACEF)$ 
>	+ $X_G^+ = BD^+_G=BDF$ quindi $BD$ non è una chiave
>	+ $Y-X_G^+ = ACE$
>2. 
>	+ $Cand=[BDA::(CE), BDC::(E), BDE::()]$
>	+ $Keys=[]$
>	+ $X::(Y)=BDA::(CE)$
>	+ $X_G^+=BDA^+_G=ABCDEF$ quindi $BDA$ è una chiave
>3. 
>	+ $Cand=[BDC::(E), BDE::()]$
>	+ $Keys=[BDA]$
>	+ $X::(Y)=BDC::(E)$
>	+ $X_G^+=BDC^+_G=BDCF$ quindi $BDC$ non è una chiave
>	+ $Y-X_G^+=E$
>4. 
>	+ $Cand=[BDE::(), BDCE::()]$
>	+ $Keys=[BDA]$
>	+ $X::(Y)=BDE::()$
>	+ $X_G^+=BDE_G^+=BDEACF$ quindi $BDE$ è una chiave
>5.
>	+ $Cand=[BDCE::()]$
>	+ $Keys=[BDA,BDE]$
>	+ $X::(Y)=BDCE::()$
>	+ $X$ contiene già la chiave $BDE$ quindi non viene considerato
>
>Poichè $Cand$ ora è vuoto l'algoritmo termina 

>[!todo]
>#todo
#### Varifica di Primalità

#### Forma Canonica

##### Copertura Canonica



