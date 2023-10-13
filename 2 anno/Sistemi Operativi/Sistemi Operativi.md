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

Un *processo* è un programma in esecuzione ed è caratterizzato da :
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
+ per differenziarsi il processo figlio esegue un *execve* per cambiare la propri immagine di memoria

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
+ Proprità del processo nello scheduling
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
+ SO toglie il processo dalla CPU salvendone il contesto di esecuzione nel suo *PCB*
+ SO carica il nuovo processo grazie ai dati presenti nel *PCB* del processo *ready*

Il tempo necessario per svolgere queste operazioni è un tempo "morto" per la CPU , ossia non viene fatta alcun calcolo per l'avanzamento di un processo , per questo il tempo di *contex switch* deve essere ridotto al minimo 

Questo processo può essere eseguito in hardware per alcune architetture

![[Pasted image 20231012101645.png]]

### Prestazioni CPU

Le prestazioni di una CPU possono essere calcolate in termini di *utilizzazione* della CPU 
L'utilizzazione dipende dal grado di *multiprogrammazione* , infatti se vi sono più processi in *ready* la CPU sarà maggiormente occupata.

L'utilizzazione della CPU dipende anche principalmente dal tempo che un processo è in attessa di I/O , infatti in quel tempo la CPU può svolgere un altro processo

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
	+ tenatare di eseguire un codice di operazione non valido
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

Lo scambio di messaggi può essere bidirezionale ossia ogni processo può agire sia come *mittente* che come *reicevitore*

I *messaggi* possono essere :
+ **bloccati** : richiede al *ricevente* di notificare al *mittente* quando viene ricevuto il messaggio , viene bloccato fino alla ricezione di questa notifica
+ **non bloccati** : permette al mittente di continuare ulteriori elaborazioni poichè non viene bloccato per aspettare la notifica di ricezione del messaggio

L'implementazione più comune per i messaggi è la *pipe* ossia si utilizza una regione di memoria protetta dal SO che funge da *buffer* consentendo ai due o più processi di scambiarsi dati 

#### IPC in sistemi distribuiti

In sistemi distribuiti i *messaggi* trasmessi possono essere corrotti o persi più facilmente per questo ci sono :
+ *protocolli di conferma* che confermano che le trasmissioni siano state effettuate correttamente ( aknowledgment )
+ meccanismi di *timeout* per fare in modo che se un messaggio non viene ricevuto entro un determinato lasso di tempo esso venga *ritrasmesso*

Inoltre per fare in modo che i messaggi vengano ricevuti dai processi corretti ad un processo ricevente viene assegnata una *porta* numerata dove ascolta per la ricezione del messaggio 

Deve inoltre essere sviluppato un sistema di autenticazione per garanitre la sicurezza dei dati ( in modo che un processo non possa fingersi un'altro )

#### Segnali

I *segnali* sono interruzioni software che notificano ad un processo l'avvenimento di un evento

// SO3.34 rileggi è libro
I *processi* possono *ricevere* , *ignorare* o *mascherare* un segnale
+ **ricevere** un segnale e quindi lancia una ruotine per la gestione di quel segnale 
+ **ignorare** un segnale ossia scartarlo
+ **mascherare** un segnale significa che il SO non consegnerà più segnali di quel tipo fino a quando il processo non cancella il *mascheramento* di quel segnale

### Caso di studio : processo UNIX

Tutti i *processi* hanno un insieme di indirizzi di memoria ( spazio di indirizzi virtuali )

Il *PCB* di un processo è mantenuto dal *kernel* in una regione proteta della memoria che i processi utente non possono accedere

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

