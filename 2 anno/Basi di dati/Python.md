# list comprehension

applicare funzione a tutti el di una lista e salvare risultati in un'altra lista

```python
my_list = [x**2 for x in range(10)]
# prima del for espressione che volgio appicare alla lista e dopo il for per quella lista in questo caso il 2 di ogni elemento di una lsita tra 0 e 9 
print (my_list)

# posso avere un filtro alla fine del for con un if

my_list = [x**2 for x in range(10) if x%2==0]
print (my_list)

# si crea un dizionario con key x e valore x^2

my_dict = {x:x**2 for x in range(10) if x%2==0}
print (my_dict)

# si possono concatenare for

[(x,y) for x in range(10) for y in range(8)]
# coppie ( x (0->9), y (0->8) )
```

# Funzioni

```python
def square(x): 
	return x**2;
```

posso assegnare e passare funzioni per riferiemento

```python
copy_function = power
```

posso restituire  più parametri

```python
def power(x):
	return x^2,x^3; # restituisce una tupla

x1,x2=power(x);
```


lambda
```python
powers = lambda x:powers(x,3)
```

```python
print (sorted(a, key=lambda x:abs(x))) # ordinamento secondo il valore assoluto di x 
```
lambda può avrere solo 1 return value 

```python
def add1(x):
    for i in range(len(x)):
        x[i] = x[i]+1
    return x

y = [1,2,3,4,5]
z = add1(y)
print( y,z ) # z e y sono la stessa lista poichè viene passata per riferimento non per copia
```

classi : 
```python
__init__ # costruttore
self # riferiemento all'oggetto , tutti i metodi della classe devono avere self
```

```python
class Dog:

    tricks = []  # shared by all instances of the class

    def __init__(self, name):
        self.name = name

    def add_trick(self, trick):
        self.tricks.append(trick)

    def bark(self):
        return "Bau bau bau!"
```

creazione di un oggetto 
```python
d = Dog("pippo")
e = Dog("jbb")
d.add_trick("roll")
e.add_trick("play")
# sia d che e hanno sia roll che play
```

se voglio avere uno stato diverso per ogni oggetto : 
```python
class Dog:

    def __init__(self, name):
        self.name = name
        self.tricks = []    # creates a new empty list for each dog

    def add_trick(self, trick):
        self.tricks.append(trick)

    def bark(self):
        return "Bau bau bau!"

d = Dog('Fido')
e = Dog('Buddy')
d.add_trick('roll over')
e.add_trick('play dead')
print(d.tricks) # roll over
print(e.tricks) # play death
```

potrei aggiungere una nuova variabile all'interno di un metodo della classe , questa verrà aggiunta quando eseguo quel metodo , prima non esiste
>[!warning]
>non c'è mai una dichiarazione di varaibile
>

estensione di calsse 

```python
class DogWithPedigree(Dog): #extension

    def __init__(self, name, parent):
        Dog.__init__(self, name) #superclass constructor
        self.parent = parent

    def good_dog(self):
        return set(self.parent.tricks).issubset(self.tricks)
	# override
    def bark(self):
        return "BAU BAU BAU!!!"

f = DogWithPedigree('Bolt', d)
print(f.good_dog())
f.add_trick('roll over')
print(f.good_dog())
```

accesso al database 

