---
creation: 2024-10-16T11:23:00
aliases:
  - PDA
---
Gli *Automi a Pila* ( *pushdown automata* o **PDA** ) sono degli [[NFA]] con però l'aggiunta di uno **stack** 

Lo **stack** è una struttura dati *LIFO* che può fare due operazioni : 
+ *push* : aggiunge un elemento in cima alla coda
+ *pop* : rimuove l'elemento in testa alla coda

>[!example] 
>Proviamo a descrivere un **PDA** per il seguente [[Linguaggio Formale]] $\{0^n1^n | n\ge 0\}$
>
>1. Ogni volta che leggo $0$ facciamo *push* di $0$ nello **stack**
>2. Quando leggo un $1$ facciamo *pop* di uno $0$
>3. Finchè arrivano $1$ continuo a fare *pop*
>4. Se ho finito l'input e lo **stack** è *vuoto* **Accettiamo** la stringa
>5. Se ho finito l'input e lo **stack** *non* è *vuoto* **Rifiutiamo** la stringa ( abbiamo ricevuto più $0$ rispetto agli $1$ )
>6. Se leggo uno $0$ dopo un $1$ **Rifiutiamo** la stringa ( l'ordine degli $0$ è scorretto )
>7. Se ho ancora input ma lo **stack** è *vuoto* **Rifiutiamo** la stringa

>[!note] 
>Un **PDA** è *non deterministico* ( un **DPDA** ( *Deterministic PDA* ) è *deterministico* ) 

>[!note] 
>Possiamo dimostrare che **PDA** e [[Context-Free Grammar|CFG]] sono *equivalenti*

>[!important] Definizione Formale di **PDA**
>
>Un **PDA** è una *sestupla* $(Q,\Sigma,\Gamma,\delta,q_0,F)$ dove :
>
>+ $Q$ : è un insieme finito di stati
>+ $\Sigma$ : è l'*alfabeto* del **PDA**
>+ $\Gamma$ : un insieme finito di simboli che posso scrivere nello **stack** ( l'*alfabeto* dello **stack** )
>+ $q_0 \in Q$ : è lo [[Start Symbol]]
>+ $F\subseteq Q$ : è l'insieme degli stati *accettanti*
>+ $\delta$ : $Q \times \Sigma_{\epsilon} \times \Gamma_{\epsilon} \to \mathcal{P}(Q\times \Gamma_{\epsilon})$ : è la funzione di transizione

![[Linguaggio PDA]]

Possiamo rappresentare un **PDA** attraverso la seguente rappresentazione grafica

![[PDA_ex.excalidraw]]
Passiamo da $q_i$ a $q_j$ leggendo in input $w$ , $a$ rappresenta la cima dello **stack** , $b$ è la nuova cima
>[!example] 
>+ $\epsilon \to b$ : `push(b)`
>+ $a \to b$ : `pop(a)` e `push(b)`
>+ $a \to \epsilon$ : `pop(a)`
>+ $\epsilon \to \epsilon$ : non modifico lo **stack**

>[!example] 
>Costruiamo un **PDA** per $\{0^n1^n | n \ge 0\}$ 
![[PDA_test.excalidraw]]
>>[!note] 
>>Questo **PDA** non accetta stringhe vuote , per fare ciò dovremmo modificare la transizione tra $a$ e $b$ in $\epsilon, \epsilon \to \epsilon$

>[!example] 
>Costruiamo un **PDA** per $\{a^ib^jc^k | i,j,k \ge 0 \text{ e } i = j \text{ oppure } i = k \}$ ( ossia stringhe con stesso numero di $a$ e $b$ o stesso numero di $a$ e $c$ )
![[PDA_ijk.excalidraw]]
>>[!note] 
>>Lo stato iniziale può essere anche non accettante tanto tutte le transizioni sono $\epsilon$ transizioni , arriverei lo stesso ad uno stato accettante

>[!example] 
>Costruiamo un **PDA** per $\{ww^{R} | w \in {0,1}^*\}$ ( ossia stringhe $w$ concatenate dalla sua inversione $w^R$ , `100|001` ) 
![[PDA_R.excalidraw]]

