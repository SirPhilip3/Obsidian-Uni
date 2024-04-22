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

