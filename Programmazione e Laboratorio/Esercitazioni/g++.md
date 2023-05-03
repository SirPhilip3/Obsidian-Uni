__g++__ is the compiler for C++ code (standard C++14)

Equivalent to: `gcc -xc++ -lstdc++ -shared-libgcc`

Object files are compiled code (in machine lenguage) from source files, `.o` files do not link together, in order to be used together they need to be linked

Example of generating an executable:
```bash
g++ -c -o foo.o foo.cpp 
g++ -c -o main.o main.cpp 
g++ -c -o bar.o bar.cpp 
g++ -o fubar foo.o main.o bar.o
```

Options: 
+ __-o__ : specify the name of the output
+ __-`I`__ : incude files from different directory ( Example: `g++ Hello.cpp -o Hello -I /home/project/include `)
+ __-c__ : only generates object files
+ __-l__ : links libraries
+ __-L__ : specify where thw libraries are located
+ __-g__ : turns on debugging ( includes the names of functions and variables in the generated machine code )
+ __-Wall__ : turns on most warnings
+ __-Wextra__ : turns on extra warnings
+ __-O__ : turns on optimization
	+ __-O0__ : optimization for compilation time
	+ __-O1__ : optimization for code size and execution time
	+ __-O2__ : ''
	+ __-O3__ : ''
	+ __-Os__ : optimization fore code size
	+ __-Ofast__ : __-O3__ with fast accurate math calculations
+ __-std=c++14__ : specify the c++ standard
+ __-DNDEBUG__ : disable the asserts

## Libraries

Libraries are a collection of object files

__Static libraries__
	Copied into the executable file at compile time
	The whole application needs to be recompiled when something is changed in the library 
	On the other hand makes the code faster sice it does not have to call function outside the executable
	Windows: `.lib`
	Linux; `.a`
__Dynamic libraries__ 
	A collection of files that exist outside of the executable file, so that multiple application can use them without a private copy 
	You only need to recompile the library if you change it, not the entire program
	Windows: `.dll`
	Linux: `.so`