---
~
---
not only sql , 

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

