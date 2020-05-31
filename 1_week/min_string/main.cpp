#include <iostream>
#include <string>

int main() {
    std::string a, b, c;
    std::cin >> a >> b >> c;
    if (a < b) {
        if (a < c) {
            std::cout << a;
        } else {
            std::cout << c;
        }
    } else {
        if (b < c) {
            std::cout << b;
        } else {
            std::cout << c;
        }
    }

    return 0;
}