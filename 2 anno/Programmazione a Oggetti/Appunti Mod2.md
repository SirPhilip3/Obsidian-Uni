# 13/02/2024

imperativi -> con assegnamento
funzionali -> senza assegnamento ( only ricorsione ) 

```java
public class main {

	public static int f(int n){ // metodo statico , funzione , non ha bisongo di un istanza di un oggetto
		return n+1;
	}
	// metodo non statico ha bisogno di un oggetto 
	// main static altrimenti avrebbe bisogno di un oggetto istanziato

	public int g(int n){
		return n+1;
	}
}
```

```java
Main o;
int k = o.g(4);
// runtime error , tipi corrispondono
// a runtime o non è istanziato in memoria
```

primitivi call by value altri by reference

linguaggio ad oggetti se offre il subtyping -> 

*Polimorfismo* 
sottotipi stanno in supertipi
dinamic dispatching -> 

subsunmption conosci cosa precisa ma la dai per generale
	nei binding ( costruisco dog metto dentro animal )
	in passaggio di argomento
	assegnamento

# 15/02/2024

```java
Animal pluto = new Dog(); // subsumption
```

library managment 

java standard library 

array statici in java ( nativi ) 
vector array dinamici 
arraylist 

*jdk* ( *java development kit* ) [jdk](https://docs.oracle.com/en/java/javase/17/docs/api)

**Iterable** 

```java

```

estendere o implementare sono la stessa cosa , entrambi creano un nuvo sottotipo , posso fare subsumption in entrambi i casi

```java
interface I{

// ....

}

class K interface I{

// ....

}

// K è sottotipo di I , posso fare subsumptio

```


```java

public interface I {



}

public static abstract class K {

// solo metodi astratti 

} 

// classe stessa cosa della interface
// differenze 
// classe può essere ereditata solo da 1 altra classe 
// 

```

```java
public interface I {

	void a();
	void b();
	default void c(){
		a();
		b();
	} 

}

public static abstract class K {

	public abstract void a();
	public abstract void b();

	public void c(){
		a();
		b();
	}

} 

// classe stessa cosa della interface
```

in iterable metodo iterator deve essere implementato ( non default )

**Iterator\<E>**

iterable garantisce che sono strutture dati itereabili , collection aggiunge add ,contains etcc + Iterator() ereditato da iterable 
Iterator 

*List* -> aggiunge a collection dei metodi ( interfaccia ) , ci sono altri metodi per costrutire liste ( arraylist , circolari , queue , stack ) , insieme di elementi legati tra loro 
una struttura dati linerare a cui puoi accedere dato un indice ( array , list )

collection rappresenta strutture dati che non posso accedere tramite indice ( set ) , posso solo scorrere + pushback in coda

```java
ArrayList<Integer> A = new ArrayList<Integer>(); // no subsumptio
// costruttore di default quello che non viene implementato , 
// costruttore vuoto quello senza parametri implementato ( crea arraylist vuoto )
A.add(23); // per arraylist in coda
A.add(2); 
```

add ereditato da collection

```java
Collection<Integer> A = new ArrayList<Integer>(); // subsumption
A.add(23); // add è aggiunta da Collection poi a reuntime runna il metodo di Arraylist 
A.add(2); 
```


```java
List<Integer> A = new ArrayList<Integer>(); // subsumption
A.add(23); // add è aggiunta da Collection poi a reuntime runna il metodo di Arraylist 
A.add(2);
A.set(2,45); // ritrona elemento che c'era prima di quello che setterò
```

List rende la collection indicizzabile , accessibile in lettura e scrittura

```java
for(int i=0; i<A.size(); i++){
	A.get(i);
}
```
Spreco di tempo faccio get troppe volte 

```java
Ierator<Integer> it = A.iterator() // poichè è stato ereditato da iterable
// iterator punta all'inizio della lista
while (it.hasNext()){
	int n = it.next(); // ritorna l'elemento in cui ti trovi + si sposta la porssimo
	// hasNext fallisce quando va fuori dalla list
}
```

utilizzo for each ( utilizza iterator ) 
```java

```

# 20/02/2024

package 

iterable deve fornire l'iteratore almeno
ogni file una sola entità ( se volessi solo nested nessuna relazione con classe al cui è all'interno )
se interfaccia dentro interfaccia dovrei riferirmi `{java}Iterable.Iterator` meglio creare una nuova interface

differenza type parameter e type argument : 

```java
void f(int n) // n parametro type parameter

f(7) // 7 è un argomento type argument
// n non esiste nello scope del chiamante
```

```java
public interface Iterable<T>{ // è un parametro , analogo a n 
	// all'interno dello scope posso utilizzare T , argument quando faccio new
}
```

strutture dati eterogenee (senza tipo) per fare get posso gettare solo object , non sai cos'è e non posso fare nulla e ti assumi il richio di castarlo potresti castarlo ad un tipo sbagliato 

compiler non ti obbliga a bindare un risultato

# 22/02/2024

