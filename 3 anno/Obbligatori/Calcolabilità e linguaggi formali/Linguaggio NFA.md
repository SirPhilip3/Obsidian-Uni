---
creation: 2024-09-25T10:45:00
tags:
  - Definizione
publish: true
---
Sia $N = (Q\ , \sum\ ,\delta\ ,q_0\ ,F\ )$ un [[NFA]] e sia $w$ una stringa costruita con l'alfabeto $\sum$ 

$N$ **accetta** $w$ se e solo se $w=y_1y_2\dots y_m$ dove $\forall i : y_i \in \sum \cup \{\epsilon\}$ ( ossia le $\epsilon$ vengono trattate come tutte le altre mosse , ci basterà aggiungerle all'interno di $w$ ) ed esiste una sequenza di *stati* $r_0,r_1,\dots r_m \in Q$ tale che : 
1. $r_0 = q_0$
2. $r_m \in F$
3. $\forall i \in [0, m-1] : r_{i+1}\in \delta(r_i,y_{i+1})$

