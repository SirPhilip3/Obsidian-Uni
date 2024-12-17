---
publish: true
creation: 2024-12-17T09:07:00
---
Per dare la definizione di **Mapping Riducibilità** dobbiamo prima dare la definizione di :
![[Funzione Calcolabile]]

>[!important] Definizione
Un [[Linguaggio]] $A$ è **Mapping Riducibile** ad un [[Linguaggio]] $B$ ( $A \leq_M B$ ) $\iff$ esiste una [[Funzione Calcolabile]] $f$ tale che per ogni stringa $w$ , $w \in A \iff f(w) \in B$ 

![[MappingRiducib.excalidraw]]

>[!note] Osservazione
>
>$A \leq_M B \iff \bar{A} \leq_M \bar{B}$ 

**Teoremi Conseguenti** : 

![[Decidibilità Mapping Riducibilità]]