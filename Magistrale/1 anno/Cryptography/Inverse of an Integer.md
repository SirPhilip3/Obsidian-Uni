# Euclidian Algorithm

It calculates the *greates common divisor* ( *GCD* ) of two integers ( $a,b$ )

```python
def Euclid(c,d) :
	while d != 0:
		tmp = c % d
		c = d
		d = tmp
	return c
```

>[!example] 
>
>`gcd(17,2)`
>```
>d = 2 != 0 
>	tmp = 17 % 2 = 1
>	c = 2
>	d = 1
>d = 1 != 0
>	tmp = 2 % 1 = 0
>	c = 1
>	d = 0
>return 1 
>```
>

**Complexity** : $O(k^3)$ , where $k$ is the number of bits
# Extended Euclidian Algorithm

Finds a way to rapresent the *GCD* in terms of $a$ and $b$ such that a$gcd(a,b) = 1$

>[!note]
>$(s × n) + (b × t) = 1$
>Now apply $\mod n$ to both sides:  
>$(s × n) + (b × t) \mod n ≡ 1 \mod n$  
>This is the same as:  
>$(s × n) \mod n + (b × t) \mod n ≡ 1 \mod n$  
>$s × n$ is divisible by $n$ (since you multiply s by n), so $s × n \mod n ≡ 0 \mod n$:  
>$0 \mod n + (b × t) \mod n ≡ 1 \mod n$  
>This is the same as  
>$(b × t) \mod n ≡ 1 \mod n$
>Where $t$ is the multiplicative inverse of $b$ 

Where 

#todo 

```python
def EuclidExt(c,d):
	d0 = d
	e = 1
	f = 0
	while d != 0:
		q = c//d # integer division
		tmp = c - q*d # this is c % d
		c = d
		d = tmp
		tmp = e - q*f # new computation for the inverse
		e = f
		f = tmp
	if c == 1:
		return e % d0 # if gcd is 1 we have that e is the inverse
```

>[!example] 
>#todo

