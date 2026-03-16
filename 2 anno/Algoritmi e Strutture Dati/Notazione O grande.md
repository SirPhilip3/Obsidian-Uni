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

Per $O\big(g(n)\big)$ è possibile trovare una costante $c\gt 0$ per cui per un $n$ sufficentemente grande si verifichi la seguete relazione : $c\cdot g(n)\le f(n)$   ( Ossia che $f(n)$ stia sopra $c\cdot g(n)$  ) 

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
$$log\ n =O(\sqrt n)$$
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
Questo è evidentemente *assurdo* , abbiamo quindi dimostrato che : $o(g(n))\ \cap \ \Omega(g(n))=\emptyset$

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
