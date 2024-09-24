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

```js
let x; // dichiarazione di variabile
x = 0; // assegnazione

// TIPI

x = 1; // numeri
x = 0.01; // possono essere Integers o Reals
x = "Hello world"; // Stringhe
x = 'Hello world'; // stringhe possono anche essere determinata da ''
x = true; // Booleani
x = null; // null è un valore speciale che indica 'senza valore'
x = undefined; // un'altro valore speciale

// Un datatype importante è l'oggetto , un oggetto è una collezione di coppie nome valore o una mappa stringa -> valore

let book = {
	topic: "Javascript",
	edition: 7
};

book.topic // => "Javascript"
book["edition"] // => 7
book.author = "Dio"; // Crea una nuova proprietà con l'assegnamento

```

