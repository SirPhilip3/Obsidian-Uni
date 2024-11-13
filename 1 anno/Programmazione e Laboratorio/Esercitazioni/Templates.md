---
publish: true
---

Helps **abstract the data away** from a class or a function and focus on the algorithms , with templates you can write a generic algorithms that can work on any data type

Example :

A **sorting** routine can work on any data type ( int , float etcc )

**Templates** are recipes to create new classes and/or functions
+ Increases correctness
+ wider range of use for an algorithm

**Templates** can be used in :
+ Functions
+ Classes

## Function template

Example : 

```c++
#include <iostream>

template <typename T> // typename indicates a generic type ( class is the same )
T max(T const& x, T const& y){
	return x > y ? x : y;
}

template <typename Type1, typename Type2> // templated function
bool are_equal(Type1 const& f, Type2 const& g){
	return f==g;
}

int main(){
	auto x = max<int>(3, 12);
	auto y = max<double>(3.4, 0.5);

	if (are_equal<int, double>(5, 5.0))  std::cout<<"SAME"<<std::endl;

	return 0;
}

```

## Class template

Example :

```c++
#include <iostream>

template <typename T> // the type needs to have defined operator++ and operator<<
struct my_container {
	my_container();
	my_container(T const& val) : m_val(val) {}
	void increment() { ++m_val; }
	T const& get() const { return m_val; }

private :
	T m_val;	

};


struct my_int_class {
	my_int_class(int val) : m_val(val) {}
	void operator++() { m_val += 3; }
	int get() const { return m_val }

private : 
	int m_val;
};

std::ostream& operator<<(std::ostream& os, my_int_class const& other){
	os<<other.get();
	return os;
}
```

```c++
int main(){
	my_container<uint64_t> a(2893);
	a.increment();
	a.increment();
	std::cout<<a.get()<<std::endl;

	my_container<my_int_class> b(12);
	b.increment();
	b.increment();
	std::cout<<b.get()<<std::endl;

	std::pair<int, double> p{44, 898.23};
	my_container<std::pair<int, double>> c(p); // compilation error operator++ not supported
	c.increment():

	return 0;
}
```


A class defined from a template class by providing a specific **typename** is called **specialization** , the compiler generates different **specialization** 

Example :

```c++
// compiler generates this code for my_container<float>
struct my_container_float002__{
	my_container_float002__ (float const& val) : m_val(val) {}
	void increment() { ++m_val; }
	float const& get() const { return m_val; }

private :
	float m_val;
};
```

**Templates** work at the compiler level :
+ The compiler ensures type safety
+ The compiler could provide optimized specialization for different types

Abusing templates generates lot's of code slowing down compile time and creating big object files


We can have templated class with member function templated with different template members

Example :

```c++
template <typename T>
struct m_conatiner{
	m_container() : m_data(nellptr), m_size(0) {}
	~m_container() {
		if(m_data) delete[] m_data;
	}

	template <typename Z>
	void build_from(Z const* items, uint64_t num_items){
		m_size = num_items/2;
		m_data = new T[m_size];
		for(uint64_t i = 0; i!=m_size; i++ , items+=2){
			m_data[i].first = *items;
			m_data[i].second = *(items+1);
		}
	}

	void print() const {
		for (uint64_t i = 0; i!=m_size; ++i) std::cout<<m_data[i];
	}

private :
	T* m_data;
	uint64_t m_size;
}
```

T needs to be a type that has first and second as attributes and also needs to be defined `operator<<` for that type

```c++
typedef std::pair<int ,int> pair_t;

std::ostream& operator<<(std::ostream& os, pair_t const& p){ 
	os << "(" <<p.first<<","<<p.second<<")"; // I put in the output stream os (first..)
	return os;
}
```

`pair_t` has defined the first and second attributes and the `operator<<`

```c++
int main(){
	m_container<pair_t> x; // T is pair_t 
	{
		std::vector<uint32_t> vec{1, 2, 2, 3, 3, 4, 4, 5}; // Z is uint32_t
		x.build_from(vec.data(), vec.size());
	}
	x.print()
	return 0;
}
```

## Non-type parameters for templates

A **template** can also be just a constant known at compile time

Example :
```c++
#include <iostream>
template <class T = char, int N = 100> // int non-type parameter, you can only use int
struct mysequence {
	void set(int i, T value) {m_memblock[i] = value; }
	T get(int i) {return m_memblock[i]; }

private :
	T m_memblock[N];
}

int main(){
	mysequence<int , 5> myints;
	mysequence<float , 5> myfloats;
	myints.set(0 , 100);
	myfloats.set(3 , 3.1416);
	std::cout<<myints.get(0)<<"\n";
	std::cout<<myfloats.get(3)<<"\n";

	mysequence<> mychars; // utilize default types char, N = 100

	return 0;
}
```


## Template specialization

Sometimes some specific types needs a different implementation, it's possible to have a **template specialization**

Example :

```c++
#include <iostream>

template <typename T>
void print(T const& x){
	std::cout<<"==templated print function called=="<<std::endl;
	std::cout<<x<<std::endl; // pair has no supported operator<< compilation error if typename = pair
}

template <> // fully specialized function
void print(std::pair<int , int> const& x){ 
	std::cout<<"==template-specialization print function called=="<<std::endl;
	std::cout<<"first :"<<x.first<<"second"<<x.second<<std::endl;
}

int main(){
	double x = 3.45;
	int y = 3;
	std::pair<int , int> p{232, 34};
	print(x);
	print(y);
	print(p); // uses specialized function
	return 0;
}
```


We have `my_pair` container and we want to implement a function `get(i, p)` which returns the first value if `i=0` or the second if `i=1`

```c++
template <typename FirstType, typename SecondType>
struct my_pair{
	my_pair(FistdType f, SecondType s) : first(f), second(s) {}
	FirstType first;
	SecondType second;
}
```


```c++
template <typename MyPair>
??? get(int i, MyPair const& p){ 
	if(i==0){
		return p.first;
	}else if (i==1){
		return p.second;
	}else ??? 
}
```

We do not know what **type** we should return, it depends on the value of `i`

1. First we need to let `my_pair` to explose the type of `first` and `second`, because there is no way to access the type from a template type list, we need to use an explicit `typedef` to expose them

```c++
template <typename FirstType, typename SecondType>
struct my_pair{
	typedef FirstType first_type;
	typedef SecondType second_type;
	
	my_pair(FistdType f, SecondType s) : first(f), second(s) {}
	
	FirstType first;
	SecondType second;
}
```

2. We declare a `getter`  structure and implement two specialization for : `i=0` and `i=1` ( partial specialization , only `i` is fully specialized )

```c++
template <int i, typename MyPair>
struct getter;

template <typename MyPair>
struct getter<0, MyPair>{
	typedef typename MyPair::first_type return_type;
	static return_type get(MyPair const& p) { return p.first; }
}

template <typename MyPair>
struct getter<1, MyPair>{
	typedef typename MyPair::second_type return_type;
	static return_type get(MyPair const& p) { return p.second; }
}
```

3. Now we can write :

```c++
int main(){
	typedef my_pair<int , double> MyPair;
	MyPair p(23, 44.543);

	int first = getter<0, MyPair>::get(p);
	double second = getter<1, MyPair>::get(p);
	std::cout << first << std::endl;
	std::cout << second << std::endl;

	return 0;
}
```

