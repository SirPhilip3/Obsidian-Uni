---
publish: true
---
# Estimating join sizes

This problem is important since *DBMS* may use different join algorithm depending on the approximated *join* size

sad

>[!example] 
>```SQL
>SELECT *
>FROM R, P
>WHERE R.course_code = P.course_code
>```
>
>For the following tables :
> **R** :
>
| matriculation | course_code | module | evaluation |
| ------------- | ----------- | ------ | ---------- |
| 12345         | _664_         | 1      | 28         |
| 23315         | _664_         | 2      | 18         |
| 10123         | **622**         | 1      | 25         |
| 12345         | **622**         | 1      | 25         |
| 12345         | ***123***         | 2      | 27         |
| 10123         | _664_         | 1      | 25         |
>
>**P** :
>
| course_code | year_active |
| ----------- | ----------- |
| _664_         | 2025        |
| _664_         | 2026        |
| **622**         | 2026        |
| ***123***         | 2026        |
>
>In this case the *size* will be :
>$3*2+ 2*1 + 1*1 = 9$
>
>We want to estimate :
>$$
>\sum_{x\in R.course\_code, y\in P.course\_code, x=y} f_{x,R}f_{y,P}
>$$
>

To *estimate* this we can :
1. Build a **ToW** sketch for $R(course\_code)$ and $P(course\_code)$
$$
sk(R)=\sum_{(x_{1},\dots,x_{4})\in R} h(x_{2})  = \sum_{x \in R.course\_code} f_{x,R} \cdot h(x)
$$
>[!note] 
>$x_{2}$ is the second column or `course_code`

2. Our estimator is $sk(R)\cdot sk(P)$

$$
E[sk(R) \cdot sk(P)] = E\left[ \left( \sum_{x \in R.course\_code} f_{x,R}\cdot h(x) \right)  \cdot \left( \sum_{x \in P.course\_code} f_{x,P}\cdot h(x) \right)\right]
$$
This estimator is *unbiased* 

**Proof** :
$$
\begin{align}
 E\left[ \left( \sum_{x \in R.course\_code} f_{x,R}\cdot h(x) \right)  \cdot \left( \sum_{x \in P.course\_code} f_{x,P}\cdot h(x) \right)\right] & =  \\
 \left( \sum_{x \in R.c\_c, y \in P.c\_c, x=y} f_{x,R}f_{y,P} \cdot E[h(x)\cdot h(y)] \right) + \left( \sum_{x \in R.c\_c, y \in P.c\_c, x\neq y} f_{x,R}f_{y,P} \cdot E[h(x)\cdot h(y)] \right) & =
\end{align}
$$

Knowing that $E[h(x)\cdot h(y)] = 1$ if $x=y$ otherwise its $0$ we have :
$$
= \sum_{x\in R.course\_code, y\in P.course\_code, x=y} f_{x,R}f_{y,P}
$$

>[!note] 
>If we build a **ToW** sketch of *every column* of *every table* in the database we can estimate the join size between any two tables 
>
>The sketch can be *easily updates* when *new rows* are *added*/*deleted* 

# Aggregations on one table

>[!example] 
>```SQL
>SELECT SUM(evaluation)
>FROM R
>WHERE matriculation = 12345
>```
>
>
| matriculation | course_code | module | evaluation |
| ------------- | ----------- | ------ | ---------- |
| 12345         | 664         | 1      | *28*       |
| 23315         | 664         | 2      | 18         |
| 10123         | 622         | 1      | 25         |
| 12345         | 622         | 1      | *25*       |
| 12345         | 123         | 2      | *27*       |
| 10123         | 664         | 1      | 25         |
>
>$$\sum_{(x_{1},\dots,x_{4})\in R : x_{1}=12345} x_{4}=28+25+27=80$$
>

To estimate this we build the following *sketch* :
$$
Q_1(R)=\sum_{(x_{1},\dots,x_{4})\in R} h(x_{1}) \cdot x_{4}
$$
The *estimator* is :
$$
Q_{1}(R) \cdot h(x)
$$
>[!note] 
>$x=12345$

>[!note] 
>The *sketch* depends on the *structure* of the query not on the *input value* $x$

>[!important] Theorem
>$Q_{1}(R)\cdot h(x)$ is *unbiased*

**Proof** :

$$
\begin{align}
E[Q_{1}(R)\cdot h(x)] & = \\
& = E\left[ \sum_{(x_{1},\dots,x_{4})\in R} h(x_{1}) h(x) \cdot x_{4} \right]  \\
& = \sum_{(x_{1},\dots,x_{4})\in R: x_{1} =x} E[h(x_{1})h(x)] \cdot x_{4} + \sum_{(x_{1},\dots,x_{4})\in R: x_{1}\neq x} E[h(x_{1})h(x)] \cdot x_{4} \\
& = \sum_{(x_{1},\dots,x_{4})\in R: x_{1} = x} x_{4}
\end{align}
$$

# Aggregations + Join

>[!example] 
>```SQL
>SELECT SUM(evaluation)
>FROM R,P
>WHERE matriculation = 12345 AND active = 1 AND R.course_code = P.course_code
>```
>
>**R** :
>
| matriculation | course_code | module | evaluation |
| ------------- | ----------- | ------ | ---------- |
| 12345         | 664         | 1      | *28*       |
| 23315         | 664         | 2      | 18         |
| 10123         | 622         | 1      | 25         |
| 12345         | 622         | 1      | *25*       |
| 12345         | 123         | 2      | *27*       |
| 10123         | 664         | 1      | 25         |
>
>**P** : 
>
>| course_code | active |
| ----------- | ------ |
| 664         | 0      |
| 622         | 1      |
| 123         | 1      |
>
>

The *sketch* will be :
$$
Q_{2}(R) = \sum_{(x_{1},\dots,x_{4})\in R} h(x_{1})h(x_{2})\cdot x_{4}
$$
$$
Q_{2}(P) = \sum_{(x_{1},x_{2})\in P} h(x_{1})\cdot h(x_{2})
$$
The *estimator* will be :
$$
Q_{2}(R)\cdot Q_{2}(P) \cdot h(12345) \cdot h(1)
$$
# Final Notes

The *estimators variance* grows with $2^{2N}$ where $N$ is the *number* of *equality conditions* in the `WHERE` clause

The number of repetitions needed to obtain a $(\epsilon,\delta)-$approximation is $O(2^{2N}\cdot \epsilon^{-2}\log(1/\delta))$

>[!note] 
>$N$ is constant in many scenarion so these estimations can be used in practice ad produce accurate results

