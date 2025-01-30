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
>3. Scegliamo un intero $e$ in modo che $2 < e <\phi(n)$ che non abbia nessun divisore in comunue con $\phi(n)$ ( sono [[Coprimi]] )
>4. Determina $d$ in modo che $d\cdot e \mod{\phi(n)}=1$ , ossia che $d$ e $e$ sono inversi in modulo $\phi(n)$

$(e,n)$ è la *public key* 
$d$ è la *private key*

>[!note] 
>
>La generazione di `Pub_A` e `Priv_A` avviene nello stesso momento , queste sono il risultato di un processo matematico , c'è un connessione matematica tra di loro , non possono essere generati indipendentemente l'uno dall'altro

>[!important] Encryption e Decryption
>
>Se **Bob** vuole mandare un messaggio $M$ ad **Alice** deve *cifrarlo* nel seguente modo: 
>$$C=M^e \mod{n}$$
>**Alice** riceverà il messaggio e lo *decifrerà* nel seguente modo : 
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

>[!warning] Attacchi
>
>Se **Eve** controlla il canale di comunicazione , essa può intercettare il pacchetto con la richiesta da parte di **Alice** di `Pub_B` e rimpiazza `Pub_B` con `Pub_E` , **Alice** a questo punto pensa che la chiave pubblica di **Bob** sia `Pub_E` 
>
>Ora se **Alice** vuole cifrare qualcosa per **Bob** userà la chiave pubblica di **Eve** che lo decifrerà , e cifrerà con `Pub_B` e lo manderà a **Bob**
>
>**Eve** può leggere e scrivere qualsiasi messaggio di **Alice** o **Bob** tra di loro
>
>![[Screenshot 2024-11-19 110512.png]]

![[Digital Signature]]

## Performance

Eseguendo il comando `openssl speed` otteniamo i seguenti risultati

| `key bits` | `sign`    | `verify`  | `sign/s` | `verify/s` |
| ---------- | --------- | --------- | -------- | ---------- |
| ~~512~~        | ~~0.000048s~~ | ~~0.000003s~~ | ~~20740~~    | ~~333503~~     |
| ~~1024~~       | ~~0.000103s~~ | ~~0.000007s~~ | ~~9716~~     | ~~149899~~     |
| 2048       | 0.000708s | 0.000021s | 1412     | 47911      |
| 3072       | 0.002114s | 0.000043s | 473      | 23413      |
| 4096       | 0.004975s | 0.000072s | 201      | 13873      |
Dove :
+ *sign* = encryption
+ *verify* = decryption
+ ~~striked~~ = non più utilizzabili perchè troppo insicure

Notiamo che la che l'*encryption* è sempre più veloce della *decryption* 

>[!warning] 
>Ricordando che $d\cdot e = k \cdot \phi(n) +1$ per un qualche $k$ e che $\phi(n)$ deve essere un numero grande 
>
>Significa che se $e$ è piccolo $d$ deve essere grande , ma $d$ deve per forza essere **grande** poichè questo è un *segreto* e quindi deve essere difficile da indovinare 
>
>Visto quindi che $e$ può essere piccolo generalmente le implementazioni di [[RSA]] scelgono un numero fisso $e=2^{16}+1 = 65537$ che è *primo* 
>
>Visto che le operazioni di *encryption* e *decryption* sono delle esponenziazioni se usiamo un $e$ minore richiederanno meno tempo

>[!danger] 
>Visto che *decryption* è più difficile un attaccante può fare un attacco *DoS* mandando spropositate quantità di traffico cifrato 

>[!note] 
>Generalmente *encryption* di grandi file è molto lenta , per questo nelle implementazioni si preferisce generare un *digest* dei dati e solo questo verrà *cifrato* :
>+ $C = E(Priv_A.T = H(M))$
>+ Quando **Bob** riceve sia $M$ che $C$ calcolerà  $T'=D(Pub_A,C)$ e controllerà che $T'=H(M)$ 

## Note on Random Numbers

>[!warning] 
>Il $\mod{n}$ non dovremme mai essere riusato

Infatti se si generano due *key* con lo stesso $n$ è facile fattorizzare $n$ e invertire $e$ 

$n$ viene quindi scelto a *random* nel seguente modo : 
1. Prendi un a *random* un grande intero $p$ 
2. Fai un testi di *primarità*
