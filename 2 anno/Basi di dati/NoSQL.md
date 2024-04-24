---
~
---
not only sql , 
Document store 
Key -value
wide column -> cassandra
graph store 

[dbNoSql](https://www.ibm.com/it-it/topics/nosql-databases)

>[!todo] 

*Schemaless* : 
```json
{
	"id":3,
	"name":"d",
}

// non essendoci uno schema definito posso cambiare lo schema dei dati senza problemi
{
	"id":3,
	"name":"d",
	"height":345,
}
```

è possibile imporre comunque uno schema ( validator ) , es devo avere certi campi , tipi etcc 
es inserimento fallisce o warna se non si rispetta questo schema

*scalare orizzonalmente* 

proprietà Base :
+ Ba : basically avalilable (nodi)
+ S : soft state (consistenza non è garantita -> il sistema potrebbe cambiare il suo sontenuto senza una query)
+ E : eventually consistent ( i dati saranno consistenti in futuro )

*normalizzazione* costoso per db memory first 

*denormalizzazione* : utilizzando json->posso avere tutto il dato in un unico documento invece che in molte tabelle saprse -> evita operazioni di join

in lettura meglio , in scrittura risulta essere più costoso , devo scrivere tutti i file con le copie dei dati 

## Neo4j

database a grafi

nodo -> tipo di entità dentro ad un grafo 
tipo dell'arco > natura della relazione tra 2 nodi 

posso attraversare più volte stessi nodi ma solo 1 volta per ogni arcio

query risultano essere più semplici (cypher) rispetto a sql 

proprety graph > posso identificare nodi e relazioni e assengarne proprietà (key value)

relazioni -> predicati dentro agli archi , proprietà es da quando sono sposate 2 persone etcc , l'età di una persona etcc

index free adjacency -> non necessitiamo più di avere un index per recuperare qualcosa da una tabella 

utilizza pointers 

rispetta proprietà acide dei database relazionali 

**cypher** -> semplice nella sua sintassi attraverso ascii art -> () rappresentano nodi -[] relazioni

nodi posso non avere etichette o più etichette 
rappresentata -> `(variabile:nomelabel)`

nodi che condividono letichetta possono avere anche proprietà diverse -> schemaless

MATCH (m:Movie (released:2003))
RETURN m.prop

relazioni devono avere un tipo e necessariamente un verso 
()--()
()->()
()<-()

