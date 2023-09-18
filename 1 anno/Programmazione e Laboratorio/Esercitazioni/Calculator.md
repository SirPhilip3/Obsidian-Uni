## V1

Read three varibles from `std::cin` :
+ `int lval` , `int rval` 2 operands
+ `char op`  operation + or -

```c++
#include <iostream>

int evaluate(){

	int lval, rval = 0;
	char op = '0';
    
    std::cin >> lval >> op >> rval;
    
	int res = 0;
    if (op == '+') {
        res = lval + rval;
    } else if (op == '-') {
        res = lval - rval;
    } else {
        std::cerr << "invalid operation" << std::endl;
        return 1;
    }
    
    std::cout << "result is: " << res << std::endl;
    return 0;
}
```


## V2

+ accept double operands
+ handle operator using switch statements
+ handle chain of operations ( use as terminal string = )
+ add support for multiplication and division
+ handle input **errors**

```c++
#include <iostream>
#include <string>

int parse_error(std::string const& msg) {
    std::cerr << msg << std::endl;
    return 1;
}

int evaluate() {

    double lval = 0.0, rval = 0.0;
    char op = '0';

    std::cin >> lval >> op;
    if (!std::cin) return parse_error("invalid operand");

    while (op != '=') {
        std::cin >> rval;
        if (!std::cin) return parse_error("invalid operand");
        switch (op) {
            case '+':
                lval += rval;
                break;
            case '-':
                lval -= rval;
                break;
            case '/':
                lval /= rval;
                break;
            case '*':
                lval *= rval;
                break;
            default:
                return parse_error("invalid operation");
        }
        std::cin >> op;
    }
    std::cout << "result is: " << lval << std::endl;
    return 0;
}
```


## V2 + Exeptions

```c++
#include <iostream>
#include <string>

struct parse_error{
	std::string msg;
}

int evaluate() {

    double lval = 0.0, rval = 0.0;
    char op = '0';

    std::cin >> lval >> op;
    if (!std::cin) throw parse_error("invalid operand");

    while (op != '=') {
        std::cin >> rval;
        if (!std::cin) throw parse_error("invalid operand");
        switch (op) {
            case '+':
                lval += rval;
                break;
            case '-':
                lval -= rval;
                break;
            case '/':
                lval /= rval;
                break;
            case '*':
                lval *= rval;
                break;
            default:
                throw parse_error("invalid operation");
        }
        std::cin >> op;
    }
    std::cout << "result is: " << lval << std::endl;
    return 0;
}

int main(){
	try {
		return evaluate();
	}catch (parse_error const& e){ //reports the error thrown by evaluate
		std::cerr<<"error: \"" <<e.msg<<'"'<<std::endl;
		return 1;
	}
}
```


## V3

+ implement **operator precedence** : we need to look ahead and not perform an addition if later there is a opertion with higher precedence

**CFG** for calculator

![[Immagine 2023-04-12 132315.png]]

An expression is a<font color=00b050> summation</font> of <font color=ff323c> products</font> of terms
A term is either a number or an expression between parentheses

**CFG v1**

+ $E \longrightarrow P+P+...+P$
+ $P \longrightarrow T*T*...*T$
+ $T \longrightarrow double | ( E )$

where : 
+ $E$ expression
+ $P$ product
+ $T$ term
+ $double$ any double number

Not taking into account : 
+ left associativity
+ not taking into account - and / 

**CFG v2**

+ $E \longrightarrow P|E+P|E-P$
+ $P \longrightarrow T|P*T|P/T$
+ $T \longrightarrow double | (E)$

Feature : 
+ left-associativity encoded by the left recursion

1. Always parse P first since if we have E $\pm$ P the first E is anyway recursively expanded into P
2. parse the next token
3. if token is '+' or '-' we are in case E+P or E-P otherwise discard the token and return because we already parsed p

```c++
double E(std::vector<token> const& tokens, int& i) {
	double res = P(tokens, i); // parse next product
	token t = tokens [i] ; // next token
	while (t.is_add() or t.is_sub() {// parse operator (either + or—)
		i++;
		if (t.is_add()) res += P(tokens, i);
		if (t.is_sub()) res —= P(tokens, i);
		t = tokens[i];
	};
	return res;
}
```

```c++
double P(std: :vector<token> const& tokens, int& i) {
	double res = T (tokens, i); // parse next term
	token t = tokens [i l; // next token
	white (t.is_mul() or t.is_div()) {
		i++; // parse operator (either * or / )
		if (t.is_mul()) res*=T(tokens, i);
		if (t.is_div()) res/=T(tokens, i);
		t = tokens
	};
	return res;
```

```c++
double T(std: : vector<token> const& tokens, int& i){
	double res = 0;
	if (tokens[i].is_double()){
		res = tokens [i].get_value() ;
		++i; // skip token
	} else {
		assert(tokens[i].is_open());
		++i; // skip token
		res = E(tokens, i);// parse next expression
		assert(tokens[i].is_close());
		++i; // skip token
	}
	return res;
}
```

