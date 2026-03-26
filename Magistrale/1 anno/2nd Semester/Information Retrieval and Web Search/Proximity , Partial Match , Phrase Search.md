>[!example] WestLaw system
>
>Has the following operators :
>+ `/p` : matches in the same *parargaph*  
>+ `/s` : matches in the same *sentence*
>+ `/k` : matches within $k$ words
>+ `!` : trailing waildcard ( ex `disabl!` matches `disability` or `disable` ecc  )
>+ *spaces* are interpreted as `OR`

>[!warning] Problem
>
>We want to be able to search for a complete phrase ( ex `standford univerity` ) , this can be seen as an *AND* with a specific **order** in the terms 
>
>For this we we need to store more than `<term : docs>`

# Biword indexes

Uses the following *tokenizer* : 
+ Index every *consecutive pair of terms* in the text as a phrase

>[!example] 
>For the text `Friends, Romans, Countrymen` we produce the following *biwords* :
>+ `friends romans`
>+ `romans countrymen`

Each *biword* becomes a **dictionary term**

>[!note] 
>This only allows for *two word* phrase query processing

We still can encounter *false positive* for long phrases 

>[!example] 
>
>Searching `standford university palo alto` , this will be broken down in : 
>`"stanford university" AND "univesity palo" AND "palo alto" `
>
>Can produce phrases like this : 
>+ *Stanford University* is in *Palo Alto*. This is not the only *university. Palo* Alto also hosts Palo Alto University

Another problem is the *index blowup* due to the bigger dictionary , it doesnt scale for larger *k-words* indexes
# Positional Indexes


