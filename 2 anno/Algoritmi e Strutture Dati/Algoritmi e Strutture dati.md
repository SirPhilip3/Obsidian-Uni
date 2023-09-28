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

