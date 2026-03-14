DBMS recap

data warehousing -> hystorical data -> doesn't need normal form optimization

table space -> desc of how data is stored -> ex in a directory 

phisical plan connected phisical operator (execution plan) 

presentation about (individual discussion italian) :
+ project
+ paper -> presentation of the contents + linking to the course

---

DBMS

requirements :
+ manage data 
	+ store search update
	+ transaction -> from consistent to consistent state

+ structured data 
+ semi strucutured
+ unstructured data

+ efficent
+ persistent data
+ reliable
+ consistent data
+ no redundancy
+ multiple users

Design Patterns-> 3 main components : 
+ permanent memory
+ storage engine -> service that accepts some req and gets some answers -> tools used to acces the data according to some access pattern
+ data model engine -> transforms user query into internal behaviour -> something executed by the storage engine (query into execution plan -> efficient enough)

modular building blocks 

store data in different ways in order to optimize queries

access methonds -> algo to access data strucutures
transaction and concurrency managment

message queues -> how programs accesses the dbms physically

RDBMS
data stored on what it describes
