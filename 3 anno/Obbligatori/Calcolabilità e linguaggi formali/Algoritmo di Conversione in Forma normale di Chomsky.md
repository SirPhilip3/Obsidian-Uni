---
creation: 2024-10-17T14:13:00
tags:
  - Algoritmo
---
1. Generiamo un nuovo [[Start Symbol]] $S'$ e aggiungiamo la produzione $S' \to S$ 
>[!note] 
>Questo passaggio ci assicura che lo [[Start Symbol]] non occorra a destra di una [[Produzioni|Produzione]] 

2. Elimino le [[Produzioni]] nella forma $A \to \epsilon$ dove $A \neq$ [[Start Symbol]] 
	Per tutte le regole nella forma $R \to uAv$ introduco una nuova regola $R \to uv$ per tutte le occorrenze di $A$ 
>[!example] 
>Per $R \to uAvAw$ introduco 3 nuove regole che rappresentano tutte le possibilità di combinazione della stringa espansa da $S$ avendo rimosso $A\to \epsilon$  : 
>$R \to uvAw$
>$R \to uAvw$
>$R \to uvw$
>>[!note] 
>>Possiamo anche riscriverle in questo modo : $R \to uvAw | uAvw | uvm$

3. Elimino tutte le [[Produzioni]] nella forma $A \to B$ ( *unitarie* ) 
	Per ogni *regola* $B \to u$ aggiungeremo una nuova [[Produzioni|Produzione]] $A \to u$ in modo da esplicitare la [[Produzioni|Produzione]] $A \to B \to u$

4. Rimpiazziamo ogni *regola* nella forma : $A \to u_1,u_2,\dots,u_k$ con $k\ge3$ , con nuove regole nella forma : 
	$A \to u_1A_1$ , $A_1 \to u_2A_2$ , $\dots$ , $A_{k-2} \to u_{k-1}u_k$ 
>[!note] 
>Rimpiazziamo ogni [[Simboli Terminali]] $u_i$ con un nuovo [[Simboli Non Terminali]] , ed aggiungendo la regola $U_i \to u_i$ 

>[!important] 
>Le trasformazioni sono in un ordine specifico poichè altrimenti potrei introdurre delle [[Produzioni]] che romperebbero dei risultiti ricavati da trasformazioni precedenti

>[!example] 
>Il [[Context-Free Grammar|CFG]] iniziale è il seguente : 
>```pseudo
>\begin{algorithm}
>\begin{algorithmic}
>\State $S \to ASA|aB$ 
>\State $A \to B |S$
>\State $B \to b | \epsilon$
>\end{algorithmic}
>\end{algorithm}
>```
>
>1. Aggiungiamo $S'$
>```pseudo
>\begin{algorithm}
>\begin{algorithmic}
>\State $S \to ASA|aB$ 
>\State $A \to B |S$
>\State $B \to b | \epsilon$
>\State $\color{green}S' \to S$
>\end{algorithmic}
>\end{algorithm}
>```
>
>2. Eliminiamo le regole $B \to \epsilon$ 
>
>>[!note] 
>>$A$ può generare $\epsilon$ attraverso $A \to B$ quindi dovremo aggiungere la *transizione* $A \to \epsilon$ , inoltre in $S \to aB$ sostituendo $\epsilon$ a $B$ dovremo aggiungere la transizione $S \to a$
>
>```pseudo
>\begin{algorithm}
>\begin{algorithmic}
>\State $S \to ASA|aB|a$ 
>\State $A \to B | S | \color{green}\epsilon$
>\State $B \to b$
>\State $S' \to S$
>\end{algorithmic}
>\end{algorithm}
>```
>
>>[!note] 
>>Ora che abbiamo aggiunto $A \to \epsilon$ notiamo che dovremo anche sostituire con tutte le possiblì sostituzioni $S \to ASA$ che saranno $S \to SA|AS|S$
>
>```pseudo
>\begin{algorithm}
>\begin{algorithmic}
>\State $S \to ASA|aB|a|\color{green}SA|AS|S$ 
>\State $A \to B | S | \color{red}\epsilon$
>\State $B \to b$
>\State $S' \to S$
>\end{algorithmic}
>\end{algorithm}
>```
>
>3. Eliminiamo le *regole* *unitarie* 
>
>>[!note] 
>>Come *transizioni unitarie* avremo : $A \to B$ , $S'\to S$ e $A \to S$
>>Per $S' \to S$ avremo che possiamo sostituirla con tutte le [[Produzioni]] con $S$ sul lato *sinistro* ( ossia con le sue possibili espansioni ) :
>
>```pseudo
>\begin{algorithm}
>\begin{algorithmic}
>\State $S \to ASA|aB|a|SA|AS$ 
>\State $A \to B | S$
>\State $B \to b$
>\State $S' \to \color{green}ASA|aB|a|SA|AS$
>\end{algorithmic}
>\end{algorithm}
>```
>
>>[!note] 
>>Possiamo togliere $S' \to S$ e $S \to S$ poichè si sostiuscono con regole già presenti
>>
>>Eliminiamo ora $A \to B$ ( sostituendo con $b$ ) e $A \to S$ ( sistuendo con le regole di $S$ )
>
>```pseudo
>\begin{algorithm}
>\begin{algorithmic}
>\State $S \to ASA|aB|a|SA|AS$ 
>\State $A \to b | \color{red}S | \color{green} ASA | aB | a |SA|AS$
>\State $B \to b$
>\State $S' \to \color{green}ASA|aB|a|SA|AS$
>\end{algorithmic}
>\end{algorithm}
>```
>
>4. Trasformiamo le regole con più di 2 [[Simboli Non Terminali]] sulla destra in regole con solo 2 [[Simboli Non Terminali]]
>
>>[!note] 
>>Dovermo trasformare quindi $S' \to ASA$ , $A \to ASA$ e $S \to ASA$ aggiungendo una regola $A_1 \to SA$ 
>
>```pseudo
>\begin{algorithm}
>\begin{algorithmic}
>\State $S \to AA_1|aB|a|SA|AS$ 
>\State $A \to b | AA_1 | aB | a |SA|AS$
>\State $B \to b$
>\State $S' \to AA_1|aB|a|SA|AS$
>\State $\color{green} A_1 \to SA$
>\end{algorithmic}
>\end{algorithm}
>```
>
>>[!note] 
>>Ora dovremmo sostituire tutte le regole che hanno sulla destra sia [[Simboli Terminali]] che [[Simboli Non Terminali]] , ossia trasformiamo $S' \to aB$ , $S \to aB$ e $A \to aB$ aggiungendo una nuova regola $U \to a$
>
>```pseudo
>\begin{algorithm}
>\begin{algorithmic}
>\State $S \to AA_1|\textcolor{green}{U}B|a|SA|AS$ 
>\State $A \to b | AA_1 | \textcolor{green}{U}B | a |SA|AS$
>\State $B \to b$
>\State $S' \to AA_1|\textcolor{green}{U}B|a|SA|AS$
>\State $A_1 \to SA$
>\State $\color{green} U \to a$
>\end{algorithmic}
>\end{algorithm}
>```

