---
publish: true
---
**Tipo di dato**
Un tipo di dato (o semplicemente tipo) è un insieme di valori sul quale sono definite delle operazioni

**Oggetto**  
Un oggetto è una regione di memoria alla quale è associato un tipo

**Variabile**  
Un oggetto al quale è associato un nome

**Dichiarazione**  
Una dichiarazione è un'istruzione che introduce un nuovo nome.  
Esempio:  
int a;  
int& b=a;

**Definizione**  
Una dichiarazione è anche una definizione quando specifica completamente il nome introdotto. Per esempio: "int a;" è una definizione (e quindi anche una dichiarazione). Invece la dichiarazione "extern int a;" introduce il nome a che però è allocato altrove. In questo caso parliamo di dichiarazione ma non di definizione. 

**Conversione implicita di tipo**
Si ha quando in un assegnamento o inizializzazione, l'espressione ha un tipo diverso, ma compatible, con il lvalue. In C, e in C++, tutti i tipi numerici sono fra loro compatibili. Quindi se assegniamo ad una variabile di tipo double un valore di tipo int, abbiamo una conversione di tipo implicita. Nel caso in cui questa conversione di tipo porti a perdita di informazione si parla di **narrowing**. Per esempio, abbiamo narrowing se assegno ad una variabile int un valore double.



Data una lista dividaila tra l'n ele pari e n ele dispri