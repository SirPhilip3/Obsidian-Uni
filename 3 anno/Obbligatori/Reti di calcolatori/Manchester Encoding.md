---
creation: 2024-09-25T11:48:00
publish: true
---
Invece di utilizzare lo stato del segnale come il trasportatore di infomazione ( $low = 0$ , $high = 1$ ) utilizziamo il cambiamento di stato come encoding ( $high \rightarrow low = 1$ , $low \rightarrow high = 0$  )

In questo modo possiamo mantenere sincronizzati i due clock guardando il cambiamento di livello del segnale alla fine di ogni *simbolo* 

>[!warning] 
>Dentro un singolo simbolo dovremmo assegnarne una metà per ogni parte del segnale , questo porta il segnale ad essere più soggetto ad errori dovuti al [[Noise]]
>
>![[Pasted image 20240925115413.png]]

