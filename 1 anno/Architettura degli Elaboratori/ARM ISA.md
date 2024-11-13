---
publish: true
---
# ARMv8-A ISA

Supporta 3 istruction set:
+ **A32** : vesione a 32 bit ( Presente per retrocompatibilità )
+ **T32** : modalità Thumb ( 16 bit instructions, per specifiche applicazioni )
+ **A64** : versione a 64 bit

**Execution states** ( possono essere cambiati dinamicamente dalla CPU ):
+ **AArch64** : utilizza **A64**
+ **AArch32** : utilizza **A32 o T32**

## Simple Sequential Execution (SSE)

Istruzioni seguono il modello **SSE**

Il porcessore garantisce che le istruzioni vengano eseguite: 
+ una alla volta ( fetch->decode->execute )
+ nell'ordine in cui appaiono in memoria 

L'implementazione comporta il caircamento di 2 istruzioni alla volta che vengono eseguite in modo parallelo ( non necessariamente in-order )

Possibile ottimizzazione del codice se prendiamo in considerazione l'implementazione

![[Immagine 2023-04-04 082856.png]]

## Registri in AArch64

+ 31 registri general porpouse
+ Ogni registro può essere chiamato come registro a 64bit ( **X< n >** ) o come registro a 32bit ( **W< n >** ), W è composto dai 32bit meno significativi di X

La scelta di **X** o **W** nelle operazioni ne determina le loro dimensioni ( somma 32bit o 64bit )

+ 32 registri a 128bit per operazioni floating point e vettorizzate ( chiamati **V** per operazioni **SIMD** , se usiamo il nome **V** rappresentano operazioni su vettori di numeri, possiamo effettuare la somma 64bit di due numeri floating point contemporaneamente)
+ Il nome del registro determina la dimensione dell'operazione

![[Immagine 2023-04-04 083633.png]]

### Registri Paricolari

+ **XZR** letto con valore 0 e ignora il write
+ **X28** o **SP** usato come pointer allo stack 
+ **X29** o **FP** usato come frame pointer
+ **X30** o **LR** utilizzato per memorizzare l'inidirizzo di ritorno di una funzione ( **link register** )
+ **PC** non è general porpouse, non può essere usato direttamente dalle istruzioni. E' possibile leggere il **PC** attraverso una pseudo-istruzione **ADR**

**SYSTEM REGISTERS**
Utilizzati per configurare la CPU o il sistema di memoria, non possono essere usati direttamente nelle istruzioni ma possono essre letti o scritti dalle istruzioni **MSR** e **MRS**

**Application Program Status Registers ( APSR )**
|31|30|29|28|27|26-24|23-20|19-16|15-0|
|---|---|---|---|---|---|---|---|---|
|N|Z|C|V|Q|RAZ/SBZP|Reserved|GE|Reserved|

+ **N** : asserted se il risultato dell'ultima operazione è negativo
+ **Z** : asserted se il risultato dell'ultima operazione è zero
+ **V** : asserted se c'è stato un overflow nell'ultima operazione
+ **C** : asserted se c'è stato un "riporto" ( carry ) nell'ultima operazione

## Istruzioni

### Formato 

![[Immagine 2023-04-04 171039.png]]

Tutte le istruzioni sono a 32 bit : 
+ **Rn** : source 1
+ **Rm** : source 2
+ **Rd** : destination
+ **shamt** : shift amount
+ **Rt** : load/store destination register / test register

### Logico Aritmetiche

< op >{ S } Rd, Rn, < operand2 >

+ **S** : esegue l'operazione e setta i condition codes
+ **Rd** : destiantion
+ **Rn** : primo operando
+ **< operand2 >** : può essere : 
	+ **Rm** : secondo operando
	+ **Rm, < shift > # x** : secondo operando shiftando di un immediato ( massimo 12bit )
	+ **Rm, < shift > Rs**: secondo operando shiftando di ciò che è contenuto in un registro

**< shift >** :
+ **LSL**  : Logic shift left ( moltiplicazione per multipli di 2 ) ( può avvenire **overflow** )
![[Immagine 2023-04-04 180906.png]]
+ **LSR** : Logic shift right ( divisione per multipli di 2 ) ( 0 sui bit più significativi, se considero numeri con segno posso perdere il segno )
![[Immagine 2023-04-04 180939.png]]
+ **ASR** : Arithmetic shift right ( inserisce 0 o 1 a seconda del segno )
![[Immagine 2023-04-04 181242.png]]
+ **ROR** : "rotazioni"
+ **RRX** : "rotazioni"

#### Barrel shifter

+ Possibilità di moltiplicare e dividere per potenze di 2 prima di effettuare somme o altre operazioni
+ Possibilità di accedere ad elementi di un array :
	+ Utilizzando R1 come registro contenente il puntatore alla prima cella dell'array
	+ R2 contiene l'indice da accedere
	+ Esempio: voglio accedere int A[ 3 ] in R2 metterò il numero 3 moltiplicando per 4 ( grandezza in byte di 1 int -> 32 bit ) ( <<2 ) mi sposto di 3 elementi nell'array  addr = R1 + R2 << 2 

#### Operazioni logiche / aritmetiche

**ADD** , **SUB** , **AND** , **EOR** ( enclusive or, **XOR** ) , **ORR** ( inclusive or ) , **MUL** , **LSL** , **LSR**

Altre operazioni floating point

Se utilizzo un operatore immediato in operazioni aritmetiche l'istruzione viene convertita di tipo **I** 

#### Altre Istruzioni

**XZR** non può essere usato come secondo operando : al posto utilizzare **MOV** per spostare un valore in un registro ( **MOV** può accettare valori immediati di massimo 12bit )

**MOVZ** : posso utilizzare valori immediati di 16bit e shiftando di 0,16,32,48 bit , setta tutti gli altri bit a 0
**MOVK** : effettua stessa operazione ma lascia inalterati gli altri bit

**MOV** w(d) , w(n) : tra due registri viene automaticamente converita in :
**ORR** w(d) , wzr , w(d)

**SXT{B , H , W}** : sign extend ( estende il segno di un numero )
**UXT{B , H , W}** : zero extend ( estende lo 0 )

![[Immagine 2023-04-04 183120.png]]

**ADR** x(d) , label : Carica l'indirizzo di label nel registro x(d), la label deve trovarsi entro  $\pm$ 1Mb dal **PC** , perchè l'indirizzo è specificato come offset del **PC**

**ADRP** x(d) , label : Carica l'indice della pagina da 4KB che contiene l'indrizzo di label, label deve trovarsi entro $\pm$ 4GB dal **PC** , Se label è allineato a 4KB ( ultimi 12bit a 0 ) allora **ADRP** conterrà l'indirizzo esatto di label

### Branches

#### Salti non condizionati

Massimo offset supportato $\pm$ 128MB 

+ **B label** : salta all'indirizzo indicato dalla label
+ **BL label** : salta all'indirizzo indicato dalla label e salva l'indirizzo dell'istruzione sucessiva nel registro x30 
+ **RET** : salta all'indirizzo contenuto in x30
+ **BR x(m)** : salta all'indirizzo contenuto nel registro x(m)
+ **BRL x(m)** : salta all'indirizzo contenuto nel registro x(m) e salva l'indirizzo dell'istruzione sucessiva in x30

#### Salti condizionati semplici

Massimo offset supportato $\pm$ 1MB 

+ **CBZ w(n) or x(n), label** : salta all'indirizzo label se w(n) or x(n) è uguale a 0 
+ **CBNZ w(n) or x(n), label** : salta all'indirizzo label se w(n) or x(n) è diverso da 0

#### Branch condizionati

Format: **B.( COND ) label**

Salta all'indirizzo label sulla base di una **conditional mnemonics** = ( COND ) :
+ **B.EQ label** , if equal
+ **B.NE label** , if not equal
+ **B.LT label** , if less than

Full list:
![[Immagine 2023-04-07 175301.png]]

Risultato dipende dai condition codes della CPU ( registro **APSR** )

_Impostazione condition codes_

**CMP w(n) or x(n), w(m) or x(m)** : compare 2 registry and set **APSR** alias for :
	**SUBS xzr, w(n) or x(n), w(m) or x(m)**

Comparison tra 2 registri cambia a seconda se li consideriamo signed o unsigned ( compito del programmatore ):

w22 = 1111 1111 1111 1111 1111 1111 1111 1111 
w23 = 0000 0000 0000 0000 0000 0000 0000 0001

| |Signed|Unsigned|
|---|---|---|
|w22|-1|$2^{32}$|
|w23|1|1|
|Less than|B.LT taken|B.LO not taken|
|Greather than|B.GT not taken|B.HI taken|

#### Array bound check

Trattando i numeri con segno come se fossero senza segno è utile per verificare se 0 $\leq$ x $<$ y

I numeri negativi trattati come unsigned si presentano come numeri molto grandi quindi per verificare che un index di un array sia valido basta verificare che x$<$y poichè è true se x$<$y e x $>$ 0 

Esempio :
x20 indice array
x11 dimensione massima array

```arm-asm
CMP x20, x11
B.HS indexoutofbounds //taken se x20>=x11 o x20<0
```

#### Conditional select

**CSEL x(d), x(n), x(m), ( COND )**

Equivale a:
```c
if( COND ) then
	x(d)=x(n)
else
	x(d)=x(m)
```

#### Conditional increment

**CSINC x(d), x(n), x(m), ( COND )**

Equivale a:
```c
if( COND ) then
	x(d)=x(n)
else
	x(d)=x(m)+1
```

Vantaggiose rispetto ai branch classici perchè: 
+ minori istruzioni indipendentemente dall'outcome della condizione
+ non essendo salti non influenzano il fetch delle istruzioni sucessive e la branch prediction

_C vs Branching vs CSEL/CSINC_

|C|Branching|Conditional select|
|---|---|---|
|`if(a!=0)` <br>   `b=b+1`|`CMP W0, # 0` <br> `B.EQ else` <br> `ADD W1, W1, # 1` <br> `else:`|`CMP W0, # 0` <br> `CINC W1, W1, NE`|
|`if(a==0)`<br>`  y=y+1`<br> `else` <br> `  y=y-1`|`CMP W0, # 0`<br> `B.NE else`<br> `ADD w1, w1 , # 1`<br>`B end`<br>`else:`<br>`SUB W1, W1, # 1`<br>`end:`|`CMP W0, # 0`<br>`SUB W2, W1, # 1`<br>`CSINC W1, W2, W1, NE`|

#### Load/Store

_Load_:   reg<-MEM
**LDR( sign )( size )  ( reg ),  $[$addr$]$**

_Store_ : reg->MEM
**STR( sign )( size )  ( reg ),  $[$addr$]$**

##### ( size )
Può essere implicita ( dal nome del registro ) o esplicitata tramite il campo **( size )**

Per la store
+ **B** : carico il byte meno significativo di **( reg )** in **$[$addr$]$**
+ **H** : carico i 2 byte meno significativi di **( reg )** in **$[$addr$]$
+ **W** : carico i 4 byte meno significativi di **( reg )** in **$[$addr$]$** ( utile solo su address x(n) )

Pre la load
+ **Unisgned load** : **LDR( size ) ...** zero extends the bytes loaded![[Immagine 2023-04-07 190231.png]]
+ **Signed load** : **LDRS( size ) ...** sign extends the bytes loaded![[Immagine 2023-04-07 190334.png]]

##### $[$addr$]$

4 modi di indirizzamento possibili :

###### Base register
Utiliziammo un registro che contine l'indirizzo da utilizzare

![[Immagine 2023-04-07 191126.png]]

###### Offset
L'indirizzo da utilizzare viene ottenuto sommando un immediato ( offset ) al valore contenuto in un registro ( utile negli array ) ( **LDR** in questo caso sinonimo di **LDUR** **Load unscaled-offset register** )

![[Immagine 2023-04-07 191338.png]]

###### Pre-index
Offset viene sommato e scritto nel registro contenente l'indrizzo da utilizzare prima di accedere alla memoria

![[Immagine 2023-04-07 191506.png]]

###### Post-index

Si accede alla memoria all'indirizzo indicato dal registro ( come in base register ), dopo il caricamento l'offset è aggiunto al registro

![[Immagine 2023-04-07 191631.png]]

#### Syscall

**Supervisor call** , causa un'eccezione che porta la CPU in stato di esecuzione **EL1** ( kernel mode ) che esegue una funzione particolare in base al valore del registro x8 


#### Conversione floating point / interi

Copia valori da un registro floating point ad un registro intero e viceversa
+ **FMOV d0 , x0** 
+ **FMOV x0 , d0** 

Copa bit a bit senza arrotondamenti

Copia valori da un registro floating point ad un registro intero e viceversa
+ **SCVTF d0 , x0** 
+ **SVCTF x0 , d0**

Copia bit a bit con arrotondamento all'intero più vicino