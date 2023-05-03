#include <iostream>

int evaluate() {
    std::cout << "insert expression (we accept +-): " << std::endl;

    int lval = 0;
    int rval = 0;
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

int main() { return evaluate(); }
