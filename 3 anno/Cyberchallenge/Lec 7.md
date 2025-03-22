cryptography 2

diffie hellman , rsa

in diffiehelman -> n approx 3072 sicurezza ismile a AES 128

se eve può modificare il traffico durante diffiel hellman transction può scieglere una key che gli piace

RSA 

private can only decypher -> public cypher
oppure inverso

fermat eulero -> $a^{\phi(n)}\cong 1 (\mod{n})$
congruo a 1

oppute se $a^x \cong a^y mod(n)$ allora è possibile solo se $x \cong y mod(\phi(n))$

https://cryptohack.org/challenges/

e = 3 -> minimo utilizzabile come esponente  -> usato 65537 > perchè la sua rappresentazione ha molti 0 ez per la cpu 

int py > arb length

attachi contro rsa 

se p e q sono 2 numeri primi vicini -> prendiamo il punto medio 
$p=(a+b), q=(a-b)$ 

$N = pq$ -> $a^2 -N = b^2$ 

usare stesso numero primo più di una volta 

$N_1 = pq$ , $N_2=pr$ se vedo sia n1 che n2 posso trovare massimo comun divisore tra i due -> sarà p

se genera molte key -> riutilizzando numero primo possiamo testare paia di ni e nj e con qualche prob posso trovare p

riutilizzo modulo -> (N, e1) , (N,e2) N -> modulo riustao-> cifriamo stesso plain con entrambe le key

xgcd -> extended  -> due par che fa diventare vera u e1 + v e2 = 1

$c1 ^ u \cdot c2 ^ v = m ^ {e_1 \cdot u} \cdot m ^ {e_2 \cdot v}$ per xgcd -> $m^1$ 
c -> cyphertext == m\^e1

---

