---
publish: true
creation: 2024-12-12T13:42:00
aliases:
  - PKI
---
![[Public Key]]

# Associare una [[Public Key]] ad un identità 

## Key Fingerprint

Quando **Alice** genera una *chiave* viene pubblicata online una sua **hash** ( sul sito personale , sulle email etcc )

Quando **Bob** riceve la chiave controlla che la sua *fingerprint* sia la stessa che **Alice** ha pubblicato 

>[!note] 
>
>Questo metodo non scala con *Internet*

## Key Servers

Su *internet* esistono *key servers* che permettono di caricare la propria [[Public Key]] assieme a dei *metadati* ( nome , email etcc ) , questa verrà poi replicata su tutti gli altri *key server* 

>[!warning] 
>*key server* non garantiscono che effettivamente quella chiave appartenga a quella determinata persona , sono semplicemente un luogo conveniente dove mantenere le [[Public Key]] 


## Web Of Trust

# Public Key Infrastructure