
An **iterator** is an object that points to an element inside a container , can be used to read the element and/or modify it

They provide an **interface** to access data inside a container abstractnig the details of how the container is implemented

Example :

![[Immagine 2023-04-27 121418.png]]

+ Two different implementation of a `list<var>` 
	+ using **singly-linked list**
	+ using **array**
+ Make the difference invisible to the clients of our container via **iterators**

`it` is an iterator

![[Immagine 2023-04-27 121723.png]]

Using **iterators** we can write :
```c++
list<double> x;
// ... fills x
for (iterator it = x.begin(); it != x.end(); ++it){
	std::cout<<*it<<std::endL;
}
```

`++it` increments the iterator to point to the next element
`x.begin()` returns an iterator pointing to the **first** element
`x.end()`  returns an iterator pointing to **one-past** the last element
`*it` dereference the iterator to read/write the element

Or using a **range-based** for loop :
```c++
list<double> x;
// ... fills x
for (double val : x){
	std::cout<<val<<'\n';
}
```

Or :
```c++
list<double> x;
// ... fills x
iterator it = x.begin();
iterator end = x.end();
*it = 3; ++it; // modify first element and advance to the next
*it = 5; ++it; // modify second element and advance to the next
if(it==end) std::cout<<"no more elements"<<std::endl; 
// test if we reached the end of the container 
```

All containers in the **standard template library** ( **STL** ) expose methods to create iterators pointing to their elements , the algorithms does not have to know the implementation of the container, it's sufficient that it has the capability to read/write the elements in a container

Example :

```c++
std::vector<int> v{3, 6, 1, -34, 4, 1};
std::sort(v.begin(), v.end());

list<float> l;
l+=0; l+=1; l+=3;
std::fill(l.begin(), l.edn(), 3.14); // fills from beginning to end l with 3.14
```

## Iterator types

+ **Input** iterator : it can scan the container ( in forward direction ) only once and cannot modify the element it points to
+ **Output** iterator : it can scan the container ( in forward direction ) only once and cannot read the element it points to but you can modify it
+ **Forward** iterator : it can scan the container forward as many times as we want and can read/write the element it points to
+ **Bidirectional** iterator : same as previous one but it can scan in both forward and backward direction
+ **Random access** iterator : same as previous one but can also jump to a middle position ( access not necessarily sequential )
+ **Contiguos** iterator : same as previous one but with the property that logically adjacent elements are also physically adjacent in memory

![[Immagine 2023-04-27 125931.png]]

Each iterator type in category _i_ is also an iterator of type in category _i+1_

## Iterator class

```c++
template<typename val>
struct list{

	struct iterator{
	
	}
	
}
```

The class `iterator` is a private class of the container because we create an iterator over the element of a specific container

```c++
template<typename val>
struct list{

	struct iterator{
		using iterator_category = std::forward_iterator_tag;
		using value_type = val;
		using pointer = val*;
		using reference = val&;
	}
	
}
```

Definition of properties of the **iterator** , it's required by the lenguage to make it possible to use **STL** algorithms in a custom container

```c++
template<typename val>
struct list{

	struct iterator{

		using iterator_category = std::forward_iterator_tag;
		using value_type = val;
		using pointer = val*;
		using reference = val&;

		iterator(node* ptr); // default constructor of iterator object
		
		reference operator*() const; // operator dereference 
		pointer operator->() const; // useful for structs
		// const because they do not modify the pointer
		iterator& operator++() // prefix ++
		iterator operator++(int /*dummy*/) // postfix ++
		bool operator==(iterator const& rhs) const;
		bool operator!=(iterator const& rhs) const;
		
		private:
			node* m_ptr; // iterator will manipulate a pointer to a list node
	}

	// ability to create an iterator to the first and to one-past the last element
	iterator begin();
	iterator end();
	
}
```

## Iterator implementation

```c++
// default constructor
template<typename val>
list<val>::iterator::iterator(node* m_ptr) : m_ptr(ptr){}

// dereference
template<typename val>
typename list<val>::iterator::reference list<val>::iterator::operator*() const{
    return m_ptr->VAL;
}

template<typename val>
typename list<val>::iterator::pointer list<val>::iterator::operator->() const{
    return &(m_ptr->VAL);
}

// prefix increment
template<typename val>
typename list<val>::iterator& list<val>::iterator::operator++() {
    m_ptr = m_ptr->next;
    return *this;
}

// postfix increment
template<typename val>
typename list<val>::iterator list<val>::iterator::operator++(int) {
    iterator tmp = *this;
    m_ptr = m_ptr->next;
    return tmp;
}

// operator==
template<typename val>
bool list<val>::iterator::operator==(iterator const& rhs) {
    return m_ptr==rhs.m_ptr;
}

// opertor !=
template<typename val>
bool list<val>::iterator::operator!=(iterator const& rhs) {
    return !(*this==rhs);
}

// begin()
template<typename val>
typename list<val>::iterator list<val>::begin() {
    // iterator it(m_front)
    // return it;
    return {n_front};
}

// end()
template<typename val>
typename list<val>::iterator list<val>::end() {
    return {n_back->next} ;
}
```

## Const_iterator class

`iterator` class that can only read the elements without modifying them

Example usage :

```c++
template <typename val>
bool list<val>::operator==(list<val> const& rhs) const {
...
}
```

`const_iterator` is diffrent from `const iterator`
+ `const_iterator` is a class 
+ `const iterator` is the class iterator declared const so it can't be modified

### Implementation 

```c++
struct const_iterator{
	using iterator_category = std::forward_iterator_tag;
	using value_type =const val;
	using pointer = val const*;
	using reference = val const&
	
	// constructor
	const_iterator(node* ptr);
	
	const_iterator& operator++(); // prefix increment
	const_iterator operator++(int); // postfix
	reference operator*() const;
	pointer operator->() const; 
	bool operator==(const_iterator const& rhs) const;
	bool operator!=(const_iterator const& rhs) const;

	private :
		node const* m_ptr;
};
const_iterator begin() const; // const because the compiler will call this if the constest is cosnt
const_iterator end() const;
```

```c++
template<typename val>
list<val>::const_iterator::const_iterator(node* m_ptr) : m_ptr(ptr){}

template<typename val>
typename list<val>::const_iterator::reference list<val>::const_iterator::operator*() const{
    return m_ptr->VAL;
}

template<typename val>
typename list<val>::const_iterator::pointer list<val>::const_iterator::operator->() const{
    return &(m_ptr->VAL);
}

template<typename val>
typename list<val>::const_iterator& list<val>::const_iterator::operator++() {
    m_ptr = m_ptr->next;
    return *this;
}

template<typename val>
typename list<val>::const_iterator list<val>::const_iterator::operator++(int) {
    const_iterator tmp = *this;
    m_ptr = m_ptr->next;
    return tmp; // return element prima
}

template<typename val>
bool list<val>::const_iterator::operator==(const_iterator const& rhs) const {
    return m_ptr==rhs.m_ptr;
}

template<typename val>
bool list<val>::const_iterator::operator!=(const_iterator const& rhs) const {
    return !(*this==rhs);
}
```

Example of code using a const_iterator :

```c++
template <typename val>
bool list<val>::operator==(list<val> const& rhs) cosnt{
	auto itr1 = begin();
	auto itr2 = rhs.begin();
	while(itr1!=end() or itr2!=rhs.end()){
		if((itr1==end() and itr2!=rhs.end()) or (itr1!=end() and itr2!=rhs.end()) or (*itr1!=*itr2) return false;

		itr1++;
		itr2++;
	
	}
	return true;	
}
```


### Invalidation

What heppends to an `iterator` created by a container if the memory of the container changes : 
The `iterator` will point to garbage and becomes **invalid**

The memory held by a container can change :
+ inserting / removing elements ( after memory re-allocation )
+ the container is move assigned
+ the container is destroyed

In general _an iterator is invalid of the memory for the container it was created for is changed_
When memory is changed depends on the type of data structure that is implemented by the container so to know if the `iterator` is valid or not requires knowledge also of the implementation of the container

So in general it's good practice to _avoid mixing iteration with operations that can cause memory re / de-allocation_

Example : 
```c++
std::vector<int> v{3, 6, 1, -34, 4, 1};
auto it_v = v.begin();
v.insert(it_v, 5);
std::cout<<*it_v<<std::endl;
```

A memory re-allocation happens when inserting 5 at the beginning of the vector v so `iterator it_v`  is invalid after the `insert`

Example :
```c++
list<float> l;
((l+=0)+=1)+=3;
auto it_l = l.begin();
l.push_front(-1);
l.push_back(4);
for(; it_l!=l.end() ; ++it_l ) std::cout<<*it_l<<' ';
std::cout<<std::endl;
```

`it_l` is still valid after `push_front` and `push_back` , beacuse the memory pointed by `it_l` has not changed , it now points to 1 element after the start of `l`

Example : 
```c++
list<float> l, g;
((l+=0)+=1)+=0;
(g+=3)+=4;
auto it_l = l.begin();
l = std::move(g);
for ( ; it_l != l.end() ; ++it_l ) std::cout<<*it_l<<' ';
std::cout<<sdt::endl;
```

After `g` is moved into `l` , the memory of `l` has changed rending `it_l` invalid



---
Variabili iteratori quando un container cambia es inserisco nuovi elementi
iterator punta a garbage

nessuna regola che ci dice se un iteratore è valido o no solo se la memoria è cambiata
implica conoscenza su implementazione del contenitore (come memoria viene gestita)

In gerale non possiamo saperlo, in generale non utilizzare iteratori con costrutti che modificano il contenitore

non invalida iteratore pushback e pushfront
nel nostro conainer non modifico la memoria non avvinene reallocazione
si perde quello di pushfront























---
# Iterator class
to make the implementation of a class transparent to the user
oggetto iteratore che punta ad un elemento 

chi usa struttura dati deve avere un interfaccia semplice per interagire con la data structure

```c++
for (double val : x) // x nome dell'iteratore
```

Usata solo se il contenitore x ha iteratori implementati

ultimo elemento sempre escludo end ritorna un puntatore all'elemento dopo la fine del contenitore

std::fill riemepie il contenitroe con un valore 
tutto a 3.14 etcc

passo range di elementi che voglio che venghino modificati non obbligatorio begin e end

Iteratore deve conoscere i dettagli del contenitore implementato nella parte pubblica
struct iterator ( sotto classe del container )

per utilizzare classe con stl algorithms devo dire di che tipologia l'iteratore è

iterator wrapper attorno ad un puntatore

it ++ non è val incrementato , ritorna il valore prima dell'incremento -> ritorna iterator

```c++
iterator(node* ptr); // const manipola puntatore 

// -> (*it).

// const non manimola il pointer della struct
// se non modificano il pointer m_ptr const
reference operator* // operator dereference
pointer operator-> // utile se fosse struttura con dei campi posso scrivere it->first, it->s

```


