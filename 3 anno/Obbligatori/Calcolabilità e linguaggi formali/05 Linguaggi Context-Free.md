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
>	```
>
>>[!note] 
>>Abbiamo rimosso il requisito delle tre $1$ nello [[Start Symbol]] e poi aggiunto espressività per creare una stringa qualsiasi
>
>2. Stringhe che inizino e finiscono con lo stesso simbolo  
>	```pseudo
>	\begin{algorithm}
>	\begin{algorithmic}
>	\State $S \to 0A0|1A1|0|1$
>	\State $A \to 0A|1A|\epsilon$
>	\end{algorithmic}
>	\end{algorithm}
>	```
>3. Stringhe di lunghezza dispari
>	```pseudo
>	\begin{algorithm}
>	\begin{algorithmic}
>	\State $S \to CP$
>	\State $C \to 0|1$
>	\State $P \to 00P|11P|01P|10P|\epsilon$
>	\end{algorithmic}
>	\end{algorithm}
>	```
>4. Stringhe palindrome
>	```pseudo
>	\begin{algorithm}
>	\begin{algorithmic}
>	\State $S \to 0S0|1S1|1|0|\epsilon$
>	\end{algorithmic}
>	\end{algorithm}
>	```
>5. Nessuna stringa
>	```pseudo
>	\begin{algorithm}
>	\begin{algorithmic}
>	\State $S \to S$
>	\end{algorithmic}
>	\end{algorithm}
>	```

Verifichiamo la **correttezza** del linguaggio : 

```pseudo
	\begin{algorithm}
	\begin{algorithmic}
	\State $A \to 0A1 | B$
	\State $B \to \#$
	\end{algorithmic}
	\end{algorithm}
```
$$L(G)=\{0^n \#1^n\ |\ n\ge 0 \}$$
**Dimostriamo** che $w\in L(G)$ se e solo se $w = 0^n\# 1^n$ per qualche $n\ge 0$ :
1. $\implies$

Sia $w\in L(G)$ allora $A \implies^*\ w$ , per dimostrare questo facciamo *Induzione* sulla lunghezza della [[Derivazione]] , dividiamo i due casi ( derivanti dalla scelta che possiamo fare dallo [[Start Symbol]] ) :
1. $A \implies 0A1 \implies^* \ w$ : allora 