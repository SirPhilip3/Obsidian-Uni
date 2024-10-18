---
creation: 2024-10-18T11:26:00
---
Sia $M=(Q,\Sigma,\Gamma,\delta,q_0,F)$ un [[06 Automi a Pila|PDA]] dichiamo che $M$ accetta $w$ se e solo se $w = w_1,w_2,\dots,w_m$ dove $\forall i \in [1\dots m]$ $w_i \in \Sigma_{\epsilon}$ ( dove $\Sigma_{\epsilon} = \Sigma \cup \epsilon$ ) ed esistono poi una sequenza di *stati* $r_0,r_1,\dots,r_m\in Q$ e una sequenza di stringhe $s_0,s_1,\dots,s_m\in \Gamma_{\epsilon}$ tali che valgono le seguenti condizioni : 
1. $r_0 = q_0$ e $s_0 = \epsilon$ ( )