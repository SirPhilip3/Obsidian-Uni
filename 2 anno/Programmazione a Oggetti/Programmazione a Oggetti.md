# Introduzione

*Java* è un linguaggio orientato agli oggetti

Differenze tra diversi linguaggi :

|Java|Imperative Programming ( C / C++ )|
|---|---|
|Basato sul concetto di *oggetti* , ogni oggetto può contenere dati o codice , dati nella forma dei *campi* mentre codice nella forma di procedure o *metodi* , i metodi all'interno degli oggetti possono modificare i dati di se stesso , gli *oggetti* sono istanze di *classi* il che determina il loro tipo | Un programma imperativo utilizza istruzioni per cambiare lo stato del programma , programmazione imperativa consiste in comandi per il computer da svolgere ( si concentra nel come un programma deve funzionare ) |

*java* è garbage collected ( no more deletes )

*java* compilation workflow :
+ *.java* viengono compilati in *java bytecode*
+ Il *java bytecode* viene eseguito in una virtual machine ( *Java Runtime Enviroment* ( *JRE* ) )

Rende il codice *java* molto *portabile* ( basta avere il corretto JRE per quella macchina e il codice eseguirà )
#### Java bytecode

Il *java bytecode* è un linguaggi di basso livello indipendete dalla macchina ( è uguale per tutte le macchine ) che viene eseguito dalla *JRE*

L'esecuzione del *java bytecode* è costituito da :
+ [**Stack** of frames](https://www.jrebel.com/blog/java-bytecode-tutorial) ( uno per ogni metodo )
	è costituito da : 
	+ un insieme di *variabili locali* contenti dei valori ( es quelli passati ad una funzione ) , la sua dimensione è deteminata a compile time
	+ uno *stack degli operandi* ( è uno stack di tipo *LIFO* usato per pushare e poppare valori  , viene usato durante l'esecuzione del metodo )
+ Una memoria che contiene gli oggetti istanziati
##### Accenni di bytecode

Istruzioni sono caratterizzate dal tipo a cui si riferiscono , quindi una istruzione che somma due interi è diversa da una che somma due float : 
`iadd` : add tra 2 int ( indicato dall'*i* iniziale )
`fadd` : add tra 2 float ( indicato dall'*f* iniziale ) 

L'invocazione di funzione avviene attraverso il comando `invoke` che può differenziarsi in :
+ `invokevirtual` : calls a public method
+ `invokespecial` : calls the constructor of a class
+ `invokestatic` : calls a static method

Vi sono poi altri comandi per :
+ load e store di variabili locali
+ scrittura o lettura di locazioni sull'heap
+ controllare condizioni su delle variabili

###### Esempi :

Duplicazioni di 2 variabili

![[Pasted image 20231010110858.png]]

Caricamento di una variabile locale nello stack

![[Pasted image 20231010110922.png]]

Store di una variabile nelle variabili locali

![[Pasted image 20231010111153.png]]

Somma di due variabili 

![[Pasted image 20231010111432.png]]










#### Perchè usare OOP

Il paradigma di programmazione ad oggetti o *OOP* ( *Object Oriented Programming* ) ci consente di creare codice che si concetri nella *riusabilità* , questo avviene attraverso  : 
+ l'*incapsulamento* del codice 
+ *information hiding*
+ *eridetarietà* che ci permette di estendere e specializzare codice già esistente
+ *polimorfismo* , *metodi dinamici* , *classificazione* ci permetto di realizzare algoritmi riusabili 


# Introduzione al linguaggio

## Classi

Le classi rappresentano oggetti reali o immaginari , queste consitono di *campi* ( che identificano lo stato di un oggeto ) e *metodi* ( identificano le azioni e il cambio di stato di un oggetto )

Ogni *classe* definisce un *tipo*

La parola chiave *this.* viene utilizzata per accedere agli oggetti della classe 

Esempio : una macchina 
```java
class Car {
	double fuel;
	double speed;

	void refuel(double amount){
		fuel+=amount;
	}

	void accelerate(double a){
		speed*=a;	
		fuel-=a*FUEL_CONS	
	}

	void fullBreak(){
		speed = 0.0;
	}
}
```

Le *classi* possono essere istanziate in *oggetti* :
```java
Car myCar = new Car(); //invocazione del default constructor visto che non ne abbiamo definito uno = tutti i valori a 0 : fuel=0 , speed=0.0
```

Le variabili locali ( `myCar` ) contengono una reference ad un *oggetto* 

Quindi se per esempio ho 2 macchine e assegno dei valori alla prima , sucessivamente ne creo un'altra e voglio che abbia gli stessi valori se le assegno la prima macchina avrò copiato un pointer alla prima machina quindi se modifico la seconda modificherò anche la prima : *aliasing*

```java
Car Car1 = new Car();
// fuel=0 , speed=0.0
Car1.refuel(32);
// fuel=32 , speed=0.0
Car1.accelerate(43);
// fuel=30 , speed=43

Car Car2 = Car1;
// fuel=30 , speed=43
Car2.fullBreak();
// fuel=30 , speed=0.0
Car1 // fuel=30 , speed=0.0 ho modificato anche Car1
```

### Tipi

Possiamo dividere i tipi di *java* in 2 categorie :
+ **Valori** : int/long , boolean , float/double , char 
+ **Reference** : oggetti , array etc... ( tutti questi contengono un pointer all'area di memoria asseganta ad un oggetto , array etc... )

L'utilizzo di *reference* è utile per diminuire la presenza di duplicazioni / ridondanza di dati e codice 

#### Aliasing

*Aliasing* indica che un'area di memoria può essere acceduta tramite più nomi differenti ( ad ogni nome è associato lo stesso pointer ) , consente di effettuare *data-sharig*

Example :

![[Screenshot 2023-10-10 133609.png]]
### Constructors

I *costruttori* sono metodi speciali che ci permettono di istanziare una classe con valori differenti da quelli di default

Il costruttore che viene utilizzato senza averne definito uno è detto di *default* e imposta i valori predefiniti ( a 0 o null ) ai *campi*

Se però definiamo un *costruttore* differente da quello di default , quello di default non viene inserito nella classe

Esempio :
```java
class FuelType{
	String name;
	double costPerLiter;
	double fuelConsumption;

	FuelType(String n, double cpl, double fc){ //costruttore
		this.name=n;
		this.costPerLiter=cpl;
		this.fuelConsumption=fc;
	}
}
```

*this* può essere utilizzato per chiamare costruttori all'interno di altri costruttori 
Esempio :
```java
class FuelTank{
	String name;
	double amount;

	FuelTank(FuelType type, double amount){ 
		this.type=type;
		this.amount=amount;
	}

	FuelTank(FuelType type){
		this(type,0);// chiama il primo costruttore
	}
}
```

In *byte code* il costruttore è identificato con `init` , `clinit` per i costruttori statici

### Modificatori

3 tipi di *modificatori*
+ *Access* modifiers : applicato a *campi* e *metodi*
	Utilizzati per limitare l'accesso dall'esterno di vari elementi di una *classe*
	+ *public*
	+ *default*
	+ *protected*
	+ *private*
+ *Concurrency* modifiers : applicato a *campi* e *metodi*
	Utilizzati per rendere il codice "simultaneo"
	+ *sincronized*
	+ *volatile*
+ *Altri* 
	+ *static* : utilizzato in *campi* e *metodi*
		Utilizzato *nelle classi* non in oggetti 
		*Metodi* statici possono accedere solo a campi statici e a metodi statici e si riferiscono alla *classe* stessa , per questo non si può usare *this*
		Può essere anche scritto un costruttore statico che segue le regole precedenti e viene eseguito all'inizializzazione della classe ( ancora prima dell'istanziazione di oggetti )
		Un *campo statico* è unico per tutti gli *oggetti* istanziati
		Esempi :
	```java
	class FuelTank{
		double amount;
		static int numberOfTanks;

		static void resetTanksCount(){
			numberOfTanks=0;
		}
		static{
			FuelTank.resetTanksCount();
		}
	}
	```
	+ *final* : utilizzato in *campi* , *metodi* e *classi*
		Un *campo* finale non può essere modificato dopo la sua inizializzazione , tutti i campi *final* devono essere inizializzati da un costruttore
	+ *abstract* : utilizzato in *metodi* e *classi*

Più modificatori possono essere assegnati ad uno stesso *campo* , *metodo* o *classe* , a patto che siano compatibili

### new operator

L'operatore *new* è colui che istanzia una classe 
Esempio :
```java
Car c = new Car(100,"diesel",10);
```

I passaggi che svolge sono : 
+ Alloca la memoria per memoriazzare lo stato di un oggetto
+ Inizializza tutti i *campi* a zero/null
+ Invoca il costruttore specificato dai parametri in ingresso
+ Ritorna un *pointer* all'oggetto creato ( nell'heap )

## Packages

/git

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

# 9/10/2023

getter info su stato di un oggetto , può non essere direttametne un campo

Docs

.jar artifact contiene il bytecode
manifest : conteiene la classe main

javadoc ( docs in html )
commenti per documentation /** */ 



