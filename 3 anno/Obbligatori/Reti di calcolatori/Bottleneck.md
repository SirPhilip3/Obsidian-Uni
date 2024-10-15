---
creation: 2024-10-14T13:22:00
---
In comunicazioni *multi-hop* ( ossia che facciamo più salti per arrivare a destinazione ) il **bottleneck** è il link pi lento che dobbiamo attraversare 

>[!example] 
>![[Pasted image 20241014133317.png]]
>
>La velocità di comunicazione tra $H1$ e $H2$ è limitata a $100Mb/s$ per via del link tra $H2$ e $H3$
>
>![[Pasted image 20241014133524.png]]
>
>Quando sia $H1$ che $H3$ comunicano il loro [[Bit-rate]] è limitato a $500Mb/s$ poichè condividono il link tra $H2$ e $H4$

>[!warning] 
>In un network *gerarchico* quando ci muoviamo dalle *foglie* verso la *radice* la capacità del link deve per forza aumentare
>![[Pasted image 20241015082438.png]]
>
>>[!example] Esempio Data Center 
>>Generalmente per connettere i singoli server si utilizzano *edge switches* ( low-end ) , aumenteremo la qualità degli *switch* via via che ci alziamo nella gerarchia
>>
>>La tolleranza ai guasti viene raggiunta attraverso la ridondanza dei *core switch*
>>
>>![[Pasted image 20241015082757.png]]
>
>>[!example] Esempio Fat-Tree
>>
>>Un'alterantiva al sistema dei data-center è la gerarchia *fat-tree* , questa utilizza solo switch low-end per le connessioni , necessiteremo di più switch ma i costi rimarranno più contenuti
>>
>>![[Pasted image 20241015083002.png]]
>>




