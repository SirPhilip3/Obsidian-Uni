Sistemi di **I/O** usati per collegare il calcolatore a dispositivi esterni

## Bus

I vari sottosistemi di un calcolatore comunicano attraverso interfacce predefinite 
Collegamento eseguito attraverso un **bus** che implementa un canale di comunicazione condiviso da più sottosistemi

Example :

![[Immagine 2023-05-02 150420.png]]

Vantaggi :
+ _Versatilità_ : facile aggiungere o togliere dispositivi , le periferiche possono essere spostate tra sistemi differenti che usano lo stesso tipo di **bus** 
+ _Basso costo_ : Uno stesso collegamento è utilizzato per diverse esigenze
Svantaggi : 
+ _Collo di bottiglia_ : la banda del **bus** limita la massima frequenza di **I/O**

 Un **bus** è composto da un insieme di fili ( piste ) che veicolano segnali elettrici
 + Fili di **controllo** trasportano : 
	 + richieste di operazioni di **I/O**
	 + Acknowledge della richiesta
+ Fili per **dati** / **indirizzi** trasportano :
	+ Dati per effettuare la richiesta di operazione di **I/O** ( contenente es : indirizzo di memoria su cui scrivere )
	+ Dati per trasferire i risultati della richiesta di **I/O**

### Tipi di bus

Esempi di **bus** :
+ **System bus** : Interconnettono CPU e Memoria , caratteristiche :
	+ Corti
	+ Alta velocità
	+ Proprietari
+ **Backplane** : Interconnnettono dispositivi diversi con bande di trasferimento diverse , caratteristiche :
	+ Mediamente lunghi
	+ Veloci
	+ Standard ( es. PCI, PCIe )
+ **IO** : Bus standard come **SATA** per gestire catene di dischi , caratteristiche 
	+ Lunghi
	+ Lenti
	+ Standard

### Gerarchie di bus

Old system ( discontinued )

![[Immagine 2023-05-02 151852.png]]

**Bus** I/O interfacciati direttamente con il **bus** processore-memoria

![[Immagine 2023-05-02 152049.png]]

Sistema moderno che consente di ridurre i conflitti nell'accesso al **bus** in modo gerarchico

![[Immagine 2023-05-02 152220.png]]

### Esempi di **bus** Intel

#### Pre 2010

+ CPU connessa ad un chip chiamato _Northbridge_ attraverso il  _Front side bus_ 
+ _Northbridge_ controlla lo scambio dati tra CPU , memoria e interfacce veloci come schede grafiche
+ _Southbridge_ è un chip connesso a _Northbridge_ attraverso un bus proprietario ( Hub-link )
+ _Southbridge_ è responsabile di inerconnettere dispositivi più lenti attraverso il **bus** PCI , LPC ( Low Pin Count ) , USB , SATA

![[Immagine 2023-05-02 153249.png]]

#### PC moderni

+ _Northbridge_ integrato nella CPU 
+ _Southbridge_ diventa : I/O control HUB o Platform Controller HUB
+ Le schede grafiche sono direttamente connesse alla CPU tramite PCIe 3.0
+ _Southbridge_ connesso alla CPU trmite un **bus** chiamato **DMI ( Direct Media Interface )** basato sullo standard PCIe  

![[Immagine 2023-05-02 153347.png]]

## BUS Sincrono

Linea di clock condivisa tra gli elementi connessi al **bus** 
Il protocollo di conmnicazione sfrutta questo clock per arbitrare gli accessi al **bus**
+ Al ciclo X il dispositivo N pone sul **bus** una richiesta di lettura per M
+ Al ciclo X+d il dispositivo N può leggere i dati ( poste sulle linee dati del **bus** del dispositivo M )

Limitato a **bus** corti ( es: **bus** proprietari tra CPU - Memoria ) , con **bus** più lunghi si verifica il fenomeno del clock _skew_ ( disallineamento del segnale di clock )

## BUS Asincrono

Linea di clock non condiviso tra dispositivi connessi al **bus** ( ogni dispositivo ha il proprio ciclo di clock ) , permette la comunicazione tra periferiche di velocità diverse

**bus** standard : 
+ USB
+ SATA
+ PCIe

Protocollo di comunicazione per effettuare una trasazione di IO richiede una sincronizzazione iniziale ( **handshaking** ) che comporta dell'overhead

Oltre alle linee per il trasferimento di dati bisogna aggiungere 2 segnali per sincronizzare le operazioni ( **Req , Ack** )

Esempio :

1. All'inizio tutte le linee sono not-asserted ( volts to 0 )
   ![[Immagine 2023-05-04 125100.png]]
2. Il dispositivo A mette l'informazione da trasferire sulla linea dati e imposta **Req** a 1
   ![[Immagine 2023-05-04 130902.png]]
3. Il dispositivo B si accorge che **Req**=1 , legge quindi dalla linea **DATA** l'informazione presente. Quando l'informazione è stata letta imposta **Ack**=1
   ![[Immagine 2023-05-04 130957.png]]
4. Il dispositivo A si accorge che **Ack**=1 e sa quindi che la lettura è terminata , imposta **Req** e **DATA** a 0
   ![[Immagine 2023-05-04 131024.png]]
5. Il dispositivo B si accorge che **Req**=0 e imposta quindi **Ack** a 0
   ![[Immagine 2023-05-04 131044.png]]

## Arbitraggio

Se il bus è condiviso da più di due dispositivi si rende necessario un arbitraggio del **bus** per evitare conflitti 

Chi può iniziare una transazione sul **bus** è detto **master** del **bus**
I dispositivi che competono per l'uso del **bus** hanno linee aggiuntive che li collegano all'**arbitro** del **bus** , queste linee permettono di effettuare la richiesta , assegnazione e rilascio del **bus**

### Daisy Chain

Esempio :

I richiedenti sono posti in catena in funzione della loro priorità
![[Immagine 2023-05-04 131213.png]]

1. Quando un device deve trasmettere imposta a 1 la linea _request_ . La richiesta arriva all'**arbitro** che però non sa chi l'ha effettuata ( la linea _request_ è condivisa )
2. L'**arbitro** imposta quindi _grant_ a 1 che viene intercettato dal primo device nella catena 
3. Il device 1 può decidere se prendere lui il controllo del **bus** oppure propagare il segnale _grant_ al device sucessivo
4. Se viene propagato il device che ha fatto la richiesta riceve il segnale _grant_ e può iniziare a trasmettere
5. Al termine delle operazioni il segnale _release_ viene impostato a 1 e l'**arbitro** imposta a 0 il segnale _grant_

**Vantaggi**
+ _Semplice_ da implementare , richied pochi segnali di controllo
**Svantaggio**
+ _non è fair_ : Un dispositivo ad alta priorità può causare _starvation_ dei dispositivi a bassa priorità

### Altri tipi di arbitri

+ Centralizzato ma con linee multiple di richiesta / rilascio
+ Completamente distribuito ( es: Ethernet )