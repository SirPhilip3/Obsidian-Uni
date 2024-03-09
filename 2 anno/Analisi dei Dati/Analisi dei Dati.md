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
>+ Limite superiore : $96.5$ ( il valore $139$ è un *outlier* )
>>[!note]
>>Generalmente i tempi non seguono una distribuzione normale ( spesso esponenziale o gamma ) e quindi la probabilità $<1\%$ potrebbe non essere veritiera 

#### Azioni contro i valori anomali

Una volta individuato un valore anomalo è importante capire cosa lo rende *estremo* rispetto agli altri

I valori anomali vengono rimossi dal dataset se :
+ corrispondono ad errori ( di trascrizione , di misurazione etcc... )
+ corrispondono ad osservazioni che provengono da un'altra popolazione
	![[DoublePopulation.excalidraw]]

Se non si rientra in questi due casi bisogna studiare gli *outlier* e comprendere se è necessario il proprio modello statistico o no

### Analisi grafiche

I grafici possono essere utilizzati per individuare : 
+ un modello probabilistico per descrivere i dati
+ un motodo statistico per analizzare i dati
+ osservazioni *anomale* ( *outliers* )
+ fonti di eterogeneità ( i dati hanno *non* una varianza costante ) ( *omoschedasticità* è il contrario )
+ particolari *andamenti* ( *patterns* ) o *tendenze* ( *trend* )
+ relazioni fra due o più variabili

Ci sono tre tipi di grafici di base : 
+ *istogrammi*
+ *grafici a scatola*
+ *grafici a dispersione*
### Istogrammi

Gli istogrammi servono per visualizzare la *forma di una distribuzione* , questi sono costruiti da un insieme di rettangoli *adiacenti*

>[!note]
>Se non sono adiacenti allora si parla di grafico a barre 

I rettangoli si cotruiscono dividendo il campo di variazione dei dati ( *range* ) in intervalli ( *bins* ) e contando l'altezza è caratterizzata dal numero di osservazioni che "cadono" in ciascun intervallo

Gli istogrammi ( con intervalli della stessa ampiezza ) si suddividono in due categorie : 
+ *istrogrammi di frequenza* : se l'altezza dei rettangoli corrisponde al numero di osservazioni in ciascun intervallo
+ *istogrammi di frequenza relativa* : se l'altezza dei rettangoli corrisponde alla proporzione di osservazioni in ciascun intervallo ( $\frac{osservazioni}{n}$ )

>[!example]
>![[Pasted image 20240222161040.png]]

#### Interpretazione

Nel caso di osservazioni che provengono da variabili continue , al crescere della dimensione campionaria gli istogrammi convergeranno alla funzione di densità della variabile

>[!example]
>![[Pasted image 20240222161018.png]]

#### Scelta degli intervalli

La scelta degli intervalli è fondamentale nella costruzione dell'istogramma , infatti una cattiva scelta degli intervalli potrebbe non permettere di apprendere nulla circa la distribuzione dei dati

![[Pasted image 20240222161533.png]]

I software statistici implementano regole automatiche per il calcolo del numero *ottimale* di intervalli di un istogramma in modo che sia semplice individuare la forma di una distribuzione e individuare i valori *anomali*

>[!note]
>In ogni caso all'aumentare della dimensione campionaria il numero di intervalli dovrebbe sempre aumentare

### Grafici a Scatola ( con i baffi )

Il grafico a scatola con i baffi ( *box and whiskers plot* o *boxplot* ) è la più efficace rappresentazione grafica di dati numerici

Il *boxplot* è costruito con :
+ il minimo
+ il primo quantile
+ la mediana
+ il terzo quartile
+ il massimo

La scatola contiene l'$IQR$ 
I baffi si estendono dalla scatola al minimo e massimo ( sempre che non siano anomalmente distanti dal centro della distribuzione )
>[!note]
>Il minimo e il massimo possono non essere $Q_1-1.5\cdot IQR$ e $Q_3+1.5\cdot IQR$ se vi sono dei dati che rappresentano un minimo o massimo immediatamente minore
>>[!example] 
>>Nel nostro esempio dei tempi di CPU si prende il valore più vicino infatti abbiamo che : 
>>$max = 59+1.5\cdot (59-34)=96,5$
>>Sappiamo quindi che $139$ è l'unico possibile *outlier* e quindi prenderemo come massimo $89$ ossia il secondo valore più grande 
>>Per il minimo invece sappiamo che non vi sono sicuramete valori $\le -3.5$ e quindi prendiamo come minimo il valore minimo presente nei nostri dati
>>![[Pasted image 20240222163129.png]]  

Le osservazioni anomale sono indicate con dei punti oltre i baffi

![[Pasted image 20240222162153.png]]

#### Boxplot appaiati

I *boxplot* appaiati si utilizzano per confrontare diverse popolazioni o sottopopolazioni

![[Pasted image 20240222163241.png]]
### Grafici a dispersione

I grafici a dispersione sono utilizzati per rappresentare la relazione tra due variabili casuali 

>[!example]
>Prendiamo il numero di scansioni svolte da un programma antivirus durante un mese ( $X$ ) e il numero di worms rilevati ( $Y$ )
>![[Pasted image 20240222164617.png]]
>Queste due variabili possono essere messe in relazione tra di loro
>![[Pasted image 20240222164118.png]]
>Ogni pallino rappresenta un tot di occorrenze di quella coppia di valori all'interno dei dati , per discriminare per quantità tra questi valori si può assegnare al numero di occorrenze una lettera dell'alfabeto che andrà a sostituire il pallino corrispondente nel grafico
>![[Pasted image 20240222164312.png]]

>[!note]
>Vi sono altre soluzioni per rappresentare il numero di volte che occorre una coppia di valori all'interno dei dati :
>+ Aumentare le dimensioni del punto a seconda del numero di occorrenze
>+ Aggiungere più punti ( il numero di occorrenze ) vicino al punto originale distanziati da un errore randomizzato

>[!todo]
>jitter plot
>#todo
# Stima

## Modelli statistici 

Supponiamo che i dati $x=(x_1,\dots,x_n)$ provengano da una variabile casuale la cui distribuzione *dipende* ( si dice che *indicizza* un *modello statistico* ) da un parametro ignoto $\theta$ ( appatenente allo *spazio parametrico* $\Theta \subset \mathbb{R}^k$ , dove $k$ indica ....................) 
>[!todo]
>Spiega + Understand 
>#todo

Il *modello statistico* è : 
+ Nel caso *discreto* una classe di *funzione di probabilità* $Pr(x;\theta)$ 
+ Nel caso *continuo* una classe di *densità* $f(x;\theta)$

>[!note]
>Esistono modelli che hanno componenti sia discreti che continui
### Metodo dei momenti

Questo risulta esser il metodo più semplice per stimare il parametro ( $\theta$ ) di un modello statistico

Costruiamo uno stimatore di $\theta$ confrontando : 
+ I *momenti di popolazione* :
	+ I momenti teorici del modello statistico
+ I *momenti campionari* :
	+ I momenti che caratterizzano i dati osservati ( le osservazioni )

#### Momenti

>[!important]
>Un **momento** rappresenta una misura numerica che fornisce informazioni sulla forma e distribuzione di una variabile casuale

>[!note]
>$k$ rappresenta l'ordine del momento , per esempio la media e mediana hanno come ordine 1 , mentre la varianza ha ordine 2 
>>[!todo]
>>Understand
>>#todo

Il $k$-esimo *momento di popolazione* è : 
$$\mu_k=E(X^k)$$
Il $k$-esimo *momento campionario* è :
$$M_k=\frac 1 n\sum_{i=1}^n X_i^k \quad (M_1 = \overline X\ )$$
con *valore* osservato : 
$$m_k=\frac 1 n \sum_{i=1}^n x_i^k \quad (m_1 = \overline x\ )$$

>[!note]
>+ $M_k$ è uno *stimatore* di $\mu_k$
>+ $m_k$ è una *stima* di $\mu_k$

#### Momenti centrali

>[!important]
>Il **momento centrale** rappresenta una misura numerica che fornisce informazioni sulla dipersione o forma di una distribuzione di probablità rispetto alla sua media

Il $k$-esimo *momento centrale di popolazione* è :
$$\mu_k' = E(X-\mu)^k$$
Il $k$-esimo *momento centrale campionatorio* è : 
$$M_k' = \frac 1n \sum_{i=1}^n(X_i-\overline X)^k$$
>[!example]
>Se abbiamo $k=2$ questo rappresenterà la varianza che però deve essere resa non distorta : 
>$$M_2' = S^2(n-1)/n$$

con *valore* osservato :
$$m_k'=\frac 1 n \sum_{i=1}^n(x_i-\overline x)^k \quad (\ m_2' = s^2(n-1)/n\ )$$
>[!note]
>+ $M_k'$ è uno *stimatore* di $\mu_k'$
>+ $m_k'$ è una *stima* di $\mu_k'$

#### Metodo dei momenti

Per *stimare* il parametro $\theta$ si risolve il sistema di $k$ equazioni ottenuto uguagliando i $k$ mommenti di popolazione ai rispettivi $k$ momenti campionari

>[!todo]
>Understand
>#todo

$$\begin{cases} \mu_1(\theta) & = M_1 \\ \mu_2(\theta) & = M_2 \\ \dots \ & = \dots \\ \mu_k(\theta) & = M_k\end{cases}$$
A seconda dei casi di utilizzano i momenti 'semplici' oppure i momenti centrali , è possibile cambiare alcuni momenti semplici con altri centrali se risulta conveniente

>[!example]
>Osserviamo l'istogramma realizzato dai tempi di elaborazione della CPU
>![[Pasted image 20240305204621.png]]
>Possiamo osservare che rappresenta *approssimativamente* un funzione gamma : 
>$$f(x; \alpha,\lambda)=\frac{\lambda^\alpha}{\Gamma(\alpha)}x^{\alpha -1}e^{-\lambda x}, \quad x>0$$
>Dove $\Gamma(.)$ è la funzione gamma
>Il parametro $\theta = (\alpha , \lambda)$ dove  :
>+ $\alpha>0$ è detto parametro di forma
>+ $\lambda>0$ è detto parametro di frequenza 
>Spazio parametrico : $\Theta \in \mathbb{R}_+ \times \mathbb{R}_+$ dove $\mathbb{R}_+$ sono numeri reali positivi
>Notiamo che il parametro di forma $\alpha$ cambia di fatto la forma dellàcurva avremo infatti che : 
>![[Pasted image 20240305205727.png]]
>Svolgiamo quindi la stima dei parametri della funzione gamma attraverso il *metodo dei momenti* 
>Dai dati abbiamo che : 
>+ il valore atteso $m_1 = \overline X = 48.2333$
>+ la varianza $m_2' = S^2=679.7122$ 
>Possiamo ora scrivere le due equazioni :
>$$\begin{cases}\mu_1 = E(X) = \alpha / \lambda = m_1 \\ \mu_2' = Var(X) = \alpha / \lambda^2 = m_2' \end{cases}$$
>Utilizziamo il *secondo momento centrale* poichè sappiamo già l'espressione per la varianza di una variabile *Gamma*
>Risolviamo il sistema in modo da trovare $\alpha$ e $\lambda$ 
>$$\begin{cases} \frac{\alpha}{\lambda} = 48.2333 \\ \frac{\alpha}{\lambda^2} = 679.7122 \end{cases}$$
>$$\begin{cases}\alpha = 3.4227 \\ \lambda = 0.0710 \end{cases}$$
### Metodo della massima verosimiglianza

Lo stimatore di massima verosimiglianza è quel valore del parametro $\theta$ che massimizza la *funzione di verosimiglianza*

La *funzione di verosimiglianza* è proporzionale $\propto$ alla probabilità di osservare ciò che è stato effettivamente osservato 

Nel *caso discreto* la funzione di verosimiglianza è quindi proporzionalèalla funzione di probabilità congiunta dei dati 
$$L(\theta) \propto Pr(X_1=x_1,\dots,X_n=x_n;\theta)$$
Che per un campione casuale semplice diventa : 
$$L(\theta)\propto \prod_{i=1}^nPr(X_i=x_i; \theta)$$
>[!example]
>Una software house dichiara che l'accuratezza del riconoscimento facciale è dell'80% 
>Un blogger afferma dichiara che l'accuratezza è invece 70% 
>In un esperimento su 15 volti 11 vengono riconosciuti correttamente 
>
> Indichiamo con $\theta$ la "vera" proporzione di fotografie in cui si riconosce correttamente il volto
> 1. Individuiamo un modello statistico che potrebbe generare questo tipo di dati 
> 	In questo caso sembra essere il *binomiale* perchè ad ogni tentativo ci sono 2 possibili risultati : riconoscimento corretto o no ( possiamo rappresentarlo come estraiamo o no )
> 2. La *verosimiglianza* per $\theta$ è quindi *proporzionale* alla probabilità di osservare 11 successi su 15 prove in un modello binomiale con probabilità di successo $\theta$ :
> $$L(\theta)= \binom {15} {11} \theta^{11} (1-\theta)^4$$
> 
> Supponiamo che abbia ragione la software house allora avremo $\theta=0.8$ e potremmo quindi calcolare la verosimiglianza nel seguente modo : 
> $$L(0.8) = \binom{15}{11}0.8^{11}0.2^4 = 0.19$$
> ![[Pasted image 20240306124547.png]]
> Supponiamo che abbia ragione il blogger allora avremo $\theta=0.7$ e potremmo quindi calcolare la verosimiglianza nel seguente modo : 
> $$L(0.7) = \binom{15}{11}0.7^{11}0.3^4 = 0.22$$
> ![[Pasted image 20240306124557.png]]
>Ora essendo che la verosimiglianza calcolata per il blogger è maggore di quella per la software house il *nostro* esperimento si accorda maggiormente con quello del blogger 
>Possiamo inoltre calcolare il rapporto con il quale preferiamo il valore del blogger nel seguente modo : 
>$$\frac{L(0.7)}{L(0.8)}=\frac{\binom{15}{11}0.7^{11}0.3^4 }{ \binom{15}{11}0.8^{11}0.2^4}= 1.17$$
>Ciò ci porta ad affermare che alla luce del nostro esperimento il valore di $\theta$ del blogger è più verosimile per il $17\%$
>>[!note]
>>I fattori binomiali possono essere eliminati , possiamo quindi rimuovere i termini costanti dal calcolo della verosimiglianza
>>$$L(\theta)=\theta^{11}(1-\theta)^4$$ 

#### Log.verosimiglianza

La *log-verosimiglianza* è definita come : 
$$l(\theta)=\log L(\theta)$$
>[!note]
>Siccome $\log$ è una funzione crescente massimizzare $L(\theta)$ o $l(\theta)$ è equivalente 

Questo viene fatto poichè fare la derivata ( per trovare il massimo ) delle somme è più facile di fare la derivata dei prodotti

>[!note]
>Se massimizzassimo senza log i numeri potrebbero assumere valori molto piccoli e il computer che esegue i calcoli potrebbe andare in underflow

Nel caso *discreto* la *log-verosimiglianza* è : 
$$l(\theta)=\sum_{i=1}^n \log Pr(X_i=x_i; \theta)$$
>[!example]
>9.7 baron

#### Il caso continuo

Nel caso continuo la probabilità di osservare esattamente un certo valore $x$ è $Pr(X=x)=0$ 
Dobbiamo quindi trovare la probabilità per un valore piccolo di $h$ : 
$$Pr(x-h < X < x+h) = \int_{x-h}^{x+h} f(x; \theta) dx \approx 2h\cdot f(x; \theta)$$
![[Pasted image 20240307140449.png]]

Nel caso continuo il metodo della massima verosimiglianza massimizza la probabilità di osservare dei valori *vicini* a ciò che è stato effettivamente osservato
$$L(\theta)\propto f(x_1, \dots, x_n; \theta)$$
Nel caso di un campione casuale ( *i.i.d.* ) abbiamo ( il $2h$ può essere tolto poichè costante ) : 
$$L(\theta)\propto \prod_{i=1}^n f(x_i; \theta)$$ 
La corrispondente *log-verosimiglianza* è ( a meno di termini costanti che vengono eliminati ) ( il $2h$ può essere tolto poichè costante ) : 
$$l(\theta) = \sum_{i=1}^n \log f(x_i; \theta)$$
>[!example]
>9.8 baron

#### Problemi regolari di stima 

Lo stimatore di *massima verosimiglianza* gode di proprietà che valgono solo sotto delle *oppurtune assunzioni di regolarità* 

Una di queste assunzioni di regolarità è che stiamo lavorando con un *problema di stima regolare* 

Possiamo verificare che siamo in un problema di stima regolare se il *supporto* delle variabili casuali non dipenda dal parametro del modello 
Le altre assunzioni richiedono che la funzione di probabilità ( caso discreto ) o di densità ( caso continuo ) del modello sia *sufficente regolare* , in particolare la funzione di probabilità o densità deve essere continua e derivabile per almeno 3 volte ( fino all'ordine 3 ) ( questo perchè necessitieremo di calcolare lo sviluppo di Taylor fino all'ordine 3 )

>[!example]
>Esempi di *problemi regolari di stima* sono stimare :
>+ I parametri $\mu$ e $\sigma^2$ di una variabile casuale *Normale*
>+ Il parametro $\lambda$ di una variabile casuale di *Poisson*
>+ Il parametro $p$ di una variabile casuale *Binomiale*
>
>Un esempio di *problema non regolare di stima* :
>	Stimare il parametro $\theta$ di una variabile uniforme nell'intervallo $[\ 0,\theta\ ]$ , ossia dipende dal parametro stesso

##### Verosimiglianza e problemi regolari di stima

Nei problemi regolari di stima le *stimatore di massima verosimiglianza* si trova ispezionando le derivate prime e seconde della *(log-)verosimiglianza* 

La derivata prima della log-verosimiglianza si chiama *funzione punteggio* ( score function ) 

I punti stazionari della verosimiglianza sono gli zeri della *funzione punteggio* cioè i punti $\overline \theta$ che risolvono l'equazione di verosimiglianza : 
$$\frac {d}{d\theta}l(\overline \theta)=0$$
Un punto stazionario di $l(\theta)$ è un massimo locale se la derivata seconda calcolata in quel punto è negativa : 
$$\frac {d^2}{d\theta^2}l(\overline \theta)<0$$

##### Esempio di problema regolare di stima

Consideriamo un campione casuale semplice dalla variabile casuale con densità : 
$$f(x;\beta\ ) = \begin{cases} \frac{\beta}{x^{\beta+1}} & \text{se} \ x>1, \beta >1 \\ 0 & \text{altrimenti} \end{cases}$$
>[!todo]
>#todo
##### Esempio di problema non regolare di stima

Consideriamo un campione casuale semplice dalla variabile casuale con densità $U(0,\theta)$ ovvero : 
$$f(x;\theta)=\begin{cases} \frac1 \theta & \text{se}\ x\in [0,\theta] \\ 0 & \text{altrimenti} \end{cases}$$
La verosimiglianza di $\theta$ è : 
$$L(\theta) = \begin{cases} \frac{1}{\theta^n} & \text{se} \ 0 \le X_i \le \theta \ \text{per ogni} \ i \\ 0 & \text{altrimenti} \end{cases}$$
Ovvero : 
	$$L(\theta) = \begin{cases} \frac{1}{\theta^n} & \text{se} \ \max_i X_i \le \theta \ \text{e} \  \min_i X_i \ge 0 \\ 0 & \text{altrimenti} \end{cases}$$