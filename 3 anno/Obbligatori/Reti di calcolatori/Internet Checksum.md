---
creation: 2024-10-02T09:01:00
publish: true
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
>$$1100 + 11 = 1111$$
>
>I dati sono *corretti*

>[!warning] 
>Ci possono essere combinazioni di errori che portano ad una *checksum* valida 
>
>La probilità che ciò succeda è : $2^{-C}$ dove $C$ è la grandezza della *checksum*

**Checksum Performance**

Per migliorare le prestazioni cominciamo a computare la somma ogni volta che riceviamo 16 bit e manteniamo il risultato in un buffer 

**Conseguenze**

+ L'header deve contenere 16 extra bit
+ I dati devono essere allineati al byte ( i dati devono essere di una dimensione multipla di 16 bit ) , se ho meno byte devo aggiungere del *padding*
