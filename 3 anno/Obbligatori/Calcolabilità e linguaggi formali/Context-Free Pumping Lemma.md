---
creation: 2024-10-25T13:25:00
---
Se $A$ è un linguaggio **Context-Free** allora esiste un intero $p\ge 1$ ( *pumping length* ) tale che ogni stringa $w \in A$ con $|w|\ge p$ può essere suddivisa in 5 parti : $w=uvxyz$ per cui valgono le seguenti $3$ condizioni : 
+ $\forall i\ge 0 \quad uv^ì x y^iz \in A$ ( posso *pompare* la stringa )
+ $|vy| >0$ 
+ $|vxy| \le p$ 
>[!note]	 
>Non possiamo sapere dove la terza propietà avviene all'interno della stringa 

>[!info] Idea
>
>Sciegliamo un $p$ "molto grande" , le stringhe con lunghezza $\ge p$ sono "molto lunghe" , il loro [[Albero di Parsing]] sarà quindi "molto alto"
>Visto che i [[Simboli Non Terminali]] sono in numero finito nell'[[Albero di Parsing]] , essendo "molto alto" ci dovrà essere un [[Simboli Non Terminali|Non Terminale]] **R** che si ripete 
>
>L'[[Albero di Parsing]] della stringa $w$ avrà quindi questa forma :
>![[Pasted image 20241025140044.png]]
>
>1. Se sostituiamo l'$R$ superiore con l'$R$ inferiore si forma la stringa $w = uxz$ , abbiamo quindi fatto *pumping down* , abbiamo perso $r$ e $y$
>![[Pasted image 20241025140005.png]]
>2. Se sostituiamo l'$R$ inferiore con l'$R$  superiore si forma invece la strina $w = uv^2xy^2z$ , abbiamo fatto *pumping up*
>![[Pasted image 20241025140014.png]]

>[!abstract] Dimostrazione Formale
>
>Se **A** è *Context-Free* esiste una [[Context-Free Grammar|CFG]] **G** tale che $L(G)=A$ 
>
>Definiamo $b$ come il numero massimo di simboli che occorrono a destra di una [[Produzioni|Produzione]] di **G** 
>
>>[!example] 
>>
>>```pseudo
>>	\begin{algorithm}
>>	\begin{algorithmic}
>>	\State $S \to AB$
>>	\State $B \to bbb$
>>	\State $A \to a |aA$
>>	\end{algorithmic}
>>	\end{algorithm}
>>```
>>In questo caso avremo che $b=3$
>
>Assumiamo che $b\ge 2$ ( se $b\le 2$ la dimostrazione diventa banale visto che la lunghezza massima di una stringa sarà $1$ )
>
>Sia $v$ l'insieme dei [[Simboli Non Terminali]] della grammatica **G** , definiamo la *pumping length* $p = b^{|v|+1}$
>>[!note]  
>>$b^{|v|+1} \ge b^{|v|}+1$ quando $|v|\ge 2$
>
>

