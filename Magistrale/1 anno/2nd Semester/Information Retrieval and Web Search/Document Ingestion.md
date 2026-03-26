In order to *parse* a document we first need to determine : 
+ it's format (pdf, excel, html )
+ it's language 
+ what character set is used

>[!note] 
>Some may use multiple languages in the same document

In general also we need to define what is a unit document : a file , an email etcc 
# Tokenization

A *tokenizer* is a software that given as input a stream of character returns as output a stream of *tokens* based on some separating features ( the simpliest is the space ) 

>[!example] 
>Input : "Friends, Romans and Countrymen"
>Output : 
>+ Friends
>+ Romans
>+ Countrymen

Each *token* is a candidate to becoming a **term** in the index, this in fact depends on the further processing that we do to a *token* before insertion 
## Issues 

If we simply use space as a separator then we could lose some information

>[!example] 
>`Mar. 12, 1991` would be split into `Mar.` , `12,` and `1991`
>
>Removing any meaning to the *token* 

Or we may never separate words , for example *chinese* and *japanese* don't have any separato between symbols 

# Terms normalization

A *term* is the *normalized token* that we put in the *Information Retrieval* dictionary

This can be done with a **mapping rule** : `{equivalence class} -> term`

>[!example] 
>+ `{Word,WORD,word} -> word`
>+ `{USA,U.S.A.,usa} -> USA`

In general the names of the *equivalence class* are the *terms*

We need to mimic how the use will do the query, like removing the *accents* 
## Stop words 

We can use a *stop list* to exclude from the *dictionary* the most common stop words since they have little semantic meaning ( the, a, and, to )

>[!note] 
>In the *state of the art* we don't actually do this since we can compress them a lot and so theyr impact is really slow 

## Synonyms

We can use *equivalence classes* to map them and use them in the *index* or to expand the use query 
## Lemmatization

Reduces variant of a verb or noun to it's *base form*

>[!example] 
>+ am, are, is -> be
>+ car, cars, car's -> car
## Stemming

Reduces words to their *roots* 

>[!example] 
>+ automate(s), automatic, automation -> *automat*

## Porter's algorithm

Rule-based reductions separated in *phases* each consisting of a set of commands 

The rule that we apply is decided based on the *longest matching suffix* to be *removed*

**Rules** :

| Prefix | Substitution |
| ------ | :----------: |
| SSES   |      SS      |
| IES    |      I       |
| SS     |      SS      |
| S      | $\emptyset$  |
*Examples*
+ care*sses* $\to$ care*ss*
+ pon*ies*   $\to$ pon*i*
+ care*ss*    $\to$ care*ss*
+ cat*s*       $\to$ cat
