# Concetti di Base

## Terminologia

+ **Popolazione** :
	Tutte le unità statistiche di interesse ( es : persone ... )
+ **Parametro** :
	Una caratteristica numerica della popolazione di interesse : $\theta$
+ **Censimento** :
	Osservazione di *tutte* le unità della popolazione per valutare $\theta$
+ **Campione** :
	Sottoinsieme della popolazione utilizzato per stimare $\theta$ quando il censimento non è opportuno ( troppo costoso etcc )
+ **Statistica** : 
	Una qualsiasi funzione dei dati cesuari o campionari
+ **Stimatore** :
	Una particolare funzione statistica $\hat\theta$ ( theta cappello ) utilizzata per ricostruire $\theta$ ( si inferisce dal particolare al generale )
+ **Stima** :
	Valore dello *stimatore* corrispondente al particolare campione osservato

Il *campione* ha di per s'è un *errore* rispetto al *parametro* 
### Errori

Vi sono due diverse tipologie di errore :
+ **Errori campionari** : sono inevitabili
+ **Errori non campionari** : sono evitabili
#### Errori campionari

Sono dovuti al fatto che osserviamo solo un campione dei dati
Questi diminuiscono al crescere della dimensione campionaria se lo *stimatore* $\hat\theta$ è ragionevole ( se stima correttamente il parametro )

>[!example]
#### Errori non campionari

Dovuti ad una scorretta costruzione del campione o all'utilizzo di uno stimatore non approriato
Possono non diminuire al crescere della dimensione campionaria

>[!example]

### Campionamento Casuale

Per evitare gli errori non campionari il metodo più efficace è estrarre le unità del campione *casualmente* dalla popolazione

Questo ci permette di evitare l'introduzione di *distorsioni* dovute ad aspetti della popolazione che non conosciamo ( il nostro obbiettivo è evitare di avere un campione rappresentativo solo di un sottoinsieme della popolazione )

Esistono diversi *disegni di campionamento* ( schemi ) per estrarre casualmente le unità del campione 

#### Campionamento causale semplice

Le unità sono estratte dalla popolazione con la seguenti caratteristiche : 
+ Le unità sono indipendenti l'una dall'altra
+ Le unità hanno tutte la stessa probabilità di essere selezionate :
	Avendo $N$ unità ognuna di queste ha probabilità di essere selezionata : $\frac 1 n$ *indipendentemente* dalle altre 

>[!note]
>Le osservazioni ottenute con il campionamento casuale semplice sono variabili casuali *indipendenti e identicamente distribuite* o *i.i.d.*

>[!note]
>Esistono altre forme di campionamenti più complessi , si dicono *stratificati*
>Utilizzato dove il richio di un campione squilibrato darebbe risultati più difficilmente interpretabili

### Statistiche campionarie

Consideriamo un campione casuale di dimensione $n$ : $(X_1,\dots,X_n)$ i valori assunti dalle variabili sono indicati con $(x_1,\dots,x_n)$  

>[!example]
>campione casuale dei tempi di elaborazione ( CPU ) di 30 processi ( jobs ) in secondi :
>![[Pasted image 20240217155129.png]]

L'obbiettivo è utilizzare i dati campionari per ricostruire alcuni parametri della popolazione

Statistiche che misurano la posizione : 
+ *media* campionaria
+ *mediana* campionaria
+ *quantili* , *percentili* , *quartili*
Statistiche che misurano la variabilità : 
+ *varianza* campionaria e *deviazione standard*
+ *scarto interquartile*

Le statisiche sono *variabili casuale* quando calcolate su un campione *casuale* di dati 

Quando applico una statistica ad una variabile casuale sarà essa stessa una variabile casuale ( rappresenta la strategia che utiliziamo prima di guardare i dati ) , se la applico sui dati avremo di ritorno un valore 
#### Media campionaria

Supponiamo che le osservazioni $X_i$ siano variabili *i.i.d.* con valore atteso $E[X]=\mu$ e varianza $Var[X]=\sigma^2$ 

La media campionaria sarà allora : 
$$\overline X=\frac 1 n \sum_{i=1}^n X_i$$
$\hat X$ è uno stimatore della media di popolazione $\mu=E[X]$

Per l'esempio precedente la media campionatoria sarà : $\overline x=48.23$ 

La notazione che useremo sarà : 
+ $\overline X$ è la variabile casuale media campionaria ( è uno *stimatore* di $\mu$ )
+ $\overline x$ è il particolare valore osservato della media campionaria nel campione ( è una *stima* di $\mu$ ) 

Sia la stima che lo stimatore è rappresentato dal simbolo $\hat\theta$ , siccome $\hat\theta$ ( stima ) è calcolata su un campione della popolazione difficilmente sarà uguale al valore di popolazione $\theta$ 

Se il campione è ben costruito allora al crescere di $n$ lo stimatore $\hat\theta$ convergerà a $\theta$ 
##### Distorsione

Uno *stimatore* $\hat\theta$ è *non distorto* se :
$$E[\ \hat\theta\ ]=\theta$$
per tutti i possibili valori di $\theta$  

La distorsione di $\hat\theta$ è :
$$Bias(\hat\theta)=E(\hat\theta)-\theta$$
Uno stimatore non distorto è uno stimatore *corretto* in media se in media non sottostima o svrastima il parametro 

La *media campionaria* è uno *stimatore non distorto* della media di popolazione , questo può essere dimostrato nel seguente modo : 
$$E(\overline X)=E\Bigg(\frac 1n \sum_{i=1}^n X_i\Bigg)=\frac 1n \sum_{i=1}^n E(X_i)=\frac 1n \sum_{i=1}^n \mu = \mu$$
##### Consistenza

Uno stimatore $\hat\theta$ è *consistente* se al crescere della dimensione campionaria $n$ il suo errore campionario converge a zero :
$$Probailità(|\hat\theta-\theta|>\epsilon)\rightarrow 0$$
Ossia la probabilità che la *distorsione* di $\hat\theta$ sia maggiore di un certo $\epsilon>0$ per $n\rightarrow \infty$ tende a $0$

Questo si può scrivere nel seguente modo ( *convergenza in probabilità* ) :
$$\hat\theta\stackrel{p}\rightarrow\theta, \quad \text{per}\ n\rightarrow \infty$$
>[!assioma]
>La media campionaria è uno *stimatore consistente* della media di popolazione 

Questo poichè la *legge dei grandi numeri* ci assicura che ( solo per campionamenti casuali ) : 
$$\overline X \stackrel{p}\rightarrow\mu, \quad \text{per} \ n\rightarrow \infty$$
La *consistenza* di $\overline X$ può essere verificata anche attraverso la *disuguaglianza di Chebyshev*
$$Probabilità(|\overline X -\mu|>\epsilon)\le \frac{Var(\overline X)}{\epsilon^2}$$
$$Var(\overline X)=Var\Bigg(\frac1n \sum_{i=1}^nX_i\Bigg)=\frac1{n^2}\sum_{i=1}^nVar(X_i)=\frac{\sigma^2}n$$
Sostituendo avremo quindi che : 
$$Probabilità(|\overline X -\mu|>\epsilon)\le \frac{\sigma^2/n}{\epsilon^2}\rightarrow 0 , \quad \text{per} \ n\rightarrow \infty$$

###### Consistenza di stimatori distorti

La *consistenza* non richiede che lo stimatore sia *non distorto*

Risulta essere sufficente che lo *stimatore* sia :
+ *asintoticamente non distorto* :
$$Bias(\hat\theta)=E(\hat\theta)-\theta \rightarrow 0, \quad \text{per} \ n\rightarrow \infty $$
+ con *varianza che svanisce asintoticamente* :
$$Var(\hat\theta)\rightarrow 0,\quad \text{per} \ n\rightarrow \infty $$
Se valgono queste due propietà asintotiche allora lo stimatore $\hat\theta$ converge in *media quadratica* a $\theta$ , la *convergenza* in media quadratica implica la convergenza in probabilità

#### Normalità asintotica

Il *teroma del limite centrali* assicura che :
$$Z = \frac{\sqrt{n}(\overline X - \mu)}\sigma \stackrel{d}\rightarrow N(0,1), \quad \text{per}\ n\rightarrow \infty$$
( *convergenza a distribuzione* )
Oppure informalmente : 
$$\overline X\sim N\bigg(\mu , \frac{\sigma^2}{n}\bigg) \quad \ \text{per $n$ sufficentemente grande} $$
>[!note]
>Lo stimatore $\overline \mu = \overline X$ è approssimativamente distribuito come una variabile casuale normale al crescere della dimesione del campione

Più in generale uno stimatore $\hat\theta$ la cui distribuzione al crescere di $n$ è via via meglio approssimata da una distribuzione normale si dice *asintoticamente normale*

La normalità asintotica ci dice che : 
+ al crescere di $n$ è improbabile osservare valori $\overline x$ che distano da $\mu$
+ è altrettanto probabile osservare valori che distano da $\mu$ di almeno una certa quantità in positivo o in negativo
##### Valori anormali

La *media* ha il difetto di essere *sensibile* ad osservazioni estreme

Se modifichiamo solo un dato su 30 dei tempi di elaborazione in modo estremo a 30 minuti la media campionaria passa da 48.23 a 105.9 secondi 

>[!warning]
>Non è chiaramente accettabile che uno stimatore diepnde così tanto da poche osservazioni estreme 
#### Mediana

La *mediana campionaria* stima la mediana di popolazione 

La mediana è una misura di posizione molto meno sensibile alle osservazioni estreme rispetto alla media 

La *mediana di popolazione* $M$ suddivide la distribuzione della variabile casuale $X$ in due parti uguali ovvero : 
$$Probabilità(X>M)\le 0.5 \quad \text{e} \quad Probabilità(X<M)\le 0.5$$
La *mediana campionaria* $\hat M$ è :
+ inferiore al più a metà dei dati campionari e
+ superiore al più a metà dei dati campionari
##### Asimmetrie

La relazione tra media e mediana determina la forma di una distribuzione :
+ *distribuzione simmetrica* : $M=\mu$
+ *asimmetria destra* :           $M<\mu$
+ *asimmetria sinistra* :         $M>\mu$

![[Pasted image 20240218155336.png]]
##### Calcolo della mediana di popolazione

Nel caso di **distribuzioni continue** la mediana si ottiene risolvendo l'equazione : $F(M)=Probabilità(X\le M)=0.5$

![[Pasted image 20240218155440.png]]

Nel caso di **distribuzioni discrete** l'equazione $F(M)=0.5$ :
+ ha un intervallo di valori come soluzione , oppure
+ non ha nessuna soluzione

![[Pasted image 20240218155639.png]]

##### Calcolo della mediana campionatoria 

Si ordinano le osservazioni del campione dalla più piccola alla più grande , quindi : 
+ Se $n$ è *dispari* allora $\hat M$ è l'osservazione del campione ordinato in posizione $(n+1)/2$ 
+ Se $n$ è *pari* allora $\hat M$ è un *qualsiasi* valore nell'intervallo fra le osservazioni di posizione $n/2$ e $(n+2)/2$ ( per semplicità si scieglie l'esatta metà )

Anch'essa come la mediana di popolazione è meno sensibile alle osservazioni estreme
#### Quantili, percentili e quartili

Il **quantile** di ordine $p$ è il numero $x$ tale che :
$$Probabilià(X<x)\le p \quad \text{e} \quad Probabilià(X>x)\le 1-p$$
Il **quantile campionario** di ordine $p$ è :
+ maggiore al più del $100\cdot p \%$ delle osservazioni e
+ minore al più del $100\cdot (1-p) \%$ delle osservazioni

Il **percentile** di ordine $\gamma$ corrisponde al *quantile* di ordine $0.01 \cdot \gamma$ ( divide la distribuzione in multipli di $0.01$ )

Il **quartile** divide la distribuzione in in quattro parti : primo , secondo e terzo *quartile* che corrispondono al 25-esimo , 50-esimo e 75-esimo *percentile* ( la mediana coincide con il *quantile* di ordine $0.5$ , il 50-esimo *percentile* , il secondo *quartile* ) 

Per trovare un *quartile* ci sono diversi metodi uno di questi è calcolare $n\cdot p$ ed utilizzare come valore l'elemento trovato o per eccesso oppure il valore a metà 
>[!example]
>Troviamo il *quartile* $p=0.25$ nell'esempio precedente dei tempi di esecuzione ; avremo $n\cdot p=0.25\cdot30=7.5$ quindi prenderemo come valore l'ottavo oppure calcoliamo il valore che si trova a metà tra il settimo e l'ottavo 

Un'altro è trovare la mediana della metà corrispondente al quantile del campione
#### Varianza e deviazione standard campionarie

>[!important]
>La **varianza campionaria** è definita nel seguente modo : 
$$S^2=\frac 1 {n-1}\sum_{i=1}^n(X_i-\overline X)^2$$

Dove le quantità $X_i-\overline X$ sono dette *scarti dalla media* ( distanza dalla media )

La *varianza campionaria* misura la dispersione attorno alla media campionatoria 

La *varianza campionaria* è uno stimatore della varianza di popolazione $\sigma^2 =Var(X)$ 

>[!note]
>La varianza campionaria non può essere :
>$$\frac1n \sum_{i=1}^n(X_i-\overline X)$$
>Poichè questo darebbe come risultato sempre 0 :
>$$\frac1n \sum_{i=1}^n(X_i-\overline X)=\frac1n\sum_{i=1}^nX_i-\frac1n\sum_{i=1}^n\overline X=\overline X - \frac1n n\cdot \overline X = \overline X -\overline X =0$$

>[!important]
>La **deviazione standard campionaria** è la radice quadrata della varianza campionaria : 
>$$S=\sqrt {S^2}$$

Se stiamo considerando un'unità di misura per i nostri dati allora la *deviazione standard* è la scielta migliore per rappresentare la vairazione dei dati poichè possiede la stessa unità di misura dei dati

Un'altra misura che rappresenta la varianza di un insieme di dati è la *deviazione media assoluta* ( *DMA* ) che ha la seguente formula : 
$$\frac1n \sum_{i=1}^n(|X_i-\overline X|)$$
Questa viene spesso utilizzata quando lo *scarto dalla media* è molto grande , altrimenti infatti la *varianza* è ancora più sensibile della *media* ai valori anomali in quanto questa eleva gli scarti alla seconda e quindi valori estremi vengono amplificati 

##### Calcolo della varianza campionaria

La varianza può essere calcolata con la formula : 
$$S^2=\frac 1{n-1}\bigg(\sum_{i=1}^n X^2_i-n\overline X^2\bigg)$$
Ossia : $E[X^2]-E[X]^2$ approssimativamente ( per grandi valori di $n$ )
##### Proprietà della varianza campionaria

Per assicurare la **non distorsione** della varianza campionaria il coefficente deve essere $\frac 1{n-1}$
>[!todo]
>Questo deve essere poichè la somma degli scarti dalla media deve essere sempre 0 quindi l'ultimo elemento è già determinato ed avremo quindi solo $n-1$ elementi "liberi" nel campione
>*ricontrolla spiegazione!!!!!!!!*

Si dice spesso infatti che : 
+ $S^2$ sia la *varianza campionaria corretta*
+ $\widetilde S^2$ = $\frac{n-1}n S^2$ la *varianza campionaria*

Si può vedere che $\widetilde S^2$ è *distorto* poichè se abbiamo che $E[S^2]=\sigma^2$ allora avremo che $E[\widetilde S^2]=\frac{n-1}n \sigma^2 < \sigma^2$ possiamo anche notare che $E[\widetilde S^2]$ sottostima $E[S^2]$

Si può comunque notare che la distorsione svanisce asintoticamente infatti : 
$$\lim_{n\rightarrow \infty} \frac{n-1}n \to 1 \quad \text{questo ci porta a dire che : }\quad S^2\sim \widetilde S^2$$

La varianza campionaria ( $S^2$ ) è inoltre uno stimatore **consistente** di $\sigma^2$ 
$$S^2\stackrel{p}\to \sigma^2 \quad \text{per} \ n\to\infty$$
La varianza campionaria ( $S^2$ ) è anche uno stimatore **asintoticamente normale** 
$$S^2\stackrel{d}\to N\{ \sigma^2,Var(S^2) \}, \quad \text{per} \ n \to\infty$$
### Trasformazioni

 Una traformazione è l'applicazione di una funzione $g()$ ad una variabile casuale $X$ , di seguito abbiamo varie proprietà :
 + *valore atteso* : 
	 $$E\{ g(X) \}\neq g\{ E(X) \}$$
	 L'uguaglianza vale solo se $g()$ è una funzione lineare ( es $aX+b$ )
+ *convergenza in probabilità* : 
	$$\text{Se}\quad X\stackrel{p}\to \theta \implies g(X)\stackrel{p}\to g(\theta)$$
	Questo vale solo se $g()$ è continua ( esempio vale con $\sqrt{\dots}$ )
+ *normalità asintotica*
	$$\text{Se} \quad X \stackrel{d}\to N(\theta,\psi^2) \implies g(X)\stackrel{d}\to N(g(\theta),g'(\theta)^2\psi^2)$$
	Questo vale solo se $g'(\theta)$ esiste e non è nulla 
### Deviazione standard campionaria

La *deviazione standard* $S$ è una funzione di $S^2$ : 
$$S=g(S^2), \quad \text{con} \ g(\dots)=\sqrt\dots$$
Usando le propietà delle trasformazioni possiamo dire che : 
+ $S$ è uno *stimatore* distorto di $\sigma$ infatti :
$$\sqrt{E(S^2)}\neq E(\sqrt{S^2})\implies \sigma \neq E(S)$$
	Quindi sappiamo che :
	$$Bias(S)=E(S)-\sigma\neq0$$
>[!note]
>$S$ divente *non distorto* asintoticamente
+ $S$ è uno *stimatore* consistente di $\sigma$ ( per la seconda regola delle trasformazioni ) 
$$S\stackrel{p}\to\sigma, \quad \text{per} \ n\to \infty$$
+ $S$ è uno stimatore asintoticamente normale
$$S\stackrel{d}\to N\bigg(\sigma , \frac{1}{4\sigma^2}Var(S^2)\bigg),\quad \text{per}\ n\to\infty$$
>[!todo]
>spiega
### Errore standard

La qualità di uno *stimatore* si misura anche in termini della sua variabilità , questa corrisponde alla *deviazione standard* dello stimatore
$$SE(\hat\theta)=SD(\hat\theta)$$
Dove : 
+ $SE$ : standard error
+ $SD$ : standard deviation

*Stimatori* molto variabili portano a stime che differiscono fra loro eccessivamente in campioni differenti 

Anche l'*errore standard* può dipendere dai parametri della popolazione e quindi anchesso deve essere stimato
#### Errore standard della media campionaria

L'*errore standard* dello stimatore media campionaria è ( con la deviazione standard non stimata ) :
$$SE(\hat\mu)=SE(\overline X)=\frac{\sigma}{\sqrt n}$$
$SE(\hat\mu)$ viene *stimato* con la deviazione standard campionaria ( stimata ) : 
$$\widehat{SE}(\hat\mu)=\frac{S}{\sqrt n}$$
Le proprietà delle *trasformazioni* ci dicono che $\widehat{SE}(\hat\mu)$ è uno stimatore di $SE(\hat\mu)$ con le seguenti caratteristiche : 
+ asintoticamente non distorto
+ consistente
+ asintoticamente normale
### Precisione e Accuratezza

La qualità di uno stimatore viene valutata in termini di :
+ *accuratezza* :
	Uno stimatore è tanto più accurato quanto meno è distorto
+ *precisione* : 
	Uno stimatore è tanto più preciso quanto meno è variabile

Le misure di *accuratezza* e *precisione* sono combinate nell'*errore quadratico medio* ( mean square error ) : 
$$MSE(\hat\theta)=E[(\hat\theta-\theta)^2]$$
Aggiungo e sottraggo $E(\hat\theta)$
$$=E[(\hat\theta-E(\hat\theta)+E(\hat\theta)-\theta)^2]$$
Sviluppiamo il quadrato
$$=E[(\hat\theta-E(\hat\theta))^2]+2\cdot E[\hat\theta-E(\hat\theta)]\cdot [E(\hat\theta)-\theta]+E[(E(\hat\theta)-\theta)^2]$$
Visto che il valore medio del valore medio è sempre il valore medio originale abbiamo : 
$$=E[(\hat\theta-E(\hat\theta))^2]+2\cdot E[\hat\theta-E(\hat\theta)]\cdot [E(\hat\theta)-\theta]+(E(\hat\theta)-\theta)^2$$
Ora possiamo trovare che il doppio prodotto può essere eliminato attraverso i seguenti passaggi : 
$$2\cdot E[\hat\theta-E(\hat\theta)]\cdot Bias(\hat\theta)$$
$$2\cdot [E(\hat\theta)-E(\hat\theta)]\cdot Bias(\hat\theta) = 2\cdot [\ 0\ ]\cdot Bias(\hat\theta) =0 $$
Possiamo quindi concludere che :  
$$=E[(\hat\theta-E(\hat\theta))^2]+[E(\hat\theta)-\theta]^2\implies Var(\hat\theta)+Bias(\hat\theta)^2$$
>[!note]
>Osservando che $$E(\hat\theta)-\theta=Bias\implies [E(\hat\theta)-\theta]^2= Bias^2$$ e $$E[(\hat\theta-E(\hat\theta))^2]= E\left[ \hat\theta^2 - 2\hat\theta E(\hat\theta) + E(\hat\theta)^2 \right]=$$
>$$=E(\hat\theta^2) - 2E(\hat\theta)E(\hat\theta) +E(E(\hat\theta)^2)=E(\hat\theta^2) - 2(E(\hat\theta))^2 + (E(\hat\theta))^2=$$
>$$=E(\hat\theta^2) - (E(\hat\theta))^2=Var$$

>[!note]
>Se la *precisione* aumenta allora miniuisce l'*accuratezza* e viceversa
>Di solito si preferisce uno stimatore più *preciso* ( ossia cambia poco tra un nuovo insieme di dati ed un'altro )
### Confronto fra stimatori

La scelta fra due o più *stimatori* è basata sulle loro proprietà :
+ Se entrambi gli *stimatori* sono non distorti si preferirà quello con la varianza inferiore
+ Se invece uno o entrambi sono distorti allora spesso si scieglie lo stimatore con l'*errore quadratico medio* ( *MSE* ) inferiore 
>[!warning]
>Uno stimatore con errore quadratico medio basso ma con distorsione rilevante ( e che non converge a 0 o non con la giusta velocità ) in molti problemi è considerato *inaccettablie* 

### Intervallo Interquartile

La *varianza* è una misura della varaibilità molto sensibile alle osservazioni estreme

Una misura di variabilità meno sensibile alle osservazioni estreme è data dallo *scarto interquartile* ( *interquartile range* ) :
$$IQR=Q_3-Q_1$$
Dove $Q_1$ e $Q_3$ indicano il primo e il terzo quartile 
Questa misura rappresenta il 50% della distribuzione ( il *core* ) ossia le parti più caratteristiche 

![[Quantile.excalidraw]]

Se la mediana rappresenta bene i nostri dati allora mi aspetto che lo scarto interquartile sia piccolo , questo ci indica che i valori della distribuzione sono molto compatti attorno alla mediana ( la mediana è precisa )

**Intervallo Interquartile Campionario**

$$\widehat {IQR}=\hat Q_3-\hat Q_1$$
Dove $\hat Q_1$ e $\hat Q_3$ sono il primo e terzo quartile campionario

### Valori anomali

I valori *anomali* ( outliers ) sono le osservazioni che sono :
+ inferiori a $\hat Q_1 -1.5\cdot\widehat{IQR}$
+ superiori a $\hat Q_3 +1.5\cdot\widehat{IQR}$

Questi limiti vengono utilizzati poichè se i dati fossero normalmente distribuiti allora meno del $1\%$ delle osservazioni possono essere così esterne da non rispettarli 

>[!example]
>Per l'esempio dei tempi di elaborazione abbimao che : 
>+ Limite inferiore : $-3.5$ ( essendo che stiamo parlando di tempi questo significa che il limite inferore è in realtà 0 )