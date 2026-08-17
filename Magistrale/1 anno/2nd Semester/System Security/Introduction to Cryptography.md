---
publish: true
---
A *cipher* is defined through two functions :
+ **Encryption** : given a *plaintext* and *key* $K_{1}$ returns a *ciphertext* :
$$
E_{K_{1}}(X) = Y
$$
+ **Decryption** : given a *ciphertext* and a *key* $K_{2}$ returns a *plaintext* :
$$
D_{K_{2}}(Y) = X
$$
Keys $K_{1}$ and $K_{2}$ are *related* :
$$
D_{K_{2}}(E_{K_{1}}(X))=X
$$
>[!note] 
>+ When $K_{1}=K_{2}$ we have a *symmetric* key cipher like [[AES]]
>+ When $K_{1}\neq K_{2}$ we have an *asymmetric* key cipher like [[Magistrale/1 anno/1st Semester/Cryptography/RSA|RSA]] 

>[!important] 
>It should be *infeasible* to compute $X$ or $K_{2}$ from $Y$ even knowing other pairs $(X_{1},Y_{1}), \dots,(X_{n}, Y_{n})$

---
We need *collision resistant hash functions*

