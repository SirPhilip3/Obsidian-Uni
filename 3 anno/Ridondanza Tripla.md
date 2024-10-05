---
creation: 2024-10-05T17:25:00
---
Il metodo più semplice per poter non solo riconoscere gli errori ma anche correggerli è la **ridondanza tripla** :
>[!example] 
>+ Mappa ogni `1` con `111`
>+ Mappa ogni `0` con `000`
>
>Se viene ricevuto `010` molto probabilmente vi è stato un errore nella trasmissione di uno `0`
>>[!note] 
>>Si assume che vi siano pochi errori , infatti `010` potrebbe essere un `1` con 2 bit errati 
>
>>[!warning] 
>>Si perde sempre 2/3 del [[Bit-rate]]

