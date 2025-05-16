---
publish: true
---
# Bitcoin Security

+ *Authentication* ( paying the right person not some impersonator )
	+ Is insured by [[Digital Signature]] 
+ *Integrity* ( prevents the coins to be double spent or reverse the transactions )
	+ Insured by [[Digital Signature]] and [[Hash Functions]]
+ *Availability* ( can i always make transactions )
	+ Insured by the *p2p* network
+ *Confidentiality* 
	+ We use *pseudonyms* ( addresses ) to conceal the identity 

# Bitcoin Transaction

A *bitcoin* transaction if formed by :
$$
hash(\text{previous transaction + current owner Public Key})
$$
This $hash$ is then **signed** by the *previous owner* using their $\text{Private Key}$, to prove that they authorized the transfer:
$$
Sign(hash,\text{prev owner Private Key})
$$
Anyone can now verify this signature using the *previous owner*'s $\text{Public Key}$

>[!example] 
>![[Pasted image 20250516114656.png]]

## Avoid Double Spending

Each node ( *miner* ) verifies that this is the first spending of that *bitcoin* by that *owner* 

We need to maintain a *global public append-only log* ( a *public ledger* ) of all the transactions , the **block chain** 

>[!note] 
>One *block* appended can contain lot's of transactions 

So now if someone tries to append a block that has the same *bitcoin* attached everyone will notice that and block the transaction
# Bitcoin Mining

Only *one* *miner* can append a new block to the chain at a time , the one miner selected will recieve a reward ( in BTC ) for attaching the block

The rewarded *miner* will also recieve possible transaction fees 

>[!important] 
>This is the only way of creating new *bitcoins*

When a new transaction is generated this will be *broadcasted* to all of the *miners* in the network 

1. Each *miner* will gather the pending transaction ( prioritizing the one with fees in them ) that can fit in a block
2. Verify the transactions :
	1. checking that the address has enough *bitcoin* to make the transfer 
	2. checking that the signature is correct 
3. Solving an *hashing* *problem* as fast as possible in order to be selected as the winner 
## Hashing Problem

Find a number that combined with other transaction data will produce an *hash* with many $0$'s at the beginning

The difficulty of the problem is chosen ( by specifing the number of $0$ to find ) so that the averge time for the first *miner* to *win* is $\sim 10$ minutes 
$$
H(\text{ prev\_hash, \textcolor{red}{nonce}, [Transactions] }) < \text{\# of 0's}
$$

This is called **Proof of Work**

When a *miner* finds a *proof of work* it will *broadcast* the new block to all the nodes in the network , they will than "accept" the new block by starting to create a new block

>[!warning]
>If 2 *miners* finish at the same time when the block will be broadcasted , due to the network latency , some nodes will recieve a block before the other 
>
>Each node will create two different chains , adding each a different block , the one that will have the higher sum of $0$'s will be the winner 
>>[!note] Note
>>Since the reward given for winning will be able to be spent after $100$ blocks we will wait for $100$ block and remove the reward for the loser

>[!note] 
>For large transaction we wait for $6$ blocks before confirming it ( 6 *miners* will need to agree to the transaction )

## 51% attack

When a *mining pool* has more than $51\%$ of the mining power they can practically run the network by deciding witch transaction to approve etcc
# Mixers

In order to improve *anonimity* , mixing services will generate lot's of transaction with different addersses before sending the *bitcoin* to the new owner , this way the original sender is *obfuscated* 

