
## Passaggio per riferimento (o indirizzo)

```c++
void swap(int& a, int& b){//a, b parametri formali a tipo int&
	int c;
	c=a;
	a=b;
	b=c;
	
}

int main(){

	int x=3, y=4;
	swap(x, y);//x, y parametri effetivi (l_value non include espressioni)
	cout<<x<<" "<<y<<endl;
}
```

Ho passato l'indirizzo di `x` e `y` a `swap`

param formali nomi alternativi per gli effettivi
instanziato spazio di memoria per swap ma senza instanziare area di meomoria per a e b (nomi alternativi per x, y) 
l_value di tipo int non compatibile con double !non posso avere tipi incompatibili



## Passaggio per valore (o copia)
```c++
void swap(int a, int b){//a, b parametri formali (firma)
	int c;
	c=a;
	a=b;
	b=c;
	
}

int main(){

	int x=3, y=4;
	swap(x, y);//x, y parametri effetivi (r_value quindi anche espressioni)
	cout<<x<<" "<<y<<endl;
}
```

Ho passato il valore di `a` e `b` a `swap` (non è avvenuto lo scambio di varaibili)
valori all'interno di `a` e `b` vengono inzializzati con i prametri effettivi (copiati)
abbinamento per posizione
promozione di tipo se come parametri effettivi diverso tipo dai parametri formaili (può esserci #Narrowing)

static per mantenere l'ambiente di una funzione in memoria (non utilizzato)

Il C dispone solo del passaggio per Valore, per ottenere un risultato simile al passaggio per riferimento in C++ è necessario usare i puntatoti

//esempio