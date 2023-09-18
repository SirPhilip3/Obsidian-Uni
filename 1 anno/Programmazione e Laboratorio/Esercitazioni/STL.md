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

Data is stored in a sequential way

---
Random access : fast
other operations : slow

#### [`std::array`](https://cplusplus.com/reference/array/array/)

`template <typename T, size_t N> class array;`

Array are fixed-size sequenced containers , they hold a specific number of elements ordered in a linear sequence. It's a _wrapper_ for an ordinary array

#### [`std::vector`](https://cplusplus.com/reference/vector/vector/)

`template <typename T, class Alloc = allocator<T>> class vector`

Vectors are like arrays but theyr size can change dynamically , with their storage in memory handled automatically by the container

#### [`std::deque`](https://cplusplus.com/reference/deque/deque)

`template <typename T, class Alloc = allocator<T>> class deque`

**Deque** is a Double Ended queue : they are vectors that can be expanded in both directions

--- 
Random access : slow
other operations : fast

#### [`std::forward_list`](https://cplusplus.com/reference/forward_list/forward_list/?kw=forward_list+)

`template <typename T, class Alloc = allocator<T>> class forward_list`

They are implemented as _singly-linked list_ , storage space is fragmented , the order of the sequente of objects is implemented via pointers : each element has a pointer to the next element in the sequence 

#### [`std::list`](https://cplusplus.com/reference/list/list/)

`template <typename T, class Alloc = allocator<T>> class list`

List containers implemented using _doubly-linked list_

### Adaptors

They are wrapper for other data structures to give them a specific set of functions to access theyr elements

Here i can use as data structures to be conained : _vector, deque, list_

#### [`std::stack`](https://cplusplus.com/reference/stack/stack/)

`template <typename T, class container = deque<T>> class stack`

LIFO ( Last In First Out ) policy
push/pop are fast becuase they are always performed on the same side

#### [`std::queue`](https://cplusplus.com/reference/queue/queue)

`template <typename T, class container = deque<T>> class queue

FIFO ( First In First Out ) policy
push/pop are fast becuase they are always performed on the same side

#### [`std::priority_queue`](https://cplusplus.com/reference/queue/priority_queue/?kw=priority_queue+)

Custom policy ( the standard policy is to use less , so the smaller object is at the bottom of the queue, the bigger object is extracted first from the queue ) 
push/pop moderatly fast

Example : 

```c++
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

temprate <typename T>
struct even_comparator{
	bool operator()(T const& x, T const& y){ // need to compare 2 element
		// return true if a before b  
		if(x%2==0){
			if(y%2==0) return x<y;
			return true;
		}
		if(y%2==1) return x<y;
		return false;
	}
}


template <typename PriorityQueue>
void print(PriorityQueue& pq, int N) {
	for (int i = 0; i < N; ++i){
		std::cout<<pq.top()<<" ";
		pq.pop();
	
	}
}

int main(){
	int vec[]= {0, 23, 1, 4, 12, 5, 8, 11};
	int N = sizeof(vec) / sizeof(int);
	std::cout<< "N: "<< N<< std::endl;
	{
		std::priority_queue<int> pq(std::begin(vec), std::end(vec));
		print(pq, N);
	}
	{
		std::priority_queue<int, std::vector<int>, std::greter<int> >
			custom_pq1;
		custom_pq1 pq(std::begin(vec), std::end(vec));
		print(pq, N);
	}
	{
		 std::priority_queue<int, std::vector<int>, even_comparator<int> >
			custom_pq2;
		custom_pq1 pq(std::begin(vec), std::end(vec));
		print(pq, N);	
	}
	return 0;
}

```

Instead of declaring a new class `even_comparator`  with only a function ( it describes how the elements need to be sorted ) we ca declare it inside the declaration of `priority_queue` with an anonymous function with this declaration :
```c++
std::priority_queue<int, std::vector<int>, 
						[](T const& x, T const& y){ 
							if(x%2==0){
								if(y%2==0) return x<y;
								return true;
							}
							if(y%2==1) return x<y;
							return false;
						} >
```

### Associative

#### [`std::set`](https://cplusplus.com/reference/set/set)

#### [`std::map`](https://cplusplus.com/reference/map/map)

Based on **Binary search tree** ( balanced )

Insert / delete : moderatly fast
range queries : fast

#### [`std::unordered_set`](https://cplusplus.com/reference/unordered_set/unordered_set/?kw=unordered_set)

#### [`std::unordered_map`](https://cplusplus.com/reference/unordered_map/unordered_map/?kw=unordered_map+)

Based on [hash table](https://en.wikipedia.org/wiki/Hash_table#:~:text=A%20hash%20table%20uses%20a,the%20corresponding%20value%20is%20stored)
Insert / delete : fast
range queries : not supported

## Algorithms

[`#include <algorithm>`](https://cplusplus.com/reference/algorithm/) 

Example :

#### [`std::sort`](https://cplusplus.com/reference/algorithm/sort/?kw=sort)

```c++
#include <iostream>
#include <vector>
#include <functional> // used for lexicographical_compare

struct employee{
	employee(std::string const& n , float s) : name(n) , salary(s) {} // default contructor
	void print(){
		std::cout<< name << salary <<"\n";
	}

	std::string name;
	float salary;
}

int main(){
	int n=0;
	std::cin>>n;

	std::vector<employee> employees;
	employees.reserve(n);

	std::string name;
	float salary;
	for(int i=0; i<n, ++i){
		std::cin>>name;
		std::cin>>salary;

		employee e(name , salary);
		employees.push_back(e);
	}

	std::sort(employees.begin(), employees.end(), 
				[](employee const& x, employee const& y) { // custom sorting
					return x.salary >= y.salary; // in ordine di salario crescente
				}
	);

	for(auto const& e: employees) e.print();
	return 0;
}

```


Appunti :

argv[0] nome programma , il dato da  terminale in argv[1]
