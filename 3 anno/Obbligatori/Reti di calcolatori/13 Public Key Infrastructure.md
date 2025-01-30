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
>2. **Carl** dà a **Alice** la seguente *signature* : $S=E(Priv_C,(Pub_A,"Alice"))$ 
>	**Ossia** : **Carl** cifra sia la `Pub_A` che la sua identità con la sua `Priv_C`
>	In questo modo chiunque abbia la [[Public Key]] di **Carl** può certificare che una data [[Public Key]] appartiene ad *Alice*
>3. **Alice** invia `Pub_A` e $S$ a **Bob** che usa `Pub_C` per verificare $S$ , ora **Bob** si fida di **Alice**

>[!example] 
>![[Pasted image 20241216150742.png]]

>[!note] 
>Dopo lo scambio di $S$ con **Carl** , **Alice** può inviare la sua chiave assieme ad $S$ , e gli altri possono certificare la sua identità semplicemente possedendo la [[Public Key]] di **Carl** 
>

E' possibile anche formare delle *chain of thrust* infatti tutti coloro che si fidano di **Carl** possono *certificare* la sua identità con la propria *private key* ,  in questo modo chi non si fida di **Carl** potrà comunicare con **Alice** attraverso qualcun altro che si fida di **Carl**

>[!example] 
>![[Pasted image 20241216151905.png]]

>[!warning] 
>Chi riceve la chiave pubblica di **Alice** può cifrare il traffico verso **Alice** ma non il contrario
# Public Key Infrastructure

Una **PKI** è un'infrastruttura dove c'è una ![[Certification Authority]] o **CA**

La [[Certification Authority|CA]] ha il compito di firmare chiavi , una chiave firmata è detta :![[Certificate]]
## Obtaining a Certificate

1. **Alice** crea una ![[Certificate Signing Request]]
2. **Alice** invia la [[Certificate Signing Request|CSR]] alla [[Certification Authority|CA]] 
3. La [[Certification Authority]] controlla la sua identità ( eg attraverso dei documenti )
4. Visto che la [[Certificate Signing Request|CSR]] è firmato con `Priv_A` la [[Certification Authority]] può usare `Pub_A` per verificare la firma , ora la [[Certification Authority|CA]] sa che *Alice* possiede `Priv_A`
5. La [[Certification Authority]] ritorna un **certificato** valido ossia la [[Certificate Signing Request|CSR]] con la [[Digital Signature]] della [[Certification Authority|CA]] aggiunta :
$$Cert = \{CSR,E(Priv\_A, CSR)\}$$

>[!note] 
>Lo standard usato per i *certificati* è [[X.509]] 

>[!note] 
>+ Questo processo avviene solo una volta per periodo di validità del [[Certificate]]
>+ Quando il [[Certificate]] è stato inviato al destinatario non necessitiamo più della [[Certification Authority]] , non risulta quindi un *bottleneck* 
>+ La [[Certification Authority|CA]] non ha bisogno di conoscere la *private key* di colui che richiede il *certificato*

>[!info] Performance
>
>Visto che sappiamo che [[12 Public Key Encryption]] è dispendioso , la firma della [[Certification Authority|CA]] è in realtà relativa ad una [[Hash Functions]] dell [[Certificate]] stesso ( escludendo la firma ) , il certificato dovrà quindi contenere la [[Hash Functions]] usata 

## Receiving a Certificate

Quando **Bob** riceve un [[Certificate]] valido per **Alice** , firmato da una [[Certification Authority|CA]] esso fa le seguenti cose : 
+ Controlla che il nome nel certificato sia effettivamente *Alice* 
+ Controlla che il certificato sia valido in quell'istante di tempo 
+ Controlla che la [[Certification Authority|CA]] sia all'interno del suo database di [[Certification Authority|CA]] valide per cui possiede la chiave pubblica
+ Decifra la *signature* con la *chiave pubblica* della [[Certification Authority|CA]] , ottiene un *digest* $D$ 
+ Computa la hash $D'$ del certificato ( senza la *signature* ) 
+ Se $D=D'$ allora il [[Certificate]] è valido e **Bob** ora si fida della *public key* di **Alice** 

## Certificate for Domain Names

Nel caso dei *domini* nel campo *owner* viene inserito un nome di dominio ex `www.alice.com` 

Quando **Bob** naviga sul sito di **Alice** , `www.alice.com` fornice a **Bob** `Pub_A` , questa sarà presente in un [[Certificate]] , se questo è *invalido* ( è stato rilasciato da una [[Certification Authority|CA]] che **Bob** non conoce , il [[Certificate]] è scaduto , il [[Certificate]] è per un altro dominio ) , il broswer non accetterà la connessione con `www.alice.com`

### Trusted [[Certification Authority|CA]]

Visto che vi sono molte [[Certification Authority|CA]] nel mondo come fa **Bob** a decidere di quale fidarsi 

Le [[Certification Authority|CA]] Possono creare una **Web of Trust** perchè le [[Certification Authority|CA]] possono firmarsi i propri [[Certificate]] a vicenda

Esistono poche **Root** [[Certification Authority|CA]] che si firmano i [[Certificate]] da sole , i broswer posseggono queste [[Certification Authority|CA]] 

Quando **Bob** naviga su `www.alice.com` questa deve fornire non solo il [[Certificate]] per lei ma anche tutti i [[Certificate]] fino alla **Root** [[Certification Authority|CA]] 

Il broswer quindi controllerà la catena di certificati dalla foglia `www.alice.com` alla **Root** [[Certification Authority|CA]] 

Alla fine il *broswer* conosce la *public key* del server ma questo non sa nulla riguardo l'utente 

## Certificate Revocation Lists (CRL) 

Se viene persa una *private key* abbiamo necessità di revocare i [[Certificate]] relativi ad essa 

Una **CRL** è una lista di [[Certificate]] che sono stati revocati da una [[Certification Authority|CA]] , una **CRL** è firmata dalla chiave della [[Certification Authority|CA]] 

I broswer periodicamente aggiornano le loro **CRL** 

## Let's Encrypt

#todo 

