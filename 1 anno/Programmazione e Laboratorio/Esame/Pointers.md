---
publish: true
---
### Lvalue , Rvalue

Un Lvaue è un valore che può essere messo sia a destra che a sinistra di un'espressione
hanno una posizione in memoria

Un Rvalue è un valore che può stare solo a destra di un'espressione
sono valori temporanei

Argomento del **copy constructor** è lvalue
argometo **move constructor** è rvalue reference

### Parametri effetivi , Parametri Formali

Effettivi : valori passati alla funzione quando viene chiamata 

Formali : quelli dichiarati da una funzione

### Passagio per copia o riferimento

Il passagio per copia chiama il copy constructor per creare un oggetto temporaneo copia del parametro effettivo

Passaggio per riferimento è quando la funzione ha come parametri formali delle reference in questo caso viene passato l'address della variabile che passiamo come parametro effettivo

### Funzione con reference in C

```c++
void (int &a, int &b){
	int tmo = a;
	a = b;
	tmo = b;
}
```

```c
void(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

```

### Pimpl

Il paradigma Pimpl è utilizzato per nascondere l'implementazione della classe all'utilizzatore finale 

Separa l'intefaccia da l'implementazione 

Pointer to implementation


## Pointers
/ * operatore dereference usato per ricavare un valore da un address 
per dichiarare un pointer int * p 
Per ricavare un address di una variabile devo usare & umpersand

## Constructors / destructors

Standard **constructor** only does shallow copy = copia i pointes non i dati

**Copy constructor** 

Copiare il valore a destra rhs a sinistra 
l'elemento iniziale non è stato ancora costruito quindi devo costruirlo

Example :
```c++
// dentro la classe

List(List const& rhs);

// implementazione

List::List(List const& rhs){

	head= null;

    Pnode pc=rhs.head;
    while(pc!=nullptr){//non ottimmizato complessità quadratica
        append(pc->info);
        pc=pc->next;
    }

}

```

**Move semantics**

viene utilizzata quando posso "rubare" della memoria

Chiamata solo se trovo un rvalue a cui posso ricavare l'address cioè avere una rvalue refence

**move constructor**

```c++
int_array(int_array&& rhs) : m_data(rhs.m_data), m_size(rhs.m_size){
	rhs.m_data = nullptr;
	rhs.m_size = 0;
}
```

Per una lista

```c++
 list(list&& other) {
        head = other.head;
        tail = other.tail;
        
        other.head = nullptr;
        other.tail = nullptr;   
    }
```

Usando il move assignment operator
```c++
int_array(int_array&& rhs){
	*this = std::move(rhs);
}
```

**move assignment operator**
```c++
int_array& operator=(int_array&& rhs){
	m_data=rhs.m_data;
	m_size=rhs.m_size;
	rhs.m_data= nullptr;
	rhs.m_size= 0;
	return *this;
}
```

Per una lista 
```c++
list& operator=(list&& other) {
        if (this != &other) {
            // Release resources held by this object
            clear();

            // Transfer resources from other object
            head = other.head;
            tail = other.tail;

            // Leave other object in a valid but unspecified state
            other.head = nullptr;
            other.tail = nullptr;
        }
        return *this;
    }
```

Con clear 
```c++
void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }
```

## Operator overloading

Quando ridefinisco il comportamento per operatori standard come operator =

**copy assignment operator**

Quando faccio

```c++
	int a, b;
	a = b
```

chaimato operator= che deve prima eliminare tutti gli elementi persenti nell'oggetto a sinistra dell'assegnamento e fare deep copy come nel copy constructor per copiare b in a 

## operator+=

devo fare append della lista a destra nella lista a sinistra