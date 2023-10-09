# 20/09/2023

## Statistica

### Probabilità elementare

//! rivedi appunti

#### Principio fondamentale del calcolo combinatorio

Se una scelta può essere fatta in $m_1$ modi dviersi e un'altra scelta può essere fatta in $m_2$ modi diversi allora esistono in totale :
$$m_1{\times}m_2$$ possibilità di scelta

Esempio : 
	10 cavalieri e 12 dame partecipano ad un ballo :
	 ci sono $10*12 = 120$ possibili coppie danzanti 

#### Principio fondamentale generalizzato

Se ciascuna di $r$ scelte sucessive può essere fatta in $m_i$ modi allora esistono in totale :
$$\prod^{r}_{i=1} m_{i} = m_{1} \times...\times m_r$$
possibilità di scelta

Esempio : 
	Una commisione deve essere composta da un membro del partito A che conta 10 rappresentanti , da un membro del partito B che conta 15 rappresentanti , da un membro del partito C che conta 2 rappresentanti

   Ci sono in totale $10*15*2 = 300$ possibili commisioni

#### Disposizioni

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

#### Permutazioni

Le  disposizioni semplici di $n$ elementi presi $n$ alla volta si chiamano *permutazioni* :
	Tutti i modi in cui $n$ elementi possono esser ordinati in fila :
	$$n\times (n-1)...\times 2 \times 1=n!$$
Esempio :
Le permutazioni delle lettere *I , L , A* sono $3! = 6$ :
$ILA,IAL,LIA,LAI,AIL,ALI$

#### Combianzioni

In generale, un sottoinsieme di numerosità $r$ scelto da un insieme con $n$ elementi si chiama **combianzione** di $n$ elemento presi $r$ alla volta ( *senza ordine* )
	Il numero di combinazioni di $n$ elementi $r$ alla volta è :
	$$\frac{n\times(n-1)...\times(n-r+1)}{r!} = \binom{n}{r}$$
	**Coefficiente binomiale** $n$ su $r$

Esempio :
	La professoressa interroga ogni lunedì 10 studenti da una classe di 25. Esistono per lei $\binom{25}{10} = 3268760$ possibilità di scelta

#### R-Studio

c minuscola -> concatenate

**sapzio campionario** : insieme di tutti i possibili risusltati di un fenomeno aleatorio ( non abbiamo certezza del risusltato ) 
moneta = testa o crocio = 2
**cardinalità** : numero di elementi = 2 

# 9/10/2023
