**Entropy** can be a bad measure of *compressibility*

The best measure of *compressibility* is **Kolmogorov** complexity $\kappa(S)$ , where $S$ is a string , is the lenght of the *shortest program generating* $S$ 

>[!danger] 
>$\kappa(S)$ is **not computable** so no *compressor* can be optimal

>[!important] 
>[[Worst-case Entropy]] applies to the *worst-case* in the set not *individually* on every object in the set
>

So considering the following set : $X_n$ containing $n/2$ characters equal to "a" and $n/2$ equal to "b". Then *worst-case entropy* is : 
$$
\mathscr{H}_{wc}(X_n) = \log \binom{n}{n/2} \approx n
$$
So on average we need $n$ bits to compress a string of $X_n$ but some string are more compressible than other , for example $aaaaaabbbbbb \in X_{12}$ 

# Entropy Failure

$H_k$ can't capture repetitions longher than $k$ 

>[!example] 
>$S= 0101010101010101$ , $n=16$, than $H_0(S)=16$ , so $H_0$ does not compress the string
>>[!info]- Full computation
>>$$
>>nH_0(S) =16 \cdot\bigg( 2\cdot \bigg(\frac{8}{16} \log_2 \bigg(\frac{16}{8}\bigg)\bigg)\bigg) = 16 \cdot 1 = 16
>>$$
>
>Also $H_1$ will be fooled in fact $H_1(0110 0110 0110 0110)=16$
>
>>[!info]- Full computation
>>So with $S=0110 0110 0110 0110$ and $k=1$ we get : 
>>+ $S_1=01010101$
>>+ $S_0=1010101$
>>
>>Now : 
>>$$
>>H_1(S) = \frac{|S_0|}{n} H_0(S_0) + \frac{|S_1|}{n} H_1(S_1) 
>>$$ 
>>Calculating $H_0(S_0) = \frac{4}{7} \log_2\big(\frac{7}{4}\big)+ \frac{3}{7} \log_2\big(\frac{7}{3}\big)$ and $H_1(S_1) = \frac{4}{8} \log_2\big(\frac{8}{4}\big)+ \frac{4}{8} \log_2\big(\frac{8}{4}\big)$
>>
>>#todo



