---
creation: 2024-09-17T13:51:00
publish: true
---

L'obbiettivo dell'*analisi predittiva* è quello di acquisire conoscenza da un insieme di dati per poi utilizzarla per fare predizioni , capire o indentificare altre informazioni

I tools dell'*analisi predittiva* si dividono in : 
+ ![[Supervised Learning]]
+ ![[Unsupervised Learning]]
# Notazioni e Terminologie

+ ![[Response]]
+ ![[Feature]]
![[Model]]

L'*analisi predittiva* si riferisce a quei metodi che ci permettono di stimare $m$ partendo da dati su $X$ e $Y$ 

La *stima* del modello si indicherà con $\widehat m(X)$

Abbiamo 2 principali motivazioni per *stimare* $m$ :
+ ![[Prediction]]
+ ![[Inference]]
>[!note] 
>Alcune volte la *modellazione* potrebbe essere svolta sia per [[Prediction]] che per [[Inference]] , dipende dalla domanda che ci poniamo 

>[!important] Generalizability
>Vogliamo *predittori* che :
>+ catturino i trend nei dati
>+ ignorino fluttuazioni randomiche nei dati
>>[!example] 
>>![[Pasted image 20240926092439.png]]

>[!warning] 
>Vogliamo evitare di estrapolare dati troppo al di fuori del dominio dei nostri dati di partenza

