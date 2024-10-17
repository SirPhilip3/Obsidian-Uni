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
>6. Parentesi bilanciate ( sequqenza arbitrariamente lunga di blocchi $a^nb^n$ ) : 
>	```pseudo
>	\begin{algorithm}
>	\begin{algorithmic}
>	\State $S \to aSb|SS|\epsilon$ 
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
1. $A \implies 0A1 \implies^* \ w$ : allora $w=0v1$ con $A\implies^* v$ 
	Per *ipotesi induttiva* ( poichè $A\implies^* v$ è più piccolo di $A\implies^* w$ ( facciamo meno passi di [[Derivazione]] ) ) $v=0^m\#1^m$ con $m\ge 0$ , ma allora $w=00^m\#1^m1$ che sarà nel formato corretto
2. $A \implies B \implies^* w$ : in questo caso siamo nel formato corretto poichè avremo che $w=\#$ in ogni caso

2. $\Longleftarrow$

Sia $w = 0^n\#1^n$ con $n\ge 0$ dimostro che $w\in L(G)$ , utilizziamo l'*induzione* su $n$ 
1. Se $n=0$ : $w=\#$ e quindi $A\implies B\implies \#$ 
2. Se $n\ge 0$ : $w =0^{m+1}\#1^{m+1}$ con $m\ge 0$ , per l'*ipotesi induttiva* possiamo scrivere $A \implies^* \ 0^m\#1^m$ ma allora possiamo anche scrivere : $A \implies 0A1 \implies^*\ 00^m\#1^m1$ che risulta corrispondere a $w$

![[CFG ambigua]]

![[Forma normale di Chomsky]]

