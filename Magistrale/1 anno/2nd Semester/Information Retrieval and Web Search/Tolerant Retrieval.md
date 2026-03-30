# Wild-card queries

>[!example] 
>`mon*` finds all docs containing any word beginning with *mon*

## End Wildcard
`mon*`

This is easily implemented with [[Dictionaries#Binary tree|Binary trees]] or [[Dictionaries#B-tree|B-trees]] 

We simply retrieve all the terms between the range : `mon <= ... <= moo`
## Start Wildcard
`*mon`

This can be done by maintaning all the *terms* in **reverse** in another *B-tree* ( *reverse B-tree* )

>[!example] 
>`sermon -> nomres`
## Middle Wildcard
`co*tion`

This can be handled by doing the `AND` method of the two previous modes 
>[!example] 
>`co* AND *tion`

This is **expensive** 

>[!success] Solution
>Transform the *wild-card* queries so that the `*` appears always at the end of the word
>
>This is called **Permuterm** *index*
# Permuterm Index

For each term we store all the possible *suffixes* and associated *prefixes* in a *B-tree*, all linking to the original *term* : 
>[!example] 
>`{hello$, ello$h, llo$he, lo$hel, o$hell, $hello} -> hello`

>[!note] 
>This increases the dictionary/lexicon size since for each term we store $n+1$ terms , where $n$ is the *term size*
## Using Permuterm to solve Middle Wildcard

>[!example] 
>Query `h*e` 
>1. Insert `$` at the end : `h*e$`
>2. Rotate the term until `*` is at the end : `e$h*`
>3. Search terms starting with `e$h` in the *B-tree* :
>	1. `e$h` : returns the *postings* of *he*
>	2. `e$hol` : returns the *postings* of *hole*
>	3. `e$hop` : returns the *postings* of *hope*

## Other Queries

+ `X` : lookup `X$`
+ `*X` : lookup `X$*`
+ `X*Y` : lookup `Y$X*`
+ `X*` : lookup `$X*`
+ `*X*` : lookup `X*`
+ `X*Y*Z` : The rotation will be the following `X*Y*Z$ -> Z$X*Y*` , than do the query for `Z$X*` and filter the results for the ones containing `Y`

# K-Gram Index

For each *term* enumerate each of it's *k-grams* ( sequence of $k$ chars ) 

>[!example] 
>$2$-gram of `April is the cruelest month` :
>`$a,ap,pr,ri,il,l$,`
>`$i,is,s$,`
>`$t,th,he,e$,`
>`$c,cr,ru,ue,el,le,es,st,t$,`
>`$m,mo,on,nt,h$`
>
>`$` is a *boundary* symbol

We than maintain a *second* [[Inverted Index]] ( other than the normal one containing *term* and *docID* ) from $k$-grams to *dictionary terms* that match each $k$-*gram*

>[!example] 
>![[K-gram.excalidraw.png]]
>%%[[K-gram.excalidraw.md|🖋 Edit in Excalidraw]]%%

## Processing Wildcards

Processing `mon*` we run the following *query* on the *second* [[Inverted Index]] : 
+ `$m AND mo AND on`

>[!warning] 
>This would also enumerate `moon` that is *wrong* , we would need to *post-filter* the resulting *terms* with the original query ( `mon*` ) , this is *slow*

Given the *filterd* terms we would use the normal [[Inverted Index]] to look up the *docID's*

---
*Middle wildcard*

To process `mo*n` we transform it into the following : `$mo*n$` and than do the following *query* : 
+ `$m AND mo AND n$`

# Index Comparison

**Permuterm** is not *space efficent* , for each term of lenght $n$ we would store $(n+1)*(n+1)$ chars ( $+1$ because of the `$` )

**2-grams**

**3-grams**