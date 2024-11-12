---
creation: 2024-11-12T09:03:00
---
Il **Cifraio di cesare** o ( *ROT-13* , in questo caso $K=13$ ) 

Dato $K$ come un numero compreso tra $1$ e $25$ , questa sarà la chiave dell'algoritmo , per *criptare* un testo :
1. Per ogni lettera $X$ dell'input
2. Trasfoma $X$ nella sua posizione all'interno dell'alfabeto : $X \to N_X$
3. Aggiungi $K$ a $N_X$ : $N_X+K \mod{25}$
4. Rimpiazza $X$ con la lettera dell'alfabeto relativa a $N_X+K \mod{25}$ 

Per *decifrare* il testo facciamo lo stesso solo sottraendo $K$ invece di sommarlo

>[!warning] 
>
>Visto che la $K$ può avere solo 25 valori , questo permette semplici attacchi di *brute force*
>
>Possiamo renderlo più complesso se utilizziamo un mapping statico , casuale tra le lettere vecchie e quelle nuove , in questo modo $K$ diventa il numero di permutazioni di 26 rendendo *brute force* più difficile 

>[!danger] 
>
>Visto che il testo che *criptiano* sarà in un determinato linguaggio e il mapping è consistent , allora il testo cifrato avrà la stessa frequenza di lettere rispetto all'originale , semplicemente si cercerà di matchare le lettere con simile frequenza tra i due testi ricavando così il mapping delle lettere 

