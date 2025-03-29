dynamically linked function > 2 funzioni con la stessa firma da 2 librerie differenti > errore quando statically linked -> dynamically -> scieglie una delle due implementazioni -> possiamo sovrascrivere -> scrivi una libreria con la stessa firma -> 
`gcc --share -fpic mylib.c -o mylib.so`
-fpic -> riferimenti realtivi 

vogliamo LD_PRELOAD= -> env per set la priority di che libreria loadda
`LD_PRELOAD=/mylib.so ./code`

`ltrace -p <pid>` -> dynamic function calls
`strace` > sys call

