---
creation: 2024-11-12T09:34:00
---
**One-Time-Pad** è un *cifraio* perfetto 
1. **Alice** genera un stringa *random* di $n$ bit , questa viene inviata a **Bob** attraverso un canale sicuro ( assumiamo che **Eve** non possa intercettarlo )
2. Per *criptare* un messaggio $M$ di $m<n$ bit **Alice** prende una porzione $K'$ di $K$ di lunghezza $m$ e calcola $C = M \oplus K'$ ( dove $\oplus$ è lo `xor` )
3. La porzione $K'$ non potrà poi essere più riutilizzata

>[!example] 
>Abbiamo $K=1100100111010110$ e $M=00101101$
>$C=1001001 \oplus 00101101 = 11100101$
>$M$ non può essere ricavato da $C$ senza conoscere la chiave $K$ , i prossimi messaggi dovranno essere criptati con la parte rimanente della $K$
## Security

>[!example] 
>Assumiamo il seguente esempio : 
>$C=101$
>Ciò significa che la *key* deve essere di lunghezza $3$ e **Eve** può facilemente fare *brute force* nel seguente modo : 
>
>| $K$ | $C$ | $M' = K \oplus C$ |
>| :-: | :-: | :---------------: |
>| 000 | 101 |        101        |
>| 001 | 101 |        100        |
>| 010 | 101 |        111        |
>| 011 | 101 |        110        |
>| 100 | 101 |        001        |
>| 101 | 101 |        000        |
>| 110 | 101 |        011        |
>| 111 | 101 |        010        |
>

Notiamo però che ogni $K$ candidata mappa ad un solo `plaintext`  , ciò significa che non c'è nessun `plaintext` candidato che ha una probabilità maggiore di un'altra

>[!note] 
>*Brute forcing* non da nessun vantaggio

## Limitazioni

Il problema princiaple con **OTP** è che **Alice** per mandare un messaggio di lunghezza $N$ ha bisogno di un canale sicuro per mandare una *key* di lunghezza $N$ 

Visto che lunghezza di $N$ equivale a quella di $M$ potremmo mandare direttamente $M$

>[!warning] 
Una soluzione potrebbe essere riutilizzare la stassa chiave , ma in questo caso porteerbbe alla ripertizione di *byte* ritornando ad un algortimo di [[Sostituzione]]

### Reducing the Key length

Immaginiamo che **Eve** ha il messaggio *cifrato* $C$ , e sa che è in Italiano 

Assumiamo che la *key* sia lungha $8$ bit e che veiene utilizzata per tutti i char del messaggio 

![[Pasted image 20241112103011.png]]

>[!note] 
>
>Notiamo che vi sono dei byte ripetuti , questo reintroduce il problema degli algoritmi di [[Sostituzione]] , reintroducendo la correlazione tra $M$ e $C$ 
