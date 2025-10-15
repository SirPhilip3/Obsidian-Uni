---
publish: true
---
## Shift Cipher

The *shift cipher* generalizes the *ceasar cipher* by providing as $k$ a random number $\in Z_{26}$ ( an integer in the range $0-25$ )

$E_k(x) = (x + k)\mod{26}$
$D_k(y) = (y -k)\mod{26}$

>[!note] 
>The propiety $D_k(E_k(x)) = x$ holds
>>[!important] Proof
>> $$D_k(E_k(x)) = D_k((x + k) \mod{26}) = ((x + k) \mod{26} - k) \mod{26} = x \mod{26} = x$$
>>
>

### Attacks

Testing the [[Kerckhoffs principle]] suppose that we know that we are using a *sobstitution cipher* than a simple attack would be **brute force** since the number of *key* to test is low ( $26$ )

>[!note] 
>The [[Kerckhoffs principle]] does not hold