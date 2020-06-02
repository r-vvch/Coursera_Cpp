#include <iostream>
#include "update_if_greater.h"

int main() {
    int a = 4;
    int b = 2;
    UpdateIfGreater(a, b);
    std::cout << a << b;
    return 0;
}