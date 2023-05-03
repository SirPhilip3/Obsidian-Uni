
## For/While

In C 
```c++ 
while(cond) == for(; cond; )
```

In C++
Il ciclo for consiste di tre clausole: l’inizializzazione, la condizione di permanenza, l’espressione di iterazione. Nell’espressione di iterazione tipicamente modifichiamo il valore delle [[Variabili]] che compaiono nella condizione. L’uso appropriato del ciclo for prevede che nessuna delle [[Variabili]] che compaiono nella condizione siano alterate all’interno del corpo del ciclo. In altre parole, le iterazioni devono essere governate soltanto dalle tre clausole che compongono l’intestazione del ciclo. Il for inoltre termina in tutti i casi, ciò è garantito dall'intestazione del ciclo

non viene utilizzato break, continue, goto poichè verrà utilizzzato il paradigma della [Structured programming](https://en.wikipedia.org/wiki/Structured_programming) , nella quale non vengono utilizatti (per chiarità del codice)

**Regola di utilizzo del While**
- `while` quando il ciclo viene eseguito 0 o più volte 
- `do while` quando il ciclo viene eseguito 1 o più volte

## Invariante di ciclo

```c++
int v[20];
/*legge v*/
int n;
/*legge n*/
/*v contiene il valore 5?*/

bool resp = false;
int i=0;
while(i<20&&!resp){
	if(v[i]==n)
		resp==true;
	i++;
}

if(resp)//alternativamente controllo di i (se <20 n è presente)
	cout<<"presente";
else 
	cout<<"non presente";
```

**Spiegazione**
Scorro il vettore `v[20]` fino a `i` , se la prima parte del vettore contiene `n` avrei fermato il ciclo altrimenti continuo a cercare in `i+1` ; ciò risulterà vero per ogni `i`
L'*invariante di ciclo* è una propietà vera immediatamente prima dell'esecuzione del ciclo e durante tutto il ciclo; in questo caso è `resp` ; infatti all'inizio del ciclo, ossia quando non ho controllato nessun elemento di `v[20]` , `resp=false` in quanto non ho trovato 5; ad un punto `i` del ciclo `resp` risulterà ancora vera poichè rispecchierà se `n` è stato trovato o meno.

```c++
int a, b;
//leggi a , b

while(a!=b){
	if(a>b)
		a=a-b;
	else
		b=b-a;
}

cout<<a;
```
Invariante di ciclo = MCD

```c++
int v[20];
/*leggi v*/
int max=v[0];
for(int i=0; i<20; i++){
	if(v[i]>max)
		max=v[i];
}

cout<<max;
```

Invariante del ciclo = `max`: `max` è sempre l'elemento più grande nell'array compreso tra 0 ed un qualunque `i` 