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
#### Varifica di Primalità

Dato $R(T,F)$ , il problema di verificare se un attributo $A\in T$ è *primo* ha complessità *esponenziale* :
+ Si può dimostrare che il problema è *NP-completo* 
+ Ciò implica che non esistono soluzioni significativamente più efficenti dell'apporoccio ovvio di generare tutte le possibili chiavi
#### Forma Canonica

Vogliamo portare l'insieme delle *dipendenze funzionali* ad una forma più standard , detta *forma canonica* equivalente all'originale 

>[!important] Definizione Equivalenza
>Due insiemi di *dipendenze funzionali* $F$ e $G$ sono *equivalenti* ( indicato con $F \equiv G$ ) se e solo se $F^+=G^+$ 

>[!note]
>Se $F=G$ allora $F\equiv G$ ma in generale non vale il contrario

>[!important] Definizione Attributo Estraneo
>Sia $X\rightarrow Y \in F$ . L'attributo $A\in X$ è *estraneo* se e solo se $(X-{A})\rightarrow Y \in F^+$

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
>1. *Decomponiamo* $A\rightarrow BC$ in $A\rightarrow B$ e $A\rightarrow C$ , dato che $A\rightarrow B$ è giaà presente otteniamo $G=\{A\rightarrow C , B\rightarrow C , A\rightarrow B , AB\rightarrow C  \}$
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

Una perdita di informazione è quindi definita come : proiettando una relazione sui sottoschemi e poi facendo la giunzione si ottengono più ennuple di quante ce ne fossere nella relazione originaria

>[!important] Teorema
>Sia $p=\{R_1(T_1),R_2(T_2)\}$ una decomposizione di $R(T,F)$ . $p$ è una decmposizione che *preserva i dati* se e solo se $T_1\cap T_2 \rightarrow T_1 \in F^+$ oppure $T_1\cap T_2 \rightarrow T_2 \in F^+$ 

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
Se facessimo la `JOIN` vedremmo che ritorneremmo alla tabella originale 

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
>	+ Consideraimo $R_2(\{ C,C \})$ , abbiamo :
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
3. Pe ogni $X \to Y \in G$ crea uno schema $S_i(XY)$
4. Elimina ogni schema contenuo in un'altro schema
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

##### Proprietà *BCNF*

**Preservazione delle Dipendenze**  :
	E' facile dimostrare che la conversione in *3NF* preserva le dipendenze : poichè per ogni $X\to Y \in G$viene creato uno schema $S_i(XY)$ abbiamo $X\to Y \in \pi_{XY}(G)$ quindi $G$ è contenuto nell'unione delle proiezioni 

**Preservazione dei Dati** : 
	L'ultimo passo della conversione garantisce che la decomposizione contenga almeno uno schema i cui attributi formano una superchiave dello schema iniziale 
	Poichè la decomposizione preserva le dipendenze essa deve preservare anche i dati 

La conversione in *3NF* non garantisce l'assenza di anomialie

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
1. Convertiamo lo schema in *BCNF* per eliminare le anomalie , se notiamo che la conversione non ha preservato le diependenze ci accontentiamo di una conversione in *3NF*
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
>+ Inserimento di una tupla con attributo `president` non `NULL` e non coincidecon l'attributo `code` di una tupla in `MovieExec`
>+ Aggiornamento di una tupla per cambiare l'attributo `president` ad un valore non `NULL` che non coincide con l'attributo `code` di una tupla di `MovieExec` 

#### CHECK

##### CHECK su Attributi

##### CHECK su Tuple

#### Aggiornare i Vincoli