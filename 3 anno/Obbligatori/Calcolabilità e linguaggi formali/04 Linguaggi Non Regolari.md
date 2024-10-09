---
creation: 2024-10-08T09:56:00
---
>[!example] 
>$\{0^n 1^n | n \ge 0\}$ : rappresenta una sequenza di $0$ di lunghezza $n$ seguita dsa una sequenza di $1$ della stessa lunghezza , delle stringhe *accettate* sono : $\{01,0011,000111,\dots\}$ 
>>[!note] 
>>Non è possibile costruire un [[DFA]] che lo rappresenti poichè dovremmo avere infiniti stati per memorizzare il numero di $0$ e $1$ 

>[!warning] 
>Per dire che un linguaggio è **non regolare** non è sufficente notare che nell'esempio precedente il [[DFA]] dovrà avere stati infiniti per rappresentate il [[Linguaggio Formale]] infatti :
>$$\{w | w\ \text{ha un numero uguale di occorrenze di $01$ e $10$}\}$$ è un linguaggio [[Linguaggio Regolare NFA|Linguaggio Regolare]]

Per dimostrare la *non regolarità* di un **Linguaggio** utilizzeremo il seguente *lemma* : 
![[Pumping Lemma]]

Come possiamo *utilizzarlo* : 

Se $A$ è il [[Linguaggio Formale]] per cui vogliamo mostrare la **non** *regolarità* :
1. Assumo per *assurdo* che $A$ sia *regolare*
2. Visto che $A$ è regolare deve valere il [[Pumping Lemma]] 
3. Contraddico il [[Pumping Lemma]] attraverso un controesempio ( ci basta trovare una stringa per cui non vale )
4. Concludo che $A$ non è regolare 

In pratica dovremo trovare una stringa che soddisfi le seguenti condizioni : 
>[!abstract] 
>Esiste **una** *stringa* $s \in A$ con $|s|\ge p$ tale che per ogni $s=xyz$ si abbia :
>1. $\exists i \ge 0 \quad xy^iz \notin A$  **OR**
>2. $|y|>0$ **OR**
>3. $|xy|>p$
>
>Negli *esercizi* cercheremo una stringa $s\in A$ con $|s|\ge p$ tale per cui per ogni suddivizione di $s$ in $xyz$ con $|y|>0$ e $|xy|\le p$ si abbia $\exists i \ge 0 \quad xy^iz \notin A$ ( in pratica cerchiamo di rompere la prima ipotesi )

>[!example] 
>Abbiamo $A = \{0^n1^n\}$ ( stringhe con lo stesso numero di $0$ e $1$ ) dimostriamo che non è regolare , per *assurdo* supponiamo che $A$ è regolare , dovrà quindi valere il [[Pumping Lemma]]
>
>Prendiamo come stringa di controesempio $s=0^p1^p$ ( questa è lunga almeno $2p$ ) 
>
>Scrivo $s$ in forma $xyz$ con $|y|>0$ e $|xy|\le p$ , dimostriamo poi che esiste $i\ge 0$ tale per cui $xy^iz$ non sta in $A$
>
>Possiamo dimostrarlo in due versioni : 
>1. Senza sfruttare l'ipotesi $|xy|\le p$
>
>Avremo 3 casi : 
>1. $y$ contiene solo $0$ 
>	Allora $xy^2z$ dovrà essere $0^{p+k}1^p$ con $k>0$ , questa stringa non sta nel linguaggio $A$ visto che avremo sicuramente un numero maggiore di $0$ rispetto agli $1$
>2. $y$ contiene solo $1$
>	Allora $xy^2z$ dovrà essere $0^p1^{p+k}$ con $k>0$ , questa stringa non sta nel linguaggio $A$ visto che avremo sicuramente un numero maggiore di $1$ rispetto agli $0$
>3. $y$ contiene sia $0$ che $1$
>	Possiamo notare che per qualsiasi stringa $y$ che prendiamo questa se ripetuta 2 o più volte porterà a
