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
$$SE(\hat\mu)=SE(\overline X)=\frac{\sigma}{\sqrt n} = \sqrt{\frac{Var(X_1)}{n}}$$
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
A seconda dei casi di utilizzano i momenti 'semplici' oppure i momenti centrali , è possibile cambiare  alcuni momenti semplici con altri centrali se risulta conveniente

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
>Notiamo che il parametro di forma $\alpha$ cambia di fatto la forma della curva avremo infatti che : 
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

Nel *caso discreto* la funzione di verosimiglianza è quindi proporzionale alla funzione di probabilità congiunta dei dati 
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
La verosimiglianza per $\beta$ è : 
$$L(\beta) = \beta^n \prod_{i=1}^n X_i^{-(\beta+1)}$$
La log-verosimiglianza è ( a meno di termini costanti )
$$l(\beta) = n\log (\beta) - \beta \sum_{i=1}^n \log X_i$$
L'equazioni di verosimiglianza è : 
$$\frac n \beta - \sum_{i=1}^n \log X_i = 0$$
La sua soluzione è :
$$\hat\beta = \frac{n}{\sum_{i=1}^n \log X_i}$$
Questo coincide con lo stimatore di massima verosimiglianza poichè : 
$$l''(\beta)= -\frac n {\beta^2} < 0$$
##### Esempio di problema non regolare di stima

Consideriamo un campione casuale semplice dalla variabile casuale con densità $U(0,\theta)$ ovvero : 
$$f(x;\theta)=\begin{cases} \frac1 \theta & \text{se}\ x\in [0,\theta] \\ 0 & \text{altrimenti} \end{cases}$$
La verosimiglianza di $\theta$ è : 
$$L(\theta) = \begin{cases} \frac{1}{\theta^n} & \text{se} \ 0 \le X_i \le \theta \ \text{per ogni} \ i \\ 0 & \text{altrimenti} \end{cases}$$
Ovvero : 
$$L(\theta) = \begin{cases} \frac{1}{\theta^n} & \text{se} \ \max_i X_i \le \theta \ \text{e} \  \min_i X_i \ge 0 \\ 0 & \text{altrimenti} \end{cases}$$

>[!example]
>Facciamo un esempio con un ipotetico dataset di 50 osservazioni in cui il massimo delle osservazioni vale 5
>![[Pasted image 20240309172938.png]]
>Lo stimatore di massima verosimiglianza è $\hat\theta = \max_i X_i$
>
>Il massimo di $L(\theta)$ non può essere trovato tramite differenziazione perchè si trova in un punto di discontinuità

#### Errori Standard 

Gli errori standard servono a misurare la *precisione* degli stimatori 
+ L'*accuratezza* è il concetto opposto alla distorsione
+ La *precisione* è il concetto opposto alla variabilità 
##### Stimare gli errori standard

Gli errori standard spesso sono funzione del parametro stesso e quindi vanno a loro volta stimati

>[!example]
>9.11 baron

Stimare gli errori standard può essere complicato anche per in modelli semplici

>[!example]
>9.12 baron

##### Proprietà asintotiche dello stimatore di massima verosimiglianza

Sotto *assunzioni* che valgono nei problemi che affronteremo ( **non è necessario conoscerle** ) lo stimatore di massima verosimiglianza è : 
+ *asintoticamente non distorto* :
	$E(\hat\theta)\to \theta,$   per $n\to \infty$ 
+ *consistente*
	$\hat\theta \stackrel{p}\to \theta$  per $n\to\infty$
+ *asintoticamente normale* con distribuzione limite : $$\hat\theta \approx N\{\theta, I(\theta)^{-1}\} \quad \text{per n sufficentemente grande}$$
  Dove $I(\theta)$ è l'*informazione attesa di Fisher* ( corrisponde alla *varianza* )

###### Informazione Attesa di Fisher

L'*informazione attesa* è definita come : 
$$I(\theta)=E\bigg\{ -\frac{d^2}{d\theta^2} l(\theta) \bigg\}$$
Sostiutuendo $l(\theta)$ con la *log-verosimiglianza* avremo : 
$$=E\bigg\{  -\frac{d^2}{d\theta^2} \sum_{i=1}^n \log f(X_i; \theta) \bigg\}$$
$$=\sum_{i=1}^nE\bigg\{  -\frac{d^2}{d\theta^2} \log f(X_i; \theta) \bigg\}$$
Nel caso di un *campione casuale semplice* abbiamo :
$$I(\theta)=n\cdot E\bigg\{  -\frac{d^2}{d\theta^2} \log f(X_1; \theta) \bigg\}$$
Cioè l'informazione del campione è pari a $n$ volte l'informazione contenuta un una singola osservazione
###### Informazione attesa e osservata

L'*informazione osservata* è definita come :
$$J(\theta) = - l''(\theta) = \sum_{i=1}^n \left\{ -\frac{d^2}{d\theta^2} \log f(X_i; \theta) \right\}$$
Per la *Legge dei grandi numeri* avremo che , per $n \to \infty$ : 
$$\frac{J(\theta)}{n}\stackrel{p}\to E\{ g(X_1) \} = E\left\{ - \frac{d^2}{d\theta^2}\log f(X_1; \theta) \right\}$$
Ovvero $J(\theta) \approx I(\theta)$ per $n$ sufficentemente grandi 

##### Errore standard dello stimatore di massima verosimiglianza

Sappiamo che per campioni sufficentemente grandi e modelli che modelli che rispettino le assunzioni di regolarità avremo che lo *stimatore* sarà : 
$$\hat\theta\approx N\{\theta, I(\theta)^{-1}\}$$
Quindi l'*errore standard* dello stimatore di massima verosimiglianza $\hat\theta$ è asintoticamente pari a : 
$$SE(\hat\theta)\approx I(\theta)^{-1/2}$$
Per un $n$ sufficentemente grande 

Ma visto che non sappiamo $\theta$ dovremmo stimarlo , avremo quindi che la *stima* dell'errore standard di $\hat\theta$ è : 
$$\widehat{SE}(\hat\theta)=I(\hat\theta)^{-1/2}$$
Oppure visto che sappiamo che $J(\theta) \approx I(\theta)$ potremmo anche scrivere : 
$$\widehat{SE}(\hat\theta)=J(\hat\theta)^{-1/2}$$

>[!note]
>Si preferisce la stima con $J$ poichè riflette l'informazione effettivamente contenuta nei dati

##### Efficenza

Lo stimatore di *massima verosimiglianza* gode di una proprietà importante di ottimalità 

La *diseguaglianza di Cramèr-Rao* identifica il limite inferiore della *varianza* di uno stimatore $\hat\theta$  *non distorto* di $\theta$ in : 
$$Var(\hat\theta)\ge I(\theta)^{-1}$$
dove $I(\theta)$ è l'*informazione attesa di Fisher*

Uno stimatore non distorto la cui varianza raggiunge il limite di Cramèr-Rao e detto *efficiente*

Visto che la *varianza* dello stimatore di massima verosimiglianza raggiunge questo valore abbiamo che è *asintoticamente efficente*

>[!example]
>Consideriamo un campione casuale semplice da una variabile di Poisson di parametro $\lambda$
>
>Lo stimatore $\hat\lambda =\overline X$ è uno stimatore efficente di $\lambda$
>
>Infatti la varianza di $\hat\lambda$ è : 
>$$Var(\hat\lambda) = Var(\overline X) = \frac{Var(X_1)}{n}=\frac\lambda n$$
>
>Verifichiamo che questo soddifa il limite di Cramèr-Rao
>
>Avremo che la *log-verosimiglianza* per $\lambda$ è :
>$$l(\lambda)=-n\lambda + \log \lambda \sum_{i=1}^n X_i$$
>
>Troviamo quindi le due derivate : 
>$$l'(\lambda)=-n + \frac{\sum_{i=1}^nX_i}{\lambda}$$
>$$l''(\lambda)= -\frac{\sum_{i=1}^n X_i}{\lambda^2}$$
>
>L'*informazione attesa* sarà : 
>$$I(\lambda)=E\{-l''(\lambda)\}=E\left(\frac{\sum_{i=1}{n}X_i}{\lambdaì2}\right)=\frac{1}{\lambda^2}\sum_{i=1}^n E(X_i)=\frac{n\lambda}{\lambda^2}=\frac n \lambda$$
>
>La cui inversa è la varianza di $\hat\lambda$

###### Caso di studio

**Disastro Challenger**

Disatro causato dal danneggiamento di una coppia di o-ring presenti in un *SRB* , questo fu dovuto al fatto che gli o-ring erano stati progettati per funzionare a temperature non inferiori a $11°C$  mentre quel giorni si raggiunsero i $-8°C$ la notte ed ala momento del lancio vi erano $-0.5°C$ 

Cerchiamo di stimare la probabilità che si verificasse un cedimento dei 2 o-ring data la temperatura , abbiamo a disposizione i seguenti dati : 

| Flight | Number of o-rings with damages $r$ | Temperature ( $°F$ ) |
| ------ | ---------------------------------- | -------------------- |
| 1      | 0                                  | 66                   |
| 2      | 1                                  | 70                   |
| 3      | 0                                  | 69                   |
| 5      | 0                                  | 68                   |
| 6      | 0                                  | 67                   |
| 7      | 0                                  | 72                   |
| 8      | 0                                  | 73                   |
| 9      | 0                                  | 70                   |
| 41-B   | 1                                  | 57                   |
| 41-C   | 1                                  | 63                   |
| 41-D   | 1                                  | 70                   |
| 41-G   | 0                                  | 78                   |
| 51-A   | 0                                  | 67                   |
| 51-C   | 2                                  | 53                   |
| 51-D   | 0                                  | 67                   |
| 51-B   | 0                                  | 75                   |
| 51-G   | 0                                  | 70                   |
| 51-F   | 0                                  | 81                   |
| 51-I   | 0                                  | 76                   |
| 51-J   | 0                                  | 79                   |
| 61-A   | 2                                  | 75                   |
| 61-B   | 0                                  | 76                   |
| 61-C   | 1                                  | 58                   |
| 61-I   | —                                  | 31                   |
**Modelliamo i dati** : 

Dobbiamo specificare un *modello statistico* che usi l'informazione dei precedenti 23 lanci per prevedere quello che sarebbe successo quel giorno 

Vogliamo specificare un modello che descriva la variabile casuale : 
$$Y = '\text{cedimento di almeno un o-ring}'$$
In funzione della temperatura $x$ il giorno del lancio

Notiamo che $Y_1, \dots ,Y_{23}$ sono varaibili casuali di *Bernuolli* ossia : 
	$Y_i$ è pari a 0 se gli o-ring dell'$i$-esimo lancio sono intatti , $1$ invece se almeno un o-ring cede

>[!note]
>Le variabili $Y_1, \dots ,Y_{23}$ non sono identicamente distribuite poichè vogliamo valutare se la probabilità che un o-ring ceda dipenda dalla temperatura 
>$$Y_i \sim Ber(p_i), \quad p_i = Pr(Y_i = 1|x_I), \quad i = 1,\dots,23$$
>
>dove $p_i = g(x_i)$ è una funzione della temperatura
>

Come scegliamo la funzione $g$ ? 
	Potremmo considerare qualsiasi funzione che vada da $\mathbb{R}$ ( la temperatura ) a $[0,1]$ ( probabilità di cedimento dell'o-ring )

Tra le scelte per $g:\mathbb{R}\to[0,1]$ quella più usata è la funzione *logisitica inversa*  
$$g(z)=\text{invlogit}(z) = \frac{e^z}{1+e^z}$$
![[Pasted image 20240314144854.png]]

Consideriamo un *modello di regressione logistica* che collega la probabilità di cedimento di un o-ring alle variazioni della temperatura

>[!note]
>Il parametro del modello statistico è costituito da due componenti : $\theta = (\alpha,\beta)$

Avremo quindi le due probabilità legate al cedimento degli o-ring descritte nel seguente modo : 
$$Pr(Y_i=1|x_i)=\frac{e^{\alpha+\beta\ x_i}}{1+e^{\alpha+\beta\ x_i}}$$
$$Pr(Y_i=0|x_i)=\frac{1}{1+e^{\alpha+\beta\ x_i}}$$
>[!note]
>Le due probabilità sono state trovate considerando la seguente espressione : 
>$$Pr(Y_i=1|x_i)+Pr(Y_i=0|x_i)=1$$

Il parametro di interesse è $\beta$ : 
+ se $\beta = 0$ allora la temperatura non ha alcun effetto sul *rischio* di cedimento di un o-ring
+ se $\beta\neq 0$ allora la temperatura ha effetto sul rischio
+ valori negativi di $\beta$ indicano che il *rischio cresce* quando la temperatura scende
  
Troviamo la *verosimiglianza* basata sui dati : 
$$L(\alpha,\beta)=\prod_{i=1}^n Pr(Y_i=1)^{y_i}Pr(Y_i=0)^{1-y_i}$$
>[!note]
>perchè utilizziamo Pr*Pr

$$=\left( \frac{1}{1+e^{\alpha+66\beta}} \right)\times\left( \frac{e^{\alpha+70\beta}}{1+e^{\alpha+70\beta}} \right)\times\dots\times \left( \frac{e^{\alpha+58\beta}}{1+e^{\alpha+58\beta}} \right)$$
Le stime di *massima verosimigilianza* sono calcolate numericamente : $\hat\alpha = 15.04$ e $\hat\beta = -0.23$

**Interpretiamo ora i dati** : 

Il modello stiamto è : 
$$Pr(\text{cedimento o-ring alla temp x}) = \frac{e^{15.04-0.23\ x}}{1+e^{15.04-0.23 \ x}}$$
Calcoliamo quindi la probabilità con $x=31°F$ :
$$\frac{e^{15.04-0.23\cdot 31}}{1+e^{15.04-0.23 \cdot 31}}=0.9996$$
![[Pasted image 20240314155131.png]]

>[!warning]
>Non possiamo fare un'estrapolazione così estrema dei dati poichè non abbiamo dati che riguardano temperature inferiori a $53°F$ che sono molto lontani dai $31$ di cui vogliamo trovare la probabilità

>[!note]
>Rimane una chiara indicazione che il rischio di rotture degli o-ring quel giorno era inaccettabile

##### Esempio

Consideriamo un campione casuale semplice da una variabile casuale *Bernulliana* di parametro $p$ 

Avremo quindi che : 
$$Pr(X_1=x_1) = p^{x_1}\cdot(1-p)^{1-x_1}$$
La *verosimiglianza* sarà quindi : 
$$L(p)=\prod_{i=1}^n p^{x_i} \cdot(1-p)^{1-x_i}$$
La *log-verosimiglianza* per $p$ sarà :
$$l(p)=\sum_{i=1}^n\left[ x_i\log p+(1-x_i)\log(1-p)\right]$$
$$l(p)=\log p \sum_{i=1}^n X_i + \log(1-n)\left( n -\sum_{i=1}^nX_i\right)$$
Poichè : $$\sum_{i=1}^n(1-x_i) = \sum_{i=1}^n 1 - \sum_{i=1}^n x_i=n-\sum_{i=1}^nx_i$$
Troviamo ora la funzione punteggio : 
$$l'(p)=\frac{\sum_{i=1}^n X_i}{p}-\frac{n-\sum_{i=1}^nX_i}{1-p}$$
Risolvendo $l'(p)=0$ troveremo lo stimatore di *massima verosimiglianza* : 
$$\frac{(1-p)\sum_{i=1}^nX_i -np + p\sum_{i=1}^n X_i}{1-p}=0$$
Ci interessa mettere $=0$ solamente al numeratore : 
$$\sum_{i=1}^nX_i - p\sum_{i=1}^nX_i - np + p \sum_{i=1}^nX_i = 0$$
$$\sum_{i=1}^nX_i -np = 0$$
$$p=\frac{\sum_{i=1}^nX_i}{n}$$
Ossia visto che sappiamo che $\overline X= \frac{\sum_{i=1}^nX_i}{n}$ avremo che : 
$$p = \overline X$$
Visto che non sappiamo il vero valore di $p$ passiamo alla stima : 
$$\hat p = \overline X$$
>[!warning]
>Per verificare che effettivamente questo è uno stimatore di *massima verosimiglianza* dobbiamo calcolare la derivata seconda : 
>$$l''(p)=-\frac{\sum_{i=1}^n X_i}{p^2} - \frac{n-\sum_{i=1}^n X_i}{(1-p)^2}$$
>Ora questo deve essere $<0$ per avere lo stimatore di *massima verosimiglianza* , notiamo che i fattori moltiplicativi sono sempre $<0$ poichè hanno il segno $-$ davanti mentre la prima sommatoria rappresenta la somma di valori che possono essere o $0$ o $1$ , sarà quindi sicuramente positiva ; mentre il secondo fattore moltiplicativo sappiamo che la sommatoria è sicuramente $\le n$ avremo quindi che la sottrazione $x - \sum$ sarà sicurmanete $\ge 0$  

Calcoliamo ora l'errore standard di $\hat p$ : 
	Sfruttiamo il fatto che sappiamo che la *varianza* di una variabile bernulliana è : $p(1-p)$
	$$SE(\hat p) = \sqrt{Var(\hat p)} = \sqrt{\frac{Var(X_1)}{n}}=\sqrt{\frac{p\cdot (1-p)}{n}}$$
	Che *stimato* diventa 
$$\widehat {SE}(\hat p) = \sqrt{\frac{\hat p\cdot(1-\hat p)}{n}}$$ 
Possiamo ricavare $\widehat{SE}$ anche attraverso l'*informazione attesa* o l'*informazione osservata* : 

>[!note] Attraverso l'informazione osservata
>Sappiamo che $J(p)=-l''(p)$ , sarà quindi facile calcolarla sfruttando ciò che abbiamo precedentemente calcolato :
>$$J(p)=\frac{\sum_{i=1}^n X_i}{p^2}+\frac{n-\sum_{i=1}^n X_i}{(1-p^2)}$$
>Sappiamo inoltre che $\widehat{SE} = J(\hat p)^{-1/2}$ che ci dice che :
>$$\widehat{SE}=\left( \frac{\sum_{i=1}^n X_i}{p^2}+\frac{n-\sum_{i=1}^n X_i}{(1-p^2)} \right)^{-1/2}$$
>Siccome $\hat p = \overline X$ segue che $\sum_{i=1}^n X_i = n \hat p$ e quindi 
>$$\widehat {SE}(\hat p) = \left( \frac{n\hat p}{\hat p^2} + \frac{n - n\hat p}{(1-\hat p )^2} \right)^{-1/2}$$
>$$\left( \frac{n}{\hat p} + \frac{n}{(1-\hat p)} \right)^{-1/2}$$
>$$\sqrt{\frac{\hat p(1-\hat p)}{n}}$$

>[!note] Attraverso l'informazione attesa
>Sappiamo che $I(p)=E\{ J(p) \}$ 
>$$=E\left( \frac{\sum_{i=1}^n X_i}{p^2} \right) + E\left( \frac{n-\sum_{i=1}^n X_i}{(1-p)^2} \right)$$
>$$=\left( \frac{\sum_{i=1}^n E(X_i)}{p^2} \right) + \left( \frac{n-\sum_{i=1}^n E(X_i)}{(1-p)^2} \right)$$
>Visto che sappiamo che la bernulliana ha $E[X]=p$ possiamo sostituire : 
>$$=\left( \frac{\sum_{i=1}^n p}{p^2} \right) + \left( \frac{n-\sum_{i=1}^n p}{(1-p)^2} \right)$$
>$$=\left( \frac{n\cdot p}{p^2} \right) + \left( \frac{n-n\cdot p}{(1-p)^2} \right)$$
>$$=\left( \frac{n}{p} \right) + \left( \frac{n}{1-p} \right)$$
>$$=\frac{n}{p(1-p)}$$
>
>Quindi abbiamo che l'erroe standard limite di $\hat p$ è 
>$$\widehat{SE}(\hat p)=I(\hat p)^{-1/2}=\sqrt{\frac{\hat p(1-\hat p)}n}$$

>[!warning]
>In generale le stime dell'errore standard basate su $I$ e $J$ coincidono ma in generale le due stime sono diverse
#### Invarianza

Se $\hat\theta$ è lo *stimatore di massima verosimiglianza* di $\theta$ allora $g(\hat\theta)$ è lo *stimatore di massima verosimiglianza* di $\psi = g(\theta)$

>[!example]
>Supponiamo che il numero di utenti che si collegano ad un server in un istante di tempo si distribuisca come una variabile di Poisson di parametro $\lambda$
>La stima di massima verosimiglianza di $\lambda$ è $\hat\lambda = \overline X$ 
>Ci interessa stimare la probabilità che il numero di utenti superi un certo critico $c$
>Il *parametro di interesse* diventa quindi : $\psi = Pr(X>c) = 1- F(c)$
>Dove $F(c)$ è la funzione di ripartizione di una variabile di Poisson
>
>La proprietà dell'invarianza dice che lo stimatore di massima verosimiglianza di $\psi$ è : 
>$$\hat \psi = 1-\hat F(c)$$ 
>( ricordandoci che $F(c)$ è in funzione di $\lambda$ )
>
>Supponiamo di avere un $c=75$
>In un campione casuale di $25$ istanti di tempo è stato osservato $\overline x = 62.7$
>
>La stima di massima verosimiglianza dunque è : $\hat \lambda = 62.7$
>La stima di massima verosimiglianza di $\psi$ è : 
>$$\hat \psi = 1-\sum_{x=0}^{75} \frac{e^{-62.7}(62.7)^x}{x!}$$
>Oppure con R : 
>`{r} 1- ppois(75,lambda = 62.7)`

#### Parametro multivalore

Nella gran parte dei casi reali la dimensione del parametro è maggiore di uno : 
$$\theta = \left( \matrix{\theta_1 \\ \vdots \\ \theta_k}\right)$$
Possiamo estendere i risultati ottenuti finora ad un vettore di parametri , infatti : 

Lo *stimatore* di $\theta$ è un vettore causale : 
$$\hat\theta = \left( \matrix{\hat\theta_1 \\ \vdots \\\hat \theta_k}\right)$$
In cui ogni componente $\hat\theta_r\ (r=1,\dots,k)$ è una variabile casuale

I *momenti* di $\hat\theta$ sono : 
1. Il *vettore di valori attesi* : 
	$$\mu = \left( \matrix{\mu_1 \\ \vdots \\ \mu_k}\right)$$
	Con $\mu_r = E(\hat\theta_r), \ r=1,\dots,k$
2. La *matrice di varianze e covarianze*
	$$\sum = \left( \matrix{\sigma_1^2 &\sigma_{12} & \dots &\sigma_{1k}\\ \vdots & \vdots & \ddots & \vdots \\ \sigma_{k1} & \sigma_{k2}& \dots& \sigma_k^2 } \right)$$
	Dove $\sigma_{rs} = Cov(\hat\theta_r , \hat\theta_s)$ e $\sigma_r^2 = \sigma_{rr}$ con $r,s=1,\dots,k$

##### Stimatore di massima verosimiglianza

Nei problemi di stima regolari lo *stimatore di massima verosimiglianza* si ottiene risolvendo le equazioni di verosimiglianza : 
$$\begin{cases}  \frac{dl(\theta)}{d\theta_1} = 0 \\ \vdots \\ \frac{d l(\theta)}{d\theta_k} = 0\end{cases}$$
La soluzione è lo stimatore di massima verosimiglianza se la *matrice Hessiana* delle derivate  seconde 
$$\left(\matrix{\frac{d^2 l(\theta)}{d \theta^2_1} & \frac{d^2 l(\theta)}{d \theta_1 d\theta_2} & \dots & \frac{d^2 l(\theta)}{d \theta_1 d\theta_k} \\ \vdots & \vdots & \ddots & \vdots  \\ \frac{d^2 l(\theta)}{d \theta_k d\theta_1} & \frac{d^2 l(\theta)}{d \theta_k d\theta_2} & \dots & \frac{d^2 l(\theta)}{d \theta_k^2}}\right)$$
è definita negativa 

Nei problemi regolari di stima lo stimatore di massima verosimiglianza ha come distribuzione limite la *normale multivariata* di dimensione $k$  : 
$$\hat \theta \approx MVN_k(\theta.I(\theta)^{-1})\quad \text{per $n$ sufficentemente grande}$$
dove $I(\theta)$ è la *matrice dell'informazione attesa* 
$$\hat\theta \approx MVN_k(\theta,J(\theta)^{-1})\quad \text{per $n$ sufficentemente grande}$$
dove $J(\theta)$ è la *matrice dell'informazione osservata*

La matrice dell'*informazione attesa* è $I(\theta) = E\{J(\theta)\}$ con :

$$J(\theta)=\left(\matrix{-\frac{d^2 l(\theta)}{d \theta^2_1} & -\frac{d^2 l(\theta)}{d \theta_1 d\theta_2} & \dots & -\frac{d^2 l(\theta)}{d \theta_1 d\theta_k} \\ \vdots & \vdots & \ddots & \vdots  \\ -\frac{d^2 l(\theta)}{d \theta_k d\theta_1} & -\frac{d^2 l(\theta)}{d \theta_k d\theta_2} & \dots & -\frac{d^2 l(\theta)}{d \theta_k^2}}\right)$$

>[!todo]
>distribuzione normale multivariata
>>[!note]
>>non verrà chiesta all'esame
>#todo

# Stima Intervallare

Quando otteniamo una *stima* $\hat{\theta}$ sappiamo che questà sarà quasi sicuramente diversa dal vero valore del parametro $\theta$ a causa dell'*errore campionario* 

- Quando possiamo credere alla nostra *stima* $\hat\theta$ ?
- Quanto può essere distante la *stima* dal vero valore del parametro ?
- Se otteniamo una certa stima $\hat\theta$ quali sono i valori plausibili per $\theta$

Queste domande sono risposte attraverso gli *intervalli di confidenza*

## Intervalli di confidenza 

Un intervallo $[A,B]$ è detto *intervallo di confidenza* per $\theta$ di *livello* $(1-\alpha)100\%$ se contiene il parametro con probablità $(1-\alpha)$ :
$$\Pr(A\le \theta \le B) = 1- \alpha$$
>[!note] 
>La *probabiltà di copertura* dell'intervallo $(1-\alpha)$ viene detta anche *livello di confidenza* 

>[!warning] 
>$\theta$ rappresenta un numero 
>Gli estremi $A$ e $B$ dipendono dai dati e quindi sono quantità *casuali* , potremmo quindi riscrivere la *probabilità di copertura* nel seguente modo : $[A(X_1,\dots,X_n),B(X_1,\dots,X_n)]$
>
>>[!note] 
>>Possiamo quindi notare che l'intervallo varia al variare del campione 
>>Ci aspettiamo che $(1-\alpha)100\%$ degli intervalli contengano $\theta$

>[!example] 
![[Pasted image 20240328152003.png]]

>[!warning] 
>Non possiamo dire che se abbiamo calcolato un intervallo di confidenza di livello $90\%$ e abbiamo un intervallo $[2,5]$ allora $\theta$ appartiene a questo intervallo con probabilità $90\%$
>
>Il livello di confidenza dell'intervallo indica che $\theta$ appartiene al $90\%$ degli intervalli che possiamo calcolare con campioni diversi ( ottenuti con la stessa regola di campionamento e con la stessa dimensione )

### Costruzione di un intervallo di confidenza

Il metodo più semplice per costruire un *intervallo di confidenza* $[A,B]$ con livello di confidenza $(1-\alpha)$ richiede uno stimatore $\hat\theta$ :
+ *non distorto* : $E(\hat\theta) = \theta$
+ *con distribuzione normale* : $N\{\theta, Var(\hat\theta)\}$

In questo caso costruiremo l'*intervallo di confidenza* a partire dallo stimatore *standardizzato* 
$$Z = \frac{\hat{\theta}-\theta}{SE(\hat{\theta})}$$
Che si distribuisce come una variabile casuale *normale standard* $N(0,1)$ ( $Z$ verrà chiamata *statistica Z* )

Dobbiamo trovare i quantili della distribuzione normale standard che identificano un'area di ampiezza pari a $(1-\alpha)$ 

![[Pasted image 20240328161333.png]]

$z_{\alpha/2}$ è tale che $Pr(Z > z_{\alpha/2}) = \alpha/2$ ossia il quantile di posizione $(1-\alpha /2)$ della distribuzione normale standard
$$\Pr \Bigg\{ - z_{\alpha/2} \le \frac{\hat{\theta}-\theta}{SE(\hat{\theta})} \le z_{\alpha/2} \Bigg\}=1-\alpha$$
Ossia : 
$$\Pr \{ \hat\theta - z_{\alpha/2} SE(\hat{\theta})\le \theta \le \hat\theta + z_{\alpha/2} SE(\hat{\theta})\}=1-\alpha$$
Possiamo quindi scrivere che : 
$$A = \hat\theta - z_{\alpha/2}SE(\hat{\theta} \ )$$
$$B = \hat\theta + z_{\alpha/2}SE(\hat{\theta} \ )$$
>[!note] 
>Si tratta di un intervallo centrato in $\hat\theta$ con *margine di errore* pari a $z_{\alpha/2} SE(\hat\theta)$

### Intervallo di confidenza per la media di una popolazione

Avendo un campione casuale semplice da una popolazione con media $\mu$ e varianza $\sigma^2$ che assumiamo nota

Consideriamo lo stimatore non distorto $\hat\mu = \bar X$ 

Quando possiamo usare la statistica $Z$ ? : 
+ Se $X_1,\dots,X_n$ sono normali , allora $\hat\mu = \bar X$ è *normale*
+ Se $X_1,\dots,X_n$ non sono normali ma $n$ è *grande* allora $\hat\mu=\bar{X}$ è approssimativemente normale ( per il teorema del limite centrale )

L'errore standard sarà quindi $SE(\hat\mu) = \sigma / \sqrt{n}$  

L'intervallo di confidenza sarà quindi : 
$$\bar{X}\pm z_{\alpha/2} \frac{\sigma}{\sqrt{n}}$$
Il quantile $z_{\alpha/2}$ necessario per il caclolo degli intervalli di confidenza può essere ottenuto con il seguente comando , con $\alpha = 0.05$ : 
```r
qnorm(1-0.05/2)  ->  1.959964
```

>[!example] 
>Esempio 9.13 baron

### Quando non possiamo usare la statistica $Z$

Non possiamo usare la *statistica* $Z$ quando : 
+ $X_1,\dots,X_n$ *non* sono *normali* e $n$ è *piccolo* 

>[!note] 
>Campioni piccoli appaiono in problemi anche molto rilevanti 

**Soluzioni** : 
+ Metodi che dipendono dal problema specifico 
+ Approssimazioni che funzionano anche per valori di $n$ piccoli ( utilizziamo metodi asintotici di ordine superiore )

### Intervallo di confidenza per la differenza di due medie

Campioni casuali semplici da due popolazioni : 
+ $X_1,\dots,X_n$ con media $\mu_X$ e varianza nota $\sigma_X^2$
+ $Y_1,\dots,Y_m$ con media $\mu_Y$ e varianza nota $\sigma_Y^2$ 

Calcoliamo unintervallo di confidenza per 
$$\theta = \mu_X -\mu_Y$$
**Assunzioni** : 
+ I due campioni sono indipendenti
+ Le osservazioni sono normalmente distribuite oppure le numerosità dei due campioni $n$ e $m$ sono grandi 

Uno stimatore non distorto di $\theta$ è 
$$\hat\theta = \bar{X} - \bar{Y}$$
L'*errore standard* dello stimatore è : 
$$SE(\hat{\theta}) = \sqrt{Var(\hat{\theta})}$$
$$=\sqrt{Var(\bar X)+Var(\bar Y)}$$
$$=\sqrt{\frac{\sigma^2_X}{n}+\frac{\sigma_Y^2}{m}}$$
L'intervallo di confidenza è 
$$\hat{\theta}\pm z_{\alpha/2}SE(\hat{\theta})$$
Ossia : 
$$(\bar X-\bar Y)\pm z_{\alpha/2}\sqrt{\frac{\sigma^2_X}{n}+\frac{\sigma_Y^2}{m}}$$
>[!example] 
>Esempio 9.14 baron

>[!note] 
>Se ho valori sia positivi che negativi $[-0.3,0.4]$ nell'intervallo di confidenza non possiamo essere sicuri che ci sia una vera differenza significativa tra le due medie ( non possiamo escludere che la media sia la stessa ad un livello di confidenza $\alpha$ )

### Dimensione campionaria 

Gli intervalli di confidenza hanno la seguente forma simmetrica : 
$$\text{stimatore} \pm \text{margine d'errore}$$
Quanto deve essere grande il campione per garantire una data precisione al nostro stimatore ?

Ossia quanto deve valere $n$ affinchè il margine di errore sia inferiore ad un dato valore $\Delta$ , dobbiamo quindi risolvere la seguente diseguaglianza rispetto alla numerosità campionaria $n$ : 
$$\text{mergine d'errore} \le \Delta$$
Il margine d'errore è : $z_{\alpha/2} \frac{\sigma}{\sqrt{n}}$
Quindi dobbiamo risolvere la diseguaglianza : 
$$z_{\alpha/2} \frac{\sigma}{\sqrt{n}} \le \Delta$$
Otteniamo quinidi : 
$$n\ge \bigg( \frac{z_{\alpha/2}\cdot \sigma}{\Delta} \bigg)^2$$
>[!note] 
>Visto che $n$ è un numero intero allora la minima dimensione campionaria che assicura la precisione desiderata sarà il più piccolo intero che soddisfa la diseguaglianza

>[!example] 
>Esempio 9.15 Baron

### Deviazione standard ignota

Per calcolare un intervallo di confidenza per la media $\mu$ *assumiamo* che $\sigma^2$ sia noto , questa assunzione è ragionevole solo in alcuni casi : 
+ quando abbiamo un'ampia informazione da studi precedenti 
+ i dati sono misurazioni ottenute da strumenti con precisione nota

Spesso $\sigma^2$ non è noto e quindi dovremmo stimarlo con i dati 

In questi casi si dice che : 
+ $\mu$ è il *parametro di interesse*
+ $\sigma^2$ è il *paramtero di disturbo*

Possiamo avere tre casi possibili : 
1. Campioni di grandi dimensioni da qualsiasi distribuzione
2. Campioni di qualsiasi dimensione di distribuzione normale
3. Campioni di piccola dimensione da una distribuzione non normale

#### Campioni di grandi dimensioni

Se il campione ha *grandi dimensioni* allora ci aspettiamo che lo stimatore dell'errore standard $\widehat{SE}(\hat{\theta})$ sia *ragionevolmente* vicino al vero errore standard ( $SE(\theta)$ )

Possiamo allora calcolare un intervallo di confidenza di *livello approssimato* $1-\alpha$ con la statistica $\mathbb{Z}$
$$\hat{\theta}\pm z_{\alpha/2} \widehat{SE}(\hat{\theta})$$

Nel caso della media di una popolazione avremo : 
$$\hat{\mu}\pm z_{\alpha/2} \frac{\hat\sigma}{\sqrt{n}}$$
Ovvero 
$$\overline{X}\pm z_{\alpha/2}\frac{\hat S}{\sqrt{n}}$$
Se abbiamo la differenza di due medie : 
$$\hat\mu_x-\hat\mu_y \pm z_{\alpha/2} \sqrt{\frac{\hat\sigma^2_x}{n}+\frac{\hat\sigma^2_y}{m}}$$
Ovvero 
$$\bar X-\bar X \pm z_{\alpha/2} \sqrt{\frac{S^2_x}{n}+\frac{ S^2_y}{m}}$$
>[!example] 
>Esempio 9.16 baron

#### Intervalli di confidenza per le proporzioni

Quando dobbiamo stimare una *proporzione campionaria* non conosciamo la deviazione standard

Supponiamo che siamo interessati alla *sottopopolazione* che possiede un certo attributo A

Definiamo la *proporzione della popolazione* con l'attributo A come :
$$p=Pr(\text{possedere l'attributo A})$$
La corrispondente *proporzione campionaria* è : 
$$\hat p = \frac{n_A}{n}$$
con $n_A$ il numero di unità con l'attributo A

Possiamo riformulare il problema con le variabili indicatrici :
$$X_i = \begin{cases}
1  & \text{se l'unità $i$ possiede  l'attributo A}\\ 0 & \text{se l'unità $i$ non possiede l'attributo A}
\end{cases}$$
$X_i$ diventa quiondi una variabile *Bernulliana* con parametro $p$ :
	$E(X_i)=p$ e $Var(X_i)=p(1-p)$ 

Lo stimatore $\hat{p}$ sarà quindi la media campionaria : 
$$\hat p = \bar X = \frac{1}{n}\sum^{n}_{i=1}X_i$$
con $E(\hat{p}) = p$ e $Var(\hat{p}) = \frac{p(1-p)}{n}$ 

Quindi lo *stimatore* $\hat{p}$ è quindi : 
+ *non distorto* 
+ *asintoticamente normale* 

Per $n$ abbastanza grande la distribuzione di $\hat p$ è *approssimativamente* pari a :
$$N\bigg(p,\frac{p(1-p)}{n}\bigg)$$
L'*errore standard* di $\hat{p}$ stimato sarà quindi : 
$$\sqrt{\frac{\hat{p}(1-\hat{p})}{n}}=\sqrt{\frac{\bar X(1-\bar X)}{n}}$$
L'intervallo di confidenza per $p$ con livello di confidenza approssimativamente pari a $1-\alpha$ è 
$$\hat{p}\pm z_{\alpha/2} \sqrt{\frac{\hat{p}(1-\hat{p})}{n}} \quad\text{ovvero} \quad \bar{X}\pm z_{\alpha/2} \sqrt{\frac{\bar{X}(1-\bar{X})}{n}}$$

#### Intervalli di confidenza per la differenza di due proporzioni

Supponiamo di avere due popolazioni *indipendenti* di dimensioni $n_1$ e $n_2$ 

Vogliamo valutare in quale delle due popolazioni un certo attributo sia più frequente 

Possiamo costruire un *intervallo di confidenza* per la differenza della proporzione di unità con l'attributo : 
$$\theta= p_1 - p_2$$ 
Lo stimatore di $\theta$ è la differenza delle proporzioni campionarie 
$$\hat{\theta} = \hat{p_1}-\hat{p_2}$$
L'*errore standard* di $\hat{\theta}$ è :
$$SE(\hat{\theta}) = \sqrt{\frac{p_1(1-p_1)}{n_1}+\frac{p_2(1-p_2)}{n_2}}$$
L'*errore standard stimato* è quindi :
$$\widehat{SE}(\hat{\theta}) = \sqrt{\frac{\hat p_1(1-\hat p_1)}{n_1}+\frac{\hat p_2(1-\hat p_2)}{n_2}}$$
L'intervallo di confidenza con livello di confidenza approssimativamente pari a $(1-\alpha)$ è :
$$\hat{p}_1-\hat{p}_2 \pm z_{\alpha/2}\sqrt{\frac{\hat p_1(1-\hat p_1)}{n_1}+\frac{\hat p_2(1-\hat p_2)}{n_2}}$$
>[!example] 
>Esempio 9.17 Baron

#### Stimare proporzioni con una precisione prefissata

Il margine d'errore nell'intervallo di confidenza per una proporzione è :
$$\text{margine d'errore} = z_{\alpha/2}\sqrt{\frac{\hat{p}(1-\hat{p})}{n}}$$
La dimensione campionaria che assicura che *margine d'errore* $\le \Delta$ è pari a : 
$$n\ge \hat{p}(1-\hat{p})\bigg(\frac{z_{\alpha/2}}{\Delta}\bigg)^2$$
>[!warning] 
>Quests diseguaglianza però coinvolge $\hat{p}$ che non è nota prima della raccolta del campione

Possiamo risolvere il problema notando che il valore massiamo di $\hat{p}(1-\hat{p})$ è $0.25$ che si ottiene con $\hat{p} = 0.5$ 

![[Pasted image 20240419172815.png]]

Possiamo quindi sostituire $\hat{p}(1-\hat{p})$ con $0.25$ per ottenere la dimensione campionaria :
$$n\ge 0.25 \bigg(\frac{z_{\alpha/2}}{\Delta}\bigg)^2$$
che assicura che il margine d'errore sai inferiore a $\Delta$ ( per qualunque $\hat{p}$ )

#### Piccoli campioni : distributzione $T$

Consideriamo in campione casuale semplice di dimensione $n$ da una distribuzione normale con media $\mu$ e *varianza ignota* $\sigma^2$ 

Vogliamo calcolare un intervallo di confidenza per la media $\mu$ basato sullo stimatore $\hat \mu = \bar X$ 

Se $n$ è piccolo allora l'*errore standard stimato* $\frac{S}{\sqrt{n}}$ potrebbe differire significativamente dal vero *errore standard* $\frac{\sigma}{\sqrt{n}}$ 

>[!note] 
>Da utilizzare quando $n<30$

La conseguenza di sostituire $\sigma$ con la stima consistente $S$ è che la quantità :
$$T=\frac{\sqrt{n}(\bar X -\mu)}{S}$$
Non ha più una distribuzione normale ma una dsitribuzione **T di Student** con $n-1$ *gradi di libertà*

#### Distribuzione $T$ di Student

I *gradi di libertà* controllano la forma della distribuzione $T$ 

Al crescere dei *gradi di libertà* la distribuzione $T$ *converge* alla distribuzione *normale*

##### Gradi di Libertà

I *gradi di libertà* corrispondono alla dimensione del vettore usato per stimare la varianza $\sigma^2$ nella statistica $T$ , questa è stimata dalla *varianza campionaria* : 
$$S^2 = \frac{1}{n-1}\sum^{n}_{i=1}(X_i-\bar X)^2$$
La *varianza campionaria* è una funzione del vettore dei dati centrali

>[!todo] 

##### Intervalli di confidenza per la media basati sulla statistica $T$

L'intervallo di confidenza per la media $\mu$ di una popolazione normale è :
$$\bar X \pm t_{\alpha/2} \frac{S}{\sqrt{n}}$$
dove $t_{\alpha/2}$ è il quantile della distribuzione $T$ con $n-1$ gradi di libertà di posizione $1-\alpha/2$ ovvero il valore tale che :
$$\Pr(T \ge t_{\alpha/2}) = \alpha/2\quad \text{oppure}\quad \Pr(T \le t_{\alpha/2}) = 1-\alpha/2$$
Al crescere di $n$ l'intervallo di confidenza basato sulla statistica $T$ convergerà all'intervallo basato sulla statistica $Z$  :
$$\bar X \pm z_{\alpha/2}\frac{S}{\sqrt{n}}$$
##### Quantili

Il valore di $t_{\alpha/2}$ si può ottenere grazie ad `R` attraverso la funzione `qt` ( *quantile of the T distribution* ) : $\Pr(T \le t_{\alpha/2})=1-\alpha/2$ ovvero $t_{\alpha/2}$ è il *qunatile* di $T$ di posizione $1-\alpha/2$ 

Per esempio se $\alpha = 0.05$ e $17$ gradi di libertà : `{r}qt(1-0.05/2, df = 17)`

>[!example] 
>Esempio 9.19 Baron
##### Confronto fra le medie di due popolazioni normali con varianze ignote

Consideriamo due campioni casuali semplici normali 
+ $X_1,\dots,X_n$ con media $\mu_X$ e varianza ignota $\sigma^2_X$
+ $Y_1,\dots,Y_m$ con media $\mu_Y$ e varianza ignota $\sigma^2_Y$

Assumiamo che i campioni siano *indipendenti*

Siamo interessati alla differenza fra le due medie : 
$$\theta = \mu_X -\mu_Y$$
Abbiamo 2 casi :
1. Le due varianze sono uguali $\sigma^2=\sigma^2_X=\sigma^2_Y$
2. Le due varianza sono differenti $\sigma^2_X \ne \sigma^2_Y$
###### Varianze uguali

Se le varianze sono uguali allora stimiamo $\sigma^2$ con tutti i dati : 
$$\hat \sigma^2 = S^2_p = \frac{1}{n+m-2}\bigg\{\sum^{n}_{i=1}(X_i-\bar X)^2+ \sum^{n}_{i=1}(Y_i-\bar Y)^2\bigg\}$$
Lo stimatore $S_p^2$ è detto varianza campionaria *pooled* 

In questo caso l'intervallo di confidenza per la differenza delle medie è :
$$\bar X -\bar Y \pm t_{\alpha/2}S_p \sqrt{\frac{1}{n}+\frac{1}{m}}$$
Dove $t_{\alpha/2}$ è il quantile di posizione $1-\alpha/2$ della distribuzione $T$ con $n+m-2$ *gradi di libertò* 

>[!example] 
>Esempio 9.20 Baron
###### Varianze diverse

Il caso in cui le varianze non sono uguali $\sigma^2_X \ne \sigma^2_Y$ è più complicato poichè la statistica $T$ :
$$T = \frac{(\bar X - \bar Y)-(\mu_X - \mu_Y)}{\sqrt{\frac{S^2_X}{n}+\frac{S^2_Y}{n}}}$$
non ha più una distribuzione $T$ 

In questo caso si ricorre spesso all'approsimazione di *Satterthwaite*

La distribuzione della statistica $T$ può essere *approssimata* con la distribuzione di una variabile casuale $T$ di Student con gradi di libertà : 
$$v=\frac{\bigg(\frac{S_X^2}{n}+\frac{S_Y^2}{m}\bigg)^2}{\frac{S_X^4}{n^2(n-1)}+\frac{S_Y^4}{m^2(m-1)}}$$
>[!note] 
>$v$ non è generalmente un numero intero

L'intervallo di confidenza per la differenza di due medie con l'approssimazione di *Satterthwaite* è :
$$\bar X -\bar Y\pm t_{\alpha/2} \sqrt{\frac{S_X^2}{n}+ \frac{S_Y^2}{m}}$$
dove $t_{\alpha/2}$ è il quantile di posizione $1-\alpha/2$ dellla sitribuzione $T$ di Student con $v$ gradi di libertà

>[!example] 
>Esempio 9.21 Baron
>
##### Intervalli di confidenza basati sullo stimatore di massima verosimiglianza

Sappiamo che sotto assunzioni di regolarità lo stimatore di massima verosimiglianza $\hat \theta$ è :
+ asintoticamente non distorto 
+ asintoticamente normale con distribuzione limite : $N\{ \theta , I(\theta)^{-1} \}$ 

Possiamo usare la distribuzione limite per costruire un intervallo di confidenza approssimato : 
$$\hat \theta \pm z_{\alpha/2}I(\hat{\theta})^{-1/2}$$
Oppure utilizzando l'informazione osservata : 
$$\hat \theta \pm z_{\alpha/2}J(\hat{\theta})^{-1/2}$$

>[!example] 
>Sia $X_1, \dots,X_n$ un campione casuale semplice da una varaibile normale con media 0 e varianza $\sigma^2$ ignota
>
>La funzione di densità di $X$ è :
>$$f(x; \sigma^2) = \frac{1}{\sqrt{2\pi \sigma^2} \exp \bigg(-\frac{x^2}{2\sigma^2}\bigg)}$$
>
>Vogliamo calcolare un intervallo di confidenza 90% per $\sigma^2$
>
>Abbiamo che 
>1. $\hat\sigma^2=\sum^{n}_{i=1} X^2/n$
>2. $I(\sigma^2)= n/(2\sigma^4)$
>
>Lo stimatore di massima verosimiglianza è distribuito approssimativamente come :
>$$N\bigg(\sigma^2,\frac{2\sigma^4}{n}\bigg)\quad \text{per $n$ sufficientemente grande}$$
>
>Un intervallo di confidenza con livello approssimato del $90\%$ è quindi : 
>$$\hat \sigma^2 \pm z_{0.05}I(\hat\sigma^2)^{-1/2} \quad \text{oppure} \quad \hat \sigma^2 \pm z_{0.05}J(\hat\sigma^2)^{-1/2}$$ 
>
>In questo particolare caso avremo che $I(\hat \sigma^2)=J(\hat \sigma^2)=n/(2\hat \sigma^4)$
>
>L'intervallo di confidenza è 
>$$\hat \sigma^2 \pm z_{0.05} \hat \sigma^2 \sqrt{2/n} \implies \hat \sigma^2 \pm 1.64 \hat \sigma^2 \sqrt{2/n}$$
>
>Supponiamo che un campione di dimensione $60$ abbia dato $\sum^{60}_{i=1} x_i^2 = 164.83$ 
>
>L'intervallo di confidenza sarà quindi :
>$$\frac{164.83}{60}\pm 1.64 \bigg(\frac{164.83}{60}\bigg)\sqrt{\frac{2}{60}} = [1.93,3.57]$$

##### Intervalli di confidenza e trasformazioni

Supponiamo di aver calcolato un intervallo di confidenza $[A,B]$ per un parametro $\theta$ , siamo però interessati ad una trasformazione $\phi = g(\theta)$ del parametro $\theta$ 

Se $\phi$ è una *trasformazione monotona* calcoliamo l'intervallo di confidenza per $\phi$ applicando la funzione $g$ agli estremi dell'intervallo di confidenza per $\theta$

Se $g$ è una *trasformazione monotona crescente* allora l'intervallo per $\phi$ è $[g(A),g(B)]$ poichè :
$$1-\alpha = \Pr(A\le \theta \le B) = \Pr\{g(A)\le g(\theta)\le g(B)\}$$
Se invece $g$ è *monotona descresente* allora l'intervallo per $\phi$ sarà $[g(B),g(A)]$ 
### Verifica delle Ipotesi

#### Ipotesi nulla e alternativa

Nella *verifica delle ipotesi* vengono confrontate due ipotesi mutualmente esclusive : 
+ $H_0$ : *ipotesi nulla* 
	Rappresenta lo stato delle cose ( ciò in cui si crede finchè i dati non forniscono una *chiara evidenza* contraria ( vale la **presunzione d'innocenza** ) ) 
+ $H_A$ : *ipotesi alternativa* 

Le due ipotesi fromano un sistema d'ipotesi 

L'esperimento campionario usato per valure le ipotesi è detto *test* e può porteare a 2 possibili decisioni : 
+ *impossibilità di rifiutare* l'ipotesi nulla $H_0$ perchè i dati non forniscono sufficoente evidenza contraria a $H_0$
+ *rifiuto* dell'ipotesi nulla $H_0$ perchè i dati forniscono sufficiente evidenza contraria a $H_0$ 

>[!example] 
>Se si vuole provare una nuova teoria allora si svolgerà un esperimento per valutare : 
>$$H_0:\{\text{la nuova teoria non è corretta}\}$$
>$$H_A:\{\text{la nuova teoria è corretta}\}$$

#### Ipotesi alternative

La verifica delle ipotesi viene classificata a seconda delle possibili ipotesi alternative $H_A$ :
1. ipotesi *alternativa bilaterale* ( *test a due code* )
	$H_0 : \theta = \theta_0$  contro  $H_A  : \theta \neq \theta_0$ 
2. ipotesi *alternativa sinistra* ( *test ad una coda* )
	$H_0 : \theta \ge \theta_0$  contro  $H_A : \theta < \theta_0$
3. ipotesi *alternativa destra* ( *test ad una coda* )
	$H_0 : \theta \le \theta_0$  contro  $H_A : \theta > \theta_0$

>[!note] 
Nei *test ad una coda* se rifiutiamo $H_0$ quando $\theta = \theta_0$ allora rifiutiamo $H_0$ per tutti gli altri valori , quindi anzichè scrivere $H_0 : \theta \ge \theta_0$ o $H_0 : \theta \le \theta_0$ possiamo scrivere $H_0 : \theta = \theta_0$

>[!example] 

#### Errori del primo tipo e secondo tipo

Poichè valutiamo le ipotesi con dei dati campionari dobbiamo considerare il rischio di formulare conclusioni sbagliate a causa dell'*errore campionario* , abbiamo 4 possibili situazioni che possiamo incontrare : 

|                     | ***rifiuto $H_0$*** | ***non rifiuto $H_0$*** |
| ------------------- | ------------------- | ----------------------- |
| ***$H_0$ è vera***  | errore $I$ tipo     | corretto                |
| ***$H_0$ è falsa*** | corretto            | errore $II$ tipo        |

+ *Errore del $I$ tipo* : rifiutare $H_0$ quando è vera 
	Commettere questo errore è molto grave ( è come condannare un innocente )
+ *Errore del $II$ tipo* : non rifiutare $H_0$ quando è falsa

>[!note] 
>Visto che stiamo osservando un campione dei dati non potremmo mai sapere se abbiamo fatto degli errori o no

Possiamo però calcolare la probabilità di commettere errori del $I$ e del $II$ tipo , visto che l'errore del $I$ tipo è più grave di solito si fissa un valore massimo accettabile per la sua probabilità 

#### Livello di Significatività

>[!note] 
> Il *livello di significatività* di un test è la probablilità di commettere un errore del $I$ tipo 
> $$\alpha = \Pr(\text{Rifiutate $H_0$ quando è in realtà vera})$$

La probablilità di *rifiutare* $H_0$ quando è *falsa* ( ossia abbiamo fatto al scielta corretta ) è detta *potenza del test* :
$$\beta(\theta)=\Pr(\text{ Rifiutare $H_0$ quando $H_A$ è vera })$$
La *potenza* dipende da $\theta$ perchè $H_A$ contiene solitamente diversi valori di $\theta$ 
>[!note] 
>La *potenza* è la probabilità di non commettere un errrore del $II$ tipo 

>[!hint] 
>Spesso i test si costruiscono fissando il *livello di significatività* ossia la probabilità di commettere un errore del $I$ tipo

#### Test con livello di significatività prefissato

I test di livello prefissato $\alpha$ consistono in tre passaggi : 
1. Individuare una *statistica test* ovvero una funzione dei dati utile per discriminare fra $H_0$ e $H_A$ 
	Solitamente la *statistica test* è una trasformazione di uno stimatore $\hat{\theta}$ con una distribuzione nota $f_0$ sotto l'*ipotesi nulla* $H_0$ ( ossia quando questa è vera )
2. Individuare i valori della statistica test che portano ad accettare o rifiutare $H_0$ ad un livello di significatibilità prefissato $\alpha$ 
	Avremo quindi 2 regioni :
	+ *regione di accettazione* $\mathcal{A}$ 
	+ *regione di rifiuto* $\mathcal{R}$ 
>[!example] 
	>![[Pasted image 20240424131445.png]]
3. Prendere una decisione a seconda se il valore osservato della statistica test cade nella regione di accettazione o di rifiuto e interpretare il risultato
#### Test Z

Supponiamo di avere lo stimatore $\hat{\theta}$ non distorto e normale ( es media campionaria ) 

Se l'*ipotesi nulla* è $H_0 : \theta = \theta_0$ allora è naturale ( perchè è naturale ???? ) considerare la statistica $Z$ come statistica test 
$$Z = \frac{\hat\theta-\theta_0}{SE(\hat{\theta})}$$
La statistica $Z$ ha distribuzione $\approx$ normale standard sotto l'ipotesi nulla $H_0$

Per valori della statistica $Z$ *vicini allo 0* diremo che l'evidenza empirica non ci permette di rifiutare $H_0$
Per valori invece *distanti dallo 0* invece l'evidenza empirica ci porta contro $H_0$

>[!note] 
Viene spesso usato per risolvere verifiche che riguardano : 
>+ medie di popoalzioni normali con varianze note
>+ medie valutate con campioni di grandi dimensioni
>+ proporzioni valutate con campioni di grandi dimensioni
>+ quantità stimate con il metodo della massima verosimiglianza con campioni di grandi dimensioni

##### Test a una coda

+ Se l'ipotesi alternativa è *unilaterale destra* ( $H_A : \theta > \theta_0$ ) 
	Si rifiuta per valori *troppo grandi* della statistica $Z$ :
	+ $\mathcal{R}=[z_{\alpha},+\infty)$
	+ $\mathcal{A}=(-\infty,z_{\alpha})$
	Il livello di significatività è : $\Pr(\text{Errore I tipo}) = \Pr(Z \in \mathcal{R} | H_0) = \Pr(Z>z_{\alpha})=\alpha$
![[Pasted image 20240424135305.png]]
+ Se l'ipotesi alternativa è *unilaterale sinistra* ( $H_A : \theta < \theta_0$ )
	Si rifiuta per valori *troppo piccoli* della statistica $Z$ :
	+ $\mathcal{R}=(-\infty,-z_{\alpha})$
	+ $\mathcal{A}=(-z_{\alpha},+\infty)$
	Il livello di significatività è : $\Pr(Errore I tipo) = \Pr(Z \in \mathcal{R}|H_0)=\Pr(Z <-z_{\alpha})=\alpha$
![[Screenshot 2024-04-24 135600.png]]
##### Test a due code

Se l'ipotesi alternativa è *bilaterale* ( $H_A : \theta \neq \theta_0$ )

Si rifiuta per valori sia troppo grandi che troppo piccoli della statistica $Z$ : 
+ $\mathcal R = (-\infty, -z_{\alpha/2}]\cup[z_{\alpha/2}, + \infty)$
+ $\mathcal{A} = (-z_{\alpha/2},z_{\alpha/2})$

Il livello di significatività è : 
$$\Pr(\text{Errore I tipo}) = \Pr(Z \in \mathcal{R}|H_0)=\Pr(Z < -z_{\alpha/2})+\Pr(Z > z_{\alpha/2})=\frac{\alpha}{2}+\frac{\alpha}{2} = \alpha$$
![[Pasted image 20240424141059.png]]

#### Test Z per medie e proporzioni

![[Pasted image 20240424142605.png]]

>[!example] 
>>[!todo] 
#### Test Z e massima verosimiglianza

Se l'ipotesi nulla $H_0 : \theta = \theta_0$ è vera allora , sotto assunzioni di regolarità , lo stimatore di massima verosimiglianza ha distribuzione approssimativamente normale 

Possiamo usare questo risultato per costruire le statistiche test $Z$ : 
$$Z = I(\theta_0)^{1/2}(\hat{\theta}-\theta_0) \ \text{oppure} \ Z = J(\theta_0)^{1/2}(\hat{\theta}-\theta_0)$$
Oppure possiamo usare l'errore standard stimato
$$Z = I(\hat\theta)^{1/2}(\hat{\theta}-\theta_0) \ \text{oppure} \ Z = J(\hat\theta)^{1/2}(\hat{\theta}-\theta_0)$$
Questo poichè se l'ipotesi nulla è vera allora 
$$\hat\theta \stackrel{p}\to \theta_0\quad \text{per n sufficentemente grande}$$

Per campioni finiti le statistiche costruite con $I(\theta_0)$ anzichè $I(\hat{\theta})$ o con $J(\theta_0)$ anzichè $J(\hat{\theta})$ possono differire anche in modo non trascurabile

>[!example] 
>>[!todo] 
>>slide 22
#### Test T 

Quando il campione è di piccole dimensioni la statisitica $Z$ potrebbe avere una *distribuzione nulla* che differisce anche in modo sostanziale dalla distribuzione normale 

Se usiamo la distribuzione normale potremmo commettere errori del $I$ tipo con una probabilità maggiore di quella prefissata 

Supponiamo di voler valutare un'ipotesi relativa alla media di un campione di piccole dimensioni da una *popolazione normale* con media $\mu$ e varianza $\sigma^2$ entrambe *ignote* , siamo interessati a valutare l'ipotesi $H_0 : \mu = \mu_0$ con possibili alternative : 
$$H_A : \mu \ne \mu_0 \qquad H_A : \mu > \mu_0 \qquad H_A : \mu < \mu_0 $$
Per valutare le ipotesi utilizzeremo la statistica test $T$ 
$$T = \frac{\sqrt{n}(\bar X -\mu_0)}{S}$$
La statistica $T$ ha distribuzione $T$ di Student con $n-1$ gradi di libertà sotto $H_0$
##### Test a una coda

+ Se l'ipotesi alternativa è *unilaterale destra* ( $H_A : \theta > \theta_0$ ) 
	Si rifiuta per valori *troppo grandi* della statistica $T$ :
	+ $\mathcal{R}=[t_{\alpha},+\infty)$
	+ $\mathcal{A}=(-\infty,t_{\alpha})$
	Il livello di significatività è : $\Pr(\text{Errore I tipo}) = \Pr(T \in \mathcal{R} | H_0) = \Pr(T>t_{\alpha})=\alpha$
+ Se l'ipotesi alternativa è *unilaterale sinistra* ( $H_A : \theta < \theta_0$ )
	Si rifiuta per valori *troppo piccoli* della statistica $T$ :
	+ $\mathcal{R}=(-\infty,-t_{\alpha})$
	+ $\mathcal{A}=(-t_{\alpha},+\infty)$
	Il livello di significatività è : $\Pr(Errore I tipo) = \Pr(T \in \mathcal{R}|H_0)=\Pr(T<-t_{\alpha})=\alpha$
##### Test a due code

Se l'ipotesi alternativa è *bilaterale* ( $H_A : \theta \neq \theta_0$ )

Si rifiuta per valori sia troppo grandi che troppo piccoli della statistica $T$ : 
+ $\mathcal R = (-\infty, -t_{\alpha/2}]\cup[t_{\alpha/2}, + \infty)$
+ $\mathcal{A} = (-t_{\alpha/2},t_{\alpha/2})$
Il livello di significatività è : 
$$\Pr(\text{Errore I tipo}) = \Pr(T \in \mathcal{R}|H_0)=\Pr(T < -t_{\alpha/2})+\Pr(T > t_{\alpha/2})=\frac{\alpha}{2}+\frac{\alpha}{2} = \alpha$$
>[!example] 
>Esempio 9.28 baron slide 27
##### Test a due campioni 

Consideriamo ora ipotesi relative al confronto delle medie di due *popolazioni normali* con *varianze ignote*

*Ipotesi nulla* : $H_0 : \mu_X - \mu_Y = D$ 
*Ipotesi alternative* : 
$$H_A : \mu_X - \mu_Y \neq D \qquad H_A : \mu_X - \mu_Y > D \qquad H_A : \mu_X - \mu_Y < D$$
Spesso si addume $D=0$ per cui avremo che $H_0 : \mu_X = \mu_Y$ e 
$$H_A : \mu_X \neq \mu_Y \qquad H_A : \mu_X > \mu_Y  \qquad H_A : \mu_X < \mu_Y $$

Se la dimensione dei due campioni $n$ e $m$ non sono grandi dobbiamo usare un test $T$ a due campioni 

Dobbiamo considerare due casi differenti :
###### Con varianze uguali

Nel caso di varianze uguali si usa la statistica test $T$ : 
$$T = \frac{\bar{X}-\bar{Y}-D}{S_p \sqrt{\frac{1}{n}+\frac{1}{m}}}$$
Dove $S_p^2$ indica la *varianza pooled* ( incontrata nel calcolo degli intervalli di confidenza ) : 
$$S_p^2 = \frac{(n-1)\cdot S_X^2 + (m-1)\cdot S_Y^2}{n+m-2}$$
La statistica $T$ si distribuisce quindi come una variabile casuale $T$ di Student con $n+m-2$ gradi  di libertà sotto $H_0$

>[!example] 
>Abbiamo i seguenti dati su un pc con un lettore CD (campione $X$) e uno senza (campione $Y$)
>$$n=12, \ \bar{X}=4.8, \ s_X=1.6; \quad m=18,\ \bar{Y}=5.3,\ s_Y = 1.4; \quad s_p = 1.4818$$
>
>Vogliamo vedere se il lettore CD consuma extra enegria e se quindi si riduce la durata della batteria
>
>Testiamo dunque :
>$$H_0 : \mu_X = \mu_Y \qquad H_A : \mu_X < \mu_Y$$
>con $\alpha=0.05$ :
>$$t = \frac{\bar{X}-\bar{Y}}{s_p \sqrt{\frac{1}{n}+\frac{1}{m}}} = \frac{4.8-5.3}{1.4818\cdot \sqrt{\frac{1}{12}+\frac{1}{18}}}= -0.9054$$
>>[!note] 
>>In questo caso $D=0$ poichè abbiamo assunto che sia $0$
>
>La regione di rifiuto per questo testa alla coda sinistra è : $(-\infty,-t_{\alpha}] = (-\infty,-1.70]$ ossia il quantile della distribuzione $T$ con $18+12-2=28$ gradi di libertà
###### Con varianze diverse

Se le varianze sono diverse $\sigma_X^2 \neq \sigma_Y^2$ allora dovremmo utilizzare la seguente statistica test $T$ : 
$$T = \frac{\bar{X}-\bar{Y}-D}{\sqrt{\frac{S_X^2}{n}+\frac{S_Y^2}{m}}}$$
In questo caso la statistica $T$ **non** si distribuisce esattamente come una variabile casuale $T$ di Student sotto $H_0$

Per risolvere questo problema possiamo utilizzare l'approssimazione di *Satterthwaite* che ci dirà che $T$ ha distribuzione *approssimativamente* $T$ di Student con $v$ gradi di libertà , con $v$ : 
$$v = \frac{\bigg(\frac{S_X^2}{n}+\frac{S_Y^2}{m}\bigg)^2}{\frac{S_X^4}{n^2(n-1)}+\frac{S_Y^4}{m^2(m-1)}}$$
##### Riassunto Test $T$

![[Pasted image 20240430142444.png]]
#### Test e intervalli di confidenza

Vi è una relazione fra test a due code e intervalli di confidenza simmetrici : **dualità**

>[!Teorema]
> Un test $Z$ per l'ipotesi alternativa bilaterale $H_0 : \theta = \theta_0$ contro $H_A : \theta \neq \theta_0$ non rifiuta l'*ipotesi nulla* al *livello di significatività* $\alpha$ **se e solo** se l'*intervallo di confidenza* per $\theta$ basato sulla statistica $Z$ con *livello di confidenza* $1-\alpha$ contiene $\theta_0$

In pratica possiamo usare gli *intervalli di confidenza* per risolvere problemi di verifi d'ipotesi

>[!Dimostrazione]
>L'ipotesi nulla non viene rifiutata se e solo se il valore osservato della statistica $Z$ appartiene alla regione di accettazione : 
>$$-z_{\alpha/2}<\frac{\hat\theta-\theta_0}{SE(\hat{\theta})}<z_{\aleph/2}$$
>Ossia : 
>$$\bigg|\frac{\hat\theta-\theta_0}{SE(\hat{\theta})}\bigg|<z_{\aleph/2}$$
>Visto che $SE(\hat\theta)>0$ possiamo scrivere : 
>$$|\hat\theta-\theta_0|<z_{\aleph/2}\cdot SE(\hat{\theta})$$
>
>Questa diseguaglianza mostra che $\theta_0$ dista da $\hat\theta$ meno del margine di errore dell'intervallo di confidenza per $\theta$ con livello di confidenza $1-\alpha$

>[!important] 
>+ Il risultato vale solo per verifiche d'ipotesi con alternative bilaterali
>+ Il risultato vale solo se il livello di significatività è $\alpha$ e il livello di confidenza è $1-\alpha$
>+ Il risultato vale anche per altre statistiche test fra cui il test $T$ e l'intervallo basato sulla statistica $T$

>[!example] Example 9.31  
>Si consideri un campiona casuale semplice derivante da una distribuzione normale con media $\mu$ ignota e devizione standard $\sigma = 2.2$ : $2.5,7.4,8.0,4.5,7.4,9.2$
>
>Valutiamo l'ipotesi al livello di significatività del $5\%$ : $H_0 : \mu = 6$ contro $H_A : \mu \neq 6$
>
>L'intervallo di confidenza di livello $95\%$ per $\mu$ è : $[4.74,8.26]$ , visto che l'intervallo contiene $\mu_0 = 6$ non possiamo rifiutare l'ipotesi nulla al livello di significatività del $5\%$

>[!example] 
>Altri esempi 9.34 , 9.35
#### Fissare il livello di significatività ?

Notiamo che i dati potrebbero portarci a rifiutare l'ipotesi nulla ad un certo livello di significatività in modo netto ( ci troviamo distanti da $z_{\alpha/2}$ ) o anche solo di poco ( ci troviamo vicini da $z_{\alpha/2}$ )

I test con livello di significatività fissata ci portano solo a rifiutare o meno ma non misurano l'evidenza a favore o contro l'ipotesi nulla 
#### Livello di significatività osservato

Un approccio per risolvere il precedente problema è quello della verifica delle ipotesi basata sul *livello di significatività osservato* o *p-value* che evita di fissare un livello di significatività in modo da misurare l'ammontare di evidenza a favore delle ipotesi 

>[!note] Definizione di *livello di significatività osservato*
>La probabilità di ottenere un valore della statistica test uguae o più estremo di quello osservato se l'ipotesi nulla fosse vera 

Se il *livello di significatività osservato* è "grande" vuol dire che quello che abbiamo osservato non era poi così estremo e quindi non possiamo rifiutare $H_0$ , viceversa se il *livello di significatività osservato* è "piccolo" vuol dire che quello che abbiamo osservato era davvero estremo e quindi rifiutiamo $H_0$ 

##### Calcolo del livello di significatività osservato

Il calcolo del livello di significatività osservato dipende da $H_A$ e dalla statistica test 

Abbiamo 3 casi a seconda dell'$H_A$ :   
+ *unilaterale destra* : 
	Rifiutiamo $H_0$ per valori "troppo grandi"
	Il livello di significatività osservato è la probabilità di osservare qualcosa tanto o più estremo di $z$ ovvero : 
	$p = \Pr(Z \ge z) = 1- \Phi(z)$
+ *unilaterale sinistra*
	Rifiutiamo $H_0$ per valori "troppo piccoli"
	Il livello di significatività osservato è pari a : 
	$p = \Pr(Z \le z) = \Phi(z)$
+ *bilaterale*
	Rifiutiamo $H_0$ sia per valori "troppo grandi" che per valori "troppo piccoli"
	Il livello di significatività osservato è : 
	$p = \Pr(|Z|>|z|)=\Pr(Z > |z|)+\Pr(Z<-|z|)=2\Pr(Z>|z|)=2\{\ 1-\Pr(Z < |z|)\}=2\{1-\Phi(|z|)\}$

![[Pasted image 20240430153822.png]]

>[!note] 
>Nello stesso modo si calcola il livello di significatività osservato per il test $T$
![[Pasted image 20240430153832.png]]
#### Interpretazione del livello di significatività osservato

Quando si rifiuta l'ipotesi nulla si dice che il test è *significativo*

Esistono diversi gradi di *significatività* a seconda dell'evidenza empirica contro l'ipotesi nulla 

Soglie per il *p-value* : 

| *P-value*           | *Significatività* | *Decisione*                |
| ------------------- | ----------------- | -------------------------- |
| $p<0.001$           | forte             | rifiuto netto di $H_0$     |
| $0.001\le p < 0.01$ | moderata          | rifiuto di $H_0$           |
| $0.01 \le p < 0.05$ | modesta           | rifiuto debole di $H_0$    |
| $0.05\le p< 0.1$    | incerta           | situazione dubbia          |
| $p\ge 0.1$          | nessuna           | non si può rifiutare $H_0$ |

>[!example] Example 9.37 
> Riprende esercizio 9.34
> 
> Ci chiediamo se il livello di significatività del $5\%$ è stato superato di poco o molto
> 
> Il valore osservato della statistica $Z$ è :
> $$z=\frac{8.5-7.2}{\sqrt{\frac{1.8^2}{50}+\frac{1.8^2}{50}}} = 3.61$$
> 
> Il livello di significatività osservato è pari a :
> $p=\Pr(Z > 3.61)=1-\Phi(3.61)=0.0002$
> o in `r` : `{r}1-pnorm(3.61)`
> 
> Quindi possiamo concluder che l'aggioernamento è stato effiacce ad un livello di significatività ben più basso del $5\%$
#### Campioni non indipendenti

Cosa succede se in situazioni nelle quali non possiamo assumere l'*indipendenza* di due campioni ne assumiamo invece l'*indipendenza* ? 
In questo caso le statistiche $Z$ e $T$ utilizzano una stima dell'errore standard sbagliato perchè trascura la correlazione fra i due campioni esponendoci al rischio di errori del primo o del secondo tipo più altro di quanto atteso
##### Test per dati appaiati

Abbiamo dati *appaiati* quando le variabili $X$ e $Y$ sono osservate sulle stesse unità statistiche 

>[!example] 
>Per studiare l'efficacia di un farmaco lo si misura su un campione di volontari *prima* e *dopo* il trattamento
>
>In questo caso non possiamo assumere che le due osservazioni siano indipendenit in quanto il trattamento può essere influenzato da caratteristiche personali 

Ciò vuol dire che i dati appaiati saranno : $(X_1,Y_1),\dots,(X_n,Y_n)$ ( dove nell'esempio di prima $X$ rappresenta dei dati *prima* e $Y$ *dopo* il trattamento )

Avendo l'ipotesi nulla $H_0 : \mu_x = \mu_y$ la statistica test $Z$ o $T$ corretta è ( bisogna aggiungere la covarianza campionaria fra  $X$ e $Y$ : $S_{XY}$ ) : 
$$Z=\frac{\bar{X}-\bar{Y}}{\sqrt{\frac{S_X^2}{n}+\frac{S_Y^2}{n}+\frac{2S_{XY}}{n}}}$$
Possiamo evitare la *covarianza* se in un test per dati appaiati si utilizza come variabili $D_n=X_n-Y_n$ossia la differenza tra le varaibili dipendenti ( questo perchè dipendono sulla stessa "popolazione" )

Il test quindi può essere risctritto nel seguente modo : $H_0 : \mu_D = 0$ e la statistica $Z$ o $T$ sarà semplicemente : 
$$Z = \sqrt{n}\frac{\bar{D}}{S_D}$$
>[!example] Amazon o libreria?
>
>Abbiamo un campione di 15 libri eterogenei , abbiamo i loro costi presi da Amazon o dalla Libreria
>
>Possiamo notare che siamo nel caso di test appaiati sul nome del libro ( lo stato prima è ora il costo dalla Libreria e quello dopo il costo da Amazon )
>Dovremo calcolare la differenza tra tutti i prezzi : 
>$$d_1 = 120 - 101.22 = 18.78 , \dots , d_15 = 155.75 - 126-97 = 28.78$$
>
>Vorremo verificare l'ipotesi che sia più conveniente comprare da Amazon , avremo quindi che :
>$$H_0 : \mu_d = 0 \ \text{contro} \ H_A : \mu_d > 0$$
>Abbiamo inoltre $\bar d = 16.51$ e $s_d=9.42$
>
>Il valore osservato della statistica $T$ ( dopo aver controllato la normalità delle differenze di prezzo ) è : 
>$$t=\sqrt{15}\frac{16.51}{9.42}=6.72$$ 
>Che ci porta nettamente a rifiutare l'ipotesi nulla 

### Dipendenza tra Variabili

In molti casi siamo interessati a valutare se vi sia un legame fra due variabili :
>[!example] 
>+ Il fumo di sigaretta è associato alla formazione di tumori ?
>+ Il voto ottenuto all'esame di matematica diepende dal numero di ore di studio ? 

#### Dipendenza fra due variabili numeriche 

Valutiamo se una variabile $X$ può essere usata per *prevedere* una variabile $Y$ 

Terminologia : 
+ $X$ è la variabile *predittore*
+ $Y$ è la variabile *risposta*

Nei **modelli di regressione** si valuta la capacità predittiva della variabile $X$ sulla variabile $Y$ attraverso il *valore atteso condizionato* : 
$$G(x) = E(Y|X=x)$$
Dove $G(x)$ è una funzione di $x$ la cui forma può essere stimata con i dati 

>[!example] 
>Abbiamo i seguenti dati riguardanti la cresctita della popolazione mondiale a partire dal 1950:
>
| Year | Population mln. people |
| ---- | :--------------------: |
| 1950 |          2558          |
| 1955 |          2782          |
| 1960 |          3043          |
| 1965 |          3350          |
| 1970 |          3712          |
| 1975 |          4089          |
| 1980 |          4451          |
| 1985 |          4855          |
| 1990 |          5287          |
| 1995 |          5700          |
| 2000 |          6090          |
| 2005 |          6474          |
| 2010 |          6864          |
>
> La dsitribuzione dei dati può essere rappresentata nel seguente grafico :
> 
> ![[Pasted image 20240502134246.png]]
> 
> In questo caso vediamo che i dati si allineano rispetto ad una linea della *regression line* ( *retta di regressione* )

>[!example] 
>Il prezzo delle case rispetto alla loro dimensione invece possiamo vedere che non segue molto la *funzione di regressione* , questo poichè i prezzi non dipendono solo dalla dimensione ma anche da altri fattori 
>
>![[Pasted image 20240502134708.png]]
>
>Per rappresentare correttamente questo dataset avremmo bisogno di un modello di regressione multivalore


#### Modelli di regressione lineare

Il modello di regressione più semplice è il quello *lineare semplice* o *retta di regressione* , andremo infatti a modellare i dati secondo una retta : 
$$G(x)=\beta_0 + \beta_1x$$
+ $\beta_0$ : corrisponde all'*intercetta* della retta
+ $\beta_1$ : è invece il *coefficente angolare* della retta 
  
Nelle applicazioni è comune considerare diversi *predittori* per migliorare la previsione della *risposta* , in questo caso utilizzeremo il modello di *regressione lineare multipla* :
$$G(x) = \beta_0 +\beta_1x_1+ \dots + \beta_px_p$$
>[!example] 
>Per prevedere il prezzo di vendita di un immobile possiamo considerare : dimensione , numero di stanze , quartiere etcc... 
#### Interpretazione dei parametri 

L'*intercetta* è il valore predetto dal modello quando $x=0$ , ovvero $\beta_0 = G(0)$ 

>[!note]
>Spesso $\beta_0$ non ha un particolare significato 
>>[!example] 
>>Nessuno infatti è interessato al prezzo di una casa $Y$ con una dimensione $X$ pari a 0 metri quadri

Il *coefficente angolare* è la variazione della *risposta* quando il *predittore* aumeta di una unità : 
$$\beta_1 = G(x+1)-G(x) = \{ \beta_0 +\beta_1(x+1) \}-\{ \beta_0 +\beta_1x \} = \beta_1$$
Questo ci dice quanto aumetna il prezzo di vendita di una casa all'aumentare della dimensione di un metro quadro 

>[!note] 
>Se $\beta_1 = 0$ allora non vi è relazione lineare fra $Y$ e $X$ 
#### Metodo dei minimi quadrati

I dati consistono in $n$ coppie di osservazioni : $(y_1,x_1),\dots , (y_n,x_n)$ 

Il metodo de minimi quadrati costruisce la *stima* $\widehat{G}(x)$ della funzione di regressione $G(x)$ minimizzando la somma dei quadrati delle differenze fra le risposte $y_1,\dots,y_n$ e le corrispondenti previsioni basate sul modello di regressione $\hat{y}_1 = \widehat{G}(x_1),\dots,\hat{y}_n=\widehat{G}(x_n)$
Ossia minimizzando la somma dei quadrati *residui* $e_i = y_i -\hat{y}_i$ ossia : 
$$\sum^{n}_{i=1} e_i^2 =\sum^{n}_{i=1}(y_i -\hat{y}_i)^2$$
![[Pasted image 20240502142354.png]]

Otterremo quindi le stime dei parametri $\beta_0$ e $\beta_1$ minimizzando : 
$$\mathcal{Q} (\beta_0 , \beta_1) = \sum^{n}_{i=1}(y_i -\hat{y}_i)^2 = \sum^{n}_{i=1}\{y_i -(\beta_0+\beta_1x_i)\}^2$$
Ovvero risolvendo il seguente sistema : 
$$\begin{cases}
\frac{d\mathcal{Q}(\beta_0,\beta_1)}{d\beta_0}=0 \\ \frac{d\mathcal{Q}(\beta_0,\beta_1)}{d\beta_1}=0
\end{cases} $$
Da cui avremo : 
$$\hat{\beta_0} = \bar{y} -\hat{\beta_1}\bar{x}\quad \text{e}\quad \hat{\beta_1}=\frac{s_{xy}}{s_x^2}$$dove : 
$$s_{xy}=\frac{1}{n-1}\sum^{n}_{i=1}(x_i-\bar x)(y_i-\bar y)$$
$$s_x^2 = \frac{1}{n-1}\sum^{n}_{i=1}(x_i-\bar{x})^2$$

>[!example] 
>Con i dati relativi alla popolazione modiale
>
>Abbiamo : 
>$$\bar{x} = 1980, \quad \bar{y}=4558.1,\quad s_x^2 = 4550, \quad s_{xy}=337250$$
>
>Da cui segue : 
>$$\hat{\beta}_1 = s_{xy}/s_x^2 = 74.1, \quad \hat{\beta}_0 = \bar{y}-\hat{\beta}\bar{x}=-1442201$$
>
>La *retta di regressione* stimata è 
>$$\hat{G}(x)=-142201+74.1x$$
>
>Ora possiamo fare delle previsioni : 
>+ $\hat{G}(2015)=-1442201+74.1(2015)=7152\ \text{milioni di persone}$
>+ $\hat{G}(2020)=-1442201+74.1(2020)=7523\ \text{milioni di persone}$
#### Regressione e correlazione

Lo stimatore del coefficiente angolare può essere riscritto in funzione del coefficiente di correlazione 

Indichiamo con $r_{xy}$ il *coefficiente di correlazione* : 
$$r_{xy}=\frac{s_{xy}}{s_ys_x}$$
Abbiamo :
$$\hat{\beta}_1 = \frac{s_{xy}}{s_x^2} = \frac{s_{xy}}{s_y s_x}\frac{s_y}{s_x}=r_{xy}\frac{s_y}{s_x}$$
Quindi : 
+ $\hat{\beta_1}>0$ se $X$ e $Y$ sono correlate positivamente
+ $\hat{\beta_1}<0$ se $X$ e $Y$ sono correlate negativamente 
+ $\hat{\beta_1}=0$ se $X$ e $Y$ sono incorrelate 
#### Decomposizione della varianza

La *varianza totale* delle risposte è descritta dalla *somma dei quadrati totale* : 
$$SQ_{tot} = \sum^{n}_{i=1}(y_i - \bar{y})^2 = (n-1)s_y^2$$
Per cui vale la decomposizione 
$$SQ_{tot} = SQ_{reg} +SQ_{res}$$
dove : 
+ $SQ_{reg}$ è la *somma dei quadrati spiegata* dal modello :
	$$SQ_{reg} = \sum_{i=1}^n(\hat{y}_i-\bar{y}_i)^2$$
+ $SQ_{res}$ è la *somma dei quadati residua* :
	$$SQ_{res} = \sum_{i=1}^n({y}_i-\hat{y}_i)^2$$
#### Coefficente di determinazione

Il *coefficiente di determinazione* o $R^2$ ( R quadro ) è la proporzione della variazione totale spiegata dal modello di regressione 
$$R^2 = \frac{SQ_{reg}}{SQ_{tot}}=1-\frac{SQ_{res}}{SQ_{tot}}$$

>[!note] 
>$R^2$ può assumere valori fra 0 e 1 

Più alto è $R^2$ tanto migliore sarà l'adattamento del modello di regressione ai dati 

>[!note] 
>Per il modello di *regressione lineare semplice* si dimostra che $R^2=r_{xy}^2$ ossia il quadrato del coefficiente di correlazione

Se $X$ e $Y$ sono perfettamente correlate $r_{xy}=\pm 1$ e $R^2=1$

>[!example] 
>Nel modello della crescita di popolazione $R^2=0.995$
#### Correlazioni spurie

Due variabili possono presentare una'alta correlazione in assenza di un nesso logico 

Le *correlazioni spurie* sono solitamente dovute alla presenza di una terza variabile che è collegata alle due variabili che stiamo considerando 

Quindi $A$ e $B$ risultano correlate solamente perchè $A$ è correlata con $C$ e $B$ è correlata con $C$ ( non sempre è evidente quale sia la terza variabile coinvolta )

>[!example] 
>
>C'era una correlazione dell'85% tra la popolazione di una città tedesca e il numero di cicogne avvistate nella città 
>Potrebbe portarci a dire che le cicogne portano bambini 
>Siamo di fronte ad un caso di *correlazione spuria* : in questo caso la variabile $C$ era il numero di case che aumentando a cuasa dell'espansione della città aumentavano anche i camini dove potevano nidificare le cicogne e di conseguenza il numero di cicogne avvistate aumentava

#### Intervalli di confidenza e verifica delle ipotesi

Nel modello di *regressione lineare semplice* il parametro di interesse è il coefficente angolare $\upbeta_1$ 

Per calcolare intervalli di confidenza e valutare ipotesi su $\upbeta_1$ dobbiamo introdurre delle *assunzioni* : 

Avremo il seguente modello di regressione lineare semplice con *errori normali* :
$$Y_i=\upbeta_0 +\upbeta_1 x_i +\epsilon_i$$ **Assunzioni** :
+ Gli errori $\epsilon_i$ sono variabili casuali *indipendenti* *normali* di media 0 e varianza $\sigma^2$ ( costante per tutti gli $i$ ) 
+ Il predittore ( $x_i$ ) è una quantità *non casuale* 

Sotto queste assunzioni $\hat \upbeta_1$ è uno *stimatore non distorto* di $\upbeta_1$ con *distribuzione normale*

##### Intervalli di confidenza per $\upbeta_1$

Siccome $\hat{\upbeta}_1$ è distribuito normalemente allora possiamo calcolare gli *intervalli di confidenza* per $\upbeta_1$ con la statistica $T$ 

L'*intervallo di confidenza* di livello $1-\alpha$ per $\upbeta_1$ è :
$$\hat{\upbeta}_1 \pm t_{\alpha/2} \widehat{SE}(\hat\upbeta_1)$$
dove $t_{\alpha/2}$ è il quantile di posizione $1-\alpha/2$ della distribuzione $T$ *di student* con $(n-2)$ gradi di libertà , questo perchè ci sono due parametri $\upbeta_0$ e $\upbeta_1$ che devono essere stimati per calcolare $s^2_e$ 

##### Verifica delle ipotesi su $\upbeta_1$ 

Consideriamo un'ipotesi nulla : 
$$H_0 : \upbeta_1 = \upbeta_1^0$$
L'ipotesi può essere valutata con la statistica test $T$
$$T = \frac{\hat\upbeta_1-\upbeta_1^0}{\widehat{SE}(\hat{\upbeta}_1)}$$
che si distribuisce come una variabile casuale $T$ con $n-2$ gradi di libertà sotto l'ipotesi nulla 

##### Test di significatività del predittore

Possiamo condurlo per valutare se un predittore è *statisticamente significativo* 

Si tratta di un test *bilaterale* in cui l'ipotesi nulla è che il predittore è ininfluente nel modello di regressione lineare , l'ipotesi nulla e alternativa saranno : 
$$H_0 : \upbeta_1 = 0 \quad \text{contro} \quad H_A : \upbeta_1 \neq 0$$
La statistica test $T$ è quindi pari a : 
$$T = \frac{\hat\upbeta_1}{\widehat{SE}(\hat\upbeta_1)}$$
Se il test porta al *rifiuto* dell'ipotesi nulla allora il predittore è statisticamente significativo

#### Relazioni lineari e non lineari 

Se il test di significatività indica che non si può rifiutare l'ipotesi nulla vuol dire che *non* vi è una *relazione lineare* fra il predittore e la risposta 

Potrebbe essere che esista una qualche *relazione non lineare* fra predittore e risposta 

>[!example] 
>![[Pasted image 20240507141338.png]]
>
>Abbiamo $r_{xy}=0$ e quindi $\upbeta_1 = 0$ ma vi è una perfetta relazione quadratica fra le due variabili 

#### Previsioni

La previsione della risposta in corrispondenza ad un particolare valore del predittore $x_*$ : 
$$\hat{y}_* = \hat{\upbeta}_0 + \hat{\upbeta}_1 x_*$$
Siccome i paraetri della retta $\upbeta_0$ e $\upbeta_1$ sono stati stimati allora la previsione sarà affetta da *incertezza*

La varianza di $\hat{y}_*$ è :
$$Var(\hat{y}_*)=\sigma^2 \bigg(1+\frac{1}{n}+\frac{(x_*-\bar{x})^2}{(n-1)s_x^2}\bigg)$$
con cui possiamo calcolare l'**intervallo di previsione**
$$\hat{y}_* \pm t_{\alpha/2}\sqrt{\widehat{Var}(\hat{y}_*)}$$
dove $t_{\alpha/2}$ è il quantile di posizione $1-\alpha/2$ della distribuzione $T$ con $n-2$ gradi di libertà e la varianza $\sigma^2$ è stiamta con $s_e^2$ 

>[!example] 
>Abbiamo un dataset contenente i pesi medi del corpo ( Kg ) e del cervello ( gr ) di 62 specie di mammiferi
>
>Stimiamo la retta di regressione fra il peso medio del corpo $X$ e il peso medio del cervello $Y$ 
>
>La *correlazione* fra $X$ e $Y$ è $0.93$ 
>
>Avremo i seguenti dati : $\bar{x} = 198.79 \quad, \bar{y} = 283.13,\quad s_x = 899.16,\quad s_y = 930.28$
>
>La retta di regressione stimata con il metodo dei minimi quadrati è :
>$$\hat y = 91 +0.97 x$$
>
>Con $R^2 = 0.87$ 
>
>Notiamo che la retta non descrive molto bene i dati visto che vi sono numero osservazioni lontane dalla *retta di regressione*
>
>![[Pasted image 20240507145031.png]]

