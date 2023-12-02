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

[Naming conventions](https://www.oracle.com/java/technologies/javase/codeconventions-namingconventions.html)
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
	+ *\<default\>*
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

Le *classi* possono essere raggruppate in *pacchetti* ( *packages* )

Il nome dei *packages* deve rispecchiare un URL specchiato , il nome deve rispecchiare la classificazione in cartelle all'interno della repository

Le parole chiave della classe devono essere presenti anche nel "nome" del package 

Esempio :
```java
package it.unive.dais.po1.fuel;
class FuelTank{...}
class FuelType{...}
```

Per importare un package :
```java
package it.unive.dais.po1.car;
import it.unive.dais.po1.fuel.*;
class Car{...}
```

\* indica l'importazione di tutte le classi presenti nel pacchetto 

## Encapsulation

*Incapsulamento* : quando i dati sono legati ai metodi che li modificano 

Una parte fondamentale dell'*incapsulamento* è l'*information hiding* ossia rendere visibile all'usufruitore finale solo lo stretto necessario per utilizzare il proprio modulo senza avere accesso diretto ai dati

Per modificare l'accessibilità ai dati possono essere utilizzati gli *access modifiers* :
+ **public** : 
	consente l'accesso ovunque di quel dato o classe ( stessa classe , stesso pacchetto , stessa sottoclasse , dappertutto ) 
	Viene usato per rappresentare l'*interfaccia pubblica* del programma 
+ **protected** : consente l'accesso solo alla stessa classe , stesso pacchetto , stessa sottoclasse
+ **\<default\>** : consente l'accesso solo alla stessa classe , stesso pacchetto 
	Utilizzati per quello che deve essere acceduto dalla *stessa unità software*
+ **private** : consente l'accesso solo alla stessa classe
	Quello che dovrebbe rimanere nascosto : dettagli di implementazione che potrebbero essere modificati
+ **deprecated** : utilizzato per indicare un *metodo* non supportato

Esistono anche i *modules* , sono un file con all'interno il nome delle classe whitelistate per l'esportazione in un file *jar*

Riassunto :

|-|Same class|Same package|Sottoclassi|Dappertutto|
|---|---|---|---|---|
|public|yes|yes|yes|yes|
|protected|yes|yes|yes|no|
|\<default\>|yes|yes|no|no|
|private|yes|no|no|no|

Esempio :

```java
package it.unive.dais.po1.fuel;

class FuelTank {
	// il tipo di alimentazione non devo modificarla
	private FuelType type;
	// devo poter sapere e modificare la quantità di carburante che è presente nel        serbatoio
	public double amount;
	public FuelTank (...){...}
}
```

```java
package it.unive.dais.po1.fuel;

class FuelType {
	// è l'implementazione interna , non deve essere modificata ( il nome del             carburante non può essere cambiato )
	private String name; 
	private double costPerLiter;
	private double fuelConsumption;
	// i tipi di carburante devono essere costruiti esternamente
	public FuelType (...){...}
}
```

```java
package it.unive.dais.po1.car;
import it.unive.dais.po1.fuel.*;
class Car { 
	// è l'implementazione interna , non deve essere modificata ( la macchina non può     diventare a benzina )
	private double speed; 
	private FuelType fuelType;
	private double fuel;
	// devono essere visti esternamente
	public void refuel(FuelTank tank){...}
	public void accelerate(double a){...}
	public void fullBreak(){...}
}
```

### Getters

I metodi *getter* ci permettono di avere accesso di sola lettura a *campi* di un *oggetto*

Sono *public* e ritornano semplicemente o il valore di un *campo* o una computazione sui dati di quell'oggetto

In questo modo assicuro che lo stato dell'oggetto non possa essere modificato accedendo ad un *campo* 

Esempio :
```java
package it.unive.dais.po1.car;
import it.unive.dais.po1.fuel.*;
class Car { 
	private double speed; 
	private FuelType fuelType;
	private double fuel;

	public double getSpeed(){
		return speed;
	}
	
	public double getValueOfFuel(){
		return fuel*fuelType.getCost();
	}
}
```

### Setters

I metodi *setters* ci permettono di avere accesso di sola scrittura ad un *campo*

Sono *public* e generalmente consistono in una assegnazione ( può includere un controllo per fare in modo che venga inserito un valore valido )

Esempio 
```java
package it.unive.dais.po1.car;
import it.unive.dais.po1.fuel.*;
class Car { 
	private double speed; 
	private FuelType fuelType;
	private double fuel;

	public void setSpeed(double s){
		this.speed=s;
	}
	
	public void setSpeed(double s){
		if(s<0)
			this.speed=0;
		else this.speed=s;
	}
}
```

### Conclusion

I *getters* e *setters* sono molto utili per controllare più facilmente la variazione degli *oggetti* a discapito dell'efficenza in quanto è necessaria ogni volta una chiamata ad un metodo

*Information hiding* è fondamentale in quanto quando un modulo è rilasciato gli utenti utilizzeranno tutto ciò che è pubblico se rimangono pubblici dettagli di implemetazione possono verificarsi comportamenti imprevisti del modulo quindi :
Un cliente deve avere :
+ Accesso a tutte le informazioni strettamente necessarie per utilizzare il modulo
+ Nessun accesso a qualsiasi altro dato dell'oggetto

## Capsule

Una *capsula* è un pacchetto software con una chiara *application programming interface* ( *API* ) ( sarebbero i metodi pubblici )

Le *capsule* in java sono pubblicate come *librerie* ossia un insieme di *classi* ( appartenenti a *pacchetti* ) impacchettate assieme pubblicate come un file *jar* ( è un file zippato contente i *.class* e altre informazioni )

Per creare un *jar* viene utilizzato il comando `jar` , un *jar* può essere esseguito specificando il file *.class* che contiene il metodo main quando compiliamo

Il *jar* creato contiene un file `META-INF/MANIFEST.MF` che contiene informazioni generali sulla libreia come :
+ La sua versione : `Manifiest-Version: 1.0`
+ Il creatore : `Implementation-Vendor: Oracle Corporation` 
+ La versione della documentazoine  : `Specification-Version: 11`
etc..
[manifest](https://docs.oracle.com/javase/tutorial/deployment/jar/manifestindex.html)
## Javadoc

Bisogna documentare tutti i *metodi* pubblici ( tutti i metodi *API* ) con il loro significato in modo da astrarre dalla loro implementazione interna

La documentazione è scritta attraverso commenti , ci sono 2 tipi di commenti :
+ *Source code comments* spiegano cosa computa una parte specifica di un programma
	+ single line ( `//...` )
	+ multiple lines ( `/*...*/`)
+ *Documentation* ( *javadoc* ) sono commenti che spiegano l'*API* di una *libreria*
	+ `/**...*/`

*javadoc* genera un documento *HTML* con tutta la documentazione dell'*API* , utilizzati dalle *IDE* per mostrare la documentazione per un certo metodo

>[!todo]
>copia appunti 4° pwp
>#todo

## Inheritance

### Aggregazione

Un *oggetto* può riferire altri oggetto 

**Esempio** :

```java
class Car{
	double speed;
	FuelType fuelType; // oggetto 
	double fuel;
}
```

### Ereditarietà

Un *oggetto* estende le funzionalità di un'altro , ci consente di partire da una classe più astratta via via specilizzandola , un esempio sarebbe creare una classe `{java}class Vehicle` che implementa le caratteristiche comuni a tutti i veicoli ( come la velocità e l'accelerazione ) e sucessivamente specializzandola implementando varie classi che identificano vari tipi di viecoli 

**Esempio** 

```java
class Vehicle {
	double speed;
	void accelerate(double a){...}	
}

class Car extends Vehicle{
	FuelType fuelType;
	double fuel;
	void refuel( FuelTank tank ){...}
}
```

In questo caso la classe `{java}Car` erediterà `{java}double speed` e `{java}void accelerate(double a){...}	`

#### Proprietà

Ogni classe può estendere al massimo un'altra classe ( questa può essere già estesa )

**Esempio**

```java
public class Vehicle{...}
public class Car extends Vehicle{...}
public class Bicycle extends Vehicle{...}
public class Truck extends Car{...}
```

La gerarchia delle classi può essere rappresentata come un albero :

![[ClassExtends.excalidraw]]

>[!note]
>I metodi e campi che possono essere acceduti dalle sottoclassi devono essere `{java}default` o `{java}public`
>Questi fanno parte dell'*intefaccia* della classe

La *classe* che viene *estesa* viene detta **superclasse** , una classe che estende da una *superclasse* eredita tutti i componenti della *superclasse* che può accedere

Quando estendiamo una classe nel costruttore di quella classe dobbiamo chiamare il costruttore della superclasse attraverso `{java}super(...)` passandogli tutti i campi del costruttore che vogliamo chiamare .
Il costruttore di default della *superclasse* ( quello senza parametri ) viene chiamato implicitamente

Per accedere ai componenti della *superclasse* utilizziamo la keyword `{java}super.`

`{java}protected` ora ci permette di rendere visibile un metodo o campo alle suo sottoclassi ma non a tutti :

|-|Same class|Same package|Subclasses|Everywhere|
|--|--|--|--|--|
|public|ok|ok|ok|ok|
|protected|ok|ok|ok|no|
|\<default>|ok|ok|no|no|
|private|ok|no|no|no|

#### Abstract class

Sono classi che implementano solo parte dei metodi che definiscono , quelli non definiti sono *abstract*

>[!warning] 
>Una classe *abstract* non può essere istanziata ma può definire dei costruttori

Le sottoclassi che la ereditano possono :
+ implementare **tutti** i metodi *abstract* e quindi poter essere istanziata 
+ implementare solo alcuni metodi , non implementando tutti i metodi *abstract* essa stessa deve essere definita *abstract*

**Esempio**

```java
abstract class test{
	abstract int foo1();
	abstract int foo2(int b);
}

abstract class test2 extends test{
	int foo1() { return 0; }
	// non implemento foo2 quindi devo dichiarare la classe astratta
}

class test3 extends test2{
	int foo2(int a) { return a; }
	// avendo ereditato foo1 da test2 questo è già implementato mi basta implementare foo2 per potre creare una classe istanziabile
}
```
#### Method Overriding

le *sottoclassi* di una *superclasse* possono sovrascivere metodi della superclasse

Anche dopo aver sovrascritto un metodo abbiamo l'accesso al metodo della supercalsse attraveros il comando : `{java}super.<components>`

**Esempio** :

```java
public class Vehicle{
	
	private double speed;
	public void accelerate(double a){
		this.speed += a;
	}
	
}

public class Car extends Vehicle {
	
	private FuelType fuelType;
	private double fuel;
	// overriding
	public void accelerate(double a){
		super.accelerate(a);
		this.fuel -= a*fuelType.fuelConsumption;
	}
	
}
```

#### Method definition and signature

Un metodo è descritto da 2 parti : 
+ firma del metodo : 
	La *firma* contiene tutto quello che sappiamo quando chiamiamo un metodo :
	+ Tipo del ricevitore 
	+ Nome del metodo
	+ Numero e tipi *statici* dei parametri 
+ *definizione* del metodo :
	+ la *firma* del metodo +
	+ Il tipo di ritorno 
	+ visibiltà
	+ altri modificatori ( static , abstract  )
#### Method Overloading

L'overloading di un metodo è differente dall' overriding in quanto abbiamo diversi metodi con lo stesso nome ma con *firme* ed *implementazioni* differenti

**Esempio** :

```java
public class Vehicle{
	
	private double speed;
	public void accelerate(double a){
		this.speed += a;
	}
	
}

public class Car extends Vehicle {
	
	private FuelType fuelType;
	private double fuel;
	// overriding
	@Override
	public void accelerate(double a){
		super.accelerate(a);
		this.fuel -= a*fuelType.fuelConsumption;
	}
	
	public void refuel(double amount){
		fuel += amount;
	}
	// overloading
	public void refuel(FuelTank tank){
		fuel += tank.getAmount();
	}

}
```

La *firma* di un metodo definisce un **Contratto** 

Se una *firma* definisce un contratto meno restrittivo ( modificatori di visibilità meno restrittivo ) in una sottoclasse allora viene **Sovrascitto** ( *overrides* )

Viene **Overloadato** se :
+ Il *nome* è lo stesso
+ e la *firma* è differente

>[]
#### Final Methods and Classes

## Subtyping

### Tipi statici e dinamici

### Casting di tipi

### instanceof
## Polimorfismo

## Interfacce

### implementation

### estensione di intefacce 

## Method Dispatching

### invocations and field accesses

### overriding

### resolution

### dispatching

#### static

#### dynamic

#### overloading

#### metodi

### java algorithm

## Generic types

### subtyping with generics

### generic methods

### deduzione dei tipi

### restricted generics

### wildcards

### esempio

## Object class 

### equals

### clone

### hashCode

### toString

## String class

>[!todo]
> arrivati a slide 17 pwp Lecture11
> #todo 



%%
# Appunti
## 22/09/2023

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
/git
## 27/09/2023

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

## 29/09/2023

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

## 04/10/2023

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

## 06/10/2023

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

### Aliasing 

stessa area di memoria 2 nomi differenti es :
w1.damage
f1.weapon.damage

### Packages

Raggruppamenti di classi che possono essere importate in altre .class
naming conventions :
url reverse
deve rispecchiare il precorso delle directory

* * importa tutte le classi del package , memory !

### Encapsulation

Information hiding ( througth access modifiers ) :

private : solo visibile dalla classe ( visibilità di package , visibile solo dal package corrente , non c'è una gerarchia di package , package più profondi non ereditano , rimangono distinti )
public : tutti possono vedere ( final = non modificabile ) 
protected

deprecated metodo not supported

public "per usi interni" : modules file di testo in cui dico che classi esporto

## 9/10/2023

getter info su stato di un oggetto , può non essere direttametne un campo

Docs

.jar artifact contiene il bytecode
manifest : conteiene la classe main

javadoc ( docs in html )
commenti per documentation /** */ 

## 13/10/2023

artefatto = risultato compilazione

deployment = jar dentro un jar non ci sono commenti

nel manifest ho la versione del mio pacchetto non serve duplicarla con il javadoc `@version`

tag autore non in javadoc di default

visibility level = documentazione su private , public etcc

design by *contract*

specifica che input e corrisopndente output deve fornire un metodo

contratto sintattico


## 27/10/2023

Design by contract

@requires requisiti per classe javadoc ( precondition )
@ensures che val garantisce al completamento
indicazione con pre() per i dati presenti prima dell'esecuzione del metodo

contratto non deve contenere dei dati che non sono esposti esternamente

@ensures 
	return == 1 => f1.isAlive() && ! f2.isAlive() && f1.getLevel() >= pre(f1.getLevel())      && 
	return == 2 => f2.isAlive() && ! f1.isAlive() && f2.getLevel() >= pre(f2.getLevel())
non espone campi private e caraterizza ciò che succede se return 1 o 2 

per un campo possiamo definire un *object invariant* 

@invariant damage >= 0 && damage < pre(damage)
all'inzio damage >=0 e se viene utilizzato sarà sempre minore di ciò che era prima 

l'invariante deve essere soddisfatto in tutti i metodi che utilzzano il campo

java modelling lenguage

@loop_invariant ( invariante di ciclo ) ciò che rimane vero durante tutto il ciclo

new class 

## 03/11/2023

Inheritance

Creazione di classi generali poi espansione della loro definizione per definire classi diferrenti

Polimorifismo 

possesione di oggetti = ho una refernce ad un oggetto 

un oggetto può essere qualcosa es io sono una persona ma anche uno studente etcc

io ho tutti dati / funzionalità della persona + quello specifico per lo studente

*extends* 
![[erediarietà.excalidraw]]

erreditarietà singola una calsse estende solo un'altra 

Wizard non può avere come padre acnhe HUman

Gerarchia delle classi è un albero dx sx disgiunte 

perchè si possono creare dei casi di ambiguità

constructors se creo una sottoclasse prima inizializzo supercalsse poi me  stesso 
invocazione constructor superclasse :
`super(...)`

super pointer superclasse
pointer che mi permette di eseguire quello che sta nella superclasse

su sottoclassi invocazione costruttore sottoclasse 

se abbiamo costruttore senza parametri viene automaticametne invocato il supercostruttore

super può essere usato per eseguire campi e metodi ereditati ( i public )

this per tutti + sottoclasse

*protected* :
	visibile dal package e sottoclassi

Esternamente nessuno può inizializzare un personaggio di tipo generico solo wizard o figther

generalmente non fa parte dell'interfaccia esterna 
quando dobbiamo avere estensione alla calssse fa aprte dell'interfaccia esterna

volgio sapere quanti danni mi infligge un personaggio genreico o sapere qunato si difende , con personaggio generico non lo so

all'interno di figure hapublic getdamgae e setdamage ma non so l'implemetnaizoen per il personaggio genreico

*abstract* rendere i metodi astratti 
questo sarà obbligo delle mie sottoclassi di impleentarle

L'intera classe deve essere astratta , non può essere istanziata
metodo astratto può risiedere solo in una classe astratta 

se eredito da una calsse astratta , eredito l'obbligo di implementarlo se non viene iplementato deve essere definita astratta anche la sottoclasse

posso definire i metodi astratti nelle sottoclassi

## 08/11/2023

@override

ridefinizione dei metodi di super classi in sottoclassi 

definizione vs signature

ovverride stessa signature di un metodo 
overload signature differenti

overide visibiltà deve essere la stessa o più larga del metodo che sto overridando

## 10/11/2023

quando eredito un metodo deo avere la stessa vsiibilità o con visibilità più larga

final :
	In classi e metodi differente àfinal per i campi , si rifà alll'ereditarietà
	ci sono dei metodi che non voglio vengano riscritti adesso tutte le sottoclassi possono overridare un emtodo

`{java} final public boolean isAlive()`

in C# se non definisco modifier final è comunque final se voglio che lo sia uso keyword

campo non può essere astratto , campo non ha un'implementazione so già cosa va a fare

abastract+final -> metodo impossibile da implementare 

abstract+static -> qualsiasi cosa static non è ereditabile quindi non potrei definirlo 

static + final -> warning ridondante , statico non viene erdetiato quindi non potrebbe essere overridato ossia necessitare il final 

#### Classi 

classe final simile al metodo. la classe non può essere estesa

se ho una classe final posso non definire i metodi final -> ==ridondante==

classe non può essere privata poichè non darebbe utilizzabile , sarebbe visibile solo a se stessa 

classe  protected -> accedibile ovunque , non sarebbe protected ma publilc 

non può essere statica ( potrebbe avere senso se tutti i campi e metodi sono statici )

inner class può essere statica -> classe definita all'interno di un'altra classe  


### sottotipi

tipo statico c'è sempre , ogni tipo statico 

`{java} var` il compiler capisce che tipo possiede quell'oggetto 


quando ho una classe estesa -> calsse estesa è un sottotipo della supercalsse , permette nella pratica di applicare i l principio di sostituzione 

ci permette di usare metodi della superclasse nella sottoclasse poichè hanno lo stesso tipo 
>[!todo]
>ceck

`<:` -> sottotipo
Wizard `<:` Figure
Wizard tipo più preciso rispetto al supertipo Figure

### Polimorfismo

accelerate su macchina consuma benzian su bici accelera solo

tipo *dinamico* tipo :
`{java} Vehicle v = new Car()`

cambia da execution ad execution

il tipo dinamico è un sottotipo lo stesso tipo del tipo statico 
a livello statico posso sapere solo la "superclasse"

v è una macchina ma ptrebbe essere un'altra classe che estende la superclasse 

per vedere tipo dinamico  `{java} istanceof`

un wizard è anche un figure

posso castare il tipo `(tipo)`

## 15/11/2023

un qualcosa può essere più cose contemporanemaente
un camion e un carello sono entrambi caricabili 

multiple classes extensions creates diamond problem

![[Pasted image 20231115092234.png]]


**interfaces** 

ha un nome , all'interno una serie di firme di metodi  , non sto definendo l'implemetnazione dei metodi 
l'interfaccia è anche un *tipo* , non ha campi   

una classe può implementare un'interfaccia 
una classe eredita l'obbligo di implementare i metodi dell'interfaccia , se ne implementa solo alcuni o nessuno allora la classe deve essere astratta  

es magic sia una weapon sia una protezione w

```java

interface protection {

	public int getInfoDefence(){}

}
```

`{java} default`

per implementare metodi all'interno di interfaces 

```java
	// non serve default in campi di interface
	// private , non può essere utilizzato poichè potrebbe non essere inizializzato
	default public int getInfoDefence(){
		return defence;
	}
```


`final default` -> non può essere fatto 

campi default sono campi statici -> proprietà dedl mio tipo 
non si possono definire dei campi 
sono final anche

posso invocare degli altri metodi astratti che ogni classe deve definirlo 

firme dei metodi sono sempre pubbliche nelle interface 

interfacce che estendono altre interfacce  
quando un'interfaccia è sottotipo di un'altra interfaccia -> extends

quando 2 implemetazioni di default differenti da 2 interfaccie non posso ereditarle

interfaces
- senza campi

abstract class
+ solo eresitarietà multiple

## 17/11/2023

**Dispatching method calls**

reciever -> (this.speed ,, f.speed) che oggetto

quale metodo invocare , posso scieglere tra statico e dinamico
se mi baso sul tipo statico il metodo non cambierà a tempo di esecuzione 
chiamate a funzione cambiano a seconda del tipo dinamico

1 dal tipo dinamico guardo se ha implementaizione di quel metodo se è ereditata guardo nella superclasse 

risoluzione invocazione di metodo at runtime

risoluzione statica dei parametri ( con overloading scieglie quella con tipi statici soddisfatti ) 
perf

casting `figure->wizard` wizard è il tipo statico 

con più impleemtazioni che può scigliere sciglie  quella con i tipi più vicini' ( non devo cambiare tipo )

se ci sono 2 implemetazioni che hanno lo stesso 'costo' , priorità di scelta la stessa per il compiler

metodi statici  fa static binding quindi anche se viene chiamato da un tipo `dinamico` figthre viene eseguito il metodo del tipo statico `figure`

invocare metodo statico sempre su una classe no su un istanza , di base non viene ereditato quindi non può essere overridato

invokespecial ( binding statico sia del reciever sia dei  ) per costructors

`{java}return new Example(10)`

a livello statico so già che metodo devo chiamare -> example è satico + con parametri so il costruttore

![[Drawing 2023-11-17 11.48.03.excalidraw]]

classi generiche -> può ricevere dei tipi come parametri

## 22/11/2023

"Templates" in java :

quando classe generale viene utilizzata viene fatto il cast dinamico su tipo generico
tipo generico o sulla classe o sui metodi

```java
public <T> identity(T param){
	return param;
} 

public void foo(){
	AlmostEmpty obj = new AlmostEmpty;
	AlmostEmpty obj2 = obj.<AlmostEmpty>identity(new AlmostEmpty) ;
}
```

```java
obj.<AlmostEmpty>identity
```
indica su che tipo lavora il metodo

tipi generici a livello di bytecode non esistono 
invoca identity ritorna qualsisasi cosa ( non so il tipo di ritorno )

checkcast si passa dal tipo "qualisasi" al tipo che gli indichiamo ( casting se il tipo coincide con quello indicato  ) 

viene persa l'informazione di `{java}obj.<AlmostEmpty>` e viene fatto un cast dinamico `{java}(AlmostEmpty) obj.identity`

genericità su una classe 
```java
public class List<T1,T2>{// per il compiler una lista di oggetti (Object)

	//array list
	//private T[] elements = ...;
	// siccome non so il tipo a compile time non posso dichiarare un array con tipo T

	private T[] elements = null;

	public T get(int index){
		return elements[index];
	}

	public int length(){
		return elements.length;
	}

	public void add(T el){
		if(elements == null){
			ArrayList<T> list = new ArrayList<>();
			list.add(el);
			elements = list.toArrat(elements);
			// elements = Array.newIstance(); // array che è istanza di questa classe , di lunghezza n
		}
		//creare array con 1 el in più 
		elements = Arrays.copyOf(elements, elements.length+1);
		elements[elements.length-1]=el;
	}
	
}
```

```java

List<Wizard> f= new List<Wizard>(); 
Magic m = null;
f.add(new Wizard(m));
List<Figure> f2 = f; // non è possibile anche se la figure è suoerclasse di wizard 
// questo poichè in java le liste sono costanti
// se noi in f2 dopo l'aseganemnto aggiungiamo un wizard questi non sono compatibili

```

```java
Wizard[] f= new Wizard[2]; 
Magic m = null;
f[0]=new Wizard(m);
Sword s = null;
Armor a = null;
f[1]=new Fighter(s,a);
Wizard w = f[1];
```

I tipi degli array sono covarianti
ad un array di figure posso assegnare un array di wizard o figther
errore a runtime

tipi generici dei metodi sono legati ai metodi non alla classe 

il tipo statico essendo legato alla classe in generale T non è accessibile nel contesto satico devo dire che il metodo è parametrizzato su qualche tipo generico 
```java
public static <T1> T1 getFirst(List<T1> k)
```
`
`{java} new List<>()` il compiler assegan un tipo a seconda del contesto


tipi generici ristetti a solo sottotipi di qualche tipo 
`{java}public class ListFigure<T extends Figure> extends List<T>`
accetto solamente figure , figther , wizard

>[!note]
|
v

*covarianza* :
se ho lista di figure e una di figther se fosse covarainza figthrt sottotipo di figure va bene sui tipi di ritorno non sui parametri 

*controvarainza* figure sottipo figther poichè figure è un supertipo di fighter 

**Wildcards**
```java
List<?> listBoh = f;// f lista di figure
Object kk = listBoh.get(0);
// lista che è un supertipo di qualsiasi altra lista
// posso mettere dei bound per limitare i tipi
List<? extends Figure> listBoh = f;
Fighter kk = listBoh.get(0);
listBoh.add(new Wizard(null));// funziona so covarainza sul tipo di ritorno , nella controvarianza non funziona
```

## 24/11/2023

Object superclasse di tutto , implicitamente una classe in genrale estende la classe object

finalize sarebbe il free esplicito , viene invocato quando si libera la memoria , determinato dal gc non sappiamo se avviene e quando avviene

per sincronizzare i threads utilizzo degli oggeti qualsiasi

getClass oggetto che rappresenta il tipo dinamico dell'oggetto ( reflection )

equals per determinare se 2 oggetti sono gli stessi , implementato con oveload per ogni classe ( non stiamo coperendo il comportamento do Object )

>[!warning]

`{java}==` confronta addresses dei 2 object

equals proprietà matematiche :
```java
x.equals(y)
y.equals(x)

x.equals(y) > y.equals(z) -> x.equals(z)
```


## 29/11/2023

clone metodo protected >>> copia l'oggetto 
```java
@Override
protected Object clone(){
	return new Wizard(...) // calls constructor with all the parameter
} 
```

gli oggetti potrebbero non supportare il clone 

```java
protected Object clone() throws CloneNotSupportedException;
```

clone può essere fatto public (estensione della visibilità) , e cambiare return type 

interfaccia clonable , se viene inmplemetnata allora posso clonare quell'oggetto altrimenti no

per vedere se è cloanbile : 
```java
array[i] instanceof Clonable
```

Se lo clono non è detto che questo sia accessibile da ovunque ( clone potrebbe non essere pubblico -> potrebbe essere protected )

oggetti clonati sono equals -> ( di base può fare solo shallow copy ) , ed hanno stessa classe 

**hashCode**

all'inerno di un indice metto tutti gli oggetti che *potenzialmente* sono uguali 
se 2 oggetti sono == necessariamente devono avere lo stesso hashCode ( anche tra più objects )
se sono diversi non è required che abbiano index differenti in hashCode

`{java}Object.hash(el)` -> libreria che ci ritorna  un hash code adeguato 

```java
public int hasCode(){
	return 0; // always ok 
	// complessità pratica -> n object all'interno dell'indice 0
	return id%37; // grups of objects
	return id ; // tabella in cui ogni index 1 elemento memory duplication
} 
```

hashCode deve essere sempre definito se ridefinisco equals 

`{java}String` -> classe *final* sotto object 
istruzioni specifiche per String -> non fa nessuna new se gli passiamo una string 
`{bytecode}ldc "fff"` -> usando quei byte della variabile locale crea un oggetto di tipo stringa  
se 2 stringhe == costante nello stesso punto del pool 

```java
String a = "cf";
String b = "cf";

a.equals(b) -> true ; 

a==b -> true ; // stessa area di mem , aliasing 
se a.replace('c','t'); // a="tf" 

```

classe string è immutabile , a.replace ritorna una nuova stringa modificata non modifica l'originale 
`{java}a=a.replace()`

-> in questo modo non devo invocare ogni volta il costruttoredella stringa

operatori su stringhe -> 
+ concatenazione : `{java}a=a+"ceec"` in realtà non essendoci l'overload degli operatori è come fare `{java}a=a.concat("ceec")` -> in realtà invokedinamic ( non invoca la concat poichè è costoso ) nel bytecode 

`{java}toString()` -> ci aiuta a visualizzare lo stato di un oggetto ( è presente nella classe Object  )

```java
@Override
public String toString(){// public 

	return "....."; // descr oggetto

}
```


se non definisco un toString -> ritorna address ( posizione nel package + address ) di quell'oggetto 
se concateno una stringa con un oggetto chiamato il toString su di esso -> dove ho dei dati da rappresentare  


## 01/12/2023

**Sets**

Set tipo generico  ( insieme di elementi differenti tra loro ) 

hashset ->set che utilizza un hash table

ieteratori possiamo chiamarli esplicitamente per iterare in insieme di set 
altrimenti utilizziamo cicli for each
```java
for(T el : this)
```

il for each nel bytecode comunque chiama l'iterator 

con hash set non abbiamo nessuna garanzia dell'ordine in cui eseguiamo l'iterator per hashset
i treeset ci danno invece la garanzia di avere un ordine di iterazione

hashset estende direttametne abstract set 
tree set invece implementa navigable set -> ci da la caratteristica dell'ordine di iterazione

per fare treeset devo avere un modo per confrontare gli oggetti poichè li compara e poi li mette in ordine in modo da dare un ordine alla iterazione
quindi l'oggetto deve estendere il comparable

compareto -> ritorna un valore che ci permetta di capire se 
1 se ritorno 0 allora sono equals 

```java
// un oggetto e < di un'altro se il suo damage è minore il contrario se >
public int compareTo(OffensiveObject o){
	if(this.equels(o))
		return 0;
	int result = this.damage-o.getInfoDamage(); // se così se 2 oggetti differenti hanno damage == risulterano = anche se non lo sono
	if ( result != 0 )
		return result;
	return 1; // todo 
}
```

natural and total ordering 
se abbiamo un valore positivo l'oggetto è maggiore se diamo un valore negativo l'oggetto è minore

tutti gli oggetti che estendono offensiveobject devono implementare il compareto 

equals funziona con l'object mentre il comparable è parametrizzato 

il magi che compare to implementa quello di defensive object o quello di offensive object visto che entrambi hanno magic come sottoclasse
quando eredito 2 contratti con 2 tipi generici differenti , il compare to è definito su object e poi il compiler decide

aggiungo un interfaccia vuota comune ad entrambi ( estesa da entrambu ) che estenderà il comparable che lo farà su un oggetto generico 

implementazioni di default -> se abbaimo 2 che hanno stessa firma se sono ereditati -> non posso farlo per il problema di prima 

**classe collection**

collezione di oggetti

factory -> usa random per avere oggetti random


# Tutorati 
## 14/10/2023

final deve essere assegnato alla creazione dell'oggetto della classe solo 1 volta dal costruttore o nella dichiarazione della variabile

Encapsulation 

## 04/11/2023

## 18/11/2023
