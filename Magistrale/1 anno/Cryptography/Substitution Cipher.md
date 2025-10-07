## Substitution Cipher

We can overcome the limitations of the *shift cipher* by just using a *generic permutation* of the alphabet used to *encode* the message

>[!example] 
>
>```
>ABCDEFGHIJKLMNOPQRSTUVWXYZ
>SWNAMLXCVJBUYKPDOQERIFHGZT
>```

>[!note] 
>For the *decription* we simply invert the substitution

$K = \{p | p\text{ is a permutaion of }0,\dots,25\}$

>[!note] 
>We use $0,\dots,25$ just because they rapresent the indices of the letter of the alphabeth

$E_k(x) = p(x)$
$D_k(y) = p^{-1}(y)$ 

Let's verify the propieties :
1. 
$$D_p(y) = D_p(E_p(x)) = D_p(p(x)) = p^{-1}(p(x)) = x$$
2. Since we have a permutation of the alphabet as the *key* we will than have a space of the keys equal to : $26!$ 
>[!note] 
>It's now *infeasable* to use **brute force** 

### Attacks

Since the subtitution of the letters remains constant for all the *ciphertext* the statistics of the original *plaintext* will be retained

We can than use **statistical cryptanalysis** in order to decript a *ciphertext* assuming that : 
+ we know the used *chiper*
+ we know the *language* used in the *plaintext*

