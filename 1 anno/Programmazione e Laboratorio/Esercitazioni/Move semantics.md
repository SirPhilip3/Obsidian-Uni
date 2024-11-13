---
publish: true
---

Each time a function returns something it returns a temporary object that it's copied when assigned to another value in `main` 

Example :

```c++
#include <iostream>
#include <vector>

std::vector<uint64_t> plus_one(std::vector<uint64_t> const& vec){ // no copy here
	std::vector<uint64_t> new_vec;
	new_vec.reserve(vec.size());
	for(auto x : vec) new_vec.push_back(x+1);
	return new_vec; // returned by value so a copy is performed here
	// the compiler can optimize this copy ( RVO )
}

int main(){
	std::vector<uint64_t> x;
	for (int i=0; i!=100; i++) x.push_back(i);
	x = plus_one(x); // another copy here where the returned object is assigned to x
	return 0;
```

The copy `x = plus_one(x)` is very slow because : 
+ the returned value of `plus_one(x)` is not needed in memory ( temporary object )

To prevent this copy we can just copy the pointer of the temporary object and use it  in `x`

![[Immagine 2023-04-21 151009.png]]

Stealing memory is only fine if we steal it from a **temporary object** ( something that is going to disappeare forever )

_Distinguish between temporary e non-temporary_

Example :

```c++
#include <iostream>

float get_some_float() { return 441.12; }

int main(){
	float b = 3.5; // b = lvalue
	float const* b_ptr = &b;

	float const* other_ptr = &get_some_float();
	/*
	get_some_float() returns a temporary value, it does not have a fixed memory address
	it's address cannot be taken 
	*/
	float other = get_some_float();
	float const* other_ptr = &other;

	return 0;

}
```

**rvalue references** can only be bound to rvalues, or temporary objects

Example : 
```c++
float const&& other = get_some_float();
float&& good_ref = get_some_float();
```

We can detect if an object is **temporary** 

```c++
#include <iostream>
#include <vector>

std::vector<float> get_some_float_vec(){
	std::vector<float> float_vec{1.0, 2.0, 3.0};
	return float_vec;
}

void print_vec(std::vector<float> const& vec){
	for(auto x : vec) std::cout<<x<<" ";
}

void print_vec(std::vector<float> const&&vec){
	for (auto x : vec) std::cout<<x<<" ";
}

int main(){
	std:.vector<float> v = get_some_float_vec();
	print_vec(v); // called 1 function
	print_vec(get_some_float_vec()); // called 2 functon
	return 0;
}
```

## Stealing memory

Also called **move semantics**, to move an object means transferring the ownership of it's underlying data to another object

We have to implement 2 essential patterns
+ **Move constructor**
+ **Move assignment operator**

_Move constructor_

```c++
int_array(int_array&& rhs) : m_data(rhs.m_data), m_size(rhs.m_size){
	rhs.m_data = nullptr;
	rhs.m_size = 0;
}
```

We need to put `rhs.m_data` to `nullptr` because if we do not do this when the scope ends the destructor of `rhs` will be called deleting all the memory pointed by `rhs.m_data`

Example : 
```c++
int main(){
	int_array a(2);
	a.get(0)=1;
	a.get(1)=2;
	// a = {1, 2}

	int_array b = std::move(a);
	// b = {1, 2} using move constructor
}
```

_std::move( )_ is used to indicate that an object may be moved, it just casts an lvalue to an rvalue so that a move constructor can be invoked

_Move assignement operator_

```c++
int_array& operator=(int_array&& rhs){
	m_data=rhs.m_data;
	m_size=rhs.m_size;
	rhs.m_data= nullptr;
	rhs.m_size= 0;
	return *this;
}
```

Esempio :

```c++
int main(){
	int_array a(2);
	a.get(0)=1;
	a.get(1)=2;
	// a = {1, 2}

	int_array b = std::move(a);
	// b = {1, 2} using move constructor

	int_array c(3);
	c.get(0) = 12;
	c.get(1) = 113;
	c.get(2) = 67;
	// c = {12, 113, 67}

	a = std::move(c); 
	// a = {12, 113, 67} using move assignment operator
```

Compacted form of **move contructor** using **move assignment operator**

```c++
int_array(int_array&& rhs){
	*this = std::move(rhs);
}
```

