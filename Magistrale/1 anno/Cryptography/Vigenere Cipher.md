This *cipher* works on *blocks* of $m$ letters with a key of lenght $m$ 

The *plaintext* is split into blocks of lenght $m$ and the *key* is repeated in order to perform the sum to *encrypt* the original *plaintext*

>[!example] 
>*key* = `FLUTE` , $m=5$
>```
>THISISAVERYSECRETMESSAGE +
>FLUTEFLUTEFLUTEFLUTEFLUT =
>YSCLMXLPXVDDYVVJEGXWXLAX
>```

*Formally* :

$E_{k_1, \dots, k_m}(x_1,\dots, x_m) = (x_1 + k_1, \dots, x_m + k_m) \mod{26}$
$D_{k_1, \dots, k_m}(y_1,\dots, y_m) = (y_1 - k_1, \dots, y_m - k_m) \mod{26}$

$P=C=K=Z^m_{26}$ 

Where $Z_{26}^m$ is a given string $Z_{26}$ repeated $m$ times  

>[!important] 
>The number of possible *keys* becomes $26^m$ ( all the sequences of letters of lenght $m$ ) 
>>[!note] 
>>This prevents *brute force* attacks *only* for $m$ sufficently big
>>

With this type of *encryption* one *plaintext* letter will *not always* be mapped to the same *unless* they are at a distance that is multiple of $m$ 

>[!example] 
>![[vigene.excalidraw.png]]
>%%[[vigene.excalidraw.md|🖋 Edit in Excalidraw]]%%

>[!cite] 
>Animation : https://www.youtube.com/watch?v=RtiXSmQAB2I
## Attacks

>[!important] 
>The frequencies of the *encrypted* text becomes flatter so in this case *frequency* analysis used in [[Substitution Cipher]] does not work 

This cipher still maintains most of the structure of the *plaintext*  

There are two methods to break the cipher : 
+ [Friedrich Kasiski method](https://en.wikipedia.org/wiki/Kasiski_examination)
+ *Wolfe Friedman* method 
### Wolfe Friedman mathod

The method is composed of *two phases* : 
1. Recover the *length* $m$ of the key
2. Recover the *key* itself

