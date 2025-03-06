---
creation: 2024-11-14T10:07:00
publish: true
---
Dato un [[DFA]] determinare se esso non accetta nessuna stringa ( ***E**mptiness* problem )
$$
E_{DFA} =\{ <D> | D \text{ e' un } DFA \land L(D)=\emptyset\}
$$
>[!important] Teorema
>
>$E_{DFA}$ è [[Decidibile]] 

>[!important] Definizione
>
>Costruiamo un [[Decisore]] $M$ per $E_{DFA}$ 
>>[!example] 
>>Per costruire il [[Decisore]] consideriamo un [[DFA]] , notiamo che la condizione che ci fa capire che rappresenta un linguaggio vuoto è il fatto chè non vi sono stati accettanti raggiungibili dallo stato iniziale ( oppure non ha stati accettanti )
>>
>>![[E(DFA).excalidraw]] 
>
>$M$ aspetta un input $<D>$ :
>1. Marca lo stato iniziale di $D$
>2. Finchè è possibile marcare nuovi stati , marca gli stati con una transizione in entrata da stati già marcati
>3. Se abbiamo marcato uno stato accetante *REJECT* altrimenti *ACCEPT*

