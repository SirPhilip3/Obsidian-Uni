---
publish: true
---
>[!important] Problem Definition
>
>Given a dataset $A={x_{1},\dots,x_{m}}$ and a *distance threshold* $D$ build a *data structure* such that later, given any new data point $x$, we can quickly find *one* element $x_{i}\in A$ such that $d(x_{i},x)\le D$

>[!warning] 
>+ Each $x_{i}$ could be very large
>+ Computing $d(x_{i},x)$ is *expensive* , we can use sketches
>+ $d()$ is typically required to be a [[Introduction to sketching#^c22ae4|Metric]] 
>+ Soving this problem *exactly and quickly* is **impossible** for most metrics , we are happy with a *correct* solution with *large* *probability* and *few* *False Positives*

#todo 146