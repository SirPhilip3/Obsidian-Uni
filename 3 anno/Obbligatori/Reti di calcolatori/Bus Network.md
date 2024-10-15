---
creation: 2024-10-14T12:56:00
---
>[!example] 
>![[Pasted image 20241014125658.png]]
>

**Pros** : 
+ Poco costosa , abbiamo bisogno di un solo link che collega tutti

**Cons** : 
+ Visto che tutte le comunicazioni gestiscono lo stesso link fisico , non posso scalarla su reti di grandi dimension
+ *non robusta* : se il *bus* si rompe la rete viene divisa in due parti 

>[!important] 
>Rete utilizzata solo in specifici scenari ( ex CAN-bus )

>[!note] 
>Possono avvenire *collisioni* se due *host* trasmettono allo stesso tempo , in questo caso il *ricevitore* non riuscirà a distinguere tra i due segnali e dropperà entrambi i [[Frame]]
>
>Questo avviene soprattuto in una rete *wireless* poichè il ricevitore possiede una singola radio , se due host comunicano allo stesso tempo vi sono collisioni

