# Statistica

## Probabilità elementare

//! rivedi appunti

### Principio fondamentale del calcolo combinatorio

Se una scelta può essere fatta in $m_1$ modi dviersi e un'altra scelta può essere fatta in $m_2$ modi diversi allora esistono in totale :
$$m_1{\times}m_2$$ possibilità di scelta

Esempio : 
	10 cavalieri e 12 dame partecipano ad un ballo :
	 ci sono $10*12 = 120$ possibili coppie danzanti 

### Principio fondamentale generalizzato

Se ciascuna di $r$ scelte sucessive può essere fatta in $m_i$ modi allora esistono in totale :
$$\prod^{r}_{i=1} m_{i} = m_{1} \times...\times m_r$$
possibilità di scelta

Esempio : 
	Una commisione deve essere composta da un membro del partito A che conta 10 rappresentanti , da un membro del partito B che conta 15 rappresentanti , da un membro del partito C che conta 2 rappresentanti

   Ci sono in totale $10*15*2 = 300$ possibili commisioni

### Disposizioni

Considerieamo un insieme di $n$ elementi. Una *Disposizione* di $r$ di essi è una scelta ordinata di $r$ elementi tra quegli $n$ 

+ **Disposizione con ripetizione** : uno stesso elemento può essere scelto più di una volta 
	La *Disposizione con ripetizione* di $n$ elementi presi $r$ alla volta sono in numero di :
	$$\prod^{r}_{i=1} n = n^r$$
	
	Esempio :
	Le parole lunghe 2 lettere che si possono comporre con le lettere *I , L , A* sono $3^2=9$ : 
	$II , IL , IA , LI ,LL,LA,AI,AL,AA.$ 
+ **Disposizione semplice ( senza ripetizione )** : uno stesso elemento può essere scelto solo una volta
	Le *Disposizioni semplici* o *senza ripetizione* di $n$ elementi presi $r$ alla volta sono in numero di :
	$$n\times(n-1)...\times(n-r+1)$$

	Esempio :
	Le parole di 2 lettere diverse che si possono comporre con le lettere *I , L , A* sono $3\times2 = 6$ :
	$IL,IA,LI,LA,AI,AL.$

### Permutazioni

Le  disposizioni semplici di $n$ elementi presi $n$ alla volta si chiamano *permutazioni* :
	Tutti i modi in cui $n$ elementi possono esser ordinati in fila :
	$$n\times (n-1)...\times 2 \times 1=n!$$
Esempio :
Le permutazioni delle lettere *I , L , A* sono $3! = 6$ :
$ILA,IAL,LIA,LAI,AIL,ALI$

### Combianzioni

In generale, un sottoinsieme di numerosità $r$ scelto da un insieme con $n$ elementi si chiama **combianzione** di $n$ elemento presi $r$ alla volta ( *senza ordine* )
	Il numero di combinazioni di $n$ elementi $r$ alla volta è :
	$$\frac{n\times(n-1)...\times(n-r+1)}{r!} = \binom{n}{r}$$
	**Coefficiente binomiale** $n$ su $r$

Esempio :
	La professoressa interroga ogni lunedì 10 studenti da una classe di 25. Esistono per lei $\binom{25}{10} = 3268760$ possibilità di scelta

### Fenomeni aleatori

Un *fenomeno aleatorio* è un fenomeno *incerto* , ossia del quale non si può prevedere con certezza l'esito
Su questi fenomeni si applica il calcolo delle probabilità 

Esempio di fenomeni aleatori :
+ lancio del dado
+ lancio di una moneta

### Definizioni

#### Spazio campionario

Rappresenta l'insieme di tutti i *possibili* *risultati* di un fenomeno aleatorio ( rappresentato con $\Omega$ ) 

Esempi :
	Una mano di poker ha $\Omega = \binom{52}{5}$ possibili sottoinsiemi delle 52 carte
	Lancio di un dado : $\Omega =\{1,2,3,4,5,6\}$
#### Risultati

Un *risultato* è un elemento dello spazio campionario e si può indicare con $\omega \in \Omega$
#### Eventi

Un *evento* è un sottoinsieme $A \subset \Omega$

Esempio : 
	Ottenere un numero pari dal lancio di un dado è considerato un *evento* e può essere rappresentato come l'insieme $\{2,4,6\}$

Quando un *evento* è vero ( avviene ) si dice che è *realizzato* o *verificato*

Anche i singoli *risultati* possono essere visti come *eventi* ( detti *eventi elementari* )

$\Omega$ viene detto *evento certo* poichè sicuramente si verificherà 

Esempi :
	Un dato da un punteggio superiore a 4 : $A=\{5,6\}$
	Otteniamo almeno 3 teste da 4 lanci di una moneta :
	$$A=\{TTTC,TTCT,TCTT,CTTT,TTTT\}$$

Due *eventi* A e B si dicono *incompatibili* ( *disgiunti* ) se non è possibile che siano entrambi veri, cioè se $A\cap B=\emptyset$ 
![[Disgiunti.excalidraw]]

##### Operazioni sugli eventi

+ **Complementare**
	Il *complementare* è la *negazione* di un evento A indicato con $\overline{A}$ , questo è l'evento che è vero quando A è falso e viceversa
	Il *cmplementare* dell'evento certo è l'*evento* *impossibile* : $\overline{\Omega} = \emptyset$  
	![[Complement.excalidraw]]
+ **Intersezione**
	L'*intersezione* di due eventi A e B , indicato con $A\cap B$ è l'evento che è vero quando sia A che B sono veri :
	![[Intersection.excalidraw]]
+ **Unione**
	L'*unione* di due eventi A e B indicata con $A\cup B$ è l'evento che è vero quando o A oppure B oppure entrambi sono veri
	![[Unione.excalidraw]]
+ **Incluso** 
	L'evento A è incluso nell'evento B ( $A\subset B$ ) se il verificarsi di A implica il verificarsi di B
	![[Incluso.excalidraw]]

#### Partizioni

Una famiglia di *eventi* si dice una *partizione* dello spazio campionario se ogni coppia di insiemi della famiglia ha intersezione vuota e l'unione di tutti i componenti della famiglia è $\Omega$ stesso

Una *partizione* può essere *finita* , ad esempio : 
$\{C_1,C_2,C_3\}$ è una partizione di 3 elementi se :
$$C_1\cap C_2 = C_1\cap C_3 = C_2\cap C_3 = \emptyset$$
e 
$$C_1\cup C_2\cup C_3=\Omega$$
![[Partizione.excalidraw]]

Un qualsiasi *evento* A si può scrivere come unione delle sue intersezioni con gli elementi della *partizione*
$$A=(A\cap C_1)\cup(A\cap C_2)\cup(A\cap C_3)$$
![[Paritzione2.excalidraw]]

Una partizione *numerabile* può essere definita come :
$$C_i\cap C_j = \emptyset\quad \forall i, j;\quad \bigcup_{i=1}^{\infty} C_i=\Omega$$
Sciegliendo un qualsiasi *evento* A come unione *numerabile* delle sue intersezioni con gli elementi di una partizione abbiamo :
$$A=\bigcup_{i=1}^{\infty}\space (A\cap C_i)$$


#### Esempio

**Fenomeno Aleatorio** : Studio del lancio di un dado 

**Eventi** : Consideriamo i seguenti eventi :
	A = $\{5,6\}$ : il risultato del lancio è superiore a 4
	B = $\{2,4,6\}$ : il risultato del lancio è pari
Allora avremo che :
	$A\cap B = \{6\}$ : il risultato del lancio è pari *e* superiore a 4
	$A\cup B=\{2,4,5,6\}$ : il risultato del lancio è pari *o* superiore a 4 
**Partizione** : Dividiamo lo *spazio campionario* ( $\Omega= \{1,2,3,4,5,6\}$ ) in numeri divisibili per 3 e non ( creiamo una *partizione* )
$$C_1=\{3,6\};\quad C_2=\{1,2,4,5\}$$
Allora avremo che : 
$$A=(A\cap C_1)\cup(A\cap C_2) = \{6\}\cup\{5\}$$
$$B=(B\cap C_1)\cup(B\cap C_2)=\{6\}\cup\{2,4\}$$
### Probabilità

#### Definizione assiomatica 

La *probabilità* è una funzione che assegna ad ogni evento di uno spazio campionario un valore in $\mathbb{R}^+$ , ossia un numero non negativo , che deve soddisfare i seguenti *assiomi* :

1. *Positività* : $0\le$

# Appunti
#### R-Studio

c minuscola -> concatenate

**sapzio campionario** : insieme di tutti i possibili risusltati di un fenomeno aleatorio ( non abbiamo certezza del risusltato ) 
moneta = testa o crocio = 2
**cardinalità** : numero di elementi = 2 

## 9/10/2023

35/39 prob elementaty

