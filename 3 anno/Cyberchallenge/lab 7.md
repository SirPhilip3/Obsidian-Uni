Euclide algo impl

```python
def my_gcd(a,b):
	while b != 0:
		q,r = divmod(a,b)
```

```python
def xgcd(a,b): # a * u + b * v = g se a e b coprimi g=1
	prevx, x = 1, 0
    prevy, y = 0, 1
    while b:
        q, r = divmod(a, b)
        x, prevx = prevx - q * x, x
        y, prevy = prevy - q * y, y
        a, b = b, r
    return a, prevx, prevy
```

inverso modulare = $5 \cdot x \equiv 1 \mod 21$ -> $x\equiv 5^{-1}$
$11 \equiv x \mod{6}$ resto div per 6 py $\%$ 

$7^{17}\equiv 7$ -> $7^{-1} \cdot 7^{17} \equiv 7 \cdot 7^{-1}$ ->$7^{16} \equiv 1$ 

qualsiasi cosa ^ (p-1) mod p = 1
piccolo th di fermat 

inverso mult  di un qualsis n -> primo dei due coeff 
se num negatizo -> inverso è mod il numero primo -> tra catena di congruenze -> predi num compreso tra 0 e p

attachi contro rsa
