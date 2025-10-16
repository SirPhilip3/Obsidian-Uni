*Block ciphers* are cryptosystems that "reuse" the same key to encrypt letters or blocks of the *plaintext*

$$
\begin{matrix} x_1 & x_2& \ldots ~~~~~~& x_n\\\downarrow& \downarrow&&\downarrow\\k\rightarrow\fbox{E}~~~~~~&k\rightarrow\fbox{E}~~~~~~~~&\ldots~~~~~~&k\rightarrow\fbox{E}~~~~~~~~\\\downarrow&\downarrow& &\downarrow\\y_1 & y_2 & \ldots ~~~~~~& y_n\end{matrix}
$$

## Stream ciphers

A more advanced form of *block ciphers* are *stream ciphers* where instead of using a single key $k$ we will use a precomputed stream of keys $z_1,z_2, \dots, z_n$

$$
\begin{matrix} x_1 & x_2& \ldots ~~~~~~& x_n\\\downarrow& \downarrow&&\downarrow\\z_1\rightarrow\fbox{E}~~~~~~~~&z_2\rightarrow\fbox{E}~~~~~~~~~~&\ldots~~~~~~&z_n\rightarrow\fbox{E}~~~~~~~~~~\\\downarrow&\downarrow& &\downarrow\\y_1 & y_2 & \ldots ~~~~~~& y_n\end{matrix}
$$

>[!warning] 
>Having a different *key* for each of the *blocks* in the *plaintext* is not *pratical*

So in general instead of a stream of *keys* we will derive it from a given intial $k$ based on the previous parts of the *plaintext* : 
$$
z_i = f_i(k, x_1, \dots , x_{i-1})
$$
