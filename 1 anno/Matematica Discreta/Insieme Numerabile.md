---
creation: 2024-11-18T12:48:00
---
Un insieme è **numerabile** se e solo se è *finito* oppure ha la stessa [[Cardinalità]] di $\mathbb{N}$ 

>[!example] 
>
>L'insieme dei razionali positivi ( $Q = \{\frac{m}{n} | m.n \in N\}$ ) è **numerabile** 
>
>>[!important] Dimostrazione
>>
>>Per dimotrare questo utilizziamo la tecnica della **Diagonalizzazione**  
>>
>>Creiamo una matrice in cui sulle righe e colonne abbiamo tutti i valori di $\mathcal{N}$ e nelle celle il valore della $f$ che mi da i razionali
>>
>>
>>|         |       1       |       2       |       3       |       4       | $\dots$ |
>>| :-----: | :-----------: | :-----------: | :-----------: | :-----------: | ------- |
>>|  **1**  | $\frac{1}{1}$ | $\frac{1}{2}$ | $\frac{1}{3}$ | $\frac{1}{4}$ |         |
>>|  **2**  | $\frac{2}{1}$ | $\frac{2}{2}$ | $\frac{2}{3}$ | $\frac{2}{4}$ |         |
>>|  **3**  | $\frac{3}{1}$ | $\frac{3}{2}$ | $\frac{3}{3}$ | $\frac{3}{4}$ |         |
>>|  **4**  | $\frac{4}{1}$ | $\frac{4}{2}$ | $\frac{4}{3}$ | $\frac{4}{4}$ |         |
>>| $\dots$ |               |               |               |               |         |
>>
>>L'obbiettivo è dare una [[Biettività|Biezione]] da $\mathbb{N}$ a $\mathbb{R^+}$ cioè produrre una lista di *razionali positivi* tale che non vi siano ripetizioni ( [[Iniettività]] ) e siano rappresentati tutti i *razionali positivi* ( [[Biettività]] ) 
