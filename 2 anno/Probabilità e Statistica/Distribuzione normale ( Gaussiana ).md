#### Distribuzione normale ( Gaussiana )

Una variabile aleatoria $X$ ha *distribuzione normale* o *gaussiana* , indicata con :
$$
X\sim N(\mu,\sigma^2)
$$
La sua funzione di ripartizione è :
$$
f(x)=c\cdot e^{-\frac1 2\Big(\frac{(x-\mu)^2}{\sigma^2}\Big)}, \quad x\in \mathbb{R},\mu\in\mathbb{R},\sigma\gt 0
$$
![[Pasted image 20231129143220.png]]

La *distribuzione normale stadard* è :
$$
X\sim N(0,1)
$$
Avrà come funzione di ripartizione :
$$
f(x)=c\cdot e^{-\frac{x^2}{2}}
$$
Troviamo ora $c$ utilizzando la proprietà che è una funzione di densità e quindi deve soddisfare la seguente equazione :
$$
c\int_{-\infty}^{+\infty} e^{-\frac{x^2}{2}}dx=1
$$
$$
c\cdot\sqrt{2\pi}=1
$$
$$
c=\frac 1 {\sqrt{2\pi}}
$$
Quindi avremo che :
$$
f(x)=\frac 1 {\sqrt{2\pi}}\cdot e^{-\frac{x^2}{2}}
$$

La *funzione di ripartizione* risulta essere :
$$
\int_{-\infty}^x\frac 1 {\sqrt{2\pi}}\cdot e^{-\frac{t^2}{2}}dt
$$
In questo caso non si può svolgere l'integrale ( non esiste una funzione analitica che la deriva ) e quindi la *funzione di ripartizione* viene espressa come integrale

##### Proprietà

###### Media

$$
\mathbb{E}[X]=\mu
$$
###### Varianza

$$
Var[X]=\sigma^2
$$
###### Funzioni R

Per calcolare : $\mathbb{P}[X\le x]$

```R
pnorm(x, mean , sd)
```
Dove :
$x$ : valore di cui volgiamo calcolare $\mathbb{P}[X\le x]$
$mean$ : media della normale $\mu$
$sd$ : deviazione standard ( $\sqrt{Var}$ ) 

Per calcolare : $\mathbb{P}[X= x]$

```R
dnorm(x, mean , sd)
```

Si può inoltre calcolare il *quantile* relativo ad una determinata probabilità con il seguente comando : 

```R
qnorm(p, mean , sd)
```

>[!note] 
>Gli stessi comandi sono utilizzati per la normale standard con $mean=0$ e $sd=1$