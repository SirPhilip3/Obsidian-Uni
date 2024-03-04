# Comunicazione tra processi

I processi all'interno di un sistema operativo sono sempre in competizione per l'*utilizzo delle risorse*difatto la *gestione delle risorse* è il compito principale del sistema operativo 

Se non vengono gestite correttamente si potrebbe provocare : 
+ **Starvation** : 
	Un processo è bloccato indefinitivamente a causa di altri processi che monopolizzano le risorse 
>[!example]
>fork-bomb
```c
int main(){
	while(1)
		if(fork()<0)
			perror("errore fork");
}
```
+ **I/O** :
	Diminuzione delle prestazioni a causa dell'accesso di una perifericha di input/output da parte di più processi

Il sistema operativo deve *gestire la competizione* ( *race condition* ) per le risorse comuni in modo da ridurre le interferenze e per garantire la correttezza 

>[!example]
>+ Le stampe su una stampante devono essere accodate e non "mischiate"
>+ L'accesso al disco deve garantire che diversi processi non scrivano inavvertitamente sullo stesso blocco
>+ Garantire l'equietà per la distribuzione del tempo di CPU ai processi

Il sistema operativo *virtualizza* l'hardware in modo da dare l'impressione ad ogni processo di avere l'intera macchina a disposizione , i processi non si accorgono di altri processi in esecuzione contemporaneamente ( possiamo vedere solo se la nostra esecuzione è rallentata ma non conosciamo cosa causa questo rallentamento )

## Cooperazione tra Processi 

I processi vorrebbero comunicare nei seguenti casi : 
+ **Condivisione** : 
	Quando si vuole condividere delle informazioni ( es google docs ) 
+ **Prestazioni** :
	Potremmo utilizzare calcolo parallelo in architetture multi-core per ottimizzare le prestazioni di certi programmi
+ **Modularità** : 
	Il programma viene suddiviso in vari sottoprocessi con differenti compiti più semplici
+ **Multitasking** :
	Svolgimento di compiti differenti contemporaneamente ( esempio voglio stampare un documento e modificarlo mentre viene stampato )
+ **Replicazione** :
	Quando si necessita dell'esecuzione simultanea di diverse istanze dello stesso processo il processo viene replicato su più processi o thread ( un server si replica per servire diversi utenti )

## Modelli di comunicazione tra processi

Vi sono due modelli principapli di comunicazione tra processi : 
+ **Message passing**
	I *processi* o *thread* si scambiano informazioni tramite messaggi ( di riderimento per la comunicazione tra messaggi )
	![[Pasted image 20240216165331.png]]
+ **Shared memory** 
	I *processi* o *thread* condividono dati in memoria e accedono in lettura e scrittura ai dati condivisi ( modello di riferimento per i *thread* in quanto questi condividono la memoria del processo )
	![[Pasted image 20240216165529.png]]

### Message passing

I processi dispongono di funzioni che gli permettono di comunicare tra di loro : 
+ `{c} send(m)`
	Invia il messaggio `m`
+ `{c} recieve(&m)`
	Riceve un messaggio e lo salva in `&m`

Queste due funzioni primitive vengono realizzate attraverso chianate di sistema ( *System Call* ) dette *InnerProcess Communication* ( **IPC** )

Il mittente e destinatario possono essere comunicati *direttamente* o *indirettamente*
#### Nominazione Diretta

Il *mittente* e *destinatario* sono nominati esplicitamente nelle funzioni primitive
+ `{c}send(P,m)` 
	Invia il messagio `m` a `P`
+ `{c}recieve(Q,&m)`
	Riceve un messaggio da `Q` e lo salva in `m`

Necessitiamo di conoscere la reciproca identità , esiste una variante in cui si riceve da qualsiasi utente
+ `{c}recieve(&Q,&m)`
	Questo riceve un messaggio `m` da un qualsiasi utente

**Vantaggi** :
+ La nominazione diretta è molto semplice e permette la comunicazione diretta tra coppie di processi 

**Svantaggi**  : 
	Necessitiamo un accordo sui nomi dei processi
	Il *PID* ( *Process ID* ) non è adatto poichè questo viene allocato dinamicamente ai processi e non possiamo prevederne il valore 
	Per questo l'implementazione risulta essere complicata a meno che i processi non siano in relazione stretta di parentela genitore-figlio , in questo caso il genitore conosce i *PID* dei figli  
#### Nominazione Indiretta

Per ovviare ai difetti della nominazione diretta si utilizza una nominazione basata su **Porte** ( **mailbox** ) , queste vengono gestite dal sistema operativo che permettono la loro creazione e distruzione

+ `{c}send(A,m)` 
	Invia il messaggio `m` sulla *porta* `A`
+ `{c}recieve(A,&m)`
	Riceve un messaggio dalla *porta* `A` e lo salva in `m`

In questo modo non necessitiamo di conoscere il nome dei processi ma solo quello della *porta*

![[Pasted image 20240216173416.png]]

>[!note]
>Cosa accade quando due processi cercano di inviare/ricevere messaggi verso/dalla stessa *porta* ?
>Il sistema operativo si occuperà di gestire la competizione ( *race condition* ) 
>Spesso si associa una *porta* ad un *processo* ( creatore e possesore della porta ) che è l'unico a leggere dalla porta evitando così la *competizione* in ricezione , per evitare la competizione in arrivo basterà accodarli in modo lineare sulla *porta*

>[!note]
>In Unix le *pipe* implementano un meccanismo di scambio di messaggi a nominazione indiretta
#### Comunizazione sincrona e asincrona 

L'invio e ricezione dei messaggi può essere *sincroni* o *asincroni* , vediamo le varie combinazioni

+ *send sincrona* :
	Un messaggio viene inviato solo quando la corrispondente `recieve` viene eseguita 
	La `send` è bloccante finquando il messaggio non viene ricevuto
+ *send asincrona* :
	Il messaggio viene inviato indipendentemente dalla `recieve` , si utilizza un `buffer` ( una *coda* ) in cui depositare temporaneamente il messaggio  
+ *recieve sincrona* :
	Il messaggio viene ricevuto solo se presente , la `recieve` è bloccante finchè non c'è un messaggio da leggere 
+ *recieve asincrona* :
	La `recieve` ritorna un messaggio se presente o NULL se non ci sono messaggi da ricevere 

>[!example]
>*Produttore-consumatore*
>La comunicazione a scambio di messaggi è molto adatta nelle situazione in cui un processo *produce* un dato e un altro lo *consuma*
>UNIX inoltre utilizza nominazione indiretta con send asincrona e recieve sincrona

# Creazione di processi 

La creazione di un processo richiede alcune operazioni da parte del sistema operativo : 
+ Creazione di un nuovo ID ( *PID* - *Process Identifier* )
+ Allocazione di Memoria ( per il codice e i dati )
+ Allocazione di altre risorse ( stdin , stdout , dispositivi di I/O )
+ Gestione delle informazioni sul nuovo processo ( es. la priorità )
+ Creazione del *PCB* ( *Processo Control Block* ) contenente le informazioni del processo
## Processi in UNIX

Un processo è sempre creato da un'altro processo tramite una chiamata di sistema ( `{c}fork` ) 
Fa eccezione il processo `init` ( $pid=1$ ) che viene creato al momento del boot ( non ha un padre)

Il processo creante è detto *parent* mentre il processo creato *child* , questo crea una struttura di parentela ad albero :

![[ParentelaProcessiUNIX.excalidraw]]
### Relazioni Dinamiche

Dopo la creazione di un nuovo processo il genitore *attende* l'esecuzione del figlio

>[!example]
>`{bash}sleep 5` 
>L'esecuzione di `{bash}sleep` all'interno di una shell questa sarà il suo genitore e quindi dovremmo attenddere 5 secondi per continuare ad utilizzare la shell

>[!note]
>`ctrl+c` termina il processo in esecuzione ( metodo standard ) oppure il comando viene gestito dal programma

Il processo genitore potrebbe continuare l'esecuzione mandando il processo figlio ad eseguire in background 

>[!example]
>`{bash}sleep 5 &`
>`{bash}&` indica che il processo deve essere messo in esecuzione in background 

In questo caso i due processi sono in esecuzione in modo concorrente ( o per *time-sharing* in single core o su più core in un CPU multicore )

Il processo che termina verrà comunicato solo se interagiamo con la shell : 
```bash
-> sleep 5 &
[1] 234                       // -> indica il pid del processo in background 
-> ps                         // -> ci fa vedere i processi in esecuzione
PID TTY          TIME CMD
14695 pts/1    00:00:00 bash
17589 pts/1    00:00:00 sleep
17590 pts/1    00:00:00 ps
-> ls
[1]+ done      sleep 5        // -> indica il comando che è terminato
```

>[!note]
>`{bash}ps`
>Indica di default solo i processi associati al terminale da cui viene lanciato
>`{bash}-o` indica chè output vogliamo
>>[!example]
>>se vogliamo osservare il *pid* o *ppid* ( *Parent Process Identifier* ) utilizzeremo il comando
>>`{bash} ps -o pid,ppid`
>>Questo ci farà osservare che la shell sarà padre sia di `{bash}ps` che di `{bash}sleep`

Potrebbe essere utile che un processo si dissocia dal suo genitore , ad esempio i processi *Daemon* sono processi che devono rimanere attivi fino allo shutdown del sistema , necessitano quindi dissociarsi dalla shell per non essere terminati alla chisura del terminale

>[!note]
>Possiamo utilizzare `ctrl+Z` per sospendere il processo in *foreground* e sucessivamente utilizzare `{bash}bg` per rimandarlo in esecuzione in *background* , `{bash}fg` per riprendere l'esecuzione in *foreground*
### Relazione di contenuto

Ci sono due possibilità :
+ Il figlio è un duplicato del genitore ( in UNIX )
+ Il figlio esegue un programma differente ( in Windows )
### Fork

La chiamate a sistema `fork` permette di creare un processo duplicato del processo genitore 

>[!note]
>`fork` appartiene allo standard *POSIX* ( *Portable Operating System Interface* ) di *IEEE* ( *Institute of Eletrical and Elctronics Engineers* ) sraà quindi utilizzabile in tutti i sistemi che supportano *POSIX* 

La chiamata `fork` crea un nuovo processo che :
+ condivide l'area codice del processo genitore ( essendo immutable , read-only )
+ Utilizza una *copia* dell'area dati del processo genitore ( potrebbero essere modificati dal processo se non facessimo una copia potrebbe portare ad infonsistenze )

Per sapere che abbiamo creato un processo figlio basta osservare il valore dato in ritorno dalla chiamata `fork` :
+ se il valore è $0$ allora so di essere il processo figlio
+ se il valore è $>0$ allora sappiamo che siamo il padre poichè il valore di ritorno sarà il *pid* del figlio

>[!note]
>Il padre di un figlio non ha alcun modo per sapere il *pid* del figlio se non al momento della creazione attraverso il valore ritornato dalla `fork`

![[Pasted image 20240221181800.png]]

Lo schema di base per l'utilizzo di una `fork` è il seguente : 
```c
pid_t pid = fork(); // pid del figlio
if ( pid < 0 )
	perror("fork error");
else if ( pid == 0 ){
	// codice del figlio
} else {
	// codice del genitore
	//^ codici eseguiti contemporanemente
}
// codice svolto sia dal genitore che il figlio
```

>[!example]
>Esempio concreto
```c
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  pid_t pid;
  
  printf("Prima della fork. pid = %d, pid del genitore = %d\n",getpid(), getppid());
  
  pid = fork();
  if ( pid < 0 )
    perror("fork error"); // stampa la descrizione dell'errore
  else if (pid == 0) { 
    // figlio
    printf("[Figlio] pid = %d, pid del genitore = %d\n",getpid(), getppid());
  } else { 
    // genitore
    printf("[Genitore] pid = %d, pid del mio genitore = %d\n",getpid(), getppid());
    printf("[Genitore] Mio figlio ha pid = %d\n",pid);
    sleep(1); // attende 1 secondo
  }
  // entrambi i processi
  printf("PID %d termina.\n", getpid());
}
```
>[!example] .
>Questo dà il seguente output : 
```bash
$ ./fork
 Prima della fork. pid = 25267, pid del genitore = 329
 [Genitore] pid = 25267, pid del mio genitore = 329
 [Genitore] Mio figlio ha pid = 25268
 [Figlio] pid = 25268, pid del genitore = 25267
 PID 25268 termina.
 PID 25267 termina.
$
```

>[!note]
>`{c}pid_t` è un signed integer in molti sistemi ma potrebbe essere un altro tipo in altri sistemi

>[!note]
>`{c}getpid` è una funzione per ricevere il proprio *pid*
>`{c}getppid` è una funzione per ricavare il *pid* del padre ( ossia il *ppid* )

>[!warning]
>La `fork` può fallire , in questo caso ritorna un numero negativo
>Fallisce quando finiscono le risorse , questo è molto pericoloso per il sistema operativo perchè potrebbe significare che non ci sono risorse nemmeno per il sistema operativo stesso 
>Per questo esistono dei limiti ( `{bash}ulimit` , `{bash}cgroups` ) di processi in esecuzione in modo da mantenere sempre delle risorse minimi per il sistema operativo
>>[!example]
>>Questo potrebbe causare un fallimento ( fork-bomb )
```c
int main() {
	while(1)
		if (frok() < 0)
			perror("errore fork") // il numero di processi è esponenziale poichè ogni processo crea altri processi
}
```

Cosa succede alla terminazione di un processo figlio o padre ? : 

+ Se il genitore termina prima del figlio , i figli diventano processi **orfani** 
+ Se il figlio termina prima del genitore questo dovrebbe accorgersi della sua terminazione e raccogliere le informazioni del suo *PCB* ( *Process Control Block* ) , se questo non viene svolto dal processo genitore si dice che il processo figlio è un processo **zombie** ( questi vengono segnati come `<defunct>` se facciamo un `{bash}ps` )

I processi *orfani* vengono "adottati" dal processo `init` che ciclicamente raccoglie le loro informazioni e libera la memoria 
Se il genitore di un processo *zombie* termina questo diventa *zombie orfano* che viengono anch'essi "adottati" dal processo `init`

>[!example]
>>[!todo]
#### Esempi

Visto che non possiamo fare alcuna assunzione sullo scheduler che utilizza il sistema non possiamo nemmeno fare alcuna assunzione sul modo in cui due processi vengono eseguiti in modo parallelo : 

Per visualizzare come i processi si alternano nell'esecuzione possiamo scrivere il seguente programma : 

```c
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  pid_t pid;
  int i;
  
  pid = fork();
  if ( pid < 0 )
    perror("fork error"); // stampa la descrizione dell'errore
  else if (pid == 0) { 
    while(1) {
      for (i=0;i<10000;i++) {} // riduce il numero di printf
      printf("Figlio: pid = %d, pid del genitore = %d\n",getpid(), getppid());
    }
  } else { 
    while(1) {
      for (i=0;i<10000;i++) {} // riduce il numero di printf
      printf("genitore: pid = %d, pid di mio genitore = %d\n",getpid(), getppid());
    }
  }
}
```

Se eseguiamo questo codice in un sistema *multicore* questi verrano eseguiti in modo parallelo su due core differenti , per questo gli output saranno alternati ( a meno di buffering dell'output ) 
Mentre se il sistema è *single-core* i due processi vengono eseguiti in time-sharing portando ad un output suddiviso in blocchi di esecuzione dei due processi  

>[!todo]

### Exec

Per eseguire un programma differente da quello che ha effettuato la `frok` si utilizzala chiamata di sistema `exec`

Questa chiamata **sostituisce** *codice* e *dati* di un processo con quelli di un programma differente

![[Pasted image 20240222165718.png]]

#### Copy-on-Write

Da notare come la `exec` "butta via" la copia dei dati creata dalla `fork` , questo è chiaramente *inefficente* soprattutto quando l'`exec` viene eseguita subito dopo una `fork`

Per rendere questa operazione più efficente viene copiata inizialmente dalla `fork` solo la *page-table* e le pagine contententi i dati sono etichettate come *read-only*
Quando si tenta di scrivere queste pagine genrea un errore che verrà gestito dal kernel :
+ Copia al volo la pagina fisica e aggiorna la *page-table* in modo da farla puntare alla nuova copia
+ Imposta le pagine a *read-write* in quanto da ora in poi le due copie sono indipendenti 

>[!note] 
>Se si esegue la `fork` e subito `exec` non avviene nessuna scrittura e quindi nessuna pagina viene effettivamente copiata ( avviene solo quando facciamo una scrittura )

#### Sintassi

L'`exec` ha diverse varianti che si differiscono in base al : 
+ formato degli argomenti ( lista o array `argv[]` )
+ utilizzo o meno del path della shell 

```c
execl("/full/shell/path/command", arg0, arg1, ..., NULL) 
execlp("command", arg0, arg1, ..., NULL)
execv("/full/shell/path/command", argv[])
execvp("command", argv[])
```

>[!note] 
>La presenza della `p` alla fine del nome della `exec` indica che viene utilizzato il path della shell ( non necessitiamo di scrivere l'intero path ) 

>[!note]
>Le prime due varianti prendono in input un lista di argomenti terminata da `NULL` ( il primo argomento contiene il nome del file associato al programma da eseguire ) , mentre le altre due prendono i parametri sotto froma di un array di stringe

#### Valore di ritorno

L'`exec` ritorna solamente in caso di errore ( valore $-1$ ) , in caso di successo il vecchio codice è completamente sostituito dal nuovo e non è più possibile tornare al programma originale

```c
#include <stdio.h>
#include <unistd.h>
int main() {
    printf("provo a eseguire ls\n");

    execl("/bin/ls","/bin/ls","-l",NULL);
    // oppure : execlp("ls","ls","-l",NULL);

    printf("non scrivo questo! \n");
    // questa printf non viene eseguita se la exec va a buon fine
}
```
Darà in output :
```bash
provo a eseguire ls
total 16
-rwxr-xr-x 1 focardi focardi 6619 2008-03-05 17:02 a.out
-rw-r--r-- 1 focardi focardi  226 2008-03-05 17:02 exec1.c
-rw-r--r-- 1 focardi focardi  225 2008-03-05 17:02 exec1.c
```

Se invece runniamo il seguente comando : 
```c
execlp("ls2","ls2","-l",NULL);
```
Riitorneremo un errore in quanto `{bash}ls2` non è un comando riconosciuto , in questo caso infatti il risultato sarà : 
```bash
provo a eseguire ls
non scrivo questo!
```
Poichè la `exec` è andato in errore

>[!note]
>Risulta essere buona norma in *c* testare i codici di errore di chiamate a libreria o a sistema 
```c
if (execlp("ls2","ls2","-l",NULL) == -1) {
      perror("errore durante la exec");
      // eventualmente si esce: exit(EXIT_FAILURE);
}
```
Questo stamperà l'errore che è stato ritornato ( presente nel *PCB* ) :
```c
provo a eseguire ls
errore durante la exec: No such file or directory
non scrivo questo!
```

>[!warning]
>Qualora si verificassero errori all'interno del programma invocato l'`exec` *non fallisce* , quindi non ritorna e non esegue nessuna istruzione del programma che l'ha invocata
```c
if (execlp("ls","ls","-z",NULL) == -1) {
      perror("errore durante la exec");
      // eventualmente si esce: exit(EXIT_FAILURE);
}
```
Avremo il seguente output :
```bash
provo a eseguire ls
ls: invalid option -- z
Try `ls --help' for more information.
```

#### Example : shell

>[!todo]
>#todo
### Terminazione di un processo

La terminazione di un processo rilascia le risorse allocate dal *SO* al momento della creazione ( memoria e file aperti ) e *segnala* la terminazione al genitore : alcune informazioni di stato ( *PCB* ) vengono messe a disposizione al processo genitore e rimangono memorizzate finchè non sono processate 

Il *SO* mantiene almeno : 
+ *pid*
+ lo stato di terminazione
+ il tempo di CPU utilizzato dal processo 

Esistono 2 chiamate a sistema pertinenti alla terminazione di un processo : 
+ `exit` : termina il processo 
+ `wait` : attende la terminazione di un figlio ( se uno dei figli è uno *zombie* ritorna subito senza bloccarsi )

>[!note]
>Un processo può anche terminare in modo anomalo a causa di un errore o perchè terminato dal *SO* o da altri processi
#### Sintassi

+ `{c}exit(int stato)` : termina il processo ritornando lo `stato` al genitore ( gli stati possono essere `EXIT_FAILURE` e `EXIT_SUCCESS` reciprocamente uguali ad 1 e 0 )
+ `{c}pid = wait(int &stato)` : ritorna il `pid` e lo `stato` del figlio che ha terminato 
	Si utilizza `{c}wait(NULL)` se non interessa lo stato
	Se non ci sono figli ritorna $-1$

#### Valore di ritorno della wait

Lo stato ritornato dalla `wait` deve essere gestito con opportune macro : 

+ `{c}WIFEXITED(status) == true` se il figlio è uscito correttamente con una `exit`
	`{c}WEXITSTATUS(status)` ritorna gli 8 bit di stato passati dalla `exit` 
	Esempio : 
```c
if (WIFEXITED(status))
    printf("OK: status = %d\n",WEXITSTATUS(status));
```

+ `{c}WIFSIGNALED(status)==true` se il figlio è stato terminato in modo anomalo
	`{c}WTERMSIG(status)` ritorna il *segnale* che ha causato la terminazione 
	Esempio : 
```c
if (WIFSIGNALED(status))
    printf("ANOMALO: status = %d\n",WTERMSIG(status));
```

+ Esistono ulteriori macro per lo *stop* e *resume* , utili per il tracing dei processi ( `{c}WIFSTOPPED` , `{c}WSTOPSIG` , `{c}WIFCONTINUED`)

##### Wait per un processo particolare

Se si vuole attendere un processo particolare ( o precessi appartententi a un gruppo particolare ) si può utilizzare la chiamata a sistema : 
```c
pid = waitpid(pid2, &stato, options) 
```

Questo attende il processo `pid2` ( valori $\le 0$ permettono di attendere gruppi di processi ) 
Se `{c}pid2 == -1` attende un qualsiasi figlio , risulta uguale alla `wait`

### Segnali

I **Segnali** sono una forma minima di comunicazione tra processi ( tecnicamente sono *interruzioni* causate da svariati eventi ) 
>[!example]
>+ `ctrl-c` ( `SIGINT` ) viene generato da terminale e viene utilizzato per terminare l'esecuzione di un programma in esecuzione all'interno di una shell
>+ Eccezioni ( divisioni per 0 , *segmentation fault* ( riferimento ad area di memoria non allocata ) ) 
>+ Segnali esplicitamente inviati da un processo all'altro 
>+ Eventi *asincroni* che vengono notificati ai processi : `SIGALARM` ( utilizzato per settare un timer e poi essere svegliato ) ( utilizzato nello scheduling , soprattutto nel modello time-sharing in cui lo scheduler mette in `exec` un processo e setta il `SIGALARM` per svegliarlo dopo l'intervallo di tempo assegnato a quel processo per metterlo in pausa e mandare in `exec` un'altro processo )

Cosa possiamo fare quando riceviamo un segnale : 
+ Ignorarlo
+ Gestirlo
+ Lasciare questo compito al gestore del sistema operativo

Alcuni segnali *POSIX* ( *Portable Operating System Interface* ) supportati su Linux :
Ecco il risultato dato da `man 7 signal`

```bash
First the signals described in the original POSIX.1-1990 standard.

Signal     Value     Action   Comment
-----------------------------------------------------------------------
SIGHUP        1       Term    Hangup detected on controlling terminal
                              or death of controlling process
SIGINT        2       Term    Interrupt from keyboard     <== ctrl-C
SIGQUIT       3       Core    Quit from keyboard          <== ctrl-\
SIGILL        4       Core    Illegal Instruction
SIGABRT       6       Core    Abort signal from abort(3)
SIGFPE        8       Core    Floating point exception
SIGKILL       9       Term    Kill signal                 <== kill -9 (da shell)
SIGSEGV      11       Core    Invalid memory reference
SIGPIPE      13       Term    Broken pipe: write to pipe with no readers
SIGALRM      14       Term    Timer signal from alarm(2)
SIGTERM      15       Term    Termination signal          <== kill (da shell)
SIGUSR1   30,10,16    Term    User-defined signal 1
SIGUSR2   31,12,17    Term    User-defined signal 2
SIGCHLD   20,17,18    Ign     Child stopped or terminated <== gestito da wait()
SIGCONT   19,18,25    Cont    Continue if stopped
SIGSTOP   17,19,23    Stop    Stop process
SIGTSTP   18,20,24    Stop    Stop typed at tty
SIGTTIN   21,21,26    Stop    tty input for background process
SIGTTOU   22,22,27    Stop    tty output for background process

The  signals SIGKILL and SIGSTOP cannot be caught, blocked, or ignored.
```

Ecco alcuni segnali : 
+ `SIGHUP` : 
	Viene inviato a un processo quando il terminale a cui è associato viene chiuso 
+ `SIGINT` : 
	Viene inviato a un processo digitando `ctrl-C` per interromperlo
+ `SIGQUIT` :
	Viene inviato per far terminare un processo tramite `ctrl-\` ( fa anche il core-dump del processo ( ossia vengono salvati i dati ) )
+ `SIGILL` , `SIGABRT` , `SIGFPE` , `SIGSEGV` : 
	Corrispondono ad azioni del precesso stesso : 
>[!example] 
>+ Istruzione Illegale
>+ Invocazione di `abort`
>+ Errore aritmetico
>+ Riferimento a memoria illegale
+ `SIGKILL` , `SIGTERM` : 
	Sono segnali inviati da un processo ad un altro utilizzati per terminare un processo 
>[!example]
>Questi segnali possono essere inviati tramite shell grazie al comando `{bash}kill -9 pid` oppure `{bash} kill pid` 
>`SIGKILL` termina *sempre* un processo 
>`SIGTERM` può essere gestito o ignorato dal processo 
+ `SIGPIPE` : 
	Inviato ad un processo che prova a scrivere su una *pipe* che non ha lettori 
+ `SIGALRM` : 
	Un timer che "sveglia" un processo simile al timer usato dallo scheduler per implementare il time-sharing
+ `SIGCHLD` : 
	Viene inviato a un processo quando un suo processo figlio termina ( utilizzato per svegliare un processo che ha invocato la `wait` altrimente viene ignorato )

Comportamenti di **default** : 
+ `Term` : l'azione di *default* è quella di *terminare* il processo
+ `Ign`   : l'azione di *default* è quella di *ignorare* il segnale
+ `Core` : l'azione di *default* è quella di *terminare* il processo e *dump core* ( salvare stato del processo )
+ `Stop` : l'azione di *default* è quella di *fermare* il processo
+ `Cont` : l'azione di *default* è quella di *continuare* il processo se è al momento *fermato*

#### Esempio utilizzo di segnali : `alarm`

La chiamata di sistema `{c}alarm(n)` manda un `SIGALRM` dopo $n$ secondi .
Il default handler termina il programma
>[!note]
>La shell analizza lo stato di uscita del programma e stama il motivo della terminazione ( in questo caso stamperebbe "Alarm clock" )

>[!example]
```c
#include <unistd.h>
int main()
{
    alarm(3); 
    while(1){} 
}
```

La shell setta l'allarme tra 3 secondi , nel frattempo svolge il ciclo while e alla fine dei 3 secondi il processo termina visto che `alarm` ha come azione di *default* quello di terminare il processo

```bash
$ ./alarm
 <... dopo 3 secondi....> 
 Alarm clock
$
```

#### Impostare il gestore dei segnali tramite `signal`

Tramite la call di sistema `signal` è possibile cambiare il gestore dei segnali 
Questa prende come parametri un *segnale* e un *puntatore a funzione* che da quel momento diventerà il nuovo gestore del segnale

>[!example]
```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void alarmHandler()
{
    printf("questo me lo gestisco io!\n");
    alarm(3); // ri-setta il timer a 3 secondi
}

int main() { 
    signal(SIGALRM, alarmHandler);
    alarm(3);
    while(1){}
}
```

Dopo 3 secondi arriva il segnale `SIGALRM` , a questo punto avendo rimappato l'*handler* verrà chiamata la funzione `{c}alarmHandler()` che stampa `{c}"questo me lo gestico io!"` e reimposta l'allarme doppo 3 secondi . A questo punto la funzione ritorna al punto in cui il programma era stato interrotto ( ossia all'interno del ciclo `{c}while` ) , qui attenderemo che arrivi il sucessivo segnale che lancerà di nuovo `{c}alarmHandler()` etcc...

```bash
$ ./alarm
 <... Aspetto 3 secondi ...>
 questo me lo gestisco io!   <=== dopo 3 secondi
 questo me lo gestisco io!   <=== dopo 3 secondi
 questo me lo gestisco io!   <=== dopo 3 secondi
 .......
```

>[!note]
>`SIGALRM` , `SIGKILL` etcc sono *macro* di c e quindi potrebbero essere sostituiti da i loro valori numerici

##### Parametri particolari della `signal`

Possiamo passare alla `signal` le costanti `SIG_IGN` o `SIG_DFL` al posto della funzione handler per indicare rispettivamente : 
+ che il segnale va ignorato
+ che l'handler è quello di default di sistema

Il valore di ritorno di `signal` è :
+ `SIG_ERR` in caso di errore
+ l'handler precedente in caso di successo 

>[!note]
>L'implementazione di `signal` può essere differente da diversi sistemi `POSIX` 
>Per questo si utilizza `sigaction` per un'implementazione più consistente nelle varie versioni `UNIX` 
>>[!example]
>>La `signal` originale in `UNIX` fa il reset dell'handler a `SIG_DFL` ogni volta che viene ricevuto il segnale ( si può ottenere questo comportamento con il flag `--ansi` ) 

>[!example]
>Proteggersi da `ctrl-c`
```c
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
int main() {
    void (*old)(int);
        
    old = signal(SIGINT,SIG_IGN);
    printf("Sono protetto!\n");
    sleep(3);
        
    signal(SIGINT,old);
    printf("Non sono più protetto!\n");
    sleep(3);
}
```

>[!note]
>Salviamo il primo handler di ritorno , quando vogliamo ritornare all'hander originale è sufficente passare l'handler salvato a `signal` 

Se runniamo il programma per 3 secondi non potremmo effettuare `ctrl-c` , appena reimpostato il vecchio gestore invece `ctrl-c` funzionerà

```bash
$ ./ctrlc
 Sono protetto!
 <ctrl-c>
 <ctrl-c>
 <ctrl-c>        <==== nessun effetto
 Non sono più protetto!
 <ctrl-c>        <==== esce!
```
##### Sospensione e ripristino di processi tramite `kill`

La chiamata a sistema `kill` manda un segnale *qualsiasi* ad un processo.

>[!example]
>Utilizziamo la chiamata a sistema `kill` per sospendere , ripristinare e terminare un processo
```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
int main(){
        pid_t pid1,pid2;
        pid1 = fork();
        if ( pid1 < 0 ) {
                perror("errore fork"); exit(EXIT_FAILURE);
        } else if (pid1 == 0)
                while(1) { // primo figlio
                        printf("%d è vivo !\n",getpid());
                        sleep(1);
                        }
        pid2 = fork();
        if ( pid2 < 0 ) {
                perror("errore fork"); exit(EXIT_FAILURE);
        } else if (pid2 == 0)
                while(1) { // secondo figlio
                        printf("%d è vivo !\n",getpid());
                        sleep(1);
                        }
        // processo genitore
        sleep(2);
        kill(pid1,SIGSTOP); // sospende il primo figlio
        sleep(5);
        kill(pid1,SIGCONT); // risveglia il primo figlio
        sleep(2);
        kill(pid1,SIGINT); // termina il primo figlio
        kill(pid2,SIGINT); // termina il secondo figlio       
}
```

Quando eseguiamo il programma notiamo che il primo figlio viene sospeso per 5 secondi e che alla fine i processi figli sono terminati

```bash
$ ./kill
 6720 è vivo !
 6721 è vivo !
 6720 è vivo !
 6721 è vivo !
 6720 è vivo !
 6721 è vivo !    <==== sospende 6720
 6721 è vivo !
 6721 è vivo !
 6721 è vivo !
 6721 è vivo !
 6720 è vivo !    <==== risveglia 6720 6721 è vivo ! 6720 è vivo ! 6721 è  vivo ! >
```
#### Mascherare i segnali

A volte risulta utile bloccare temporaneamente la ricezione dei segnali per poi riattivarli , i segnali non sono ignorati ma solamente *posticipati*

>[!note]
>*POSIX* non specifica se più occorrenze dello stesso segnale debbano essere memorizzate oppure no 
>Tipicamente se più segnali uguali vengono generati , solamente uno verrà recapitato quando il blocco viene tolto
>

La chiamata a sistema `{c}sigprocmask(int action, sigset_t *newmask, sigset_t *oldmask)`
compie azioni differenti a seconda del valore del parametro `action` : 
+ `SIG_BLOCK` : l'insieme dei segnali `newmask` viene *unito* all'insieme dei segnali attualmente bloccati che sono restituiti in `oldmask`
+ `SIG_UNBLOCK` : l'insieme dei segnali `newmask` viene *sottratto* all'insieme dei segnali attualmente bloccati che sono restituiti in `oldmask`
+ `SIG_SETMASK` : l'insieme dei segnali `newmask` *sostituisce* quello dei segnali attualmente bloccati ( `oldmask` )

Per gestire gli insiemi di segnali ( che sono rappresentati dal tipo `sigset_t` ) si utilizzano le seguenti chiamate di sistema : 
+ `{c}sigemptyset(sigset_t *set)` : Inizializza l'insieme `set` all'insieme vuoto
+ `{c}sigaddset(sigset_t *set, int signum)` : Aggiunge il segnale `signum` all'insieme set 

>[!example] 
>Esempio di come bloccare `SIGINT` e poi ripristinarlo
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
        if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0) {
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

Se digito `ctrl-c` mentre il segnale è mascherato questo viene sospeso , appena la maschera viene rimossa il segnale è ricevuto dal processo che viene interrotto ( è diverso da quello che abbiamo fatto in precedenza poichè ora non modifichiamo il gestore del segnale )

```bash
$ a.out
 Sono protetto!
 <ctrl-c>
 <ctrl-c>
 <ctrl-c>        <==== per 3 secondi nessun effetto
				 <==== esce appena la maschera viene tolta (senza dare  ulteriori ctrl-c)!
```

>[!note]
>Tramite la chiamata a sistema `sigpending` è possibile ottenere l'insieme dei segnali "pendenti" ( ossia quei segnali non ancora inviati al processo , quelli mascherati )

>[!note]
>`{c}sigprocmask`  non aderisce allo standard *ANSI* ( *ISO C99* ) ma solamente allo standard *POSIX* , la gestione dei segnali da parte di *ANSI-C* è si riduce quindi a `signal` , `raise(sig)` ( equivalente di `kill(getpid(),sig)` ) e `abort()`
>*ANSI-C* non prevede quindi multi-processing e non prevede l'invio di segnali ad altri processi
#### Attendere un segnale tramite `pause`

Per attendere un segnale , in precedenza abbiamo usato `{c}while(1){}` per attendere un segnale ( questo metodo viene detto *busy-waiting* ) ( consuma tempo di CPU ) , la system call `pause()` invece attende il segnale senza consumare tempo di CPU

>[!example]
```c
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void alarmHandler()
{
    printf("questo me lo gestisco io!\n");
}

int main()
{
    signal(SIGALRM, alarmHandler);
    alarm(3);
    pause();
    printf("termino!\n");
}
```
#### Interferenze e funzioni 'safe' in *POSIX*

L'uso della `{c}printf` nell'handler dell'`alarm` è rischioso perchè usa strutture dati condivise da diversi processi , se anche il programma interrotto stava facendo operazioni di I/O i due potrebbero interferire 
>[!note]
>`printf` non è *safe*

La lista di funzioni *safe* che possono essere utilizzate all'interno di un *handler* possono essere 