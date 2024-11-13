---
creation: 2024-11-13T09:05:00
publish: true
---
**RSA** ( **Rivest-Shamir-Adelmann** ) è l'approccio più conosciuto alla **public key encryption**

Gli step sono i seguenti : 

>[!important] Creation of Keys
>
>1. Sciegliamo due grandi numeri primi $p$ e $q$ , questi devono rimanere **segreti** 
>2. Computiamo $n=pq$ e la [[Funzione di Eulero]] : $\phi(n)=(p-1)(q-1)$ 
>3. Sicegliamo un itero $e$ in modo che $2 < e <\phi(n)$ che non abbia nessun divisore in comunue con $\phi(n)$ ( sono [[Coprimi]] )
>4. Determina $d$ in modo che $d\cdot e \mod{\phi(n)}=1$ , ossia che $d$ e $e$ sono inversi in modulo $\phi(n)$

$(e,n)$ è la *public key* 
$d$ è la *private key*

>[!note] 
>
>La generazione di `Pub_A` e `Priv_A` avviene nello stesso momento , queste sono il risultato di un processo matematico , c'è un connessione matematica tra di loro , non possono essere generati indipendentemente l'uno dall'altro

>[!important] Encryption e Decryption
>
>Se **Bob** vuole mandare un messaggio $M$ ad **Alice** deve *criptarlo* nel seguente modo: 
>$$C=M^e \mod{n}$$
>**Alice** riceverà il messaggio e lo *decripterà* nel seguente modo : 
>$$M = C^d \mod{n}$$

>[!example] 
>
>1. Scegliamo $p=7$ e $q=11$ allora $n=77$ e $\phi(n)=60$ 
>2. Scegliamo $e=13$ , questo è *primo* e non ha nessun divisore comune con $60$
>3. Troviamo $d$ in modo che $(d \cdot 13)\mod{60} = 1$ , ossia $d=37$
>>[!note] 
>>
>>Per calcolare questo numero nella vita reale utilizzeremo un algoritmo efficente come : [Extended Euclidean algorithm](https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm) 
>
>Ora assumiamo di avere il seguente $M=00010100$ , ossia $20$ in decimale
>**Encryption** sarà : $C=20^{13} \mod{77} = 69$
>**Decryption** sarà : $M = 69^{37} \mod{77}=20$

Le **Proprietà** che otteniamo sono : 
1. Risulta essere computazionalmente efficente generare `Pub_A` e `Priv_A`
2. Dato `Pub_A` è computazionalmente efficente generare $C=E(\text{Pub\_A}, M)$
3. Dato `Priv_A` è computazionalmente efficente generare $M = D(\text{Priv\_A},C)$ 
4. Dato solo `Pub_A` è [[Computationally Impossible]] derivare `Priv_A`
5. Dato solo `Pub_A` e $C$ è [[Computationally Impossible]] derivare $M$ 

>[!note] 
>
>Rompere **RSA** è considerato [[Computationally Impossible]] per via della *hardness* di  invertire $d\cdot e \mod{\phi(n)}$ ( [[Integer Factorization Problem]] ) per *key* abbastanza lunghe ( più lunghe di 1024 bit )

