sfw sec 0

gcc preprocessors instruction decompl 
static linking -> intero codice della funzione nel bin
dynamic linking -> ldb 

elf -> object files 
readelf
relocable object files , exec and

header -> metadati
program header table 

bss -> var non inizializzate 
data -> inizializzate
rodata > readonly data
symtab -> tabella dei simboli 
dynamic -> linking data

x86 -> cisc

8 reg gen porpouse esp -> for stack 

rip -> istr pointer

push -> operand on top of the stack 
pop  -> from top to a register 
lea -> addre da op1 a op2

jmp -> no condition
cmp -> setta flag usate da jle etcc per salti condizionati 

memory / calling conventions 

-02 -> può cambiare pos in memoria delle var 

stack frame -> activation record in cima allo stack -> call add return viene tolta 

32 -> tutti parametri nello stack , 64 solo dal 7 in poi , deve salvare pointer to return 

frame pointer -> pointer al frame precedente 

stack smashing 

64 bit -> primi 6 parametri sui registri 

*red zone* 128 byte sotto rsp -> per var locali 
cdecl -> calling conventions for x86 , come funzioni ricevono i parametri

malloc , free 

