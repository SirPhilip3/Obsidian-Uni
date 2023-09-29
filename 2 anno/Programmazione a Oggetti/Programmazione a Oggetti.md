# 22/09/2023

Integer.parseint(args()) parsing args da string ad int

.class

Object oriented

java bytecode in output , universal execution , jvm si occupa dell'execution , worst performance
""""senza pointers

bytecode intermedio tra assembly e ( high level ) java , grabage collector , garbage = area di memoria che non ha un pointer assegnato

garbage collector avviato anche quando out of memory , rallentamento 

- out of memory
- garbage collection timeout ( max time for gc )

javabytecode 
operand stack  , pila delle operazioni 

i davanti a bytcode = int

# 27/09/2023

[bytecode]([Java bytecode - Wikipedia](https://en.wikipedia.org/wiki/Java_bytecode))

```
if_icmpge 22
```

variabile speciale *this* in 0 di variabili locali : oggetto corrente

```
invokevirtual 
```
invocazione fun

var locali e operand stack per ogni fun

campo di una classe in heap
this.field = lettura valore di this
campo at compile time

```java
public class T{
	// campo
	int field; // in heap vale per tutti i metodi 
	

	int T{
		this.field++;
	}


}
```

bytecode  :
- laod / store local variables
- read / write heap locations
- invoke methods
- arithmetic op
- check conditions on values

metodi nativi mapping di funzioni in c in java 

puntato sul riutilizzo del codice 
-
classi campi e metodi

oggetto instanza di una classe con metodi etcc
rappresentazione di un'entità reale o astratta

funzionalità per evolvere l'oggetto
metodi modifiano i campi mantenendo consistenza logica

# 29/09/2023

encapsulamento dei metodi , non modifico i dati al di fuori della classe , espongo solo funzioni e nascondo i dati

struttura dati fissa durante l'execution 
ogni oggetto ha il prorpio life_cycle

ogni var locale che contiene un oggetto è un pointer a quell'oggetto se faccio 
	`fighter f3 = f1`

f3 prende stessi valori di f1 quando modificati *aliasing*

@ indica address accorciato 

metodi public / private
```java
class Runner{
// prima i campi e poi i metodi
	double speed;

	void refuel(){
	
	}

}
```

tutto il codice all'interno di una classe

ogni classe = nuovo tipo 

ciascuna classe in un file con nome del file = nome della calsse in realtà ci sono inner classes // not really

[naming conventions](https://www.oracle.com/java/technologies/javase/codeconventions-namingconventions.html)

Constructors

metodi sempre invocati su un oggetto

receiver = oggetto che viene modificato dal metodo chiamato

Contructor : 
stesso nome della classe
non ha un ritorno 

1 allocca memoria per un oggetto fighter 
2 invoca contructor

se non c'è un costruttore creazione del costruttore di default senza alcun parametro

se definisco un contructor non posso più cotruire un oggetto senza quel costruttore

posso definire più costruttori ( overloading )