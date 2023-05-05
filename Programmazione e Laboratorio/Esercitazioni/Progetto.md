Lista -> [ T ] | null
T -> string | double | bool | Lista | Dictionary | null
Dictionary -> { key (string) : T } | null

```cpp
json& lista(){

	cin>>'['
	El();
	cin>>']'

}

json& Dictionary(){

	cin>>'{'
	T();
	cin>>'}'

}

T(){

	while(last_cahracter == ','){
	
		
		read key = pair key;

		read EL();

	
	}


}

El(){
	while(last_character = ','){

		if(first character == '\"' ) {
			read string;
		}else if (peek == number) read double
		else if (peek == bool) read bool
		else if (peek == '[') {
			putback 
			lista();
		}
		else if (peek == '{'){
			putback
			Dictionary();
		}
		
	}

	return ; // se ho finito di avere , alla fine

}

```