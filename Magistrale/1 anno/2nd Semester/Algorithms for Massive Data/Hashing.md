---
publish: true
---
# Randomization

It's often easier to design algorithms under the *assumption* that $x_1, \dots, x_m$ are *random*

>[!example]- 
>[Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort) allows us to perform *sorting* on $x_1,\dots,x_m$ distributed uniformly in *expected* $O(m)$ time

However generally $x_1,\dots,x_m$ are **not** *random* , we use *hashing* to randomize this input

# Hashing

