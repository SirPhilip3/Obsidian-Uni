---
publish: true
---
# Estimating join sizes

This problem is important since *DBMS* may use different join algorithm depending on the approximated *join* size

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
1. Build a **ToW** sketch for $R()$