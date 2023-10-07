# 20/09/2023

## Cos'è un S.O.

Il **Sistema Operativo** è il software che controlla l'hardware 

Un **Sistema Operativo** è un programma che *gestisce e controlla l'esecuzione* di un insieme di applicazioni, agisce come *interfaccia* tra le applicazioni e l'hardware del calcolatore e *gestice le risorse* hardware

Un **Sistema Operativo** è quindi un :
+ **Macchina Astratta** :
	Nasconde i dettagli e le operazioni complesse ( *mascheramento* ) e presenta all'utente una macchina virtuale facile da usare ( *trasparenza* )
+ **Gestore di Risorse** :
	Deve gestire le risorse **HW** in modo da fornire le migliori prestazioni possibili

Le proprietà che deve soddisfare un *SO* sono :
+ Efficenza
+ Robustezza
+ Scalabilità
+ Estensibilità
+ Portabilità
+ Sicurezza
+ Interattività
+ Usabilità
### Modalità

+ **Utente** : Le applicazioni sono in maggior parte runnate in modalità *utente* 
+ **Kernel** : Il S.O. è per la maggior parte runnato in modalità *kernel*

## Storia dei Sistemi Operativi

#### 1° generazione ( 1945 - 1955 )

Caratteristiche principali :
+ Assenza **S.O.**
+ Programmazione in linguaggio macchina ( attraverso schede perforate ) o cablando i circuiti
+ Memorie estremamente limitate ( decine di numeri )

Limiti : 
+ Scarsa affidabilità
+ Chi gestiva la macchina era anche colui che la programmava
+ Complessità d'uso
+ Lentezza

#### 2° generazione ( 1955 - 1965 ) 

Caratteristiche principali : 
+ **Monoprogrammazione** : esecuzione di un *job* ( unità di esecuzione, programma o insieme di programmi ) alla volta
+ Uso di linguaggi ad alto livello : Fortran, Assembly
+ Programmazione attraverso schede perforate
+ Separazione tra programmatore e operatori
+ Semplici **S.O.** 
	+ *Single-stream batch-processing* o *Sistemi operativi batch*
		+ I programmi e i dati venivano caricati in sequenza su un nastro
		+ Spostati sul computer e eseguiti a lotti ( *Batch* )
		+ Ouput stampato su nastro 
		
![[Immagine 2023-09-20 173300.png]]

+ Utilizzo del **JCL** ( *Job Control Language* ) per lanciare batch o sottoprocessi example :

![[Pasted image 20230920175249.png]]

+ Esempio di utilizzo della memoria per un sistema batch

![[Pasted image 20230920175351.png]]
#### 3° generazione ( 1965 - 1980 )

Caratteristiche principali :
+ **Sistemi operativi batch**
+ **Multiprogrammazione** : 
	+ Più job in esecuzione *contemporanea*, 1 solo job può essere svolto per unità di tempo dalla CPU, quando un job richiede l'utilizzo dell' I/O, delle memorie o viene stoppato alla CPU viene assegnato un ulteriore job
+ Utilizzo di *circuiti integrati*
+ Utilizzo di linguaggi ad alto livello ( C )
+ Editor testuali e grafici
+ **CPU** scheduling ( scheduling dei processi per ottimizzarne il tempo di esecuzione )
+ **SPOOL** ( *Simultaneous Pheripherials Operation On-Line* ) 
	+ Esecuzione di job parallela ad operazioni di I/O
+ Memory partitions ( dovuta alla *multiprogrammazione* )

![[Pasted image 20230921130856.png]]

+ Sistemi **Timesharing**
	+ Variante della *multiprogrammazione* per supportare utenti multiplici
	+ Il tempo di *CPU* è diviso in *quanti di tempo*
		+ Alla fine di ogni *quanto* il job viene interroto e il prossimo *quanto* viene assegnato al prossimo job ( con più utenti diminuisce il tempo di risposta poichè ogni utente deve aspettare meno per l'esecuzione di un job )
		+ Frequenti *cambi di contesto* : richiedono tempo 
		+ Introduzione della **Memoria virtuale** per gestire in sicurezza i vari job ( nessun job dovrebbe accedere alla memoria di un altro job )
+ Sistemi **real-time** 
	+ Hanno una deadline entro la quale un processo deve essere terminato ( differenti algoritmi di *scheduling* )
	+ 2 tipologie di sistemi *real-time*
		+ **Hard real time** : la deadline è fissa , senza alcun margine 
		+ **Soft real time** : la deadline ha un delta dinamico entro il quale può essere termianto il job

Un sistema *timesharing* può anche essere *multiprogrammato*

Sviluppo dei protocolli **TCP/IP** ( *Transmission Control Protocol/Internet Protocol* )

#### 4° generazione ( 1980 - present )

Sviluppo del modello di elaborazione *Cliente/Servente* ( *Client/Server* ) 

Sviluppo del **Multithreading** : esecuzione di più istruzioni contemporaneamente ed in modo indipendente

Sviluppo di sistemi *Distribuiti* : Vari computer collegati ad una rete che cooperano per un obbiettivo comune 

Sviluppo di sistemi *Paralleli* : sistema costituito da un insieme di unità di elaborazione , condivione di risiorse tra di loro  

Utilizzo della teconologia a **oggetti** per sviluppare i sistemi operativi ( *Sistemi operativi orientati agli oggetti* , **OOOS** ) , consente modularità facilmente mantenibili e estensibili

Creazione del progetto **GNU** e **OSI** ( *Open Source Initiative* ) : 
+ Open source operating systems : *Linux* , *Apache Web server*
+ Migliora il debugging , testing e advancement del software ( visto che tutti possono lavorarci ) 
+ Adattabilità a vari ambienti di utilizzo

Creazione di **GUI** per migliorare l'esperienza utente 
Introduzione della tecnologia *plug-and-play*

#### 5° generazione ( 1990 - present )

Sviluppo della tecnologia per sistemi *mobili* ( Android , iOS ) 
	Considerando le limitazioni di questi :
	Risparmio energetico mantenendo prestazioni decenti

Sviluppo dell'**IoT**

## Componenti gestiti da SO

Deve gestire componenti *hardware* e *software* : 
+ processori
+ memoria
+ memoria secondaria
+ I/O
+ processi
+ thread
+ file
+ database

### Processori

esegue codice in linguaggio macchina

presenza di *coprocessori* per compiti specifici ( es audio / video )

contengono *registri* ( memorie ad alta velocità vicine al processore , amntengono i dati immediatamenti necessari all'avanzamento di un processo ) 
	ci sono dei registri speciali : ( **PC** ( Program Counter ) , **SP** ( Stack Pointer ) , **PSW** ( [Program Status Word](https://en.wikipedia.org/wiki/Program_status_word) ) che contiene *flags* , bit di confronto quando si usano istruzioni di confronto o flags per **interrupt** di sistema ossia cambiamenti di contesto / errori / modalità del kernel )

lunghezza della *parola* -> lunghezza delle istruzioni ( supporate diverse lunghezze a seconda della macchina )

tempo di esecuzione misurazione in cicli ossia un'oscillazione completa di un segnale elettrico la cui lunghezza è fornita dal *clock* di sistema ( misurata in Hz )

La **CPU** ha 2 modalità di funzionamento :
+ *kernel* ( riservata per funzioni del sistema operativo come managing memoria etcc )
+ *utente* 
Per cambiare tra queste 2 modalità un'applicazione in modalità *utente* può usare l'istruzione **TRAP** per cambiare modalità in *kernel*

#### Miglioramento prestazioni

Le prestazioni di una **CPU** si possono calcolare attraverso la seguente fromula :
$$T = N_i/IPS$$
dove $IPS$ è :
$$IPS=F\times IPC=F/CPI$$
Dove :
+ T : è il tempo di esecuzione
+ $N_i$ : è il numero di istruzioni di un programma
+ IPS : è il numero di istruzioni svolte al secondo
+ F : è la frequanza di clock del processore
+ IPC : sono il numero di istruzioni per ciclo di clock
+ CPI : sono i cicli di clock per istruzioni

Il *T*empo di esecuzione può essere migliorato :
	- Aumentando F
	- Riducendo $N_i$ ( svolto realizzando diverse architetture es : CISC / RISC )
	- Aumentando gli IPC o diminuendo il CPI ( costruendo una *pipeline* o creando una *CPU superscalare* )

![[Pasted image 20231004220324.png]]

Per il miglioramento delle prestazioni possono essere implementati :
+ *Multithreading* ( hyperthreading )
	*una* CPU può mantenere lo stato di due *thread* ( più piccola parte eseguibile di un programma ) se il loro scambio avviene entro 1 nanosec ( in modo che sembrino concorrenti )
+ *Multi core CPU* 
	più processori completi ( *core* ) su un singolo chip 
	questi hanno la memoria L1 non condivisa e possono o no avere anche la memoria L2 condivisa

> [!warning] 
>  Se la memoria è condivisa bisogna fare attenzione che i *thread* non modifichino o accedino a memoria in conflitto 

#### Scheda madre

Scheda che contiene tutti i circuiti elettrici stampati per il collegamento dei vari componenti di un calcolatore inoltre contiene il :
+ **BIOS** ( *Basic Input Output System* ) Software I/O di basso livello per il boot del sistema e gestione delle risorse ( mantenuto in un chip a parte )
+ **Memorie**

### Memoria 

Vi sono vari livelli di memoria che permettono all'utente finale di avere l'impressione di possedere una macchina con molta memoria e veloce 

![[Pasted image 20231004222902.png]]

#### Registri

Sono interni alla CPU , molto veloci 

Capacità :
+ 32x32 bit per CPU a 32 bit
+ 64x64 bit per CPU a 64 bit

Alcuni registri importanti ( oltre a PC , SP , PSW ) :

+ *Base register* 
+ *Limit register*

Limitano inferiormente ( start , *base register* ) e superiormente ( fine , *limit register* ) un processo , limtando così gli indirizzi che può accedere e modificare 
Possono essere utilizzati a coppie per condiviere vari dati con vari programmi per cui :
+ la prima coppia di *base* e *register* (1) sono associati al limite del codice del programma
+ la seconda coppia (2) limita invece i *dati* su cu un programma può operare

![[Screenshot 2023-10-04 230745.png]]
#### Cache

Diversi livelli dal livello più basso , *L1* , interno alla CPU molto veloce ma molto piccolo ; a livelli più alti con sempre più memoria , più distanti dalla CPU e più lenti

La cache è fondamentale per l'aumento delle prestazioni del calcolatore , essa riduce infatti i tempi di accesso alla memoria memorizzando blocchi di dati vicini tra loro che hanno più probabilità di essere acceduti il più vicino possibile alla CPU

Risulta quindi fondamentale trovare le adatte :
+ *dimensioni*
+ *politiche* di inserimento e rimozione

Quando un dato è presente in cache si dice *cache hit*

Inoltre la cache è considerata *valida* quando rappresenta correttamente lo stato dei dati nella memoria principale

#### RAM

**RAM** ( *Random Access Memory* )

è una memoria *volatile* e ad acesso diretto

vari tipi di *RAM* : 
+ **DRAM** : ( dynamic ) richiede aggiornamenti continui del circuito per non perdere i dati
+ **SRAM** : ( static ) non richiede aggiornamenti ma è più lenta

La *RAM* è caratterizzata da una *banda* ossia quanti dati possono essere trasferiti per unità di tempo
#### ROM

*Read Only Memory* : 
	non volatile , veloce , economica , programmata dal produttore
#### EEPROM

Memoria *Flash* , *Electronically Erasable* :
	non volatile , riscrivibile , molto più lenta della *RAM*
#### CMOS

memoria volatile che principalmente mantiene dati come la data e l'ora

#### Dischi

Può mantenere grandi quantità di dati a basso costo

Accesso ai dati più lento rispetto alla memoria principale 
+ Movimento meccanico della testa di lettura / scrittura
+ Latenza di rotazione
+ Tempo di trasferimento

è un dispositivo a *blocchi* ( ossia i dati sono conservati in blocchi , per diminuire il delay vengono caricati in memoria più blocchi in modo da diminuire le volte che è necessario accedere ad un disco )

Ogni disco è costituito da varie tracce e ogni traccia è divisa in settori ( l'address per accedere ad un determinato settore deve quindi contenere : n° cilindro , n° disco , n° traccia , n° settore )

![[Pasted image 20231005105729.png]]

Il *controllore* ( *driver* ) è colui che si interfaccia con il **SO** per accedere al disco ( mantenuto su uno o più chip )

Un *driver* puù essere inserito nel sistema operativo in diversi modi :
+ manualmente ( in un chip ) , riavviando la macchina
+ in un file del SO , riavviando la macchina
+ senza riavviare ( *plug-and-play* )

Il *driver* comunica con il SO attraverso dei *registri* che possono essere :
+ mappati nello spazio di indirizzamento del SO ( il SO ci comunica con normali istruzioni come se fossero normali registri su cui può scrivere o leggere )
+ in una porta speciale di I/O ( l'accesso avviene tramite istruzioni speciali )

#### Comunicazione con I/O

##### busy waiting

La CPU attende *attivamente* la fine dell'operazione di *I/O* 
##### interrupt

La CPU invia una richiesta di *I/O* al driver , il driver gestisce la richiesta , nel frattempo la CPU svolge un'altro compito ; alla fine dell'operazione dI *I/O* il driver lancia un'interrupt che viene gestita dall'apposito gestore delle interruzioni

![[Pasted image 20231005125839.png]]
##### DMA ( Direct Memory Access )

Il *DMA* è un chip che svincola il processore dal controllo di alcuni dispositivi di *I/O* 

Nei casi precedenti era la CPU a gestire il trasferimento dei dati , con il *DMA* le periferiche traferiscono direttamente i dati da e verso la memoria , il *DMA* notifica solamente il processore del completamento dell'operazione di *I/O*

### Bus

Il *bus* è un insieme di **tracce** ( collegamenti elettrici ) che trasportano informazioni tra dispositivi hardware

Una **porta** è un *bus* che collega solo 2 dispositivi
Un **canale** *di I/O* è un *bus condiviso* da diveris dispositivi per eseguire operazioni di *I/O* indipendentemente dalla CPU

Esempi : 
+ **FSB** ( *Frontside Bus* ) collega la CPU alla memoria principale ( viene diviso in bus dati e bus indirizzi )
+ **PCIe** ( *Pheripherial Component Interconnect Express* ) collega una CPU a vari dispositi ( veolcità tra 16 e 64 Gbps )
+ **AGP** ( *Accelerated Graphic Port* ) utilizzato per schede grafiche ( no more in use )
+ **DMI** ( *Direct Media Interface* )
+ **SATA** ( *Seral Advanced Tecnology Attachment* ) usato per hard disk 
+ **USB** ( *Universal Serial Bus* )
+ **SCSI** ( *Small Computer System Interface* ) 

![[Screenshot 2023-10-05 131705.png]]

![[Pasted image 20231005132238.png]]

### Tipi di OS

Generalmente un **SO** si interfaccia con le applicazioni attraverso le chiamate di sistema :

![[Pasted image 20231005133127.png]]

La progettazione dei *componenti del SO* dipende dalla funzione che deve svolgere il *SO* es :
+ SO per sistemi *integrati* ( *Embedded* ) 
	+ devono gestire un numero limitato di risorse specializzate 
	+ gestione molto efficente delle risorse 
+ SO per *mainframe* 
	+ devono gestire una grande quantità di *I/O*
	+ fornire servizi come *batch* , *transazioni* , *time-sharing*
+ SO per *server*
	+ gestione di molti utenti
	+ fornire servizi come : *web server* , *archiviazione* , *ISP*
+ SO per *multiprocessore*
	+ gestione del parallelismo dei processi
+ SO *real-time*
	+ devono mantenere prestazioni sufficenti per rispettare le *deadline* dei processi
+ SO per *smart-card* 
	+ gestione di operazioni molto semplici
+ SO per *PC*
	+ singolo utente , molti processi in esecuzione
+ SO per *dispositivi mobili*
	+ gestione di molti sensori , power efficency molto importante
+ SO per *sensori* ( TinyOS )

## Concetti Base

Le architetture degli SO devono considerare :
+ *Prestazioni* 
+ *Protezione* dei dati
	+ Impedire ai processi di accedere a istruzioni privilegiate o a zone di memoria non autorizzate
	+ Ciò avviene attraveso 2 modalità di esecuzione della CPU :
		+ *Modalità utente* ( l'utente può eseguire solo un sottoinsieme di istruzioni ) 
		+ *kernel mode* ( il processo può accedere alle istruzioni e alle risorse privilegiate per conto dei processi )
	+ avviene anche attravero il concetto di *privilegio minimo* ossia ogni processo ha solo i minimi privilegi e accessi
	+ La protezione da errori può avvenire attraverso interrupt 
		+ Un processo potrebbe svolgere operazioni non permesse ( es divisione per 0 o accedere a indirizzi di memoria in cui non può accedere )
		+ Per evitare che un processo monopolizzi il processore vengono lanciate periodicamente interrupt attraverso un *timer* per ridare il controllo dei processi allo *scheduler*

## Avvio del sistema operativo

+ **Bootstrapping**
	è il caricamento in memoria dei componenti iniziali del sistema operativo
	+ Eseguita dal *Basic Input/Otput System* ( **BIOS** ) ( modernamente dall'*EFI* ( *Extensible Firmware Interface* ) )
		+ Inizializza l'hardware di sistema 
		+ Carica le istruzioni in memoria principale dal *settore* *di* *boot* della memoria secondaria 
	+ Prima di inizializzzare il *boot* il **BIOS** svolge un test sull'hardware ( *Power On Self Test* ) 

![[Pasted image 20231005223556.png]]

## Processi

Un *processo* è un progrmma in esecuzione ed è caratterizzato da :
+ Spazio di indirizzamento 
+ **UID** identificatore unico di utente 
+ Tabella dei processi ( tabella contentente ogni processo in vita con un pointer al suo *descrittore* ; usata dallo *scheduler* per gestire i processi )
+ **IPC** ( *interprocess communication* ) ( ogni processo può comunicare con altri processi per sca,biarsi dati )
+ Ogni processo può creare dei processi figli
+ Ogni processo possiede un *descrittore* di processo che contiene tutte le informazioni necessarie per fare runnare quel processo

Più processi che volgio accedere ad una stessa risorsa possono causare un *deadlock* , ossia uno stallo che non consente ai processi di proseguire , per risolvere questo problema ci sono 2 principali tecniche :
+ *detection* dello stallo e conseguente *kill* dei processi responsabili
+ *prevenzione* dello stallo
## File system

La struttura di un *file system* è tipicamente realizzata ad albero 

![[Screenshot 2023-10-07 162034.png]]

Ogni file è *identificato* univocamente dal suo *path* e ha associato un *descrittore* del file

Se vogliamo leggere un *file system* di un altro dispositivo esterno dobbiamo *montarlo* su una directory del nostro *SO* , in questo modo possiamo accedervi come se fosse una qualsiasi altra cartella del nostro *SO*

![[Screenshot 2023-10-07 164822.png]]

Esistono dei *File speciali* , questi sono utilizzati per trattare i dispositivi di *I/O* come file , scrivendoci e leggendoli si interagisce con essi :
+ *blocchi* ( per dischi )
+ *caratteri* ( per stampanti / modem )
Vengono montati nella directory `/dev` ( nei sistemi *Unix* )

Vi sono anche file detti *Pipe* , utilizzati per la connessione fra 2 processi

![[Pasted image 20231007165102.png]]

## Altre tecnologie

### Plug and Play

Consente ai *Sistemi Operativi* di configurare l'hardware di nuova installazione senza l'interazione dell'utente

Funzionamento :
+ *Identificazione* del nuovo dispositivo al sistema operativo
+ *Comunicare* al sistema operativo le risorse i servizi che il dispositivo richiede per funzionare correttamente
+ Identificazione del *driver* necessario per la configurazione del dispositivo ( la configurazione comporta l'assegnamento per esempio di un canale DMA per comunicare informazioni al SO ) 
### Caches

Memorie veloci che mantengono copie di dati che verranno richiesti dai programmi 
Aumenta la velocità di esecuzione dei programmi 
Vengono utilizzati algoritmi per ottimizzare l'uso della cache ( per l'inserimento e rimozione di blocchi di memoria )
### Buffers

area di *memoria temporanea* che contiene dati durante le operazioni di *I/O*
Questi *buffer* vengono utilizzati per il coordinamento delle comunicazioni tra dispositivi a diverse velocità 
Vengono anche utilizzati per permettere l'elaborazione dei dati in modo *asincrono*
!!!!!!
### Spooling ( Simultaneous Peripheral Operations On Line )

Tecnica di *buffering* in cui un dispoditivo intermedio ( il disco ) è interposto tra un processo e una periferica *I/O* lenta 

Permette ai processi di inviare operazioni di richiesta da una periferica senza aspettare che il dipositivo sia pronto a servire la richiesta
### Memoria Virtuale

Permette di eseguire programmi con richieste di memoria di maggiori dimensioni rispetto alla memoria fisica disponibile
## Chiamate di sistema

Un processo utente attiva le chiamate al sistema operativo ( modalità kernel ) attraverso una *TRAP* , il controllo passa quindi al sistema operativo che svolge le chiamate di sistema , al termine il controllo ritorna all'istruzione sucessiva del processo utente

![[Pasted image 20231007175211.png]]

Esempi di chiamate di sistema in Unix :

|Call|Description|
|---|---|

Differenze con le chiamate di sistema di Windows :

|UNIX|Win32|Description|
|---|---|---|



## Architetture SO

+ Processor *scheduler*
+ Gestore della memoria
+ Gestore della I/O
+ Gestore dell'*Interprocess communication* ( *IPC* )
+ Gestore del File system

l'architettura di un sistema operativo influenza direttamente le priorità di un sistema operativo
Per questo esistono diverse architetture :
### Architettura Monolitica

Ogni componente del sistema operativo è contenuta nel nucleo 
Ogni componente può comunicare direttamente con qualsiasi altra componente , rendendo lo scambio di dati molto veloce 
Ciò la rende una architettura *molto efficente* ma risulta difficilemente estensibile ( difficoltà ad indentificare le fonti degli errori )

![[Pasted image 20231007181517.png]]

### Architettura a livelli

Divisione del nucleo del sistema operativo in *livelli* che svolgono differenti funzioni 

Ogni livello può comunicare solo con strati immediatemente sopra e sotto
Le richieste dei processi potrebbero quindi dover passare attraverso vari strati ( necessitano di ulteriori metodi per spostare le informazioni da un livello ad un altro ) prima di essere completate ( il througthput risulta meno efficente rispetto ai sistemi monolitici )

![[Pasted image 20231007182526.png]]
### Architettura Microkernel

Il kernel fornisce solo *servizi limitati* ( per contenere le dimensioni del kernel e garantirne la scalabilità )
Il sistema risulta quindi avere un elevato grado di modularità , estensibilità e portabilità

è necessario svolgere vari cambi di tra user space e kernel space per svolgere le stesse operazioni ( degradazione delle prestazioni di sistema )

![[Pasted image 20231007182909.png]]



## Macchine virtuali

Sono una *astrazione software* di un sistema di elaborazione , spesso in esecuzione sopra un SO nativo

Permette la coesistenza di diverse istanze di un SO eseguibili contemporaneamente *emulando* hardware e software non presente nel sistema originario

![[Pasted image 20231007212329.png]]

## Sistemi Operativi di Rete e Distribuiti

### Di Rete

Il *SO* viene eseguito in un solo computer ma può utilizzare le risorse di computer collegati alla rete per eseguire i suio processi

### Distribuito

Il *sistema operativo distribuito* è unico e gestisce le risorse di un insieme di sistemi , ciò gli permette di avere una :
+ elevata ridondanza e *tolleranza ai guasti* 
+ trasparenza di accesso per le applicazioni ( non sembra di avere a disposizione risorse replicate )
+ elevate prestazioni 
+ scalabilità

Un esempio di questi sistemi operativi è una rete di tipo client/server

![[Pasted image 20231007214042.png]]

**Middleware** è un software per sistemi distribuiti che permette *interazioni* tra più processi in esecuzione su uno o più computer in una rete ( per sistemi *eterogenei* ( costituiti da macchine diverse fra loro ) ) 

Esempio : *Open DataBase Connectivity* ( *ODBC* )
+ API per accesso a database
+ Permette alle applicazioni di accedere ai database distribuiti tramite il *driver* *ODBC*

