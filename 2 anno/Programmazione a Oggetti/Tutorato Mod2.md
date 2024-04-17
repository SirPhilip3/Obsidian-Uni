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