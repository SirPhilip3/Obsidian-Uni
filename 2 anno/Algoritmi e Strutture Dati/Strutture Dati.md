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
+ `{cpp} search(Dizionario S, Chiave K) -> Elem U {NIL}`
	- *Pre-condizione* : nessuna
	- *Post-condizione* : Resituisce il valore associato alla chiave $K$ se presente in $S$ , $NIL$ altrimenti ( il valore non è presente nel Dizionario $S$ )
+ `{cpp}insert(Dizionario S, Elem v, Chiave K)`
	+ *Pre-condizione* : nessuna
	+ *Post-condizione* :  Associa il valore $v$ alla chiave $K$ aggiungendo la coppia al dizionario se non presente , aggiornando il valore relatiovo a $K$ se presente
+ `{cpp} delete(Dizionario S, Chiave K)`
	+ *Pre-condizione* : $K$ deve essere presente in $S$
	+ *Post-condizione* : Cancellazione della coppi avente chiave $K$ dal Dizionario $S$

## Implementazione attraverso Array ordinati

I *dati* in questa implementazione sono contenuti in un array ( $A$ ) di dimensione $n$ contenente un record con 2 campi `( Key , Info )` ,  i record sono ordinati secondo il campo `Key` ( in modo da implementare la *ricerca binaria* )

*Esempio* :

|$4,-7$|$6,9$|$8,-4$|$12,11$|$24,6$|$30,7$|
|-|-|-|-|-|-|

Avremo anche un attributo `A.length` che contiene la dimensione dell'array

Il **costo** in termini di **spazio** è equivalente allo spazio richiesto per memorizzare $n$ elementi , avremo quindi :
$$S(n)=\Theta(n)$$
### Operazioni 

#### Search

##### Code 

```c
search(Dizionario A, Key K)
	i = search_index(A, K, 1 , A.legth)
	if i == -1 
		return NIL // non è presente la Key
	else 
		return A[i].info // ritrona val assunto da key

search_index(Dizionario A, Key K, int p , int r) -> int // p , r indicano su che parte del vettore svogliamo la binary search
	if  p > r
		return -1 // se abbiamo che gli indici si sono scambiti
	else 
		med = L(p+r)/2 L  // parte intera inferiore
		if A[med].Key == K
			return med
		else 
			if A[med].Key > K
				return search_index(A, K, p , med - 1)
			else 
				return search_index(A, K, med + 1 , r)  
```

##### Complexity

La complessità di `search` dipende dalla complessità di `search_index` 

Il *caso base* ha complessità costante :
```c
if  p > r
	return -1 
```

Ne restanti casi abbiamo una *ricosione* avremo infatti che :

```c
med = L(p+r)/2 L 
if A[med].Key == K
	return med
```
Risulta avere complessità *costante* 

Mentre 
```c
if A[med].Key > K
	return search_index(A, K, p , med - 1)
else 
	return search_index(A, K, med + 1 , r)  
```

Risulterà avere complessità :
$$T\bigg(\frac n 2 \bigg)$$
Avremo infatti che nel peggior caso la funzione `search_index` verrà chiamata su di un array con dimensione uguale alla sua metà 

La complessità totale sarà quindi :
$$T(n) = \begin{cases} \Theta(1) &\text{se } n = 0 \\ T\big(\frac n 2 \big)+\Theta(1) &\text{se } n\gt0 \end{cases}$$

Per risolvere questa ricorezza si può fare uso del *Master Theorem* avremo infatti :
+ $a=1$
+ $b=2$
+ $d=log_2 1 = 0$
+ $f(n)=\Theta(1)=1$
+ $n^d = n^0 = 1$

Siamo quindi nel caso in cui la complessità dello $split+merge = \text{ricorsione}$
Avremo quindi che la complessità della funzione `search_index` è :
$$T(n)=\Theta(n^d log \ n)=\Theta(1\cdot log \ n)=\Theta(log \ n)$$
La complesstà della `search` sarà quindi :
$$T(n)=\Theta(log \ n)+  \Theta(1)=\Theta(log \ n)$$
#### Insert

##### Code 

```c
insert(Dizionario S, Info v, Key k)
	i = 1
	while (i <= A.legth and A[i].Key < K)
		i = i + 1 // ricerca dell'elemento 
	if (i <= A.length and A[i].Key == K)
		A[i].Info = v // l'indice corrisponde alla key allora aggiorniamo il valore di info 
	else 
		reallocate(A,A.length + 1)  // aggiungiamo 1 spazio per il nuovo elemento
		A.length = A.length + 1 // aggiorniamo la lunghezza dell'array
		for j = A.length down to i + 1
			A[j]=A[j-1] // spostiamo tutti gli elementi a partire dal primo più grande della key di 1 elemento a destra per fare spazio al nuovo elemento
		A[i].Key = K
		A[i].Info = v
		// aggiunta del nuovo elemento 
```

##### Complexity

L'algoritmo non essendo ricorsivo possiamo definire la sua complessità come la somma della complessità delle varie parti dell'algoritmo 

###### 1

```c
while (i <= A.legth and A[i].Key < K)
	i = i + 1 
```
La complessità del codice al suo interno è $\Theta(1)$ 
Essendo che questo ciclo viene svolto $i$ volte avremo che la sua complessità risultante è : $i\cdot d$

###### 2 

```c
reallocate(A,A.length + 1)
```

La *reallocate* ha un costo di $O(n)$ 

###### 3

```c
for j = A.length down to i + 1
	A[j]=A[j-1] 
```

Il ciclo *for* viene eseguito $(n+1)-(i+1)+1=n-i+1$  volte , il suo corpo ha un costo pari a $d$ , avremo quindi un costo complessivo pari a : $(n-i+1)\cdot d$

$n+1$ poichè abbiamo scritto alla riga prima : `{cpp} A.length = A.length + 1`
$i+1$ poichè dobbiamo spostare tutti i blocchi più grandi del blocco che dobbiamo inserire a destra di 1 blocco 

###### 4 

Le restanti istruzioni hanno complessità comparabile a $O(1)$

La complessità finale sarà quindi la somma delle complessità dei vari elementi ossia :
$$T(n)=O(1)+i\cdot d+O(n)+(n-i+1)\cdot d$$
$$=O(1)+n\cdot d +d+O(n)$$
$$=O(n)$$

Infatti poichè l'algoritmo non potrà mai spostare più di $n$ elementi possiamo essere sicuri che $n$ rappresenta il limite superiore della complessità
#### Delete

##### Code

```c
delete(Dizionario A, Key K)
	i = search_index(A , K , 1 , A.legth)
	for j = i to A.length - 1
		A[j] = A[j+1]
	reallocate(A , A.length - 1)
	A.length = A.length - 1
```

##### Complexity

###### 1

```c
i = search_index(A , K , 1 , A.legth)
```

Facciamo uso dell'algoritmo di `search_index()` ( ricerca binaria ) per trovare la chiave da eliminare all'interno dell'array

Questa parte della `delete()` ha come complessità quella già calcolata in precedenza ossia $\Theta(\log n)$

###### 2

```c
for j = i to A.length - 1
	A[j] = A[j+1]
```

Il ciclo *for* si occupa di shiftare a sinistra gli elementi dell'array che si trovano dopo l'elemento da eliminare 

Il ciclo *for* viene eseguito $(n-1)-i+1 = n-1$ volte , il suo corpo ha un costo arbitrario di esecuzione di $d$ , avremo quindi che la complessità totale del ciclo è : 
$$(n-i)\cdot d$$
###### 3

```c
reallocate(A , A.length - 1)
```

La reallocate ha come complessità $\Theta(n)$

La *complessità* dell'intero algoritmo sarà quindi :
$$T(n)=\Theta(\log n)+(n-i)\cdot d + O(n)=O(n)$$
Poichè $n$ risulta essere il limite superiore della nostra coplessità ( bisogna sempre considerare il caso peggiore )

#### Reallocate

`reallocate(array A)`

La *riallocazione* della memoria in un array avviene secondo la seguente tecnica :

Si adotta la tecnica del *dimezzamento* e *raddoppiamento* , ossia si vuole mantenere in memoria un array la cui dimensione $h$ risulta essere :
$$n\le h \lt 4\cdot n$$
Avremo quindi un array nelle cui prime $n$ celle dell'array vengono contenuti gli elementi della collezione che vogliamo memorizzare , il contenuto delle altre celle è indefinito

La dimensione $h$ dell'array si sviluppa nel seguente modo :
+ con $n=0$ , $h=1$
+ Ogni qualvolta che l'array supera $h$ elementi di dimensione , la dimensione dell'array viene raddoppia :  $h=h\cdot 2$ 
+ Se la dimensione dell'array diminuice e scende al di sotto di $\frac h 4$ allora la sua dimensione viene dimezzata : $h = \frac h 2$


Lo spazio che quindi occupa risulta essere $\Theta(n)$

### Analisi Ammortizzata

L'*analisi ammortizzata* ci permette di determinare il costo medio di un insieme di $m$ operazioni su una struttura dati

Esempio con `insert()`

Assumiamo di partire con un vettore iniziale di dimensione $h=1$ ( $n=0$ di conseguenza ) , volgiamo svolgere $n$ `insert()` 

Sia $C_i$ il costo dell'$i$-esimo `insert()` 
$$T(n) = \begin{cases} i &\text{se } \exists \ k  : i=2^k+1 \\ 1 &\text{altimenti ( la maggior parte dei casi ) } \end{cases}$$

>[!todo]

## Implementazione attraverso Liste doppiamente concatenate

I dizionari si possono implementare attraverso una collezione L di $n$ record contenenti le seguenti informazioni : 
+ `Key` : La chiave
+ `Info` : L'infromazione relativa alla chiave
+ `next` : puntatore al record sucessivo
+ `prev` : puntatore al precedente record

Inoltre la collezione L contiene un attributo `{c}L.head` contente un puntatore al primo elemento del dizionario , la lista vuota viene codificata con : `{c}L.head == NIL`

La complessità spaziale sarà : $S(n)=\Theta(n)$

#### Insert

##### Code 

```c
insert(Dizionario L , Info v , Key K)
	// creo nuovo record p con valore v e chiave k
	p.next = L.head;
	if(L.head!=NIL)
		L.head.prev = p
	p.prev = NIL
	L.head = p
```

##### Complexity

L'algoritmo aggiunge un elemento in testa ad una lista doppiamente concatenata , in questo caso a differeneza dell'`insert()` nel caso degli array non aggiorniamo il valore di una chiave se già presente nella lista

L'algoritmo risulta avere complessità : $\Theta(1)$ 
Poichè consiste in un insieme di operazioni di assegnamento 
#### Search

##### Code

```c
search(Dizionario L, Key K)
	x = L.head
	while x != NIL and x.Key != K
		x = x.next
	if x != NIL
		return x.Info
	else 
		return NIL
```

##### Complexity

L'algoritmo rappresenta una scansione lineare di tutti gli elementi della lista doppimente concatenata , ritornando l'informazione relativa alla key cercata se presente `NIL` altrimenti 

La sua complessità risulterà essere :
$$T(n)=O(n)$$
Poichè nel caso peggiore ( non è presente la key cercata o è nell'ultimo nodo della lista ) dobbiamo scorrere l'intera lista con $n$ elementi 
##### Correctness

Verifichiamo ora la correttezza del precedente algoritmo :
Perchè possiamo dichiarare che l'algoritmo è corretto esso ci deve garantire di ritornare la prima occorrenza della chiave $K$

Questo può essere provato dimostrando la persistenza di un *invariante* all'interno del ciclo `while`
Un'**invariante** è una formula che deve essere vera prima , dopo e durante tutta l'esecuzione del ciclo

Dovremo quindi dimostrare l' :
+ **Inizializzazione** : l'invariante è vero prima della prima iterazione del ciclo 
+ **Conservazione** : 
	se l'invariante è vero prima di un'iterazione del ciclo rimane vero prima della successiva iterazione :
	$$INV \land \text{Guardia ( Condizione del ciclo )} \implies INV[\text{ dopo esecuzione del corpo del ciclo }]$$
+ **Conclusione** :
	Quando il ciclo termina l'*invarainte* fornisce una prorpietà che aiuta a dimostrare la correttezza dell'algoritmo :
	$$INV \land \ \lnot \ \text{Guardia}\implies \text{Assegnazione Finale}$$
	Ci deve permettere di dimostrare che alla fine ci venga restituito il valore corretto
+ **Funzione di Terminazione** : 
	E' una funzione a valori naturali che decresce strettamente ad ogni iterazione del ciclo 
	Questa ad un certo punto arriverà a 0 : il ciclo necessariamente termina

###### Search

Possiamo quindi indicare per il nostro caso come *invariante* :
	Gli elementi da `L.head` ad `x` escluso hanno chiave differente da `K`
Mentre come *funzione di terminazione* :
	Il numero di elementi della lista non ancora visitati

+ **Inizializzazione** :
	All'inizio viene posto `x=L.head` , l'*invariante* è vera poichè ci sono 0 elementi tra `L.head` e `x` non compreso , quindi non possiamo aver già trovato l'elemento con chiave `K` ( l'asserzione è vacuamente vera )
+ **Conservazione** :
	$$INV\land\ \text{Guardia} \implies INV\bigg[\frac{x.next}{x}\bigg]$$
	Per ipotesi sappiamo : 
	1. *Invariante vero* : gli elementi da `L.head` ad `x` non compreso hanno chiave diversa da `K` 
	2. *Guardia vera* : `x!=NIL && x.Key == K`
	Dobbiamo quindi dimostrare la tesi :
	3. $INV\big[\frac{x.next}{x}\big]$ : gli elementi da `L.head` ad `x.next` non compreso hanno chiave diversa da `K`

	Per ipotesi ( 1. ) gli elementi da `L.head` a `x` non compreso hanno chiave divrsa da `K` , inoltre per ipotesi ( 2. ) l'elemento puntato da `x` ha chiave diversa da `K`
	Abbiamo quindi dimostrato che tutti gli elementi da `L.head` ad `x` *compreso* hanno chiave diversa da `K`
+ **Conclusione** :
	$$INV\land \ \lnot \text{Guardia}\implies \text{Asserzione finale}$$
	Il ciclo termina quando : 
	+ `x==NIL` : abbiamo terminato gli elementi della lista , alla fine l'*invarainte* rimane vero quindi possiamo concludere che l'elemento cercato non appartiene alla lista
	+ `x!=NIL && x.Key == K` : siccome l'*invariante* ci assicura che `K` non è presente prima di `x` , `x` sarà dunque la prima occorrenza della chiave `K`
#### Delete

##### Code

```c
delete(Dizionario L, Key K)
	x = L.head
	while x != NIL
		if x.Key == K
			if x.next != NIL
				x.next.prev = x.prev
			if x.prev != NIL
				x.prev.next = x.next
			else 
				L.head = x.next
			temp = x
			x = x.next 
			// rimuovi temp
		else 
			x=x.next
```

##### Complexity

Poichè l'`insert()` non aggiorna le occorrenza di `K` ci saranno più chiavi con `info` differenti , bisognerà quindi scorrere l'intero dizionario `L` per rimuovere tutte le occorrenze della chiave `K`

Se lungo la ricerca si trova un elemento avente la chiave cercata , sistemeremo i puntatori degli elementi precedente e sucessivo ( se presenti ) e infine elimineremo l'elemento dalla lista

Poichè l'algoritmo deve scorrere tutti gli elementi della lista la complessità risulterà lineare rispetto al numero degli elementi 
$$T(n)=\Theta(n)$$
# Alberi 

**Albero radicato** :
	è una coppia $T=(N,A)$ dove :
		$N$ è un insieme finito di **nodi** fra cui si distingue un nodo $r$ detto radice 
		$A \subseteq N \times N$ è un insieme di coppie di nodi detti *archi* 
	In un albero ogni nodo $v$ ( eccetto la radice ) ha esattamente un *genitore* ( o *padre* ) $u$ tale che esiste un arco ( $u , v$ ) $\in A$

## Definizioni

+ Un nodo $n$ può avere zero o più figli $v$ tali che esiste un arco $(u,v)\in A$
+ Il numero di figli di un nodo è detto *grado* del nodo
+ Un nodo senza figli ( grado 0 ) è detto *foglia*
+ Un nodo non foglia è detto *nodo interno*
+ Se due nodi hanno lo stesso padre sono detti *fratelli*
+ Il *cammino* da un nodo $u$ a un nodo $u'$ i un albero $T$ è una sequenza di nodi $<n_0,n_1,\dots,n_k>$ tali che : 
	+ $u=n_0$
	+ $u'=n_k$
	+ $<n_{i-1},n_i>\ \in A\ \forall\ i = 1,\dots,k$
+ La *lunghezza* di un cammino è il numero degli archi del cammino , o il numero di nodi che formanoil cammino meno 1
	+ Esiste sempre un cammino di lunghezza zero che va da $u$ a $u$
+ Sia $x$ un nodo in un albero radicato $T$ con radice $r$ . Un nodo qualsiasi , $y$ , in un cammino che parte da $r$ e arriva a $x$ è detto *antenato* di $x$
	+ Ogni nodo è antenato di sè stesso
+ Se $y$ è antenato di $x$ , allora $x$ è *discendente* di $y$ 
	+ Ogni nodo è discendendo di sè stesso
+ Se $y$ è un antenato di $x$ e $x$ è diverso da $y$ , allora $y$ è un *antenato proprio* di $x$ , e $x$ è un *discendente proprio* di $y$
+ Il *sottoalbero* con radice in $x$ è l'albero indotto dai discendenti di $x$ 
+ La *profondità* di un nodo $x$ è la lunghezza del cammino dalla radice a $x$
+ Un *livello* di un albero è costituito da tutti i nodi che stanno alla stessa profondità
+ L'*altezza* di un nodo è la lunghezza del più lungo cammino che scende dal nodo $x$ a una foglia
	+ L'altezza di un albero è l'altezza della sua radice ed è anche uguale alla profondità massima di un qualsiasi nodo dell'albero

## Alberi binari e alberi $k$-ari

Un *albero binario* è un albero definito in modo ricorsivo 

Caso Base :
+ Un albero vuoto è un albero binario
Passo ricorsivo :
+ Un albero costituito da un nodo radice , da un albero binario ( sottoalbero sinistro della radice ) e da un albero binario ( sottoalbero destro della radice ) è un albero binario

Un *albero $k$-ario* è un albero in cui i figli di un nodo sono etichettati con interi positivi distinti e le etichette maggiori di $k$ sono assenti ( ossia ogni nodo può avere al massimo $k$ figli )  

>[!note]
>Un albero binario è un caso particolare di un albero $k$-ario , avente $k = 2$
>

Un *albero $k$-ario completo* è un albero $k$-ario in cui vslgono le seguenti caratteristiche :
+ Tutte le foglie hanno la stessa profondità
+ Tutti i nodi interni hanno grado $k$ ( hanno esattamente $k$ figli )

**Esempio** :

![[Strutture Dati 2023-11-15 13.29.53.excalidraw]]

### Esercizio

Trovare il numero di foglie e il numero di nodi interni di un albero $k$-ario completo , la cui altezza risulta essere $h$ 

>[!todo]
>completa esercizi ( pag 59 60 pdf asd )

## Tipo Albero

### Dati

Un insieme di nodi ( di tipo `Node` ) e un insieme di archi

### Operazioni

1. `{c} newtree() -> Tree`
	+ Post-condizione : restituisce un albero vuoto
2. `{c}treeEmpty(Tree P) -> bool`
	+ Post-condizione : restituisce `true` se l'albero è vuoto `false` altrimenti
3. `{c}padre(Tree P, Node v) -> Node U , {NIL}`
	+ Pre-condizione : $v \in P$
	+ Post-condizione : restituisce il padre di $v$ se $v$ è diverso dalla radice , `NIL` altrimenti
1. `{c}figli(Tree P, Node v) -> List of Node`
	+ Pre-condizione : $v \in P$
	+ Post-condizione : restituisce una lista contenente i figli del nodo $v$

## Alberi impementati con array

### Vettore padri

L'implementazione con gli array prevede l'utilizzo di un vettore di coppie che rappresentano i singoli nodi , coppie costituite da `(info , parent)` in cui :
+ `info` : informazione contenuta nel nodo
+ `parent` : indice del suo nodo padre

**Esempio** :

Sia $T=(N, A)$ un albero con $n$ nodi numerati da 0 a $n-1$ rappresentabile come segue :

![[VettorePadri.excalidraw]]

Questo può quindi essere rappresentato nel seguente modo :

|P.info|A|B|C|D|E|F|G|H|I|
|-|-|-|-|-|-|-|-|-|-|
|P.parent|-1|0|0|0|1|1|3|6|6|
|Indice|0|1|2|3|4|5|6|7|8|

#### Proprietà 

+ $\forall\ v \in [0 , n-1]$
	+ `P[v].info` : è l'informazione del nodo
	+ `P[v].parent = u` se e solo se vi è un arco $(u,v)\in A$ 
+ Se $v$ è la radice avremo che : `P[v].parent = -1`
+ `P.length` contiene il numero di nodi dell'albero 
+ Spazio richiesto : $S(n)=\Theta(n)$ per un albero contenente $n$ nodi
#### Operazioni

##### padre

**Code** :

```c
padre(Tree P, Node v)
	if P[v].parent == -1
		return NIL
	else 
		return P[v].parent
```

**Complessità** :

Essendo solo operazioni di ritorno e if ( entrambi a complessità costante ) la comlessità totale sarà :
$$
T(n)=\Theta(1)
$$
##### figli

**Code** :

```c
figli(Tree P, Node v)
	l = crealista()
	for i = 0 to P.length - 1
		if P[i].parent == v
			// inserisci i nella lista l
	return l
```

**Complessità** :

Il ciclo *for* viene svolto $n$ volte ( l'intera lunghezza dell'array ) , le altre operazioni sono a complessità costante ( consideriamo a complessità costante anche l'inserimento a righa 5 ) avremo quindi una complessità totale :
$$
T(n)=\Theta(n)
$$
### Vettore posizionale

Supponiamo di avere un albero $k$-ario completo con $k\ge2$ , ogni nodo di questo albero avrà una posizione prestabilita all'interno dell'array

Avremo quindi $P$ vettore di dimensione $n$ tale che `P[v]` contiene l'informazione associata al nodo $v$  

#### Proprietà 

+ 0 è la posizione della radice 
+ L'$i$-esimo *figlio* di $v$ è in posizione $k\cdot v +1 +i ,\ \ i\in\{0,\dots,k-1\}$
+ Il *padre* del nodo $f$ ( con $f \not= 0$ ) è in posizione 
	$$
	k\cdot v +1\ \text{(primo figlio)}\le f\le k\cdot v +1 +(k-1)\ \text{(ultimo figlio)}
	$$
	$$
	k\cdot v \le f -1 \le k\cdot v + k +1
	$$
	$$
	v \le \frac{f-1}{v}\le v + \frac{k-1}{k}
	$$
	Poichè $\frac{k-1}{k}$ è minore di $1$ , la frazione potrà essere sostituita con 1 visto che essendo maggiore della frazione presente in precedenza il $\frac{f-1}{v}\le$ sarà ancora valido
	$$
	v \le \frac{f-1}{v}\le v + 1
	$$


	Essendo infine che $v$ è un indice e quindi un numero intero risulterà che :
	$$
	v =\bigg\lfloor \frac{f-1}{k} \bigg\rfloor
	$$

**Esempio** : 

![[VettorePosizionale.excalidraw]]

Vettore Posizione

|Info|a|b|c|d|e|f|g|h|i|l|m|n|o|
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Index|0|1|2|3|4|5|6|7|8|9|10|11|12|

Gli indici dei figli di `a` ,`b,c,d` , possono essere calcolati attraverso la formula $k\cdot v +1 +i$ dove :
+ $k$ sono il numero di figli 
+ $v$ è l'indice del nodo per il quale vogliamo trovare i figli
+ $i$ è un indice che va da : $i \in \{0,\dots,k-1\}$

Gli indici dei figli di `a` saranno quindi : $3\cdot 0 +1 +i$
`b` = $3\cdot0+1+0=1$ 
`c` = $3\cdot0+1+1=2$
`d` = $3\cdot0+1+2=3$

Gli indici dei figli di `c` saranno quindi : $3\cdot 2 +1 +i$
`h` = $3\cdot2+1+0=7$ 
`i` = $3\cdot2+1+1=8$
`l` = $3\cdot2+1+2=9$

Volendo invece calcolare l'indice del padre di `i` avremo la seguente formula :
$$
\bigg\lfloor \frac{f-1}{3} \bigg\rfloor
$$
Dove $f$ reppresenta l'indice del figlio ( per `i` $f=8$ ) , avremo quindi

$$
\bigg\lfloor \frac{8-1}{3} \bigg\rfloor = 2
$$

Lo spazio necessario 

# Alberi Binari di Ricerca

# Esercizi 

## Complessità 

## Alberi 