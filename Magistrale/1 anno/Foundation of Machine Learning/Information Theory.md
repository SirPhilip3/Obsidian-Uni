Infromation theory was "invented" by Claude Shannon 

It's a *math theory* that models *communication problems* 
## Model

![[Pasted image 20251017155730.png]]

Where : 
+ **Source** : creator of information in a given alphabet
+ **Transmitter** ( *encoder* ) : translates the information produced by the *source* in an alphabet that the *channel* can understand
+ **Channel** : The mean with which the message is transported 
+ **Noise** : Some random perturbation that the channel is subject to
+ **Reciever** ( *encoder* ) : translates the information coming from the *channel* in an alphabet that the *destination* can understand
+ **Destination** : final destination of the message

>[!note] 
>The *source* and *destination* of the information can be the same ( like for storing things in memory ) or there could be multiple *destinations* ( in a dsitributed setting ) etcc 

>[!important] 
>The model only treats with the *symbolic* ( the way symbols combine ) level of "information"
>

### Measuring Information

>[!important] 
>Given an event $E$ , $I(E)$ rapresents the amount of information provided by $E$ when it actually occurs 

The foundamental fact of *information theory* is that $I(E)$ is a function of the probability of  $E$
$$
I(E) = f(P(E))
$$
Or the more uncertain an event is the more information it produces 