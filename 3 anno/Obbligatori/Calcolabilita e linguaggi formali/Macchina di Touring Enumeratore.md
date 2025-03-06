---
creation: 2024-11-06T11:55:00
publish: true
---
Un **Enumeratore** ( generatore ) è una **MdT** a cui attachiamo una *stampante*

Un **Enumeratore** : 
+ Non ha nessun input ma accumula caratteri nel buffer della *stampante*
+ Il suo linguaggio è rappresentato dall'insieme delle stringhe che stampa 

![[Enumerator.excalidraw]]

>[!important] Teorema
>
>Un linguaggio è **Touring riconoscibile** se e solo se esiste un **Enumeratore** che lo genera 
>

>[!important] Dimostrazione
>
>$\implies$ : Se $A$ linguaggio **Touring riconoscibile** dimostriamo che esiste un **Enumeratore** $E$ tale che $L(E)=A$ 
>
>Visto che $A$ è **Touring riconoscibile** esiste una **MtR** $M$ tale che $L(M)=A$ , costruiamo un **Enumeratore** $E$ tale che $L(E)=A$ 
>
>$E =$ per tutti gli indici $i = 1,2,3,\dots$ 
>1. Genera prime $i$ stringhe dell'ordine
>2. Prova $M$ su $i$ stringhe per $i$ passi di computazione
>3. Se troviamo una stringa accettata questa verrà stampata
>
>>[!note] 
>> $s_i$ saranno stringhe di lunghezza $i$
>> In pratica ad ogni passo generiamo stringhe più lunghe e le proviamo su sempre più passi di computazione ( andando più in profondità nell'albero delle computazioni ) , questo evita che se una stringa porta ad un loop manderebbe in loop anche $M$ non controllando più nessuna stringa
>
>
>$\Leftarrow$ : Se esiste un **Enumeratore** $E$ tale che $L(E)=A$ allora $A$ è **Touring riconoscibile**
>
>Costruisco una **MdT** $M$ per il linguaggio $A$
>$M =$ aspetta un input $w$ : 
>1. Simula l'enumeratore $E$
>2. Ogni volta che $E$ stampa una stringa $v$ verifico se $v=w$ 
>3. Se $v==w$ allora *accetto* altrimenti torno allo step 1

>[!important] Definizione Formale
>Un **Enumeratore** è una settupla : $(Q, \Sigma, \Gamma, \delta, q_0,q_p,q_h)$ dove : 
>+ $Q$ : insieme finito di stati
>+ $\Sigma$ : alfabeto finito per la stampa
>+ $\Gamma$ : alfabeto finito del nastro $\sqcup \in \Gamma$
>+ $\delta$ : $Q \times \Gamma \to Q \times \Gamma \times \{L,R\} \times \Sigma_{\epsilon}$ 
>
>Ossia dato in input uno stato e un simbolo del nastro ritorniamo un nuvo stato , un nuovo simbolo del nastro , la direzione di movimento della testina e il carattere ( preso da $\Sigma$ ) da aggiungere al buffer di stampa ( può anche essere $\epsilon$ )
>+ $q_0$ : stato iniziale 
>+ $q_p$ : stato di stampa
>+ $q_h$ : stato di terminazione

>[!summary] Compuazione di un **Enumeratore**
>
>Data una coppia $(uqv,w)$ , detta *configurazione* , dove : 
>1. Il primo elemento è la rappresentazione dello stato della **MdT** dove $u\in \Gamma^*$ è la parte sinistra del nastro , $q \in Q$ rappresenta lo stato in cui si trova la macchina , $v\in \Gamma^*$ è la parte destra del nastro 
>2. Il secondo elemento , $w\in \Sigma^*$ , è il buffer della stampante 
>   
>Possiamo definire come una configurazione evolve alla sucessiva attraverso delle regole : 
>1. Assumiamo che la configurazione corrente sia : $(ua\textcolor{orange}{q_i}bv,w)$ e sia $\delta(q_i,b)=(q_j,c,L,d)$ la nuova configurazione sarà : $(u\textcolor{orange}{q_j}acv,wd)$
>>[!note] Explanation
>Dato $q_i$ e il simbolo $b$ , quello sopra il quale si trova la testina , ritorniamo uno stato $q_j$ , il simbolo , $c$ , da scrivere sul nastro al posto di $b$ , il movimento della testina $L$ e un nuovo simbolo $d$ da mettere sul buffer della stampante 
>
>2. Analogo sarà per il movimento verso destra $R$ della testina
>3. Analogo sarà per il movimento verso sinista $L$ della testina quando ci troviamo all'estremità più a sinistra del nastro
>4. Analogo sarà per il movimento verso destra $R$ della testina quando ci troviamo all'estremità più a sinistra del nastro
>5. Assumiamo che la configurazione corrente sia $(u\textcolor{orange}{q_p}v, w)$ ( ci troviamo in uno stato di stampa ) allora la prossima configurazione sarà : $\textcolor{orange}{q_0}uv, \epsilon$ ossia torniamo allo stato iniziale , ritornando allo stato del nastro iniziale , e liberiamo il buffer

>[!important] Linguaggio di un **Enumeratore**
>
>$$\{w\in \Sigma^* | \exists u,v \in \Gamma^* \text{ t.c. } (u\textcolor{orange}{q_p}v,w) \text{ è raggiungibile da } (q_0,\epsilon) \}$$
>
>Ossia saranno quelle stringhe tale per cui esiste una *configurazione* per cui la *configurazione* di stapa è raggiungibile dalla *configurazione* iniziale


