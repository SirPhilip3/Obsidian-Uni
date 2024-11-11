---
creation: 2024-11-11T14:07:00
---
In **HMAC** ( **Hashed Message Authentication Code** ) , *Alice* e *Bob* prima si mettono daccordo su una *secret key* $K$ e una funzione di hashing cryptografica sicura $H()$ 

La *secret key* $K$ verrà utilizzata come ulteriore input nella [[Hash Functions|Funzione di Hashing]] :
$$
D=HAMC(M,K) = H((K\oplus opad )|(K\oplus ipad)|M)
$$
Dove : 
+ `opad` e `ipad` sono sequenze di padding