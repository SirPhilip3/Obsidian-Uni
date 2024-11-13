---
publish: true
---
**C++ streams** is a flow of data into or out of a program, more precisly a sequence of bytes that is read or written

Example : 
`std::cin` input stream
`std::cout` output stream

A **stream** includes a **buffer** , in order to minimize the impact of sending/reading a sequence of chars to/from hardware accumulating them in a small in-memory **buffer**

Example :

Extracting bytes from an input buffer : `std::cin >> x`
Push bytes to an output buffer : `std::cout << x`

![[Immagine 2023-04-13 121554.png]]

## Other streams 

+ `std::istream` : general porpose input stream ( `std::cin` is an example of [istream](https://cplusplus.com/reference/istream/istream/) ) 
+ `std::ostream` : general porpouse output stream ( `std::cout` and `std::cerr` examples of [ostream](https://cplusplus.com/reference/ostream/ostream/) )
+ `std::ifstream` : is an input **file** stream 
+ `std::ofstream` : is an output **file** stream 
+ `std::istringstream` : is an input **string** stream ( [istringstream](https://cplusplus.com/reference/sstream/istringstream/) )
+ `std::ostringstream` : is an output **string** stream ( [ostringstream](https://cplusplus.com/reference/sstream/ostringstream/) ) 

Streams **cannot** be **copied**  

## `std::getline`
[`std::getline`](https://cplusplus.com/reference/string/string/getline/)

Useful to parse a stream  

Example : 
`istream& getline (istream& is, string& str, char delim);`

Extract characters from `is` and stores them into `str` until the delimitation character `delim` is found , or until the end of the stream is `delim` is not found , if `delim` is found the stream then points to the **next character** after `delim`

Example :
```c++
#include <iostream>
#include <fstream>
#include <string> //for getline

int main(){
	std::ifstream ifs("questions.txt");
	std::string line;
	while (std::getline(ifs, line, '\n')){
		std::cout<<"read line is: " << line <<std::endl;
	}
	ifs.close(); // a stream needs to be closed ( closed at the end of a scope )
	return 0;
}
```

## Stream states

+ **good()** : operation succeeded 
+ **eof()** : we hit the end of an input
+ **fail()** : something unexpected happened ( looked for a digit and found a char )
+ **bad()** : something unexpected and serious happened ( e.g. disk error )

If we convert `istream` or `ostream` to bool ( e.g. `if(std::cin)` )  the stream is converted to the value `not fail()`

`good()` = `not eof()` and `not fail()` nad `not bad()`

If we `clear()` the state of the stream then it becomes `good()`


## Write unformatted bytes

To write unformatted data ( single bytes ) to a ostream use : `std::ostream::write` ( [write](https://cplusplus.com/reference/ostream/ostream/write/) )

`ostream& write (const char* s, streamsize n)`

Example : 

```c++
#include <iostream>
#include <vector>
#include <fstream>

int main(){

	std::vector<int> v{23, 145, 12 ,89};
	size_t size = v.size();
	std::ostream f("myfile" , std::ios::binary); // create a binary file
	f.write(reinterpret_cast<char const*>(&size), sizeof(size)); 
	// reinterpret_cast cast size of int in bytes (char) for length of size
	f.write(reinterpret_cast<char const*>(v.data()), size*sizeof(v.front()));
	// v.data() returns pointer to the first element of the vector
	return 0; 
}
```


## Read unformatted bytes

To read unformatted bytes from istream `std::istream::read` ( [read](https://cplusplus.com/reference/istream/istream/read/) )

`istream& read (char* s, streamsize n)`

Example :
```c++
#include <iostream>
#include <fstream>
#include <vector>

int main(){
	std::ifstream f("myfile", std::ios::binary);
	size_t size = 0;
	f.read(reinterpret_cast<char*>(&size), sizeof(size)); // size of vector
	std::vector<int> v;
	v.resize(size);
	f.read(reinterpret_cast<char*>(v.data()), size*sizeof(v.front()));

	for (auto x : v) std::cout<<x<<' ';
	std::cout<<'\n';

	return 0;
}
```


## XML parser

**XML** ( eXtensible Markup Language ) is designed to store data in both human and machine readable format

We want to parse an **XML document** ( read it and check if it is well-formatted ) and extract some information to write to another file
