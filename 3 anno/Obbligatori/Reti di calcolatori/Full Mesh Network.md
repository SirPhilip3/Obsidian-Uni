---
creation: 2024-10-14T12:49:00
publish: true
---
>[!example] 
>![[Pasted image 20241014124955.png]]

+ **Pros** : 
	+ Ogni link tra due singoli *host* avrà *capacità massima* visto che non dovremo condividere quel cavo con nessun altro
	+ *Massima robustezza* : ha un alta resistenza ai guasti visto che tutti gli host sono collegati con tutti gli altri host 
+ **Cons** : 
	+ Necessitiamo di un totale di $\frac{n(n-1)}{2}$ link fisici
	+ Ogni *host* necessiterà di avere $n-1$ interfaccie per comunicare con tutti gli altri $n$ host

>[!important] 
>Questo tipo di rete non viene quasi mai utilizzata visto che scala molto male