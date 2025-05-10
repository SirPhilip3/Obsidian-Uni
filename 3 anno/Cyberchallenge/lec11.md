rop 
ret2libc

ret addr -> under basep , sp top of the stack
call -> push ret addr -> nella funzione push bp 

leave sp = bp -> pop bp -> return al main -> ret -> retadd in ip > istr dopo call

rop chains 

gadget > pezzi di codice che termina con ret 
`pop rdi` 
`ret` 

rop chain > pointer list to gadgets -> ret -> ritorna a pointer al prossimo gadget 

gadget per syscall a execve

eax syscall

dynamically linked -> non ci sono syscall -> si troverebbero sulle librerie

ret to libc 

dynamic linked -> libc viene caricata in memoria -> possiamo saltare dentro system() -> basta imporstar il parametro con "/bin/sh" o altro comando -> lei imposta i registri 

64bit -> primi 6 param -> rdi , rsi , rdx , r10 , r9 , r9 -> oltre nello stack 

32 bit tutti nello stack 

payload 64

pop rdi ret -> pointer a bin sh
address bin/sh
ret per fare allineare lo stack > allineato a 128 bit 
address di system ->

do_system+2 

payload 32

visto che ci salti direttamente -> non fa push di rip -> abbiamo 4 byte inutili -> basta fare allineamento + address di bin/sh 

1 gadget -> settano tutti i registri -> basta un overflow di 8 byte

potrei avere dei constraints 

posix_spawn -> contiene bin/sh

got override -> global offset table -> in dyn per salvare pointer a funzioni esterne 
può rw -> se modifichi address -> puoi puntare a dunzione che vuoi

non possiamo fare una chain -> solo un jm
con format string -> per scrivere nella got un onegadget 

full relro -> la got ro -> all'avvio deve fare il linker 
partial relro > sopra bss dove ci sono le variabili globali non possiamo fare overflow e andare a scrivere nella got 

libc usava partial relro 

slr abilitato -> base bin -> 6byte  -> prima ci sono null byte -> fgets si ferma a nullbyte

retaddr  -> says ret addr 

ropchain : 
pop eax

fil@Filippo:~/Ropper$ python3 Ropper.py --file primality_test --search="pop eax"
[INFO] Load gadgets from cache
[LOAD] loading... 100%
[LOAD] removing double gadgets... 100%
[INFO] Searching for gadgets: pop eax

[INFO] File: primality_test
0x08048606: pop eax; int 0x80;
0x08048606: pop eax; int 0x80; pop ebx; pop ecx; ret;

pop ecx -> impostarlo a 0 
o xor ecx exc -> lo imposta a 0

fil@Filippo:~/Ropper$ python3 Ropper.py --file primality_test --search="pop ecx"
[INFO] Load gadgets from cache
[LOAD] loading... 100%
[LOAD] removing double gadgets... 100%
[INFO] Searching for gadgets: pop ecx

[INFO] File: primality_test
0x080488f5: pop ecx; pop ebx; pop ebp; lea esp, [ecx - 4]; ret;
0x0804860a: pop ecx; ret;

retlibc

