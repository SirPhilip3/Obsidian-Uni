Memory accesses are the main sources of performance degradation

Memory is faster when close to the CPU 
__Cache__ is the fastest memory present in the system (exept for the CPU registers) it has 3 levels:
+ __L1__ is usually part of the CPU chip itself (the size is between 8KB and 64KB)
+ __L2__ is an extra chip between the CPU and the RAM (it's size is up to 512KB)
+ __L3__ is the larger of the three but also the slowest (it's size is up to 32 MB shared between variuos cores)

![[Immagine 2023-03-04 211525.png]]

In order to not slow down a program it's better to access always the fastest memory you can.

A __cache-miss__ is when a requested data is not found in a cache chip (for example L1) so the nearest chip is accessed (in this case L2)
When a __cache-miss__ heppends the CPU copies an entire __cache line__ (64 bytes of memory) from L2 to L1 
A __cache-hit__ is when a __cache-miss__ does not occour

In order to make our program more efficent we need to take advantage of __Caching__ and the __cache line copy__ faeture
+ __Temporal locality__ if a memory location *x* is used it's likely that it will be used in the near future 
+ **Spatial locality** if a memory location *x* is used it's likely that also x + i  or x - i will also be used

In our code if data *x* and *y* are used together, keep them close to memory
Accessing from RAM can be 60x slower

__Cache misses__ can be detected using two __Valgrind__ options:
	--tool=callgrind
	--cache-sim=yes