# Laboratorio 1 

simulazione popolazione pseudo randomici 

```r
popolazione <- rexp(n = 5000, rate = 1/40)
```
seed per definire `{r}setseed(...)`

vera media = `{r}mean(popolazione)` 

sample estrae delle osservazioni dalla popolazione ( *iid* )

media campionaria stimatore non distorto se valroe atteso = vero valore parametro
per vedere questo media delle medie di molti campioni
```r
replicate() # n volte un comando
```

```r
range
```

```r
mean(medie) ~ media.pop 
```

hist(mean , breaks ) , breaks suggestione ad r , decide in modo autonomo 

scala della densità utile per comprendere il modello che li descrive ( dist normale per media campionaria )

permutazione = sample (popolazione) crea permutazione di popolazione ( campione casuale ) con size permuta il campione e prende le prime size el

verificare la consistenza , aumentiamo dimensione campione , verificahiamo che convergiamo alla 

cumsum -> somme cumulate , 1 el somma primi 2 , 2 el = somma primi 3 etcc
sum(permutazioni[1:20]) -> numeratori[20]

numeratori[1]/denominatori[1] -> prima media campionaria etcc...

la media campionaria converge in media di popolazione  

Analisi descrittive : 

ci sono 9+ modi per calcolare il quartile ,
```r
quantile(type=2)
# stesso tipo del libro
```

with utilizza un oggetto e i valori di quell'oggetto ( es x e y )

# 29/02/2024

# Prova Intermedia 

