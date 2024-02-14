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