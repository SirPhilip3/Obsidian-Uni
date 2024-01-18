## Cos'è un S.O.

Il **Sistema Operativo** è il software che controlla l'hardware 

Un **Sistema Operativo** è un programma che *gestisce e controlla l'esecuzione* di un insieme di applicazioni, agisce come *interfaccia* tra le applicazioni e l'hardware del calcolatore e *gestice le risorse* hardware

Un **Sistema Operativo** è quindi una :
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
+ ***Mono*programmazione** : esecuzione di un *job* ( unità di esecuzione, programma o insieme di programmi ) alla volta
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

contengono *registri* ( memorie ad alta velocità vicine al processore , mantengono i dati immediatamenti necessari all'avanzamento di un processo ) 
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
+ F : è la frequenza di clock del processore
+ IPC : sono il numero di istruzioni per ciclo di clock
+ CPI : sono i cicli di clock per istruzioni

Il *T*empo di esecuzione può essere migliorato :
	- Aumentando $F$
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

Limitano inferiormente ( start , *base register* ) e superiormente ( fine , *limit register* ) un processo , limitando così gli indirizzi che può accedere e modificare 
Possono essere utilizzati a coppie per condiviere vari dati con vari programmi per cui :
+ la prima coppia di *base* e *register* (1) sono associati al limite del codice del programma
+ la seconda coppia (2) limita invece i *dati* su cui un programma può operare

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

Un *driver* può essere inserito nel sistema operativo in diversi modi :
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
Un **canale** *di I/O* è un *bus condiviso* da diversi dispositivi per eseguire operazioni di *I/O* indipendentemente dalla CPU

Esempi : 
+ **FSB** ( *Frontside Bus* ) collega la CPU alla memoria principale ( viene diviso in bus dati e bus indirizzi )
+ **PCIe** ( *Pheripherial Component Interconnect Express* ) collega una CPU a vari dispositi ( velocità tra 16 e 64 Gbps )
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

Un *processo* è un programma in esecuzione ed è caratterizzato da :
+ Spazio di indirizzamento 
+ **UID** identificatore unico di utente 
+ Tabella dei processi ( tabella contentente ogni processo in vita con un pointer al suo *descrittore* ; usata dallo *scheduler* per gestire i processi )
+ **IPC** ( *interprocess communication* ) ( ogni processo può comunicare con altri processi per scambiarsi dati )
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

Tecnica di *buffering* in cui un dispositivo intermedio ( il disco ) è interposto tra un processo e una periferica *I/O* lenta 

Permette ai processi di inviare operazioni di richiesta da una periferica senza aspettare che il dipositivo sia pronto a servire la richiesta
### Memoria Virtuale

Permette di eseguire programmi con richieste di memoria di maggiori dimensioni rispetto alla memoria fisica disponibile
## Chiamate di sistema

Un processo utente attiva le chiamate al sistema operativo ( modalità kernel ) attraverso una *TRAP* , il controllo passa quindi al sistema operativo che svolge le chiamate di sistema , al termine il controllo ritorna all'istruzione sucessiva del processo utente

![[Pasted image 20231007175211.png]]

>[!todo]
>completa tables
>#todo

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

## Processi

I sistemi operativi hanno il compito di svolgere le seguenti operazioni su un processo :
+ *creazione*
+ *distruzione*
+ *sospensione*
+ *ripresa*
+ *risveglio*

La CPU è assegnata a turno ad un processo per volta ( *pseudo-parallelismo* )  

Lo spazio di indirizzamento di un processo è diviso in varie regioni :
+ **Testo** : contiene il codice che deve essere eseguito dal processore
+ **Dati** : contiene le variabili e la memoria allocata dinamicamente
+ **stack** : memorizza istruzioni e variabili locali per le chiamate di procedura attive

### Creazione di processi

Avviene :
+ All'inizializzazione del sistema
+ dopo una chiamata di sistema di creazione di un processo
+ dopo una richiesta di un utente per la creazione di un processo

Processi di sistema :
+ Attivi ( collegati ad utenti )
+ in background ( non associati ad utenti ma con funzioni specifiche ) chiamati *demoni*

Comandi per la creazione di processi :
**Fork** in *Unix* 
+ crea un clone del processo chiamante 
+ il processo figlio ha una copia dello spazio di indirizzamento del padre ( spazi distinti )
+ per differenziarsi il processo figlio esegue un *execve* per cambiare la propria immagine di memoria

**CreateProcess** in *Windows*
+ Creazione di un nuovo processo con una nuova immagine di memoria 

I processi *Padre-Figlio* possono condividere delle risorse

### Chiusura di Processi

La chiusura di un processo avviene quando : 
+ Uscita autonoma del programma
+ Uscita per errore nel programma ( rimane volontaria da parte del processo )
+ Errore critico ( uscita eseguita dal sistema operativo )
+ Uscita forzata da un altro processo

Chiamate di sistema per la chiusura di un programma :
*Unix* :
+ `exit` 
*Windows* : 
+ `TerminateProcess`

### Gerarchie

Il processo che genera un altro processo : *Padre*
Il processo creato è chiamato : *Figlio*

Quando un processo *padre* viene distrutto il SO può rispondere in 2 modi differenti :
+ Distruggere tutti i processi figli di quel genitore
+ Consentire ai processi figli di procedere indipendentemente dai loro genitori

In *Unix* viene creato il *Process group* che contiene il processo padre e tutti i suoi discendenti
In *Windows* non c'è il concetto di gerarchie ma il processo padre ha un `handle` che gli permette di controllare il figlio

### Ciclo di vita

Un processo può essere in vari stati :
+ **Running** ( in esecuzione ) : il processo è in esecuzione su un processore
+ **Ready** ( pronto ) : il processo potrebbe essere posto in esecuzione su un processore se ve ne fosse uno disponibile
+ **Blocked** ( bloccato ) : il processo è in attesa di qualche evento che deve accadere prima che possa proseguire

Il SO mantiene una lista *ready* e una *blocked* per mantenere i riferimenti ai processi non in esecuzione

![[Pasted image 20231008115537.png]]

Il *Dispatching* : assegnamento di un processore al primo processo nella lista *ready*

Il SO può impostare un *timer a intervalli* per fare in modo che un processo non venga eseguito per un tempo troppo lungo

Transizioni di stato dei processi :
+ *ready* -> *running* : quando il processo è *dispatched*
+ *running* -> *ready* : quando un processo termina il suo tempo di CPU
+ *running* -> *blocked* : quando il processo viene bloccato per attesa di un evento
+ *blocked* -> *ready* : quando è avvenuto quell'evento per il quale era *blocked*

![[Pasted image 20231008120024.png]]

### Descrittori di Processo

In inglese : *Process Control Blocks ( PCBs )* mantiene le informazioni necessarie all'OS per gestire il processo :
+ Process identificator number ( *PID* )
+ *Stato* del processo ( *ready* , *running* , *blocked* )
+ *Program counter* ( PC )
+ *Stack pointer* ( SP )
+ Priorità del processo nello scheduling
+ Diritti ( r,w,e per i vari utenti )
+ Pointer al processo padre
+ Pointer ai processi figli
+ Pointer per localizzare i dati e le istruzioni in memoria
+ Pointer alle risorse allocate

La **Tabella dei Processi** mantiene dei pointers ai *PCB* di ogni processo divisi in 2 tabelle :
+ *sistema* : contiene i processi legati al *sistema operativo*
+ *utente* : contiene i processi legati ad un utente

Quando un processo termina il SO rimuove il processo dalla tabella dei processi e libera tutte le risorse legate a quel processo ( fa garbage collection )

### Sospensione

Un processo può essere *sospeso* per motivi di sicurezza o di debugging

Quando un processo viene *sospeso* viene rimosso dalla contesa per il tempo sulla CPU senza distruggerlo 

Una sospensione può essere richiesta da se stesso o da un altro processo ma il suo riavvio ( *risveglio* ) può essere effettuato solo da un altro processo

Vi sono 2 stati di sospensione : 
+ *suspendedready*
+ *suspendedblocked*
La scielta tra i due tipi di sospensione riguarda lo stato del processo dove viene sospeso : se era nello stato *ready* al momento della sospensione allora otterrà lo stato di *suspendedready* altrimenti se era nello stato *blocked* otterrà lo stato *suspendedblocked*

![[Pasted image 20231011225755.png]]

### Context Switch

Viene eseguito dal SO per fermare l'esecuzione di un processo *running* e iniziare l'esecuzione di un processo *ready*

Svolgimento :
+ SO toglie il processo dalla CPU salvandone il contesto di esecuzione nel suo *PCB*
+ SO carica il nuovo processo grazie ai dati presenti nel *PCB* del processo *ready*

Il tempo necessario per svolgere queste operazioni è un tempo "morto" per la CPU , ossia non viene fatto alcun calcolo per l'avanzamento di un processo , per questo il tempo di *contex switch* deve essere ridotto al minimo 

Questo processo può essere eseguito in hardware per alcune architetture

![[Pasted image 20231012101645.png]]

### Prestazioni CPU

Le prestazioni di una CPU possono essere calcolate in termini di *utilizzazione* della CPU 
L'utilizzazione dipende dal grado di *multiprogrammazione* , infatti se vi sono più processi in *ready* la CPU sarà maggiormente occupata.

L'utilizzazione della CPU dipende anche principalmente dal tempo che un processo è in attesa di I/O , infatti in quel tempo la CPU può svolgere un altro processo

Quindi considerando : 
+ $n$ processi in memoria
+ $p$ frazione di tempo in cui un processo è in attesa di I/O

Avremo che l'*utilizzazione* della CPU potrà essere calcolcata con la seguente formula :
$$1-p^n$$
In grafico :
20% di attesa di I/O -> blu
50% di attesa di I/O -> rosso
80% di attesa di I/O -> verde
```functionplot
---
title: 
xLabel: Grado di multiprogrammazione
yLabel: Utilizzo della CPU ( in percentuale )
bounds: [0,11,0,1]
disableZoom: true
grid: true
---
20(x)=1-0.2^x
50(x)=1-0.5^x
80(x)=1-0.8^x
```


### Interrupts

Le *interrupts* abilitano il software alla ricezione di segnali hardware

Una *interrupt* può essere iniziato da un processo in esecuzione :
+ Questo tipo di interrupt viene chiamato *trap*
+ è *sincrono* con le operazioni del processo
+ Avviene per esempio con divisione per zero o quando il programma si riferisce ad aree di memoria protette

Una *interrupt* può essere avviata da qualche evento che può non essere collegato al processo in esecuzione : 
+ è *asincrono* con le operazioni del processo
+ Esempi : un tasto viene premuto su una tastiera o viene mosso un mouse

*Polling*
	Il *polling* è un approccio alternativo all'interruzione del flusso delle operazioni in CPU :
	Il processore richiede ad intervalli regolari lo stato di ogni dispositivo di I/O
	Se il sistema diventa complesso l'*overhead* *aumenta*

#### Gestione dell'interrupt

Dopo aver ricevuto una *interrupt* la CPU completa l'esecuzione dell'istruzione corrente sucessivamente interrompe il processo corrente 

Il processore chiama il *gestore degli interrupt* che determina come il sistema deve rispondere a quella specifica interruzione 

I vari puntatori ai gestori delle interruzioni sono memorizzati in un array detto ( *vettore di interrupt* )

Dopo aver gestito correttamente l'interruzione il SO ripristina il processo interrotto in precedenza oppure viene eseguito il processo sucessivo ( se il precedente non può continuare o aveva finito di eseguire )

I passi completi per la gestione di un interruzione sono :
1. l'hardware mette nello *stack* il *PC* ( salva lo stato del processo )
2. l'hardware carica il nuovo *PC* dal *vettore di interrupt* ( carica il gestore delle interrupt )
3. Una procedura in *assembly* salva i registri
4. Una procedura in *assembly* imposta il nuovo *stack*
5. Si esegue la procedura per la *gestione dell'interrupt* ( scritta in C )
6. Lo *scheduler* viene attivato per selezionare il prossimo processo da eseguire
7. La procedura in C restituisce il controllo al codice in assembly
8. La procedura in assembly avvia il nuovo processo da eseguire

![[Pasted image 20231012132701.png]]

#### Classi di Interrupt

Le *interrupt* supportate dalla architettura del sistema 

Esempio :  Intel IA-32 ( x86 ) distingue 2 tipi di segnali che possono essere ricevuti dal processore :
+ *Interrupts* : notifica il processore che si è verificato un evento e che lo stato di un dispositivo esterno è cambiato ( viene generata da un dispositivo esterno al processore )
+ *Eccezioni* : Indicano quando si è verificato un errore ( hardware o come risultato di un'istruzione software ) , vengono classificate come : *faults* , *traps* , *abort*

##### Interrupt in x86

+ **I/O** :
	L'interrupt di *I/O* è lanciata da un hardware di *I/O* per notificare al processore una variazione di stato di un canale ( es fine operazione di *I/O* ) o di una periferica
+ **Timers** :
	Sono *interrupt* generati periodicamente da periferiche , vengono usate  per gestire il tempo o per monitorare le prestazioni
+ **Interruzione per IPC** :
	Avviene quando un processo invia messaggi ad un altro processo , nei sistemi multiprocessori vi possono essere più processi contemporanemanente in esecuzione

##### Exceptions in x86

+ **Fault** : Avviene quando si svolge un'operazione non consentita :
	+ divisione per zero
	+ tentare di eseguire un codice di operazione non valido
	+ utilizzo di dati in formato errato
	+ tentativo di accedere ad una zona di memoria proibita
	+ tentativo di eseguire da parte di un processo utente di istruzioni kernel
	+ riferimento a delle risorse protette
+ **Trap** : Generate da eccezioni come overflow o durante il debugging alla presenza di un breakpoint nel codice
+ **Abort** : Viene generata quando il processore identifica un errore dal quale non si può recuperare l'esecuzione del processo :
	Può avvenire nel caso di *double-fault* ossia quando il controller delle eccezioni esso stesso genera un'eccezione , la risoluzione dei *fault* in questo caso non può essere portata a termine sequenzialmente portando quindi alla terminazione del processo che l'ha attivata

### Interprocess communication

La comunicazione tra processi è fondamentale per consentire ai processi di scambiarsi informazioni o per cooperare e raggiungere un obbiettivo comune ( per esempio distributed rendering )

La comunicazione è basata sullo scambio di *messaggi* 

I *messaggi* possono essere trasmessi in una direzione sola ( da processo *mittente* a *destinatario* ) 

Lo scambio di messaggi può essere bidirezionale ossia ogni processo può agire sia come *mittente* che come *ricevitore*

I *messaggi* possono essere :
+ **bloccanti** : richiede al *ricevente* di notificare al *mittente* quando viene ricevuto il messaggio , il processo mittente viene bloccato fino alla ricezione di questa notifica
+ **non bloccanti** : permette al mittente di continuare ulteriori elaborazioni poichè non viene bloccato per aspettare la notifica di ricezione del messaggio

L'implementazione più comune per i messaggi è la *pipe* ossia si utilizza una regione di memoria protetta dal SO che funge da *buffer* consentendo ai due o più processi di scambiarsi dati 

#### IPC in sistemi distribuiti

In sistemi distribuiti i *messaggi* trasmessi possono essere corrotti o persi più facilmente per questo ci sono :
+ *protocolli di conferma* che confermano che le trasmissioni siano state effettuate correttamente ( aknowledgment )
+ meccanismi di *timeout* per fare in modo che se un messaggio non viene ricevuto entro un determinato lasso di tempo esso venga *ritrasmesso*

Inoltre per fare in modo che i messaggi vengano ricevuti dai processi corretti al processo ricevente viene assegnata una *porta* numerata dove ascolta per la ricezione del messaggio 

Deve inoltre essere sviluppato un sistema di autenticazione per garanitre la sicurezza dei dati ( in modo che un processo non possa fingersi un'altro )

#### Segnali

I *segnali* sono interruzioni software che notificano ad un processo l'avvenimento di un evento

I *processi* possono *ricevere* , *ignorare* o *mascherare* un segnale
+ **ricevere** un segnale e quindi lancia una ruotine per la gestione di quel segnale 
+ **ignorare** un segnale ossia scartarlo
+ **mascherare** un segnale significa che il SO non consegnerà più segnali di quel tipo fino a quando il processo non cancella il *mascheramento* di quel segnale

### Caso di studio : processo UNIX

Tutti i *processi* hanno un insieme di indirizzi di memoria ( spazio di indirizzi virtuali )

Il *PCB* di un processo è mantenuto dal *kernel* in una regione protetta della memoria che i processi utente non possono accedere

In *UNIX* il *PCB* memorizza :
+ Il contenuto dei registri del processore
+ PID
+ Il Progam Counter
+ Lo *stack* si sistema

Tutti i processi sono elencati nella *tabella dei processi*

I processi possono interagire con il SO attraverso *chiamate di sistema* 

Un processo può generare un processo figlio attraverso la chiamata di sistema *fork* che crea una copia del processo padre
+ Il processo figlio riceve una *copia* delle risorse del genitore
+ I file aperti dal processo padre sono condivisi con il figlio
+ La *fork* restituisce il PID del figlio al genitore

Ogni processo ha una *priorità* ( per lo scheduling ) che è indicata da numeri interi tra -20 a 19 ( con -20 si indica la priorità più alta di scheduling ) 

*UNIX* fornisce i *pipes* per consentire il trasferimento di dati tra processi

Esempio di chiamate di sistema UNIX :

|**Chiamata di sistema**|**Descrizione**|
|---|---|
|`fork`|Crea un processo figlio e alloca una copia delle risorse del processo padre al figlio|
|`exec`|Carica da un file le istruzioni e dati di un processo nel suo spazio di indirizzamento|
|`wait`|Il processo chiamante si blocca fino a quando il processo figlio non ha terminato|
|`signal`|Permette ad un processo di specificare un gestore di segnalazione per un dato tipo di segnale|
|`exit`|Termina il processo chiamante|
|`nice`|Modifica la priorità del processo usata dallo scheduling|


## Threads

### Introduzione

I *thread* vengono sviluppati per :
+ Rappresentare in modo più naturale le attività *parallele* ( o *concorrenti* )
+ Per migliorare le prestazioni in sistemi *multiprocessore* 
	+ Il *thread* è infatti più leggero del *processo*
	+ Miglior utilizzo della CPU se i *thread* sono I/O bound ( poichè ci sono altri thread non I/O bound dello stesso processo che posso eseguire nel mentre )
+ Poichè essi condividono lo spazio degli *indirizzi* e dei *dati* vi è riduzione dell'overhead dovuto al *context switch*

### Definizione

Viene considerato un *lightweigth process* ( *LWP* )

Condividono con il loro processo d'origine lo spazio di *indirizzamento* , *file* aperti ed altre informazioni globali ( non è rischiesto al SO di inizializzare questi dati riducendo l'overhead di *creazione* e *terminazione* )

I *thread* hanno delle infomazioni che sono locali ad ogni *thread* come : Registri , stack , maschere dei segnali etcc ( *Thread Specific Dara* ( *TSD* ) )

I *thread* possono essere getiti da :
+ *SO*
+ da un'applicazione utente

![[Pasted image 20231020183053.png]]

Un *thread* si sposta fra degli *stati discreti* ( come un *processo* , possiedono infatti stati in comune come : creazione , terminazione , ripresa e sospensione ) 

In sistemi con un unico processore i thread runnano paralleli in modo virtuale ( la CPU può supportare un thread alla volta quindi scambia molto velocemente tra 2 thread in modo che sembrino essere svolti in parallelo )

### Stati 

Gli stati di un *thread* possono essere conderati analoghi a quelli di un processo , gli stati sono :
+ *Born*
+ *Ready* ( *pronto* )
+ *Running* ( *in esecuzione* )
+ *Dead*
+ *Blocked* ( thread bloccato da un evento di I/O )
+ *Waiting* ( thread bloccato poichè sta aspettando il finire di una evento di un'altro thread )
+ *Sleeping* ( Blocco di un *thread* per un determinato periodo di tempo )

![[Pasted image 20231021144706.png]]

### Operazioni sui Thread

+ **Cancellazione** 
	+ Questa operazione indica che un thread dovrebbe essere eliminato ma non è garantito che lo sarà ( viene mantenuta in memoria la sua tabella di stato )
	+ i thread possono disabilitare o mascherare i segnali di cancellazione ( eccetto il segnale di *abort* )
+ *Join*
	+ Normalmente se un *thread* crea un'altro thread ( diventa quindi *thread primario* ) quando il thread padre termina allora anche tutti i suoi figli terminano
	+ Se il *thread primario* fa un *join* con i suoi thread figli allora prima di terminare deve aspettare che anche i thread figli abbiano terminato la loro esecuzione [Thread](https://pages.mtu.edu/~shene/NSF-3/e-Book/FUNDAMENTALS/thread-management.html) 

### Standard POSIX

Implementati nella liberia *Pthread*

I *thread* possiedono :
+ un identificatore
+ un insieme di registri ( PC , ... )
+ un insieme di attribuiti ( parametri per lo scheduling , stack , etcc... )

Alcune chiamate presenti in *Ptherad* :

|*Chiamata*|*Descrizione*|
|---|---|
|`Pthread_create`|Crea un nuovo thread|
|`Pthread_exit`|Termina il thread chiamante|
|`Pthread_join`|Attende che un thread specifico esca|
|`Pthread_yield`|Rilascia al CPU perchè venga eseguito un altro thread|
|`Pthread_attr_init`|Crea e inizializza la struttura attributi di un thread|
|`Pthread_attr_destroy`|Rimuove la struttura attribuiti di un thread|

### Modelli di Thread

+ Thread di livello *utente*
+ Thread di livello *kernel*
+ Thread *ibridi* tra livello utente e kernel

#### Thread di livello Utente

I thread a livello utente svolgono operazione nello spazio utente , per questo non possono eseguire istruzioni privilegiate o accedere direttamente al nucleo

*Implementazione* :

- Mapping dei thread *molti-a-uno* : 
	- Il SO associa tutti i thread di un processo multithread ad un *unico contesto di esecuzione* a livello *kernel*

+ **Vantaggi** :
	+ Le librerie di livello utente possono *schedulare* i thread per ottimizzare le prestazioni
	+ Non c'è bisogno del *context switch* per la sincronizzazione dei threads ( poichè viene tutto svolto a livello utente )
	+ Possono essere utilizzati anche in sistemi dove il SO non supporta il CPU multithreading
	+ *Più portabile* visto che lo sviluppo dei thread è svolto da liberie utente e non dipendente da API di sistema 

+ **Svantaggi** :
	+ Il *kernel* vede un processo multithread come un singolo *thread* di controllo
	+ Se un thread deve attendere una risposta dall'I/O non è possibile cambiare thread nello stesso processo
	+ Non possono essere *schedulati* su più processori alla volta

![[Pasted image 20231021153318.png]]

I *thread a livello utente* sono raggrupati per ogni processo in una *tabella di thread* 

La *tabella dei thread* viene gestita da uno scheduler ad hoc che mantiene inoltre una lista dei thread bloccati e la lista dei thread pronti ( come nella tabella dei processi ) 

![[Pasted image 20231021153912.png]]

#### Thread di livello Kernel

I thread a livello nucleo mappano ogni thread al proprio contesto di esecuzione ( mapping *uno-a-uno* ) , ogni processo ha quindi vari contesti di esecuzione

+ **Vantaggi** :
	+ Aumento del *throughput* , infatti poichè questi hanno spazi di esecuzione differenti , se un thread è impattato da una operazione di I/O posso svolgere un thread diverso maanche di processi differenti
	+ Aumento della *scalabilità* : questa tipologia di thread si comporta maggiormente come una soluzione multithreaded ( i thread possono essere posti in scheduling su diversi core )
+ **Svantaggi** :
	+ *Overhead* dovuto ai cambi di contesto che devono essere effettuati se devo effettuare operazioni sui thread 
	+ Ridotta *portabilità* poichè questi thread sono specifici per un SO

![[Pasted image 20231021160628.png]]

Non occorre una tabella di thread per ogni processo , è il *kernel* stesso che gestisce e mantiene la *tabella di thread*

Per diminuire l'*overhead* dovuto alle chiamate di sistema i contesti di esecuzione dei thread non vengono eliminate dopo la terminazione di un thread ( il thread viene solo contraddistinto come terminato nella tabella dei thread ) in modo da riclarle

Lo *scheduler* essendo implementato a livello del nucleo è meno flessibile di quello dei thread a livello utente poichè non può essere adattato a situazioni differenti tra loro , in complesso se un thread è bloccato esso non blocca l'intero processo ed altri thread possono essere mandati in esecuzione

![[Pasted image 20231021161310.png]]

#### Thread Ibridi

I thread *ibridi* sono la combinazione dell'implementazione dei thread di livello utente e quelli di livello kernel

+ I thread sono mappati *molti-a-molti*
	+ Il numero di thread di livello utente e livello kernel non deve per forza essere uguale
	+ Riduce l'*overhead* rispetto al mapping *uno-a-uno* implementando il *thread pooling* ( ossia l'assegnazione di thread utente ad un determianto thread kernel ( *worker thread* ) )

Per diminuire l'overhead dovuto dei thread a livello del nucleo utilizziamo i :
+ *Worker threads*
	+ Sono dei thread a livello nucleo *persistenti* che occupano il *pool* di thread
	+ Diminuisce l'overhead dovuto alla creazione e distruzione di thread a livello nucleo , infatti a livello nucleo necessitiamo di chiamate a sistema per svolgere queste funzioni , mantenendo sempre in attesa un certo numero di thread per essere assegnati a dei thread utente ( che sofforono in modo minore dell'overhead dovuto alla creazione e distruzione ) diminuiamo notevolmente il numero di volte che dobbiamo creare e distruggere un thread al livello del nucleo

Per aumentare invece la *flessibilità* dello scheduler si utilizza la tecnica dell'*attivazione dello scheduler* :
+ Permette ad uno *scheduler* di livello utente di gestire i thread a livello utente
+ Ad ogni processo vengono assegnati dei processori virtuali su cui fare lo scheduling a tempo di esecuzione 
+ Se si presenta una situazione di thread bloccato nel kernel questo viene notificato allo scheduler utente ( *upcall* ) che cambierà il thread in esecuzione

>[!todo]

![[Pasted image 20231021171208.png]]

#### Thread Pop-Up

Un *thread pop-up* è un thread che viene creato per la gestione di messaggi in arrivo da parte di altri processi ( anche in processi collegati ad una rete )

![[Pasted image 20231021171659.png]]

#### Conflitti tra Thread 

Poichè i *thread* hanno in comune lo spazio di indirizzamento potrebbero agire contemporanemente sullo stesso dato ( ovviamente ciò si applica solo a dati che hanno entrambi accesso come le *variabili globali* ) 

Es : 
![[Pasted image 20231021172150.png]]

Le possibili soluzioni a questo problema portebbero essere : 
+ vietare la modifica delle variabili globali ai thread
+ utilizzare solo variabili globali private ( ossia una copia presente in ogni thread )

### Thread in Linux

In *linux* non vi è differenza tra i processi e i thread ( chiamati *Task* ) , essi infatti hanno lo stesso descrittore di processo 

Per costruire un descrittore di una *Task* si utilizza la chiamata di sistema `Task_struct`

Per generare *Task* figli si utilizza la chiamata di sistema `fork`

Per abilitare una *Task* come *thread* linux fornisce una verisione modificata di `fork` chiamata `clone` , questa chiamata accetta argomenti che permettono di specificare che risorse condividere con tra il *Task padre* e il *task figlio*

Le *task* in linux passano anchesse attraverso vari stati :

![[Screenshot 2023-10-21 172903.png]]

Un *task zombie* è un task che è contrassegnato come da uccidere ma vengono momentanemente mantenuti in memoria il suo stato per poter essere riutilizzato

Inoltre in *linux* vi è una differente divisione del tempo rispetto a *windows* :
+ *epoche* : le epoche sono la somma massima dei tempi di esecuzione in CPU ( es un *task* può svolgere 10 esecuzioni in CPU per un massimo di 1000us , quando avrà terminato queste esecuzioni la sua *epoca* finirà e dovrà quindi aspettare che gli venga asseganta un'altra *epoca* ) 
Questo permette di evitare ancor più maggiormente la monopolizzazione della CPU da parte di un singolo *task*
### Thread in Windows

I processi contegono gli *handle* ( riferimenti ad oggetti ) , i *thread* con cui condividono le risorse e i programmi (??????)
>[!todo]
>completa
>#todo

Il *contesto di esecuzione* di un processo contiene :
+ Runtime stack
+ Lo stato dei registri della macchina
+ Degli attributi
+ Unità di esecuzione reale ( thread ) inviata al processore per l'esecuzione
Questo viene chiamato *PEB* ( *Process Environment Block* )

L'equivalente per un thread viene chiamato *TEB* ( *Thread Environment Block* ) ( contiene tutto ciò necessario ad un thread )

*Windows* può raggruppare vari processi in un *job* , in modo da gestire meglio le risorse per ogni thread relativo a quel *job*

In *windows* i *thread* possono creare le *Fiber* ( gestiti a livello utente )
+ Un *fiber* viene eseguito nel contesto del *thread* che lo crea ( vengono infatti gestiti dal programmatore anzichè dallo scheduler )
+ I *thread* possono essere converiti in *fiber* , le *fiber* possono essere creati indipendentemente dai *thread*
+ Hanno un bassissimo overhead per il cambio di contesto visto che lavorano a livello utente con risorse condivise

La relazione tra *thread* e *fiber* è *molti-a-molti* ( normalmente un thread è associato ad un insieme di fiber )

*windows* utilizza il concetto di *thread worker* che compongono un *pool di thread* di livello *kernel* che eseguono le funzioni previste dai thread utente.
La coda di *task* da eseguire viene servita da questo *thread pool* 
Se un thread si blocca in attesa di eventi esso non può essere riassegnato ad un altro *task* da eseguire 

La transizione tra stati di un *processo* in *windows* è la seguente :
![[Pasted image 20231021180457.png]]


## Scheduler

Un algoritmo di *scheduling* deve decidere quale processo viene eseguito ad un certo istante ,
queste decisioni devono essere prese cercando di raggiungere i seguenti *obbiettivi* :
+ Massimizzare il *throughput*
+ Minimizzare la *latenza*
+ Prevenire la *starvation* di un processo ( attesa infinita )
+ Completare i processo entro una *deadline* ( molto importante in sistemi real-time )
+ Massimizzare l'uso del processore
+ Garantire la *predicibilità* dello scheduling
+ Minimizzare l'*overhead*
+ *Bilanciamento* di tutte le parti del sistema
+ *Equità* : ogni processo deve ricevere la *CPU* in modo equo

Vi sono differenti obbiettivi per lo scheduling di processi differenti :
+ Processi *CPU-bound*
+ Processi *I/O-bound*
+ Processi *batch*
+ Processi *iterattivi*
Inoltre lo scheduling cambia a seconda dei tipi di sistema :
+ Sistemi *Batch*
	+ Massimizzazione del *throughput*
	+ Massimizzare utilizzo della CPU
+ Sistemi *Interattivi*
	+ Minimizzare il *tempo di risposta*
+ Sistemi *Real-Time*
	+ Rispetto delle *scadenze*
	+ *Prevedibilità* dello scheduler ( stabilità delle prestazioni )

### Livelli di scheduling

+ Scheduling di *alto livello*
	Determina che *job* può entrare in competizione per le risorse
	Mantiene il controllo sul numero di processi in esecuzione nel sistema ad un dato tempo
+ Scheduling di *livello intermedio*
	Determina quali *processi* possono competere per il processore
+ Scheduling di *basso livello*
	Assegna le *priorità* ai processi
	Assegna i processori ai processi

### Prelazione

Lo scheduling può essere :
+ *con prelazione*
	I processi possono essere tolti dall'attuale processore
	Si possono avere un miglioramento delle prestazioni ( migliore *tempo di risposta* )
	E' molto importante in ambienti *interattivi* 
+ *senza prelazione*
	I processi sono eseguiti fino al loro completamento
	Processi che richiedono molto tempo possono bloccare altri processi

### Priorità

+ *statica* :
	La priorità viene assegnata alla nascita del processo e non cambia nel tempo
	*facile* da implementare
	*basso* overhead
	*poca* flessibiltà 
+ *dinamica* :
	La priorità può essere cambiata nel tempo
	*elevata* flessibilità
	*maggior* overhead

### Algoritmi di Scheduling

Sono responsabili per decidere :
+ *che* processo eseguire 
+ *quanto* tempo deve essere posto in esecuzione il processo
+ gestire le *interrupt* e i processi che si bloccano ( per I/O etcc )

Deve fare scelte su : 
+ *prelazione*
+ *priorità*
+ *tempo di esecuzione*
+ *tempo fino al completamento*
+ *equità*

#### FIFO ( First-In-First-Out )

I processi vengono posti in esecuzione a seconda del loro tempo di arrivo all'interno della coda dei processi pronti 
Non viene utilizzata la prelazione
Molto iniefficente 

![[Pasted image 20231026095649.png]]
#### SJF ( Shortest-Job-First )

Lo scheduler seleziona il processo con il *minimo tempo* stimato *per terminare*

Vantaggi :
+ Il tempo medio di attesa per ogni processo è minore di *FIFO*

Svantaggi :
+ Essendo *senza prelazione* può portare a tempi di risposta lunghi in presenza di richieste interattive
+ Potrebbe protare a *starving* di processi molto lunghi
+ La stima del tempo per terminare può essere scorretta o falsata da un processo per "saltare la coda" 

#### SRT ( Shortest-Remaining-Time-First )

è la versione con *prelazione* di *SJF*

Vantaggi :
+ Ottimo per il tempo medio di risposta

Svantaggi :
+ I processi più corti che arrivano fanno prelazione sui processi in esecuzione 
+ I processi lunghi aspettano ancora di più rispetto a *SJF* ( poichè verrano eseguiti sempre processi e parti di processi più corti prima di lui )
+ *overhead* elevato per il cambio di contesto

#### RR ( Round-Robin )

Basato su *FIFO* 

I processi vengono eseguiti solo per un periodo di tempo limitato detto intervallo o *quanto* di tempo ( prelazione )
La grandezza del *quanto* di tempo deve essere definita in modo da massimizzare l'efficenza della CPU tenendo presente il costo dei cambi di contesto e l'utilizzo della CPU da parte dei processi ( in contrasto con le operzioni di I/O )
+ *grande*
	Degenera nella coda *FIFO* se troppo grande
+ *piccola*
	Elevato *overhead* dovuto ai tempi del cambio di contesto 
+ *media*
	Abbastanza lungo per i processi interattivi per fare richieste di I/O
	Processi *batch* ottengono la maggior parte del tempo di CPU

Vantaggi :
+ Facile da implementare

Svantaggi :
+ Per minimizzare l'overhead di creare nuovi processi è necessario mantenere numerosi processi in memoria
+ Numerosi cambi di contesto

![[Screenshot 2023-10-26 101329.png]]

![[Pasted image 20231026101818.png]]

#### Scheduling a Priorità

I processi sono divisi in *classi di priorità* , I processi appartenenti a classi di maggiore priorità sono eseguiti prima

La priorità può essere :
+ *statica* : determinata all'avvio del processo
+ *dinamica* : cambia nel tempo
	+ *basata sui tempi* : un processo che necessità più tempo di esecuzione ottiene un maggiore priorità
		Es : La probabilità dinamica potrebbe essere impostata come $\frac{1}{f}$ dove $f$ rappresenta la frazione di tempo realmente utilizza dal processo durante il suo quanto di tempo 
	+ *astratta* : a seconda dell'utente che lancia il processo 

Combinazione tra algoritmo *round-robin* e a *priorità*
Si creano varie classi di priorità , all'interno di ogni classe si utilizza l'agoritmo *round-robin* per mandare in esecuzione ognuno dei processi ; prima si mandano in esecuzione i processi con classe di priorità più alta 

Processi con priorità bassa potrebbero non essere mai eseguiti

![[Pasted image 20231026105414.png]]
#### SRR ( Selfish-Round-Robin )

Aumento della priorità con l'età del processo

Possiede 2 code :
+ *Attivo* 
+ *In Attesa*

Un processo nuovo entra nella coda *In Attesa* e più tempo ci rimane più la sua priorità aumenta
Quando la sua priorità è uguale a quella dei processi pronti viene posto nella coda *attivo* e viene quindi applicato il *round-robin*

Possono essere applicate diverse velocità di crescita della priorità a seconda se un processo necessità di essere svolto più velocemente
#### HRRN ( Highest-Response-Ratio-Next )

Considero quanto a lungo un processo aspetta rispetto al suo tempo di esecuzione 
Avremo quindi che la priorità dinamica sarà impostata come :
$$\text{Priorità dinamica} = \frac{\text{tempo di risposta}}{\text{tempo di esecuzione}}$$
dove il $\text{tempo di risposta}=\text{tempo di attesa}+\text{tempo di esecuzione}$

Non ha prelazione ma previene l'attesa infinita da parte di un processo

#### Code multilivello con Feedback

I processi che arrivano per essere eseguiti entrano nella coda di più alto livello e sono eseguiti con priorità maggiore rispetto ai processi di code inferiori

Una volta finito il loro quanto di tempo e non hanno finito il loro processo allora essi vengono declassati alla coda di livello inferiore

Ciò avviene per vari livelli di priorità

In questo modo i processi più brevi e I/O bound hanno una priorità maggiore rispetto a processi più lunghi questi infatti vengono eseguiti solo alla termianzione dei processi più veloci 

Le code sono implementate con *FIFO* ( o *FCFS* ) tranne l'ultima coda che implementa il *round-robin* 

![[Screenshot 2023-10-26 154926.png]]

L'algoritmo per rispondere ai cambiamenti dell'ambiente ( quando un processo ha un comportamento batch e quando diventa interattivo ) sposterà il processo in code di differente priorità per rispecchiare il suo utilizzo da parte dell'utente ( per rilevare questi cambiamenti di comportametno comporta un maggior *overhead* )
#### FSS ( Fair Share )

FSS controlla l'accesso da parte degli utenti delle risorse 
Assicura che gruppi di utenti meno importanti non possano monopolizzare le risorse

Le risorse inutilizzate sono distribuite secondo la proporzione delle risorse già assegnate 

Se un gruppo di utenti non utilizza tutte le risorse assegnate allora potrebbe aumentare la sua priorità in modo che più dei suoi processi vadino in esecuzione aumentando quindi le risorse che utilizza

![[Screenshot 2023-10-26 161735.png]]


#### Scheduling per sistemi Real-Time

I processi devono essere completati entro un certo periodo di tempo

2 tipi di real time scheduling :
+ *Soft real-time* scheduling : 
	+ Non garantisce che i vincoli temporali siano soddisfatti
+ *Hard real-time* scheduling :
	+ I vincoli temporali devono essere sempre soddisfatti

Il *deadline scheduling* è usato quando i processi devono essere completati entro un tempo stabilito ma che se questa deadline non è raggiunta i loro risultati sono inutili

Questo tipo di scheduling è difficile da implementare poichè bisogna conoscere i requisiti delle risorse in anticipo : 
+ Notevole *overhead*
+ Il servizio offerto ad altri tipi di processi degrada 

Gli eventi in sistemi *real-time* possono essere distinti in 2 tipi :
+ *periodici* ( prevedibili )
+ *non periodici* ( non prevedibili )

Dati *m* eventi periodici e sapendo che l'evento *i* avviene durante il periodo $P_i$ e richiede $C_i$ secondi di CPU allora potremmo dire che il sistema è *schedulabile* se : 
$$\sum_{i=1}^m\frac{C_i}{P_i}\le1$$
Gli algoritmi per gestire i sistemi dinamici possono essere : *staici* o *dinamici* :

##### Real-Time scheduling statico

Non si adegua al cambiamento delle priorità nel corso del tempo , adatto a sistemi dove le condizioni cambiano raramente

Risulta avere un basso *overhead*

*Rate-monotonic* ( RM ) scheduling :
	Aumenta la priorità del processo in modo monotono con la frequenza che deve essere eseguito
	L'agoritmo altrimenti è *round-robin* con prelazione e priorità
	Favorisce quindi i processi periodici , eseguiti spesso

*Deadline RM scheduling*
	Utile per i processi periodici che però possono avere scadenze differenti dal loro periodo ( dura 10s scadenza in 12s o 8s )
##### Real-Time scheduling dinamico

Regola le priorità a seconda delle condizioni variate durante l'esecuzione

Può portare ad un *overhead* molto elevato , deve garantire che questo non porti ad un aumento di mancate scadenze 

Le priorità sono di solito legate alla scadenze dei processi 

*Earliest-deadline-first* ( *EDF* )
+ con prelazione
+ scieglie sempre il processo con scadenza più vicina
+ massimizza il throughput e minimizza il tempo di attesa

*Minimum-laxity-first*
+ Basa le priorità sulla *lassità* :
	+ misura il tempo *alla* scadenza del processo ( ossia quanto manca alla deadline )
		$L=D-(T+C)$
		Dove:
			D = deadline
			T = tempo corrente 
			C = tempo di esecuzione rimanente

#### Politica e meccanismo di scheduling

Viene fatta la separazione tra :
+ *maccanismo* di scheduling ( è nel nucleo )
+ *politica* di scheduling ( responsabilià del processo utente poichè è lui che conosce la priorità dei suoi thread )

#### Scheduling di Thread

I thread a livello *utente* di un processo non può essere mischiati con altri *thread* di altri processi poichè questi vivono in un diverso contesto di esecuzione

![[Pasted image 20231026171255.png]]

I thread di livello *kernel* invece non vivendo in un contesto di esecuzione specifico per un processo questi possono essere mischiati con thread di altri processi

![[Pasted image 20231026171350.png]]




## Gestione della memoria

Le memorie che dobbiamo gestire sono : 
+ Memoria *principale*
	+ costosa
	+ capacità limitata
	+ alte prestazioni
+ Memoria *secondaria*
	+ economica 
	+ grande capacità
	+ basse prestazioni

Per far sì che l'utente abbia l'impressione di avere una memoria che :
+ è grande
+ è veloce
+ non è volatile

Si implementano le gerarchie di memoria 
+ Memoria *secondaria*
	+ Memorizza i dati e programmi che non sono necessari al momento
+ Memoria *principale*
	+ Deve memorizzare solo i programmi e dati che sono strettamente necessari al momento
+ Memoria *cache*
	+ Utilizzate per sfruttare la località spaziale e temporale delle istruzioni e dei dati all'interno della CPU 

![[Pasted image 20231030084558.png]]

### Organizzazione della memoria principale

Per ottimizzare lo spazio all'interno della memoria principale dobbiamo rispondere alle seguenti domande :
+ *Quale* processo rimarrà in memoria ?
+ *A quanta memoria* ogni processo ha accesso ?
+ *Dove* posizionare in memoria ogni processo ?

La memoria può essere organizzata in 2 macro modi differenti :
+ Il processo utilizza *tutto* lo spazio in memoria 
+ Ad ogni processo viene assegnata una *partizione* della memoria
	+ questa può essere allocata *staticamente* o *dinamicamente*

Esempi di organizzazione della memoria di un programma con quella del sistema operativo :

![[Pasted image 20231030090551.png]]

Il BIOS poteva essere posto nella *ROM* ( *Read Only Memory* ) nei primi PC ( 3° esempio )

#### Strategie di gestione della memoria

Vi sono diverse categorie di strategie da applicare quando dobbiamo gestire la memoria principale :
+ *fetch*
	+ Quando dobbiamo inserire la prossima sezione di programma e dati in memoria principale ?
	+ 2 principali tipologie di strategie :
		+ a *richiesta* ( spostemento quando viene richiesto dal programma )
		+ a *previsione* ( spostamento quando prevediamo che un programma dovrebbe andare in esecuzione )
+ *posizionamento*
	+ Decide dove inserire dati e programmi nella memoria 
	+ 3 strategie di inserimento principali :
		+ *best-fit*
		+ *first-fit*
		+ *worst-fit*
+ *sostituzione*
	+ Decide quali dati e programmi rimuovere dalla memoria principale 

### Allocazione di programmi in memoria principale

Possiamo avere 2 modi per organizzare i programmi in memoria principale :
+ Allocazione *contigua*
	+ Un programma viene memorizzato come un unico blocco di indirizzi contigui
	+ Potrebbe essere impossibile trovare un blocco di indirizzi contigui così grande
	+ Basso overhead
![[Pasted image 20231030094713.png]]
+ Allocazione *non contigua*
	+ Un pogramma viene diviso in blocchi chiamati *segmenti*
	+ Ogni *segmento* può essere allocato in diverse parti della memoria anche non contigue
	+ Risulta più facile trovare spazi in memoria in cui un segmento può essere memorizzato
	+ Alto overhead ma compensato dalla quantità di processi che possono essere in esecuzione

+ Un metodo alternativo per superare le limitazioni della allocazione *contigua* è l'**Overlay** :
	+ è una tecnica di programmazione in cui il programma viene diviso in *sezioni logiche* 
	+ Vengono poste in memoria solo le sezioni che sono attive in questo momento
	+ Questa tecnica comporta diversi svantaggi infatti risulta :
		+ Difficile per il programmatore organizzare gli *overlay* per ottimizzare la memoria
		+ Complica la scrittura e modifica dei programmi
	+ Ci permette però di mettere in esecuzione programmi che hanno dimensioni maggiori rispetto alla memoria principale disponibile

**Esempio** :

![[Screenshot 2023-10-30 093754.png]]

Ambiente *mono-utente* 
>[!tldr] 
> vedi slide 13 pdf 3.1

In un ambiente *mono-utente* un utente ha il controllo dell'intero sistema in questo modo :
+ Le risorse non devono essere condivise 
+ Si può scrivere codice senza tenere conto dell'OS ( se abbiamo una allocazione contigua ) ossia a livello macchina inclusa la gestione dell'I/O ( sucessivamente viene sviluppato l'IOCS ( Input Output Control Systems ) )
### Protezione in ambiente mono-utente

Per fare in modo che i programmi utente non possano modificare il S.O. vengono introdotti i registri *boundary* :
+ Contengono l'indirizzo di inizio del programma
+ Può essere impostato solo tramite *istruzioni privilegiate*
+ Un programma può accedere alla memoria del SO solo attraverso *chiamate di sistema*

![[Pasted image 20231030095053.png]]

### Single-Stream Batch Processing

I primi sistemi avevano un tempo di *setup* rilevante

Infatti in un sistema *batch* bisognava gestire ogni *job* attraverso un *job control language* , ossia definirlo e configurarlo a mano ( spazio in memoria etcc ) 
### Multiprogrammazione a partizioni fisse

Molti processi devono risiedere in *memoria* contemporaneamente  

Per mettere in memoria vari processi abbiamo diversi metodi :
#### Partizioni fisse

+ Ogni processo attivo risede in un blocco di dimensione prefissata in memoria
+ Il processore sapendo dove sono i processi a priori è molto veloce a passare tra processi
+ Potrebbe richiedere più memoria di quella effettivamente richiesta dai processi
+ Utilizzazione di registri *boundary* multipli per proteggere i processi ( uno per ogni processo )
	+ *base* ( indica l'indirizzo base del programma )
	+ *limite* ( indica il limite superiore del programma )
	+ Le richieste di accesso e modifica dei dati devono essere tra questi 2 registri ( apparte qunado venogno fatte chiamate di sistema ) 
	![[Screenshot 2023-10-30 101912.png]]

Per l'*assegnamento* dei job avremo quindi varie code separate ( una per ogni partizione ) che contengono i *job* che ( per la loro dimensione ) possono essere eseguiti solo lì

![[Pasted image 20231030100825.png]]

Inizialmente si usavano *indirizzi assoluti* per fare riferimento all'area di memoria che doveva contere il *job* Se quindi quell'area era occupata il programma non poteva essere caricato in nessun altra partizione

Con lo sviluppo di *compilatori rilocanti* questo problema è stato risolto infatti ora i programmi iniziano da un indirizzo relativo 0 , questo verrà modificato quando viene lanciato il *loader* con l'indirizzo corretto in memoria

![[Pasted image 20231030101548.png]]

+ **Svantaggi** :
	+ **Frammentazione interna** :
		+ Se il processo non occupa un'intera partizione viene sprecata memoria
		+ Impossibilità di usare questa memoria
		+ Un processo potrebbe essere troppo grande per essere inserito  in una partizione
		![[Pasted image 20231030102424.png]]

#### Partizioni variabili

I *job* sono allocati in una partizione con le stesse dimensioni del *job*
+ Nessuno spazio sprecato all'inizio
+ Frammentazione interna impossibile
+ Può verificarsi **Frammentazione esterna** :
	+ Quando un processo viene rimosso potrebbero :
		+ Lasciare buchi troppo piccoli per qualsiasi altro processo

![[Pasted image 20231030103230.png]]

Combattere la *frammentazione esterna* attraverso :
+ *Coalescenza* : 
	+ Combinazione di blocchi liberi adiacenti in un unico grande blocco 
	![[Pasted image 20231030103612.png]]
+ *Compattazione* :
	+ Ogni tanto viene chiamato *garbage collection* che :
		+ Riorganizza la memoria in un unico blocco contiguo di spazio libero
		+ *overhead* significativo
	![[Pasted image 20231030103632.png]]

Per aumentare l'efficenza nella gestione dello spazio bisogna migliorare l'efficenza di utilizzo dello spazio prima di chiamare la *garbage collection* 
Per questo si implementano diverse strategie per il posizionamento di processi in memoria :
+ **First-fit** :
	+ Il nuovo processo viene allocato nel primo spazio libero trovato di dimensini sufficenti
	+ *basso overhead*
	![[Pasted image 20231030104237.png]]
+ **Best-fit**
	+ Il nuovo processo viene allocato nello spazio che lascia il minimo spazio inutilizzato
	+ *maggior overhead*
	![[Pasted image 20231030104254.png]]
+ **Worst-fit**
	+ Il nuovo processo viene allocato nello spazio che lascia il maggior spazio inutilizzato
	+ In questo modo esso lascia un grande spazio libero rendendo più probabile che un'altro processo possa utilizzarlo
	![[Pasted image 20231030104306.png]]

#### Swapping di Memoria 

Non occorre mantenere i processi attualmente non attivi in memoria :
+ I processi non attivi sono spostati temporaneamente in *memoria secondaria*
+ Massimizzazione della memoria disponibile per il processo in esecuzione
+ *Overhead significativo* per il cambio di contesto in quanto doppiamo caricare il nuovo processo in memoria 

Per ovviare all'elevato *overhead* dovuto al cambiamento di contesto con la soluzione precedente si possono mantenere più programmi in memoria in modo da avere tempi di risposta migliori 

![[Pasted image 20231105145437.png]]

L'allocazione di memoria non comprende solo la memoria necessaria per il codice del processo ma anche ulteriore memoria su cui istanziare lo *stack* , ossia spazio utilizzato durante l'esecuzione del programma 

![[Pasted image 20231105150001.png]]

#### Gestione della Memoria Libera

Vi sono 2 metodi per gestire la memoria libera :
+ **Mappa di bit**
	La memoria viene organizzata in blocchi , ogni blocco corrisponde ad un bit di stato ( occupata o libera ) nella *mappa di bit*
+ **Liste collegate**
	Utilizzo di una lista collegata contenente i segmenti di memoria libera o allocata
	Ogni elemento della lista è composto da :
	+ P o H se lo spazio di memoria è occupato ( P ) o libera ( H )
	+ l'indirizzo dell'inizio della parte di memoria rappresentata
	+ la lunghezza di questa parte di memoria 
	+ il puntatore all'elemento sucessivo 

![[Pasted image 20231105151011.png]]

### Memoria Virtuale

La *memoria virtuale* crea l'illusione che esista più memoria di quella realmente disponibile nel sistema

Nei sistemi di *memoria virtuale* possiamo trovare 2 tipi di address :
+ indirizzi **virtuali**
	+ riferiti ai processi
	+ L'intervallo di indirizzi virtuali ai quali un processo può fare riferimento viene detto :
		+ **Spazio di indirizzamento virtuale** $V$
+ indirizzi **fisici**
	+ descrivono indirizzi nella memoria principale
	+ L'intervallo di indirizzi fisici disponibili su un particolare computer :
		+ **Spazio di indirizzamento reale** $R$

Spesso $V>>R$
	Per questo spesso il sistema operativo deve memorizzare parti di $V$ al di fuori della memoria principale

La **MMU** ( *Memory managment unit* ) è quella componente che ha come compito quello di tradurre gli indirizzi virtuali in indirizzi fisici 

![[Pasted image 20231219151155.png]]

La **DAT** ( *Dynamic Address Translation* ) invece è un meccanismo di traduzione degli indirizzi virtuali in fisici durante l'esecuzione di un programma

Per collegare gli indirizzi *virtuali* con quelli *fisici* esiste la **tabella delle pagine** : 

![[Pasted image 20231219151848.png]]

Per tradurre l'indirizzo virtuale in indirizzo fisico l'*MMU* ( *memory managment unit* ) prende i bit relativi al numero di pagina e lo utilizza come indice per andare a cercare nella tabella delle pagine i bit corrispondenti alla pagina fisica ( viene aggiunto un bit per indicare se la pagina è presente o assente in memoria ( se assenente il sistema deve caricarla ) ) i bit trovati vengono quindi aggiunti all'offset presente nell'address iniziale ( 16 bit , 4 di pagina e 12 di offset ) 

![[Pasted image 20240114180249.png]]

Una righa della tabella delle pagine è costruita nel seguente modo :
1. Numero di pagina fisica 
2. Bit presenza , assenza in memoria 
3. Bit di protezione ( che tipi di accesso sono permessi ) 
	Si utilizzano 3 bit ( lettura , scrittura , esecuzione )
4. Bit di modifica viene posto a 1 quando si scrive quella pagina 
5. Bit usata indica quando si fa un riferimento ad una pagina 
6. Bit per disabilitare la cache 

**Esempio** :

![[Pasted image 20240117152127.png]]

Si utilizza una mappa di traduzione degli indirizzi per indicare quali regioni dello spazio di indirizzamento virtuale di un processo $V$ sono attualmente in memoria principale e dove si trovano

Una caratterristica degli indirizzi virtuali è che gli indirizzi contigui di un processo potrebbero non corrispondere ad indirizzi contigui nella memoria fisica 

![[Pasted image 20240117153359.png]]

Il mapping può avvenire in due modi principali : 
+ *Paginazione*
	In cui tutti i blocchi hanno dimensione fissa 
+ *Segmentazione*
	In cui i blocchi possono avere dimensioni differenti
+ *Mappa dei blocchi*
	Rappresentazione degli indirizzi come coppie ordinate

#### Mappa Dei Blocchi

Formato dell'indirizzo virtuale in un sistema con mapping dei blocchi 

![[Pasted image 20240117154743.png]]

Indirizzo virtuale  $v=(b,d)$
###### Traduzione

Ogni processo possiede una tabella della mappa dei blocchi che contiene una riga per blocco del processo 
L'indirizzo $a$ rappresenta l'indirizzo della tabella legata al processo 

Per tradurre l'indirizzo $v$ in un indirizzo reale : 
+ Si aggiunge ad $a$ il numero di blocco $b$ per individuare la riga nella tabella dei blocchi 
+ La riga produce l'indirizzo $b'$ 
+ Si aggiunge lo spostamento $d$ per creare l'indirizzo reale $r$

![[Pasted image 20240117155846.png]]

### Paginazione

La paginazione utilizza il *mapping di blocchi* a dimensione fissa 

L'indirizzo virtuale è una coppia $v=(p,d)$ dove :
+ $p$ è il numero della pagina in memoria virtuale 
+ $d$ è lo spostamento dall'inizio della pagina $p$ in cui si trova il blocco

![[Pasted image 20240117160249.png]]

**Page frame**

I *page frame* sono blocchi della memoria principale a dimensione fissa destinati a contenere delle pagine 

Inizia ad un indirizzo che è multiplo intero della dimensione fissa della pagina

Le pagine possono essere caricate in un qualsiasi *page frame* libero

La tabella delle pagine spesso non risiede completemante in memoria principale 

**Page table entry** ( **PTE** ) : 
+ Indica che la pagina virtuale $p$ è nel page frame $p'$
+ Contiene un bit di residenza $r$ per indicare se la pagina è in memoria principale :
	+ $r=1$ : **PTE** memorizza il numero di page frame $p'$ ( pagina in memoria principale )
	+ $r=0$ : **PTE** memorizza la posizione della pagina in memoria secondaria

![[Pasted image 20240117161700.png]]

##### Traduzione 

La traduzione dell'indirizzo dipende da come abbiamo implementato il mapping : 
###### Mapping diretto

Simile alla traduzione di indirizzi 

**DAT** ( *Dynamic Address Translation* ) aggiunge l'indirizzo base della tabella delle pagine $b$ al numero di pagina riferito $p$ ( riga della tabella ) 
$b+p$ forma l'indirizzo di memoria principale della **PTE** per la pagina $p$ 
Concateniamo quindi il page frame $p'$ con lo spostamento $d$ per formare l'indirzzo reale $r$

![[Pasted image 20240117164113.png]]
###### Mapping associativo

Per aumentare le prestazioni si potrebbe porre la tabella delle pagine nella *memoria associativa* con indirizzamento per contenuto in cui ogni posizione della memoria associativa è cercata *contemporaneamente* ( nella cache )

![[Pasted image 20240117164322.png]]

Come memoria associativa si può utilizzare una **TLB** ( *Translation Lookaside Buffer* ) , siccome non è abbastanza grande per tutta la tabella si mettono solo alcuni **PTE** se non è presente nella **TLB** allora si ricerca nella tabella nella memoria principale 

![[Screenshot 2024-01-17 164902.png]]
### Tabella delle Pagine multilivello

Ci interessano solo quelle parti della tabella che il processo sta utilizzando non tutta , ci permette di ridurre il numero di righe della tabella necessarie in memoria principale

Ogni livello della tabella contiene dei puntatori alle tabelle di livello inferiore , questi livelli hanno tabelle con le traduzioni di indirizzi

![[Pasted image 20240117165706.png]]

**Traduzione di indirizzi**

![[Pasted image 20240117165749.png]]
### Tabella inversa delle pagine

La tabella inversa memorizza un **PTE** in memoria per ogni *page frame* 

Il numero di pagine della tabell in memoria dipende dal numero di *page frame* 

>[!todo]
>#todo
### Condivisione in un sistema di paginazione

Possiamo ridurre la memoria consumata dai programmi che utilizzano i dati e itruzioni in comune

Il sistema deve identificare come condivisibile o non condivisibile

![[Pasted image 20240117172633.png]]
### Sostituzione 

Poichè la memoria principale finisce dobbiamo identificare delle strategie per la sostituzione delle pagine presenti in memoria 

Determina *dove* caricare in memoria principale una pagina

Strategie di **Fetch** : 
+ Determinano *quando* le pige o segmenti devono essre caricati nella memoria principale 
+ Strategie a *richiesta*
	+ Determino cosa e dove quando mi è richiesto
+ Strategie a *previsione*
	+ Determino cosa e dove prevedendo con l'uso di euristiche 

Per migliorare le prestazioni si utilizza i principi di : 
+ Località *sapaziale*
+ Località *temporale*
### Paginazione a richiesta

Quando un processo inizia l'esecuzione il sistema carica in memoria princiaple la pagina che contiene la sua prima istruzione 

Caricheremo la seguente pagina solo quando il processo vi fa esplicito riferimento
### Paginazione a previsione

Il sistema operativo cerca di prevedere di quali pagine un processo avrà bisogno e le carica in previsione nella memoria principale 
### Sostituzione di pagina

Quando un processo genera un *page fault* il gestore della memoria deve : 
+ *individuare* la pagina di memoria secondaria a cui fa riferimento
+ *caricarla* nel page frame della memoria principale
+ *aggiornare* la riga corrispondente della tabella delle pagine 

Per individuare la pagina modifica si aggiunge un *dirty bit* che viene settato a 1 se la pagina è stata modificata a 0 altrimenti 
#### RAND

Sostituzione casuale delle pagine 

+ Basso overhead semplice
+ Veloce 
+ Non discrimina tra i processi ( *equa* )

Potrebbe selezionare come prossima pagina da sostituire anche la pagina del prossimo riferimento
#### FIFO ( First-In-First-Out )

Sostituisce la pagina che è stata nel sistema più a lungo ( in base al tempo di arrivo )

Può sostituire anche pagine molto utilizzate 

Non conviene per la maggior parte dei sistemi

![[Pasted image 20240117181023.png]]

>[!note]
>Anomalia di Belady
>Aumento del numero di errori di pagina all'aumentare del numero di page frame assegnati a un processo
#### LRU ( Least-Recently-Used )

Sfrutta la località *temporale* sostituendo la pagina che ha trascorso più tempo in memoria senza essere riferita

>[!note]
>Prestazioni migliori rispetto a FIFO

Maggior overhead di sistema : 
+ devo aggiornare dei contatori per determinare la pagina LRU

>[!note]
>Possiamo avere scarse prestazioni se la pagina meno utilzzata è la prossima pagina a cui fa riferimento un programma all'interno di un ciclo 
>Questa verrà sostituita e poi ricaricata il prossimo ciclo

![[Pasted image 20240117181943.png]]
#### LFU ( Least-Frequently-Used )

Sostituisce la che è meno *intensamente* riferita

Basato du l'*euristica* di una pagina alla quale non si fa riferimento spesso è probabile che non sia riferita in futuro

#### NFU ( Not-Frequently-Used )

Sostituisce la pagina che *non è stata recentemente* riferita 

Ogni volta che si fa riferimento ad una pagina si somma uno al contatore che conta il numero di riferimento 

Si scieglie la pagina da sostituire a seconda del contatore minimo sfuttando la caratteristica che una pagina alla quale non si fa riferimento spesso è probabile che non sia riferita in futuro
#### NRU ( Not-Recently-Used )

Approssima la strategia *LRU* con un overhead minimo utilizzando i bit di riferimento e modifica   

La pagina da sostituire sarà : 
+ Pagina non riferita ( bit di riferimenot a 0 ) 
+ Se non si trova una pagina non riferita si cerca una pagina non modificata 

Con molti utenti le pagine vengono spesso tutte riferite , periodicamente si possono quindi azzerare i bit di riferimento

![[Pasted image 20240117214123.png]]
#### FIFO Second-Chance

Esamina il bit di riferimento della pagina più vecchia : 
+ Se è 0 la strategia seleziona la pagina per la sostituizione 
+ Se è 1 la stategia azzera il bit e sposta la pagina in coda *FIFO* e si considera come un nuovo inizio 

Assicura che le pagine attive siano quelle con minor probabilità di essere sostituite

![[Pasted image 20240117215414.png]]

I numeri sopra alle pagine sono i tempi di caricamento 

- a) pagine ordinate secondo FIFO
- b) la lista delle pagine se il fault accade al tempo 20 , A ha bit R=1 

#### FIFO Clock

Organizza le pagine in una lista circolare invece che lineare 

Quando si verifica un page fault viene analizzata la pagina a cui sta puntando la lancetta , l'azione intrapresa dipende dal bit R : 
+ R = 0 rimuovi la pagina 
+ R = 1 azzera R e fa avanzare la lancetta 

![[Pasted image 20240117215807.png]]
#### Far

Crea un grafo di accesso che rappresenta il modello dei riferimenti di un processo ( nodi -> pagine , archi -> riferimenti  )

Sostituisce la pagina non referenziata che è più lontana nel grafo di accesso rispetto a qualsiasi pagina riferita

>[!note]
>Prestazioni quasi ottimali 
>Non implementata perchè la ricerca e gestione del grafo complessa senza un supporto hardware 

![[Pasted image 20240117220439.png]]
### Working Set

Per eseguire un programma in modo efficente il sistema deve mantenere in memoria principale quel sottoinsieme favorito dal programma
Altrimenti si potrebbe verificare eccesive richieste in memoria secondaria per la paginazione ( *thrashing* )

Poichè i processi mostrano località aumentare il numero di page frame oltre una certa soglia non ha nessun effetto sul tasso di page fault

![[Screenshot 2024-01-17 221149 2.png]]

Il **Working Set** delle pagine di un processo : $W(t,w)$ rappresenta l'insieme delle pagine alle quali un processo fa riferimento

![[Pasted image 20240117221521.png]]

>[!note]
>La dimensione del working set del processo aumenta asintoticamente con la dimensione del programma all'aumentare della finestra del working set

![[Pasted image 20240117221710.png]]

Allo spostarsi tra working sets di processo il sistema mantiene temporaneamente in memoria le pagine che non sono più nel working set corrente del processo :
+ L'obbiettivo è ridurre la cattiva allocazione della memoria ( deallocazione e riallocazione successiva delle stesse pagine )
+ Se teniamo traccia del working set al momento di un page fault possiamo sciegliere di eliminare una pagina al di fuori del working set
+ Per determinare che pagina da sostituire si utilizza invece del numero di riferimenti il tempo di esecuzione 
+ Il working set a questo punto corrisponde all'insieme di pagine referenziate negli ultimi $t$ secondi ( tempo virtuale trascorso dall'avvio del processo )

![[Pasted image 20240117224934.png]]

![[Pasted image 20240117225010.png]]
#### Working Set Clock

Utilizzo dell'algoritmo clock unito al working set come politica di sostituzione delle pagine invece dell'algoritmo basico pichè quello ad ogni sostituzione deve scandire l'intera tabella delle pagine 

Le pagine man mano che vengono caricate vengono inserite nella lista circolare , quando necessitiamo di sostituire una pagina esaminiamo la pagina che è indicata dalla lancetta :
+ Se il bit R=1 la pagina è stata usata nel ciclo precedente quindi non è una buona candidata per essere sostituita , gli viene quindi impostato R=0 e si passa ad esaminare la pagina sucessiva
+ Se il bit R=0 
	+ Se l'età è maggiore di $t$ e la pagina non è modificata questa non fa parte del working set e c'è una una copia valida in memoria , può essere quindi sostituita
	+ Se la pagina è stata modificata dobbiamo prima scriverla sul disco ma visto che questo comporterebbe un cambiamento di processo la si schedula per la scrittura e si ri-esegue l'algoritmo per la pagina sucessiva 

Se si ritorna al punto di partenza ? 2 casi : 
+ è stata schedulata almeno una scrittura 
	+ La lancetta continua a scorrere finchè non si trova una pagina con R=0
+ Altrimenti vuol dire che tutte le pagine sono nel working set e se ne sceglie una qualunque da sostituire 

![[Pasted image 20240118103347.png]]

#### PFF ( Page-Fault-Frequency )

Regola l'insieme delle pagine di un processo residenti in memoria principale basandosi sulla :
+ Frequenza in cui il processo ha un fault
+ Tempo tra *page fault* ( tempo di *interfault* del processo )

**Vantaggi** : 
+ *PFF* regola l'insieme delle pagine solo dopo ogni page fault
+ Il meccanismo del working set deve operare dopo ogni riferimento alla memoria 
+ Si seleziona la pagina da sostituire che ha svolto più page fault
### Rilascio delle pagine

Problema : le pagine inattive possono rimanere in memoria a lungo prima di essere sostituite dalla strategia di gestione delle pagine 

Soluzione : 
	Il processo stesso potrebbe chiedere una sostituzione volontaria di pagina 
### Dimensione della pagina

Per migliorare le prestazioni si potrebbero fornire diverse dimensioni di pagina 

Pagina *piccola* : 
Vantaggi :
+ Minor frammentazione interna
	![[Pasted image 20240118104935.png]]
+ Riduzione della memoria necessaria per menatenere il working set di un processo
Svantaggio :
+ Tabella delle pagine più grande

Pagina *grande* :
Vantaggi :
+ Riduce la memoria sprecata dalla frammentazione della tabella 
+ Abilita la *TLB* a mappare una regione della memoria più grande 
+ Riduce il numero di operazioni di I/O per caricare il working set di un processo in memoria

Dimensione *multipla* di pagina :
+ Potrebbe causare frammentazione esterna
### Comportamento del programma con paginazione

I processi tendono a fare riferimento a una parte significativa delle loro pagine entro un breve periodo di tempo dopo l'inizio dell'esecuzione 

![[Pasted image 20240118105128.png]]

Il tempo medio di *interfaut* aumenta monotonicamente in qunto più page frame un processo carica più lungo sarà il tempo tra *page faults*

![[Pasted image 20240118105301.png]]

### Strategie di sostituzione Globali e Locali

Strategie **Globali** : applicate a tutti i processi come unità
+ Tendono ad ignorare caratteristiche individuali di ogni processo

*Esempio* : 
+ *gLRU* :
	Sostituisce la pagina meno utilizzata di recente in tutto il sistema 
+ *SEQ* : 
	Usa la strategia *LRU* per sostituire le pagine fino a quando non viene rilevato una sequenza di errori di pagina su pagine contigue a quel punto si utilizza la strategia *most-recently-used* ( **MRU** )

Strategie **Locali** : considera ogni processo individuale 
+ Consente di regolare il ssitema di allocazione della memoria in base alla rilevanza di ciascun processo

![[Pasted image 20240118110733.png]]

### Sostituzione di pagina il Linux

Utilizza una variante dell'algoritmo dell'orologio per approssimare una strategia *LRU* 

Utilizza due liste collegate : 
+ *lista attiva* 
	+ Contiene le pagine attive 
	+ Le pagine usate più di recente sono in cima alla lista
+ *lista inattiva*
	+ Contiene le pagine inattive
	+ Le pagine meno usate di recente sono in fondo alla lista 

Si scielgono le pagine da sostituire solo dalla lista inattiva

![[Pasted image 20240118111027.png]]
### Segmentazione

Ogni segmento contiene una parte significativa del programma ( procedure , array etcc )

Ogni segmento è composto da posizioni contigue 

I segmenti non devono essere necessariamente della stessa dimensione nè devono essere adiacenti in memoria principale 

Il segmento è un concetto logico non fisico 

Se il processo fa riferimento a dati in memoria secondatia il segmento corrispondente va caricato

![[Pasted image 20240118112435.png]]

l'indirizzo virtuale è composto da : 
+ *s* : numero di segmento in memoria virtuale
+ *d* : spostamento all'interno del segmento *s*
#### Traduzione dell'indirizzo

Con *mapping diretto* : 

Il *DAT* aggiunge l'indirizzo base della *tabella dei segmenti* del processo *b* al numero di segmento riferito *s* 
*b+s* costituisce l'indirizzo di memoria principale della riga nella tabella dei segmenti per il segmento *s* 

La riga contiene l'indirizzo iniziale del segmento in memoria *s'* , il sistema aggiunge *s'* allo sostamento *d* per formare l'indirizzo reale *r*

![[Pasted image 20240118113010.png]]

Ogni riga della tabella della mappa dei segmenti :
+ Contiene un bit di residenza :
	+ Se $r=1$ *s'* memorizza l'indirizzo di base del segmento
	+ Se $r=0$ *a* memorizza la posizione del segmento in memoria secondaria
+ Contiene $l$ che indica la dimensione del segmento ( utilizzato per fare in modo che un processo non accedi ad indirizzi al di fuori del segmento )
+ Contiene dei bit di protezione del segmento per controllare se un'operazione è ammessa 

![[Pasted image 20240118113721.png]]
#### Condivisione 

La condivisione con segmentazione può causare meno overhead rispetto alla condivisione con paginazione pura e con mapping diretto

+ Potenzialmente pochi elementi della tabella della mappa dei segmenti devono essere condivise 

![[Pasted image 20240118115320.png]]
#### Protezione e Controllo degli Accessi

Si utilizzano le **chiavi di protezione della memoria**

Ogni chiave possiede un valore associato ad un processo 

Se la chiave di protezione per il prcesso e il blocco richiesto sono gli stesso il processo può accedere al segmento

Le chiavi sono manipolabili solo da istruzioni provilegiate 

![[Pasted image 20240118115805.png]]

Un ulteriore schema di protezione sono i **Bit di protezione** , questi specificano se un processo è autorizzato a compiere determinate azioni 

| Type of Acces | Abbreviatio | Description |
| ---- | ---- | ---- |
| Read | R | This segment may be read |
| Write | W | This segment may be modified |
| Execute | E | This segment may be executed |
| Append | A | This segment may have information added to its end |

Vi sono varie combinazione di diritti di accesso in lettura , scrittura ed esecuzione in modo da definire modalità di controllo dell'accesso

![[Pasted image 20240118120238.png]]

I *bit di protezione* vengono aggiunti alle righe della tabella dei segmenti , vengono controllati quando un processo ne fa riferimento

![[Pasted image 20240118121815.png]]

+ Se il segmento non è in memoria viene generato un *missing-segment fault*
+ Se $d>l$ generata eccezione di overflow *overflow-segment exception*
+ Se non è consentia l'operazione si genera *segment-protection exception*

#### Segmentazione e frammentazione esterna

Quando si tolgono dalla memoria dei segmenti riamangono dei buchi , questi a differenza della paginazione possono essere di dimensione differente e quindi un nuovo blocco potrebbe non trovare un buco dove essere caricato 

Vi si pone rimedio con la *compattazione*

![[Pasted image 20240118122240.png]]
### Confronto fra paginazione e segmentazione

![[Pasted image 20240118121919.png]]

### Segmentazione + Paginazione

Si possono sfruttare i vantaggi sia della *paginazione* che della *segmentazione* assieme 

I *segmenti* occupano una o più pagine ( tutte le pagine del segmento non devono necessariamente essere in memoria principale contemporaneamente )

pagine contigue in memoria virtuale possono non essere contigue in memoria principale

L'*indirizzo* è rappresentato da $v=(s,p,d)$ dove :
+ *s* è il numero del segmento
+ *p* è il numero di pagina all'interno del segmento
+ *d* è lo spostamento all'interno della pagina

![[Pasted image 20240118123241.png]]
#### Traduzione dell'indirizzo

Utilizzo della *TLB* per contenere le pagine più usate

Si cerca nella *TLB* la pagina $( s,p )$ :
+ Se trovata si ottiene il page frame *p'* che concatenato con *d* forma l'indirizzo reale 
+ Se non si trova si applica la mappatura diretta

Nella mappatura diretta avermo : 
Il *DAT* aggiunge l'indirizzo base della tabella dei segmenti *b* al numero del segmento *s* 
La riga corrispondente a *b+s* contiene l'indirizzo base della tabella delle pagine *s'* 
Il numero di pagina *p* è aggiunto a *s'* per individiuare la *PTE* per la pagina *p* che memorizza il page frame *p'*
Si concatena *p'* con *d* per formare l'indirizzo reale

![[Screenshot 2024-01-18 123811.png]]

>[!note]
>Potrebbero verificarsi un *segment-overflow* o eccezzioni riguardanti la protezione 
>+ In caso di *segment-missing fault* il sistema operativo cerca il segmento in memoria secondaria
>+ In caso di *page-fault* cercae carica la pagina dalla memoria secondaria

#### Condivisione e Protezione

Due processi condividono la stessa memoria quando ogni processo ha una riga ella tabella di mappa dei segmenti che punta alla stessa tabella delle pagine 

La condivisione è facilitata dalla paginazione

>[!warning]
>La condivisione richiede una gestione attenta rispetto alle modifiche delle pagine 
>Utilizzo di liste *PTE* che mappano una pagina condivisa per facilitare l'aggiornamento in caso di modifica

Il controllo degli accessi avviene come spiegato nella segmentazione

![[Screenshot 2024-01-18 124655.png]]

### Architettura di Memoria Virtuale di IA-32

Supporta sia la segmentazione pura che la segmentazione e paginazione della memoria virtuale

I segmenti sono posizionati in un qualsiasi punto disponibile nello spazio di indirizzzamento lineare del sistema

La traduzione degli indirizzi è effettuata attraverso il *mapping diretto* , questa utilizza i registri del processore per memorizzare il descrittore della tabella dei segmenti ( globale ( *GDT* ) o locale ( *LDT* ) ) in modo da trovare il registro base velocemente

Supporta la paginazione a più livelli
## File System

Compiti di un file system : 
+ *Controllo degli accessi* : Questo gestisce i vari permessi per scrivere , leggere ed eseguire ( nel caso di file eseguibili ) i vari file memorizzati da parte degli utenti
+ Utilizzato per *organizzare* e *gestire* i *dati* e lo *spazio libero* in un dispositivo di memoria secondario
+ *Trattamento dei guasti* : Implementazione di un meccanismo di backup , recovery e controllo / mantenimento dell'integrità di un file system

### Introduzione 

#### Gerarchia dei dati 

Il livello più basso sono i singoli *bit* , la creazione di pattern con questi *bit* ci consentono di rappresentare tutti i dati di interesse all'interno del nostro sistema 
+ *Byte* : 8 *bit*
+ *Word* : Il numero di *bit* che un processore può elaborare alla volta 
+ *Char* : mappano i *byte* a simboli ( lettere , numeri etc.. ) come ASCII , EBCDIC , Unicode
+ *Field* : un gruppo di *caratteri* 
+ *Record* : un gruppo di *campi*
+ *File* : un gruppo di *record* *correlati*
+ *File System* : insieme di file
+ *Database* : insieme di dati 

#### Volume

Un **Volume** è un'unità di memorizzazione dei dati che può contenere anche più file

2 tipi di volumi : 
+ *Fisico* : un solo dispositivo di memoria
+ *Logico* : più dispositivi di memoria
#### Files

+ Raccolte di dati *denominati* e trattati come un'unità
+ Risiedono in memoria secondaria ( ??? e non solo )
+ Per la gestione di grandi quantità di dati condivisi si utilizzano *database* in alternativa ai file

Le operazioni che si possono svolgere sono : 
+ Open
+ Close 
+ Create
+ Destroy
+ Copy
+ Rename
+ List

I singoli elementi di dati all'interno di un file possono essere manipolati da operazioni come :
+ Create
+ Delete
+ Open
+ Close
+ Read
+ Write
+ Append
+ Seek
+ Get Attributes
+ Set Attributes
+ Rename

**Caratterisitche** :
+ Locazione
+ Accessibilità
+ Tipo
+ Volatilità
+ Attività

I *file* possono includere uno o più record 
2 tipi di *record* :
+ *fisici* : Il record è mappato interamente in memoria
+ *logici* : Insieme di dati trattati dal software come unità logica 

+ *File con record non bloccati* :
	+ Sono file per cui ogni blocco ( record ) fisico corrisponde ad un solo blocco logico 
+ *File con record bloccati*
	+ Sono file per cui ogni blocco fisico può corrispondere a più blocchi logici 

Inoltre il *record* può essere di dimensioni fisse o variabili
##### Nome

I nomi dei file sono suddivisi in 2 parti :
+ *nome_file* : rappresenta il nome vero e proprio del file
+ *.estensione* : Indica di che tipologia è il file ( .pdf documento in formato Adobe PDF ( portable document format ) ) 

##### Struttura

3 tipi principali di strutture :
+ Sequenza di *byte*
+ Sequenza di *record*
+ Albero di record ( utilizzato per accedere velocemente a parti del file visto che ogni record contiene una *key* secondo la quale effettuare la ricerca )

##### Tipi

+ *File regolari* : contengono le informazioni dell'utente
+ *Directory* : sono file di sistema che contengono tutte le informazioni riguardanti il file system
+ *File speciali*
	+ A *caratteri* : utilizzati per modellare l'input/output come terminali , stampanti etcc
	+ A *blocchi* : utilizzati per modellare dischi

##### Accesso

+ **Accesso sequenziale** : ( nastri magnetici )
	+ Legge tutti i bytes/records dall'inizio del file
	+ Non può fare salti , riavvolgere o tornare indietro
+ **Accesso casuale** : 
	+ Leggono byte/record in qualsiasi ordine
	+ Per spostarsi all'interno del file si utilizza un puntatore che viene spopstato nella posizione in cui vogliamo leggere ( operazione di *seek* )

Un file possiede dei *flag* ( attributi ) per settare alcune caratteristiche che avrà il file es : 

![[Pasted image 20240115162751.png]]

#### File System 

Il *File System* dovrebbe essere indipendente dal dispositivo : 
	Gli utenti dovrebbero esser ein grado di fare rifermento ai propri file grazie a nomi simbolici invece di nomi legati ai dispositivi in cui sono immagazzinati i dati

Responsabile per :
+ *gestione dei file*
+ *gestione della memoria ausiliaria*
+ meccanismi di *integrità* dei file
	+ Fornisce funzionalità di *backup* e *ripristino* per prevenire la predita accidentale o distruzione malevola dei dati
	+ Potrebbe fornire funzionalità di *crittografia* e de-crittografia
+ gestione degli accessi

#### Directories

Sono file che contengono i nomi e le posizioni di altri file in moda da organizzarli 

Gli elementi che una *directory* memorizza sono quindi : 
+ File name
+ Location ( *pathname* ( posizione logica ) o blocco fisico )
+ Dimensione
+ Tipo ( data file / directory )
+ Tempo ultimo accesso
+ Tempo di ultima modifica e creazione 

Operazioni che posso svolgere : 
+ Create 
+ Delete ( cancella una directory se vuota )
+ Opendir
+ Closedir
+ Readdir
+ Rename
+ Link ( permette di far apparire un file in diverse directory )
+ Unlink ( se non ci sono altri link il file viene cancellato )

#### File System a livello singolo ( flat )

Memorizza tutti i *file* in una sola *directory* 
>[!warning]
>Non possono esserci file con lo stesso nome

Per trovare un file necessitiamo di svolgere una ricerca lineare ( scorrendo tutti i file presenti nella directory ) questo può portare a scarse prestazioni

![[Pasted image 20240115171809.png]]

#### File System gerarchico

La *root* indica dove inizia la directory principale all'interno del dispositivo 
La *directroy* *root* punta alle varie directory , ognuna delle quali contiene una riga per ciauscuno dei suoi *file*

>[!warning]
>Il nome dei file deve essere unico *solamente* all'interno di una determinata directory poichè il nome del file è formato dal *pathname* dalla *root* al file

Es :
+ Windows : C:\\dir1\\nome_file
+ Unix : /dir1/nome_file

![[Pasted image 20240115172600.png]]

#### Working directory

Semplifica la navigazione 
Infatti fa in modo che se siamo all'interno di una directory tutti i nostri movimenti sono relativi al pathname della directory dove ci troviamo ( cammino *relativo* )

#### Link

Rappressenta un entry di una directory che fa riferimento ad un file o directory situata in un directory differente

Vi sono 2 tipi di *Link* : 
+ **Soft Link** : la entry contiene il pathname per il file a cui vogliamo fare riferimento
	Quando un file viene spostato nella memoria fisica non occorre aggiornare il link 
+ **Hard Link** : la entry specifica la posizione del file ( il numero di blocco ) sul dispositivo fisico di memoria 
	Se cambia la posizione fisica di questi dati faremo riferimento a dati non validi mentre lo spostamento in una directory differente non influenzia il link

>[!warning] 
>Nel caso dei soft link se spostiamo il file in una nuova directroy dovremo aggiornare il link  

![[Pasted image 20240115174732.png]]

#### Metadata

I metadata sono informazioni che proteggono l'integrità del file system ( non possono essere modificate direttamente dagli utenti )  

**Super-blocco** :
+ Contiene tutte le infomazioni critiche per proteggere l'integrità del file system :
	+ File System Identifier
	+ Posizione dei blocchi di meoria liberi all'interno del dispositvo di memrizzazione
	+ Posizione delle directory *root*
	+ Tempo dall'ultima modifica 

Per ridurre il rischio di perdita di dati i file system distribuiscono varie copie del *super-blocco* all'interno del dispositivo di memorizzazione 

##### Open

L'operazione di *open* di un file restituisce un descrittore di file 


#### Mounting

L'operazione *mount* 
+ combina più file system in un unico namespace in modo che possano essere riferiti da una singola directory radice 
+ Assegna una directory chiamato punto di mount presente nel file system originario alla *root* del file system montato 

Per gestire i *mount* esistono tabelle di mount che contengono informazioni sulla posizione dei punti di mount e dei dispositivi ai quali puntano

>[!note]
>Quando un file system incontra un punto di mount si riferisce alla tabella di mount per determinare il dispositivo e il tipo di file system montato

>[!warning]
>Gli utenti possono creare solo *soft link* ai file di un file system montato ( non si possono creare *hard link* tra file systems )

**Esempio** :
![[Pasted image 20240115183622.png]]

#### Organizzazione dei File

Come sono disposti i record di un file in memoria secondaria ?

Il disco è diviso in partizioni :
+ Settore 0 : *MBR* ( *master boot record* ) utilizzato per l'avvio del computer
+ *Tabella delle partizioni* : Una sola partizione è attiva alla volta 
	+ Il primo blocco della partizione contiene codice per avviare il sistema operativo ( *blocco di boot* )

![[Pasted image 20240115184147.png]]

#### Allocazione dei File

Problema dell'allocazione dei file simile a quello dell'allocazione nella memoria principale con multiprogrammazione a partizioni variabili

Poichè i file tendono a crescere o ridursi nel tempo tendiamo a utilizzare sistemi di allocazione *non contigui* 

##### Allocazione contigua

Alloca i dati dei file ad indirizzi *contigui* sul dispositivo di memoria 

| Vantaggi | Svantaggi |
| ---- | ---- |
| record logici sucessivi sono tipicamente fisicamente adiacenti l'uno all'altro | Frammentazione esterna |
| Semplice memorizzazione | Scarse prestazioni se i file crescono o si riducono nel tempo |
| Conviene nel caso in cui abbiamo memorizzazione statica ( DVD , CD ) | Se un file cresce oltre le dimensioni specificate necessitiamo di spostarlo in un'altra area libera di memoria ( operazionie di I/O necessarie ) |
**Esempio** :
![[Pasted image 20240115185445.png]]

##### Allocazione non contigua con liste collegate 

Un file è suddiviso in *settori* :
+ Una riga della directory punta al primo settore di un file
	+ La porzione dati contiene la prima porzione del file
	+ La porzione puntatore punta al secondo settore del file

I settori appartenenti ad un file formano una *lista collegata* 

Questo permette di eliminare la *frammentazione esterna* mentre si può avere *frammentazione interna* solo all'ultimo blocco

![[Pasted image 20240115215027.png]]

Quando necessito di un nuovo blocco semplicemente assegno l'indirizzp del primo blocco libero che trovo al puntatore dell'ultimo blocco del file

>[!note]
>Quando vogliamo cercare un blocco siamo costretti a cercarlo dall'inizio della lista collegata di blocchi

Ulteriori *svantaggi* sono l'utilizzo di ulteriore spazio per immagazzinari i puntatori e la possibilità di creazioni di liste doppi 

###### Dimensione dei Blocchi

+ *Grande*
	+ Può portare a frammentazione interna
	+ Necessito di meno operazioni di I/O ( caricamento , scrittura , ricerca )
+ *Piccola*
	+ Dispersione dei dati dei file all'interno del dispositivo di memorizzazione
	+ Scarse prestazioni poichè devo fare molte ricerche per trovare tutti i blocchi di un file all'interno di un dispositivio di memoria

##### Allocazione dei file non contigua tabellare

Utilizza tabelle che memorizzano punatori ai blocchi dei file 
	Riduce il numero di ricerche lunghe per accedere ai un record particolare 

Le righe della directory indicano il primo blocco di un file

Il numero di blocco viene utilizzato come un indice nella tabella di allocazione blocco per determinare la posizione del blocco sucessivo 

Se il blocco attuale è terminale allora il valore nella tabella di allocazione è nullo 

**Esempio** :

![[Pasted image 20240115220602.png]]

>[!note]
>I puntatori non sono memorizzati all'interno dei blocchi ma in una posizione centrale , questo ci permette di memorizzare la tabella nella cache in modo che possiamo attraversare i blocchi dei file più velocemente

>[!warning]
>Per individuare l'ultimo blocco necessitiamo di seguire tutti i puntatori questo richiede un tempo significativo

>[!warning]
>Quando un dispositivo contiene molti blocchi :
>+ La tabella di allocazione dei blocchi può diventare grande e frammentata ( peggiorazione prestazioni del sistema operativo )

Dimesioni tabella = \#blocchi * lunghezza indirizzo di blocco

**Esempio** : 

Una implementazione è : *FAT* ( *File Allocator Table* ) 

Varie versioni a seconda del numero di bit utilizzati come indirizzo del blocco :
 + FAT32 : consente di avere blocchi piccoli anche per dischi di gradi dimensioni questo però aumenta il costo per accedere ai blocchi 

##### Aloocazione dei file non contigua e indicizzata 

Ogni file ha un *blocco indice* o più blocchi indice 

I *blocchi indice* contengono un elenco di puntatori che puntano ai blocchi di dati dei file 

Le righe delle directory puntano ai blocchi indice del file 

>[!note]
>Un blocco indice può riservare gli ultimi elementi per puntatori ad altri blocchi indice ( *chaining* ) 

![[Pasted image 20240115222445.png]]

I vantaggi dei *blocchi indice* ( *i-node* ) sono : 
+ La ricerca può avvenire nei blocchi indice stessi 
+ Utilizzo della cache
+ Il *file system* tipicamente colloca i blocchi indice vicino ai blocchi dati a cui fanno riferimento in modo che sia possibile accedere rapidamente ai blocchi di dati dopo che è stato caricato il loro blocco indice 

Gli *i-node* contengono ulteriori informazioni come : 
+ Proprietario
+ Dimensione
+ Data di creazione
+ Data di ultima modifica
+ Si possono concatenare un massimo di 3 *i-node* ( max 4 puntatori )

Gli *i-node* sono implementati da *NTFS*

**Esempio** :
![[Pasted image 20240115223328.png]]

#### Organizzazione delle directories

Gli attributi dei file possono essere contenute in :
+ Nelle righe della directory
![[Pasted image 20240115223636.png]]
+ Negli *i-node* 
![[Screenshot 2024-01-15 223656.png]]

##### Memorizzazione dei nomi dei file 

Diverse soluzioni : 
+ Lunghezza limite ( es 255 ) questo potrebbe creare un possibile spreco di memoria ( blocchi vuoti dove non metto dei char )
+ Lunghezza variabile e si pone il nome all'interno dell'header ( a lunghezza fissa ) seguito dal resto con carattere speciale per delimitare la fine ( occorrono caratteri di riempimento )
![[Pasted image 20240115224745.png]]
+ Si lasciano righe della directory di lunghezza fissa e si usa l'heap per memorizzare i nomi dei file alla fine della directory
![[Pasted image 20240115224811.png]]
>[!note]
>+ Evita i problemi di riuso dopo la cancellazione di un file
>+ Evita l'utilizzo dei caratteri di riempiemento
>+ Richiede la gestione dell'heap

#### Condivisione dei file

La condivisione di file attraverso *link* ( si copia l'indirizzo del disco )

Se però si fanno degli append al file *linkato* , le modifiche potranno essere viste solo dalla directory che ha fatto le modifiche non ovunque il file sia condiviso

2 metodi per risolvere questo : 
+ Utilizzo di una struttura dati ( *i-node* in UNIX ) cotenente gli address dei blocchi , il *link* poi punteranno a questa struttura dati ( contiene un contatore per contare il numero di proprietari )
>[!warning]
>Quando condivido il file con un nuovo utente questo viene registrato come proproietario del file
>Se il proprietario del file lo elimina il secondo proprietario ( colui a cui lo sto condividendo ) avrà un indirizzo che punterà ad un file non valido 
>**Soluzione**
>Quando il proprietario elimina il file in realtà l'*i-node* rimane intatto e questo verrà eliminato solo quando il nuovo proprietario deciderà di eliminarlo  

![[Pasted image 20240116120107.png]]

+ Si crea un nuovo file di tipo *LINK* che contiene il pathname del file originale , quando vogliamo leggere il file andremo a cercare il suo pathname non l'indirizzo ( *symbolic linking* )
>[!note]
>+ Con i *link simblici* non vi è il problema precedente 
>+ Problema del sovraccarico dovuto alla necessità di leggere il path , trovare l'*i-node* ed accedere infine al file 
>+ Inoltre necessitiamo di un *i-node* in più per memorizzare il path ( sovraccarico per il disco )
>+ Potrebbe verificarsi che si possano effettuare più copie dello stesso file quando si vuole copiare un intero volume ( copia del file originale + copia della risoluzione del link )
#### Gestione dello spazio del file system

La dimensione dei blocchi all'interno dei dispositivi di memorizzazione secondaria sono di solito costanti in dimensione 

Che dimensione utilizzare ? :
+ *grandi* : possibile spreco di spazio
+ *piccoli* : utilizzazione di molti blocchi , questo potrebbe portare a uno spreco di tempo 

Per leggere un blocco di $k$ byte in un disco con tracce da 1 MB infatti avremo : 
$$S + R/2 + ( k\cdot 10^{-6} )\cdot R$$
Dove : 
+ $S$ : tempo medio di *seek* del disco ( ms )
+ $R$ : tempo medio di rotazione ( ms )

Velocità di trasferimento e utilizzo del disco in relazione alla dimensione dei blocchi :

![[Pasted image 20240116121043.png]]

##### Gestione dello spazio libero

###### Lista libera

Utilizzo di una *linked list* per contenere le posizioni dei blocchi liberi 
+ I blocchi a cui volgiamo assegnare dei dati sono scelti dall'inizio della lista
+ I nuovi blocchi liberi sono assegnati alla fine della lista 

Questa soluzione comporta un *basso overhead* per eseguire le operazioni sulla lista ma comporta la possibile frammentazione dei dati ( i blocchi liberi contigui non sono contigui nella lista )

>[!note]
>La dimensione della lista libera dipende dal numero di blocchi presente nella memoria secondaria , potrebbe essere molto grande 


![[Pasted image 20240116121834.png]]

###### BitMap

Una *bitmap* contiene un *bit* per ogni blocco in memoria 
+ il *bit* viene posto a 1 se il blocco è in uso a 0 se è libero
+ l'*i*-esimo bit corrisponde all'*i*-esimo blocco sul dispositivo di memoria

**Vantaggio** :
+ Risulta essere più facile e veloce dtereminare se blocchi contigui sono liberi 

**Svantaggio**
+ Per trovare un blocco libero necessitiamo di cercare l'intera *bitmap* ( aumento dell'*overhead* )

![[Pasted image 20240116122951.png]]

>[!note] 
>Risparmio di spazio , n blocchi = n bit per la *bitmap*

###### Memoria per gli Utenti

Ogni utente del file system avrà delle quote del disco su cui può memorizzare file , queste sono assegnate dall'amministratore di sistema

Ogni utente avrà 2 tabelle : 
+ Tabella dei *file aperti*
+ Tabella delle *quote* ( contiene i limiti hard ( non possono essere superati ) e i limiti soft associati ad ogni utente ( se superati danno un warning ) )

![[Pasted image 20240116123539.png]]
#### Backup e Recovery

I sistemi operativi e i sistemi di memorizzazione dei dati devono essere *fault tolerant* 

Per questo devono fornire tecniche di backup , recupero e ripristino ( *recovery* ) dopo un guasto 

Per far sì che un sistema di memoria sia *fault tolerant* si utilizzano varie tecniche : 
+ Tecniche di *Backup* : conservare copie ridondanti delle informazioni
+ Tecniche di *Recovery* : consente il ripristino dei dati del sistema dopo un errore di sistema 
+ Protezione fisica dei dati 

##### Backup

Vi sono 2 principali tipi di *backup* : 

**Fisico** : Duplicazione completa di un dispositivo di memoria bit per bit

**Logico** :
+ Memorizzazione dei dati del file system e la sua struttura logica 
+ Permette di diminuire il numero di dati che dobbiamo copiare : controlliamo la struttura dei dati nel backup per determinare cosa è stato modificato e eseguire il backup solo di quello , questo ci permette di eseguire backup con più frequenza

Il backup *logico* utilizza una *bitmap* per memorizzare lo schema dell file system indicando per ogni bit l'*i-node* con l'indice corrisponente 
Ogni *bit* viene inizialmente marcato indicando un nuovo elemento è stato aggiunto , sucessivamente si ripercorre il file system smarcando i file che non sono stati modificati e maracando quelli modificati , infine si farà il *backup* dei file marcati 

>[!note]
>+ Siccome la lista dei blocchi liberi non è un file questa deve essere ricreata ad ogni ripristino ( è semplicemente il complementare della *bitmap* )
>+ Bisogna assicurarsi che i link vengano copiati una sola volta 
>+ I file contenti buchi non devono contenere questi buchi all'interno del backup ( altrimenti per esempio in file eseguibili questi potrebbero essere grandi come tutto lo spazio di indirzzamento virtuale )
>+ I file speciali non dovrebbero essere mai scaricati

##### File system strutturato a log e Integrità

In sistemi in cui non possiamo tollerare la predita dei dati possiamo sciegliere : 
+ RAID ( *Redundant Array of Indipendent Disks* )
+ Registrazione ( *logging* ) delle transazioni

File system basati sulle transazioni riducono la perdita di dati poichè :
+ Eseguono un gruppo di istruzioni atomiche , se una parte della transizione fallisce l'intera transazione viene ripristinata allo stato precedente all'inizio della transazione ( *rollback* ) 

**Implementazione** : 
Il meccanismo della transazione viene implementato grazie ad un file di *log* : 
+ Le operazioni prima di essere svolte sui dati vengono svolte all'interno di un file di *log* 
+ Una volta completata in modo definitivo questa viene *committata* registrando un valore sentinella nel *log*

**Checkpoints**

Per ridurre il tempo per le operazioni di ri-esecuzione nel *log* vengono mantenuti dei *checkpoints* che puntano all'ultima transizione che è stata trasferita alla memoria in modo permanente in modo tale che se il sistema si blocca solo le transazioni dopo il *checkpoint* debbano essere ri-eseguite

**Paginazione shadow**

Implementa la *transazione* scrivendo i dati modificati in un'area libera della memoria : 
+ Terminata la transazione i metadati sono aggiornati al nuovo blocco liberando il vecchio 
+ Se la transazione viene annullata si libera il nuovo blocco mantendo quello vecchio

Un tipo di file system che implementa le transazione sono i : 

###### Log-Structured File Systems ( LFS )

Anche chiamato *journaling file system* ( NTFS , ext3 )

Esegue tutte le operazioni di un file system come transazioni 
L'intero disco serve come un file di *log* 

I nuovi dati sono scritti in sequenza nello spazio libero del file di *log*

Le directory e i metadai sono sempre scritti alla fine del log 

>[!note]
>Per individuare un file in particolare un LFS potrebbe aver bisogno di leggere l'intero registro $\implies$ scarse prestazioni in lettura

Per aumentare le prestazioni in lettura : 
+ Memorizza nella cache le posizioni dei metadati del file system
+ Ogni tanto scrive le mappe degli *i-node* o i super-blocchi nel log per indicare la posizione di altri metadati
+ Quando il registro si riempie lo spazio libero risulta frammentato per questo si utilizza un thread pulitore che periodicamente passa per il log e compatta i file alla fine del log

##### File Servers e Sistemi ditribuiti 

In una rete di calcolatori si utilizza un *file server* :
+ Un sistema dedicato alla risoluzione dei riferimenti ai file tra sistemi 
+ Controllo centralizzato di questi riferimento 

>[!note]
>Il file server potrebbe diventare un collo di bottiglia se tutti i clienti inviano richieste al server

In una rete di calcolatori un'altro approccio è quello *distribuito* lasciando che i sistemi siano separati e comunichino direttamente tra loro ( NFS , AFS )

#### Controllo degli accessi 

Per controllare l'accesso ai dati : 
+ Matrice di controllo di accesso 
+ Controllo di accesso per classi di utenti 

##### Matrice degli accessi

Si utilizza una matrice bidimensionale in cui l'indice $i$ rappresenta l'i-esimo utente metre l'indice $j$ rappresenta il j-esimo file 

*Esempio* : 
$a_{ij}=1$ all'utente $i$ è consentito l'accesso al file $j$ 

Se il sistema ha un numero molto grande di utenti e file potrebbe risultare molto grande 

![[Pasted image 20240116162328.png]]

##### Controllo degli accessi per classi di utenti

Si dividono gli utenti secondo determinati gruppi :
+ Proprietari ( possono cambiare i permessi )
+ Gruppo
+ Progetto
+ Pubblico ( generalmente in sola lettura )

Possono essere memorizzati all'interno del *File Control Block* richiedendo poco spazio
##### Diritti di accesso

Utilizzati per proteggere le risorse e i servizi di sistema da utenti potenzialmente dannosi limitando le azioni che possono essere eseguite 

Questo viene gestito da : 
+ *access control lists*
+ *capability lists*

I diritti più comuni sono : 
+ Lettura 
+ Scrittura 
+ Esecuzione

*Dominio di protezione* : insieme di diritti di accesso applicati ad un oggetto 

Per la gestione dei diritti di accesso si utilizzano le seguenti tecniche : 
+ Matrici di controllo degli accessi
+ Lista di controllo degli accessi
+ Liste di capacità 

###### Modello di sicurezza 

Definisce soggetti , oggetti e privilegi di un sistema

+ *Discretionary Accesso Control*
	+ Regole di accesso definite dal proprietario del file 
+ *Mandatory Access Control*
	+ Regole di accesso predefinite dal sistema

###### Politica di sicurezza

Specificato dall'amministratore di sistema

Definisce che privilegio possiamo assegnare 

La maggior parte incorporano il concetto di *privilegio minimo* 
	Al soggetto viene concesso l'accesso solo aglio oggetti di cui ha strettamente bisogno per svolgere i suoi compiti
###### Meccanismo di sicurezza 

Metodo con il quale il sistema implementa la *politica di sicurezza* 

**Matrici di controllo degli accessi**

Associa ai soggetti e ai corrispondenti oggetti i *diritti di accesso* appropriati

>[!note]
>Con molti soggetti e oggetti potrebbe essere una matrice di grandi dimensioni ( con numerosi duplicati ) 
>Può diventare quindi *inefficente*

Diventa inoltre un elemento critico da proteggere all'interno del file system

![[Pasted image 20240116170752.png]]

**Lista dei controlli degli accessi**

Contiene informazioni riguardanti solo i diritti esplicitamente attributi ( riduzione dello spazio necessario )

Formata da File e lista di utenti e diritti 

>[!note]
>Inefficente nella ricerca 

![[Pasted image 20240116171044.png]]

**Lista di capability**

Viene fornita da un puntatore o token che garantisce l'insieme di capacità che può possedere ad un soggetto che lo possiede

>[!todo]
>controlla ?????
#### Tecnice di accesso ai dati

##### Metodi di accesso a coda

Viene utilizzato quando la sequanza di accesso ai record può essere prevista ( es accesso sequenziale )

Esegue il *caching* ( manteniamo copie dei dati più usati nella cache ) e lo scheduling delle operazioni di I/O

##### Metodi di accesso di base

Utilizzato quando non può essere prevedibile la squenza di accesso ai record ( es accesso diretto )
##### File mappati in memoria

I dati dei file vengono mappati nello spazio di indirizzamento virtuale di un processo invece di usare la cache del file system 

Il gestore della memoria virtuale avrà quindi il compito di gestire quello spazio di memoria

#### Prestazioni di un file system

Siccome stiamo gestendo la memoria secondaria questa è molto meno performante rispetto alla memoria principlae per questo di devono utilizzare diverse tecniche per migliorarne le prestazioni :

+ uso della *cache* : utilizzo di buffer all'interno della memoria pincipale ( soprattuto per la scrittura da principale a secondaria )
+ *read ahead* : lettura del blocco successivo anticipatamente
+ riduzione del tempo di *seek* del disco
+ diminuzione della frammentazione all'interno del disco
## Ottimizzazione prestazioni memoria secondaria

### Dispositivi di I/O

#### Comunicazione con I/O

Può avvenire in vari modi :

+ **Registri** ai quali è assegnata una porta di I/O da gestire
+ **I/O mappato in memoria** : ad ogni registro che gestisce l'I/O è assegnato un indirizzo di memoria 
+ **Ibrido** : Utilizzo di un buffer di dati per i dispositivi di I/O mappato in memoria e porte I/O sperate per i registri di controllo 

![[Pasted image 20240116174646.png]]

##### I/O mappato in memoria

| **Vantaggi** | **Svantaggi** |
| ---- | ---- |
| Il driver può essere scritto in un linguaggio ad alto livello | Non è possibile utilizzare la cache per velocizzare gli accessi  |
| Protezione semplice ( basta controllare l'accesso agli indirizzi ) |  |
| Le istruzioni possono riferirsi direttamente ai registri di controllo  |  |
>[!todo]
>WTFFFFFF
##### DMA ( Direct Memory Access )

Il controllore *DMA* ha accesso diretto alla memoria indipendentemene dalla CPU 

Ha molti più registri rispetto a quelli che potevano essere forniti dalla CPU :
+ Registri di *controllo* ( per il controllo del flusso di dati )
+ Registri di *conteggio* ( per fare in modo da stanziare la giusta area di memoria )

Sono possibili trasferimenti multipli simultanei grazie all'utilizzo di diversi canali 

#### Livelli di software di I/O

>[!todo]
>Fino a slide 26


### Dispositivi di memoria secondaria

La maggior parte dei dispositivi di memorizzazione secondaria si basano su *supporti magnetici* 

L'accesso ai dati avviene attraverso una testina che ci permette la lettura e scrittura dei dati 

Le prime tecnologie utilizzavano l'accesso sequenziale : le informazioni erano accessibili in modo ordinato uno per volta ( inefficente per applicazioni ad accesso diretto )

Memorizzazione ad accesso casuale : 
+ Anche detto memoria ad accesso diretto
+ Accesso ai record in qualsiasi ordine 

#### Disco

Insieme di dischi magnetici ( piatti ) che ruotano su un perno ( rotore )

Composto da *tracce* che a loro volta contengono *settori*
Un insieme di gruppi verticali di tracce formano un *cilindro*

La lettura avviene grazie ad un braccio mobile con in fondo una testina per la lettura e scrittura

Gli indici di prestazione del disco sono : 
+ Tempo di ricerca ( *seek* )
	Tempo per la testina di lettura-scrittura per spostarsi su un nuovo cilindro
+ Latenza rotazionale 
	Tempo perchè il cilindro ruoti in posizione
+ Tempo di trasmissione
	Tempo pechè i dati cercati scorrino sotto la testina

Il numero di settori all'interno di un cilindro può essere determinato dalla :
+ *geometria fisica* 
+ *geometria virtuale* : la più diffusa nei dischi moderni consiste nella numerazione dei settori senza considerare la geometria fisica del disco

##### RAID

Utilizzato per aumentare l'affidabilità e prestazioni dei dischi 

RAID gestisce un insieme di dischi a cui si accede in parallelo 
I dischi gestiscono la distribuzione di parte dei dati ( con copie ridondanti ) sui vari dischi

Vi sono diversi schemi di organizzazione dei RAID : 

+ Livello 0 : 
Divisione dei dati in diversi dischi tramite sezionamento ( *striping* ) senza nessuna informazione di parità o ridondanza
![[Pasted image 20240116212609.png]]
+ Livello 1 :
Copia esatta di tutti i dati 
![[Pasted image 20240116212818.png]]
+ Livello 2 :
Divide i dati al livello di bit e utilizza codici di *Hamming* per correggere errori 
![[Pasted image 20240116213141.png]]
+ Livello 3 :
Divisione al livello di Byte con un disco dedicato interamente alla parità
![[Pasted image 20240116213156.png]]
+ Livello 4 : 
Divisione dei dati a livello di blocchi e mantiene su uno dei dischi i valori di parità
![[Pasted image 20240116213211.png]]
+ Livello 5 : 
Distribuisce i dati di parità su tutti i dischi
![[Pasted image 20240116213227.png]]

##### Formattazione dei dischi

###### Formattazione a basso livello

Viene svolta via software definendo ogni settore del disco attraverso un preambolo i dati ed infine l'*ECC* contenente informazioni ridondanti per il recupero degli errori ( 16 byte normalmente )

Lo spazio del disco formattato si riduce del 20% 

*Cylinder Skew* : Il settore 0 si sposta di una certa distanza rispetto al settore 0 della traccia precedente ( in modo che alla fine della lettura di una traccia la testina si trova all'inizio della seconda traccia )
![[Pasted image 20240116214930.png]]

Si utilizza una tabella delle partizioni e la dimensione di ogni partizione per indicare il partizionamento del disco
###### Formattazione ad alto livello

Relativa ad ogni partizione questa definisce il blocco di avvio , la gestione dello spazio libero , directroy principale ( root ) e il file system ( vuoto )
###### Interleaving

Per fare in modo che il controllore abbia il tempo di copiare un settore dal buffer in memoria principale si utilizza l'*interleaving* 
+ Interleaving *singolo* : 
	Si sposta di un settore tutti i settori del disco
+ Interleaving *doppio*
	Si sposta di due settori tutti i settori del disco

![[Pasted image 20240116215646.png]]
##### Scheduling del disco 

Ci sono tre criteri per misurare le strategie : 
+ *Throughput* : 
	+ Numero di richieste servite per unità di tempo 
+ *Tempo medio di risposta*
	+ Tempo medio di attesa percui la richiesta sia servita 
+ *Varianza del tempo di risposta*
	+ Misura della prevedibilità del tempo di risposta

Obbiettivi generali : 
+ Massimizzazione del *throughput*
+ Minimizzare il tempo di risposta e la varianza di tempi di risposta

![[Pasted image 20240116221056.png]]
###### Fist-Come-First-Served ( FCFS )

Richieste servite in ordine di arrivo 

| Vantaggi | Svantaggi |
| ---- | ---- |
| Equo | Modello di *seek* casuale questo può portare ad un notevole ritardo nel servizio |
| Previene l'attesa infinita |  |
| Basso overhead |  |
![[Pasted image 20240116221547.png]]
###### Shortest-Seek-Time-First ( SSTF )

Richiesta di servizio più vicina alla testina di lettura-scrittura 

| Vantaggi | Svantaggi |
| ---- | ---- |
| throughput maggiore e tempi di risposta inferiori rispetto a *FCFS* | Non garantisce equità |
| Soluzione ragionevole per sistemi di elaborazione batch | Possibilità di attesa infinita |
|  | Alta varianza dei tempi di risposta |
|  | Il tempo di risposta generalmente inaccettabile per sistemi interattivi |
![[Pasted image 20240116223548.png]]
###### SCAN

Tempo più breve di *seek* in una direzione preferita
+ Non cambia direzione fino a quando non si è raggiunto il limite del disco 
+ Caratteristiche simili a *SSTF*
+ Attesa infinita possibile
+ Non equo le tracce centrali sono favorite
+ Migliora la varianza dei tempi di risposta

![[Pasted image 20240116223945.png]]
###### C-SCAN

Alla fine di una scansione verso l'interno il braccio del disco salta ( senza servire richieste ) al cilindro più esterno ( si muove sempre nella stessa direzione per servire le richieste )

Riduzione della varianza dei tempi di risposta a scapito del throughput e del tempo medio di risposta

![[Pasted image 20240116224431.png]]
###### FSCAN e N-Step SCAN

**FSCAN** : congela periodicamente la coda di richieste al disco e serve solo le richieste in coda in quel momento

![[Pasted image 20240116225608.png]]

**N-Step SCAN** : serve solo le prime $n$ richieste nella coda in quel momento 

![[Pasted image 20240116225628.png]]

Entrambe le strategie prevengono l'attesa infinita 
Entrambe riducono la varianza dei tempi di risposta rispetto a **SCAN**
###### LOOK e C-LOOK

**LOOK** ( miglioramento di SCAN )

Serve tutte le richieste in una direzione e al raggiungimento dell'estremità del disco o alla fine delle richieste in quella direzione inverte sucessivemente la direzione 

Porta ad un throughput elevato evitando operazioni inutili di ricerca

![[Pasted image 20240117101049.png]]

**C-LOOK** ( miglioramento di C-SCAN )

Quando non ci sono richieste dell'attraversamento vero l'interno si sposta verso le richieste posizionate più all'esterno senza servire quelle in mezzo iniziando un nuovo attraversamento del disco 

MIgliora la varianza dei tempi di risposta del LOOK a discapito del throughput
##### Ottimizzazione rotazionale

Ottimizzare la latenza di rotazione è molto utile quando si cerca di accedere a piccole porzioni di dati distribuiti casualemente in tutto il disco
###### Shortest-latency-time-first ( SLTF )

In un dato cilindro si servono richieste con la minima latenza di rotazione 

>[!note]
>Prestazioni quasi ottimali per la latenza rotazionale

![[Pasted image 20240117102556.png]]
###### Shortest-positioning-time-first ( SPTF )

Si basa sul tempo di *posizionamento* = somma del tempo di ricerca e la latenza di rotazione

Serve quindi richieste a seconda del minimo tempo di posizionamento

>[!note]
>Può causare attesa infinita ( la testina vorrà restare vicino alla sua posizione attuale )

###### Shortest-access-time-first ( SATF )

Si basa sul tempo di *accesso* = tempo di posizionamento + tempo di trasferimento

>[!note]
>Può causare attesa infinita

>[!note]
>Sia *SPTF* che *SATF* possono implementare *LOOK* per mmigliorare le prestazioni

>[!note]
>Entrambi gli algoritmi richiedono la conoscenza pregressa delle caratteristiche prestazionali del disco , questi dati potrebbero non essere disponibili

![[Pasted image 20240117103954.png]]

##### Considerazioni sullo Scheduling

Lo scheduling dei dischi potrebbe non essere sempre utile :
+ Nei sistemi processor bound
+ Richieste al disco in sequenze imprevedibili
+ Per distribuzioni non uniformi delle richieste l'overhead dello scheduling potrebbe ridurre le prestazioni
+ Le tecniche di organizzazione dei file possono contrastare lo scheduling dei dischi
+ *geometria reale* e *virtuale* possono vanificare i vantaggi degli algoritmi di scheduling 

##### Caching e Buffering

Il disco può spesso beneficiare di un buffer che mantenga una copia di dati presenti sul disco 

Spesso questa cache viene situata in memoria principale , onboard cache ( situata su un chip ) o sul controller del disco 

Viene utilizzato come buffer per ritardare la scrittura dei dati finchè il carico sul disco non è leggero 

>[!note]
>Potrebbero verificarsi delle *incoerenze* 
>Potremmo perdere dati se i dati presenti nel buffer non vengono scritti nel disco in caso di mancanza di corrente o guasto al sistema

Per gestire le *incoerenze* si utilizzano 2 tecniche :
+ *cache write-back* :
	I dati non vengono scritti immediatamente sul disco 
	Periodicamente scritti sul disco ( fino a quando non strettamente necessario )
+ *write-throught caching*
	Scrittura contemporanea sul disco e sulla cache ( garantisce la coerenza dei dati )

Per aumentare le prestazione si può effettuare il *caching preventivo* di più settori da parte del controller ( in lettura salvando più settori in cache in scrittura mantenendo più dati all'interno della cache prima di passarli al disco )
##### Gestione degli errori

Una traccia di un cilindro possiede dei settori di riserva utilizzati per sostituire quelli difettosi all'interno della traccia , ci sono 2 modi per sostituirli :
+ Rimappare il settore difettoso ad uno di riserva ( si utilizza delle tabelle interne per il mapping )
+ Spostare tutti i settori per ignorare quello difettoso

![[Screenshot 2024-01-17 113119.png]]

Per minimizzare problemi di affidabilità si utilizza il *RAID* 

*Memorizzazione stabile* : la scrittura avviene in modo corretto o non avviene

In un sistema a memorizzazione stabile con due dischi avremo :
+ Operazione di scrittura stabile
	Scrive il blocco nel primo disco se non avviene in modo corretto l'operazione viene ripetuta $n$ volte 
	Se l'operazione fallisce $n$ volte il blocco viene mappato con un blocco di riserva del disco 
+ Operazione di lettura stabile
	Lettura di un blocco dal primo disco se non risulta corretto si ripete $n$ volte 
	Se fallisce $n$ volte si legge dal secondo disco
+ Ripristino da un *crash*
	Scanzione e confronto dei blocchi dai due dischi
	Se risultano essere identici e validi abbiamo completato il ripristino
	Se un blocco risulta essere errato si utilizza il secondo disco per sovrascrivere il blocco 
	Se risultano essere validi ma differenti il primo disco sovrascrive il secondo

Cosa succede se un *crash* avviene durante una scrittura stabile ? 5 casi : 
+ crash avviene prima che entrambe le coppie del blocco siano scritte , i vecchi valori continueranno ad esistere
+ crash avviene durante la scrittura del drive 1 , ripristino del blocco sul drive 1 da parte del drive 2 ( ritorno allo stato precedente )
+ crash avviene dopo che abbiamo scritto sul drive 1 ma prima della scrittura sul drive 2 , il programma di ripristino copia il blocco dal drive 1 al drive 2 in modo che la scrittura abbia successo 
+ crash alla scrittura sul drive 2 semplicemente si scrive il blocco dal drive 1 al drive 2 in modo da avere i nuovi valori in entrambi
+ crash avviene dopo la scrittura sul drive 2 , la scrittura ha avuto successo

![[Pasted image 20240117120523.png]]

##### Altre tecniche di ottimizzazione

**Deframmentazione**

A seguito di modifiche ai dati si possono creare delle frammentazioni dei dati all'interno del disco

Periodicamente si sivolge la *deframmentazione* :
+ Si inseriscono i dati in relazione in settori contigui
+ Inseriamo dati in espansione vicino a spazi liberi 
+ Il partizionamento del disco aiuta a ridurre la frammentazione ( posizionamento strategico dei dati es separare i dati temporanei da quelli che cambiano meno spesso )

>[!note]
>La *deframmentazione* diminuisce il numero delle operazioni di ricerca da efettuare 

**Compressione**

Compressione dei dati in modo che occupino meno spazio all'interno del disco

| Vantaggi | Svantaggi |
| ---- | ---- |
| Miglioramento del tempo di trasferimento | Maggior overhead dovuto al processo di compressione e decompressione dei dati |
| Miglioramento del tempo di accesso |  |

**Copie di dati richieste più frequentemente**

Creazione di copie dei dati più richieste in diverse parti del disco in modo che si diminuisca il tempo medio di accesso ( mino tempo di ricerca e rotazione ) a quei dati

Adatta per dati in sola lettura o con rare modifiche

>[!warning]
>Può comportare overhead significativi di memoria 
>+ Mantenimento della coerenza
>+ Maggiore occupazione di spazio 

**Accorpamento dei record**

Lettura e scrittura di più record come un unico blocco di dati 

**Anticipazione del braccio del disco**

Quando il disco è inattvo si sposta il braccio nella posizione dove è maggiore la probabilità del prossimo accesso oppure al centro ( media )

>[!warning]
>Se non prevediamo in modo corretto potremmo subire degradazioni nelle prestazioni

Minore efficenza con la multiprogrammazione
### Software per I/O

>[!todo]
>#todo

## Caso di studio Linux

## Caso di studio Windows 8
