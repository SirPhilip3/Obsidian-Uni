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

Where 