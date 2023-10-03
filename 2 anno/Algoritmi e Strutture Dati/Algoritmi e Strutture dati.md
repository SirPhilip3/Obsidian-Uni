# 20/09/2023

## Definizioni

+ **Algoritmo corretto**
	Un algoritmo si dice corretto se per ogni input si ferma e da in output il risultato corretto ( si dice che l'algoritmo risolve il problema computazionale )
+ **Complessità computazionale** 
	.................

Esempio : 

## Calcolo numeri di Fibonacci

Definizione :
$$F_n = \begin{cases} 1 &\text{if } n = 1&\text{or} &n=2  \\ F_{n-1} + F_{n-2} &\text{if } n\geq3 \end{cases}$$

### Fib1

Definizione attraverso la *sezione aurea*
Equazione fondamentale : 
$$x^2=x+1$$
$$x^2-x-1=0$$
$$x_{12}=\frac{1\pm \sqrt{5}}{2}$$
$$x_1\simeq1,618 = \intop$$
$$x_{2}\simeq -0,618 =\oint$$
I numeri di *Fibonacci* possono essere calcolati con $\oint$ e $\intop$  
$$F_n=\frac{1}{\sqrt{5}}\cdot\Bigg(\intop^n-\oint^n\Bigg)$$
Sviluppiamo un algoritmo che sfrutti queste formule :

```Fib1(int n) -> int```
	```return``` $\frac{1}{\sqrt{5}}\cdot(\intop^n-\oint^n)$

Dim *correttezza* per **induzione** :
#### Casi Base : 
+ $n=1$ 
	$$F_1=\frac{1}{\sqrt{5}}\cdot\Bigg(\intop-\oint\Bigg)$$
	$$\frac{1}{\sqrt{5}}\cdot\Bigg(\frac{1+\sqrt5}{2}-\frac{1-\sqrt5}{2}\Bigg)$$
	$$\frac{1}{\sqrt{5}}\cdot\Bigg(\frac{2\sqrt5}{2}\Bigg)=1$$
+ $n=2$
	$$F_2=\frac{1}{\sqrt{5}}\cdot\Bigg(\intop^2-\oint^2\Bigg)$$
	$$\frac{1}{\sqrt{5}}\cdot\Bigg(\frac{1+5+2\sqrt5}{2}-\frac{1+5-2\sqrt5}{2}\Bigg)$$
	$$\frac{1}{\sqrt{5}}\cdot\Bigg(\frac{4\sqrt5}{4}\Bigg)=1$$

Siccome $F_1$ e $F_2$ sono equivalenti ai primi 2 numeri di *Fibonacci* i casi basi sono dimostrati

#### Passo Induttivo

**Ipotesi Induttiva** : Assumiamo che la fromula di Binet sia vera per ogni $n-1$

Quindi :
$$\forall k \le n-1 : F_{k}= \frac{1}{\sqrt5}\cdot\Bigg(\intop^k -\oint^k\Bigg)$$
$$\text{Per definizione} \space F_k=F_{n-1}+F_{n-2}$$
$$\text{Quindi}\space \space F_k=\frac{1}{\sqrt5}\cdot\Bigg(\intop^{n-1}-\oint^{n-1}\Bigg)+\frac{1}{\sqrt5}\cdot\Bigg(\intop^{n-2}-\oint^{n-2}\Bigg)$$
$$\frac{1}{\sqrt5}\cdot\Bigg(\intop^{n-1}-\oint^{n-1}+\intop^{n-2}-\oint^{n-2}\Bigg)$$
$$\frac{1}{\sqrt5}\cdot\Bigg[\Bigg(\intop^{n-1}+\intop^{n-2}\Bigg)-\Bigg(\oint^{n-1}+\oint^{n-2}\Bigg)\Bigg]$$
$$\text{Ora la formula precedente è molto simile a ciò che vogliamo dimostrare dobbiamo solo verificare che :}$$
$$\intop^n = \intop^{n-1}+\intop^{n-2}$$
$$\oint^n=\oint^{n-1}+\oint^{n-2}$$
$$\text{Ricordandoci che la formula ( ossia la sezione aurea ) per determinare $\oint$ e $\int$ è :}$$
$$x^2= x+1$$
$$\text{Possiamo quindi ricavarla semplicemente dividento tutto per $\oint^{n-2}$ e $\int^{n-2}$}$$
$$\frac{\intop^{n}}{\int^{n-2}} = \frac{\intop^{n-1}}{\int^{n-2}}+\frac{\intop^{n-2}}{\int^{n-2}}\implies \int^2=\int +\space 1$$
$$\frac{\oint^{n}}{\oint^{n-2}} = \frac{\oint^{n-1}}{\oint^{n-2}}+\frac{\oint^{n-2}}{\oint^{n-2}}\implies \oint^2=\oint +\space 1$$
$$\text{Quindi ho dimostrato per induzione che : }$$
$$F_{n-1}+F_{n-2}==\frac{1}{\sqrt5}\cdot\Bigg(\intop^{n}-\oint^{n}\Bigg)$$

#### Correttezza e Complessità

Quindi **Fib1** è **corretto** ? 
	Matematicamente sì ma a livello computazionale *non risulta coretto* per via delle approsimazioni applicate ai numeri irrazionali in un compilatore infatti :
	Per $F_{18}\implies\text{Fib1} = 2583.1 \simeq 2583 \neq F_{18}=2584$

**Complessità** ?
	La complessità non dipende dalla grandezza di $n$ in input per questo viene sempre svolta 1 sola istruzione ciò implica che la complessità è *costante*




### Fib2

In *Fib2* utilizziamo la definizione di numero di *Fibonacci* rendendo così l'algoritmo *ricorsivo* :
``` c
Fib2(int n) -> int
	if(n<=2) then return 1
	else return Fib2(n-1)+Fib2(n-2)
```

È **corretto** ?
	Sì , abbiamo seguito la definizione di *Fattoriale*

**Complessità** ? ( $T(n)$ )
	Per trovare la complessità di questo algoritmo è necessario calcolare il numero di istanze lanciate  :

Calcolo della *complessità* attraverso esempi : 

|$n$|$T(n)$|
|--|--|
|$1$|$1$|
|$2$|$1$|
|$3$|$2+T(2)+T(1) = 4$|
|4|$2+T(3)+T(2) = 7$|


Da questo possiamo dedurre che la complessità generale per un qualsiasi $n$ è :
$$T{(n)}=2 + T{(n-1)}+T{(n-2)}$$
Quindi per $n=5$ avremo : $T_5=2+5\cdot1+4\cdot2=13$

Per calcolare le complessità possiamo affidarci a degli **alberi della ricorsione** ($T_n$)

![[Untitled-2023-09-27-18293.png]]

Per calcolare la *complessità* attraverso l'utilizzo di *alberi della ricorsione* bisogna sapere la quantità di *foglie* ( $f(T_n)$ ) e *nodi interni* ( $i(T_n)$ ) , osservando l'*albero* possiamo ottenere :
$$T(n) = 2\cdot i(T_n) + 1\cdot f(T_n)$$
#### Proposizione 1 :
Se $T_n$ è l'*albero delle ricorsioni* di `Fib2(n)` allora vale che : 
	$$\text{numero di foglie} \space f(T_n) = F_n\space \text{ennesimo numero di fibonacci}$$
**Dimostrazione**

..................


#### Proposizione 2 :
Se $T_n$ è un albero dove i *nodi interni* hanno esattamente 2 figli ( ossia è un albero binario ) allora : 
	$$\text{numero di nodi interni }i(T_n) = f(T_n)-1 \implies F_n -1$$
**Dimostrazione** 
..................
####

Sostituendo nella formula $T(n) = 2\cdot i(T_n) + 1\cdot f(T_n)$ avremo :
$$T(n) = 2\cdot (F_n -1) + F_n \implies 3F_n-2 \approx F_n$$
Quindi si deduce che la *compessità* corrisponde all'incirca all'ennesimo numero di *fibonacci* 

---
Per determinare come cresce la *complessità* dei numeri di *fibonacci* possiamo appoggiarci alla seguente *proprietà* :
$$\forall n \ge 6$$
$$F_n \ge 2^{\frac{n}{2}} \simeq \sqrt2^n$$

**Dimostrazione** :

+ **Caso Base** : 
	$n=6$

+ **Passo induttivo**
	**Ipotesi induttiva** : Assumiamo che la *proprietà* sia vera per $n-1$

	Quindi , per definzione di numero di *fibonacci* abbiamo :
	$$F_n=F_{n-1}+F_{n-2}$$
	Considerando la *proprietà* abbiamo che :
	$$F_{n-1} \ge 2^\frac{n-1}{2}$$
	$$F_{n-2} \ge 2^\frac{n-2}{2}$$
	Quindi la definizione diventa :
	$$F_n=2^\frac{n-1}{2}+2^\frac{n-2}{2}$$
	$$c\cdot2^\frac{-1}{2}+2^\frac{n}{2}\cdot2^{-1}$$
	$$2^\frac{n}{2}\Big(2^{\frac{-1}{2}}+2^{-1}\Big)$$
	$$2^\frac{n}{2}\Bigg(\frac{1}{\sqrt2}+\frac{1}{2}\Bigg)$$
	E visto che 
	$$\Bigg(\frac{1}{\sqrt2}+\frac{1}{2}\Bigg)\ge1$$
    Abbiamo che :
	$$F_{n} \ge 2^\frac{n}{2}$$
La soluzione *ricorsiva* del problema risulta quindi estremamente *inefficente* , principalmente poichè vengono *ripetute* moltissime operazioni già svolte in precedenza ( es il calcolo dei numeri di fibonacci $F_1$ e $F_2$ )

### Fib3

Trasformando la soluzione ricorsiva in *iterativa* ed aggiungendo un *array* dove contenere i risultati precedentemente calcolati 

```c
Fib3(n)
	Allocazione di un array di n interi
	F[1] = F[2] = 1 // assegnazione casi base
	for i=3 to n
		F[i]=F[i-1]+F[i-2] //calcolo fib con array
	return F[n] // rit ultimo el array ossia n-esimo numero di fibonacci
```

È **Corretto** ?
	sì poichè applichiamo la definzione di numero di *fibonacci*

**Complessità** :
	Per $n\leq3$ la *complessità* risulta costante poichè non entriamo mai nel ciclo *for*
	Per $n\ge3$
		3 operazioni vengono sempre svolte :
			- Allocazione della memoria iniziale
			- Assegnazione dei casi base
			- ritorno del risultato
		Il corpo interno del ciclo *for* viene svolto $n-3+1$ volte ( -3 poichè non lo svolgiamo per i casi base , +1 poichè ne viene svolto sempre 1 in più per l'uscita dal ciclo )
		L'istruzione *for* viene svolta $n-1$ volte 

Quindi complessivamente la *complessità* risutlerà essere : 
$$T(n)=3+(n-2)+(n-1)=2n$$

La *complessità* risulterà quindi essere **lineare**

Questo algoritmo può essere ulteriormente migliorato diminuendo la *complessità spaziale* 

### Fib4

```c
Fib4(n)
	a=1 , b=1 //casi base
	for i=3 to n
		c=a+b //applico fibonacci 
		a=b // il primo caso base diventa il 2  
		b=c // il 2 caso base diventa il numero di fibonacci
	return c
```

La **Complessità** risulta essere :
$$4n-5$$
che rimane **lineare**

Ovviamente è **corretto** poichè segue la definizione di numero di *fibonacci*
###
Possiamo quindi riassumere le varie complessità dei precedenti algoritmi qui :

|ver|correttezza|complessità Temporale|complessità Spaziale|
|---|---|---|---|
|binet|no|costante|costante|
|ricorsiva|si|esponenziale|lineare*|
|iterativa|si|lineare|lineare|
|iterativa2|si|lineare|costante|

.* La complessità spaziale della soluzione è lineare poichè lo spazio allocato per ogni chiamata ricorsiva viene deallocato alla sua conclusione quindi il caso peggiore per la memoria utilizzata è la profondità dell'albero delle ricorsioni

## Notazione O grande

La notazione *O grande* viene utilizzata per rappresentare l'andamento della complessità asintotica di un algoritmo

**Classi di Complessità** : 
### $O\Big(g(n)\Big)$

O grande di $g(n)$ è definito come l'insieme delle funzioni $f(n)$ per cui vale la seguente *proprietà* : 
$$\bigg\{f(n)\mid\exists\space c\gt0\space , \exists\space n_0 \in \mathbb{N}\space \text{t.c.}\space \forall\space n\ge n_0 : f(n)\le c\cdot g(n)\bigg\}$$
In cui $\exists\space n_0 \in \mathbb{N}\space \text{t.c.}\space \forall\space n\ge n_0$ significa : per $n$ sufficentemente grandi

Esempio :

Per $O\big(g(n)\big)$ è possibile trovare una costante $c\gt 0$ per cui per un $n$ sufficentemente grande si verifichi la seguete realzione : $f(n)\le c\cdot g(n)$   ( Ossia che $f(n)$ stia sotto $c\cdot g(n)$  ) 

