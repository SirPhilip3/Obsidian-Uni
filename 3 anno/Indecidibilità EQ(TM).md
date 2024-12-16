---
publish: true
creation: 2024-12-16T10:08:00
---
>[!important] Teorema
>$EQ_{TM} = \{<M_1, M_2> | M_1,M_2 \text{ sono MdT e } L(M_1)=L(M_2)  \}$ è [[Indecidibile]] 

**Dimostrazione** : 

Dimostriamo per **Assurdo** che se $EQ_{TM}$ fosse [[Decidibile]] potremmo decidere $E_{TM}$ che è [[Indecidibile]] 
Sia $H$ l'ipotetico [[Decisore]] per $EQ_{TM}$ costruiamo un [[Decisore]] per $E_{TM}$ nel seguente modo : 

$S$ = Su input $<M>$ :
1. Costruiamo una nuova [[08 Macchine di Touring|MdT]] $N$ tale che $L(N) = \emptyset$ 
2. Eseguiamo $H$ su input $<M,N>$
3. Ritorna il suo *output*

Questo è **Assurdo** perchè abbiamo dimostrato l'[[Indecidibilità E(TM)]] 