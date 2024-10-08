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

