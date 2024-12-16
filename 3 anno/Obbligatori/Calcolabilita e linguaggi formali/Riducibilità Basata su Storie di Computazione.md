---
publish: true
creation: 2024-12-16T10:19:00
---
>[!important] Definizione
>
>Sia $M$ una [[08 Macchine di Touring|MdT]] e $w$ una stringa di input per $M$ 
>Una **storia di computazione accettante** per $M$ e $w$ è una sequenza di **configurazioni** della [[08 Macchine di Touring|MdT]] $M$ tale che :
>1. La prima *configurazione* è la *configurazione* iniziale di $M$ su $w$ 
>2. L'ultima *configurazione* è una *configurazione* **accettante**
>3. Ogni *configurazione* discende dalla precedente secondo le regole di coputazione di una [[08 Macchine di Touring|MdT]] 

>[!note] 
>
>In pratica dobbiamo passare da una configurazione iniziale $S$ ad una finale $F$ attraverso la *funzione di transizione* di $M$ 

>[!tldr] 
>
>$M$ **accetta** $w$ se e solo se esiste una **Storia di computazione accettante** per $M$ su $w$ 

