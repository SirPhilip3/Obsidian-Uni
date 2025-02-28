cryptography 

$c \leftarrow Enc_k(m)$ 
$m \leftarrow Dec_k(c)$ 

shift cypher , monoalfabetici -> freq attack 

polyaphabetical lettere diverse , key -> parola che si ripete -> key ripetuta qunate volte il plaintext -> sposta rispetto a posizione nell'alfabeto della key 

26^m poss key

attacchi -> indovinare length della key -> tutti gli ogetti a dist ex 4 hanno lo stesso shift -> rifaccio l'attacco di prima su solo le lettere shiftate nello stesso modo 

enigma 

vigenere
+ var -> ad ogni ripetizione shift di 1

diag cypher

rail fence

---

attacks

cifraio sicuro se da cyphertext non posso ricostruire ne key ne plaintext  anche sapendo lo schema

attacchi dipendono da quante info :
+ solo cyphertext - > diffiuclt
+ known plaintext -> posso chiedere cypher per dei plaintext
+ chosen cypher
+ chose plain
+ chose text

shannon

confusion -> key deve essere distribuita completamente sul cypertext
diffusion -> tutte le lettere del plaintex si devono diffondere ul cyphertext

perfect cyphertext 

xor -> one time pad 

