## C++ project directory 

``` Folders
parent_project_folder/ 
|
|—— include/
|
|—— src/
| 
|—— build/
| 
|—— tools/
```

__include__
	contains the header files (function signatures) `.hpp`
__src__
	contains source files (implementation of header files) `.cpp`
__tools__
	contains makefiles etcc
__build__
	contains compilation files `.exe .o`
```ad-note
Each header file should have a corresponding source file, having the same name
```
Additional subdirectories
__test__
	test to convalidate your code
__external__
	contains external dependencies `.dll`

For more info [direcory](https://api.csswg.org/bikeshed/?force=1&url=https:// raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs#tld)

Examples :

"include/myf.hpp"
```c++
int myf(int a, double b);
```
"src/myf.cpp"
```c++
#include "myf.hpp"
```


## Makefile

A __Makefile__ is used to automatize tasks, like , in this case, the building of  a complex application

__Makefile__ is made up of rules, each one of them is made up of :
+ __target__ : name of the action or file you want ot generate
```ad-note
A target is not required to have prerequisites
```
+ __prerequisites__ : file(s) needed as input to generate the target
+ __recipe__ : actions to be performed

Composition:
```bash
<target> : <prerequisites>
<TAB><recipe>
```

To execute the Makefile, type the command `make` in the directory where the Makefile is located
To execute a a specified target type  `make <target>`
