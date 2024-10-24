---
creation: 2024-10-24T14:32:00
---
Il *Connectionless Service* offre :
+ **Unrelaiable delivery** dei dati ( generalmente aggiungiamo *error detection* )
+ **Multiplexing** ai due endpoint della comunicazione 

>[!important] 
>Normalmente è un servizio *stateless* , ossia il [[Transport Layer]] dei due *endpoint* non mantengono alcuna variabile , ogni **segmento** viaggia indipendentemente l'uno dall'altro 

>[!info] Use Cases
>Generalmente questo *servizio* viene utilizzato per applicazioni interattive in cui possiamo accettare la perdita di alcuni dati e non ci interessa la loro ritrasmissione 
>>[!example] 
>>In una applicazione di video streaming non ci interessa ritrasmettere un frame visto che quando ci arriverà il tempo in cui dovevamo servirlo all'utente è già passato 

Per garantire comunque l'**error detection** viene aggiunta una [[Internet Checksum|Checksum]] all'interno dell'*header* , quando riceviamo il [[packet]] semplicemente controlliamo che la checksum computata dai dati del [[packet]] e quella dell'*header* conincidano ( se non coincidono scartiamo il [[packet]] ) 

Per implementare il **Multiplexing** utilizziamo il concetto di ![[Porte]]