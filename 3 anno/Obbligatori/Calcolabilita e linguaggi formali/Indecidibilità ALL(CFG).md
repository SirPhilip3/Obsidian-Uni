---
publish: true
creation: 2024-12-16T11:54:00
---
>[!important] Teorema
>
>$ALL_{CFG} = \{ <G> | \text{G è una CFG e } L(G) = \Gamma^* \}$ è [[Indecidibile]]

**Dimostrazione** : 

Assumiamo per **assurdo** che $ALL_{CFG}$ sia [[Decidibile]] e costruiamo un [[Decisore]] per $A_{TM}$

$S$ = Su input $<M,w>$ :
1. Costruire una [[Context-Free Grammar|CFG]] $G$ con le seguenti propietà : 
$$L(G) = \begin{cases}
A \neq \Sigma^* & \text{Se M accetta $w$} \\
\Sigma^* & \text{Altrimenti} 
\end{cases}$$
2. Esegui il [[Decisore]] per $ALL_{CFG}$ su $<G>$
3. Ritorna il suo output invertito 

Costruiamo ora $G$ in modo che $L(G)$ contenga le stringhe che non sono **storie di computazione accettanti** per $M$ e $w$
+ Se $L(G)=\Sigma^*$ *nessuna* stringa è una [[Riducibilità Basata su Storie di Computazione#^bd6bb6|Storia di computazione accettante]] per $M$ e $w$ ( $M$ non accetta $w$ )
+ Se $L(G) \neq \Sigma^*$ *qualche* stringa è una [[Riducibilità Basata su Storie di Computazione#^bd6bb6|Storia di computazione accettante]] ( $M$ accetta $w$ )

>[!note] 
>
>Visto che la definizione di una [[Context-Free Grammar|CFG]] per $G$ sarebbe complesso creiamo invece un [[06 Automi a Pila|PDA]] $P$ ( che verrà convertito in $G$ )

Costruiamo un [[06 Automi a Pila|PDA]] $P$ tale che $L(P)$ comprende stringhe che **non** sono [[Riducibilità Basata su Storie di Computazione#^bd6bb6|Storie di computazione accettante]] per $M$ e $w$ 

>[!note] 
>
>Una stringa che codifica una [[Riducibilità Basata su Storie di Computazione#^bd6bb6|Storia di computazione accettante]] ha il seguente formato : $\#C_1 \# C_2\# \dots \# C_k \#$ 

$P$ genera quindi tutte le stringhe : 
1. Che *non* iniziano con $C_1$
2. Per cui $C_k$ non è configurazione accettante
3. Esiste un $i$ tale che $C_{i+1}$ non discende da $C_i$ secondo la funzione di transizione della [[08 Macchine di Touring|MdT]] $M$ 

Il [[06 Automi a Pila|PDA]] sceglie in modo non deterministico se verificare al condizione $1$ , $2$ o $3$ 
1. Per verificare la condizione $1$ basta che fascia una scansione per capire se $C_1 \neq q_0 w$
2. Per verificare che $C_k \neq \mu\ q_{accept}\ w$ basta che verifichi la presenza di $q_{accept}$ 
3. Per verificare la terza condizione necessitiamo di modificare la rappresentazione dei dati : $\#C_1 \# C_2^R\# C_3 \# C_4^R \# \dots \# C_k \#$ , in questo modo possiamo caricare nello stack del [[06 Automi a Pila|PDA]] la prima *configurazione* e sucessivamente se leggiamo $C_2^R$ possiamo confrontare ogni simbolo nell'ordine corretto rispetto allo stack , se i due simboli matchano possiamo toglierli dallo stack ( in quanto non saranno cambiati da una configurazione all'altra ) , altrimenti dobbiamo verificare se questi possono essere generati dalla **funzione di transizione** di $M$ 