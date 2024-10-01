---
creation: 2024-10-01T10:49:00
---
Ci sono due tipi di bit di parità :
+ *parità pari* ( even parity ) : Se ho un numero di bit posti ad `1` pari aggiungo un ulteriore `0` alla fine 
 + *parità dispari* ( odd parity ) : Se ho un numero di bit posti ad `1` pari aggiungo un ulteriore `1` alla fine , in modo da rendere il numero di bit a `1` dispari

>[!example] 
>Assumiamo che l'informazione è `0011011`
>+ *odd parity* : i dati diventano `00110111`
>+ *even parity* : i dati diventano `00110110` 

>[!warning] 
>Se ci sono un numero *pari* di errori il *parity bit* non può riconoscerli 
>>[!example] 
>>1. Original message : 00110101
>>2. Aggiungendo il *parity bit* : 00110101*0*
>>3. Messaggio ricevuto : *11*1101010 ( il *parity bit* è ancora valido , l'*errore* non viene identificato )
>
>L'*errore* può trovarsi nel *parity bit* stesso
>4. 0*1*110101*1* ( errore non identificato )

