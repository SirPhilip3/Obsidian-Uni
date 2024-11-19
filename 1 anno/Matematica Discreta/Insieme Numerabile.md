---
creation: 2024-11-18T12:48:00
aliases:
  - Numerabile
publish: true
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
>>
>>>[!warning] 
>>>Ogni riga è infinita 
>>
>>Seguiamo un pattern **diagonale** per la funzione $f$ , in questo modo ogni diagonale ha sicuramente un numero finito di elementi , per evitare ripetizioni semplicmente omettiamo elementi cha abbiamo già trovato 
>>
>>![[Pasted image 20241118132731.png]]

>[!example] 
>
>L'insieme dei $\mathbb{R}$ *non* è **numerabile** 
>
>>[!important] Dimostrazione
>>
>>Assumiamo per assurdo che $\mathbb{R}$ sia **numerabile** , deve allora esistere una [[Biettività|Biezione]] $f$ da $\mathbb{N}$ a $\mathbb{R}$ 
>>Costruiamo quindi un controesempio , ossia un numero reale che non occorre nel *codominio* di $f$ 
>>
>>
>>| $n$ | $f(n)$  |
>>| --- | ------- |
>>| 1   | 3,145   |
>>| 2   | 5,623   |
>>| 3   | 12,152  |
>>| 4   | 1,18927 |
>>| 5   | 3,55556 |
>>
>>Per costruire un numero che non occore nel codomionio di $f$ semplicemente prendiamo la $n$-esima cifra decimale di ogni $f(n)$ e la sostituiamo con un numero diverso 
>>
>>>[!warning] 
>>>Il numero che creiamo deve iniziare con $0$ e i numeri che scegliamo devono essere diversi da $0$ e $9$ , questo perchè $1==0.9999\dots$
>>
>>Un numero può essere : $0.5783\dots$
 
