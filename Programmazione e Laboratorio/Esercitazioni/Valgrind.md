__Valgrind__ helps finding this type of errors :
+ out-of-bounds memory accesses
+ invalid memory allocation requests
+ memory leaks
+ use of unininitialized memory
+ reading/writing memory after it has been freed

Options:
+ __--track-origins=__ : finds the origin of an error in yout program
+ __--leak-check=full__ : to see memory leak in more detail

__Valgrind__ simulates the memory used by a program this causes bad performances, Valgrind is 10x slower than using sanitizers, also being a simulator some problems can look fine for Valgrind

## Examples: 

### Uninitialized memory
```c++
#include <iostream>
int main(){ 
	int x; 
	int y = x * 7;
	std::cout << y << std::endl; 
}
```
```bash
$ g++ hello.cpp -o hello -g 
$ valgrind --leak-check=full ./hello
```

Valgind output:
```bash
Condition jump or move depends on uninitialised value(s)
	at 0x2131239: std::ostreambuf_iterator<char...>
	by 0x324FE34: .....
	by 0x123G322: main (hello.cpp:10)//at line 10 of hello.cpp action on unintialised value
Uninitialised value was created by a stack allocation
	by 0x38247D6: main (hello.cpp:5)//at line 5 the uninitialised value was defined
```

### Reading freed memory
```c++
#include <iostream>
int main() { 
	int* a = new int[10]; 
	delete[] a; 
	std::cout << a[5] << std::endl; 
}
```
```bash
$ g++ hello.cpp -o hello -g 
$ valgrind ./hello
```

Valgind output:
```bash
Invalid read of size 4
	at 0x324237E: main (hello.cpp:11)//invalid read was performed at line 11
  Address 0x45FRE125 is 20 bytes inside a block of size 40 freed
	at 0x324AG59: operator delete[] (void*) 
	by 0x213459: main (hello.cpp:9)//memory was freed at line 9
  Block was allocd at
	at 0x979D987: operator new[](unsigned long)
	by 0x1218FE: main (hello.cpp:7)//memory was allocated at line 7
```

### Out-of-range errors
```c++
#include <iostream>
int main(){ 
	int* a = new int[10]; 
	std::cout << a[10] << std::endl; 
	delete[] a; 
}
```
```bash
$ g++ hello.cpp -o hello -g 
$ valgrind ./hello
```

Valgind output:
```bash
Invalid read of size 4
	at 0x18373B: main (hello.cpp:8) //invalid read at line 8
  Address 0x4efr0we is 0 bites after a block of 40 allocd
	at 0x483C384: operator new[](unsigned long)
	by 0x1092FE: main (hello.cpp:7) //created at line 7	
```

### Memory leaks
```c++
#include <iostream> 
int main(){ 
	int* a = new int[10]; 
}
```
```bash
$ g++ hello.cpp -o hello -g 
$ valgrind --leak-check=full ./hello
```

Valgind output:
```bash
HEAP SUMMARY:
	  in use at exit: 40 bytes in 1 blocks
	total heap usage: 2 allocs, 1 frees, 72,744 bytes allocated

40 bytes in 1 blocks are definitely lost in loss record 1 of 1
	at 0x483C534: operator new[](unsigned long)
	by 0x1234ER: main (hello.cpp:7)//memory not freed initialized at line 7

LEAK SUMMARY:
	definitely lost: 40 bytes in 1 blocks
	indirectly lost: 0 bytes in 0 blocks
	  possibly lost: 0 bytes in 0 blocks
	still reachable: 0 bytes in 0 blocks
		 suppressed: 0 bytes in 0 blocks
```