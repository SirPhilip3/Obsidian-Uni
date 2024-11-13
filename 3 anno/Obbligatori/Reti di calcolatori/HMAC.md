---
creation: 2024-11-11T14:07:00
publish: true
---
In **HMAC** ( **Hashed Message Authentication Code** ) , *Alice* e *Bob* prima si mettono daccordo su una *secret key* $K$ e una funzione di hashing cryptografica sicura $H()$ 

La *secret key* $K$ verrà utilizzata come ulteriore input nella [[Hash Functions|Funzione di Hashing]] :
$$
D=HAMC(M,K) = H((K\oplus opad )|(K\oplus ipad)|M)
$$
Dove : 
+ `opad` e `ipad` sono sequenze di padding usate per allineare $K$ con la lunghezza dell'output di $H()$ , se $K$ è più grande del *digest* verrà sostituita con $H(K)$

![[Pasted image 20241111142505.png]]

Ora anche se **Eve** intercetta il messaggio e il *digest* , non può ricalcolare l'hash poichè necessita anche della *chiave* $K$ che solo **Bob** e **Alice** conoscono

>[!warning] 
>**Alice** e **Bob** hanno bisogno di un canale separato di comunicazione sicuro per scambiarsi la *chiave*

>[!note] 
>**HMAC** garantisce [[Data integrity]] e [[Data authentication]] ma non garantisce [[Secrecy]] 

## Generating Keys

Una *chiave* non dovrebbe essere difficile da indovinare da parte di un attaccante 

Generalmente si dovrebbero creare delle strighe di caratteri random , visto che è difficile ricordare stringhe arbitrarie di byte **Alice** e **Bob** si scambiano una password , poi questa genera una chiave $K$ facendola passare per una [[Hash Functions|Funzione di Hashing]] 

>[!note] 
>Visto che la [[Hash Functions|Funzione di Hashing]] ha un comportamento pseudo-randomico , conoscere l'hash non da nessuna informazione riguardante la password 

>[!warning] 
>
>Un attaccante può fare un attacco di *brute force* su un insieme di password già conosciute , per questo necessitiamo di password complesse :
>+ $l \ge 15,20$
>+ Deve essere fatta di lettere , numeri e simboli in modo da aumentare il tempo che ci mette l'attaccante per generare le password 
>+ Non deve essere presente in un dizionario di password 

