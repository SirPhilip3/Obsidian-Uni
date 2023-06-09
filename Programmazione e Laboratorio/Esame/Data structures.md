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
	}else{ // altrimenti devo scorrere tutta la lista fino alla fine e mettere il nuovo nodo alla fine 
		Pcell pc = head;
		while (pc!=nullptr){
			pc = pc->next;
		}
		pc->next = node;
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

### Remove a head

### Remove a tail

### Remove a index

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

## Vector e Array

Sono utili quando lo scopo principale del programma è quello di immagazzinare i dati e modificarli ma non l'inserimento di ulteriori dati

