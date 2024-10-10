---
creation: 2024-10-10T09:41:00
---
![[Context-Free Grammar]]

Definizione di **Linguaggio Context-Free** : 
>[!important] Definizione
>Un linguaggio $A$ si dice *context-free* se e solo se esiste un [[Context-Free Grammar|CFG]] $G$ tale che $L(G)=A$ 

>[!important] Definizione
>Sia $G=(V,\Sigma,R,S)$ ( [[Context-Free Grammar|CFG]] ) definiamo $L(G)$ come :
>$$L(G)=\{w \in \Sigma^*\ |\ S\implies^*\ w\}$$

>[!example] Esempio di [[Context-Free Grammar|CFG]]
>Si assuma $\Sigma=\{0,1\}$ , fornire un [[Context-Free Grammar|CFG]] per i seguenti linguaggi : 
>1. Stringhe che comprendono almeno tre $1$ :
>	```pseudo
>	\begin{algorithm}
>	\begin{algorithmic}
>	\State $S \to A1A1A1A$
>	\State $A \to 0A|1A|\epsilon$
>	\end{algorithmic}
>	\end{algorithm}
>```

>[!note] 
>Abbiamo rimosso il requisito delle tre $1$ nello [[Start Symbol]] e poi aggiunto espressività per creare una stringa qualsiasi

>[!example] Esempio di [[Context-Free Grammar|CFG]]
>2. Due stringhe che inizino e finiscono con lo stesso simbolo  
