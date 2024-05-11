#include <iostream>
#include "calculator.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Calculator calculator;
    calculator.calcAdd(5, 10);
    calculator.calSub(5, 10);
    return 0;
}
