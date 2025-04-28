---
publish: true
---
>[!note] 
>Since all the clocks are perfectly synched we can use time to comunicate between entities

# 2-bit Communication

>[!important] 
>We can transmit any information with $2$ *bits* given syncronized clocks

We simply send at time $t$ one bit to the reciever , than wait the units of time relative to the value to be send and send a different at time $t+x$ to the reciever 

The reciever will recieve the first bit at time $t' = t+1$ 
>[!note] 
>The transmission of the message always takes $1$ unit of time 

And the second bit at time $t'' = t+x+1$ , the final number recieved will be : 
$$t''-t' = x$$
>[!note] 
>In this protocol the first bit indicates to the reciever to start counting the time , and the second to stop counting

>[!example]
>#todo
>

## Speed improvments 

To improve the time that it takes to send a message we thus need to lower the time that it takes to "count" ( the time between the first and second bit ) the number

### time = $\lfloor x/2 \rfloor$ , bits = 2

We can associate a meaning to the first and second bit 

The *sender* :
+ Send a bit $b_0$ to the reciever to start counting
+ Wait $\lfloor x/2 \rfloor$ units of time 
+ Send a bit $b_1$ where :
$$
\begin{equation}
    \begin{cases}
      0 \text{ if $x$ is even} \\
      1 \text{ if $x$ is odd}
    \end{cases}\
\end{equation}
$$
The *reciever* :
+ Recieves $b_0$ and starts counting
+ Recieves $b_1$ stops counting and decodes the value with the following equation : $$x = 2 (t'' - t')+b_1$$
>[!example] 
>$x = 7$ 
>*sender* :
>1. sends $b_0$
>2. waits $3$
>3. sends $b_1 = 1$ 
>
>*reciever* :
>
>
>1. recieves $b_0$ at time $t'$
>2. recieves $b_1=1$ at time $t'' = t'+3$
>3. $x=2\cdot 3 +1 = 7$

### time = $\lfloor x/4 \rfloor$ , bits = 2

The *sender* : 
+ Send bit $b_1$ at time $t$ where :
$$
\begin{equation}
    \begin{cases}
      0 \text{ if $x$ is even} \\
      1 \text{ if $x$ is odd}
    \end{cases}\
\end{equation}
$$
+ Wait $\lfloor x/4 \rfloor$ units of time 
+ Send bit $b_2$ where :
$$
\begin{equation}
    \begin{cases}
      0 \text{ if $\lfloor x/2 \rfloor$ is even} \\
      1 \text{ if $\lfloor x/2 \rfloor$ is odd}
    \end{cases}\
\end{equation}
$$

>[!example] 