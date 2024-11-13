---
creation: 2024-10-18T11:26:00
publish: true
---
Sia $M=(Q,\Sigma,\Gamma,\delta,q_0,F)$ un [[06 Automi a Pila|PDA]] dichiamo che $M$ accetta $w$ se e solo se $w = w_1,w_2,\dots,w_m$ dove $\forall i \in [1\dots m]$ $w_i \in \Sigma_{\epsilon}$ ( dove $\Sigma_{\epsilon} = \Sigma \cup \epsilon$ ) ed esistono poi una sequenza di *stati* $r_0,r_1,\dots,r_m\in Q$ e una sequenza di stringhe $s_0,s_1,\dots,s_m\in \Gamma_{\epsilon}$ tali che valgono le seguenti condizioni : 
1. $r_0 = q_0$ e $s_0 = \epsilon$ ( lo **stack** inizia dalla stringa vuota )
2. Per $i = 0 \dots m-1$ abbiamo $(r_{i+1},b) \in \delta(r_i,w_{i+1},a)$ dove $s_i = at$ e $s_{i+1} = bt$ ( lo stato dello **stack** è rappresentato da stringhe ) per qualche $a,b \in \Gamma_{\epsilon}$ e $t \in \Gamma^*$ ( $t$ rappresenta il resto dello **stack** ) ossia lo stato successivo $r_{i+1}$ e il simbolo in cima allo **stack** $b$ è determinato dalla *funzione di transizione* avendo in input lo stato corrente $r_i$ , il carattere in input $w_{i+1}$ e il carattere in cima allo **stack** : $a$ 
3. $r_m \in F$ : alla fine dell'input dobbiamo trovarci in uno *stato finale* 


>[!note] 
>Possiamo avere 4 possibilità per $a$ e $b$ : 
>+ $a \neq \epsilon$ , $b \neq \epsilon$ : `pop(a)` dopo `push(b)`
>+ $a = \epsilon$ , $b\neq \epsilon$ : `push(b)` ( $s_{i+1}$ diventa più lungo , aggiungiamo $b$ )
>+ $a \neq \epsilon$ , $b = \epsilon$ : `pop(a)` ( $s_i$ è più lungo , togliamo $a$ )
>+ $a = b = \epsilon$ : lo **stack** non viene toccato

>[!note] 
>Non richiediamo nulla riguardante lo **stack** per l'accettazione di un input

>[!important] Accettazione per **stack** vuoto
>
>Appena inizia la computazione facciamo la `push`di un simbolo convenzionale ( generalmente $\$$ ) , quando lo leggiamo di nuovo sappiamo che lo **stack** è vuoto