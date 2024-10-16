---
creation: 2024-10-16T08:58:00
---
Il *Control plane* ha il compito di creare le [[Forwarding Table]] 

Per generare [[Forwarding Table]] abbiamo due metodi : 
1. Farlo manualmente :
	Questo funziona in network piccoli e dove le rotte non cambiano molto
2. Generazione automatica :
	Per fare questo necessitiamo di ![[Control Plane Packets]]
	La generazione automatica può essere svolta da una autorità centrale che controlla tutto il network e quindi quando qualcosa cambia genera le nuove [[Forwarding Table]] 
	Visto che su *internet* non c'è un controllore centrale necessitamo di avere un approccio *distribuito*