---
publish: true
---
## Automated Model checking

Model a system as a state machine 

>[!note] 
>An execution is called a *trace*

We formalize security properties as *trace properties*

We can use *automated tools* to check that the *property holds*
### Tamaring prover

Is a *tool* for the *automated analysis* of security protocols, it allows :
+ Rapid prototyping
+ Finding attacks
+ Provide a proof
+ Explore alternative designs or threat models quickly

**System specification** : the specification induces set of *traces* 
+ Modeling protocol and adversary using *multiset* rewriting

**Property specification** : specify which are the *good* traces

+ Tamarin tries to provide a *proof* that all *system traces* are *good*
+ contruct a counterexample trace of the system ( *attack* ) 

---
Basic ingredients :
+ *terms* : $m$ , $k$ , $enc(m,k)$
+ *facts* : model state and traces
+ *Special facts* : `Fr(t)` , `In(t)`, `Out(t)`, `K(t)`

*State* of system is a multiset of facts :
+ Initial state is the empty multiset
+ *rules* specify transitions

*Rules* are of the form :
+ `l --> r`
+ `l --[ a ]-> r`

`l` is comsumes , `r` is produce , facts in `a` constitute *traces*

#todo examples
