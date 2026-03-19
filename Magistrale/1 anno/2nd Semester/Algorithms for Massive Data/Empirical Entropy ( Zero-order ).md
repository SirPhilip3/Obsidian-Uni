>[!important] Definition
>Let $S \in \Sigma^n$ be a *string*. The **zero-order empirical entropy** of $S$ is : 
>$$
>H_0(S) = \sum_{c \in \Sigma} \frac{n_c}{n} \log_2 \bigg( \frac{n}{n_c} \bigg)
>$$
>
>Where $n_c = |\{i\ :\ S[i] = c \}|$ is the number of occurences of character $c$ in $S$

>[!example] 
>$H_0(aaaabbcd)$ , $n_a =4$ , $n_b=2$ , $n_c=n_d=1$ , $n=8$
>
>Than : 
>$$
>\frac{4}{8} \cdot \log_2 \bigg( \frac{8}{4} \bigg) + \frac{2}{8} \cdot \log_2 \bigg( \frac{8}{2} \bigg) + \frac{1}{8} \cdot \log_2 \bigg( \frac{8}{1} \bigg) +\frac{1}{8} \cdot \log_2 \bigg( \frac{8}{1} \bigg) \approx 1.75 
>$$

---

Consider the set $\mathscr{S}(n_1, \dots, n_{\sigma}) \subseteq [\sigma]^n$ , strings of lenght $n$ over the alphabet $[\sigma]$ such that each $s \in \mathscr{S}$ contains $n_c$ occurences of each character $c \in [\sigma]$

>[!example] 
>$12122132 \in \mathscr{S}(3,4,1)$ , or it contains $3$ $1$'s , $4$ $2$'s and $1$ $3$

**Worst-case entropy** : 

The first character can be positioned in $n_1$ positions inside the full string of lenght $n$ so : $$
\binom{n}{n_1}
$$
For the second character this will be positioned in $n_2$ in the remaining $n-n_1$ positions , so on for all the character in the set
$$
\binom{n}{n_1} \cdot \binom{n - n_1}{n_2} \cdot \binom{n-n_1-n_2}{n_3} \cdot \dots = \frac{n!}{n_1!\cancel{(n-n_1)!}} \cdot \frac{\cancel{(n-n_1)!}}{n_2!\cancel{(n-n_1-n_2)!}} \cdot \frac{\cancel{(n-n_1-n_2)!}}{n_3!\cancel{(n-n_1-n_2-n_3)!}} \cdots
$$
At the end we will have the following : 
$$
\cdots = \frac{n!}{n_1!n_2! \dots n_{\sigma}!} = \binom{n}{n_1, \dots,n_\sigma}
$$
or the *multinomial coefficent*

So :
$$
\mathscr{H}_{wc}(\mathscr{S}(n_1, \dots, n_{\sigma})) = \log \binom{n}{n_1, \dots,n_\sigma}
$$
Applying *Stirling* approximation to the factorial we can prove that : 
^328557
$$
\mathscr{H}_{wc}(\mathscr{S}(n_1, \dots, n_{\sigma})) = n H_0 -O(\sigma \log n)
$$
#todo explain

**Encoding** : 

>[!info] Idea
>Frequent characters are encoded in few bits , rare with many bits
>
>With no code as a *perfix* of another code ( [[Information Theory#Huffman Coding|Huffman encoding]] )

>[!example] 
>Given $S = abracadabra$, $n=11$, $\sigma = 5$ , so if we pack every char with *worst case entropy* we would need $n \lceil \log \sigma \rceil = 33$ bits
>
>Let's prove that $n H_0 = 22.444\dots$ bits
>>[!note]- Calculation
>>$$
>>11 \cdot \bigg\{ \frac{5}{11}\log \frac{11}{5}+ 2\bigg( \frac{2}{11}\log \frac{11}{2} \bigg) + 2\bigg(\frac{1}{11}\log \frac{11}{1}\bigg) \bigg\} = 11 \cdot 2.040\dots = 22.444\dots
>>$$
>
>Using **prefix-free** encoding we can have : $c \to 000, d \to 001, b \to 010, r \to 011, a \to 1$  , than the string takes $23$ bits

