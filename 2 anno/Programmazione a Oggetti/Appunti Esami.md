---
~
---

Una classe è final -> non può essere estesa da altre classi 

rappresentazione di dati immutabili : 
+ classe static ( non può essere istanziata ) inner classes ????
+ campi final

Interfaccie : 

**Iterator**

```java
@Override  
public boolean hasNext() {  
    return se ho un prossimo valore;  
}  
  
@Override  
public ... next() {  
    return prossimo valore;  
}
```


**Iterable** 

```java
@Override  
public Iterator<...> iterator() {  
    return iteratore;  
}
```