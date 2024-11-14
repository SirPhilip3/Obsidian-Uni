---
creation: 2024-11-05T11:40:00
publish: true
---
>[!important]  Definizione
> Una **Macchina di Touring** ( **MdT** ) è un modello teorico di un calcolatore con *memoria infinita* ed utilizzabile in modo arbitrario
>
>Una **macchina di touring** è formata da : 
>+ uno Stato interno 
>+ un nastro infinito
>+ una testina che può :
>	+ leggere o scrivere sul nastro
>	+ spostarsi liberamente a destra e sinistra lungo il nastro
>+ accetto o rifiuto non appena entro in uno stato di accettazione o rifiuto 

>[!example] 
>Scriviamo una **macchina di touring** per il seguente linguaggio : $\{w\#w | w \in \{0,1\}^*\}$ 
>
>>[!info] Idea 
>>La strategia è quella di muoversi a zig-zag in modo simmetrico attorno al marker $\#$ in modo da matchare i caratteri corrispondenti delle due stringhe , quando raggiungiamo il marker $\#$ e la seconda stringa è finita allora possiamo accettare
>
>Descrizione completa : 
>1. La testina fa zig-zag tra le due parti della stringa divisa da $\#$ per controllare se contengono lo stesso simbolo , gli elementi controllati vengono contrassegnati con $x$
>   In caso negativo o se non incontriamo $\#$ *rifiuteremo* la stringa
>2. Quando tutti gli elementi a sinistra di $\#$ sono stati contrassegnati , verifichiamo la presenza di altri simboli rimanenti a destra di $\#$ 
>   Se rimane qualche elemento *rifiuta* , altrimenti *accetta*
>>[!example]
>>| $\color{red}\downarrow$ |              |     |     |      |              |     |     |     |              |
| :----------: | :----------: | :-: | :-: | :--: | :----------: | :-: | :-: | :-: | :----------: |
|      0       |      1       |  1  |  0  | $\#$ |      0       |  1  |  1  |  0  |   $\sqcup$   |
|              | $\color{red}\downarrow$ |     |     |      |              |     |     |     |              |
|     $x$      |      1       |  1  |  0  | $\#$ |      0       |  1  |  1  |  0  |   $\sqcup$   |
|              |              |     |     |      | $\color{red}\downarrow$ |     |     |     |              |
|     $x$      |      1       |  1  |  0  | $\#$ |     $x$      |  1  |  1  |  0  |   $\sqcup$   |
| $\color{red}\downarrow$ |              |     |     |      |              |     |     |     |              |
|     $x$      |      1       |  1  |  0  | $\#$ |     $x$      |  1  |  1  |  0  |   $\sqcup$   |
|              | $\color{red}\downarrow$ |     |     |      |              |     |     |     |              |
|     $x$      |     $x$      |  1  |  0  | $\#$ |     $x$      |  1  |  1  |  0  |   $\sqcup$   |
|              |              |     |     |      |              |     |     |     | $\color{red}\downarrow$ |
|     $x$      |     $x$      | $x$ | $x$ | $\#$ |     $x$      | $x$ | $x$ | $x$ |   $\sqcup$   |
 
>[!important] Definizione Formale
>
>Una **Macchina di Tuoring** è una settupla : $(Q,\Sigma , \Gamma,\delta,q_0,q_{accept},q_{reject})$
>
>Dove : 
>+ $Q$ : è l'insieme degli stati
>+ $\Sigma$ : è l'alfabeto finito di input tale che $\sqcup \notin \Sigma$ 
>+ $\Gamma$ : è l'alfabeto finito del *nastro* tale che $\sqcup \in \Gamma$ e $\Sigma\subseteq\Gamma$ 
>+ $\delta$ : $Q \times \Gamma \to Q \times \Gamma \times \{L,R\}$ è la funzione di transizione , ossia dato uno stato $Q$ e un simbolo del nastro $\Gamma$ produrremo un nuovo stato $Q$ , un nuovo simbolo del nastro $\Gamma$ e la direzione in cui si muove la testina : $L$ ( sinistra ) o $R$ ( destra )
>+ $q_0 \in Q$ : è lo stato iniziale
>+ $q_{accept} \in Q$ : è lo stato di accettazione 
>+ $q_{reject} \in Q$ : è lo stato di rifiuto, con $q_{reject} \neq q_{accept}$ 

>[!note] 
>Le **MdT** sono *deterministiche* , si dimostrerà che **MdT** non deterministiche equivalgono a **MdT** deterministiche

>[!important] Computazione
>
>Possiamo descrivere un momento nella computazione tramite : 
>+ lo stato interno
>+ il contenuto del nastro
>+ la posizione della testina
>  
>>[!example] 
>>$001q_3\textcolor{red}{0}1$ : la testina sta nella quarta posizione e è nello stato $q_3$ 
>
>In generale una configurazione ha la forma $uqv$ dove $u$ e $v$ sono stringhe $\in \Gamma^*$  e $q\in Q$
>
>Una **MdT** computa passando da una configurazione a quella sucessiva secondo quanto definito da $\delta$ 
>
>La computazione deve seguire le seguenti **regole** : 
>1. Sia $M$ nella configurazione $ua\textcolor{orange}{q_i}bv$ e sia $\delta(q_i,b)=(q_j,c,L)$ allora la prossima configurazione sarà : $u\textcolor{orange}{q_j}acv$
>2. Sia $M$ nella configurazione $ua\textcolor{orange}{q_i}bv$ e sia $\delta(q_i,b)=(q_j,c,R)$ allora la prossima configurazione sarà : $uac\textcolor{orange}{q_j}v$
>3. Sia $M$ nella configurazione $\textcolor{orange}{q_i}bv$ e sia $\delta(q_i,b)=(q_j,c,L)$ allora la prossima configurazione sarà : $\textcolor{orange}{q_j}cv$
>4. Sia $M$ nella configurazione $\textcolor{orange}{q_i}bv$ e sia $\delta(q_i,b)=(q_j,c,R)$ allora la prossima configurazione sarà : $c\textcolor{orange}{q_j}v$
>
>Una **MdT** **accetterà** un input $w$ se e solo se esistono delle configurazioni $C_1\dots C_k$ tali che : 
>1. $C_1$ è la configurazione iniziale $q_0 w$
>2. $C_k$ è una configurazione *accettante* $u q_{accept} v$ per qualche $u,v \in \Gamma^*$
>3. $\forall i , C_i$ passa in $C_{i+1}$ secondo le regole di computazione date 

>[!note]
>Visto che $q_{accept}$ e $q_{reject}$ sono stati finali , possiamo riscrivere la funzione di transizionen le seguente modo : $\Gamma = [Q\backslash\{q_{accept},q_{reject}\}]\times \Gamma \to Q \times \Gamma\times\{L,R\}$ 

>[!important] Linguaggio di Touring
>Un linguaggio $A$ si dive **Touring riconoscibile** se e solo se esiste una **MdT** $M$ tale che $L(M)=A$

>[!note] 
>Dato un input $w$ una **MdT** $M$ ha solo 3 possibili risultati : 
>1. $M$ *accetta* $w$
>2. $M$ *rifiuta* $w$
>3. $M$ *non termina* ( va in loop quando eseguito su $w$ )

![[Decisore]]

![[Decidibile]]

>[!example] 
>Facciamo un esempio di rappresentazione grafica di una **Macchina di Touring** 
>
>$C=\{w\#w|w\in {0,1}^*\}$ , dare un **MdT** $M$ tale che $L(M)=C$
![[MdT1.excalidraw]]

>[!example] 
>**MdT** per $\{0^{2^n}|n \ge 0\}$ , ossia le stringhe di $0$ con lunghezza uguale a potenze di 2 
>
>>[!info] Idea
>>
>>Ogni passata della testina sul nastro cancelliamo metà degli $0$
>>
| 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| --- | --- | --- | --- | --- | --- | --- | --- |
| x   | 0   | x   | 0   | x   | 0   | x   | 0   |
| x   | x   | x   | 0   | x   | x   | x   | 0   |
| x   | x   | x   | x   | x   | x   | x   | 0   |
>>
>
>Su input $w$ :
>1. Scorri il nastro da sinistra a destra cancellando uno $0$ si uno no
>2. Se tale passata ha trovato un solo $0$ *accetta* $w$
>   Se tale passata ha trovato una quantità dispari di $0$ ( $>1$ ) *reject*
>3. Riavvolgi il nastro a sinsitra e riparti dallo step $1$
>>[!note] 
>>1. Visto che non abbiamo un marker di inizio nastro all'inizio shifto tutto l'input a destra e metto un *blank* ( $\sqcup$ ) in prima posizione
>>2. Sostituisco il primo simbolo con *blank* e in coda aggiungo il primo simbolo presente nella stringa di input
>>3. Sostituico con *blank* e passo ad uno stato che conta la presenza di uno zero , questo sarà il caso base , se rimangono altri $0$ dopo *reject* , altrimenti se rimane solo il *blank* *accept*

## Varianti della MdT

![[Macchina di Touring con Stay]]

![[Macchina di Touring Multinastro]]

![[Macchina di Touring non Deterministica]]

![[Macchina di Touring Enumeratore]]

## Tesi di Church-Touring

![[Tesi di Chruch-Touring]]

>[!important] Teorema
>Se non possiamo dare una **MdT** che risolve un *problema* allora non possiamo nemmeno scriverene un algoritmo risolutivo

>[!example] 
>Problema delle radici intere di un polinomio ( [10° problema di **Hilbert**](https://en.wikipedia.org/wiki/Hilbert%27s_tenth_problem) )
>
>Definire un algoritmo che dato un polinomio ( ex $x^2 - y^2$ ) determina se esso ammette o meno una [[Radice Intera di un Polinomio|Radice Intera]]
>
>E' impossibile dimostrare che tale algoritmo non esiste 

>[!example] 
>Possiamo ridurre il problema precedente al seguente : 
>
>Definire un algoritmo che dato un polinomio in *una* sola *variabile* determina se esso ammette o meno una [[Radice Intera di un Polinomio|Radice Intera]]
>
>Per definire un **MdT** dobbiamo tradurre il problema in un [[Linguaggio]] da riconoscere , definiamo quindi : 
>$$A = \{<p>|\ p\text{ è un polinomio in $x$ con radice intera}\}$$
>>[!note] 
>>$<p>$ è una funzione che trasforma i polinomi in una loro rappresentazione in forma di *stringa*
>>>[!example] 
>>>Possiamo utilizzare il seguente encoding : $3x^2- 5x +3 \to \text{"+3 | -5 | +3"}$ in cui semplicemente rappresento i suoi coefficenti separati da $|$ 
>
>Questo ammette soluzione algoritimica se e solo se $A$ è **Decidibile** 
>
>Proviamo a costruire un **Decisore** per $A$
>>[!note]   
>>Per la [[Tesi di Chruch-Touring]] possiamo dare lo pseudocodice della **MdT** $M$
>
>$M$ = sia in input $<p>$ : 
>1. Per tutti gli $x = 0,1,-1,2,-2,\dots$ ( per tutti i numeri interi )
>2. Calcola il valore di $p(x)$
>3. Se $p(x) = 0$ ritorna *accept*
>
>>[!warning] 
>>Questo però non è un **Decisore** perchè se il polinomio non ha una [[Radice Intera di un Polinomio|Radice Intera]] allora questo algoritmo andrà in loop
>
>Se riuscissimo a mettere dei limiti alla computazione allora diventerebbe un **Decisore**
>
>E' dimostrabile che la [[Radice Intera di un Polinomio|Radice Intera]] , se esiste , è compresa tra : $-k \frac{C_{max}}{C_1}$ e $+k \frac{C_{max}}{C_1}$ dove : 
>+ $C_{max}$ : è il coefficente di massimo valore assoluto
>+ $C_1$ : è il coefficente di grado massimo



