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

# 04/10/2023

Instanza oggetto with contructor

new in bytecode = malloc di c ( malloc sizeof figther ) niiziailizza tutto a 0

nello stack delle op i parametri e li assegna a campi

tutti i metodi all'interno di una classe , sempre invocati in un metodo

tutti metodi dentro una calsse ha un prametro implicito this

chiamare constructor da constructor

```java
Fighter(Weapon w1, Armor a1){

	this(0,100,w1,a1)//chiama 2° constructor

}

Fighter(int exp , int life, Weapon w1, Armor a1) {  
    this.exp = exp;
    this.life=life;
    this.weapon = w1;  
    this.armor = a1;  
}
```

modifiers :
caratterizzare la classe , campo o metodo che ci permettono di modificarli

3 classi

+ Accesso
	+ public
	+ private
	+ protected
+ Concurrency
	+ synchronized
	+ volatile
+ Others
	+ satic 
	+ final
	+ obstract


static
	non è per forza legato ad un oggetto
	definire un metodo / campo di una classe 

metodi static 
	appartiene alla classe nella sua interezza 
	in un metodo statico il puntatore a this non esiste
	non esistendo in pos 0 dello stack c'è primo 

```java

static{

	Fighter.id=0;

}

```

costruttore statico per inizializzare i campi statici della classe , eseguito la prima volta che viene usata quella classe / start

clinit per static constructors

final : classi , campi e metodi
ha effetto su ereditarietà

campo final = non può essere modificato , si inizializza solo all'interno di un constructor
es id non deve essere modificato

costante globale static e final

# 06/10/2023

modi per accedere a campo statico 
```java

this.( nome campo statico )

```

```jvmbytecode
aload0
aload 0
pop
getstatic
```

inutile load visto che svolge pop dopo

campi persistono in heap fino a che l'oggetto non viene deallocato 
minimizzazione dei campi presenti ( mem occupation )

naming conventions : [Conventions](https://www.oracle.com/java/technologies/javase/codeconventions-namingconventions.html) 

static types :

primitive ( *values* )
objects ( *refrence types* )

```java
x=5
Weapon w = new Weapon()
```

|campi|value|
|---|---|
|x|5|
|w|pointer ad oggetto che abbiamo creato|

pointer nascosti
non posso allocare un oggetto direttamente nello stack ma viene allocato solamente il pointer

pointer condivisi tra oggetti
```
Weapon w1 = new Weapon(324)
FIghter f1 = new Fighter(w1)
f1.weapon.damage = 1200
```

sia f1 che w1 diventano 1200 modifico values nel pointer 

code data structure 

## Aliasing 

stessa area di memoria 2 nomi differenti es :
w1.damage
f1.weapon.damage

## Packages

Raggruppamenti di classi che possono essere importate in altre .class
naming conventions :
url reverse
deve rispecchiare il precorso delle directory

* * importa tutte le classi del package , memory !

## Encapsulation

Information hiding ( througth access modifiers ) :

private : solo visibile dalla classe ( visibilità di package , visibile solo dal package corrente , non c'è una gerarchia di package , package più profondi non ereditano , rimangono distinti )
public : tutti possono vedere ( final = non modificabile ) 
protected

deprecated metodo not supported

public "per usi interni" : modules file di testo in cui dico che classi esporto

