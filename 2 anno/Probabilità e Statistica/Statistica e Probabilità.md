# Statistica

## Probabilità elementare

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

### Riassunto

![[image.jpeg]]

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

1. *Positività* : $0\le\mathbb{P}[A]\le1$
2. *Normalizzazione* : $\mathbb{P}[\Omega]=1$ ( probabilità dell'evento certo = 1 )
3. *Additività* : Se $A_1, A_2, ...$ è una sequenza di eventi *incompatibili* cioè $A_i\cap A_j=\emptyset\quad \forall i\ne j$  allora :
	$$\mathbb{P}\Bigg[\bigcup_{n=1}^{\infty} A_n\Bigg]=\sum_{n=1}^{\infty}\mathbb{P}[A_n]$$
	Ossia la probabilità dell'unione degli eventi incompatibili è uguale alla somma delle probabilità dei singoli eventi

#### Interpretazione Logica

La probabilità dell'evento A , $\mathbb{P}[A]$ , è un numero tra 0 e 1 che indica il grado di fiducia dell'individuo nell'avverarsi dell'evento A. Più $\mathbb{P}[A]$ si avvicina a 1 più ci aspettiamo che l'evento si avveri ( o minore è la nostra incertezza sull'avverarsi di quell'evento )

Una volta osservato il fenomeno aleatorio sappiamo se A si è verificato o meno e di conseguenza la sua probabilità non serve più ( 1 se l'evento si è verificato 0 altrimenti )

#### Proprietà

##### Complementare
Probabilità del *complementare*
Dato un evento A :
$$\mathbb{P}\Big[\overline{A}\Big]=1-\mathbb{P}[A]$$
##### Evento impossibile
Probabilità dell'*evento impossibile*
$$\mathbb{P}[\emptyset]=\mathbb{P}\Big[\overline{\Omega}\Big]=1-\mathbb{P}[\Omega]=0$$
##### Unione
Probabilità dell'*unione*
Dati due eventi A e B
$$\mathbb{P}[A\cup B]=\mathbb{P}[A]+\mathbb{P}[B]-\mathbb{P}[A\cap B]$$
##### Partizione
Probabilità di una *partizione*
Se $C_1,C_2,...$ sono una partizione allora :
$$\mathbb{P}\Bigg[\bigcup_{i=1}^{\infty} C_i\Bigg]=\mathbb{P}[\Omega]=1$$
#### Legge della probabilità totale

Se $C_1,C_2,...$ sono una partizione dell'evento certo, la probabilità di un qualsiasi evento A può essere scritta come :
$$\mathbb{P}[A]=\sum_{i} \mathbb{P}[A\cap C_i]$$
#### Spazi campionari finiti

Quando lo spazio campionatorio costituisce un insieme finito, $\Omega=\{\omega_1,...,\omega_n\}$ allora un'assegnazione di probabilità è data da $n$ valori $p_1,...,p_n$ tali che :
1. $p_i\in[0,1],\quad \forall i=1,...,n$
2. $\sum_{i=1}^n p_i=1$
3. $p_i=\mathbb{P}[\{\omega_i\}], \quad \forall i=1,...,n$

Dato che ogni evento è $A\subset \Omega$ , esso si può scrivere come unione ( finita ) degli eventi elementari ( disgiunti ) che lo costituiscono 
$$A=\{\omega_1,...,\omega_{i_r}\}=\bigcup_{k=1}^r \{\omega_{i_k}\}$$
Potremmo quindi scrivere che la *probabilità* di A è :
$$\mathbb{P}[A]=\sum_{k=1}^r\mathbb{P}[\{\omega_{i_k}\}]=\sum_{k=1}^r p_{i_k}$$
#### Eventi elementari equiprobabili

Se possiamo assumere che tutti gli eventi elementari abbiano la *stessa probabilità* allora :
$$p_i=\mathbb{P}[\{\omega_i\}]=\frac{1}{n}, \quad \forall i=1,...,n$$
Per ogni evento $A=\{\omega_1,...,\omega_{i_r}\}$ si può dunque scrivere
$$\mathbb{P}[A]=\frac{r}{n}=\frac{\#A}{\#B}=\frac{\text{numero casi favorevoli}}{\text{numero casi possibili}}$$
Esempio :
1. **Il dado** : Qual'è la probabilità che il risultato del lancio di un dado equilibrato sia un numero divisibile per 3
	+ Ognuno dei 6 possibili risultati ha la stessa probabilità di $\frac{1}{6}$
	+ I *casi favorevoli* per il nostro evento sono 2 : $\{3\}\space e \space \{6\}$ mentre i *casi possibili* sono 6
	+ Il risultato sarà quindi $\frac{2}{6}=\frac{1}{3}$
2. **Le antenne** : Un sistema di comunicazione è formato da $n$ antenne allineate di cui $m$ difettose. Il sistema funziona correttamente se non ci sono 2 antenne difettose consecutive. Qual'è la *porbabilità* che avremo un sistema funzionante ?
	+ Le antenne hanno $\binom{n}{m}$ configurazioni possibili ( ognuna con la stessa probabilità )
	+ Il numero di configurazioni funzionanti sono : $\binom{n-m+1}{m}$ perciò la probabilità richiesta sarà :
		$$\mathbb{P}[\text{sistema funzionante}]=\frac{\binom{n-m+1}{m}}{\binom{n}{m}}$$
#### Popolazioni e sottopopolazioni

Una *popolazione* è un insieme di $N$ elementi suddivisi, a seconda che possiedano o meno una certa caratteristica, in due *sottopopolazioni* rispettivamente $m$ e $N-m$ elementi

Qual'è la probabilità che su $n$ elementi estratti casualmente esattamente $k$ abbiano quella caratteristica ( e i rimanenti $n-k$ no ) ?

##### Soluzione con reinserimento

+ **Spazio campionatorio** : $\Omega = \{(x_1,...,x_n); x_i\in\text{popolazione}\space \forall i \}$
	Le estrazioni sono casuali quindi ogni $n$-upla ( vettore ordinato di dimensione $n$ ) in $\Omega$ ha la stessa probabilità di essere estratta
+ **Evento di interesse** : $A_k=\{(x_1,...,x_n)\in \Omega; k\space \text{elementi hanno la caratteristica richiesta}\}$
$$\#\Omega=N^n ;\quad \#A_k=\binom{n}{k}m^k(N-m)^{n-k}$$$$\mathbb{P}[A_k]=\binom{n}{k}m^k(N-m)^{n-k}\frac{1}{N^n}$$
$$=\binom{n}{k}\bigg(\frac{m}{N}\bigg)^k\bigg(\frac{N-m}{N}\bigg)^{n-k}$$
$$=\binom{n}{k}\bigg(\frac{m}{N}\bigg)^k\bigg(1-\frac{m}{N}\bigg)^{n-k}$$

Possiamo modificare la formula precedente considerando $\frac{m}{N}=p$ ossia la frazione può essere considerata come la probabilità di sucesso di un tentativo ; avremo quindi :
$$\mathbb{P}[A_k]=\binom{n}{k}(p)^k(1-p)^{n-k}$$
L'utilizzo del binomiale può avvenire quando :
+ ci sono 2 eventi possibili ( successo e insuccesso )
+ la probabilità di successo è costante per ogni tentativo
+ gli eventi sono indipendenti tra di loro ( ossia l'esito di un tentativo non influenza l'esito degli altri tentativi )

$$\binom{n}{k}$$
Indica $n$ come gli oggetti che dobbiamo selezionare e $k$ il numero di oggetti con la caratteristica che vogliamo

**Esempio**

Abbiamo un urna con 50 palline , 15 delle quali sono rosse le rimanente nere , volgiamo estrarre 5 palline *con reinserimento* . Qual'è la probabilità che abbiamo esattamente 3 palline rosse estratte ?

Avremo quindi che :
+ $n = 5$ ( dobbiamo selezionare 5 palline )
+ $k = 3$ ( i casi che vogliamo abbiano successo )
+ $m = 15$ ( numero delle palline con la caratterristica che è per noi un successo )
+ $N = 50$ ( numero totale di palline nell'urna )

Avremo quindi :
$$\binom{5}{3}\bigg(\frac{15}{50}\bigg)^3\bigg(1-\frac{15}{50}\bigg)^{2}$$

Possiamo anche vederla avendo la probabilità di estrarre una pallina rossa ( successo ) ossia : $\frac{15}{50}=0.3$

Avremo quindi :
$$\binom{5}{3}(0.3)^3(1-0.3)^{2}$$

##### Soluzione senza reinserimento
Solo valida se $n\le N , k\le m$ e $n-k\le N-m$

+ **Spazio campionatorio** : $\Omega = \{(x_1,...,x_n); x_i\in\text{popolazione}\space \forall i \}$
	Le estrazioni sono casuali quindi ogni sottoinsieme ( vettore non ordinato di dimensione $n$ ) in $\Omega$ ha la stessa probabilità di essere estratta
+ **Evento d'interesse** :
	$A_k=\{(x_1,...,x_n)\in \Omega; k\space \text{elementi hanno la caratteristica richiesta}\}$
$$\#\Omega=\binom{N}{m} ;\quad \#A_k=\binom{n}{k}\binom{N-m}{n-k}$$
$$\implies \mathbb{P}[A_k]=\frac{\binom{m}{k}\binom{N-m}{n-k}}{\binom{N}{n}}$$

**Esempio** :

Abbiamo un urna con 50 palline , 15 delle quali sono rosse le rimanente nere , volgiamo estrarre 5 palline *senza reinserimento* . Qual'è la probabilità che abbiamo esattamente 3 palline rosse estratte ?

Avremo che :
+ $N = 50$ palline ( la totalità della nostra popolazione )
+ $n = 5$ ( il numero delle estrazioni )
+ $k = 3$ ( numero dei successi desiderati )
+ $m = 15$ ( numero di possibili successi nella popolazione totale )

Avremo quindi :
$$\frac{\binom{15}{3}\binom{50-15}{5-3}}{\binom{50}{5}}$$
$$\frac{\binom{15}{3}\binom{35}{2}}{\binom{50}{5}}$$
$$\mathbb{P}[R]=0,1277$$
### Probabilità condizionata

Una probabilità si dice *condizionata* ( o *subordinata* ) quando : 
Prima dell'arrivo di un'informazione ho un'idea di probabilità con l'arrivo di un'informazione questa probabilità viene aggiornata ( essenzialmente sapendo una certa informazione aggiornare la probabilità di un evento )

#### Definizione 

Sia B un evento di probabilità positiva. La *probabilità condizionata* dell'evento A dato l'evento B è :
$$\mathbb{P}[A|B]=\frac{\mathbb{P}[A\cap B]}{\mathbb{P}[B]}$$
+ Evento condizionato : $A$ ( ciò che cambia )
+ Evento condizionante : $B$ ( ciò che fa cambiare )
+ Probabilità di A in presenza di B : $\mathbb{P}[A|B]$

**Esempio** : 

Eventi : 
+ $B$ : Incendio quel giorno
+ $\overline{B}$ : non c'è un incedio quel giorno
+ $A$ : La lezione è in ritardo
+ $\Omega$ : tutto ciò che poteva succedere quel giorno

![[Pasted image 20231024103714.png]]

Prima abbiamo che la probabilità risulta essere l'intersezione tra i 2 eventi :
$$\mathbb{P}[A\cap B]$$

Come varia la probabilità di $A$ sapendo che è avvenuto $B$ ?
Sapendo che $B$ è avvenuto l'evento certo diventa $B$ ( essenzialmente $\Omega$ diventa $B$ ) :

![[Pasted image 20231024103836.png]]

Ora la probabilità aggiornata sarà :
$$\mathbb{P}[A|B]=\frac{\mathbb{P}[A\cap B]}{\mathbb{P}[B]}$$

In questo modo *normalizziamo* la nuova probabilità sul nuovo evento certo $B$

>[!warning]
>$\mathbb{P}[A|B]\not=\mathbb{P}[B|A]$
>Nel primo caso la normalizzazione è in B nel secondo è in A 

##### Assiomi

$$\mathbb{P}[A|B]\quad \text{e} \quad \mathbb{P}[\overline{A}|B]$$
Sono in relazione tra loro infatti :
$$\mathbb{P}[\overline{A}|B]=\frac{\mathbb{P}[\overline{A}\cap B]}{\mathbb{P}[B]}=\frac{\mathbb{P}[B]-\mathbb{P}[A\cap B]}{\mathbb{P}[B]}=1-\mathbb{P}[A|B]$$

>[!warning]
>$\mathbb{P}[A|B]\quad \text{e} \quad \mathbb{P}[A|\overline{B}]$ non sono in relazione diretta
 
**Esempio** :

Abbiamo un urna contente 4 palle bianche numerate da 1 a 4 e 3 palle nere numerate da 1 a 3 
Da questa urna si campiona casualmente una palla , avremo quindi i seguenti eventi :
+ B = "viene estratta una palla bianca"
+ N = "viene estratta una palla nera"
+ $C_i$ = "viene estratto il numero $i$" con $i=1,2,3,4$ 

Calcoliamo le seguenti probabilità condizionate :
+ La palla estratta ha il numero 1 *dato* che è bianca
+ La palla estratta ha il numero 1 *dato* che è nera 
+ La palla estratta sia nera *dato* che ha il numero 1

Avremo quindi :
+ $$\mathbb{P}[C_1|B]=\frac{\mathbb{P}[C_1 \cap B]}{\mathbb{P}[B]}=\frac{1/7}{4/7}=\frac1 4$$
+ $$\mathbb{P}[C_1|N]=\frac{\mathbb{P}[C_1 \cap N]}{\mathbb{P}[N]}=\frac{1/7}{3/7}=\frac1 3$$
+ $$\mathbb{P}[N|C_1]=\frac{\mathbb{P}[N \cap C_1]}{\mathbb{P}[C_1]}=\frac{1/7}{2/7}=\frac1 2$$
#### Formula delle probabilità composte

La definizione di *probabilità condizionata* si può utilizzare per descrivere le probabilità di un'intersezione , sempre che $\mathbb{P}[A|B]$ sia ben definita :
$$\mathbb{P}[A\cap B]=\mathbb{P}[A|B]\cdot\mathbb{P}[B]$$
Questa formula può essere generalizzata per un qualsiasi numero di eventi :
$$\mathbb{P}[A_1\cap A_2\cap \dotsc \cap A_n]=\mathbb{P}[A_1]\cdot\mathbb{P}[A_2|A_1]\cdot\mathbb{P}[A_3|A_1\cap A_2]\dotsc\cdot\mathbb{P}[A_n|A_1\cap \dotsc \cap A_{n-1}]$$

**Esempio** : 

>[!todo]
>Scrivi un esempio
>#todo

#### Eventi Indipendenti

Si dice che $A$ e $B$ sono *indipendenti* nel caso in cui :
$$\mathbb{P}[A|B]=\mathbb{P}[A]$$
Avremo anche quindi che :
$$\mathbb{P}[A\cap B]=\mathbb{P}[A]\cdot\mathbb{P}[B]$$
Ossia sapere l'avvenimento di $B$ non modifica la probabilità di $A$

>[!warning] 
>Eventi *indipendenti* è diverso da eventi *disgiunti* 
>Due eventi *disgiunti*  possono essere *indipendenti* solo se uno di essi ha probabilità 0

La definizione può essere resa generale :
Gli eventi $A_1, \dotsc , A_n$ si dicono reciprocamente *indipendenti* se comunque si prendono $k\gt 1$ di essi , si ha :
$$\mathbb{P}[A_{i_k}\cap\dots \cap A_{i_k}]=\mathbb{P}[A_{1_k}]\cdot\dotsc\cdot\mathbb{P}[A_{i_k}]$$
#### Esempi

> [!todo]
> fai un esempio
> #todo

#### Legge della Probabilità totale

Se $C_1, C_2, \dotsc$  Sono una partizione dell'evento certo , la probabilità di un qualsiasi evento $A$ può essere scritta come :
$$\mathbb{P}[A]=\sum_i\mathbb{P}[A\cap C_i]=\sum_i\mathbb{P}[C_1]\cdot\mathbb{P}[A|C_i]$$
La prima uguaglianz aderiva dal fatto che l'evento $A$ è l'unione delle intersezioni tra l'evento stesso e le partizioni :
$$A=\bigcup_i(A\cap C_i)$$
che sono a due a due *disgiunti* 
La seconda uguaglianza deriva invece dalla definizione di *probabilità condizionata*

**Esempio**

> [!todo]
> fai un esempio
> #todo 
#### Legge di Bayes

Sia data la partizione $C_1, C_2, \dotsc$  ( con tutti i suoi elementi tale che abbiano probabilità positiva ) e un evento A ( con probabilità positiva ) Allora avremo che la probabilità condizionata da una qualsiasi partizione sarà :
$$\mathbb{P}[C_m|A]=\frac{\mathbb{P}[A|C_m]\cdot\mathbb{P}[C_m]}{\sum_i \mathbb{P}[A|C_i]\cdot\mathbb{P}[C_i]}$$
Questa può essere derivata da :
+ $$\mathbb{P}[C_m|A]=\frac{\mathbb{P}[C_m\cap A]}{\mathbb{P}[A]}$$
	Derivante dalla definizione di *probabilità condizionata*
+ $$\mathbb{P}[C_m\cap A]=\mathbb{P}[C_m]\cdot \mathbb{P}[A|C_m]$$
	Derivante dalla fromula delle *probabilità composte*
+ $$\mathbb{P}[A]=\sum_i\mathbb{P}[A|C_i]\cdot\mathbb{P}[C_i]$$
	Derivante dalla legge della *probabilità totale*

**Interpretazione** :
• Interpretazione del teorema di Bayes: 
	• Permette di aggiornare l’assegnazione di probabilità data a priori a certi eventi $C_m$, alla luce di nuova informazione ($A$ si è verificato). 
	• Il risultato di questa operazione di aggiornamento sono le nuove probabilità $P[C_m|A]$, dette anche a posteriori. 
	• Le probabilità a posteriori costituiscono una sintesi dell’informazione disponibile a priori su un certo fenomeno e dell’informazione empirica.

**Esempio** :

Un’azienda che assembla computer riceve il 24% dei componenti dal fornitore X, il 36% dal fornitore Y e il rimanente 40% dal fornitore Z. Risultano difettosi il 5% dei componenti forniti da X, il 10% dei componenti forniti da Y e il 6% dei componenti forniti da Z. 

Se un computer assemblato presenta un componente difettoso, qual'è la probabilita che questo componente sia stato fornito da Z?

Evidenziamo gli *eventi* :
+ X : Assembalto dal fornitore X ( $P[X] = 0.24$ )
+ Y : Assemblato dal fornitore Y ( $P[Y] = 0.36$ )
+ Z : Assemblato dal fornitore Z ( $P[Z] = 0.4$ )
+ D : Componenti difettorsi ( $P[D|X] = 0.05$ , $P[D|Y] = 0.1$ , $P[D|Z] = 0.06$ )

Ciò che sappiamo è che il componente e danneggiato e noi vogliamo calcolare la probabilità che questo venga dal produttore Z
Avremo che dovremo quindi calcolare :
$$\mathbb{P}[Z|D]=\frac{\mathbb{P}[D|Z]\cdot \mathbb{P}[Z]}{\mathbb{P}[D]}$$
$$\mathbb{P}[D]=\mathbb{P}[X]\cdot\mathbb{P}[D|X]+\mathbb{P}[Y]\cdot \mathbb{P}[D|Y]+\mathbb{P}[Z]\cdot \mathbb{P}[D|Z]$$
$$=0.24\cdot0.05+0.36\cdot0.4+0.4\cdot 0.6$$
Concludendo avremo :
$$\mathbb{P}[Z|D]=\frac{\mathbb{P}[D|Z]\cdot \mathbb{P}[Z]}{\mathbb{P}[D]}=\frac{0.4\cdot0.06}{0.072}=0.33$$
### Varaibili Casuali

Spazi campionatori e fenomeni aleatori possono non rappresentare un insieme numerico  

In molte situazioni non ci interessa il risultato specifico di un esperimento ma una sua rappresentazione numerica ( *funzione numerica* )

*Esempio* : 

Abbiamo un urna contenente 4 palline bianche ( numerate da 1 a 4 ) e 3 nere ( numerate da 1 a 3 )
Consideriamo l'estrazione di 2 palline con reinserimento 

Avremo che lo *spazio campionario* risulta essere :
$$\Omega=\{(B1,B1),(B1,N3),(N3,N3),(N3,B2),\dots\}$$
Per rappresentare questi eventi numericamebte potremmo assegnare ad ogni possibile un valore numerico :
$$\Omega=\{2,4,6,5,\dots\}$$

In questo caso ad ogni coppia di palline estratte gli assegnamo la somma dei loro valori

**Variabili Aleatorie** ( o *causali* ) :
	Una *variabile aleatoria* X è una funzione che assume valori numerici determinati dall'esito di un cero fenomeno aleatorio 
	$$X : \Omega \rightarrow \mathbb{R}$$
>[!warning]
>Possono esistere più variabili aleatorie per lo stesso esperimento 

*Esempi* :
+ $S_4$ : numero di teste in 4 lanci consecutivi di una moneta 
	I possibili valori di $S_4$ sono : $0 ,1 ,2 ,3 , 4$ ( *variabile aleatoria discreta* )
+ $X$ : vincita in una scommessa 
	I possibili valori di $X$ sono : $500$ e $-500$
+ $T$ : tempo di vita di un componente elettronico 
	I possibili valori di $T$ sono tutti i possibili numeri reali maggiori di 0 ( *variabile aleatoria continua* )


Una variabile aleatoria associata ad un esperimento definisce dunque un nuovo *spazio campionatorio* numerico costituito da tutti i possibili valori assunti dalla variabile stessa 

![[Pasted image 20231102160105.png]]

#### Varaibili aleatorie discrete

Una variabile aleatoria *discreta* $X$ assume valori in un insieme numerabile ( o finito ) di punti : 
$$\{x_1,x_2,\dots,x_i,\dots\}$$

Ad ogni elemento del nuovo spazio campionatorio viene quindi asseganta una probabilità :
$$\mathbb{P}[X=x_i]=p_i, \quad \forall i =1,2,\dots$$
Ogni probabilità $p_i$ deve rispettare le seguenti proprietà :
+ $0\le p_i \le 1$ : la probabilità per ogni evento deve essere compresa tra 0 e 1 
+ $\sum_i p_i = 1$ : la somma di tutte le proprietà deve fare 1 

Per calcolare la *probabilità* di un evento A si sommano le *probabilità* dei singoli valori che appartengono ad A :
$$\mathbb{P}[X\in A]=\sum_{i:x_i\in A} p_i$$
**Funzione di Probabilità** :

E' un'assegnazione di probabilità $P(x)=\mathbb{P}[X=x]$ e può essere rappresentata attraverso un diagramma a bastoncini :

![[Pasted image 20231102162013.png]]

*Esempio* :

Abbiamo un urna contenente 4 palline bianche ( numerate da 1 a 4 ) e 3 nere ( numerate da 1 a 3 )
Si campiona casualmente una pallina :

$X$  = numero estratto dall'urna
$$X\in \{1,2,3,4\} = X(\Omega)\subset\mathbb{R}$$
$$\mathbb{P}[X=1]=\frac{2}{7}$$
$$\mathbb{P}[X=2]=\frac{2}{7}$$
$$\mathbb{P}[X=2]=\frac{2}{7}$$
$$\mathbb{P}[X=3]=\frac{1}{7}$$
Avremo quindi che la *funzione di probabilità* è :
$$x = \begin{cases}
   \frac{2}{7} &\text{se } x=1,2,3; \\
   \frac{1}{7} &\text{se } x=4; \\
   0 &\text{altrimenti}
\end{cases}
$$

Se $A=\{1,2\}$ allora 
$$\mathbb{P}[X \in A]=\mathbb{P}[X\le2]=P_X(1)+P_X(2)=\frac{2}{7}+\frac{2}{7}=\frac{4}{7}$$
#### Variabili aleatorie continue

Una *variabile aleatoria continua* X assume valori in un insieme continuo di punti ( un sottoinsieme di $\mathbb{R}$ non numerabile )

In questo caso non possiamo assgnare una probabilità ad ogni elemento dello *spazio campioanrio* poichè esso contiene infiniti elementi
Per questo si assegna la probabilità ad ogni sottoinsieme di suoi possibili valori , questa sarà l'area sottesa ad una curva 

La funzione che rappresenta la *densità di probabilità* deve seguire le seguenti regole :
+ $f(x)\ge 0, \quad \forall x\in \mathbb{R}$
+ $\int_{\mathbb{R}} f(x)\ dx = 1$  : ossia l'area totale sotto il grafico di $f(x)$ è 1

**Densità di Probabilità** 

Una *funzione* $f(x)$ con le prorpietà precedenti viene chiamata *densità di probabilità* 

Una volta assegnata una densità di probabilità alla variabile aleatoria continua X si può determinare la probabilità di ogni evento A
$$\mathbb{P}[X \in A]=\int_A f(x)\ dx$$

![[Pasted image 20231102164950.png]]

>[!warning]
>$\mathbb{P}[X=x]=P(x)=0 \quad \forall x \in \mathbb{R}$
>Ossia la probabilità che sia esattamente un numero $x$ è 0 poichè l'area del sottografico di un punto preciso è 0 ( non esiste l'area al di sotto di un punto , è una linea ) 

>[!note]
>$\mathbb{1}_{I}(x)$
>Indica la funzione indicatrice , questa è equivalente a dire :
> $$x = \begin{cases}
   \mathbb{1} &\text{se } x\in  I\\
   0 &\text{altrimenti} ; 
\end{cases}$$

*Esempio* :

Sia $X$ una variabile aleatoria continua con densità :
$$f(x)=2\cdot e^{-2\cdot x}\mathbb{1}_{(0,+\infty)}(x)$$
Questo corrisponde a :
$$x = \begin{cases}
   2\cdot e^{-2\cdot x} &\text{se } x\gt0\\
   0 &\text{altrimenti} ; 
\end{cases}$$

>[!todo]
>grafico
>#todo

Come prima cosa verifichiamo che $f(x)$ sia davvero una densità :
+ $f(x)\ge 0, \forall x \in \mathbb{R}$  :  poichè è un esponenziale moltilicato per un numero positivo
+ $\int_0^{+\infty} 2e^{-2x}\ dx = 1$

Abbiamo quindi verificato che siamo effettivamente davanti ad una *desità di probabilità* 

Consideriamo ora due eventi : $A = (1,2)$ e $B=(-1,1)$  e calcoliamone la probabilità 
$$\mathbb{P}[X\in A]=\mathbb{P}[X\in (1,2) ]=\int_1^2 2e^{-2x}\ dx = e^{-2}-e^{-4}$$
$$\mathbb{P}[X\in B]=\mathbb{P}[X\in (-1,1) ]=\int_{-1}^0 0\ dx + \int_{0}^1 2e^{-2x}\ dx  = 1-e^{-2}$$


>[!todo]
>grafico
>#todo

#### Funzione di ripartizione

Si dice *funzione di ripartizione* ( o distribuzione comulativa ) di una variabile aleatoria $X$ la funzione $F : \mathbb{R}\rightarrow [0 ,1 ]$ così definita
$$F(x)=\mathbb{P}[X\le x], \quad \forall x \in \mathbb{R}$$ 
La funzione di ripartizione in un dato punto $x$ è semplicemente la probabilità che la varibile $X$ assuma valori minori o al più uguali a $x$ .
Per questo il suo dominio è $[0,1]$

La *funzione di ripartizione* ha le seguenti proprietà :
+ $F$ è non decrescente ( non può decrescere )
+ $F$ è continua a destra ( si arriva al valore da destra )
+ $\lim_{x\rightarrow -\infty} F(x)=0$ e $\lim_{x\rightarrow +\infty} F(x)=1$ 

Rappresenta la somma delle probabilità 

##### Funzione di Ripartizione per una variabile discreta

Se $X$ è una variabile *discreta* con valori $\{x_1,x_2,\dots\}$ e funzione di probabilità $P(x_i)=p_i$

$$F(x)=\sum_{i:x_i\le x}\mathbb{P}[X=x_i]=\sum_{i:x_i\le x} p_i$$
La *funzione di riaprtizione* di una *variabile* discreta è una funzione costante a tratti con salti in corrispondenza dei punti di massa $x_1, x_2,\dots$  

![[Pasted image 20231109114806.png]]


Dalla *funzione di ripartizione* si può risalire alla *funzione di probabilità* così :
$$\mathbb{P}[X=x]=F(x)-F(x^-)$$
Ossia la probabilità che $X$ assuma il valore $x$ è uguale al salto della funzione di ripartizione nel punto $x$ 

>[!todo]
>Example

##### Funzione di Ripartizione per una variabile continua

Se $X$ è una variabile continua con densità $f(x)$ allora 
$$F(x)=\int_{-\infty}^{x} f(t) \ dt$$
*Proprietà* :
+ La funzione di ripartizione di una variabile continua è una funzione continua 
+ Dalla funzione di ripartizione si può risalire alla densità di probabilità della variabile in tutti i punti in cui $F(x)$ è derivabile :
	$$f(x)=\frac{dF(x)}{dx}$$

![[Pasted image 20231109160442.png]]

>[!todo]
>Example
>#todo

#### Costanti Caratterisitiche 

Una *costante caratteristica* o indice è un numero associato ad una variabile aleatoria o alla sua distribuzione di probabilità e sintetizza l'infromazione di interesse sul fenomeno rappresentato dalla variabile 

Alcune *costanti caratteristiche* sono :
+ Il *valore atteso* che è unindice di posizione ( media )
+ La *varianza* che è un indice di dispersione
+ I *quantili* di una variabile aleatoria contengono informazioni sia sulla posizione che sulla forma di una distribuzione di probabilità

##### Valore atteso ( media )

###### Valore atteso di una variabile aleatoria discreta

Se $X$ è una variabile aletaoria discreta con valori $\{x_1,x_2,\dots \}$ e funzione di probabilità $P(x_i)=p_i$ allora il *valore atteso* o *media* di $X$ è :
$$\mathbb{E}[X]=\sum_ix_ip_i=x_1p_1+x_2p_2+\dots$$

**Esempio** :

Abbiamo un urna 
Per la variabile $X$ = numero estratto si ha :
$$P_X(x)=\begin{cases}
   \frac{2}{7} &\text{se } x=1,2,3; \\
   \frac{1}{7} &\text{se } x=4; \\
   0 &\text{altrimenti}
\end{cases}$$

Allora : $$\mathbb{E}[X]=1\frac{2}{7}+2\frac{2}{7}+3\frac{2}{7}+4\frac{1}{7}=\frac{16}{7}$$
###### Valore atteso di una variabile aleatoria continua

Se $X$ è una variabile aletaoria continua con densità $f(x)$ allora il *valore atteso* o *media* di $X$ è :
$$\mathbb{E}[X]=\int_\mathbb{R}xf(x)\ dx$$
**Esempio** :

Abbiamo una variabile aleatoria continua $X$ con densità : $$f(x)=2e^{-2x}\mathbb{1}_{(0, +\infty)}(x)$$
si ha :
$$\mathbb{E}[X]=\int_0^{+\infty} 2xe^{-2x}\ dx = \frac1 2$$
###### Propri

Il *valore atteso* ha le seguenti proprietà :
+ $\mathbb{E}[a]=a$   dove $a$ è una costante
+ $\mathbb{E}[aX+b]=a\mathbb{E}[X]+b$    dove $a$ e $b$ sono costanti

In particolare $\mathbb{E}[X-\mathbb{E}[X]]=0$
##### Varianza

###### Varianza di una variabile aleatoria discreta

Se $X$ è una varaibile aleatoria discreta con valori $\{x_1,x_2,\dots \}$ e funzione di probabilità $P(x_i)=p_i$ allora la *varianza* di $X$ è :
$$\text{Var}[X]=\sum_ix^2_ip_i-[\mathbb{E}[X]]^2$$
**Esempio** :

Abbiamo un urna 
Per la variabile $X$ = numero estratto si ha :
$$P_X(x)=\begin{cases}
   \frac{2}{7} &\text{se } x=1,2,3; \\
   \frac{1}{7} &\text{se } x=4; \\
   0 &\text{altrimenti}
\end{cases}$$
Allora $$\text{Var}[X]=1\frac2 7 + 2^2\frac2 7 + 3^2\frac 3 7 + 4^2\frac 1 7-\bigg(\frac {16} 7 \bigg)^2$$

###### Varianza di una variabile aleatoria continua

Se $X$ è una variabile aletaoria continua con densità $f(x)$ allora la *varianza* di $X$ è :
$$\text{Var}[X]=\int_\mathbb{R} x^2f(x)\ dx-[\mathbb{E}[X]]^2$$
**Esempio**


Abbiamo una variabile aleatoria continua $X$ con densità : $$f(x)=2e^{-2x}\mathbb{1}_{(0, +\infty)}(x)$$
Abbiamo :
$$\text{Var}[X]=\int_0^{+\infty} 2x^2e^{-2x}\ dx - \bigg(\frac 1 2\bigg)^2=\frac1 4$$
###### Proprietà

La *varianza* ha le seguenti proprietà :
+ $\text{Var}[a]=0$   dove $a$ è una costante
+ $\text{Var}[aX+b]=a^2\text{Var}[X]$    dove $a$ e $b$ sono costanti
##### Moda

La *moda* di una variabile aleatoria $X$ è il punto ( o i punti ) in cui la funzione di probabilità ( o di densità ) assume valore massimo

**Esempio** :

La varaibile $X$ con densità $f(x)=2e^{-2x}\mathbb{1}_{(0, +\infty)}(x)$  ha come *moda* 0 , ha infatti il suo massimo nel limite destro di 0
##### Mediana

La *mediana* di una variabile aleatoria $X$ è il minimo valore $m$ per cui 
$$F(m)=\mathbb{P}[X\le m]\ge \frac 1 2 $$
**Esempio** :

>[!todo]
>fai un esempio
>#todo

##### Quantili

Fissato un valore $\alpha \in (0,1)$ , il *quantile di livello* $\alpha$ di una variabile aleatoria $X$ è il minimo valore $q_{\alpha}$ per cui :
$$F(q_{\alpha}) = \mathbb{P}[X\le q_{\alpha}]\ge \alpha$$

I *quantili* sono *indici di posizione* che generalizzano il concetto di mediana di una distribuzione

Per una variabile aleaotria continua ( con funzione di ripartizione $F$ continua ) il quantile di livello $\alpha$ p l'unico punto $q_{\alpha}$ in cui :
$$F(q_{\alpha})=\mathbb{P}[X\le q_{\alpha}]=\alpha$$

Vari *quantili* particolari :
+ La *mediana* non è altro che il quantile di livello $\frac 1 2$
+ I *percentili* sono i quantili di livello $\frac k {100}$ con $k=1,2,\dots,99$
+ I *decili* sono i quantili di livello $\frac k {10}$ con $k=1,2,\dots,9$  
+ I *quartili* sono i quantili di livello $0.25$ ( primo quartile ) , $0.5$ ( mediana ) e $0.75$ ( terzo quantile )

### Distribuzioni di probabilità Discrete

#### Distribuzione Uniforme Discreta 

Consideriamo una varaibile aleatoria $X$ che assume un numero finito di valori , $\{x_1,\dots,x_n\}$ , tutti con la stessa probabilità $p_i=1/n, \ i=\ 1,\dots,n$

Si dice allora che $X$ ha una *distribuzione uniforme* e si scrive :
$$X \sim U\{x_1,\dots,x_n\}$$

Graficamente :
![[Pasted image 20231122123112.png]]

**Esempi** :
	$X$ descrive il risultato del lancio di un dado ( non truccato ). I valori possibili per $X$ sono gli interi fra $1$ e $6$ ciascuno con probabilità $\frac 1 6$ di verificarsi

##### Proprietà

###### Media 
Se i valori di $x$ sono equidistanti tra di loro abbiamo :
$$E[x]=\frac{x_{min}+x_{max}}{2}$$
Altrimenti avremo :
$$
\sum_{i=1}^n x_i\cdot p_i = \frac 1 n \sum_{i=1}^n x_i 
$$
###### Varianza
Se i valori di $x$ sono equidistanti tra di loro abbiamo che :
	la varianza si può ricavare sapendo che $Var(X)=E[X^2]-E[X]^2$
	Avremo quindi : 
$$
Var(X)=\frac{(x_{max}-x_{min})^2}{12}
$$
Altrimenti avremo che :
$$\sum_{i=1}^n x_i^2\cdot p_i - E[X]^2$$
$$= \frac 1 n \sum_{i=1}^n x^2_i-\frac 1 {n^2}(\sum_{i=1}^n x_i)^2$$
#### Distribuzione Ipergeometrica 

Sia $X$ la variabile aleatoria che conta il numero di successi su $n$ estrazioni senza reinserimento da una popolazione con $N$ elementi dei quali $K$ sono considerati successo. Si dice allora che che $X$ ha una *distribuzione ipergeometrica* di parametri $N$ , $K$ e $n$ , si scrive :
$$
X\sim Ig(N,K,n)
$$
Avremo che la probabilità di un evento sarà dato da :
$$\mathbb{P}[X=k]=\frac{\binom{K}{k}\cdot\binom{N-K}{n-k}}{\binom{N}{n}}$$
con : $k=max\{0,n-(N-K)\},\dots,min\{n,K\}$  con $n\le N$

##### Proprietà
###### Media

$$E[X]=n\cdot \frac K N$$
###### Varianza

$$Var[X]=n\cdot\frac K N \cdot \frac{N-K}N\cdot \frac {N-n}{N-1}$$

**Esempio** :

Un software consiste di 12 programmi , 5 dei quali necessitano di upgrade. Se vengono scelti a caso 4 programmi per un test :
1.  Qual'è la probabilità che almeno 2 di essi siano da aggiornare ?
	Sia $X$ la variabile che conta il numero di programmi da aggiornare fra 4 scelti 
	Allora $X \sim Ig(N=12,K=5,n=4)$ 
	E la probabilità richiesta è :
	$$
	\mathbb{P}[X\ge 2] = 1 - \mathbb{P}[X \le 1]
	$$
	$$
	=1-\mathbb{P}[X=0]-\mathbb{P}[X=1]
	$$
	$$
	1 -\frac{\binom{5}{0}\cdot\binom{12-5}{4-0}}{\binom{12}{4}} -\frac{\binom{5}{1}\cdot\binom{12-5}{4-1}}{\binom{12}{4}}
	$$
2. Qual'è il numero medio di programmi da aggiornare fra i 4 scelti ?
	Il numero atteso di programmi da aggiornare fra i 4 scelti è
	$$
	\mathbb{E}[X]=4\cdot\frac{5}{12}=\frac 5 3 
	$$
###### Funzioni R

Per calcolare : $\mathbb{P}[X\le x]$

```R
phyper(x,K,N-K,n)
```
Dove :
$x$ : numero di successi dall'estrazione
$K$ : numero di successi dall'intera popolazione
$N$ : intera popolazione
$n$ : numero di estrazioni 

Quindi nel caso del precedente problema potevamo usare :
```R
1-phyper(1,5,7,4)
```

Per calcolare : $\mathbb{P}[X= x]$

```R
dhyper(x,K,N-K,n)
```

Utilizzato per calcolare la probabilità di avere esattamente quel numero di successi

Nel problema precedente potevamo scrivere :
```R
1-dhyper(1,5,7,4)-dhyper(0,5,7,4)
```

#### Distribuzione di Bernuolli

Supponiamo di eseguire un esperimento i cui possibili risultati possono essere classificati come *successo* con probabilità $p$ o *insuccesso* con probabilità $1-p$ . Questo esperimento viene chiamato **Prova Bernulliana** 

**Definizione** :
	Sia $X$ la variabile casuale che prende il valore $X=1$ quando l'esito di una *prova bernulliana* è un *successo* e $X=0$ quando è un *insuccesso* . 
	Si dice allora che $X$ ha una *distribuzione di Bernuolli* di parametro $p\in (0,1)$ e si scrive 
	$$
	X\sim Ber(p)
	$$ 
La funzione di probabilità è :
$$
\mathbb{P}[X=x]=p^x(1-p)^{1-x}\mathbb{1}_{\{0,1\}}(x) = \begin{cases}
   1-p &\text{se } x=0; \\
   p &\text{se } x=1; \\
   0 &\text{altrimenti}
\end{cases}
$$
##### Proprietà
###### Media

$$E[X]=p$$
Avendo $K$ il numero di successi e $N$ il numero totale degli elementi avremo :
$$E[X]=\frac K N$$
###### Varianza
$$Var[X]=p\cdot(1-p)$$
Avendo $K$ il numero di successi e $N$ il numero totale degli elementi avremo :
$$\frac K N\cdot\frac{N-K}{N}$$
#### Distribuzione Binomiale

Supponiamo di eseguire $n$ *prove bernulliane* indipendenti, ognuna con probabilità di successo $p$.
Sia $X$ la variabile aleatoria che conta il numero totale di successi ottenuti in $n$ prove. 
Si dice allora che $X$ ha una *distribuzione Binomiale* di parametri $n$ e $p\in(0,1)$ e si scrive :
$$
X\sim Bin(n,p)
$$

Avremo che la funzione di probabilità risulterà essere :
$$
\mathbb{P}[X=x]=\binom n x p^x(1-p)^{n-x},\quad x=0,1,\dots,n 
$$
Dove $p$ risulta essere la probabilità di successo 
##### Dimostrazione

Possiamo dimostrare che la precedente funzione di probabilità risulta essere una distribuzione di probabilità poichè : 
$$
\sum_{x=0}^n\mathbb{P}[X =x] = \sum_{x=0}^n \binom n x p^x (1-p)^{n-x}
$$
Questo è equivalente al binomio di Newton nella seguente forma :
$$
(a+b)^n=\sum_{x=0}^n \binom n x a^x (b)^{n-x}
$$
Sostituendo avremo :
$$
\sum_{x=0}^n\mathbb{P}[X =x]=(p+(1-p))^x=1
$$
>[!note]
> La *distribuzione di Bernuolli* è un caso particolare della binomiale con $n=1$

##### Esempi

###### 1
Si consideri un'urna contenente 4 palline bianche e 3 nere . Sia $S_3$ la variabile che conta il numero di palline bianche ottenute in tre estrazioni con reinserimento 

Calcolare $\mathbb{P}[S_3=2]$

Consideriamo l'estrazione di una pallina bianca come un successo avremo che : $\mathbb{P}[\text{bianca}]=4/7$  si può affermare che $S_3 \sim Bin(3,4/7)$

Avremo quindi che :
$$\mathbb{P}[S_3=2]=\binom 3 2\bigg(\frac 4 7\bigg)^2\bigg(\frac 3 7\bigg)^{(3-2)}=0.4198$$
###### 2

La distribuzione binomiale is utilizza spesso nel caso di *campionamento da popolazioni infinite* quando si conosce la probabilità di successo $p$

Se la popolazione viene considerata infinita non si distingue tra estrazioni con o senza reinserimento poichè si assume che la probabilità di successo in estrazioni sucessive non cambia 

**Esempio** :

Un motore di ricerca cerca una parola in una sequenza infinita di siti web bindipendenti , il 20% dei siti contentgono la parola cercata.
Qual'è la probabilità che 5 dei primi 10 siti visitati contengono la parola cercata ?
E la probabilità che *almeno* 5 dei primi 10 siti la contengano ? 

Sia $Y$ la varaibile aleatoria che conta il numero di siti , fra i primi 10 visitati , che contengono la parola cercata.
Allora $Y\sim Bin(n=10,p=0.2)$

Avremo quindi :
$$\mathbb{P}[Y=5]=\binom {10} 5 0.2^5(1-0.2)^{10-5}=0.0264$$
$$\mathbb{P}[Y\le5]=\mathbb{P}[Y=0]+\mathbb{P}[Y=1]+\dots+\mathbb{P}[Y=5]=0.1074+0.2684+\dots+0.0264=0.9936$$
##### Proprietà

La forma della binomiale dipende di parametri di essa :
![[Pasted image 20231122145127.png]]

###### Media

$$
E[X]=\sum_{k=0}^n k\binom n k p^k (1-p)^{n-k}
$$
>[!todo]
>completa dimostrazione 
>#todo

$$E[X]=n\cdot p$$
###### Varianza

La varianza si calcola tenendo conto che 
$$
E\big[X^2\big]=\sum_{k=0}^n k^2\binom n k p^k (1-p)^{n-k}
$$
>[!todo]
>completa dimostrazione 
>#todo

$$E[X]=n(n-1)\cdot p^2+np$$

Si ha dunque 
$$Var[X]=E\big[X^2\big]-E[X]^2=np(1-p)$$
###### Funzioni R

Per calcolare : $\mathbb{P}[X\le x]$

```R
pbinom(x,N,p)
```
Dove :
$x$ : numero di successi dall'estrazione
$p$ : probabilità di un successo
$N$ : intera popolazione 

Quindi nel caso del precedente problema potevamo usare :
```R
pbinom(5,10,0.2)
```

Per calcolare : $\mathbb{P}[X= x]$

```R
dbinom(x,N,p)
```

Utilizzato per calcolare la probabilità di avere esattamente quel numero di successi

Nel problema precedente potevamo scrivere :
```R
dbinom(0,10,0.2)+dbinom(1,10,0.2)+dbinom(2,10,0.2)+dbinom(3,10,0.2)+dbinom(4,10,0.2)+dbinom(5,10,0.2)
```
#### Distribuzione di Poisson

Una variabile $X$ che assume valori nell'insieme dei numeri naturali $\mathbb{N}$ ha *distribuzione di Posson* di parametro $\lambda\gt 0$ se :
$$
\mathbb{P}[X=k]=\frac{\lambda^k}{k!}\cdot e^{-\lambda}, \quad k=0,1,\dots
$$

Scriveremo allora 
$$X\sim Po(\lambda)$$

>[!todo]
>inserici grafico
>#todo

##### Dimostrazione 

Possiamo dimostrare che risulta essere una distribuzione vedendo che :
$$\sum_{i=0}^{+\infty}\frac{\lambda^i}{i!}e^{-\lambda}=e^{-\lambda}\sum_{i=0}^{+\infty}\frac{\lambda^i}{i!}=e^{-\lambda}e^{\lambda}=1$$
##### Utilizzo

La vaiabile di *Poisson* viene utilizzata come modello per il conteggio di un certo fenomeno di interesse in un determinato intervallo ( tempo , spazio etcc... ) 
Ad esempio : 
+ chiamate in arrivo ad un centralino in un certo intervallo di tempo
+ macchine transitanti ad un casello autostradale in un certo periodo del giorno 
+ difetti rilevati in un pezzo di filo d'acciaio 
+ terremoti manifestatisi in una data area nell'arco degli ultimi 10 anni

##### Proprietà

###### Media

$$\mathbb{E}[X]=\sum_{i=0}^{+\infty}i\frac{\lambda^i}{i!}e^{-\lambda}$$
>[!todo]
>spiegazione
>#todo

$$\lambda\sum_{i=1}^{+\infty}\frac{\lambda^{i-1}}{(i-1)!}e^{-\lambda}=\lambda$$
###### Varianza

Similmente si può dimostrare che 
$$Var[X]=\lambda$$
##### Esempio

Ad un account di posta elettronica arrivano messaggi con una media di 10 ogni mezz’ora. 
Si può inoltre supporre che il numero di messaggi in arrivo segua una distribuzione di Poisson. 

Qual è la probabilità che nella prossima mezz’ora mi arrivino non più di 3 messaggi? E almeno 12?

Quindi prendendo come variabile causale : $X=\text{"numero di messaggi ogni mezz'ora"}\sim Po(\lambda=10)$

$$\mathbb{P}[X\le3]=\mathbb{P}[X=0]+\mathbb{P}[X=1]+\mathbb{P}[X=2]+\mathbb{P}[X=3]$$
$$=\frac{10^0}{0!}e^{-10}+\frac{10^1}{1!}e^{-10}+\frac{10^2}{2!}e^{-10}+\frac{10^3}{3!}e^{-10}=0.0103$$
###### Funzioni R

Per calcolare : $\mathbb{P}[X\le x]$

```R
ppois(x, lambda)
```
Dove :
$x$ : numero di eventi
$lambda$ : $\lambda$ 

Quindi nel caso del precedente problema potevamo usare :
```R
ppois(3,10)
```

Per calcolare : $\mathbb{P}[X= x]$

```R
dpois(x, lambda)
```

Utilizzato per calcolare la probabilità di avere esattamente quel numero di successi

Nel problema precedente potevamo scrivere :
```R
dpois(0,10)+dpois(1,10)+dpois(2,10)+dpois(3,10)
```


##### Approssimazione Poisson per la Binomiale 

Quando $n\rightarrow \infty$ e $p \rightarrow 0$ ma in modo tale che il prodotto $np\rightarrow \lambda$ rimane costante, allora la funzione di probabilità di una variabile aleatoria binomiale di parametri $n$ e $p$ si può approssimare con la funzione di probabilità di una *Poisson* di parametro $\lambda$ :
$$\lim_{\substack{n \rightarrow \infty \\ p \rightarrow 0 \\ np \rightarrow \lambda}}
\binom n x p^x(1-p)^{n-x}=e^{-\lambda}\frac{\lambda^x}{x!}$$
Questa approssimazione viene utilizzata principalmente quando $n\ge 100$ e $p\le 0.05$ si sciegle allora $\lambda=\mathbb{E}[X]=np$

Questa legge di sostituzione è nota come **legge degli eventi rari** poichè si può interpretare come la distribuzione del numero di eventi di tipo successo quando gli esperimenti bernulliani sono tanti ( $n \rightarrow \infty$ ) ma la possibilità di succeso è molto piccola ( $p \rightarrow 0$ ) ovvero i successi sono rari

###### Esempio

Una fabbrica di componenti elettronici fornisce il 3% dei chip acquistati da un produttore di telefoni cellulari. 
Qual è la probabilità che su 100 chip acquistati ve ne siano al massimo 3 provenienti da quella fabbrica?

$X$ = numero di chip provenienti dalla fabbrica su 100 avremo :
$$X\sim Bin(100,0.03)$$
Utilizzando la *binomiale* avremo :
$$\mathbb{P}[X \le 3]=\sum_{k=0}^3\binom{100}{k}0.03^k0.97^{100-k}=0.64724921$$
Dato che $n=100$ è grande e $p=0.03$ è piccolo si può utilizzare l'approssimazione di *Poisson* con parametro $\lambda = np = 100\cdot 0.03=3$ :
$$\sum_{k=0}^{3} \frac{3^k}{k!}e^{-3}=0.64723189$$

I risultati risultano uguali fino alla 4° cifra decimale
#### Distribuzione Geometrica

Sia $X$ una variabile aleatoria che conta il numero di ripetizioni indipendenti necessarie per osservare il primo successo in un esperimento binario che ha probabilità di successo singola $p$ . 
Si dice allora che $X$ ha una *distribuzione geometrica* di parametro $p\in(0,1)$ e si scrive :
$$X\sim Geo(p)$$
Avremo che la funzione di probabilità sarà :
$$\mathbb{P}[X=x]=(1-p)^{x-1}p, \quad x= 1,2,3,\dots$$

##### Dimostrazione

Possiamo facilmente dimostrare che si tratta di una distribuzione di probabilità nel solito metodo :
$$\sum_{x=1}^\infty \mathbb{P}[X=x]=p\sum_{x=1}^\infty(1-p)^{x-1}=p\frac{1}{1-(1-p)}=1$$

>[!todo]
>spiegazione matematica
>#todo

##### Proprietà

###### Media

$$\mathbb{E}[X]=1/p$$
>[!todo]
>dimostrazione
>#todo
###### Varianza

$$Var[X]=\frac{1-p}{p^2}$$
>[!todo]
>dimostrazione
>#todo
###### Mancanza di Memoria

La probabilità non cambia sapendo che le precedenti ripetizioni siano state un *insuccesso* , per ogni nuovo elemento di cui si fa una prova di bernuolli la sua probabilità di essere un successo o insuccesso non dipende dalle precedenti probabilità ( è come se facessi l'esperimento di bernulli la prima volta , come se non fossero mai evvenute le precedenti )

Questo può essere dimostrato nel seguente modo :
$$\mathbb{P}[X\gt m + n| X\gt m]=\frac{\mathbb{P}[X\gt m + n]}{\mathbb{P}[X\gt m]}$$
Come da definizione di *probabilità condizionata*
Sostutiamo ora tenendo conto che $\mathbb{P}[X\gt k]=(1-p)^k$
$$\frac{(1-p)^{m+n}}{(1-p)^m}=\frac{(1-p)^m(1-p)^n}{(1-p)^m}=(1-p)^n=\mathbb{P}[X\gt n]$$

La probabilità quindi di $m+n$ sapendo la probabilità di $m$ ( gli elementi prima ) risulta essere la probablità di $n$ , ossia la probabilità risulta indipendente dalla probabilità degli elementi precedenti ( $m$ )

##### Esempio

Consideriamo che il 20% dei siti visitati contengono la parola cercata

Supponiamo che $X$ conti il numero di pagine da visitare per trovare per la prima volta la parola cercata

1. Qual'è la probabilità di dover visitare 15 siti per trovare la parola ?
	$$
	\mathbb{P}[X=15]=0.2\times0.8^{14}=0.0088
	$$
2. Dato che i primi 4 siti visitati non contenevano la parola cercata , qual'è la probabilità di doveren visitare più di 10 in tutto per trovvare la parola cercata ?
	$$
	\mathbb{P}[X\gt10|X\gt4]=\mathbb{P}[X\gt10-4]=\mathbb{P}[X\gt6]=(1-0.2)^6=0.2621
	$$
3. Qual'è il numero medio di siti da visitare per trovare la parola la prima volta
	$$
	\mathbb{E}[X]=\frac 1 {0.2} = 5
	$$
###### Funzioni R

Per calcolare : $\mathbb{P}[X\le x]$

```R
pgeom(x,p)
```
Dove :
$x$ : numero di fallimenti
$p$ : probabilità di un successo

Per calcolare : $\mathbb{P}[X= x]$

```R
dgeom(x,p)
```

### Distribuzioni di probabilità Continue

#### Distribuzione uniforme

$X$ è una variabile che può assumere qualsiasi valore nell'intervallo $(a,b)$ indifferentemente .
La sua densità di probabilità è allora costante nell'intervallo $(a,b)$ e nulla al di fuori
$$
f(x)=\begin{cases}
   \frac{1}{b-a} &\text{se } x\in(a,b); \\
   0 &\text{altrove } 
\end{cases}
$$

$X$ è quindi una variabile aleatoria *uniforme* e si scrive :
$$
X\sim U(a,b)
$$

La *funzione di ripartizione* è :
$$
F(x)=\int_a^x\frac 1 {b-a} dy=\frac{x-a}{b-a}; \quad x\in (a,b)
$$

Per calcolare $\mathbb{P}[c\le X \le d] = \frac{d-c}{b-a}$

##### Proprietà

###### Media

$$
\mathbb{E}[X]=\frac{a+b}2
$$
###### Varianza

$$
Var[X]=\frac{(b-a)^2}{12}
$$

###### Funzioni R

Per calcolare : $\mathbb{P}[X\le x]$

```R
punif(x, min , max)
```
Dove :
$x$ : elemento di cui si vuole calcolare la probabilità
$min$ : intervallo inferiore della variabile aleatoria
$max$ : intervallo superiore della variabile aleatoria

Per calcolare : $\mathbb{P}[X= x]$

```R
dunif(x, min , max)
```

**Esempio** :

La variabile aleatoria $B$ ha distribuzione uniforme compresa tra $5.1\le B \le 5.8$ , si calcoli : $\mathbb{P}[5.1<Y<5.7]$
```R
punif(5.7,5.1,5.8)-punif(5.1,5.1,5.8) = 0.8571
```

#### Distribuzione normale ( Gaussiana )

Una variabile aleatoria $X$ ha *distribuzione normale* o *gaussiana* , indicata con :
$$
X\sim N(\mu,\sigma^2)
$$
La sua funzione di ripartizione è :
$$f(x)=c\cdot e^{-\frac1 2\Big(\frac{(x-\mu)^2}{\sigma^2}\Big)}, \quad x\in \mathbb{R},\mu\in\mathbb{R},\sigma\gt 0$$
![[Pasted image 20231129143220.png]]


La *distribuzione normale stadard* è :
$$X\sim N(0,1)$$
Avrà come funzione di ripartizione :
$$f(x)=c\cdot e^{-\frac{x^2}{2}}$$
Troviamo ora $c$ utilizzando la proprietà che è una funnzione di densità e quindi devve soddisfare la seguente equazione :
$$
c\int_{-\infty}^{+\infty} e^{-\frac{x^2}{2}}dx=1
$$
$$
c\cdot\sqrt{2\pi}=1
$$
$$
c=\frac 1 {\sqrt{2\pi}}
$$
Quindi avremo che :
$$f(x)=\frac 1 {\sqrt{2\pi}}\cdot e^{-\frac{x^2}{2}}$$

La *funzione di ripartizione* risulta essere :
$$\int_{-\infty}^x\frac 1 {\sqrt{2\pi}}\cdot e^{-\frac{t^2}{2}}dt$$
In questo caso non si può svolgere l'integrale ( non esiste una funzione analitica che la deriva ) e quindi la *funzione di ripartizione* viene espressa come integrale

##### Proprietà

###### Media

$$\mathbb{E}[X]=\mu$$
###### Varianza

$$Var[X]=\sigma^2$$
###### Funzioni R

Per calcolare : $\mathbb{P}[X\le x]$

```R
pnorm(x, mean , sd)
```
Dove :
$x$ : valore di cui volgiamo calcolare $\mathbb{P}[X\le x]$
$mean$ : media della normale $\mu$
$sd$ : deviazione standard ( $\sqrt{Var}$ ) 

Per calcolare : $\mathbb{P}[X= x]$

```R
dnorm(x, mean , sd)
```

Si può inoltre calcolare il *quantile* relativo ad una determinata probabilità con il seguente comando : 

```R
qnorm(p, mean , sd)
```

>[!note] 
>Gli stessi comandi sono utilizzati per la normale standard con $mean=0$ e $sd=1$
#### Normale Standard

La *normale standard* ( $Z\sim N(0,1)$ ) ha come funzione di  *ripartizione* viene indicata con $\Phi$ 
Tutte le altre *normali* possono essere ricondotte alla standard attraverso la *standardizzazine*
$$X\sim N(\mu,\sigma^2)\implies Z=\frac{X-\mu}{\sigma}\sim N(0,1)$$
Sappiamo anche che :
$$\mathbb{P}[a<X<b]=\mathbb{P}\bigg[\frac{a - \mu}{\sigma}<Z<\frac{b-\mu}{\sigma}\bigg]=\Phi\bigg(\frac{b-\mu}{\sigma}\bigg)-\Phi\bigg(\frac{a-\mu}{\sigma}\bigg)$$

Si può facilmente calcolare il valore della probabilità attraverso le tavole della normale :

**Esempio** 

$$\mathbb{P}[X\le 1] = 0.84134$$
![[Pasted image 20231129143905.png]]

Possiamo anche utilizzare la funzione di R `{r}qnorm(q)` per determinare questo valore

**Esempio di Standardizzazione** :

$$X\sim N(-1,4)\implies Z=\frac{X+1}{2}\sim N(0,1)$$
+ $\mathbb{P}[X\le 1]=\mathbb{P}\bigg[Z\le\frac{1+1}{2}\bigg]$ 
	`{r}pnorm(q=1,mean=-1,sd=2) = 0.84134`
	oppure
	`{r}pnorm(q=(1+1)/2, mean=0,sd=1) = 0.84134`
+ $\mathbb{P}[0\le X\le 1]=\mathbb{P}\bigg[\frac{0+1}{2}\le Z\le\frac{1+1}{2}\bigg]$
	`{r}pnorm(q=1,mean=-1,sd=2)-pnorm(q=0,mean=-1,sd=2) = 0.14988`
	oppure
	`{r}pnorm(q=(1+1)/2,mean=0,sd=1)-pnorm(q=(0+1)/2,mean=0,sd=1) = 0.14988`
#### Approssimazione normale per la Binomiale

Quando $n$ è grande allora la funzione di ripartizione di una variabile aleatoria binomiale di parametri $n$ e $p$ si può approssimare con la funzione di ripartizione di una normale di parametri $\mu = n\cdot p$  e  $\sigma^2 = n\cdot p(1-p)$ 

Avremo che : 
$$Bin(n,p)\approx N(np\ ,\ np(1-p))$$

>[!attention]
>L'approssimazione viene utilizzata nella pratica quando $np(1-p)\ge 10$
>

**Esempio** :

Un certo virus danneggia un file con probabilità 0.35, indipendentemente dagli altri file. Il virus attacca una cartella con 2400 file. Qual è la probabilità che vengano danneggiati fra gli 800 e gli 850 file ( *inclusi* ) ?

Sia $X$ la variabile che conta il numero di file danneggiati 
Allora avremo $X\sim Bin(2400,0.35)$ e la probabilità richiesta sarà :
$$\mathbb{P}[800\le X \le 850]=\sum_{k=800}^{850}\binom{2400}{k}0.35^k(1-0.35)^{2400-k}=0.632893$$

Possiamo però approssimare $X$ con una *normale* con parametri :
$$\mu=2400\cdot0.35=840$$
$$\sigma=\sqrt{2400\cdot0.35\cdot(1-0.35)}=\sqrt{546}=23.36664$$
Ora dobbiamo applicare la *correzione per continuità* infatti poichè stiamo convertendo da una distribuzione discreta ad una continua infatti poichè nel caso discreto $\mathbb{P}[X=x]$ potrebbe essere positivo nel caso continuo risulta essere sempre 0
In generale : 
$$\mathbb{P}[X=x]=\mathbb{P}[x-0.5\lt X \lt x+0.5]$$

Corregiamo quindi così la nostra probabilità :

$$\mathbb{P}[800\le X \le850]=\mathbb{P}[799.5\lt X \lt 850.5]$$
$$\approx\Phi\bigg(\frac{850.5-840}{23.36664}\bigg)-\Phi\bigg(\frac{799.5-840}{23.36664}\bigg)$$
$$=\Phi(0.4493586)-\Phi(-1.73324)=0.631887$$
#### Distribuzione Gamma

Si dice che $X$ ha *distribuzione gamma* di parametri $\alpha \gt 0$ e $\lambda \gt 0$ e si scrive :
$$X\sim Ga(\alpha,\lambda)$$
La sua *densità* di probabilità è della forma :
$$f(x)=\begin{cases} 
   \frac{\lambda^\alpha}{\Gamma(\alpha)}x^{\alpha-1}e^{-\lambda x} & x \in (0,\infty) \\
   0 &\text{altrove } 
\end{cases}$$
Dove $\Gamma(\alpha)=\int_0^\infty x^{\alpha-1}{e^{-x}}dx$ è la *funzione gamma* 
##### Proprietà
###### Media 
$$\mathbb{E}[X]=\frac{\alpha}{\lambda}$$
###### Varianza
$$Var[X]=\frac{\alpha}{\lambda^2}$$

###### Funzoni R

Per calcolare : $\mathbb{P}[X\le x]$

```R
pgamma(x, alpha , lambda)
```
Dove :
$x$ : valore di cui volgiamo calcolare $\mathbb{P}[X\le x]$
$\alpha$ : parametro alpha della distribuzione
$\lambda$ : parametro rate 

Per calcolare : $\mathbb{P}[X= x]$

```R
dgamma(x, alpha , lambda)
```


**Esempio** :

Se $X$ è una variabile aleatoria gamma di *media* 4 e *varianza* 4 allora :
$$\alpha = 4 \quad e\quad \lambda=1$$
+ Si può calcolare allora ( itegrando ripetutamente per parti )

$$\mathbb{P}[X<4]=\int_0^4 \frac{e^{-x}x^3}{6}dx$$
$$=\frac 1 6 \Big[-(x^3+3x^2+6x+6)e^{-x}\Big]\Bigg|_0^4 =$$
$$=0.567$$
Possiamo infatti ricondurre $\Gamma(4)=\int_0^\infty x^{4-1}e^{-x}=(4-1)!=6$
>[!note]
La funzione gamma può quindi essere rincondotta a : $(\alpha-1)!$

#### Distribuzione Esponenziale

Un caso particolare di distribuzione gamma si verifica con $\alpha = 1$ è la *distribuzione esponenziale* : $$X\sim Exp(\lambda)$$
La sua *densità* risulta essere :
$$f(x)=\begin{cases} 
   \lambda e^{-\lambda x} & x \in (0,\infty) \\
   0 &\text{altrove } 
\end{cases}$$
La funzione di *ripartizione* diventa quindi :
$$f(x)=\begin{cases} 
   0 & x \lt 0 \\
   1-e^{-\lambda x} & x \ge 0 
\end{cases}$$
>[!important]
>La distribuzione esponenziale si usa per modellare tempi di attesa.
>Esempi :
>+ La vita di un certo componente elettronico di un'automobile
>+ La lunghezza fra 2 difetti consecutivi di una fibra ottica
>+ Il tempo che passa fra l'arrivo di un treno in stazione e il sucessivo
##### Proprietà 

###### Media
$$\mathbb{E}[X]=\frac{1}{\lambda}$$
###### Varianza
$$Var[X]=\frac{1}{\lambda^2}$$
###### Mancanza di Memoria

La *distribuzione esponenziale* è l'unica distribuzione continua a possedere questa proprietà

Quindi se abbiamo :
$$\mathbb{P}[X\gt t +s|X\gt t]=\frac{\mathbb{P}[X\gt t+s]}{\mathbb{P}[X>t]}=\mathbb{P}[X>s]$$
Questa proprietà può essere dimostrata, come per quella della dimostrazione *geometrica*, trenendo conto che :
$$\mathbb{P}[X>x]=e^{-\lambda x}, \quad x>0$$
###### Funzione R

Per calcolare : $\mathbb{P}[X\le x]$

```R
pexp(x, lambda)
```
Dove :
$x$ : valore di cui volgiamo calcolare $\mathbb{P}[X\le x]$
$\lambda$ : parametro rate 

Per calcolare : $\mathbb{P}[X= x]$

```R
dexp(x, lambda)
```

**Esempio** : 

Il tecnico di un laboratorio dell’università in un’*ora* *installa* un certo software in media su *30* *pc*. Assumendo che il tempo di installazione su ogni pc segua una *distribuzione esponenziale*. 

Calcolare la *probabilità* che il tecnico impieghi *più* *di* *5* *minuti* per *installare* il software nel *prossimo* *pc*

Possiamo definire la variabile aleatoria in 2 modi :
+ $X$ = tempo di attesa in ore $\sim Exp(30)$
	$\mathbb{P}[X\gt 1/12] = e^{-30/12}$
+ $X$ = tempo di attesa in minuti $\sim Exp(1/2)$
	$\mathbb{P}[X>5]=e^{-5/2}$

>[!todo]
>rivisita distribuzione esponenziale e gamma
>#todo

#### Processo di Poisson

Il processo di Poisson è una sucessione di variabili aleatorie $\{X_t\}_{t\ge 0}$ con distribuzione di Poisson il cui parametro dipende dall'indice $t$ :
$$X_t\sim P(\lambda\times t)$$
Si utilizza per contare il numero di manifestazioni di un fenomeno di interesse in un qualsiasi intervallo di tempo di ampiezza $t$ , quando il tempo medio di queste manifestazioni dipende soltanto dall'ampiezza ( e non dalla posizione ) dell'intervallo considerato

Si può quindi scrivere che :
$\lambda$ : numero medio di eventi nell'unità di tempo
$X_t$ : numero di eventi in un intervallo di tempo $t$

**Esempio** : 

Il numero di messaggi in arrivo ad un casella di posta elettronice segue un processo di Poisson nel tempo con una media di 12 messaggi ogni 10 minuti

Se sciegliamo il minuto come unità di misura del tempo abbiamo :
$\lambda$ : numero medio di messaggi in un minuto = $12/10$
$X_t$ : numero di messaggi in $t$ minuti $\sim Po\Big(\frac {12}{10} t\Big)$ 

Possiamo allora calcolare : 
$$\mathbb{P}[\text{più di 20 messaggi in mezz'ora}]= \mathbb{P}[X_{30}>20] = 1-\mathbb{P}[X_{30}\le20]$$
Può essere calcolata utilizzando la seguente distribuzione : 
$$X_{30}\sim Po\bigg(\frac{12}{10}30\bigg)=Po(36)$$

##### Relazione con esponenziale

Associata ad ogni processo di Poisson c'è una variabile aleatoria esponenziale che misura il tempo tra 2 manifestazioni successive del fenomeno in questione 

$$T=\text{"tempo trascorso fra 2 eventi sucessivi"}\sim Exp(\lambda)$$
**Esempio** 

Riprendendo l'esempio precedente calcoliamo la probabilità che non arrivi nessun messaggio in 15 minuti :

Questa si può calcolare in 2 modi differenti 
+ Cosiderando che il numero di messaggi arrivati in 15 minuti devono essere uguali a 0
	$\mathbb{P}[X_{15}=0]\sim Po(12/10 \cdot 15) = Po(18)$
	$\mathbb{P}[X_{15}=0] = \frac{(12/10\times 15)^0}{0!}e^{-12/10\times 15}=e^{-18}$ 
+ Considerando che il primo messaggio che deve arrivare deve arrivare dopo 15 minuti
	$\mathbb{P}[T>15]\sim Exp(12/10) = e^{-12/10\times 15}= e^{-18}$

### Distribuzioni Congiunte

Distribuzioni costituite da due o più *variabili aleatorie* 

Quando abbiamo solo una *coppia* di variabili aleatorie si dice che abbiamo una **Distribuzione Bivaria** 

Quando abbiamo un numero di variabili maggiore di 1 si dice sempre che stiamo parlando di **Distribuzioni Multivarie**

#### Funzioni di Ripartizione

La *funzione di ripartizione congiunta* di una coppia di variabili aleatorie $(X,Y)$ è una funzione $F : \mathbb{R}^2\rightarrow [0,1]$ definta nel seguente modo :
$$F(x,y)=\mathbb{P}[X\le x, Y\le y], \quad \forall(x,y)\in \mathbb{R}$$
Si possono trovare le *funzioni di ripartizione* delle singole variabili aleatorie nel seguente modo :
$$F_X(x)=\mathbb{P}[X\le x]$$
$$=\mathbb{P}[X\le x, Y\le \infty]$$
Ponendo $Y\le \infty$ è come se dicessi che quella variabile non mi interessa considerarla nel risultato finale
$$=\mathbb{P}\bigg[\lim_{y\rightarrow\infty}\{X\le x, Y\le y\}\bigg]$$
$$=\lim_{y\rightarrow \infty}\mathbb{P}[X\le x, Y\le y]$$
$$=\lim_{y\rightarrow\infty}F(x,y)$$

Allo stesso modo $\lim_{x\rightarrow \infty}F(x,y)$

>[!note]
>La funzione di ripartizione congiunta $(X,Y)$ contiene tutte le informazioni riguardante le distribuzioni di probabilità delle singole varaibili aleatorie $X$ e $Y$ ovvero le *distribuzioni marginali*

>[!warning]
>Il viceversa non è vero , ossia dalle *distribuzioni marginali* non posso ricavare la *funzione di ripartizione congiunta* a meno che non si abbia un'ulteriore informazione riguardante la relazione tra le due varaibili

Il calcolo delle probabilità su una *distribuzione congiunta* può essere sempre calcolata usando la *funzione di ripartizione congiunta* $F(x,y)$ :
$$\mathbb{P}[a_1<X\le a_2, b_1 < Y \le b_2]=F(a_2,b_2)+F(a_1,b_1)-F(a_1,b_2)-F(a_2,b_1)$$

#### Funzione di probabilità congiunta

##### Per variabili aleatorie discrete

La *funzione di probabilità congiunta* :
$$p(x,y)=\mathbb{P}[X=x,Y=y],\quad \forall(x,y)\in \mathbb{R}^2$$

Le *funzioni di probabilità marginali* si ottengono sommando rispetto a tutti i valori possibili dell'altra variabile :
$$p_X(x)=\sum_{y : p(x,y)>0}p(x,y)$$
$$p_Y(y)=\sum_{x : p(x,y)>0}p(x,y)$$

Alternativiamente le funzioni di probabilità *congiunte* e *marginali* si possono rappresentare nella stessa tabella a 2 entrate :

![[Pasted image 20231208161937.png]]

**Esempio** :

Un programma consiste in 2 moduli , indichiamo con :
+ $X$ il numero di errori nel primo modulo
+ $Y$ il numero di errori nel secondo modulo
Questi hanno la seguente *distribuzione congiunta* :
$$p(0,0)=p(0,1)=p(1,0)=0.2$$
$$p(1,1)=p(1,2)=p(1,3)=0.1$$
$$p(0,2)=p(0,3)=0.5$$
Possiamo rappresentare la probabilità congiunta e le probabilità marginali attraverso una tabella : 
![[Pasted image 20231208162532.png]]

Possiamo ora calcolare le seguenti probabilità :
+ Probabilità che non ci siano errori nel primo modulo 
	Questa si calcola sommando tutte le probabilità congiunte della riga corrispondente a $X=0$ :
	$$\mathbb{P}[X=0]=\sum_{y=0}^3p(0,y)=0.20+0.20+0.05+0.05=0.5$$
+ Probabilità che nel primo modulo ci siano meno errori che nel secondo 
	$$\mathbb{P}[X<Y]=1-\mathbb{P}[X\ge Y]$$
	$$=1-\mathbb{P}[X=0,Y=0]-\mathbb{P}[X=1,Y=0]-\mathbb{P}[X=1,Y=1]$$
$$=1-(0.2+0.2+0.1)=0.5$$
##### Per variabili aleatorie continue

Si dice che $X$ e $X$ sono *congiunte continue* se esiste una funzione $f:\mathbb{R}^2\rightarrow \mathbb{R}$ integrabile e tale che abbia le seguenti caratteristiche :
+ $f(x,y)\ge 0, \quad \forall(x,y) \in \mathbb{R}^2$
+ $\int\int_{\mathbb{R}^2}f(x,y)dxdy=1$

$f$ è la *funzione di densità congiunta* di $(X,Y)$ e si utilizza per calcolare probabilità riguardanti le due varaibili congiuntamente 

Se $A,B \subset \mathbb{R}$
$$\mathbb{P}[X\in A,Y\in B]=\int_B\Bigg(\int_A f(x,y)dx \Bigg)dy$$

In particolare dalla *densità congiunta* si può ricavare la *funzione di ripartizione congiunta* : 
$$F(x,y)=\mathbb{P}[X\le x, Y\le y]=\int_{-\infty}^y\int_{-\infty}^{x}f(s,t)ds\ dt$$
Dalla *funzione di riaprtizione* si ottiene la *funzone di densità* : 
$$f(x,y)=\frac{d^2F(x,y)}{dx\ dy}$$

Le *funzioni di densità marginali* si ricavano integrando la *densità congiunta* rispetto all'altra variabile :

$$f_X(x)=\int_{\mathbb{R}}f(x,y)dy$$
$$f_Y(y)=\int_{\mathbb{R}}f(x,y)dx$$
**Esempio** :

La densità congiunta di $X$ e $Y$ è :
$$f(x,y)=\begin{cases} 2e^{-x}e^{-2y} & x>0 , y>0 \\ 0 & \text{altrove} \\ \end{cases}$$
Allora :
$$\mathbb{P}[X>1,Y<1]=\int_0^1\Bigg(\int_1^{+\infty}2e^{-x}e^{-2y}dx\Bigg)dy$$
$$=\int_0^12e^{-2y}(-e^{-x})_1^{+\infty}dy=e^{-1}\int_0^12e^{-2y}dy$$
$$e^{-1}(-e^{-2y})_0^1=e^{-1}(1-e^{-2})$$
>[!todo]
>continua esempi
>#todo

#### Varaibili aleatorie indipendenti

Si dice che due *varaibili aleatorie* sono *indipendenti* se :
$$\mathbb{P}[X\in A,Y\in B]=\mathbb{P}[X\in A]\mathbb{P}[Y\in B], \quad \forall A, B \subset \mathbb{R}$$
Possiamo dismostrare che è equivalente a :
$$F(x,y)=F_X(x)F_Y(y), \quad \forall (x,y)\in \mathbb{R}^2$$
Suddividendo nei casi in cui le varaibli sono :
+ *Discrete* : $p(x,y)=p_X(x)p_Y(y),\quad \forall(x,y)\in \mathbb{R}^2$ 
+ *Continue* : $f(x,y)=f_X(x)f_Y(y), \quad \forall(x,y)\in \mathbb{R}^2$

**Esempio** :

1. 
$$f(x,y)=\begin{cases} 24xy & x,y\in(0,1), x+y \in (0,1)\\ 0 & \text{altrove}\end{cases}$$
$X$ e $Y$ sono indipendenti ?
Poichè abbiamo che $x+y\in(0,1)$ per il dominio , sicuramente se modifichiamo $x$ anche $y$ cambierà di conseguenza , avremo quindi che $X$ e $Y$ *non sono indipendenti*


```functionplot
---
title: 
xLabel: x
yLabel: y
bounds: [-1,4,-1,3]
disableZoom: true
grid: true
---
f(x)=1-x
```

2.

![[Pasted image 20231208162532.png]]

Cosiderando questo esempio con 2 varaibili aleatorie *discrete* , per verficiare che $X$ e $Y$ siano indipendenti dobbiamo verificare che tutte le coppie di $x$ e $y$ soddifino la seguente proprietà :
$$p(x,y)=p_X(x)p_Y(y)$$
Nel nostro caso però non tutte le coppie soddisfano questa proprietà :
$$p(1,1)=0.10\ne p_X(1)p_Y(1)=0.50\cdot 0.30$$
Quindi $X$ e $Y$ *non sono indipendenti*

3. 
Considerando il caso in cui $X$ e $Y$ sono *variabili aleatorie indipendenti*  con funzioni di probabilità marginali : 

![[Pasted image 20231209163104.png]]

Sapendo le marginali e che queste sono indipendenti possiamo ricostriìuire la distribuzione congiunta , possiamo infatti calcolare :
$$p(0,0)=\mathbb{P}[X=0,Y=0]=\mathbb{P}[X=0]\cdot\mathbb{P}[Y=0]=0.5\cdot 0.7=0.35$$
$$p(0,1)=\mathbb{P}[X=0,Y=1]=\mathbb{P}[X=0]\cdot\mathbb{P}[Y=1]=0.5\cdot 0.2=0.10$$
Così via per tutte le coppie di $x$ e $y$ otteniamo :

![[Pasted image 20231209163407.png]]

Aquato punto potremmo calcolare :

$$\mathbb{P}[X+Y=1]=\mathbb{P}[X=0,Y=1]+\mathbb{P}[X=1,Y=0]=0.21+0.10=0.31$$
**Esempio** :

Un programma è formato da due blocchi che vengono processati sequenzialmente durante la compilazione.
Ogni blocco viene processato in un tempo medio di 5 minuti e si assume che i tempi di compilazione dei due blocchi, $X$ e $Y$ , siano *indipendenti* e con *distribuzione esponenziale*.

Poichè $X$ e $Y$ sono *indipendenti* la densità congiunta $X$ e $Y$ è :
$$f(x,y)=f_X(x)f_Y(y)=\frac15e^{-x/5} \mathbb{I}_{(0,+\infty)}(x)\cdot\frac15e^{-y/5} \mathbb{I}_{(0,+\infty)}(y)$$
Allora la probabilità che l'intero programma venga compilato in meno di 12 minuti sarà :
$$\mathbb{P}[X+Y\lt 12]=\int\int_{(x,y):x+y<12}f(x,y)dx\ dy$$
$$\int_0^{12}\Bigg(\int_0^{12-x}\frac15e^{-y/5}dy\Bigg)\frac15e^{-x/5}\ dx$$
$$\int_0^{12}\Bigg(\int_0^{12-x}\frac15e^{-y/5}dy\Bigg)\frac15e^{-x/5}\ dx$$
$$\int_0^{12}\bigg(1-e^{-(12-x)/5}\bigg)\frac15e^{-x/5}dx$$
$$\bigg(1-e^{-(12-x)/5}\bigg)-\frac{12}{5}e^{-12/5}=0.69156$$

#### Probabilità condizionata

##### Discrete

Siano $X$ e $Y$ due variabili aleatorie *discrete* con funzione di probabilità congiunta $p(x,y)$

La funzione di *probabilità condizionata* di $X$ dato $Y=y$ è :
$$p_{X|Y}(x|y)=\frac{p(x,y)}{p_Y(y)},\quad \forall y\ \text{ t.c.  }\ p_Y(y)>0$$
Allo stesso modo la funzione di probabilità condizionata di $Y$ dato $X=x$ è :
$$p_{Y|X}(y|x)=\frac{p(x,y)}{p_X(x)},\quad \forall x\ \text{ t.c.  }\ p_X(x)>0$$

Possiamo verificare infatti che .
$$p_{X|Y}(x|y)=\mathbb{P}[X=x|Y=y]$$
$$=\frac{\mathbb{P}[X=x,Y=y]}{\mathbb{P}[Y=y]}=\frac{p(x,y)}{p_Y(y)}$$

Se $X$ e $Y$ sono **Indipendenti** allora :
$$p_{X|Y}(x|y)=p_X(x)\quad p_{Y|X}(y|x)=p_Y(x)$$

**Esempio** :

Siano $X$ e $Y$ due varaibili aleatorie *discrete* :

![[Screenshot 2023-12-09 175636.png]]

Calcoliamo la funzione di probabilità di $X$ dato $Y=1$ utilizzando le informazioni contenute nella colonna corrispondente a $Y=1$
$$p_{X|Y}(0|1)=\frac{p(0,1)}{p_Y(1)}=0.2/0.5=0.4$$
$$p_{X|Y}(1|1)=\frac{p(1,1)}{p_Y(1)}=0.3/0.5=0.6$$
Dobbiamo avere che : 
$$X|Y=1\sim p_{X|Y}(x|1)=\begin{cases}0.4 &\text{se $x=0$} \\ 0.6 &\text{se $x=1$}\end{cases}$$
Essendo questa distribuzione differente dalla marginale di $X$ concludiamo che le due varaibili *non sono indipendenti* 

##### Continue

Siano $X$ e $Y$ due variabili aleatorie *continue* con funzione di probabilità congiunta $f(x,y)$



#### Valore atteso

# Appunti
#### R-Studio

c minuscola -> concatenate

**sapzio campionario** : insieme di tutti i possibili risusltati di un fenomeno aleatorio ( non abbiamo certezza del risusltato ) 
moneta = testa o crocio = 2
**cardinalità** : numero di elementi = 2 

## 9/10/2023

35/39 prob elementaty

## 6/11/2023

maggiore dispersione = dobbiamo prima vedere se le varianze sono gradi o piccole rispetto alle loro medie  

E[X] = 3.5   var[X] = 2.9
E[Y] = 7 var[Y] = 5.833 -> scala quadratica

*deviazione standard* 
sd(X) = $\sqrt {Var(x)}$

sd(X) = 1.707
sd(Y) = 2.41

*coeff di variazione* 

cv(x)=sd(x)/mod|E[x] (media)|

cumsum = funzione di ripartizione

*quantili*

???????????

