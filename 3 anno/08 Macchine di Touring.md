---
creation: 2024-11-05T11:40:00
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

