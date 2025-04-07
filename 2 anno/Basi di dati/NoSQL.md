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

# 15/05/2024

**Couchbase**

-.....

buchet -> schema tipo mysql -> ogni bucket identifica serie di dati di un determinato gruppo , max 30 

scope (max 1000) -, collection -> \_default , suddivisione in sottogruppi dentro un bucket ( a livello logico )

memory first -> per avere sempre performance su operazioni in memoria ( metadata etcc )

approccio alla normalizzazione -> utilizza json per manetere dati etcc 
subdocument per rappresentare tabelle èadre , figio

doc : 20 mb max
key : 250byte ( non solo id ma anche altre info )
+ natural key -> deriva dal dataset
+ surrogate key -> contatore , sha , uuid
posso avere dei pattern nella key :
+ `DocumentType::ID` -> ex:
	+ `order::id`
	+ `product::uuid`
+ `ApplicationName::DocumentType::ID::ID`
+ `DocumentType::ParentID::ChildID::ID`

informazioni mancanti posso avere :
+ non mettere il campo
+ valore null
+ non dare un valore alla key

per documents -> 
+ campo dedicato -> riduce profondità co -> riduce complessità
+ innestare ho il tipo sempre a portata di mano

utilizzo di array o no per multivalue -> all'aggiornamento senza array dovrei modificare il documento 

dentro array posso mettere sia key che subdoc
generalmente meglio non mischiare subdoc con value

relazioni 1:1 meglio doc insestati -> migliore perf in lettura

1: m -> array di key doc 

se facciamo update dobbiamo propagare l'aggiornamento su doc inestate in altri documenti 

relazioni m:m -> 1:m con m che incorpora l'1 

documento di relazione separato (not to do, documenti ridondanti)

denormalizzazione in lettura molto buno in scrittura dobbiamo considerare molto di più 

**N1QL**

linguaggio di interrogazione couchbase -> SQL per json 

PRIMARY INDEX -> tutto il set di key all'inteno di uno spazio di key
deve manterere aggioranto molti bucket

Stesse SELECT -> supporta * per ritornare tutto il doc
supporta Alias con AS

posso usare la dot annotation 

posso far tornare la key con META().id -> META tutti i metadati del doc

USE KEYS -> cerco doc individuandolo per key 

expiration -> se != 0 quando il doc viene tolto dal sistema 

CREATE INDEX 

posso prendere index con system:indexes

UPSERT update o inser a seconda se c'è la key (update)o no(insert)

# 16/05/2024

**Redis**

modellazione : key-value db

qualsiasi valore binario come key , anche stringa vuota , (512mb max dim)

larger key -> more time to search + more memory 

`recordtype:id:subtype` 

Redis string -> struttura dati std -> come key - value 
mappando stringa in altra stringa

set solo se non esiste la key NX
XX solo se esite la sovrascrivo

x : time to leave

px in millisecond

dati non sono divisi in cartelle -> raggruppa le key

operazioni di incr -> decr ( su stringe anche se su int )
exists -> verifica la presenza
del -> remove key
type -> ritorna il ripo della key

list data type -> linked list 

Lrange -> ritorna el compresi tra i due inde 0-1 o 1-0
Ltrim al di fuori dell'intervallo rimossi
llen lunghezza lista 
blpop / brpop tolgie ultimi 2 o primi 2 el

altro data type -> hash -> primo el key poi coppie key-value

set -> stringe non ripetute ne ordinate , non posso recuperare un inidice ??? 

smembers -> tutti gli el del set 
s.is member -> per trovare el in un set 

persistenza poliglotta in sistema -> più dbms che convivono per gesitre info differenti o per gestire dati differenti 

