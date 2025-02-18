---
publish: true
---
# Normalizzazione

La teoria della *normalizzazione* ci permette di rispondere in modo rigoroso alle seguenti domande:
+ Quando una rappresentazione è di buona qualità ?
+ Quando due diverse rappresentazioni sono *equivalenti* ?
## Problemi di una Base di Dati

I principali problemi delle basi di dati sono i seguenti : 
+ *Ridondanza dei dati* 
+ *Scarsa espressività*

**Esempio** : 

| NomeUtente       | Telefono | *CodiceLibro* | Titolo     | Data  |
| ---------------- | -------- | ------------- | ---------- | ----- |
| Rossi Carlo      | 75444    | XY188A        | Decameron  | 07-07 |
| Pastine Maurizio | 66133    | XY090C        | Canzoniere | 01-08 |
| Paolicchi Laura  | 59729    | XY101A        | Vita Nova  | 05-08 |
| Paolicchi Luca   | 59729    | XY701B        | Adelchi    | 14-01 |
| Paolicchi Luca   | 59729    | XY008C        | Amleto     | 17-08 |

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

| NomeUtente      | Telefono  | _CodiceLibro_ | Titolo  | Data      |
| --------------- | --------- | ------------- | ------- | --------- |
| ~~Rossi Carlo~~ | ~~75444~~ | XY701B        | Adelchi | ~~07 07~~ |

Per risolvere le precedenti **Anomalie** dobbiamo sciegliere una modellazione alternativa : utilizziamo 2 tabelle , una contente gli utenti e una i libri con *foreing key* NomeUtente

| *NomeUtente*     | Telefono |
| ---------------- | -------- |
| Rossi Carlo      | 75444    |
| Pastine Maurizio | 66133    |
| Paolicchi Laura  | 59729    |
| Paolicchi Luca   | 59729    |

| *CodiceLibro* | Titolo | Data | NomeUtente (FK) |
| ---- | ---- | ---- | ---- |
| XY188A | Decameron | 07-07 | Rossi Carlo |
| XY090C | Canzoniere | 01-08 | Pastine Maurizio |
| XY101A | Vita Nova | 05-08 | Paolicchi Laura |
| XY701B | Adelchi | 14-01 | Paolicchi Luca |
| XY008C | Amleto | 17-08 | Paolicchi Luca |

>[!danger] 
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
	Rappresenta l'insieme di tutti gli attributi derivabile da un insieme di uno o più attributi ( come le chiavi ) secondo le regole di derivazione

### Notazione

+ Con prime lettere maiuscole dell'alfabeto ( $A , B , C , \dots$ ) per indicare attributi di una tabella ( eg NomeUtente etcc )
+ Con ultime lettere maiuscole dell'alfabeto per indicare un insieme di attributi ( $T,X,Y,\dots$ )
+ $R(T)$ schema costituito dagli attributi $T$ ( $T = \{A,B,C\}$ )
+ $r$ particolare insieme di dati contenuti nella relazione 
+ $t,u,v, \dots$  particolari righe di una relazione
+ $t[\{A,B,C\}]$ -> i valori della righa $t$ 
+ $A \rightarrow BC$ , B e C dipendono da A ( Titolo e Data dipendono dal CodiceLibro ) 
### Dipendenze Funzionali

>[!note] Definizione
>Sia $R(T)$ uno schema di relazione e siano $X$ e $Y$ due insiemi di attributi non vuoti tali che $X\cup Y \subseteq T$ una *dipendenza funzionale* è un qualsiasi vincolo della forma $X\rightarrow Y$  ( $X$ determina $Y$ )

>[!note] Soddisfazione
>Un'istanza $r$ di $R(T)$ soddisfa la *dipendenza funzionale* $X\rightarrow Y$ se e solo se ogni coppia di ennuple in $r$ che coincide su $X$ ( ha gli stessi valori su $X$ ) coincide anche su $Y$
>$$\forall t_1, t_2 \in r : t_1[X]=t_2[X]\implies t_1[Y]=t_2[Y]$$

Indichiamo con $R(T,F)$ uno schema relazionale $R(T)$ con le dipendenze funzionali $F$ che tutte le sue istanze ( dello schema relazionale ) valide devono soddisfare 
( In pratica $R(T,F)$ indica uno schema relazionale $R(T)$ all'interno del quale sono definite delle dipendenze funzionali $F$ che devono essere soddisfatte per tutte le istanze ( schemi relazionali completi di dati ) dello schema relazionale )

>[!example] 
>Se abbiamo la dipendenza $CodiceLibro \rightarrow Titolo, NomeUtente, Data$ 
>Due righe con stesso CodiceLibro devono avere stesso Titolo, NomeUtente e Data
>>[!note] 
>>Possono essereci duplicati all'interno del DB

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
>Dato un insieme $F$ di dipendenze funzionali la *chiusura* di $F$ ( $F^+$ ) è definita come l'insieme di tutte le dipendenze funzionali logicalmente implicate da $F$ attraverso gli assiomi di *Armstrong*  
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

Siano $a$ il numero totale di attributi di $T$ e $d$ il numero di dipendenze funzionali $F$ allora: 
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
#### Varifica di Primalità

Dato $R(T,F)$ , il problema di verificare se un attributo $A\in T$ è *primo* ha complessità *esponenziale* :
+ Si può dimostrare che il problema è *NP-completo* 
+ Ciò implica che non esistono soluzioni significativamente più efficenti dell'approccio ovvio di generare tutte le possibili chiavi
#### Forma Canonica

Vogliamo portare l'insieme delle *dipendenze funzionali* ad una forma più standard , detta *forma canonica* equivalente all'originale 

>[!important] Definizione Equivalenza
>Due insiemi di *dipendenze funzionali* $F$ e $G$ sono *equivalenti* ( indicato con $F \equiv G$ ) se e solo se $F^+=G^+$ 

>[!note]
>Se $F=G$ allora $F\equiv G$ ma in generale non vale il contrario

>[!important] Definizione Attributo Estraneo
>Sia $X\rightarrow Y \in F$ . L'attributo $A\in X$ è *estraneo* se e solo se $(X-{A})\rightarrow Y \in F^+$
>
>>[!note] 
>>Ossia ci basta che nella chiusura risultante sia presente l'attributo estraneo


Ossia se rimuoviamo questi attributi estranei la dipendenza fa ancora parte della chiusura ( ossia non contribuiscono nel determinare univocamente la dipendenza )

>[!important] Definizione Dipendenza Ridondante
>La dipendenza $X\rightarrow Y \in F$ è *ridondante* se e solo se $X \rightarrow Y\in (F-\{ X \rightarrow Y \})^+$  

In parole povere una dipendenza è ridondante se questa può essere dedotta da altre dipendenze  

>[!important] Definizione Forma Canonica
>$F$ è in *forma canonica* se e solo se per ogni $X \rightarrow Y \in F$ avremo :
>+ $|X|=1$
>+ $X$ non contiene *attributi* *estranei*
>+ $X \rightarrow Y$ non è *ridondante*
##### Copertura Canonica

>[!important] Definizione Copertura Canonica
>$G$ è una *copertura canonica* di $F$ se e solo se $F\equiv G$ e $G$ è in forma canonica

>[!note] Teorema
>Per ogni insieme di dipendenze $F$ esiste una copertura canonica , uno stesso insieme di dipendenze può avere più coperture canoniche
>

Utilizziamo il seguente algoritmo per ricavare una *copertura canonica* : 
+ Decompone tutte le *dipendenze funzionali* che hanno più attributi a destra :
	$X\rightarrow Y \implies \{ X\rightarrow A | A \in Y \}$
+ Toglie dalla parte sinistra delle dipendenze gli attributi che non contribuiscono alla dipendenza ( attributi estranei ) :
	$X\rightarrow A \implies X -Z|A \in (X-Z)_F^+$
+ Toglie le *dipendenze funzionali* non essenziali per derivare la dipendenza stessa ( toglie le dipendenze *ridondanti* ) :
	$X\rightarrow A \implies F^{new} = F-\{ X\rightarrow A \} | A\in X_{F-\{ X\rightarrow A \} }^+$

```pseudo
	\begin{algorithm}
	\caption{Canonize}
	\begin{algorithmic}
	\Function{Canonize}{F}
	\State $G \leftarrow \{X\rightarrow A | \exists Y : X\rightarrow Y \in F \land A \in Y\}$
	\Forall{$X \rightarrow A \in G\ \text{such that}\ |X|>1 $}
		\State $Z \leftarrow X$
		\Forall{$B \in X$}
			\If{$A\in ( Z - \{B \} )^+_G$}
				\State $Z \leftarrow Z - \{B \}$
            \EndIf
        \State $G \leftarrow ( G -\{ X \rightarrow A \} )\cup \{ Z \rightarrow A \}$
        \EndFor
    \Forall{$X \rightarrow A \in G$}
	    \If{$A\in X_{G-\{ X \rightarrow A \}^+}$}
		    \State $G \leftarrow G - \{ X \rightarrow A \}$
        \EndIf
    \EndFor
    \EndFor
    \Return G
    \EndFunction
	\end{algorithmic}
	\end{algorithm}
```

>[!example]
>Sia $F=\{A\rightarrow BC , B\rightarrow C , A\rightarrow B , AB\rightarrow C  \}$
>1. *Decomponiamo* $A\rightarrow BC$ in $A\rightarrow B$ e $A\rightarrow C$ , dato che $A\rightarrow B$ è già presente otteniamo $G=\{A\rightarrow C , B\rightarrow C , A\rightarrow B , AB\rightarrow C  \}$
>2. L'unica dipendenza che può contenere attributi estranei è $AB\rightarrow C$ 
>	Proviamo a togliere $A$ :
>	Calcoliamo la *chisura* del rimanente : $B_G^+=BC$ , visto che $C$ è presente all'interno della *chiusura* possiamo togliere l'attributo $A$ ( era la stessa cosa se toglievamo prima $B$ )
>	Dato che $B\rightarrow C$ era già presente in $G$ otteniamo : $H=\{A\rightarrow C,B\rightarrow C,A\rightarrow B\}$
>3. Verifichiamo che l'unica dipendenza è ridondante ( è possibile vedere che la possiamo ricavare per transitività tra $A\rightarrow B$ e $B\rightarrow C$ ) possiamo verificarlo dato che : 
>	$C\in A_{H-\{A\rightarrow C\}}^+=ABC$ ( ossia abbiamo calcolato la copertura di $A$ utilizzando $\{A\rightarrow B,B\rightarrow C\}$ ossia $H-\{A\rightarrow C\}$ e verificato che la chiusura contiene la parte sinistra )
>Concludendo possiamo dire che una *copertura canonica* di $F$ è l'insieme $\{ B\rightarrow C ,A\rightarrow B \}$

### Decomposizione di schemi

La strategia migliore per eliminare le *anomalie* è quella di decomporre lo schema di partenza in schemi più piccoli che godono di particolari proprietà ( *frome normali* ) e che sono equivalenti allo schema originale 

>[!important] Definizione di *Decomposizione* 
>Dato uno schema $R(T)$ , $p=\{ R_1(T_1),\dots ,R_n(T_n) \}$ è una *decomposizione* di $R$ se e solo se $\cup_i T_i =T$

>[!important] Definizione di *Proiezione*
>Dati uno schema $R(T,F)$ e $Z\subseteq T$ la *proiezione* di $F$ su $Z$ è definita come l'insieme $\pi_Z(F)=\{ X \to Y \in F^+ | X \cup Y \subseteq Z \}$

La proiezione $\pi_Z F$ è definita come l'insieme di tutte le dipendenze funzionali $X \to Y$ in $F^+$ tali che l'unione di $X$ e $Y$ sia contenuta in $Z$. In altre parole, stiamo considerando solo le dipendenze funzionali che coinvolgono attributi interamente contenuti in $Z$.

In pratica abbiamo che un insieme di schemi è una decomposizione dello schema originale solo se l'unione degli attributi dei sotto schemi equivalgono agli attributi dello schema iniziale

>[!example]
>

| Proprietario | Abitazione | Telefono |
| ---- | ---- | ---- |
| p1 | a1 | t1 |
| p1 | a2 | t2 |
| p1 | a3 | t2 |
Viene diviso in : 

| Proprietario | Telefono |
| ---- | ---- |
| p1 | t1 |
| p1 | t2 |

| Proprietario | Abitazione |
| ---- | ---- |
| p1 | a1 |
| p1 | a2 |
| p1 | a3 |

>[!note]
>Vederemo però che non è una decomposizione equivalente alla tabella originale poichè dalla `JOIN` delle due tabelle decomposte arriveremo ad un numero di righe differenti dall'originale

Per fare in modo che la *decomposizione* sia equivalente allo schema originario dobbiamo soddisfare le seguenti due proprietà : 
+ *preservi i dati* 
+ *preservi le dipendenze*
#### Dipendenze che preservano i dati

>[!note]
>Per *preservano* non intendiamo se si perdono dei dati da una decomposizione ma se i dati non presentano duplicati ( ossia se facendo la `JOIN` abbiamo le stesse righe dell'originale )

L'esempio di prima è una *decomposizione* che non preserva i dati possiamo infatti osservare che se faccessimo la `JOIN` delle due tabelle della *decomposizione* avremo : 

| Proprietario | Abitazione | Telefono |
| ---- | ---- | ---- |
| p1 | t1 | c1 |
| p1 | t1 | c2 |
| p1 | t2 | c1 |
| p1 | t2 | c2 |
| p1 | t3 | c1 |
| p1 | t3 | c2 |
Che evidentemente non corrisponde alla tabella iniziale 

>[!important] Definizione di *Decomposizione che preserva i dati*
>$p=\{ R_1(T_1),\dots ,R_n(T_n) \}$ è una *decomposizione* di $R(T,F)$ che *preserva i dati* se e solo se per ogni relazione $r$ che soddisfa $R(T,F)$ : 
>$$r=\pi_{T_1}(r)\bowtie\dots\bowtie \pi_{T_k}(r)$$

In pratica una decomposizione preserva i dati se e solo se per ogni righa della relazione iniziale questa è equivalente alla `JOIN` delle linee corrispondenti nella decomposizione 

Da questa definizione possiamo anche ricavare un teorema per la *decomposizione* : 
>[!important] Teorema *Decomposizione*
>Se $p=\{ R_1(T_1),\dots ,R_n(T_n) \}$ è una *decomposizione* di $R(T,F)$ ( qualunque ) allora per ogni istanza $r$ di $R(T,F)$ si ha : 
>$$r\subseteq \pi_{T_1}(r)\bowtie\dots\bowtie \pi_{T_k}(r)$$

Una perdita di informazione è quindi definita come : proiettando una relazione sui sottoschemi e poi facendo la giunzione si ottengono più ennuple di quante ce ne fossero nella relazione originaria

>[!important] Teorema
>Sia $p=\{R_1(T_1),R_2(T_2)\}$ una decomposizione di $R(T,F)$ . $p$ è una decomposizione che *preserva i dati* se e solo se $T_1\cap T_2 \rightarrow T_1 \in F^+$ oppure $T_1\cap T_2 \rightarrow T_2 \in F^+$ 

>[!important] *Dimostrazione*
>Dobbiamo dimostrarlo per entrambi i versi del se e solo se : 
>+ $\impliedby$
>	Supponiamo che $T_1 \cap T_2 \to T_1 \in F^+$
>	Sia $r$ un'istanza valida di $R(T,F)$ e $s=\pi_{T_1}(r)\bowtie \pi_{T_2}(r)$ , sia $t\in s$ bisogna dimostrare che $t\in r$ 
>	Per come è stata definita $s$ esistono due ennuple $u$ e $v$ in $r$ tali che $u[T_1]=t[T_1]$ e $v[T_2]=t[T_2]$
>	Avremo quindi : $u[T_1 \cap T_2]=v[T_1 \cap T_2]=t[T_1 \cap T_2]$ 
>	Poichè $T_1 \cup T_2 \to T_1 \in F^+$ da $u[T_1 \cap T_2]=v[T_1 \cap T_2]$ otteniamo $u[T_1]=v[T_1]$ quindi $t=v\in r$
>+ $\implies$ $\dots$

>[!example]
>Si consideri $R(A,B,C,D)$ con $F=\{ A \to BC \}$
>La decomposizione $\{R_1(A,B,C),R_2(A,D)\}$ preserva i dati : 
>+ $T_1=\{A,B,C\}$ e $T_2=\{A,D\}$
>+ $T_1 \cap T_2 = \{A\}$
>+ $A^+_F=\{A,B,C\}=T_1$ quindi $T_1 \cap T_2 \to T_1 \in F^+$

L'esempio precedente possiamo anche visualizzarlo nel seguente modo 

Prima della decomposizione : 

| A | B | C | D |
| ---- | ---- | ---- | ---- |
| a1 | b1 | c1 | d1 |
| a1 | b1 | c1 | d2 |
| a2 | b2 | c2 | d2 |

Dopo la decomposizione : 

| A | B | C |
| ---- | ---- | ---- |
| a1 | b1 | c1 |
| a2 | b2 | c2 |

| A | D |
| ---- | ---- |
| a1 | d1 |
| a1 | d2 |
| a2 | d2 |
Se facessimo la `JOIN` vedremo che ritorneremo alla tabella originale 

>[!example] Contro-Esempio
>Si consideri $R(A,B,C,D)$ con $F=\{ A \to B , C \to D \}$
>La decomposizione $\{R_1(A,B),R_2(C,D)\}$ non preserva i dati : 
>+ $T_1=\{A,B\}$ e $T_2=\{C,D\}$
>+ $T_1 \cap T_2 = \emptyset$
>+ abbiamo quindi $\{ T_1 \cap T_2 \to T_1 , T_1 \cap T_2 \to T_2 \} \cap F^+ = \emptyset$

L'esempio precedente possiamo anche visualizzarlo nel seguente modo 

| A | B | C | D |
| ---- | ---- | ---- | ---- |
| a1 | b1 | c1 | d1 |
| a2 | b2 | c2 | d2 |

Dopo la decomposizione : 

| A | B |
| ---- | ---- |
| a1 | b1 |
| a2 | b2 |

| C | D |
| ---- | ---- |
| c1 | d1 |
| c2 | d2 |
La `JOIN` qui ritorna l'insieme vuoto poichè non ho elementi in comune
#### Decomposizioni che preservano le dipendenze

Una disposizione che *preserva le dipendenze* siginifica che l'unione delle dipendenze dei sottoschemi è equivalente alle dipendenze dello schema originario 

>[!example] 
>Decomposizione con Perdita di Dipendenze

Prima della decomposizione

| Proprietario | Telefono | Macchina |
| ---- | ---- | ---- |
| Mario Rossi | 423567 | CG153SE |
| Mario Rossi | 423567 | PT267MV |
| Mario Rossi | 542635 | PT267MV |
Dopo la decomposizione

| Proprietario | Telefono |
| ---- | ---- |
| Mario Rossi | 423567 |
| Mario Rossi | 542635 |

| Telefono | Macchina |
| ---- | ---- |
| 423567 | CG153SE |
| 423567 | PT267MV |
| 542635 | PT267MV |
Se volessi aggiungere $(Luca Bianchi, 421448, CG153SE)$
+ nel primo caso violerei la dipendenza $Macchina\to Proprietario$
+ nel secondo caso non ce ne possiamo accorgere se non dopo la giunzione

---
Una decomposizione *preserva le dipendenze* se e solo se l'unione delle dipendenze indotte sui singoli schemi equivale alle dipendenze dello schema originale

>[!important] Definizione di *Decomposizione che Preserva le Dipendenze*
>la decomposizione $p=\{R_1(T_1),\dots,R_n(T_n)\}$ di $R(T,F)$ *preserva le dipendenze* se e solo se $\bigcup_i\pi_{T_i}(F)\equiv F$

Questo può essere verificato algoritmicamente nel seguente modo : 
+ Calcoliamo le proiezioni $\pi_{T_i}(F) = \{ X \to Y \in F^+ | X \cup Y \subseteq T_i \}$
+ Verifichiamo se $\bigcup_i\pi_{T_i}(F)\equiv F$
##### Verificare l'Equivalenza

>[!important] Teorema
>$F\equiv G$ se e solo se $F \subseteq G^+$ e $G \subseteq F^+$

>[!Dimostrazione]
>Essendo un se e solo se dobbiamo dimostrare entrambi i versi dell'equivaleza
>+ Sia $F\equiv G$ allora $F^+ =G^+$ per definizione di equivalenza . Dato che si ha $F\subseteq F^+$ e $G \subseteq G^+$ , ottengo $F\subseteq G^+$ e $G\subseteq F^+$ ( ho sostituito grazie a $F^+ =G^+$ ( def di equivalenza ) )
>+ Poichè $F\subseteq G^+$ , osservo che $F^+\subseteq (G^+)^+ = G^+$ . Analogamente avremo anche : $G \subseteq F^+$ ottengo $G^+ \subseteq (F^+)^+ = F^+$ concludiamo quindi che $F^+=G^+$ 

**Algoritmo Esponenziale**

Sia $G=\bigcup_i \pi_{T_i}(F)$ per dimostrare che $F\equiv G$ dobbiamo verificare : 
+ $F\subseteq G^+$ è possibile verificare tramite il problema dell'*implicazione* perchè equivale a verificare che per ogni $X\to Y \in F$ abbiamo $Y \subseteq X^+_G$  
+ $G\subseteq F^+$ è verificato per definizione 

Per completare l'algoritmo necessitiamo di calcolare $G=\bigcup_i \pi_{T_i}(F)$ in modo efficente , questo non è possibile poichè abbiamo che il costo per calcolare le singole proiezioni $\pi_{T_i}(F)$ ha costo *esponenziale* 
```pseudo
	\begin{algorithm}
	\caption{Proiezione}
	\begin{algorithmic}
	\Function{PROIEZIONE}{F,$T_i$}
	\State $proj \leftarrow \emptyset$
	\ForAll{$X\subset T_i$}
		\State $(Y \leftarrow X_F^+)-X$
		\State $proj \leftarrow proj \cup \{ X \to T \cap T_i \}$
	\EndFor
	\Return $proj$
    \EndFunction	
	\end{algorithmic}
	\end{algorithm}
```

L'agoritmo completo risulta quindi essere : 
1. Calcola le proiezioni $\pi_{T_i}(F)$ per ogni $i\in[1,n]$
2. Calcola $G=\bigcup_i \pi_{T_i}(F)$
3. Verifica che per ogni $X\to Y\in F$ si abbia $Y \subseteq X_G^+$
 
>[!example]
>Siano $R(A,B,C)$ e $F=\{ A\to B , B \to C , C \to A \}$
>Vogliamo verificare se la decomposizione $p=\{R_1(A,B),R_2(B,C)\}$ preserva le dipendenze
>Calcoliamo $\pi_{AB}(F)$ consideriamo i due sottoinsiemi propri $A$ , $B$
>+ $A_F^+ = ABC$ , quindi $A\to B \in \pi_{AB}(F)$
>+ $B_F^+ = BCA$ , quindi $B\to A \in \pi_{AB}(F)$
>Concludiamo quindi che $\pi_{AB}(F)=\{ A\to B , B \to A \}$
>
>Calcoliamo ora $\pi_{BC}(F)$ consideriamo i due sottoinsiemi propri $B$ , $C$
>+ $B_F^+ = BCA$ , quindi $B\to C \in \pi_{BC}(F)$
>+ $C_F^+ = CAB$ , quindi $C\to B \in \pi_{BC}(F)$
>Concludiamo quindi che $\pi_{BC}(F)=\{ B\to C , C \to B \}$
>
>Possiamo quindi calcolare $G=\pi_{AB}(F)\cup\pi_{BC}(F)=\{A\to B , B \to A, B\to C , C \to B \}$
>
>Iteriamo sulle dipendenze di $F=\{ A\to B, B\to C, C\to A \}$ e verichiamo che siano tutte derivabili da $G$ : 
>+ $A \to B$ : abbiamo $B \in A_G^+ = ABC$
>+ $B \to C$ : abbiamo $C \in B_G^+ = BAC$
>+ $C \to A$ : abbiamo $A \in C_G^+ = CBA$
>
>Concludiamo quindi che la decomposizione in esame preserva le dipendenze 

**Algoritmo Polinomiale**

Non ci interressa calcolare $G=\bigcup_i \pi_{T_i}(F)$ ma ci basta verificare che per ogni $X \to Y \in F$ abbiamo $Y \subseteq X_G^+$  

```pseudo
	\begin{algorithm}
	\caption{}
	\begin{algorithmic}
	\Function{FC}{X,F,p}
	\State $res_{old}\leftarrow \emptyset$
	\State $res_{new}\leftarrow X$
	\While{$res_{new}\neq res_{old}$}
		\State $res_{old}\leftarrow res_{new}$
		\ForAll{$R_i(T_i)\in p$}
			\State $res_{old}\leftarrow res_{new} \cup ((res_{new}\cap T_i)_F^+ \cap T)$
        \EndFor
    \EndWhile
    \Return $res_{new}$
    \EndFunction
	\end{algorithmic}
	\end{algorithm}
```

```pseudo
	\begin{algorithm}
	\caption{Preserve Dependency}
	\begin{algorithmic}
	\Function{PreserveDeps}{R(T,F),p}
	\ForAll{$X \to Y \in F$}
	\If{$Y \nsubseteq FC(X,F,p)$}
	\Return False
	\EndIf
    \EndFor
    \Return True
    \EndFunction
	\end{algorithmic}
	\end{algorithm}
```
Questo *algoritmo* ottimizzato ha complessità *polinomiale*

>[!example]
>$F=\{ A\to B, B \to C , C \to A \}$ e $p=\{ R_1(A,B) , R_2(B,C) \}$
>Verifichiamo che preserviamo le dipendenze 
>1. Partiamo dalla dipendenza $A \to B$
>	+ Inizialmente avremo $FC(A,F,p)=\{A\}$ 
>	+ Consideraimo $R_1(\{ A,B \})$ , abbiamo : 
>		$(\{A\}\cap\{A,B\})_F^+ \ \cap\{A,B\}=A^+_F \cap \{A,B\} = \{A,B\}$
>		Aggiungiamo quindi $B$ a $FC(A,F,p)$ 
>	+ Consideraimo $R_2(\{ B,C \})$ , abbiamo :
>		$(\{A,B\}\cap\{B,C\})_F^+ \ \cap\{B,C\}=B^+_F \cap \{B,C\} = \{B,C\}$
>		Aggiungiamo quindi $C$ a $FC(A,F,p)$

>[!todo]
>Capisci esempio

### Forme normali

L'obbiettivo delle *forme normali* è garantire che uno schema sia di buona qualità ( questo può essere ottenuto attraverso un processo chiamato *normalizzazione* basato su una decomposizione dello schema di partenza ) 

Caratteristiche fondamentali ad uno schema in *forma normale* :
+ Non deve contenere anomalie
+ Il processo di normalizzazione deve *preservare i dati*
+ Il processo di normalizzazione deve *preservare le dipendenze*

>[!note]
>In generale non possiamo garantire tutte e tre le proprietà

#### Forma Normale di Boyce-Codd ( BCNF )

Un tipo di *forma normale* è quella così detta *BCNF*

>[!important] Definizione di *BCNF*
>Uno schema è in *BCNF* se e solo se per ogni dipendenza funzionale non banale $X \to Y \in F^+$ tale che $Y \nsubseteq X$ si ha che $X$ è una *superchiave*

>[!example] 
>Verifichiamo se $Prodotti(\{ Articolo, Magazzino ,Quantità , Indirizzo \})$ , $F=\{  Articolo\  Magazzino \to Quantità , Magazzino \to Indirizzo\}$ è *BCNF*
>
>Dato che $\{Magazzino\}_F^+ = \{Magazzino,Indirizzo\}$ , il quale insieme non è superchiave abbiamo che lo schema *non* è *BCNF*

##### Dipendenze Anomale

Una dipendenza che *viola* *BCNF* è detta **Anomala** 

>[!example]
>
| Articolo | Magazzino | Quantità | Indirizzo       |
| -------- | --------- | -------- | --------------- |
| Flauto   | Roma      | 10       | Via Cavour, 7   |
| Oboe     | Roma      | 5        | Via Cavour, 7   |
| Arpa     | Torino    | 1        | Via Mazzini, 11 |
>
>Come possiamo notare lo schema *mescola* informazioni relative ai magazzini con altre *indipendenti* relative agli articoli 
>Inoltre lo schema è scarsamente espressivo poichè se un magazzino non ha alcun articolo all'interno allora questo è come se non esistesse

Per risolvere le anomalie si trasformano questi schemi in schemi "normali" ( *BCNF* , *3NF* , etc... )
##### Conversione in BCNF

L'algoritmo di conversione in *BCNF* è anche detto algoritmo di *analisi* poichè decompone lo schema originale fino a normalizzazione

Sia $R(T,F)$ lo schema di partenza : 
1. Se $R(T,F)$ è già *BCNF* ritorna $R(T,F)$
2. Seleziona $X\to Y\in F$ che *viola* *BCNF* . Calcola gli insiemi di attributi $T_1 = X_F^+$ e $T_2=X \cup (T-T_1)$
3. Calcola le *proiezioni* $F_1=\pi_{T_1}(F)$ e $F_2=\pi_{T_2}(F)$ 
4. Decomponi ricorsivamente $R_1(T_1,F_1)$ e $R_2(T_2,F_2)$ in $p_1$ e $p_2$
5. Ritorna l'unione $p_1 \cup p_2$

>[!example]
>Si consideri $Telefoni(\{ Prefisso  , Numero , Località \}, F)$ con $F=\{ Prefisso , Numero \to Località , Località \to Prefisso \}$
>
>La dipendenza $Località \to Prefisso$ viola *BCNF* dato che :
>$$\{Località\}_F^+ = \{ Località ,Prefisso \}$$
>Applicando l'algoritmo di conversione in *BCNF* abbiamo : 
>+ $R_1(\{ Località , Prefisso \}, F_1)$ 
>+ $R_2(\{ Località , Numero \}, F_2)$ 
>con $F_1$ e $F_2$ da calcolare per proiezione 
>
>Calcoliamo $F_1$ su $R_1$ : 
>+ $\{ Località \}_F^+=\{Località ,Prefisso\}$ da cui $Località \to Prefisso \in F_1$
>+ $\{ Prefisso \}_F^+ = \{ Prefisso \}$ da cui nessuna nuova dipendenza
>
>Calcoliamo $F_2$ su $R_2$ : 
>+ $\{ Località \}_F^+=\{Località ,Prefisso\}$ da cui nessuna nuova dipendenza
>+ $\{ Prefisso \}_F^+ = \{ Prefisso \}$ da cui nessuna nuova dipendenza
>
>Abbiamo quindi $F_1 = \{Località \to Prefisso\}$ e $F_2 = \emptyset$
>
>Abbiamo quindi decomposto in : 
>+ $R_1(\{ Località , Prefisso \}, \{ Località \to Prefisso \})$
>+ $R_2(\{ Località , Numero \}, \emptyset)$
>>[!warning]
>>Entrambi gli schemi sono in *BCNF* ma è andata perduta la dipendenza funzionale $Prefisso , Numero \to  Località$

##### Correttezza della conversione in *BCNF*

L'algoritmo di conversione in *BCNF* termina quando non ci sono più dipendenze anomale. 
Per garantire che questo avvenga dimostriamo che tutti gli schemi con *solo due attributi* sono in *BCNF* 

Consideriamo $R(\{ A,B \} , F)$ e sia $X\to Y \in F$ , dimostriamo che in nessun caso si viola la *BCNF* : 
1. Se $X=\{A\}$ ho 2 casi : 
	1. Se $B \notin Y$ allora $Y \subseteq X$ e la dipendenza è banale
	2. Se $B \in Y$ allora $X$ è una superchiave
2. Se $X=\{B\}$ il caso è simmetrico al precedente
3. Se $X=\{A,B\}$ allora $Y \subseteq X$ e la dipendenza è banale 
 
##### La conversione in *BCNF* preserva i dati

>[!todo]
>Scrivi dimostrazione
>#todo

##### Proprietà di *BCNF*

| Pregi                                                       | Difetti                                                                                                                                                                                                                                             |
| ----------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| *BCNF* garantisce l'assenza di anomalie                     | L'algoritmo di conversione in *BCNF* ha costo *esponenziale* perchè richiede di calcolare le proiezioni delle dipendenze ( alcuni algoritmi lo fanno con costo polinomiale ma non vengono usati perchè producono schemi eccessivamente decomposti ) |
| L'algoritmo di conversione in *BCNF* preserva i dati        | L'algoritmo di conversione in *BCNF* non preserva le dipendenze nel caso generale                                                                                                                                                                   |
| Verifichiamo se uno schema è in *BCNF* ha costo polinomiale | ---                                                                                                                                                                                                                                                 |
#### Terza Forma Normale ( 3NF )

>[!important] Definizione *3NF*
>Uno schema d relazione $R(T,F)$ è in *3NF* se e solo se per ogni dipendenza funzionale $X \to Y \in F^+$ tale che $Y \nsubseteq X$ si ha che $X$ è una superchiave oppure tutti gli attributi di $Y-X$ sono primi

Possiamo dimostrare che la definizione precedente è valida anche con $F$ invece di $F^+$

La verifica se uno schema è *3NF* ha comunque costo *esponenziale* poichè per il calcolo degli attributi primi richiediamo di trovare tutte le chiavi

>[!note]
>Per definizione ogni schema in *BCNF* è anche in *3NF* ma non viceversa

>[!example]
>Si consideri $Telefoni(\{ Prefisso  , Numero , Località \}, F)$ con $F=\{ Prefisso , Numero \to Località , Località \to Prefisso \}$
>
>Calcoliamo le chiavi osservando che $Numero$ deve fare parte di tutte le chiavi , poichè non è mai a destra 
>Quindi : 
>+ $\{Numero\}_F^+$ = $Numero$
>+ $\{Numero,Prefisso\}_F^+ = \{ Numero,Prefisso,Località \}$
>+ $\{Numero,Località\}_F^+ = \{ Numero,Loaclità,Prefisso \}$ 
>
>Visto che $\{Numero , Prefisso\}$ e $\{Numero , Località\}$ sono chiavi si ha che ogni attributo è primo e quindi siamo in *3NF* 
##### Conversione in *3NF*

Sia $R(T,F)$ lo schema di partenza : 
1. Costruisci $G$ una *copertura canonica* di $F$
2. Sostituisci in $G$ ciascun insieme di dipendenze $X \to A_1,\dots,X\to A_n$ con una singola dipendenza $X\to A_1\dots A_n$
3. Per ogni $X \to Y \in G$ crea uno schema $S_i(XY)$
4. Elimina ogni schema contenuto in un'altro schema
5. Se la decomposizione non contiene alcuno schema i cui attributi costituiscano una superchiave per $R$ aggiungi un nuovo schema $S(W)$ dove $W$ è una chiave di $R$

>[!example]
>Sia $R(\{ A,B,C,D \}, \{ AB \to C ,C \to D , D \to B  \})$
>L'insieme delle dipendenze è già in forma canonica . Otteniamo quindi : 
>+ $R_1(\{ A,B,C \})$ tramite $AB \to C$
>+ $R_2(\{ C,D \})$ tramite $C \to D$
>+ $R_3(\{ B,D \})$ tramite $D \to B$
>
>Nessuno schema è contenuto in altro quindi non dobiamo eliminarne alcuno
>Poichè $\{ A,B,C \}$ è una superchiave per $R$ non è necessario aggiungere altri schemi

##### Proprietà *3NF*

**Preservazione delle Dipendenze**  :
	E' facile dimostrare che la conversione in *3NF* preserva le dipendenze : poichè per ogni $X\to Y \in G$ viene creato uno schema $S_i(XY)$ abbiamo $X\to Y \in \pi_{XY}(G)$ quindi $G$ è contenuto nell'unione delle proiezioni 

**Preservazione dei Dati** : 
	L'ultimo passo della conversione garantisce che la decomposizione contenga almeno uno schema i cui attributi formano una superchiave dello schema iniziale 
	Poichè la decomposizione preserva le dipendenze essa deve preservare anche i dati 

La conversione in *3NF* non garantisce l'assenza di anomalie

>[!example]
>Consideriamo $Telefoni(\{ Prefisso , Numero , Località \} , F)$ con $F=\{ Prefisso,Numero \to Località, Località \to Prefisso \}$
>Notiamo che il $Prefisso$ di replica : 
>
| Prefisso | Numero | Località |
| -------- | ------ | -------- |
| 041      | 422865 | Venezia  |
| 041      | 463212 | Venezia  |
| 049      | 513227 | Padova   |

### Conversione di schemi di scarsa qualità

Abbiamo 2 principali strategie per migliorare uno schema di scarsa qualità : 
1. Convertiamo lo schema in *BCNF* per eliminare le anomalie , se notiamo che la conversione non ha preservato le dipendenze ci accontentiamo di una conversione in *3NF*
2. Convertiamo lo schema in *3NF* in modo da preservare dati e dipendenze sperando di essere fortunati e rimuovere tutte le anomalie . Questo si verifica se la conversione produce un *BCNF*

>[!note]
>Una anomalia che non viene prevenuta da *BCNF* si può verificare quando siamo in presenza di attributi multivalore indipendenti
>>[!example]
>>
| Corso        | LibroDiTesto        | Docente   |
| ------------ | ------------------- | --------- |
| Basi di Dati | Fondamenti di BD    | Calzavara |
| Basi di Dati | Web App Development | Calzavara |
| Basi di Dati | Database System     | Calzavara |
| Basi di Dati | Fondamenti di BD    | Raffaetà  |
| Basi di Dati | Web App Development | Raffaetà  |
| Basi di Dati | Database System     | Raffaetà  |
>>
>>Ha forte ridondanza : se ci sono $m$ docenti e $n$ libri di testo si memorizzano $m\times n$ righe
>>Possiamo fare di meglio memorizzando $m+n$ righe 
>>
| Corso        | LibroDiTesto        |
| ------------ | ------------------- |
| Basi di Dati | Fondamenti di BD    |
| Basi di Dati | Web App Development |
| Basi di Dati | Database System     |
>>
| Corso        | Docente   |
| ------------ | --------- |
| Basi di Dati | Calzavara |
| Basi di Dati | Raffaetà  |
>> 
>> La teoria della normalizzazione è stata generalizzata per rimuovere anche questo tipo di anomalie attraverso la *quarta forma normale* o *4NF*

### Vincoli di Integrità

Alcuni *vincoli di integrità* : 
+ Garantire che certi attributi abbiano un valore ( `{sql}NOT NULL` ) 
+ Garantire che un certo insieme di attributi sia un chiave ( `{sql} PRIMARY KEY` , `{sql}UNIQUE` )
+ Garantire l'integrità referenziale ( `{sql}FOREING KEY` )
+ Gatantire alcuni vincoli sui valori degli attributi 
>[!example]
>+ Garantire che l'età di una persona sia sempre un numero positivo
>+ Garantire che il primario di un ospedale sia anche un dottore 
#### NOT NULL

Un certo attributo non deve essere mai impostato a `{sql}NULL`

>[!example]
```sql
CREATE TABLE Movies (
	title  CHAR(100) NOT NULL,
	year   INT,
	length INT,
	genre  CHAR(10)
)
```
#### UNIQUE

Data una tabella $R(T)$ ed un insieme di attributi $X \subseteq T$ possiamo specificare che nessuna coppia di tuple in $R(T)$ coincida su tutti gli attributi in $X$ a meno che almeno uno di essi non sia `NULL`

>[!example]
```sql
CREATE TABLE Movies (
	title  CHAR(100) NOT NULL,
	year   INT,
	length INT,
	genre  CHAR(10),
	UNIQUE (title, year)
)
```
#### PRIMARY KEY

Il vincolo `{sql}PRIMARY KEY` si comporta come `{sql}UNIQUE` ma impone in aggiunta il vincolo di `{sql}NOT NULL` per tutti gli attributi specificati

>[!example]
```sql
CREATE TABLE Movies (
	title  CHAR(100) NOT NULL,
	year   INT,
	length INT,
	genre  CHAR(10),
	PRIMARY KEY (title, year)
)
```
#### FOREIGN KEY

Dati una tabella $R(T)$ e $X \subseteq T$ possiamo specificare un vincolo di *integrità referenziale* secondo cui $X$ è una *chiave esterna* di $R(T)$ : 
+ Il vincolo deve riferire una tabella $S(U)$ ed un insieme di attributi $Y\subseteq U$ dichiarati *PRIMARY KEY* o *UNIQUE*
+ Per ogn *tupla* $t\in R(T)$ tale che tutti gli attributi in $X$ sono diversi da `{sql}NULL` deve esistere una tupla $t'\in S(U)$ tale che $t[X] = t'[Y]$ 

>[!note]
>Implicitamente si chiede che $|X| = |Y|$ 

Indichiamo che un attributo è *chiave esterna* : 
```sql
Attribute REFERENCES <table> (<attribute>)
```
oppure
```sql
FOREING KEY (<attributes>) REFERENCES <table> (<attributes>)
```

>[!example]
```sql
CREATE TABLE MovieExec (
	name CHAR(50), 
	address VARCHAR(255), 
	code INT PRIMARY KEY, 
	netWorth INT 
)
```
```sql
CREATE TABLE Studio ( 
	name CHAR(30) PRIMARY KEY, 
	address VARCHAR(255), 
	president INT, 
	FOREIGN KEY (president) REFERENCES MovieExec(code) 
)
```
>[!note]
>Le seguenti operazioni su `Studio` sono impedite : 
>+ Inserimento di una tupla con attributo `president` non `NULL` e non coincide con l'attributo `code` di una tupla in `MovieExec`
>+ Aggiornamento di una tupla per cambiare l'attributo `president` ad un valore non `NULL` che non coincide con l'attributo `code` di una tupla di `MovieExec` 
>
>Altre operazioni pericolose su `MovieExec`
> + Cancellazione di una tupla il cui attributo `code` coincide con l'attributo `president` di qualche tupla in `Studio`
> + Aggiornamento di una tupla per cambiare il suo attributo `code` in modo tale che non coincida più con l'attributo `president` di qualche tupla di `Studio`

##### Politiche di Integrità Referenziale

*SQL* mette a disposizione tre politche per gestire i due casi descritti : 

1. *Default* : rifiuta la modifica
2. *CASCADE* : applica la stessa modifica ( *DELETE* o *UPDATE* ) sulle tuple che fanno uso della chiave esterna
3. *SET NULL* : imposta la chiave esterna a *NULL* sulle tuple che fanno uso della stessa

Possiamo specificare una politica diversa per *DELETE* e *UPDATE* , utilizzando la sintassi *ON DELETE* oppure *ON UPDATE* seguito da *CASCADE* oppure *SET NULL*

>[!example]
```sql
CREATE TABLE Studio (
	name CHAR(30) PRIMARY KEY,
	address VARCHAR(255),
	president INT,
	FOREING KEY ( president )
	REFERENCES MovieExec(code)
		ON DELETE SET NULL
		ON UPDATE CASCADE
)
```
#### CHECK

E' possibile specificare vincoli complessi sul valore di un attributo, usando la sintassi *CHECK* seguita da un'espressione booleana fra parentesi : 
+ Si può usare qualsiasi espressione ammessa da *WHERE*
>[!warning] 
>Nello standard SQL si possono riferire altre relazioni tramite sotto-query , questo non è supportato nei DBMS commerciali ( Postgres )
+ Il vincolo viene controllato ogni volta che una tupla assume un nuovo valore per quell'attributo ( in pratica quando avviene un `{sql}INSERT` o `{sql}UPDATE` )

>[!note]
>Non necessariamente significa che il vincolo venga sempre rispettato 
##### CHECK su Attributi

>[!example]
>
```sql
CREATE TABLE MovieExec ( 
	name CHAR(50), 
	address VARCHAR(255), 
	code INT PRIMARY KEY CHECK ( code >= 100000), 
	netWorth INT CHECK (netWorth >= 0) 
)
```

>[!example]
```sql
CREATE TABLE Studio(
	name CHAR(30) PRIMARY KEY, 
	address VARCHAR(255), 
	president INT, FOREIGN KEY (president) REFERENCES MovieExec(code)	
)
```
```sql
CREATE TABLE Studio ( 
	name CHAR(30) PRIMARY KEY, 
	address VARCHAR(255), 
	president INT CHECK (president in (SELECT code FROM MovieExec)) )
```

Nel secondo esempio il `{sql}CHECK` offre meno garanzie rispetto alla `{sql}FOREING KEY` poichè se modificassimo `code` questo non verrebbe rilevato nel `CHECK` poichè con la modifica non tocchiamo mai la tabella `Studio` , non viene quindi garantita l'*integrità referenziale*

##### CHECK su Tuple

Il `CHECK` ci permette di specificare un vincolo sull'intera tupla 

>[!note]
>I `CHECK` su attributi sono più efficenti rispetto a quello su tuple

>[!example]
```sql
CREATE TABLE MovieExec ( 
	name CHAR(50), 
	address VARCHAR(255), 
	code INT PRIMARY KEY, 
	netWorth INT, 
	CHECK (code >= 100000 AND netWorth >= 0) 
)
```

##### CHECK su Tuple o Attributi ? 

+ Se un vincolo coinvolge più di un attributo e non è una congiunzione di vincoli su attributi indipendenti è *necessario* ricorrere a `CHECK` su tuple per motivi di espressività 
+ Se un vincolo coincolge un solo attributo possiamo scegliere fra i due tipi di `CHECK` ma generalmente i `CHECK` su attributi sono *più efficenti* dei `CHECK` su tuple dato che vengono controllati meno frequentemente

>[!todo]
>#todo
>Equivalenze logiche
#### Aggiornare i Vincoli

Possiamo dare un nome ai vincoli anteponendo alla loro dichiarazione `{sql}CONSTRAINT namo_costraint [FOREING KEY , UNIQUE , CHECK . etc...]`

>[!example]
```sql
CREATE TABLE nome_tabella ( 
	colonna1 TIPO_DATO CONSTRAINT nome_vincolo CHECK (condizione), 
	colonna2 TIPO_DATO, 
	... 
	CONSTRAINT nome_vincolo_primario PRIMARY KEY (colonna_primaria),
	CONSTRAINT nome_vincolo_esterno FOREIGN KEY (colonna_esterna) REFERENCES altra_tabella(colonna_corrispondente) );
```

Possiamo *cancellare* un vincolo esistente a partire dal suo nome : 
```sql
ALTER TABLE nome_tabella DROP CONSTRAINT nome_vincolo
```

Possiamo *inserire* un nuovo vincolo nel seguente modo : 
```sql
ALTER TABLE nome_tabella ADD [CONSTRAINT nome_vincolo] definizione_vincolo
```

>[!warning]
>Il vincolo che viene aggiunto deve già valere al momento del suo inserimento

>[!note]
>La *modifica* di un vincolo non è supportata ma può essere effettuata tramite una cancellazione seguita da un inserimento

>[!todo]
>#todo
>Add examples

#### Limitazione dei Vincoli

##### 1

Consideriamo questi schemi dove `president` è chiave esterna per `code` : 
```
MovieExec(name, address, code, netWorth) 
Studio(name, address, president)
```

Il vincolo : 
	Nessuno può essere il presidente di uno studio senza avere reddito di almeno 100000
Non può essere esprimibile via `CHECK` a meno che il DBMS non supporta vincoli con sotto-query

Soluzione con sotto-query 
```sql
CHECK (100000 <= ALL(SELECT netWorth 
					 FROM Studio, MovieExec 
					 WHERE president = code))
```

##### 2 

Consideriamo il seguente schema : 
```
Movies(title, year, length, genre, studio, producer)
```

Il vincolo : 
	La durata complessiva dei film prodotti da ciascuno studio non deve superare i 10000 minuti
Non può essere espresso con un `CHECK` a meno che il DBMS non supporti vincoli con sotto-query

Soluzione con sotto-query 
```sql
CHECK (10000 >= ALL(SELECT SUM(length) 
					FROM Movies 
					GROUP BY studio))
```

#### Asserzioni

Le asserzioni esprimono *invarianti globali* sull'intero schema relazionale : 
```sql
CREATE ASSERTION <name> CHECK ( <condition> )
```

La condizione deve essere vera quando l'asserzione viene creata e continuare a rimanere vera dopo *ogni modifica* del database

>[!note]
>Le *asserzioni* sono più potenti dei `CHECK` ma molto più complicate da implementare efficentemente

>[!note]
>Nessun DBMS le implementa poichè toppo inefficenti

>[!example]
>Nessuno può essere il presidente di uno studio senza avere un reddito di almeno 100000 
```sql
CREATE ASSERTION RichPresident CHECK( 
	NOT EXISTS( 
		SELECT Studio.name 
		FROM Studio, MovieExec 
		WHERE Studio.president = MovieExec.code AND 
			MovieExec.netWorth < 100000 
	) 
)
```

>[!example]
>La durata complessiva dei film prodotti da ogni studio deve essere di almeno 500 minuti 
```sql
CREATE ASSERTION SumLength CHECK(
	500 <= ALL(
		SELECT SUM(length)
		FROM Movies
		GROUP BY studio
	)
)
```

#### Vincoli o Asserzioni 

|                      | Dichiarazione            | Controllo                                         | Validità                  |
| -------------------- | ------------------------ | ------------------------------------------------- | ------------------------- |
| `CHECK` su attributo | Attributo di una tabella | Inserimento nella tabella o update dell'attributo | In assenza di sotto-query |
| `CHECK` su tupla     | Tabella                  | Inserimento nella tabella o update della tupla    | In assenza di sotto-query |
| Asserzione           | Schema relazionale       | Ogni modifica di ogni tabella menzionata          | Sempre                    |

#### Triggers

I *trigger* sono lo standard per il mantenimento di invarianti *globali* nei DBMS poichè possono essere implementati efficentemente 

Un *trigger* utilizza il paradigma *Evento-Condizione-Azione* 
1. Un *trigger* è associato ad un *evento* che ne determina l'attivazione 
	Esempi tipici sono `{SQL}INSERT,DELETE o UPDATE` su una certa tabella 
2. Quando un *trigger* viene attivato possiamo controllare una certa *condizione* , se questa risulta falso il trigger termina 
3. Se la condizione è vera viene eseguita una *azione* associata al trigger ( una sequenza arbitraria di operazioni sullo schema relazionale ) 

>[!note]
>I *trigger* sono stati standardizzati in *SQL-3* ( 1999 ) , ma i DBMS li avevano già implementati da prima ma non si aggiornano allo standard per problemi di backwards compatability

Un evento può convilgere una sola riga o righe multiple per questo abbiamo due *trigger* diversi : 
+ *Trigger per riga* : 
	Eseguiti per ognuna delle righe coinvolte dall'evento scatenante 
	Possiamo usare `{sql} OLD ROW` e `{sql}NEW ROW` per riferirsi rispettivamente alla tupla coinvolta dall'evento prima e dopo la sua occorrenza 
+ *Trigger per statement* : 
	Eseguiti una sola volta per evento scatenante 
	Si può usare `OLD TABLE` e `NEW TABLE`  per riferirsi a tutte le tuple coinvolte dall'evento prima e dopo la sua occorrenza 

>[!note]
>E' consentito fare uso di `OLD TABLE` e `NEW TABLE` anche all'interno di un *trigger* per riga ( la riga viene interpretata come una tabella con una singola tupla al suo interno )

In fase di definizione di un *trigger* è possibile specificare se l'azione debba essere eseguita prima o dopo l'evento scatenante : 
+ `{sql} BEFORE trigger` : attivati prima dell'evento scatenante
	Di solito vengono utilizzati per impedire l'esecuzione di un'operazione o per modificarne preventivamente il comportamento
+ `{sql} AFTER trigger` : attivati dopo l'evento scatenante 
	Hanno visibilità dello stato della base di dati dopo l'esecuizone di un'operazionee quindi sono talvolta necessari per motivi di espressività

>[!note]
>Un *AFTER trigger* può simulare l'annullamento di un'operazione facendo un rollback dello stato della base di dati alla situazione precedente 
>L'uso di *BEFORE trigger* è preferibile quando possibile 

##### Progettazione di Trigger

I *trigger* forniscono un modo indiretto per mantenere invarianti globali

Metodologia per il mantenimento di invarianti tramite *trigger* prevede 3 passi : 
1. Quali operazioni possono violare l'invariante
2. Il mantenimento dell'*invariante* può essere controllato per ogni riga coinvolta dall'operazione oppure no ? 
3. Cosa bisogna fare prima o dopo dell'operazione per garantire il mantenimento dell'*invariante*

>[!example]
>Vogliamo usare un *trigger* per garantire che non sia mai possibile abbassare uno stipendio 
>1. L'invariante può essere violata da un'operazione di aggiornamento 
>2. L'informazione che potrebbe violare l'invariante si trova sempre su una sola riga
>3. Possiamo fare 2 scielte : 
>	1. Impedire l'aggiornamento della riga ( `BEFORE` )
>	2. Riportare lo stipendio al valore originale ( `AFTER` )
```sql
CREATE TRIGGER NetWorthTrigger 
AFTER UPDATE OF netWorth ON MovieExec 
REFERENCING OLD ROW AS OldTuple, NEW ROW AS NewTuple 
FOR EACH ROW 
WHEN (OldTuple.netWorth > NewTuple.netWorth) 
	UPDATE MovieExec SET netWorth = OldTuple.netWorth 
	WHERE code = NewTuple.code;
```

>[!example]
>Vogliamo utilizzare un *trigger* per garantire che la media degli stipendi non scenda mai sotto $500.000$ : 
>1. L'*invariante* può essere violata da un'operazione di inserimento , aggiornamento o cancellazione
>2. Visto che la media è un'informazione globale della tabella e non di una riga non possiamo ricorrere ad un controllo per riga
>3. Possiamo mantenere l'*invariante* annulando l'operazione che l'ha violata cioè riportando la tabella allo stato originale ( `AFTER` )
```sql
CREATE TRIGGER AvgNetWorthTrigger 
AFTER UPDATE ON MovieExec 
REFERENCING OLD TABLE AS OldStuff, NEW TABLE AS NewStuff 
FOR EACH STATEMENT 
WHEN (500000 > (SELECT AVG(netWorth) FROM MovieExec)) 
BEGIN 
	DELETE FROM MovieExec 
	WHERE (name, address, code, netWorth) 
	IN (SELECT * FROM NewStuff); 
	INSERT INTO MovieExec (SELECT * FROM OldStuff); 
END;
```

>[!note]
>Servono *trigger* analogi per `{sql}INSERT` e `{sql}DELETE`

>[!example]
>Vogliamo utilizzare un *trigger* per garantire che la data di uscita di un film non possa mai essere `{sql}NULL` , usando il valore di default 1915 in questo caso
>1. L'*invariante* può essere violata da un'operazione di inserimento o aggiornamento
>2. L'informazione è relativa alla riga modificata o inserita
>3. Possiamo mantere l'*invariante* correggendo il valore della data nella riga prima o dopo l'operazione
```sql
CREATE TRIGGER FixYearTrigger 
BEFORE INSERT ON Movies 
REFERENCING NEW ROW AS NewRow, NEW TABLE AS NewStuff 
FOR EACH ROW 
WHEN NewRow.year IS NULL 
UPDATE NewStuff SET year = 1915;
```

>[!note]
>Serve un *trigger* analogo per `{sql}UPDATE`

##### Uso dei Trigger

Esistono 2 tipi di *trigger* : 
+ **Trigger passivi** : 
	Questi provocano il fallimento di un'operazione sotto determinate condizioni , usi tipici : 
	+ Definizione di vincoli di integrità 
	+ Controlli dinamici di autorizzazione (  )
+ **Trigger attivi** : 
	Questi modificano lo stato della base di dati in corrispondenza di certi eventi , usi tipici : 
	+ Definizione di vincoli di integrità 
	+ Meccanismi di auditing , logging
	+ Definizione di regole aziendali

>[!example]
>Attraverso i *trigger* possiamo implementare i vincoli di `FOREING KEY` gestendo sia la poltica `CASCADE` che la politica `SET NULL` oppure anche un'arbitraria *dipendenza funzionale* $X \to Y$

##### Vantaggi dei Trigger

Poichè i *trigger* sono gestiti dal *DBMS* non c'è alcun modo per sorpassarli : 
+ Risulta essere più robusto centralizzare un'*invariante* in un *trigger* che sparpagliare i controlli all'interno del codice 
+ Chiunque utilizzi la base di dati , anche all'esterno dell'applicazione che state sviluppando è soggetto al controllo dei *trigger*
+ Se si vuole fare *auditing* e *logging* i *trigger* sono l'unico strumento robusto per tali compiti visto che il *DBMS* ha completa visibilità delle operazioni effettuate sulle tabelle

##### Svantaggi dei Trigger

I *trigger* sono poco standardizzati e *DBMS* differenti faranno scielte differenti riguardo alcuni aspetti : 
+ Il linguaggio utilizzato per scrivere i *trigger* 
+ L'ordine dei *trigger* da svolgere se ve ne sono più di uno sullo stesso evento
+ Possibilità di chiamare un *trigger* all'interno di un'altro trigger , gestione dei *trigger* ricorsivi

>[!note] 
>I *trigger* sono difficili da debuggare , poco visibili in generale

#### Trigger o Vincoli

Generalmente , se è possibile , è sempre preferibile utilizzare i *vincoli* messi a dispozione da parte del *DBMS* invece che i *trigger* poichè : 
+ I vincoli sono standard e gestiti in modo uniforme da tutti i *DBMS* 
+ I vincoli hanno una semantica semplice e non presentano problemi in termini di debugging
+ I vincoli garantiscono che una certa proprietà valga già al momento della loro definizione a differenza dei trigger che sono reattivi

I *trigger* sono necessari per via della loro espressività : 
+ per *invarianti* che coinvolgono più di una tabella
+ per *invarianti* che coinvolgono più righe di una stessa tabella 

#### Trigger in Postgres

Esempio di sintassi in *Postgres* : 
```sql
CREATE TRIGGER name { BEFORE | AFTER } { evt [ OR ... ] } 
	ON table_name 
	[ REFERENCING { { OLD | NEW } TABLE AS tab } [ ... ] ] 
	[ FOR EACH { ROW | STATEMENT } ] 
	[ WHEN ( condition ) ] 
	EXECUTE FUNCTION func ( args )
```

Differenze rispetto allo standard :
+ Posso utilizzare `{sql}OR` per associare uno stesso *trigger* a più eventi
+ Non è possibile riferire `OLD ROW` e `NEW ROW` in `REFERENCING` ma c'è un modo *custom* per accedere a tali righe
+ Il corpo del *trigger* deve essere definito in una *funzione* separata

*Postgres* supporta la definizione di funzioni nel suo linguaggio nativo *PL/pgSQL* , questo linguaggio viene utilizzato per definire *trigger functions* ossia funzioni : 
+ con *trigger* come tipo di ritorno 
+ senza argomenti , il passaggio di parametri avviene in modo custom in fase di creazione del *trigger* perchè non esiste un chiamante

```sql
CREATE FUNCTION my_trigger() RETURNS trigger AS $$
	definizione della funzione
$$ LANGUAGE plpgsql
```

All'interno della definizione della funzione possiamo avere : 
```sql
BEGIN
	statement_1;
	...
	statement_n;
END;
```

Dove ogni *statement* può essere un'istruzione *SQL* , un *IF* opppure un *RETURN*

##### Passaggio di Parametri

Quando una trigger function viene invocata da *Postgres* vengono create nel suo scope delle variabili speciali : 
+ *NEW* : la nuova riga per operazioni di `{sql}INSERT/UPDATE` all'interno di un trigger per riga ( `NULL` nel caso di `{sql}DELETE` )
+ *OLD* : la vecchia riga per operazioni di `{sql}DELETE/UPDATE` all'interno di un trigger per riga ( `NULL` nel caso di `{sql}INSERT` )
+ *TG_NARGS* : numero di argomenti passati tramite `{sql}CREATE TRIGGER`
+ *TG_ARGV* : vettore di argomenti passati tramite `{sql}CREATE TRIGGER`

>[!note] 
>Vi sono inoltre altre variabili informative come *TG_OP* che dicono quale evento ha scatenato il *trigger*

##### Valore di Ritorno

Una trigger function associato ad un *BEFORE trigger per riga* può : 
+ ritornare `NULL` per indicare che l'operazione ( `{sql}INSERT, UPDATE` o `{SQL}DELETE` ) sulla riga deve essere abortita
+ nel caso di `{sql}INSERT` o `{sql}UPDATE` ritornare una riga che diventerà la nuova riga che sarà inserita o sostituirà la riga aggiornata 
+ Se non si vuole interferire con l'operazione : 
	+ Ritornare `NEW` nel caso di `{sql}INSERT UPDATE`
	+ Ritornare `OLD` nel caso di `{sql}DELETE`

Una trigger function deve ritornare `NULL` in tutti gli altri casi cioè nel caso di *trigger per statement* ed `AFTER` *trigger per riga*

##### Trigger per Riga

```sql
CREATE TRIGGER name { BEFORE | AFTER } { evt [ OR ... ] } 
	ON table_name 
	[ REFERENCING { { OLD | NEW } TABLE AS tab } [ ... ] ] 
	FOR EACH ROW 
	[ WHEN ( condition ) ] 
	EXECUTE FUNCTION func ( args )
```

+ Un `{sql}BEFORE` *trigger* per riga può prevenire operazioni o modificarle
+ La clausola `WHEN` può fare riferimento a `OLD`e `NEW` per specificare una condizione di attivazione e non può fare uso di sotto-query
+ Possiamo utilizzare `REFERENCING` per vedere i cambiamenti complessivi nell'intera tabella , non solo nella riga ( solo per `AFTER` trigger )
##### Trigger per Statement

```sql
CREATE TRIGGER name { BEFORE | AFTER } { evt [ OR ... ] } 
	ON table_name 
	[ REFERENCING { { OLD | NEW } TABLE AS tab } [ ... ] ] 
	FOR EACH STATEMENT 
	EXECUTE FUNCTION func ( args )
```

+ Un trigger per statement viene eseguito una volta anche se nessuna riga è coinvolta nell'operazione scatenante
+ Il `WHERE` non supporta `OLD`e `NEW`
+ Possiamo utilizzare `REFERENCING` per vedere i cambiamenti complessivi nell'intera tabella ( solo per `AFTER` trigger ) 

##### Modello di Esecuzione 

L'ordine di esecuzione dei *trigger* dipende dal loro tipo : 
+ I `BEFORE` *trigger per statement* si attivano prima di tutti ( prima che l'evento abbia inizio )
+ I `BEFORE` *trigger per riga* si attivano immediatamente prima di operare sulla riga coinvolta ( prima dei `CHECK` ) 
+ Gli `AFTER` *trigger per riga* si attivano alla fine dell'evento ma prima degli `AFTER` trigger per statement 
+ Gli `AFTER` *trigger per statement* vengono eseguiti per ultimi 

**Specificità di Postgres** : 
+ Un *trigger per riga* ha visibilità dei cambiamenti effettuati sulle righe precedenti ma l'ordine delle righe non è predicibile 
+ Se più di un *trigger* viene definito per lo stesso evento sulla stessa tabella essi sono eseguiti in ordine *alfabetico* fino a terminazione o finchè uno non ritorna `NULL` 
+ Un *trigger* può attivare ricorsivamente altri *trigger* ( può condurre a ricorsioni infinite )

>[!example]
>Trigger per garantire la dipendenza funzionale $A \to B$
```postgresql
CREATE TRIGGER FuncDep 
	BEFORE INSERT OR UPDATE ON Relation 
	FOR EACH ROW 
	EXECUTE FUNCTION fix_func_dep() 

CREATE FUNCTION fix_func_dep() RETURNS TRIGGER AS $$ 
	IF (EXISTS SELECT * FROM Relation 
			WHERE A = NEW.A AND B != NEW.B) 
	THEN RETURN NULL; 
	END IF; 
	RETURN NEW; 
$$ LANGUAGE plpgsql;
```

### Funzioni e Procedure 

Le funzioni in SQL possono avere vari utilizzi : 
+ Incapsulare funzionalità di uso comune 
+ Offrire interfacce di accesso semplificate ad utenti inesperti in SQL
+ Centralizzare lato server una sequenza di operazioni di cui non ci interessano i risultati intermedi ( miglioramento delle performance )

Vedremo le funzioni in *PL/pgSQL*
#### Dichiarazione di Funzioni

Possiamo dichiarare nel seguente modo : 
```sql
CREATE FUNCTION my_fun ( args ) RETURN type
AS function_body
LANGUAGE plpgsql
```

Dove il *function_body* è un blocco con la seguente struttura : 
```sql
[ DECLARE declarations ]
BEGIN 
	staements
END;
```

>[!note]
>*Postgres* richiede che il *function_body* sia una stringa. Lo possiamo definire in più righe facendolo precedere e terminare da `$$`

##### Dichiarazione di Variabili

Tutte le *variabili* utilizzate in un blocco vanno dichiarate nella sezione iniziale associando loro un tipo : 

```sql
name [ CONSTANT ] type [ NOT NULL ] [ = expr ];
```

Il tipo di una variabile può essere un qualsiasi tipo *SQL* . Ci sono inoltre alcuni tipi e sintassi particolari : 
+ `var%TYPE` : il tipo della variabile o colonna chiamata `var`
+ `tab%ROWTYPE` : il tipo record delle righe della tabella `tab`
+ `RECORD` : un qualsiasi tipo record 
+ `SETOF t` : un insieme di elementi di tipo `t` ( utilizzato solo per valori di ritorno )

>[!example]
```postgresql
CREATE FUNCTION my_concat(a text, b text, uppercase boolean = false)
RETURN text AS $$
BEGIN
	IF uppercase THEN RETURN UPPER(a || '' || b);
	END IF
	RETURN LOWER(a || '' || b);
END; 
$$ LANGUAGE plpgsql
```

Possiamo involare la funzione nei seguenti modi : 
```sql
SELECT my_concat(’Hello’, ’World’) -- ritorna helloworld
SELECT my_concat(’Hello’, ’World’, true) -- ritorna HELLOWORLD
SELECT my_concat(b := ’Hello’, a := ’World’) -- ritorna worldhello
```

**Assegnamento**

Un assegnamento ad una variabile si effettua con la sintassi : 
```sql
var = expr;
```

Il risultato di un comando *SQL* che ritorna una *singola riga* può essere salvato in una variabile con la sintassi : 
```sql
SELECT expr INTO [STRICT] var FROM ...
```

>[!note]
>L'`{sql}STRICT` richiede alla query di ritornare esattamente una riga , in caso contrario viene dato errore a runtime . Se viene omessa solo la prima riga del risultato verrà assegnata , `{sql}NULL` nel caso di risultato vuoto
##### Valore di Ritorno

Una funzione che ritorna un *singolo valore* può usare la sintassi : 
```sql
RETURN expr;
```

Se è necessario ritornare un *record* possiamo utilizzare i parametri di output per definire implicitamente il tipo :
>[!example]
```postgresql
CREATE FUNCTION sum_n_product(x int,y int, OUT sum int, OUT prod int)
AS $$
BEGIN
	sum = x + y;
	prod = x * y;
END; 
$$ LANGUAGE plpgsql
```

Una funzione che ritorna un *insieme di valori* ( `SETOF` ) deve costruirlo in modo incrementale tramite le sintassi : 
```postgresql
RETURN NEXT expr; -- aggiunge un record al risultato
RETURN QUERY query; -- aggiunge un insieme al risultato
```

L'insieme di valori da ritornare può essere restituito con `RETURN` senza passare alcun argomento o lasciando terminare la funzione

>[!example]
>Data la tabella `PC(model, speed, ram, hd, price)` definire una funzione che ritorna un insieme di modelli associati ai rispettivi prezzi
>
>Possiamo svolgerlo in due modi differenti : 
>1. Ritorniamo un `SETOF RECORD`
>2. Utilizziamo la sintassi `RETURNS TABLE` al posto di `RETURNS` 
```sql
-- opzione 1
CREATE FUNCTION f() RETURNS SETOF RECORD AS $$ 
BEGIN 
RETURN QUERY SELECT model, price FROM pc; 
END; 
$$ LANGUAGE plpgsql;
```
```sql
-- call
SELECT m,p FROM f() AS (m character(20), p real);
```

```sql
-- opzione 2
CREATE FUNCTION f() 
RETURNS TABLE(m integer, p real) AS $$ 
BEGIN 
RETURN QUERY SELECT model, price FROM pc; 
END; 
$$ LANGUAGE plpgsql;
```
```sql
-- call
SELECT * FROM f();
```

>[!note]
>La sintassi 
```sql
CREATE FUNCTION f()
RETURNS TABLE(m character(20), p real) ...
```
>[!note]
>Può essere riscritta in modo più rigoroso nel seguente modo :
```sql
CREATE FUNCTION f(OUT m character(20), OUT p real)
RETURNS SETOF RECORD ...
```

>[!note]
>Nel caso di funzioni con parametri di output che ritornano un insieme di valori si può usare `{sql}RETURN NEXT` senza argomenti per aggiungere gli attuali valori dei parametri di output come nuova riga del risultato

##### Statement Condizionali

Costrutto `IF THEN ELSE` 

```sql
IF boolean-expr THEN
	statements
[ ELSIF boolean-expr THEN 
	statements
	... ]
[ ELSE 
	statements ]
END IF;
```

Esiste inoltre il costrutto `CASE` , questo ha 2 forme :
1. **Costrutto CASE Semplice:**
```sql
CASE
   WHEN condizione1 THEN valore1
   WHEN condizione2 THEN valore2
   ...
   ELSE valore_default
END
```

   Questo costrutto valuta le condizioni nell'ordine in cui sono elencate e restituisce il valore corrispondente alla prima condizione vera. Se nessuna delle condizioni è vera, viene restituito il valore predefinito specificato nella clausola ELSE (facoltativa).

>[!example]
```sql
SELECT 
   CASE 
	   WHEN age < 18 THEN 'Minore'
	   WHEN age >= 18 AND age < 65 THEN 'Adulto'
	   ELSE 'Anziano'
   END AS category
FROM people;
```

2. **Costrutto CASE di Ricerca:**
```sql
CASE espressione_da_valutare
   WHEN valore1 THEN risultato1
   WHEN valore2 THEN risultato2
	...
   ELSE risultato_default
END
```

   Questo costrutto valuta un'espressione specificata e restituisce il risultato corrispondente al primo valore che coincide con l'espressione da valutare. Se nessun valore coincide, viene restituito il risultato predefinito specificato nella clausola ELSE (facoltativa).

>[!example]
```sql
SELECT 
   name,
   CASE gender
	   WHEN 'M' THEN 'Maschio'
	   WHEN 'F' THEN 'Femmina'
	   ELSE 'Non specificato'
   END AS gender_text
FROM employees;
```

In entrambi i casi, il costrutto CASE può essere utilizzato in qualsiasi parte di una query SQL dove è consentita un'espressione, come nelle clausole SELECT, WHERE, GROUP BY, ORDER BY e altre.

##### Cicli

Ciclo **While** : 
```sql
WHILE boolean-expr LOOP
	statements
END LOOP;
```

Ciclo **For** : 
```sql
FOR name IN [ REVERSE ] int-expr .. int-expr
			[ BY int-expr ] LOOP
	statements
END LOOP;
```

>[!note] 
>La variabile di iterazione non deve essere dichiarta ed è locale al ciclo

Il ciclo *for* può anche essere utilizzato per iterare sui risultati prodotti da una certa query : 
```sql
FOR target IN query LOOP
	statements
END LOOP;
```

L'iterazione su un array si effettua invece con `FOREACH` : 
```sql
FOREACH target IN ARRAY expr LOOP
	statements
END LOOP
```

##### Variabile `FOUND`

Ciascuna funzione contiene una variabile booleana `FOUND`
+ `SELECT INTO` imposta `FOUND` a `true` se viene assegnata una riga alla variabile corrispondente , `false` altrimenti
+ `UPDATE`,`INSERT` e `DELETE` impostano `FOUND` a `true` se almeno una riga è stata toccata dall'operazione , a `false` altrimenti 
+ Un ciclo `FOR` imposta `FOUND` a `true` se ha iterato almeno una volta a `false` altrimenti
+ `RETURN QUERY` imposta `FOUND` a `true` se la query ha ritornato almeno una riga , a `false` altrimenti

>[!example]
```sql
CREATE FUNCTION f3(OUT m character(20), OUT p real) 
RETURNS SETOF RECORD AS $$ 
declare r RECORD; 
BEGIN 
	FOR r IN SELECT model, price FROM lab.pc LOOP 
	SELECT r.model,r.price INTO m, p; 
	RETURN NEXT; 
	END LOOP; 
END; 
$$ LANGUAGE plpgsql;
```

##### Messaggi ed Eccezioni

Una *funzione* può riportare messaggi o errori con la sintassi :
```sql
RAISE [ level ] 'format' [, expr [, ... ]]
				[USING option = expr]
```
Dove : 
+ `level` indica il *livello* di severità dell'errore ( `DEBUG`, `LOG`, etc... ). Il *livello* di default `EXCEPTION` solleva nache un'*eccezione*
+ `{sql}'format'` è una string formattata ( posso inseri segnaposti da essere sostituiti ) che specifica il messaggio da riportare
+ La clausola `USING` permette di popolare informazioni aggiuntive sull'errore come il codice di errore `ERRCODE`

Si può usare `RAISE` senza parametri per rilanciare un'*eccezione* *catturata*

Per **catturare** un'eccezione possiamo usare la seguente sintassi 
```sql
BEGIN
	statements
EXCEPTION
	WHEN cond [ OR cond ... ] THEN handler
	[ WHEN cond [ OR cond ... ] THEN handler ... ]
END;
```

Le condizioni `cond` seguono una sintassi particolare che ci permette di avere condizioni complesse come fare azioni diverse in base al codice di errore

Quando un'eccezione viene catturata, il contenuto delle variabili locali persiste , ma tutti i cambiamenti al database effettuatu nel blocco che ha sollevato l'eccezione vengono **annullati** 

>[!example]
```postgresql
INSERT INTO mytab(firstname, lastname) VALUES(’Tom’, ’Jones’); 
BEGIN 
	UPDATE mytab SET firstname = ’Joe’ WHERE lastname = ’Jones’;
	x := x + 1; 
	y := x / 0; 
EXCEPTION 
	WHEN division_by_zero THEN 
		RAISE NOTICE ’caught division_by_zero’; 
		RETURN x; 
END;
```
>[!example]
>In questo caso catturiamo la divisione per 0 effettuata alla riga 5

##### Procedure

Una *procedura* è una funzione che non ritorna alcun risultato :
```postgresql
CREATE PROCEDURE my_proc( args )
AS proc_body
LANGUAGE plpgsql
```

Una *procedura* può essere invocata attraverso il comando `CALL` 

>[!note]
>+ Prima di Postgres 11 si utilizzava il comando `PERFORM`
>+ Una *procedura* differisce da una *funzione* void solo nella gestione della *transazioni*


---

>[!caution] 
>Dopo questo gli argomenti sono solo nella domanda di teoria

---


### Sicurezza e autenticazione

Tutti i principali *DBMS* implementano meccanismi di : 
+ *autenticazione* : Identifica chi sta operando sul database 
	Questa viene normalmente effettuata tramite l'utilizzo di un nome utente e password 
+ *autorizzazione* : Determinare chi può fare cosa ( ossia determinare i *permessi* per ogni utente ) 

>[!note] Controllo degli accessi
>
>Il controllo degli accessi è il meccanismo con cui viene verificato che chi richede un'operazione sia effitivamente autorizzato a farla 

#### Autenticazione 

>[!note] 
>Lo standard *SQL* non definisce uno standard per la gestione degli utenti , vediamo la l'implementazione in *Postgres*

La creazione di un nuovo utente avviene attraverso una query SQL : 
```sql
CREATE USER NomeUtente WITH PASSWORD NuovaPwd
```

In coda al comando possiamo aggiungere delle opzioni come : 
+ `{sql}SUPERUSER` : l'utente creato ignora i controlli di sicurezza
+ `CREATEDB` : consente all'utente di creare nuovi database
+ `VALID UNTIL ts` : consente di specificare la durata massima della password inserita dall'utente

In *Postgres* possiamo controllare il processo di autenticazione all'interno del file : $\text{pg\_hba.conf}$ 

Possiamo modificare il *metodo di autenticazione* per ciascuna richiesta di autenticazione con le seguteni opzioni :
+ *tipo di connessione* : locale , remota , cifrata 
+ *database* : lista di database o `all`
+ *utente* : lista di utenti o `all`
+ *indirizzo* : hostname , indirizzo IP , range di IP

Se non si trovano *match* per una connessione allora l'autenticazione è vietata

Posso inoltre definire un metodo di autenticazione : *trust* , *reject* , *password* , *MD5* , *SCRAM* , *peer* ...
##### Password

>[!example] 
>1. Crazione delll'utente il server si salva : `y=123456`
>2. Il *client* manda lo username e richiede la connessione
>3. Il *server* richiede la password per quell'username
>4. Il *client* fornisce la propria password `x=123456`
>5. Il *server* verifica che `x == y` ed autorizza l'accesso

>[!warning] Problemi di Sicurezza
>+ Se il canale di comunicazione in cui mandiamo la password non è cifrato siamo suscettibili a *man in the middle* attacks , problema facile da risolvere tramite TLS o SSL
>+ La password viene salvata  in chiaro sul server e quindi esposta a chiunque riesca ad ottenerene il controllo ( questo non viene più fatto in nuove versioni di *Postgres* )
##### MD5

>[!example] 
>1. In fase di creazione dell'utente il server salva `y=MD5(12345+peter)`
>2. Il *client* manda lo username e richiede la connessione
>3. Il *server* richiede un *MD5* della password poponendo un *salt*
>4. Il *client* calcola `x=MD5(MD5(123456+peter)+"salt")` e lo invia al server
>5. Il *server* verifica che `x == MD5(y+"salt")` ed autorizza l'accesso

>[!warning] Problemi di Sicurezza
>Questo protocollo non è consigliato per via dell'uso dell'*MD5* ( considerato un algoritmo di hashing debole ) e del *salt* breve
>
>Il furto di `y` può portare all'impersonificazione dell'utente , basterebbe sapere il *salt*
>
>Questi problemi sono risolti dall'algoritmo *SCRAM*

#### Autorizzazione

**Politiche base** : 
1. Quando un oggetto viene creato il suo creatore ne diventa il proprietario
2. Gli altri utenti possono accedervi solo secondo le modalità stabilite dai *permessi* concessi su di esso
3. Solo il creatore dell'oggetto può eliminarlo o alterarne la definizione 
##### Permessi

*SQL* mette a disposizione diversi tipi di permessi , fra cui : 
+ `SELECT` : può essere riferito ad una tabella intera o ad un set di attributi `X` di quella tabella
+ `INSERT` : può essere riferito ad una tabella intera o ad un set di attributi `X` di quella tabella
+ `UPDATE` : può essere riferito ad una tabella intera o ad un set di attributi `X` di quella tabella
+ `DELETE` : spesso necessitiamo il permesso `SELECT` per `DELETE` non banali
+ `TRIGGER` : necessario per definire un *trigger* su una tabella
+ `EXECUTE` : necessario per eseguire una *funzione* o *procedura*

##### Permessi e Trigger

+ Il permesso `TRIGGER` per una *tabella* abilita la definizione di *trigger* *arbitrari* su di essa 
+ Il creatore del trigger deve avere il permesso `TRIGGER` sulla tabella e tutti i permessi richiesti per eseguire l'azione del trigger
+ Quando un *trigger* viene attivato esso deve essere eseguito con i permessi del suo cretatore indipendentemente da chi ha indotto l'attivazione 

>[!warning] 
>L'uso di *trigger* può portare a scalate di privilegi

Quando una *funzione* viene dichiarata è possibile specificarne i permessi di esecuzione tramite le opzioni :
+ `SECURITY INVOKER` : la funzione viene eseguita con i permessi dell'utente chiamante ( *default* )
+ `SECURITY DEFINER` : la funzione viene eseguita con i permessi dell'utente che l'ha definita 

>[!warning] 
>L'utilizzo di `SECURITY DEFINER` può abilitare scalate di privilegi , possiamo però fornire accesso controllato a funzionalità che richiederebbero permessi elevati

#### Assegnare Permessi 

Il *proprietario* di uno schema relazionale ha tutti i permessi possibili sulle tabelle e altri elementi dello schema , questi permessi possono essere concessi ad altri utenti usando la sintassi : 
```postgresql
GRANT ListaPermessi ON Elemento TO ListaUtenti
```

>[!note] 
>Possiamo utilizzare `ALL PRIVILEGES` per indicare tutti i permessi 
>Possiamo utilizzare `PUBLIC` per indicare tutti gli utenti ( compresi quelli non ancora creati )

#### Delegare Permessi

I permessi possono essere assegnati fornendo la possibilità di *delegarli* ad altri utenti : 

```postgresql
GRANT ListaPermessi ON Elemento TO ListaUtenti WITH GRANT OPTION
```

E' sempre possibile delegare una versione meno generale di un privilegio ( delegabile ) che si possiede

>[!example] 
>Un utente con permesso `{postgresql}SELECT WITH GRANT OPTION` può delegare `SELECT(X)` con `X` arbitrario sullo stesso elemento

#### Revoca di Permessi

I permessi assegnati possono essere *revocati* tramite la sintassi : 
```postgresql
REVOKE ListaPermessi ON Elemento FROM ListaUtenti
```

La revoca deve essere terminata da una delle seguenti opzioni : 
+ `{postgresql}CASCADE` : Il permesso viene revocato in modo ricorsivo a tutti gli utenti che lo hanno ricevuto
+ `{postgresql}RESTRICT` : fa fallire la revoca se essa comporterebbe la revoca di ulteriori permessi secondo la politica `{postgresql}CASCADE`

>[!note] 
>Un utente può revocare soltanto permessi assegnati *direttamente* da se stesso a meno di revoche indirette tramite `{postgresql}CASCADE`

>[!example]
>>[!todo] 

##### Revoca di Deleghe

Possiamo revocare solo la *possibilità* di delega ma non il permesso 

```postgresql
REVOKE GRANT OPTION FOR ListaPermessi ON Elemento FROM ListaUtenti
```

##### Revoca e Generalità 

Potrebbe essere che un utente possieda un permesso `P` e una sua variante meno generale `p` sullo stesso oggetto 

Revocare `p` non ha alcun effetto su `P` 
Revocare `P` invece ha un comportamento che dipende dal *DBMS* : 
+ *Postgres* revoca automaticamente anche `p` 
+ Lo standard *SQL* suggerisce di lasciare assegnato `p` 

#### Ruoli 

Un *ruolo* è un colletore di permessi che permette di introdurre un livello di segmentazione durante la loro assegnazione

##### Gestione dei Ruoli 

Un ruolo può essere creato tramite il comando : 
```postgresql
CREATE ROLE NomeRuolo;
```

Una volta fatto questo ci basta usare i comandi :
+ `GRANT` : per assegnare permessi a ruoli e ruoli ad utenti
+ `REVOKE` : per rimuovere permessi a ruoli e ruoli ad utenti

I ruoli assegnati ad un utente non sono *attivi* di default. L'attivazione di un ruolo per ottenere i permessi viene effettuata tramite il comando : 
```postgresql
SET ROLE NomeRuolo;
```

**Pros** : 
+ Possiamo raggruppare insiemi di permessi *logicamente collegati*
+ Risulta essere meno dispensioso assegnare ruoli rispetto a permessi visto che vi sono molti meno ruoli rispetto ai permessi
+ Rimuove errori nell'assegnazione di permessi
+ Le operazioni di revoca sono semplificate 
+ Sono più fedeli al principio di *minimo privilegio*

##### Ruoli in Postgres

In *Postgres* non vi è una vera e propria differenza tra utenti e ruoli ( il comando `CREATE USER` è un alias per `CREATE ROLE WITH LOGIN` )

>[!note] 
>+ L'opzione `CREATE ROLE` consente al ruolo di creare altri ruoli 
>>[!warning] 
>>Potrebbe portare a scalata di privilegi
>
>+ Ruoli assegnati con `WITH ADMIN OPTION` possono essere delegati
>+ Possiamo assegnare ruoli ad altri ruoli introducendo una forma di *ereditarietà* dei permessi
>+ Se un permesso viene assegnato tramite un ruolo, qualsiasi altro utente con quel ruolo può revocarlo

Possiamo gestire l'ereditarietà attraverso le opzioni `INHERIT` ( *default* ) e `NOINHERIT` 

>[!example] 
#### SQL Injection

>[!todo]
>

### Indici e viste materializzate

>[!note] Definizione
>Un *indice* è una struttura dati ausiliaria che ci permette di accedere in modo più efficente alle tuple di una relazione che soddifano una determinata proprietà

Un *indice* su un attributo $A$ di una relazione $R$ è una lista di coppie $(a_i, P_i)$ dove $a_i$ è un valore di $A$ presente in almeno una tupla di $R$ e $P_i$ è un insieme di puntatori alle tuple di $R$ per cui $A$ vale $a_i$
Tale lista è ordinata rispetto al valore di $A$ 

In pratica si utilizza una struttura dati simile ad un *Binary Search Tree* per memorizzare l'indice in modo da trovare in modo efficente i puntatori alle tuple che soddisfano una condizione $A$ 

>[!note] 
>L'*indice* creato viene utilizzato solo quando il query planner del DBMS lo ritiene vantaggioso

>[!example] 
>Supponiamo di avere un *indice* sull'anno di produzione di un film , avremo che verrà creata la seguente struttura dati : 
>![[Pasted image 20240403144012.png]]
>
>Ora per trovare tutti i film prodotti nel 2012 dobbiamo esaminare solo la metà delle tuple 

#### Indici Multiattributi

Nel caso avessimo indici formati da più attributi l'ordine di primo grado sarà il primo attributo dell'indice e l'ordinamento secondario si svolgerà sul'ordinamento primario

>[!example] 
>![[Pasted image 20240403144906.png]]

>[!warning] 
>L'ordine degli attributi è rilevante alla costruzione di un indice multiattributo , si scieglie come ordinamento primario l'attributo per il quale ci si aspettano più query

>[!example] 
>>[!todo] 

>[!note] 
>Generalemente se il database si trova completamente in RAM allora il guadagno in termini di accessi è generalmente minimale

Per questo generalmente non si utilizza come misura del costo di un'operazione il numero di accessi alle tuple poichè ignoriamo l'organizzazione fisica della memoria 

Una metrica migliore è basata sul numero di *pagine* caricate in RAM : 
+ Ciascuna pagina tipicamente contiene motle tuple 
+ Anche se volessimo accedere ad una sola tuple comunque dovremmo caricare la corrispondente pagina in RAM
+ L'accesso a tutte le tuple in una pagina è solo poco più costoso dell'accesso ad una singola tupla 

Se una tabella è fortemente "*clusterizzata*" su un certo attributo nella memoria fisica è possibile accedere a molte tuple caricando solo poche pagine : il numero di tuple come stima del costo effettivo risulta essere quindi *pessimistica*

>[!example] 
>Supponiamo che la tabella `Movies` occupi 700 pagine di memoria e ogni pagina contenga 100 tuple e che vi siano 300 film prodotti nel 2001 : 
>+ se i film sono salvati sul disco ordinati per anno possono bastare 3 pagine ( tuple tutte continue )
>+ Nel caso peggiore potremmo dover accedere a 300 pagine ( ogni pagina contiene una sola tupla con 1 solo film del 2001 )

**Conclusioni Indici** : 

+ **Pro** : 
	Un *indice* su di un asttributo può accelerare di molto l'esecuzione delle query in cui un valore è specificato per quell'attributo o di join che coinvolgono quell'attributo
+ **Contro** : 
	Ogni indice che utilizziamo rende le operazioni di inserimento , cancellazione e aggiornamento più costose poichè anche l'indice deve essere aggiornato  

**Consigli** : 
+ *Utilizzare gli indici* :
	+ Su una chiave 
	+ Sulle chiavi esterne 
	+ Qando le operazioni di modifica sono rare 
	+ Quando le tuple sono clusterizzate su un certo attributo nella memoria fisica ( `CLUSTER` )
+ *Non utilizzare gli indici* : 
	+ Su tabelle piccole che occupano un ridotto numero di pagine
	+ Su attributi poco selettivi ( sesso , stato civile )
	+ Su attributi modificati di frequente

#### Definizione di Indici

Una sintassi per definire un nuovo indice è la seguente : 
```postgresql
CREATE INDEX NomeIndice ON NomeTabella ( Attributi )
```

Sintassi per eliminare un indice : 
```postgresql
DROP INDEX NomeIndice
```

>[!note] 
>Una volta che un indice è definito il *DBMS* lo utilizza automaticamente quando lo ritiene più efficente dello scanning sequenziale

>[!tip] 
>+ `ANALYZE TableName` : ci fornisce delle statistiche sulla distribuzione dei dati , utilizzate dal query planner per decidere che *indici* usare
>+ `EXPLAIN Query` : Spiega che metodo ha utilizzato il query planner per svolgere quella query 
>>[!example] 
>>Senza index
>> ```postgresql
>>EXPLAIN SELECT * FROM foo; 
>>						QUERY PLAN
>> --------------------------------------------------------- 
>> Seq Scan on foo (cost=0.00..155.00 rows=10000 width=4) (1 row)
>>```
>>Con index
>> ```postgresql
>>EXPLAIN SELECT * FROM foo WHERE i = 4; 
>>						QUERY PLAN
>> --------------------------------------------------------- 
>> Index Scan using fi on foo (cost=0.00..5.98 rows=1 width=4) Index Cond: (i = 4) (2 rows)
>>```
>>

#### Modello di Costo

>[!todo] 
#### Selezione Automatica di Indici

Un *DBMS* può suggerire automaticamente gli indici migliori sulla base di un *modello di costo* simile al seguente : 
1. Usa i log delle query per stimare il costo delle operaizoni più frequenti
2. Genera un insieme di *indici candidati* $I$ e stima i loro tempi di esecuzione
3. Ritorna l'insieme di indici $J_{min}$ che ottimizza i tempo di esecuzione 

>[!note] 
>Il secondo passo potrebbe essere implementato in modo *greedy* ( non considera altri risultati ) per motivi di efficenza :
>1. Usa i log delle query per stimare il costo delle operaizoni più frequenti
>2. Genera un insieme di indici candidati $I$ ed inizializza $J \neq \emptyset$
>3. Finchè è possibile migliorare i tempi di esecuzione : 
>	1. Identifica $i_{min} \in I$ ossia l'indice che ottimizza meglio i tempi di esecuzione assumendo di avere già creato gli indici in $J$
>	2. Imposta $J = J \cup {i_{min}}$
>	3. Imposta $I = I -  {i_{min}}$

#### Viste e Performance

Le *viste* hanno un problema di performance in quanto devono essere *valutate* ogni volta che viene fatta una query su di questa 

Una possibile soluzione sarebbero le *viste materializzate*
##### Viste Materializzate

SQL permette di *materializzare* una vista in memoria in modo che essa *non venga valutata* ad ogni query che la coinvolge :

>[!example] 
>```postgresql
>CREATE MATERIALIZED VIEW MovieProd AS 
>	SELECT m.title, m.year, e.name 
>	FROM Movies m, MovieExec e 
>	WHERE m.producer = e.code
>```

>[!note] 
>L'uso di viste materializzate comporta un costo aggiuntivo derivante dalla necessità di riflettere sulla vista le modifiche alle tabelle su cui la vista è costruita

Non c'è bisogno di aggiornare `MovieProd` quando : 
+ Modifichiamo tabelle differenti da `Movies` e `MovieExec`
+ Modifichiamo attrbuti diversi da quelli menzionati nella definizione di `MovieProd`

>[!important] Approccio Conservativo
>In tutti i restanti casi rigenero la vista ( è possibile svolgere diverse ottimizzazioni )
>*Postgres* delega la responsabilità all'utente finale che manualmente può : 
>+ creare dei trigger per refreshare la vista
>+ refershare la vista periodicamente
>+ utilizzare il comando `REFRESH MATERIALIZED VIEW` manualmente

**Ottimizzazioni** : 

Potremmo svolgere queste operazioni invece di rigenerare completamente la vista

+ Aggiungere una tupla :
```postgresql
INSERT INTO VistaMaterializzata 
VALUES (...)
```
+ Eliminare una tupla o delle tuple : 
```postgresql
DELETE FROM VistaMaterializzata
WHERE ...
```

**Conclusioni** :

+ Possono velocizzare le query ma rendono operazioni di modifica più costose o potenzialmente invalidanti
+ In certi *DBMS* vengono mantenute in modo incrementale per quanto possibile ma richiedono comunque di essere *rigenerate* dopo certe operazioni
+ Possono essere *inlined* automaticamente dal *DBMS* in una query per migliorarne l'efficenza sfruttando il fatto che parte dell'informazione è già stata computata e salvata in memoria

##### Inlining Viste Materializzate

Il *DBMS* può svolgere l'inlining sotto le seguenti condizioni :

Abbiamo la seguente *vista materializzata* : 
```postgresql
SELECT AV
FROM RV
WHERE CV
```
E la seguente *query* : 
```postgresql
SELECT AQ 
FROM RQ
WHERE CQ
```

Se abbiamo che : 
+ $RV \subseteq RQ$
+ $CQ = CV \land CQ'$ per qualche $CQ'$
+ Ogni attributo di $CQ'$ che proviene da $RV$ fa parte di $AV$
+ Ogni attributo di $AQ$ che proviene da $RV$ fa parte di $AV$

Allora avremo che l'*inlining* sarà : 
```postgresql
SELECT AQ
FROM V , RQ-RV
WHERE CQ'
```

>[!example] 
Vista *materializzata*
```postgresql
CREATE MATERIALIZED VIEW MovieProd AS 
	SELECT m.title, m.year, e.name 
	FROM Movies m, MovieExec e 
	WHERE m.producer = e.code
```
*Query*
```postgresql
SELECT s.starName 
FROM StarsIn s, Movies m, MovieExec e 
WHERE s.title = m.title 
	AND s.year = m.year 
	AND m.producer = e.code 
	AND e.name = ’Tarantino’
```
Risultato dell'*inlining* : 
```postgresql
SELECT s.starName 
FROM StarsIn s, MovieProd mp 
WHERE s.title = mp.title 
	AND s.year = mp.year 
	AND mp.name = ’Tarantino’
```

### Transazioni

Raggruppare una *sequenza di operazioni* può causare problemi quando : 
+ Ci sono molte operazioni *concorrenti* sulla base di dati ( più persone stanno prenotando contemporaneamente un posto a sedere sullo stesso volo )
+ Certe operazioni *falliscono* e non possono essere completate

In entrambi i casi possiamo danneggiare l'*integrità* della base di dati

>[!example] 
>2 utenti $u$ e $v$ vogliono prenotare lo stesso posto $22A$ *contemporaneamente*
![[Concurrenxy.excalidraw]]
>
>Alla fine dell'esecuzione avremo che il posto è occupato da 2 utenti differenti

>[!example] 
>*Fallimenti* : Vogliamo rimborsare un biglietto , preleviamo 800 euro dal conto della compagnia e aggiungiamo 800 euro nel conto del cliente 
>
>```postgresql
>UPDATE Accounts
>SET balance = balance - 800
>WHERE acctNo = 342;
>```
>```postgresql
>UPDATE Accounts
>SET balance = balance + 800
>WHERE acctNo = 456;
>```
>Potrebbe succedere che l'operazione crashi dopo la prima operazione non rimborsando ma il
>cliente

Per risolvere i problemi di *integrità* dei dati si utilizzano le **Transazioni** : 

Una *transazione* è una sequenza di operazioni sul database che soddisfino le seguenti proprietà : 
1. *Serializzabilità* : L'esecuzione concorrente di più transazioni è equivalente ad una loro esecuzione seriale in un qualche ordine 
2. *Atomicità* : Se la transazione termina prematuramente tutti suoi effetti parziali sono annulati
3. *Persistenza* : Le modifiche effettuate da una transazione terminata con successo sono permanenti 

##### Serializzabilità

L'esempio precedente dovrà essere eseguito nel seguente modo :

![[Serilizable.excalidraw]]

In questo modo solo uno dei due può avere quel posto 
##### Atomicità 

Nell'esempio precedente se avviene un crash tra 2 operazioni all'interno di una transazione questa non viene più eseguita annullando tutte le modifiche apportate fino al crash ( revert allo stato prima dell'inizio della transazione )
#### Programmare Transazioni

Normalmente ogni operazione *SQL* è gestita come una transazione indipendente , possiamo però utilizzare i seguenti comandi : 
+ `{postgresql}START TRANSACTION` indica l'inizio di una nuova tansazione
+ `{postgresql}COMMIT` indica la terminazione *corretta* di una transazione , tutto ciò che è stato fatto durante la transazione deve essere reso persistente
+ `{postgresql}ROLLBACK` indica la terminazione *anomala* di una transazione , tutto ciò che è stato fatto durante la transazione deve essere annullato

>[!note] 
>*API* come *JDBC* offrono metodi che permettono di gestire le transazioni che si appoggiano a questi comandi

##### Vincoli

Vista l'*atomicità* delle transazioni è possibile *rimandare* il controllo di alcuni vincoli di intergrità alla fine di una transazione 

Ogni vincolo di integrità può essere quindi assegnato ad una fra tre categorie : 
+ `{postgresql}NOT DEFERRABLE` : il vincolo viene sempre controllato dopo ogni operazione 
+ `{postgresql}DEFERRABLE INITIALLY IMMEDIATE` : il vincolo viene controllato dopo ogni operazione della transizione ma è possibile rilassarlo per farlo controllare solo prima del commit
+ `{postgresql}DEFERRABLE INITIALLY DEFERRED` : il vincolo viene controllato solo prima del commit ma è possibile forzarlo a farlo controllare dopo ogni operazione della transizione

>[!note] 
>I vincolo *rimandabili* possono essere configurati tramite `{postgresql}SET CONSTRAINTS`

#### Implementazioni di Transizioni

Visto che una transazione deve essere una sequenza di operazioni *serializzate* questa ci porta a dei problemi in termini di performance : 

Ciascuna transazione prende un *lock* *globale* ( blocca qualsiasi altra operaizone sul database ) sul database che viene rialasciato dopo il commit 

*ottimizzazione* : insieme di *lock locali* che blocchino solo porzioni del database e gestione "rilassata" delle transazioni *read only* poichè non possono compromettere l'integrità della base di dati 

>[!note] 
>I *DBMS* moderni utilizzano soluzioni senza *lock* come *MVCC* (*multiversion concurrency control*)
>Inoltre forniscono ulteriore controllo al programmatore definendo diversi livelli di isolamento fra transazioni 
#### Transazioni Read Only 

Possiamo dichiarare una transazione *read only* tramite la sintassi : 
```postgresql
SET TRANSACTION READ ONLY 
```

Questo permette alla transazione di leggere solo dati ( `SELECT` ) ma non scriverli

Tutte le query nella transazione possono vedere solo le scritture committate prima dell'inizio della transazione

Più operazioni *read only* che operano sugli stessi dati possono essere eseguire concorrentemente

>[!important] 
>Una transazione *read only* fornisce una lettura *consistente* dello stato del database prima dell'inizio della transazione

#### Transazioni Read Uncommitted

Il livello di isolamento `{postgresql}READ UNCOMMITTED` consente ad una transazione di leggere *dirty data* ossia dati scritti da altre transazioni che non hanno ancora fatto commit ( si svolge una *dirty read* ) 

>[!warning] 
>Potrebbe avvenire che la transazione che ha scritto i *dirty data* potrebbe *abortire* : in tal caso i *dirty data* dovrebbero essere rimossi e non dovrebbero influenzare le altre transazioni
>
>*SQL* limita l'utilizzo di `{postgresql}READ UNCOMMITTED` a solo transazioni *read only* a meno che lo sviluppatore non decida di rilassare questo vincolo

>[!todo] 
>>[!example] 
>>scrivi gli esempi dirty reads 15-16
#### Transazioni Read Committed

Il livello di isolamento `{postgresql}READ COMMITTED` impedisce il fenomeno delle *dirty reads* fornendo un maggiore isolamento : 
+ Quando una transazione vuole effettuare una *scrittura* acquisice un *lock* che viene rilasciato solo dopo la sua terminazione
+ Si può verificare il fenomeno di **unrepeatable read** : due letture degli stessi dati in momenti diversi possono portare a risultati diversi a causa dell'intervento di un'altra transazione 
+ Si può verificare il fenomeno di **lost update** : la perdita di una modifica da parte di una transazione causata da un aggiornamento operato da un'altra transazione

>[!todo] 
>>[!example] 
>>Esempio unrepeatable read , lost update
#### Transazioni Repetable Read

Il livello di isolamento `{postgresql}REPEATABLE READ` impedisce il fenomeno delle *dirty read* delle *urepeatable read* e dei *lost update* : 
+ Quando una transazione vuole effettuare una lettura oppure una scrittura acquisisce un *lock* che viene rilasciato solo dopo la sua terminazione 
>[!note] 
>I *lock* sono a livello di righe ( in modo da aumentare le performance )

>[!warning] 
>Si può verificare il fenomeno dei *fantasmi* : un'altra transazione può aggiungere dati ad una tabella prima che la transazione sia completata andando ad influenzare il risultato ( poichè il risultato potrebbe essere sull'intera tabella )

>[!example] 
>>[!todo] 

#### Interazioni fra Livelli di Isolamento

Il livello di isolamento di una transazione riguarda esclusivamente ciò che può vedere quella transazione  

>[!example] 
>Se abbiamo una transazione $T$ `{postgresql}SERIALIZABLE` questà dovrà essere svolta come se tutte le altre transazioni siano eseguite interamente prima o dopo $T$ ma se un'altra transazione è `{postgresql}READ UNCOMMITTED` quest'ultima potrà leggere *dirty data* dalla transazione $T$

#### Transazioni in Postgres

*PostgreSQL* considera ciascuna istruzione *SQL* come una transazione : 
	Se non viene eseguito `{postgresql}BEGIN` ciascuna istruzione ha un `{postgresql}BEGIN` implicito e , se ha successo un `{postgresql}COMMIT` 

Il livello di isolamento di default è `{postgresql}READ COMMITTED` ma i livelli di isolamento garantiscono proprietà più forti rispetto allo standard `SQL` 

>[!note] 
>`{postgresql}SERIALIZABLE` garantisce l'assenza di *anomalie di serializzazione* che invece sono possibili con `{postgresql}REPEATABLE READ` 

>[!example] 
>>[!todo] 
### Linguaggi per SQL

>[!todo] 
>mybe