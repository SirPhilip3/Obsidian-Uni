>[!note] 
>Lo standard si chiamerebbe *ECMAScript* l'ultima versione è ES2020 
>
>Visto che c'erano molti errori nelle prime versioni di Javascript ora essendo che deve mantenere legacy code sono dovute rimanere 
>
>E' possibile tuttavia in versioni più recenti di optare per la *strict mode* di Javascript al cui interno sono stati corretti vari errori iniziali

JavaScript definisce una API minimale per lavorare con numeri , testo , array etcc ma **non include** funzionalità di *input - output* che sono responsabilità dell'*environment host* all'interno del quale Javascript è embeddato 

L'*environment host* originariamente era il broswer web 
>[!note] 
>Dal 2010 è arrivato un altro *host environment* : Node , questo ci permette di avere accesso a tutto il sistema operativo 
>Questo viene utilizzato per implementare server web e altri script


Il broswer consente al codice Javascript di ottenere *input* dal mouse e dalla tastiera attraverso richieste *HTTP*
L'*output* viene fornito attraverso HTTP e CSS

---
# Javascript Tour

