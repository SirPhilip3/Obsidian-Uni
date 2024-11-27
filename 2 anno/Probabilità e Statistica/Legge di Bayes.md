#### Legge di Bayes

Sia data la partizione $C_1, C_2, \dotsc$  ( con tutti i suoi elementi tale che abbiano probabilità positiva ) e un evento A ( con probabilità positiva ) Allora avremo che la probabilità condizionata da una qualsiasi partizione sarà :
$$\mathbb{P}[C_m|A]=\frac{\mathbb{P}[A|C_m]\cdot\mathbb{P}[C_m]}{\sum_i \mathbb{P}[A|C_i]\cdot\mathbb{P}[C_i]}$$
Questa può essere derivata da :
+ $$\mathbb{P}[C_m|A]=\frac{\mathbb{P}[C_m\cap A]}{\mathbb{P}[A]}$$
	Derivante dalla definizione di *probabilità condizionata*
+ $$\mathbb{P}[C_m\cap A]=\mathbb{P}[C_m]\cdot \mathbb{P}[A|C_m]$$
	Derivante dalla formula delle *probabilità composte*
+ $$\mathbb{P}[A]=\sum_i\mathbb{P}[A|C_i]\cdot\mathbb{P}[C_i]$$
	Derivante dalla legge della *probabilità totale*

**Interpretazione** :
• Interpretazione del teorema di Bayes: 
	• Permette di aggiornare l’assegnazione di probabilità data a priori a certi eventi $C_m$, alla luce di nuova informazione ($A$ si è verificato). 
	• Il risultato di questa operazione di aggiornamento sono le nuove probabilità $P[C_m|A]$, dette anche a posteriori. 
	• Le probabilità a posteriori costituiscono una sintesi dell’informazione disponibile a priori su un certo fenomeno e dell’informazione empirica.

**Esempio** :

Un’azienda che assembla computer riceve il 24% dei componenti dal fornitore X, il 36% dal fornitore Y e il rimanente 40% dal fornitore Z. Risultano difettosi il 5% dei componenti forniti da X, il 10% dei componenti forniti da Y e il 6% dei componenti forniti da Z. 

Se un computer assemblato presenta un componente difettoso, qual'è la probabilita che questo componente sia stato fornito da Z?

Evidenziamo gli *eventi* :
+ X : Assembalto dal fornitore X ( $P[X] = 0.24$ )
+ Y : Assemblato dal fornitore Y ( $P[Y] = 0.36$ )
+ Z : Assemblato dal fornitore Z ( $P[Z] = 0.4$ )
+ D : Componenti difettorsi ( $P[D|X] = 0.05$ , $P[D|Y] = 0.1$ , $P[D|Z] = 0.06$ )

Ciò che sappiamo è che il componente e danneggiato e noi vogliamo calcolare la probabilità che questo venga dal produttore Z
Avremo che dovremo quindi calcolare :
$$\mathbb{P}[Z|D]=\frac{\mathbb{P}[D|Z]\cdot \mathbb{P}[Z]}{\mathbb{P}[D]}$$
$$\mathbb{P}[D]=\mathbb{P}[X]\cdot\mathbb{P}[D|X]+\mathbb{P}[Y]\cdot \mathbb{P}[D|Y]+\mathbb{P}[Z]\cdot \mathbb{P}[D|Z]$$
$$=0.24\cdot0.05+0.36\cdot0.4+0.4\cdot 0.6$$
Concludendo avremo :
$$\mathbb{P}[Z|D]=\frac{\mathbb{P}[D|Z]\cdot \mathbb{P}[Z]}{\mathbb{P}[D]}=\frac{0.4\cdot0.06}{0.072}=0.33$$