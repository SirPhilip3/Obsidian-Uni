---
creation: 2024-10-16T09:48:00
publish: true
---
Generalmente non possiamo assumere che il [[DataLink Layer]] sia lo stesso per tutti i *router* , una feature specifica del [[DataLink Layer]] è però la massima dimensione ( **MTU** , *maximum transfer unit* ) di un [[Frame]] 

>[!example]
>In internet è possibile la seguente situazione :  
>![[Pasted image 20241016095144.png]]
>
>$A$ invia un [[Frame]] di dimensione $1000B$ ( con destinazione $B$ ) ad $R1$ , questo però non può semplicemente inviarlo ad $R2$
>

In questa situazione $R2$ può fare tre cose : 
1.  **Drop and Notify** : 
	$R1$ rifiuta il [[packet]] e ritorna un *control packet* ad $A$ con l'informazione che la dimensione massima del suo prossimo hop è $500B$ 
	$A$ reinpacchetterà il pacchetto in [[packet]] più piccoli
>[!warning] 
>Potremmo dover fare questa operazione più volte durante la trasmissione , $A$ deve mantere i pacchetti per molto tempo
1.  **Fragment and Reassemble at Next Hop** : 
	$R1$ può dividere il *pacchetto* in due parti , queste vengono trasmesse a $R2$ che poi le riassembla prima di inviarlo  
>[!warning] 
>Forza i router a riassembleare i paccheti prima di inviarli , introduce delay
1.  **Fragment and Reassemble at Destination**
	Ogni fragmento prodotto da $R1$ è un [[packet]] indipendente , in modo che arrivino a destinazione ognuno indipendente l'uno dall'altro
	Quando arriveranno tutti a $B$ ricostuiremo il pacchetto originale 
>[!important] 
>Miglior trade-off, introduce delay in un solo *router* e delega il riassemblamento alla macchina di destinazione



