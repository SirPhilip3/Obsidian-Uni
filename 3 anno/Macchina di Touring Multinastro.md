---
creation: 2024-11-06T10:07:00
---
Una **MdT** *multinastro* avrà $k>1$ nastri : 
+ Riceve l'input sul *primo* nastro
+ quando *computa* : 
	+ legge da $k$ nastri
	+ modifica $k$ nastri
	+ sposta $k$ testine arbitrariamente 

La *funzione di transizione* diventerà quindi : 
$$\delta : Q \times \Gamma^k \to Q \times \Gamma^k \times \{L,R,S\}^k$$
Dove : 
+ $Q \times \Gamma^k$ : dallo stato $Q$ legge $k$ simboli da $k$ nastri
+ $Q \times \Gamma^k \times \{L,R,S\}^k$ : passa ad uno stato $Q$ modificando $k$ simboli e fa $k$ passi indipendenti gli uni 