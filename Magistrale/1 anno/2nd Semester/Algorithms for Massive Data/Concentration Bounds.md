---
publish: true
---
# Introduction 

+ Designing *randomized algorihtms* to **estimate** statistics on data stream 
+ The output $X$ of a *randomized algorithm* is a **Random Variable** ( $RV$ )
+ Usually $E[X]$ is equal to the *value* we want to *estimate*

>[!example] 
>
>Estimate the *frequency* $f_x$ of $x$ in a stream $x_1,\dots,x_m$
>
>**Algorithm** : 
>	For every $x_i$ append $x_i$ to a list $S$ with probability $1/1000$
>
>
>
# Concentration Bounds

## Markov ( linear )

## Chebyshev ( quadratic )

### Boosted Chebyshev

## Chernoff-Hoeffding ( exponential )

## Mean+Median trick