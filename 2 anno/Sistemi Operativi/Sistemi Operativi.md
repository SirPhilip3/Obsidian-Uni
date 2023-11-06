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
+ F : è la frequanza di clock del processore
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
	+ Aumento del *throughput* , infatti poichè questi hanno spazi di esecuzione differenti , se un thread è impattato da una operazione di I/O posso svolgere un thread diverso ma dello stesso processo
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
	+ Il numero di thread di livello utente e livello kernel non deve essere uguale
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

Un *thread pop-up* è un thread che viene creato per la gestione di messaggi in arrivo da parte di altri processi ( anche in processo collegati ad una rete )

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

Il *contesto di esecuzione* di un processo contiene :
+ Runtime stack
+ Lo stato dei registri della macchina
+ Degli attributi
+ Unità di esecuzione reale ( thread ) inviata al processore per l'esecuzione
Questo viene chiamato *PEB* ( *Process Environment Block* )

L'equivalente per un thread viene chiamato *TEB* ( *Thread Environment Block* ) ( contiene tutto ciò necessario ad un thread )

*Windows* può raggruppare vari processi in un *job* , in modo da gestire meglio le risorse per ogni thread relative a quel *job*

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
+ Scheduling di *medio intermedio*
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
	+ misura il tempo alla scadenza del processo ( ossia quanto manca alla deadline )
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
		+ Un porcesso potrebbe essere troppo grande per essere inserito  in una partizione
		![[Pasted image 20231030102424.png]]

#### Partizioni variabili

i *job* sono allocati in una partizione con le stesse dimensioni del *job*
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

