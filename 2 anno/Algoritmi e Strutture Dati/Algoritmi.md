# Definizioni

+ **Algoritmo corretto**
	Un algoritmo si dice corretto se per ogni input si ferma e da in output il risultato corretto ( si dice che l'algoritmo risolve il problema computazionale )
+ **Complessità computazionale** 
>[!todo]
>completa
>#todo


Esempio : 

# Calcolo numeri di Fibonacci

Definizione :
$$F_n = \begin{cases} 1 &\text{if } n = 1&\text{or} &n=2  \\ F_{n-1} + F_{n-2} &\text{if } n\geq3 \end{cases}$$

## Fib1

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
### Casi Base : 
+ $n=1$ 
	$$F_1=\frac{1}{\sqrt{5}}\cdot\Bigg(\intop-\oint\Bigg)$$
	$$\frac{1}{\sqrt{5}}\cdot\Bigg(\frac{1+\sqrt5}{2}-\frac{1-\sqrt5}{2}\Bigg)$$
	$$\frac{1}{\sqrt{5}}\cdot\Bigg(\frac{2\sqrt5}{2}\Bigg)=1$$
+ $n=2$
	$$F_2=\frac{1}{\sqrt{5}}\cdot\Bigg(\intop^2-\oint^2\Bigg)$$
	$$\frac{1}{\sqrt{5}}\cdot\Bigg(\frac{1+5+2\sqrt5}{2}-\frac{1+5-2\sqrt5}{2}\Bigg)$$
	$$\frac{1}{\sqrt{5}}\cdot\Bigg(\frac{4\sqrt5}{4}\Bigg)=1$$

Siccome $F_1$ e $F_2$ sono equivalenti ai primi 2 numeri di *Fibonacci* i casi basi sono dimostrati

### Passo Induttivo

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

### Correttezza e Complessità

Quindi **Fib1** è **corretto** ? 
	Matematicamente sì ma a livello computazionale *non risulta coretto* per via delle approsimazioni applicate ai numeri irrazionali in un compilatore infatti :
	Per $F_{18}\implies\text{Fib1} = 2583.1 \simeq 2583 \neq F_{18}=2584$

**Complessità** ?
	La complessità non dipende dalla grandezza di $n$ in input per questo viene sempre svolta 1 sola istruzione ciò implica che la complessità è *costante*

## Fib2

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
### Proposizione 1 :
Se $T_n$ è l'*albero delle ricorsioni* di `Fib2(n)` allora vale che : 
	$$\text{numero di foglie} \space f(T_n) = F_n\space \text{ennesimo numero di fibonacci}$$
**Dimostrazione**
>[!todo]
### Proposizione 2 :
Se $T_n$ è un albero dove i *nodi interni* hanno esattamente 2 figli ( ossia è un albero binario ) allora : 
	$$\text{numero di nodi interni }i(T_n) = f(T_n)-1 \implies F_n -1$$
**Dimostrazione** 
>[!todo]
###

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

## Fib3

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
## Fib4

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
##
Possiamo quindi riassumere le varie complessità dei precedenti algoritmi qui :

|ver|correttezza|complessità Temporale|complessità Spaziale|
|---|---|---|---|
|binet|no|costante|costante|
|ricorsiva|si|esponenziale|lineare*|
|iterativa|si|lineare|lineare|
|iterativa2|si|lineare|costante|

.* La complessità spaziale della soluzione è lineare poichè lo spazio allocato per ogni chiamata ricorsiva viene deallocato alla sua conclusione quindi il caso peggiore per la memoria utilizzata è la profondità dell'albero delle ricorsioni

# Notazione O grande

La notazione *O grande* viene utilizzata per rappresentare l'andamento della complessità asintotica di un algoritmo

**Classi di Complessità** : 
## $O\Big(g(n)\Big)$

O grande di $g(n)$ è definito come l'insieme delle funzioni $f(n)$ per cui vale la seguente *proprietà* : 
$$\bigg\{f(n)\mid\exists\space c\gt0\space , \exists\space n_0 \in \mathbb{N}\space \text{t.c.}\space \forall\space n\ge n_0 : f(n)\le c\cdot g(n)\bigg\}$$
In cui $\exists\space n_0 \in \mathbb{N}\space \text{t.c.}\space \forall\space n\ge n_0$ significa : per $n$ sufficentemente grandi

Esempio :

Per $O\big(g(n)\big)$ è possibile trovare una costante $c\gt 0$ per cui per un $n$ sufficentemente grande si verifichi la seguete relazione : $f(n)\le c\cdot g(n)$   ( Ossia che $f(n)$ stia sotto $c\cdot g(n)$  ) 

![[Ogrande.excalidraw]]

Esempio :
$$\frac{1}{2}n^2-3n=O\big(n^2\big)$$
Applicando la definizione :
$$\exists\space c\gt0\space , \exists\space n_0 \in \mathbb{N}\space \text{t.c.}\space \forall\space n\ge n_0 : \frac{1}{2}n^2-3n\le c\cdot n^2$$
Dimostriamo quindi la precedente relazione :
$$\frac{1}{2}n-3\le c\cdot n $$
$$\frac{1}{2}n-c\cdot n\le3$$
$$\bigg(\frac{1}{2}-c\bigg)\cdot n\le3$$
Quando è vera la precedente disequazione 

>[!todo]
>completa la dimostrazione
>#todo
## $\Omega\Big(g(n)\Big)$

Omega grande di $g(n)$ è definito come l'insieme delle funzioni $f(n)$ per cui vale la seguente *proprietà* :
$$\bigg\{f(n)\mid\exists\space c\gt0\space , \exists\space n_0 \in \mathbb{N}\space \text{t.c.}\space \forall\space n\ge n_0 : c\cdot g(n)\le f(n)\bigg\}$$

Risulta essere l'esatto contrario di *O-grande*

Esempio :

Per $O\big(g(n)\big)$ è possibile trovare una costante $c\gt 0$ per cui per un $n$ sufficentemente grande si verifichi la seguete realzione : $c\cdot g(n)\le f(n)$   ( Ossia che $f(n)$ stia sopra $c\cdot g(n)$  ) 

![[Omega.excalidraw]]

Esempio :
$$\frac{1}{2}n^2-3n=\Omega\big(n^2\big)$$
Applicando la definizione :
$$\exists\space c\gt0\space , \exists\space n_0 \in \mathbb{N}\space \text{t.c.}\space \forall\space n\ge n_0 : c\cdot n^2\le \frac{1}{2}n^2-3n $$
Dimostriamo quindi la precedente relazione :
$$ c\cdot n \le\frac{1}{2}n-3$$
$$3\le\frac{1}{2}n-c\cdot n$$
$$\bigg(\frac{1}{2}-c\bigg)\cdot n\le3$$
Quando è vera la precedente disequazione 

>[!todo]
>completa la dimostrazione
>#todo
## $\Theta\Big(g(n)\Big)$

Risulta la combinazione di *O-grande* e *Omega-grande* ossia :
$$\bigg\{f(n)\mid\exists\space c_1\gt0\space \land\exists\space c_2\gt 0 , \exists\space n_0 \in \mathbb{N}\space \text{t.c.}\space \forall\space n\ge n_0 : c_1\cdot g(n)\le f(n)\le c_2\cdot g(n)\bigg\}$$

![[big-theta-notation.png]]

Accade quando $f(n)$ si comporta asintoticamente come $g(n)$ 

Quindi avremo che :
$$f(n)=\Theta\big(g(n)\big)\iff f(n)=\Omega\big(g(n)\big) \land\space f(n)=O\big(g(n)\big)$$

Per : 
$$\frac{1}{2}n^2-3n = \Theta\big(n^2\big)$$
Quindi si comporta come il termine $n^2$ , in generale tutti i polinomi si comportano come il loro termine di massimo grado

**Esempio** : 
$$\sqrt{n+10}=\Theta(\sqrt{n})$$
*Dimostrazione* :

Applico la definizione : 
	$$\exists\space c_1 , c_2 \gt 0 \space\text{t.c.}\space c_1\sqrt{n}\le \sqrt{n+10}\le c_2\sqrt{n}$$
	$$c_1^2\cdot n\le n+10\le c_2^2\cdot n$$
Suddividendo le disequazioni abbiamo :
1. 
$$c_1^2\cdot n\le n+10$$
$$c_1^2\cdot n-n\le 10$$
$$(c_1^2-1)\cdot n\le 10$$
Perchè la disequazione risulti vera necessitamo che $(c_1^2-1)$ sia $\le 0$ , avremo quindi :
$$c_1\le 1$$
$n$ deve quindi essere
$$n\ge1$$

2. 
	$$n+10\le c_2^2\cdot n$$
	$$(c_2^2-1)\cdot n\ge 10$$
Quindi avremo che :
$$c_2\gt1$$
Con $n$ che risulterà essere :
$$n\ge \frac{10}{c_2^2-1}$$
Scielgiendo $c_2=\sqrt2$ avremo che $n\ge10$ 
Quindi avremo che 
$$\sqrt{n+10}=\Theta(\sqrt{n})$$
Quando :
$$c_1=1$$
$$c_2=\sqrt2$$
$$n_0=10$$
Abbiamo scielto $n_0=10$ poichè soddisfa entrambe le condizioni
## Ulteriori Dimostrazioni

### $log\space n=O(n)$

Osservando il grafico si può capire il perchè 

```functionplot
---
title: 
xLabel: 
yLabel: 
bounds: [-2,10,-3,10]
disableZoom: true
grid: true
---
1 y=x-1
2 y=log(x)
```

Poichè $log(n)\le n-1 \implies log(n) \le n$

ciò avviene per $c=1$ e $n_0=1$
### $n\cdot log\space n = O\big(n^2\big)$

Visto che 
$$log(n)\le n$$
Avremo che :
$$n\cdot log(n)\le n^2$$
Quindi è *O grande* per $c=1$ e $n_0=1$
### $n!=O\big(n^n\big)$

Si può dimostrare dicendo che :
$$1\cdot2\cdot3\cdot...\cdot n = n! \le n\cdot n\cdot...\cdot n = n^n$$
Quindi :
$$n!\le n^n$$
### $n!=\Omega\big(2^n\big)$

$$1\cdot2\cdot3\cdot...\cdot n\space \text{è maggiore di} \space 1\cdot2\cdot2\cdot...\cdot2 = 2^{n-1}$$
Quindi avremo che :
$$n!\ge2^{n-1}\implies n!\ge\frac{1}{2}2^n$$
In questo caso $c$ diventa $\frac{1}{2}$ in questo modo abbiamo verificato che $n!=\Omega(2^n)$
### $log\space (n!) = O(n\cdot log\space n)$

$$log\big(n!\big)=log\Bigg(\prod_{i=1}^{n} i\Bigg)$$
$$=\sum_{i=1}^{n} log(i)$$
Essendo che $log(i)\le log(n)$ avremo che :
$$\sum_{i=1}^{n} log(i)\le n\cdot log(n)$$
### $\sqrt n = O(n)$

Possiamo facilmente dimostrarla :
Essendo che :
$$n\le n^2\space\space \forall n\ge1$$
Avremo quindi che $\sqrt n \le n$
## Proprietà

$$f(n)=O\Big(g(n)\Big) \Leftrightarrow g(n) = \Omega\Big(f(n)\Big)$$
Per dimostrare la precedente proprietà bisogna dimostrare sia $\Rightarrow$ che $\Leftarrow$

Dimostriamo $\Rightarrow$

Ipotesi : $f(n)=O\Big(g(n)\Big)$

Per ipotesi avremo quindi che :
$$\exists\space c\gt0 , \exists\space n_0\in \mathbb{N}\space \text{t.c.}\space \forall n \ge n_0 : f(n)\le c\cdot g(n)$$
Ciò che vogliamo dimostrare è : 
$$\exists\space c'\gt0 , \exists\space n_0'\in \mathbb{N}\space \text{t.c.}\space \forall n \ge n_0' : c'\cdot f(n)\le g(n)$$
Dall'ipotesi abbiamo che :
$$\frac{1}{c}\cdot f(c)\le g(n)$$
Ponendo $c'=\frac{1}{c}$ e sciegliendo $n_0'=n_0$ la proprietà è dimostrata

La dimostrazione è equivalente per $\Leftarrow$
### Proprietà Transitiva

La seguente proprietà e valida per $O$ , $\Omega$ , $\Theta$

Se :
$$f(n)=O\Big(g(n)\Big)\space \text{e} \space g(n)=O\Big(h(n)\Big)$$
Allora :
$$f(n)=O\Big(h(n)\Big)$$
Dimostrazione :

Ipotesi :
$$\exists\space c_1\gt0 , \exists\space n_1\in \mathbb{N}\space \text{t.c.}\space \forall n \ge n_1 : f(n)\le c_1\cdot g(n)$$
$$\exists\space c_2\gt0 , \exists\space n_2\in \mathbb{N}\space \text{t.c.}\space \forall n \ge n_2 : g(n)\le c_2\cdot h(n)$$
Ciò che vogliamo dimostrare :
$$\exists\space c_3\gt0 , \exists\space n_3\in \mathbb{N}\space \text{t.c.}\space \forall n \ge n_3 : f(n)\le c_3\cdot h(n)$$

Sciegliamo un $n_3 = max\{n_1,n_2\}$ ( massimo tra $n_1$ e $n_2$ in modo tale che ciò che vogliamo dimostrare valga sia per la prima che per la seconda ipotesi )

Sostituendo nella prima ipotesi con la seconda ipotesi abbiamo :
$$f(n)\le c_1\cdot c_2\cdot h(n)$$
Poichè $c_1\cdot c_2 \ge c_3\gt0$ abbiamo dimostrato che : $f(n)=O\Big(h(n)\Big)$
## $o\Big(g(n)\Big)$

$$o\Big(g(n)\Big)=\Big\{f(n)\mid \forall\space c \gt 0 \space\exists\space n_0 \in \mathbb{N}\space \text{t.c.}\space \forall\space n\ge n_0 : f(n) \lt c\cdot g(n)\Big\}$$

Vi sono alcune differenze con l'*O* :
$$\forall\space c \gt 0$$
Invece di :
$$\exists\space c \gt 0$$
Inoltre : 
$$f(c) \lt c\cdot g(n)$$
Invece di :
$$f(c) \le c\cdot g(n)$$
Queste differenze ci fanno capire che non c'è più un $c$ per il quale vale la definizione ma deve valere per tutti i valori di $c$

Avremo quindi che *O* risulterà essere un sottoinsieme di *o*
$$o\Big(g(n)\Big)\subset O\Big(g(n)\Big)$$
Quindi avremo anche che :
$$f(n)=o\Big(g(n)\Big)\implies f(n)=O\Big(g(n)\Big)$$

La definizione di $o(g(n))$ è molto simile alla definzione di limite di una sucessione infatti :
$$\lim_{n\rightarrow\infty} a_n = l$$
$$\forall\space \epsilon \gt 0\space \exists\space n_0 \in\mathbb{N}\space \text{t.c.}\space \forall\space n\ge n_0  \space|a_n-l |\le\epsilon $$
Come si può vedere infatti la prima parte è identica alla definizione di *o* , la seconda parte $|a_n-l |\le\epsilon$ è riconducibile alla distanza tra le 2 funzioni , che si può ricondurre a $f(c) \lt c\cdot g(n)$

Quindi si può dedurre la seguente *proprietà* :
$$f(n)=o\Big(g(n)\Big)\iff \lim_{n\rightarrow\infty} \frac{f(n)}{g(n)}=0$$
Visto che : 
$$o\Big(g(n)\Big)\subset O\Big(g(n)\Big)$$
Abbiamo anche che :
$$ \lim_{n\rightarrow\infty} \frac{f(n)}{g(n)}=0 \implies f(n)=o\Big(g(n)\Big)=O\Big(g(n)\Big)$$
Esempi :
$$log\ n =O(\sqrt n) $$
$$\lim_{n \to \infty} \frac{log_e\ n}{\sqrt n} = \lim_{n \to \infty} \frac{\frac{1}{n}}{\frac{1}{2}\cdot n^{\frac{-1}{2}}} \quad \text{(per L'Hôpital)}$$
$$\lim_{n \to \infty} \frac{2}{\sqrt n}=0$$
Avremo quindi che : 
$$log\ n =o(\sqrt n)$$
poichè $o\Big(g(n)\Big)\subset O\Big(g(n)\Big)$ avermo che :
$$log\ n =O(\sqrt n)$$
## $\omega \Big(g(n)\Big)$

$$\omega\Big(g(n)\Big)=\Big\{f(n)\mid \forall\space c \gt 0 \space\exists\space n_0 \in \mathbb{N}\space \text{t.c.}\space \forall\space n\ge n_0 :c\cdot g(n)\lt f(n)\Big\}$$
Come per *o-piccolo* anche in questo caso abbiamo che :
$$\omega\Big(g(n)\Big)\subset \Omega\Big(g(n)\Big)$$
Lo stesso vale per la definizione tramite *limite* :
$$f(n)=\omega\Big(g(n)\Big)\iff \lim_{n\rightarrow\infty} \frac{f(n)}{g(n)}=\infty$$
Il limite risulta uguale a $\infty$ poichè abbiamo che $g(n)\lt f(n)$

Le seguenti proprietà possono quindi essere determinate dalle precedenti definizioni :
$$o(g(n))\ \cap \ \Omega(g(n))=\emptyset$$
$$\omega(g(n))\ \cap \ O(g(n))=\emptyset$$

![[O-notationWenn.excalidraw]]

Questo può essere *dimostrato* per assurdo :

Supponiamo che valga la tesi e che quindi $o(g(n))\ \cap \ \Omega(g(n))\neq \emptyset$

Avremo quindi che :
$$\exists \ f(n) \in o(g(n))\ \cap \ \Omega(g(n))$$
Seguendo le definzioni avremo che :
$$\forall\space c \gt 0 \space\exists\space n_0 \in \mathbb{N}\space \text{t.c.}\space \forall\space n\ge n_0 : f(n) \lt c\cdot g(n)\quad \text{Per o-piccolo}$$
$$\exists\space c'\gt0\space , \exists\space n_0' \in \mathbb{N}\space \text{t.c.}\space \forall\space n\ge n_0' : c'\cdot g(n)\le f(n)\quad \text{Per $\Omega$}$$
1. Poichè abbiamo che per *o-piccolo* abbiamo che la definizione deve valere per ogni $c$ allora scielgieremo come $c$ $c'$ 
2. Per far valere entrambe le difinizioni dobbiamo sciegliere un $n\ge max\{n_0,n_0'\}$

Avendo fatto queste 2 considerazioni possiamo concludere che :
$$f(n)\lt c'\cdot g(n)\le f(n)$$
Questo è evidentemente *assurdo* ; abbiamo quindi dimostrato che : $o(g(n))\ \cap \ \Omega(g(n))=\emptyset$

La stessa dimostrazione può essere svolta per $\omega(g(n))\ \cap \ O(g(n))=\emptyset$ 

### Proposizione 

Anche $\Theta (g(n))$ ha un simile comportamento a $o(g(n))$ e $\omega (g(n))$ per quanto riguarda i *limiti* , infatti possiamo scrivere che :
$$\text{Se}\quad\lim_{n\rightarrow \infty} \frac{f(n)}{g(n)} = l \quad \text{con $0 \lt l \lt \infty$ } \quad \implies \quad f(n)=\Theta(g(n))$$
## Lim e O notation riassunto

$$\lim_{n\rightarrow \infty} \frac{f(n)}{g(n)} \begin{cases} 0 & \implies f(n) = O(g(n)) \\ l & \implies f(n)=\Theta(g(n)) \\ \infty & \implies f(n)=\Omega(g(n)) \end{cases}$$

Esempio :

$$(1+\sin(n))\cdot n=O(n)$$
Avremo che :
$$-1\le\sin(n)\le 1$$
$$0\le1+\sin(n)\le 2$$
Ora moltiplicando per $n$
$$(1+\sin(n))\cdot n\le 2\cdot n$$
Avremo quindi che $c=2$ e per definizione abbiamo dimostrato che : $(1+\sin(n))\cdot n=O(n)$

Ora proviamo a fare lo stesso con la definizione di $\lim$
$$\lim_{n\rightarrow \infty} \frac{(1+\sin(n))\cdot n}{n}=\lim_{n\rightarrow \infty} (1+\sin(n))=\emptyset$$
Non è quindi sempre valida la definizione di limite per dimostra l'apparteneza ad una classe di complessità
## Polinomi

Per determinare la complessità di un polinomi bisogna considerare solo l'elemento che risulta più alto grado :
Esempio :
$$3n^3+2n^2+6n+5=\Theta(n^3)$$
Regola dei polinomi *semplici*
$$P(n)\ \text{con grado k massimo} \implies P(n)=\Theta(n^k)$$
Quando abbiamo una espressione addittiva con termini di complessità diverse possiamo dire che funzione si comporta come il *termine dominante*

Esempio :
$$21n^2+n^2\log{n} + \sqrt{n}+\log{n^2}$$
I *termini dominati* sono : $n^2\log{n}$ e $\log{n^2}$
E visto che : $\log{n^2}=2\log{n}$
Avremo che sicuramente : $n^2\log{n}\ge 2\log{n}$

Quindi il polinomio avrà come complessità : $\Theta(n^2\log{n})$

Infatti possiamo anche osservare dal grafico :

```functionplot
---
title: Polinomial
xLabel: x
yLabel: y
bounds: [0,10,0,10]
disableZoom: true
grid: true
---
1 y=x^2
2 y=x^2*log(x)
3 y=x^(1/2)
4 y=log(x^2)
```
### Proprietà

Quindi per riassumere possiamo scrivere la seguente **Proprietà** :
$$f(n)+o(f(n))=\Theta(f(n))$$
Ciò significa : una funzione che è la somma di una funzione $f(n)$ ad una funzione che è più piccola di $f(n)$ risulterà avere come complessità $\Theta(f(n))$ 

La precedente proprietà può anche essere riscritta nel seguente modo :
$$\text{Considerando}\quad o(f(n))=h(n)\quad \text{e} \quad f(n)+h(n)=g(n) \quad \text{Avremo che :}$$
$$g(n)=\Theta{f(n)}$$
# Metodi per la stima della complessità di un Algoritmo

Facciamo un Esempio :

Abbiamo un algoritmo di *ricerca sequenziale* che ci permette di ricercare un numero *x* all'interno di un array , passando uno per uno gli elmenti dell'array e verificando che questo sia o non sia il numero che cerchiamo.

Avremo quindi diversi tipi di complessità :
+ *caso migliore* : $T_{\text{best}}(n)=1$
	Nel caso migliore avremo che *x* sarà presente nel primo elemento dell'array
+ *caso peggiore* : $T_{\text{worst}}(n)=n$
	Nel caso peggiore avremo che *x* non è presente all'interno dell'array o è l'ultimo elemento
+ *media* : $T_{\text{avg}}(n)=\frac{n}{2}$
	Se volessimo calcolare il caso medio dovremmo effettuare uno studio probabilistico del nostro algoritmo ( nel nostro caso in termini di complessità risulta assimilabile al caso peggiore ma potrebbe essere diverso )

A noi interessa studiare al caomplessità nel **caso peggiore** in vari costrutti standard per la costruzione di algoritmi
### Sequenza

Se un algoritmo è formato da blocchi di codice che costituiscono nel complesso una *sequenza* di istruzioni

![[SequenzaCompl.excalidraw]]
Avremo che la sua complessità può essere calcolata come :
$$seq=O(f(n)+g(n))$$
### If then else

Avendo un codice simile :
```c
if <cond>   then
	Ramo-then
else 
	Ramo-else
```

Avremo 3 complessità che comongono l'*if then else* :
+ `<cond>` : La condizione iniziale ha acnhessa una complessità , questa istruzione viene sempre eseguita 
	$O(f(n))$
+ `Ramo-then`
	$O(g(n))$
+ `Ramo-else`
	$O(h(n))$

Per via della condizione dell'*if* uno dei 2 rami dell'*if* non viene svolto per questo calcolando la complessità di un *if then else* prendiamo sempre in considerazione il ramo che ha la maggiore complessità.
Avremo quindi :
$$if=O(f(n)+max\{g(n),h(n)\})$$
### Ciclo For

Avendo un codice simile :
```c
for i to k
	Block
```

Il `Block` verrà ripetuto $k$ volte quindi avremo come complessità ( considerando la complessità di `Block` come $O(f(n))$  ) :
$$for=O(k\cdot f(n))$$
### Cicli For annidati

I cicli *for annidati* funzionano in modo simile ai normali cicli *for* quindi avendo un codice simile :
```c
for i to k
	for j to n
		Block
```

Dove `n` dipende dall'input della funzione 

Come prima il `Block` verrà ripetuto $k\cdot n$ volte e avendo la complessità del `Block` come : $O(f(n)))$
Avremo che la complessità totale sarà :
$$forA=O(k\cdot n \cdot f(n))$$
Se avessimo anche $k$ in funzione dell'input della funzione $n$ avremo :
$$forA=O(n^2 \cdot f(n))$$
### While

Avendo un codice simile :
```c
while <cond> do
	Block
```

In questo caso non sappiamo a priori il numero di volte che il ciclo verrà eseguito quindi prenderemo il massimo numero di iterazioni ossia il *caso peggiore* : $N(n)$

Considerando quindi la complessità della `<cond>`  come $O(f(n))$ e la complessità del `Block` come $O(g(n))$
Avremo quindi che la complessità totale sarà :
$$while = O\Big(N(n)\cdot\big(f(n)+g(n)\big)\Big)$$
### Esempio

Abbiamo il seguente algoritmo :
```c
Alg(int n) -> n 
int a , i , j
if( n > i ) then
	a = 0
	for i = 1 to n
		for j = 1 to n
			a = (n + i) * j + n/2
	
	for i = 1 to 16
		a = a + Algo(n/4)
	return a
else
	return false
```

Studiando quindi la complessità avremo che :
+ La condizione dell'*if* iniziale è *costante* ( è solo la verifica che un numero sia maggiore di un'altro ) quindi la sua complessità può essere ignorato nel calcolo totale finale
+ Ramo `then`
	+ *for annidati* :
		I *for* annidati poichè il loro numero di iterazioni dipende da $n$ e il *blocco* all'interno dell'ultimo *for* risulta essere costante rispetto a $a$ avremo che la *complessità* di questo *for annidato* sarà :
		$$O(n\cdot n\cdot \text{costante})=O(n^2)$$
	+ secondo *for* non annidato ( riga 9-10 ) : 
		Il secondo *for* risulta avere $16$ ricorrenze 
		Il *blocco* all'interno del *for* è ricorsivo avremo quindi che la sua complessità sarà la complessità dell'algoritmo con come input $n/4$
		La complessità totale del *for* sarà quindi :
		$$O\bigg(16\cdot T\bigg(\frac{n}{4}\bigg)\bigg)$$
+ Ramo `else`
	Il ramo *else* risulta *costante* poichè è solo un `return`

La complessità totale dell'algoritmo sarà quindi la somma della complessità delle sue parti :
$$T(n)=n^2+16\cdot T\bigg(\frac{n}{4}\bigg)\quad \text{con}\space n\gt1$$
Abbiamo quindi una fromula ricorsiva che attraverso il *Teorema Master* può essere semplificata in : 
$$T(n)=\Theta(n^2\log(n))$$
## Risolvere le Ricorrenze

Per risolvere le ricorrenze abbiamo 4 metodi principali :
+ Metodo degli *alberi della ricorsione*
+ Metodo dell'*intersezione*
+ Metodo della *sostituzione*
+ *Teorema Master*
### Metodo degli alberi della ricorsione

Vedi [Fib2](#Fib2)
### Metodo dell'interazione

Si cerca di sviluppare la ricorsione fino all'identificazione di un *pattern*
#### Esempio 1 :
In un algoritmo che ha come complessità :
$$T(n) = \begin{cases} c+T(\frac{n}{2}) & n\ge 2 \\ 1 & n=1 \quad\text{caso base}\end{cases}$$
Sviluppando per $n\ge 2$ avremo :
$$T(n)=c+T\bigg(\frac{n}{2}\bigg)$$
$$=c+\bigg[c+T\bigg(\frac{n}{2^2}\bigg)\bigg]$$
$$=2\cdot c+T\bigg(\frac{n}{2^2}\bigg)$$
$$2\cdot c+\bigg[c+T\bigg(\frac{n}{2^3}\bigg)\bigg]$$
$$=3\cdot c+T\bigg(\frac{n}{2^3}\bigg)$$
Possiamo quindi trovare un *pattern* :
$$=k\cdot c+T\bigg(\frac{n}{2^k}\bigg)$$
Ora usando il caso base risolviamo la ricorsione 
$$\frac{n}{2^k}=1$$
$$n=2^k$$
$$k=\log_2 n$$
Ora sostituiamo nell'equazione derivata dal *pattern* :
$$c\cdot \log_2 n + T(1)$$
$$=c\cdot \log_2 n +1$$
Siccome non ci interessano le costanti possiamo dedurre che :
$$T(n)=O(\log_2 n)$$
Se consideriamo il *terema Master* potremmo dire :
$$T(n)=\Theta(\log_2 n)$$
#### Esempio 2 :

$$T(n) = \begin{cases} 9\cdot T(\frac{n}{3})+n & n\ge 2 \\ 1 & n=1 \quad\text{caso base}\end{cases}$$

Per $n$ sufficentemente grande avremo che :
$$T(n)=9\cdot T\bigg(\frac{n}{3}\bigg)+n$$
$$=9\cdot \bigg[9\cdot T\bigg(\frac{n}{3^2}\bigg)+\frac{n}{3}\bigg]+n$$
$$=9^2\cdot T\bigg(\frac{n}{3^2}\bigg)+3\cdot n+n$$
$$=9^2\cdot \bigg[9\cdot T\bigg(\frac{n}{3^3}\bigg)+\frac{n}{3^2}\bigg]+3\cdot n+n$$
$$=9^k\cdot T\bigg(\frac{n}{3^k}\bigg)+ n[3^2+3^1+3^0]$$
$$=9^k\cdot T\bigg(\frac{n}{3^k}\bigg) + \Bigg(\sum_{i=0}^{k-1}3^i\Bigg)\cdot n$$
Possiamo identificare inoltre che 
$$\sum_{i=0}^{k-1}3^i$$
è una *progressione geometrica finita* che può quindi essere scritta come :
$$\sum_{i=0}^{n}q^i=\frac{q^{n+1}-1}{q-1}$$
Avremo quindi :
$$T(n)=9^k\cdot T\bigg(\frac{n}{3^k}\bigg) + n\cdot \frac{3^k-1}{2}$$

Ora utilizzando il caso base avremo che :
$$\frac{n}{3^k}=1$$
$$n=3^k$$
$$\log_3 n = k$$
Sostituendo nell'equazione dedotta avremo :
$$T(n)=9^{\log_3 n}+n\cdot \frac{3^{\log_3 n}-1}{2}$$
$$=3^{{\log_3 n}^2}+n\cdot \frac{n-1}{2}$$
$$=n^2+\frac{n^2}{2}-\frac{n}{2}$$
Possiamo quindi determinare che la complessità sarà :
$$T(n)=\Theta(n^2)$$
### Metodo della sostituzione

Il metodo della *sostituzione* consiste nel fare una ipotesi sulla complessità dell'algoritmo ( grazie all'esperienza e alla conoscenza di altri teoremi ) e poi *dimostrarla* 
#### Esempio

$$T(n) = \begin{cases} 1 & n=1 \quad\text{caso base} \\ T(\lfloor\frac{n}{2}\rfloor)+n & n\ge 2  \end{cases}$$
Faccio una ipotesi riguardante la sua *complessità* 
$$T(n)=O(n)$$
Dimostriamo quindi per induzione la nostra assunzione :
Utilizzando la definizione di $\text{O-grande}$ come *ipotesi induttiva*:
$$\exists\space c>0\quad \exists\space n_0 \in \mathbb{N} \quad \text{t.c.} \quad \forall\space n \ge n_0 \quad T(n)\le c\cdot n$$
Per prima cosa consideriamo il *caso base* :

con $n_0=1$ avremo :
$$T(1)\le1\cdot c$$
Essendo che $T(1)=1$ per il caso base avremo che :
$$c\ge 1$$

Quindi se vogliamo che la proprietà valga da 1 in poi la costante $c$ deve essere $\ge$ 1

Passando quindi al caso con $n\ge 2$ abbiamo che :
$$T(n)=T\bigg(\bigg\lfloor\frac{n}{2}\bigg\rfloor\bigg)+n$$
Questo vale se consideriamo che l'ipotesi induttiva vale per tutti gli $n-1$

Sostituendo quindi all'interno dell'*ipotesi induttiva* abbiamo :
$$T(n)\le c\cdot \frac{n}{2}+n$$
$$\le n\cdot \bigg(\frac{c}{2}+1\bigg)$$
ma noi vogliamo che sia $\le c\cdot n$
Quindi dovremmo porre che :
$$\frac{c}{2}+1\le c$$
$$c\ge 2$$
Avremo quindi che quando $c\ge2$ la complessità dell'algoritmo sara :
$$T(n)\le c\cdot n$$
Abbiamo quindi dimostrato che la complassità è : $O(n)$
### Teorema Master o Teorema fondamentale delle ricorrenze

Il *teorema Master* ci permette di risolvere le ricorrenze di algoritmi dividi et impera
Possiamo infatti dividere questo tipo di algoritmi in tre parti :
$$T(n)=T_{split}(n)+\sum_{i=1}^a T\bigg(\frac{n}{b}\bigg) + T_{merge}(n)$$
In cui :
+ $T_{split}(n)$ 
	Questo rappresenta il tempo necessario per dividere il problema in sottoproblemi
+ $\sum_{i=1}^a T(\frac{n}{b})$
	Questo rappresenta la somma dei tempi di computazione dei singoli sottoproblemi che se avessero tutti la stessa dimensionabilità potrebbe essere scritto come : $a\cdot T(\frac{n}{b})$
+ $T_{merge}(n)$
	Questo rappresenta il tempo necessario per combinare le soluzioni dei sottoproblemi in una soluzione finale

La formula precedente può essere sommarizata come segue :
$$T(n)=a\cdot T\bigg(\frac{n}{b}\bigg)+f(n)$$
In cui $f(n)=T_{split}(n)+T_{merge}(n)$

Perchè il *teorema* possa essere applicato dobbiamo avere soddifatte le seguenti condizioni :
+ $f(n)\ge0$ : n deve essere sufficentemente grande
+ $a\ge1$
+ $b\gt1$

Utilizzeremo inoltre un parametro $d$ :
$$d=\log_b a$$
Il *teorema* comprende 3 casi : 
#### $split+merge \lt \text{chiamate ricorsive}$ 1 caso $f(n)<g(n)$

La complessità di $split+merge$ è *minore* della complessità delle *chiamate ricorsive*

$$f(n)=O\Big(n^{d-\epsilon}\Big)$$
Se $f(n)$ è $O(n^{d-\epsilon})$  allora per $\epsilon \gt 0$ avremo che 
$$T(n)=\Theta\Big(n^d\Big)$$
Ossia la parte ricorsiva domina sulla parte di $split+merge$ 
#### $split+merge = \text{chiamate ricorsive}$ 2 caso $f(n)=g(n)$

La complessità di $split+merge$ è *uguale* a quella delle *chiamate ricorsive*
$$f(n)=\Theta\Big(n^d\Big)$$
Ossia $f(n)$ ha complessità simile allo $split+merge$  , avremo la complessità come :
$$T(n)=\Theta(n^d\cdot \log n)$$
#### $split+merge \gt \text{chiamate ricorsive}$ 3 caso $f(n)>g(n)$

La complessità di $split+merge$ è *maggiore* della complessità delle *chiamate ricorsive*
$$f(n)=\Omega\Big(n^{d+\epsilon}\Big)$$
Ossia $f(n)$ è dominata dalla parte di $split+merge$ 
Dobbiamo in questo caso verificare la *condizione ausiliaria* :
$$\exists\space 0\lt c\lt1 \quad \text{t.c.} \quad \text{per $n$ sufficentemente grande vale :}$$
$$a\cdot f\bigg(\frac{n}{b}\bigg)\le c \cdot f(n)$$
( questo verifica che il secondo livello di ricorsione per le $split+merge$ sia minore di del tempo di $f(n)$ )
Verificata la condizione ausiliaria possiamo concludere che la complessità sarà :
$$T(n)=\Theta(f(n))$$
#### Esempi

##### 1

$$T(n)=T\bigg(\frac{n}{2}\bigg)+c$$
Si può applicare il *teorema master* ? :
- [ ] La forma è simile a : $a\cdot T(\frac{n}{2})+c$
- [ ] $f(n)\ge 0$ 
- [ ] $a\ge 1$ 
- [ ] $b\gt 1$

Avendo verificato che si può applicare il *teorema master* andiamo a verificare in che caso ci troviamo 

+ $a=1$
+ $b=2$
+ $f(n)=c$
+ $d=\log_2 1=0$

Come si confronta $n^d$ a $f(n)$
+ $g(n)=n^d=n^0=1$
+ $f(n)=c$ 

Poichè asintoticamente 1 e c si comportano nello stesso modo siamo nel caso in cui lo $split+merge = \text{chiamate ricorsive}$

Quindi avremo che :
$$T(n)=\Theta(n^0\cdot \log n)=\Theta(\log n)$$
##### 2
$$T(n)=9\cdot T\bigg(\frac{n}{3}\bigg)+n$$
Si può applicare il *teorema master* ? :
- [ ] La forma è simile a : $a\cdot T(\frac{n}{2})+c$
- [ ] $f(n)\ge 0$ 
- [ ] $a\ge 1$ 
- [ ] $b\gt 1$

Avendo verificato che si può applicare il *teorema master* andiamo a verificare in che caso ci troviamo 

+ $a=9$
+ $b=3$
+ $f(n)=n$
+ $d=\log_3 9=2$

Come si confronta $n^d$ a $f(n)$
+ $g(n)=n^d=n^2$
+ $f(n)=n$ 

Poichè $n^2$ ( parte ricorsiva ) domina su $f(n)=n$ ( parte di $split+merge$ ) siamo nel caso in cui la parte ricorsiva domina sullo $split+merge$

Per trovare $\epsilon$ basterà applicare il *teorema* :
$$f(n)=O(n^{d-\epsilon})$$
Sostituendo abbiamo :
$$n=O(n^{2-\epsilon})$$
Per trovare $\epsilon$ dobbiamo consideare che $n$ deve avere la stessa complessità di $O(n^{2-\epsilon})$ 
Basterà quindi sciegliere $\epsilon\quad \text{t.c.}\quad 1=2-\epsilon$
Scielgiendo quindi $\epsilon = 1$ la condizione sarà verificata e avremo che la complessità sarà :
$$T(n)=\Theta(n^2)$$
##### 3

$$T(n)=3\cdot T\bigg(\frac{n}{9}\bigg)+1$$
Si può applicare il *teorema master* ? :
- [ ] La forma è simile a : $a\cdot T(\frac{n}{2})+c$
- [ ] $f(n)\ge 0$ 
- [ ] $a\ge 1$ 
- [ ] $b\gt 1$


Avendo verificato che si può applicare il *teorema master* andiamo a verificare in che caso ci troviamo 

+ $a=3$
+ $b=9$
+ $f(n)=1$
+ $d=\log_9 3=\frac{1}{2}$

Come si confronta $n^d$ a $f(n)$
+ $g(n)=n^{\frac{1}{2}}=\sqrt n$
+ $f(n)=1$ 

Poichè $\sqrt n$ ( parte ricorsiva ) domina su $f(n)=1$ ( parte di $split+merge$ ) siamo nel caso in cui la parte *ricorsiva* domina sullo $split+merge$

Troviamo quindi $\epsilon$
$$1=O(n^{\frac{1}{2}-\epsilon})$$
$$0=\frac{1}{2}-\epsilon\quad\quad \text{0 poichè $n^0=1$}$$
Quindi con
$$\epsilon=\frac{1}2$$
Abbiamo verificato la condizione 
Avremo quindi che la complessità sarà :
$$T(n)=\Theta(\sqrt n)$$
##### 4
$$T(n)=3\cdot T\bigg(\frac{n}{9}\bigg)+n$$
Si può applicare il *teorema master* ? :
- [ ] La forma è simile a : $a\cdot T(\frac{n}{2})+c$
- [ ] $f(n)\ge 0$ 
- [ ] $a\ge 1$ 
- [ ] $b\gt 1$


Avendo verificato che si può applicare il *teorema master* andiamo a verificare in che caso ci troviamo 

+ $a=3$
+ $b=9$
+ $f(n)=n$
+ $d=\log_9 3=\frac{1}{2}$

Come si confronta $n^d$ a $f(n)$
+ $g(n)=n^{\frac{1}{2}}=\sqrt n$
+ $f(n)=n$

Poichè $n$ ( $split+merge$ ) domina su $\sqrt n$ ( parte ricorsiva ) siamo nel caso in cui lo $split+merge$ domina sulla parte ricorsiva 

Troviamo quindi l'$\epsilon$ 
$$n=\Omega\Big(n^{\frac{1}{2}+\epsilon}\Big)$$
$$1=\frac{1}{2}+\epsilon$$
Quindi scielgiendo 
$$\epsilon=\frac{1}{2}$$
Abbiamo soddisfatto la condizione

Dobbiamo però considerare la *condizione ausiliaria* :
Dobbiamo trovare un $c$ t.c. :
$$\exists\space 0\lt c\lt1 \quad \text{con $n$ sufficentemente grande tale che :}$$
$$a\cdot f\bigg(\frac{n}{b}\bigg)\le c\cdot f(n)$$

Sostituendo abbiamo che :
$$3\cdot\frac{n}{9}\le c\cdot n$$
$$\frac{1}{3}\cdot n\le c\cdot n$$
$$\frac{1}{3}\le c$$
Quindi la condizione risulta verificata per $c=\frac{1}{3}$

Possiamo quindi conludere che la complessità risulta essere :
$$T(n)=\Theta(n)$$
Poichè deve essere che $T(n)=\Theta(f(n))\quad f(n)=n$
#### Dimostrazione Teorema Master

Come *prima* cosa dobbiamo trasformare la formula generale di un algoritmo divide et impera da una formula ricorsiva ad una formula non ricorsiva
*Sucessivamente* dovremo dimostrare il Teorema per ogni suo caso
##### Primo step

Avendo una formula generale di un algoritmo divide et impera :
$$
T(n)=a\cdot T\Big(\frac n b\Big) + f(n)
$$
Esplicitiamo la ricorsione attraverso l'albero delle ricorsioni 

![[RerTreeMaster.excalidraw]]

Al livello $i$ avremo che : 
+ il numero di nodi persenti a quelli livello sono : $a^i$
+ la dimensione del problema risolto da ogni nodo è pari a : $\frac{n}{b^i}$
+ il tempo necessario per lo svolgimento di ogni nodo sarà quindi una funzione della dimensione del sottoproblema : $f\Big(\frac n {b^i}\Big)$ 

Il tempo totale di svolgimento dell'algoritmo sarà quindi la somma delle complessità di ogni livello ossia il prodotto del numero di nodi per ogni livello e il loro contributo temporale :
$$T(n)=\sum_{i=0}^{n°\ \text{livelli}}a^i\cdot f\Big(\frac{n}{b^i}\Big)$$
Il tempo totale dipede ancora da una variabile $n°\ \text{livelli}$ , questa può essere dedotta capendo quando la ricorsione si ferma ( ossia i suoi *casi base* )
In questo caso il *caso base* è quando la dimensione del sottoproblema risulta essere $1$ quindi troviamo il valore di $i$ ( $n° \text{livelli}$ )
$$
\frac{n}{b^i}=1 \iff n=b^i\iff i= \log_bn
$$
La funzione diventa quindi :
$$
T(n)=\sum_{i=0}^{\log_bn}a^i\cdot f\Big(\frac{n}{b^i}\Big)
$$
Calcoliamo ora il numero dei *nodi foglia* :
$$
n_{foglie}=a^{\log_bn}=a^{(\log_ba\cdot\log_an)}=(a^{\log_an})^{\log_bn}=n^{\log_bn}=n^d
$$
Il numero totale di nodi è invece :
$$
n_{nodi}=\sum_{i=0}^{\log_bn}a^i
$$
Essendo assimilabile ad una progressione geometrica possiamo semplificare nel seguente modo :
$$\frac{a^{log_bn+1}-1}{a-1}=\frac{a\cdot a^{log_bn}-1}{a-1}=\frac{a\cdot n^d-1}{a-1}$$
Essendo $a$ e $1$ costanti possiamo non considerarle nel calcolo finale , avremo quindi che 
$$
n_{nodi}=\Theta\big(n^d\big)
$$
Avremo quindi che il numero di vertici cresce asintoticamente come $n^d$ e rappresenta la dimensione complessiva dell'albero 
##### Dimostrazione dei casi

###### Caso 1

Per *ipotesi* sappiamo che $\exists\ \epsilon\gt 0,\ f(n)=O(n^{d-\epsilon})$
La *Tesi* che dobbiamo dimostrare è : $T(n)=\Theta(n^d)$

Applichiamo l'*ipotesi* alla complessità totale del livello $i$-esimo :
$$
a^i\cdot f\Big(\frac{n}{b^i}\Big)=a^i\cdot O\Bigg(\Big(\frac{n}{b^i}\Big)^{d-\epsilon}\Bigg)
$$
$$
=O\Bigg(a^i\cdot\Big(\frac{n}{b^i}\Big)^{d-\epsilon}\Bigg)
$$
$$
=O\Bigg(a^i\cdot\bigg(\frac{n^{d-\epsilon}}{{(b^i)}^{d-\epsilon}}\bigg)\Bigg)
$$
$$
=O\Bigg(a^i\cdot\bigg(\frac{n^{d-\epsilon}}{{(b^i)}^{d}{(b^i)}^{-\epsilon}}\bigg)\Bigg)
$$
Ora essendo che possiamo scambiare gli esponenti in ${(b^i)}^{d}\implies {(b^d)}^{i}$
Ricordandoci ora che $d=\log_ba$ avremo che : ${b^i}^d=a^i$ questo si semplifica con l'$a^i$ che moltiplica la frazione 
$$
=O\Bigg(\frac{n^{d-\epsilon}}{{(b^i)}^{-\epsilon}}\Bigg)
$$
$$
=O\bigg((b^i)^\epsilon\cdot n^{d-\epsilon}\bigg)
$$
Calcoliamo ora la sommatoria dei livelli per trovare la complessità totale :
$$
=\sum_{i=0}^{\log_bn}O\Big((b^\epsilon)^i\cdot n^{d-\epsilon}\Big)
$$
$$
=O\Bigg(n^{d-\epsilon}\sum_{i=0}^{\log_bn}(b^\epsilon)^i\Bigg)
$$
La sommatoria risulta essere una progressione geometrica e si può quindi esprimere come :
$$
=O\Bigg(n^{d-\epsilon} \frac{(b^\epsilon)^{\log_bn+1}-1}{b^\epsilon-1}\Bigg)
$$
$$
=O\Bigg(n^{d-\epsilon} \frac{b^\epsilon\cdot(b^\epsilon)^{\log_bn}-1}{b^\epsilon-1}\Bigg)
$$
$$
=O\Bigg(n^{d-\epsilon} \frac{b^\epsilon\cdot(b^{\log_bn})^{\epsilon}-1}{b^\epsilon-1}\Bigg)
$$
$$
=O\Bigg(n^{d-\epsilon} \frac{b^\epsilon\cdot n^{\epsilon}-1}{b^\epsilon-1}\Bigg)
$$
$b^\epsilon$ è trascurabile così come $1$ poichè costanti , avremo quindi :
$$
=O(n^{d-\epsilon}\cdot n^\epsilon)=O(n^d)
$$
Per verificare la *tesi* bisognerebbe verificare anche il caso in cui $\Omega(n^d)$ ma questo risulta vero poichè l'algoritmo dovrà visitare tutti i nodi foglia ( $n^d$ ) quindi ci vorra *almeno* un tempo uguale a $n^d$ di conseguenza possiamo concludere che :
$$T(n)=\Theta(n^d)$$
###### Caso 2 

Per *ipotesi* sappiamo che $\exists\ \epsilon\gt 0,\ f(n)=O(n^{d})$
La *Tesi* che dobbiamo dimostrare è : $T(n)=\Theta(n^d\cdot \log n)$

Come prima cosa applichiamo l'*ipotesi* alla complessità totale al livello $i$-esimo
$$
a^i\cdot f\Big(\frac{n}{b^i}\Big)=a^i\cdot \Theta\Bigg(\Big(\frac{n}{b^i}\Big)^{d}\Bigg)
$$
$$
= \Theta\Bigg(a^i \cdot\Big(\frac{n}{b^i}\Big)^{d}\Bigg)
$$
$$
= \Theta\Bigg(a^i \cdot\bigg(\frac{n^d}{{(b^i)}^d}\bigg)\Bigg)
$$
Come prima ${(b^i)}^d$ può essere semplificato con $a^i$ , avremo quindi
$$
= \Theta\big(n^d\big)
$$
Infine per dimostrare la *tesi* ci basterà svolgere la sommatoria :
$$
\sum_{i=0}^{\log_bn}\big(\Theta\big(n^d\big)\big)=
\Theta\Bigg(\sum_{i=0}^{\log_bn}n^d\Bigg)
$$
$$
=\Theta(n^d\cdot(\log_bn+1))=\Theta(n^d\cdot\log_bn)
$$
###### Caso 3

Per *ipotesi* sappiamo che $\exists \ 0 < c < 1$ e $f(n)=\Omega(n ^ {d+\epsilon})$  
La *Tesi* che dobbiamo dimostrare è $T(n)=f(n)$ 
$$a\cdot f\bigg (\frac{n}{b}\bigg ) \le c \cdot f(n)$$
Dove $a\cdot f\big (\frac{n}{b}\big )$ rappresenta il costo totale del $1°$ livello e $c \cdot f(n)$ rappresenta il costo totale della prima chiamata ricorsiva 

La disequazione rappresenta che il tempo del primo livello è minore del tempo per finire la $1°$ chiamata ricorsiva
$$\forall i \quad a^i\cdot f\bigg(\frac{n}{b^i}\bigg) \le c^i \cdot f(n)$$
Dove $i$ rappresenta l'$i$-esimo livello 
$$T(n) = \sum_{i=0}^{\log_b a} a^i \cdot f\bigg(\frac{n}{b^i}\bigg)$$
Questa sommatoria sarà per definizione 
$$\le \sum_{i=0}^{\log_b a} c^i \cdot f\big(n\big)$$
$$\le f(n) \cdot \sum_{i=0}^{\log_b a} c^i$$
$\sum_{i=0}^{\infty} c^i$ sarà sicuramente maggiore di $\sum_{i=0}^{\log_b a} c^i$ possiamo quindi sostituirla visto che sicuramente sarà maggiore di $a\cdot f(\frac{n}{b})$ 

Visto che $\sum_{i=0}^{\infty} c^i$ è una prograssione geometrica convergente per $c<1$ potremmo sostituirla con : $$\frac{1}{1-c}$$
avremo quindi che :
$$\le f(n)\frac{1}{1-c}$$
$$\implies T(n) = O(f(n))$$
Dobbiamo solo dimostrare che : 
$$T(n) = \Omega(f(n))$$
Questo è vero poichè se 
$$T(n) = a\cdot T\bigg(\frac{n}{b}\bigg)+f(n)$$
Per *ipotesi* e sapendo che $a\cdot T(\frac{n}{b})$ è $\ge 0$ allora questo implicherà che $T(n)$ sarà sicuramente maggiore di $f(n)$

Possiamo quindi concludere che :
$$T(n) = \Theta(f(n))$$
