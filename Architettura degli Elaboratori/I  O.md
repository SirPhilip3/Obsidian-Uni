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


