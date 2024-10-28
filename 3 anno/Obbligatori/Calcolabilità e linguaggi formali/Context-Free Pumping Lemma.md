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
>Consideriamo $w\in A$ con $|w|\ge p$ ossia $|w| \ge b^{|w|}+1$ 
>
>Un [[Albero di Parsing]] di altezza $h=1$ può generare al massimo una stringa di lunghezza $b$ ( questo perchè ottengo la stringa di lunghezza massima se sostituisco il [[Simboli Non Terminali|Simbolo Non Terminale]] con il massimo numero di [[Simboli Terminali]] alla sua destra )
>Aumentando l'altezza dell'[[Albero di Parsing]] avremo che con $h=n$ l'*albero* genererà strighe di lunghezza massima $b^n$ ( scielgo sempre la sostituizione più lunga ) 
>
>Fatta questa considerazione l'[[Albero di Parsing]] della stringa $w$ avrà come altezza minima $|v|+1$ ( per via della *pumping length* che abbiamo scelto )
>
>Fra tutti gli [[Albero di Parsing]] di $w$ prendiamo quello con il numero minimo di nodi , prendiamo il cammino più lungo di tale [[Albero di Parsing]] che ne definisce l'altezza , questo cammino deve contenere almeno $|v|+1$ [[Simboli Non Terminali]] , questo implica che lungo questo cammino c'è almeno un [[Simboli Non Terminali|Non Terminale]] **R** che si ripete 
>
>Ora possiamo dimostrare le varie condizioni del teorema originale : 
>1. Possiamo pompare la stringa notando che avendo un **R** duplicato possiamo attuare la sostituzione vista nell'**Idea**  
>2. Dimostriamo per assurdo che $|vy|>0$ :
>	
>	Assumiamo per assurdo che $|vy|=0$ cioè $|v|=|y|=0$ , $w=uvxyz$ diventerà $uxz$ , ma allora se sostituiamo il più piccolo albero radicato in **R** al posto di quello più grande otteno un [[Albero di Parsing]] per $uxy$ con meno nodi dell'[[Albero di Parsing]] di partenza 
>	Questo è **Assurdo** poichè l'[[Albero di Parsing]] di partenza è *minimo*
>3. Dimostriamo $|vxy| \le p$
>	
>	Visto che abbiamo scelto **R** nel cammino più lungo dell'[[Albero di Parsing]] , avremo che l'altezza massima del sottoalbero radicato in **R** sarà $|v|+1$ , questo potrà generare strighe di lunghezza massima $b^{|v|+1}$ ossia $p$

>[!example] 
>Dimostriamo che $B=\{a^nb^nc^n|n\ge 0\}$ non è **Context-Free**
>
>>[!note] 
>>$B=\{a^nb^n|n\ge 0\}$ è un linguaggio **Context-Free**
>
>Assumiamo per **assurdo** che $B$ sia **Context-Free** allora deve valere il **Pumping Lemma**
>
>Sia $p$ la sua *pumping length* , costruiamo una stringa che contraddica il *pumping lemma* : 
>Consideriamo $s=a^pb^pc^p$ abbiamo che $s\in B$ e $|s|\ge p$ 
>
>Assumiamo $s = uvxyz$ con $|vy| > 0$ e $|vxy|\le p$ 
>
>Ragioniamo per casi : 
>1. $v$ contiene più di un tipo di carattere **oppure** $y$ contiene più di un tipo di carattere ( questo deve avvenire almeno una volta poichè abbiamo detto che $|vy|>0$ )
>	In questo caso se facciamo 1 *pumping up* la stringa risultante non sta più nel *linguaggio* $B$ poichè non rispetteremo più l'ordine dei caratteri
>>[!example] 
>>Abbiamo la stringa $s=aaabbbccc$
>>Prima del *pumping up* la dividiamo nel seguente modo
>>
|  a  |  a  | $\epsilon$ | ab  | bbccc |
|:---:|:---:|:----------:|:---:|:-----:|
| $u$ | $v$ |    $x$     | $y$ |  $z$  |
>>
>>Dopo il pumping up di $v$ e $y$
>>
|  a  |  aa   | $\epsilon$ | abab  | bbccc |
|:---:|:-----:|:----------:|:-----:|:-----:|
| $u$ | $v^2$ |    $x$     | $y^2$ |  $z$  |
>
>2. $v$ e $y$ contengono al più un simbolo , per esempio $v$ contine delle $a$ e $y$ contiene delle $b$ , in questo caso se facciamo un *pumping up* il numero delle $c$ sarà minore rispetto alle $a$ e $b$ portando la stringa fuori dal linguaggio

>[!example] 
>Dimostriamo che $D=\{ww|w\in\{0,1\}^*\}$ non è **Context-Free**
>
>Assumiamo per assurdo che $D$ sia **Context-Free** allora deve valere il **Pumping Lemma** 
>Sia $p$ la sua *pumping length* 
>>[!warning] 
>>Consideriamo la stringa $s=0^p10^p1$ questa $s \in D$ e $|s|\ge p$ , questa però soddisfa il *pumping lemma* poichè possiamo dividerela nel seguente modo e soddisferà il *pumping lemma* : 
>>
| $0\dots0$ | $0$ | $1$ | $0$ | $0\dots1$ |
| :-------: | :-: | :-: | :-: | :-------: |
|    $u$    | $v$ | $x$ | $y$ |    $z$    |
>>
>>Questa facendo *pumpin up* o *pumping down* rimane nel linguaggio $D$
>
>Consideriamo la stringa $s=0^p1^p0^p1^p$ questa $s\in D$ e $|s|\ge p$ 


>
>Osserviamo che se $s=uvxyz$ allora $vxy$ deve stare a cavallo delle due metà , 


