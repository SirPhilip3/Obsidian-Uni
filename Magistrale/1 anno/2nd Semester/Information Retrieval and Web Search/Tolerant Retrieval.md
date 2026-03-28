# Wild-card queries

>[!example] 
>`mon*` finds all docs containing any word beginning with *mon*

## End Wildcard
`mon*`

This is easily implemented with [[Dictionaries#Binary tree|Binary trees]] or [[Dictionaries#B-tree|B-trees]] 

We simply retrieve all the terms between the range : `mon <= ... <= moo`


## Start Wildcard
`*mon`


## Middle Wildacard
`co*tion`

