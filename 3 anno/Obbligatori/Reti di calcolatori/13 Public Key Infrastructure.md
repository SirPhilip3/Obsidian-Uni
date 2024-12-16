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

>[!example] 
>```bash
>gpg -gen-key
>```
>Questo genera una *primary key* usata per fare [[Digital Signature]] e una *secondary key* per fare *encryption* 
>
>>[!important] 
>>La prima dovrebbe sempre essere mantenuta segreta 
## Web Of Trust

E' un social network di contatti attraverso i quali certificare l'identità di una persona 
  
Sia **Alice** che **Bob** si fidano di **Carl** , ossia :
+ Entrabi hanno la sua [[Public Key]] 
+ Si fidano che se certifica qualcosa questo sia vero 

**Alice** e **Bob** però non si fidano tra di loro 

>[!important] Certification Process
>
>1. **Alice** e **Carl** si scambiano *fingerprint* , stessa cosa tra **Bob** e **Carl**
>2. **Carl** da a **Alice** la seguente *signature* : $S=E(Priv_C,(Pub_A,"Alice"))$ 
>	**Ossia** : **Carl** cifra sia la `Pub_A` che la sua identità con la sua `Priv_C`
>	In questo modo chiunque abbia la [[Public Key]] di **Carl** può certificare che una data [[Public Key]] appartiene ad *Alice*
>3. **Alice** invia `Pub_A` e $S$ a **Bob** che usa `Pub_C` per verificare $S$ , ora **Bob** si fida di **Alice**

>[!example] 
>![[Pasted image 20241216150742.png]]

>[!note] 
>Dopo lo scambio di $S$ con **Carl** , **Alice** può inviare la sua chiave assieme ad $S$ , e gli altri possono certificare la sua identità semplicemente possedendo la [[Public Key]] di **Carl** 
>

E' possibile anche formare delle *chain of thrust* infatti tutti coloro che si fidano di **Carl** possono *certificare* la sua identità con la propria *private key* ,  in questo modo chi non si fida di **Carl** potrà comunicare con **Alice** attraverso qual'unaltro che si fida di **Carl**

>[!example] 
>![[Pasted image 20241216151905.png]]

>[!warning] 
>Chi riceve la chiave pubblica di **Alice** può cifrare il traffico verso **Alice** ma non il contrario



# Public Key Infrastructure