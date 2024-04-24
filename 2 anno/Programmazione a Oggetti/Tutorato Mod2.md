# prec

# 17/04/2024

pag 16 -> in poi

ripasso thread

thread -> creazione oggetto thread , new thread  -> oggetto non corrisponde a thread sys , thread schedulabile .start() -> thread diventa runnable non è ancora schedulato 

thread -> acrive ->( quando faccio start )
active -> runnable(in coda ) o running(in esecuzione)

prima è in runnabel -> running alla fine del quanto -> runnable  
quando finisce esecuzione -> in waiting se deve attendere una risorsa altrimenti termina

quando prende un lock per quella risorsa -> va in stato active , lock essenzialmente è un monitor (syncronize)

in java -> 
2 modi per creare i thread -> estendo thread
creo nuvo threa con lambda

se chiamo run -> chiamo un metodo se lo chia

thread.currentThread -> restituisce l'oggetto di tipo thread che sta eseguendo quel codice in quel momento a questo punto posso chiamare getName di Thread

join -> mainthread aspetta fine del thread creato prima di continuare

thread possono terminare in modo inaspettato -> le join throwano errore

*consumer producer*

ex -> container di risorse che 

lincked blocking queue è thread safe -> 

# 24/04/2024

esercizi : pg 17 eserciziario
pattern di programmazione 

creare un'altra classe che riusa i metodi della classe random

*singleton* :  insieme con un solo elemento , voglio avere un unica istanza renderla accessibile in tutto il programma non faccio mai new ,
+ non voglio che sia istanizabile dall'esterno
+ metodo che la renda accessibile da fuori -> ritorna un pointer a quell'istanza 

deve essere partre della calsse stessa , es connesione database -> oggetto connessione accessibile da tutto il programma 

costruttore privato , se lo eredito override

metodo per istanziare l'istanza se non lo è ancora e ritorno il pointer all'oggetto 

`Es7 e = Es7.getInstance();` per accedere all'istanza , essendo statico -> nomeclasse.metodo
quando ho bisogno della board 

