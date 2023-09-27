# 20/09/2023

## Definizioni

+ **Algoritmo corretto**
	Un algoritmo si dice corretto se per ogni input si ferma e da in output il risultato corretto ( si dice che l'algoritmo risolve il problema computazionale )
+ **Complessità computazionale** 
	.................

Esempio : 

**Calcolo numeri di Fibonacci**

Definizione :
$$F_n = \begin{cases} 1 &\text{if } n = 1&\text{or} &n=2  \\ F_{n-1} + F_{n-2} &\text{if } n\geq3 \end{cases}$$

Definizione attraverso la *sezione aurea*
Equazione fondamentale : 
$$x^2=x+1$$
$$x^2-x-1=0$$
$$x_{12}=\frac{1\pm \sqrt{5}}{2}$$
$$x_1\simeq1,618 = \intop$$
$$x_{2}\simeq -0,618 =\oint$$
I numeri di *Fibonacci* possono essere calcolati con $\oint$ e $\intop$  
$$F_n=\frac{1}{\sqrt{5}}\cdot(\intop^n-\oint^n)$$
Sviluppiamo un algoritmo che sfrutti queste formule :

```Fib1(int n) -> int```
	```return``` $\frac{1}{\sqrt{5}}\cdot(\intop^n-\oint^n)$

Dim *correttezza* per **induzione** 

