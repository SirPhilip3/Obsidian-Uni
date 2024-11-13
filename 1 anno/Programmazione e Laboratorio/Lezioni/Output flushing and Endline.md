---
publish: true
---

Ogni qualvolta viene svolta una `std::cout` l'output viene salvato temporanemente in un buffer, questo viene liberato e mandato in output dopo che abbia raggiunto una grandezza tale per cui sia conveniente a livello di performance. 
Per le operazioni di `std::cout` è fondamentale svolgere il flushing in quanto se ciò non viene svolto potrebbe portare a segmentation fault 

`std::endl` quindi ci permette sia di andare a capo di ogni riga ma allo stesso tempo forza il flushing dell'output

`\n` permette anchesso di andare a capo ma non permette il flushing 

[Flushing](https://www.geeksforgeeks.org/buffer-flush-means-c/)
