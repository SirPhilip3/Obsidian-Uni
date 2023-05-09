The **Standard Template Library** is a C++ framework consisting of **template-based** classes and algorithms that implements the mostly used data-structures and common tasks

Composed of : 
+ 16 containers ( data structures )
+ 90 algorithms
+ other utilities

Goals : 
+ **Generic Programming** : code once re-use many times ( increases correctness )
+ **Open-Closed Principle ( OCP )** : Containers / Algorithms should be open for extensions but closed for modification so extend the behaviour of a component without modifying its source code

Examples :

`std::sort` can be used with integers , floats , custom structs independently ; `sort` also accepts a custom method for sorting
`std::vector` is only one vector implementstion that can be used with any **template**

## STL model

![[Immagine 2023-05-09 112155.png]]

**Iterators** are used to link data structures ( container ) and algorithms that interacts with the data so that the algorithm dosen't require the knowledge of how a container is implemented ( it works on **iterator** , pointers ) 

Esempi : 

### [`std::find`](https://cplusplus.com/reference/algorithm/find/)

`template <typename Iterator, typename T>`
`find( Iterator First , Interator Last , const T& val )`

It returns an iterator to the first element in the range (`first, last`) that compares equal to _val_ . If no elements compare it returns `last` 

The function uses the `opertator==` to compare the individual elements , this needs to be defined in the container that is called with `std::find`

## Containers

A **container** is an holder object that stores a _collection_ of other objects that are implemented as **class templates** 
The **container** manages the storage space for its elements and provides funciotns to access them, directly or with an _iterator_

3 types of **containers**
+ **sequential**
	+ vector
	+ deque
	+ list
	+ array
	+ forward_list
+ **adaptors**
	+ stack
	+ queue
	+ priority_queue
+ **associative**
	+ set
	+ multiset
	+ map
	+ multimap
	+ unordered_set
	+ unordered_multiset
	+ unordered_map
	+ unordered_multimap

### Sequential

#### [`std::array`](https://cplusplus.com/reference/array/array/)

#### [`std::vector`](https://cplusplus.com/reference/vector/vector/)

#### [`std::deque`](https://cplusplus.com/reference/deque/deque)

#### [`std::forward_list`](https://cplusplus.com/reference/forward_list/forward_list/?kw=forward_list+)

#### [`std::list`](https://cplusplus.com/reference/list/list/)

### Adaptors

#### [`std::stack`](https://cplusplus.com/reference/stack/stack/)

#### [`std::queue`](https://cplusplus.com/reference/queue/queue)

#### [`std::priority_queue`](https://cplusplus.com/reference/queue/priority_queue/?kw=priority_queue+)

### Associative

#### [`std::set`](https://cplusplus.com/reference/set/set)

#### [`std::map`](https://cplusplus.com/reference/map/map)

#### [`std::unordered_set`](https://cplusplus.com/reference/unordered_set/unordered_set/?kw=unordered_set)

#### [`std::unordered_map`](https://cplusplus.com/reference/unordered_map/unordered_map/?kw=unordered_map+)

## Algorithms

#### [`std::sort`](https://cplusplus.com/reference/algorithm/sort/?kw=sort)

std::find deve avere definito operator== 

sequenziali in modo continuo in memoria ( modellano una sequenza )

deque std::vector sia push back che push front

stoull string to unsigned long long  argv[0] nome programma

priority queue 
ordinamento custom

tipo elementi class T

class compare per custom ordinamento
default std::less
elementi sono estratti dal back del container che è il top della priority queue top = last in
se non specifichi parametri allora da maggiore a minore 

con std:: greater dal più piccolo a maggiore

per custom comparator
una calssecustom con una funzione bool operator()
devo dire quando x deve essere considerato minore di y
x deve venire prima ritorna true altrimenti torna false

[] funzione anonima 