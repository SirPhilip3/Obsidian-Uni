---
publish: true
---

Ogni qual volta avviene un assegnamento tra 2 tipi diversi C++ svolge un casting (in C++ tutti i tipi sono compatibili) 
Esempio:  
```c++
int a=2; 
double b=3.14 
a=b;
```
in memoria `a=3` -> #Narrowing del dato (perdita di informazioni)