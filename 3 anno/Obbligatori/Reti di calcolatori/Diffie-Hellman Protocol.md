---
creation: 2024-11-12T11:49:00
publish: true
---
Questo protocollo ci permette di negoziare una *chiave segreta simmetrica* tra **Alice** e **Bob** senza condividere informazioni segrete 

Si basa sul [[Discrete Logarithm Problem]]

## Algorithm

1. **Alice** scieglie $n$ primo , $a$ randomico e $g$ [[Radice prima modulo n]] 
2. **Bob** genera un numero random $b$ 

>[!important] 
>$a$ e $b$ sono numeri segreti , non lasciano mai **Alice** e **Bob** 

3. **Alice** manda $m,g,n$ a **Bob** , dove $m=g^a\mod{n}$
4. **Bob** ritorna $r=g^b\mod{n}$ ad **Alice**
5. La chiave generata sarà $K=g^{ab}\mod n$   

![[Pasted image 20241022122750.png]]

>[!important] 
>
>Anche se **Eve** riesce ad intercettare $m,g,n,r$ per via della difficoltà del [[Discrete Logarithm Problem]] non riuscirà ad ottenere $a$ o $b$ 
>

>[!warning] 
>
>Se **Eve** può modificare il traffico , può far credere che **Alice** e **Bob** stiano parlando tra di loro quando invece stanno parlando con **Eve** , in questo modo **Eve** ha le chiavi di criptografia sia di **Alice** che di **Bob**

>[!important] 
>
>*Diffie-Hellman* funziona solo se esiste uno strumento che garantisce anche [[Data authentication]] 