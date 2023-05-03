
Le **Reference** ci permettono di non utilizzare i puntatori
```c++
double a;
double& b = a;
```
`b` è una reference (`b` ha lo stesso indirizzo di `a`)
`b` sarà un nome alternativo per `a` 

```c++
double c = 3.14;
b=c;
```
dentro sia `a` che `b` è presente il valore di `c`

La **Reference** deve sempre essere sempre abbinata ad un'altra variabile (dichiarazione + inizializzazione)

La **Reference** è inizializzata con un [l_value](https://www.oreilly.com/library/view/c-in-a/059600298X/ch03s01.html#:~:text=An%20rvalue%20is%20an%20expression,any%20storage%20associated%20with%20it.) per cui non è possibile scrivere
```c++
double a = 3.14;
double& b = a+5.5;//!Errore
```

Regola di forma: & accanto a double

```c++
void swap(int& a, int& b){//a, b parametri formali
	int c;
	c=a;
	a=b;
	b=c;
	
}

int main(){

	int x=3, y=4;
	swap(x, y);//x, y parametri effetivi
	cout<<x<<" "<<y<<endl;
}
```

Chiamando `swap` inizializzo i parametri formali con i parametri effettivi (`x=a`, `y=b`)
`swap` ha come input 2 reference: `int& a` e `int& b` ,rispettivamente nomi alternativi per `x` e `y`
`a` e `b` essendo reference non occupano spazio di memoria quindi non devo fare la free

Per fare la stessa cosa in C sarei stato obbligato ad usare i puntatori

Le **reference** sono gestite con puntatori dal compilatore (g++)
