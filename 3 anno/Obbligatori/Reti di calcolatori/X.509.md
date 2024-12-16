---
publish: true
creation: 2024-12-16T15:57:00
---
Un certificato in formato **X.509** ha i seguenti campi : 
+ Un identificativo unico per ogni [[Certification Authority|CA]] 
+ Un numero seriale univoco che identifica il certificato
+ Un tempo di validità 
+ Dati per identificare il proprietario della chiave 
>[!example] 
>Nome , IP , indirizzo , dominio etcc
+ La chiave pubblica
+ La *firma* per l'intero certificato della [[Certification Authority|CA]] , fatta usando la *private key* della [[Certification Authority|CA]] 