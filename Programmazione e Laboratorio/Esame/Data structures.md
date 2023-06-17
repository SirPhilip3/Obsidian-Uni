## Singly linked list

è utile quando si devono fare molte aggiunte o eliminazioni dalla testa ( se è solo con il pointer alla testa )  poichè se li facessimo con i vector o gli array bisognerrebbe riallocare dello spazio in memoria in qunato negli array per inserire in testa bisogna spostare di 1 elemento a destra tutto il resto dell'array, invece nelle liste basta che aggiungi un nuovo nodo all'inizio modificando dei puntatori

Il problema principale delle liste è spostarsi tra gli elementi infatti ogni volta che abbiamo bisogno di andare al centro della lista devo attraversarla tutta dalla head fino a dove devo arrivare invece con gli array se so l'indice a cui devo accedere basta fare `a[i]` 

Il problema può essere parzialmente risolto aggiungendo un pointer all'elemento precedente di ogni nodo e anche aggiungendo un pointer alla tail , così se devo inserire un elemento in coda non devo attraversare tutta la lista

![[structure-of-a-singly-linked-list.png]]

### Example class :

senza pimpl
```c++
class list_int{

public:
	list_int(); //default constructor
	list_int(const list_int& s); // copy contructor
	~list_int(); // distruttore
	void append(int e);
	void prepend(int e);
	void add(int pos, int e);

private:
	struct cell{
		int info;
		cell* next;
	};
	typedef cell* Pcell;
	Pcell h;
}
```

Con pimpl
```c++

```

### Costruttore

Senza pimpl
```c++
list_int::list_int(){

	head = nullptr;

}
```

Con Pimpl
```c++
list_int::list_int(){

	pimpl = new impl;
	pimpl->head = nullptr;
	
}
```

### Distruttore 

senza pimpl
```c++
list_int::~list_int(){

	cell* pc = head;
	while(pc!=nullptr){
		head=head->next;
		delete pc;
		pc = head;
	}

}
```

con pimpl
```c++
list_int::~list_int(){

	cell* pc = pimpl->head;
		while(pc!=nullptr){
			pimpl->head = pimpl->head->next;
			delete pc;
			pc = pimpl->head;
		}

	delete pimpl;

}
```

### Copy contructor

è chiamato qunado faccio una cosa così :
`list_int list2 = list1`
in questo caso list2 non è stata ancora inizializzata con nessun valore quindi non devo eliminare niente della lista originale però se faccio una cosa del genere :
```c++
list_int list2;
list2.append(324);

list2 = list1; // copy assignment operator called
```

non chiama il copy constructor ma il copy assignment operator che deve eliminare i dati precedentemente presenti nella lista iniziale

senza pimpl
```c++
list_int::list_int(const list_int& s){

	head = nullptr;

	cell* pc = s.head;
	while(pc!=nullptr){
		append(pc->info);
		pc=pc->next;
	}

}
```

con pimpl
```c++
list_int::list_int(const list_int& s){

	pimpl = new impl;
	pimpl->head = nullptr;

	cell* pc = s.pimpl->head;
	while(pc!=nullptr){
		append(pc->info);
		pc=pc->next;
	}

}
```

### Append

![[Single_Link_List_Insert_Append.png]]

senza pimpl
```c++
void list_int::append(int e){
	// creo un nuvo nodo
	Pcell node = new cell;
	node->info = e;
	node->next = nullptr;

	if(head==nullptr){//se la lista è vuota la testa della lista diventa il nuovo nodo
		head = node;
		//tail = node;
	}else{ // altrimenti devo scorrere tutta la lista fino alla fine e mettere il nuovo nodo alla fine 
		Pcell pc = head;
		while (pc->next!=nullptr){
			pc = pc->next;
		}
		pc->next = node;
		/*
		con tail
		tail->next = node;
		tail = node;
		*/
	}
}
```

Alternativa ricorsiva
```c++
void list_int::append(int e){
	append_ric(h, e);
}

void list_int::append_ric(Pcell& head, int e){ // deve essere inserita nella parte privata della classe
	if(head==nullptr){
		head = new cell;
		head->info=e;
		head->next= nullptr;
    }
    else {
		append_ric(head->next, e);
    }
}
```

con pimpl
```c++

```


### Prepend

devo aggiungere un elemento all'inizo

![[image006.gif]]

senza pimpl
```c++
void list_int::prepend(int e){

	Pcell node = new cell;
	node->info = e;
	node->next = head;

	head = node;
}
```

con pimpl
```c++

```

### Inserisci a index

![[Single_Link_List_Insert_Append2.png]]

Qui ci sono dei problemi poichè dobbiamo chiederci se vogliamo inserire l'elemento prima o dopo l'elemento trovato o l'index, questo cambia l'implementazione dell'insert

Devo fermarmi al node precedente all'index che devo inserire

```c++
void list_int::insert(int index, int item) {
    if (index < 0) {
        // Invalid index
        return;
    }

    NodePtr node = new Node;
    node->Item = item;

    if (index == 0) {
        // Insert at the head
        node->Next = Head;
        Head = node;
    } else {
        // Insert at a non-zero index
        NodePtr current = Head;
        for (int i = 0; i < index - 1; i++) {
            if (current == nullptr) {
                // Index out of range
                delete node;
                return;
            }
            current = current->Next;
        }
        node->Next = current->Next;
        current->Next = node;
    }
}
```

### Insert if element found

Inserisci dopo dell'elemento da trovare
```c++
void list_int::insertAfter(int toFind, int toInsert) {
    Pcell current = head;
    while (current != nullptr) {
        if (current->info == toFind) {
            Pcell newNode = new cell;
            newNode->info = toInsert;
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
}
```


Inserisci prima dell'elemento da trovare
```c++
void list_int::insertBefore(int toFind, int toInsert) {
    if (h == nullptr) return;

    if (h->info == toFind) {
	    Pcell newNode = new cell; 
	    newNode->info = toInsert;
	    newNode->next = h;
	    h = newNode;
        return;
    }

    Pcell current = h;
    while (current->next != nullptr) {
        if (current->next->info == toFind) {
		    Pcell newNode = new cell;
			newNode->info = toInsert; 
			newNode->next = current->next; 
			current->next = newNode;
            return;
        }
        current = current->next;
    }
}
```


### Remove a head

Se ho il pointer alla head devo cambiare anche il pointer head 
```c++
void list_int::remove_head(){


}
```

### Remove a tail

Se ho il pointer alla tail devo cabiare anche il pointer tail
```c++
void list_int::remove_tail(){


}
```

### Remove index

```c++
void removeAt(int pos) {
    if (h == nullptr || pos < 0) return;

    if (pos == 0) {
        Node* temp = h;
        h = h->next;
        delete temp;
        return;
    }

    Node* current = h;
    int currentPos = 0;
    while (current->next != nullptr && currentPos < pos - 1) {
        current = current->next;
        currentPos++;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}
```


### Remove if element found

```cpp
void list_int::remove(int toRemove) {
    if (h == nullptr) return;

    if (h->info == toRemove) {
        Pcell temp = h;
        h = h->next;
        delete temp;
        return;
    }

    Pcell current = h;
    while (current->next != nullptr) {
        if (current->next->info == toRemove) {
            Pcell temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }
        current = current->next;
    }
}
```

### Print 

senza pimpl
```c++
void list_int::print(){

	Pcell pc = head;
	while (pc!=nullptr){
		std::cout<<pc->info;
		pc=pc->next;
	}
}
```

con pimpl
```c++
void list_int::print(){

	Pcell pc = pimpl->head;
	while (pc!=nullptr){
		std::cout<<pc->info;
		pc=pc->next;
	}
}
```

## Doubly linked list

è una singly linked list in cui ogni nodo oltre a next ha anche un puntatore a prev

### Costruttore

```c++
list_DL::list_DL(){

	head = nullptr;
	tail = nullptr;

}
```

### Destructor e Copy constructor 

Stessi rispetto alla singly linked list

### Append

```c++
void listDL::append(int e){
	Pcell nuova = new cell;
	nuova->info = e;
	nuova->next = nullptr;
	nuova->prev = tail;

	if(tail!=nullptr){
		tail->next = nuova;
	}else{
		head = nuova;
	}
	tail = nuova;
}
```

### Prepend

```c++
void listDL::prepend(int e){
	Pcell nuova = new cell;
	nuova->info = e;
	nuova->next = head;
	nuova->prev = nullptr;

	if(head!=nullptr){
		head->prev = nuova;
	}else{
		tail = nuova;
	}
	head = nuova;
}
```

### Inserimento

Inserisci prima di un elemento

```cpp
void list_int::insertAfter(int toFind, int toInsert) {
    Pcell current = head;
    while (current != nullptr) {
        if (current->info == toFind) {
            Pcell newNode = new cell;
		    newNode->info = toInsert;
		    newNode->next = current->next;
		    newNode->prev = current;
		    
            if (current->next != nullptr) {
                current->next->prev = newNode;
            } else {
                tail = newNode;
            }
            current->next = newNode;
            return;
        }
        current = current->next;
    }
}
```

Inserimento dopo un elemento

```cpp
void list_int::insertBefore(int toFind, int toInsert) {
    if (head == nullptr) return;

    if (head->info == toFind) { // se lo devo mettere all'inizio
        head = new cell;
        head->info = toInsert;
        head->prev = nullptr;
        head->next = head->next;
        head->next->prev = head;
        return;
    }

    Pcell current = head;
    while (current->next != nullptr) {
        if (current->next->info == toFind) {
            Pcell newNode = new cell;
            newNode->info = toInsert;
            newNode->prev = current;
            newNode->next = current->next;
            
            current->next->prev = newNode;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
}
```

Inserimento a Index

```cpp
void insertAt(int index, int value) {
    if (index < 0) return;

    if (index == 0) {
        Pcell newNode = new cell;
        newNode->info = value;
        newNode->prev = nullptr;
        newNode->next = head;
        
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
        return;
    }

    Pcell current = head;
    int currentIndex = 0;
    while (current != nullptr && currentIndex < index - 1) {
        current = current->next;
        currentIndex++;
    }

    if (current != nullptr) {
        Pcell newNode = new cell;
        newNode->info = value;
        newNode->prev = current;
        newNode->next = current->next;
        
        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
    }
}
```

### Remove a found element

```cpp
void list_int::remove(int toRemove) {
    if (head == nullptr) return;

    if (head->info == toRemove) {
        Pcell temp = head;
        head = head->next;
        
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        
        delete temp;
        return;
    }

    Pcell current = head;
    while (current->next != nullptr) {
        if (current->next->info == toRemove) {
            Pcell temp = current->next; 
            current->next = current->next->next; 
            
            if (current->next != nullptr) { 
                current->next->prev = current; 
            } else { 
                tail = current; 
            } 
            
            delete temp; 
            return; 
        } 
        current = current->next; 
    } 
} 
```

### Remove at index

```c++
void ListDL::remove(int pos){
    if (pos < 0) return;
    
    pcella pc = head;
    while(pc != nullptr && pos>0){
        pc = pc->next;
        pos--;
    }
    
    if(pc != nullptr) {// here we need to delete pc
        if(pc->prev == nullptr) // pc is the head
            head = pc->next;
        else //we have a cell before pc
            pc->prev->next = pc->next;
        if(pc->next == nullptr) // pc is the tail
            tail = pc->prev;
        else // we have a cell after pc
            pc->next->prev = pc->prev;

        delete pc;
    }
}
```

## Liste circolari

### Append e Prepend

Aggiungo sempre come se fosse un'insert sul primo elemento a cui punto poichè non esiste una testa o una coda

```c++
void insert(ListCirc& l, int e){
    ListCirc new_cell = new cella;
    new_cell->info = e;
    if(l!=nullptr){
        new_cell->next = l->next;
        l->next = new_cell;
    }else{
        l->next = new_cell;
        l = new_cell;
    }
}
```

### Print

Per stampare una lista circolare siccome non sappiamo quando incontreremo la fine mettiamo un "paletto" al primo elemento della lista che ci viene passato e iteriamo lungo la sita fino a ritrovare quel nodo

```c++
void print(ListCirc l){
    ListCirc start=l;
    if(l){
        do{
            std::cout<<l->info;
            l=l->next;
        }while (l!=start);
    }
}
```

### Capire se si tratta di una lista circolare o no

Per capire se si tratta di una lista circolare o no uso lo stesso metodo della stampa :
se incontro un nullptr come next pointer allora è lineare se invece incontro il paletto allora è circolare se invece è vuota non posso decidere

```c++
int decide(ListCirc l){ // 0 vuota 1 circolare 2 lineare vuota non so decidere se circolare o lineare
    if(l==nullptr) return 0;
    else {
        ListCirc pc = l;
        do{
            l=l->next;
        }while(l!=nullptr&&l!=pc);
        if(l==nullptr) return 2;
        else return 1;
    }
}
```

### Lista con cappio ( parziale lineare parziale circolare )

Come si fa a determinare la presenza di una chiusura all'interno di una lista

1 metodo uso 3 pointer
1. Pointer a il primo elemento della lista (starter)
2. pointer al secondo elemento della lista (ender)
3. pointer all'inizio della lista

Inizialmente muovo i 2 pointer di 1 entrambi e faccio partire il pointer dall'inzio della lsita se incontra prima il pointer starter rispetto a ender allora non è circolare se invece incontra prima ender allora è circolare es :


```c++
bool ha_cappio(ListCirc l){
    ListCirc A, T, G;
    if(l!=nullptr){
        // lista 1 cella chiusa su se stesso funziona anche se è una lista completamente circolare
        T = l;
        A = l->next;
        bool found = false;
        while (A!=nullptr&&!found)
        {
            G = l;
            while (G!=A&&G!=T)
            {
                G=G->next;
            }
            if (G == A) found = true;
            A = A->next;
            T = T->next;
        }
        return found;
    }
    else
        return true;
}
```

Questo metodo comporta una complessità molto alta un metodo alterantivo è il seguente

![[Image-4-1-522x1024.png]]

## Lista con vector

Per sviluppare delle liste con i vector è necessario sviluppare una codifica adeguata

## Vector e Array

Sono utili quando lo scopo principale del programma è quello di immagazzinare i dati e modificarli ma non l'inserimento di ulteriori dati

