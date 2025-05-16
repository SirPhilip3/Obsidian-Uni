---
publish: true
---
Tring to approximate $\pi$ , by dropping $N$ *needles* of unit ( $1$ ) length in a fllor that is subdivided in boards of witch theys width is $2$ units

Some of the needle will fall between boards 
>[!important] Leclerc Theorem
>If we drop 1 needle of length $l$ on the floor and the boards are ata a distance $d$ the probability thatit will cross the board is $2 \cdot l / \pi \cdot d$ 

>[!example] 
>In our case $l=1$ and $d=2$ so $(2 \cdot l) / (\pi \cdot d) = (2 \cdot 1 )/ (2 \cdot \pi) = 1 / \pi$

Then if we drop $n$ needles the number of needle that will cross the board is $k=n/\pi$ 

>[!important] Buffon Algorithm 
>With a high enugh number $n$  than we can estimate $\pi \approx n / k$ 
>

Now the probability that one will fall crossing two boards will be $p$ ( bernuollian varaible =1 ) and the opposite otherwise 

For the *Leclerc* *theorem* $p$ will be $1/\pi$ and so the vairance will be $1/\pi \cdot(1-1/\pi)$

Than given $X$ the binomial variable that describes the *mean* of $n$ drops with $k$ seccesses we have : 
$$X = \sum^{n}_{i=1}X_i/n : \Pr\bigg[X=\frac{k}{n}\bigg] = \binom{n}{k}\bigg(\frac1\pi\bigg)^k\cdot \bigg(1-\frac{1}{\pi}\bigg)^{n-k}$$
Than if we want to have a precision of $\ge 99\%$ we will have : $$\Pr[|X-\frac{1}{pi}|< \epsilon]$$ With number of needles : $$n > \frac{1440}{\epsilon^2}$$ 
 >[!note] Note
 >We can than define an $\epsilon$ , the error that we want to achive 
 
 