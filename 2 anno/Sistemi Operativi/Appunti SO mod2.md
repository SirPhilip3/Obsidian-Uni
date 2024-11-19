---
tags:
  - appunti
---
# 20/02/2024

**Creazione di processi**

Alla creazione del processo si assegna un ID , memoria  , 

processi sono in relazione tra loro -> gerarchia padre figli , processo init con id=1 nasce in modo spontaneo gli altri tutti figli di un genitore ( relazioni statiche )

shell crea processo figlio lo esegue , aspetta fine della sua esecuzione , continua , 

cntr+C termina il processo in esecuzione o può essere gestito dal processo

relazioni dinamiche 


per dire esplicitamente che il processo deve essere eseguito in background `{bash}sleep 5 &`
il processo che ha terminato viene segnalato solo se interagisco con la shell 

`{bash}ps` fa vedere processin in esecuzione 
`{bash}ps -o` che campi voglio visualizzare

qunado lancio comando in shell la shell è il genitore del processo

cntr+Z sospende il processo in foreground , bg in background, fg continua in foreground



relazioni di contenuto

+ unix figlio *duplicato* da genitore ( fork )
+ figlio esegue un programma differente ( win )

**fork**

creo il processo figlio :
+ condivide il codice ( immutabile in read only )
+ dati possono essere modificati quindi vengono "copiati" ( quella read-write )

per sapere che è differente dal padre si capisce poichè la fork ritorna un valore differente 

se valore di ritorno fork negativo = errore

se fork = 0 so di essere processo figlio se >0 allora è il pid del figlio , il padre non può scoprire il pid del figlio poichè potrebbe avere molti figli e se non glielo diamo subito non lo saprà mai

dopo la fork sono 2 processi ad eseguire il codice :

```c
pid = fork();
// da qui in poi codice eseguito da entrambi
```

getpid = proprio codice id , getppid codice id del padre
processi in esecuzione in parallelo ( o time sharing o su più core )

la terminazione prima figlio o padre potrebbero alternarsi il finire dei processi

fork2 

se fossero in timesharing in blocchi , se sono alternati vanno in core differenti

non possiamo assumere nulla sullo scheduler

la fork può fallire -> quando sono finite le risorse , se fallisce pericolosa per sistema operativo ( saturazione risorse del kernel ) se le risorse del kernel finiscono sonon problemi
ulimit e cgroups limitano il numero di rsorse allocate a quel terminale , non finisce le risorse del kernel

processi orfani e zombie

se il genitore termina prima del figlio -> processi orfani
il figlio termina prima del genitore , il genitore dovrebbe accorgersi della morte e raccoglierne le info ( se è stato terminato etcc mantenuto nella PCB ) se il padre non lo fa il processo rimane come processo zombie

il processo init adotta tutti gli orfani del sistema

processi zombie segnati come `{bash}<defunct>` 

cosa succede se termina il genitore diventa zombie orfano , adottato da init , ciclicamente legge le informazioni ciclicamente per i suoi figli adottati

# 22/02/2024

```c
#include <unistd.h>
#include <stdio.h>

int main() {
  pid_t f1,f2,f3;
  
  f1=fork();
  f2=fork();
  f3=fork();

  printf("%i%i%i ", (f1 > 0),(f2 > 0),(f3 > 0)); 
}
```

*exec*

codice e dati rimpiazzate con un codice nuovo e dei dati nuovi -> copy-on-write per evitare di copiare tutti i dati e poi eliminare , si fa quindi una copia ?virtuale che diventa fisica solo quando mi serve ( copia della pagetable ) e le marca come read only solo quando scrivo allora faccio la copia , finchè entrambi leggono non ho una copia dei dati

exec non ritorna mai, ritorna solo se la exec va in errore 
exec p con path non completo 

devo raccogliere gli zombie dopo che 

>[!todo]

# 27/02/2024

Esercitazione

# 29/02/2024

wait ruolo di una recieve sincrona

**Segnali**

Forma minimia di comunizazione in pratica sono le iterruzioni , 
*es* : 
- ctrl c , interrompe il processo in esecuizione nella shell ( shell->programma )
- eccezioni : divisione per 0 , segfault

cose asincrone -> sigalarm ( puntare un timer e poi essere risvegliato ) ( scheduling , soprattutto in time-sahring mette processo in exec + mette allrame per il tempo -> mi sveglo tolgo il processo ( salvo stato ) + metto nuovo processo )

segnale : 
+ ignora 
+ gestisce 
+ lasciare a so ( può decidere di igonararlo )

*es segnali*

SIGINT -> ctrl c -> interrupt da keyboard

IllegalIstruction -> chiamo istruzione che non esiste 

SIGKILL uccide un processo e lui non può gestirlo

posso definire dei segnali *custom*

SIGCHILD quando un filgio termina risveglia padre dalla wait

core dumped -> salva la memoria interna del programma

Action sono i comportamenti di default

>[!note]
>Il segnale non ha messagio oltre il numero associato ad un segnale 

>[!example]
```c
#include <unistd.h>
int main()
{
    alarm(3); // punta la sveglia a 3 secondi ( di default alarm termina )
    while(1){} // timeout per terminare il programma
}
```

shell analizza lo stato d'uscita del programma e stampa il motivo

con `signal` ci permette di cambiare il *gestore* ( una funzione ) dell'interruzione

```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void alarmHandler() // può essere utilizzato da più signal
{
    printf("questo me lo gestisco io!\n");
    alarm(3); // ri-setta il timer a 3 secondi
}

int main() { 
    signal(SIGALRM, alarmHandler); // SIGALRM è una macro ( posso sostituirlo con il suo numero ) , passo address di una funzione
    alarm(3);
    while(1){}
}
```

gestore di segnali ha tabella che aassegna ad ogni segnale il codice che lo gestisce 

quando esco dal gestore vado avanti con l'istruzione sucessiva

signal non è implementata in modo consistente in tutti gli UNIX , meglio utilzzare sigaction che funziona per tutti UNIX

`SIG_IGN` : macro per ignorare il segnale
`SIG_DFL` : per ritornare all'implementazone di defautl
`SIG_ERR`

signal ritorna l'indirizzo del precedente gestore del segnale

il segnale non viene bufferizzato

*kill* , sistem call manda un qualsiasi segnale ad un qualsiasi processo 

mascheramento dei segnali -> il segnale arriva e viene sospeso , quando tolgo il gestore vengono rieseguiti , molto più usato dell'ignorare  

se faccio 3 segnali == alla fine della maschera il segnale viene svolto una sola volta , non specificato in POSIX potrebbe essere che un OS lo implementi differentemente 

```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
        sigset_t newmask,oldmask;

        sigemptyset(&newmask);          // insieme vuoto
        sigaddset(&newmask, SIGINT);    // aggiunge SIGINT alla "maschera"
        // setta la nuova maschera e memorizza la vecchia
        if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0) { // oldmask valore di ritorno istanziato da sigprocmask
                perror("errore settaggio maschera"); exit(1); }

        printf("Sono protetto!\n");
        sleep(3);

        // reimposta la vecchia maschera 
        if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0) {
                perror("errore settaggio maschera"); exit(1); }

        printf("Non sono piu' protetto!\n");
        sleep(3);
}
```

**Interferenze e funzioni safe POSIX**

printf dentro handler viola funzioni safe

es posso interrompere `write` nel mentre della sua esecuzione senza avere problemi
se invece interrompo la printf rimane in uno stato inconsistente

handler corretto , :
+ uso solo safe dentro handler
+ maschero i segnali ogni volta 

# 05/03/2024

**Pipe**

-> | ->

tecnicamente è una *porta* di comunicazione dove la send è *asincrona* ( non aspetto che qualcuno li collezioni ) 

di 2 tipi 
+ senza nome -> usato solo tra processi che sono parenti
+ con nome -> chiunque può utilizzarla ( sapendo il nome )

per creare pipe senza nome `pipe()`

in linux `|` shell crea due processi 1 per il primo programma uno per il secondo , crea pipe e direziona output del 1 in pipe e 2 mette input ( direziona solo stdout )

il programma ricevente recieve sincrona

`pipe(filedes[2])` , file descrittori tabella di file , `filedes[0]` > lettura `filedes[1]` > scrittura 

l'array che metto in *pipe* copia per ogni processo creato 
prima della fork viene creata la pipe questa è *condivisa* tra i due processi 

pipe anonima
```c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main() {
  int fd[2];
 
  pipe(fd); /* crea la pipe */
  if (fork() == 0) {
    char *phrase = "prova a inviare questo!";
 
    close(fd[0]);                         /* chiude in lettura */
    write(fd[1],phrase,strlen(phrase)+1); /* invia anche 0x00 , scrive byte */
    close(fd[1]);                         /* chiude in scrittura */
  } else {
    char message[100]; // buffer 100 byte
    memset(message,0,100); // setto a 0 , le stringhe sono terminate da 0 se leggo una stringa non completa sono sicuro che la stringa termina con 0
    int bytesread; 
 
    close(fd[1]);                         /* chiude in scrittura */
    bytesread = read(fd[0],message,99); // recieve , 99 -> leggi al massimo 99 byte , sincrona non necessita wait , meglio mettere numero massimo per evitare bufferoverflow
    printf("ho letto dalla pipe %d bytes: '%s' \n",bytesread,message);
    close(fd[0]);                         /* chiude in lettura */
  }
}
```

chiudo i file in lettura e scrittura ->

il file descriptor copiato in entrambi i processi , li chiudo per eveitare che so pensi che ci siano 2 processi che leggono e scrivono -> il so sa che c'è 1 solo processo che scrive e 1 solo che legge in modo che quando faccio l'ultima close l'so rimuove la risorsa da memoria

la pipe assegna i valori di f\[0] e f\[1] con address dei file

comunicazione bidirezionale 2 pipe distinte altrimenti non so se ho scritto io o l'altro processo

chiusura utile per capire quando ho finito di scrivere / leggere , la read ritorna 0
leggere da una pipe chiusa è come leggere fino alla fine del file EOF

fa questo solo quando tutti i descrittore f\[1] sono stati chiusi
 
`SIGPIPE` -> generato errore in pipe , di default uccide il processo  

write su una pipe chiusa -> ignoro SIGPIPE ( dal code ) -> ritorno -1 -> errore poichè se scrivessi "buttare" via byte , poichè nessuno li leggerebbe 

wc -> wordcount 

0 -> stdin
1-> stdout
2 ->stderr

dup2 -> duplico un descrittore in un'altro -> copio il descrittore di f\[1] in 1 ossia ridireziono l'output del programma al terminale
stessa cosa per ridirezionare l'input ossia ridireziono l'input al mio descrittore della pipe 
visto che se tenessimo sia f\[0] che 0 avremmo 2 input -> dobbiamo chiuderlo subito altrimenti le risorse non verrebbero deallocate ( 0 viene chiuso dalla `execlp` )

*pipe con nome*

in realtà è un file ( fifo in unix ) 
`mkfifo` -> crea pipe con nome *p*rw-w

la open è bloccante in lettura fino a che qualcunaltro la apra in scrittura
 
`myfifo()` anche da c , permission 0666 -> leggere e scrivere , se non eseiste già non fa nulla 
`open()` `O_RDONLY` -> pipe aperta solo in lettura

sulle pipe leggo e scrivo byte

`strlen(message)+1` manda stringa + byte 0 per mandare a capo 

`;` -> esegue in sequenza 


`./lettore & ./scrittore & ./scrittore & ./scrittore & ./lettore & ./lettore`
interfersicono i messaggi , lettori non si coordinano tra loro per leggere ciò che viene scritto , non ho garanzia che ogni lettore legge completamente un messaggio 

# 14/03/2024

comunicazione in memoria condivisa tra threads 

thread -> condivide delle risorse del processo , parti d'esecuazione di un processo , light weight processes , mem dati condivisa tra tutti i thread del processo 

Produttore - Consumatore

`{bash} ls | grep 'ciao'`
ls produce grep consuma

message passing 
```c
produttore(){
	while(1){
		// produce un dato
		send(a,dato) // può essere asincrona me deve diventare sincorna se il buffer si riempie , es se l'altro aspetta prima di leggere l'output etccc  
	}
}
```
```c
consumatore(){
	while(1){
		recieve(a,&dato) // deve essere bloccante , se non è sincrona devo gestire l'errore
		d = ....
		// consuo d
		// legge un dato e poi lo consuma
	}
}
```

porta a è condivisa

con la memoria condivisa ?? ( con buffer di dimensione illimitata )
 aggiungo un indice che indica dove ho messo i dati 
```c
int inserisci = 0; // globale accessibile da tutti i thread
produttore(){
	while(1){
		buffer[inserisci]=dato;
		insersci++;
	}
}
```
```c
int retrieve = 0; // globale
consumatore(){
	while(1){
		while(retrieve==inserisci){}// busy waiting
		dato = buffer[retrieve]; // non è corretto poichè la recieve potrebbe leggere più avanti di inserisci
		retrieve++;
	}
}
```

non implementabile perchè il buffer non è infinito
implemento coda -> buffer circolare , lavoro con il modulo per accedere elementi

```c
data_t buffer[MAX]
int inserisci = 0,retrieve = 0;
produttore(){
	while(1){
		// produce
		while((inserisci+1)%MAX==preleva){} // busy waiting
		buffer[inserisci]=dato;
		inserisci = (insersci+1)%MAX;
	}
}
consumatore(){
	while(1){
		while(retrieve==inserisci){}// busy waiting
		dato = buffer[retrieve]; // non è corretto poichè la recieve potrebbe leggere più avanti di inserisci
		retrieve=(retrieve+1)%MAX;
	}
}
```

versione più intuitiva -> uso contatore per sapere quanto ho scritto o letto nel buffer

```c
data_t buffer[MAX]
int inserisci = 0,retrieve = 0;
int counter = 0;
produttore(){
	while(1){
		// produce
		while(counter == MAX){} // busy waiting
		buffer[inserisci]=dato;
		inserisci = (insersci+1)%MAX;
		counter++;
	}
}
consumatore(){
	while(1){
		while(counter == 0){}// busy waiting
		dato = buffer[retrieve]; // non è corretto poichè la recieve potrebbe leggere più avanti di inserisci
		retrieve=(retrieve+1)%MAX;
		counter--;
	}
}
```

>[!warning]
>Soluzione incorretta , race condition  quando 2 thread modificano lo stesso dato 
>Perchè ? 
>1-> leggo dalla ram `r1=contatore` 
>3-> incremento `r1++`
>2-> faccio store `contatore = r1`
>
>1-> leggo dalla ram `r2=contatore` 
>3-> incremento `r2--`
>2-> faccio store `contatore = r2`
>
>nella CPU potrei leggere r2 prima della scrittura 

risoluzione , dovrei aspettare l'altro thread , devo sincronizzarla con se stessa 
per proteggere codice che modifica dati condivisi da race condition , 
problema della *sezione critica* -> tutto ciò che viene messo in sezione critica deve essere prottetto da altri thread

# 19/03/2024

*sezione critica* codice che deve essere protetto , le istruzioni di ogni thread non devono essere interrotte da altre di altri processi?? 

```c
<entrance>
	<critical section>
<exit>
```

proprietà che deve soddisfare la sezione critica : 
	solo un thread alla volta può accedere alla sezione critica , *mutua esclusione* 
	mutex oggetti che permettnon di ottenere questa proprietà 

Decidere cosa fare in entrance e exit :
1. soluzione software 
	In pratica utilizzare il busy waiting 
2. sol che si basa sul SO
3. soluzioni con istruzioni hardware speciali


*sol sftw*

sol su 2 thread 

```c
t0{
	....
	<sezione critica>
	....
}

t1{
	....
	<sezione critica>
	....
}
```

1. utilizzo un flag booleano se qualcuno è dentro la sezione critica , `lock`

```c
bool lock = false; // in nessuna szezione critica

t0{
	....
	while(lock){} // se lock true aspetto 
	lock = true;
	<sezione critica>
	lock = false;
	....
}

t1{
	....
	while(lock){}
	lock = true;
	<sezione critica>
	lock = false;
	....
}
```

>[!warning]
>Stesso problema di prima , lock può essere modificato da entrambi , oppure entrambi entrano
>Non c'è mutua esclusione 

2. dò io la priorità a qualcuno 

```c
int turno = 0; // in nessuna szezione critica

t0{
	....
	while(turno!=0){} // non è il tuo turno -> turno di 1 poichè !=0
	<sezione critica>
	turno = 1;
	....
}

t1{
	....
	while(turno!=1){}
	<sezione critica>
	turno = 0;
	....
}
```

>[!note]
>non possono entrare 2 assieme poichè la condizione di entrata è differente 

dà **mututa esclusione** 

>[!warning]
>i due thread devono per forza alternarsi 

proprità del *progresso* a meno che non ci sia un buon motivo , 
se la sezione critica è libera ( nessuno è in sezione critica ) il thread deve poter entrarci

3. pronto

```c
pronto[2]={false,false};

t0{
	....
	pronto[0]=true;
	while(pronto[1]){} // se l'altro è pronto
	<sezione critica>
	pronto[0] = false;
	....
}

t1{
	....
	pronto[1]=true;
	while(pronto[0]){}
	<sezione critica>
	pronto[1] = false;
	....
}

```

>[!warning]
>Se vengono settati entrambi i pronto a true entrambi i thread si bloccano , *deadlock*

c'è *progresso*

**Soluzione** ( algoritmo di Peterson ) per 2 thread

```c
pronto[2]={false,false};
int turno = 0;

t0{
	....
	pronto[0]=true;
	turno = 1; // turno viene concesso
	while(pronto[1]&&turno!=0){} // se l'altro è pronto
	<sezione critica>
	pronto[0] = false;
	....
}

t1{
	....
	pronto[1]=true;
	turno = 0;
	while(pronto[0]&&turno!=1){}
	<sezione critica>
	pronto[1] = false;
	....
}
```

**Soluzioni HW** 

creato per evitare il busy waiting -> preco tempo di CPU , se single core devo aspettare il suo stallo di tempo , in multi core quando vado in sezione critica devo bloccare tutti i core comunque , non cambia a livello di performance in multi core 

da comunque race condition poichè ottimizzazioni del compiler e CPU modificano ordine delle istruzioni , preservano corretteza del programma ma non del multithreading

*istruzioni hw speciali*

test_and_set , architettura offre istruzione macchina che fa in modo indivisibile un'operazione normalmente divisibile 

permette di fare un test e un set(assegnamento) in modo indivisibile a livello architetturale

```c
// indivisibile
bool test&set(bool *x){
	tmp = *x 
	*x = true;
	// accede in modo esclusivo al bus di memoria 
	return tmp;
}
```

cambia valore di X e ritorna il valore vecchio di X ma contempraneamente viene assegnata a *true*

*lock* : 
```c
bool lock = false; // in nessuna szezione critica

t0{
	....
	while(test&set(&lock)){} // ritorna false  
	// lock ora è true
	<sezione critica>
	lock = false; // questo è unsafe posso esegure op prima/dopo
	....
}

t1{
	....
	while(test&set(&lock)){}
	// lock ora è true
	<sezione critica>
	lock = false;
	....
}
```

while su un cosa inefficente , guardo prima lock e poi test&set solo quando necessario

```c
while(test&set(&lock)){
	while(lock){}
}
```

*Intel* : 

```c
// exchange
XCHG(bool *x, *y){
	tmp = *x;
	*x = *y;
	*y = tmp;
	
}
```

# 21/03/2024

( lab )

-pthread per linkare libreria per creazione di thread in POSIX

```c
pthread_create(pthread_t *thread, pthread_attr_t *attr, void *(*start_routine)(void *), void *arg)
```

```c
pthread_t *thread
```
Passa id thread 
attr attributi per modificare impostazioni del thread NULL = default 

```c
*()
```
pointer a funzione  , puntatore a void , possiamo passare un pointer di qualsiasi tipo e poi castarlo a void \*  , nome di funzione che prende pointer ritorna pointer -> codice che eseguirà

se voglio passare argomenti alla funzione \*arg 

```c
pthread_exit
```
usciamo dal thread  + ritorniamo un pointer al valore di ritorno

```c
pthread_join
```
aspetta terminazione di un thread  primo è l'id del ritorno , secondo è l'eventuale return , visto che quello che ritorno è pointer a void devo salvarlo su un address , null se non mi interessa il valore di ritorn o 

ritornano 0 se successo >0 se vanno in errore 

```c
pthread_detach
```
non si vuole attendere la detach utilizzato se non volgiamo fare la join , fino a che non finisce il processo altrimenti rimarrebbero thread zombie che attendono di essere joinati

A livello di sistema i therad hanno un id differente da quello all'interno del processo 
```c
syscall(SYS_gettid) // per prendere id di sistema
```

# 26/03/2024

XCHG , scambia 2 valori di 2 variabile booleane 

Abbiamo in memoria condivisa il token che indica quando un thread è in sezione critica poi ognuno si prende il token

```c
bool lock = false;
t0{
	bool b0 = true;
	while(b0){ XCHG( &b0, &lock); } // se un thread ha fatto exchange qui continuerà a scambiare sempre true perchè lock è diventato true
	<sezione critica>
	XCGH( &b0, &lock )
}

t1{
	bool b1 = true;
	while(b1){ XCHG( &b1, &lock); } // variabile locale non da race condition
	<sezione critica>
	XCGH( &b1, &lock );
}
```

XCHG fa da barriera e il compiler / architettura evita di ottimizzare riorganizzando le righe tra le due exchange

Ottimizzazione : evitare di fare exchange anche quando non serve

## Semafori

Ci permette di evitare il busy waiting con il while , ed in modo semplice 

**Example**

![[Drawing 2024-03-26 12.40.45.excalidraw]]

Semafori contatori 

Se 2 entrate entrano simultaneamente , senza sezione critica race condition sullo stesso contatore 
Semaforo deve evitate race condition

sistema operativo gestisce la race condition ( implementato attraverso spin-lock ) 

possono anche dire quanti stanno aspettando all'entrata , quando qualcuno è in coda si tolgie -1 dal semaforo , vale per tutti i thread 

Quando esce un out sblocco quella che ha il numero negativo minore , ossia quella che aveve prenotato per primo 

realizzati da Dijkstra 1965

```c
struct semaphore{
	int valore; // contatore 
	thread *queue ; // coda di thread
}
```

Due primitive (S = semaforo): 
+ `P(S)` : wait : 
	deve decrementare il valore
	Se il valore è diventato negativo metto il coda il thread 
```c
P(){
	S.valore --;
	if(S.valore<0)
		<mette thread corrente in S.queue>
}
```
+ `V(S)` : post
	Incrementa valore 
	Se il valore minore o ugale di 0 sblocco il primo thread della coda 
```c
V(){
	S.valore++;
	if(S.valore<=0)
		<sblocca il primo thread in attesa in S.queue>
}
```

P e S blocca me e sblocca qualcun'altro

mutua esclusione può entrare solo 1 thread -> mutex = 1

```c
mutex = 1;

t0{
	P(mutex)
	<sezione critica>
	S(mutex)
}

t1{
	P(mutex)
	<sezione critica>
	V(mutex)
}
```

Esempio con 3 processi , se 1 solo entra in sc ma gli altri non lo sono non vengono bloccati processi , se invece  vi sono altri processi che vogliono entrare aspettano che uno esca

posso usare valori di `valore` più grande quando vogliamo gestire l'accesso a risorse duplicate 

es ho 3 stampanti , non mi interessa su quale stampo , potrei usare un semaforo inizializzato a 3 su vari thread che stampano , possono stampare in 3 alla volta 

# 28/03/2024

thread safe -> le funzioni possono o non essere thread safe 
`printf` è thread safe ( non safe per i segnali ) poichè `stdio` è thread safe

`mt_safe locale` -> sono safe da invocare in presenza di altri thread , locale -> legge senza sincronizzazione , ossia leggo se qualcuno modifica nella variabile locale , se uso funzioni che modificano il locale allora in questo caso sono unsafe altrimenti sono safe

codifica i mutex in `pthread mutex` utilizzati solo per sezione critica 

`pthread condition` -> utilizzati per implementare i monitor in C

libreria `semaphore.h`

`sem_t` -> tipo del semaforo da mettere globale 

funzione per inzialzzare semaforo -> primo indirizzo semaforo , secondo sempre a 0 ( per dire se fra thread 0 o processi !=0 ) ultimo è il valore del semaforo

init fatto prima di dichiarare i thread 

+ P(sem) -> `int sem_wait(sem_t *sem)`
+ V(sem) -> `int sem_post(sem_t *sem)`

`sem_getValue` -> non da utilizzare per la sincronizzazione ->l'implementazione potrebbe ritornare 0 anche se ci sono 100 thread in attesa 

`sem_destroy` per eliminare il semaforo , se elimino durante l'utilizzo comportamento non specificato

semafori con il nome come per le pipe sono semafori che esistono a livello del sistema operativo

**Esercizi**

--

# 02/04/2024

**Produttore -> consumatore molti ad uno**

Produttori scrivono su code separate tra loro , il consumatore legge un dato per ogni coda e fa qualcosa , computazione che dipende da tutte le altre 

Ogni produttore ha un suo indice 

```c
queue_t datoProduttore[N]; // -> N indica il numero di produttori (N-1)
// MAX = dimensione delle code , meglio di allocazione dinamica -> prima o poi finisco la memoria se il produttore è più veloce del consumatore 
// se la struttura dati non è thread safe dobbiamo mettere mutex
semafori piene[N] = {0,0...,0}, vuote[N] = {MAX,MAX,...,MAX}; // array di semafori

// mutex
semaforo mutex[N] = {1,1,...,1,};

// se metto un solo mutex sincornizzo troppo altri produttori potrebbero scrivere nei loro buffer e non interferire tra loro 

Produttore(i){
	while(1){
		// produce d
		// aspetto quando raggiungo dim massima , mi servono i-semafori
		P(vuote[i])
		P(mutex[i])
		datoProduttre[i].add(d); // aggiunge alla coda i il dato d
		V(mutex[i])
		V(piene[i])
	}
}

Consumatore{
	dato_t d[N]; // array locale per i dati 
	while(1){
		// legge 1 dato per ogni coda
		for(j = 0; j<N; j++){
			P(piene[j])
			P(mutex[j])
			d[j]=datoProduttore[j].remove() // prendo il dato e lo metto in un array locale
			V(mutex[j])
			V(vuote[j])
		}
		// consumo tutti i dati d[0],d[1].... d[N-1] 
	}
}
```

meglio sincronizzare di più che di meno

**Lettori e scrittori**

thread lettore , 

```c
semaforo scrittura=1; // di fatto un mutex per solo 1 scrittore
int n_lettori = 0; // può dare race condition 
semaforo mutex=1; // per poteggere n_lettori
lettore{
	while(1){
		// quando ho uno scrittore devo aspettare 
		// posso entrare qunado ho già dei lettori all'interno della sezione critica
		// solo il primo lettore che entra in sezione critica devo fare P(scrittura) -> prendo il controllo della sezione scritica 
		// mi serve un counter
		// race condition su n_lettori e gli if -> per risolvere creo una sezione critica
		P(mutex);
		n_lettori++;
		if(n_lettori==1) 
			P(scrittura) // V mutex dopo if perchè un thread potrebbe siperarmi e fare prima la if
			// Se faccio P(scrittura) essendo bloccante potrebbe fare deathlock
		V(mutex)

		<legge da risorsa condivisa>

		P(mutex)
		n_lettori--;
		if(n_lettori==0) // ultimo che esce dalla sezione critica libera la sezione critica
			V(scrittura)
		V(mutex)
	}
}

scrittore{
	while(1){
		P(scrittura)
		<modifica/scrive su risorsa condivisa>
		V(scrittura)
	}
}
```

race condition -> scrittori ( ex 2 scrittori scrivono contemporaneamente ) -> mutex

lettori tra di loro non danno race condition

lettori potrebbero leggere cose sbagliate con scrittori , non permetto ai lettori di leggere mentre vengono scritte 
*sezione critica*
può accedere 1 scrittore (mutex) oppure tanti lettori

*dim*

1. Entra uno scrittore -> scrittura = 0
2. Arriva il primo lettore -> 
		1. mutex = 0 
	1. Faccio P(scrittura) e mi blocco ( scrittura = 0 )
3. Arriva altro lettore -> si ferma su mutex ( mutex = 0 ) , primo lettore sta aspettando lo scrittore *oki*


1. Entra un lettore ( scrittura = 0  )
	1. svolge lettura
2. Altri lettori saltano if e fanno anche loro lettura
3. Arriva scrittore non può acquisire (scrittura = 0) 

>[!warning] 
>Se entrano più lettori che ne escono -> *starvation* dello scrittore 

soluzione corretta con starvation , esiste sol simmetrica con starvation ai lettori , + soluzione equa , quando c'è un scrittore che aspetta si ferma l'entrata dei lettori e poi faccio scrittore etcc

**Filosofi a cena**

5 filosofi > 1 bacchetta per piatto 

ogni filosofo utilizza la bacchetta della sx e dx

```c
filosofo(i){
	while(1){
		// pensa
		raccogli(i)//sx
		raccogli((i+1)%5) //dx

		deposita(i)
		deposita((i+1)%5)
	}
}
```

sol con semafori

```c
// 5 mutex , uno per ogni bacchetta differente
semafori bacchette[5]={1,1,1,1,1};

filosofo(i){
	while(1){
		// pensa
		P(bacchetta[i])
		P(bacchetta[(i+1)%5])
		// raccogli(i)//sx
		// raccogli((i+1)%5) //dx
		// mangio
		// deposita(i)
		// deposita((i+1)%5)
		V(bacchetta[i])
		V(bacchetta[(i+1)%5])
	}
}
```

>[!warning] 
>Se tutti prendono la bacchetta di sx nessuno può prendere bacchette di dx 
>**Deathlock** 

Permetto di mangiare al massimo in 4 -> 1 bacchetta rimane libera -> almeno un filosofo mangia poi a catena si sbloccano i rimanenti

```c
// 5 mutex , uno per ogni bacchetta differente
semafori bacchette[5]={1,1,1,1,1};
semaforo posti = 4; 
filosofo(i){
	while(1){
		// pensa
		P(posti)
		P(bacchetta[i])
		P(bacchetta[(i+1)%5])
		// raccogli(i)//sx
		// raccogli((i+1)%5) //dx
			// mangio
		// deposita(i)
		// deposita((i+1)%5)

		// potrei fare V(posti) qui tanto mi interessa che non siano mai in 5 a prendere le bacchette comunque al massimo 2 che mangiano in contemporanea 

		V(bacchetta[i])
		V(bacchetta[(i+1)%5])
		V(posti)
	}
}
```

2 sol -> senza aggiungere semafori usando solo le bacchette 

Faccio in modo che basti che uno raccolga le bacchette in ordine differente 

```c
// 5 mutex , uno per ogni bacchetta differente
semafori bacchette[5]={1,1,1,1,1};

filosofo(i){
	while(1){
		// pensa
		if(i==4)
			P(bacchetta[0]) // dx
			P(bacchetta[4]) // sx
		else{
			P(bacchetta[i]) // sx
			P(bacchetta[(i+1)%5]) // dx
		}
		// raccogli(i)//sx
		// raccogli((i+1)%5) //dx
			// mangio
		// deposita(i)
		// deposita((i+1)%5)
		V(bacchetta[i])
		V(bacchetta[(i+1)%5])
	}
}
```

3 sol -> 

>[!error] 
>mutex prima e dopo P(bacchette) -> sincronizza troppo -> se un filofo vuole mangiare una baccheta di uno che è passato il mutex blocca tutti gli altri filosofi che potrebbero mangiare

# 04/04/2024

Lab

# 09/04/2024

Eesercitazione punto bonus

sem_wait--
sem_post++

# 16/04/2024

**Monitor**

semafori -> sincronizzazione è sconnessa dai thread stessi , decentralizzata , sparsa nell'applicazione , example -> annidando i semafori

monitor sono un costrutto linguistico che semplificano la programmazione multithread 

contiene : 
+ dati condivisi
+ accesso ai dati tramite funzioni
	+ sono in mutua esclusione 

un moitor è di fatto una sezione critica

variabili *condition* ( anche in pthread ) -> sono semafori sempre rossi , sono solo code
+ wait -> sempre bloccante e rilascia la mutua esclusione del monitor ( in modo automatio )
+ signal/notify -> sbloccano il primo thread in coda , altrimenti non fa nulla se la coda è vuota

![[monitor.excalidraw]]


signal sblocca il primo thread in coda e blocca il thread corrente su una coda urgente per il mutex 

notify sblocca T1 ma non entra subito -> viene ri messo nella coda per i mutex e T2 esegue , deve riaqiusire il mutex dopo l'uscita di T2 e dopo ulteriori thread nella stessa coda per il mutex

>[!example] 
>
>Produttore consumatore , la mutua esclusione è "gratis" , logica + lock

```c

monitor PC{
	dato_t buffer[MAX]
	int inserisci = 0;
	int preleva = 0;
	int contatore = 0; // numero di celle scritte 

	Condition piene , vuote;
	// funzioni già in mutua esclusione non devo considerare i mutex
	// motivo per che mi blocco e sblocco determina se mi servono code differenti
	// stesso motivo = unica coda 
	// motivi differenti = code differenti
	void scrivi(dato_t d){
		if(contatotre == MAX) // non posso più scrivere 
			// sto aspettando una vuota 
			vuote.wait()
			// mi aspetto che qui ci sia una cella vuota 
		buffer[inserisci]=d
		inserisci++;
		contatore++;
		// è giusto che sblocchi un lettore poichè siamo sicuri che abbiamo un elemento e l'if wait non viene più controllato e so che posso leggere
		piene.signal()
		// se lo notifico ed entra dopo possono entrare altri thread che leggono  
	}

	dato_t leggi(){
		if(contstotre == 0) // non posso più scrivere 
			piena.wait()
		d = buffer[preleva];
		preleva=(preleva++)%MAX
		contatore--;
		vuote.signal()
	}
}

Produttore(){
	while(1){
		// produce d
		pc.scrivi(d) // scrive d dentro la struttura dati del monitor
	} 
}

Consumatore(){
	while(1){
		pc.leggi()
		// consuma d
	}
}
```

sincronizzazione sulla scrittura e lettura tutta all'interno del monitor

>[!example] 

nella coda per il mutex C P1 P2

1. C -> leggi -> contatore = 0 , fa subito la wait , entra in coda piene
2. il monitor ra è libero entra P1 -> scrivi , inserice , incrementa contatore = 1 , signal , si auto esclude dal monitor
	1. sblocca C -> legge value -> contatore = 0 , fa vuote.signal (la coda è vuota , non succede nulla)
	2. C esce
3. P1 rientra dalla coda urgent ( prima guardo coda urgent e poi la coda per il monitor ) , non fa nulla dopo signal ed esce
4. P2 entra contatore = 1 , signal che non fa nulla perchè adesso piena è una coda vuota

compito di chi fa la signal sbloccare al momento giusto 

con la **notify** ??

```c

monitor PC{
	dato_t buffer[MAX]
	int inserisci = 0;
	int preleva = 0;
	int contatore = 0; // numero di celle scritte 

	Condition piene , vuote;
	void scrivi(dato_t d){
		if(contatotre == MAX) 
			vuote.wait()
		buffer[inserisci]=d
		inserisci++;
		contatore++;
		
		piene.notify()
		
	}

	dato_t leggi(){
		// lascio allo scheduler decidere 
		// while perchè potrebbe avermi sbloccato quando il contatore è diverso da 0 , note -> sblocca alla riga sucessiva della wait ma a quel punto non sono sicuro che counter == 0 quindi la ricontrollo con il while , se il counter è ancora == 0 continuo a bloccarmi 
		while(contatotre == 0) // non posso più scrivere 
			piena.wait()
		d = buffer[preleva];
		preleva=(preleva++)%MAX
		contatore--;
		vuote.notify()
	}
}

Produttore(){
	while(1){
		// produce d
		pc.scrivi(d) // scrive d dentro la struttura dati del monitor
	} 
}

Consumatore(){
	while(1){
		pc.leggi()
		// consuma d
	}
}
```

**Filosofi** con raccolta atomica

non faccio raccogliere uno alla volta ma 2 assieme , raccolfo tutte e due o nessuna 

```c
monitor Tavola{

	bool bacchette[5] = {true,true,true,true,true} // sono tutte sul tavolo 

	Condition filosofi[5]

	raccoglie(int i){
		// mi blocco quando non ci sono le bacchette
		while(!bacchette[i]|| !bacchette[(i+1)%5]) // finchè non c'è bacchetta a desta o a sinistra mi blocco
			filosofi[i].wait();

		bacchette[i] = false;
		bacchette[(i+1)%5] = false;
	}

	deposita(int i){
		// rimette le bacchette 
		bacchette[i]=true
		bacchette[(i+1)%5] = true;
		// potrei bloccare o il filosofo a dx o a sx , mi servono 5 code
		// solo i filosofi a dx o sx potrebbero poter mangiare
		// +4 perchè il modulo può ritornare un numero negativo
		filosofi[(i+4)%5].notify();
		filosofi[(i+1)%5].notify();
	}

}

filosofi(i){
	while(1){
	// pensa
	tavola.raccogli(i)

	// mangia

	tavola.deposita(i)
	
	}
}
```


Se volessi utilizzare la signal :

```c
monitor Tavola{

	bool bacchette[5] = {true,true,true,true,true} // sono tutte sul tavolo 

	Condition filosofi[5]

	raccoglie(int i){
		// mi blocco quando non ci sono le bacchette
		if(!bacchette[i]|| !bacchette[(i+1)%5]) // finchè non c'è bacchetta a desta o a sinistra mi blocco
			filosofi[i].wait();

		bacchette[i] = false;
		bacchette[(i+1)%5] = false;
	}

	deposita(int i){
		// rimette le bacchette 
		bacchette[i]=true
		bacchette[(i+1)%5] = true;
		// con signal qui potrebbe partire anche solo aggiungendone 1 al tavolo
		// devo sapere se esiste bacchetta a sinistra del filosofo di sinstra
		if(bacchetta[i+4]%5) // deve essere false la if di raccoglie
			filosofi[(i+4)%5].signal();
		if(bacchetta[i+2]%5)
			filosofi[(i+1)%5].signal();
	}

}
```

Potrebbe penalizzare un filosofo che non mangia mai -> c'è sempre uno alla mia destra e sinistra che mangia , se quelli di fianco a me si alternano ad usare le bacchette non esce mai dalla wait

# 18/04/2024

programmazione con i monitor

**Semafori con monitor** 
hanno lo stesso potere espressivo , fare un semaforo sentro i monitor è ez

Soluzione dei filosofi con solo 4 filosofi

```c
// praticamente per implemetnare in semaforo con i monitor metti ciò che serve dentro il monitor

// in pratica è un semaforo contatore ma in questo caso i semafori non vanno in negativo
// il monitor stesso è mutex quindi non ho mai race condition
monitor Tavola{
	int sedie = 4;
	// coda -> condition nei monitor
	Condition sedia;
	siediti() // non ci interessa chi si siede
	{
		while(sedie==0) 
			sedia.wait();
		sedie=sedie-1; // la prendo se la posseggo
	}
	alzati(){
		sedie = sedie + 1;
		sedia.notify();
	}
}

// voglio che questo sia eseguito da al massimo 4 filosofi
filosofo(i)
	// pensa 
	tavolo.siediti()
	// raccoglie le bachchette
	// mangia
	//deposita bacchette
	tavola.alzati()
```

**Lettori Scrittori** 

```c
monitor rwd{
	bool scrittore = false; // se lo scrittore sta scrivendo ( dentro sezione critica ) o no
	int lettori = 0;
	Condition c;
	initLeggi(){
		while(scrittore) // finchè c'è uno scrittore aspetto
			c.wait()
		lettori++;
	}
	endLeggi(){
		lettori--;
		if(lettori==0) // notifico solo quando non ve ne sono più tanto se ne abbiamo >0 rimane nel while sotto
			c.notify
	}
	initScrivi(){
		while(lettori>0||scrittore) //
			c.wait()
		scrittore = true;
	}
	endScrivi(){
		scrittore = false;
		// potrebbero accodarsi sia scrittore che lettori 
	}
}
// policy 1 scrittore o tanti lettori 
lettore{
	// thread che accede solo in lettura
	while(1){
		rwd.initLeggi()
		// read
		rwd.endLeggi();
		// voglio svegliare 1 solo se scrittore e molti se lettori perchè potrebbero essercene più di uno in coda
		c.notifyAll(); // sveglia tutti ed essendo in un while vince o uno scrittore e tutti si bloccano oppure se sis sveglia lettore tutti scrittori si bloccano e gl altri lettori si sbloccano 
	}
}

scrittore{
	while(1){
		rwd.initScrivi();
		// leggi
		rwd.endScrivi();
	}
}
```

posso avere **starvation** agli scrittori -> ....

Soluzione grenerica -> ho un ordine di arrivo in cui richiedo l'ingresso al monitor
prima di far entrare altri lettori dopo aver incontrato uno scrittore svolgo lo scrittore -> non voglio sorpassare lo scrittore

utilizzo un coda non condition ma esplicta

```c
monitor rwd{
	queue Q;
	bool scrittore = false; 
	int lettori = 0;
	Condition c;
	initLeggi(i){ // i = id thread
		Q.add(i); // aggiungo in cosa il lettore
		while(scrittore||Q.top()!=i) // se non sono io il primo della coda  
			c.wait()
		lettori++;
		Q.remove()
		c.notifyAll() 
	}
	endLeggi(){
		Q.remove()
		lettori--;
		if(lettori==0) 
			c.notifyAll()
	}
	initScrivi(i){
		Q.add(i); // aggiungo in coda lo scrittore
		while(lettori>0||scrittore||Q.top()!=i) // finchè non è il mio turno
			c.wait()
		scrittore = true;
		Q.remove()
		// se entra uno scrittore c'è solo lui
	}
	endScrivi(){
		scrittore = false;
		c.notifyAll()
	}
}
```

se aggiungo condizione di bloccaggio probabilmente devo notificare di più 

# 23/04/2024

thread in java 

classe Thread in java -> getName -> ritorna stringa dell'id del thread

dentro run codice del thread t.run() -> call funzione 

t.start() -> starta il thread nella jvm

tutte le classi che impleemtano runnable candidati per creare dei thread e poi lo passo alla classe thread

variabili condition -> sono come dei semafori sempre rossi , sempre bloccante 

**monitor in java** :

ogni oggetto ha un mutex , il metodo aquisirà il mutex dentro al metodo syncornized , 

oltre al mutex c'è coda implicita utilizzata per notify, wait, notifyall

se i metodi non sono statici ogni classe un suo mutex , se invece voglio più istanzee evoglio mutua eslusione su più oggetti mi basta dichiarae il metodo statico in modo che il mutex diventa unico per tutti gli oggetti 

sincronizzazioen rientrante -> chiamare un metodo sync da un altro sync senza problemi 

# 30/04/2024

lab monitor java

# 09/05/2024

se esame gio

**Stallo** : andiamo in stallo quando in un insieme di processi o thread tutti attendono un qulcosa che può essere fatto soloda altri processi di S 

sotto che condizioni avviene uno stallo :

1. *mutua esclusione* : fa attendere dei thread ( altrimenti i thread non attenderebbero mai )
2. *mancanza di rilascio di una risorsa* : Possesso e attesa (call and wait)
   Ho una risorsa e chiedo per un qualcosaltro ( richiesta delle risorse in modo incrementale ) , questa portebbe essere a sua volta in attesa 
3. Se non ho un modo di forzare il rilascio di una risorsa ( posso fare la prelazione sulla cpu salvando lo stato )  *prelazione*
4. Attesa circolare ( a *runtime* )

1 , 2 , 3 -> condizioni *statiche* 

Per evitare lo stallo : 
+ Prevenire ( pre runtime ) -> lo stallo non può avvenire
+ Controlla a runtime lo stato del sistema se sta per avvenire uno stallo cerco di evitarlo -> monitoraggio e evito attesa circolare 
+ Riconoscimento dello stallo -> mi accorgo dell'avvenimento dello stallo (reset o rollback) , meglio i primi 2 casi

**Prevenire** : 

Provo a toglie una condizione di stallo , se posso toglierla allora non avverrà lo stallo

1. negare la mutua esclusione ?
	Dipende dalla risorsa stessa 
>[!example] 
>Per i lettori ha senso negare ma non per gli scrittori

2. negare possesso e attesa -> contrario è raccolta (allocazione) atomica , 
	Dipende dalle risorse 

3. Prelazione -> dipende sempre dall'applicazione , rischio di corrompere lo stato
4. Negare attesa circolare -> a runtime -> vuol dire prevenire l'attesa circolare 
   Attraverso *allocazione gerarchica* 
   Divido le risorse in classi ordinate secondo una gerachia , devo seguire questo ordine anche quando alloco le risorse , una risorsa viene concessa solo se un processo possiede (se ne possiede) risorse di minore "importanza"

non va in stallo perchè 

![[Drawing 2024-05-09 13.13.35.excalidraw]]
Se succedesse questo la policy non sarebbe rispettata e non alloco la risorsa 

Filosofi a cena , 
numero le bacchette , l'indice delle bachette è la gerarchia 

tutti raccolgono prima la sinistra e uno raccoglierà prima la destra ( non posso prendere 4 prima di 0 (essendo 4 > 0 violererbbe la policy) -> devo raccogliere prima 0 a 4  )

# 14/05/2024

Prevenzione : 
+ raccolta atomica 
+ allocazione gerarchica ( può dare starvation  )

Controllo -> qulcuno controlla il mio programma e evita lo stallo da solo ( SO , VM , runtime )

C'è dell'overhead -> generalemente non c'è per questo

grafo di assegnazione delle risorse per controllare come le risorse vengono assegnate 
Archi
quali risorse a quali processi 
che processi dipendono da che risorse
quali risorse potrebbero essere richieste 

Nodi
Processi = tondi
Risorse = quadrati -> 1 o più istanze 

da un'istanza di R a un P -> ha quell'istanza
P verso R vuole quella risorsa
P tratteffio R -> P potrebbe volere un'istanza di R (assunzione forte che sappiamo che risorse ho bisogno, in contesti realtime si fa il prefetch)

>[!example] 
>R1 -> P2
>P1 -> R1 attesa di R1 che è in P2
>R2 -> P1
>P3 -> R2 attesa di R2 che è in P1
>Non c'è stallo perchè P2 quando ha finito sblocca il tutto

>[!example] 
>![[Pasted image 20240514124535.png]]
>
>Stalla se si P2 richiede R2 
Se arrivo ad un asituazione in cui le frecce trattegiate indicano stallo è già troppo tardi 
>
>C'è ciclo ma non stallo 


Con la seguente sequenza i processi possono uscire dalle attese : $<P2,P1,P3>$ , sequenza *sicura* ossia ordine di uscita dei processi tale pre cui usciamo da tutte le attese 

Dato un grafo di assegnazione come si fa a decidere se c'è uno stallo ? 
2 casi : 
+ una sola istanza per risorsa

Lo stallo è equivalente al fatto che sia presente un ciclo nel grafo

+ più istanze per risorse

Se c'è uno stallo c'è per forza un ciclo ma non è vero che se c'è un ciclo c'è per forza uno stallo ( potrebbe esserci un'altra istanza libera )

Se non esiste una sequenza sicura c'è uno stallo 

**Algoritmo**

Algoritmo del banchiere ( caso generale )

Fa dei presetiti solo se è sicuro che gli ritornano i soldi 

+ P richiede una istanza di R 
	+ Se R non è disponibile P andrà in attesa ( mutua esclusione )
	+ Se R è disponibile simulo l'assegnamento della risorsa sul grafo
		+ Se sul grafo individuo uno stallo , in cui considero anche le richieste future , mette P in attesa , altrimenti assegno la risorsa 

![[Stall.excalidraw]]

>[!example] Filosofi

Individuo la sequenza sicura -> 

Cerco se c'è un processo che può ottenere tutte le risorse necessarie incluse quelle future 
Se non c'è vuol dire che non c'è una sequenza sicura
Se lo trovo aggiunge P alla sequenza sicura e rilascio le sue risorse e cerco il sucessivo 
Se terminano tutti allora ritorna la sequenza sicura 

Se non riesco ad ottenere una sequenza sicura c'è uno stallo 

>[!example] 
>+ aggiungi P3 richiede R1 alla fine 
>  
>  Se tutti richiedono tutto non ci sono abbastanza risorse per soddisfare tutti

Compiti vecchi , stessi esercizi ma a risposta multipla 

