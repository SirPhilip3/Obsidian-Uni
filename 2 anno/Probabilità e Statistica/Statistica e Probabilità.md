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
###### Proprietà

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

### Distribuzioni di probabilità

>[!todo]
>copia appunti su distribuzioni di probabilità discrete e continue
>#todo

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
Sia $X$ la variabile aleatoria che conta il nuemro totale di successi ottenuti in $n$ prove. 
Si dice allora che $X$ ha una *distribuzione Binomiale* di parametri $n$ e $p\in(0,1)$ e si scrive :
$$
X\sim Bin(n,p)
$$

Avremo che la funzione di probabilità risulterà essere :
$$
\mathbb{P}[X=x]=\binom n x p^x(1-p)^{n-x},\quad x=0,1,\dots,n 
$$




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

