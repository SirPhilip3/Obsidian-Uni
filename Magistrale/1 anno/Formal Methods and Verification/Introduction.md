1. written test -> open questions + ecercises
2. project 2/3 pp + oral exam

formal methods > math models to rapresent systems we can verify some propieties on it 

abstraction of the concrete system

type of system analized : 
+ *discrete event system* -> state changes depending on descrete event
	+ time driven -> ex bouncing ball -> state : position of the ball detemined by some params -> the movements changes according to time continuos changes
	+ event driven -> ex *barber shop* -> state : number of custumers -> events : customers arrives, leaves , queues etcc **non-deterministic** system descrete changes

+ state : variables
	+ n of customers $N$ , arrives : $N=N+1$
	+ changes continuosly with time and also *occasionally* changes states

Comms networks -> n° of noted waiting to send a message
state : 
+ N of nodes waiting to send a message

changes :
+ node that starts waiting : $N=N+1$
+ node that sends previously waiting : $N = N-1$

Discrete system -> changes state bc something occasionally happends
+ Descrete time : system considered at predetermined times
+ continuos time : system considered at time of each event

Exemple :
+ barbershop at descret times : every 10 minutes i observe the system *descrete time rapresentation* -> more difficul rapresentation of the system 

**continuos time** -> more "difficult" -> observing the events at exacly the time at witch happends -> easier description of the system (*in the course*)

---

models used to model the perfomance of the system (descrete event at continuos times)

---
**Examples**

+ capacity planning -> resources req in order to maintain acceptable performance
+ system config in order to perform efficently
+ system tuning -> optimizing parameter to improve performace
+ sustainable energy planning
+ blockchain prediction 

**Functional proprieties** : does a system respects some specifications ?
**Performance** : how well the system perfrorms-> efficency of the system
	continuos time markov chains

queueing networks 

---
Process Algebra -> let's us reason on strucuture and behaviour of a detrmined model 

Stocasticc PA ->adds dynamic behaviour of the system 

**PEPA** -> perf eval process algebra 
system : 
+ system -> caraterized by its components 
+ we can specify processes

Cooperator pradigm -> how te components can be combined , how they communicate etcc -> **compositionality**

compositional reasoning -> deveolps a model with hierarchical strucuture 
1st -> reason on small components
2nd -> how to connect them

allows both qualitative and quantitavie modelling

**PEPA** 

---
PEPA -> spec language

we can define processes -> 