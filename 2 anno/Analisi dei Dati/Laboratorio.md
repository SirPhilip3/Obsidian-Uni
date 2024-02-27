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


