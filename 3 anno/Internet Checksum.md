---
creation: 2024-10-02T09:01:00
---
L'*internet checksum* è utilizzata dall'**Internet Protocol** ( **IP** ) 

>[!note] Definizione
>Aggiungiamo un campo di 16 bit all'header del [[Frame]] contenente il complemento della somma complemento ( $+'$ ) di tutte le parole di 16 bit all'interno del [[Frame]] ( se vi sono riporti li sommiamo ) 

>[!example] 
>>[!note] Costruiamo una checksum di 4 bit invece che 16
>
>$$1100+0011+1010+1110+1001 = 110000$$
>Sommiamo quindi il riporto :
>$$0000 + 11 = 0011$$
>Aggiungiamo all'header il complemento di questo : 
>$$1100$$
>
>Alla fine il frame sarà quindi : 
>
>$$\textcolor{red}{1100} \ 1100\ 0011\ 1010\ 1110\ 1001 $$

Per **Verificare** la checksum semplicemente facciamo la somma complemento di tutti i dati ( anche la checksum ) , se il risultato sono tutti `1` allora non ci sono errori

>[!example] 
>$$1100+1100+0011+1010+1110+1001 = 111100$$
>