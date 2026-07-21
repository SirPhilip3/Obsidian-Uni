---
publish: true
---
# Streaming Algorithm 

>[!important] Streaming Model of Computation
>
>We have as input a *stream* $x_{1},\dots,x_{m}$ of $m$ *integers* , receiving them one by one 
>
>Once received $x_{i}$  we use it to *update* some *data sketch* and then *discard* $x_{i}$
>
>After seeing any stream *prefix* $x_{1},\dots,x_{i}$ we *must* be able to return the *answer* to the particular *statistic* that we are computing on the stream 

Streaming algorithms have the following features :
+ Maximum *working **space***
+ ***Delay*** per element :
	How much time the algorithm spends when receiving a new stream element $x_{i}$
+ ***Probability*** of obtaining a *correct* solution 
+ **Approximation ration** if the solution is approximated

# Pattern matching on streams

>[!important] Problem statement
>We recieve a stream containing $n+m$ characters ( $n \le m$ ) :
>$$
>y_{1},\dots,y_{n} , x_{1},\dots , x_{m}
>$$
>
>Where :
>+ $y=y_{1},\dots,y_{n}$ is a **pattern** of lenght $n$
>+ $x=x_{1},\dots,x_{m}$ is the **text** of length $m \ge n$
>
>After processing $y$, every time we receive a new text character $x_{i}$ we must be able to determine if $y=x_{i-n+1},\dots,x_{i}$ ( for $i \ge n$ )
>
>Or if the *pattern* $y$ is a *suffix* of the current text *prefix* $x_{1},\dots,x_{i}$

This problem is *easy* to solve the problem in $O(n)$ words of space by maintaining a *window* of the last $n$ text characters 
## $O(n)$ working space

Using [[Hashing#Polynomial Hashing ( Rabin hashing )|Polynomial Hashing ( Rabin hashing )]] we can squeeze the *pattern* into $1$ memory word

But this can't be used to solve the problem in $O(1)$ space for the following problem :

>[!example] 
>Suppose we have the hashes of the *pattern* $y$ and the last $n$ text characters 
>
>$$
>\begin{align}
>\text{text prefix } x_{1},\dots,x_{i} = & \text{ abbaabba}\textcolor{red}{bbab} & \kappa_{q,z}(x_{i-n+1},\dots,x_{i}) \\
>\text{pattern } y = &\ \textcolor{blue}{baba} & \kappa_{q,z}(y)
>\end{align}
>$$
>
>Keeping these two hashes takes $O(1)$ *space* , also checking if the pattern is a *suffix* of the current text prefix takes $O(1)$ *time*
>
>>[!warning] 
>>The problem is **updating** the text *prefix* *hash* when a new character arrives 
>>
>>The new *hash* is :
>>$$
>>\kappa_{q,z}(x_{i-n+2},\dots,x_{i+1}) = \kappa_{q,z}(x_{i-n+1},\dots,x_{i}) \cdot z - b \cdot z^n + a \mod{q}
>>$$
>>
>>Where $a$ is the new arriving character and $b$ the character exiting the window
>>
>>Since we need to access the $n$-th last stream character we need to *explicitly* *store* the last $n$ characters , so we are still in $O(n)$ *space*
>>

# Porat & Porat's algorithm 

*Instead* of storing the last $n$ characters of the stream, we can keep a *combination* of $O(\log n)$ *hashes* in order to retrieve tha last $n$ characters when needed

This will give us :
+ $O(\log n)$ *space*
+ $O(\log n)$ *update* time
+ *Correctness* with *high* *probability*

---

## Data Structures

Consider the following pattern of lenght $n=16$ 

We compute the *hashes* of its $\log n +1$ *prefixes* of length $2^j$

![[P&P_init.excalidraw.png]]
%%[[P&P_init.excalidraw.md|🖋 Edit in Excalidraw]]%%

Then the *text* arrives 

We also keep $\log n$ *sets* : $W_{0}, \dots , W_{\log n -1}$

Each set $W_{i}$ stores the occurences of the *pattern* *prefix* *of lenght* $2^i$ in the last $2^{i+1}$ text's characters 

![[P&P_state.excalidraw.png]]
%%[[P&P_state.excalidraw.md|🖋 Edit in Excalidraw]]%%

>[!note] 
>$W_{0}$ has the starting postions for the pattern identifying $b$, $W_{1}$ has the starting postions for the pattern identifying $ba$ and so on

>[!warning] 
>Each $W_{i}$ could contain up to $2^i+1$ *integers* , this can be shown to be stored in $O(1)$ space since they are periodic 

Also the set $W_{\log n} = W_{4}$ will tell us if the *full pattern* occurs as a *suffix*

## Updates

How do we update the *data structure* when the next text character $x_{i+1}$ arrives 

>[!note] 
>The updates should be done without accessing previous text characters

Suppose next character arrives ( $x_{i+1}=x_{17}=b$ )

1. Right-shift all the windows of the sets $W_{i}$ 
2. Set $W_{i}$ behave in the following ways :
	1. The *occurrences* stay inside the windows. Then we *won't delete* anything from the $W_{i}$
	2. If the new text character is an occurrence of $y_{1}$ : insert $17$ in $W_0$
	3. Check if first-cell occurences can be *promoted* to the next level ( in this case no )

![[P&P_update1.excalidraw.png]]
%%[[P&P_update1.excalidraw.md|🖋 Edit in Excalidraw]]%%

New character arrives ( $x_{18}=a$ )

1. Right-shift all the windows of the sets $W_{i}$ 
2. Set $W_{i}$ behave in the following ways :
	1. Two *occurrences* **exit** the windows. **Delete** them from their relative sets $W_{i}$
	2. Since $a$ is not an occurence of $y_{1}$ we do not insert it into $W_{0}$
	3. Check if first-cell occurences can be *promoted* to the next level 
		1. $17$ is also an *occurrence* of $ba$ so it is promoted into $W_{1}$
		2. $11$ is *not* an occurrence of $baabbaab$ ( $y_{4}$ ) so is *not* promoted
		3. $3$ is an *occurrence* of the **full pattern** 

![[P&P_pass2.excalidraw.png]]
%%[[P&P_pass2.excalidraw.md|🖋 Edit in Excalidraw]]%%

```pseudo
	\begin{algorithm}
	\caption{new_stream_character($x_j$)}
	\begin{algorithmic}
	\If{ $x_j == y_1$ }
		\State $W_0 \leftarrow W_0 \cup \{j\}$ 
    \EndIf
    \ForAll{level $i=0,\dots, e-1$}
	    \State $W_i \leftarrow W_i - \{j-2^{i+1}\}$
	    \Comment{delete occurrences exiting the window}
	    \If{$j-2^{i+1}+1 \in W_i$}
		    \If{$\kappa_{q,z}(y[1,2^{i+1}]) == \kappa_{q,z}(x[j-2^{i+1}+1,j])$}
			    \If{$i== e-1$}
					\Return $j-2^e+1$
					\Comment{pattern occurrence found}
	            \Else
		            \State $W_{i+1}\leftarrow W_{i+1} \cup \{j-2^{i+1}+1\}$
		            \Comment{promote position to next level}
	            \EndIf
            \EndIf
        \EndIf
    \EndFor
	\end{algorithmic}
	\end{algorithm}
```
### Rapresenting $W_{i}$ in constant space

Each $W_{i}$ contains *occurrences* of a string $A$ of lenght $2^i$ inside another string $B$ of length $2^{i+1}$ 

If there are $\ge 3$ occurrences of $A$ inside $B$ then $B$ must be *periodic* and so the numbers inside $W_{i}$ are *regularly-spaced*

>[!example] 
>$i=2$, hence $|A|=2^2=4$ and $|B|=2^{2+1}=8$
>
>![[P&P_Wregul.excalidraw.png]]
%%[[P&P_Wregul.excalidraw.md|🖋 Edit in Excalidraw]]%%

>[!important] 
>There is no way you can have occurences that are not regularly spaced

Then we can rapresent the following in *constant space* :
$$
W_{i}=\{r_{1},r_{2},\dots,r_{t}\} = \{r_{1},r_{1}+p,r_{1}+2p,\dots\}
$$
by storing only $(r_{1},t,p)$ 

Now we can also **update** this in *constant time* 

>[!example] 
>Let $(r_{1},t,p)$ be the representation of $\{r_{1},r_{2},\dots,r_{t}\}$. 
>
>The representation of $\{r_{2},\dots,r_{t}\}$ is :
>$$
>(r_{1}+p,t-1,p)
>$$
>
>The representation of $\{r_{2},\dots,r_{t},r_{t+1}\}$ is :
>$$
>(r_{i},t+1,p)
>$$

So in total the sets $W_{i}$ use $O(\log n)$ words of *space* and support updates in *constant time*
### Compute the hash of the text window

In order to do the **promotion** we need the *hash* of the corresponding text window in order to compare it to the *pattern*

We maintain the following $O(\log n)$ text hashes :
1. The *hash* of the *whole stream* , this is easy to update when new characters arrive
2. For each $|W_{i}| \ge 2$, the *hash* of the text between *first occurence* ( included ) and *second occurence* ( excluded )
3. For each $|W_{i}| > 0$, the *hash* from the *beginning* of the *stream* *to* the *first occurence* ( excluded )

>[!example]
>![[hashes_P&P.excalidraw.png]]
%%[[hashes_P&P.excalidraw.md|🖋 Edit in Excalidraw]]%%

>[!note] 
>The $2$ hashes are needed only to update the $3$ hashes when the leftmost occurrence disappears

>[!important] 
>We need the *hash* of the text window only when there is an occurrence in the *leftmost position* of the window

Then given :
+ $A=\kappa(x_{1},\dots,x_{18})$ : *hash* of the full *stream*
+ $C=\kappa(x_{1},\dots,x_{10})$ : *hash* of the remainder *from* the *start* of the stream *to* *leftmost occurrence* 

We get the hash of the current window as :
$$
\kappa(x_{11},\dots,x_{18}) = \kappa(x_{1},\dots,x_{18}) - \kappa(x_{1},\dots,x_{10}) \cdot z^8 \mod{q}
$$
>[!example]
>![[P&P_finalcal.excalidraw.png]]
%%[[P&P_finalcal.excalidraw.md|🖋 Edit in Excalidraw]]%% 

All the hashes can be updates in $O(\log n)$ and allow us to compute the hash of the text window when needed in $O(1)$
# Conclusion

#todo 