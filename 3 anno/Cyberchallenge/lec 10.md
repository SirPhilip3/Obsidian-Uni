memory corruption

buffer overflow 

stack can be executable -> code injection
shellcode -> 

jmp rsp -> if on the stack shellcode > executes it 

64 bit -> first 6 bytes -> adresses

*format string*

%s %s -> cerca di deferenziare qualcosa -> quello nei reg o nello stack 

%n -> scriver dei byte ad indirizzo 'ciao%n' -> size di quello che ha stampato fino a quel momento in un determinato address dato alla format string

4 byte
%hn scrive solo 2 byte

%s -> possiamo leggere valori da altri indirizzi

--

Non executable stack -> rende stack non eseguibile -> evita shellcode nello stack
non esegue codice 

se c'è altra parte eseguibile e dove possiamo jumpare :((

--
canary  -> all'inizio di ogni funzione lo piazza dentro lo stack , prima di ritornare controlla se il canary è stato danneggiato se non sono uguali gg

terminator canary -> primo byte a null -> se non ci fosse potremmo lekkare inviando una stringa non terminata fino al canary

xor between rand val e rand addr

random -> preso da fonte ad alta entropia

canary == quando il programma fa la fork 

se stack smashing sul figlio non crasha il padre -> possiamo usarlo come oracolo

*ASLR* randomizza il base address -> se leaka l'indirizzo del binario -> ez



shellcode -> possiamo usare nop sled se abbiamo aslr -> aumenta le chance di beccare lo shellcode

Control flow graphs -> visivamente puoi controllare dove finisce il tuo programma