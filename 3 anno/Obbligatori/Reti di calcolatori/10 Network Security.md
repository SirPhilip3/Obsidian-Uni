---
creation: 2024-10-29T13:33:00
---
L'[ITU](https://www.itu.int/en/Pages/default.aspx) definisce lo standard `X.800` che definisce tre topic centrali per la sicurezza : 
+ ![[Security Services]]
+ ![[Security Mechanisms]]
+ ![[Security Threats]]
Per studiare la sicurezza di un sistema si utilizza il seguente **modello** : 

![[Pasted image 20241111085848.png]]

>[!note]
>+ **Alice** : il mittente del messaggio
>+ **Bob** : il destinatario del messaggio
>+ **Eve** : un attaccante che mantiene il controllo del canale di comunicazione
>+ **Security Trasformation** : sono trasfomazioni del messaggio originale attraverso algoritmi *Cryptografici* ( assumiamo che questi meccanismi siano robusti e che l'attaccante non possa romperli )
>+ **Trusted Third Party** : è un entità di cui sia *Bob* che *Alice* si fidano 

>[!warning] 
>
>La sicurezza di un sistema è sempre un *trade-off* tra usabilità / costo del sistema e sicurezza , infatti più aggiungiamo meccanismi di sicurezza più sarà complesso per l'utente utilizzare il servizio e più costerà al mantenitore del servizio 

