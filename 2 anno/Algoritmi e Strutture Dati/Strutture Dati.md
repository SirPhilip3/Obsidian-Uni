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
>completa ( pag 41 pdf asd )
>#todo

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
>#todo

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

| P.info | A | B | C | D | E | F | G | H | I |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| P.parent | -1 | 0 | 0 | 0 | 1 | 1 | 3 | 6 | 6 |
| Indice | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
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

Lo spazio necessario per un albero con $n$ nodi è $\Theta(n)$ , la struttura dati contiene i seguenti campi : 
+ `P.length` : il numero di nodi
+ `P.K` : il grado di tutti i nodi

#### Operazioni

##### padre

```c
padre(Tree P, Node v) // v è un indice
	if v == 0
		return NIL
	else 
		return floor((v-1)/P.K)
```

**Complessità** : $O(1)$  ( la funzione `floor` ha complessità costante )
##### figli

```c
figli(Tree P, Node v)
	l = createlista()
	if v * P.K + 1 >= P.length
		return l // lista vuota poichè il nodo non ha figli
	else 
		for i = 0 to P.K - 1
			// inserici v*P.K+1+i in l
		return l 
```

**Complessità** : $\Theta(\text{grado}(v))=O(K)$ 
La complessità è $O$ poichè potremmo essere fortunati ed essere in una foglia 

Le rappresentazioni con i vettori hanno lo svantaggio che le operazioni di inserimento e cancellazione sono costose poichè dobbiamo spostare degli elementi in memoria

## Alberi implementati con strutture collegate

Possiamo rappresentare un albero facilente attraverso la definizione di un record che contiene 
+ L'informazione associata 
+ Un puntatore al padre
+ Altri puntatori ( per accedere ai figli )

### Puntatori ai Figli 

Se ogni nodo ha grado al più $k$ possiamo mantenre in ogni nodo un puntatore a ciascuno dei possibili $k$ figli 

Supponendo di avere un albero binario ( $k=2$ ) ogni nodo dell'ablero avrà :
+ `x.p` : puntatore al padre 
+ `x.left` : puntatore al figlio sinistro
+ `x.rigth` : puntatore al figlio destro
+ `x.Key` : informazione del nodo

**Esempio** :

![[PointerFigli.excalidraw]]

Definiamo un albero `T` avente come campo `T.root` , un puntatore puntatore alla radice dell'albero

Lo spazio richiesto da questa implementazione è $\Theta(n\cdot k)$ , se $k$ è costante avremo $\Theta(n)$ 

#### Operazioni

##### Padre

```c
padre(Tree P, Node v)    // v è un puntatore
	return v.p
```

**Complessità** : $O(1)$

##### Figli

```c
figli(Tree P, Node v) // funziona per un albero binario
	l = crealista()
	if v.left != NIL
		// inserisci v.left in l
	if v.rigth != NIL
		// inserisci v.rigth in l
	return l
```

**Complessità** : $O(1)$  ( solo if )

#### Svantaggi 

In presenza di un $k$ grande la maggior parte dei puntatori ai figli saranno `NIL` , ciò comporta un grande spreco di memoria , infatti questa struttura si utilizza principalmente per alberi *binari*

### Figlio sinistro - Fratello destro

Questa struttura dati è più adatta ad alberi generali in quanto c'è meno spreco di spazio ( meno puntatori a `NIL` )

Ogni nodo `x` ha i seguenti campi :
+ `x.Key` : contiene l'informazione del nodo
+ `x.p` : puntatore al padre
+ `x.left_child` : puntatore al figlio più a sinistra di `x` ( se è `NIL` `x` è un nodo foglia )
+ `x.rigth_sib` : puntatore al fratello di `x` immediatamente alla sua destra ( se è `NIL` `x` è il figlio più a destra del padre )

**Esempio**

![[FigliFratelli.excalidraw]]

#### Operazioni

##### Padre

```c
padre(Tree P, Node v)
	return v.p
```

**Complessità** : $O(1)$
##### Figli

```c
figli(Tree P, Node v)
	l = crealista()
	iter = v.left_child
	while iter != NIL
		// inserisci iter in l
		iter = iter.rigth_sib
	return l
```

**Complessità** : $\Theta(\text{grado}(v))=\Theta(k)$
	Questo poichè il numero di volte che svolgiamo il corpo del `{c}while` dipende dal numero di figli ( o $\text{grado}$ del nodo $v$ )

### Algoritmi di visita degli alberi

#### Visita generica

```c
visitaGenerica(Node r)
	S = {r}
	while S != emptySet
		// estrai un nodo n da S
		// visita il nodo n
		S = S U {figli di n}
```

**Teorema** :
	L'algoritmo di visita applicato alla radice di un albero con $n$ nodi termina in $O(n)$ iterazioni , lo spazio necessario da allocare ad $S$ è $O(s)$

**Dimostrazione** :
	Assumiamo l'ipotesi che la cancellazione e l'inserimento da $S$ siano costanti
	Ogni nodo verrà inserito ed estratto da $S$ *una sola volta* poichè in un albero non si può tornare ad un nodo a partire dai suoi figli se lo stiamo scorrendo di figlio in figlio 
	Quindi le iterazioni del ciclo `{c}while` saranno al più $O(n)$
	Poichè ogni nodo compare al più una volta in $S$ lo spazio richiesto è $O(n)$  
#### Visita in profondità - Depth-First Search ( DFS )

##### Versione Iterativa

Per questo algoritmo utilizzeremo una struttura dati a pila/stack $S$ dotata di politica *LIFO*

```c
visitaDFS(Node r)
	Stack s
	s = newStack()
	push(S, r)
	while not stack.empty(S)
		u = pop(S)  // estrazione
		if u != NIL
			// visita il nodo u
			push(S, u.rigth)
			push(S, u.left)
```

**Complessità** : 
	Poichè devo visitare tutti i nodi dell'albero avrò una complessità lineare ossia $\Theta(n)$
###### Spiegazione :

Esempio di svolgimento sul seguente albero :

![[TestTree.excalidraw]]

Inizialmente avremo :
+ `{C}s = {'A'}`

Entriamo nel `{c}while` poichè lo stack non è vuoto

1° ciclo :
+ `{c}u='A'  // s = {NIL}`
+ `//visit 'A'`
+ `{c}s={'B'} // 1° push `
+ `{c}s={'B','L'} // 2° push`

2° ciclo :
+ `{c}u='L'  // s = {'B'}`
+ `//visit 'L'`
+ `{c}s={'B','R'} // 1° push `
+ `{c}s={'B','R','E'} // 2° push`

3° ciclo :
+ `{c}u='E'  // s = {'B','R'}`
+ `//visit 'E'`
+ `{c}s={'B','R'} // 1° push non ho figli dx`
+ `{c}s={'B','R'} // 2° push non ho figli sx`

4° ciclo :
+ `{c}u='R'  // s = {'B'}`
+ `//visit 'R'`
+ `{c}s={'B'} // 1° push non ho figli dx`
+ `{c}s={'B'} // 2° push non ho figli sx`

5° ciclo :
+ `{c}u='B'  // s = {NIL}`
+ `//visit 'B'`
+ `{c}s={'O'} // 1° push `
+ `{c}s={'O'} // 2° push non ho figli sx`

6° ciclo :
+ `{c}u='O'  // s = {NIL}`
+ `//visit 'O'`
+ `{c}s={NIL} // 1° push non ho figli dx`
+ `{c}s={NIL} // 2° push non ho figli sx`

7° ciclo :
Il ciclo `{c}while` termina poichè lo stack è vuoto , abbiamo visitato tutti i nodi a partire dal nodo radice
La vista finale sarà : `A,L,E,R,B,O`
##### Versione Ricorsiva

```c
visitaDFS_rec(Node r)
	if r != NIL
		// visita il nodo r
		visitaDFS_rec(r.left)
		visitaDFS_rec(r.rigth)
```
##### Dimostrazione

**Teorema** :
	Se $x$ è la radice di un sottoalbero di $n$ nodi la chiamata di `visitaDFS_rec(x)` richiede un tempo $\Theta(n)$

**Dimostrazione** :
	$T(n)$ è il tempo di esecuzione della procedura quando è chiamata per la radice di un sottoalbero di $n$ nodi 
	Poichè `visitaDFS_rec` visita tutti gli $n$ nodi del sottoalbero avremo che  $T(n)=\Omega(n)$ 
	La complessità totale sarà :
	$$
	T(n) = \begin{cases} 0 & n=0 \\ T(k)+T(n-k-1)+d & n \gt 0 \end{cases}
	$$
Dove :
+ $k$ : è il numero di nodi del sottoalbero sinistro
+ $n-k-1$ : è il numero di nodi del sottoalbero destro
+ $d$ : tempo necessario per la visita del nodo ( costante )

>[!warning]
>$T(n)\ne2\cdot T(\frac n 2)$
>Questo avviene solo se i sotttoalberi destri e sinistri sono perfettamente distribuiti ( l'albero è bialanciato ) 

Non essendo nella forma in cui la ricorsione può essere risolta con il teorema *Master* utilizziamo il *metodo di sostituzione*

**Intuizione** :
	La complessità è *lineare* ( $\Theta(n)$ )
	Supponiamo quindi che $T(n)=a\cdot n +b$ ( se esistono degli assegnamenti per $a$ e $b$ allora possiamo dire che la complessità è *lineare* )

Procediamo quindi alla dimostrazione per *induzione completa* su $n$

**Caso Base** :
	Con $n=0\implies T(0)=c$ per definizione possiamo dire che :
	$$T(0)=a\cdot n + b=a\cdot 0 +b = b$$
	Ponendo infine $b=c$ abbiamo verificato il *caso base*

**Passo induttivo** :
	Assumiamo che per ogni $m\lt n$ vale che $T(m)=a\cdot m +b$ 
	Lo dimostro per $n$ 
	$$
	T(n)=T(k)+T(n-k-1)+d
	$$
	$$
	= ak+b+a(n-k-1)+b+d \quad \text{sostituendo}
	$$
	$$
	=ak+b+an-ak-a+b+d
	$$
	$$
	=an-a+2b+d
	$$
	Vogliamo dimostrare che $an-a+2b+d=an+b$
	$$
	an-a+2b+d=an+b
	$$
	$$
	-a+b+d=0 \implies a=b+d
	$$
	$$
	a=c+d\quad \text{poichè per il caso base abbiamo che $b=c$}
	$$
	Sostituendo infine nell'equazione originale abbiamo :
	$$
	T(n)=(d+c)n+c \quad \text{sostituendo b con c}
	$$
	Abbiamo così dimostrato che anche per $n\gt m$ è valido che il tempo di esecuzione è lineare

La procedura `visitaDFS_rec` ha quindi tempo di esecuzione $T(n)=\Theta(n)$

#### Visite di alberi binari

In base alla posizione dell'operatore di visita all'interno di `visitaDFS_rec` abbiamo diverse tipologie di visite 
##### Visita anticipata ( in preordine )

Si vista prima la radice poi si fanno le chiamate ricorsive

**Code** :
```c
visitaDFS_rec(Node r)
	if r != NIL
		// visita il nodo r
		visitaDFS_rec(r.left)
		visitaDFS_rec(r.rigth)
```

**Esempio** :
	Se applichiamo questo algoritmo sull'albero visto in precedenza avremo che verrà visitato nel seguente modo :
	`A,L,E,R,B,O`

##### Visita simmetrica ( in ordine )

Prima si fa la chiamata ricorsiva sul figlio sinistro , sucessivamente si visita la radice ed infine si fa la chiamata ricorsiva sul figlio destro

**Code** :
```c
visitaDFS_rec(Node r)
	if r != NIL
		visitaDFS_rec(r.left)
		// visita il nodo r
		visitaDFS_rec(r.rigth)
```

**Esempio** :
	Se applichiamo questo algoritmo sull'albero visto in precedenza avremo che verrà visitato nel seguente modo :
	`E,L,R,A,B,O`
##### Visita posticipata ( in postordine )

Prima si fa la chiamata ricorsiva sul figlio sinistro e destro ed infine si visita la radice

**Code** :
```c
visitaDFS_rec(Node r)
	if r != NIL
		visitaDFS_rec(r.left)
		visitaDFS_rec(r.rigth)
		// visita il nodo r
```

**Esempio** :
	Se applichiamo questo algoritmo sull'albero visto in precedenza avremo che verrà visitato nel seguente modo :
	`E,R,L,O,B,A`

#### Visita in ampiezza - Breadth-First Search ( BFS )

Questo algoritmo ci permette di visitare tutti i nodi presenti alla corrente profondità di un albero prima di scendere e visitare i nodi delle profondità inferiori

Verrà utilizzata una struttura dati queue con politica *FIFO*

```c
visitaBFS(Node r)
	Queue C
	C = newQueue()
	enqueue(C, r)
	while not queueEmpty(C)
		u = dequeue(C)
		if u != NIL
			// visita il nodo u
			enqueue(C, u.left)
			enqueue(C, u.right)
```

**Complessità** : 
	Per il teorema precedente la complessità è $\Theta(n)$

##### Spiegazione

Eseguiamo l'algoritmo sull'albero percedente

Inizialmente avremo :
+ `{C}C = {'A'}`

Entriamo nel `{c}while` poichè la queue non è vuota

1° ciclo :
+ `{c}u='A'  // s = {NIL}`
+ `//visit 'A'`
+ `{c}s={'L'} // 1° enqueue `
+ `{c}s={'L','B'} // 2° enqueue`

2° ciclo :
+ `{c}u='L'  // s = {'B'}`
+ `//visit 'L'`
+ `{c}s={'B','E'} // 1° enqueue `
+ `{c}s={'B','E','R'} // 2° enqueue`

3° ciclo :
+ `{c}u='B'  // s = {'E','R'}`
+ `//visit 'B'`
+ `{c}s={'E','R','O'} // 1° enqueue `
+ `{c}s={'E','R','O'} // 2° enqueue non ho figli dx`

4° ciclo :
+ `{c}u='E'  // s = {'R','O'}`
+ `//visit 'E'`
+ `{c}s={'R','O'} // 1° enqueue non ho figli sx`
+ `{c}s={'R','O'} // 2° enqueue non ho figli dx`

5° ciclo :
+ `{c}u='R'  // s = {'O'}`
+ `//visit 'R'`
+ `{c}s={'O'} // 1° enqueue non figli sx`
+ `{c}s={'O'} // 2° enqueue non ho figli dx`

6° ciclo :
+ `{c}u='O'  // s = {NIL}`
+ `//visit 'O'`
+ `{c}s={NIL} // 1° enqueue non ho figli sx`
+ `{c}s={NIL} // 2° enqueue non ho figli dx`

7° ciclo :
Il ciclo `{c}while` termina poichè lo stack è vuoto , abbiamo visitato tutti i nodi a partire dal nodo radice
La vista finale sarà : `A,L,B,E,R,O`

# Alberi Binari di Ricerca

## Alberi binari bilanciati

**Definizione** : 
	Un albero binario è bilanciato se la sua altezza risulta essere limitata superiormente da $h=O(\log n)$ 

Un albero *completo* è un albero *bilanciato* ma un albero bilanciato non è necessaraimente completo

**Esempio** :

![[BilanciatoNotComplete.excalidraw]]
Albero bilanciato ma non completo

![[Unbalanced.excalidraw]]
Albero fortemente sbilanciato in cui $h=n-1$

## Alberi binari di ricerca

**Definizione** :
	Un *albero binario di ricerca* è un albero binario che soddifa la *proprietà di ricerca*

**Proprietà di ricerca** :
+ Sia $x$ un nodo di un albero binario di ricerca. Se $y$ è un nodo nel sottoalbero sinistro di $x$ , allora $y.Key \le x.Key$
+ Se $y$ è un nodo nel sottoalbero destro di $x$ allora $y.Key \ge x.Key$ 

**Esempio** :

![[BinarySearchS.excalidraw]]
Questo è un corretto albero binario di ricerca

![[BinarySearchN.excalidraw]]
Questo non è un albero binario di ricerca poichè la foglia con valore 11 e maggiore del valore del nodo radice

La *proprietà di ricerca* ci permette di elencare in modo non decrescente ( strettamente crescente ) le chiavi di un albero binario di ricerca visitando l'albero in ordine *simmetrico*

**Esempio**

```c
if u != NIL
	visita(u->left)
	print(u->Key)
	visita(u->right)
```

![[Research.excalidraw]]

### Operazioni

#### Ricerca

`{c}Tree_search(Node x, Elem k) -> Node U NIL`

Post-condizione : restituisce un nodo con chiave $k$ se estiste , $NIL$ altrimenti
##### Versione ricorsiva
```c
Tree_search(Node x, Elem k)
	if x == NIL or x.Key == k
		return x
	else 
		if x.Key > k
			return Tree_search(x.left, k)
		else 
			return Tree_search(x.rigth, k)
```
##### Versione iterativa
```c
Tree_search_iter(Node x, Elem k)
	while x != NIL and x.Key != k
		if k < x.Key
			x = x.left
		else 
			x = x.rigth
```

##### Correttezza

Possiamo tagliare lo spazio di ricerca perchè la proprietà degli alberi binari di ricerca assicura che nel sottoalbero destro non ci sono nodi con chiavi minori di `x.Key`.
In maniera analoga si taglia il sottoalbero sinistro perchè la proprietà degli alberi binari di ricerca assicura che nel sottoalbero sinistro non ci sono nodi con chiavi maggiori di `x.Key`.
##### Complessità

I nodi incontrati durante la ricorsione formano un cammino verso il basso a partire dalla radice dell'albero quindi il tempo di esecuzione è al massimo l'altezza dell'albero ossia $O(h)$ 
+ Se l'albero è bilanciato : $T(n)=O(\log n)$
+ Se l'albero è fortemente sbilanciato ( catena di nodi ) : $T(n)=O(n)$

La complessità è identica sia per il modello ricorsivo che iterativo , quest'ultimo però risulta più veloce in pratica poichè non vi sono chiamate a funzione da svolgere 
#### Massimo

`{c}Tree_max(Node x) -> Node`

+ Pre-condizione : $x\in T$
+ Post-condizione : ritorna il nodo con chiave più grande nel sottoalbero radicato in $x$

```c
Tree_max(Node x)
	while x.right != NIL
		x = x.right
	return x
```

Il massimo si troverà andando sempre a destra nell'albero poichè il nodo finale dovrà per forza essere maggiore di tutti i nodi precedenti ( è sicuramente maggiore dei nodi di sinistra ) per via della *prorpietà di ricerca*
#### Minimo

`{c}Tree_min(Node x) -> Node`

+ Pre-condizione : $x\in T$
+ Post-condizione : ritorna il nodo con chiave più piccola nel sottoalbero radicato in $x$

```c
Tree_min(Node x)
	while x.left != NIL
		x = x.left
	return x
```

Il minimo si troverà andando sempre a sinistra nell'albero poichè il nodo finale dovrà per forza essere minore di tutti i nodi precedenti ( è sicuramente minore dei nodi di destra ) per via della *prorpietà di ricerca*
##### Correttezza

Se un nodo $x$ non ha un sottoalbero sinistro allora poichè ogni chiave nel sottoalbero destro è almeno grande come `x.Key` la chiave minima è proprio `x.Key`

Se $x$ ha un sottoalbero sinistro allora nessuna chiave nel sottoalbero destro può essere più piccola di `x.Key` e ogni chiave nel sottoalbero sinistro non è maggiore di `x.Key` . Dunque il minimo lo trovo nel sottoalbero sinistro
##### Complessità

Il tempo di esecuzione è $O(h)$ perchè la sequenza di nodi visitati forma un cammino che scende dalla radice e può avere lunghezza massim $h$

#### Sucessore

Dato un albero binario di ricerca, voglio determinare dato un nodo il suo sucessore nell'ordine stabilito in una visita simmetrica 
Se tutte le chiavi sono distinte il sucessore di un nodo $x$ è il nodo con la più piccola chiave che è maggiore di `x.Key`

Distinguiamo 2 casi : 
+ $x$ ha un figlio destro 
	+ In questo caso il sucessore è il minimo del sottoalbero destro di $x$
	**Esempio** :
	![[SuccessorWithRChildren.excalidraw]]
+ $x$ non ha un figlio destro
	+ In questo caso , se esiste ( perchè $x$ potrebbe essere il massimo ) , il *sucessore* è l'antenato più prossimo di $x$ il cui figlio sinistro è anch'esso antenato di $x$ .
	+ Per trovarlo si risale da $x$ verso la radice fino ad incontrare la prima svolta a destra 
	**Esempio** :
	![[SuccessorWithoutChildrens.excalidraw]]
**Code** :

`{c}Tree_successor(Node x) -> Node`

Pre-condizione : $x\in T$

```c
Tree_successor(Node x)
	if x.right != NIL
		return Tree_min(x.right)
	else 
		y = x.p
		while y != NIL and x == y.right
			x = y
			y = y.p
		return y
```

##### Complessità 

Se `{c}x.right != NIL` viene chiamata `{c}Tree_min()` che ha complessità $O(h)$ 
Altrimenti viene scielto un cammino partendo da $x$ andando vero la radice , anche questo può essere lungo al massimo come l'altezza dell'albero , quindi anche in questo caso la complessità risulta essere $O(h)$

La complessià di questo algoritmo risulta quindi essere $O(h)$
#### Predecessore

Per trovare il *predecessore* il ragionamento è analogo a quello fatto per trovare il *sucessore* ma invertito 

Se $x$ ha un figlio sinistro allora il predecessore sarà il massimo del sottoalbero sinistro di $x$ altrimenti sarà l'antenato più prossimo di $x$ il cui figlio destro è anch'esso antenato di $x$ 
Per trovarlo si risale da $x$ verso la radice fino a incontrare la prima svolta a sinistra 

`{c}Tree_predecessor(Node x) -> Node`

Pre-condizione : $x\in T$

```c
Tree_predecessor(Node x)
	if x.left != NIL
		return Tree_max(x.left)
	else 
		y = x.p
		while y != NIL and x == y.left
			x = y
			y = y.p
		return y
```

Analogamente allo studio del *sucessore* questo algoritmo ha *complessità* $O(h)$
#### Inserimento

L'idea iniziale è quella di ricercare finchè non trovo un `NIL` dove posso fare l'inserimento

**Esempio** : 

![[Insert.excalidraw]]

**Code**

`{c}Tree_insert(Tree T, Node z)`

+ Pre-condizione : 
	$z$ è un nodo avente le seguenti caratteristiche `{c}z.Key = v , z.left = NIL , z.right = NIL`
+ Post-condizione : inserisce il nodo $z$ nell'albero $T$ mantendo la *proprietà di ricerca*

```c
Tree_insert(Tree T, Node z)
	y = NIL    // variabile che usiamo per trovare il padre di z
	x = T.root // varaibile che usiamo per scorrere l'albero 
	while x != NIL
		y = x
		if z.Key < x.Key
			x = x.left
		else 
			x = x.right
	z.p = y 
	if y == NIL // albero vuoto : la radice diventa il nodo z
		T.root = z
	else 
		if z.Key < y.Key
			y.left = z
		else
			y.right = z
```

**Complessità** : 
	Il ciclo `{c}while` costa $O(h)$ , poichè sto scendendo dalla radice la profondità massima a cui potrei scendere è $h$ ; le altre istruzioni sono semplici assegnamenti e non influiscono nella complessità totale

La complessità dell'algoritmo risulta quindi essere : $O(h)$
#### Cancellazione

Prima di costruire un algoritmo teniamo presente la seguente *proprietà* :
##### Proprietà

Se un nodo $x$ in un *albero binario di ricerca* ha 2 figli allora il *sucessore* non ha un figlio sinistro e il suo *predecessore* non ha un figlio destro

###### Dimostrazione

Sia $x$ un nodo con 2 figli allora in una visita simmetrica i nodi del sottoalbero *sinistro precedono* $x$ mentre quelli de sottoalbero *destro seguono* $x$ 

Se $s$ è il sucessore di $x$ assumiamo per assurdo che $s$ abbia un figlio sinistro ( $y$ ) , allora $y$ seguirà $x$ poichè si trova nel sottoalbero destro ma precede $s$ poichè si trova nel suo sottoalbero sinistro .
Questo è assurdo poichè $s$ non sarebbe più il sucessore di $x$ ma lo sarebbe $y$

In modo simmerico questa *proprietà* può essere verificata per il predecessore

##### Algoritmo 

Analizziamo il problema :
Abbiamo il seguente albero :

![[DeleteTree.excalidraw]]

Vogliamo eliminare il nodo $z$ : ci sono 3 casi che possiamo individuare :

1. Se $z$ non ha figli modifichiamo suo padre ( $z.p$ ) per sostituire $z$ con $NIL$ , un esempio sarebbe l'eliminazione del nodo $z=10$ 
	![[TreeDelete1case.excalidraw]]
2. se $z$ ha un unico figlio stacchiamo $z$ creando un collegamento tra suo figlio e suo padre ( `{c}z.figlio.p = z.p` ) , un esempio sarebbe l'eliminazione del nodo $z=18$
	![[TreeDelelte2case.excalidraw]]
3. se $z$ ha 2 figli troviamo il *sucessore* $y$ di $z$ che deve trovarsi nel sottoalbero destro di $z$ e facciamo in modo che $y$ la posizione di $z$ nell'albero , un esempio sarebbe l'eliminazione del nodo $z=15$
	![[TreeDelete3case.excalidraw]]

Dobbiamo avvalerci di una funzione **ausiliaria** che mi permetta di spostare dei sottoalberi all'interno di un albero 

```cpp
// sostituisce il sottoalbero con radice nel nodo u con il sottoalbero con radice nel nodo v
Transplant(Tree T, Node u, Node v){
	if u.p == NIL
		T.root = v // se il nodo che volgio sostituire è root cambio il root dell'albero
	else 
		if u == u.p.left // u figlio sx di suo padre 
			u.p.left = v // v diventa figlio sx di suo padre
		else 
			u.p.rigth = v // u figlio dx
	if v != NIL
		 v.p = u.p
}
```

![[Transplant.excalidraw]]

**Complessità**
$O(1)$ : sono solo assegnamenti 

**Tree_delete**

```cpp
Tree_delete(Tree T, Node z)
	if z.left == NIL
		Transplant ( T , z , z.right ) // comprene il caso in cui z è una foglia  
	else 
		if z.right == NIL
			Transplant ( T , z , z.left ) // ha un solo figlio
		else
			y = Tree_minimun ( z.right ) // trovo il successor
				if y.p != z 
					Transplant ( T , y , y.right ) 
					y.right = z.right 
					z.right.p = y 
				Transplant ( T , z , y ) 
				y.left = z.left 
				y.left.p = y
```

###### Spiegazione

>[!todo]
>add explanation
>#todo

###### Complessità

Poichè tutte le operazioni sono degli assegnamenti dobbiamo considerare la complessità delle funzioni chimate :
+ `{cpp}Transplant(...)` ha complessità $O(1)$
+ `{cpp}Tree_minimum(...)` ha complessità $O(h)$

`{cpp}Transplant(...)` risulta trascurabile come le altre operazioni , la complessità risultante sarà quindi quella relativa alla `{cpp}Tree_minimum(...)` : $O(h)$

Tutti i seguenti algoritmi hanno complessità $O(h)$ : `{cpp}search(...) , minimum(...) , maximum(...) , insert(...) , successor(...) , predecessor(...) , delete_node(...)` risultano avere complessità dipendente dall'altezza dell'albero che se :
+ L'albero è *bilanciato* : $O(h)=O(\log n)$
+ L'albero è molto *sbilanciato* ( linked list ) : $O(h)=O(n)$
Dove $n$ è il numero dei nodi
#### Costruzione

Per evitare di avere un albero fortemente sbilanciato dobbiamo creare opputunamente l'albero .

Utilizzando questo algoritmo :
```cpp
Arr A = [1, 3, 5, 7, 9]

buildBST (Arr A) -> Tree
	t = newTree() 
	for i = 1 to A.length
		u = creaNodo(A[i]) // u.Key = A[i], u.left = u.right = NIL
		Tree_insert(t,u)
	return t
```

Se assumiamo che l'input sia un array ordinato l'albero risultante sarà *fortemente sbilanciato* , non ottimale per tutte le operazioni che operano in $O(h)$

Calcoliamo la **Complessità** dell'algoritmo :
Supponendo che `{cpp}creaNodo(...)` abbia una complessità $O(1)$ , la complessità sarà dipendente dalla complessità di `{cpp}Tree_insert(...)` che verrà chiamate per $n$ volte , ossia quanti sono i nodi da inserire presenti nell'array di input 

La complessità di `{cpp}Tree_insert(...)` è $O(h)$ , ma essendo che viene costruito un albero fortemente sbilanciato la sua complessità risulterà essere $\Theta(n)$ poichè dovremo inserire il nuovo nodo sempre alla fine dell'albero 

Il tempo complessivo d'esecuzione di `{cpp}buildBST` risulterà quindi essere $n\cdot \Theta(n) = \Theta(n^2)$
>[!question]
>$\Theta\ o \ O$
>

La *complessità* può anche essere dimostrata nel seguente modo 

$$T(n)=\sum_{i=0}^{n-1}(c+d\cdot i)$$
Dove : 
+ $c$ = costo di `{cpp}createNode(...)`
+ $d$ = costo della `{cpp}treeInsert(...)`
+ $i$ = numero di ripetizioni della chiamata a `{cpp}treeInsert(...)`

Avremo :
$$=\sum_{i=0}^{n-1}c+\sum_{i=0}^{n-1} d \cdot i$$
$$=c\cdot n + d\cdot\sum_{i=0}^{n-1}i$$
Poichè $\sum_{i=0}^{n-1}i$ può essere ricondotta ad una serie geometrica possiamo scrivere : 
$$=c\cdot n + d\cdot\bigg(\frac{(n-1)(n-1+1)}{2}\bigg)$$
$$=c\cdot n + d\cdot\bigg(\frac{(n-1)n}{2}\bigg)$$
Cosiderando solo la parte più complessa avremo che 
$$T(n)=\Theta(n^2)$$

Si può fare un'**ottimizzazione** all'algoritmo :
Possiamo infatti considerare l'esatta metà del vettore ordinato come la radice dell'albero , a questo punto nella metà sinistra e destra avremo i rispettivi sottoalberi destri e sinistri della radice , inolte essendo l'array diviso esattamente a metà sicuramente creeremo un albero binario di ricerca **bilanciato** 

L'**Algoritmo** sarà quindi :

```cpp
Arr A = [1, 3, 5, 7, 9] 

buildBSTott (Arr A)
	t = newTree() 
	t.root = buildBSTottAux(A, 1, A.length, NIL)
	return t
	
buildBSTottAux (Arr A ,int inf ,int sup ,Node padre) 
	if inf > sup 
		return NIL 
	else 
		med = ( inf + sup ) / 2
		r = creaNodo (A[med])
		r.p = padre 
		r.left = buildBSTottAux(A, inf, med - 1, r) 
		r.right = buildBSTottAux(A , med + 1, sup , r) 
		return r
```

In questo caso la complessità risulta essere : 

$$
T(n)=\begin{cases}
0 &\text{se } n=0 \\
2\cdot T(\frac{n}{2}) + d &\text{se } n>0\\
\end{cases}
$$

La ricorrenza può essere risolta con il teorema *Master*
Infatti avremo che :
+ $a=2$
+ $b=2$
+ $f(n)=d$
+ $g(n)=n^{\log_2^2}=n$ 

Saremo quindi nel caso in cui $split+merge \lt \text{chiamate ricorsive}$ 
Possiamo quindi porre che : $f(n)=O(n^{1-\epsilon})$ 
Sciegliendo $\epsilon=1$ possiamo concludere che :
$$T(n)=\Theta(n)$$

>[!note]
>Se avessimo in input un array non ordinato è sufficente ordinarlo e applicare l'algoritmo ottimizzato , questo avrà complessità : $\Theta(n\cdot \log n )$ 

# Ulteriori alberi di ricerca 

## AVL

Sono alberi *binari di ricerca bilanciati*

Per mantenere il bilanciamento per ogni nodo viene mantenuta un'informazione in più , il *fattore di bianciamento* ( $h_{sx}-h_{dx}$ ) di quel nodo

In un albero *AVL* il valore assoluto del *fattore di bialnciamento* è $\le$ ad 1 per ogni suo nodo 

Per mantenere questa proprietà in caso di operazioni di cancellazione o inserimento necessitiamo di eseguire delle operazioni di rotazione per mantenere il bilanciamento
## B_alberi

Sono alberi generali di ricerca bilanciati con grado minimo $t\ge 2$  aventi le seguenti caratteristiche :
+ Tutte le foglie hanno la stessa profondità
+ Ogni nodo $v \neq root$ mantiene un numero di $K(v)$ chiavi ordinate
	$$key_1(v)\le key_2(v)\le\cdots\le key_K(v)$$
	tali che il numero di chiavi all'interno di un nodo sia : 
	$$t-1\le K(v)\le2t-1$$
	se il numero di chiavi cade al di sotto di $t-1$ allora queste devono essere fuse con un'altro nodo , se il numero di chiavi supera $2t-1$ dobbiamo splittare il nodo in sottonodi
+ La radice mantiene almeno una chiave e al più $2t-1$ chiavi *ordinate*
+ Ogni nodo interno $v$ ha $K(v)+1$ ( numero di chiavi dentro il nodo +1 ) figli 
+ Le chiavi $Key_i(v)$ separano gli intervalli di chiavi memorizzate in ciascun sottoalbero 

**Esempio** :

![[B_albero.excalidraw]]
## Black - Red Trees

Sono alberi binari di riceca che contengono un'informazione aggiuntiva in ogni nodo ossia il suo colore : rosso o nero 

Vincolando in modo oppurtuno come si alternano i nodi rossi e i nodi neri possiamo mantere la seguente proprietà : 
Il cammino più lungo nell'albero è lungo al massimo il doppio del cammino più basso , ne deriva un albero *bilanciato*

# Ordinamento

Il problema dell'ordinamento è fondamentale nell'algortmica poichè risulta essere l'algoritmo più frequentemente utilizzato

Generalmente gli algoritmi di ordinamento hanno 2 caratteristiche :
+ In **Input** abbiamo una sequenza di $n$ numeri  $< a_1, a_2,\dots, a_n>$ 
+ In **Output** abbiamo una permutazione $< a_1', a_2',\dots, a_n'>$ della sequenza di $n$ numeri in input tale che $a_1'\le a_2' \le \dots \le a_n'$

Il metodo principale per implementare questo tipo di algoritmi è basarsi su *confronto* 

La complessità quindi di questi algoritmi risulta essere in funzione del numero di confronti che svolgo 

>[!note]
>La complessità minima che un algoritmo del genere può avere è $O(n\log n)$

## Definizioni

### Algoritmo in Loco

Un algoritmo si dice *in loco* ( o *sul posto* ) se in ogni istante al più un numero costante di elementi dell'array di input sono memorizzati all'esterno dell'array  
### Metodo stabile

Gli elementi con lo stesso valore si presentano nell'output nello stesso ordine rispetto all'input 

**Esempio** :

![[Pasted image 20231205112704.png]]

## Insertion Sort

L'*Insertion Sort* è un algoritmo che sfrutta la tecnica incrementale ossia avendo $k$-elementi già ordinati vogliamo espandere questo insieme al $(k+1)$-esimo elemento   

![[Pasted image 20231205105508.png]]

**Algoritmo** :

```cpp
Insertion_sort(Array A)
	for j=2 to A.length // l'array in questo caso parte dall'indice 1
	// il primo elemento è ordinato per se stesso quindi parto dal secondo elemento dell'array
		Key = A[j] // Key -> l'elemento che voglio ordinare
		i = j - 1 // scorro a ritroso la parte già ordinata per inserire nel posto corretto il nuovo elemento
		while i > 0 AND Key < A[i] // finchè ho un indice valido dell'array e la Key è minore del valore all'interno di quell'indice 
			A[i + 1] = A[i] // sposto a destra gli elementi > di Key
			i = i - 1
		A[i + 1] = Key // all'uscita del ciclo precedente indice sarà dove tutti gli elementi sucessivi alla key saranno > del suo valore 
```

**Esempio** di esecuzione : 

![[EsempioInsertion.excalidraw]]
>[!todo]
>copleta esempio
>#todo

### Dimostrazione di Correttezza 

**Invariante** : Il sottoarray $A[1,\dots,j-1]$ è formato dagli elementi ordinati originariamente nelle posizioni $A[1,\dots,j-1]$ ( quella parte dell'array è ora ordinata )
L'invariante può essere quindi espresso : 
$$INV=\Big[\frac{n+1}{j}\Big]$$ 
**Prima del ciclo** : 
	Con $j=2$ abbiamo che ovviamente il sottoarray $A[1,\dots,1]$ risulta ordinato poichè è composto da un solo elemento 

**Conservazione** : 
	L'esecuzione del corpo del for posiziona correttamente l'elemento $j$ nella porzione del vettore già ordinato $A[1,\dots,j-1]$ rendendo la porzione di elementi ordintati $A[1,\dots,j]$ 
	Gli elementi presenti all'interno del vettore $A[1,\dots,j]$ sono esattamente gli elementi presenti nell'array orignario alle posizioni $A[1,\dots,j]$ 

**Conclusione del ciclo** : 
	Quando il ciclo `{cpp}for` termina , l'indice $i$ ha valore $A.length+1=n+1$ , avremo quindi che il sottoarray $A[1,\dots, n+1-1]$ è formato da elementi ordinati i quali valori origniale risiedono in posizione : $A[1,\dots,n]$
	Quindi al temine del ciclo l'invariante ci garantice che tutti gli elementi all'interno dell'array $A$ sono ordinati  

### Complessità

Nel caso *migliore* ( l'array originale è ordinato in modo crescente ) il tempo di esecuzione è $\Theta(n)$ poichè scorro tutto l'array ma non svolgo nessuna operazione di scambio ( il ciclo `{cpp}while` non viene mai eseguito )

Nel caso *peggiore* ( l'array originale è ordinato in modo decrescente ) il tempo di esecuzione è $\Theta(n^2)$ poichè ad ogni elemento svolgo $n$ confronti 
Questa complessotà può essere calcolata :
$$\sum_{j=2}^{n-1}j-1$$
Sostituiamo con $k=j-1$
$$\sum_{k=1}^{n-1}k$$
Risulta essere al serie aritmetica 
$$\frac{(n-1)(n-1+1)}{2}=\frac{n(n-1)}{2}\sim \Theta(n^2)$$
### Conclusioni

**Vantaggi** :
+ è in *loco*
+ è un *metodo stabile*
+ è sensibile all'ordinamento dell'input : se trova un elemento maggiore dell'array già ordinato lo capisce e non va ad eseguire il ciclo interno

**Svantaggi**
+ Nel caso peggiore la complessità risulta essere $O(n^2)$ , infatti l'*insertion sort* viene utilizzato solo per l'ordinamento di array di piccole dimensioni

## Merge Sort

Il *merge sort* è un algoritmo di ordianmento basato sulla tecnica del divide et impera 

Inizialmente avremo un array $A[p\ ...\ r]$ dove inzialmente $p=1$ e $r = A.length$

### Passi dell'algoritmo

1. **Divide** : Divide l'array in 2 sottoarray $A[p\ ...\ q]$ e $A[q+1 \ \dots \ r]$ dove $q$ è l'indice di mezzo $q=\lfloor\frac{p+r}{2}\rfloor$ 
2. **Impera** :  Ordina i 2 sottoarray in modo ricorsivo utilizzando l'algoritmo *mergesort* . Se il problema è sufficentemente piccolo ( 0 e 1 elemento ) si risolve direttamente
3. **Combina** : fonde i 2 sottoarray che sappiamo essere ordinati per generare un singolo vettore ordinato $A[p \ \dots \ r]$ 

### Algoritmo 

```cpp
 mergesort ( array A , int p , int r )
	if p < r // l'array deve contenere almeno 2 elementi 
		med = (p + r) / 2 
		mergesort (A , p , med)
		mergesort (A , med + 1, r) 
		merge (A , p , q , r) 

 merge ( array A , int p , int q , int r ) 
	n1 = q - p + 1
	n2 = r - q 
	crea due array di appoggio L [1 ... n1 + 1] e R [1 ... n2 + 1] 
	for i = 1 to n1 // inserisco in L la parte bassa dell'array tagliato in q
		L[i] = A[p + i - 1] 
	for j = 1 to n2 // inserisco in R la parte alta dell'array tagliato in q
		R[j] = A[q + j] 
	L[n1 + 1] = infinito // infinito nel nostro caso valore sentinella per      non dover controllare che L è finito e R no e il contrario 
	R[n2 + 1] = infinito 
	i = 1, j = 1 
	for k = p to r 
		if L[i] <= R [j] // posiziono in k l'elemento minore tra L[i] e R[j] questo fa sì che alla fine del for avremo un array completamente ordinato 
			A[k] = L[i]  
			i++ 
		else 
			A[k] = R[j] 
			j++
```
### Analisi Correttezza

Per verificare la correttezza del nostro algoritmo dobbiamo dimostrare la correttezza del seguente **Invariante** : Il sottoarray `A[p ... k-1]` contiene *ordinati* i `k-p` elementi più piccoli di `L[1 ... n1 + 1]` e `R[1 ... n2 + 1]` , inoltre  `L[i]` e `R[j]` sono i più piccoli elementi dei loro rispettivi array che non sono ancora stati copiati in `A` 

Verifichiamo quindi che l'*invariante* è verificato anche per la conclusione

Alla fine del ciclo , ossia quando l'*invariante* è valido e la guardia del ciclo for non è verificata ( siamo usciti dal ciclo ) $INV\land \lnot \text{Guardia}$ , avremo `k = r + 1` , dovremo quinid vedere se il nostro invariante è valido :
$$INV\bigg[\frac{r+1}{k}\bigg]$$
Sostituendo quindi all'interno dell'*invariante* : 
	Il sottoarray `A[p ... r]` contiene *ordinati* i `r+1-p` ( quelli iniziali ) elementi più piccoli di `L[1 ... n1 + 1]` e `R[1 ... n2 + 1]` , inoltre  `L[i]` e `R[j]` sono i più piccoli elementi dei loro rispettivi array che non sono ancora stati copiati in `A` 
Questo vuol dire che il vettore `A[p ... r]` è ordinato , gli unici elementi non copiati sono le due sentinelle
### Complessità

Il tempo di esecuzione del `merge()` si può ricavare nel seguente modo :
+ $\Theta(n_1)$ per il ciclo `{c}for` per riempire l'array `L`
+ $\Theta(n_2)$ per il ciclo `{c}for` per riempire l'array `R`
+ $\Theta(r-p+1)$ per il ciclo `{c}for` che unisce i due array
+ $O(1)$ per tutte le altre operazioni costanti

Possiamo quindi calcolare :
$$T(n)=O(1)+\Theta(n_1)+\Theta(n_2)+\Theta(r-p+1)$$
$$=\Theta(n_1+n_2)+\Theta(r-p+1)$$
Dove $n_1=q-p+1$ e $n_2=r-q$
$$=\Theta(q-p+1+r-q)+\Theta(r-p+1)$$
$$=\Theta(r-p+1)+\Theta(n)$$
$$=\Theta(n)+\Theta(n)=\Theta(n)$$

Ora il tempo di esecuzione del `mergesort()` è il seguente :
$$T(n)=\begin{cases}O(1) & n \le1 \\ 2T\Big(\frac{n}{2}\Big)+\Theta(n) & n \gt 1\end{cases}$$
Dove :
+ $2T\Big(\frac n 2\Big)$ : è la complessità delle 2 chiamate ricorsive ( poichè divo l'array in 2 parti uguali )
+ $\Theta(n)$ : per via del `merge()`

La ricorrenza può essere risolta con il teorema *Master*
$$f(n)=\Theta(n)$$
$$n^{\log_2 2}=n=\Theta(n)$$
Poichè siamo nel caso in cui il tempo di $split+merge=\text{chiamate ricorsive}$ possiamo dire che :
$$T(n)=\Theta(n\cdot\log n)$$

### Conclusioni

#### Vantaggi

+ $T(n)=\Theta(n\cdot \log n)$  complessità efficente
+ Risulta essere un metodo *stabile* , questo è garantito dal `<=` presente a righa 20 
#### Svantaggi

+ *Non è in loco* , visto che utilizzamo dei vettori ausiliari 
+ Non è *sensibile* all'ordinamento del vettore in entrata , un eventuale ottimizzazione sarebbe quella di riordinare l'array attraverso un `InsertionSort` appena raggiungo una certa soglia di elementi ( tipicamente $5\lt el \lt 25$ ) 
## Quick Sort

Si basa sulla tecnica *divide et impera* , abbiamo un array `A[p ... r]` in cui inizialmente `p = 1` e `r = A.length`

### Passi dell'Algoritmo

1. **Divide** : Pertizioniamo l'array orignale `A[p ... r]` in 2 sottoarray `A[p ... q-1]` e `A[q+1 ... r]` eventualmente vuoti tale che $A[p\ ...\ q-1]\le A[\ q\ ] \le A[q+1\ ...\ r]$ , l'indice `q`  è risultato di questa procedura di partizionamento , questo indice è chiamato *pivot* 
2. **Impera** : Ordino i due sottoarray `A[p ... q-1]` e `A[q+1 ... r]` chiamando ricorsivamente la procedura `quicksort()` , se il problema è sufficentemente piccolo riolvo direttamente il problema 
3. **Combina** : Non devo combinare nulla per via di ciò che abbiamo descritto nel *divide* e sucessivamente nell' *impera*

### Algoritmo

```cpp
quicksort(array A, int p, int r)
	if p < r // altrimenti non ho el da ordinare 
		q = partition(A, p, r)
		quicksort(A, p, q-1)
		quicksort(A, q+1, r)

partition(array A, int p, int r) -> int
	x = A[r] // il pivot è l'ultimo elemento
	i = p - 1
	for j = p to r - 1
		if A[j] <= x
			i = i + 1
			scambia A[i] e A[j]
	scambia A[i + 1] e A[r]
	return i + 1  
```

La chiamata iniziale a `partition()` suddivide l'array iniziale in 2 parti aventi le caratteristiche descritte prima ( nella parte *divide* ) , questa ritornerà l'indice `q` , del *pivot* , di separazione dei 2 array , a questo punto vengono fatte le 2 chiamate ricorsive sui due sottarray creati

`partition()` funziona nel seguente modo : 
	Selezioniamo come *pivot* l'elemento finale dell'array , scorriamo l'array indicando con : 
+ `i` l'indice dove termina la parte in cui i valori sono `<=` del *pivot*
+ `j` l'indice dove termina la parte in cui i valori sono `>=` del *pivot*
	Scorriamo quindi l'array partendo da `{c}i=0` e `{c}j=1` ( scorrendo con `{c}for j = p to r - 1` )
	Se `{c}A[j]<=` *pivot* :
	+ `{c}i=i+1` poichè abbiamo trovato un valore `<=` del *pivot*
	+ Scambio i valori di `{c}A[i]` e `{c}A[j]` poichè il valore minore è in posizione `j`
	Alla fine del ciclo `{c}for` dovremo pozionare il *pivot* nel posto corretto ossia `{c}A[i + 1]` 

**Esempio** :

![[Sorting_quicksort_anim.gif]]
### Analisi Correttezza

Per analizzare la correttezza del nostro algoritmo innanzitutto individuiamo l'*invariante* : 
$$INV\sim x=A[r]\land\forall k \in [p\dots i]\rightarrow A[k]\le x\ \land$$
$$\land\ \forall \ k \in [i+1\dots j-1]\rightarrow A[k]> x\ \land$$
$$\land \ p\le j\le r \land p -1 \le i \le j-1$$

Consideriamo la conclusione : $j=r$
$$INV\bigg[\frac{r}{j}\bigg]\sim x=A[r]\land\forall k \in [p\dots i]\rightarrow A[k]\le x\ \land$$
$$\land\ \forall \ k \in [i+1\dots r-1]\rightarrow A[k]> x\ \land$$
$$\land \ p\le r\le r \land p -1 \le i \le r-1$$
Questo ci consente di dire che abbiamo ripartito l'array correttamente in 3 parti 
![[Pasted image 20231216165036.png]]
Basterà eseguire l'ultima operazione di scambio per inserire il *pivot* nella posizione corretta 
### Complessità

Per analizzare la complessità dell'algoritmo determiniamo innanzitutto la complessità di `partition()` : 
	Sia $n$ il numero di elementi dell'array che `partition()` riceve in input , allora la complessità sarà $\Theta(n)$ poichè il ciclo `{c}for` al suo interno svolge $r-p+1=n$ iterazioni

Ora calcoliamo la complessità del `quicksort()` 
	Siano : 
+ $k$  il numero di elementi del sottoarray che va da $p$ a $q-1$
+ $n-1-k$ il numero di elementi del sottoarray che va da $q+1$ a $r$
	Allora la complessità totale del `quicksort()` sarà :
	$$T(n)=\begin{cases} O(1) & n \le 1 \\ T(k)+T(n-1-k)+\Theta(n) & n>1 \end{cases}$$
	Dove $\Theta(n)$ è la complessità di `partition()`

Per indicare correttamente la complessità dobbiamo separare diversi casi : 
#### Caso peggiore

In questo caso abbiamo che una partizione contiene $n-1$ elementi mentre l'altra è vuota 
Sostituendo nella formula ricorsiva abbiamo : 
$$T(n)=T(n-1)+T(0)+\Theta(n) \rightarrow T(n-1)+\Theta(n)\rightarrow T(n-1)+c\cdot n$$
Ora risolviamo questa ricorrenza con il metodo dello srotolamento o albero delle ricorsioni :
$$T(n)=T(n-1)+cn = T(n-2)+c(n-1)+cn= \dots$$
$$T(n)=\sum_{i=1}^n ci=c \frac{n(n+1)}{2}=\Theta(n^2)$$
Essendo che $\sum_{i=1}^n ci$ è una serie aritmetica

Ciò significa che se abbiamo un vettore ordinato o ordinato nel senso opposto la complessità risulterà essere $\Theta(n^2)$

#### Caso migliore 

In questo caso abbiamo che un vettore contiene $\lfloor \frac{n}{2} \rfloor$ elementi metre l'altro vettore conterrà $\lceil \frac{n}{2} \rceil-1$ elementi 

Sostituendo quindi nella ricorsione abbiamo ( più o meno )
$$T(n)=2T\bigg(\frac n 2\bigg)+\Theta(n)$$
In questo caso la ricorrenza può essere risolta con il teorema *Master* :
+ $f(n)=\Theta(n)$
+ $n^{\log_2 2}=n=\Theta(n)$

Siamo nel caso in cui il tempo di $split+merge$ equivale al tempo delle $\text{Ricorsioni}$ , avremo quindi :
$$T(n)=\Theta(n\cdot\log n)$$
#### Caso medio 

Per lo studio del caso medio vogiamo verificare se siamo più vicini al caso *peggiore* o *migliore* 

Studiamo quindi il caso in cui i 2 sottoarray sono divisi con un a proporzione 9-a-1 costante durante l'esecuzione dell'algoritmo , ciò significa che avremo una ricorsione del seguente tipo :
$$T(n)=T\bigg(\frac{n}{10}\bigg)+T\bigg(\frac{9\cdot n}{10}\bigg)+cn$$
Risolviamo le ricorrenenze attraverso l'albero delle ricorrenze 
![[Drawing 2023-12-18 08.52.34.excalidraw]]

Possiamo notare che ogni livello ha un costo $cn$ fino a che non viene raggiunta la condizione di ritorno della funzione , ossia quando la dimensione del sottoarray arriva ad $1$ .

Per verificare le lunghezze dei cammini poniamo la condiozione di terminazione per i nodi dell'albero che decresono in modo omogenero ( il cammino destro e sinistro )

Per il cammino sinistro :
$$\frac n {10^i} = 1 \implies n=10^i \implies i = \log_{10} n$$
dove $i$ indica il livello del nodo dell'albero 

Per il cammino destro :
$$\bigg(\frac{9}{10}\bigg)^i n = 1 \implies n = \bigg(\frac{10}{9}\bigg)^i\implies i = \log_{\frac {10}9} n$$
L'altezza massima tra i 2 è quindi quella per cui vogliamo calcolare la complessità ( visto che sarebbe il caso peggiore )

Consideriamo quindi l'altezza dell'albero come $\log_{\frac {10}9} n$ e visto che il costo massimo di quei livelli è $cn$ possiamo dire che la complessità risulta essere : 
$$T(n)\le cn \cdot \log_{\frac {10}9}  n = O(n \log n)$$
Questa complessità può essere generalizzata per qualsiasi proporzionalità :
$$T(n)=T(\alpha n)+T((1-\alpha)n)+cn \quad 0<\alpha<1, c>0$$

Possiamo quindi concludere che la complessità risulterà essere $T(n)=O(n \log n)$ quando le ripartizioni hanno proporzionalità costante 

##### Caso Medio : proporzioni alterne

Supponiamo che le partizioni si alternano tra partizioni $Lucky\ L(n)$ , se esiste una proprozione bilanciata tra gli elementi dell'array , e $Unlucky\ U(n)$ altrimenti 
$$L(n)=2\cdot U\bigg(\frac{n}{2}\bigg)+\Theta(n)$$
$$U(n)=L(n-1)+\Theta(n)$$

Sostiutendo all'interno di $L(n)$ :
$$L(n)=2\bigg(L\bigg(\frac{n}{2}-1\bigg)+\Theta\bigg(\frac n 2\bigg)\bigg)+\Theta(n)$$
$$L(n)=2L\bigg(\frac{n}{2}-1\bigg)+2\Theta\bigg(\frac n 2\bigg)+\Theta(n)$$
$$L(n)=2L\bigg(\frac{n}{2}-1\bigg)+\Theta(n)$$
Ora risolvendo con il teorema *Master*
$$L(n)=\Theta(n \log n)$$
### Conclusioni

La complessità del quicksort è quindi $\Theta(n^2)$ nel caso peggiore , ma la complessità nel caso medio rimane $\Theta(n \log n)$ per questo è usato spesso 

Inoltre si tratta di un ordinamento *in loco* , mal'algoritmo *non* è *stabile*
### Ottimizzazioni
#### Randomize quicksort

Ciò che mette in difficolatà il quicksort sono gli array ordinati per fare in modo che non abbiano un impatto nella complessità finale prendiamo un *pivot* casuale , questo abbasserà la probabilità che avvenga il caso peggiore 

```cpp
randomized_quicksort(array A, int p, int r)
	if p < r 
		q = randomized_partition(A, p, r)
		randomized_quicksort(A, p, q-1)
		randomized_quicksort(A, q+1, r)

randomized_partition(array A, int p , int r) -> int
	i = random(p, r)
	scambia A[i] con A[r]
	return partition(A, p, r)
```

##### Conclusioni

+ **Vantaggi**
	+ $T(n)$ è indipendente dal'ordinamento dell'input 
	+ Non posso fare nessuna assunzione su come sono distribuiti gli input 
	+ Nessuno specifico input può portare al caso peggiore poichè il caso peggiore è determinato del generatore di numeri casuali

#### Miglioramenti vari 

##### Insertion Sort

Possiamo utilizzare all'interno di algoritmi di ordinamento altri algoritmi di ordinamento più efficenti per diversi tipi di input 

Possiamo per esempio utilizzare l'*insertion sort* per ordinare array piccoli in quanto in questo caso risulta essere più efficente   

**Esempio** : 

```cpp
if r - p < M
	insertion_sort(A, p, r)
```

Dove $M$ è un valore prestabilito di solito $5\le M\le 25$  

Un'altro modo per sfruttare l'efficenza dell'*insertion sort* è quello di fornirgli un input parzialmente ordinato 
In questo caso poniamo all'interno del `quicksort()` la seguente condizione :

```cpp
if r - p <= M
	return
```
In questo modo avremo che ci verrà restituito un array semi ordinato , questo array andremo a darlo in pasto all'*insertion sort*

```cpp
void sort(array A, int p, int r)
	quicksort(A, p, r)
	insertion_sort(A, p, r)
```
##### Mediana

Un altro metodo per migliorare la complessità del *quicksort* è quello di scigliere il *pivot* come la mediana di 3 elementi ( es il centro , l'inizio e la fine ) dell'array da ordinare 
##### Duplicate Keys

Se abbiamo tutte le chiavi uguali con o senza randomizzazione ci porterà sempre ad avere una partizione vuota e una contenente $n-1$ elementi

Per risolvere il problema dividiamo in 3 il vettore iniziale , aggiungendo una partizione contenente tutte le chiavi uguali al *pivot*

`partition()` a questo punto non ritorna solo l'indice del *pivot* ma anche un ulteriore indice $t$ che indica la fine degli elementi uguali ad $x$

L'array sarà quindi suddiviso nel seguente modo :

![[partition.excalidraw]]

dove :
+ $p\le q\le t\le r$
+ Tutti gli elementi di $A[q...t]$ sono uguali a *pivot*
+ Tutti gli elementi di $A[p ... q-1]$ sono minori di $A[q]$
+ Tutti gli elementi di $A[t+1 ...r]$ sono maggiori di $A[q]$

Il tempo di esecuzione della partition diventa : $T(n)=\Theta(r-p)$

```cpp
partition (array A , int p , int r)
	x = A[r]
	min = eq = p 
	mag = r 
	while eq < mag 
		if A[eq] < x 
			scambia A[eq] con A[min] 
			min = min + 1 
			eq = eq + 1 
		else 
			if A[eq] == x 
				eq = eq + 1
			else 
				mag = mag - 1 
				scambia A[eq] con A[mag] 
	scambia A[r] con A[mag] 
	return <min,mag>
```

**Spiegazione**

Ad ogni iterazione del ciclo `{c}while` viene controllato il valore presente all'interno dell'indice `eq` e confrontato con il valore del *pivot* :
+ Se minore del *pivot* vengono aumentati gli indici `eq` e `min`
+ Se uguale al *pivot* viene incrementato solo `eq`
+ Se maggiore del *pivot* viene decrementato `mag` e si scambiano gli elementi puntati dagli indici `eq` e `mag` 

Il ciclo prosegue finchè `eq` e `mag` non raggiungono lo stesso valore 
Infine scambiamo il *pivot* ( che è l'ultimo elemento ) con l'elemento in posizione `mag`
###### Correttezza 

L'*invariante* di ciclo è il seguente 

$$INV \sim x = A[r]\ \land$$
$$\land \ \forall k \in [p... min),\ A[k]<x\ \land$$
$$\land \ \forall k \in [min... eq),\ A[k]=x\ \land$$
$$\land \ \forall k \in [mag... r),\ A[k]>x\ \land$$
$$\land \ p\le min \le eq\le mag \le r$$

Verifichiamo la *conclusione* ( ossia quando $eq = mag$ ) 

$$INV\bigg[\frac{mag}{eq}\bigg] \sim x = A[r]\ \land$$
$$\land \ \forall k \in [p... min),\ A[k]<x\ \land$$
$$\land \ \forall k \in [min... mag),\ A[k]=x\ \land$$
$$\land \ \forall k \in [mag... r),\ A[k]>x\ \land$$
$$\land \ p\le min \le mag \le r$$
Con lo scambio finale il vettore sarà nel seguente modo :
![[pertitionEQ.excalidraw]]

Possiamo quindi implementare la precedene ottimizzazione nel seguente modo : 

```cpp
quicksort(array A, int p, int r)
	if p < r
		<q,t> = partition(A, p ,r)
		quicksort(A, p, q-1)
		quicksort(A, t+1, r)
```
###### Complessità

Il tempo di esecuzione di `partition()` è $\Theta(r-p)$ , nel caso in cui abbiamo un array di elementi identici la `partition()` verrà eseguita sull'intero array $\Theta(n)$ , mentre le chiamate ricorsive verrano svolte su 2 array vuoti ( visto che tutti gli elemenit stanno tra $q$ e $t$ ) avranno quindi complessità costante ,

La complessità finale sarà quindi la complessità di `partition()` ossia $\Theta(n)$

###### Conclusioni

**Vantaggi** :
+ Risulta essere *in loco*
+ Nal caso medio il tempo di esecuzione è $O(n \log n)$

**Svantaggi** :
+ Non è *stabile*
+ Nel caso peggiore la complessità risulta essere $O(n^2)$
## Heap e Heap sort

L'*Heap Sort* è un algoritmo di ordinamento basato sul confronto che fa uso di una strutta dati *Heap* 
### Heap

Un *heap binario* è un albero quasi completo ossia un albero in cui tutti i suoi livelli sono riempiti tranne eventualmente l'ultimo in cui tutte le foglie sono addossate a sinistra 

**Esempio** :

![[Heap.excalidraw]]

Un *heap* può essere memorizzato attraverso un *array posizionale* contente 2 attributi :
+ `A.length` indica il numero di elementi dell'array 
+ `A.heap_size` il numero di elementi dell'*heap* che sono memorizzati nell'array , è possibile che $A.length\ge A.heap\_size$

La radice dell'albero è memorizzata alla prima posizione dell'array 

Possiamo ricavare : 

**Padre** :
```cpp
parent(Node i) -> Node
	return floor(i/2)
```

Può anche essere espresso attraverso uno shift a destra di un bit dell'address di `i` 

**Figlio Sinistro** :
```cpp
left(Node i) -> Node
	return 2 * i
```

Può anche essere espresso attraverso uno shift a sinistra di un bit dell'address di `i` 

**Figlio Destro** :
```cpp
right(Node i) -> Node
	return 2 * i + 1
```

Può anche essere espresso attraverso uno shift a sinistra di un bit e la somma di 1 all'address di `i` 

Esistono due tipi di *heap*
#### max_heap

Per ogni nodo differente dalla radice abbiamo la seguente proprietà :
$$A[parent(i)]\le A[i]$$
Questa proprietà garantisce che il massimo elemento di un *max_heap* si trova nella radice e che il sottoalbero di un nodo contiene valori non maggiori rispetto al valore del nodo stesso
#### min_heap

Per ogni nodo differente dalla radice abbiamo la seguente proprietà :
$$A[parent(i)]\ge A[i]$$
Questa proprietà garantisce che il minimo elemento di un *min_heap* si trova nella radice e che il sottoalbero di un nodo contiene valori non minori rispetto al valore del nodo stesso

#### Proprietà 

##### Lemma 1

L'altezza di un *heap* di $n$ elementi è dato dal $\lfloor \log n \rfloor$

**Dimostrazione** : 

Un heap è un albero quasi completo , se ha altezza $h$ allora il numero di nodi può essere limitato superiormente e inferiormente nel seguente modo : 
$$n\le\sum_{i=0}^h 2^i = \frac{2^{h+1}-1}{2-1}=2^{h+1}-1 \quad \text{se l'albero è completo}$$
$$n\ge\sum_{i=0}^{h-1} 2^i +1= 2^{h+1-1}-1 +1= 2^{h} \quad \text{altrimenti}$$
Avremo quindi che :
$$2^h\le n \le 2^{h+1} -1 $$
$$2^h\le n < 2^{h+1}$$
$$h \le \log n < h+1$$
Visto che $h$ è un intero allora $h=\lfloor \log n \rfloor$
##### Lemma 2

Nell'array che rappresenta un *heap* di $n$ elementi le foglie sono i nodi con indici :
$$\bigg\lfloor \frac{n}{2} \bigg\rfloor + 1, \ \bigg\lfloor \frac{n}{2} \bigg\rfloor + 2 , \dots \ , n  $$
Questo comporta che le foglie dell'*heap* costituiscono al più la metà degli elementi dell'*heap*
##### Lemma 3

Ci sono al massimo $\big\lceil \frac{n}{2^{h+1}} \big\rceil$ nodi di altezza $h$ in un qualsiasi *heap* di $n$ elementi

Se $h=0$ ci sono al più $\lceil \frac{n}{2} \rceil$ nodi ( i nodi foglia )

Se $h=\log n$ allora 
$$\bigg\lceil \frac{n}{2^{\log n+1}} \bigg\rceil=\bigg\lceil \frac{n}{2^{\log _2 n}\cdot 2} \bigg\rceil=\bigg\lceil \frac{n}{n\cdot 2} \bigg\rceil=\bigg\lceil \frac{1}{2} \bigg\rceil=1$$  Ossia la radice dell'albero , è infatti l'unico elemento ad avere altezza $\log n$

#### Operazioni

##### max_heapify

è una procedura per riparare l'ordine all'interno di un *max_heap*

+ Pre-Condizione : gli alberi binari con radice in `left(i)` e `right(i)` sono *max_heap*
+ Post-Condizione : l'abero radicato in `i` è un *max_heap*

###### Algoritmo

```cpp
max_heapify(Heap A, Node i)
	l = left(i) 
	r = right(i) 
	if l <= A.heap_size AND A[l] > A[i]
		massimo = l
	else 
		massimo = i 
	if r <= A.heap_size AND A[r] > A[massimo]
		massimo = r 
	if i != massimo 
		scambia A[i] e A[massimo] 
		max_heapify(A , massimo) 
```

Avendo l'indice $i$ ricaviamo innanzitutto i figli destri e sinistri di $i$ , se $i$ non è foglia allora lo confrontiamo con i valori dei suoi figli e scambiamo il valore di $i$ con il valore del figlio massimo trovato , se il valore massimo trovato è $i$ allora abbiamo finito ( poichè sappiamo che il sottoalbero sinistro e destro sono *max_heap* per pre-condizione ) , lo stesso se il valore massimo è una foglia 

**Esempio** :

![[Pasted image 20231219104328.png]]

###### Complessità

Il tempo di esecuzione è $T(n)=O(h)$ dove $h$ è l'altezza del nodo su cui chiamiamo la procedura , $O(\log n)$ se chiamiamo la procedura sulla radice , $1$ se la chiamiamo su una foglia 


##### Costruzione di un max_heap

Dato un vettore disordinato trasformarlo in un *max_heap*

###### Algoritmo

```cpp
build_max_heap(array A)
	A.heap_size = A.length
	for i = floor(A.length/2) down to 1 // poichè da A.length/2 -> A.length abbiamo già foglie per lemma 2
		max_heapify(A, i)
```

###### Analisi della correttezza

L'*invariante* è : $$INV \sim \text{ogni nodo $i+1$ , $i+2$, $\dots$ , $n$ è radice di un max\_heap con $n=A.length$} $$
L'*invariante* ci assicura che la pre-condizione di *max_heapify* sia verificata poichè i figli di $i$ si trovano in posizioni $2 \cdot i$ e $2\cdot i +1$ entrambe maggiori di $i$

**Conclusione** : 
	Alla conclusione del ciclo avremo che $i=0$ : 
	$$INV\bigg[\frac 0 i\bigg]\sim \text{ogni nodo $1$ , $2$, $\dots$ , $n$ è radice di un max\_heap con $n=A.length$} $$
	In particolare il nodo $1$ contiene la radice del nostro albero che è dunque *max_heap*

###### Analisi della complessità

La procedura compi $O(n)$ interazioni , più precisamente $\frac n 2$  , in ognuna delle quali viene chiamata la funzione `max_heapify()` che ha come costo temporale $O(\log n)$ .
Quindi il tempo di esecuzione risulterebbe essere $O(n \log n)$ tuttavia questo non risulta essere un *limite stretto*

Uno più stretto può essere ricavato osservando che il tempo di esecuzione dipende da quello di *max_heapify* : $O(h)$ , dove possiamo notare che l'altezza della maggior parte dei nodi risulta essere 
$$\sum_{h=0}^{\lfloor \log n  \rfloor} \bigg\lceil \frac{n}{2^{h+1}} \bigg\rceil O(h) = O\Bigg(n \sum_{h=0}^{\lfloor \log n \rfloor} \frac{h}{2^h}\Bigg)$$
Sfruttiamo una serie nota :
$$\sum_{h=0}^{\infty} h x^h = \frac{x}{(1-x)^2} \text{per |x|<1}$$
Poniamo $x=\frac{1}{2}\lt 1$ Allora 
$$\sum_{h=0}^\infty \frac{h}{2^h}=\frac12 \frac1{(\frac 1 2)^2}=\frac  42=2$$
Quindi 
$$O\Bigg(n \sum_{h=0}^{\lfloor\log n \rfloor} \frac h {2^h}\Bigg)=O\Bigg(n \sum_{h=0}^{\infty} \frac h {2^h}\Bigg)=O(2n)=O(n)$$
Quindi il tempo di esecuzione di *build_max_heap* è $O(n)$
### Heap sort

#### Algoritmo 

```cpp
heapsort(array A)
	build_max_heap(A)
	for i = A.length down to 2 // la radice si trova già nel posto corretto è sicuramente  minore di tutti gli elementi prima
		scambio A[i] con A[1]
		A.heap_size = A.heap_size - 1
		max_heapify(A, i) // potrebbe verificarsi una violazione delle proprietà del max_heap solo sulla radice poichè è quello che abbiamo scambiato
```

#### Analisi della correttezza

*Invariante* : 
	$INV \sim$  il sottoarray `A[1 ... i]` è un *max_heap* che contiene gli $i$ elementi più piccoli di `A[1 ... n]` e il sottoarray `A[i+1 ... n]` contiene gli $(n-1)$ elementi più grandi di `A[1 ... n]`  *ordinati*

  ![[Pasted image 20231219114910.png]]

*Conculsione* :
	Alla conclusione del ciclo $i=1$ avremo che l'*invariante* sarà :
	$INV\big[\frac 1 i\big] \sim$ il sottoarray `A[1 ... 1]` è un *max_heap* che contiene l'emento più piccolo di `A[1 ... n]` e il sottoarray `A[2 ... n]` contiene gli $(n-1)$ elementi più grandi di `A[1 ... n]`  *ordinati*
 
#### Complessità

La costruzione del *max_heap* ha complessità $O(n)$ , sucessivamente viene eseguita *max_heapify* con costo $O(\log n)$ per un totale di $n-1$ volte

Il tempo di esecuzione totale sarà  : 
$$T(n)=O(n)+O(n)\cdot O(\log n)=O(n \cdot \log n)$$
#### Conclusioni

L'*heap sort* è **in loco** 

La complessità nel caso peggiore è : $O(n \log n)$ 
La sua complessità risulta quindi essere uguale al *marge sort* ma applicando le varie ottimizzazioni ( randomize , utilizzo di algoritmi più efficenti per array di piccole dimensioni etcc ) l'*heap sort* risulta essere più veloce 

>[!warning]
> Tranne nel caso peggiore

## Code di Priorità

Una *coda di priorità* è una struttura dati che serve a memorizzare un inseme dinamico di elementi , ciascuno dei quali ha un valore  *key* o *peso*

2 tipologie di code :
+ **Code di massima priorità**
	+ Usate per l'implementazione dello scheduling dei processi 
+ **Code di minima priorità**
	+ Usate nella teoria dei grafi , Djikstra

### Operazioni su code di massima priorità

#### Inserimento

```cpp
insert(S , x)
```

L'*inserimento* di un nodo $x$ all'interno della coda $S$ $\implies S\ \cup \ \{x\}$ 
#### Massimo

```cpp
maximum(S)
```

Restituisce l'elemento di $S$ con la chiave più *grande* ( non rimuove $S$ )
#### Estrazione del Massimo

```cpp
extract_max(S)
```

Restituisce ed elimina da $S$ l'elemento di $S$ con chiave più *grande*
#### Increase

```cpp
increase(S, x, k)
```

Pre-condizione : $x$ deve esistere in $S$ , $x \in S$
Post-condizione : Aumenta il valore della chiave di $x$ al nuovo valore $k$ che si suppone si almeno pari al valore corrente della chiave di $x$ ( $k\ge$ chiave di $x$ )
### Operazioni su code di minima priorità

#### Inserimento

```cpp
insert(S ,x)
```

L'*inserimento* di un nodo $x$ all'interno della coda $S$ $\implies S\ \cup \ \{x\}$ 
#### Minimo

```cpp
minimum(S)
```

Restituisce l'elemento di $S$ con la chiave più *piccola* ( non rimuove $S$ )
#### Estrazione del Minimo

```cpp
extract_min(S)
```

Restituisce ed elimina da $S$ l'elemento di $S$ con chiave più *piccola*
#### Decrease 

```cpp
decrease(S, x,k)
```

Pre-condizione : $x$ deve esistere in $S$ , $x \in S$
Post-condizione : *Decrementa* il valore della chiave di $x$ al nuovo valore $k$ che si suppone si al più pari al valore corrente della chiave di $x$ ( $k\le$ chiave di $x$ )

### Implementazione di code di massima priorità con max_heap

#### Massimo

```cpp
heap_maximum(Heap A)
	if A.heap_size < 1
		error "heap underflow"
	return A[1]
```

L'algoritmo ritorna il primo elemento dell'heap in quanto , per via delle caratteristiche del *max_heap* , questo sarà il valore massimo presente all'interno dell'heap , avendo prima controllato ovviamente che la dimensione dell'array sia $\ge 1$ 

**Complexity** : $O(1)$
#### Estrazione del massimo

```cpp
heap_extract (Heap A) 
	if A.heap_size < 1
		error "heap underflow"
	max = A[1] 
	A[1] = A[A.heap_size] // tolgo la foglia più a destra e la sostituisco alla root , in questo modo la poprietà di albero quasi completo è ancora rispettata  
	A.heap_size = A.heap_size - 1
	max_heapify(A , 1) // per mantere le proprietà di max_heap 
	return max
```

L'algoritmo sostituisce il massimo con l'ultimo elemento del *max_heap* , in modo da mantere la proprietà di albero quasi completo , aggiornando la lunghezza dell'heap e chiamando `max_heapify()` sulla root per ripristinare la proprietà di *max_heap*

**Complexity** : $O(\log n)$ data dalla chiamata e `max_heapify()` applicata sulla radice dell'albero
#### Increase

```cpp
heap_increase_key(Heap A , Node i , Elem Key ) // i è un indice 
	if Key < A[i] 
		error "nuova chiave più piccola di quella corrente" 
		// per via della precondizine che Key >= A[i]
	A[i] = Key // assegno nuovo valore a A[i]
		while i > 1 and A[parent(i)] < A[i]
			scambia A[i] e A[parent(i)] 
			i = parent(i)
```

L'algoritmo controlla che la pre-condizione sia soddisfatta ( $Key \ge A[i]$ ) 
Aggiorna il nodo con la $Key$ , poiche la $Key$ soddisfa la pre-condizione l'unica violazione delle prorpietà del *max_heap* può avvenire solo verso la root ( ossia potrebbe essere maggiore del suo parent )
##### Correttezza

**Invariante** : $INV\sim$ L'array `A[1 ... A.heap_size]` soddisfa la proprietà *max_heap* tranne una possibile violazione in posizione `A[i]` poichè potrebbe essere $\ge$ di `parent(i)`

**Conclusione** : 
	Abbiamo 2 casi in cui $\lnot Guardia$ è `{cpp}true` :
+ `{cpp}i==1`
	Se $i$ è la radice non ci può essere nessuna violazione
+ `{cpp}A[parent(i)]>=A[i]`
	L'unica violazione potrebbe essere in $i$ , non è possibile poichè la negazione della guardia ci garantisce che non si è verificata nessuna violazione
##### Complessità

Il tempo di esecuzione è $O(\log n)$ poichè il caso peggiore in cui dobbiamo verificare che potrebbe esserci stata una violazione è quando abbiamo modificato un nodo folgia per il quale al massimo dovremmo correggere la violazione fino alla root dell'albero , percorrendo un percorso di lunghezza $h=\log n$  

#### Insert

```cpp
max_heap_insert(Heap A , Elem Key)
	A.heap_size = A.heap_size + 1
	A[A.heap_size] = -infinito
	heap_increase_key(A, A.heap_size, Key)
```

Aumentiamo la size dell'heap di 1 elemento , poniamo nell'ultimo elemento dell'array un elemento sentinella ( $-\infty$ ) , sul quale chiameremo `heap_increase_key()` ( se non mettessimo $-\infty$ la funzione uscirebbe subito poichè non rispetta la condizione $Key\ge A[i]$ ) con `Key` il valore che vogliamo sostituire , `heap_increase_key()` rispistinerà quindi in caso lo stato di *max_heap* in caso di violazioni

**Complexity** : $O(\log n)$ per via della chiamata di `heap_increase_key()`

#### Conclusione

Un *heap* può svolgere le operazioni delle code di priorità con complessità $O(\log n)$
# Secondo Semestre
## Ordinamenti Lineari

### Limiti degli algoritmi basati sui confronti

Gli algoritmi visti in precedenza hanno complessità : 
+ *Insertion Sort* : $O(n^2)$
+ *Merge Sort* : $O(n\ \log n)$
+ *Quick Sort* : $O(n^2)$ nel caso peggiore , $O(n\ \log n)$ nel caso medio 
+ *Heap Sort* : $O(n\ \log n)$

Possiamo trovare algoritmi di ordinamento più efficenti ? 

Dipende dal modello di computazionale , gli algoritmi fin'ora incontrati usano come modello computazionale il *confronto* , cerchiamo di definire il limite inferiore del tempo di esecuizione per questo tipo di algoritmi 

Partiamo da delle intuizioni : 
Il limite inferiore *ideale* sarebbe $\Omega(n)$ in quanto almeno tutti gli elementi dobbiamo visitarli , questo però non corrisponde alla realtà 

Cerchiamo ora di trovare il *limite inferiore* per gli algoritmi basati sul confronto ( scopriremo che sarà $\Omega(n\ \log n)$ )

Questo possiamo dimostrarlo attraverso gli **alberi di decisione** , questi sono una struttura dati che ci permette di astrarre gli algoritmi basati sul confronto

Ogni *nodo* è composto dai confronti che dobbiamo svolgere tra 2 indici ( $i$ , $j$ ) di un array 
Ogni *foglia* è composta da una permutazione degli indici dell'array di partenza tale per cui l'array in input risulti ordinato
Il *sottoalbero sinistro* da i sucessivi confronti se $a_i \le a_j$
Il *sottoalbero destro* da i sucessivi confronnti se $a_i \gt a_j$ 

Facciamo un esempio per l'ordinamento di un array di tre elementi : 

![[DecisionTree.excalidraw]]

Se vogliamo per esempio ordinare l'array $<6,8,5>$ eseguiremo i seguenti confronti :

![[DecisionTree(6,8,5).excalidraw]]

1. Confrontiamo il $6$ e l' $8$ , essendo che $6 \le 8$ si va sul sottoalbero *destro*
2. Confrontiamo l'$8$ e il $5$ , essendo che $8>5$ si va sul sottoalbero *sinistro*
3. Confrontiamo il $6$ con il $5$ , essendo che $6>5$ si va sul sottoalbero *sinistro* dove troviamo al soluzione : $<5 , 6 , 8>$

Possiamo dire che dato un qualsiasi algoritmo di ordinamento per confronti : 
+ Possiamo costruire un albero di decisione per ogni $n$ ( lunghezza dell'input )
+ L'albero modella tutte le possibili *tracce d'esecuzione* ( ossia ciascun cammino che parte dalla radice ed arriva ad una foglia ) 
+ Il tempo d'esecuzione ( il numero di confronti ) è la lunghezza della traccia
+ Il tempo d'esecuzione nel caso peggiore è quindi l'*altezza dell'albero* ( la traccia più lunga )

Per determinare il limite inferiore degli algoritmi basati sul confronto è sufficente trovare il limite inferiore sulle altezze di tutti gli alberi di decisione

Il numero di *foglie* presenti su di un albero devono essere *almeno* le permutazioni di $n$ elementi , per definizione di permutazioni allora il numero di foglie è $\ge n!$ 

>[!note]
>Se il numero di foglie fosse $< n!$ significherebbe che per un determinato input non c'è una soluzione e questo è impossibile

**Lemma** : Un qualsiasi albero binario di altezza $h$ ha *al più* $2^h$ foglie 

Questo *lemma* può essere dimostrato per induzione su $h$ 

**Caso Base** : 
	Un albero di altezza uguale a 0 ( $h=0$ ) rappresenta un albero che ha un solo nodo , la radice che è anche l'unica foglia
	 Allora : $f = 1 \le 2^0 = 1\quad \text{c.v.d.}$ 

**Passo Induttivo** : 
	Assumiamo che per alberi binari di altezza $k < h$ il numero di foglie è $\le 2^k$ e lo dimostro per $h$Sia $r$ la radice dell'albero $T$ di altezza $h$ : 
		Se $r$ ha un solo figlio allora il numero di foglie di $T$ è uguale al numero di foglie dell'albero $T_1$ ( il suo unico sottoalbero ) , avremo quindi : 
		$$f=f_{T_1}\le2^{h-1}\le 2^h \quad \text{c.v.d.}$$ ![[Pasted image 20240212144342.png]]
		Se invece $r$ ha due figli allora il numero di foglie di $T$ è uguale alla somma delle foglie di $T_1$ e $T_2$ e poichè $T_1$ ha altezza $h_1<h$ e $T_2$ ha altezza $h_2<h$ 
		![[AltezzaAlberoDecidione.excalidraw]]
	Quindi $f\le 2^h\ ,\quad \text{c.v.d.}$

Possiamo ora esprimere il seguente **Teorema** : 

Qualsiasi Algoritmo di ordinamento per confronti richiede $\Omega(n \log n)$ confronti nel caso peggiore

**Dimostrazione** :  
Dobbiamo determinare l'altezza di un albero di decisione dove ogni permutazione appare come foglia 
Si cosideri un albero che abbia $h$ come altezza e $l$ come numero di foglie 

Avremo che : $$n!\le l \le 2^h$$ Applichiamo il logaritmo : 
$$\log n! \le \log l \le h$$
Da qui possiamo ricavare che $h \ge \log n!$

Per semplificare $n!$ utilizziamo l'approssimazione di *Sterling* , questa ci dice che :
$$n! = \sqrt{2\pi}\bigg(\frac n e\bigg)^n\bigg(1+\Theta\bigg(\frac 1n\bigg)\bigg)$$
Di questa formula ci interessa solamente il termine che asintoticamente domina ossia $\big(\frac n e\big)^n$ 
Possiamo quindi sostituire :
$$h\ge \log \bigg(\frac n e\bigg)^n\ge n \log \bigg(\frac n e\bigg)\ge n (\log n - \log e)\ge n \log n$$
Abbiamo quindi dimostrato che $h$ è limitato inferiormente da $n \log n$ 

Possiamo concludere che il limite inferiore di complessità per gli algoritmi basati sul confronto è $\Omega(n \log n)$

**Corollario** : 
	*HeapSort* e *MergeSort* sono algoritmi di ordinamento per confronti asintoticamente *ottimali* , questo poichè il limite superiore di esecuzione ( $O(n \log n)$ ) di questi algoritmi coincide con il limite inferiore degli algoritmi basati sul confronto 
### Counting Sort

Per ricavare una complessità minore degli algoritmi basati sul confronto non possiamo svolgere confronti all'interno dell'algoritmo di sorting , per evitare ciò abbiamo bisogno di fare delle *assunzioni* 

Nel caso del **Counting Sort** , esso è applicabile solo se i dati in input rispettano la seguente *assunzione* : I numeri da ordinare sono interi in un intervallo che va da 0 a $k$ per qualche intero $k$

+ **Input** : $A[\ 1, \dots , n\ ]$ dove $A[\ j\ ]\in[\ 0,\dots,k \ ]$ ; $n$ e $k$ sono parametri dell'algoritmo    
+ **Output** : $B[\ 1,\dots, n \ ]$ una permutazione ordinata di $A$ 
+ **Memoria ausiliaria** : $C[\ 0,\dots, k \ ]$ , vettore delle occorrenze

```c++
countingsort(array A, array B, int n, int k)
	creo C[0,...,k]
	for i = 0 to k
		C[i] = 0
	for j = 1 to n
		C[A[j]]++ // popola vettore delle occorrenze
	for i = 1 to k
		C[i] = C[i] + C[i - 1] // popola vettore delle somme prefisse 
	for j = n down to 1 
		B[C[A[j]]] = A[j] // spostiamo nella posizione corretta 
		C[A[j]]-- // evita sovrapposizioni nel caso di duplicati
```

>[!note] 
>Counting sort in descending order : 
```c
counting_sort(array A, array B, int n, int k)
    creo C[0,...,k]
    for(int i=0;i<k; i++) 
	    C[i] = 0;
    // ASSUMPTION: All elements in arr is < k
    for(int i=0;i<size;i++) 
	    C[A[i]]++;
    for(int i=k-1;i>0;i--) 
	    C[i-1] += C[i];
    for(int j=0;j<size;j++) {
        B[C[A[j]]] = A[j];
        C[a[j]]--;
```

#### Spiegazione

L'algoritmo ha 3 array : 
+ $A$ : l'array da ordinare 
+ $B$ : l'array risultato , contenente gli elementi di $A$ ordinati in modo crescente 
+ $C$ : un vettore ausiliario delle occorrenze , contenente $k+1$ elementi ( da $0$ a $k$ )

Il secondo ciclo for incrementa gli elementi del vettore delle ricorrenze , alla fine di questo ciclo l'elemento in posizione $i$-esima del vettore $C$ contiene il numero di volte che il numero $i$ compare in $A$ 
$$C[\ i\ ]=|\{ x\in \{1,\dots,n\} \ \text{t.c.} \ A[\ x \ ]= i \ \}|$$
Il terzo ciclo compie il calcolo delle *somme prefisse* sugli elementi del vettore delle occorrenze : somma ad ogni elemento del vettore delle occorrenze il numero di occorrenze dell'elemento precedente
Questo ci permette di capire quanti elementi minori o uguali di $i$ sono presenti in $A$ dove $i$ è l'indice che scorre il vettore delle occorrenze e quindi assume tutti i valori contenuti in $A$ 
$$C[\ i\ ]=| \{ x\in \{ 1,\dots,n \}| \ A[\ x\ ]\le i\ \} |$$
L'ultimo ciclo è quello che riempie l'array di output 
Abbiamo a questo punto un vettore delle occorrenze che contiene la somma comulativa delle occorrenze dei valori minori o uguali all'indice in cui ci posizioniamo 
Scorriamo quindi il vettore in input $A$ dalla fine all'inizio , sia $x$ il numero $i$-esimo presente in $A$ e $y$ il numero di occorrenze in $A$ di valori minori o uguali ad $x$ , possiamo quindi inserire $x$ nel vettore $B$ in posizione $y$ ( poichè sono sicuro che avremo almeno $y$ altri numeri prima di $x$ minori o uguali a $x$ ) 

>[!note]  
>per assicurarci che inseriamo correttamente occorrenze ulteriori di $x$ ci basterà decrementare di $1$ $y$  
#### Complessità

+ Il primo ciclo compie $k$ interazioni : ha costo $\Theta(k)$
+ Il secondo ciclo compie $n$ interazioni : ha costo $\Theta(n)$
+ Il terzo ciclo compie $k$ interazioni : ha costo $\Theta(k)$
+ Il quarto ciclo compie $n$ interazioni : ha costo $\Theta(n)$

Il tempo complessitvo d'esecuzione é : 
$$T(n)=\Theta(k)+\Theta(n)+\Theta(k)+\Theta(n) = \Theta(k+n)$$
>[!note]
>Per poter utilizzare in modo efficente questo algoritmo è importante notare che $k=O(n)$ in questo modo $T(n)=\Theta(n)$ 
>Altrimenti se all'interno dell'array originale abbiamo un numero come : $k=n^3$ la complessità diventa $T(n)=\Theta(n^3+n)=\Theta(n^3)$ che non e efficente

#### Osservazioni

+ Per rendere *stabile* l'algoritmo dobbiamo iniziare la lettura di $A$ dalla fine
+ Se l'intervallo contiene valori negativi possiamo ricondurci alla assunzione iniziale traslando l'array ( tenendo sempre presente la nota precedente )
	$$[-n,M]\rightarrow[0,M+n]$$
#### Esempio di Esecuzione

![[CountingSort.excalidraw]]
### Radix Sort

Il *Radix Sort* ci permette di estendere i casi di utilizzo del *Counting Sort*

**Assunzione** : Tutti i numeri da ordinare sono composti da $d$ cifre dove la cifra in posizione 1 è la cifra meno significativa mentre la cifra in posizione $d$ è la più significativa

*Intuizione* : Per ogni colonna di cifre ( l'array è posto in verticale ) si applica un algoritmo di ordinamento *stabile*

```c++
radixsort(array A, int d)
	for i = 1 to d
		// usa un algoritmo di ordinamento stabile per ordinare l'array A sulla cifra i
```

Come algoritmo *stabile* si utilizza una *Counting Sort*

**Esempio** : 

![[RadixSort.excalidraw]]

Per la correttezza dell'algoritmo è *necessario* che l'algoritmo ausiliario sia *stabile*
#### Correttezza 

La *dimostrazioni* avviene per induzione sulla colonna da ordinare 

**Caso Base** : 
	se $i=1$ ordino l'unica colonna e non devo fare altro poichè i numeri sono costituiti da una sola cifra ( l'array finale risulta ordinato )

**Passo Induttivo** : 
	*Assumiamo* ( **Ipotesi Induttiva** ) che le cifre delle colonne da $1,\dots,i-1$ siano ordinate e dimostriamo che un algoritmo *stabile* sulla colonna $i$ lascia le colonne da $1$ a $i$ ordinate

Dobbiamo considerare 2 casi : 
+ Se due cifre in posizione $i$ sono uguali per la *stabilità* rimangono nello stesso ordine e per l'ipotesi induttiva sono ordinate ( poichè le colonne $1,\dots,i-1$ sono ordinate )
+ Se due cifre in posizione $i$ sono differenti allora l'algoritmo di ordinamento sulla colonna $i$ le ordina e le mette in posizione corretta ( risultano ordinate )

In entrambi i casi il risultato finale è ordinato abbiamo quindi dimostrato che l'algoritmo è corretto 
#### Complessità

>[!lemma]
>Dati $n$ numeri costituiti da $d$ cifre , dove ogni cifra può avere fino a $k$ valori possibili

La complessità della procedura *radixsort( )* sarà quindi $\Theta(d\cdot(n+k))$ se l'ordinamento *stabile* utilizzato dalla procedura impiega un tempo $\Theta(n+k)$

**Dimostrazione** :
+ Per ogni iterazione il costo è dato da $\Theta(n+k)$
+ Il ciclo `{c}for` compie $d$ iterazioni
+ Di conseguenza il costo totale è $\Theta(d\cdot(n+k))$

##### Osservazioni

L'algoritmo viene eseguito in tempo lineare se $k=O(n)$ ( il tempo di esecuzione diventa quindi $\Theta(d\cdot n)$ ) e se $d$ è costante questo porta la complessità a $\Theta(n)$

#### Caso di Studio

Consideriamo una *word* ( un numero intero rappresentato da $b$ bit ) di lunghezza $b=32$ bit se applicassimo il *Radix Sort* alla *word* questo eseguirebbe il *Counting Sort* 32 volte su cifre che possono avere come valore solo $0$ o $1$ , questo risulta **costoso**

Spezziamo quindi ogni *word* in 4 parti ognuna costituita da 8 bit ( $r=8$ ) , avremo quindi 4 cifre ( $d=4$ ) ognuna delle quali varia tra $[0,\dots,2^k-1]$ , in questo caso avremo $k=255$ 

>[!lemma]
>Dati $n$ numeri di $b$ bit e un intero positivo $r\le b$ la procedura di *radixsort( )* ordina in correttamente i numeri in tempo  :
>$$\Theta\bigg(\frac b r \cdot( n + 2^r )\bigg)$$  

Come sciegliamo $r$ in modo da minimizzare il tempo di esecuzione :
+ Sicuramente $r\le b$ 
+ Vogliamo che $r$ sia grande ( per minimizzare il moltiplicatore ) ma non grande al punto da rendere $2^r \gg n$

Distinguiamo quindi in 2 casi : 
+ Se $b \lt \lfloor \log n \rfloor$ allora per qualche valore $r\le b$ si ha $(n+2^r)=O(n)$
	In questo caso conviene sciegliere $r$ il più grande possibile cioè $b$ , si ottiene il seguente tempo di esecuzione : 
	$$\frac b b (n+2^b)=\Theta(n) \quad 2^b \lt n$$
+ Il caso più frequente , però , vede la seguente condizione $b\ge \lfloor\log n\rfloor$ 
	In questo caso conviene scegliere $r$ tale che sia massimo ma sotto la condizione che $n\ge 2^r \implies r = \lfloor\log n \rfloor$ , otteniamo quindi il tempo di esecuzione risultante :
	$$\frac b {\log n}(n + 2 ^{\log n})=\frac b {\log n}(n+n)=\frac b {\log n}(2n)=\Theta\bigg(\frac b {\log n} n\bigg)$$

# Tabelle Hash

## Tabelle ad indirizzamento diretto

Una tabella ad induruzzamento diretto viene utilizzata per memorizzare dati indicizzati da una *chiave* ( un numero ) 

**Caratteristiche** : 
+ Sono costituite da un insieme dinamico al fine dell'implementazione delle operazioni di *inserimento* , *ricerca* e *cancellazione*
+ Ogni elemento ha una *chiave* estratta dall'universo $U=\{ 0,1,\dots,w-1 \}$ dove $w$ non è troppo grande
+ Nessun elemento ha la stessa *chiave*

La struttura dati che ci permette di gestire questo tipo di dato è un *array* $T$ con posizioni $[\ 0,\dots ,w-1\ ]$ dove $w$ corrisponde alla dimensione dell'universo delle chiavi rappresentato da $U$

![[Pasted image 20240214123718.png]]

Ogni posizione dell'array corrisponde ad una *chiave* in $U$ , se nella tabella è presente l'elemento $x$ con *chiave* $k$ allora $T[\ k\ ]$ contiene un puntatore a $x$ altrimenti se la tabella non contiene l'elemento $x$ avremo che $T[\ k\ ]=NIL$ 
### Operazioni

Vediamo ora l'implementazione delle operazioni di *ricerca* , *inserimento* e *cancellazione* :

**Ricerca** :
```c++
direct_access_search(T, k)
	return T[k]
```
Complessità : $O(1)$

**Inserimento** :
```c++
direct_access_insert(T, x)
	T[x.Key] = x
```
Complessità : $O(1)$

**Cancellazione** :
```c++
direct_access_delete(T, x)
	T[x.Key] = NIL
```
Complessità : $O(1)$

### Conclusioni

**Vantaggi** : 
+ Il tempo di esecuzione delle operazioni disponibili sulle tabelle ad indirizzamento diretto è $O(1)$

**Svantaggi** : 
+ Elevato spreco di memoria 
	Lo spazio utilizzato è legato alla dimensione del dominio universale ( $w$ ) non ad $n$ ( i dati memorizzati ) 
	Il dominio è molto grande ma il numero di dati da memorizzare è piccolo $n\ll w$
## Tabelle Hash

Le *tabelle Hash* sono un'alternativa alle tabelle ad indirizzamento diretto senza ereditare però l'elevata complessità spaziale ( in questo caso sarà proporzionale al numero di elementi memorizzati non al dominio )

Non utilizziamo la *key* come indice ma applico una funzione *hash* ( $h$ ) che ritorna un indice che riduce il range di variabilità dell'*indice* 

La funzione *hash* è una funzione definita nel seguente modo : $h= U \rightarrow \{ 0,1,\dots, m-1 \}$ 
Significa che ha come dominio l'universo $U$ e restituisce un intero compreso nell'intervallo $[\ 0,m-1\ ]$ dove $m$ la dimensione della tabella è generalmente molto più piccola di $|U|$ 

![[Pasted image 20240214170244.png]]

Potrebbe però avvenire che $2$ *key* differenti vengano mappate nella stessa cella ( **collisione** ) 

Quando avvengono le *collisioni* : 
+ $|U|\gt m$ : in questo caso possono avvenire delle collisioni
+ $|K|\gt m$ : in questo caso sicuramente ci sono collisioni ( ossia ci sono più chiavi che elementi dell'array della hash table )

Le collisioni si possono risolvere in 2 modi :
+ **Concatenamento** : Ad ogni cella corrisponde una lista di elementi contenenti tutte le chiavi mappate con lo stesso indice
+ **Indirizzamento aperto** : Mappiamo una chiave già occupata un una cella differente
### Concatenamento

Inseriamo tutti gli elementi associati ad una stessa cella in una lista concatenata 
La cella $j$ contiene un puntatore alla testa della lista se sono memorizzati degli elementi , altrimenti si memorizza $NIL$ 

##### Operazioni con il concatenamento 

**Inserimento** :
```c++
chained_hash_insert(T, x)
	// inserice x in testa alla lista T[h(x.Key)]
```
Tempo di esecuzione : $O(1)$ poichè :
+ L'inserimento in testa in una lista concatenata è *costante*
+ Assumiamo che il calcolo della funzione *hash* sia costante
+ Si suppone che l'elemento da inserire non sia già presente nella lista
>[!note]
	>Se potesse essere presente dobbiamo per forza *cercare* l'elemento all'interno della lista concatenata e sucessivamente fare un update del suo valore se presente o un insert altrimenti , il costo totale sarebbe dato dal costo della ricerca

**Ricerca** : 
```c++
chained_hash_search(T, k)
	// ricerco un elemento con chiave k nella lista T[h(k)]
```
Il tempo di esecuzione nel caso peggiore è proporzionale alla lunghezza della lista nella cella $h(k)$ ( see [[#Analisi dell'Hashing con concatenamento]] )

**Cancellazione** :
```c++
chained_hash_delete(T, x)
	// cancella x della lista T[h(x.Key)]
```

In questa implementazione $x$ è un puntatore all'elemento , non è quindi necessario svolgere un'operazione di *search* ( se fosse una *key* allora sarebbe necessaria ) 
Inoltre , per fare sì che la complessità sia costante dobbiamo utilizzare una *lista doppiamente concatenata* , questa ci permette di non dovere trovare il predecessore per cambiare i puntatori 
#### Analisi dell'Hashing con concatenamento

Studiamo il tempo medio di ricerca di un elemento con *chiave* $K$ 

Il *caso peggiore* si verifica quando tutte le chiavi sono mappate su una stessa cella , questa avrà una lista di lunghezza $n$ e il tempo di esecuzione di conseguenza è $O(n)$ più il tempo necessario allo svolgimento della funzione di hashing 

La complessità per il *caso medio* dipende da come la funzione di hashing distribuisce le chiavi tra le $m$ celle 

**Hasing Uniforme e Indipendente** : 
	Qualsiasi elemento ha la stessa probabilità di essere mandato in una qualsiasi delle $m$ celle indipendentemente dalle celle in cui sono mandati gli altri elementi 
	$$\forall i \in [0,\dots,m-1], \quad Q(i)=\frac1m$$
Dove $Q(i)$ indica la *probabilità* ( ideale ) che una chiave finisca nell'$i$-esima cella 

**Fattore di carico** di una tabella hash costituita da $m$ celle e $n$ chiavi è $\alpha=\frac nm$ ( può essere : $\alpha < 1$ , $\alpha = 1$ o $\alpha > 1$ , in questo caso potrebbero degradare le prestazioni )

Ora calcoliamo con le precedenti osservazioni la lunghezza media di una lista $T[\ j\ ]$ indicando con $n_j$ la sua lunghezza : 
$$
E[n_j] = \frac{n_0+n_1+\dots + n_{m-1}}{m} = \frac n m = \alpha 
$$
Possiamo dire quindi che il *fattore di carico* rappresenta il n° medio di elementi memorizzati in una lista

Ora *ipotizziamo* che la funzione di hash sia calcolata in tempo $O(1)$ 

>[!Important] **Teorema**
>In una tabella hash in cui le collisioni sono risolte con il metodo del concatenamento una *ricerca senza successo* richiede tempo $\Theta(1+\alpha)$ nel caso medio utilizzando l'ipotesi di *hashing uniforme e indipendente*

**Dimostrazione** ( intuizione ) : 
+ Calcolare $j=h(k)$ costa $O(1)$ ( per ipotesi )
+ Accedo alla lista $T[\ j\ ]$ , costo $O(1)$
+ Scorro la lista $T[\ j \ ]$ , questa operazione costa $\Theta(\alpha)$ ( visto che è senza successo devo scorrere la lista completamente )

Il tempo complessivo di esecuzione è quindi $\Theta(1+\alpha)$ ( l'1 deriva dal calcolo della funzione hash )

>[!Important] **Teorema**
>In una tabella hash in cui le collisioni sono risolte con il metodo del concatenamento una *ricerca con successo* richiede tempo $\Theta(1+\alpha)$ nel caso medio utilizzando l'ipotesi di *hashing uniforme e indipendente*

**Dimostrazione** ( intuizione ) : 
+ Calcolare $j=h(k)$ costa $O(1)$ ( per ipotesi )
+ Accedo alla lista $T[\ j\ ]$ , costo $O(1)$
+ Scorro la lista fino a trovare $k$ , questa operazione *mediamente* costa $\Theta(\frac \alpha 2 )$

Il tempo complessivo di esecuzione sarà quindi : $\Theta(1+\frac \alpha 2)=\Theta(1+\alpha)$

**Interpretazione** 
	Essendo il tempo di esecuzione del caso medio di ricerca $\Theta(1+\alpha)$ 
	Se $n=O(m)$ il numero delle celle è *proporzionale* al numero di elementi da memorizzare :
	$$\alpha = \frac n m = \frac {O(m)}{m}=O(1)$$
	Avremo quindi che anche la ricerca è *costante* ( $\Theta(1+ \alpha)=\Theta(1+O(1))=\Theta(1)$ )

>[!warning]
>Quando $\alpha$ cresce oltre una certa soglia ( $\gt2$ ) dobbiamo raddopiare le dimensioni della tabella hash e reinserire le *chiavi* ripassate attraverso la funzione hash in modo da recuperare la complessità $\Theta(1)$ , altrimenti la complessità potrebbe diventare maggiore : $\Theta(1+\frac {3m}{m}) = \Theta(4)$ che è ovviamente inefficente rispetto a $\Theta(1)$
#### Funzioni hash

Una *funzione hash* è una funzione che spezzetta la nostra chiave e la ricompone casualmente in modo tale da ottenere un intero che risulti più casuale possibile 
Lo scopo è quello di *distribuire* in modo *uniforme* gli elementi nella nostra tabella 

>[!example]
>Le chiavi sono numeri reali $k$ *casuali* e distribuiti in modo *uniforme* nell'intervallo $0\le k < 1$ 
>Se abbiamo queste condizioni allora la seguente *funzione hash* offre *prestazioni ottimali* : $$h(k)=\lfloor k\cdot m \rfloor$$
>Funzione che soddisfa la condizione di *hashing uniforme semplice*

Questa però è una condizione ottimale , utilizzeremo quindi delle euristiche
###### Metodo della divisione
$$h(k)=k\ \text{mod} \ m \quad \ \text{resto della divisione tra $k$ e $m$}$$
Dove $m$ è la dimensione della tabella 

+ **Vantaggi** : 
	Semplice da realizzare 
+ **Svantaggi** : 
	La dimensione della tabella risulta essere un *dato critico*
>[!warning]
>I valori di $m$ devono essere scelti in modo accurato
>+ $m$ non può assumere valori pari a potenze di 2 : 
>	Se $m=2^p$ allora $h(k)$ rappresenta i $p$ bit meno significativi di $k$ , questo potrebbe portare ad un maggior numero di collisioni 

Una buona scielta per $m$ è un *numero primo* non troppo vicino a una potenza esatta di 2 o di 10

>[!example]
>Vogliamo memorizzare $n=2000$ chiavi prevedendo una media di 3 collisioni 
>Poniamo come dimensione della tabella un numero primo vicino a $\frac {2000}3=666.\overline6$ mantenendo le caratteristiche menzionate prima 
>Scegliamo quindi $m=701$ che ci permette di spargere in modo opportuno e ben distribuito gli elementi della tabella 
###### Metodo della moltiplicazione
$$h(k)=\lfloor m \cdot k \rfloor , \quad \ \text{con $0\le k <1$}$$
Data una chiave $k\in U$ decidiamo di trasformarla in un numero $\overline k \in [ 0,1 [$ per poi applicarci la funzione hash

>[!note] Algoritmo
>+ Fisso una costante $A$ , $0<A<1$
>+ Calcolo $k\cdot A$ ( restituisce una parte intera e una frazionaria )
>+ Estraiamo la parte frazionaria calcolata precedentemente : 
>$$k\cdot A\mod{1}=k\cdot A -\lfloor k\cdot A \rfloor \in [0,1]$$

La funzione di hashing diventerà quindi : 
$$h(k)=\lfloor m\cdot (k\cdot A \mod 1) \rfloor$$
+ **Vantaggi** : 
	+ Il valore di $m$ non è critico 
	+ Potenzialmente funzionano bene tutti i valori di $A$
	+ In particolare si utilizza il valore inverso del rapporto aureo ( scoperto da Donald Knuth )
	$$A\simeq \frac{\sqrt5 -1}{2}=0.618033\simeq \hat\Phi$$

**Semplificare il calcolo della funzione hash** : 

Sia $w$ la lunghezza di una parola di memoria e $k$ entri in una singola parola di memoria ( al più $2^w$ ) 
Scielgo un intero $q$ , $0<q<2^w$ , e $m=2^p$ ( $0\le p\le w$ ) , poniamo quindi $A=\frac q {2^w}<1$
Calcoliamo quindi : 
$$\overline k=k\cdot A=\frac{k\cdot q}{2^w}$$
$A$ è un numero con una parte frazionaria e una parte decimale

![[Pasted image 20240219133805.png]]

Chiamiamo ora la parte intera con il nome di $r_1$ e $r_0$ la parte decimale , a questo punto possiamo riscrivere 
$$k\cdot q=r_1+\frac{r_0}{2^w}$$
Visto che siamo interessati alla parte frazionaria possiamo scrivere la funzione hash nel seguente modo : 
$$h(k)=\bigg\lfloor 2^p\cdot\bigg(\frac{k\cdot q}{2^w} \mod 1\bigg) \bigg\rfloor$$
Ossia sono i $p$ bit più significativi della parola meno significativa del prodotto di $k\cdot p$ 
Possiamo quindi riscriverla più semplicemente : 
$$h(k)=(k\cdot q \mod 2^w)>> (w-p)$$
Eseguiamo lo shift a destra di $w-p$ posizioni in modo da inserire degli 0 nelle posizioni lasciate libere in modo che i $p$ bit più significativi di $r_0$ si spostino nelle posizioni $p$ più a destra
###### Hashing Randomizzato

Esistono insieme di *funzioni hash* ben costruite tra le quali il programma scieglie casualmente quale utilizzare durante l'esecuzione , in questo modo non è possibile che un attacante sappia la funzione di hash utilizzata per protare a pessime prestazioni  
### Indirizzamento aperto

Le tabelle hash ad indirizzamento aperto non utilizzano una struttura dati esterna per gestire le collisioni

>[!note] Idea
>Tutti gli elementi vengono memorizzati nella tabella hash stessa 

Ogni cella contiene un elemento dell'insieme oppure $NIL$ 

**Cercare un elemento**

Per cercare un elemento con $key=k$ : 
1. Calcolo $h(k)$ ed esamino la cella con indirizzo $h(k)$ : *ispezione*
2. Se la cella $h(k)$ contiene la chiave la ricerca ha *successo* . Se la cella contiene $NIL$ la ricerca termina con *insuccesso*
3. Se la cella dovesse contenere una chiave che non è $k$ allora bisogna calcolare l'indice di un'altra cella in base alla chiave $k$ e all'*ordine di ispezione* cioè il numero di *ispezioni* compiute fino a questo momento ( al massimo $m$ ispezioni , ho scorso tutta la tabella ) 
4. Si continua la scansione della tabella finchè : 
	1. Non si trova la chiave $k$ ( *successo* )
	2. Si trova una cella che contiene $NIL$
	3. Ho eseguito $m$ ispezioni senza successo ( *insuccesso* ) ( ho scorso l'intera tabella )

La funzione hash ora deve prendere 2 argomenti : $h(k,i)$ rappresenta la posizione della chiave $k$ dopo $i$ ispezioni fallite dove inizialmente avremo $i=0$ 
$$h(k,i):U\times \{ 0,1,\dots,m-1 \}\rightarrow \{ 0,1,\dots,m-1 \}$$
>[!note] Precondizione
>Per ogni possibile chiave $k\in U$ la sequenza di ispezioni $<h(k,0),h(k,1),\dots,h(k,m-1)>$ deve essere una permutazione di $<0,1,\dots,m-1>$ ossia gli indici della tabella , in modo che ogni posizione della tabella hash possa essere considerata come possibili cella in cui inserire una nuova chiave mentre la tabella si riempie
#### Operazioni

>[!note] Ipotesi
>Per semplificare il codice supponiamo che gli elementi contengono solo la chiave , ossia che non abbiano dati satellite
###### Insert

```c++
hash_insert(T, k)
	i = 0
	trovata = false
	repeat // tipo un ciclo do while
		j = h(k, i)
		if T[j] == NIL
			T[j] = k
			trovata = true
		else 
			i++
	until trovata or i == m
	if trovata
		return j
	else error "overflow della tabella hash"
```

**Post-condizione** :
	Restituisce l'indice della cella dove ha memorizzato $k$ oppure segnala un errore se la tabella è piena

###### Ricerca

```c++
hash_search(T, k)
	i = 0
	trovata = false
	repeat 
		j = h(k, i)
		if T[j] == k
			trovata = true
		else 
			i++ // ispezione sucessiva
	until trovata or i == m or T[j] == NIL
	if trovata
		return j
	else 
		return NIL // non ho trovato la key
```

**Post-condizione** :
	Retituisce $j$ se la cella $j$ contiene la chiave $k$ oppure $NIL$ se la chiave $k$ non si trova nella tabella $T$

**Osservazioni**
	Il motivo per cui abbiamo `{c} i==m or T[j]==NIL` è perchè se abbiamo fallito troppe volte ( `m` volte poichè è il massimo numero di elementi che possiamo inserire nella tabella hash ) ad un'ispezione oppure abbiamo trovato `NIL` ossia siamo arrivati nel posto corretto ma non c'è nessun elemento ossia che l'elemento da cercare non è presente all'interno dell hash 
##### Cancellazione 

La *cancellazione* è il problema principale dell'indirizzamento aperto 
Vediamo un esempio : 
>[!example]
>![[Cancellazione.excalidraw]]

**Soluzione** : 
	Aggiungiamo una chiave speciale per inficare una cella cancellata : `DELETED`

A questo punto dobbiamo modificare `{c}hash_insert()` nel seguente modo :
```c++
hash_insert(T, k)
	i = 0
	trovata = false
	repeat // tipo un ciclo do while
		j = h(k, i)
		if T[j] == NIL or T[j] == DELETED // aggiunta dell'or
			T[j] = k
			trovata = true
		else 
			i++
	until trovata or i == m
	if trovata
		return j
	else error "overflow della tabella hash"
```

A questo punto non necessitiamo di modificare `{c}hash_search()` poichè il valore di `{c}DELETED` sarà sempre differente da tutte le chiavi presenti all'interno dell'universo del discorso , ossia continueremo la ricerca della chiave `k` 

**Svantaggio**
	Il tempo di ricerca non dipende più dal *fattore di carico* : $\frac n m$ , avremo infatti che in presenza di un alto numero di cancellazioni la *search* risulterà essere molto più complessa , per questo quando abbiamo molte cancellazioni non si usa l'indirizzamento aperto

#### Funzioni hash

La funzione ideale per l'*hashing* con l'indirizzamento *aperto* è l'hashing **uniforme** : ogni chiave ha la stessa probabilità di avere come sequenza di ispezioni una delle $m!$ permutazioni di $<0,1,\dots, m-1>$ ossia che : 
$$h(k,0)\ \text{si distribuisce uniformemente sulle}\ m\ \text{celle}$$
$$h(k,1)\ \text{si distribuisce uniformemente sulle}\ m-1\ \text{celle}$$
$$\vdots$$
$$\simeq \text{hashing uniforme semplice ad ogni iterazione}$$
Visto che la precedente è una situazione ideale dobbiamo creare delle *approssimazioni* 
##### Ispezione Lineare 

Data una funzione hash ordinaria $h' : U \to \{0,1,\dots,m-1\}$ che sarà una *funzione hash ausiliaria*

Il metodo dell'ispezione lineare sarà : 
$$h(k,i)=(h'(k)+1) \mod m$$
La prima cella esaminata è $T[\ h'(k)\ ]$ se collidiamo continuerà a scandire tutte le celle sequenzialmente fino alla cella $m-1$ ; infine riprende dalla cella $0$ fino alla cella $T[\ h'(k)\ -1]$

![[Pasted image 20240228130453.png]]

>[!example] 
> 
![[Ispezionelineare.excalidraw]]

**Vantaggi** : Facilità di implementazione 

**Svantaggi** : 
+ Presenza di *addensamenti primari* ( ossia file di celle adiacenti occupate che occupano il tempio di ricerca )
+ La prima ispezionata determina l'intera sequenza di ispezioni , questo significa che per ogni chiave ci sono soltanto $m$ sequenze di ispezioni distinte 
+ La probabilità che una cella $j$ , preceduta da $i$ celle occupate , sia accupata risulta essere $\frac {i+1}m$ ( questo poichè ogni cella $i$ può essere occupata con probabilità $\frac 1m$ e $j$ stessa ha probabilità di essere occupata $\implies i+1$ )
>[!todo]
>Understand
>#todo
##### Ispezione quadratica 

Cerchiamo la cella sucessiva attraverso una *funzione quadratica* : 
$$h(k,i)=(h'(k)+c_i\cdot i + c_2\cdot i^2)\mod m$$
Dove : 
+ $h'$ è una funzione hash ausiliaria 
+ $c_1 ,\ c_2$ sono due costanti ( anche reali ) ausiliarie $\neq 0$ che prendono valori compresi tra $0$ e $m-1$ 

L'*hashing quadratico* soffre analogmente alla sua variante lineare della formazione di *addensamenti secondari* : se due chiavi distinte $k_1$ e $k_2$  sono mappate tramite la funzione ausiliaria $h'$ nello stesso valore , cioè $h'(k_1)=h'(k_2)$ allora le due chiavi generano la stessa sequenza di ispezioni ( forma più lieve di *addensamenti primari* )
>[!note]
>Anche in questo caso la prima posizione determina l'intera sequenza di ispezioni e dunque per una chiave ci sono soltanto $m$ sequenze di ispezioni distinte
##### Hashing Doppio
$$h(k,i)=(h_1(k)+i\cdot h_2(k)) \mod m$$
Dove :
+ $h_1$ e $h_2$ sono due funzioni hash ausiliarie e $i$ può assumere tutti i valori da $0$ a $m-1$ . 

$h_1$ serve per determinare il punto di partenza ( non cambia in funzione di $i$ ) mentre $h_2$ serve per determinare il passo delle ispezioni

>[!example]
>Inseriamo nella tabella hash con $m=13$ e con chiavi $69,4,31,43$ 
>Utilizziamo le seguenti funzioni hash : 
>$h_1(k)=k \mod 13$ , $h_2(k)=1 +(k \mod 11)$
>$h(k,i)=(h_1(k)+i\cdot h-2(k))\mod13$
>
![[Doubehashing.excalidraw]]

**Proprietà** : 
	Ogni possibile coppia data da $(h_1,h_2)$ produce una sequenza di ispezioni distinta , questo ci porta a dire che poichè $h_1$ e $h_2$ possono assumere entrambi $m$ valori distinti avremo che la coppia $(h_1,h_2)$ può generare $\Theta(m^2)$ sequenze di ispezione

**Costruire una funzione di hashing doppio**

Necessitiamo che il valore di $h_2(k)$ sia relativamente primo con la dimensione $m$ della tabella hash affinchè questa possa essere ispezionata completamente

Abbiamo qiuindi due possibilità per costruire $h_2(k)$ : 
+ Si può scegliere $m=2^p$ per qualche $p$ . Questo vuol dire che $m$ è un numero pari 
	Definisco quindi $h_2(k)$ in modo che produca sempre numeri dispari in questo modo $m$ e $h_2(k)$sono relativamente primi
	 *Esempio* : $m=2^p$ e $h_2=2\cdot h'(k)+1$ dove $h'(k)$ e $h_1(k)$ è una qualsiasi funzione hash già vista 
+ Si può scegliere $m$ numero primo e definire $h_2(k)$ in modo che generi sempre un intero positivo minore strettamente di $m$ 
	Per esempio scegliamo $m$ primo , $h_1(k)=k \mod m$ e $h_2=1+(k\mod m')$ dove $m'<m$ 

##### Analisi dell'hashing a indirizzamento aperto 

Per analizzare il costo della ricerca e dell'inserimento nel caso di hashing con indirizzamento aperto è necessario porre alcune ipotesi : 
1. Assumiamo di essere in una situazione di *hashing uniforme*
2. Assumiamo che non avvengano operazioni di cancellazione 

Quest'ultima ipotesi è fondamentale per poter compiere l'analisi in termini di *fattore di carico* : $\alpha = \frac n m$ , notiamo inoltre che nel caso di indirizzamento aperto avremo che $0\le \alpha \le 1$  ( il numero massimo di chiavi che possiamo memorizzare è infatti $m$ portando ad un $\alpha$ massimo $=1$ )

##### Costo ricerca senza successo 

>[!important] Teorema
>Nell'ipotesi di hashing uniforme , data una tabella hash a indirizzamento aperto con un fattore di carico $\alpha = \frac n m < 1$ il numero atteso di ispezioni in una *ricerca senza successo* ( caso peggiore ) risulta essere al massimo $\frac 1 {1-\alpha}$

**Dimostrazione** :  

Se $\alpha < 1$ allora ci sono delle celle vuote ( contenenti $NIL$ ) , quindi nel compiere la ricerca ci fermeremo alla prima cella vuota 

1. La probabilità di fare una prima ispezione è $1$ 
2. La probabilità che venga svolta una seconda ispezione equivale alla probabilità che la prima cella sia stata occupata : $\frac n m$ 
3. La probabuilità che venga compiuta una terza ispezione equivale alla probabilità che anche la seconda cella sia stata occupata : $\frac n m \cdot \frac {n-1}{m-1}$

Questo per le $n$ possibili ispezioni ; possiamo notare che visto che $\frac n m=\alpha$ possiamo *maggiorare* ad $\alpha$ tutte le probabilità di ogni ispezione avremo quindi che : 
$$\mathbb{P}[I]=1\quad \mathbb{P}[II]=\alpha\quad \mathbb{P}[III]\simeq\alpha^2\quad \mathbb{P}[IV]\simeq\alpha^3\quad \dots$$
Di conseguenza il valore atteso sarà : 
$$1+\alpha+\alpha^2+\dots \le \sum_{i=0}^{\infty}\alpha^i$$
Notando che la sommatoria si tratta di una serie geometrica possiamo semplificarla nel seguente modo : 
$$\sum_{i=0}^{\infty}\alpha^i=\frac1{1-\alpha}$$
**Interpretazione** : 

Se $\alpha$ è costante una *ricerca senza successo* viene eseguita in tempo $O(1)$ 

>[!example]
>+ Se $\alpha=0.5$ ( tabella piena a metà ) il numero medio di ispezioni è al massimo : 
>$\frac 1 {1-\frac12}=2$
>+ Se $\alpha = 0.9$ ( tabella quasi piena ) il numero medio di ispezioni è al massimo : 
>$\frac 1 {1-\frac{9}{10}}=10$

>[!note]
>Più la tabella è piena più la ricerca è costosa

>[!important] Corollario
>L'*inserimento* di un elemento in una tabella hash a indirizzamento aperto con fattore di carico $\alpha$ richiede in media non più di $\frac 1 {1-\alpha}$ ispezioni nelle ipotesi di hashing uniforme

*Dimostrazione* : 

Un elemento viene inserito all'interno della tabella solo se questa non è satura ossia $\alpha<1$ questo ci permette di utilizzare il *teorema* precedente : 

L'inserimento di una chiave richiede una *ricerca senza successo* ( dobbiamo trovare una posizione vuota dove inserire il nuovo valore ) e sucessivamete l'inserimento della chiave nella prima cella vuota trovata 

Quindi il numero atteso di ispezioni è direttamente legato al numero di ispezioni svolte da una *ricerca senza successo* ossia al massimo $\frac 1 {1-\alpha}$ 
##### Costo ricerca con successo

>[!important] Teorema
>Data una tabella hash a indirizzamento aperto con un fattore di carico $\alpha < 1$ , il numero atteso di ispezioni in una ricerca con successo è al massimo :
>$$\frac 1 \alpha \log \frac1{1-\alpha}$$ 
>Supponendo che l'hashing sia uniforme e che ogni chiave nella tabella abbia la stessa probabilità di essere cercata

**Interpretazione** : 

Se $\alpha$ è costante , una ricerca con successo viene eseguita in tempo medio $O(1)$

>[!example]
>+ Se $\alpha = 0.5$ il numero medio di ispezioni in una ricerca con successo è minore di $1.387$
>+ Se $\alpha = 0.9$ il numero medio di ispezioni in una ricerca con successo è minore di $2.559$

#### Confronto tra indirizzamento aperto e concatenamento

![[ConfrontoHash.excalidraw]]

**Ristrutturazione** : 

Per valori di $\alpha$ maggiori di $\frac 1 2$ il tempo di esecuzione delle operazioni su tabelle hash con indirizzamento aperto cresce a ritmo esponenziale.

Per questo quando il valore di $\alpha$ cresce oltre una certa soglia è necessario effettuare una *ristrutturazione* della tabella hash ossia riallocare la tabella raddoppiando la sua dimensione e reinserendo tutti i valori precedenti utilizzando la nuova funzione hash ( poichè dipende dalla dimensione della tabella ) in modo da riottenere le prestazioni iniziali

La *ristrutturazione* va effettuata quando : 
+ Nel caso del *concatenamento* quando $\alpha>2$ 
	L'operazione di *ristrutturazione* costerà nel caso peggiore $\Theta(m+n)$ in quanto dovremmo scorrere tutte le celle della tabella e tutte le liste delle celle
+ Nel caso dell'*indirizzamento aperto* quando $\alpha \ge \frac 1 2$ 
	In tal caso l'operazione costerà al caso peggiore $\Theta(m)$ in quanto dovremmo scorrere solo un array

## Programmazione Dinamica

La *programmazione dinamica* è una tecnica di progettazzione di algoritmi che si applica in presenza delle seguenti condizioni : 
+ Un problema si può ridurre ad un insieme di problemi più piccoli ( con nel *Divide et Impera* )
+ I sottoproblemi *non sono indipendenti* , ossia molti sottoproblemi si ripetono

>[!important] Idea
>Ogni volta che risolvo un problema salvo la soluzione per evitare di doverla ricalcolare 

La *programmazione dinamica* è adatta a risolvere problemi di **ottimizzazione** , questi problemi sono caratterizzati da diverse possibili soluzioni al problema ognuna con un costo in termini di tempo , attraverso la programmazione dinamica siamo in grado di scegliere la soluzione *ottima* cioè quella di *costo massimo* o *minimo* (tenendo conto che ci possono essere più soluizoni ottime)  
### Sviluppo di un Algoritmo :

Ci sono 4 principali passi da seguire per sviluppare un algoritmo di programmazione dinamica : 
1. Caratterizzazione della struttura di una soluzione ottimale ( di solito ricorsiva )
2. Definire ricorsivamente del valore di una soluzione ottimale 
3. Calcolo il valore di una soluzione ottimale 
4. Individuare una souzione ottimale sulla base del passo 3 

**Approcci** : 

Ci sono due principali approcci per risolvere un problema di programmazione dinamica : 
+ **Top-Down** :
	Memorizzo in una tabella ( vettore , tabella hash , ... ) le soluzioni dei problemi già risolti 
+ **Bottom-Up** : 
	Ordiniamo i problemi in base alla dimensione e partendo dai più piccoli li risolviamo e memorizziamo le soluzioni ottenute 

>[!note]
>A livello asintotico i due approcci sono equivalenti , considerando le costanti moltiplicative la strategia *Top-Down* risulta essere meno costosa 

### Problema del taglio delle aste

Un'azienda produce aste d'acciaio e le vende a prezzi. 
Le aste prodotte hanno una certa lunghezza $n$ , e sul mercato i pezzi hanno un prezzo che dipende dalla loro lunghezza 
Trovare il modo di tagliare le aste che massimizzi il guadagno

Dato : 
+ Un'asta di lunghezza $n$ 
+ Una tabella di prezzi $p_i$ con $i=1, \dots , m$ e $m\ge n$

Vogliamo determinare : 
+ $r_n$ : il ricavo massimo che si può ottenere da un'asta di lunghezza $n$
+ Le posizioni dove effettuare i tagli 

>[!example]
> Abbiamo un'asta di lunghezza $7$ e la seguente tabella dei prezzi :
>  
| Lunghezza $i$ | Prezzo $p_i$ |
| ------------- | ------------ |
| 1             | 1            |
| 2             | 5            |
| 3             | 8            |
| 4             | 9            |
| 5             | 10           |
| 6             | 17           |
| 7             | 17           |
>Supponiamo di fare i seguenti tagli : 
>+ $1+1+1+1+1+1+1=7$
>+ $2+2+2+1=16$
>+ $2+2+3=18$
>La soluzione che ci porta al ricavo maggiore è l'ultima ma non è l'unica infatti : 
>+ $3+2+2=18$
>+ $2+3+2=18$
>+ $1+6=18$
>+ $6+1=18$

#### Approccio *Divide et impera*

In quanti modi posso dividere un'asta di lunghezza $n$ ? 

Per ogni posizione possiamo decidere se effettuare o meno un taglio , ciò significa che in totale possiamo effettuare : $2\cdot 2\cdot\ \cdots\ \cdot2 = 2^{n-1}$ , analizzare quindi tutti i tagli ci porta ad una complesstià dell'ordine di $\Theta(2^n)$

**Caratterizzazione** *ricavo massimo* : 

+ *Caso base* : se $n=0$ allora $r=0$
+ $r_n=max\{ p_n \ ,\ r_1+r_{n-1}\ ,\ r_2+r_{n-2}\ , \dots ,\ r_{n-1} + r_1\ \}$
	Ossia dobbiamo prendere il valore massimo tra la divisione dell'asta nel seguenti modi : 
	+ Non taglio l'asta 
	+ Taglio l'asta in $i=1$ 
	+ Taglio l'asta in $i=2$
	+ $\cdots$
	+ Taglio l'asta in $i=n-1$

Come possiamo notare il ricavo ottimo è esprimibile attraverso la combinazione di soluzioni ottime di sottoproblemi , si dice che vale la *proprietà della sottostruttura ottimale*

La *caratterizzazione* precedente può essere resa più semplice diminuendo le chiamate ricorsive a una :
	Si taglia definitivamente un pezzo dell'asta ( quello sinistro ) e suddividiamo in modo ottimo la parte rimanente ( quella destra )

La formulazione ricorsiva diventa quindi : 

+ *Caso base* : se $n=0$ allora $r=0$ 
+ $r_n = max\{ \ p_i + r_{n-i}\ \}$ con $1\le i \le n$ 
	Dove : 
	+ $p_i$ : è il prezzo del taglio in posizione $i$
	+ $r_{n-i}$ : il prezzo ottimo del pezzo rimanente 

>[!note]
>Se $i=n$ vuol dire che il pezzo non viene tagliato e lo vendiamo tutto d'un pezzo

##### Algoritmo

**Input** : 
+ $p[\ 1, \dots , m \ ]$ : indica ( con $m\ge n$ ) il vettore contenente i prezzi delle aste , in $p[\ i\ ]$ è contenuto il valore di un'asta di lunghezza $i$ ( $i\ge 0$ )
+ $n$ è la lunghezza dell'asta da tagliare
**Output** : 
+ $r_n$ : ossia il ricavo massimo da un'asta di lunghezza $n$

```c
Cut_Rod (p , n)
	if n == 0 
		return 0 
	else
		q = -1 
		for i = 1 to n // il primo taglio può essere dall'inizio alla fine
			q = max(q , p[i] + Cut_Rod(p , n - i)) // caraterizzazione ricorsiva 
		return q
```

>[!note] 
>Inizializziamo $q$ a $-1$ poichè sappiamo che le aste non possono avere prezzi negativi ( se li postessero avere allora andrebbe inizializzato a $-\infty$ )

**Analisi della complessità** : 

Sia $T(n)$ il numero di chiamate di *Cut_Rod* quando la chiamata viene fatta con il secondo parametro uguale a $n$ 
$$T(n)=\begin{cases}1 & n=0 \\ 1+\sum_{i=1}^n T(n-i) & n >0\end{cases}$$
Dove $1$ corrisponde alla chiamata iniziale , la sommatoria rappresenta il `{c}for` e $T(n-i)$ rappresenta la chiamata ricorsiva 

Poniamo ora $j=n-i$ e otteniamo : 
$$T(n)=1+\sum_{i=1}^n T(n-1)=1+\sum_{j=0}^{n-1}T(j)$$
>[!note]
>Non sono sicuro se sostituiamo $j=n-1$ o $j=n-i$

*Dimostriamo* per *induzione* su $n$ che $T(n)=2^n$

+ *Caso base* : Se $n=0$ , $T(0)=2^0=1$ che è vero per definizione
+ *Passo Induttivo* : 
	Assumiamo l'ipotesi induttiva che $T(n)=2^n$ e lo dimostriamo per $n+1$
$$T(n+1)=1+\sum_{j=0}^{n+1-1}T(j)=$$
	Ora possiamo portate fuori un $T(n)$ ( visto che la sommatoria possiamo vederla come $n-1$ + l'ultimo elemento ) in modo da ricondurci alla definizione 
$$=1+\sum_{j=0}^{n-1}T(j)+T(n)=T(n)+T(n) = 2 \cdot T(n)$$
	Poichè per definizione abbiamo che $T(n)=2^n$ possiamo sostituire e otteniamo : 
	$$2\cdot 2^n=2^{n+1}$$
	Che dimostra il nostro passo induttivo

Possiamo quindi dire che $T(n)$ ha complessità *esponenziale* $T(n)=O(2^n)$

>[!example]
>Verifichiamo la complessità della funzione anche attraverso l'albero della ricorsione
![[Pasted image 20240304150455.png]]
> Notiamo che il numero dei nodi è esattamente pari a $2^n$ e il numero di possibili problemi distinti è invece $n$ 
> Notiamo inoltre che ogni cammino dalla radice ad una foglia ci dà una permutazione dei possibili tagli effettaubili sull'asta ( il cammino più lungo rappresenta la divisione dell'asta sempre in posizione $1$ sottosbarra destra )

#### Approccio di programmazione dinamica ( *Top-Down* )

Se i sottoproblemi distinti sono in numero polinomiale e ciascuno si risolve in tempo polinomiale ( data la soluzione dei sottoproblemi ) allora memorizzando le soluzioni ed evitando di ricalcolare si ottiene un algoritmo polinomiale , occorre però scendere ad un compromesso utilizzando della memoria ausiliaria

**Top-Down**

```c
Memorized_Cut_Rod(p, n)
	sia r[0, ... ,n] un nuovo vettore 
	for i = 0 to n
		r[i] = -1 // inizializzazione del vettore
	return Memorized_Cut_Rod_Aux(p ,n ,r)

Memorized_Cut_Rod_Aux(p ,j ,r)
	if r[j] < 0
		if j == 0
			r[j] = 0
		else 
			q = -1
			for i = 1 to j
				q = max(q, p[i] + Memorized_Cut_Rod_Aux(p, j-i, r))
	return r[j]
```

`r[i]` conterrà il prezzo ottimo per la lunghezza $i$ , se questo è $\ge0$ allora abbiamo già risolto poichè vuol dire che abbiamo già trovato il prezzo ottimo per quella lunghezza altrimenti come possiamo semplicemente ricopiare ciò che già faccio nel metodo *divide et impera* 

**Analisi della complessità** ( analisi aggregata ) : 

Una chiamata ricorsiva , per risolvere un problema precedentemente risolto termina  immediatamente , giungiamo quindi al ramo `{c}else` della funzione ausiliaria una sola volta per ciascun sottoproblema

Per risolvere un sottoproblema di dimensione $j$ il ciclo `{c}for` effettua $j$ iterazioni 
Il numero totale di iterazioni di questo ciclo `{c}for` per tutte le chiamate ricorsive della funzione ausiliaria sarà :
$$\sum_{j=1}^nj=\frac{n(n+1)}{2}=\Theta(n^2)$$
Considerando anche il fatto che svolgiamo $n$ iterazioni per inizializzare $r$ diremo che la complessità totale dell'algoritmo sarà : 
$$T(n)=\Theta(n)+\Theta(n^2)=\Theta(n^2)$$
#### Approccio di programmazione dinamica ( *Bottom-Up* )

```c
Bottom_Up_Cut_Rod(p, n)
	Sia r[0, ... ,n] un nuovo vettore
	r[0] = 0
	for j = 1 to n // utilizza sempre soluzioni già calcolate
		q = -1
		for i = 1 to j
			q = max(q, p[i]+r[j - i]) // r[j-i] sarà sempre < j
		r[j] = q
	return r[n]
```

**Complessità** : 

Il ciclo esterno compie esattamente $n$ iterazioni mentre il ciclo interno compie $j$ iterazioni dove $j$ prende tutti i valori $1,\dots, n$ , avremo quindi che la complessità sarà : 
$$T(n)=\sum_{j=1}^n j\cdot\Theta(1)=\Theta\bigg(\frac{n(n+1)}{2}\bigg)=\Theta(n^2)$$
#### Trovare la soluzione finale ( la posizione dei tagli )

Per trovare dove andremo a tagliare per ottenere il ricavo massimo andremo ad utilizzare un'ulteriore vettore $s[\ 1 , \dots , n\ ]$ , nella cui posizione $j$-esima memorizza la posizione del primo taglio che determina la soluzione ottima per il problema di dimensione $i$

```c
Ext_Bottom_Up_Cut_Rod(p, n)
	Siano r[0,...,n] e s[1,...,n] due nuovi vettori
	r[0] = 0
	for j = 1 to n
		q = -1
		for i = 1 to j
			if q < p[i] + r[j - i]
				q = p[i] + r[j - i]
				s[j] = i
		r[j] = q
	return r, s 
```

Possiamo notare che la *complessità* dell'algoritmo non cambia  

Per visualizzare la sequenza dei tagli possiamo scrivere : 
```c
Print_Cut_Rod(p, n)
	r,s = Ext_Bottom_Up_Cut_Rod(p, n)
	while n > 0
		print(s[n])
		n = n - s[n] // il prossimo taglo lo troveremo nella lunghezza rimanente della barra destra 
```

*Complessità* :
	La funzione è composta dalla chiamata a funzione che ritorna il vettore dei tagli e il ricavo ottimale ( $\Theta(n^2)$ ) più un ciclo `{c}while` che svolge $n$ iterazioni al massimo , avrà quindi complessità $O(n)$
	La complessità totale sarà dunque : $T(n)=\Theta(n^2)+O(n)=\Theta(n^2)$

>[!example]
>Supponiamo di avere un'asta di lunghezza $7$ avente i seguenti array : 
>
>|        | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   |
| ------ | --- | --- | --- | --- | --- | --- | --- | --- |
| `r[i]` | 0   | 1   | 5   | 8   | 10  | 13  | 17  | 18  |
| `s[i]` | -   | 1   | 2   | 3   | 2   | 2   | 6   | 1   |
>
>Ora la prima volta avermo `s[7] = 1` che indicherà che taglia l'asta in posizione $1$ , sucessivamente alla 2 iterazione $n$ diventa $7-1=6$ e quindi selezioneremo `s[6] = 6` che indicherà che prendiamo l'intera parte restante dell'asta , usciremo quindi dal ciclo poichè $n==0$ 
>La sequenza finale di taglio sarà quindi : $[1,6]$ che porta al ricavo di $18$
### Longest Common Subsequence ( LCS )

Facciamo un esempio di trovare le *LCS* all'interno di una sequenza di DNA avente il seguente alfabeto : `{A, G, C, T}` 

#### Edit Distance

L'*edit distance* rappresenta il minimo numero di *modifiche* ( inserimento , cancellazione , inserimento , copia , scambio ) da apportare ad una stringa per renderla uguale ad un'altra stringa

>[!example]
>Prendiamo $S_1 = ACTACCTG$ e $S_2=ATCACC$ e calcoliamo la loro *edit distance* : 
>+ Inseriamo una $C$ tra $A$ e $T$ in $S_2$
>+ Eliminiamo la prima $C$ dopo la $T$ in $S_2$
>+ Inseriamo una $T$ in coda a $S_2$
>+ Inseriamo una $G$ in coda a $S_2$
>L'*edit distance* risulta quindi essere 4

#### LCS

>[!note]
>Una *sottostringa* è diversa da una *sottosequenza* , infatti la *sottostringa* è una sequenza di caratteri *consecutivi* mentere una *sottosequenza* è una sequenza ordinata di caratteri ( mi basta sapere che i loro indici siano strettamente maggiori non che siano consecutivi ( possono in pratica esserci buchi nella sequenza ) )

Il problema del *Longest Common Subsequence* si pone il seguente problema : date due sequenze $X=x_1,\dots,x_m$ e $Y=y_1,\dots,y_n$ vogliamo trovare una sequenza $W$ tale che sia sottoseqeuenza di $X$ e $Y$ e che sia di *lunghezza massima* 

>[!example] 
> Proviamo a trovare $W$ tra le precedenti stringhe 
> Notiamo che è possibile trovare 2 sottosequenze che soddifano la condizione di *LCS* : 
> $$LCS(S_1,S_2)=\{ ATACC , ACACC \}$$
> >[!note]
> >La massima sottosequenza comune può non essere unica

**Algoritmo Brute Force**

L'algoritmo fa i seguenti passi : 
+ Genera tutte le sottosequenze di $X$
+ Verifico se è sottosequenza di $Y$
+ Mantengo la più lunga sottosequenza

Può essere facilmente notato che visto che il numero di sottosequenze di $X$ risulta essere $2^m$ ( questo poichè dobbiamo pensare che ad ogni carattere dobbiamo decidere se includerlo o meno all'interno della sottosequenza ) allora l'algoritmo risulterebbe avere complessità $O(2^m)$ , molto *inefficente* 

Controlliamo riusciamo a ridurci ad un problema risolvibile attraverso la *programmazione dinamica*
##### Definiamo la Sottostruttura Ottima

Dato $X=x_1,\dots,x_m$ consideriamo $k\le m$  con $x^k$ rappresentante il prefisso ( i primi $k$ caratteri di $X$ ) di lunghezza $k$ di $X$

>[!note]
>Per una seqeunza di $m$ caratteri avermo che il numero massimo di prefissi sarà $m+1$ ( $+1$ poichè dobbiamo includere anche la sequenza vuota )
>>[!example]
>>Per $X=ACG$ avremo i seguenti *prefissi* : $X^0=\epsilon$ , $X^1=A$ , $X^2=AC$ , $X^3=ACG$

In genare avendo $X=x_1,\dots,x_m$ e $X=y_1,\dots,y_n$ se possiamo ridurre il problema della $LCS(X,Y)$ al problema dei suoi prefissi allora avremo che la complessità diventa $O(m\cdot n)$ , ossia polinomiale ( come richiesto per l'utilizzo della *programmazione dinamica* ) , questa complessità deriva dal fatto che .....
>[!todo]
>Finisci / trova soluzione
>#todo

>[!important] Teorema *Struttura Ottima per LCS*
>Siano $X=x_1,\dots,x_m$ e $Y=y_1,\dots,y_n$ due sequenze e sia $W=w_1,\dots,w_k \in LCS(X,Y)$ Allora : 
>1. Se $x_m=y_n$ ( gli ultimi elementi sono uguali ) allora $w_k=x_m=y_n$ e $W^{k-1}\in LCS(X^{m-1},Y^{n-1})$ ( in pratica se l'ultimo carattere di $X$ e $Y$ sono uguali allora questo carattere farà parte dell'$LCS$ e il penultimo carattere sarà dato da trovare l'$LCS$ nelle restanti parti delle due sequenze iniziali )
>2. Se $x_m\neq y_n$ avremo 2 casi : 
>	2a. Se $w_k\neq x_m$ allora $W \in LCS(X^{m-1},Y)$
>	2b. Se $w_k\neq y_n$ allora $W \in LCS(X,Y^{n-1})$

>[!important] *Dimostrazione* per assurdo
>
##### Soluzione ricorsiva per il valore della soluzione 

Dati $X = x_1, \dots ,x_m$ e $Y=y_1,\dots,y_n$ indichiamo con $c[i,j]$ la lunghezza delle sottosequenze appartenenti a $LCS(X^i, Y^j)$ con $0\le i \le m$ e $0\le j \le n$ 
$$c[i,j] = \begin{cases} 0 & \text{se} \ i=0\ \text{o} \ j=0 
\\ c[i -1, j-1] +1 & \text{se} \ i,j > 0 \ \text{e} \ x_i = y_j \\ max\{\  c[i-1,j]\ ,\ c[i,j-1] \} & \text{se} \ i,j>0 \ \text{e} \ x_i\neq y_j \end{cases} 
$$
>[!example]
>Abbiamo $X=ABACA$ e $Y=ACDA$ , risolviamo l'*LCS*
>1. Abbiamo `c[4,5]` , confrontiamo `X[4]` e `Y[5]` , questi essendo `==` dovremmo ridurci a risolvere il seguente sottoproblema : `c[3,4]+1` ( poichè `A` fa parte dell'*LCS* )
>2. Abbiamo `c[3,4]` , ora visto che `X[3]!=Y[4]` dovremo risolvere il seguente sottoproblema : `max[c[3,3],c[4,2]]` 
>3. $\dots$

##### Soluzione *Bottom Up*

Faremo uso di 2 strutture ausiliarie :
+ `c[i,j]` che conterrà la lunghezza dell'$LCS(X^i,Y^i)$ 
+ `b[i,j]` che conterrà informazioni utili al recupero della soluzione , in particolare 
	+ $b[i,j]=\ \nwarrow$ se $x_i=y_i \implies LCS(X^i,Y^i)$ viene ridotta a $LCS(X^{i-1},Y^{i-1})$ 
	+ $b[i,j]=\ \uparrow$   se $x_i\neq y_i \implies LCS(X^i,Y^i)$ viene ridotta a $LCS(X^{i-1},Y^{i})$ 
	+ $b[i,j]=\ \leftarrow$ se $x_i\neq y_i \implies LCS(X^i,Y^i)$ viene ridotta a $LCS(X^{i},Y^{i-1})$ 

**Algoritmo** : 
```c
LCS(X , Y)
	m = X.length
	n = Y.length
	for i = 0 to m 
		c[i , 0] = 0
	for j = 1 to n
		c[0 , j] = 0
	for i = 1 to m
		for j = 1 to n
			if xi == yj
				c[i , j] = c[i - 1, j - 1] + 1
				b[i , j] = ↖
			else 
				if c[i - 1, j] ≥ c[i , j - 1]
					c[i , j] = c[i - 1, j]
					b[i , j] = ↑
				else
					c[i , j] = c[i , j - 1]
					b[i , j] = ← 
	return b , c
```

>[!example]
>Simuliamo l'esecuzione dell'algoritmo con le stringhe $X=AC$ , $Y=BA$
>1. Viene inizializzata la colonna e riga 0 nella tabella `c[i,j]` a 0 questo perchè queste corrispondono alla sottostringa di lunghezza 0 per cui sappiamo che sono il caso base della ricorsione   
>2. Iniziamo con $i=1, j=1$ :
>	`B!=A` $\implies$ `c[i,j]=max{c[i-1,j],c[i,j-1]` che risulterà essere 0 poichè entrambi i sottoproblemi risultano essere uguali e prevale `c[i-1,j]` , posizioniamo $\uparrow$ in `b[i,j]` 
>3. Confrontiamo $i=1,j=2$ : 
>	`A==A` : prenderemo il valore della casella precedente sulla diagonale `c[i-1,j-1]` e vi sommiamo `1` poichè abbiamo trovato un *match* , settiamo `b[i,j]=`$\nwarrow$
>4. Confrontiamo $i=2 , j=1$ : 
>	`C!=B` : troviamo il massimo tra `c[i-1,j]` e `c[i,j-1]` , visto che entrambi sono 0 prevale `c[i-1,j]` e aggiungiamo in `b[i,j]=`$\uparrow$
>5. Confrontiamo $i=2,j=2$ : 
>	`C!=A` : troviamo il massimo tra `c[i-1,j]` e `c[i,j-1]` , visto che `c[i-1,j]=1` , avremo che `c[i,j]=1` e `b[i,j]=`$\uparrow$
![[Pasted image 20240312153516.png]]

**Complessità** : 
	La complessità di `LCS(X , Y)` va espressa in funzione di $m$ e $n$ , avremo che : 
	1. Il primo ciclo viene svolto $m$ volte per inizializzare l'array `c[i,0]` , avrà quindi complessità : $\Theta(m)$
	2. Il secondo ciclo viene svolto $n$ volte per inizializzare l'array `c[0,j]` , avrà quindi complessità : $\Theta(n)$
	3. I due cicli for annidati hanno vengono svolti $m\cdot n$ volte ed avranno quindi complessità : $\Theta(m\cdot n)$
	La complessità risultante sarà quindi : $T(n,m)=\Theta(m)+\Theta(n)+\Theta(m\cdot n) = \Theta(m\cdot n)$

**Costruzione di una Soluzione** :
```c
printLCS(X , Y)
	b , c = LCS(X , Y)
	printLCSrec(X , b , X.length , Y.length)
	
printLCSrec(X , b , i , j )
	if i > 0 and j > 0
		if b[i , j] == ↖
			printLCSrec (X , b , i - 1, j - 1)
			print Xi
		else 
			if b[i , j ] == ↑
				printLCSrec(X , b , i - 1, j) 
			else
				printLCSrec(X , b , i , j - 1)
```

>[!note]
>Ogni volta che troviamo $\nwarrow$ vuol dire che avevamo trovato una lettera che faceva parte dell'*LCS*

>[!example] 
>Seguiamo i passaggi dell'algoritmo : 
>1. Partiamo da $i=2,j=2$ , siamo nel caso in cui abbiamo in `b[i,j]=`$\uparrow$ ed avremo quindi che continueremo l'esecuzione risolvendo il problema `(i-1,j)`
>2. Siamo in $i=1,j=2$ , siamo nel caso in cui abbiamo in `b[i,j]=`$\nwarrow$ , abbiamo trovato un *match* , stampiamo quindi `A` e continuiamo risolvendo il problema `(i-1,j-1)`
>3. Siamo in $i=0,j=1$ , essendo che abbiamo raggiunto un *caso base* , concludiamo la stampa
>![[Pasted image 20240312155412.png]]

**Complessità**

Analizziamo la complessità di `printLSCrec()` : questa dipende da $i$ e $j$ questo poichè i due indici vengono dimuiti ad ogni passaggio della funzione ricorsiva che termina quando o $i$ o $j$ diventano minori di 1 , potremmo quindi prima raggiungere 1 con uno dei due e poi con l'altro portando ad un numero massimo d'esecuzioni di $i+j$ , la complessità sarà quindi : $O(i+j)$

La complessità della funzione `printLCS()` sarà quindi : $T(n,m) = \Theta(m\cdot n)+ O(m+n)$ 
Dove : 
+ $\Theta(m\cdot n)$ corrisponde alla complessità di `LCS()`
+ $O(m+n)$ corrisponde alla complessità della funzione ricorsiva dove abbiamo sostituito $i$ e $j$ con le lunghezze delle due stringhe

>[!note]
>Risulta molto importante l'ordine delle operazioni che vengono svolte 

**Ottimizzazioni** 

Notiamo che l'array `b` può non essere memorizzato dato che l'informazione corrispondente è derivabile da `c` , questo poichè `c[i,j]` dipende solo da 3 valori : `c[i-1,j-1]` , `c[i-1,j]` , `c[i,j-1]` 

La soluzione diventa quindi : 
```c
printLCSrec(X , c , i , j)
	if i > 0 and j > 0
		if c[i , j] == c[i - 1, j]
			printLCSrec(X , c , i - 1, j)
		else if c[i , j] == c [i , j - 1]
			printLCSrec(X , c , i , j - 1)
		else
			printLCSrec(X , c , i - 1, j - 1)
			print Xi
```

Inoltre , se sono interesato *solo* alla *lunghezza* di *LCS* possiamo evitare di mantenere la tabella `c` completa visto che ci interessa solo la riga $i+1$ e $i$ per calcolare la soluzione finale

>[!note]
>Un'ulteriore ottimizzazione riduce lo spazio ad un vettore di spazio = $\min(m,n)$ più uno spazio aggiuntivo in $O(1)$

##### Soluzione *Top Down*

```c
tdLCS(X , Y)
	m = X.length
	n = Y.length
	c [0 ... m , 0 ... n] = -1 // riempie la matrice c di -1
		return tdLCSaux(X , Y , c , m , n)
		
tdLCSaux(X , Y , c , i , j)
	if c[i , j] == -1 // altrimenti ho già risolto il problema
		if i == 0 or j == 0
			c[i , j] = 0
		else
			if Xi == Yj
				c[i , j] = tdLCSaux(X , Y , c , i - 1, j - 1) + 1
			else 
				c[i , j] = max(tdLCSaux(X , Y , c , i - 1, j) ,
							   tdLCSaux(X , Y , c , i , j - 1) )
	return c[i , j]
```

**Complessità** 

Possiamo ridurre la complessità di `tdLCS()` al numero di chiamate ricorsive che vengono svolte dalla funzione `tdLCSaux()` , questa poichè o legge un valore già presente $O(1)$ o inserisce un valore , quest'ultima operazione viene effettuata al più $i\cdot j$ volte o più precisamente $(i+1)\cdot(j+1)$( questo per comprendere anche le due stringhe vuote $\epsilon$ ) che possiamo sostituire con $m\cdot n$ poichè la funzione `tdLCSaux()` viene chiamata con $i=m$ e $j=n$ 

Avremo quindi che la complessità di `tdLCS()` risulterà essere : 
$$T(n,m)=\Theta(n\cdot m) + O(m\cdot n)$$
$$T(n,m)=\Theta(n\cdot m) \quad \text{domina}$$
Dove $\Theta(n\cdot m)$ rappresenta il riempimento della matrice alla riga 4 di `tdLCS()`

>[!note] 
>Il numero di sottoproblemi risolti non è strettamente $m\cdot n$ , infatti : 
>>[!example]
>>Se avessimo due stringhe uguali allora il numero di confronti sarà $O(n)$
>>![[Pasted image 20240313131030.png]]

Nel caso medio quindi l'approccio *Top Down* è più efficente poichè questo risolve solo i sottoproblemi *strettamente* necessari ( nonostante asintoticamente sia *Top Down* che *Bottom Up* abbiano la stessa complessità )
### Riassunto

1. A quali problemi può essere applicata ?
	La programmazione dinamica si applica ai *problemi di ottimizzazoni* cioè problemi in cui ho un insieme molto grande di soluzioni e voglio determinarne una ottima
2. I problemi di ottimizzazione devono soddisfare due caratteristiche : 
	1. Il problema deve disporre di una *sottostruttura ottima* 
		La soluzione di un problema è una combinazione di soluzioni ottime di sottoproblemi
	2. Il numero di sottoproblemi distinti è piccolo rispetto rispetto al numero di possibili soluzioni 
		Nel caso delle *aste* il numero di soluzioni è $\Omega(2^n)$ mentre il numero di sottoproblemi è $\Theta(n)$
		Nel caso della *LCS* il numero di soluzioni è $\Omega(2^n)$ mentre il numero di sottoproblemi è $\Theta(m\cdot n)$
3. Se valgono le precedenti due condizioni abbiamo due possibili approcci per risolvere il problema 
	1. *Bottom Up* :
		+ Risolve i problemi dal più piccolo a quello di dimensione desiderata
		+ L'ordine della risoluzione deve assicurare che tutti i sottoproblemi che compongono un sottoproblema maggiore siano già stati risolti
	2. *Top Down* con *Memorization* : 
		+ Fornisce la risoluzione ricorsiva data dalla caratterizzazione del problema in termini di sottoproblemi utilizzando le soluzioni di questi memorizzate in precedenza 

>[!note]
>Se per il calcolo della soluzione occorre risolvere tutti i sottoproblemi risulta essere conveniente l'approccio *Bottom Up* poichè si evita la ricorsione e alcuni controlli 
>
>Se invece c'è solamente bisogno di alcuni sottoproblemi allora la soluzione *Top Down* risulta essere migliore poichè evita il calcolo di sottoproblemi inutili

### Esercizi sulla Programmazione Dinamica

#### 1

Abbiamo una stringa $a_1,\dots,a_n$ individua la lunghezza della massima *sottostringa* palindroma

>[!example] Comprendiamo il problema
>In `COLONNA` la sottostringa palindroma di massima lunghezza è : `OLO` con lunghezza $3$ 

Facciamo la *caratterizzazione ricorsiva* del problema : 
$$l\ [ \ i,j\ ] = \begin{cases} 0 & \text{se} \ i > j \\ 1 & \text{se} \ i == j \\ 2+l\ [\  i+1, j-1 \ ] & \text{se} \ x_i ==x_j\  \land\ l\ [\  i+1, j-1 \ ] == j+1-i \\ \max\left(l\ [\  i+1, j \ ],l\ [\  i, j-1 \ ]\right) & \text{altrimenti}   \end{cases}$$
**Spiegazione** : 

$i$ : rappresenta l'indice d'inizio della stringa che stiamo prendendo in considerazione
$j$ : rappresenta l'indice di fine della stringa che stiamo prendendo in considerazione

I primi due casi della caratterizzazione rappresentano i due *casi base* del problema , infatti : 
+ Se non abbiamo alcun carattere la lunghezza massima della stringa palindroma non potrà che essere 0
+ Se abbiamo esattamente un carattere allora la lunghezza massima della stringa palindroma è 1 poichè un solo carattere è una stringa palindroma

>[!note]
>Il modo in cui suddividiamo il problema è il seguente : 
>Se sappiamo che il primo e ultimo carattere sono uguali allora dovremmo controllare se la stringa compresa tra questi due caratteri è palindroma , questa lo sarà solo se la lunghezza della massima stringa palindroma compresa risulti essere la lunghezza della stringa , solo a quel punto possiamo considerarla come possibile soluzione

Possiamo quindi ora spiegare il terzo caso : 
$$2+l\ [\  i+1, j-1 \ ] \quad \text{se} \ x_i ==x_j\  \land\ l\ [\  i+1, j-1 \ ] == j+1-i$$
Dove : 
+ $j+1-i$ indica la lunghezza della stringa compresa tra i caratteri $x_i$ e $x_j$ , questi devono soddisfare la seguente propietà : $x_i==x_j$ , che deve essere corrispondenta alla lunghezza della massima sottostringa palindroma ( $l\ [\  i+1, j-1 \ ]$ )
+ Verificate le condizioni possiamo svolgere la chiamata ricorsiva $2+l\ [\  i+1, j-1 \ ]$ , dove $2$ rappresenta i due caratteri uguali trovati

Il quarto caso rappresenta il caso in cui i due caratteri considerati $x_i$ e $x_j$ sono differenti , in questo caso dovremmo cercare la stringa con massima lunghezza in 2 casi : $l\ [\  i+1, j \ ]$ e $l\ [\  i, j-1 \ ]$ , tra i due dovremmo ritornare il massimo che rappresenta la stringa palindroma di massima lunghezza 

#### 2

Abbiamo un *multinsieme* ( insieme di numeri anche ripetuti ) di numeri naturali , questi sono *prefettamente bilanciati* se posso dividere il multinsieme in due sottoinsiemi che abbiano la stessa somma

>[!example] Comprendiamo il problema
>Abbiamo per esempio l'insieme $I=1,7,3,3$ , questo può essere diviso in $I_1 =1,3,3$ e $I_2=7$ , avendo la stessa somma ( $7$ ) possiamo dire che $I$ è *perfettamente bilanciato*

>[!note]
>Ci sono delle soluzioni banali che possiamo eliminare : 
>+ La somma è dispari : infatti avendo a disposizione solo numeri naturali è impossibile creare multinsiemi con somma frazionaria

>[!note]
>Il problema può essere suddiviso nel cercare se esiste una somma che risulti uguale a $k/2$ dove $k$ rappresenta la somma di tutti i numeri all'interno di $I$

Facciamo la *caratterizzazione ricorsiva* del problema : 
$$\text{isSubSetSum}(i ,sum) = \begin{cases} true & \text{se} \ sum=0 \\ false & \text{se} \ i=0 \land sum \neq 0 \\ \text{isSubSetSum}(i-1,sum) & \text{se} \ i>0 \ \land I[i-1]>sum \\ \text{isSubSetSum}(i-1,sum)\ \lor\ \text{isSubSetSum}(i-1,sum-I[i-1]) & \text{se} \ i>0 \land \ I[i-1]\le sum \end{cases}$$
>[!note]
>L'array $I[\dots]$ è rappresentato come se fosse in `c` ( inizia dall'indice 0 e finisce a $I.size-1$ )

**Spiegazione** : 

$i$ : indica i primi $i$ elementi dell'array $I[\dots]$ 
$sum$ : indica $k/2$ ( ossia la somma che dobbiamo raggiungere )

Analizziamo ora i differenti *casi* : 

Abbiamo due differenti *casi base* : 
+ $sum==0$ : in questo caso ritorniamo `{cpp}true` poichè significa che abbiamo raggiunto la somma richiesta con i primi $i$ elementi 
+ $i==0\land sum\neq 0$ : in questo caso ritorniamo `{c}false` poichè vuol dire che non abbiamo più elementi da sommare ma non abbiamo raggiunto la somma richiesta

*Casi ricorsivi* : 
+ $i>0 \ \land \ I[i-1] > sum$ : ciò significa che abbiamo ancora elementi da sommare ( $i>0$ ) ma l'elemento in cui ci troviamo è da solo maggiore della somma richiesta , ciò significa che per risolvere il problema dobbiamo escludere quell'elemento dalla somma ( ossia svolgiamo $\text{isSubSetSum}(i-1,sum)$ ) 
+ $i>0 \ \land \ I[i-1] \le sum$ : ciò significa che abbiamo ancora elementi da sommare ( $i>0$ ) e l'emento in cui ci troviamo è minore della somma richiesta , ciò significa che abbiamo 2 possibilità : 
	1. Lo prendiamo perchè venga utilizzato nella somma ( $\text{isSubSetSum}(i-1,sum-I[i-1])$ )
	2. Non lo prendiamo nella somma ( $\text{isSubSetSum}(i-1,sum)$ )
	Ora l'*or* di questi due risultati ci dirà se almeno uno dei due ritorna `true` , ossia $I$ è *perfettamente bilanciato* 

#### 3 

Abbiamo un array di lunghezza $n$ composto da numeri positivi strettamente maggiori di 0 , ci chiediamo quante *sottosequenze* ( gli indici devono essere strettamete maggiori del precedente ma non sucessivi ) ci sono con prodotto $\le k$ 

>[!example] Comprendiamo il problema
>Prendiamo il seguente array : $<2,1,7,3>$ e $k=15$ avremo che $<2,1,7,3,2\cdot 1,2\cdot 7,2\cdot 3,\dots>$ saranno le sottosequenze cercate

Facciamo la *caratterizzazione ricorsiva* del problema : 
$$\text{nsub}(m,j)=\begin{cases} 0 & j=0\\ \text{nsub}(m,j-1) & a_j>m \land j>0 \\ \text{nsub}(m,j-1) + \text{nsub}(m/a_j\ ,j-1) +1 & a_j\le m \land j>0\end{cases}$$

**Spiegazione** : 

$m$ : rappresenta il prodotto a cui dobbiamo arrivare 
$j$ : rappresenta i primi $j$ elementi dell'array di partenza

In questo problema abbiamo un unico *caso base* :
+ $j=0$ : in questo caso infatti avendo $0$ elementi non possiamo moltiplicare nulla quindi la risposta sarà $0$ sottoquenze trovate

*Casi ricorsivi* :

>[!note]
>$a_j$ rappresenta il $j$-esimo elemento del vettore di input

+ $a_j >m \land j>0$ : ciò significa che l'elemento che stiamo ispezionando è maggiore del valore da trovare , visto che vi sono ancora elementi da visitare ( $j>0$ ) possiamo non scieglere l'elemento per essere incluso nella moltiplicazione e continuare a cercare : $\text{nsub}(m,j-1)$ 
+ $a_j \le m\land j > 0$ : ciò significa che abbiamo ancora elementi e l'elemento che stiamo ispezionando è minore del valore da trovare , ciò significa che abbiamo 2 casi : 
	1. Lo includiamo nella moltiplicazione : ciò significa che dovremo toglierlo dalla moltiplicazione e continuare a cercare ( visto che abbiamo ancora elementi ) -> $\text{nsub}(m/a_j,j-1)$
	2. Non lo includiamo nella moltiplicazione : ciò significa che dovremo cercare all'interno della rimanente parte del vattore -> $\text{nsub}(m,j-1)$
	La soluzione finale sarà quindi data da : $\text{nsub}(m,j-1) + \text{nsub}(m/a_j\ ,j-1) +1$
>[!note]
>Dobbiamo anche aggiungere $1$ poichè l'elemento stesso , visto che è $a_j\le m$ , fa parte dell'insieme delle soluzioni
 
# Grafi

I *grafi* rappresentano il concetto matematico di relazione binaria

Un *grafo* è costituito da un insieme di *vertici* ( o nodi , $V$ ) e da un insieme di *archi* ( $E$ ) che collegano i nodi 

Formalmente un *grafo* $G$ è una coppia $G=(V,E)$ , dove $V=\{1,2,\dots,n\}$ è l'insieme di vertici del grafo , e $E \subseteq V \times V$ è un insieme di coppie che rappresentano gli *archi*  

I *grafi* si dividono in : 
+ **grafi orientati**
+ **grafi non orientati**
## Grafi orientati 

Gli *archi* hanno una direzione 

>[!example]
>Avendo : $V=\{ 1,2,3,4 \}$ e $E=\{ (1,2),(1,4),(2,2),(2,3),(3,1),(3,4),(4,2),(4,3) \}$

![[grafo1.excalidraw]]

Il numero di *archi* presenti all'interno di un *grafo orientato* sono rappresentati come : $|V|=n$

Quindi il *massimo* numero di *vertici* sarà : $n^2$ visto che $E = V \times V = V^2$ e quindi $|E|=|V|^2=n^2$ 

>[!note] 
>In generale non è detto che due nodi collegati abbiano sia l'arco $(primo,secondo)$ che $(secondo,primo)$

## Grafi non orientati

Un *grafo non orientato* $G$ è una coppia $G=(V,E)$ dove $V$ è l'insieme di vertici e $E\subseteq V \times V$ è l'insieme di archi su cui valgono le seguenti proprietà : 
+ *Simmetria* : 
	$$(i,j)\in E \iff (j,i)\in E$$
+ *Non riflessività* : 
$$\forall i \in V,\quad  (i,i) \notin E$$
	In pratica significa che non vi possono essere *archi* che vanno da un nodo a se stesso ( *cappi* o *loophole* ) 

>[!example]
>Abbiamo $V=\{ 1,2,3,4 \}$ e $E=\{ (1,2),(2,3),(1,3),(3,4) \}$
![[grafo2.excalidraw]]

**Definizione alternativa** 

Un *grafo non orientato* $G=(V,E)$ è costituito dall'insieme di veritici $V$ e dall'insieme di archi $E \subseteq \binom V 2$

>[!note]
>Dove $\binom V 2$ rappresenta l'insieme di tutti gli insiemi di 2 elementi presenti in $V$  , questo ci dice che formalmente l'ordine non conta a differenza della dicitura $V \times V$ 
>Per rappresentare l'insieme delle coppie utilizziamo al dicitura $\{\{1,2\}\}$ ( parentesi graffe a racchiudere la coppia ) per indicare che l'ordine non cambia

Troviamo ora la *cardinalità di $E$* :
$$\left|\binom V 2\right|=\binom {|V|}2 = \frac{n(n-1)}{2}$$

## Altre suddivisioni dei grafi

I *grafi* possono essere divisi a seconda della loro *densità* : 
+ **grafo sparso** : 
	Se il numero di archi è approssimativamente il numero di vertici : $|E|\simeq n$
+ **grafo denso** : 
	Se il numero di archi è dell'ordine di $n^2$ : $|E|\approx n^2$ 

Definiamo formalmente la **densità** ( $\delta$ ) di un *grafo* 

>[!note]
>$$0\le \delta \le 1$$

Con :
+ $\delta(G) = 0$ si dice che il grafo è *vuoto* , ossia non ha archi , ciò non significa che non abbia vertici
+ $\delta(G)=1$ si dice che il grafo è *completo* , ossia sono presenti tutti gli archi possibili

Avremo che $\delta$ differenzierà per i *grafi orientati* e *non* : 
+ Per quelli *orientati* avremo che : 
	$$\delta(G)= \frac{|E|}{n^2} \to \frac{|E|}{|V|^2}$$
+ Per quelli *non orientati* avremo che : 
	$$\delta(G)=\frac{|E|}{\left|\binom V 2\right|}= \frac{|E|}{\frac{n(n-1)}{2}}=\frac{2\cdot |E|}{n(n-1)}$$

## Grafi Pesati

I *grafi pesati* sono un'altra tipologia di *grafo* che hanno valori numerici collegati agli *archi* , *vertici* o entrambi

Un *grafo pesato* sui *vertici* $G(V,E,w)$ , dove $w$ rappresenta una funzione che assegna ad ogni vertice un numero reale 

>[!example]
![[grafopesatoV.excalidraw]]

Un *grafo pesato* sugli *archi* $G(V,E,w)$ , dove $w$ rappresenta una funzione che assegna ad ogni arco un numero reale

>[!example]
![[grafopesatoA.excalidraw]]

I pesi possono rappresentare informazioni es :
+ I veritici rappresentano delle stazioni
+ Gli archi rappresentano la tratta tra 2 stazioni 
+ I pesi sugli archi rappresentano la distanza tra due stazioni

Un *grafo pesato* sui vertici e sugli archi $G(V,E,w_1,w_2)$ , dove $w_1$ rappresenta una funzione che assegna ad ogni vertice un numero reale e $w_2$ rappresenta una funzione che assegna ad ogni arco un numero reale  

## Sottografo

Definiamo con *sottografo* di $G(V,E)$ come $G'(V',E')$ con $V' \subseteq V$ e $E'\subseteq E \cap V' \times V'$ 

>[!example]
![[subgraph.excalidraw]]

L'importante è che i *nodi* che vogliamo nel *sottografo* siano presenti anche senza alcun *arco* , questo poichè l'insieme vuoto è sempre un sottoinsieme di $E$ , non è un *sottografico* se invece aggiungiamo degli *archi* non presenti nel *grafo* originale 
### Sottografo indotto

Un *sottografo indotto* è un particolare sottografo che ha la seguente caratteristica : $E' = E \cap V' \times V'$ , significa che , dato un sottoinsieme $V'$ dei vertici di $G$ il sottoalbero indotto $G[V']$ contiene *tutti gli archi* incidenti ai nodi di $V'$ 

>[!example]
![[SottografoIndotto.excalidraw]]
## Cammino

Un *cammino* tra due vertici $u$ e $v$ è una sequenza di vertici $<x_0,x_1,\dots,x_q>$ tali che $x_1=u$ e $x_q=v$ e deve esistere un arco tra un vertice $x_i$ e il suo sucessivo $x_{i+1}$ ossia : $(x_i,x_{i+1}) \in E\forall i=0,\dots,q-1$

>[!example]
![[camminiGrafo.excalidraw]]
$<1,2,1,2,3,1,2,3>$ è un cammino

>[!note]
>Un cammino è definito *semplice* se non ci sono vertici ripetuti 
>>[!example]
>>$<1,2,3>$ è un cammino *semplice*
>
>Il cammino precedente è quindi un cammino *non semplice*
### Lunghezza di un cammino

La *lunghezza di un cammino* è il numero di *archi* presenti in un cammino 
## Connessione

Un *grafo* si dice *connesso* se presi due vertici del grafo esiste almeno un cammino che li collega 
>[!example]
![[camminiGrafo.excalidraw]]
E' un *grafo connesso*


Un *grafo* *disconnesso* invece presenta almeno una coppia di vertici non raggiungibili da un cammino

>[!example]
![[disconnectedGraph.excalidraw]]
E' un *grafo disconnesso*
## Cicli

I *cicli* sono sono *cammini* che ritornano su se stessi , ossia quando $x_0==x_q$ 
>[!example]
>$$<1,2,3,1>$$

In un *grafo non orientato* per creare dei cili dobbiamo avere almeno 3 vertici
In un *grafo orientato* invece è sufficente averne 2 visto che i *cappi* rappresentano un ciclo con 2 vertici ( un unico vertice ripetuto )

>[!example]
![[grafociclico.excalidraw]]
### Grafo Aciclico

Un *grafo* si dice *aciclico* se non ha *cicli* 

>[!example]
![[Aciclico.excalidraw]]

## Alberi 

Un *grafo aciclico connesso* viene detto *albero*

Un *albero* può essere *libero* se privo di gerarchia , *radicato altrimenti*

**Proprietà** : 
+ Se $G$ è un *albero libero* allora il numero di archi è : $n-1$ , dove $n$ è il numero di vertici 
+ Tra $u$ e $v$ ( vertici ) esiste sempre uno e uno solo *cammino* ( in caso contrario si creano dei *cicli* )

Un *grafo acicliclo disconnesso* è detto *foresta*
![[foresta.excalidraw]]

## Adiacenza

In un *grafo* i nodi $i$ e $j$ sono *adiacenti* se esiste un arco che li collega 

![[adiacenza.excalidraw]]

>[!note] 
>$j$ è adiacente a $i$ solo se ho un vertice che va *da $i$ a $j$* un vertice orientato al contrario non funziona
## Implementazione

### Lista di Adiacenza

La *lista di adiacenza* implementa i grafi attraverso l'uso di un array di dimensione $n$ che contiene , in ciascuna posizione , un puntatore ad un lista concatenata 

Ogni posizione dell'array indica un *nodo* del grafo da cui partono la lista degli *archi* *uscenti*  , ogni cella della lsita concatenata contiene l'informazione sul *nodo* a cui arriva quell'arco

>[!example]
![[Pasted image 20240320082151.png]]

**Vantaggi** : 
+ L'occupazione di memoria creace linearmente rispetto ad $n$

**Svantaggi** : 
+ I tempi di accesso non sono ottimi : 
	Per verificare l'essitenza di un arco è necessario scorrere le liste concatenate che è un'operazione lenta rispetto all'accesso diretto degli array

>[!note]
>L'utilizzo di questa struttura dati conviene in *grafi sparsi* visto che ho pochi archi e non devo sprecare molto tempo per la ricerca 
### Matrice di Adiacenza

La *matrice di adiacenza* $A_G$ ( matrice di adiacenza $A$ del grafo $G$ ) è una matrice di dimensione $n\times n$ i cui elementi assumono i seguenti valori : 

$$a_{ij}=\begin{cases} 1 & \text{se}\ (i,j)\in E \\ 0 & \text{se}\ (i,j)\notin E
\end{cases}$$
Con $1\le i, j\le n$

In pratica metteremo 1 in quelle caselle le cui coordinate rappresentano un arco che esiste all'interno del grafo

>[!example]
![[MatriceAdiacenza.excalidraw]]
>
>
|       | **1** | **2** | **3** | **4** |
| :---: | :---: | :---: | :---: | :---: |
| **1** |   0   |   1   |   1   |   1   |
| **2** |   0   |   1   |   1   |   0   |
| **3** |   0   |   1   |   0   |   1   |
| **4** |   1   |   0   |   0   |   0   |

>[!note]
>Questo metodo risulta essere più efficente ( dal punto di vista temporale ) rispetto alla *lista di adiacenza* poichè per vedere se abbiamo un arco tra due nodi $i$ e $j$ ci basterà vedere se la cella $a[\ i\ ][\ j\ ]$ contiene 1 o 0
>
>Dal punto di vista spaziale abbiamo un consumocostante di $\Theta(n^2)$

Questa soluzione risulta essere preferibili nel caso di *grafi densi* se non ho problemi di spazio

>[!note]
>Con un *grafo non orientato* avremo che la matrice creata risulterà simmetrica rispetto alla sua diagonale che conterrà solo 0 poichè non possono esistere *cappi* per definizione
>
>Possiamo dire che $A^T = A$ ossia la sua *trasposta* ( scambio righe con colonne ) corrisponde alla matrice iniziale
### Matrice di Indicenza

Rappresentiamo il grafo attraverso la matrice di incidenza di dimensione $|V|\times |E| = n \times m$  in cui le righe rappresentano i *vertici* e le colonne gli *archi* 

Nel caso di *grafi orientati* metteremo : 
+ 1  nella casella che corrisponde al *veritice* di *arrivo*
+ -1 nella casella che corrisponde al *vertice* di *partenza*
+ 0   per tutte le altre caselle

>[!example]
![[MatriceAdiacenza.excalidraw]]
>
>
|   -   | **(1,2)** | **(1,4)** | **(3,1)** | **(3,2)** | **(3,4)** | **(4,1)** | **(2,2)** |
| :---: | :-------: | :-------: | :-------: | :-------: | :-------: | :-------: | :-------: |
| **1** |    -1     |    -1     |    +1     |     0     |     0     |    +1     |     0     |
| **2** |    +1     |     0     |     0     |    +1     |     0     |     0     |    -1     |
| **3** |     0     |     0     |    -1     |    -1     |    -1     |     0     |     0     |
| **4** |     0     |    +1     |     0     |     0     |    +1     |    -1     |     0     |

>[!note] 
>Quando troviamo un *cappio* possiamo mettere o -1 o +1 a piacimento visto possiamo capire che siamo in un cappio dal fatto che abbiamo solo un 1 nella colonna 
>
>Generalmente viene usato solo con *grafi* senza *cappi*

Se questo metodo viene utilizzato con *grafi non orientati* utilizzeremo 1 per indicare sia l'arrivo che la partenza 

Questa rappresentazione è utilizzata nel caso in cui abbiamo un *grafo sparso* ( in modo che abbiamo poche colonne per diminuire la complessità spaziale )

## Componente Connessa

Dato un grafo $G=(V,E)$  , una *componente connessa* di $G$ è un sottoinsieme di *vertici* $V'$ tale che :
+ Il sottografo indotto da $V'$ ( $G[V']$ ) è connesso
+ $V'$ non è contenuto in nessun insieme di *vertici* che indica un sottografo connesso
	In altre parole non è possibile aggiungere un vertice esterno ad una componente connessa e ottenere un grafo connesso

>[!example]
![[ConnectedComponents.excalidraw]]
>
>Non possiamo aggiungere $6$ nel primo componente connesso altrimenti non è più connesso 

**Proprietà** : 
+ L'insieme delle *componenti connesse* di un *grafo* formano una *partizione* ( l'$\cap$ risulta essere vuota e l'$\cup$ ritorna l'insieme di partenza ) di $V$ 

**Dimostrazione** : 

## Tipologie di grafi

### Grafo vuoto

Un *grafo vuoto* si rappresenta con $E_n$ ( $E$ indica che è empty , $n$ rappresenta il numero di vertici , ossia $n$ componenti connesse ) e indica un grafo con $n$ vertici e nessun arco
### Grafo completo

Si rappresenta con $K_n$ e indica il grafo con $n$ vertici e $n^2$ archi se *orientato* , $\frac{n(n-1)}{2}$ o $\binom V 2$ archi se *non orientato*
### Grafo complemento

Dato $G=(V,E)$ allora $\overline G=(V,\overline E)$ o $G^C$  è un nuovo grafo costruito sugli stessi *vertici*  ma con tutti gli archi non presenti in $E$ : 
$$\overline G=(V,\overline E)\implies (u,v)\in \overline E \iff (u,v) \notin E$$
![[Coplemento.excalidraw]]

>[!note]
>$\overline K_n = E_n$ 
### Grafo bipartito

Un *grafo bipartito* è un grafo che può essere partizionato in due parti tali che all'interno di ciascuna di queste non ci sono *archi* ( sono grafi vuoti ) obbiamo solo archi tra i due insiemi

**Grafo bipartito completo** : 
	Tutti i possibili archi tra i due insiemi

>[!note]
>Un grafo può essere sempre $k$-partito

Se indichiamo con $n_1$ e $n_2$ il numero di *vertici* di ogni *partizione* possiamo dire che il numero di archi di un *grafo bipartito* sono : $n_1\times n_2$

Formalmente possiamo dire : 
$$\exists\  V_1 , V_2 \subseteq V \ \text{tale che} : $$$$\begin{cases}V_1 \cap V_2 = \emptyset \\ V_1 \cup V_2 = V\end{cases}$$
$$\text{t.c.}\ \forall (u , v) \in E : (u \in V_1 \land v \in V_2) \lor(u \in V_2 \land v \in V_1)$$
Oppure $G[V_1]$ e $G[V_2]$ sono vuoti
## Grado

Per *grafi non orientati* il grado rappresentra il numero di vertici adiacenti al vertice $u$ ( $deg(u)$ )

>[!example]
![[Degree.excalidraw]]

L'*intorno* ( l'insieme dei vertici per cui esiste un arco tra $u$ e $v$ ) di $u$ è rappresentato nel seguente modo : $N(u)=\{ v\in V | (u,v)\in E \}$ potremmo quindi scrivere : $deg(u)=|N(u)|$

### Proprietà

Non possiamo creare un *grafo* tale che ogni vertice ha un *grado* diverso

**Dimostrazione** per assurdo
	Supponiamo che esista un grafo $G$ tale che tutti i $0\le deg(u)\le n-1$ 
	Allora avremo che dovranno esistere vertici con $deg(u)=0$ ma anche uno con $deg(u)=n-1$ ciò significa che dovrebbero esistere due *vertici* uno che abbia 0 archi e uno che sia collegato a tutti i *vertici* ==Impossibile== 
#### Somma dei gradi

Notiamo che la somma dei *gradi* può essere scritta come $2\ \cdot$ numero archi 

**Lemma della stretta di mano** ( solo su grafici non orientati ) : 
	Sia $G=(V,E)$ un grafo non orientato allora la somma dei gradi dei nodi di $G$ è un numero pari , in particolare il doppio della cardinalità di $E$ 
	$$\sum_{i=1}^n deg(i)=2\cdot |E|$$
	*Dimostrazione* : possiamo dimostrare notando che si conta due volte ogni arco

Se rappresentiamo il *grafo* con una matrice di adiacenza il *grado* può essere calcolato sommando tutti i valori della riga corrispondente ad $i$ , se abbiamo un *grafo non orientato* questo vale anche per la somma della colonna 

#### Moltiplicazioni della martice di adiacenza

Consideriamo un grafo $G=(V,E)$ *non orientato* allora avremo che $A_G$ sarà la *matrice di adiacenza* di $G$ , cosa rappresenterà $A \times A = A^2 = (a_{ij}^{(2)}) = \sum_{l=1}^n a_{ik}\cdot a_{lj}$ 

Cosa rappresenta nei seguenti casi : 
+ $i==j$
	Avremo che $a_{ii}=\sum_{k=1}^n[a_{ik}\cdot a_{ki}] = \sum_{k=1}^n a_{ik}^2$
	Ma essendo che $a_{ik}$ può essere solo o 1 o 0 avremo che la radice di questi numeri sarà uguale alla radice dei numeri precedenti , possiamo quindi scrivere : 
	$a_{ii}=\sum_{k=1}^n a_{ik}=deg(i)$ 
	Possiamo quindi dire che i valori che troviamo sulla *diagonale* della matrice quadrata $A^2$ rappresentano il *grado dei nodi del grafo*
+ $i\neq j$ 
	Avremo che $a_{ij}=\sum_{k=1}^n[a_{ik}\cdot a_{kj}]$ dove il prodotto tra $a_{ik}$ e $a_{jk}$ assume come valore 1 se entrambi sono 1 ( ossia c'è un cammino tra $i$ e $k$ e un cammino tra $k$ e $j$ il che implica l'esistenza di un cammino di lunghezza 2 tra $i$ e $j$ ) 0 altrimenti , possiamo quindi dire che la somma di tali cammini indica il *numero di cammini di lunghezza 2 tra $i$ e $j$*

Riassumendo possiamo scrivere : 
$$a_{ij}^{(2)}=\begin{cases} deg(i) &\text{se}\ i == j\\ \text{n° di cammini di lunghezza 2 tra $i$ e $j$} & \text{se} \ i \neq j \end{cases}$$
In **generale** se abbiamo il prodotto di $k$ matrici di adiacenza $A$ allora la matrice risultante rappresenta : 
+ se $i\neq j$ il numero di cammini di lunghezza $k$ tra i nodi $i$ e $j$ 

>[!important] Dimostrazione
>>[!todo]
>>#todo
### Grafo regolare

Sono *grafi* con i vertici con lo stesso grado 

![[Regolari.excalidraw]]

Un *grafo* viene detto $k$-regolare se $\forall u \in V : \quad \ deg(u)=k$ 

Se $G$ è $2$-regolare allora per il *lemma della stretta di mano* avremo che : 
$$\sum_{u\in V} deg(u) = 2\cdot m$$
$$n\cdot deg(u) = 2\cdot m$$
$$2\cdot n = 2\cdot m \implies n=m$$

Possiamo dimostrare che il numero di vertici di grado dispari è sempre pari

Dividiamo $V$ in due sottoinsiemi di vertici : 
$$P=\{ u \in V | deg(u)\ \text{è pari} \ \}$$
$$D=\{ u \in V | deg(u)\ \text{è dispari} \ \}$$
$P$ e $D$ costituiscono quindi due *partizioni* di $V$ dove avremo che $P \cup D = V$ e $P\cap D = \emptyset$ 
Sviluppiamo quindi il *lemma della stretta di mano* : 
$$2\cdot m = \sum_{u\in V} deg(u)$$
$$= \sum_{u\in P} deg(u) + \sum_{u\in D} deg(u)$$
$$= \sum_{u\in P} 2\cdot f(u) + \sum_{u\in D} (2\cdot f(u)+1)$$
	Dove questo perchè sappiamo che $deg(u)$ di $P$ è pari e quindi può essere trasformato in $2\cdot f(u)$ ossia come può essere rappresentato un numero pari , il contrario vale per $D$ dove un numero dispari può essere rappresentato con $2\cdot f(u) +1$ 
$$= \sum_{u\in P} 2\cdot f(u) + \sum_{u\in D} 2\cdot f(u) + \sum_{u \in D} 1$$
$$= 2\cdot\left( \sum_{u\in P} f(u) + \sum_{u\in D} f(u) \right) + |D|$$
$$2\cdot m= 2\cdot \sum_{u\in V} f(u)  + |D|$$
$$|D|=2 \cdot\left( m - \sum_{u\in V} f(u) \right)$$
Che essendo scritto nella forma in cui scriveremmo un qualsiasi numero *pari* sarà anch'esso *pari*

### Proprietà

#### Esistono almeno 2 vertici con grado 1 ( sono *Terminali* )

Considerando un grafo $G=(V,E)$ *non orientato* senza veritici *isolati* ( $deg()=0$ ) e per cui abbiamo che : $|E|=|V|-1$ 

Voglia dimostrare che se prendiamo l'insieme di veritici $V_1$ di grado $1$ allora $|V_1| \ge 2$ 

**Dimostrazione** : 
>[!todo] 
#### Grado di un Grafo Orientato

Per grafo $G=(V,E)$ *orientato* avremo che possiamo suddividere il grado di un vertice in : 
+ $in\_deg(u)$ : rappresenta il numero di *archi* *entranti* in un *vertice* $u$
+ $out\_deg(u)$ : rappresenta il numero di *archi* *uscenti* in un *vertice* $u$ 

Se abbiamo la *matrice di adiacenza* possiamo calcolarli nei seguenti modi : 
$$in\_deg(i)=\sum_{j=1}^n a_{ji} \quad \text{ossia la somma della $i$-esima colonna}$$
$$out\_deg(i)=\sum_{j=1}^n a_{ij} \quad \text{ossia la somna della $i$-esima riga}$$

Vale che la somma degli $in\_deg$ e $out\_deg$ rappresenta il numero totale di archi presenti all'interno di un grafo orientato , possiamo anche vederlo come : 
$$\sum_{i=1}^nin\_deg(i) = \sum_{i=1}^nout\_deg(i)=m $$
Per i grafi *orientati* vale anche che all'interno della diagonale di $A$ è presente il numero di cicli che passano su quel vertice
### Isomorfismo di grafi

Dati due grafi $G_1 = (V_1,E_1)$ e $G_2 = (V_2,E_2)$ allora $\phi : V_1 \to V_2$ è un *isomorfismo* se valgono le seguenti propietà : 
1. $\phi$ è biunivoca ( o bigettiva )
2. Deve preservare l'adiacenza tra i vertici : $(u,v) \in E_1 \iff (\phi(u), \phi(v))\in E_2$ 

>[!example]
![[Isomorfismo.excalidraw]]
>
>I due grafi si dicono *isomorfi* ( $G_1 \simeq G_2$ ) ( o uguali ) se esiste almeno un *isomorfismo* 
>Per i due grafi precedenti possiamo trovare il seguente isomorfismo : 
>$\phi : \{1,2,3\} \to \{a,b,c\}$
>$1 \to b$
>$2 \to a\ \text{or} \ c$
>$3 \to c\ \text{or} \ a$
>Si nota infatti che la funzione è *biettiva* e che le adiacenze sono rispettate infatti : tra i nodi $1$ e $2$ c'è un *arco* come anche tra $b$ e $a$ , tra i nodi $1$ e $3$ c'è un *arco* come anche tra $b$ e $c$ , infine tra i nodi $2$ e $3$ non c'è un *arco* come tra $a$ e $c$
>
>In pratica $\phi$ rappresenta la seguente associazione :
![[phi.excalidraw]]

>[!note]
>Un grafo *isomorfo* può essere detto *uguale* ( rappresenta la stessa relazione ) ad un altro grafo

Un *grafo* è detto **Auto-complementare** se $G \approx\overline G$

>[!note]
>Non esiste un algoritmo di tempo polinomiale che , dati due grafi , ritorni la funzione di isomorfismo tra di essi , qualora esistesse 
#### Proprietà necessarie ma non sufficenti per l'*isomorfismo*

1. $|V_1| = |V_2|$
2. $|E_1| = |E_2|$
3. $deg\_seq(G_1)=deg\_seq(G_2)$
	Dove $deg\_seq$ rappresenta la *degree sequence* di un grafo ossia il vettore di $n$ elementi dove sono scritti in ordine crescente gli *ordini* o *degree* dei nodi del grafo
>[!example]
![[deg_seq.excalidraw]]
>
>Questo grafo ha come *degree sequence* : $deg\_seq = <1,2,2,3>$
4. $NCC(G_1) = NCC(G_2)$
	Dove $NCC$ rappresenta il *Numero di Componenti Connesse*
5. $\omega_{G_1} = \omega_{G_2}$
	Dove $\omega$ rappresenta il *Clique number* ossia la cardinalità della *clique massima* , questa è la *clique* ( *sottografo completo* ) con il più grande numero di vertici , una *clique massimale* invece è una *clique* che non è contenuta in una *clique* più grande
>[!example]
![[Clique.excalidraw]]
#### Traccia di una matrice

Consideriamo una matrice $A = n \times n$ allora la *taccia* di questa è : 
$$tr(A)=\sum_{i=1}^{n}a_{ii}$$
Ossia la somma dei valori sulla diagonale principale 

Possiamo dire che $G=(V,E)$ *grafo non orientato* ha : 
+ $tr(A)=0$ : questo poichè in un grafo non orientato non essendoci cappi il numero di vertici tra $i$ e $i$ è sempre 0
+ $tr(A^2) = 2\cdot |E|$ : questo rappresenta la somma degli archi uscenti da un nodo che rappresenta il numero totale di archi moltiplicato per 2 poichè se un nodo è collegato ad un'altro allora verrà contato una volta per il primo ed un'altra per il secondo ( *lemma della stretta di mano* ) 
+ $tr(A^3)=\sum_{i=1}^n a_{ii}^{(3)}$ : questo rappresenta  il numero di cammini di lunghezza $3$ che vanno da $i$ ad $i$ ossia 2 volte il numero di *triangoli* presenti adiacenti ad un nodo $i$ ( 1 triangolo ha infatti 2 versi di percorrenza ) , la sommatoria quindi rappresenta 6 volte il numero di triangoli presenti in totale in un *grafo* ( 6 poichè ogni triangolo aventi 3 vertici avremo che ognuno di essi può avere $2 \times$ i suo triangoli adiacenti  )

>[!example] 
![[Triangoli.excalidraw]]
>
>|       | **1** | **2** | **3** | **4** |
| :---: | :---: | :---: | :---: | :---: |
| **1** |   2   |       |       |       |
| **2** |       |   4   |       |       |
| **3** |       |       |   4   |       |
| **4** |       |       |       |   2   |
>
>Questa è la tebella $A^3$

>[!note]
>Un *grafo non orientato* contiene un *triangolo* se e solo se $\exists\ i,j \in V \quad i\neq j$ tale che $a_{ij}\cdot a_{ij}^{(2)}\neq 0$
>
>Perchè questo si verifichi deve essere che $a_{ij} \neq 0$ e $a_{ij}^{(2)} \neq 0$ , 
>+ $a_{ij} \neq 0$ : avviene se esiste un arco tra $i$ e $j$
>+ $a_{ij}^{(2)} \neq 0$ : avviene se esiste un cammino di lunghezza $2$ che congiunge $i$ e $j$
### Connettività , Aciclicità

In *grafi non orientati* $G$ è *connesso* se $\forall u ,v \in V \quad u \neq v \quad \exists \ \text{un cammino che li collega}$

**Proprietà** : 
	Qual'è il numero minimo di archi perchè un grafo sia connesso ? 

Abbiamo che : 
	Se $G$ è connesso allora $|E| \ge |V|-1$

**Dimostrazione** per induzione sul numero di vertici del grafo 

La *base* dell'induzione sarà : 
	$$n=2 \quad |E|=1 \ \ \ |V| = 2 \quad |E|=|V|-1 \quad \text{come volevasi dimostrare}$$
Supponiamo ora che la proprietà valga per un grafo con $n-1$ vertici e dimostriamo la proprietà per $n$ vertici

*Passo induttivo* : per $n\ge 3$

Consideriamo un vertice $Z \in V$ , togliamolo dal *grafo* , consideriamo quindi $G[V - \{Z\}]$ ossia il *grafo indotto* da $V - Z$ , questo possiamo dunque rappresentarlo con $G'$ il quale avrà come $|V'| = n-1$ , questo però non può essere usato direttamente poichè togliendo $Z$ potremmo disconnettere il grafo e quindi non essere più nelle ipotesi di avere un *grafo connesso* 
Indichiamo quindi con $k$ il numero di componenti connesse di cui è costituito $G'$ ( se $G'$ è connesso $k=1$ ) , essendo che ogni *componente connesso* è *connesso* posso utilizzare l'ipotesi induttiva
Indico con $E_i$ gli archi dell'$i$-esima componente connessa e con $V_i$ i vertici dell'$i$-esima componente connessa , allora possiamo dire per ipotesi induttiva che : 
$$|E_i|\ge |V_i|-1$$
Vorrei dimostrare che $|E|\ge |V|-1$ quindi deve essere vero che $|E|\ge \sum_{i=1}^{k}|E_i| +deg(Z)$
Ossia il numero di archi del grafo iniziale deve essere equivalente alla somma degli archi di tutte le componenti connesse più gli archi del nodo che ho tolto ( ossia $deg(Z)$ )
Quindi semplificando : 
$$|E|\ge \sum_{i=1}^{k}|E_i| +deg(Z)$$
Visto che so che per ipotesi induttiva abbiamo che $|E_i|\ge |V_i|-1$ possiamo scrivere : 
$$|E|\ge \sum_{i=1}^{k}(|V_i|-1) +deg(Z)$$
$$|E|\ge \sum_{i=1}^{k}|V_i|-k +deg(Z)$$
Visto che abbiamo tolto il vertice $Z$ avremo che la sommatoria può essere riscritta come : 
$$|E|\ge |V|-1-k +deg(Z)$$
Essendo che il grafo di partenza è connesso deve essere che $deg(Z)\ge k$ altrimenti non sarebbe connesso , e quindi $deg(Z)-k \ge 0$
Quindi possiamo sicuramente dire che : 
$$|E|\ge |V|-1$$
>[!warning] 
>Questa condizione non è *sufficente* per dire che il grafo è connesso , possiamo infatti vedere il seguente *controesempio* per verificarlo : 
![[Notconnected.excalidraw]]
>
>Possiamo vedere infatti che la condizione precedente è verificata ossia $|E|\ge |V|-1 = 5\ge 6-1$ ma il grafo non è connesso 

#### Condizione sufficente per la connettività di un grafo

Se $G=(V,E)$ è un grafo non orientato allora questo sarà connesso se il grado di ogni vertice è : 
$$deg(u)\ge \frac{n-1}{2}$$
**Dimostrazione** : 
	Usiamo la dimostrazione per *assurdo* : 

Supponiamo che $G$ *non* sia *connesso* e supponiamo che sia costituito da $k\ge 2$ componenti connesse dove $V_1$ e $V_2$ sono due *componenti connesse* di $G$

Avremo quindi che se vogliamo che valga che $G$ non sia connesso $|V| \ge |V_1|+|V_2|$

Prendiamo due nodi $u\in V_1$ e $v\in V_2$ questi per ipotesi induttiva ( può essere usata poichè stiamo parlando di componenti connesse ) hanno come $deg(u) \ge \displaystyle \frac{n-1}{2}$  avremo quindi che $|V_1| = \displaystyle \frac{n-1}{2} + 1$ dove 1 indica il vertice che stiamo prendendo in considerazione 

Lo stesso vale per $|V_2| =\displaystyle \frac{n-1}{2}+1$ 
Riportando questi nell'eqazione originale avremo : 
$$|V|\ge \frac{n+1}{2} + \frac{n+1}{2}$$
$$n \ge n +1$$
Che è un ==Assurdo== , possiamo quindi dire che $G$ deve essere per forza connesso 
### Grafi Aciclici non orientati

Condizione *necessaria* perchè un grafo sia *aciclico* : $|E| \le |V|-1$ 

**Dimostrazione** per induzione

*Caso Base* : 
+ $n=1$ : avremo un solo nodo e quindi nessun arco , la condizione è verificata
+ $n=2$ : avremo 2 nodi ed al massimo un arco tra di loro : la condizione è verificata

*Ipotesi Induttiva* : 
	La propriteà vale per ogni grafo con $|V|=n$ , verifichiamo per $n+1$

*Passo induttivo* : 

Rimuoviamo un vertice $Z$ dal grafo $G$ con $n=|V|$ , avremo quindi $G' = [V -\{Z\}]$ ( sottografo indotto )
Questo è composto da $k$ componenti connesse $V_1,V_2,\dots,V_k$ 
Per ogni componente connessa varrà quindi l'ipotesi induttiva $|E_i|\le |V_1|-1$ 
Ricordiamoci che dobbiamo arrivare alla seguente equazione : $|E|\le |V|-1$
Notiamo che $|E|$ può essere riscritto nel seguente modo : 
$$|E|=\sum^{k}_{i=1} |E_i|+\deg(Z)$$
Considerando $|E_i|\le |V_i|-1$ possiamo scrivere :
$$|E|=\sum^{k}_{i=1} (|V_i-1|)+\deg(Z)$$
$$|E|=\sum^{k}_{i=1} |V_i| -k+\deg(Z)$$
$$|E|=|V| -1 -k+\deg(Z)$$
Questo poichè la somma delle cardinalità dei componenti connessi risulta essere tutti i nodi di $|V|$ meno quello che abbiamo tolto all'inizio 
Avremo quindi che perchè sia vera $|E|\le |V|-1$ dovremmo avere che $\deg(Z) \le k$ 
### Grafi connessi e i loro complementi

|     $G$     |        $\bar G$        |        |          Controesempo          |
| :---------: | :--------------------: | ------ | :----------------------------: |
|  Connesso   |  $\implies$ Connesso   | Falso  | ![[CompConNotCon.excalidraw]]  |
|  Connesso   | $\implies$ Disconnesso | Falso  | ![[GrafoConNonCon.excalidraw]] |
| Disconnesso |  $\implies$ Connesso   | *Vero* |                                |
| Disconnesso | $\implies$ Disconnesso | Falso  |   ![[ComDiscCon.excalidraw]]   |

**Dimostriamo** intuitivamente la terza casistica

Abbiamo $k$ componenti connesse , il *complementare* di ogni coppia di componenti connesse rappresenta tutti gli archi tra le due componenti 
Prendiamo quindi 2 nodi , avremo 2 casi : 
+ $u\in V_1$ e $v\in V_2$ : in questo caso sicuramente avremo che i due nodi saranno connessi poichè le due componenti connesse sono connesse tra di loro ( in $\bar{G}$ )
+ $u,v\in V_1$ : in questo caso non sappiamo se sono collegati tra di loro ma so che abbiamo tutti i possibili archi tra le due componenti , questo ci garantisce che anche se non vi è un arco tra $u$ e $v$ ci basterà uscire dal componente connesso che li contiene e sicuramente avremo un cammino che li collega 
### Alberi

Un *albero* è un grafo *aciclico connesso* dove avremo che $|E|=|V|-1$ ( questo per l'unione tra le proprietà dell'*aciclicità* e *connettività* ) 

Una proprità dell'*albero* è la : **Fragilità** : 
+ Se aggiungo un arco all'*albero* questo non è più *aciclico*
+ Se tolgo un arco all'*albero* il grafo diventa disconnesso

**Caratterizzazioni** degli alberi , le affermazioni sono *equivalenti* tra loro se $G=(V,E)$ è un grafo non orientato: 
+ $G$ è un albero
+ Due vertici qualsiasi di $G$ sono connessi da un unico cammino ( condizione sufficente perchè sia un albero )
+ $G$ è connesso ma se un arco qualsiasi è rimosso da $G$ allora il grafo risultante è disconnesso
+ $G$ è connesso e $|E|=|V|-1$
+ $G$ è aciclico e $|E|=|V|-1$
+ $G$ è aciclico ma se un arco qualsiasi viene aggiunto in $G$ il grafo diventa ciclico 
#### Alberi di copertura 

Un *albero di copertura* è un sottoinsieme di archi che forma un albero e toccano tutti i vertici del grafo 
Più formalmente possiamo scrivere : $T\subseteq E$ tale che $(V,T)$ è un albero

Dato un grafo possono esitere più alberi di copertura

>[!example] 
![[AlberoCopertura.excalidraw]]

#### Alberi di copertura minimi

Dato un grafo $G(V,E,\omega)$ dove $\omega$ rappresenta una funzione peso $\omega : E\to R$ relativa agli archi di $G$ 
Allora l'*albero di copertura minimo* ( *MInimum Spanning Tree* ( *MST* ) ) DI $G$ è un albero di copertura avente la somma dei pesi sugli archi minima 

>[!example] 
![[MST.excalidraw]]

##### Fatto cruciale

Dato un *taglio* di un grafo : 
	dato $G=(V,E)$ è $(S,V-S)$ dove $S \subseteq V$ 

Poichè ipotizziamo che il grafo è connesso avremo che almeno un arco attraverserà il taglio
Il primo vertice di questo taglio deve essere contenuto nell'insieme $S$ e il secondo vertice in $S-V$ 

>[!note] 
>Un arco con peso minimo che attraversa un *taglio* si dice **arco leggero**

>[!note] Fatto cruciale
>Se $(u,v)$ è un ( possono essere molteplici ) *arco leggero* allora $(u,v)$ appartiene ad un **MST** 

**Tecnica del cuci e taglia** 

**Dimostrazione** : 

$T$ è un **MST** di $G$

2 casi : 
+ $(u,v) \in T$ : la dimostrazione è finita visto che $(u,v)$ è già in $T$
+ $(u,v) \notin T$ : 
	1. *cuci* aggiungo l'arco $(u,v)$ a $T$ = $T'$ , in questo caso si crea un ciclo visto che $T$ è un **MST** 
	   poichè abbiamo un ciclo sicuramente avremo un arco che attraversa il taglio oltre a $(u,v)$ , $(x,y)$ 
	   Inoltre visto che $(u,v)$ è *leggero* sicuramente avremo che tutti gli altri archi presenti nel taglio avranno il peso $\le$ rispetto a $(u,v)$ ( $w(u,v)\le w(x,y)$ ) 
	2. *taglia* rimuoviamo l'arco che creava il ciclo dal gafo $T'$
		$T' - \{x,y\} = T''$ allora $T''\in MST(G)$ 
		Come prima cosa $T''$ sicuramente è uno *spanning tree* per il modo in cui l'ho costruito : ossia aggiungendo e poi togliendo un arco ma se $T''$ fosse un $MST(G)$  allora dovrebbe essere che : $w(T'') == w(T)$ 
		$w(T'') = w(T)+w(u,v)-w(x,y)$  
		visto che $w(u,v)\le w(x,y)$ sicuramente $w(u,v) - w(x,y) \le 0$
		Quindi $w(T'') \le w(T)$ e poichè $T$ è un $MST$ $\implies w(T)\le w(T'')\le w(T)$ 

>[!todo] 
>Spiega meglio

>[!important] 
Questo ci dice che se $(u,v)$ è un arco leggero che attraversa $(S,V-S)\implies \exists\ T \in MST(G)\ \text{t.c.}\ (u,v)\in T$  

Dimostriamo ora che se $(u,v)$ è l'*unico* arco leggero che attravversa il taglio $(S,V-S)$
$$\implies \forall\ T \in MST(G) \ \text{t.c.} \ (u,v) \in T$$
Ossia tutti gli alberi di copertura minimi conterranno quell'arco

**Dimostrazione** per assurdo

Supponiamo che $\exists \ T \in MST(G)\ \text{t.c.} \ (u,v) \notin T$
Utilizziamo la tecnica del *cuci e taglia* per la dimostrazione

1. $T' = T \cup (u,v)$ -> si forma un ciclo , sicuramente avremo un arco $(x,y)$ che attraversa il taglio
2. $T'' = T' - (x,y)$ -> $T''$ è uno *spanning tree* , poichè $(u,v)$ è un arco leggero unico avremo che $w(u,v) < w(x,y)$ 
	Avremo quindi che : $w(T'')=w(T)-w(u,v)+w(x,y)$ ma essendo che $w(u,v)-w(x,y)<0$ questo è **assurdo** 

**Osservazione**

Abbiamo $G(V,E,w)$ grafo non orientato connesso e $(u,v)\in E$ è l'arco di peso minimo dell'intero grafo allora $\forall (x,y) \in E , w(u,v)\le w(x,y)$ ( tutti gli archi dovranno avere peso maggiore o uguale di $(u,v)$ ) avremo che $\exists\ MST(G)\ \text{t.c.}\ (u,v) \in T$ ossia $(u,v)$ dovrà per forza appartenere ad un $MST(G)$

**Dimostrazione**

Con metodo *cuci e taglia*

Diciamo che $T\in MST(G)$ , abbiamo 2 casi : 
+ $(u,v)\in T$ , in questo caso abbiamo già concluso la dimostrazione 
+ $(u,v)\notin T$ 
	1. *cuci* : aggiungi $(u,v)$ in $T$ = $T'$ , avendo aggiunto un arco ad uno *spanning tree* si formerà un ciclo 
	2. *taglia* : togliamo l'arco che crea il ciclo $T'-(x,y)=T''$ , il grafo risultante sarà anch'esso un $MST$ poichè : $w(T'') = w(T) +w(u,v) -w(x,y)$ e sapendo che $w(u,v)\le w(x,y)$ avremo che $w(T)\le w(T'')\le w(T)\implies w(T'')=w(T)$ questo vorrà dire che $w(T'')$ dovrà contenere $(u,v)$ , l'arco minimo dell'albero 
##### Teorema Fondamentale degli MST

Sia $G=(V,E,w)$ un grafo non orientato e connesso dove $w : E \to \mathbb{R}$ è una funzione peso sugli archi . 
Valgono le seguenti ipotesi : 
+ $A \subseteq E$ è un sottoinsieme di archi contenuto in qualche $MST$
+ $(S,S-V)$ un talgio di $G$ che **rispetta** A ( ossia se gli archi di A stanno in S o S-V o entrambi ma non devono esserci archi di A che attraversano il taglio )
+ Un arco $(u,v)$ è un *arco leggero* che attraversa il taglio 

Allora avremo che il *teorema fondamentale degli MST* afferma che $A \cup (u,v)$ è contenuto in qualche $MST$ . Si può dire che $(u,v)$ è **sicuro** per $A$

**Dimostrazione** : ( sempre per il *cuci e taglia* ) 

Sia $T\in MST(G)$ tale che $A \subseteq T$ 
1. $(u,v)\in T$ questo implica che $A \cup (u,v) \subseteq T$
2. $(u,v)\notin T$ 
	1. Aggiungiamo $(u,v)$ -> $T' = T \cup (u,v)$
	2. Tagliamo  $T'' = T' - (x,y)$ ( questo sarà un *minimum spanning tree* di $G$ poichè aggiungiamo un arco leggero del taglio e togliamo un arco leggero ( questo poichè si trova sul taglio che ha come arco leggero $(u,v)$ ) $(x,y)$ )
	Avremo quindi che $T''$ è un $MST$ di $G$

Possiamo quindi dire che $A\cup (u,v)\subseteq T''$ poichè $A$ era un insieme di archi tranne quelli sul taglio , $(u,v)$ invece è l'arco che abbiamo scielto da aggiungere in $T$ questo inoltre fa parte del taglio , avremo quindi che $A \cup (u,v) \subseteq T''$

>[!note] 
>Se nel metodo *cuci e taglia* facciamo prima il taglia del cuci non è la stessa cosa e porta ad un risultato scorretto

>[!example]
>>[!todo] 

###### Corollario del Teorema Fondamentale

In pratica è al riscrittura delle ipotesi che però portano alla stessa conclusione : 

Se G è un grafo non orientato connesso , pesato allora avremo le seguenti ipotesi : 
1. $A \subseteq E$ è un sottoinsieme di archi contenuto in qualche $MST$ 
2. Sia $C$ una componente connessa della foresta $G_A=(V,A)$
3. Sia $(u,v)$ un arco leggero che connette $C$ ad un'altra componente connessa della foresta $G_A$

Allora $(u,v)$ è *sicuro* per $A$ cioè $A \cup \{u,v\}$ è contenuto in qualche $MST$
#### Strutture Dati per Insiemi Disgiunti

>[!note] 
>L'intersezione di questi insiemi da $\emptyset$ 
>
>Ogni insieme è caratterizzato da un *rappresentante* che lo individua

>[!example] 
>$S_5 = \{3,5,7,32\}$
>$S_2 = \{2\}$
>$S_{17} = \{8,9,17,4\}$
>

**Operazioni** : 
+ `make_set(x) ->`$S_x = \{x\}$ 
	Crea un insieme il cui unico elemento è $x$ , questo diventa anche il suo *rappresentante*
+ `Union(x,y) ->`$S_x \cup S_y$ 
	Unisce 2 insiemi i cui *rappresentanti* sono $x$ e $y$
+ `Find_Set(x) ->` $S_y \ \text{t.c.} \ x\in S_y$ 
	Ritorna il *rappresentante* dell'insieme che contiene $x$ 

L'implementazione può essere fatta in 2 modi differenti : 
+ **Liste concatenate**
	+ `make_set(x)` semplicemente inizializza una cella con il valore $x$ e il puntatore `next` a `nullptr`
	+ `Union(x,y)` semplicemente concateniamo le 2 liste
	+ `Find_Set(x)` siamo costretti a scorrere l'intera lista ( $O(n)$ )
+ **Alberi radicati** 
	Costruiamo un albero binario radicato rispetto al rappresentate dell'insieme
	+ `Union(x,y)` visto che utilizziamo gli alberi quando facciamo la `union` è meglio che bilanciamo l'albero altrimenti la ricerca non è efficente ( questo avrà complessità $\log n$ )
	+ `Find_Set(x)` scorre l'albero fino alla radice e ritorna la radice ( $\log n$ )

Con questa struttura dati possiamo scrivere il seguente algoritmo che restituisce le componenti connesse di un grafo $G$ 
```pseudo
	\begin{algorithm}
	\caption{$\text{Connected Components}$}
	\begin{algorithmic} 
		\ForAll{$v \in V[G]$}
		\State $\text{Make\_Set(v)}$
        \EndFor
        \ForAll{$(u,v)\in E[G]$}
	        \If{$\text{Find\_Set(u)} \neq \text{Find\_Set(v)}$ }
		        \State $\text{Union(u,v)}$
            \EndIf
        \EndFor
	\end{algorithmic}
	\end{algorithm}
```
>[!example] 
>Svolgiamo l'agoritmo sul seguente grafo
![[ExGraph.excalidraw]]
>
| Step | Insiemi                               | Arco    |
| :--: | ------------------------------------- | ------- |
|  0   | $\{1\},\{2\},\{3\},\{4\},\{5\},\{6\}$ |         |
|  1   | $\{1,2\},\{3\},\{4\},\{5\},\{6\}$     | $(1,2)$ |
|  2   | $\{1,2\},\{3\},\{4,5\},\{6\}$         | $(4,5)$ |
|  3   | $\{1,2,3\},\{4,5\},\{6\}$             | $(1,3)$ |
|  4   | $\{1,2,3\},\{4,5\},\{6\}$             | $(2,3)$ |
#### Algoritmo di ricerca di MST

```pseudo
	\begin{algorithm}
	\caption{$\text{Generic-MST}$}
	\begin{algorithmic}
	\State $A \leftarrow \emptyset$
	\While{$|A| < |V[E]|-1$}
		\State $\text{trova un arco sicuro per A}$
		\State $A \leftarrow A \cup \{(u,v)\}$
    \EndWhile
    \Return A
	\end{algorithmic}
	\end{algorithm}
```

**Correttezza**

Questo algoritmo è corretto per come viene costruito $A$ ( questo infatti sarà sempre un sottoinsieme di un $MST$ ) ( per via del *teorema fondametale degli MST* )
>[!todo] 
>Controlla ?????
#### Algoritmo di Kruskal

Avendo $G$ un grafo non orientato connesso
```pseudo
	\begin{algorithm}
	\caption{$Kruskal(G)$}
	\begin{algorithmic}
	\State $A \leftarrow \emptyset$
	\ForAll{$v \in V[G]$}
		\State $\text{Make\_Set(v)}$
    \EndFor
    \State $\text{Ordina gli archi di G in modo crescente}$
    \ForAll{$(u,v) \in E[G]$}
	    \If{$\text{Find\_Set(u)} \neq \text{Find\_Set(v)}$}
		    \State $\text{Union(u,v)}$
		    \State $A \leftarrow A \cup \{(u,v)\}$
        \EndIf
    \EndFor
    \Return A
	\end{algorithmic}
	\end{algorithm}
```
**Correttezza**

La correttezza dell'agoritmo può essere verificata grazie al *teorema fondametale degli MST* , inoltre , per il modo in cui estraggo l'arco ( estraggo sempre il minimo dall'ordinamento crescente ) questo sarà **sicuro** per $A$

**Complessità**

Indichiamo con $n$ il numero di vertici e $m$ il numero di archi

La complessità è data da :
+ Il primo `for each` ha complessità $O(n)$
+ L'ordinamento ha complessità $O(m \log m)$ ( visto che è la complessità migliore per un algoritmo di ordinamento basato sui confronti )
+ Il secondo `for each` viene svolto $m$ volte e le operazioni `find_set` e `union` hanno complessità $O(\log m)$ , avremo quindi che la complessità totale sarà $O(m\log m)$

La complessità totale sarà : $O(n + m \log m + m \log m) = O(m \log m)$ 
questo poichè essendo che siamo in un grafo *connesso* $m \ge n$ 
#### Algoritmo di Prim

L'algoritmo di *Prim* a differenza dell'algoritmo di *Kruskal* costruisce un albero radicato , prendendo in input il grafo , la funzione peso e la radice dell'MST

L'algoritmo si serve di una struttura dati formata da una coda di minima priorità $Q$ che memorizza i vertici del grafo per estrarli uno alla volta sulla base del campo `Key[u]` , $u \in V$ , che contiene il minore tra i pesi degli archi $u$ che attraversano un taglio 

La *key* rappresenta la chiave della coda di priorità $Q$ , se voglio quindi estrarre un arco leggero mi basterà prendere la *key* con il valore minore , dopo aver aggiunto un arco devo però aggiornare i campi *key* dei vertici rimaneti visto che il taglio adesso non comprende più il vertice scelto

Per ogni vertice inoltre abbiamo un campo `predecessore` che è un puntatore al suo predecessore ( utilizzato per costruire l'albero che stiamo cercando )

>[!example] 
![[Prim.excalidraw]]

Il campo *key* deve essere aggiornato infatti potremmo avere il seguente caso : 

![[keycahgeMST.excalidraw]]

>[!note] 
>L'ordine di estrazione non è importante , tanto troveremo al massimo un MST diverso ma sarebbe comunque un MST

**Algoritmo** : 
```pseudo
	\begin{algorithm}
	\caption{MST\_Prim(G,w,r)}
	\begin{algorithmic}
	\State $Q \leftarrow V[G]$
	\ForAll{$u \in V[G]$}
		\State $key[u]\leftarrow + \infty$
		\State $\pi[u] \leftarrow NIL$
    \EndFor
    \State $key[r] \leftarrow 0$
    \While{$Q \neq \emptyset$}
	    \State $u \leftarrow \text{Extract\_Min(Q)}$
		\ForAll{$v \in Adj[u]$}
			\If{$v \in Q \land w(u,v) < key[v]$}
				\State $key[v]\leftarrow w(u,v)$
				\State $\pi[v] \leftarrow u$
            \EndIf
        \EndFor
    \EndWhile
    \Return $A = \{v,\pi[v]\in E | v \in V - \{r\}\} $
	\end{algorithmic}
	\end{algorithm}
```

**Spiegazione** : 

+ *Inizializzazione* : 
	All'inizio dell'algoritmo $Q$ corrisponde all'insieme dei vertici $V$  
	Il campo `Key[u]` di ogni nodo viene inizializzato a $\infty$ tranne per la radice che è inizializzata a 0 
	Il campo $\pi$ di ogni nodo viene inizializzato a `NIL` 
+ *Estrazione* : 
	Finchè $Q$ non è vuoto viene estratto il minimo da $Q$ cioè il vertice del grafo che non è ancora stato estratto avente campo `Key` minore.
	Questo prevede anche l'aggiornamento del *taglio* che divide i nodi appartenenti a $Q$ sai nodi $V-Q$
+ *Aggiornamento campi* :
	L'estrazione di un elemento di $Q$ va aggiunto all'insieme $V-Q$ , questo porta alla conseguenza che il *taglio* va aggiornato
	Bisogna quindi aggiornare il valore `Key` dei nodi di $V-Q$ ( per esempio se includiamo un arco non incluso precedentemente )

**Terminazione** : 

Poichè tolgo sempre nodi da $Q$ prima o poi questo diventerà $\emptyset$ e quindi l'algoritmo terminerà

**Correttezza** : 

Poichè ogni ciclo del `while` aggiungiamo un arco leggero avremo che sicuramente ritorna un *MST*

**Complessità** :

+ L'inizializzazione ha complessità $O(n)$ 
+ *Extract_Min* : visto che il minimo si trova sulla radice dell'albero dovremo aggiornare l'albero , questo costa $\log n$
+ Il *for each* viene svolto per il numero di archi adiacenti a $u$ ( ossia il grado di quel vertice ) , visto che questo viene svolto per tutti i nodi allora verrà svolto $2 \cdot m$ 

Avremo quindi in totale che la complessità sarà : 
$$n+n\log n + 2m\log n$$
Visto che $m \ge n-1$ avremo che $T(n,m)=O(m\log n)$ 

>[!example] 
>>[!todo] 
### Cammini minimi sui grafi

Dato un *grafo orientato* $G=(V,E)$ avente pesi sugli archi ( $w: E \to \mathbb{R}$ )
Il problema che ora affrontiamo è quello di determinare il cammino minimo tra due vertici 

>[!note] 
>Gli algoritmi che studieremo saranno applicabili sia a grafi non orientati ( possimao convertirli in grafi orientati duplicando gli archi e mettendoli in direzioni opposte con lo stesso peso )

>[!important] Definizione
>Avendo due $u,v \in V$ : $v$ è raggiungibile da $u$ se $\exists$ un cammino tra $u$ e $v$ altrimenti viene detto *irraggiungibile*   

>[!important] Peso di un cammino
>Avendo il cammino $p = <x_0,x_1,x_2,...,x_q>$ dove $x_0=u$ e $x_n=v$ 
>$\forall i = 1,...,q , \ (x_{i-1},x_i) \in E$ allora il peso del cammino sarà :
>$w(p)=\sum^{q}_{i=1} w(x_{i-1},x_i)$
>
>L'insieme dei cammini può anche essere scritto nel seguente modo : 
>$C(u,v) = \{p|p\ \text{è un cammino tra u e v}\}$

La *distanza tra 2 vertici* sarà :
$$\delta(u,v)=\begin{cases}
\min w(p) & \text{se} \ C(u,v)\neq \emptyset \\
+\infty & \text{se} \ C(u,v)= \emptyset \\
-\infty & \text{se} \ C(u,v)\neq \emptyset\ \text{ed}\ \exists \ \text{cicli di costo negativo tra u e v}
\end{cases}$$
Possiamo descrivere i tre casi nel seguente modo : 
1. Ritorneremo il peso minimo tra i cammini trovati tra $u$ e $v$
2. La distanza è $+\infty$ se $v$ sono *irraggiungibili*
3. La distanza è $-\infty$ se esiste un ciclo *negativo* tra $u$ e $v$

Facciamo un esempio : 

![[Distance.excalidraw]]
#### Quattro tipi di problemi

I problemi che possiamo risolvere si possono dividere a seconda del numero di sorgenti e destinazioni 

1. Dati $G=(V,E)$ orientato e pesato sugli archi e $u,v \in V$ si cerchi il cammino minimo da $u$ a $v$ 
2. Dati $G=(V,E)$ orientato e pesato sugli archi e $s \in V$ si cerchi il cammino minimo da $s$ a tutti gli altri vertici 
3. Dati $G=(V,E)$ orientato e pesato sugli archi e $d \in V$ si cerchi il cammino minimo da tutti i vertici a $d$
4. Dati $G=(V,E)$ orientato e pesato sugli archi si cerchi il cammino minimo tra tutte le possibili coppe di nodi 

I problemi 2 e 3 sono interscambiabili basterà invertire il verso del grafo 

>[!note] 
>Il problema 1 risulta avere una simile complessità al problema 2 perchè comunque dovremo cercare l'intero grafo
#### Proprietà dei cammini minimi

>[!important] 
>Sottocammini di cammini minimi sono anch'essi minimi

>[!example] 
![[CamminiMinimi.excalidraw]]

**Dimostrazione** per *assurdo*

Supponiamo per assurdo che esista un'altro cammino tra $x$ e $y$ il cui peso è minore del cammino precedente tra $x$ e $y$

Allora il peso del cammino tra $u$ e $v$ avrebbe peso $<$ del cammino precedente che però è assurdo poichè abbiamo come ipotesi che il cammino tra $u$ e $v$ era minimo
#### Strutture dati

Per ogni vertice ( $\forall u \in V$ ) avremo : 
1. $d[u]$ : stima della distanza tra $s$ ( sorgente ) e $u$ 
2. $\pi[u]$ : puntatore al predecessore

**Operazioni** : 

*Inizializzazione*
```pseudo
	\begin{algorithm}
	\caption{INIT\_SS(G)}
	\begin{algorithmic}
	\ForAll{$v \in V[G]$}
		\State $d[v] = +\infty$
		\State $\pi[v] = NIL$
    \EndFor
    \State $d[s] = 0$
	\end{algorithmic}
	\end{algorithm}
```
*Relax*
Utilizzato per abbassare il valore $d$ di un vertice 
```pseudo
	\begin{algorithm}
	\caption{RELAX(u,v, w(u,v))}
	\begin{algorithmic}
    \If{$d[v]>d[u]+w(u,v)$}
	    \State $d[v]\leftarrow d[u] + w(u,v)$
	    \State $\pi[v]\leftarrow v$
    \EndIf
	\end{algorithmic}
	\end{algorithm}
```
>[!example] 
>![[relax.excalidraw]]

Visto che $d[u]$ rappresenta la distanza del cammino che abbiamo trovato fino ad ora e visto che ora $d[u]+w(u,v)$ è minore di $d[v]$ allora significa che abbiamo trovato un cammino migliore per arrivare a $d[v]$ 
#### Grafo dei Predecessori

$G_{\pi}=(V_{\pi},E_{\pi})$ è un sottografo del grafo di partenza $G$ che dipende dal campo predecessore dei vertici di $G$ 
Gli insiemi $V_{\pi}$ e $E_{\pi}$ sono definiti nel seguente modo : 
+ $V_{\pi}=\{s\}\cup\{ u \in V : \pi[u] \neq NIL \}$ , ossia rappresenta tutti i vertici che hanno predecessori 
+ $E_{\pi} = \{(\pi[u],u) \in E : u \in V_{\pi} - \{s\}\}$ , rappresenta gli archi che collegano i vertici con i predecessori

>[!example] 
![[PredecessorGraph.excalidraw]]
>
>Avremo che : 
>$V_{\pi} = \{s,a,c\}$ e $E_{\pi} = \{(s,a),(a,c)\}$
#### Albero di cammini minimi

$G'=(V',E')$ è un albero di cammini minimi , sottografo di $G(V,E,w)$ dove avremo che : 
+ $V' = \{u \in V : \delta(s,u)<+\infty\}$
+ $G'$ forma un albero con radice $s$ 
+ Per ogni vertice $u\in V'$ l'*unico* cammino ( visto che è un albero ) tra $s$ e $u$ in $G'$ è un cammino minimo tra $s$ e $u$ in $G$

>[!example] 
![[MinimumTreeWalks.excalidraw]]
#### Proprietà della Diseguaglianza triangolare

Sia $G=(V,E)$ un grafo con $s\in V$ , $(u,v)\in E$ allora :
$$\delta(s,v)\le \delta(s,u)+w(u,v)$$
**Dimostrazione** : 

Abbiamo 3 casi : 
1. $\delta(s,u) = +\infty$ : non esiste un cammino tra $s$ e $u$ 
	+ Avremo che $\delta(s,v) \le +\infty + w(u,v)$ e siccome $w(u,v)\in \mathbb{R}$ allora la condizione è banalmente vera
2. $\delta(s,u) = - \infty$ : tra $s$ e $u$ esiste un ciclo negativo 
	+ Avremo che $\delta(s,v)\le -\infty + w(u,v)$ ma quindi anche $\delta(s,v)=-\infty$ per via del ciclo negativo , dunque la condizione è verificata 
3. $\delta(s,u) \in \mathbb{R}$ : esiste un cammino senza cicli tra $s$ e $u$ 
	+ Sia $p$ il cammino tra $s$ e $u$ allora se l'*unico* cammino tra $s$ e $v$ è costituito dal cammino $p$ e dall'arco tra $(u,v)$  il suo peso risulterà essere pari alla somma peso di $p$ e $w(u,v)$ , ( $\delta(s,v) = \delta(p)+w(u,v)$ ) e visto che potrebbero esserci cammini meno costosi tra $s$ e $v$ questo risulterà essere un limite inferiore 
>[!todo] 
>capire la dimostrazione
#### Proprietà del limite inferiore

In qualsiasi algoritmo che : 
+ Inizializza i dati con `Init_ss`
+ Usa solo la `Relax` per modificare i valori di $d$ e $\pi$

Avremo che $\delta(s,v)\le d[v]$ , ossia la vera distanza tra $s$ e $v$ sarà sempre un limite inferiore per la stima della distanza 
Quando $\delta(s,v)=d[v]$ nessuna `Relax` potrà mai cambiare il valore di $d[v]$ 

**Dimostrazione** :

Distinguiamo 2 momenti nell'algoritmo : 
1. Subito dopo la `Init_SS`
	1. Se $v\neq s$ varrà che $d[v]=+\infty \ge \delta(s,v)$ , questo verifica banalmente la proprietà del limite inferiore
	2. Se $v=s$ sappiamo che $\delta(s,s) = 0$ se non esistono cicli negativi che passano per la sorgente altrimenti $\delta(s,s)=-\infty$ , in entrambi i casi $\delta(s,s)\le 0 = d[s]$
	Abbiamo quindi dimostrato che subito dopo l'inzializzazione la proprietà è vera
2. Supponiamo per assurdo che $v$ sia il primo vertice per cui la proprietà è violata
	Al termine di questa `Relax` verrà che : 
	$d[u]+w(u,v)=d[v]$ ma per ipotesi avremo che $d[u]+w(u,v)< \delta(s,v)$ 
	applico quindi la diseguaglianza triangolare ottenendo $d[u]+w(u,v) \le \delta(s,u)+w(u,v)$ che risulterà essere $d[u]< \delta(s,u)$ ma questo è *assurdo* perchè allora $v$ non sarebbe il primo vertice ad infrangere la proprietà ma sarebbe $u$

#### Proprietà della convergenza

In un *cammino minimo* $p=<s,\dots,u,v>$ per una qualche coppia di veritici $u,v\in V$ ad un certo punto , dopo una certa `Relax` avremo che $d[u]=\delta(s,u)$ ( abbiamo trovato il cammino minimo ) allora chiamare `Relax(u,v,w(u,v))` farà sì che $d[v]=\delta(s,v)$ 

**Dimostrazione** :

Per la proprietà del limite inferiore : 
$$\delta(s,v)\le d[v]$$
Per la proprietà della `Relax` : 
$$\delta(s,v)\le d[u]+w(u,v)$$
Per ipotesi ( $d[u]=\delta(s,u)$ ) avremo che : 
$$\delta(s,v)\le \delta(s,u)+w(u,v)$$
Poichè siamo su un *cammino minimo* : 
$$\delta(s,v)=\delta(s,v)$$
#### Dijkstra

*Intuizione* : estrae una radice alla volta e rilasserà gli archi uscenti da quel vertice
```pseudo
	\begin{algorithm}
	\caption{DIJKSTRA(G,w,s)}
	\begin{algorithmic}
	\State $INIT\_SS(G)$
	\State $Q \leftarrow V[G]$
	\State $S \leftarrow \emptyset$
	\While{$Q \neq \emptyset$}
		\State $u \leftarrow EXTRACT\_MIN(Q)$
		\State $S \leftarrow S \cup \{u\}$
		\ForAll{$v \in Adj[u]$}
			\State $RELAX(u,v,w(u,v))$
        \EndFor
    \EndWhile
    \Return
	\end{algorithmic}
	\end{algorithm}
```
**Spiegazione** :

>[!todo] 

**Terminazione** : 
	L'algoritmo sicuramente termina poichè il ciclo `while` estrae sempre un vertice , arriveremo sempre quindi all'insieme vuoto e il ciclo `for` è limitato dal numero di vertici adiacenti ( al massimo tutti gli altri verici del grafo )

**Complessità** :
	1. Righe `2-4` : La procedura `Init_SS` ha tempo di esecuzione $\Theta(n)$ poichè scorrerà per forza l'intero grafo 
	2. Righe `5-7` : il ciclo `while` compie $n$ iterazioni , ora la complessità delle rimanenti operazioni dipende da come abbiamo implementato la $Q$
		1. Se è stata implementata con un *heap binario* : 
			La `Extract_min` avrà complessità $\log n$ poichè dovremo ribilanciare l'*heap* ad ogni estrazione , poichè è svolto per $n$ volte avremo che la complessità totale di `Extract_min` sarà $O(n\log n)$
		3. Se è stata implementata con un *array lineare* :
			La `Extract_min` non necessità di ribilanciamento ma saremo costretti a cercare l'intero array per trovare il minimo , la complessità sarà quindi $O(n)$ 
	3. Righe `8-9` : il ciclo `for` viene svolto tante volte quanto l'*out-degree* del nodo appena estratto $u$ , notiamo che visto che viene svolto per $n$ volte all'interno del ciclo `while` possiamo trovare il numero di iterazioni totali risolvendo : $$\sum_{i=1}^n \text{out-deg}(i)=m$$
	  All'interno del ciclo `for` svolgiamo la `Relax` , la sua complessità dipende dal'implementazione di $Q$ , avremo quindi 2 casi :
		1. *heap binario* : 
			Ha complessità $\log n$ poichè può cambiare la key di $Q$ e deve quindi essere ribilanciato
		2. *array lineare* : 
			In questo caso avremo complessità *costante*

La complessità totale sarà quindi dipendente dalle 2 implementazioni di $Q$ : 
+ **Heap binario** : 
	$$T(n,m)=n + n\log n +m \log n=O(m\log n)$$
+ **Array lineare** :
	$$T(n,m)=n+n^2+c\cdot m = O(n^2)$$

L'implementazione scielta dipende da come è fatto il grafo , avremo 2 casi : 
+ grafo *sparso* : in questo caso avremo che $m \approx n$
+ grafo *denso* : in questo caso avremo che $m \approx n^2$

|      -       |   *heap*    | **array** |
| :----------: | :---------: | :-------: |
| ***sparso*** |  $n\log n$  |   $n^2$   |
| ***denso***  | $n^2\log n$ |   $n^2$   |
Avremo quindi che in caso di grafo *sparso* preferiremo l'implementazione con l'*heap binario* , mentre nel caso di grafo *denso* preferiremo l'implementazione con l'*array lineare*

**Correttezza** : 

>[!warning] 
>L'algoritmo di *Diijkstra* non è sempre corretto , restituirà risultati corretti solamente se tutti i pesi sono $\ge 0$

Sia $G=(V,E)$ un grafo orientato con $w : E \to \mathbb{R}$ tale che $\forall (u,v) \in E : w(u,v)\ge 0$
Allora alla fine dell'algortimo di *Dijkstra* si ha : 
1. $\forall v \in V : d[v] = \delta(s,v)$ 
2. $G_{\pi}$ è un albero di cammini minimi

>[!note] 
>Non dimostreremo il secondo punto

Dimostriamo quindi la seguente effermazione : 
	$\forall u \in V$ all'atto dell'estrazione di $u$ dalla coda $Q$ risultetà che $d[u]=\delta(s,u)$ ( se questo è vero all'estrazione allora dovrà essere vero anche alla fine dell'algoritmo poichè sappiamo che quando $d[u]=\delta(s,u)$ questo non potrà più cambiare per come è scritta la `Relax`)

**Dimostrazione** per assurdo :

Supponiamo *per assurdo* che esista un vertice $u\in V$ tale che al momento della sua estrazione si avrà : $d[u]\neq \delta(s,u)$  e che $u$ sia il primo vertice per il quale accade 

**Osservazioni** : 

1. $u$ non può essere sorgente , avremo infatti che $d[u] = 0 = \delta(s,s)$ 
>[!note] 
>$\delta(s,s)$ non può valere $-\infty$ poichè abbiamo supposto di avere solo pesi $\ge 0$ all'interno del grafo $G$
2. Al momento dell'estrazione di $u$ , $S \neq \emptyset$ perchè in $S$ ( insieme dei vertici estratti ) ci sarà almeno la sorgente $s$
3. $u$ deve essere *raggiungibile* da $s$ ( altrimenti avremo che $\delta(s,u)=+\infty = d[u]$ )

Ci poniamo nell'istante in cui $s$ è già stato estratto ( $s\in S$ ) ma $u$ no ( $u \in Q$ dove $Q=V - S$ )
Visto che $u$ è *raggiungibile* dovrà esistere un *cammino minimo* $p$ tra $u$ e $s$ 
Inoltre visto che $u$ si trova in $Q$ avremo necessariamente un arco che attraversa il taglio tra gli insiemi $S$ e $Q$ 

Prendiamo quindi i vertici $x$ e $y$ che delimitano l'arco che attraversa questo taglio

Quindi possiamo dire che :
 4. $d[x]=\delta(s,x)$ : visto che :
	 1. ci troviamo in un cammino minimo e sottocammini di un cammino minimo sono anch'essi minimi 
	 2. sappiamo che entrambi fanno parte dei vertici già estratti che necessaramente hanno $d[x]=\delta(s,x)$ 
	 3. Inoltre sappiamo per ipotesi che $u$ è il primo vertice per cui non vale questa proprietà
 5. $d[y]=\delta(s,x)+w(x,y)=\delta(s,y)$ :
	 1. Questo per la *proprietà della convergenza* in quanto quando abbiamo estratto $x$ svolgiamo la relax su tutti i veritici adiacenti e faremo quindi anche $d[y]=d[x]+w(x,y)$ ( questo viene sempre svolto perchè so di essere su un cammino minimo e quindi sicuramente $d[x]>d[y]+w(x,y)$ ) e dal punto prima abbiamo che $d[y]=\delta(s,x)+w(x,y)$ abbiamo inoltre che questo sarà $\delta(s,y)$ poichè ci troviamo su un cammino minimo
 6. $d[u]\le d[y]$ :
	 1. Poichè stiamo per estrarre il nodo $u$ siccome l'algorimo estrae il vertice avente campo $d$ minore avremo che $d[u]\le d[y]$
 7. $\delta(s,y)\le \delta(s,u)$ : 
	 1. poichè i pesi devono essere $\ge 0$ se aggiungo un arco al cammino questo influisce sul peso finale del cammino solo in modo positivo
 8. $\delta(s,u)\le d[u]$ : 
	 1. Per la proprietà del limite inferiore 

Ricostruiamo l'*assurdo* sulla base delle precedenti osservazioni , ci basterà dimostrare che : 
$$\delta(s,u)\le d[u]\le \delta(s,u)$$
+ $\delta(s,u)\le d[u]$ per la proprietà del limite inferiore 
+ $d[u]\le\delta(s,u)$ : possiamo ricondurci a questo grazie alla precedenti osservazioni : 
$$d[u]\le d[y] \quad \text{per 6}$$
$$d[u]\le \delta(s,y) \quad \text{per 5}$$
$$d[u]\le \delta(s,u)\quad \text{per 7}$$
Possiamo quindi dire che deve essere $d[u]=\delta(s,u)$ e questo è un *assurdo*

>[!note] 
>Possiamo interrompere l'algoritmo prima dell'estrazione dell'ultimo vertice oichè nel momento in cui viene estratto tutti gli altri apparterranno a $S$ e non verrà eseguita nessuna `Relax` 
##### Dijkstra con pesi negativi 

Come abbiamo detto *Dijkstra* non è corretto se vi sono dei pesi negativi all'interno 

Possiamo però circumnavigare questo problema *shiftando* tutti i pesi sommando in modo che abbiamo tutti pesi positivi mantenendo inalterato il risutlato dell'algoritmo di *Dijkstra* 

>[!example] 
>Proviamo con il seguente grafo : 
![[ShiftedDijkstra.excalidraw]]
>
>Come si può notare lo *shift* ha causato il cambiamento del cammino minimo , non possiamo quindi *shiftare* i pesi per risolvere il problema dei pesi negativi
#### Bellman-Ford

>[!note]
>Questo algoritmo svolge per $n-1$ volte la `Relax` su tutti gli archi del grafo 

```pseudo
	\begin{algorithm}
	\caption{Bellman-Ford(G,w,s)}
	\begin{algorithmic}
	\State $Init\_ss(G)$
	\For{$i=1\ \text{to} \ |V[G]|-1$}
		\ForAll{$(u,v)\in E[G]$}
			\State $\text{Relax}(u,v,w(u,v))$
        \EndFor
    \EndFor
    \ForAll{$(u,v)\in E[G]$}
	    \If{$d[v]>d[u]+w(u,v)$}
		    \Return False
        \EndIf
    \EndFor
    \Return True
	\end{algorithmic}
	\end{algorithm}
```

**Spiegazione e Complessità** : 

+ Si inzializza con `init_ss`
+ Il ciclo `for` esterno verrà svolto per $n-1$ volte ( dove $n$ indica $|V|$ ) 
+ Il ciclo `for` interno verrà svolto per $m$ volte ( il numero di achi presenti nel grafo )
+ La `Relax` ha costo costante poichè non stiamo utilizzando alcuna coda per $Q$
+ Il secondo ciclo `for` esterno ( ha il compito di ritornare false se vi sono cicli negativi all'interno del grafo , se vi sono cicli negativi infatti non possiamo più fidarci della risposta dell'algoritmo in quanto i cammini minimi potrebbero ciclare all'infinito nei cicli negativi ) viene eseguito $m$ volte ( il numero degli archi )

Avremo quindi che la complessità finale sarà : 
$$T(n,m)=n+(n-1)\cdot m + m = \Theta(n\cdot m)$$
**Correttezza** : 

Avremo 2 casi da considerare : 
1. Se $G$ non contiene cicli negativi raggiungibili da $s$ allora alla fine dell'algortimo avremo : 
	1. $d[u]=\delta(s,u)\quad \forall u \in V$
	2. $G_{\pi}$ è un albero di cammini minimi
	3. L'algoritmo restituisce `True`
2. Se $G$ contiene cicli negativi raggiungibili da $s$ allora l'agoritmo restituisce `False`

**Dimostrazione** 1.1

Sappiamo che $\nexists$ cicli negativi raggiungibili da $s$ , avremo quindi che :
$$\forall u \in V, \ne s , \quad \delta(s,u)=\begin{cases}
+\infty  & \text{ovvio dopo $Init\_ss$}\\ \mathbb{R}
\end{cases}$$
Se $\delta(s,u) \in \mathbb{R}$ allora esisterà un cammino $p=<x_0 = s , x_1 , \dots , x_q = u>$ minimo *semplice* ( ossia un cammino dove non vi sono vertici ripetuti ) tra $s$ e $u$ 

>[!note] 
>Esiste sempre un cammino minimo *semplice* poichè visto che non esitono cicli negativi questi possono essere solo $\ge 0$ e per questo possono sempre essere eliminati dal cammino minimo

$p$ può avere al massimo $n-1$ archi in totale ( visto che è *semplice* ) nel caso in cui attraversa tutti i veritici del grafo

Poichè sottocammini di un cammino minimo sono anch'essi minimi possiamo applicare il teorema della convergenza tante volte quante sono le passate dell'algoritmo e verificare che alla fine dell'algoritmo avremo $d[u]=\delta(s,u)$

![[DimoBellmanFord.excalidraw]]

**Dimostrazione** 1.3

Perchè l'algoritmo ritorni `True` alla fine della dovremmo avere che : 
$$\forall (u,v)\in E, \quad d[v]\le d[u]+w(u,v)$$ Questo in modo che fallisca sempre l'`if` ed infine ritorni `True`

Utilizziamo la *disuguaglianza triangolare* :
$$\delta(s,v)\le \delta(s,u)+w(u,v)$$
Ma avendo dimostrato nella dimostrazione precedente che $d[u]=\delta(s,u)$ e $d[v]=\delta(s,v)$ possiamo concludere che : 
$$d[v]\le d[u]+w(u,v)$$

**Dimostrazione** 2

Dimostriamolo per *assurdo* : 

Supponiamo che abbiamo un grafo $G$ contenente almeno un ciclo negativo raggiungibile da $s$ e che , *per assurdo* , l'algoritmo restituice `True`

Osservando l'algoritmo sappiamo che questo restituisce `True` quando $$\forall (u,v)\in E, \quad d[v]\le d[u]+w(u,v)$$
Sia $c=<x_0,x_1,\dots,x_q>, \quad x_0=x_q$  il ciclo negativo raggiungibile da $s$ allora dovrà essere che :
$$\sum_{i=1}^q w(x_{i-1},x_i)<0$$
Visto che l'algoritmo avrà restituito `True` avremo che dovrà essere ( poichè se la proprietà sopra deve valere per tutti gli archi allora dovrà anche valere per un sottoinsieme di archi ) :
$$\sum^{q}_{i=1}d[x_i] \le \sum^{q}_{i=1}d[x_{i-1}]+\sum^{q}_{i=1}w(x_{i-1},x_i)$$
Visto che ci troviamo su un ciclo e $x_0=x_q$ avremo che le due sommatorie possono essere semplificate nel seguente modo : 
$$d[x_1]+d[x_2]+\dots+d[x_q]\le d[x_0]+d[x_1]+\dots+d[x_{q-1}]+\sum^{q}_{i=1}w(x_{i-1},x_i)$$
Possiamo eliminare quindi tutti i pesi uguali e rimarremo con $d[q]\le d[x_0]$ ma sapendo che $d[q]=d[x_0]$ possiamo riscrivere l'equazione precedente nel seguente modo : 
$$\sum^{q}_{i=1}w(x_{i-1},x_i)\ge 0$$
che va contro l'ipotesi iniziale e abbiamo quindi raggiunto l'*assurdo*

**Osservazioni**

Quando è meglio utilizzare *Bellman-Ford* rispetto a *Dijkstra* ? :

|                           |   *Dijkstra*    | *Bellman-Ford* |
| :------------------------ | :-------------: | :------------: |
| ***Sparso*** $m\approx n$ | $n\cdot \log n$ |     $n^2$      |
| ***Denso***               |      $n^2$      |     $n^3$      |
Notiamo che generalmente *Dijkstra* ha una migliore complessità rispetto a *Bellman-Ford* , dobbiamo però ricordarci che *Dijkstra* è valido solo se i pesi sono $>0$ mentre *Bellman-Ford* è un algoritmo più generale

>[!example] 
>>[!todo] 
#### Cammini minimi tra tutte le coppie di vertici

>[!note] 
In questo caso ci limitiamo al calcolo delle distanze 

Una prima soluzione sarebbe quella di lanciare l'algoritmo di *Dijkstra* ( se so che i pesi sono $>0$ ) o *Bellman-Ford* su tutti i vertici 
```pseudo
	\begin{algorithm}
	\caption{Iterated\_Bellman-Ford(G,w)}
	\begin{algorithmic}
	\ForAll{$v\in V[G]$}
		\State $\text{Bellman-Ford}(G,w,v)$
    \EndFor
	\end{algorithmic}
	\end{algorithm}
```
La **complessità** sarebbe : 

|                           |   *Iterated_BF*    |       *Iterated_Djikstra*        |
| :-----------------------: | :----------------: | :------------------------------: |
| ***Sparso*** $m\approx n$ | $n\cdot n^2 =n^3$  | $n\cdot n\cdot \log n=n^2\log n$ |
|        ***Denso***        | $n\cdot n^3 = n^4$ |         $n\cdot n^2=n^3$         |

Possiamo fare di meglio ? 
Si grazie alla *programmazione dinamica* 
##### Floyd-Warshall

L'algortimo di *Floyd-Warshall* ha complessità $\Theta(n^3)$ che risulta essere meglio di tutte le complessità ottenute nel precedente esempio ( solo nel caso in cui abbiamo tutti i pesi $>0$ e grafo sparso allora *Iterated_Djikstra* fa meglio )

Supponiamo di avere un $G=(V,E)$ orientato con $w:E\to \mathbb{R}$
Inoltre supponiamo di numerare tutti i vertici con numeri naturali compresi tra $1$ e $n$

L'algortimo prende in input una matrice $W$ che contiene in $w(i,j)$ il peso dell'arco tra $i$ e $j$
e $w_{ij}$ per indicare l'elemento della matrice alla righa $i$ e colonna $j$ , $w_{ij}$ potrà quindi prendere i seguenti valori : 
$$w_{ij}=\begin{cases}
0 & \text{se} \ i =j \\ w(i,j) & \text{se}\ i\ne j \land (i,j)\in E \\ \infty & \text{se}\ i\ne j \land (i,j)\notin E
\end{cases}$$
L'algortimo restituirà un'ulteriore matrice detta *matrice delle distanze* $D$ per cui alla fine dell'algoritmo avermo che $d_{ij}=\delta(i,j)$ ( ossia la distanza vera tra $i$ e $j$ ) 

```pseudo
	\begin{algorithm}
	\caption{Floyd\_Warshall(W)}
	\begin{algorithmic}
	\State $n \leftarrow rows(W)$
	\State $D^{0} \leftarrow W$
	\For{$k=1\ \text{to}\ n$}
		\For{$i=1\ \text{to}\ n$}
			\For{$j=1\ \text{to}\ n$}
			\State $d_{ij}^k = \min \{ d_{ij}^{k-1} , d_{ik}^{k-1} + d_{kj}^{k-1} \}$
			\EndFor
		\EndFor
    \EndFor
    \Return $D^k$
	\end{algorithmic}
	\end{algorithm}
```
**Spiegazione** :

Ciò che fa l'algortimo è il seguente : 
Prende dalla matrice $k-1$ i valori di $d_{ij}$ che viene confrontato con la somma dei valori trovati sulla stessa matrice a $d_{ik}$ e $d_{kj}$ , il minimo tra questi due valori verrà scritto nella nuova matrice $k$

>[!todo] 
>Sopiegazione un pò di merda

**Complessità** : 

Visti i tre cicli `for` e la complessità costante dell'operazione all'interno avremo che : la *complessità* sarà : $n^3\cdot 1 = \Theta(n^3)$

**Correttezza** : 

Avendo $k$ l'etichetta posta sui vertici allora diremo che : $\mathcal{D}_{i,j}$ è un insieme di cammini tali per cui : 
$$\mathcal{D}_{i,j} = \{p|p\ \text{è un cammino semplice tra $i$ e $j$}\}$$
e 
$$\mathcal{D}_{i,j}^{(k)} = \{p|p\ \text{è un cammino semplice tra $i$ e $j$, con vertici intermedi di etichetta}\le k\}$$
Dove *vertice intermedio* : è un qualsiasi vertice del cammino $p<x_0,x_1,\dots,x_n>$ tale che sia diverso da $x_0$ o $x_n$ 

>[!example] 
>In questo cammino $p=<1,2,5,7,9>$ i *vertici intermedi* sono $<2,5,7>$

>[!example] 
![[Floyd-Warshall.excalidraw]]
>
>Se abbiamo $\mathcal{D}_{2,7}$ allora avremo differenti insiemi per differenti valori di $k$ :
>+ $\mathcal{D}_{2,7}^{(1)}=\mathcal{D}_{2,7}^{(2)}=\mathcal{D}_{2,7}^{(3)}=\emptyset$
>+ $\mathcal{D}_{2,7}^{(4)}=\{<2,1,4,3,7>\}$
>+ $\mathcal{D}_{2,7}^{(5)}=\{<2,5,3,7>\}$
>
>Da questo possiamo notare che $\mathcal{D}_{i,j}^{(k)}\subseteq \mathcal{D}_{i,j}^{(k+1)}$  ed in particolare quando $k=n$ $\mathcal{D}_{i,j}^{(k)}$ e $\mathcal{D}_{i,j}$ coincidono ( ossia $\mathcal{D}_{i,j}$ è un cammino semplice tra $i$ e $j$ )
>
>

Definiamo ora $d_{i,j}^{(k)}$ come il peso del cammino minimo tra $i$ e $j$ dove i valori dei vertici intermedi hanno valore minore o uguale a $k$ ossia : 
$$d_{i,j}^{(k)} = \min_{p \in \mathcal{D}_{i,j}^{(k)}} w(p)$$
In pratica tra tutti i cammini minimi presenti in $\mathcal{D}_{i,j}$ , $d_{i,j}^{(k)}$ sarà il peso minimo tra tutti i cammini minimi 

Notiamo che se $k=n$ avremo che il peso minimo sarà preso da tutti i cammini minimi tra $i$ e $j$ , avremo quindi che : $$\delta(i,j)=d_{ij}^{(n)}$$ossia l'elemento $i,j$-esimo della matrice risultanto dell'algoritmo di *Floyd-Warshall*

Ora per dimostrare che l'algoritmo è corretto ci basterà dimostrare la veridicità di : 
$$d_{ij}^{(k)} = \min\{ d_{ij}^{k-1} , d_{ik}^{k-1}+d_{kj}^{k-1}\}$$
Possiamo dividere un cammino tra $i$ e $j$ in due sottocammini quelli che passano per $k$  e quelli che non passano per $k$ , poichè stiamo assumendo che i cammini siano semplici abbiamo la sicurezza che $k$ non è compreso in nessuno dei due insiemi di sottocammini $\mathcal{D}_{i,k}^{(k-1)}$ e $\mathcal{D}_{k,j}^{(k-1)}$ e che tutti i vertici compresi in tali sottocammini abbiano valore minore o uguale a $k-1$ 

![[Pasted image 20240426174605.png]]

Definiamo quindi il seguente insieme : 
$$\hat{\mathcal{D}}^{(k)}_{i,j}=\big\{ p | p \in \mathcal{D}_{i,j}^{(k)} \quad \text{passanti per k} \ \big\}$$
Quindi potremmo costruire il seguente insieme : 
$$\mathcal{D}^{(k)}_{i,j} = \hat{\mathcal{D}}^{(k)}_{i,j} \cup \mathcal{D}_{i,j}^{(k-1)}$$
Possiamo quindi riscrivere la definizione di distanza nel seguente modo : 
$$d_{ij}^{(k)}=\min_{p\in \mathcal{D}_{i,j}^{(k)}} w(p)$$
$$=\min\bigg\{ \min_{p\in \hat{\mathcal{D}}_{i,j}^{(k)}} w(p) , \min_{p\in \mathcal{D}_{i,j}^{(k-1)}} w(p) \bigg\}$$
$$=\min\bigg\{ \min_{p\in \mathcal{D}_{i,k}^{(k-1)}} w(p) + \min_{p\in \mathcal{D}_{k,j}^{(k-1)}} w(p)\ ,\ d_{ij}^{(k-1)} \bigg\}$$
$$=\min\bigg\{  d_{ik}^{(k-1)}+d_{kj}^{(k-1)}\ ,\ d_{ij}^{(k-1)} \bigg\}$$
$d_{ij}^{(k)}$ rappresenta dunque il peso del cammino minimo tra $i$ e $j$ i cui vertici intermedi sono di valore minore o uguale a $k$ 
## Algoritmi Greedy

Un *algoritmo greedy* o goloso è : 
	Un alogritmo *iterativo* in cui ad ogni passo dell'iterazione si compie una *decisione* che sembra essere in quel momento la più promettente per determinare il proseguimento dell'algortimo

>[!example] 
>Esempio di algoritmi *greedy* sono : *Kruskal* , *Prim* e *Dijkstra*
>+ Per *Kruskal* ad ogni passo devo sciegliere un arco da aggiungere all'insieme risultante , in questo caso sciegliamo l'arco di peso minimo 
>+ Per *Prim* invece ad ogni iterazione sciegliamo il vertice con `Key` minore 
>+ Per *Dijkstra* ad ogni iterazione sciegliamo quello con campo `d` minore

>[!note] 
>Non sono algoritmi *greedy* invece *Bellman-Ford* e *Floyd-Warshall* in quanto non si deve svolgere una decisione 

### Problema della selezione delle attività

Supponiamo di avere $n$ attività indicizzate con un numero da $1$ a $n$ di cui conosciamo l'orario di inizio $s_i$ e di fine $f_i$ 
Due attività $i$ e $j$ sono dette *compatibili* se gli insiemi temporali che occupano sono disgiunti ossia :
$$[s_i,f_i[\ \cap\ [s_j,f_j[ = \emptyset \implies \text{i e j sono compatibili}$$
Vogiamo determinare il massimo numero di attività che sono tra loro *compatibili*

>[!example] 
>>[!warning] 
>>Il diagramma è scorretto ? 
>
>Rappresentiamo un esempio con un diagramma di Gantt : 
>![[Pasted image 20240429132847.png]]
>Il numero massimo di attività compatibili in questo esempio sono $3$ ( ${(1,4,6),(1,5,6)}$ )

Possiamo scrivere un algoritmo *greedy* per trovare la soluzione a questo problema ?

Partiamo da $A=\emptyset$ , questo rappresenta le attività compatibili 
Ora sciegliamo un'attività , *faccio una verifica* e la inserisco in $A$
Scielgo un'altra attività  , *verifico se è compatibile* , se sì la aggiungo ad $A$ altrimenti la scarto

Ora ci basta sciegliere un modo con il quale confrontiamo le diverse attività , scegliamo il tempo di fine di ogni attività , ordiniamo le attività quindi in modo crescente secondo questo parametro in modo da ottenere : 
$$f_1 \le f_2 \le f_3 \le \dots \le f_n$$
Per sciegliere che attività aggiungere ad $A$ sciegliamo quella per cui il suo inizio è maggiore o uguale al tempo di fine dell'ultima attività inserita in $A$ 

Vediamo qundi l'algoritmo : 
```pseudo
	\begin{algorithm}
	\caption{$Greedy\_Activity\_Selector(s,f)$}
	\begin{algorithmic}
	\State $n \leftarrow length(s)$
	\State $\text{ordina le n attività per tempo di fine in senso crescente}$
	\State $A \leftarrow \{1\}$
	\State $j \leftarrow 1$
	\For{$i=2\ \text{to} \ n$}
		\If{$s_i \ge f_j$}
			\State $A \leftarrow A \cup \{i\}$
			\State $j \leftarrow i$
        \EndIf
    \EndFor
    \Return $A$
	\end{algorithmic}
	\end{algorithm}
```
Dove :
+ $s$ e $f$ sono vettori conenenti i valori di $s_i$ e $f_i$
+ $j$ indica l'ultima attività inserita in $A$
+ Il ciclo `for` inizia da due perchè abbiamo già inserito il primo elemento in $A$

**Complessità** : 

L'ordinamento avrà complessità equivalente a $n\log n$ 
Il ciclo `for` viene svolto per $n$ volte e visto che le operazioni al suo interno hanno complessità costante potremmo dire che la complessità del ciclo `for` è $O(1)$

La complessità totale sarà quindi : $T(n)=O(n\log n+ n) = O(n)$

**Correttezza** :

Non dimostriamo la correttezza dell'algoritmo ma sappiamo che risulterà essere corretto 

#### Scielte greedy alternative 

Potremmo aver fatto diverse scielte su come abbiamo ordinato le attività : 
1. *Ordinamento per tempo di inizio minore* :
	In questo caso l'algoritmo *non* sarebbe *corretto* poichè se fosse presente una attività che inizia subito ed è anche la più lunga di tutte allora verrebbe scielta solo questa e nessun'altra
>[!example] 
>![[Pasted image 20240429140121.png]]
>In questo caso viene scielta subito l'attività $1$ e non potremmo scieglerne nessun'altra poichè saranno incompatibili
2. *Ordinamento per durata minore* :
	Anche in questo caso l'algoritmo *non* sarebbe stato *corretto* poichè potremmo aver avuto tante attività di durata maggiore e altre di durata minore che però fanno in modo di non essere compatibili con quelle di durata maggiore , in questo caso verrebbero scielte solamente le minori attività di durata minore e non le altre che potrebbero aver formato un insieme di dimensioni maggiori 
>[!example] 
>![[Pasted image 20240429140443.png]]
>In questo caso avremmo preso le attività $3,5,7$ mentre le attività $1,2,4,6$ sarebbero state maggiori
### Schema generale Algoritmo Greedy

Lo schema generale per un *algoritmo greedy* è il seguente :

```pseudo
	\begin{algorithm}
	\caption{Greedy}
	\begin{algorithmic}
	\State Ordinamento ( secondo un qualche criterio a nostra discrezione )
	\State $A \leftarrow \emptyset$	inizializzazione di strutture dati usiliarie
	\ForAll{$element\ x$ preso secondo l'ordine}
		\If{$A \cup \{x\}$ è ok (test/controllo della condizione cercata)}
	        \State $A \leftarrow A \cup \{x\}$ aggiunta dell'elemento che soddisfa la condizione
        \EndIf
    \EndFor
    \Return $A$
	\end{algorithmic}
	\end{algorithm}
```
>[!example] 
>In *Kruskal* : 
>+ si ordina secondo il peso in modo crescente 
>+ ok : se non si crea un ciclo in $A$ con l'aggiunta dell'elemento
>
>In *Activity selector* : 
>+ si ordina secondo il tempo finale in modo crescente
>+ ok : se l'attività $x$ è compatibile con tutte l'ultima attività in $A$ ( di conseguenza a tutte le altre )
### Problema della $Clique$ Massima

#### $Clique$ Massima

Un *clique* è un sottografo completo del grafo $G$ 
Una *clique massima* è una *clique* con il massimo numero di *vertivi*
Una *clique massimale* è una *clique* che non è contenuta in una *clique* più grande 
>[!warning] 
>Non è detto che sia anche *massima*
>>[!example] 
>>![[Clique.excalidraw]]

#### Trovare la $clique$ massima

Proviamo ad implementare quindi un algoritmo *greedy* che trovi la $clique$ massima dato un grafo $G$ in input

+ Oridiniamo secondo il grado dei vertici in modo decrescente ( teoricamente dovremo avere più nodi collegati possibile )
+ ok : quando il vertice scielto è collegato a tutti quelli presenti in $A$

```pseudo
	\begin{algorithm}
	\caption{Greedy\_Clique(G)}
	\begin{algorithmic}
	\State Ordina i vertici di $G$ per grado decrescente
	\State $A \leftarrow \emptyset$
	\ForAll{$u \in V[G]$ estratti secondo l'ordinamento}
		\If{Is\_A\_Clique(C,u)}
			\State $A \leftarrow A \cup \{u\}$
        \EndIf 
    \EndFor	
    \Return $A$
	\end{algorithmic}
	\end{algorithm}
```
```pseudo
	\begin{algorithm}
	\caption{Is\_A\_Clique(C,u)}
	\begin{algorithmic}
	\ForAll{$v\in A$}
		\If{$(u,v)\notin E$ non ho l'arco tra il vertice scelto e un vertice di $A$}
			\Return $FALSE$
        \EndIf
    \EndFor
    \Return $TRUE$
	\end{algorithmic}
	\end{algorithm}
```
>[!note] 
>Non usiamo il grado dei vertici per determinare se siamo dentro una $clique$ poichè potrebbe essere che il vertice sia collegato ad altri vertici all'esterno della $clique$

**Complessità** : 

+ L'ordinamento come sempre ha complessità $n \log n$ 
+ Il ciclo `for` itera per $n$ volte su una funzione che nel peggiore dei casi avrà complessità $n$ , avremo quindi che la complessità del ciclo `for` sarà $n^2$

La complessità totale sarà quindi : $T(n)= O(n\log n + n^2) =O(n^2)$

**Correttezza** : 

Pultroppo l'algoritmo **non** è **corretto** , per dimostrarlo ci basta un contro esempio : 

![[MaxClique.excalidraw]]

Visto che l'algoritmo non è corretto potremmo pensare di modificare il modo in cui svolgiamo l'ordinamento ( non possiamo modificare il modo in cui sciegliamo chi mettere in $A$ perchè questo co definisce cos'è una *clique* )

**Ordinamenti Alternativi** : 

*Ordinamento secondo il numero di triangoli incidenti in modo crescente*
	Con questo ordinamento risulterà corretta l'individuazione della *clique* nel grafo precedente 
	![[MaxClique2.excalidraw]]
	Possiamo però comunque trovare un *controesempio* anche per questa soluzione : 
	![[MaxClique3.excalidraw]]

>[!warning] 
>Per questo problema non esiste un modo per ordinare i vertici in modo da raggiungere la soluzione corretta
## Teoria della $NP$ completezza

### Problemi 

Parliamo in modo generico di *problemi* 

Un *problema* può essere rappresentato in modo astratto da due insiemi : 
$$\mathcal{I} = \text{Questo rappresenta l'insieme delle istanze}$$
>[!example] 
>Queste *istanze* possono essere : nel problema dei cammini minimi tutti i possibili , infiniti , grafi orientati e pesati 

$$\mathcal{S} = \text{Questo rappresenta l'insieme delle soluzioni}$$
>[!example] 
>Le *soluzioni* possono essere : nel problema dei cammini minimi questo può essere l'insieme dei vertici e cammini che costituiscono un possibile cammino minimo 

Un **problema** quindi può essere scritto come una relazione binaria tra le sue possibili *istanze* e le sue possibili *soluzioni* : 
$$\mathcal{P} \subseteq \mathcal{I} \times \mathcal{S}$$
Un **Algoritmo** invece è una serie di istruzioni che prende come *input* un'istanza dell'insieme delle istanze e come *output* una particolare soluzione : 
![[Algorithm.excalidraw]]
#### Tipologie di Problemi 

![[Problems.excalidraw]]

I *Problemi* possono essere divisi in : 
+ *Problemi Decidibili* : 
	Sono problemi per cui *esiste* un algoritmo che dia una soluzione in tempo *finito*
+ *Problemi Indecidibili* : 
	Sono problemi per cui *non esiste* un algoritmo che dia una soluzione in tempo finito
>[!example]
>Un esempio di problema indecidibile è il problema dell'Alt di una macchina di Turing  
>In questo problema dobbiamo dire se un certo programma termina oppure no 
>
>L'unica soluzione per questo problema è inevitabilmente di simulare il programma dati dei certi dati e osservare se termina oppure no , se preò il programma entra in un ciclo infinito anche l'algoritmo simulante ci entra non dando mai una soluzione

I problemi *Decidibili* possono essere suddivisi in due categorie a seconda del loro tempo di esecuzione : 
+ *Problemi trattabili* : 
	Sono problemi per cui esistono algoritmi risolutivi con complessità al massimo polinomiale ossia risolvibili in tempo $O(n^k)$ dove $n$ è la dimensione dell'input e $k$ è una qualche costante 
>[!note] 
>Si è notato che non si hanno generalmente problemi con un $k>4$ , altrimenti con $k$ molto alti la complessità potrebbe essere simile ad un problema *intrattabile*
>Inoltre si è notato che generalmente se un algortimo ammette una soluzione polinomiale si possono fare delle ottimizzazioni per diminuirne la complessità
+ *Problemi intrattabili* :
	Sono problemi i cui algoritmi risolutivi hanno tempi d'esecuzione almeno esponenziali , ossia risolvibili in tempo $O(k^n)$ 

#### Tipi di Problemi 

Un'altra divisione dei *problemi* può essere fatta a seconda di cosa calcolano :

![[Problems2.excalidraw]]

+ *Problemi decisionali* : 
	Sono problemi per cui la risposta dell'algortimo è *binaria* ( $\mathcal{S}=\{0,1\}$ )
>[!example] 
>Il grafo è connesso ? $S = \{ Si, No\}$
+ *Problemi di Ottimizzazione* : 
	Sono problemi per cui la soluzione è costituita da un insieme più o meno vasto da dove vogiamo ricavare l'elemento massimo o minimo 
>[!example] 
>Trova il cammino minimo in un grafo non orientato

>[!important] 
>Possiamo dimostrare che per ogni problema di ottimizzazione esiste una versione decisionale

>[!example] MAX CLIQUE  -> CLIQUE 
>Il problema della *MAX CLIQUE* è un problema di *ottimizzazione* ( ossia trovare la clique massima all'interno di un grafo orientato ) mentre il problema della *CLIQUE* è un problema *decisionale* dove come input avremo $\mathcal{J}$ grafi non orientati e $k$ , l'algoritmo risponderà alla seguente domanda : $\exists$ nel grafo una *clique* di $k$ vertici ?

>[!example] GRAFO HAMILTONIANO
>
>Un grafo non orientato è detto hamiltoniano se ha un ciclo hamiltoniano al suo interno , ossia se esite un cammino che tocchi tutti i vertici 
>
>Il problema del grafo *hamiltoniamo* ha le seguenti due verioni : 
>+ la decisionale che determina se un grafo è *hamiltoniano*
>+ la versione di ottimizzione invece resituisce il ciclo *hamiltoniamo* presente

>[!important] 
>Se abbiamo un problema di ottimizzazione e consideriamo la sua versione decisionale allora avranno la stessa complessità
### Classi di problemi decisionali

#### Classe $P$
La classe $P$ è definita nel seguente modo : 
$$P = \{\mathcal{P} | \mathcal{P}\ \text{è un problema decisionale risolvibile polinomialmente}\}$$
Dove $\mathcal{P}$ è un problema generale
#### Classe $NP$
La classe $NP$ è definita nel seguente modo :
$$NP = \{\mathcal{P} | \mathcal{P}\ \text{è un problema decisionale verificabile polinomialmente}\}$$
Cosa significa *verificabile* ? :
##### Verificabile
Possiamo partizionare l'insieme delle istanze $\mathcal{I}$ in due sottinsiemi : $\mathcal{L_+}$ ( che include le istanze positive , ossia quelle che ritornano 1 ) e $\mathcal{L_-}$ ( che include le istanze negative , ossia quelle che ritornano 0 ) 

Immaginiamo di avere un algoritmo $A_{VER}$ detto *algoritmo di verifica* che prende in input due elementi : un'*istanza positiva* $i \in \mathcal{L_+}$ di un problema e un *certificato* , ossia una presunta soluzione del problema. 

Il compito dell'*algoritmo di verifica* è quello di verificare se l'*istanza positiva* sia effettivamente un'*istanza positiva* del problema attraverso il *certificato* , ritornando $Si$ in questo caso e $No$ altrimenti 

>[!example] CICLO HAMILTONIANO
>
>Supponiamo di avere come certificato una permutazione dei vertici del grafo ( questo poichè per essere hamiltoniano dobbiamo avere un cammino che passi per tutti i vertici ) 
>Dovremmo quindi avere un algoritmo che verifichi che questa permutazione di vertici costituisca di fatto un ciclo hamiltoniamo , questo può essere fatto semplicemente scorrendo la lista di vertici e verificando che essi siano connessi tra di loro da un arco
>
>Poichè questa verifica può essere eseguita in tempo polinomiale questo problema è $NP$

Un'altro modo per scrivere la definizione di $NP$ è : 
$$NP = \{\mathcal{P} | \mathcal{P}\ \text{è un problema decisionale per il quale posso scrivere un algoritmo di verifica in tempo polinomiale} \}$$

>[!example] CLIQUE
>Un possibile *algoritmo di verifica* per il problema della *CLIQUE* può essere : 
>Dato un certificato costituito da un insieme di vertici :
>1. Controlla che il numero di vertici sia $\ge k$
>2. Controlla se per ogni coppia di vertici ci sia un arco ( questo ha complessità $n^2$ )
>   
>Visto che l'algoritmo può essere scritto polinomialmente allora il problema della *CLIQUE* è $NP$

>[!note] 
>$P \subseteq NP$ : 
>Se un problema è risolvibile polinomialmente allora è verificabile polinomialmente
#### Classe $Co-NP$

La *classe* $Co-NP$ e ( classi di problemi il cui complemento è $NP$ )

Il *complemento* di un *problema decisionale* $\mathcal{P}$ è il problema $\mathcal{P}$ per cui le soluzioni sono invertite , ossia $\bar{\mathcal{P}}$ è vero quando $\mathcal{P}$ è falso ed è falso quando $\mathcal{P}$ è vero 

>[!example] 
>Per il problema del *grafo hamiltoniano* avremo che $\bar{\mathcal{P}}$ ritornarà *no* se $G$ è hamiltoniano e *yes* se non lo è 
>
>Vediamo ora se $\bar{\mathcal{P}}$ è $NP$ 
>
>Come certificato dovrei avere tutte le possibili permutazioni di vertici e verificare che nessuna di esse sia un ciclo poichè dobbiamo verificare che non è hamiltoniano ossia non ha un ciclo hamiltoniano , per verificare ciò dobbiamo per forza ritornare tutte le possibili permutazioni in modo da verificare che nessuna di esse sia un grafo hamiltoniano
>
>Questo ci porta a dover per forza controllare $n!$ combinazioni di vertici
#### Classe $NP-completi$ ( o NPC )

##### Riducibilità polinomiale

Questa proprietà è simile a quella che sfruttiamo per ricondurci ad un problema già risolto quando cerchiamo di risolvere un problema nuovo 

In questo caso parliamo di *riducibilità polinomiale* ossia :
	Dati due problemi decisionali $\mathcal{P}_1$ e $\mathcal{P_2}$ diciamo che $\mathcal{P_1}$ è riducibile polinomialmente al problema $\mathcal{P_2}$ ( $\mathcal{P_1} \le_P \mathcal{P_2}$ ) se esiste un algoritmo polinomiale che mappi le istanze del problema $\mathcal{P_1}$ in istanze *equivalenti* ( ossia da istanze positive a positive o da negative a negative ) del problema $\mathcal{P_2}$ 

Potremmo quindi dire che : 
+ Se $\mathcal{P_1} \le_P \mathcal{P_2}$ e $\mathcal{P_2} \in P$ allora anche $\mathcal{P_1}\in P$ 

>[!important] Dimostrazione
>
>Supponiamo che $\mathcal{P_1}\leq_p \mathcal{P}_2$ e che $\mathcal{P_2} \in P$
>Per definizione di $\leq_p$ : $\exists$ un algoritmo $f$ calcolabile in tempo polinomiale tale che mappi le istanze di $\mathcal{P_1}$ in istanze equivalenti di $\mathcal{P_2}$ 
>Poichè $\mathcal{P_2} \in P$ allora avremo un algoritmo polinomiale che risolve $P_2$ 
>Possiamo quindi risolvere $P_1$ nel seguente modo : 
>+ Data un istanza di $\mathcal{P_1}$ calcoliamo con $f$ un'istanza equivalente di $\mathcal{P_2}$ in tempo polinomiale
>+ Utilizziamo ora l'algoritmo polinomiale di $\mathcal{P_2}$ per risolvere l'istanza tradotta
>
>Abbiamo quindi visto che il problema può essere risolto in tempo polinomiale ( trasformazione + algoritmo di $\mathcal{P_2}$ ) 
>Possiamo concludere che $\mathcal{P_1}\in P$

Questa proprietà soddisfa le seguenti proprietà : 
+ **Riflessività** : 
	Dato un problema decisionale qualsiasi, possiamo dire che è riducibile a sé stesso in quanto l’algoritmo di riducibilità applica il mapping identità: ogni istanza del problema viene mappata a sé stessa
+ **Transitività** : 
	Dati $\mathcal{P_1} \le_P \mathcal{P_2}$  e  $\mathcal{P_2} \le_P \mathcal{P_3}$  avremo :  $\mathcal{P_1} \le_P \mathcal{P_3}$ , questo è vero poichè ci basterà concatenare i due algoritmi che passano da $\mathcal{P_1}$ a $\mathcal{P_2}$  e  da $\mathcal{P_2}$ a $\mathcal{P_3}$ 
##### $NP-completi$

La definizione di problema $NP-completo$ è : 
$$NP-completo = \{ \mathcal{P} | \mathcal{P} \ \text{è un problema decisionale tale che :}\ \mathcal{P} \in NP\quad ,\forall \mathcal{P}' \in NP :  \mathcal{P}' \le_P \mathcal{P}  \}$$
Ossia : 
1. Il problema $\mathcal{P}$ deve essere un problema $NP$
2. Tutti i problemi in $NP$ sono riducibili polinomialmente a $\mathcal{P}$

Le classi di problemi sono distribuite come nel seguente insieme :

![[ClassiNP.excalidraw]]

>[!note] 
>Se vale solo la seconda proprietà degli $NPC$ allora diremo che il problema è $NP-Hard$
##### Teorema fondamentale della $NP$ completezza

$$(\ P \cap NPC \ )\neq \emptyset \implies P =NP$$
>[!important] Definition
> Se esiste un problema che allo stesso tempo è $P$ e $NPC$ allora la classe $P$ coincide con la classe $NP$ 

>[!important] Dimostrazione
>Abbiamo la seguente *ipotesi* : 
>$P \cap NPC \neq \emptyset$ ossia : 
>$\exists Q \in (P \cap NPC)$ da cui ricaviamo che $Q \in P$ e $Q \in NPC$ 
>
>La *tesi* è : $P = NP$ , dovremmo quindi dimostrare : 
>1. $P \subseteq NP$ :
>	Questo è banalmente vero in quanto un problema risolvibile polinomialmente è anche verificabile polinomialmente
>2. $NP \subseteq P$ : 
>	Essendo che $Q \in NPC$ dovrà valere che tutti i problemi in $NP$ devono essere ricondicibili a $Q$  

>[!error] 
>rivedi dimostrazione

>[!note] 
>$\le_p$ *simmetrica* vale solo tra $NPC$
>>[!important] Dimostrazione
>>Supponiamo che $\mathcal{P}$ e $Q$ $\in NPC$
>>
>>Per definizione sappiamo che $NPC \subset NP \implies \forall \mathcal{P'} \in NP : \mathcal{P'}\leq_p \mathcal{P''}$ dove $\mathcal{P''}\in NPC$ 
>>
>>Quindi $\forall \mathcal{P'} \in NPC$ è riducibile a qualsiasi altro $\mathcal{P''}\in NPC$
>>Quindi $\exists$ $f$ e $g$ algoritmi calcolabili in tempo polinomiale tali per cui : 
>>+ $\mathcal{P} \leq_p Q : \exists\ f \ |\ i \in \mathcal{P} \iff f(i) \in Q$
>>+ $Q \leq_p \mathcal{P} : \exists\ g\ |\ i \in Q \iff g(i) \in \mathcal{P}$
>>
>>Quindi per qualsiasi coppia di problemi $\mathcal{P}$ e $Q$ in $NPC$ vale che $\mathcal{P} \leq_p Q$ e $Q \leq_p \mathcal{P}$
##### Teorema di Cook

*Cook* dimostra che il problema $CIRCUIT-SAT$ è un $NPC$ 
###### Circuit Satisfability ( $CIRCUIT-SAT$ )

Il problema della $CIRCUIT-SAT$ è stato il primo problema ad essere dimostrato $NPC$

Supponiamo di avere un circuito booleano con $n$ ingressi e una sola uscita , vogliamo determinare se esiste una configurazione degli input per cui l'uscita è 1

>[!example] 
![[Cricuit.excalidraw]]
>In questo esempio una possibile configurazione potrebbe essere $x_1 = 0, x_2 =1 , x_3 = 0$

Per dimostrare la $NPC$ *Cook* ha dovuto dimostrare la seconda parte della definizione di $NPC$ 
###### Altri problemi

Avendo dimostrato un problema $NPC$ risulta essere relativamente semplice dimostrare gli altri infatti la seconda proprietà può essere riscritta nel seguente modo per via della *transitività* della *riducibilità polinomiale* : 

$$\exists\ Q \in NPC, \quad Q \le_p \mathcal{P}$$
Infatti potremmo avere che :
$$\forall \mathcal{P}' \in NP, \quad \mathcal{P}' \le_p Q \le \mathcal{P}$$
In questo modo ci basterà ricondurci ad un problema per cui abbiamo già dimostrato la $NPC$ per dire che quel problema è $NPC$
###### SAT

Supponiamo di avere una *formula booleana* 
>[!example] 
>$$\Phi = \{ [[(x_1\lor x_2) \to x_3]\lor x_4 ] \land [x_2 \land \lnot x_1 \lor (x_1 \to x_5)]\}$$

Vogliamo determinare se esiste una configurazione di $x_1 , x_2,x_3,x_4$ tale che il risultato sia $1$ 

Una possibile configurazione per $\Phi$ è : $x_1 = 0, x_2 = 1, x_3 = 0, x_4 = 1, x_5 = 0$ 

Per verificare questo risultato dobbiamo controllare tutte le possibili configurazioni ( $2^n$ ) degli input ( *polinomialmente verificabile* , $NP$ ) è inoltre dimostrabile che $CIRCUIT-SAT$ è *polinomalmente riducibile* a $SAT$ e questo , per la proprietà della *transitività* dellariducibilità polinomiale , sarà $NPC$ 
###### Froma normale congiuntiva , 3-SAT , CLIQUE

Nel caso dell'algebra booleana è comodo lavorare con certi formati particolari dotati di una struttura precisa, una di queste è la *forma normale conginutiva* o *FNC* costituita nel seguente modo : 
$$\Phi = C_1 \land C_2 \land \dots \land C_k$$
Dove $C_k$ rappresenta una *clausola* , ognuna di queste è costituita da una disgiunzione di *letterali* : ossia $\lor$ di variabili o negazioni di variabili : 
$$C = l_1 \lor l_2 \lor \dots \lor l_q$$
>[!example] 
>Un esempio di *FNC* è : 
>$$\phi = (x_1 \lor \lnot x_2)\land(x_2 \lor x_3\lor \lnot x_4) \land (x_1 \lor x_4)\land (x_2 \lor x_4)$$
>

Per verificare la *soddisfacibilità* di $\Phi$ è necessario che tutte le *clausole* siano vere e che all'interno delle clausole almeno un letterale sia vero

Il formato $k-FNC$ è una specializzazione della forma normale congiuntiva in cui tutte le clausole hanno esattamente $k$ letterali 

Ci interessiamo del problema $SAT-3FNC$ ossia una variante del $SAT$ che si occupa di verificare la soddisfacibilità di formule nella forma $3FNC$ ( ossia che per ogni *clausola* abbiamo esattamente 3 letterali )

>[!important] 
>Si può verificare che $SAT-3FNC$ è $NPC$ dimostrando che appartiene a $NP$ e che $SAT$ è riducibile polinomialmente a $SAT-3FNC$ 
>

>[!note] 
>Vale che $k-FNC$ è riducibile a $3-FNC$ per $k \ge 3$ 
>Notiamo che quando $k=2$ il problema $SAT-2FNC$ appartiene alla classe $P$ 

Con i precedenti problemi possiamo dimostrare che il problema della $CLIQUE$ è $NPC$ 

Per dimostrarlo dobbiamo verificare 2 proprietà : 
+ $CLIQUE \in NP$ 
+ Possiamo dire che $SAT-3FNC \le_p CLIQUE$ 
	Questo ci dice che possiamo trasformare il problema $SAT-3FNC$ in un problema di $CLIQUE$ 
	
	Una istanza di $SAT-3FNC$ può essere : 
	$$\Phi = C_1 \land C_2 \land C_3$$$$C_1 = x_1 \lor \lnot x_2 \lor \lnot x_3$$$$C_1 = \lnot x_1 \lor x_2 \lor x_3$$$$C_1 = x_1 \lor x_2 \lor  x_3$$

Questa può essere trasformato in un'istanza di $CLIQUE$ nel seguente modo :  
Avremo un grafo di tanti sottoinsiemi di vertici quante sono le clausole di $\Phi$ e ciascun sottoinsieme ha $k$ vertici , gli archi possono essere costruiti nel seguente modo : 
+ non ci sarà mai un arco tra i letterali dello stesso gruppo , un'arco può solo collegare vertici di gruppi diversi 
+ non ci possono essere archi tra letterali che sono la negazione dell'altro

Nel nostro caso avremo un grafo simile : 

![[Pasted image 20240513125405.png]]

La congiunzione $\Phi$ risulta soddisfacibile se e solo se esiste una *clique* di grado 3 nel grafo risultante 

>[!example] 
>Possiamo sciegliere i seguenti vertici : $\lnot x_2$ nel sottoinsieme $C_1$ , $x_3$ nel sottoinsieme $C_2$ e $x_3$ nel sottoinsieme $C_3$ 
>Questi formano una *cllique* , inoltre se poniamo ad 1 i letterali non negati e a 0 quelli negati avremo che la *congiunzione* è verificata 

Il problema della $CLIQUE$ è quindi riconducibile al problema $SAT-3FNC$ , questo ci porta a dire che , per la riconducibilità polinomale , avremo che $CLIQUE$ sarà $NPC$ 
##### Se troviamo un problema $NPC$

Poichè non si possono scrivere algoritmi efficenti per quesi problemi bisogna ricorrere a delle alternative : 
+ algoritmi di *approssimazione* : algoritmi che ritornano risultati non perfetti 
+ *euristiche* : algoritmi che statisticamente parlando forniscono la risposta corretta
