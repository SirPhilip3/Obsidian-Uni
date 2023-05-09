The **Standard Template Library** is a C++ framework consisting of **template-based** classes and algorithms that implements the mostly used data-structures and common tasks

Composed of : 
+ 16 containers ( data structures )
+ 90 algorithms
+ other utilities

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

per custom cmoparator
una calssecustom con una funzione bool operator()
devo dire quando x deve essere considerato minore di y
x deve venire prima ritorna true altrimenti torna false

[] funzione anonima