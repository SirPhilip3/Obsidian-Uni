>[!example] 
>Consider a string of lenght $n$ over alphabet $\{A,C,G,T\}$ that cotains exactly one occurrence of $A, C, G$ with the remaining $n-3$ letters being equal to $T$
>
>1. The way that we can order $A,C,G$ is $3!$ 
>2. In the string of lenght $n$ we need to choose $3$ places to put them so $\binom{n}{3}$
>
>Since all the other letters are $T$ ther's only $1$ for them to be positioned , so in total we have $3! \binom{n}{3}$ combinations   
>
>A *compression scheme* to store this string in $O(\log n)$ bits is simply storing the position of $A,C,G$
>
>>[!note] 
>>This observes the **Information Theoretical Lower bound** of 
>>$$
>>\log \binom{n}{3} 3! = \log \frac{n!}{3!(n-3)!} 3! = \log \frac{n(n-1)(n-2)(n-3)!}{(n-3)!} =
>>$$
>>$$
>> = \log n(n-1)(n-3) = \log n + \log (n-1) + \log (n-2) \approx 3 \log n \approx O(\log n) 
>>$$

**Information Theoretical Lower bound** has a fromal rule : 

>[!important] Definition
>Let $\mathscr{U}$ be the *universe* of objects that we encode. The *worst-case entropy* of $\mathscr{U}$ is : 
>$$
>\mathscr{H}_{wc}(\mathscr{U}) = \lceil \log_2(|\mathscr{U}|) \rceil
>$$

So any *decodable* encoding of objects from $\mathscr{U}$ must use at least $\mathscr{H}_{wc}(\mathscr{U})$ *bits* for its **longhest** code ( otherwise we encounter collisions )

In the real word we can expect to use also a small *negligible* amount of extra space : 
$$\mathscr{H}_{wc}(\mathscr{U}) \cdot (1 +o(1))$$ 
>[!example] 
>#todo

