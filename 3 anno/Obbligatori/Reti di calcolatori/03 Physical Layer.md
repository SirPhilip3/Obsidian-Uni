---
creation: 2024-09-19T08:22:00
---
Innanzittutto diamo delle definizioni che ci permetteranno di comprendere meglio la gestione del segnale al livello fisico : 
+ ![[Bit-rate]]
+ ![[Attenuation]]
+ ![[Delay]]
>[!note] 
>Il [[Delay]] non influenza direttamente la velocità di trasmissione
+ ![[Noise]]
+ ![[SNR]]
+ ![[Sensitivity]]
+ ![[Syncronization]]
### Sending Signals

Per mandare segnali usiamo la ![[Modulazione]]
Nel nostro caso utilizzeremo ![[Frequency Modulation]]
>[!example] 
>Quale sarà il [[Bit-rate]] di una comunicazione ?
>+ Assumiamo che $f_p = 4$ ( ossia l'onda *portante* fa 4 oscillaizoni al secondo )
>+ La lunghezza di un *bit* è determinato da 4 oscillazioni ( questo è chiamato **simbolo** )
>+ Mandiamo un *simbolo* al secondo ( [[Baud rate]] )
>+ Essendo che ogni *simbolo* rappresenta un bit avremo che il [[Bit-rate]] sarà $1 \ b/s$ 

>[!important] 
>Il [[Bit-rate]] è dato dal [[Baud rate]] moltiplicato per il numero di bit per *simbolo*

Per aumentare il [[Bit-rate]] possiamo fare due cose : 
1. Ridurre la lunghezza di un *simbolo* ( aumentiamo il [[Baud rate]] )
2. Codificare più bit all'interno di ogni *simbolo*

#### 1. Ridurre la durata di un simbolo

Potremmo aumentare il [[Baud rate]] , poremmo utilizzare 2 oscillazioni invece di 4 

>[!example] 
>![[Pasted image 20240920222137.png]]

>[!warning] 
>Più lungo *simbolo* è il simbolo più è facile per il *ricevitore* distinguerlo dal [[Noise]] , se invece il *simbolo* è più corto è più difficile da distinguere in canali rumorosi  

#### 2. Codificare più di un bit per simbolo

Potremmo codificare invece di solo due livelli per *simbolo* ( massimo e minimo ) più livelli per *simbolo* ( multipli di 2 )

>[!example] 
>Con 4 livelli ( 2 bit ) abbiamo :
>$$\begin{cases}
f'_p = f_p & \text{if} \ m(t)=00\\ 
f'_p = f_p(1+\Delta)&\text{if} \ m(t)=01\\
f'_p = f_p(1+2\Delta)&\text{if} \ m(t)=10\\
f'_p = f_p(1+3\Delta)&\text{if} \ m(t)=11\\
\end{cases}$$
>
>![[Pasted image 20240920223652.png]]

>[!warning] 
>Il ricevitore deve essere abbastanza fatto bene per poter percepire la differenza tra le varie frequenze

---

### Limitations

Notiamo che se volgiamo aumentare il [[Bit-rate]] dobbiamo per forza aumentare la ![[Bandwidth]]
#### Radio limitations

Ci sono però alcune limitazioni riguardanti i *ricevitori* : 
+ Un *ricevitore* funziona solo in un range di frequenze 
+ Il ricevitore ha una [[Sensitivity|sensibilità]] per la quale riesce a distinguere tra *frequenze* ( non possiamo ridurre il $\Delta$ troppo )

#### Wireless limitation

>[!warning] 
>Non possiamo utilizzare le stesse frequenze per più di una comunicazione alla volta 
>
>Se aumentiamo la [[Bandwidth]] per una trasmissione occupiamo più spettro
>>[!danger] 
>>Le *frequenze* sono allocate per legge
>>>[!example] 
>>> + Wi-Fi : 2401-2483 MHz
>>> + 4G : 703-748, 832-862 MHz

---
Possiamo calcolare il massimo teoretico di $bit/s$ attraverso due teoremi : 
+ ![[Nyquist Theorem]]
+ ![[Shannon Theorem]]