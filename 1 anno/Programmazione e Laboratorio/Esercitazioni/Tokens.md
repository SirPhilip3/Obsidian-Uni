---
publish: true
---
Tokens helps deifining how an expression is made ( of what elements )

Implementing :

+ define a `struct token` :
	+ `m_type` defines the type of the token ( +, - , ( , ) , etc... )
	+ `m_value` is the actual number ( only if the toke is a number and not an operator )

```c++
struct token{

	(...)

private:
	char m_type;
	double m_value;
}
```

Example :

_Parsing ( 1.5 + 4 ) $\cdot$ 11_ 

|---|1|2|3|4|5|6|7|
|---|---|---|---|---|---|---|---|
|m_type|(|0|+|0|)|* |0|
|m_value|$\infty$|1.5|$\infty$|4|$\infty$|$\infty$|11|


```c++
#include <limits>
#include <iostream>


struct token {
    static constexpr double inf = std::numeric_limits<double>::max();
    //static: only one instance of the variable shared by all objects from the class
    //constexpr: the expression is constant , evauated at compile time 

	
    token() : m_type(0), m_value(inf) {}  // default constructor

	//friend  grants the function access to private data members
	//redefines the operator << ( for cout )
    friend std::ostream& operator<<(std::ostream& os, token const& t) {
        os << "[m_type: " << t.m_type << ", m_value: " << t.m_value << "]";
        return os;
    }

	//redefines the operator >> ( for cin )
    friend std::istream& operator>>(std::istream& is, token& t) {
        char c = 0;
        is >> c;  // skip separators
        if (c >= '0' and c <= '9') {
            is.putback(c);
            is >> t.m_value;
        } else {
            t.m_type = c;
        }
        return is;
    }

    double get_value() const { return m_value; };
    char get_type() const { return m_type; };

    bool is_double() const { return m_type == 0 and m_value != inf; }
    bool is_open() const { return m_type == '('; }
    bool is_close() const { return m_type == ')'; }
    bool is_add() const { return m_type == '+'; }
    bool is_sub() const { return m_type == '-'; }
    bool is_mul() const { return m_type == '*'; }
    bool is_div() const { return m_type == '/'; }
    bool is_eq() const { return m_type == '='; }

private:
    char m_type;     // ()+-*/=
    double m_value;  // the token's m_value or inf (if m_type is a symbol)
};
```

_Reading the tokens_

```c++
int main(){
	std::vector<token> tokens;

    do {
        try {
            token t; //the default constructor is called: m_type =0 and m_value =inf
            std::cin >> t;
            // std::cout << t;
            if (t.is_double())
                std::cout << t.get_value() << std::endl;
            else {
                std::cout << t.get_type() << std::endl;
            }
            tokens.push_back(t);
        } catch (std::runtime_error const& e) {
            std::cerr << e.what() << std::endl;
            break;
        }
    } while (!tokens.back().is_eq());
}

```

[what exeption](https://cplusplus.com/reference/exception/exception/what/)

