---
publish: true
---
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
#### $m$ recovery

We can use a *statistical* measure in order to recover $m$ 

**Index of Coincidence** : 
$$
I_c(x) = \frac{\sum_{i=1}^{26} f_i(f_i-1)}{n(n-1)} \approx \sum_{i=1}^{26} p_i^2
$$
Where : 
+ $f_i$ is the *frequency* of the $i-$th letter in a text of lenght $n$
+ $p_i = \frac{f_i}{n}$ is the *probability* of the $i-$th letter 

>[!summary] 
>The *index of coincidence* gives the probability that *two* letters, chosen at random from the text are the same

>[!example] 
>*IC* for the text `the index of coincidence` :
>$$
>c(3\cdot 2) + d(2\cdot1) + e(4\cdot3) + f(1\cdot0) + h(1\cdot0) + i(3\cdot2) + n(3\cdot2) + o(2\cdot1) + t(1\cdot0) + x(1\cdot0) = 34
>$$
>
>Divided by $n(n-1) = 21 \cdot 20 = 420$ will give us : $IC = \frac{34}{420} = 0.0809$ 

>[!note] 
>The value of the index is *maximum* ( $1$ ) for text composed of a single letter 
>
>The value of the index is *minimum* ( $\frac{1}{26} \approx 0.038$ ) for text composed of letter chosen with *uniform probability*

Each natural language has a characteristic *IC* :
+ English : $\sim 0.065$ 
+ Russian : $\sim 0.0529$

We can detect the type of *cipher* by checking the *IC* for the *ciphertext* produced : 
+ $\approx 0.038$ is a *polyalphabetic* cipher
+ $\approx 0.065$ is a *monoalphabetic* cipher

To find the $m$ the idea is to *brute-force* over $m$ and test if the computed *IC* matches the natural language value , we can use the following algorithm : 

```python
m = 1
LIMIT = 0.06 # IC of the language
found = False
while(not found):
	# analyze cy with jumps of m
	# compute IC if < than limit than not written in english
	# IC > limit -> substring in english
	sub = subciphers()
	found = True
	for i in range(0,m):
		if Ic(sub[i]) < LIMIT:
			found = False
			m += 1
			break
print m
```

>[!note] 
>We are checking the *IC* on the *subciphers* composed of letter at distance $m$ from each other
#### Key recovery

1. Devide the text in blocks of lenght $m$ 
2. Build new cripthograms such that one will have only the first letters of each group , the second letters from each group and so on 

>[!note] 
>This will produce $m$ [[Caesar Cipher]]s 

3. Find the *shift* between each subciphers 
4. *Brute-force* the first character of the ciphertext

We find the *relative shift* between two *subciphers* of lenght $n$ and $n'$ by using the **Mutual Index of Coincidence** : 
$$
MI_c(x,x') = \frac{\sum^{26}_{i=1} f_i f_i'}{nn'} = \sum^{26}_{i=1} p_i p_i'
$$
Where $n$ and $n'$ are the lenght of the two *subciphers*

>[!summary] 
>This rapresents the *probabilty* that two letters taken from two texts $x$ and $x'$ are the same 

>[!note] Idea
>The *idea* is to *shift* one *subcipher* until the *MI* of the first *subcipher* becomes close to the one of the *plaintext* language
>
>When this happens we know that the applied shift is the relative shift between the two *subcipher* and also between the letters of the key 

Algorithm : 

```python
key = []
for i in range(0,m)
	k=0
	mick=0
	for j in range(0,26)
		mic = MIC(sub[0], shift(j,sub[i]))
		if(mic > mick)
			k = j
			mick = mic
	key.append(k)
```

We repeat this process for each letter of the key and get a list of relative shifts now we can just try all the possible $26$ first letters of the *key* 

