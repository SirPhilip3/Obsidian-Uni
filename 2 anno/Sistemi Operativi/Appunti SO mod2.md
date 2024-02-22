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