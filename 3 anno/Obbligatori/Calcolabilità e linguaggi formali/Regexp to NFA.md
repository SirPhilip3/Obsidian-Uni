---
creation: 2024-10-03T14:23:00
publish: true
---
>[!example] 
Convertiamo $(ab \cup a)^*$ in un [[NFA]]
Iniziamo creando i [[DFA]] per $ab$ e $a$ :
>1. $ab$ :
![[ab_NFA.excalidraw]]
>2. $a$ :
![[a_NFA.excalidraw]]
>3. La $\cup$ può essere scritta come ( essendo che dobbiamo scieglere tra una delle due ) : 
![[abUa_NFA.excalidraw]]
>4. Ora visto che vogliamo poter ripetere questo pattern da $0$ a $\infty$ volte dobbiamo far ritornare gli stati accettanti all'inzio ( aggiungendo un opportuno stato iniziale accettante per accettare la stringa $\emptyset$ ) :
![[Complete_NFA.excalidraw]]

