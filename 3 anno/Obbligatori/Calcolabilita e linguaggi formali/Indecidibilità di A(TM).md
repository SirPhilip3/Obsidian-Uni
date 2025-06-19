---
publish: true
creation: 2024-11-19T09:21:00
---
>[!important] Teorema
>
>$A_{TM}$ è *indecidibile* ( *Accept* di una [[08 Macchine di Touring|MdT]] ) 

Osserviamo che $A_{TM}$ è [[Touring Riconoscibili]] , infatti possiamo costruire  un [[08 Macchine di Touring|MdT]] $N$ tale che $L(N)=A_{TM}$ :

$N$ accetta in input $<M,w>$ :
1. Simula $M$ su $w$
2. Ritorna il suo output

>[!note] 
>$N$ non è un [[Decisore]] perchè $M$ potrebbe andare in loop

>[!important] Dimostrazione
>
>Non è possibile dare un [[Decisore]] per $A_{TM}$
>
>Assumiamo *per assurdo* che $A_{TM}$ sia [[Decidibile]] , allora esiste un [[Decisore]] $H$ per $A_{TM}$ 
>
>$$
>H(<M,w>) = \begin{cases} \text{accept} & \text{ se $M$ accept $w$} \\ \text{reject} & \text{altrimenti} \end{cases}
>$$
>
>Costruiamo un altro [[08 Macchine di Touring|MdT]] $D$ come segue : 
>
>$D$ si aspetta in input $<M>$ :
>1. Esegue $H$ su input $<M,<M>>$
>2. Ritorna il suo output invertito
>
>Avremo quindi che : 
>$$
>D(<M>) = \begin{cases} \text{accept} & \text{ se $M$ non accetta $<M>$} \\ \text{reject} & \text{ se $M$ accetta $<M>$ } \end{cases} 
>$$
>
>Se gli passiamo la sua stessa descrizione 
>
>$$
>D(<D>) = \begin{cases} \text{accept} & \text{ se $D$ non accetta $<D>$} \\ \text{reject} & \text{ se $D$ accetta $<D>$ } \end{cases} 
>$$
>
>Questo è **Assurdo** infatti non ha senso che qualsiasi cosa faccia $D$ dobbiamo fare il contrario , qundi non può esistere nè $D$ nè $H$

>[!note] 
>
>Questa dimostrazione è basata sulla **Diagonalizzazione** 
>
>
|         | $<M_1>$ | $<M_2>$ | $<M_3>$ | $<M_4>$ | $\dots$  | $<D>$   |
| ------- | ------- | ------- | ------- | ------- | -------- | ------- |
| $M_1$   | Accept  |         |         |         |          |         |
| $M_2$   |         | Accept  |         |         |          |         |
| $M_3$   |         |         | Reject  |         |          |         |
| $M_4$   |         |         |         | Reject  |          |         |
| $\dots$ |         |         |         |         | $\ddots$ | $\dots$ |
| $D$     | Reject  | Reject  | Accept  | Accept  | $\dots$  | $?$     |
>
>$D$ fa il contrario di ciò che fa $M_n(<M_n>)$ , non sappiamo cosa faccia a $D(<D>)$






