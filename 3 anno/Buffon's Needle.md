Tring to approximate $\pi$ , by droppin $N$ *needles* of unit ( $1$ ) length in a fllor that is subdivided in boards of witch theys width is $2$ units

Some of the needle will fall between boards 
>[!important] Leclerc Theorem
>If we drop 1 needle of length $l$ on the floor and the boards are ata a distance $d$ the probability thatit will cross the board is $2 \cdot l / \pi \cdot d$ 

>[!example] 
>In our case $l=1$ and $d=2$ so $2 \cdot l / \pi \cdot d = 2 \cdot l / 2 \cdot \pi = 1 / \pi$

Then if we drop $n$ needles the number of needle that will cross the board is $k=n/\pi$ 

>[!important] Buffon Algorithm 
>With a high enugh number $n$  than we can estimate $\pi \approx n / k$ 
>

Now the probability that one will fall crossing two boards will be $p$ ( bernuollian varaible =1 ) and the opposite otherwise 

For the *Leclerc* *theorem* $p$ will be $1/\pi$ and so the vairance will be $1/\pi (1-1/\pi)$