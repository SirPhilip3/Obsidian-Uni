### Lvalue , Rvalue

Un Lvaue è un valore che può essere messo sia a destra che a sinistra di un'espressione
hanno una posizione in memoria

Un Rvalue è un valore che può stare solo a destra di un'espressione
sono valori temporanei

### Parametri effetivi , Parametri Formali

Effettivi : valori passati alla funzione quando viene chiamata 

Formali : quelli dichiarati da una funzione

### Passagio per copia o riferimento

Il passagio per copia chiama il copy constructor per creare un oggetto temporaneo copia del parametro effettivo

### Funzione con reference in C

```c++
void (int &a, int &b){
	int tmo = a;
	a = b;
	tmo = b;
}
```

```c
void(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

```

### Pimpl

Il paradigma Pimpl è utilizzato per nascondere l'implementazione della classe all'utilizzatore finale 
