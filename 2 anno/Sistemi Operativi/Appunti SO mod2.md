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