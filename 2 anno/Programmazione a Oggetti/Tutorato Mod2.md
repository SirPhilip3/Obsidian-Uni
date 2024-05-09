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

Es7 del libro

`Es7 e = Es7.getInstance();` per accedere all'istanza , essendo statico -> nomeclasse.metodo
quando ho bisogno della board

```java
// non creo mai l'istanza 
int random = Es7.RandomSingleton.nextInt();
```

due collection != se diverso numero di el o elementi differenti stessa lunghezza 

---
comparaTo\<T>

comparato confronta il this con il parametro che passo -> implementa confronto a 3 vie 
0 se el sono uguali 
1 se A \> B tra i due parametri
-1 se A \< B \>

se collection A ha meno el di B ritorno -1

a1 > b1 return 1 
a1 < b1 > return -1

es 2 pg 11

# 08/05/2024

5/9/2024

trasformazione tra iteratori :

oggetto iterabile di tipo a con el di tipo a -> map per cui vogliamo ritornare un iteratore di tipo B -> conversione dentro l'iteratore -> f A -> B , ad ogni iterazione applichiamo f  e ritorniamo un el di tipo B *asincrona* -> ogni thread fa f , passando lambda `f.apply(A)` ritorniamo promessa che una volta fatta apply 

`() -> (f.apply(a))`

lambda non prende parametri e ritorna un el di tipo B (supplier) , iteratore di supplier di B  

asincrona -> non so quando la computazione eseguisce -> in iteratore normale lo fa sequenzialmente , per ogni el sequenzialmente f.apply(a) , se la metto in lambda e passo a thread non so quando effettivamente verrà effettuata 

```java

```

ad ogni iterazione voglio creare un nuovo thread passando f.apply() , ogni volta che istanzio future creo nuovo thread e passa apply restituendo un risultato

l'iteratore ad ogni iterazione ritorna una nuova future che starta il thread che computa la funzione di trasformazione che ritorna un valore 

iterable di liste -> ha iteratore ,ad ogni iterazione dobbiamo ordinare ogni lista 
T deve essere comparabile altrimenti non posso ordinare

# 09/05/2024

template -> su qualsiasi entità 

template non solo tipi ma anche valori , 
classi , metodi , typedef ( nome alternativo a tipi vecchi )

namespace non templetizzabili

```cpp
// copy con un template diverso 
template <class S>
matrix(const matrix<S>& m)

// matrix int , matrix double -> passi a int il double -> invoca costruttore
// copy transformer
```

operatori bianri o dentro una classe con this + destro o globali con due parametri 

per permettere programmazione polimorfa devo avere typedef dentro a

iteratori si comportano come pointer ma non lo sono 

subscript

typename -> nome di un tipo che occorrono dei member type , per scpecificare che :: indica un nome di tipo , problema di parsing 