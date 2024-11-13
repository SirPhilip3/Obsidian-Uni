---
creation: 2024-10-02T10:24:00
tags:
  - Definizione
publish: true
---
Sia $R$ una [[03 Espressioni Regolari|regexp]] definiamo il suo linguaggio $L(R)$ come : 
1. Se $R=a$ ( singolo carattere ) allora $L(R)=\{a\}$
2. Se $R=\epsilon$ allora $L(R) = \{\epsilon\}$
3. Se $R = \emptyset$ allora $L(R)=\emptyset$
4. Se $R = R_1 \cup R_2$ allora $L(R)=L(R_1)\cup L(R_2)$
5. Se $R=R_1\ o\ R_2$ allora $L(R) = L(R_1)\ o\ L(R_2)$ 
6. Se $R = R_1^*$ allora $L(R)=[L(R_1)]^*$

>[!example]
>
>Troviamo il linguaggio $(0 \cup 1)\ o\ 0^*$  : 
>$$L[(0 \cup 1)\ o\ 0^*] = L(0 \cup 1)\ o\ L(0^*)$$
>$$[L(0)\cup L(1)]\ o\ [L(0)]^*$$
>$$[\{0\}\cup\{1\}]\ o\ [L(0)]^*$$
>$$\{0,1\}\ o\ \{0\}^* = \{ xw | x \in \{0,1\} , w \in \{0\}^* \}$$

>[!example] 
>Esempi di linguaggi ( con $\Sigma = \{0,1\}$ ) : 
>
>+ $L(0^*\ 1\ 0^*)$ : stringhe binarie con un solo $1$
>+ $L(\Sigma^*\ 1 \ \Sigma^*)$ : stringhe binarie con almeno un $1$
>+ $L((\Sigma \Sigma)^*) = L([\{0,1\}\ o \ \{0,1\}]^*) = \{01,10,11,00\}^*$ : stringhe binarie di lunghezza pari ( anche la stringa vuota $\epsilon$ ) 
>+ $L[(0\cup \epsilon)\ o \ (1\cup \epsilon)] = \{0,1,01,\epsilon\}$
>+ $L(1^*\ o \ \emptyset) = L(1^*)\ o \ L(\emptyset) = \emptyset$ : non rappresenta nessuna stringa poichè la concatenzione ( [[A o B]] ) necessita che vi sia almeno una stringa nell'insieme $B$ , e questo essendo $\emptyset$ nel nostro caso non ha stringhe tra cui sciegliere , non potendo formare una stringa concatenata il risultato sarà $\emptyset$
>+ $L(\emptyset^*) = [L(\emptyset)]^* = \emptyset^* = \{\epsilon\}$ : se ho 0 stringhe la loro concatenzione ritornerà sempre la stringa vuota ( $\epsilon$ )
>+ $L(R)\ o \ \epsilon = L(R)$

![[Linguaggio Regolare Regexp]]