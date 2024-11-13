---
creation: 2024-09-18T10:35:00
publish: true
---
# Introduzione

Internet utilizza [[packet switching]] questo lo rende molto robusto e non preve l'esistenza di un coordinatore globale 
+ Può estendersi senza una gerarchia pianificata
+ Si può automaticamente rigenerare in caso di guasti 
 
Se non abbiamo un coordinatore globale dobbiamo rendere la rete *inter-operabile* 

Questo comporta l'utilizzo di *standard* , *protocolli* e *layer*

![[Layers]]
![[Sandard o Protocolli]]

# Internet Layers

Per *internet* abbiamo due differenti *network stack* :
+ ![[TCP IP]]
+ ![[ISO-OSI]]
>[!question] 
>Che *stack* utilizzare ?
>+ *IETF* ( l'organizzazione che produce gli internet standard ) usa [[TCP IP]]
>+ Documenti *RFC* gestiscono protoclli che vanno dall'[[Internet Layer]] in su ( ex : HTTP )
>+ *IEEE* ( l'organizzazione che si occupa di standard a basso livello : Ethernet , Wi-Fi etc.. ) utilizza [[ISO-OSI]] poichè non si occupano dei [[Layers]] superiori e quindi hanno bisogno di maggiore dettaglio ai livelli inferiori

>[!important]
>+ Ogni [[Layers|layer]] è un software separato
>+ I developer devono preoccuparsi solo del [[Layers|layer]] in cui stanno lavorando 
>+ Ogni [[Layers|layer]] definisce un'interfaccia da un [[Layers|layer]] all'altro
>+ Ogni [[Layers|layer]] comunica solo con il [[Layers|layer]] corrispondente dall'altra parte della comunicazione 

![[Communication.excalidraw]]

>[!note] 
>Ogni [[Layers|layer]] offre un *servizio* al [[Layers|layer]] superiore : 
>>[!example] 
>>Il [[Transport Layer]] offre 2 servizi : 
>>+ *reliable* transfer di uno stream di dati ( più lento e complicato , *UDP* )
>>+ *unreliable* transfer di [[packet|pacchetti]] ( semplice e veloce ma potremmo perdere dei pacchetti , *TCP* )

**Encapsulation** :
	Ogni [[Layers]] incapsula i dati del [[Layers]] precedente 
>[!example] 
> Il [[Transport Layer]] riceve i dati dall'applicazione e ci aggiunge il *TCP* header e passa i dati al layer *IP*

>[!note] *Sicurezza*  
>I [[packet]] possono essere intercettati prima di arrivare a destinazione 

