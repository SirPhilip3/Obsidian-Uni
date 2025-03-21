```pseudo
	\begin{algorithm}
	\caption{RandomizedQuicksort}
	\begin{algorithmic}
	\Input S
	\If{$|S| = 0$} 
		\Return
    \EndIf
    \State Choose a splitter $a_i \in S$ uniformly at random
    \ForAll{$a\in S$}
	    \If{$a < a_i$} 
	    \State put a in $S^-$
	    \Else
	    \If{$a > a_i$} 
	    \State put a in $S^+$
        \EndIf
        \EndIf
    \EndFor
    \State\Call{RandomizedQuicksort}{$S^-$}
    \Output $a_i$
    \State\Call{RandomizedQuicksort}{$S^+$}
	\end{algorithmic}
	\end{algorithm}
```

>[!note] 
>This is a **Las Vegas** algorithm, for the decisional version see : [[Strutture Dati#Quick Sort|Quick Sort]]

## Running Time

![[Strutture Dati#Quick Sort#Complessità]]

