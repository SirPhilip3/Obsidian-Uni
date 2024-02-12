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
+ `A.heap_size` il numero di elementi dell'*heap* che sono memorizzati nell'array , è possibile che $A.length\ge A.heap_size$

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
+ Il tempo d'esecuzione nel caso peggiore è quindi l'altezza dell'albero ( la traccia più lunga )

Per determinare il limite inferiore degli algoritmi basati sul confronto è il limite inferiore sulle altezze di tutti gli alberi