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

| - | Same class | Same package | Sottoclassi | Dappertutto |
| ---- | ---- | ---- | ---- | ---- |
| public | yes | yes | yes | yes |
| protected | yes | yes | yes | no |
| \<default\> | yes | yes | no | no |
| private | yes | no | no | no |

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

L'overloading di un metodo è differente dall'overriding in quanto abbiamo diversi metodi con lo stesso nome ma con *firme* ed *implementazioni* differenti

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

La *firma* contiene :
+ la classe contenente la definizione del metodo
+ il suo nome
+ il numero e tipop dei suoi parametri

>[!warning]
>Non comprende i modificatori


Viene fatto l'**Overload** se :
+ Il *nome* è lo stesso
+ e la *firma* è differente

>[!todo]
>slide 22 inheritance
>#todo

#### Final Methods and Classes

Per evitare che vengano *overridden* alcuni metodi questi possono essere dichiarati **Final** o **Static** 

Un metodo **Final** nello specifico rimane lo stesso sempre ( garantito dal modificatore )

>[!warning]
>Costruttori e metodi astratti non possono essere **Final** 

**Esempio** :

```java
public class Vehicle{

	public void accelerate(double a){
		this.speed += a ;
	}

}

public class Car extends Vehicle {

	final public boolean accelerate(double a){
		super.accelerate(a);
		this.fuel -= a*fuelType.fuelConsumption
	}

}


public class Truck extends Car {...} // non posso sovrascrivere accelerate poichè final nella sua superclasse
```


Anche una *classe* può essere dichiarata *final* questo fa in modo che non possa essere estesa 

>[!note] 
>Una classe non può essere dichiarata `{java}protected` o `{java}private` 

>[!todo]
>completa spiegazione

#### Modificatori consentiti 

|-|Class|Method|Field|
|--|--|--|--|
|public|YES|YES|YES|
|protected|NO|YES|YES|
|\<default>|YES|YES|YES|
|private|NO|YES|YES|

|-|Class|Method|Field|
|--|--|--|--|
|static|NO|YES|YES|
|final|YES|YES|YES|
|abstract|YES|YES|NO|

## Subtyping

Java ha i tipi dichiarati , per questo possiamo svolgere solo operazioni che sono constentite in quel tipo 

**Esempio** :

```java
Vehicle v1 , Vehicle v2;
v1 + v2 // not allowed
v1.getSpeed() // allowed
```

Java è un linguaggio *fortemente tipato* $\implies$ quando chiamiamo una funzione i tipi che gli passiamo devono essere compatibili con i tipi che sono dichiarati nella firma della funzione

Java è un linguaggio *digitato staticamente* ( *statically typed* ) $\implies$ i tipi sono verificati a compile time infatti ogni espressione ha un tipo conosciuto durante la compilazione 
Alcuni tipi sono dichiarati ( es `{java}Vehicle v1` ) , altri sono inferiti ( es \<int>+\<int> = int )  
#### Principio di sostituzione

Se una classe C1 espone un interfaccia che è più grande ( ossia definisce tutti i campi e metodi di C2 più qualcos'altro ) di C2 allora quando ci aspettiamo C2 possiamo metterci un'istanza di C1

**Esempio**

```java
race(new Car(), new Truck(), 100); // posso passare una sottoclasse alla superclasse poichè le sottoclassi implementano tutti i metodi e campi della superclasse  

int race(Vehicle v1, Vehicle v2, double length){

	... // solo operazioni consentite in vehicle

}
```

Se una classe C1 estende un'altra classe C2 allora le sue istanze hanno una interfaccia più grande , tutte le occorrenze di C2 possono essere sostituite da C1
### Tipi statici e dinamici

Ogni espressione ha una tipo *static* determinato a compile time e un tipo *dinamico* determinato a execution time 

Il tipo *dinamico* può solo essere un sottotipo del tipo *statico* esponendo gli stessi o più membri 

Il tipo *statico* determinato a compile time ci consente di dire che a runtime questi membri esistono

**Esempio** : 

```java
class Vehicle {...} 
class Car extends Vehicle {...} 
class Truck extends Car {...} 
class Bicycle extends Vehicle {...} 

int race(Vehicle v1, Vehicle v2) {...} 

// il tipo dinamico corrisponde allo statico
Car c1 = new Car(), c2 = new Car(); 
Truck t = new Truck();

// il tipo dinamico è un sottotipo dello statico
Vehicle v = new Car();

// il tipo passato è un sottotipo del tipo dichiarato
race(c1, c2);
race(c1, t);
race(t, v);
```

### Casting di tipi

`{java}(<type>) <expression>`

Possiamo fare *casting* di un'espressione ad un sottotipo del suo tipo *statico* , se il tipo che castiamo non è compatibile errore at execution time

>[!warning]
>Non possiamo castare ad un tipo non sottotipo

**Esempio** :

```java
Vehicle v = new Car();

Car c = (Car) v; // consentito 

Car c1 = new Car();

((Vehicle)c1).accelerate(...); // inutile 

Bicycle b = (Bicycle) c1; // non è possibile una macchina non può essere una bicicletta

Bicycle b1 = (Bicycle) v; // consentito ma crasha a runtime pichè v è veicolo con new Car() -> posso castarlo perè il tipo statico è veicolo ma il tipo dinamico è Car che non è compatibile con Bicycle
```

### instanceof

Per verificare il tipo *dinamico* usiamo la seguente espressione : `{java}<expr> instanceof <type>` 
Ritorna `{java}true` se e solo se il tipo dinamico dell'espressione è un *sottotipo* del *tipo* dato

>[!warning] 
>Non posso controllare un tipo che non è sottotipo

**Esempio** :

```java
Vehicle v = null; 
if(Math.random()>0.5) 
	v = new Car(); 
else v = new Bicycle(); 

((Car) v).refuel(...); // potrebbe non essere vero se prima ho dichiarato una bicycle

if(v instanceof Car) 
	((Car) v).refuel(...); // svolto solo se il tipo dinamico è Car quindi safe 

Car c = new Car();
if(c instanceof Vehicle) 
	c.fullStop(); // inutile Car è sempre un veicolo 
	
if(c instanceof Bicycle) // non possibile è sempre falsa 
	c.fullStop();
```

## Polimorfismo

Ciò che abbiamo definito in precedenza : *Inheritance* , *Subtyping* permettono il polimorfismo infatti ciamiamo uno stesso metodo `{java}accelerate(100)` su diverse istanze della classe `{java}Vehicle` portando a comportamenti differenti a seconda su quale istanza viene chiamato 

**Esempio** :

```java
class Vehicle{
	public void accelerate(double a){...}
}

class Car extends Vehicle { 
	public void accelerate(double a) {...} 
}

class Truck extends Car {...} 

Vehicle v1 = new Vehicle();
Vehicle v2 = new Car();
Vehicle v3 = new Truck();

v1.accelerate(100); // svolge l'implementazione di Vehicle
v2.accelerate(100); // svolge l'implementazione di Car
v3.accelerate(100); // svolge l'implementazione di Truck che eredita l'implementazione di Car

```

### Limiti di extend

Ogni classe può al massimo estendere un'altra classe ( *single inheritance* )

Potrebbe essere che più calssi possano condividere delle caratteristiche per esempio :
+ `{java}class Truck extends Car` 
+ `{java}class HorseCart extends Vehicle` 
Ma in entrambi i casi possiamo caricare un camion con tot kg di qualcosa come possiamo caricare un carrello trainato da cavalli con tot kg di qualcosa , abbiamo una ripetizione di codice 
## Interfacce

Per coprite i limiti della *single inheritance* si possono utilizzare le **Interfacce** , queste definiscono solo firme di metodi ( non la loro implementazione ) 

Un *interfaccia* definisce un nuovo tipo come le classi 

Se voglio implementare i metodi definiti in una interfaccia all'interno di una classe uso la seguente sintassi :

```java
interface Loadable{
	public void changeLoad(double l);
}

class Truck extends Car implements Loadable{

	private double load;
	public void changeLoad(double l){
		load += l;
	}

}
```

>[!warning]
>implementare una interfaccia significa implementare *tutti* i metodi


>[!note]
>in una classe posso implementare più interfaccie

Se ho più classi che implementano lo stesso metodo nello stesso modo posso dichiarare come `{java}default` una implementazione del metodo nella interfaccia in modo tale che se implemeto una interfaccia in una classe posso non ridefinire il metodo ed avere la sua implentazione di `{java}default` 

>[!note] 
>L'implementazione all'interno della interfaccia può dipendere solo da metodi pubblici

**Esempio** : 
```java
interface Loadable { 
	default public void chargeLoad(double l) {                              
		this.setLoad(this.getLoad()+l); } 
	} 
	
class Truck extends Car implements Loadable {}
```

>[!note]
>Le interfaccie possono avere dei campi ma solo *static* , *public* e *final*

In questo modo il tipo di una *classe* è definito come :
+ *sottotipo* delle superclassi che estende
+ *sottotipo* delle interfacce che implementa

>[!warning]
>Implementare due interfaccie che hanno metodi con la stessa firma e implementazione di default è *proibito* ( detto *diamond problem* )

![[DiamondProblem.excalidraw]]

### Estensione di intefacce 

Una interfaccia può *estendere* un'altra interfaccia 

Le regole per l'*eredità* dei tipi sono le stesse rispetto alle classi :
+ Sottointerfacce devono garantire una interfaccia più grande

**Esempio** : 
```java
interface Loadable{
	public void changeLoad(double l);
}

interface LoadableUnloadable{
	public void unchageLoad(double l);
}

class Truck extends Car implements LoadableUnloadable {
	private double load;
	public void chargeLoad(double l) { 
		load += l;
	}
	public void unchargeLoad(double l) { 
		load -= l;
	}
}
```

### Classi Astratte vs Interfaccie

|-|pros|cons|
|--|--|--|
|abstract classes|hanno un stato , possiamo implementare alcuni metodi|possiamo estendere al massimo una classe|
|interfaces|non possono avere uno stato , non possiamo implementare i metodi tranne tramite implementazioni di default ma hanno dei limiti ( posso utilizzare solo metodi pubblici )| possiamo estendere\implementare più interfaccie|

## Method Dispatching

Per chiamare un metodo usiamo la seguente sintassi : `{java}<reciever>.<method_name>(<parameters>)` , il codice che si vuole eseguire è collegato alla *classe* del `{java}<reciever>` ( alcune volte può essere implicito es `{java}this` , la classe dove siamo ) 

Per questo dobbiamo decidere da quale classe vogliamo iniziale la ricerca dell'implementazione del metodo , ovviamente se la classe non contiene l'implementazione dobbiamo controllare per la sua superclasse  

Se però abbiamo dei metodi *sovrascritti* ( *override* ) questi nascondono il comportamento della superclasse 

>[!note]
>Possiamo accedere all'implementazione della superclasse nel seguente modo :
>`{java}super.<component>` 
>Questo ci permette di evitare la duplicazione di codice , in quanto se parte del metodo *sovrascitto* è già implementato nella superclasse ci basterà chiamare l'implementazione della super classe
>Ci permette inoltre di nascondere l'implementazione di parte del codice alle sottoclassi 

### Prima Implementazione

1. Estraiamo il tipo *dinamico* del `{java}<reciever>` della chiamata del metodo ( è sempre presente anche se implicito )
2. Cerca un metodo in questa classe che he la stessa *firma* 
	1. Se trovato ritorna il metodo
	2. Se non trovaro ripeti passo 2 con la superclasse della classe corrente 

### Supportare overriding dei metodi

Visto che se un metodo sovrascrive un metodo della superclasse nasconde la sua firma andremo a selezionare l'implementazione più specifica che troviamo per quel metodo ( ossia quello al livello più basso all'interno della gerarchia dei tipi )

Utilizzare il tipo *statico* non funzionerebbe poichè necessiterei del tipo di ogni oggetto a compile time ma questo può cambiare a runtime

**Esempio** :

```java
Vehicle v1 = new Vehicle();
Vehicle v2 = new Car();
Vehicle v3 = new Truck();

v1.accelerate(100); // in v1 iniziamo a cercare dal tipo dinamico Vehicle che ha il metodo implementato e quindi lo eseguiamo
v2.accelerate(100); // in v2 iniziamo a cercare da Car che ha il metodo implementato e quindi lo eseguiamo
v3.accelerate(100); // in v3 iniziamo a cercare da Truck che però non ha il metodo implementato cerchiamo quindi il metodo nella sua superclasse Car che ha il metodo e quindi lo eseguiamo
```

### In presenza di Overloading

Le firme delle funzioni potrebbero avere stesso nome ma argomenti differenti ( con *sottotipi* ) 

Svolgiamo quindi lo *static dispatiching* degli argomenti del metodo , sciegliendo l'implementazione con i tipi statici più vicini 

Questo limita ancora il polimorfismo , per questo necessitiamo di svolgere *dinamic dispatching* anche dei tipi dei metodi 

### dispatching

#### static

#### dynamic

#### overloading

#### metodi

### java algorithm

>[!todo]
>correggi method dispatching
>#todo

## Generic types

Utilizzati per generalizzare l'implementazione di metodi parametrizzando il suo tipo ( es : una lista può essere di interi , float , double etcc )

Possiamo specificare tipi generici per *matodi* e *classi*

Questo tipo di polimorifismo viene detto *parametric polymorphis* in quanto utilizziamo un unico simbolo per rappresentare più tipi differenti  

Un tipo *generico* può essere visto come un parametro che sostituiamo con il tipo che vogliamo quando gli passiamo un tipo 

**Esempio** :

```java
public class List<V> { 
	private V[] elements;
	
	public void add(V el) { 
		int n = elements.length+1;
		elements = Arrays.copyOf(elements, n); 
		elements[n-1] = el; 
	} 
	
	public boolean contains(V el) { 
		for(int i=0; i < elements.length; i++)
			if(elements[i]==el) return true; 
		return false; 
	} 

	public V get(int i) { 
		return elements[i];
	}
}
```

I generics di java sono *invarianti* :
	Non posso assegnare un espressione con un tipo generico ad una variabile con un tipo generico differente anche se uno è sottotipo dell'altro

**Esempio** : 

```java
public class List<V> { 
	public void add(V el) {...} 
	public boolean contains(V el) {...} 
	public V get(int i) {...} 
} 

List v = new List(); 
v.add(new Car(...)); 
List b = new List(); 
v.add(new Bicycle()); 

// ----- //
v = b; // errore 
b = v; // errore
```

>[!note]
>Gli array sono *covarianti*
>Posso eseguire : `{java}Vehicle[] v = new Bicycle[10]`

I generici nei *metodi* possono essere utilizzati come : 
+ tipo dei parametri 
+ tipo di ritorno
+ tipo delle varibili locali 

**Esempio** :

```java
public static <T> T getFirst(List<T> list){
	return list.get(0);
}
```

### Deduzione dei tipi

Non dobbiamo passare esplicitamente il tipo generico quando istanziamo la classe , l'inferenza dei tipi lo fa per noi 

```java
List<Vehicle> v1 = new List<>() // verrà creata una lista di veicoli anche se non lo abbiamo specificato nella new , viene dedotto dalla dichiarazione di v1 
```

### Restricted generics

Se vogliamo che vengano assegnati solo un determinato *tipo* o sottotipi di un tipo possiamo scrivere nel seguente modo :

```java
<T extends Vehicle> T race(T v1, T v2, double length) { ... }
```

In questo modo `{java}T` può essere solo un *sottotipo* di `{java}Vehicle` , a patto che vengano utilizzati solo componenti *sottotipi* di `{java}Vehicle` nell'implementazione

Quando istanziamo la classe o chiamiamo il metodo viene controllato che il tipo sia compatibile 
### Wildcards

Invece di passare un tipo generico passiamo `{java}?` per cui : `{java}List<?>` è supertipo di `{java}List<T>` per un qualsiasi `{java}T`

Anche le *wildcards* possono essere limitate usando `{java}extends` , in questo caso gli `{java}extends` sono *covarianti* 

**Esempio** :

```java
List<? extends Car> // è un sottotipo di 
List<? extends Vehicle>
```

```java
public class List<V> { 
	public void add(V el) {...} 
	public boolean contains(V el) {...} 
	public V get(int i) {...} 
} 

List<Car> v = new List<Car>(); 
List<?> q = v;
List<? extends Vehicle> w = v; 

Vehicle e = q.get(0); // error 
q.add(new Car(...));  // error 
Vehicle e = w.get(0); // OK 
w.add(new Car(...));  // error 
v.add(new Truck(...));// OK
```

## Object class 

La classe *Object* è una classe universale , se una classe non estende esplicitamente una classe questo vuol dire che implicitamente estende la classe *Object* 

La classe *Object* fornisce dei metodi comuni a tutte le classi :
+ `{java}protected Object clone()`
+ `{java}boolean equals(Object obj)`
+ `{java}int hashCode()`
+ `{java}String toString()`

### equals()

Indica quando un altro oggetto equivale a questo 

**Proprietà** :
+ Riflessiva : `{java}x.equals(x)`
+ Simmetrica : `{java}x.equals(y)` $\iff$ `{java}y.equals(x)`
+ Transitiva : `{java}x.equals(y)&&y.equals(z)` $\implies$ `{java}x.equals(z)` 

Fare `{java}==` è diffrente , in fatti questo confronta solo se gli indirizzi dei due oggetti sono gli stessi , non che i valori al loro interno siano gli stessi 

**Esempio** :

```java
Car car1 = new Car(0,fuelType,100);
Car car2 = new Car(0,fuelType,100);
car1.equals(car2) // true
car1==car2 // false
```

**Implementazione standard** :

```java
public class Car {
	private double speed; 
	private FuelType fuelType; 
	private double fuel; 
	public boolean equals(Object o) { 
		if(o != null && o instanceof Car) { 
			Car o1= (Car) o;
			return o1.speed == this.speed && 
				   o1.fuel == this.fuel && 
				   this.fuelType.equals(fuelType); 
		} 
		else return false; 
	} 
}
```

### clone()

Ritorna una copia dell'oggetto :
+ Oggetto differente ( refence differente )
	`{java}o.clone() != o`
+ Stesso contenuto
	`{java}o.equals(o.clone())==true`

>[!warning]
>Oggetti dei campi non sono contenuti nella `{java}clone()` , vengono solo copiate la reference per loro

>[!note]
>`{java}clone()` è `{java}protected` , posso solo clonare la classe stessa o le sue sottoclassi

**Esempio** :

```java
class FuelTank{
	private FuelType type;
	private double amount; 
	public FuelTank(FuelType t, double a) {...}; 
	protected Object clone() { 
		return new FuelTank(type, amout); 
	}
} 
```

### hashCode()

Ritorna un valore di *hash* per quell'oggetto , questo metodo è implementato per sfruttare i vantaggi dati in termini di complessità computazionale dalle *hash* *tables* 

Il codice computato serve per unire oggetti che potrebbero essere *potenzialmente* `{java}equals()` 

Quando *sovrascriviamo* `{java}equals()` dobbiamo necessariamente anche sovrascrivere `{java}hashCode()` , e viceversa
### toString()

Il metodo `{java}toString()` presente nella classe `{java}Object` ritorna la rappresentazione in formato `{java}String` di un oggetto 
## String class

La classe `{java}String` rappresenta una stringa di caratteri in java 

Contiene come campo un array di caratteri , ogni volta che dichiariamo una stringa con `{java}" "`  istanziamo un oggetto di tipo `{java}String`

>[!note] 
>Le stringhe sono *immutabili* , per questo ogni qualvolta chiamiamo un metodo di `{java}String` questo non modifica la stringa stessa 
>Questo per fare in modo che abbiamo degli effetti indesiderati per l'*aliasing*

Questa qualità delle stringhe fa in modo che le stringhe possano essere scambiate tra vari oggetti ( questo viene fatto per ragioni di performance in quanto le stringhe sono uno degli oggetti più usati ) 

La classe `{java}StringBuffer` supporta invece stringhe *mutabili*

La classe stringa supporta la concatenzione di stringhe attravero l'operatore `{java}+` , questo corrisponde alla chiamata a funzione `{java}s1.concat(s2)` che restituisce una nuova stringa ( `{java}s1` non viene modificata ) creata aggiungendo ad un `{java}StringBuffer` i char presenti in `{java}s1` e `{java}s2`

>[!todo]
> arrivati a slide 17 pwp Lecture11
> #todo 

## Sets

Un `{java}Set` è una collezione di oggetti *iterabili* che non contengono elementi duplicati

Vi sono vari tipo di `{java}Set` un esempio è l'`{java}HashSet` , questo implementa l'intefaccia `{java}Set` utilizzando le *hash tables*

Un `{java}HashSet` non garantisce nessun ordine specifico per l'iterazione dei suoi elementi , non garantisce inoltre che questo rimanga costate nel tempo
>[!warning]
All'interno di una *collection* non possono essere inseriti due oggetti identici , possiamo però aggiungere due oggetti diversi e sucessivamente modificarli per farli diventare gli stessi
La soluzione sarebbe rendere gli oggetti immutabili oppure adottare altre librerie
### Iterare lungo collections

Iterare lungo una collezione di oggetti deve avvenire per un oggetto che risulti essere *iterabile*

**Esempio** :

Ciclo *for-each*
```java
for(<t> <v1> : <v2>)
```

>[!note]
>Il tipo della variabile locale deve essere lo stesso del tipo generico della collezione

L'ordine in cui leggiamo gli elementi della collezione dipende dalle caratteristiche della collezione stessa ( per esempio `{java}HashSet` non ha un ordine specifico mentre `{java}TreeSet` lo ha )

Un ulteriore tipo di `{java}Set` è il `{java}TreeSet` appunto che invece ordina gli elementi che riceve attraverso *Natural Ordering* o attraverso un *Comparator* fornito alla creazione del `{java}Set`

Per fare in modo che avvenga il *Natural Ordering* all'interno di un `{java}Set` dobbiamo implementare l'interfaccia `{java}Comparable` per la classe di oggetti che inseriamo nel `{java}Set` , dobbiamo inoltre definire il metodo `{java}compareTo()` 

## Tipi Primitivi

I tipi primitivi non sono sottotipi di `{java}Object` e sono :
+ `{java}boolean` 
	+ valori : `{java}true , false`
+ `{java}byte`
+ `{java}char`
	+ valori : `{java}'a','b','\n','\t',...`
+ `{java}short`
+ `{java}int`
	+ valori : `{java}12,075,0x123`
+ `{java}long`
+ `{java}float`
	+ valori : `{java}12.5,7.24e2`
+ `{java}double`

Su questi tipi possiamo svolgere operazioni standard come : 
+ `{java}+ - * / %` per i valori numerici
+ `{java}&& || !` per i valori booleani
### Boxing and Unboxing

Per ogni tipo primitivo esiste un *wrapper* che lo rappresenta come oggetto 
Questo risulta essere poco efficente ma più strutturato

![[Wrapper.excalidraw]]

Questi *wrapper* forniscono vari metodi di utilità come : 
+ Conversione di tipo
+ Conversione da `{java}String` ad un valore numerico
+ Valori minimi e massimi

Questi *wrapper* non vengono costruiti automaticamente alla creazione di una variabile dichiarata con un tipo *primitivo* ma dovremmo fare una cosa del genere :

```java
int a = 42;
Integer A = Integer.valueOf(a);
```
### Implicit type convertion

Ogni tipo numeri può essere assegnato a qualsiasi altro tipo numerico a patto che supporti un range di valori maggiore ( abbia più bit a disposizione )

Non è presente però una traduzione implicita tra tipi questa deve essere fatta esplicitamente 

**Esempio** :

```java
byte a = 3; //int -> byte 
char b = 'a'; // char -> char 
int c = b; //char -> int 
c = a; // byte -> int 
a = c; // int -> byte NON PUSSO FARLO
long d = c; //int -> long 
c = d; //long -> int NON PUSSO FARLO
float e = c; // int -> float 
e = d; //long -> float 
double f = e; //float -> double 
e = f; //double -> float NON PUSSO FARLO
```

```java
// traduzione esplicita
a = Integer.valueOf(c).byteValue(); // int -> byte 
c = Long.valueOf(d).intValue(); //long -> int 
e = Double.valueOf(f).floatValue(); //double -> float
```

## Eccezioni

Esempio di errori in java : 
+ Accedere ad una reference nulla
+ Divisione per 0
+ Accedere all'array in un indice fuori dai limiti 
+ Allocare memoria quando non ne abbiamo disponibile

Vi sono differenti livelli di severità dipendenti dal contesto

Gli errori sono rappresentati da *eccezzioni* che vengono lanciate quando non possiamo procedere con l'esecuzione normale

**Esempio** 

1. Viene lanciata un'eccezzione 
2. La normale esecuzione è sospesa 
3. L'eccezzione attraversa tutti lo stack delle chiamate 
4. Un errore con un messaggio viene riportato oltre che al completo stack delle chiamate 

### Throwable

Lo statement `{java}throw` ( usato per lanciare un'eccezione ) può lanciare solo oggetti `{java}Throwable` 

Gli oggetti che estendo `{java}Throwable` rappresentano i diversi tipi di errori che si possono presentare durante l'esecuzione 

La *classe* `{java}Throwable` ha un metodo per creare un messaggio , stamparlo etc...

Si possono definire nuove eccezzioni estendendo `{java}Throwable` direttamente o indirettamente che possono implementare la propria interfaccia  

Per dichiarare una eccezione all'interno di un metodo dobbiamo : 
+ dichiarare che quel metodo lancia una determinta eccezione
	`{java}int race(...) throws <exc1>, <exc2>`

Anche i metodi che chiamano questo metodo devono dichiarare che lanciano le eccezioni del metodo chiamato

**Commenting**

Essendo che le eccezioni fanno parte dell'interfaccia queste devono essere documentate all'interno del *javadoc*

`{java} @throws <exception>`   o `{java}@exception <exception>`

#### Ovveriding

Quando sovrascrivo un metodo devo assicurarmi che le eccezioni che lancia il metodo sovrascritto siano le stesse , un sottoinsieme o un sottotipo delle eccezzioni del metodo originale 

#### Checked and unchecked exceptions 

Vi sono 2 tipi di eccezioni che possono essere lanciate :
+ *Unchecked* : non devono essere dichiarate ed estendono `{java}Error` e `{java}RuntimeException`
+ *Checked* : devono essere dichiarate all'interno del metodo , estendono `{java}Exception` ma non `{java}RuntimeExcception` 

Le eccezioni *uncheched* vengono usate quando c'è un errore all'interno della logica del programma dalla quale *non possiamo recuperare* e dovrebbero causare la terminazione del progamma poichè il runtime environment potrebbe essere compromesso

>[!warning] 
>Le eccezioni *unchecked* non dovrebbero essere mai lanciate dal programma solo dalla JVM o la standard library

#### Catching exceptions

Si le eccezioni *checked* che le *unchecked* devono essere *catturate* ( *caught* ) 

Il blocco `{java}try{...} catch(...){...}` specifica il codice da eseguire se un'eccezione viene lanciata all'interno del codice controllato dal `{java}try` 

`{java}catch{<exc-type> e}` viene eseguito solamente se il blocco `{java}try` lancia un'eccezione sottotipo di `{java}<exc-type>` 

>[!note]
>Mai catturare eccezioni generiche come : `{java}Throwable , Exception , Error , ...` 
>I blocchi `{java}catch` non dovrebbero essere vuoti


Esiste inoltre il blocco `{java}finally` che viene eseguito in qualunque caso , sia che un'eccezione sia stata lanciata che no

Normalmente utilizzato per riportare lo stato del sistema ad punto accettabile , es chiudere le risorse IO aperte 

>[!note] 
>Il `{java}finally` viene eseguito anche se è presente un `{java}return` all'interno di un `{java}catch`
>Se però `{java}finally` contiene un `{java}return` oppure lancia esso stesso un'eccezione gli altri valori di ritorno o le altre eccezioni lanciate vengono scartate

**Esempio** :

```java
try{
	<body>
}
catch( <exc-type> e ){
	<catch-body>
}
finally{
	<finally-body>
}
```

Esecuzione : 
1. Esegui il body del `{java}try`
2. Se viene lanciata un'eccezione che è un sottotipo di `{java}exc-type`
	1. Esegui `{java}catch-body`
	2. Esegui `{java}finally-body` sia in caso di esecuzione normale che eccezionale
	3. Continua la normale esecuzione del programma o rilancia l'eccezione in base a cosa succede nel `{java}catch-body`
3. Se viene lanciata un'eccezione che non è sottotipo
	1. Esegui `{java}finally-body`
	2. L'eccezione viene propagata al livello superiore
4. Se non viene lanciata nessuna eccezione esegui `{java}finally-body` e continua l'esecuzione normale

#### Chains

Se un'eccezione è causata da un'altra eccezione si può creare una catena di eccezioni passando per parametro alla eccezione causata l'eccezione che la causa 

**Esempio** : 
```java
try {
	...
}catch( NegativeSpeedException e ){
	throw new IllegalArgumentException("msg" , e); // ho passato come causa NegativeSpeedException
}
```

>[!warning]
>La causa di un'eccezione può essere settata solo una volta , la seconda volta fallirà
## Assertions

Le *Assertions* controllano se una condizione è vera , il codice può continuare l'esecuzione anche se l'*asserzione* non è verificata 

**Esempio** :

`{java}assert <condition> :<message>`

Di default le *assertion* non sono controllate , vengono abilitate attraverso il flag `{java}-ea` nel compiler 
Quando sono abilitate se l'asserzione fallisce viene generata l'eccezione `{java}AsserionError` 

## Annotations

Le *annotazioni* consentono l'aggiunta di informazioni strutturate al codice 
A differenza dei commenti possono essere trattenuti dal compilatore 

Le annotazioni vanno separate in un file .java differente

Le *annotazioni* possono essere aggiunte a : 
+ Classi 
+ Campi
+ Metodi e Costruttori
+ Parametri e Variabili locali

**Esempio**

`{java}@Override`

L'informazione che stiamo *overridando* questo metodo è disponibile al compilatore e questo gli consente di lanciare un *warning* nel caso in cui in realtà non stiamo realmente *overridando* quel metodo ;
```java
public class Vehicle{
	@Override
	public int hashCode(int i){...}// questo metodo non overrida hashCode in quanto hashCode non deve avere argomenti
}
```

`{java}@Deprecated`

Viene utilizzato per indicare che un elemento dell'intefaccia non dovrebbe essere utilizzato , questo è necessario poichè se viene eliminato il programma che utilizza il metodo non compilerebbe più :
```java
@Deprecated(since: '2.0') // indica la versione dalla quale è deprecated
```

`{java}@SuppressedWarnings`

Viene utilizzata per fare in modo che alcuni warning non vengano riprodotti per quel pezzo di codice :
```java
@SuppressWarnings("unused")
public double getFuelType(){
	return this.fuelType.getFuelCost();
}
```

Si possono creare nuove *annotations* attraverso la seguente sintassi : 
```java
public @interface Speed{
	String type() default "kmh";
	boolean forward();
}
```

Gli attributi vanno definiti come metodi senza attributi con come tipo di ritorno il tipo della variabile

Se non specifichiamo `{java}default` quando dichiariamo un'eccezione siamo costretti a definirne un valore

```java
@Speed(forward = true) private double speed;
```

Una *annotazione* può essere ispezionata dalla *reflection* a runtime
### Target

Se vogliamo applicare le annotazioni solo su una parte del codice possiamo specificarlo con `{java}@Target`

**Esempio** :

```java
@Target{
	ElementType.METHOD,
	ElementType.FIELD,
	ElementType.PARAMETER
}
public @interface Speed{...}
```

### Retention

Possiamo determinare a che livello dobbiamo mantenere l'annotazione 

Ci sono tre livelli di retention :
+ SOURCE
	+ Se vogliamo che l'annotazione rimanga solo nel codice sorgente ( eliminato dal compilatore )
+ CLASS
	+ Se vogliamo che rimanga solo nel file .class ma non a runtime
+ RUNTIME
	+ Se vogliamo che rimanga anche a runtime ( potrebbero modificare il comportamento del programma a runtime )

**Esempio** :
```java
@Retention(RetentionPolicy.SOURCE)
public @interface Speed{...}
```
### JUnit

*JUnit* è una libreria esterna di testing del codice che utilizza le *annotazioni*

**Esempio** :

+ `{java}@Test` : Specifica un metodo di test , questo viene eseguito solo quando eseguiamo dei test ( testano il programma )
+ `{java}@BeforeEach` , `{java}@AfterEach` : Specifica cosa eseguire prima e dopo ogni singolo test ( utilizzato per preparare o resettare lo stato del programma )
+ `{java}@BeforeAll` , `{java}@AfterAll` : Specifica cosa eseguire prima e dopo tutti i test

### JAXB

Acronimo per *Java Architecture for XML Binding* , faceva parte della libreira standard di java fino alla versione 8 poi separata con una libreria esterna : `{java}jaxb-core`

Viene utilizzata per salvare in memoria classi sotto forma di file XML 

Utilizza *annotazioni* per specificare che classi devono essere mantenute all'interno di un file XML 

**Esempio** :

+ `{java}@XmlType` : Mappa un classe ad uno schema XML
+ `{java}@XmlRootElement` : Indica la classe come radice del file XML 
+ `{java}@XmlAttribute` : Mappa un campo o metodo getter / setter ad un attributo XML  
+ `{java}@XmlElement` : Mappa un campo o metodo getter / setter ad un elemento XML

Per fare in modo che dei dati vengano salvati all'interno di un file XML dobbiamo definire anche un metodo *marshal* e *unmarshall* per la classe che vogliamo salvare in XML 
+ *marshal* : scarica lo stato dell'oggetto in un file XML
+ *unmarshall* : legge lo stato di un oggetto da un file XML e ritorna un oggetto con quello stato

**Esempio** :

```java
static void marshal(FuelType fuelType) throws JAXBException {
	JAXBContext context = JAXBContext.newInstance(FuelType.class);
	Marshaller mar = context.createMarshaller(); 
	mar.marshal(fuelType, new File("./fuelType.xml")); 
} 

static FuelType unmarshall() throws JAXBException, IOException {
	JAXBContext context = JAXBContext.newInstance(FuelType.class);
	return (FuelType) context.createUnmarshaller() 
		.unmarshal(new FileReader("./fuelType.xml")); 
}
```

>[!note]
>JAXB ha bisogno di un costruttore senza nessun argoemento definito per funzionare 
>Deve essere esposto all'interfaccia pubblica per funzionare ( non la best practice )
## Reflection

La *riflessione* permette di accedere e usare programmaticamente i campi , metodi e costruttori delle classi caricate fino a quel momento in memoria 

La riflessione è implementata da `{java}java.lang.reflect` che forniace varie classi per accedere alle diverse parti di una classe 
### Class class

`{java}java.lang.class` è il principale punto di inizio della *reflection* , questa classe ha il compito di rappresentare tutti i tipi presenti all'interno del nostro programma 

Per ottenere un'istanza di `{java}Class` possiamo utilizzare :
+ `{java}Object.getClass` : ci permette di ottenere oggetti `{java}Class` che rappresentano tipi concreti di oggetti istanziati
+ `{java}<type_name>.class` : ci permette di ottenere oggetti `{java}Class` anche di oggetti non istanziabili ( es : tipi primitivi , interfacce , classi astratte etcc )  

La classe `{java}Class` fornisce diversi metodi : 
+ `{java}isPrimitive` , `{java}isInterface` , `{java}isAnnotation` , `{java}getModifiers` , etcc
	Ci permettono di ottenere informazioni riguradanti la *definizione* del tipo
+ `{java}getInterface` , `{java}getSuperclass` , `{java}getPackage` , etcc
	Ci permettono di ottenere informazioni riguardanti alla *gerarchia* del tipo
+ `{java}getField` , `{java}getMethods` , `{java}getConstructors` , etcc
	Ritornano tutti i campi , metodi e costruttori accessibili ( public )
+ `{java}getDeclaredFields` , `{java}getDeclaredMethods` , `{java}getDeclaredConstructors` 
	Ritornano tutti i campi , metodi e costruttori definiti ( anche quelli private )

**Esempio** : 

```java
Class<Vehicle> c = Vehicle.class; 
for(Constructor t : c.getDeclaredConstructors()) 
	System.out.println(t); // prints all declared constructors of Vehicle
for(Method m : c.getDeclaredMethods()) 
	System.out.println(m); // prints all declared methods of Vehicle
for(Field f : c.getDeclaredFields()) 
	System.out.println(f); // prints all declared fields of Vehicle
	// stamperà anche il campo $assertionAnabled se abbiamo abilitato le assertion dal compiler , questo campo viene aggiunto dal compiler per indicare che le assertion sono attivate
System.out.println(c.getSuperclass()); // get the superclass of Vehicle
System.out.println(c.getPackage()); // get the package of Vehicle 
```

### Field class

Questa classe ci dà accesso sia in lettura che scrittura di un campo 

Possiamo leggere i campi attraverso dei getters per i vari tipi : `{java}get` , `{java}getDouble/Int/..`
Possiamo scrivere i vari campi con : `{java}set` , `{java}setDouble/Int/..`

Posso inoltre ricavare altre informazioni come : `{java}getModifiers` , `{java}getType` etcc

Se un campo è settato privato e non possiamo scriverlo possiamo renderlo accessibile attraverso `{java}setAccessible` 

**Esempio** :

```java
Car c = new Car(0 , null);
Class classCar = c.getClass();
Class classVehicle = classCar.getSuperclass();
Field speed = classVehicle.getDeclaredField("speed"); // se non torvato NoSuchFieldException
// se speed è private possiamo scrivere speed.setAccessible(true) per renderlo accessibile
speed.setDouble(c,10.0);
```
### Method class

Questa classe ci permette di accedere ad un metodo 

Per accedere al metodo utilizziamo : `{java}getMethod(String name , Class ... parameterType)` che dati il nome del metodo e una seguenza di classi rappresentanti i tipi dei parametri

Ci permette di leggere la dichiarazione del metodo con : 
+ `{java}getReturnType`
+ `{java}getTypeParameters`
+ `{java}getGenericExceptionTypes`
+ `{java}getModifiers`
+ `{java}isDefault`

Possiamo inoltre invocare il metodo grazie a `{java}.invoke(Object obj , Object ... args)` che riceve l'oggetto ricevente dell'invoke e gli argomenti da passare a quel metodo 

**Esempio** :

```java
Car c = new Car(0, null); 
Class classCar = c.getClass();
Class classVehicle = classCar.getSuperclass();

for(Method m : classCar.getDeclaredMethods())
	System.out.println(m); // tutti i metodi anche privati di Car non quelli ereditati da Vehicle 
for(Method m : classVehicle.getDeclaredMethods()) 
	System.out.println(m); // tutti i metodi anche privati di Vehicle
	
Method accelerate = classVehicle.getDeclaredMethod( "accelerate", double.class); // scielgo il metodo che corrisponde al nome accelrate con unico argomento un double

Method getSpeed = classVehicle.getDeclaredMethod("getSpeed"); // scielgo il metodo getSpeed

result = getSpeed.invoke(c); // invoco il metodo get speed sull'oggetto c
Object result = accelerate.invoke(c, 2.0); // invoco il metodo accelerate su c con 2.0
```
### Constructor class

Per rappresentare i *costruttori* abbiamo una classe speciale `{java}Constructor` questo perchè sono metodi speciali che :
+ non ritornano un valore
+ non hanno un nome

Per prendere tutti i costruttori si utilizza `{java}getDeclaredConstructors` che non riceve un nome ( i costruttori non lo hanno )

Non possiamo chiamarlo direttamente poichè questo viene chiamato una sola volta quando istanziamo una classe , per questo utilizziamo `{java}newInstance` per invocarlo , questo ritorna un nuovo oggetto creato dal costruttore

**Esempio** :

```java
Class classCar = c.getClass(); 
Constructor cst = classCar.getDeclaredConstructor( double.class, FuelType.class); // prendo il costruttore con argomenti un double e un FuelType 

Car created = cst.newInstance(2.0, new FuelType("diesel", 0.015, 0.01));
```

### Annotations

La *reflection* può essere utilizzata per accedere *annotations* a runtime

L'interfaccia `{java}AnnotatedElement` ci fornisce dei metodi per accedere alle annotazioni :
+ `{java}isAnnotationPresent` : per verificare se un oggetto è annotato
+ `{java}getAnnotations` e `{java}getDeclaredAnnotations` :  per ricevere *tutte* le annotazioni di un oggetto
+ `{java}getAnnotation` e `{java}getDeclaredAnnotation` : per ricevere una specifica annotazione

Per accedere ai valori presenti all'interno di un'annotazione possiamo utilizzare `{java}.<name>` con il nome del campo , questo è possibile poichè il compilatore quando dichiariamo un'annotazione crea una nuova classe che estende `{java}Annotation` e che implementa i getters e setters per i campi di quella annotazione 

**Esempio** :

```java
public @interface Speed { 
	String type() default "kmh";
	boolean forward(); 
}

Class classVehicle = Vehicle.class; 
Field s = classVehicle.getDeclaredField("speed"); 
boolean annotated = s.isAnnotationPresent(Speed.class); // se è presente l'annotazione in s
Speed speedAnnotation = (Speed) s.getAnnotation(Speed.class);
String type = speedAnnotation.type(); // ritorna il type()
boolean forward = speedAnnotation.forward(); // ritorna forward()
```
### Conclusioni

|Pros|Cons|
|--|--|
|Possiamo accedere a componenti che potremmo non conoscere a compile time|Lungo da scrivere   
|Possiamo accedere a componenti che normalmente potrebbero non essere accessibili ( va contro i principi della programmazione orientata ad oggetti )|Non abbiamo nessuna garanzia statica ( possiamo fare eccezione per ogni cosa )

## Library managment

>[!todo]
>Forse da fare 
>#todo