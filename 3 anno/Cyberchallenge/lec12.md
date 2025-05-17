cryptography 3

hash 

cryptographic hash :
+ one way 
+ collision resistance 
+ similar message $\neq$ digest

tendenzialmente 1/2 dei bit cambia tra 2 hash 

visto che è impossibile evitare le collisioni vogliamo che almeno l'hash non da nessuna info riguardante la stringa iniziale 

1. impossibile da digest a messaggio originale
2. difficile trovare una collisione
3. difficile trovare una coppia di messaggi che abbiano lo stesso digest

tecniche per trovare collisione -> paradosso dei compleanni

massimizare prob di trovare collisioni

scegliamo $2^{n/2}$ stringhe casuali -> calcoliamo hash e cerchiamo collisioni in questa tabella , se non troviamo -> ripeti 

tempo comunque esponenziale -> basta scegliere $n$ grande 

merkle-damgard -> definisce una compression function -> su 2 stringhe di l=n e le combina in una -> catena di queste per costruire una funzione hash

messaggio originale + padding -> per allineare a lughezza della parola 
dividi in k blocchi ognuno di l della parola
inizia con un Initialization vector (stringa a caso) + primo blocco nella compressio poi risultato + next block etcc 

*compression function* : 
il blocco corrente fa da key , l'intermedio precedente da plaintext e poi xor tra i res e prec inizia con block cyphers 

**MD5** -> produce digest 128bit -> vulnerable 

**SHA1** shattered.io

PSRG -> approx true random oracle -> usano hashing functions per geneare queste hash  

**Machine Authentication Code** 

coppia di funzioni :
+ sign -> prende un messagio + key -> produce tag
+ verify -> messagio + tag + key -> dice se tag era stato prodotto dalla sign con la key 

attacchi :
+ existential forgery -> messaggio valido + tag senza sapere la key 
+ selective forgery -> possiamo dare un tag valido per un messagio senza key
+ universal forgery -> tag per ogni possibile messaggio 

*CBC-MAC*
	messaggio separato in blocchi e xor con una prima key poi xor finale con 2 key
*Nested-MAC*
	messaggio usato come plain key -> passata a catena -> out precedente nei blocchi , alla fine round con 2° key  

senza ultimo passaggio -> 1-choose-message attack ->messagio da 1 blocco -> ottieni il tag -> ora concatenzation (t e t xor m) -> ha stesso tag del messagio ad 1 blocco 

coppia di key condivise

CBC-MAC usata con aes

NMAC -> non usato con aes -> 

HMAC -> applicazioni della compression funciton invece di xor con prec ogni volta 

**lenght extension attack** 

*Digital Signature*

ask to sign $R^eM$ -> otteniamo $RM^d(\mod{n})$ -> inverso moltiplicativo di R per avere la firma del messaggio M 

DSA -> digital signature Algorithm

noone reuse DSA -> k riusato

PRNG attaks

seed -> usato per determinare tutti i numeri pseudocasuali not secure
LCG
-> n(modulo) a b -> coefficenti mult e add -> fissi 
basta osservare i numeri per romperlo 
+ conosciamo tutti i parametri
	+ basta l'ultimo numero -> applichi $x_{k+1}=(a\cdot x_k +b )\mod n$
+ n a known
	+ abbiamo bisogno di $x_{i-1}$ e $x_i$ 
		1. $x_{k}=(a\cdot x_{k-1} +b)\mod n$
		2. $b = (x_k - a \cdot x_{k-1}) \mod n$
+ n known
	+ 3 observation needed
$$\begin{cases}
x_k =(a\cdot x_{k-1} +b)\mod n \\
x_{k-1} = (a\cdot x_{k-2} +b)\mod n
\end{cases}$$
$$x_k - x_{k-1} = a(x_{k-1} - x_{k-2})$$
$$$$
$$a = t2 * t1^{-1} \mod n$$
+ nothing known
da tot osservazioni definiamo sequenza $s$ -> differenza tra $x_k$ e $a x_{k-1} + b$ > non ha modulo 
-> numeri saranno multipli del modulo stesso -> minimo comune divisore -> sarà il modulo -> se $n$ è primo 100% il modulo 

seq -> differenza tra 2 numeri consecutivi -> b si elidono
$t_{i+1} = t_1 \cdot a \mod n$

..

mersenne twister
prime mersenne number $n^2 - 1$ 

osserva 624 numeri 

LFSR

binomio caratteristico -> stato iniziale -> se è noto e l=n bit ci basta avere n output per ricostruire il seed

berlekamp massey 

osserva numeri già usciti per prevedere i prossimi


DSA -> scelta dei parametri pubblici + scelta delle key + sign

comando a caso da firmare -> prendi la firma -> possiamo ritornare alla private key 
una volta con x genriamo la firma per gimme the flag -> e poi gli passi

$$kS = H(m) + xr$$
$$kS - H(m) = xr$$
$$\frac{kS-H(m)}{r} = x$$
g public param

