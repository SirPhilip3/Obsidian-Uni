---
creation: 2024-10-23T09:32:00
---
>[!info] Idea
>I *router* si scambiano messaggi in modo che ognuno sappia tutta la topografia della rete , in base alla topologia imparata ogni *router* deciderà indipendentemente il cammino minimo tramite un algoritmo di *shortes path* come *Dijkstra*

>[!note] 
>La rete è rappresentata attraverso un grafo direzionato con i *link* che possono avere diversi tipi di pesi : 
>+ Peso *unitario*
>+ Peso proporzionale al *delay* del link , il percorso più breve sarà quello con minore *delay* complessivo
>+ $\frac{C}{link\_capacity}$ dove $C$ è una *costante* , più grande sarà la capacità del *link* minore sarà il peso 

## LSP Messages

Ogni *router* ha un indirizzo unico 

Un *router* manda un messaggio di `HELLO` ogni $N$ secondi su tutte le sue interfacce , questo messaggio contiene l'indirizzo del *router* , visto che anche tutti i suoi vicini mandano messaggi di `HELLO` questo automaticamente scopre tutti i suoi vicini

>[!note] 
>Se un *link* fallisce questo non potrà più mandare messaggi di `HELLO` , un *link* viene considerato fallito se non abbiamo ricevuto un `HELLO` per almeno $k\times N$ secondi

![[Pasted image 20241023100049.png]]

![[Link state packet]]

## LSP Flooding

Visto che ogni *router* deve avere una rappresentazione completa della rete prima di potere trovare i cammini migliori un algoritmo di **Flooding** viene usato per distribuire gli *LSP* tra tutti i *router* della rete 

Ogni *router* mantiene un *link state database* ( **LSDB** ) che contiene gli *LSP* ricevuti più di recente 

Quando un *router* riceve un *LSP* verifica con il *sequence number* se è già presente all'interno dell **LSDB** , se era già presente il router non dovrà instradarlo ad altri router 

Se non era presente dentro l'**LSDB** invio l'*LSP* a tutti i miei vicini tranne a quello da dove era arrivato 

```c
if newer(LSP, LSDB(LSP.Router)): // prende l'ultimo LSP dal DB e lo compara con quello che ci è arrivato
	LSDB.add(LSP) // rimuove anche gli LSP più vecchi che arrivano dallo stesso router
	for i in links:
		if i != l:
			send(LSP,i) 
```

>[!note] 
>Il numero di sequenza non è una timestamp quindi prima o poi dovreà wrappare su se stesso 

>[!example] 
>Rete dopo il **Flooding**
>![[Pasted image 20241023103034.png]]
## Link Failure

Quando un *link* fallisce i due *router* collegati rilevano il fallimento visto che non ricevono più i messaggi di `HELLO` 
>[!note] 
>Viene ritenuto un fallimento solo dopo che non riceviamo un `HELLO` per $k\times N$ secondi

Questi genereranno dei nuovi [[Link state packet|LSP]] che non conterrano più quel *link* 

>[!example] 
>Dopo la propagazione degli [[Link state packet|LSP]] dopo 3 hop 
>
>![[Screenshot 2024-10-24 at 09-05-43 main (10)_2.jpg]]
>
>>[!note] 
>>Dopo il secondo *hop* la rete è convergente , il **Flooding** fa in modo che un singolo *router* possa ricevere più copie dello stesso messaggio
>
>In generale un *link* 