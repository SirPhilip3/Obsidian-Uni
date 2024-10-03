---
creation: 2024-10-02T11:04:00
tags:
  - Teorema
---
$A$ è **regolare** $\iff$ esiste una [[03 Espressioni Regolari|regexp]] $R$ tale che $L(R)=A$

>[!important] Dimostrazione
>
>Essendo un $\iff$ dovremo dimostrare $\implies$ e $\Longleftarrow$ : 
>
>1. Iniziamo dimostrando $\implies$ : Sia $R$ una *regexp* allora $L(R)$ è *regolare* :
>
>La dimostrazione si fa per *induzione* sulla struttura di $R$ , dividiamo quindi in casi : 
>1. Sia $R=a$ per qualche $a$ allora $L(R) = \{a\}$ 
>   Dimostriamo che $L(R)$ è *regolare* costuendo un [[DFA]] :
>   ![[Regex_dim1.excalidraw]]
>2. Sia $R =\epsilon$ allora $L(R)=\{\epsilon\}$
>   Dimostriamo che $L(R)$ è *regolare* costruendo un [[DFA]] :
>   ![[Regex_dim2.excalidraw]]
>3. Sia $R=\emptyset$ allora $L(R) = \emptyset$
>   Dimostriamo che $L(R)$ è *regolare* costruendo un [[DFA]] :
>   ![[Regex_dim3.excalidraw]]
>4. Sia $R = R_1 \cup R_2$ allora $L(R) = L(R_1)\cup L(R_2)$
>   $L(R_1)$ e $L(R_2)$ hanno un operatore in meno rispetto a $L(R)$ , posso quindi applicare l'*ipotesi induttiva* : so che il teorema vale per $R_1$ e $R_2$ quindi so che $L(R_1)$ e $L(R_2)$ sono **regolari** , concludo dicendo che $L(R)=L(R_1)\cup L(R_2)$ è **regolare** pouchè i linguaggi regolari sono *chiusi* rispetto all'unione ( [[A ∪ B]] )
>5. Posso fare lo stesso ragionamento rispetto all'$\cup$ anche per la $o$
>6. Posso fare lo stesso ragionamento rispetto all'$\cup$ anche per la $^*$ 
>
>Questo ci fa capire che possiamo costruire dei [[DFA]] o [[NFA]] equivalenti alla *regexp*
>![[Regexp to NFA]]
>
>2. Dimostriamo $\Longleftarrow$ :
>Se $A$ è **regolare** allora esiste una *regexp* $R$ tale che $L(R)=A$ 
>
>**IDEA** : sia $A$ *regolare* allora esiste un [[DFA]] $D$ tale che $L(D) = A$ , ci basterà quindi trasformare un [[DFA]] in una *regexp* 
>
>Per arrivare alla [[03 Espressioni Regolari|regexp]] partendo da un [[DFA]] a $k$ stati  , costuiamo prima un ![[GNFA]] a $k+2$ stati 
>
>Via via toglieremo degli archi fino ad avere uno solo , la sua etichetta sarà la *regexp* che ci interessa 
>
>In dettaglio il [[GNFA]] deve soddisfare le seguenti caratteristiche : 
>+ Avere un solo stato iniziale
>+ Avere un solo stato accettante , differente da quello iniziale
>+ Lo stato iniziale ha archi in *uscita* verso tutti gli altri stati e nessun arco in *entrata*
>+ Lo stato accettante deve avere archi in entrata da tutti gli altri stati e nessun arco in uscita 
>+ Il resto del grafo è completamente connesso 
>  