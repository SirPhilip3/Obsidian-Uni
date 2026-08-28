---
publish: true
---
# Case studies

## PIN verification

*Hardware Security Modules* ( *HSM* ) are :
+ Used in the ATM Bank network
+ Tamper resistant
+ Offer APIs for :
	+ managing cryptographic keys
	+ *Decrypting* / *re-encrypting* the PIN
	+ Checking for the *validity* of the PIN

![[Pasted image 20260822115925.png]]

**Encrypted PIN Block** : contains the *PIN* at the *ATM*
$$
PIN\_V(EPB, vdata,len,dectab,offset)
$$
>[!note] 
>Where :
>+ `vdata` is usually derived from the customer Primary Account Number to validate the data
>+ `len` lenght of the pin
>+ `dectab` is *decimalization table* a 16 character string used to translate the hexadecimal output of the encryption to decimal numbers
>+ `offset` 

>[!example] 
>$$
>PIN\_V( \{4104,r\}_{k}, vdata, 4,0123456789012345,4732 )
>$$
>1. The *HSM* uses it's secret key $k$ to decrypt the *Encrypted PIN Block*
>2. `vdata` produces the 16 character string `A4795FDE32A48B1` and we uses the `dectab` to convert it in normal numbers
>3. Now doing the following operation to the first $4$ digits : $0472 \oplus 4732 \mod{10} = 4104$
### Decimalization attack

Changing a digit in the `dectab` propagates into the decryption algorithm and eventually changes the result 

>[!example] 
>If changing the first $0$ in `dectab` changes the result than we know that $0$ appeared in the *PIN* computation
>We can compensate on the offset to find the correct position in the *PIN* 

By doing this we can infer the *PIN* 
## PKCS#11

*Keys* have **attributes** and are referenced via **handles**

>[!example] 
>![[Pasted image 20260822122859.png]]

If a key is `sensitive` it should *never* be *accessible* as *plaintext* outside the device and all crypto operations must happen inside the device

>[!warning] Attack scenarion
>1. The device is used on compromised host
>2. The attacker extracts `sensitive` keys
>3. The attacker *clones the device*

Some key may have the `wrap` and `unwrap` properties such that they can be used to export keys encrypted under the *WrapKey* and also import a previously exported key ( *UnwrapKey* )

>[!warning] Wrap-then-decrypt attack
>
>The attacker wraps the key that he wants to extract with an *WrapKey* that also have the `decrypt` value set to true , it can then aks to decrypt the wrapped key to get the plaintext of the key even if it's tagged `sensitive`
>
>The fix is to simply not allow key wrapping in production
>

### Cloud HSM

Let's us use the *HSM* hardware as a service in the cloud , this allows for a vulnerability in a service on the cloud expose the full *PKCS#11* API

#todo 
#### Formal verified configuration

