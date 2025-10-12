This *cipher* works on *blocks* of $m$ letters with a key of lenght $m$ 

The *plaintext* is split into blocks of lenght $m$ and the *key* is repeated in order to perform the sum to *encrypt* the original *plaintext*

>[!example] 
>*key* = `FLUTE` , $m=5$
>```
>THISISAVERYSECRETMESSAGE +
>FLUTEFLUTEFLUTEFLUTEFLUT =
>YSCLMXLPXVDDYVVJEGXWXLAX
>```

$E_{k_1, \dots, k_m}(x_1,\dots, x_m) = (x_1 + k_1, \dots, x_m + k_m) \mod{26}$
$D_{k_1, \dots, k_m}(y_1,\dots, y_m) = (y_1 - k_1, \dots, y_m - k_m) \mod{26}$

$P=C=K=Z^m_{26}$ 
$Z_{26}^m$ strings repeated m times
