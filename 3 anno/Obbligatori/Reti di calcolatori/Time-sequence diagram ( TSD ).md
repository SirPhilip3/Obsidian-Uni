---
creation: 2024-09-25T11:10:00
publish: true
---
Un diagramma *time-sequence* descrive l'interazione tra gli host che stanno comunicando

>[!example] 
>![[Pasted image 20240925111155.png]]

+ Il tempo passa dall'alto verso il basso
+ Descriviamo l'invio di un bit come una chiamata di sistema `DATA.req(bit-value)`
+ Descriviamo la ricezione di un bit come una chiamata di sistema `DATA.ind(bit-value)`

>[!note] 
>La trasmissione non essendo istantanea forma una retta diagonale , dall'alto al basso

# Errors

>[!warning] 
>I bit possono essere *flippati* ossia il [[Noise]] potrebbe far credere al ricevitore che il bit è differente rispetto a quello che era stato mandato 
>
>![[Pasted image 20240925111739.png]]

>[!warning] 
>Un'altro tipo di errore di connessione è la *de-sincronizzazione* 
>
>Il ricevitore potrebbe percepire un numero di bit *minori* rispetto a quelli inviati originariamente a causa di un *disallineamento* dei *clock*
>
>Questo può avvenire poichè la lettura dei segnali da parte di un ricevitore dipende dal *clock* del ricevitore e del trasmettitore , se questi sono *disallineati* il ricevitore potrebbe leggere il segnale in tempi differenti e quindi aggiungere o togliere dati
>
>![[Pasted image 20240925111935.png]]
>
>Il ricevitore potrebbe percepire un numero di bit *maggiore* rispetto a quelli inviati originariamente a causa di un *disallineamento* dei *clock*
>
>![[Pasted image 20240925112308.png]]
>
>Per ovviare a questo problema utilizziamo il ![[Manchester Encoding]]
