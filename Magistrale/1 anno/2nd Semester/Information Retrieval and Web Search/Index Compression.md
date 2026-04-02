---
publish: true
---
Compressing : 
+ **Dictionary**
	+ Small enough to keep it in main memory all the time 
+ **Postings files**
	+ Reduce disk space
	+ Decrease time needed to read the postings lists from disk 
# Initial Sizes 

![[Pasted image 20260402150601.png]]
# Heap Law

# Zipf Law

# Dictionary Compression

## Fixed Width array

Simply store each *dictionary* entry as the following struct : 
```c
struct Term{ 
	char[20] term;
	int frequency;
	int postings_pointer;
}
```

So in total each term will be : 
+ $20$ bytes for the *term* itself + 
+ $4$ bytes for the *frequency* of the term + 
+ $4$ bytes for the pointer to the *postings list*

This for $\sim 400000$ terms, we will have $400000 \times 28 = 11.2 MB$

>[!warning] 
>This method is wasteful since not all the *terms* need $20$ bytes to be stored , also we can't handle very large words 
## Dictionary as a String

Store the *dictionary* as a long string of characters , in the struct we save a pointer stating the starting postion of that term on the string ( the lenght of the term is the distance between the current pointer and the next one )

A string containing $400000$ *terms*, each of *average lenght* $8$ , will need $400000 \times 8B = 3.2MB$

And since we need to resolve $3.2M$ pointers positions we will need $\log_2 3.2M=22$bits to store the *pointers* ( $3$ *Bytes* )  

....
### Blocking

### Front coding

# Postings Compression